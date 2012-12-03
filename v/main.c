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
#include <libtecla.h>

#define U2_GLOBAL
#define C3_GLOBAL
#include "all.h"
#include "v/vere.h"

/**  Legacy fixed jet linkage.  Destroy me please.
**/
    /* External drivers.
    */
      extern u2_ho_driver j2_da(k_194);
      extern u2_ho_driver j2_da(k_195);

    /* Built-in battery drivers.   Null `cos` terminates. 
    */
      u2_ho_driver *HostDriverBase[] = {
        &j2_da(k_194),
        &j2_da(k_195),
        0
      };

/* u2_ve_getopt(): extract option map from command line.
*/
static u2_weak
u2_ve_getopt(c3_i argc, c3_c** argv)
{
  u2_noun map = 0;
  c3_w    kno_w = 0;
  u2_noun hep = u2_nul;
  u2_bean abo = u2_no;
  u2_bean gab = u2_no;
  u2_bean pro = u2_no;
  u2_bean veb = u2_no;

  c3_i ch_i;

  while ( (ch_i = getopt(argc, argv, "k:h:agqv")) != -1 ) {
    switch ( ch_i ) {
      case 'a': { abo = u2_yes; break; }
      case 'g': { gab = u2_yes; break; }
      case 'h': { hep = u2_ci_string(optarg); break; }
      case 'k': {
        c3_w arg_w = atoi(optarg);

        if ( (arg_w > 0) && (arg_w < 256) ) {
          kno_w = arg_w;
        }
        else return u2_none;
        break;
      }
      case 'q': { veb = u2_no; break; }
      case 'v': { veb = u2_yes; break; }
      case '?': default: {
        return u2_none;
      }
    }
  }
  if ( argc != (optind + 1) ) {
    return u2_none;
  }
  map = u2_ckd_by_put(map, c3__cpu, u2_ci_string(argv[optind]));
  map = u2_ckd_by_put(map, c3__kno, kno_w);
  map = u2_ckd_by_put(map, c3__abo, abo);
  map = u2_ckd_by_put(map, c3__gab, gab);
  map = u2_ckd_by_put(map, c3__pro, pro);
  map = u2_ckd_by_put(map, c3__veb, veb);
 
  if ( hep != u2_nul ) {
    map = u2_ckd_by_put(map, c3__hep, hep); 
  }
  return map;
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
  u2_noun map = u2_Host.map;

  {
    u2_noun cpu = u2_ckd_by_got(u2_ct(map), c3__cpu);

    u2_Local = u2_cr_string(cpu);
    u2_cz(cpu);
  }

  u2_Flag_Abort = u2_ckd_by_got(u2_ct(map), c3__abo);
  u2_Flag_Garbage = u2_ckd_by_got(u2_ct(map), c3__gab);
  u2_Flag_Profile = u2_ckd_by_got(u2_ct(map), c3__pro);
  u2_Flag_Verbose = u2_ckd_by_got(u2_ct(map), c3__veb);
}

static jmp_buf Signal_buf;
#ifndef SIGSTKSZ
# define SIGSTKSZ 16384
#endif
static uint8_t Sigstk[SIGSTKSZ];

volatile enum { sig_none, sig_overflow, sig_interrupt } Sigcause;
ev_io Stdin_watcher;
struct ev_loop *Loop_u;

static GetLine *Tecla;

static void
stdin_cb(struct ev_loop *lup_u, struct ev_io *w, int revents)
{
  c3_c* lin_c;
  
  lin_c = gl_get_line(Tecla, ": ", 0, -1);

  if ( !lin_c ) {
    if ( GLR_BLOCKED != gl_return_status(Tecla) ) {
      fprintf(stderr, "stdin_cb: abort\n");
      ev_io_stop (lup_u, w);
      ev_unloop (lup_u, EVUNLOOP_ALL);
    }
    else { 
      // fprintf(stderr, "stdin_cb: blocked\n");
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
      gl_get_line(Tecla, ": ", 0, -1);

      // printf(": "); fflush(stdout);
    }
  }
}

static void
overflow_handler(int emergency,
                      stackoverflow_context_t scp)
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

  //  Instantiate process globals.
  {
    u2_boot();

    u2_Host.wir_r = u2_wr_init(c3__rock, u2_ray_of(0, 0), u2_ray_of(1, 0));
    u2_Host.fel_c = c3_comd_init();
    u2_Wire = u2_Host.wir_r;
  }

  //  Set outside bail trap.  Should not be used, but you never know...
  //
  if ( 0 != u2_cm_trap() ) {
    u2_ve_panic(argc, argv);
  }
  else {
    //  Get and apply command-line options.
    {
      u2_noun map; 

      if ( u2_none == (map = u2_ve_getopt(argc, argv)) ) {
        u2_ve_usage(argc, argv);
      }
      else u2_Host.map = map;

      u2_ve_sysopt();
    }

    //  Set boot and goal stages.
    {
      u2_noun kno = u2_ckd_by_get(u2_ct(u2_Host.map), c3__kno);

      if ( (u2_none == kno) || (kno > 255) ) {
        kno_w = DefaultKernel;
      } else {
        kno_w = kno;
      } 
    }

    //  Load the system.
    //
    {
      u2_ve_init(kno_w);

      if ( 0 != u2_Host.ver_e[kno_w].ken ) {
#if 0
        u2_reck_boot(&u2_Host.rec_u[0]);
#else
        u2_reck_boot(&u2_Host.rec_u[0]);
#endif
      }
    }
    u2_cm_done();
  }

  //  Install signal handlers and set buffers.
  //
  //  Note that we use the sigmask-restoring variant.  Essentially, when
  //  we get a signal, we force the system back into the just-booted state.
  //  If anything goes wrong during boot (above), it's curtains.
  {
    if ( 0 != setjmp(Signal_buf) ) {
      switch ( Sigcause ) {
        case sig_overflow: printf("[stack overflow]\n"); break;
        case sig_interrupt: printf("[interrupt]\n"); break;
        default: printf("[signal error!]\n"); break;
      }
      Sigcause = sig_none;

      signal(SIGINT, SIG_DFL);
      stackoverflow_deinstall_handler();

      if ( Loop_u ) {
        ev_loop_destroy(Loop_u);
        Loop_u = 0;
      }

      //  Print the trace, do a GC, etc.
      //
      //  This is half-assed at present, so we exit.
      //
      u2_ve_sway(0, u2k(u2_wire_tax(u2_Wire)));

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

  if ( 0 == u2_Host.ver_e[kno_w].ken ) {
    fprintf(stderr, "no command line in transitional mode\n");
    exit(1);
  }

  u2_ve_launch();
  u2_ve_sync();

  Tecla = new_GetLine(16384, 4096);
  gl_io_mode(Tecla, GL_SERVER_MODE);
  {
    struct ev_loop *lup_u = ev_default_loop(0);

    u2_Host.lup_u = Loop_u = lup_u;

    // fprintf(stderr, "http: on port 8080\n");
    u2_ve_http_start(8080);

    ev_io_init(&Stdin_watcher, stdin_cb, 0, EV_READ);
    ev_io_start(lup_u, &Stdin_watcher);

    {
      c3_c* lin_c;
    
      lin_c = gl_get_line(Tecla, ": ", 0, -1);
      c3_assert(!lin_c && (GLR_BLOCKED == gl_return_status(Tecla)));
    }
    ev_loop(lup_u, 0);
  }
  gl_io_mode(Tecla, GL_NORMAL_MODE);

  return 0;
}
