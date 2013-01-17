/* v/loop.c
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

#include "all.h"
#include "v/vere.h"

/* _lo_htls(): callback for http listener.
** _lo_htcn(): callback for http connections.
** _lo_cons(): callback for main console.
*/
static void _lo_htls(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i);
static void _lo_htcn(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i);
static void _lo_cons(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i);


/**  console control - move to proper file
**/
  extern GetLine *Tecla;
  ev_io Stdin_watcher;
  u2_bean Ded = u2_no;

  static c3_c*
  _get_line(u2_reck* rec_u)
  {
    u2_noun pot = u2_reck_prick
                      (rec_u,
                       u2nt(c3__eyre, 
                            c3__prod,
                            u2nq(c3__gold, c3__term, '0', u2_nul)));
    c3_c* pot_c;
    c3_c* out_c;

    if ( u2_none == pot ) {
      gl_normal_io(Tecla);
      exit(1);
    }
    if ( u2_nul == pot ) {
      pot_c = strdup(": ");
    } else {
      pot_c = u2_cr_string(u2t(u2t(pot)));
    }

    out_c = gl_get_line(Tecla, pot_c, 0, -1);

    u2z(pot);
    free(pot_c);

    return out_c;
  }

  void 
  u2_cons_io_init(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
    ev_io_init(&Stdin_watcher, _lo_cons, 0, EV_READ);
    ev_io_start(lup_u, &Stdin_watcher);

    {
      c3_c* lin_c;
    
      lin_c = _get_line(rec_u);
      c3_assert(!lin_c && (GLR_BLOCKED == gl_return_status(Tecla)));
    }
  }

  void
  u2_cons_io_poll(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
    if ( u2_yes == Ded ) {
      fprintf(stderr, "\nconsole: stop\n");
      ev_unloop(lup_u, EVUNLOOP_ALL);
    }
  }

  void
  u2_cons_io_stop(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
    ev_io_stop(lup_u, &Stdin_watcher);
    gl_normal_io(Tecla);
  }

  void
  u2_cons_io_suck(u2_reck*      rec_u,
                  struct ev_io* wax_u)
  {
    c3_c* lin_c;
    
    lin_c = _get_line(rec_u);

    if ( !lin_c ) {
      if ( GLR_BLOCKED != gl_return_status(Tecla) ) {
        Ded = u2_yes;
      }
      else { 
        return;
      }
    }
    else {
      c3_w  len_w = strlen(lin_c);
      c3_c* out_c = malloc(len_w);

      strncpy(out_c, lin_c, (len_w - 1));
      out_c[len_w - 1] = 0;

      if ( !*out_c ) {
        // printf(": "); fflush(stdout);
        free(out_c);
        return;
      }
      else {
        gl_normal_io(Tecla);
        u2_ve_line(out_c); 
        free(out_c);

        gl_raw_io(Tecla);
        _get_line(rec_u);

        // printf(": "); fflush(stdout);
      }
    }
  }

  void
  u2_cons_io_spin(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
    ev_io_start(lup_u, &Stdin_watcher);
    gl_raw_io(Tecla);
  }

  void 
  u2_cons_io_exit(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
    gl_io_mode(Tecla, GL_NORMAL_MODE);
  }

/* u2_http_io_init(): initialize http I/O.
*/
void 
u2_http_io_init(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
}

/* u2_http_io_exit(): terminate http I/O.
*/
void 
u2_http_io_exit(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
}

/* u2_http_io_spin(): start http server(s).
*/
void
u2_http_io_spin(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_http* htp_u;

  for ( htp_u = u2_Host.htp_u; htp_u; htp_u = htp_u->nex_u) {
    u2_hcon* hon_u;

    if ( (u2_yes == htp_u->nuw) || (u2_yes == htp_u->ded) ) {
      continue; 
    } else {
      ev_io_start(lup_u, &htp_u->wax_u);
    }

    for ( hon_u = htp_u->hon_u; hon_u; hon_u = hon_u->nex_u ) {
      if ( (u2_yes == htp_u->nuw) || (u2_yes == htp_u->ded) ) {
        continue; 
      } else {
        ev_io_start(lup_u, &hon_u->wax_u);
      }
    }
  }
}

/* u2_http_io_stop(): stop http servers.
*/
void
u2_http_io_stop(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_http* htp_u;

  for ( htp_u = u2_Host.htp_u; htp_u; htp_u = htp_u->nex_u) {
    u2_hcon* hon_u;

    if ( (u2_yes == htp_u->nuw) || (u2_yes == htp_u->ded) ) {
      continue; 
    } else {
      ev_io_stop(lup_u, &htp_u->wax_u);
    }

    for ( hon_u = htp_u->hon_u; hon_u; hon_u = hon_u->nex_u ) {
      if ( (u2_yes == htp_u->nuw) || (u2_yes == htp_u->ded) ) {
        continue; 
      } else {
        ev_io_stop(lup_u, &hon_u->wax_u);
      }
    }
  }
}

