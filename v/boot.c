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
#include <ev.h>

#include "all.h"
#include "v/vere.h"

/* u2_ve_build(): load and/or build/save kernel `tah`.
*/
static u2_weak
u2_ve_build(u2_noun tah)
{
  c3_w  kno_w = u2_Host.kno_w;
  c3_d  src_d = u2_ve_date("watt", u2_ct(tah));
  c3_d  bin_d = u2_ve_date("pill", u2_ct(tah));
  u2_noun fol;

  if ( !src_d ) {
    u2_cz(tah);
    return u2_none;
  }
  else if ( bin_d && (bin_d >= src_d) ) {
    u2_weak pil = u2_ve_file("pill", u2_ct(tah));

    if ( u2_none == pil ) {
      u2_cz(tah);
      return u2_none;
    } 
    else {
      fol = u2_cke_cue(pil);
    }
  } 
  else {
    u2_noun src = u2_ve_file("watt", u2_ct(tah));
    u2_noun ken;
    u2_noun pil;

    u2_cm_push(u2nc(c3__lose, u2_cf_path(".", "watt", u2_ct(tah))));

    if ( !(ken = u2_Host.ver_e[kno_w + 1].ken) &&
         !(ken = u2_Host.ver_e[kno_w + 1].ras) )
    {
      return u2_cm_foul("make");
    }
    fol = u2_cn_nock(src, u2_ct(ken));
    u2_cm_drop();

    pil = u2_cke_jam(u2_ct(fol));
    u2_ve_save("pill", u2_ct(tah), pil);
  }

  u2_cz(tah);
  return fol;
}

