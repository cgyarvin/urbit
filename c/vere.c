/* c/vere.c
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
#include "f/coal.h"

/**  Legacy fixed jet linkage.  Destroy me please.
**/
    /* External drivers.
    */
      extern u2_ho_driver j2_da(k_223);
      extern u2_ho_driver j2_da(k_224);
      extern u2_ho_driver j2_da(k_225);

    /* Built-in battery drivers.   Null `cos` terminates. 
    */
      u2_ho_driver *HostDriverBase[] = {
        &j2_da(k_223),
        &j2_da(k_224),
        &j2_da(k_225),
        0
      };

    /* First kernel this executable can boot.
    */
#     define FirstKernel 225

    /* Temporary dependency on old gunn.
    */
      /* u2_ve_gunn_line(): apply command line.
      */
        void
        u2_ve_gunn_line(u2_noun cor, u2_noun txt);

      /* u2_ve_gunn_swan(): convert shoe to tank.
      */
        u2_noun
        u2_ve_gunn_swan(u2_noun cor, u2_noun yos);

      /* u2_ve_gunn_gank(): print a tank.
      */
        void
        u2_ve_gunn_gank(u2_noun cor, u2_noun tac);


/**  General vere state.  Move to header file.
***
***  All nouns are in the basket (permanent storage) and need not be tracked.
**/
  typedef struct {
    u2_noun ken;                        //  stable kernel, or 0 for none
    u2_noun ras;                        //  transition kernel, or 0
    u2_noun tip;                        //  broken sub-kernel, or 0
    struct {
      u2_noun old;                      //  legacy app
      u2_noun esh;                      //  command-line parsing & execution
      u2_noun rin;                      //  introspection & debugging
      u2_noun tul;                      //  miscellaneous utilities
    } dev;
  } u2_steg;

  typedef struct {
    u2_wire wir_r;                      //  noun system, 1 per thread
    c3_c*   fel_c;                      //  readline filename
    u2_noun pet;                        //  petname of self, atomic
    u2_noun pat;                        //  unix path to self, atomic
    u2_noun opt;                        //  unix arguments as map
    u2_steg ver_e[257];                 //  stages improving downward
    c3_w    kno_w;                      //  current executing stage
  } u2_host;                            //  host == computer == process

/**  Globals!
**/
  c3_global  u2_host  u2_Host;
  c3_global  u2_wire  u2_Wire;
  c3_global  c3_c*    u2_Local;
  c3_global  c3_c*    u2_System;
  c3_global  u2_flag  u2_Quiet;
  c3_global  u2_flag  u2_Debug;


#if 0
/* u2_ve_roc(): find appropriate core for call.
*/
static u2_noun
u2_ve_roc(c3_m roc_m)
{
  c3_w kno_w = u2_Host.kno_w;

  while ( 0 != u2_Host.ver_e[kno_w].ken ) {
    u2_noun cor;

    switch ( roc_m ) {
      case c3__old: cor = u2_Host.ver_e[kno_w].dev.old; break;
      case c3__esh: cor = u2_Host.ver_e[kno_w].dev.esh; break;
      case c3__rin: cor = u2_Host.ver_e[kno_w].dev.rin; break;
      case c3__tul: cor = u2_Host.ver_e[kno_w].dev.tul; break;

      default: c3_assert(0); return 0;
    }
    if ( 0 != cor ) return u2_ct(cor);
    kno_w += 1;
  }
  u2_cm_mean(roc_m); return u2_cm_foul("vere-core");
}

/* u2_ve_f(): call soft function from an internal core.
*/
static u2_noun
u2_ve_f(c3_m roc_m, c3_c* nam_c, u2_noun sam)
{
  return u2_ch_mong(u2_ch_hook(u2_ve_roc(roc_m), nam_c), sam);
}
#  define u2_ve_fc(r, n, a, b)        u2_ve_f(r, n, u2nc(a, b))
#  define u2_ve_ft(r, n, a, b, c)     u2_ve_f(r, n, u2nt(a, b, c))
#  define u2_ve_fq(r, n, a, b, c, d)  u2_ve_f(r, n, u2nq(a, b, c, d))
#endif

