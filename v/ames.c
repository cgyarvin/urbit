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
#include <curses.h>
#include <termios.h>
#include <term.h>

#include "all.h"
#include "v/vere.h"

static void _lo_ames(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i)
  { u2_lo_call(&u2_Host.rec_u[0], lup_u, wax_u, c3__ames, rev_i); }

static void _lo_amat(struct ev_loop *lup_u, struct ev_timer* tim_u, c3_i rev_i)
  { u2_lo_call(&u2_Host.rec_u[0], lup_u, tim_u, c3__ames, rev_i); }


/* u2_ames_ef_send(): send packet to network.
*/
void
u2_ames_ef_send(u2_reck* rec_u,
                u2_noun  lan,
                u2_noun  pac)
{
  u2_ames* sam_u = &u2_Host.sam_u;
  c3_s     por_s = (c3_s)u2_cr_word(0, u2h(u2t(lan)));
  c3_w     pip_w = u2_cr_word(0, u2t(u2t(lan)));
  c3_w     len_w = u2_cr_met(3, pac);

  {
    u2_apac* pac_u = malloc(sizeof(u2_apac) + len_w);

    u2_cr_bytes(0, len_w, pac_u->hun_y, pac);
    pac_u->nex_u = 0;
    pac_u->len_w = len_w;
    pac_u->pip_w = pip_w;
    pac_u->por_s = por_s;

    if ( sam_u->tou_u ) {
      sam_u->tou_u->nex_u = pac_u;
    } else {
      c3_assert(!sam_u->out_u);
      sam_u->out_u = pac_u;
    }
    sam_u->tou_u = pac_u;
  }
}