/* u2_ve_oldtool: load tool path `tah` at `kno`, or 0.
*/
static u2_noun
u2_ve_oldtool(u2_noun tah)
{
  c3_w    kno_w = u2_Host.kno_w;
  u2_weak src = u2_ve_file("watt", tah);

  if ( u2_none == src ) {
    return 0;
  } 
  else {
    u2_noun ken, fol, cor;

    if ( !(ken = u2_Host.ver_e[kno_w].ken) ) {
      return u2_cm_foul("make-old");
    }
    fol = u2_cn_nock(src, u2_ct(ken));
    cor = u2_cn_nock(0, fol);

    return cor;
  }
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
          u2_noun pas = u2nt(c3__gunn, u2_ve_tag(u2_Host.kno_w), c3__sys);

          ver_e->dev.old = u2_ve_oldtool(pas);
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

/* u2_ve_tool(): load kernel tool.
*/
void
u2_ve_tool(u2_noun nam)
{
  u2_steg* ver_e = u2_ve_at();
  u2_noun  tah   = u2nt(nam, u2_ve_tag(u2_Host.kno_w), c3__sys);
  u2_weak  src   = u2_ve_file("watt", u2_ct(tah));

  u2_cm_push(u2nc(c3__lose, u2_cf_path(".", "watt", tah)));
  if ( u2_none == src ) {
    u2_cm_bail(c3__fail);
  }
  else {
    u2_noun gen = u2_ve_ream(src);
    u2_noun syd, vos;
   
    if ( u2_Host.kno_w > 209 ) {
      syd = u2_ct(ver_e->toy.what ? ver_e->toy.what : ver_e->toy.seed);
    } else {
      syd = u2_ct(ver_e->toy.seed);
    }
    vos = u2_ve_slap(syd, gen);

    ver_e->tul = u2_ckd_by_put(ver_e->tul, nam, u2_cm_bury(vos));
  }
  u2_cm_drop();
}

/* u2_ve_able(): u2_yes iff kernel `kno` is bootable as `nam`.
*/
u2_flag
u2_ve_able(c3_w kno_w, c3_m nam_w)
{
  u2_noun tah = u2nt(nam_w, u2_ve_tag(kno_w), c3__sys);
  c3_d  src_d = u2_ve_date("watt", u2_ct(tah));
  c3_d  bin_d = u2_ve_date("pill", tah);

  if ( bin_d && (bin_d >= src_d) ) {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_ve_auto(): find the first kernel loaded as a pill.
*/
c3_w
u2_ve_auto(c3_w kno_w)
{
  while ( kno_w <= FirstKernel ) {
    if ( (u2_yes == u2_ve_able(kno_w, c3__watt)) || 
         (u2_yes == u2_ve_able(kno_w, c3__tram)) ) {
      return kno_w;
    }
    kno_w++;
  }
  fprintf(stderr, "%s: %d: no sys/watt.pill (max %d)\n", 
                  u2_Local, kno_w, FirstKernel);
  exit(1);
}

/* u2_ve_base(): basic install (loads kernel only).
*/
void
u2_ve_base()
{
  u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];
  u2_noun  bot   = u2nc(u2_ve_tag(u2_Host.kno_w), c3__sys);

  c3_assert(0 == u2_Host.ver_e[u2_Host.kno_w].mod_m);
  {
    u2_noun ken = u2_cm_bury(u2_ve_build(u2nc(c3__watt, u2_ct(bot))));

    if ( u2_none != ken ) {                             //  stable kernel
      ver_e->ken = ken;
      ver_e->mod_m = c3__warm;
    } 
    else { 
      u2_noun ras = u2_cm_bury(u2_ve_build(u2nc(c3__tram, u2_ct(bot))));

      if ( u2_none != ras ) {                           //  transitional kernel
        ver_e->ras = ras;
        ver_e->mod_m = c3__cool;
      }
      else {
        u2_noun tip = u2_cm_bury(u2_ve_build(u2nc(c3__test, u2_ct(bot))));

        if ( u2_none != tip ) {                         //  test stub
          ver_e->tip = tip;
          ver_e->mod_m = c3__weak;
        }
        else {
          fprintf(stderr, "  %s: %d: no kernel\n", u2_Local, u2_Host.kno_w);
          u2_cm_foul("vere-none");
        }
      }
    }
  }

#if 0
  //  Old gunn - to be deleted.
  {
    if ( 0 != ver_e->ken ) {
      ver_e->dev.old = u2_ve_oldtool(u2nc(c3__gunn, u2_ct(bot)));
      if ( ver_e->dev.old ) {
        ver_e->dev.old = u2_cm_bury(ver_e->dev.old);
      }
    }
  }
#endif
  u2_cz(bot);
}

/* u2_ve_rest(): rest of install.
*/
void
u2_ve_rest()
{
  u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];

  c3_assert(c3__warm == u2_Host.ver_e[u2_Host.kno_w].mod_m);
  {
    ver_e->toy.seed = u2_cm_bury(u2_ve_bone("seed"));
    ver_e->toy.ream = u2_cm_bury(u2_ve_bone("ream"));
    ver_e->toy.slam = u2_cm_bury(u2_ve_bone("slam"));
    ver_e->toy.slap = u2_cm_bury(u2_ve_bone("slap"));
    ver_e->toy.slop = u2_cm_bury(u2_ve_bone("slop"));

    if ( u2_Host.kno_w <= 221 ) {
      ver_e->toy.sell = u2_cm_bury(u2_ve_bone("sell"));
      if ( u2_Host.kno_w == 221 ) {
        ver_e->toy.skol = u2_cm_bury(u2_ve_bone("soul"));
      } else {
        ver_e->toy.skol = u2_cm_bury(u2_ve_bone("skol"));
      }
      ver_e->toy.slot = u2_cm_bury(u2_ve_bone("slot"));
    }

    if ( u2_Host.kno_w <= 220 ) {
      ver_e->toy.spay = u2_cm_bury(u2_ve_bone("spay"));
    }

    if ( u2_Host.kno_w > 209 ) {
      u2_ve_tool(c3__what);
      ver_e->toy.what = u2_ve_use("what");
    }
    else ver_e->toy.what = 0;
  }
  {
    if ( u2_Host.kno_w > 209 ) {
      u2_ve_tool(c3__pitt);
      if ( u2_Host.kno_w <= 221 ) {
        u2_ve_tool(c3__zuse);
      }
    } else {
      u2_ve_tool(c3__born);
    }
  }
  u2_Host.ver_e[u2_Host.kno_w].mod_m = c3__live;
}

/* u2_ve_full(): full install (base + toys & tools).
*/
void
u2_ve_full()
{
  c3_assert(0 != u2_wire_kit_r(u2_Wire));
  u2_ve_base();
  c3_assert(0 != u2_wire_kit_r(u2_Wire));
  if ( c3__warm == u2_Host.ver_e[u2_Host.kno_w].mod_m ) {
    c3_assert(0 != u2_wire_kit_r(u2_Wire));
    u2_ve_rest();
    c3_assert(0 != u2_wire_kit_r(u2_Wire));
  }
}

/* u2_ve_retreat(): wind kno_w backward to live stage.
*/
void
u2_ve_retreat()
{
  while ( 1 ) {
    u2_Host.kno_w += 1;

    if ( u2_Host.kno_w > FirstKernel ) {
      fprintf(stderr, "%s: %d: retreat failure\n", u2_Local, FirstKernel);
      exit(1);
    }

    switch ( u2_Host.ver_e[u2_Host.kno_w].mod_m ) {
      default: c3_assert(0);

      case 0: {
        if ( u2_yes == u2_ve_able(u2_Host.kno_w, c3__watt) ) {
          u2_ve_full();
          break;
        } else continue;
      }
      case c3__live: { break; }
      case c3__warm: { u2_ve_rest(); break; }
      case c3__cool: continue;
      case c3__weak: continue;
    }
    break;
  }
}

/* u2_ve_die(): exit nobly, printing trace.
*/
void
u2_ve_die(u2_noun tax)
{
  u2_noun hoe;

  if ( 0 != (hoe = u2_cm_trap()) ) {
    u2z(tax);                         //  deepest error takes precedence
    u2_ve_grab(hoe, 0);

    u2_ve_wine(u2k(u2h(hoe)));
    u2_ve_die(u2k(u2t(hoe)));

    u2z(hoe);
  } 
  else {
    u2_ve_retreat();
    u2_ve_sway(2, u2_ckb_flop(tax));
    u2_cm_done();
  }
  fprintf(stderr, "%s: %d: boot failure\n", u2_Local, u2_Host.kno_w);
  exit(1);
}

#if 0
/* u2_ve_pile(): load the zuse packet log.  Crude.
*/
void
u2_ve_pile(void)
{
  u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];
  u2_noun  tah   = u2nt(u2_ci_string("zuse"), u2_ci_string("log"), u2_nul);
  u2_noun  all   = u2_ve_fold("atom", u2k(tah));
  u2_noun  len   = u2_ckb_lent(all);

  ver_e->has.pyl.len = len;
  {
    u2_noun log   = u2_nul;
    c3_l    len_l = len;
    c3_l    i_l;
    u2_noun fun = ver_e->toy.spay;

    for ( i_l = 0; i_l < len_l; i_l++ ) {
      u2_noun man = u2_cn_mong(u2k(fun), u2nt(u2_nul, c3_s2('u','d'), i_l));
      u2_noun hat = u2nc(man, u2k(tah));
      u2_noun kap = u2_ve_file("atom", hat);

      log = u2nc(kap, log);
    }
    ver_e->has.pyl.log = log;
  }
}

