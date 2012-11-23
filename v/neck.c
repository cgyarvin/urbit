/* v/neck.c
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

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

/* _neck_root(): tool from boot.
*/
static u2_noun
_neck_root(const c3_c *txt_c, u2_noun ken)
{
  c3_c *ful_c = alloca(7 + strlen(txt_c));

  strcpy(ful_c, "=>  !%  ");
  strcat(ful_c, txt_c);

  return u2_cn_nock(0, u2_cn_nock(u2_ci_string(ful_c), u2k(ken)));
}

/* _neck_ream(): ream with toy.
*/
static u2_noun
_neck_ream(u2_reck* rec_u, u2_noun txt)
{
  return u2_cn_mung(u2k(rec_u->toy.ream), txt);
}

/* _neck_rain(): rain with toy.
*/
static u2_noun
_neck_rain(u2_reck* rec_u, u2_noun bon, u2_noun txt)
{
  return u2_cn_mung(u2k(rec_u->toy.rain), u2nc(bon, txt));
}

/* _neck_slam(): slam with toy.
*/
static u2_noun
_neck_slam(u2_reck* rec_u, u2_noun gat, u2_noun sam)
{
  return u2_cn_mung(u2k(rec_u->toy.slam), u2nc(gat, sam));
}

/* _neck_slap(): slap with toy.
*/
static u2_noun
_neck_slap(u2_reck* rec_u, u2_noun vax, u2_noun gen)
{
  return u2_cn_mung(u2k(rec_u->toy.slap), u2nc(vax, gen));
}

/* _neck_slop(): slop with toy.
*/
static u2_noun
_neck_slop(u2_reck* rec_u, u2_noun hed, u2_noun tal)
{
  return u2_cn_mung(u2k(rec_u->toy.slop), u2nc(hed, tal));
}

/* _neck_gate(): nock gate from vase and text.
*/
static u2_noun
_neck_gate(u2_reck* rec_u, u2_noun vax, const c3_c* txt_c)
{
  u2_noun gen = _neck_ream(rec_u, u2_ci_string(txt_c));
  u2_noun vag = _neck_slap(rec_u, vax, gen);
  u2_noun gat = u2k(u2t(vag));

  u2z(vag); 
  return gat;
}

/* _neck_hard(): function against vase, producing noun.
*/
static u2_noun
_neck_hard(u2_reck* rec_u, u2_noun vax, const c3_c* txt_c, u2_noun sam)
{
  return u2_cn_mung(_neck_gate(rec_u, vax, txt_c), sam);
}

/* _neck_coin_da(): print atom as date.
*/
static u2_noun
_neck_coin_da(u2_reck* rec_u, u2_noun ato)
{
  return _neck_hard
    (rec_u, u2k(rec_u->syd), "|=([a=@] ~(rent co ~ %da a))", ato);
}

/* _neck_soft(): function against vase, producing vase.
*/
static u2_noun
_neck_soft(u2_reck* rec_u, u2_noun vax, const c3_c* txt_c, u2_noun sam)
{
  u2_noun gen = _neck_ream(rec_u, u2_ci_string(txt_c));
  u2_noun gat = _neck_slap(rec_u, vax, gen);

  return _neck_slam(rec_u, gat, sam);
}

/* _neck_spat(): noun path from c, kind of a hack.
*/
static u2_noun 
_neck_spat(c3_c* pax_c)
{
  if ( !*pax_c ) {
    return u2_nul;
  } else {
    c3_c* ash_c = strchr(pax_c, '/');

    if ( !ash_c ) {
      return u2nc(u2_ci_string(pax_c), u2_nul);
    } 
    else {
      u2_noun pan;

      *ash_c = 0;
      pan = u2_ci_string(pax_c);
      *ash_c = '/';
      
      return u2nc(pan, _neck_spat(ash_c + 1));
    }
  }
}

/* _neck_load(): layer file on vase -> vase.
*/
static u2_noun
_neck_load(u2_reck* rec_u, u2_noun vax, c3_c* pax_c)
{
  u2_noun txt = u2_walk_load(pax_c);
  u2_noun gen = _neck_rain
    (rec_u, _neck_spat(pax_c + strlen(u2_Local) + 1), txt);

  return _neck_slap(rec_u, vax, gen);
}

/* _neck_load_temp(): _neck_load() for old fs structure.
*/
static u2_noun
_neck_load_temp(u2_reck* rec_u, u2_noun vax, c3_w kno_w, c3_c* pax_c)
{
  c3_c ful_c[2048];
 
  sprintf(ful_c, "%s/sys/%d/%s", u2_Local, kno_w, pax_c);
  return _neck_load(rec_u, vax, ful_c);
}

/* _neck_time_set(): set the neck time.
*/
static void
_neck_time_set(u2_reck* rec_u)
{
  struct timeval tim_tv;

  gettimeofday(&tim_tv, 0);
  u2z(rec_u->now);
  rec_u->now = u2_time_in_tv(&tim_tv);

  u2z(rec_u->wen);
  rec_u->wen = _neck_coin_da(rec_u, u2k(rec_u->now));
}