/* u2_ames_io_init(): initialize ames I/O.
*/
void 
u2_ames_io_init(u2_reck* rec_u)
{
  u2_ames* sam_u = &u2_Host.sam_u;

  c3_assert(u2_nul != rec_u->own);
  {
    c3_w pip_w = 0x7f000001;    //  hardbound to localhost 
    c3_s por_s;
    c3_i fid_i;

    if ( rec_u->our < 256 ) {
      //  Fixed port for imperial servers.
      //
      por_s = 13337 + rec_u->our;
    } 
    else {
      por_s = 0;
    }

    if ( (fid_i = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      perror("ames: socket");
      c3_assert(0);
    }

    //  Bind.
    {
      struct sockaddr_in add_k;
      socklen_t          add_t = sizeof(add_k);

      memset(&add_k, 0, sizeof(add_k));
      add_k.sin_family = AF_INET;
      add_k.sin_addr.s_addr = htonl(INADDR_ANY);
      add_k.sin_port = htons(por_s);

      if ( bind(fid_i, (struct sockaddr *)&add_k, sizeof(add_k)) < 0 ) {
        if ( EADDRINUSE == errno ) {
          fprintf(stderr, "bind: address in use\r\n");
          c3_assert(0);
        }
        else {
          perror("bind");
          c3_assert(0);
        }
      }

      getsockname(fid_i, (struct sockaddr *)&add_k, &add_t);
      c3_assert(add_k.sin_port);
      por_s = ntohs(add_k.sin_port);

      fprintf(stderr, "ames: on localhost, UDP %d.\n", por_s);

      sam_u->pip_w = pip_w;
      sam_u->por_s = por_s;
      sam_u->out_u = sam_u->tou_u = 0;

      ev_io_init(&sam_u->wax_u, _lo_ames, fid_i, 0);
    }

    //  You are here.
    {
      // u2_noun pax = u2nt(c3__lead, c3__ames, u2_nul);
      u2_noun pax = u2nt(c3__gold, c3__ames, u2_nul);   //  XX no!
      u2_noun fav = u2nt(c3__home, 
                         u2k(rec_u->our),
                         u2nt(c3__if, por_s, u2_ci_words(1, &pip_w)));

      u2_reck_plan(rec_u, pax, fav);
    }

    //  Timer too.
    {
      ev_timer_init(&sam_u->tim_u, _lo_amat, 10000.0, 0.);
      sam_u->alm = u2_no;
    }
  }
}

/* u2_ames_io_exit(): terminate ames I/O.
*/
void 
u2_ames_io_exit(u2_reck* rec_u)
{
  u2_ames* sam_u = &u2_Host.sam_u;

  close(sam_u->wax_u.fd);
}

/* u2_ames_io_spin(): start ames server(s).
*/
void
u2_ames_io_spin(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_ames* sam_u = &u2_Host.sam_u;

  ev_io_start(lup_u, &sam_u->wax_u);
  if ( u2_yes == sam_u->alm ) {
    // uL(fprintf(uH, "timer start!\n"));
    ev_timer_start(lup_u, &sam_u->tim_u);
  }
}

/* u2_ames_io_stop(): stop ames servers.
*/
void
u2_ames_io_stop(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_ames* sam_u = &u2_Host.sam_u;

  ev_io_stop(lup_u, &sam_u->wax_u);

  if ( u2_yes == sam_u->alm ) {
    ev_timer_stop(lup_u, &sam_u->tim_u);
  }
}

/* u2_ames_io_poll(): update ames IO state.
*/
void
u2_ames_io_poll(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_ames* sam_u = &u2_Host.sam_u;
  c3_i     ver_i = 0;

  ver_i |= EV_READ;   //  no constraint on reading right now
  if ( sam_u->out_u  ) {
    ver_i |= EV_WRITE;
  }
  ev_io_set(&sam_u->wax_u, sam_u->wax_u.fd, ver_i);

  {
    u2_noun wen = u2_reck_wait(rec_u, u2nt(c3__gold, c3__ames, u2_nul));
    
    if ( (u2_nul != wen) && 
         (u2_yes == u2du(wen)) &&
         (u2_yes == u2ud(u2t(wen))) )
    {
      mpz_t now_mp, wen_mp, dif_mp;
      double sec_g = (((double)(1ULL << 32ULL)) * ((double)(1ULL << 32ULL)));
      double gap_g, dif_g;

      u2_cr_mp(now_mp, rec_u->now);
      u2_cr_mp(wen_mp, u2t(wen));
      mpz_init(dif_mp);
      mpz_sub(dif_mp, wen_mp, now_mp);

      dif_g = mpz_get_d(dif_mp) / sec_g;
      gap_g = (dif_g > 0.0) ? dif_g : 0.0;
      mpz_clear(dif_mp); mpz_clear(wen_mp); mpz_clear(now_mp);

      // uL(fprintf(uH, "ames: wait: %g\n", gap_g));

      sam_u->alm = u2_yes;
      ev_timer_set(&sam_u->tim_u, gap_g, 0.);
    }
    else {
      sam_u->alm = u2_no;
    }
  }
}

/* u2_ames_io_fuck(): output event on connection socket.
*/
void
u2_ames_io_fuck(u2_reck*      rec_u,
                struct ev_io* wax_u)
{
  u2_ames* sam_u = &u2_Host.sam_u;

  while ( 1 ) {
    u2_apac* pac_u = sam_u->out_u;
   
    if ( 0 == pac_u ) {
      break;
    }
    else {
      struct sockaddr_in add_k;

      if ( 1 == (pac_u->pip_w >> 8) ) {
        pac_u->por_s = 13337 + (pac_u->pip_w & 0xff);
        pac_u->pip_w = 0x7f000001;
      }

      memset(&add_k, 0, sizeof(add_k));
      add_k.sin_family = AF_INET;
      add_k.sin_addr.s_addr = htonl(pac_u->pip_w);
      add_k.sin_port = htons(pac_u->por_s);

      // uL(fprintf(uH, "sendto %x %d\n", pac_u->pip_w, pac_u->por_s));

      if ( pac_u->len_w != sendto(sam_u->wax_u.fd,
                                  pac_u->hun_y,
                                  pac_u->len_w,
                                  0,
                                  (struct sockaddr*)(void *)&add_k,
                                  sizeof(add_k)) )
      {
        if ( EAGAIN != errno ) {
          uL(fprintf(uH, "send: to %x:%d; error %s\n", 
                pac_u->pip_w, pac_u->por_s, strerror(errno)));
        }
      } 

      sam_u->out_u = sam_u->out_u->nex_u;

      if ( 0 == sam_u->out_u ) {
        c3_assert(pac_u == sam_u->tou_u);
        sam_u->tou_u = 0;
      }
      free(pac_u);
    }
  }
}

/* u2_ames_io_time(): time event on ames channel.
*/
void
u2_ames_io_time(u2_reck*         rec_u,
                struct ev_timer* tim_u)
{
  u2_reck_plan
    (rec_u,
     u2nt(c3__gold, c3__ames, u2_nul),    //  XX no!
     // u2nt(c3__lead, c3__ames, u2_nul),
     u2nc(c3__wake, u2_nul));
}

/* u2_ames_io_suck(): input event on listen socket.
*/
void
u2_ames_io_suck(u2_reck*      rec_u,
                struct ev_io* wax_u)
{
  c3_y               buf_y[65536];
  c3_ws              len_ws;
  struct sockaddr_in add_k;
  socklen_t          add_t;
  c3_s               por_s;
  c3_w               pip_w;

//  while ( 1 ) {

    add_t = sizeof(struct sockaddr_in);
    if ( -1 == (len_ws = recvfrom(wax_u->fd, 
                                  buf_y, 
                                  65536, 
                                  MSG_WAITALL,
                                  (struct sockaddr *)&add_k,
                                  &add_t)) )
    {
      if ( EAGAIN != errno ) {
        uL(fprintf(uH, "ames: error %d\n", errno));
      }
      return;
    }
    // por_s = ntohs(add_k.sin_port);
    // pip_w = ntohl(add_k.sin_addr.s_addr);

    por_s = ntohs(add_k.sin_port);         //??
    pip_w = ntohl(add_k.sin_addr.s_addr);  //??

    // uL(fprintf(stderr, "por_s %d, pip_w %x\n", por_s, pip_w));

    u2_reck_plan
      (rec_u,
       u2nt(c3__gold, c3__ames, u2_nul),    //  XX no!
       // u2nt(c3__lead, c3__ames, u2_nul),
       u2nt(c3__hear, 
            u2nt(c3__if, por_s, u2_ci_words(1, &pip_w)),
            u2_ci_bytes((c3_w)len_ws, buf_y)));
 // }
}
