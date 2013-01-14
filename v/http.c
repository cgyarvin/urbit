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
#include <libtecla.h>

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

/* _http_bud(): create a header buffer.  Not null-terminated!
*/
static u2_hbod*
_http_bud(c3_c* nam_c, c3_c* val_c)
{
  c3_w lnm_w     = strlen(nam_c);
  c3_w lvl_w     = strlen(val_c);
  c3_w len_w     = lnm_w + 2 + lvl_w + 2;
  u2_hbod* bod_u = malloc(len_w + sizeof(*bod_u));

  strncpy((c3_c *)bod_u->hun_y, nam_c, lnm_w);
  strncpy((c3_c *)bod_u->hun_y + lnm_w, ": ", 2);
  strncpy((c3_c *)bod_u->hun_y + lnm_w + 2, val_c, lvl_w);
  strncpy((c3_c *)bod_u->hun_y + lnm_w + 2 + lvl_w, "\r\n", 2);

  bod_u->len_w = len_w;
  bod_u->nex_u = 0;

  return bod_u;
}

/* _http_heds_free(): free header structure.
*/
static void
_http_heds_free(u2_hhed* hed_u)
{
  if ( hed_u ) {
    u2_hhed* nex_u = hed_u->nex_u;

    if ( hed_u->nam_c ) free(hed_u->nam_c);
    if ( hed_u->val_c ) free(hed_u->val_c);

    free(hed_u);
    hed_u = nex_u;
  }
}

/* _http_bods_free(): free body structure.
*/
static void
_http_bods_free(u2_hbod* bod_u)
{
  if ( bod_u ) {
    u2_hbod* nex_u = bod_u->nex_u;

    free(bod_u);
    bod_u = nex_u;
  }
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
    _http_heds_free(req_u->hed_u);
    _http_bods_free(req_u->bod_u);

    free(req_u->par_u);
    free(req_u);
  }
}

/* _http_rep_free(): free http response.
*/
static void
_http_rep_free(u2_hrep* rep_u)
{
  _http_heds_free(rep_u->hed_u);
  _http_bods_free(rep_u->bod_u);

  free(rep_u);
}

/* _http_respond_body(): attach response body.
*/
static void
_http_respond_body(u2_hreq *req_u,
                   u2_hbod *rub_u)
{
  if ( !(req_u->rub_u) ) {
    req_u->rub_u = req_u->bur_u = rub_u;

    //  if this is the next request to be responded to,
    //  tell the event layer we are ready to write
    //
    if ( req_u == req_u->hon_u->req_u ) {
      u2_hcon* hon_u = req_u->hon_u;

      // fprintf(stderr, "http: %d: writing ON\r\n", hon_u->wax_u.fd);

      ev_io_stop(u2_Host.lup_u, &hon_u->wax_u);
      ev_io_set(&hon_u->wax_u, hon_u->wax_u.fd, (EV_READ | EV_WRITE));
      ev_io_start(u2_Host.lup_u, &hon_u->wax_u);
    } 
    else {
      u2_hcon* hon_u = req_u->hon_u;

      fprintf(stderr, "http: %d: out of order\r\n", hon_u->wax_u.fd);
      fprintf(stderr, "req_u %p, ruc_u %p\r\n", req_u, req_u->hon_u->ruc_u);
    }
  }
  else {
    req_u->bur_u->nex_u = rub_u;
    req_u->bur_u = rub_u;
  }
}

/* _http_respond_str(): attach output string.
*/
static void
_http_respond_str(u2_hreq*    req_u,
                  const c3_c* str_c)
{
  _http_respond_body(req_u, _http_bod(strlen(str_c), (const c3_y*)str_c));
}

/* _http_respond_headers(): attach output headers.
*/
static void
_http_respond_headers(u2_hreq* req_u,
                      u2_hhed* hed_u)
{
  while ( hed_u ) {
    _http_respond_body(req_u, _http_bud(hed_u->nam_c, hed_u->val_c));
    hed_u = hed_u->nex_u;
  }
}

