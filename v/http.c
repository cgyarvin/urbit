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

#include "../outside/jhttp/http_parser.h"
#include "all.h"
#include "v/vere.h"

/* u2_ve_http_mark(): mark http server memory for gc.
*/
c3_w
u2_ve_http_mark()
{
  c3_w     siz_w = 0;
  u2_http* htp_h = u2_Host.htp_h;

  while ( htp_h ) {
    // u2_hcon* con_n = htp_h->con_n;

    siz_w += u2_cm_mark_noun(htp_h->vox);
#if 0
    while ( con_n ) {
      siz_w += u2_cm_mark_ptr(con_n);
      con_n = con_n->nex_n;
    }
#endif
    // siz_w += u2_cm_mark_ptr(htp_h);
    htp_h = htp_h->nex_h;
  }
  return siz_w;
}

/* _http_conn_cb(): callback for http connections.
*/
static void
_http_conn_cb(struct ev_loop *lup_v, struct ev_io* wax_w, int revents)
{
  // u2_hcon *con_n = (void *)wax_w;
  u2_flag inn    = (revents & EV_READ) ? u2_yes : u2_no;
  u2_flag out    = (revents & EV_WRITE) ? u2_yes : u2_no;

  printf("action on fd %d inn %d out %d\n", wax_w->fd, inn, out);
}

/* _http_conn_new(): new http connection with fd.
*/
static void
_http_conn_new(u2_http *srv_h, c3_i fid_i)
{
  u2_hcon *hon_n = malloc(sizeof(*hon_n));
  
  hon_n->srv_h = srv_h;
  hon_n->nex_n = srv_h->con_n;
  srv_h->con_n = hon_n;

  ev_io_init(&hon_n->wax_w, _http_conn_cb, fid_i, EV_READ);
  ev_io_start(u2_Host.lup_v, &hon_n->wax_w);
}

/* _http_list_cb(): callback for http listener.
*/
static void
_http_list_cb(struct ev_loop *lup_v, struct ev_io* wax_w, int revents)
{
  u2_http *srv_h = (void *)wax_w;
  c3_assert(revents & EV_READ);

  {
    socklen_t          len_o = sizeof(struct sockaddr_in);
    struct sockaddr_in add_k;
    c3_i               fid_i;

    fid_i = accept(wax_w->fd, (struct sockaddr *)&add_k, &len_o);
    if ( fid_i < 0 ) {
      perror("http: accept");
    }
    else _http_conn_new(srv_h, fid_i);
  }
}

#if 0
/* _http_conn_dead(): free http connection, close fd.
*/
static void
_http_conn_dead(u2_hcon *con_n)
{
  _ev_io_stop(u2_Host.lup_v, &con_n->wax_w);
  close(con_n->wax_w.fd);

  {
    struct _u2_http *srv_h = con_n->srv_h;

    if ( srv_h->con_n == con_n ) {
      srv_h->con_n = con_n->nex_n;
    }
    else {
      u2_hcon *pre_n = srv_h->con_n;

      while ( pre_n ) {
        if ( pre_n->nex_n == con_n ) {
          pre_n->nex_n = con_n->nex_n;
        }
        else pre_n = pre_n->nex_n;
      }
      c3_assert(!"zombie connection");
    }
  }
  free(con_n);
}
#endif

u2_flag
u2_ve_http_start(u2_noun vox, c3_w por_w)
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
    u2_http *htp_h = malloc(sizeof(*htp_h));

    htp_h->con_n = 0;
    htp_h->nex_h = 0;
    htp_h->por_w = por_w;
    htp_h->vox = vox;

    ev_io_init(&htp_h->wax_w, _http_list_cb, fid_i, EV_READ);
    ev_io_start(u2_Host.lup_v, &htp_h->wax_w);

    htp_h->nex_h = u2_Host.htp_h;
    u2_Host.htp_h = htp_h;
  }
  return u2_yes;
}
