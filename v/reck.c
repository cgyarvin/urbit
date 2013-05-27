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
#include <curses.h>
#include <termios.h>
#include <term.h>

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

/* _reck_nock_poke(): call poke through hardcoded interface.
*/
static u2_noun
_reck_nock_poke(u2_reck* rec_u, u2_noun ovo)
{
  u2_noun fun = u2_cn_nock(u2k(rec_u->roc), u2k(u2_cx_at(42, rec_u->roc)));
  u2_noun sam = u2nc(u2k(rec_u->now), ovo);

  return u2_cn_mung(fun, sam);
}

/* _reck_nock_peek(): call peek through hardcoded interface.
*/
static u2_noun
_reck_nock_peek(u2_reck* rec_u, u2_noun our, u2_noun hap)
{
  u2_noun fun = u2_cn_nock(u2k(rec_u->roc), u2k(u2_cx_at(87, rec_u->roc)));
  u2_noun sam = u2nt(our, u2k(rec_u->now), hap);

  return u2_cn_mung(fun, sam);
}

/* _reck_nock_keep(): call wait through hardcoded interface.
*/
static u2_noun
_reck_nock_keep(u2_reck* rec_u, u2_noun hap)
{
  u2_noun fun = u2_cn_nock(u2k(rec_u->roc), u2k(u2_cx_at(4, rec_u->roc)));
  u2_noun sam = u2nc(u2k(rec_u->now), hap);

  return u2_cn_mung(fun, sam);
}

/* _reck_nock_wish(): call wish through hardcoded interface.
*/
static u2_noun
_reck_nock_wish(u2_reck* rec_u, u2_noun txt)
{
  u2_noun fun = u2_cn_nock(u2k(rec_u->roc), u2k(u2_cx_at(20, rec_u->roc)));

  return u2_cn_mung(fun, txt);
}

/* u2_reck_wish(): noun from expression
*/
u2_noun 
u2_reck_wish(u2_reck* rec_u, c3_c* str_c)
{
  return _reck_nock_wish(rec_u, u2_ci_string(str_c));
}

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