/* u2_neck_init(): load the neck engine, from kernel.
*/
void
u2_neck_init(u2_reck* rec_u, c3_w kno_w, u2_noun ken)
{
  memset(rec_u, 0, sizeof(*rec_u));
  rec_u->kno_w = kno_w;
  rec_u->rno_w = 0;

  rec_u->ken = ken;
  rec_u->syd = _neck_root("seed", u2k(ken));

  rec_u->toy.rain = _neck_root("rain", u2k(ken));
  rec_u->toy.ream = _neck_root("ream", u2k(ken));
  // rec_u->toy.sham = _neck_root("sham", u2k(ken));
  rec_u->toy.slam = _neck_root("slam", u2k(ken));
  rec_u->toy.slap = _neck_root("slap", u2k(ken));
  rec_u->toy.slop = _neck_root("slop", u2k(ken));

  _neck_time_set(rec_u);
  {
    c3_c* dyt_c = u2_cr_string(rec_u->wen);

    printf("time: %s\n", dyt_c);
    free(dyt_c);
  }
  {
    u2_noun syd, zen, yen, xan, wol, vay;

    syd = u2k(rec_u->syd);

    {
      // printf("zen:\n");
      zen = _neck_load_temp(rec_u, u2k(syd), kno_w, "reck/zen.watt");

      rec_u->toy.sham = _neck_gate(rec_u, u2k(zen), "sham");

      // printf("yen:\n");
      yen = _neck_load_temp(rec_u, zen, kno_w, "reck/yen.watt");

      // printf("xan:\n");
      xan = _neck_load_temp(rec_u, yen, kno_w, "reck/xan.watt");

      // printf("wol:\n");
      wol = _neck_load_temp(rec_u, xan, kno_w, "reck/wol.watt");

      // printf("vay:\n");
      vay = _neck_load_temp(rec_u, wol, kno_w, "reck/vay.watt");
    }

#if 0
    rec_u->toy.duel = 
      _neck_gate(rec_u, u2k(cay), "|=([a=arch b=arch] (~(duel cy a) b))");
#endif

    rec_u->rec = vay;
  }
}


/* _neck_kick(): apply an output ovum.
*/
static void
_neck_kick(u2_reck* rec_u, u2_noun ovo)
{
  u2_noun pay = u2t(ovo);
  u2_noun p_pay, q_pay;

  switch ( u2h(pay) ) {
    default: 
    {
      u2_err(u2_Wire, "unsupported", u2h(pay));
    } break;

    case c3__crap: p_pay = u2t(pay);
    {
      u2_ve_sway(2, u2_ckb_flop(u2k(p_pay)));
      printf("<exit>\n");
    } break;

    case c3__tell: u2_cx_cell(u2t(pay), &p_pay, &q_pay);
    {
      switch ( p_pay ) {
        case 0: u2_ve_tank(2, u2k(q_pay)); break;
        case 1: u2_ve_tank(0, u2k(q_pay)); break;
        case 2: u2_ve_tank(1, u2k(q_pay)); break;
        case 3: u2_ve_tank(3, u2k(q_pay)); break;
      }
    } break;
  }
  u2z(ovo);
}

/* _neck_poke(): insert an input ovum.
*/
static void
_neck_poke(u2_reck* rec_u, u2_noun ovo)
{
  u2_noun sam = _neck_slop(rec_u, u2nc(u2nc(c3__atom, 0), u2k(rec_u->now)),
                                  u2nc(c3__noun, ovo));
  u2_noun gax = _neck_soft(rec_u, u2k(rec_u->rec), "poke", sam);
  u2_noun hix, pux;

  hix = _neck_slap(rec_u, u2k(gax), u2nc(c3__cnbc, 'p'));
  pux = _neck_slap(rec_u, gax, u2nc(c3__cnbc, 'q'));

  u2z(rec_u->rec);
  rec_u->rec = pux; 

  {
    u2_noun hux = u2t(hix);

    while ( u2_nul != hux ) {
      _neck_kick(rec_u, u2k(u2h(hux)));
      hux = u2t(hux);
    }
  }
  u2z(hix);
}

/* u2_neck_launch_toy(): launch a new neck engine, with toy parms.
*/
static void
u2_neck_launch_toy(u2_reck* rec_u, u2_noun pax)
{
  _neck_poke
    (rec_u, 
     u2nc(pax, 
          u2nq(c3__make, c3_s4('z','u','s','e'), 256, u2k(rec_u->now))));
}

/* u2_neck_boot(): boot the neck engine (unprotected).
*/
void
u2_neck_boot(u2_reck* rec_u)
{
  u2_noun hoe;

  memset(rec_u, 0, sizeof *rec_u);
  u2_cm_trip();
  if ( 0 != (hoe = u2_cm_trap()) ) {
    u2_cm_purge();
    u2_ve_grab(hoe, 0);

    u2_ve_wine(u2k(u2h(hoe)));
    u2_ve_sway(2, u2_ckb_flop(u2k(u2t(hoe))));
    u2z(hoe);
  } 
  else {
    u2_neck_init(rec_u, 
                 u2_Host.kno_w, 
                 u2k(u2_Host.ver_e[u2_Host.kno_w].ken));

    u2_cm_done();
  
    u2_cm_purge();
    if ( (u2_yes == u2_Flag_Garbage) || (u2_no == u2_wire_lan(u2_Wire)) ) {
      u2_ve_grab(0);
    }
  }
  u2_cm_chin();
}

/* u2_neck_launch(): launch the neck engine (protected).
*/
void
u2_neck_launch(u2_reck* rec_u)
{
  u2_noun pax = u2nq(c3__gold, c3__term, '0', u2_nul);
  u2_neck_launch_toy(rec_u, pax);
}

/* u2_neck_line(): apply a neck line (protected).
*/
void
u2_neck_line(u2_reck* rec_u, u2_noun lin)
{
  u2_noun pax = u2nq(c3__gold, c3__term, '0', u2_nul);

  _neck_time_set(rec_u);
  _neck_poke(rec_u, u2nc(pax, u2nc(c3__line, lin)));
}