/* u2_ve_getopt(): extract option map from command line.
*/
u2_weak
u2_ve_getopt(c3_i argc, c3_c** argv)
{
  u2_noun opt = 0;

  c3_i ch_i;

  while ( (ch_i = getopt(argc, argv, "k:v")) != -1 ) {
    switch ( ch_i ) {
      case 'k': {
        c3_w kno_w = atoi(optarg);

        if ( (kno_w > 0) && (kno_w < 256) ) {
          opt = u2_ckd_by_put(opt, c3__kno, kno_w);
        }
        else return u2_none;
        break;
      }
      case 'v': {
        opt = u2_ckd_by_put(opt, c3__veb, 0);
        break;
      }
      case '?': default: {
        return u2_none;
      }
    }
  }
  if ( argc != (optind + 1) ) {
    return u2_none;
  }
  opt = u2_ckd_by_put(opt, c3__cpu, u2_ci_string(argv[optind]));
  
  return opt;
}

/* u2_ve_usage(): print usage and exit.
*/
void
u2_ve_usage(c3_i argc, c3_c** argv)
{
  fprintf(stderr, "%s: usage: [-v] [-k stage] computer\n", argv[0]);
  exit(1);
}

/* u2_ve_panic(): panic and exit.
*/
void
u2_ve_panic(c3_i argc, c3_c** argv)
{
  fprintf(stderr, "%s: gross system failure\n", argv[0]);
  exit(1);
}

/* u2_ve_sysopt(): apply option map to system state.
*/
u2_flag
u2_ve_sysopt(u2_noun opt)                            //  retain
{
  {
    u2_weak cpu = u2_ckd_by_get(u2_ct(opt), c3__cpu);

    if ( u2_none == cpu ) {
      return u2_no;
    }
    u2_Local = u2_cr_string(cpu);
  }

  {
    u2_weak veb = u2_ckd_by_get(u2_ct(opt), c3__veb);

    if ( u2_none != veb ) {
      u2_Quiet = !veb;
    }
  }
  return u2_yes;
}

/* u2_ve_load(): load internal file as atom from local or system.
*/
static u2_weak
u2_ve_file(c3_c* ext_c, u2_noun tah)
{
  u2_noun pas;
  u2_weak dat;

  c3_assert(u2_Local);
  pas = u2_cf_path(u2_Local, ext_c, u2_ct(tah));
  dat = u2_cf_flat_load(c3__atom, pas);

  if ( (u2_none != dat) || !u2_System ) {
    u2_cz(tah);

    return dat;
  } else {
    return u2_cf_flat_load(c3__atom, u2_cf_path(u2_System, ext_c, tah));
  }
}

/* u2_ve_date(): date internal file.
*/
static c3_d
u2_ve_date(c3_c* ext_c, u2_noun tah)
{
  u2_noun pas;
  u2_weak dat;

  pas = u2_cf_path(u2_Local, ext_c, u2_ct(tah));
  dat = u2_cf_flat_date(pas);

  if ( (0 != dat) || !u2_System ) {
    u2_cz(tah);

    return dat;
  } else {
    return u2_cf_flat_date(u2_cf_path(u2_System, ext_c, tah));
  }
}

/* u2_ve_save(): save internal file as atom.
*/
static void
u2_ve_save(c3_c* ext_c, u2_noun tah, u2_noun dat)
{
  u2_cf_flat_save(c3__atom, u2_cf_path(u2_Local, ext_c, tah), dat);
}

