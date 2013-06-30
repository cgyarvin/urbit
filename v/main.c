/* v/main.c
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
#include <signal.h>
#include <gmp.h>
#include <stdint.h>
#include <ev.h>
#include <sigsegv.h>
#include <curses.h>
#include <termios.h>
#include <term.h>

#define U2_GLOBAL
#define C3_GLOBAL
#include "all.h"
#include "v/vere.h"

/**  Legacy fixed jet linkage.  Destroy me please.
**/
    /* External drivers.
    */
      extern u2_ho_driver j2_da(k_191);
      extern u2_ho_driver j2_da(k_192);

    /* Built-in battery drivers.   Null `cos` terminates. 
    */
      u2_ho_driver *HostDriverBase[] = {
        &j2_k_191_d,
        &j2_da(k_192),
        0
      };

struct _u2_opts {
  c3_c*   cpu_c;
  c3_c*   inv_c;
  c3_w    kno_w;
  u2_bean abo;
  u2_bean gab;
  u2_bean ice;
  u2_bean pro;
  u2_bean veb;
  u2_bean rez;
  u2_bean nuu;
} u2_Opts;

/* u2_ve_getopt(): extract option map from command line.
*/
static u2_bean
u2_ve_getopt(c3_i argc, c3_c** argv)
{
  c3_i ch_i;

  u2_Opts.abo = u2_no;
  u2_Opts.gab = u2_no;
  u2_Opts.ice = u2_no;
  u2_Opts.pro = u2_no;
  u2_Opts.veb = u2_yes;
  u2_Opts.rez = u2_no;
  u2_Opts.nuu = u2_no;
  u2_Opts.kno_w = DefaultKernel;

  while ( (ch_i = getopt(argc, argv, "k:lcsagqvR")) != -1 ) {
    switch ( ch_i ) {
      case 'a': { u2_Opts.abo = u2_yes; break; }
      case 'c': { u2_Opts.nuu = u2_yes; break; }
      case 'g': { u2_Opts.gab = u2_yes; break; }
      case 's': { u2_Opts.ice = u2_yes; break; }
      case 'k': {
        c3_w arg_w = atoi(optarg);

        if ( (arg_w > 0) && (arg_w < 256) ) {
          u2_Opts.kno_w = arg_w;
        }
        else return u2_no;
        break;
      }
      case 'q': { u2_Opts.veb = u2_no; break; }
      case 'v': { u2_Opts.veb = u2_yes; break; }
      case 'R': { u2_Opts.rez = u2_yes; break; }
      case '?': default: {
        return u2_no;
      }
    }
  }

  if ( argc != (optind + 1) ) {
    return u2_no;
  } else { 
    {
      c3_c* ash_c;

      if ( (ash_c = strrchr(argv[optind], '/')) && (ash_c[1] == 0) ) {
        *ash_c = 0;
      }
    }

    if ( u2_yes == u2_Opts.rez ) {
      c3_c yes[2];

      yes[1] = 0;
      printf("really forget all events in %s? (y/N) ", argv[optind]);
      scanf("%1s", yes);

      if ( yes[0] != 'y' ) {
        printf("okay, we won't do that!\n");
        exit(1);
      }
      else printf("%s will be reset.\n", argv[optind]);
    }
    u2_Opts.cpu_c = strdup(argv[optind]);
    return u2_yes;
  }
}

/* u2_ve_usage(): print usage and exit.
*/
static void
u2_ve_usage(c3_i argc, c3_c** argv)
{
  fprintf(stderr, "%s: usage: [-v] [-k stage] computer\n", argv[0]);
  exit(1);
}

/* u2_ve_panic(): panic and exit.
*/
static void
u2_ve_panic(c3_i argc, c3_c** argv)
{
  fprintf(stderr, "%s: gross system failure\n", argv[0]);
  exit(1);
}