/* u2_ve_recv(): receive a packet.  Crude.
*/
void
u2_ve_recv(u2_noun kap)
{
  u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];
  u2_noun  fun   = u2_ve_at()->toy.spay;
  c3_l     len_l = u2_ve_at()->has.pyl.len;
  {
    u2_noun man = u2_cn_mong(u2k(fun), u2nt(u2_nul, c3_s2('u','d'), len_l));
    u2_noun tah = u2nq(man, u2_ci_string("zuse"), u2_ci_string("log"), u2_nul);
 
    if ( u2_no != u2_ve_save("atom", tah, u2k(kap)) ) {
      ver_e->has.pyl.len += 1;
      ver_e->has.pyl.log = u2nc(kap, vere->has.pyl.log);
    }
  }
}
#endif

/* u2_ve_start(): boot the kernel from `kfo` to `kto`.  Exit on fail.
*/
void
u2_ve_start(c3_w kfo_w, c3_w kto_w)
{
  if ( u2_yes == u2_Flag_Verbose ) {
    if ( kto_w == kfo_w ) {
      fprintf(stderr, "%s: at %d\n", u2_Local, kto_w); 
    } else {
      fprintf(stderr, "%s: from %d, to %d\n", u2_Local, kfo_w, kto_w); 
    }
  }

  u2_cm_trip();
  {
    u2_noun hoe;
 
    if ( 0 != (hoe = u2_cm_trap()) ) {
      u2_ve_grab(hoe, 0);

      u2_ve_wine(u2k(u2h(hoe)));
      u2_ve_die(u2k(u2t(hoe)));
    } 
    else {
      while ( kfo_w > kto_w ) {
        u2_Host.kno_w = kfo_w;
        u2_ve_base();
        kfo_w--;
      }
      u2_Host.kno_w = kto_w;
      c3_assert(0 != u2_wire_kit_r(u2_Wire));
      u2_ve_full();
      u2_cm_done();
    }
    u2_cm_purge();
  }
  u2_cm_chin();

  if ( u2_yes == u2_Flag_Verbose ) {
    fprintf(stderr, "%s: in %d ", u2_Local, u2_Host.kno_w);
    {
      u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];

      switch ( ver_e->mod_m ) {
        case c3__live:
          fprintf(stderr, "(%x)\n", u2_mug(ver_e->ken));
          break;
        case c3__cool:
          fprintf(stderr, "(transitional) (%x)\n", u2_mug(ver_e->ras));
          break;
        case c3__weak:
          fprintf(stderr, "(experimental) (%x)\n", u2_mug(ver_e->tip));
          break;
      }
    }
  }