/* u2_ve_build(): load and/or build/save kernel `tah`.
*/
static u2_weak
u2_ve_build(u2_noun tah)
{
  c3_w  kno_w = u2_Host.kno_w;
  c3_d  src_d = u2_ve_date("watt", u2_ct(tah));
  c3_d  bin_d = u2_ve_date("pill", u2_ct(tah));
  c3_c* ext_c;
  u2_noun fol;

  if ( !src_d ) {
    return u2_none;
  }
  else if ( bin_d && (bin_d >= src_d) ) {
    u2_weak pil = u2_ve_file("pill", u2_ct(tah));

    if ( u2_none == pil ) {
      return u2_none;
    } 
    else {
      fol = u2_cke_cue(pil);
    }
    ext_c = "pill";
  } 
  else {
    u2_noun src = u2_ve_file("watt", u2_ct(tah));
    u2_noun ken;
    u2_noun pil;

    if ( !(ken = u2_Host.ver_e[kno_w + 1].ken) &&
         !(ken = u2_Host.ver_e[kno_w + 1].ras) )
    {
      fprintf(stderr, "%d: no %d kernel\n", kno_w, kno_w + 1);
      return u2_cm_foul("make");
    }
    fol = u2_cn_nock(src, u2_ct(ken));

    pil = u2_cke_jam(u2_ct(fol));
    u2_ve_save("pill", u2_ct(tah), pil);

    ext_c = "watt";
  }

  //  Display our work.
  {
    u2_noun pas = u2_cf_path("", ext_c, u2_ct(tah));
    c3_c*   pas_c = u2_cr_string(pas);

    fprintf(stderr, "  %s: %x\n", pas_c+1, u2_mug(fol));
    free(pas_c);
    u2_cz(pas);
  }

  u2_cz(tah);
  return fol;
}

/* u2_ve_tool: load tool path `tah` at `kno`, or 0.
*/
static u2_noun
u2_ve_tool(u2_noun tah)
{
  c3_w    kno_w = u2_Host.kno_w;
  u2_weak src = u2_ve_file("watt", u2_ct(tah));

  if ( u2_none == src ) {
    u2_cz(tah); 
    return 0;
  } 
  else {
    u2_noun ken, fol, cor;

    if ( !(ken = u2_Host.ver_e[kno_w].ken) ) {
      fprintf(stderr, "%d: no kernel", kno_w);
      return u2_cm_foul("make");
    }
    fol = u2_cn_nock(src, u2_ct(ken));
    cor = u2_cn_nock(0, fol);

    {
      u2_noun pas = u2_cf_path("", "watt", u2_ct(tah));
      c3_c*   pas_c = u2_cr_string(pas);

      fprintf(stderr, "  %s: %x\n", pas_c+1, u2_mug(cor));
      free(pas_c);
      u2_cz(pas);
    }
    return cor;
  }
}

/* u2_ve_tag: simple string from number.
*/
static u2_noun
u2_ve_tag(c3_w a_w)
{
  c3_c a_c[] = {0, 0, 0, 0};

  sprintf(a_c, "%d", a_w);
  return u2_ci_string(a_c);
}

/* u2_ve_stage(): load current stage to best of ability.  crash-only.
*/
void
u2_ve_stage(u2_flag hyr)
{
  c3_w     kno_w = u2_Host.kno_w;
  u2_noun  kna   = u2_ve_tag(kno_w);
  u2_noun  bot   = u2nc(c3__boot, kna);
  u2_steg* ver_e = &(u2_Host.ver_e[kno_w]);             //  assumed bzero

  /* Organize the stable kernel / transitional kernel / test tip.
  */
  {
    u2_noun ken = u2_ve_build(u2nc(c3__watt, u2_ct(bot)));

    if ( u2_none != ken ) {                             //  stable kernel
      ver_e->ken = u2_cm_bury(ken);
    } 
    else { 
      u2_noun ras = u2_ve_build(u2nc(c3__tram, u2_ct(bot)));

      if ( u2_none != ras ) {                           //  transitional kernel
        ver_e->ras = u2_cm_bury(ras);
      }
      else {
        u2_noun tip = u2_ve_build(u2nc(c3__test, u2_ct(bot)));

        if ( u2_none != tip ) {                         //  test stub
          ver_e->tip = u2_cm_bury(tip);
        }
        else {
          fprintf(stderr, "  %s: %d: no kernel\n", u2_Local, kno_w);
          u2_cm_bail(c3__fail);
        }
      }
    }
  }

  /* Organize internal tools, if we have a stable kernel.
  */
  if ( (u2_yes == hyr) && (0 != ver_e->ken) ) {
    ver_e->dev.old = u2_ve_tool(u2nc(c3__gunn, u2_ct(bot)));
    if ( ver_e->dev.old ) {
      ver_e->dev.old = u2_cm_bury(ver_e->dev.old);
    }

    ver_e->dev.esh = u2_ve_tool(u2nc(c3__born, u2_ct(bot)));
    if ( ver_e->dev.esh ) {
      ver_e->dev.esh = u2_cm_bury(ver_e->dev.esh);
    }

    ver_e->dev.rin = u2_ve_tool(u2nc(c3__mach, u2_ct(bot)));
    if ( ver_e->dev.rin ) {
      ver_e->dev.rin = u2_cm_bury(ver_e->dev.rin);
    }

    ver_e->dev.tul = u2_ve_tool(u2nc(c3__born, u2_ct(bot)));
    if ( ver_e->dev.tul ) {
      ver_e->dev.tul = u2_cm_bury(ver_e->dev.tul);
    }
  }
}