/* u2_http_io_poll(): update http IO state.
*/
void
u2_http_io_poll(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_http** hyp_u;

  for ( hyp_u = &(u2_Host.htp_u); *hyp_u; hyp_u = &((*hyp_u)->nex_u) ) {
    u2_http* htp_u = *hyp_u;

    if ( u2_yes == htp_u->nuw ) {
      c3_i fid_i;

      /* Open, bind and listen on the socket.
      */
      {
        struct sockaddr_in add_k;

        if ( (fid_i = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
          perror("http: socket");
          continue;
        }

        add_k.sin_family = AF_INET;
        add_k.sin_addr.s_addr = INADDR_ANY;

        /*  Try ascending ports.
        */
        while ( 1 ) {
          add_k.sin_port = htons(htp_u->por_w);

          if ( bind(fid_i, (struct sockaddr *)&add_k, sizeof(add_k)) < 0 ) {
            if ( EADDRINUSE == errno ) {
              htp_u->por_w++; 
              continue;
            }
            else {
              perror("http: bind");
              break;
            }
          }
          fprintf(stderr, "http: live on %d\n", htp_u->por_w);
          break;
        }
        if ( listen(fid_i, 3) < 0 ) {
          perror("http: listen");
          continue;
        }
      }
  
      /* Create and activate the server structures.
      */
      {
        {
          struct timeval tp;

          gettimeofday(&tp, 0);
          htp_u->sev_l = 0x7fffffff & (((c3_w) tp.tv_sec) ^ (getpid() << 16));
        }
        htp_u->coq_l = 1;

        htp_u->nuw = u2_no;
        htp_u->ded = u2_no;

        htp_u->hon_u = 0;
        htp_u->nex_u = 0;

        ev_io_init(&htp_u->wax_u, _lo_htls, fid_i, EV_READ);

        htp_u->nex_u = u2_Host.htp_u;
        u2_Host.htp_u = htp_u;
      }
    }
    else if ( u2_yes == htp_u->ded ) { 
      c3_assert(!"dead");   //  don't need this right now
    }
    else {
      u2_hcon** hyn_u;

      hyn_u = &(htp_u->hon_u); 
      while ( *hyn_u ) { 
        u2_hcon* hon_u = *hyn_u;

        if ( u2_yes == hon_u->nuw ) {
          ev_io_init(&hon_u->wax_u, _lo_htcn, hon_u->wax_u.fd, EV_READ);

          hon_u->coq_l = htp_u->coq_l++;
          hon_u->seq_l = 1;

          hon_u->nuw = u2_no;
          hon_u->ded = u2_no;

          hon_u->ruc_u = 0;
          hon_u->req_u = 0;
          hon_u->qer_u = 0;
        }
        else if ( u2_yes == hon_u->ded ) {
          close(hon_u->wax_u.fd);

          while ( 0 != hon_u->req_u ) {
            u2_hreq* req_u = hon_u->req_u;
            u2_hreq* nex_u = req_u->nex_u;

            _http_req_free(req_u);
            hon_u->req_u = nex_u;
          }

          *hyn_u = hon_u->nex_u;
          free(hon_u);
          continue;
        }
        else {
          c3_i ver_i = 0;

          ver_i |= EV_READ;   //  no constraint on reading right now
          if ( hon_u->req_u && hon_u->req_u->rub_u ) {
            ver_i |= EV_WRITE;
          }
          ev_io_set(&hon_u->wax_u, hon_u->wax_u.fd, ver_i);
        }
        hyn_u = &(hon_u->nex_u);
      }
    }
  }
}

/* _lo_init(): initialize I/O across the process.
*/
static void
_lo_init(u2_reck*        rec_u,
         struct ev_loop* lup_u)
{
  u2_cons_io_init(rec_u, lup_u);
  u2_http_io_init(rec_u, lup_u);
}

/* _lo_exit(): terminate I/O across the process.
*/
static void
_lo_exit(u2_reck*        rec_u,
         struct ev_loop* lup_u)
{
  u2_cons_io_exit(rec_u, lup_u);
  u2_http_io_exit(rec_u, lup_u);
}

/* _lo_stop(): stop event I/O across the process.
*/
static void
_lo_stop(u2_reck*        rec_u,
         struct ev_loop* lup_u)
{
  u2_http_io_stop(rec_u, lup_u);
  u2_cons_io_stop(rec_u, lup_u);
}

/* _lo_poll(): reset event flags across the process.
*/
static void
_lo_poll(u2_reck*        rec_u,
         struct ev_loop* lup_u)
{
  u2_http_io_poll(rec_u, lup_u);
  u2_cons_io_poll(rec_u, lup_u);
}

/* _lo_spin(): restart event I/O across the process.
*/
static void
_lo_spin(u2_reck*        rec_u,
         struct ev_loop* lup_u)
{
  u2_http_io_spin(rec_u, lup_u);
  u2_cons_io_spin(rec_u, lup_u);
}

/* _lo_suck(): process input on a socket.
*/
static void
_lo_suck(u2_reck*      rec_u,
         struct ev_io* wax_u,
         u2_noun       how)
{
  switch ( how ) {
    default: c3_assert(0); break;

    case c3__cons: u2_cons_io_suck(rec_u, wax_u); break;
    case c3__htcn: u2_http_io_suck_conn(rec_u, wax_u); break;
    case c3__htls: u2_http_io_suck_lisn(rec_u, wax_u); break;
  }
}

/* _lo_fuck(): process output on a socket.
*/
static void
_lo_fuck(u2_reck*      rec_u,
         struct ev_io* wax_u,
         u2_noun       how)
{
  switch ( how ) {
    default: c3_assert(0); break;

    case c3__cons: u2_cons_io_fuck(rec_u, wax_u); break;
    case c3__htcn: u2_http_io_fuck_conn(rec_u, wax_u); break;
    case c3__htls: u2_http_io_fuck_lisn(rec_u, wax_u); break;
  }
}

/* _lo_call(): central callback.
*/
static void
_lo_call(u2_reck*        rec_u,
         struct ev_loop* lup_u,
         struct ev_io*   wax_u,
         u2_noun         how,
         c3_i            revents)
{
  u2_bean inn = (revents & EV_READ) ? u2_yes : u2_no;
  u2_bean out = (revents & EV_WRITE) ? u2_yes : u2_no;

  _lo_stop(rec_u, lup_u);
  {
    //  update time
    //
    u2_reck_time(rec_u);

    //  sync with filesystem (ugh)
    //
    u2_reck_sync(rec_u);

    //  process input on this socket
    //
    if ( u2_yes == inn ){
      _lo_suck(rec_u, wax_u, how);
    }

    //  process output on this socket
    //
    if ( u2_yes == out ) {
      _lo_fuck(rec_u, wax_u, how);
    }

    //  process actions
    //
    u2_reck_work(rec_u);
   
  }
  _lo_poll(rec_u, lup_u);
  _lo_spin(rec_u, lup_u);
}

static void _lo_htls(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i)
  { _lo_call(&u2_Host.rec_u[0], lup_u, wax_u, c3__htls, rev_i); }
static void _lo_htcn(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i)
  { _lo_call(&u2_Host.rec_u[0], lup_u, wax_u, c3__htcn, rev_i); }
static void _lo_cons(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i)
  { _lo_call(&u2_Host.rec_u[0], lup_u, wax_u, c3__cons, rev_i); }


static void
_launch_cons(u2_reck* rec_u)
{
  Tecla = new_GetLine(16384, 4096);
  gl_io_mode(Tecla, GL_SERVER_MODE);
}

static void 
_launch_http(u2_reck* rec_u, c3_w por_w)
{
  u2_http *htp_u = malloc(sizeof(*htp_u));

  {
    struct timeval tp;

    gettimeofday(&tp, 0);
    htp_u->sev_l = 0x7fffffff & (((c3_w) tp.tv_sec) ^ (getpid() << 16));
  }
  htp_u->coq_l = 1;
  htp_u->por_w = por_w;

  htp_u->nuw = u2_yes;
  htp_u->ded = u2_no;

  htp_u->hon_u = 0;
  htp_u->nex_u = 0;
  htp_u->por_w = por_w;

  htp_u->nex_u = u2_Host.htp_u;
  u2_Host.htp_u = htp_u;
}

/* u2_lo_loop(): enter main event loop.
*/
u2_lo_loop(u2_reck* rec_u)
{
  _launch_cons(rec_u);
  _launch_http(rec_u, 8080);
  {
    struct ev_loop *lup_u = ev_default_loop(0);

    _lo_init(rec_u, lup_u);
    ev_loop(lup_u, 0);
    _lo_exit(rec_u, lup_u);
  }
  return 0;
}