#if 0
  if ( u2_Host.kno_w <= 220 ) {
    u2_ve_pile();

    if ( u2_yes == u2_Flag_Verbose ) {
      u2_steg* ver_e = &u2_Host.ver_e[u2_Host.kno_w];

      if ( 0 != ver_e->has.pyl.len ) {
        fprintf(stderr, "pile: %d packets\n", ver_e->has.pyl.len);
      }
    }
  }
#endif
}

/* u2_ve_init(): boot the kernel at `kno`.
*/
void
u2_ve_init(c3_w kno_w)
{
  c3_w kfo_w, kto_w;

  kto_w = kno_w;
  kfo_w = u2_ve_auto(kno_w);

  u2_ve_start(kfo_w, kto_w);

  if ( u2_yes == u2_Flag_Garbage ) {
    u2_ve_grab(0);
  }
}

/* u2_ve_mark(): mark the whole vere system.
*/
static c3_w
u2_ve_mark()
{
  c3_w siz_w, i_w;

  siz_w = u2_cm_mark_internal();

  siz_w += u2_cm_mark_noun(u2_Host.pet);
  siz_w += u2_cm_mark_noun(u2_Host.pat);
  siz_w += u2_cm_mark_noun(u2_Host.map);

  for ( i_w = 0; i_w < 257; i_w++ ) {
    u2_steg* ver_e = &u2_Host.ver_e[i_w];

    siz_w += u2_cm_mark_noun(ver_e->ken);
    siz_w += u2_cm_mark_noun(ver_e->ras);
    siz_w += u2_cm_mark_noun(ver_e->tip);
    siz_w += u2_cm_mark_noun(ver_e->tul);

    siz_w += u2_cm_mark_noun(ver_e->toy.seed);
    siz_w += u2_cm_mark_noun(ver_e->toy.what);
    siz_w += u2_cm_mark_noun(ver_e->toy.ream);
    siz_w += u2_cm_mark_noun(ver_e->toy.sell);
    siz_w += u2_cm_mark_noun(ver_e->toy.skol);
    siz_w += u2_cm_mark_noun(ver_e->toy.slam);
    siz_w += u2_cm_mark_noun(ver_e->toy.slap);
    siz_w += u2_cm_mark_noun(ver_e->toy.slop);
    siz_w += u2_cm_mark_noun(ver_e->toy.spay);

    siz_w += u2_cm_mark_noun(ver_e->dev.old);

    siz_w += u2_cm_mark_noun(ver_e->has.pyl.log);
    siz_w += u2_cm_mark_noun(ver_e->has.pyl.len);
  }
  return siz_w;
}

/* u2_ve_word(): print a word to stderr.
*/
void
u2_ve_word(c3_w wod_w)
{
  u2_flag top = u2_yes;

  if ( wod_w / (1000 * 1000 * 1000) ) {
    fprintf(stderr, "%u.", wod_w / (1000 * 1000 * 1000));
    wod_w %= (1000 * 1000 * 1000);
    top = u2_no;
  }
  if ( wod_w / (1000 * 1000) ) {
    fprintf(stderr, ((top == u2_yes) ? "%u." : "%03u."), 
                     wod_w / (1000 * 1000));
    wod_w %= (1000 * 1000);
    top = u2_no;
  }
  if ( wod_w / 1000 ) {
    fprintf(stderr, ((top == u2_yes) ? "%u." : "%03u."), wod_w / 1000);
    wod_w %= 1000;
    top = u2_no;
  }
  fprintf(stderr, ((top == u2_yes) ? "%u" : "%03u"), wod_w);
}

/* u2_ve_grab(): garbage-collect the world, plus roots.
*/
void
u2_ve_grab(u2_noun som, ...)
{
  c3_w siz_w, lec_w;

  siz_w = u2_ve_mark();
  {
    va_list vap;
    u2_noun tur;

    va_start(vap, som);

    if ( som != 0 ) {
      siz_w += u2_cm_mark_noun(som);

      while ( 0 != (tur = va_arg(vap, u2_noun)) ) {
        siz_w += u2_cm_mark_noun(tur); 
      }
    }
    va_end(vap);
  }
  lec_w = u2_cm_sweep(siz_w);

  if ( lec_w || (u2_yes == u2_Flag_Verbose) ) {
    fprintf(stderr, "%s: gc: ", u2_Local);
    if ( lec_w ) {
      u2_ve_word(4 * lec_w);
      fprintf(stderr, " bytes shed; ");
    }
    u2_ve_word(4 * siz_w);
    fprintf(stderr, " bytes live\n");
  }
  u2_wire_lan(u2_Wire) = u2_yes;
}
