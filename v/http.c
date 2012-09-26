/* v/http.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ev.h>
#include <errno.h>

#include "../outside/jhttp/http_parser.h"   // Joyent HTTP
#include "all.h"
#include "v/vere.h"

/* _http_bod(): create a data buffer.
*/
static u2_hbod*
_http_bod(c3_w len_w, const c3_y* hun_y)
{
  u2_hbod* bod_u = malloc(len_w + sizeof(*bod_u));

  bod_u->len_w = len_w;
  memcpy(bod_u->hun_y, hun_y, len_w);
  
  bod_u->nex_u = 0;
  return bod_u;
}

/* _http_req_free(): free http request.
*/
static void 
_http_req_free(u2_hreq* req_u)
{
  if ( req_u ) {
    if ( req_u->url_c ) {
      free(req_u->url_c);
    }
    while ( req_u->hed_u ) {
      if ( req_u->hed_u->nam_c ) free(req_u->hed_u->nam_c);
      if ( req_u->hed_u->val_c ) free(req_u->hed_u->val_c);
      req_u->hed_u = req_u->hed_u->nex_u;
    }
    while ( req_u->bod_u ) {
      u2_hbod* nex_u = req_u->bod_u->nex_u;

      free(req_u->bod_u);
      req_u->bod_u = nex_u;
    }
    free(req_u);
  }
}

/* _http_rep_free(): free http response.
*/
static void
_http_rep_free(u2_hrep* rep_u)
{
  if ( rep_u->bod_u ) free(rep_u->bod_u);
  if ( rep_u->msg_c ) free(rep_u->msg_c);
  if ( rep_u->typ_c ) free(rep_u->typ_c);

  free(rep_u);
}

/* _http_respond_body(): attach response body.
*/
static void
_http_respond_body(u2_hcon *hon_u,
                   u2_hbod *rep_u)
{
  if ( !(hon_u->rep_u) ) {
    hon_u->rep_u = rep_u;
    hon_u->per_u = rep_u;

    ev_io_stop(u2_Host.lup_u, &hon_u->wax_u);
    // printf("http: %d: send on\n", hon_u->wax_u.fd);
    ev_io_set(&hon_u->wax_u, hon_u->wax_u.fd, (EV_READ | EV_WRITE));
    ev_io_start(u2_Host.lup_u, &hon_u->wax_u);
  }
  else {
    hon_u->per_u->nex_u = rep_u;
    hon_u->per_u = rep_u;
  }
}

/* _http_respond_str(): attach output string.
*/
static void
_http_respond_str(u2_hcon*    hon_u,
                  const c3_c* str_c)
{
  _http_respond_body(hon_u, _http_bod(strlen(str_c), (const c3_y*)str_c));
}

/* _http_respond(): attach response for transmission.
*/
static void
_http_respond(u2_hcon* hon_u,
              u2_hrep* rep_u)
{
  c3_c buf_c[81];

  sprintf(buf_c, "HTTP/1.1 %d %s\r\n",
                 rep_u->sat_w,
                 rep_u->msg_c ? rep_u->msg_c 
                              : (rep_u->sat_w == 200) ? "OK" : "Fscked");
  _http_respond_str(hon_u, buf_c);

  sprintf(buf_c, "Content-Type: %s\n", rep_u->typ_c);
  _http_respond_str(hon_u, buf_c);

  if ( rep_u->bod_u ) {
    sprintf(buf_c, "Content-Length: %u\r\n", rep_u->bod_u->len_w);
    _http_respond_body(hon_u, rep_u->bod_u);
  }
}