/* _reck_spat(): spat with toy.
*/
static u2_noun
_reck_spat(u2_reck* rec_u, u2_noun pox)
{
  return u2_cn_mung(u2k(rec_u->toy.spat), pox);
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

#if 0
/* _reck_coin_ud(): print atom as decimal.
*/
static u2_noun
_reck_coin_ud(u2_reck* rec_u, u2_noun ato)
{
  return _reck_hard
    (rec_u, u2k(rec_u->syd), "|=([a=@] ~(rent co ~ %ud a))", ato);
}
#endif

/* _reck_coin_uv(): print atom as base32.
*/
static u2_noun
_reck_coin_uv(u2_reck* rec_u, u2_noun ato)
{
  return _reck_hard
    (rec_u, u2k(rec_u->syd), "|=([a=@] ~(rent co ~ %uv a))", ato);
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

/* _reck_spoo(): noun path from c, kind of a hack.
*/
static u2_noun 
_reck_spoo(c3_c* pax_c)
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
      
      return u2nc(pan, _reck_spoo(ash_c + 1));
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
    (rec_u, _reck_spoo(pax_c + strlen(u2_Local) + 1), txt);

  return _reck_slap(rec_u, vax, gen);
}

/* _reck_load_temp(): _reck_load() for old fs structure.
*/
static u2_noun
_reck_load_temp(u2_reck* rec_u, u2_noun vax, c3_w kno_w, c3_c* pax_c)
{
  c3_c ful_c[2048];
 
  sprintf(ful_c, "%s/%d/%s", u2_System, kno_w, pax_c);
  return _reck_load(rec_u, vax, ful_c);
}

/* _reck_load_arvo(): read an arvo file.
*/
static u2_noun
_reck_load_arvo(u2_reck* rec_u, c3_c* pax_c)
{
  c3_c ful_c[2048];
  u2_noun hof = u2_cn_mung(u2k(rec_u->toy.hoof), rec_u->kno_w);
  c3_c* hof_c = u2_cr_string(hof);

  sprintf(ful_c, "%s/%d/arvo/%s.%s", u2_System, rec_u->kno_w, pax_c, hof_c);
  return u2_walk_load(ful_c);
}

/* u2_reck_time(): set the reck time.
*/
void
u2_reck_time(u2_reck* rec_u)
{
  struct timeval tim_tv;

  gettimeofday(&tim_tv, 0);
  u2z(rec_u->now);
  rec_u->now = u2_time_in_tv(&tim_tv);

  u2z(rec_u->wen);
  rec_u->wen = _reck_coin_da(rec_u, u2k(rec_u->now));
}

/* u2_reck_wind(): set the reck time artificially.
*/
void
u2_reck_wind(u2_reck* rec_u, u2_noun now)
{
  u2z(rec_u->now);
  rec_u->now = now;

  u2z(rec_u->wen);
  rec_u->wen = _reck_coin_da(rec_u, u2k(rec_u->now));
}

/* u2_reck_numb(): set the instance number.
*/
void
u2_reck_numb(u2_reck* rec_u)
{
  struct timeval tp;

  gettimeofday(&tp, 0);
  rec_u->sev_l = 0x7fffffff & 
                 ( ((c3_w) tp.tv_sec) ^
                   u2_mug(0x7fffffff & ((c3_w) tp.tv_usec)) ^
                   u2_mug(getpid()));
                 
  rec_u->sen = _reck_coin_uv(rec_u, rec_u->sev_l);
}

#if 0
/* _reck_time_bump(): advance the reck time by a small increment.
*/
static void
_reck_time_bump(u2_reck* rec_u)
{ 
  c3_d bum_d = (1ULL << 48ULL);

  rec_u->now = u2_cka_add(rec_u->now, u2_ci_chubs(1, &bum_d));
}
#endif

/* u2_reck_peek(): query the reck namespace (protected).
*/
u2_noun
u2_reck_peek(u2_reck* rec_u, u2_noun our, u2_noun hap)
{
  return _reck_nock_peek(rec_u, our, hap);
}

/* u2_reck_keep(): measure timer.
*/
u2_noun 
u2_reck_keep(u2_reck* rec_u, u2_noun hap)
{
  return _reck_nock_keep(rec_u, hap);
}

/* _reck_init_veer(): install vane with direct poke.
*/
static void
_reck_init_veer(u2_reck* rec_u, u2_noun nam, u2_noun pax, u2_noun txt)
{
  u2_noun ovo, pro;

  pax = u2nc(c3__arvo, pax);
  ovo = u2nc(u2nc(c3__gold, u2_nul), u2nc(c3__veer, 
                                          u2nq(u2_yes, nam, pax, txt)));
  pro = _reck_nock_poke(rec_u, ovo);

  u2z(rec_u->roc);
  rec_u->roc = u2k(u2t(pro));
  u2z(pro);
}

/* u2_reck_init(): load the reck engine, from kernel.
*/
void
u2_reck_init(u2_reck* rec_u, c3_w kno_w, u2_noun ken)
{
  memset(rec_u, 0, sizeof(*rec_u));
  rec_u->kno_w = kno_w;
  rec_u->rno_w = 0;

  rec_u->own = 0;
  rec_u->now = 0;
  rec_u->wen = 0;
  rec_u->sen = 0;
  rec_u->our = 0;
  rec_u->pod = 0;
  rec_u->roe = 0;
  rec_u->key = 0;

  rec_u->dir_c = 0;

  if ( kno_w > 191 ) {
    rec_u->ken = ken;
    rec_u->syd = _reck_root("seed", u2k(ken));
    rec_u->roc = 0;

    rec_u->toy.rain = _reck_root("rain", u2k(ken));
    rec_u->toy.ream = _reck_root("ream", u2k(ken));
    rec_u->toy.slay = _reck_root("slay", u2k(ken));
    rec_u->toy.slam = _reck_root("slam", u2k(ken));
    rec_u->toy.slap = _reck_root("slap", u2k(ken));
    rec_u->toy.slop = _reck_root("slop", u2k(ken));
    rec_u->toy.scot = _reck_root("scot", u2k(ken));
    rec_u->toy.spat = _reck_root("spat", u2k(ken));
    rec_u->toy.stab = _reck_root("stab", u2k(ken));
    rec_u->toy.turf = _reck_root("turf", u2k(ken));
    rec_u->toy.tuft = _reck_root("tuft", u2k(ken));
    rec_u->toy.wash = _reck_root("wash", u2k(ken));
    rec_u->toy.hoof = _reck_root("hoof", u2k(ken));
    rec_u->toy.mook = _reck_root("mook", u2k(ken));

    u2_reck_time(rec_u);
    u2_reck_numb(rec_u);
    {
      c3_c* dyt_c = u2_cr_string(rec_u->wen);

      printf("time: %s\n", dyt_c);
      free(dyt_c);
    }
    {
      u2_noun syd, zen, yen, xan, wol, ray, dyl, yer, vay;

      syd = u2k(rec_u->syd);

      {
        // printf("hyde:\n");
        yen = _reck_load_temp(rec_u, u2k(syd), kno_w, "arvo/hyde.hoon");

        // printf("ford:\n");
        zen = _reck_load_temp(rec_u, yen, kno_w, "arvo/ford.hoon");

        rec_u->toy.sham = _reck_gate(rec_u, u2k(zen), "sham");
        rec_u->toy.shen = _reck_gate(rec_u, u2k(zen), "en:crya");
        rec_u->toy.shed = _reck_gate(rec_u, u2k(zen), "de:crya");

        // printf("ames:\n");
        xan = _reck_load_temp(rec_u, zen, kno_w, "arvo/ames.hoon");

        // printf("born:\n");
        wol = _reck_load_temp(rec_u, xan, kno_w, "arvo/born.hoon");

        // printf("clay:\n");
        ray = _reck_load_temp(rec_u, wol, kno_w, "arvo/clay.hoon");

        // printf("dill:\n");
        dyl = _reck_load_temp(rec_u, ray, kno_w, "arvo/dill.hoon");

        // printf("eyre:\n");
        yer = _reck_load_temp(rec_u, dyl, kno_w, "arvo/eyre.hoon");

        // printf("zuse:\n");
        vay = _reck_load_temp(rec_u, yer, kno_w, "arvo/zuse.hoon");
      }
      rec_u->roc = u2_cn_nock(0, u2k(u2t(vay)));
      u2z(vay);
    }
  } else {
    rec_u->ken = ken;
    rec_u->roc = u2_cn_nock(0, u2k(ken));

    rec_u->syd = u2_reck_wish(rec_u, "seed");
    rec_u->toy.rain = u2_reck_wish(rec_u, "rain");
    rec_u->toy.ream = u2_reck_wish(rec_u, "ream");
    rec_u->toy.slay = u2_reck_wish(rec_u, "slay");
    rec_u->toy.slam = u2_reck_wish(rec_u, "slam");
    rec_u->toy.slap = u2_reck_wish(rec_u, "slap");
    rec_u->toy.slop = u2_reck_wish(rec_u, "slop");
    rec_u->toy.scot = u2_reck_wish(rec_u, "scot");
    rec_u->toy.spat = u2_reck_wish(rec_u, "spat");
    rec_u->toy.stab = u2_reck_wish(rec_u, "stab");
    rec_u->toy.turf = u2_reck_wish(rec_u, "turf");
    rec_u->toy.tuft = u2_reck_wish(rec_u, "tuft");
    rec_u->toy.wash = u2_reck_wish(rec_u, "wash");
    rec_u->toy.hoof = u2_reck_wish(rec_u, "hoof");
    rec_u->toy.mook = u2_reck_wish(rec_u, "mook");

    //  Direct poke to install tang/vanes.  Shd be in egz but isnt.
    //
    {
      _reck_init_veer(rec_u, 0, 
                             u2nc(c3__zuse, u2_nul),
                             _reck_load_arvo(rec_u, "zuse"));

      _reck_init_veer(rec_u, 'a', 
                             u2nc(c3__ames, u2_nul), 
                             _reck_load_arvo(rec_u, "ames"));

      _reck_init_veer(rec_u, 'b', 
                             u2nc(c3__born, u2_nul),
                             _reck_load_arvo(rec_u, "born"));

      _reck_init_veer(rec_u, 'c', 
                             u2nc(c3__clay, u2_nul),
                             _reck_load_arvo(rec_u, "clay"));

      _reck_init_veer(rec_u, 'd', 
                             u2nc(c3__dill, u2_nul),
                             _reck_load_arvo(rec_u, "dill"));

      _reck_init_veer(rec_u, 'e', 
                             u2nc(c3__eyre, u2_nul),
                             _reck_load_arvo(rec_u, "eyre"));
    }
    rec_u->toy.sham = u2_reck_wish(rec_u, "sham");
    rec_u->toy.shen = u2_reck_wish(rec_u, "en:crya");
    rec_u->toy.shed = u2_reck_wish(rec_u, "de:crya");
    rec_u->toy.cyst = u2_reck_wish(rec_u, "cyst");

    u2_reck_time(rec_u);
    u2_reck_numb(rec_u);
    {
      c3_c* dyt_c = u2_cr_string(rec_u->wen);

      printf("time: %s\n", dyt_c);
      free(dyt_c);
    }
  }
}

/* _reck_mole(): parse simple atomic mole.
*/
static u2_bean 
_reck_mole(u2_reck* rec_u,
                u2_noun  fot,
                u2_noun  san,
                c3_d*    ato_d)
{
  u2_noun uco = u2_cn_mung(u2k(rec_u->toy.slay), san);
  u2_noun p_uco, q_uco, r_uco, s_uco;

  if ( (u2_no == u2_cr_qual(uco, &p_uco, &q_uco, &r_uco, &s_uco)) ||
       (0 != p_uco) ||
       (0 != q_uco) ||
       (u2_no == u2_sing(fot, r_uco)) )
  {
    uL(fprintf(uH, "strange mole\n"));

    u2z(fot); u2z(uco); return u2_no;
  }
  else {
    *ato_d = u2_cr_chub(0, s_uco);

    u2z(fot); u2z(uco); return u2_yes;
  }
}

/* _reck_lily(): parse little atom.
*/
static u2_bean
_reck_lily(u2_reck* rec_u, u2_noun fot, u2_noun txt, c3_l* tid_l) 
{
  c3_d ato_d;

  if ( u2_no == _reck_mole(rec_u, fot, txt, &ato_d) ) {
    return u2_no;
  } else {
    if ( ato_d >= 0x80000000ULL ) {
      return u2_no;
    } else {
      *tid_l = (c3_l) ato_d;

      return u2_yes;
    }
  }
}

/* _reck_kick_term(): apply terminal outputs.
*/
static u2_bean
_reck_kick_term(u2_reck* rec_u, u2_noun pox, c3_l tid_l, u2_noun fav)
{
  u2_noun p_fav;

  if ( u2_no == u2du(fav) ) {
    u2z(pox); u2z(fav); return u2_no;
  }
  else switch ( u2h(fav) ) {
    default: u2z(pox); u2z(fav); return u2_no;
    case c3__bbye: 
    {
      u2_reck_sync(rec_u);
      // u2_reck_plan(rec_u, pox, u2nc(c3__helo, u2_nul));

      u2z(fav); return u2_yes;
    } break; 
     
    case c3__blit: p_fav = u2t(fav);
    {
      u2_term_ef_blit(rec_u, tid_l, u2k(p_fav));

      u2z(pox); u2z(fav); return u2_yes;
    } break;

    case c3__init: p_fav = u2t(fav);
    {
      rec_u->own = u2nc(u2k(p_fav), rec_u->own);
      u2z(pox); u2z(fav); return u2_yes;
    } break;
  }
  c3_assert(!"not reached"); return 0;
}

/* _reck_kick_http(): apply http effects.
*/
static u2_bean
_reck_kick_http(u2_reck* rec_u, 
                u2_noun  pox,
                c3_l     coq_l,
                c3_l     seq_l,
                u2_noun  fav)
{
  u2_noun p_fav;

  if ( u2_no == u2du(fav) ) {
    u2z(pox); u2z(fav); return u2_no;
  } 
  else switch ( u2h(fav) ) {
    default: u2z(pox); u2z(fav); return u2_no;
 
    case c3__thou: p_fav = u2t(fav);
    {
      u2_http_ef_thou(rec_u, coq_l, seq_l, u2k(p_fav));

      return u2_yes;
    } break;
  }
  c3_assert(!"not reached"); return u2_no;
}

/* _reck_kick_sync(): apply sync outputs.
*/
static u2_bean
_reck_kick_sync(u2_reck* rec_u, u2_noun pox, u2_noun fav)
{
  //  XX obviously not right!
  //
  u2z(pox); u2z(fav); return u2_no;
}

/* _reck_kick_ames(): apply packet network outputs.
*/
static u2_bean
_reck_kick_ames(u2_reck* rec_u, u2_noun pox, u2_noun fav)
{
  switch ( u2h(fav) ) {
    default: break;
    case c3__send: {
      u2_noun lan = u2k(u2h(u2t(fav)));
      u2_noun pac = u2k(u2t(u2t(fav)));

      u2_ames_ef_send(rec_u, lan, pac);
      u2z(pox); u2z(fav); return u2_yes;
    } break;
  }
  u2z(pox); u2z(fav); return u2_no;
}

/* _reck_kick_spec(): apply an effect, by path.
*/
static u2_bean
_reck_kick_spec(u2_reck* rec_u, u2_noun pox, u2_noun fav)
{
  u2_noun i_pox, t_pox;
    
  if ( (u2_no == u2_cr_cell(pox, &i_pox, &t_pox)) ||
       ((i_pox != c3__gold) && (i_pox != c3__iron) && (i_pox != c3__lead)) )
  {
    u2z(pox); u2z(fav); return u2_no;
  } else {
    u2_noun it_pox, tt_pox;

    if ( (u2_no == u2_cr_cell(t_pox, &it_pox, &tt_pox)) ) {
      u2z(pox); u2z(fav); return u2_no;
    }
    else switch ( it_pox ) {
      default: return u2_no;

      case c3__http: {
        u2_noun pud = tt_pox;
        u2_noun p_pud, t_pud, tt_pud, q_pud, r_pud, s_pud;
        c3_l    coq_l, seq_l;

        if ( (u2_no == u2_cr_cell(pud, &p_pud, &t_pud)) ||
             (u2_no == u2_sing(rec_u->sen, p_pud)) )
        {
          u2z(pox); u2z(fav); return u2_no;
        }

        if ( u2_nul == t_pud ) {
          coq_l = seq_l = 0;
        }
        else {
          if ( (u2_no == u2_cr_cell(t_pud, &q_pud, &tt_pud)) ||
               (u2_no == _reck_lily(rec_u, c3__ud, u2k(q_pud), &coq_l)) )
          {
            u2z(pox); u2z(fav); return u2_no;
          }

          if ( u2_nul == tt_pud ) {
            seq_l = 0;
          } else {
            if ( (u2_no == u2_cr_cell(tt_pud, &r_pud, &s_pud)) ||
                 (u2_nul != s_pud) ||
                 (u2_no == _reck_lily(rec_u, c3__ud, u2k(r_pud), &seq_l)) )
            {
              u2z(pox); u2z(fav); return u2_no;
            }
          }
        }
        return _reck_kick_http(rec_u, pox, coq_l, seq_l, fav);
      } break;

      case c3__sync: {
        if ( (u2_nul != tt_pox) ) {
          u2z(pox); u2z(fav); return u2_no;
        }
        else { 
          return _reck_kick_sync(rec_u, pox, fav);
        }
      } break;

      case c3__ames: {
        if ( (u2_nul != tt_pox) ) {
          u2z(pox); u2z(fav); return u2_no;
        }
        else { 
          return _reck_kick_ames(rec_u, pox, fav);
        }
      } break;

      case c3__term: {
        u2_noun pud = tt_pox;
        u2_noun p_pud, q_pud, r_pud;
        c3_l    tid_l;

        if ( (u2_no == u2_cr_trel(pud, &p_pud, &q_pud, &r_pud)) ||
             (u2_nul != r_pud) ||
             (u2_no == u2_sing(rec_u->sen, p_pud)) ||
             (u2_no == _reck_lily(rec_u, c3__ud, u2k(q_pud), &tid_l)) )
        {
          //  uL(fprintf(uH, "term: bad tire\n"));
          u2z(pox); u2z(fav); return u2_no;
        } else {
          return _reck_kick_term(rec_u, pox, tid_l, fav);
        }
      } break;
    }
  }
  c3_assert(!"not reached");
  return u2_no;
}

/* _reck_kick_norm(): non path-specific effect handling.
*/
static u2_bean
_reck_kick_norm(u2_reck* rec_u, u2_noun pox, u2_noun fav)
{
  if ( u2_no == u2du(fav) ) {
    u2z(pox); u2z(fav); return u2_no;
  } 
  else switch ( u2h(fav) ) {
    default: u2z(pox); u2z(fav); return u2_no;
 
    case c3__exit:
    {
      uL(fprintf(uH, "<<<goodbye>>>\n"));
      u2_lo_bail(rec_u);

      u2z(pox); u2z(fav); return u2_yes;
    } break;

    case c3__send:
    {
      u2_noun lan = u2k(u2h(u2t(fav)));
      u2_noun pac = u2k(u2t(u2t(fav)));

      u2_ames_ef_send(rec_u, lan, pac);
      u2z(pox); u2z(fav); return u2_yes;
    } break;
  }
  c3_assert(!"not reached"); return u2_no;
  u2z(pox); u2z(fav); return u2_no;
}

/* u2_reck_kick(): handle effect.
*/
void
u2_reck_kick(u2_reck* rec_u, u2_noun ovo)
{
  if ( (u2_no == _reck_kick_spec(rec_u, u2k(u2h(ovo)), u2k(u2t(ovo)))) &&
       (u2_no == _reck_kick_norm(rec_u, u2k(u2h(ovo)), u2k(u2t(ovo)))) )
  {
    u2_noun tox = _reck_spat(rec_u, u2k(u2h(ovo)));

#if 0
    if ( (c3__warn != u2h(u2t(ovo))) &&
         (c3__text != u2h(u2t(ovo))) &&
         (c3__note != u2h(u2t(ovo))) )
#endif
#if 1
    {
      uL(fprintf(uH, "kick: lost %%%s on %s\n", 
                     u2_cr_string(u2h(u2t(ovo))),
                     u2_cr_string(tox)));
    }
#endif
    u2z(tox);
  }
  u2z(ovo);
}

/* u2_reck_poke(): insert and apply an input ovum (protected).
*/
u2_noun
u2_reck_poke(u2_reck* rec_u, u2_noun ovo)
{
  return _reck_nock_poke(rec_u, ovo);
}

/* u2_reck_sync(): poll and apply sync events (protected).
*/
void
u2_reck_sync(u2_reck* rec_u)
{
  u2_reck_plow(rec_u, u2_sync_reck(rec_u));
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

/* u2_reck_http_request(): hear http request on channel (unprotected).
*/
void
u2_reck_http_request(u2_reck* rec_u, u2_bean sec, u2_noun pox, u2_noun req)
{
  // uL(fprintf(uH, "http: request\n"));
  u2_reck_plan(rec_u, pox, u2nc((sec == u2_yes) ? c3__this : c3__thin, req));
}

/* u2_reck_prick(): query the reck namespace (unprotected).
*/
u2_noun
u2_reck_prick(u2_reck* rec_u, u2_noun our, u2_noun hap)
{
  u2_noun hoe;
  u2_noun que;

  if ( 0 != (hoe = u2_cm_trap()) ) {
    u2_cm_purge();
    u2_ve_grab(hoe, 0);

    u2_ve_wine(u2k(u2h(hoe)));
    u2_ve_sway(2, u2_ckb_flop(u2k(u2t(hoe))));
    u2z(hoe);

    return u2_nul;
  } 
  else {
    que = u2_reck_peek(rec_u, our, hap);
    u2_cm_done();
  
    u2_cm_purge();
    if ( (u2_yes == u2_Flag_Garbage) || (u2_no == u2_wire_lan(u2_Wire)) ) {
      u2_ve_grab(0);
    }
  }
  return que;
}

/* u2_reck_plan(): queue ovum (external).
*/
void
u2_reck_plan(u2_reck* rec_u,
             u2_noun  pax,
             u2_noun  fav)
{
  u2_cart* egg_u = malloc(sizeof(u2_cart));

  egg_u->egg = u2nc(pax, fav);
  egg_u->clr_f = 0;
  egg_u->nex_u = 0;

  if ( !rec_u->ova.egg_u ) {
    c3_assert(0 == rec_u->ova.geg_u);

    rec_u->ova.egg_u = rec_u->ova.geg_u = egg_u;
  } else {
    c3_assert(0 == rec_u->ova.geg_u->nex_u);

    rec_u->ova.geg_u->nex_u = egg_u;
    rec_u->ova.geg_u = egg_u;
  }
}

/* u2_reck_plow(): queue multiple ova (external).
*/
void
u2_reck_plow(u2_reck* rec_u, u2_noun ova)
{
  u2_noun ovi = ova;

  while ( u2_nul != ovi ) {
    u2_noun ovo=u2h(ovi);

    u2_reck_plan(rec_u, u2k(u2h(ovo)), u2k(u2t(ovo)));
    ovi = u2t(ovi);
  } 
  u2z(ova);
}
