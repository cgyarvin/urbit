/* v/unix.c
**
**  This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <dirent.h>
#include <stdint.h>
#include <ev.h>
#include <curses.h>
#include <termios.h>
#include <term.h>

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

#define u2R  ((u2_reck *) &u2_Host.arv_u)     //  new school

static void _lo_unix(struct ev_loop *lup_u, struct ev_timer* tim_u, c3_i rev_i)
  { u2_lo_call(u2_Host.arv_u, lup_u, tim_u, c3__unix, rev_i); }

static void _lo_sign(struct ev_loop *lup_u, struct ev_signal* sil_u, c3_i rev_i)
  { u2_lo_call(u2_Host.arv_u, lup_u, sil_u, c3__unix, rev_i); }

/* _unix_hot_gain(): enter sync, syncing out iff sow == yes.
*/
static struct _u2_uhot*
_unix_hot_gain(u2_reck* rec_u, u2_noun who, u2_bean sow)
{
  return 0;
}

/* _unix_hot_lose(): release and free() a host directory.
*/
static void
_unix_hot_lose(u2_reck* rec_u, u2_uhot* hot_u)
{
}

/* u2_unix_ef_edit(): apply edits pushed out by clay.
*/
void
u2_unix_ef_edit(u2_reck* rec_u, u2_noun who, u2_noun syd, u2_noun nor)
{
}

/* u2_unix_ef_refresh_root(): refresh the root.
*/
void
u2_unix_ef_refresh_root(u2_reck* rec_u, u2_bean liv)
{
  u2_bean  sow = (liv == u2_yes) ? u2_yes : u2_Host.ops_u.sow;
  u2_unix* unx_u = &u2_Host.unx_u;
  u2_noun  who;
  u2_uhot* hot_u; 

  //  find owners without directories
  {
    for ( who = rec_u->own; u2_nul != who; who = u2t(who) ) {
      mpz_t who_mp;

      u2_cr_mp(who_mp, u2h(who));
      for ( hot_u = unx_u->hot_u; 
            hot_u && (0 != mpz_cmp(who_mp, hot_u->who_mp));
            hot_u = hot_u->nex_u );

      if ( 0 == hot_u ) {
        hot_u = _unix_hot_gain(rec_u, u2k(who), sow);
      }
      if ( 0 != hot_u ) {
        hot_u->nex_u = unx_u->hot_u;
        unx_u->hot_u = hot_u;
      }
    }
  }

  //  find directories without owners
  {
    u2_uhot** het_u = &(unx_u->hot_u);

    while ( 0 != (hot_u=*het_u) ) {
      for ( who = rec_u->own; u2_nul != who; who = u2t(who) ) {
        mpz_t who_mp;

        u2_cr_mp(who_mp, u2h(who));
        if ( 0 == mpz_cmp(who_mp, hot_u->who_mp) ) {
          break;
        }
        mpz_clear(who_mp);
      }

      if ( u2_nul == who ) {
        *het_u = hot_u->nex_u;
        
        _unix_hot_lose(rec_u, hot_u);
        continue;
      }
      else {
        het_u = &(hot_u->nex_u);
      }
    }
  }
}

/* u2_unix_io_init(): initialize unix sync.
*/
void 
u2_unix_io_init(u2_reck* rec_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  ev_timer_init(&unx_u->tim_u, _lo_unix, 10000.0, 0.);
  unx_u->alm = u2_no;
  unx_u->sig_u = 0;

  {
    u2_usig* sig_u;

    sig_u = malloc(sizeof(u2_usig));
    ev_signal_init(&sig_u->sil_u, _lo_sign, SIGTERM);

    sig_u->nex_u = unx_u->sig_u;
    unx_u->sig_u = sig_u;
  }
  {
    u2_usig* sig_u;

    sig_u = malloc(sizeof(u2_usig));
    ev_signal_init(&sig_u->sil_u, _lo_sign, SIGWINCH);

    sig_u->nex_u = unx_u->sig_u;
    unx_u->sig_u = sig_u;
  }

  // u2_unix_refresh_root(rec_u, u2_no);
}

/* u2_unix_io_exit(): terminate unix I/O.
*/
void 
u2_unix_io_exit(u2_reck* rec_u)
{
}

/* u2_unix_io_spin(): start unix server(s).
*/
void
u2_unix_io_spin(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  if ( u2_yes == unx_u->alm ) {
    ev_timer_start(lup_u, &unx_u->tim_u);
  }

  {
    u2_usig* sig_u;

    for ( sig_u = unx_u->sig_u; sig_u; sig_u = sig_u->nex_u ) {
      ev_signal_start(lup_u, &sig_u->sil_u);
    }
  }
}

/* u2_unix_io_stop(): stop unix servers.
*/
void
u2_unix_io_stop(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  if ( u2_yes == unx_u->alm ) {
    ev_timer_stop(lup_u, &unx_u->tim_u);
  }

  {
    u2_usig* sig_u;

    for ( sig_u = unx_u->sig_u; sig_u; sig_u = sig_u->nex_u ) {
      ev_signal_stop(lup_u, &sig_u->sil_u);
    }
  }
}

/* u2_unix_io_poll(): update unix IO state.
*/
void
u2_unix_io_poll(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  {
    u2_noun wen = u2_reck_keep(rec_u, u2nt(c3__gold, c3__clay, u2_nul));
    
    if ( (u2_nul != wen) && 
         (u2_yes == u2du(wen)) &&
         (u2_yes == u2ud(u2t(wen))) )
    {
      double gap_g = u2_time_gap_double(u2k(rec_u->now), u2k(u2t(wen)));

      unx_u->alm = u2_yes;
      ev_timer_set(&unx_u->tim_u, gap_g, 0.);
    }
    else {
      unx_u->alm = u2_no;
    }
  }
}

/* u2_unix_io_time(): time event on unix channel.
*/
void
u2_unix_io_time(u2_reck*         rec_u,
                struct ev_timer* tim_u)
{
  u2_reck_plan
    (rec_u,
     u2nt(c3__gold, c3__clay, u2_nul),
     u2nc(c3__wake, u2_nul));
}


/* u2_unix_io_stat(): fs event on storage.
*/
void
u2_unix_io_stat(u2_reck*        rec_u,
                struct ev_stat* sat_u)
{
}

/* u2_unix_io_sign(): signal event.
*/
void
u2_unix_io_sign(u2_reck*          rec_u,
                struct ev_signal* sil_u)
{
  switch ( sil_u->signum ) {
    case SIGTERM: u2_Host.liv = u2_no; break;
    case SIGWINCH: u2_term_ef_winch(rec_u); break;
  }
}