/* _http_respond_request(): attach response to request for transmission.
*/
static void
_http_respond_request(u2_hreq* req_u,
                      u2_hrep* rep_u)
{
  c3_c buf_c[81];

  sprintf(buf_c, "HTTP/1.1 %d %s\r\n",
                 rep_u->sas_w,
                 (rep_u->sas_w == 200) ? "OK" : "Hosed");
  _http_respond_str(req_u, buf_c);

  // printf("attached response status %d\n", rep_u->sas_w);
  _http_respond_headers(req_u, rep_u->hed_u);

  if ( rep_u->bod_u ) {
    sprintf(buf_c, "content-length: %u\r\n", rep_u->bod_u->len_w);
    _http_respond_str(req_u, buf_c);

    _http_respond_str(req_u, "\r\n");
    _http_respond_body(req_u, rep_u->bod_u);
  } else {
    //  Why is this necessary?  Why can't we send a naked error?
    //
    _http_respond_str(req_u, "\r\n");
    sprintf(buf_c, "HTTP error %d.\r\n", rep_u->sas_w);
    _http_respond_str(req_u, buf_c);
  }

  c3_assert(u2_no == req_u->end);
  req_u->end = u2_yes;
}

/* _http_conn_dead(): free http connection, close fd.
*/
static void
_http_conn_dead(u2_hcon *hon_u)
{
  // fprintf(stderr, "http: %d: writing DEAD\r\n", hon_u->wax_u.fd);

  ev_io_stop(u2_Host.lup_u, &hon_u->wax_u);
  close(hon_u->wax_u.fd);

  {
    struct _u2_http *htp_u = hon_u->htp_u;

    if ( htp_u->hon_u == hon_u ) {
      htp_u->hon_u = hon_u->nex_u;
    }
    else {
      u2_hcon *pre_u = htp_u->hon_u;

      //  XX glories of linear search
      //
      while ( pre_u ) {
        if ( pre_u->nex_u == hon_u ) {
          pre_u->nex_u = hon_u->nex_u;
        }
        else pre_u = pre_u->nex_u;
      }
    }
  }

  while ( 0 != hon_u->req_u ) {
    u2_hreq* req_u = hon_u->req_u;
    u2_hreq* nex_u = req_u->nex_u;

    _http_req_free(req_u);
    hon_u->req_u = nex_u;
  }
  free(hon_u);
}

#if 0
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
      printf("%s: %s\r\n", hed_u->nam_c, hed_u->val_c);
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
    printf("body: %d bytes\r\n", bod_w);
  }
}
#endif

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
  u2_hreq *req_u = par_u->data;

  req_u->url_c = _http_more(req_u->url_c, buf_c, siz_i);
  return 0;
}
 