/* _http_conn_dead(): free http connection, close fd.
*/
static void
_http_conn_dead(u2_hcon *hon_u)
{
  ev_io_stop(u2_Host.lup_u, &hon_u->wax_u);
  close(hon_u->wax_u.fd);

  {
    struct _u2_http *srv_u = hon_u->srv_u;

    if ( srv_u->hon_u == hon_u ) {
      srv_u->hon_u = hon_u->nex_u;
    }
    else {
      u2_hcon *pre_u = srv_u->hon_u;

      while ( pre_u ) {
        if ( pre_u->nex_u == hon_u ) {
          pre_u->nex_u = hon_u->nex_u;
        }
        else pre_u = pre_u->nex_u;
      }
      c3_assert(!"zombie connection");
    }
  }
  _http_req_free(hon_u->req_u);

  while ( 0 != hon_u->rep_u ) {
    u2_hbod* nex_u = hon_u->rep_u->nex_u;

    free(hon_u->rep_u);
    hon_u->rep_u = nex_u;
  }

  free(hon_u);
}

/* _http_req_dump(): dump complete http request.
*/
static void
_http_req_dump(u2_hreq* req_u)
{
  c3_c* mets[] = { "delete", "get", "head", "post", "put", "other" };

  printf("%s %s\n", mets[req_u->met_e],
                    req_u->url_c ? req_u->url_c : "(null)");
  {
    u2_hhed* hed_u = req_u->hed_u;

    while ( hed_u ) {
      printf("%s: %s\n", hed_u->nam_c, hed_u->val_c);
      hed_u = hed_u->nex_u;
    }
  }
  {
    u2_hbod* bod_u = req_u->bod_u;
    c3_w bod_w = 0;

    while ( bod_u ) {
      bod_w += bod_u->len_w;
      bod_u = bod_u->nex_u;
    }
    printf("body: %d bytes\n", bod_w);
  }
}

/* _http_message_begin(): jhttp callback
*/
static c3_i
_http_message_begin(http_parser* par_u)
{
  return 0;
}

/* _http_more(): extend string with new data.
*/
static c3_c*
_http_more(c3_c* str_c, const c3_c* buf_c, size_t siz_i)
{
  if ( !str_c ) {
    str_c = malloc(siz_i + 1);
    memcpy(str_c, buf_c, siz_i);
    str_c[siz_i] = 0;
  }
  else {
    c3_w len_w = strlen(str_c);

    str_c = realloc(str_c, len_w + siz_i + 1);
    memcpy(str_c + len_w, buf_c, siz_i);
    str_c[len_w + siz_i] = 0;
  }
  return str_c;
}

/* _http_url(): jhttp callback
*/
static c3_i
_http_url(http_parser* par_u, const c3_c* buf_c, size_t siz_i)
{
  u2_hcon *hon_u = par_u->data;
  u2_hreq *req_u = hon_u->req_u;

  req_u->url_c = _http_more(req_u->url_c, buf_c, siz_i);
  return 0;
}
 
/* _http_header_field(): jhttp callback
*/
static c3_i
_http_header_field(http_parser* par_u, const c3_c* buf_c, size_t siz_i)
{
  u2_hcon *hon_u = par_u->data;
  u2_hreq *req_u = hon_u->req_u;

  switch ( req_u->rat_e ) {
    case u2_hreq_non: 
    case u2_hreq_val: {
      u2_hhed* hed_u = malloc(sizeof(*hed_u));

      hed_u->nam_c = _http_more(0, buf_c, siz_i);
      hed_u->val_c = 0;
      hed_u->nex_u = req_u->hed_u;
      req_u->hed_u = hed_u;

      break;
    }
    case u2_hreq_nam: {
      req_u->hed_u->nam_c = _http_more(req_u->hed_u->nam_c, buf_c, siz_i);
      break;
    }
  }
  req_u->rat_e = u2_hreq_nam;
  return 0;
}
 
/* _http_header_value(): jhttp callback
*/
static c3_i
_http_header_value(http_parser* par_u, const c3_c* buf_c, size_t siz_i)
{
  u2_hcon *hon_u = par_u->data;
  u2_hreq *req_u = hon_u->req_u;

  switch ( req_u->rat_e ) {
    case u2_hreq_non: fprintf(stderr, "http: odd value\n"); return 1;

    case u2_hreq_nam: {
      req_u->hed_u->val_c = _http_more(0, buf_c, siz_i);
      break;
    }
    case u2_hreq_val: {
      req_u->hed_u->val_c = _http_more(req_u->hed_u->val_c, buf_c, siz_i);
      break;
    }
  }
  req_u->rat_e = u2_hreq_val;
  return 0;
}

