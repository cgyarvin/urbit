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

  rec_u->toy.rain = _reck_root("rain", u2k(ken));
  rec_u->toy.ream = _reck_root("ream", u2k(ken));
  // rec_u->toy.sham = _reck_root("sham", u2k(ken));
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
    u2_noun syd, zil, uno, duo, tre, ber, cay, zin, qua, nul, pay, now;

    syd = u2k(rec_u->syd);

    zil = _reck_load_temp(rec_u, syd, kno_w, "reck/zil.watt");

    rec_u->toy.sham = _reck_gate(rec_u, u2k(zil), "sham");

    uno = _reck_load_temp(rec_u, zil, kno_w, "reck/uno.watt");
    duo = _reck_load_temp(rec_u, uno, kno_w, "reck/duo.watt");
    tre = _reck_load_temp(rec_u, duo, kno_w, "reck/tre.watt");

    ber = _reck_load_temp(rec_u, u2k(tre), kno_w, "reck/born.watt");
    cay = _reck_load_temp(rec_u, u2k(tre), kno_w, "reck/cary.watt");
    zin = _reck_load_temp(rec_u, u2k(tre), kno_w, "reck/zuse.watt");

    rec_u->toy.duel = 
      _reck_gate(rec_u, u2k(cay), "|=([a=arch b=arch] (~(duel cy a) b))");

    qua = _reck_load_temp(rec_u, tre, kno_w, "reck/qua.watt");

    nul = u2nc(u2nt(c3__cube, 0, u2nc(c3__atom, 'n')), 0);
    pay = _reck_slop(rec_u, 
                     ber, 
                     _reck_slop(rec_u, 
                                cay,
                                _reck_slop(rec_u, zin, nul)));
    now = u2nc(u2nc(c3__atom, c3_s2('d','a')), u2k(rec_u->now));

    rec_u->rec = _reck_slam(rec_u, qua, _reck_slop(rec_u, now, pay));
  }
}

/* _reck_kiwi(): apply reck output; produce (list lamb)
*/
u2_noun 
_reck_kiwi(u2_reck* rec_u, u2_noun veb)
{
  u2_noun p_veb, q_veb, r_veb;
  u2_noun lab = u2_nul;

  switch ( u2h(veb) ) {
    case 'p': {
      u2_cx_trel(u2t(veb), &p_veb, &q_veb, &r_veb);

      u2_ve_tank(u2k(q_veb), u2k(r_veb));
      break;
    }
    case 't': {
      u2_ve_sway(2, u2k(u2t(veb)));
      break;
    }
    case 'o': {
      u2_cx_cell(u2t(veb), &p_veb, &q_veb);

      switch ( p_veb ) {
        //  $:  p=tube
        //      ^=  q
        //      $%  [%i p=@tas q=path]          ::  load from get/
        //          [%o p=path q=*]             ::  save to put/
        //      ==
        //  ==
        case c3__ber: {
          u2_noun tub = u2k(u2h(q_veb));
          u2_noun pay = u2k(u2t(q_veb));

          switch ( u2h(pay) ) {
            default: break;

            case 'i': {
              u2_noun var=u2k(u2h(u2t(pay)));
              u2_noun pax=u2k(u2t(u2t(pay)));
              u2_noun pad;
              c3_c*   pax_c;

              pax = u2nc(c3_s3('g','e','t'), pax);
              pax_c = u2_path(u2_yes, pax);

              pad = u2nc(var, u2_walk_load(pax_c));
              free(pax_c);

              lab = u2nc
                (u2nt('o',
                      u2nc
                        (c3__echo, 
                         u2nt(c3_s2('p', 'i'),
                              u2nq(c3__load,
                                   _reck_coin_ud(rec_u, u2k(u2h(tub))),
                                   _reck_coin_ud(rec_u, u2k(u2t(tub))),
                                   u2_nul),
                              pad)),
                      u2_nul),
                 lab);
              break;
            } 
          }
        }
      }
      break;
    }
  }
  u2z(veb);
  return lab;
}