/* _http_header_field(): jhttp callback
*/
static c3_i
_http_header_field(http_parser* par_u, const c3_c* buf_c, size_t siz_i)
{
  u2_hreq *req_u = par_u->data;

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
  u2_hreq *req_u = par_u->data;

  switch ( req_u->rat_e ) {
    case u2_hreq_non: fprintf(stderr, "http: odd value\r\n"); return 1;

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
  u2_hreq *req_u = par_u->data;

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
  u2_hreq* req_u = par_u->data;
  u2_hcon* hon_u = req_u->hon_u;

  c3_assert(req_u == hon_u->ruc_u);
  hon_u->ruc_u = 0;
  // _http_req_dump(req_u);

  // Queue request for response control.
  {
    if ( !hon_u->qer_u ) {
      c3_assert(!(hon_u->req_u));
      
      hon_u->qer_u = hon_u->req_u = req_u;
    }
    else {
      hon_u->qer_u->nex_u = req_u;
    } 
  }

  // Dispatch event request, respond synchronously if offered.
  //
  {
    u2_hrep* rep_u = u2_ve_http_request(req_u);

    if ( rep_u ) {
      _http_respond_request(req_u, rep_u);
      _http_rep_free(rep_u);
    }
    return 0;
  }
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
_http_req_new(u2_hcon* hon_u)
{
  u2_hreq* req_u = malloc(sizeof(*req_u));

  req_u->hon_u = hon_u;
  req_u->seq_l = hon_u->seq_l++;

  req_u->met_e = (u2_hmet)0;
  req_u->rat_e = (u2_hrat)0;

  req_u->par_u = malloc(sizeof(struct http_parser));
  http_parser_init(req_u->par_u, HTTP_REQUEST);
  ((struct http_parser *)(req_u->par_u))->data = req_u;

  req_u->liv = u2_no;
  req_u->end = u2_no;

  req_u->url_c = 0;

  req_u->hed_u = 0;
  req_u->bod_u = 0;
  req_u->nex_u = 0;
  req_u->rub_u = 0;
  req_u->bur_u = 0;

  return req_u;
}

/* _http_clip(): remove sent bytes from buffer.
*/
static void
_http_clip(u2_hbod* bod_u, c3_i siz_i)
{
  if ( siz_i ) {
    c3_assert(siz_i < bod_u->len_w);
    {
      c3_w res_w = (bod_u->len_w - siz_i);

      memmove(bod_u->hun_y, (bod_u->hun_y + siz_i), res_w);
      bod_u->len_w = res_w;
    }
  }
}

/* _http_conn_suck(): suck down all available input on connection.
*/
static void
_http_conn_suck(u2_hcon* hon_u)
{
  if ( !hon_u->ruc_u ) {
    hon_u->ruc_u = _http_req_new(hon_u);
  }
  {
    c3_w len_w = (80 * 1024);
    c3_i siz_i;
    c3_y buf_y[len_w];

    if ( (siz_i = recv(hon_u->wax_u.fd, buf_y, len_w, 0)) < 0 ) {
      if ( EAGAIN == errno ) {
        return;
      } else {
        perror("http: recv");
        _http_conn_dead(hon_u);
        return;
      }
    }
    if ( siz_i != http_parser_execute(hon_u->ruc_u->par_u, 
                                      &_http_settings, 
                                      (c3_c*)buf_y, 
                                      siz_i) )
    {
      fprintf(stderr, "http: parse error\r\n");
      _http_conn_dead(hon_u);
    }
    if ( siz_i == 0 ) {
      // fprintf(stderr, "EOF on fd %d\r\n", hon_u->wax_u.fd);
      _http_conn_dead(hon_u);
    }
  }
}

/* _http_conn_flush(): flush all available output on connection.
*/
static void
_http_conn_flush(u2_hcon* hon_u)
{
  while ( hon_u->req_u ) {
    u2_hreq* req_u = hon_u->req_u;
    u2_hbod* rub_u = req_u->rub_u;

    if ( 0 == rub_u ) {
      if ( u2_yes == req_u->end ) {
        hon_u->req_u = req_u->nex_u;
        if ( 0 == hon_u->req_u ) {
          c3_assert(req_u == hon_u->qer_u);
          hon_u->qer_u = 0;
        }
        _http_req_free(req_u);
        continue;
      }
      else {
        //  We have not yet finished adding responses to this
        //  current request - so, we cannot start writing the next.
        //
        goto stop;
      }
    }
    else {
      c3_i siz_i;

      if ( (siz_i = send(hon_u->wax_u.fd, 
                         rub_u->hun_y, 
                         rub_u->len_w, 0)) < 0 ) {
        if ( EAGAIN == errno ) {
          return;
        } else {
          perror("http: send");
          _http_conn_dead(hon_u);
        }
      }
      if ( siz_i < rub_u->len_w ) {
        _http_clip(rub_u, siz_i);
        return;
      }
      else {
        req_u->rub_u = req_u->rub_u->nex_u;
        if ( 0 == req_u->rub_u ) {
          c3_assert(rub_u == req_u->bur_u);
          req_u->bur_u = 0;
        }
        
        free(rub_u);
      }
    }
  }

  stop: {
    // fprintf(stderr, "http: %d: writing OFF\r\n", hon_u->wax_u.fd);

    ev_io_stop(u2_Host.lup_u, &hon_u->wax_u);
    ev_io_set(&hon_u->wax_u, hon_u->wax_u.fd, EV_READ);
    ev_io_start(u2_Host.lup_u, &hon_u->wax_u);
  }
}

extern GetLine *Tecla;
/* _http_conn_cb(): libev callback for http connections.
*/
static void
_http_conn_cb(struct ev_loop *lup_u, struct ev_io* wax_u, int revents)
{
  u2_hcon *hon_u = (void *)wax_u;
  u2_bean inn    = (revents & EV_READ) ? u2_yes : u2_no;
  u2_bean out    = (revents & EV_WRITE) ? u2_yes : u2_no;

  gl_normal_io(Tecla);
  if ( u2_yes == inn ) {
    _http_conn_suck(hon_u);
  }
  if ( u2_yes == out ) {
    _http_conn_flush(hon_u);
  }
  gl_raw_io(Tecla);
}

/* _http_conn_new(): create and install new http connection with fd.
*/
static void
_http_conn_new(u2_http *htp_u, c3_i fid_i)
{
  u2_hcon *hon_u = malloc(sizeof(*hon_u));

  hon_u->coq_l = htp_u->coq_l++;
  hon_u->seq_l = 1;

  ev_io_init(&hon_u->wax_u, _http_conn_cb, fid_i, EV_READ);
  ev_io_start(u2_Host.lup_u, &hon_u->wax_u);

  hon_u->ruc_u = 0;
  hon_u->req_u = 0;
  hon_u->qer_u = 0;

  hon_u->htp_u = htp_u;
  hon_u->nex_u = htp_u->hon_u;
  htp_u->hon_u = hon_u;
}

/* _http_req_find(): find http request by sequence.
*/
static u2_hreq*
_http_req_find(u2_hcon* hon_u, c3_w seq_l)
{
  u2_hreq* req_u = hon_u->req_u;

  //  XX glories of linear search
  //
  while ( req_u ) {
    if ( seq_l == req_u->seq_l ) {
      return req_u;
    }
    req_u = req_u->nex_u;
  }
  return 0;
}

/* _http_conn_find(): find http connection by sequence.
*/
static u2_hcon*
_http_conn_find(u2_http *htp_u, c3_w coq_l)
{
  u2_hcon* hon_u = htp_u->hon_u;

  //  XX glories of linear search
  //
  while ( hon_u ) {
    if ( coq_l == hon_u->coq_l ) {
      return hon_u;
    }
    hon_u = hon_u->nex_u;
  }
  return 0;
}

/* _http_list_cb(): callback for http listener.
*/
static void
_http_list_cb(struct ev_loop *lup_u, struct ev_io* wax_u, int revents)
{
  u2_http *htp_u = (void *)wax_u;
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
      // fprintf(stderr, "http: new connection %d\r\n", fid_i);
      _http_conn_new(htp_u, fid_i);
    }
  }
}