/* _http_headers_complete(): jhttp callback
*/
static c3_i
_http_headers_complete(http_parser* par_u)
{
  u2_hcon *hon_u = par_u->data;
  u2_hreq *req_u = hon_u->req_u;

  if ( par_u->method >= u2_hmet_other ) {
    req_u->met_e = u2_hmet_other;
  } else req_u->met_e = par_u->method;

  return 0;
}

/* _http_body(): jhttp callback
*/
static c3_i
_http_body(http_parser* par_u, const c3_c* buf_c, size_t siz_i)
{
  u2_hcon *hon_u = par_u->data;
  u2_hreq *req_u = hon_u->req_u;
  u2_hbod* bod_u = _http_bod(siz_i, (const c3_y*)buf_c);

  bod_u->nex_u = req_u->bod_u;
  req_u->bod_u = bod_u;
 
  return 0;
}

/* _http_message_complete(): jhttp callback
*/
static c3_i
_http_message_complete(http_parser* par_u)
{
  u2_hcon *hon_u = par_u->data;
  u2_hreq *req_u = hon_u->req_u;
  u2_hrep *rep_u;

  _http_req_dump(req_u);
  rep_u = u2_ve_http_sync(req_u);

  _http_req_free(req_u);
  hon_u->req_u = 0;

  if ( rep_u ) {
    _http_respond(hon_u, rep_u);
    _http_rep_free(rep_u);
  }
  return 0;
}

/* _http_settings[]: callback array.
*/
static struct http_parser_settings _http_settings = {
  _http_message_begin,
  _http_url,
  _http_header_field,
  _http_header_value,
  _http_headers_complete,
  _http_body,
  _http_message_complete
};

/* _http_req_new(): new http request.
*/
static u2_hreq*
_http_req_new()
{
  u2_hreq* req_u = malloc(sizeof(*req_u));

  req_u->met_e = (u2_hmet)0;
  req_u->rat_e = (u2_hrat)0;
  req_u->url_c = 0;
  req_u->hed_u = 0;
  req_u->bod_u = 0;

  return req_u;
}

/* _http_clip(): remove sent bytes from buffer.
*/
static void
_http_clip(u2_hbod* bod_u, c3_i siz_i)
{
  c3_assert(siz_i < bod_u->len_w);
  {
    c3_w res_w = (bod_u->len_w - siz_i);

    memmove(bod_u->hun_y, (bod_u->hun_y + siz_i), res_w);
    bod_u->len_w = res_w;
  }
}

/* _http_conn_cb(): libev callback for http connections.
*/
static void
_http_conn_cb(struct ev_loop *lup_u, struct ev_io* wax_u, int revents)
{
  u2_hcon *hon_u = (void *)wax_u;
  u2_flag inn    = (revents & EV_READ) ? u2_yes : u2_no;
  u2_flag out    = (revents & EV_WRITE) ? u2_yes : u2_no;

  if ( u2_yes == inn ) {
    http_parser* par_u = hon_u->par_u;

    if ( !hon_u->req_u ) {
      hon_u->req_u = _http_req_new();
      http_parser_init(par_u, HTTP_REQUEST);
      par_u->data = hon_u;
    }
    {
      c3_w len_w = (80 * 1024);
      c3_i siz_i;
      c3_y buf_y[len_w];

      if ( (siz_i = recv(wax_u->fd, buf_y, len_w, 0)) < 0 ) {
        if ( EAGAIN == errno ) {
          return;
        } else {
          perror("http: recv");
          _http_conn_dead(hon_u);
        }
      }
      if ( siz_i != 
           http_parser_execute(par_u, &_http_settings, (c3_c*)buf_y, siz_i) ) {
        fprintf(stderr, "http: parse error\n");
        _http_conn_dead(hon_u);
      }
      if ( siz_i == 0 ) {
        fprintf(stderr, "EOF on fd %d\n", wax_u->fd);
        _http_conn_dead(hon_u);
      }
    }
  }
  if ( u2_yes == out ) {
    while ( 1 ) {
      u2_hbod* rep_u = hon_u->rep_u;
      c3_i siz_i;

      if ( (siz_i = send(wax_u->fd, rep_u->hun_y, 2, 0)) < 0 ) {
        if ( EAGAIN == errno ) {
          break;
        } else {
          perror("http: send");
          _http_conn_dead(hon_u);
        }
      }

      if ( siz_i < rep_u->len_w ) {
        _http_clip(rep_u, siz_i);
        break;
      }
      else {
        free(rep_u);
        hon_u->rep_u = hon_u->rep_u->nex_u;
        
        if ( 0 == hon_u->rep_u ) {
          hon_u->per_u = 0;
  
          ev_io_stop(u2_Host.lup_u, &hon_u->wax_u);
          ev_io_set(&hon_u->wax_u, hon_u->wax_u.fd, EV_READ);
          ev_io_start(u2_Host.lup_u, &hon_u->wax_u);

          break;
        } 
      }
    }
  }
}

