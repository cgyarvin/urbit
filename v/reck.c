/* v/reck.c
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

/* _reck_root(): tool from boot.
*/
static u2_noun
_reck_root(const c3_c *txt_c, u2_noun ken)
{
  c3_c *ful_c = alloca(7 + strlen(txt_c));

  strcpy(ful_c, "=>  !%  ");
  strcat(ful_c, txt_c);

  return u2_cn_nock(0, u2_cn_nock(u2_ci_string(ful_c), u2k(ken)));
}

/* _reck_ream(): ream with toy.
*/
static u2_noun
_reck_ream(u2_reck* rec_u, u2_noun txt)
{
  return u2_cn_mung(u2k(rec_u->toy.ream), txt);
}

/* _reck_rain(): rain with toy.
*/
static u2_noun
_reck_rain(u2_reck* rec_u, u2_noun bon, u2_noun txt)
{
  return u2_cn_mung(u2k(rec_u->toy.rain), u2nc(bon, txt));
}

/* _reck_slam(): slam with toy.
*/
static u2_noun
_reck_slam(u2_reck* rec_u, u2_noun gat, u2_noun sam)
{
  return u2_cn_mung(u2k(rec_u->toy.slam), u2nc(gat, sam));
}

/* _reck_slap(): slap with toy.
*/
static u2_noun
_reck_slap(u2_reck* rec_u, u2_noun vax, u2_noun gen)
{
  return u2_cn_mung(u2k(rec_u->toy.slap), u2nc(vax, gen));
}

/* _reck_slop(): slop with toy.
*/
static u2_noun
_reck_slop(u2_reck* rec_u, u2_noun hed, u2_noun tal)
{
  return u2_cn_mung(u2k(rec_u->toy.slop), u2nc(hed, tal));
}

/* _reck_gate(): nock gate from vase and text.
*/
static u2_noun
_reck_gate(u2_reck* rec_u, u2_noun vax, const c3_c* txt_c)
{
  u2_noun gen = _reck_ream(rec_u, u2_ci_string(txt_c));
  u2_noun vag = _reck_slap(rec_u, vax, gen);
  u2_noun gat = u2k(u2t(vag));

  u2z(vag); 
  return gat;
}

/* _reck_hard(): function against vase, producing noun.
*/
static u2_noun
_reck_hard(u2_reck* rec_u, u2_noun vax, const c3_c* txt_c, u2_noun sam)
{
  return u2_cn_mung(_reck_gate(rec_u, vax, txt_c), sam);
}

/* _reck_coin_da(): print atom as date.
*/
static u2_noun
_reck_coin_da(u2_reck* rec_u, u2_noun ato)
{
  return _reck_hard
    (rec_u, u2k(rec_u->syd), "|=([a=@] ~(rent co ~ %da a))", ato);
}

/* _reck_coin_ud(): print atom as decimal.
*/
static u2_noun
_reck_coin_ud(u2_reck* rec_u, u2_noun ato)
{
  return _reck_hard
    (rec_u, u2k(rec_u->syd), "|=([a=@] ~(rent co ~ %ud a))", ato);
}

/* _reck_soft(): function against vase, producing vase.
*/
static u2_noun
_reck_soft(u2_reck* rec_u, u2_noun vax, const c3_c* txt_c, u2_noun sam)
{
  u2_noun gen = _reck_ream(rec_u, u2_ci_string(txt_c));
  u2_noun gat = _reck_slap(rec_u, vax, gen);

  return _reck_slam(rec_u, gat, sam);
}

/* _reck_spat(): noun path from c, kind of a hack.
*/
static u2_noun 
_reck_spat(c3_c* pax_c)
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
      
      return u2nc(pan, _reck_spat(ash_c + 1));
    }
  }
}

/* _reck_load(): layer file on vase -> vase.
*/
static u2_noun
_reck_load(u2_reck* rec_u, u2_noun vax, c3_c* pax_c)
{
  u2_noun txt = u2_walk_load(pax_c);
  u2_noun gen = _reck_rain
    (rec_u, _reck_spat(pax_c + strlen(u2_Local) + 1), txt);

  return _reck_slap(rec_u, vax, gen);
}

/* _reck_load_temp(): _reck_load() for old fs structure.
*/
static u2_noun
_reck_load_temp(u2_reck* rec_u, u2_noun vax, c3_w kno_w, c3_c* pax_c)
{
  c3_c ful_c[2048];
 
  sprintf(ful_c, "%s/sys/%d/%s", u2_Local, kno_w, pax_c);
  return _reck_load(rec_u, vax, ful_c);
}

/* _reck_time_set(): set the reck time.
*/
static void
_reck_time_set(u2_reck* rec_u)
{
  struct timeval tim_tv;

  gettimeofday(&tim_tv, 0);
  u2z(rec_u->now);
  rec_u->now = u2_time_in_tv(&tim_tv);

  u2z(rec_u->wen);
  rec_u->wen = _reck_coin_da(rec_u, u2k(rec_u->now));
}

/* _reck_time_bump(): advance the reck time by a small increment.
*/
static void
_reck_time_bump(u2_reck* rec_u)
{ 
  c3_d bum_d = (1ULL << 48ULL);

  rec_u->now = u2_cka_add(rec_u->now, u2_ci_chubs(1, &bum_d));
}

/* u2_reck_peek(): query the reck namespace.
*/
u2_noun
u2_reck_peek(u2_reck* rec_u, u2_noun hap)
{
  return _reck_hard(rec_u, u2k(rec_u->rec), "peek", u2nc(u2k(rec_u->now), hap));
}