/* _http_heds_to_list(): C headers to list.
*/
static u2_noun
_http_heds_to_list(u2_hhed* hed_u)
{
  if ( 0 == hed_u ) {
    return u2_nul;
  } else {
    return u2nc(u2nc(u2_ci_string(hed_u->nam_c),
                     u2_ci_string(hed_u->val_c)),
                _http_heds_to_list(hed_u->nex_u));
  }
}

/* _http_list_to_heds(): list to C headers.
*/
static u2_hhed*
_http_list_to_heds(u2_noun lix)
{
  u2_noun  yix = lix;
  u2_hhed* hed_u = 0;

  while ( 1 ) {
    if ( u2_nul == lix ) {
      break;
    } 
    else {
      u2_noun  i_lix = u2h(lix);
      u2_noun  pi_lix = u2h(i_lix);
      u2_noun  qi_lix = u2t(i_lix);
      u2_noun  t_lix = u2t(lix);
      u2_hhed* nex_u = malloc(sizeof(u2_hhed));

      nex_u->nam_c = u2_cr_string(pi_lix);
      nex_u->val_c = u2_cr_string(qi_lix);
      nex_u->nex_u = hed_u;

      hed_u = nex_u;
      lix = t_lix;
    }
  }
  u2z(yix);
  return hed_u;
}

#if 0
/* _http_map_to_heds(): http header noun to C.
*/
static u2_hhed*
_http_map_to_heds(u2_noun lom)
{
  return _http_list_to_heds(u2_ckd_by_tap(lom, u2_nul));
}