/* _reck_kiwis(): apply a kiwi list; produce (list lamb).
*/
static u2_noun
_reck_kiwis(u2_reck *rec_u, u2_noun vyl, u2_noun bal)
{
  if ( u2_no != u2du(vyl) ) {
    u2_noun lab = _reck_kiwi(rec_u, u2k(u2h(vyl)));

    bal = u2_ckb_weld(lab, bal);
    bal = _reck_kiwis(rec_u, u2k(u2t(vyl)), bal);

    u2z(vyl);
  }
  return bal;
}

/* _reck_gall(): apply a reck result; produce (list lamb).
*/
static u2_noun
_reck_gall(u2_reck* rec_u, u2_noun gax)
{
  u2_noun hix, pux, bal;

  hix = _reck_slap(rec_u, u2k(gax), u2nc(c3__cnbc, 'p'));
  pux = _reck_slap(rec_u, gax, u2nc(c3__cnbc, 'q'));

  bal = _reck_kiwis(rec_u, u2k(u2t(hix)), u2_nul);
  u2z(hix);

  u2z(rec_u->rec);
  rec_u->rec = pux; 

  return bal;
}

/* _reck_prod(): poke with raw lamb, produce more lambs.
*/
static u2_noun 
_reck_prod(u2_reck* rec_u, u2_noun lam)
{
  u2_noun sam = _reck_slop(rec_u, u2nc(u2nc(c3__atom, 0), u2k(rec_u->now)),
                                  u2nc(c3__noun, lam));
  u2_noun gax = gax = _reck_soft(rec_u, u2k(rec_u->rec), "poke", sam);

  return _reck_gall(rec_u, gax);
}

/* _reck_poke(): apply lamb cycle.
*/
static void
_reck_poke(u2_reck* rec_u, u2_noun lam)
{
  u2_noun bal = _reck_prod(rec_u, lam);

  _reck_time_bump(rec_u);

  while ( u2_nul != bal ) {
    u2_noun buz = u2k(u2h(bal));
    u2_noun waq = u2k(u2t(bal));

    u2z(bal);
    _reck_prod(rec_u, buz);
    bal = waq;
  }
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
  } 
  else {
    // printf("loading reck...\n");
    u2_reck_init(rec_u, 
                 u2_Host.kno_w, 
                 u2k(u2_Host.ver_e[u2_Host.kno_w].ken));
    // printf("loaded reck.\n");

#if 1
    /* initial sync with filesystem
    */
    {
      u2_noun lam = u2_sync_reck(rec_u);

      _reck_poke(rec_u, lam);
    }
#endif

    /* hack - hardcode a local.
    */
    {
      u2_noun lam = u2nc
        ('o',
         u2nc(u2nc(c3__cay,
                   u2nt(c3_s2('p','i'),
                        u2nc(u2_ci_string("~ligbud-barnel"), u2_nul),
                        u2_yes)),
              u2_nul));

      _reck_poke(rec_u, lam);
    } 
    u2_cm_done();
  
    u2_cm_purge();
    if ( (u2_yes == u2_Flag_Garbage) || (u2_no == u2_wire_lan(u2_Wire)) ) {
      u2_ve_grab(0);
    }
  }
  u2_cm_chin();
}

/* u2_reck_line(): apply a reck line (protected).
*/
void
u2_reck_line(u2_reck* rec_u, u2_noun lin)
{
  static c3_w seq_w = 1;

  _reck_time_set(rec_u);
#if 1
  {
    u2_noun lam = u2_sync_reck(rec_u);

    _reck_poke(rec_u, lam);
  }
#endif
  {
    u2_noun lam = u2nq('l', u2nc(0, 0), seq_w, lin);

    _reck_poke(rec_u, lam);
    seq_w++;
  }
}