/* u2_ve_auto(): find the first kernel loaded as a pill.
*/
c3_w
u2_ve_auto(c3_w kno_w)
{
  while ( kno_w <= FirstKernel ) {
    u2_noun tah = u2nt(c3__watt, c3__boot, u2_ve_tag(kno_w));
    c3_d  src_d = u2_ve_date("watt", u2_ct(tah));
    c3_d  bin_d = u2_ve_date("pill", tah);

    if ( bin_d && (bin_d >= src_d) ) {
      return kno_w;
    }
    kno_w++;
  }
  fprintf(stderr, "%s: %d: no boot/watt.pill (max %d)\n", 
                  u2_Local, kno_w, FirstKernel);
  exit(1);
}

/* u2_ve_gunn(): produce a gunn, of any vintage.
*/
u2_noun
u2_ve_gunn()
{
  u2_noun cor; 

  if ( 0 != (cor = u2_Host.ver_e[u2_Host.kno_w].dev.old) ) {
    return u2_ct(cor);
  }
  else {
    c3_w kno_w = u2_Host.kno_w;

    u2_Host.kno_w += 1;
    while ( u2_Host.kno_w <= FirstKernel ) {
      u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];

      if ( 0 != (cor = ver_e->dev.old) ) {
        u2_Host.kno_w = kno_w;
        return u2_ct(cor);
      }
      else {
        if ( 0 != u2_Host.ver_e[u2_Host.kno_w].ken ) {
          u2_noun pas = u2nt(c3__gunn, c3__boot, u2_ve_tag(u2_Host.kno_w));

          ver_e->dev.old = u2_ve_tool(pas);
          if ( ver_e->dev.old ) {
            ver_e->dev.old = u2_cm_bury(ver_e->dev.old);

            cor = ver_e->dev.old;
            u2_Host.kno_w = kno_w;
            return u2_ct(cor);
          }
        }
      }
      u2_Host.kno_w++;
    }
  }
  return u2_cm_foul("gunn-fail");
}

/* u2_ve_command():
*/
void
u2_ve_command(u2_noun lin)
{
  u2_noun cor;

  if ( 0 != (cor = u2_Host.ver_e[u2_Host.kno_w].dev.old) ) {
    u2_ct(cor);

    u2_ve_gunn_line(cor, lin);
  }
  else {
    fprintf(stderr, "  %d: no gunn\n", u2_Host.kno_w);
    u2_cz(lin);
  }
}

/* u2_ve_flog(): print trace stack.
*/
void
u2_ve_flog(u2_noun gun, u2_noun tax)
{
  while ( u2_yes == u2_cr_du(tax) ) {
    u2_noun h_tax = u2h(tax);
    u2_noun t_tax = u2t(tax);
    {
      c3_w poq_w = u2_cm_wind();
      u2_noun how;

      if ( 0 != (how = u2_cm_trap()) ) {
        u2_cm_done(poq_w);
        fprintf(stderr, "  !!--!!\n");
      } 
      else {
        u2_noun tac = u2_ve_gunn_swan(u2_ct(gun), u2_ct(h_tax));
     
        u2_ve_gunn_gank(u2_ct(gun), tac);
        u2_cm_done(poq_w);
      }
    }
    tax = t_tax;
  }
  u2_cz(gun);
  u2_cz(tax);
}