/* http_heds_to_map(): http header C to noun.
*/
static u2_noun
_http_heds_to_map(u2_hhed* hed_u)
{
  return u2_ckd_by_gas(u2_nul, _http_heds_to_list(hed_u));
}
#endif

/* _http_bods_to_octs: translate body into octet-stream noun.
*/
static u2_noun
_http_bods_to_octs(u2_hbod* bod_u)
{
  c3_w    len_w;
  c3_y*   buf_y;
  u2_noun cos;

  {
    u2_hbod* bid_u;

    len_w = 0;
    for ( bid_u = bod_u; bid_u; bid_u = bid_u->nex_u ) {
      len_w += bid_u->len_w;
    }
  }
  buf_y = malloc(len_w);

  {
    c3_y* ptr_y = buf_y;

    while ( bod_u ) {
      memcpy(ptr_y, bod_u->hun_y, bod_u->len_w);
      ptr_y += bod_u->len_w;
      bod_u = bod_u->nex_u;
    }
  }
  cos = u2_ci_bytes(len_w, buf_y);
  free(buf_y);
  return cos;
}

/* _http_octs_to_bod(): translate octet-stream noun into body.
*/
static u2_hbod*
_http_octs_to_bod(u2_noun oct)
{
  c3_w len_w;

  if ( !u2_fly_is_cat(u2h(oct)) ) {
    //  2GB max
    u2_cm_bail(c3__fail); return 0;
  }
  len_w = u2h(oct);

  {
    u2_hbod* bod_u = malloc(len_w + sizeof(*bod_u));

    bod_u->len_w = len_w;
    u2_cr_bytes(0, len_w, bod_u->hun_y, u2t(oct));
   
    bod_u->nex_u = 0;

    u2z(oct);
    return bod_u;
  }
}

/* _http_pox_to_noun(): translate srv/con/req to path noun (pox).
*/
static u2_noun
_http_pox_to_noun(c3_w sev_l, c3_w coq_l, c3_w seq_l)
{
  u2_reck* rec_u = &u2_Host.rec_u[0];

  return u2nq(u2_cn_mung(u2k(rec_u->toy.scot), u2nc(c3_s2('u','x'), sev_l)),
              u2_cn_mung(u2k(rec_u->toy.scot), u2nc(c3_s2('u','d'), coq_l)),
              u2_cn_mung(u2k(rec_u->toy.scot), u2nc(c3_s2('u','d'), seq_l)),
              u2_nul);
}

/* _http_request_to_noun(): translate http request into noun, or u2_none.
*/
static u2_noun
_http_request_to_noun(u2_hreq* req_u)
{
  u2_noun med, url, hed, bod;

  switch ( req_u->met_e ) {
    default: fprintf(stderr, "strange request\r\n"); return u2_none;
    case u2_hmet_get: { med = c3__get; break; }
    case u2_hmet_post: { med = c3__post; break; }
  } 
  url = u2_ci_string(req_u->url_c);
  hed = _http_heds_to_list(req_u->hed_u);
  bod = req_u->bod_u ? u2nc(u2_nul, _http_bods_to_octs(req_u->bod_u))
                     : u2_nul;

  return u2nq(med, url, hed, bod);
}

/* _http_slay_mole(): parse simple mole.
*/
static c3_d
_http_slay_mole(u2_noun fot, u2_noun san)
{
  u2_reck* rec_u = &u2_Host.rec_u[0];
  u2_noun  uco   = u2_cn_mung(u2k(rec_u->toy.slay), san);
  u2_noun  p_uco, q_uco, r_uco, s_uco;

  if ( (u2_no == u2_cr_qual(uco, &p_uco, &q_uco, &r_uco, &s_uco)) ||
       (0 != p_uco) ||
       (0 != q_uco) ||
       (u2_no == u2_sing(fot, r_uco)) )
  {
    fprintf(stderr, "strange mole\r\n"); return 0;

    u2z(fot);
    u2z(uco);
    return 0;
  }
  else {
    c3_d say_d = u2_cr_chub(0, s_uco);

    u2z(uco);
    return say_d;
  }
}

