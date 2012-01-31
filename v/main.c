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
#include <gmp.h>
#include <stdint.h>

#define U2_GLOBAL
#define C3_GLOBAL
#include "all.h"
#include "v/vere.h"

/**  Legacy fixed jet linkage.  Destroy me please.
**/
    /* External drivers.
    */
      extern u2_ho_driver j2_da(k_220);
      extern u2_ho_driver j2_da(k_221);
      extern u2_ho_driver j2_da(k_222);

    /* Built-in battery drivers.   Null `cos` terminates. 
    */
      u2_ho_driver *HostDriverBase[] = {
        &j2_da(k_220),
        &j2_da(k_221),
        &j2_da(k_222),
        0
      };

/* u2_ve_getopt(): extract option map from command line.
*/
static u2_weak
u2_ve_getopt(c3_i argc, c3_c** argv)
{
  u2_noun map = 0;
  c3_w    kno_w = 0;
  u2_flag abo = u2_no;
  u2_flag gab = u2_yes;
  u2_flag pro = u2_no;
  u2_flag veb = u2_yes;

  c3_i ch_i;

  while ( (ch_i = getopt(argc, argv, "k:agpqv")) != -1 ) {
    switch ( ch_i ) {
      case 'a': { abo = u2_yes; break; }
      case 'g': { gab = u2_yes; break; }
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

c3_i
main(c3_i   argc,
     c3_c** argv)
{
  c3_w kno_w, qop_w;

  //  Instantiate process globals.
  {
    u2_boot();

    u2_Host.wir_r = u2_wr_init(c3__rock, u2_ray_of(0, 0), u2_ray_of(1, 0));
    u2_Host.fel_c = c3_comd_init();
    u2_Wire = u2_Host.wir_r;
  }

  //  Set outside bail trap.  Should not be used, but you never know...
  //
  qop_w = u2_cm_wind();
  if ( 0 != u2_cm_trap() ) {
    u2_cm_done(qop_w);
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
    }
  }

  //  Process commands.  Replace with actual event loop.
  //
  while ( 1 ) {
    c3_c* lin_c = c3_comd_line(u2_Host.fel_c);

    if ( !lin_c ) {
      break;
    }
    else {
      u2_ve_line(lin_c); 
      free(lin_c);
    }
  }
  return 0;
}