/* u2_ve_jail(): analyze and express error result.
*/
void
u2_ve_jail(u2_noun how)
{
  u2_noun p_how, q_how;

  if ( u2_no == u2_cr_du(how) ) {
    switch ( how ) {
      case c3__exit: fprintf(stderr, "<<exit>>:\n"); break;
      case c3__fail: fprintf(stderr, "<<fail>>:\n"); break;
      case c3__intr: fprintf(stderr, "<<intr>>:\n"); break;
      default:       fprintf(stderr, "<<--->>\n"); break;
    }
  } else {
    switch ( u2_h(how) ) {
      case c3__fail: u2_cx_cell(u2_t(how), &p_how, &q_how);
      {
        c3_c* str_c = u2_cr_string(p_how);

        fprintf(stderr, "<<fail (%s)>>:\n", str_c);
        break;
      }
      case c3__need: u2_cx_cell(u2_t(how), &p_how, &q_how);
      {
        fprintf(stderr, "<<need>>:\n");

        u2_err(u2_Wire, "need", p_how);
        break;
      }
      default: {
        fprintf(stderr, "<<--->>\n");
        break;
      }
    }
  }
  u2_cz(how);
}

/* u2_ve_line(): execute a command line, fully protected.
*/
void
u2_ve_line(c3_c* lin_c)
{
  c3_w poq_w;
  u2_noun how;

  u2_cm_trip();
  poq_w = u2_cm_wind();

  if ( 0 != (how = u2_cm_trap()) ) {
    u2_noun rap = u2_cm_trac();
    u2_noun gun;

    u2_cm_done(poq_w);
    //  gc with rap as root

    gun = u2_ve_gunn();

    u2_ve_jail(how);
    u2_ve_flog(gun, u2_ckb_flop(rap));
  } 
  else {
    u2_noun cor = u2_ve_gunn();
    u2_noun lin = u2_ci_string(lin_c);

    u2_ve_gunn_line(cor, lin);
    u2_cm_done(poq_w);
  }
  u2_cm_chin();
}

c3_i
main(c3_i   argc,
     c3_c** argv)
{
  c3_w kno_w, kfo_w, qop_w;

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
    //  Get command-line options.
    {
      u2_noun opt; 

      if ( u2_none == (opt = u2_ve_getopt(argc, argv)) ) {
        u2_ve_usage(argc, argv);
      }
      else u2_Host.opt = opt;

      if ( u2_no == u2_ve_sysopt(opt) ) {
        u2_ve_usage(argc, argv);
      }
    }

    //  Set boot and goal stages.
    {
      u2_noun kno = u2_ckd_by_get(u2_ct(u2_Host.opt), c3__kno);

      if ( (u2_none == kno) || (kno > 255) ) {
        kno_w = FirstKernel;
      } else {
        kno_w = kno;
      } 
      kfo_w = u2_ve_auto(kno_w);

      if ( kno_w == kfo_w ) {
        fprintf(stderr, "%s: %s: at %d\n", 
                argv[0], u2_Local, kno_w); 
      } else {
        fprintf(stderr, "%s: %s: from %d, to %d\n", 
                argv[0], u2_Local, kfo_w, kno_w); 
      }
    }

    //  Load the system.
    {
      c3_w kgo_w = kfo_w;

      while ( 1 ) {
        c3_w    poq_w;
        u2_noun how;

        u2_cm_trip();
        poq_w = u2_cm_wind();

        if ( 0 != (how = u2_cm_trap()) ) {
          u2_noun rap = u2_cm_trac();
          u2_noun gun;

          u2_cm_done(poq_w);
          //  gc with rap as root
          //
          
          gun = u2_ve_gunn();

          // fprintf(stderr, "%s: %s: %d: fail\n", argv[0], u2_Local, kgo_w);
          u2_ve_jail(how);
          u2_ve_flog(gun, u2_ckb_flop(rap));

          exit(1);
        } else {
          u2_Host.kno_w = kgo_w;

          u2_ve_stage((kgo_w == kno_w) ? u2_yes : u2_no);
          u2_cm_done(poq_w);
        }
        u2_cm_chin();

        if ( kgo_w == kno_w ) {
          break;
        } else kgo_w--;
      }

      if ( kgo_w != kno_w ) {
        fprintf(stderr, "%s: %s: %d: no boot\n", argv[0], u2_Local, kgo_w);
        exit(1);
      } else {
        fprintf(stderr, "%s: %s: boot %d\n", argv[0], u2_Local, u2_Host.kno_w);
      }
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