/* u2_reck_init(): load the reck engine, from kernel.
*/
void
u2_reck_init(u2_reck* rec_u, c3_w kno_w, u2_noun ken)
{
  memset(rec_u, 0, sizeof(*rec_u));
  rec_u->kno_w = kno_w;
  rec_u->rno_w = 0;

  rec_u->ken = ken;
  rec_u->syd = _reck_root("seed", u2k(ken));

  rec_u->pug = 0;

  rec_u->toy.rain = _reck_root("rain", u2k(ken));
  rec_u->toy.ream = _reck_root("ream", u2k(ken));
  // rec_u->toy.sham = _reck_root("sham", u2k(ken));
  rec_u->toy.slay = _reck_root("slay", u2k(ken));
  rec_u->toy.slam = _reck_root("slam", u2k(ken));
  rec_u->toy.slap = _reck_root("slap", u2k(ken));
  rec_u->toy.slop = _reck_root("slop", u2k(ken));

  _reck_time_set(rec_u);
  {
    c3_c* dyt_c = u2_cr_string(rec_u->wen);

    printf("time: %s\n", dyt_c);
    free(dyt_c);
  }
  {
    u2_noun syd, zen, yen, xan, wol, ray, vay;

    syd = u2k(rec_u->syd);

    {
      // printf("ford:\n");
      zen = _reck_load_temp(rec_u, u2k(syd), kno_w, "reck/ford.hoon");

      rec_u->toy.sham = _reck_gate(rec_u, u2k(zen), "sham");

      // printf("hyde:\n");
      yen = _reck_load_temp(rec_u, zen, kno_w, "reck/hyde.hoon");

      // printf("arvo:\n");
      xan = _reck_load_temp(rec_u, yen, kno_w, "reck/arvo.hoon");

      // printf("bede:\n");
      wol = _reck_load_temp(rec_u, xan, kno_w, "reck/bede.hoon");

      // printf("cary:\n");
      ray = _reck_load_temp(rec_u, wol, kno_w, "reck/cary.hoon");

      rec_u->toy.duel = 
        _reck_gate(rec_u, u2k(ray), "|=([a=arch b=arch] (~(duel cy a) b))");

      // printf("eyre:\n");
      vay = _reck_load_temp(rec_u, ray, kno_w, "reck/eyre.hoon");
    }
    rec_u->rec = vay;
  }
}

/* _reck_kick(): apply an output ovum.
*/
static void
_reck_kick(u2_reck* rec_u, u2_noun ovo)
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

    case c3__talk: p_pay = u2t(pay);
    {
      u2_ve_tank(0, u2k(p_pay));
    } break;

    case c3__warn: u2_cx_cell(u2t(pay), &p_pay, &q_pay);
    {
      switch ( p_pay ) {
        case 0: u2_ve_tank(2, u2k(q_pay)); break;
        case 1: u2_ve_tank(4, u2k(q_pay)); break;
        case 2: u2_ve_tank(6, u2k(q_pay)); break;
      }
    } break;
  }
  u2z(ovo);
}

/* _reck_poke(): insert an input ovum.
*/
static void
_reck_poke(u2_reck* rec_u, u2_noun ovo)
{
  u2_noun sam = _reck_slop(rec_u, u2nc(u2nc(c3__atom, 0), u2k(rec_u->now)),
                                  u2nc(c3__noun, ovo));
  u2_noun gax = _reck_soft(rec_u, u2k(rec_u->rec), "poke", sam);
  u2_noun hix, pux;

  hix = _reck_slap(rec_u, u2k(gax), u2nc(c3__cnbc, 'p'));
  pux = _reck_slap(rec_u, gax, u2nc(c3__cnbc, 'q'));

  u2z(rec_u->rec);
  rec_u->rec = pux; 

  {
    u2_noun hux = u2t(hix);

    while ( u2_nul != hux ) {
      _reck_kick(rec_u, u2k(u2h(hux)));
      hux = u2t(hux);
    }
  }
  u2z(hix);
}

/* _reck_pook(): multiple poke.
*/
static void
_reck_pook(u2_reck* rec_u, u2_noun ova)
{
  u2_noun ovi = ova;

  while ( u2_nul != ovi ) {
    _reck_poke(rec_u, u2k(u2h(ovi)));
    ovi = u2t(ovi);
  } 
  u2z(ova);
}

/* _reck_launch_toy(): launch a new reck engine, with toy parms.
*/
static void
_reck_launch_toy(u2_reck* rec_u, u2_noun pax)
{
  _reck_poke
    (rec_u, 
//     u2nc(pax, u2nq(c3__make, c3_s4('z','u','s','e'), 256, u2k(rec_u->now))));
     u2nc(pax, u2nq(c3__make, c3_s4('z','u','s','e'), 256, 0)));
}

/* u2_reck_sync(): poll and apply sync events (protected).
*/
void
u2_reck_sync(u2_reck* rec_u)
{
  _reck_pook(rec_u, u2_sync_reck(rec_u));
}

/* u2_reck_boot(): boot the reck engine (unprotected).
*/
void
u2_reck_boot(u2_reck* rec_u)
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

    exit(1);
  } 
  else {
    u2_reck_init(rec_u, 
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

/* u2_reck_launch(): launch the reck engine (protected).
*/
void
u2_reck_launch(u2_reck* rec_u)
{
  u2_noun pax = u2nq(c3__gold, c3__term, '0', u2_nul);
  _reck_launch_toy(rec_u, pax);
}

/* u2_reck_line(): apply a reck line (protected).
*/
void
u2_reck_line(u2_reck* rec_u, u2_noun lin)
{
  u2_noun pax = u2nq(c3__gold, c3__term, '0', u2_nul);

  _reck_time_set(rec_u);
  u2_reck_sync(rec_u);
  _reck_time_set(rec_u);

  _reck_poke(rec_u, u2nc(pax, u2nc(c3__line, lin)));
}