/* _http_noun_to_response(): translate path/noun into http response.
*/
static u2_hrep*
_http_noun_to_response(u2_noun pox, u2_noun rep)
{
  u2_noun p_rep, q_rep, r_rep;
  u2_noun p_pox, q_pox, r_pox, s_pox;

  if ( u2_no == u2_cr_trel(rep, &p_rep, &q_rep, &r_rep) ) {
    fprintf(stderr, "strange response\r\n"); 
    u2z(pox); u2z(rep); return 0;
  }
  if ( (u2_no == u2_cr_qual(pox, &p_pox, &q_pox, &r_pox, &s_pox)) ||
       (0 != s_pox) )
  {
    fprintf(stderr, "strange response\r\n"); 
    u2z(pox); u2z(rep); return 0;
  }

  {
    u2_hrep* rep_u = malloc(sizeof(u2_hrep));

    rep_u->sev_l = (c3_l)_http_slay_mole(c3_s2('u','x'), u2k(p_pox));
    rep_u->coq_l = (c3_l)_http_slay_mole(c3_s2('u','d'), u2k(q_pox));
    rep_u->seq_l = (c3_l)_http_slay_mole(c3_s2('u','d'), u2k(r_pox));

    rep_u->sas_w = p_rep;
    rep_u->hed_u = _http_list_to_heds(u2k(q_rep));
    rep_u->bod_u = (u2_nul == r_rep) ? 0 : _http_octs_to_bod(u2k(u2t(r_rep)));

    u2z(pox); u2z(rep); return rep_u;
  }
}

/* u2_ve_http_request(): dispatch http request, returning null if async.
*/
u2_hrep*
u2_ve_http_request(u2_hreq* req_u)
{
  u2_noun req = _http_request_to_noun(req_u);
  u2_noun pox = _http_pox_to_noun(req_u->hon_u->htp_u->sev_l,
                                  req_u->hon_u->coq_l,
                                  req_u->seq_l); 

  u2_reck_http_request(&u2_Host.rec_u[0], u2_yes, pox, req);
  return 0;
}

/* _http_respond(): transmit http response.
*/
static void
_http_respond(u2_hrep* rep_u)
{
  u2_http* htp_u = u2_Host.htp_u;
  u2_hcon* hon_u;
  u2_hreq* req_u;

  if ( htp_u->sev_l != rep_u->sev_l ) {
    fprintf(stderr, "http: server mismatch! %d, %d\r\n", 
              htp_u->sev_l,
              rep_u->sev_l);
    return;
  }

  if ( !(hon_u = _http_conn_find(htp_u, rep_u->coq_l)) ) {
    fprintf(stderr, "http: connection not found: %d\r\n", rep_u->coq_l);
    return;
  }
  if ( !(req_u = _http_req_find(hon_u, rep_u->seq_l)) ) {
    fprintf(stderr, "http: request not found: %d\r\n", rep_u->seq_l);
    return;
  }
  _http_respond_request(req_u, rep_u);
}

/* u2_ve_http_respond(): queue response.
*/
void
u2_ve_http_respond(u2_noun pox, u2_noun rep)
{
  u2_hrep* rep_u = _http_noun_to_response(pox, rep);

  if ( !rep_u ) {
    fprintf(stderr, "http: response dropped\r\n");
  }
  else _http_respond(rep_u);
}

u2_bean
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

    /*  Try ascending ports.
    */
    while ( 1 ) {
      add_k.sin_port = htons(por_w);

      if ( bind(fid_i, (struct sockaddr *)&add_k, sizeof(add_k)) < 0 ) {
        if ( EADDRINUSE == errno ) {
          por_w++; 
          continue;
        }
        else {
          perror("http: bind");
          return u2_no;
        }
      }
      fprintf(stderr, "http: live on %d\n", por_w);
      break;
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

    {
      struct timeval tp;

      gettimeofday(&tp, 0);
      htp_u->sev_l = 0x7fffffff & (((c3_w) tp.tv_sec) ^ (getpid() << 16));
    }
    htp_u->coq_l = 1;

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