/* _http_conn_new(): new http connection with fd.
*/
static void
_http_conn_new(u2_http *srv_u, c3_i fid_i)
{
  u2_hcon *hon_u = malloc(sizeof(*hon_u));
 
  hon_u->par_u = malloc(sizeof(struct http_parser));
  hon_u->srv_u = srv_u;
  hon_u->nex_u = srv_u->hon_u;
  srv_u->hon_u = hon_u;
  hon_u->req_u = 0;

  ev_io_init(&hon_u->wax_u, _http_conn_cb, fid_i, EV_READ);
  ev_io_start(u2_Host.lup_u, &hon_u->wax_u);
}

/* _http_list_cb(): callback for http listener.
*/
static void
_http_list_cb(struct ev_loop *lup_u, struct ev_io* wax_u, int revents)
{
  u2_http *srv_u = (void *)wax_u;
  c3_assert(revents & EV_READ);

  {
    socklen_t          len_o = sizeof(struct sockaddr_in);
    struct sockaddr_in add_k;
    c3_i               fid_i;

    fid_i = accept(wax_u->fd, (struct sockaddr *)&add_k, &len_o);
    if ( fid_i < 0 ) {
      perror("http: accept");
    }
    else if ( fcntl(fid_i, F_SETFD, O_NONBLOCK) < 0 ) {
      perror("http: fcntl");
    }
    else {
      fprintf(stderr, "http: new connection %d\n", fid_i);
      _http_conn_new(srv_u, fid_i);
    }
  }
}

u2_flag
u2_ve_http_start(c3_w por_w)
{
  c3_i fid_i;

  /* Open, bind and listen on the socket.
  */
  {
    struct sockaddr_in add_k;

    if ( (fid_i = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
      perror("http: socket");
      return u2_no;
    }

    add_k.sin_family = AF_INET;
    add_k.sin_addr.s_addr = INADDR_ANY;
    add_k.sin_port = htons(por_w);

    if ( bind(fid_i, (struct sockaddr *)&add_k, sizeof(add_k)) < 0 ) {
      perror("http: bind");
      return u2_no;
    }
    if ( listen(fid_i, 3) < 0 ) {
      perror("http: listen");
      return u2_no;
    }
  }

  /* Create and activate the server structures.
  */
  {
    u2_http *htp_u = malloc(sizeof(*htp_u));

    htp_u->hon_u = 0;
    htp_u->nex_u = 0;
    htp_u->por_w = por_w;

    ev_io_init(&htp_u->wax_u, _http_list_cb, fid_i, EV_READ);
    ev_io_start(u2_Host.lup_u, &htp_u->wax_u);

    htp_u->nex_u = u2_Host.htp_u;
    u2_Host.htp_u = htp_u;
  }
  return u2_yes;
}