/* u2_ve_sysopt(): apply option map to system state.
*/
static void
u2_ve_sysopt()
{
  {
    u2_Local = strdup(u2_Opts.cpu_c);
  }
  u2_System = U2_LIB;

  u2_Flag_Abort = u2_Opts.abo;
  u2_Flag_Garbage = u2_Opts.gab;
  u2_Flag_Profile = u2_Opts.pro;
  u2_Flag_Verbose = u2_Opts.veb;
}

static jmp_buf Signal_buf;
#ifndef SIGSTKSZ
# define SIGSTKSZ 16384
#endif
static uint8_t Sigstk[SIGSTKSZ];

volatile enum { sig_none, sig_overflow, sig_interrupt } Sigcause;

static void
overflow_handler(int emergency, stackoverflow_context_t scp)
{
  if ( 1 == emergency ) {
    write(2, "stack emergency\n", strlen("stack emergency" + 2));
    exit(1);
  } else {
    Sigcause = sig_overflow;
    longjmp(Signal_buf, 1);
  }
}

static void
interrupt_handler(int x)
{
  Sigcause = sig_interrupt;
  longjmp(Signal_buf, 1);
}

c3_i
main(c3_i   argc,
     c3_c** argv)
{
  c3_w kno_w;

  //  Parse options.
  //
  if ( u2_no == u2_ve_getopt(argc, argv) ) {
    u2_ve_usage(argc, argv);
    return 1;
  }
  u2_ve_sysopt();

  //  Instantiate process globals.
  {
    u2_wr_check_init(u2_Opts.cpu_c);

    if ( (u2_no == u2_Opts.nuu) && (u2_no == u2_Opts.rez) ) {
      if ( u2_no == u2_loom_load() ) {
        fprintf(stderr, "%s: could not load\n", u2_Opts.cpu_c);
        return 1;
      } else {
        u2_Host.wir_r = u2_ray_of(0, 0);
        u2_Wire = u2_Host.wir_r;

        u2_Host.cpu_c = u2_Opts.cpu_c;
        u2_Host.arv_u = u2_Arv;

        u2_Arv->ova.egg_u = u2_Arv->ova.geg_u = 0;

        //  Horrible ancient stuff.
        //
        kno_w = u2_Host.arv_u->kno_w;

        u2_Host.kno_w = kno_w;
        u2_Host.ver_e[kno_w].ken = u2k(u2_Host.arv_u->ken);
        u2_Host.ver_e[kno_w].mod_m = c3__warm;

        u2_ho_push();
        u2_ve_rest();
      }
    } else {
      u2_loom_boot();
      u2_Host.wir_r = u2_wr_init(c3__rock, u2_ray_of(0, 0), u2_ray_of(1, 0));
      u2_Wire = u2_Host.wir_r;

      u2_Host.cpu_c = u2_Opts.cpu_c;
      u2_Host.arv_u = u2_Arv;
    }
  }

  //  If we have not loaded from checkpoint, build kernel.
  //
  if ( 0 != u2_Host.arv_u->ent_w ) {
    u2_reck_time(u2_Host.arv_u);
    u2_reck_numb(u2_Host.arv_u);
    {
      c3_c* dyt_c = u2_cr_string(u2_Host.arv_u->wen);

      printf("time: %s\n", dyt_c);
      free(dyt_c);
    }
  } else {
    //  Set outside bail trap.  Should not be used, but you never know...
    //
    if ( 0 != u2_cm_trap() ) {
      u2_ve_panic(argc, argv);
    }
    else {
      //  Set boot and goal stages.
      {
        if ( (0 == u2_Opts.kno_w) || (u2_Opts.kno_w > 255) ) {
          kno_w = DefaultKernel;
        } else {
          kno_w = u2_Opts.kno_w;
        } 
      }

      //  Load the system, within memory cross.
      //
      {
        if ( u2_no == u2_Opts.ice ) {
          u2_rl_leap(u2_Wire, c3__rock);
          u2_ve_init(kno_w);
          u2_rl_fall(u2_Wire);
   
          //  Horrible ancient stuff.
          //
          {
            u2_steg* stg = &u2_Host.ver_e[kno_w];

            if ( 0 != stg->ken ) {
              stg->ken = u2_rl_copy(u2_Wire, stg->ken);
            }
            if ( 0 != stg->tip ) {
              stg->tip = u2_rl_copy(u2_Wire, stg->tip);
            }
            if ( 0 != stg->ras ) {
              stg->ras = u2_rl_copy(u2_Wire, stg->ras);
            }
            stg->tul = u2_rl_copy(u2_Wire, stg->tul);

            stg->toy.seed = u2_rl_copy(u2_Wire, stg->toy.seed);
            stg->toy.what = u2_rl_copy(u2_Wire, stg->toy.what);
            stg->toy.ream = u2_rl_copy(u2_Wire, stg->toy.ream);
            stg->toy.rain = u2_rl_copy(u2_Wire, stg->toy.rain);
            stg->toy.sell = u2_rl_copy(u2_Wire, stg->toy.sell);
            stg->toy.skol = u2_rl_copy(u2_Wire, stg->toy.skol);
            stg->toy.slot = u2_rl_copy(u2_Wire, stg->toy.slot);
            stg->toy.slam = u2_rl_copy(u2_Wire, stg->toy.slam);
            stg->toy.slap = u2_rl_copy(u2_Wire, stg->toy.slap);
            stg->toy.slop = u2_rl_copy(u2_Wire, stg->toy.slop);
            stg->toy.scot = u2_rl_copy(u2_Wire, stg->toy.scot);
          }
          u2_rl_flog(u2_Wire);
        }
        else u2_Host.kno_w = u2_Opts.kno_w;

        if ( (u2_yes == u2_Opts.ice) || (0 != u2_Host.ver_e[kno_w].ken) ) {
          u2_reck_boot(u2_Host.arv_u, u2_Opts.ice);
        }
      }
      u2_cm_done();
    }
  }

  //  Install signal handlers and set buffers.
  //
  //  Note that we use the sigmask-restoring variant.  Essentially, when
  //  we get a signal, we force the system back into the just-booted state.
  //  If anything goes wrong during boot (above), it's curtains.
  {
    if ( 0 != setjmp(Signal_buf) ) {
      switch ( Sigcause ) {
        case sig_overflow: printf("[stack overflow]\r\n"); break;
        case sig_interrupt: printf("[interrupt]\r\n"); break;
        default: printf("[signal error!]\r\n"); break;
      }
      Sigcause = sig_none;

      signal(SIGINT, SIG_DFL);
      stackoverflow_deinstall_handler();

      //  Print the trace, do a GC, etc.
      //
      //  This is half-assed at present, so we exit.
      //
      u2_ve_sway(0, u2k(u2_wire_tax(u2_Wire)));

      u2_lo_bail(u2_Host.arv_u);

      exit(1);
    }
    if ( -1 == stackoverflow_install_handler
        (overflow_handler, Sigstk, SIGSTKSZ) )
    {
      fprintf(stderr, "overflow_handler: install failed\n");
      exit(1);
    }
    signal(SIGINT, interrupt_handler);
  }

  if ( 0 != u2_Host.ver_e[kno_w].tip ) {
    // Special stupid-loop for experimental mode.
    //
    while ( 1 ) {
      c3_w num_w;
      u2_noun res;

      printf("! ");
      scanf("%ud", &num_w);
      if ( 0 == num_w ) {
        exit(0);
      }
      else {
        res = u2_nk_nock(u2_Wire, num_w, u2k(u2_Host.ver_e[kno_w].tip));
        u2_err(u2_Wire, "result", res);
        u2z(res);
      }
    }
  }

  if ( 0 != u2_Host.ver_e[kno_w].ras ) {
    fprintf(stderr, "no command line in transitional mode\n");
    exit(0);
  }

  {
    u2_lo_loop(u2_Host.arv_u, u2_Opts.nuu, u2_Opts.rez, u2_Opts.inv_c);
  }
  return 0;
}
