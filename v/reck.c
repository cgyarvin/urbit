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
 
  sprintf(ful_c, "%s/sys/%d/%s", u2_Local, kno_w, pax_c);
  return _reck_load(rec_u, vax, ful_c);
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
  rec_u->own = 0;

  rec_u->toy.rain = _reck_root("rain", u2k(ken));
  rec_u->toy.ream = _reck_root("ream", u2k(ken));
  rec_u->toy.slay = _reck_root("slay", u2k(ken));
  rec_u->toy.slam = _reck_root("slam", u2k(ken));
  rec_u->toy.slap = _reck_root("slap", u2k(ken));
  rec_u->toy.slop = _reck_root("slop", u2k(ken));
  rec_u->toy.scot = _reck_root("scot", u2k(ken));
  rec_u->toy.spat = _reck_root("spat", u2k(ken));
  rec_u->toy.turf = _reck_root("turf", u2k(ken));
  rec_u->toy.tuft = _reck_root("tuft", u2k(ken));

  u2_reck_time(rec_u);
  {
    c3_c* dyt_c = u2_cr_string(rec_u->wen);

    printf("time: %s\n", dyt_c);
    free(dyt_c);
  }
  {
    u2_noun syd, zen, yen, xan, wol, ray, dyl, gul, vay;

    syd = u2k(rec_u->syd);

    {
      // printf("hyde:\n");
      yen = _reck_load_temp(rec_u, u2k(syd), kno_w, "arvo/hyde.hoon");

      // printf("ford:\n");
      zen = _reck_load_temp(rec_u, yen, kno_w, "arvo/ford.hoon");

      rec_u->toy.sham = _reck_gate(rec_u, u2k(zen), "sham");

      // printf("ames:\n");
      xan = _reck_load_temp(rec_u, zen, kno_w, "arvo/ames.hoon");

      // printf("bede:\n");
      wol = _reck_load_temp(rec_u, xan, kno_w, "arvo/bede.hoon");

      // printf("cary:\n");
      ray = _reck_load_temp(rec_u, wol, kno_w, "arvo/cary.hoon");

      rec_u->toy.duel = 
        _reck_gate(rec_u, u2k(ray), "|=([a=arch b=arch] (~(duel cy a) b))");

      // printf("dill:\n");
      dyl = _reck_load_temp(rec_u, ray, kno_w, "arvo/dill.hoon");

      // printf("gall:\n");
      gul = _reck_load_temp(rec_u, dyl, kno_w, "arvo/gall.hoon");

      // printf("eyre:\n");
      vay = _reck_load_temp(rec_u, gul, kno_w, "arvo/eyre.hoon");
    }
    rec_u->rec = vay;
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
      u2_reck_plan(rec_u, pox, u2nc(c3__helo, u2_nul));

      u2z(fav); return u2_yes;
    } break; 
     
    case c3__blit: p_fav = u2t(fav);
    {
      u2_term_ef_blit(rec_u, tid_l, u2k(p_fav));

      u2z(pox); u2z(fav); return u2_yes;
    } break;

    case c3__crap: p_fav = u2t(fav);
    {
      u2_ve_sway(2, u2_ckb_flop(u2k(p_fav)));
      uL(fprintf(uH, "<<<crap>>>\n"));

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

/* _reck_kick_boot(): apply boot outputs.
*/
static u2_bean
_reck_kick_boot(u2_reck* rec_u, u2_noun pox, u2_noun fav)
{
  u2_noun p_fav;

  if ( u2_no == u2du(fav) ) {
    u2z(pox); u2z(fav); return u2_no;
  } 
  else switch ( u2h(fav) ) {
    default: u2z(pox); u2z(fav); return u2_no;
 
    case c3__bbye: 
    case c3__blit: {
      u2_noun pux = u2nq(c3__gold, c3__term, '1', u2_nul);

      uL(fprintf(uH, "_kick_boot: terminal %s\n", u2_cr_string(u2h(fav)))); 

      u2z(pox);
      return _reck_kick_term(rec_u, pux, 1, fav);
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
                c3_l     sev_l,
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
      u2_http_ef_thou(rec_u, sev_l, coq_l, seq_l, u2k(p_fav));

      return u2_yes;
    } break;
  }
  c3_assert(!"not reached"); return u2_no;
}

/* _reck_kick_sync(): apply boot outputs.
*/
static u2_bean
_reck_kick_sync(u2_reck* rec_u, u2_noun pox, u2_noun fav)
{
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

      case c3__boot: {
        if ( (u2_nul != tt_pox) ) {
          u2z(pox); u2z(fav); return u2_no;
        }
        else { 
          return _reck_kick_boot(rec_u, pox, fav);
        }
      } break;

      case c3__http: {
        u2_noun pud = tt_pox;
        u2_noun p_pud, q_pud, r_pud, s_pud;
        c3_l    sev_l, coq_l, seq_l;

        if ( (u2_no == u2_cr_qual(pud, &p_pud, &q_pud, &r_pud, &s_pud)) ||
             (u2_nul != s_pud) ||
             (u2_no == _reck_lily(rec_u, c3__ux, u2k(p_pud), &sev_l)) ||
             (u2_no == _reck_lily(rec_u, c3__ud, u2k(q_pud), &coq_l)) ||
             (u2_no == _reck_lily(rec_u, c3__ud, u2k(r_pud), &seq_l)) )
        {
          u2z(pox); u2z(fav); return u2_no;
        }
        else {
          return _reck_kick_http(rec_u, pox, sev_l, coq_l, seq_l, fav);
        }
      } break;

      case c3__sync: {
        if ( (u2_nul != tt_pox) ) {
          u2z(pox); u2z(fav); return u2_no;
        }
        else { 
          return _reck_kick_sync(rec_u, pox, fav);
        }
      } break;

      case c3__term: {
        u2_noun pud = tt_pox;
        u2_noun p_pud, q_pud;
        c3_l    tid_l;

        if ( (u2_no == u2_cr_cell(pud, &p_pud, &q_pud)) ||
             (u2_nul != q_pud) ||
             (u2_no == _reck_lily(rec_u, c3__ud, u2k(p_pud), &tid_l)) )
        {
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
  }
  c3_assert(!"not reached"); return u2_no;
  u2z(pox); u2z(fav); return u2_no;
}

/* _reck_kick(): handle effect.
*/
static void
_reck_kick(u2_reck* rec_u, u2_noun ovo)
{
  if ( (u2_no == _reck_kick_spec(rec_u, u2k(u2h(ovo)), u2k(u2t(ovo)))) &&
       (u2_no == _reck_kick_norm(rec_u, u2k(u2h(ovo)), u2k(u2t(ovo)))) )
  {
    u2_noun tox = _reck_spat(rec_u, u2k(u2h(ovo)));

    uL(fprintf(uH, "kick: lost %s from %s\n", 
                   u2_cr_string(u2h(u2t(ovo))),
                   u2_cr_string(tox)));
    u2z(tox);
  }
  u2z(ovo);
}

#if 0
  u2_noun p_fav, q_fav;

  switch ( u2h(fav) ) {
    default: 
    {
      u2_err(u2_Wire, "unsupported", u2h(fav));
    } break;

    case c3__bbye: 
    {
      u2_reck_sync(rec_u);
      u2_reck_plan(rec_u, u2k(u2h(ovo)), u2nc(c3__helo, u2_nul));

      break;
    } 
    case c3__blit: p_fav = u2t(fav);
    {
      u2_term_ef_blit(rec_u, 1, u2k(p_fav));
      break;
    }
    case c3__crap: p_fav = u2t(fav);
    {
      u2_ve_sway(2, u2_ckb_flop(u2k(p_fav)));
      printf("<<<exit>>>\n");
    } break;

    case c3__exit:
    {
      fprintf(uH, "<goodbye>\n");
      exit(0);
    } break;

    case c3__init: p_fav = u2t(fav);
    {
      rec_u->own = u2nc(u2k(p_fav), rec_u->own);
      break;
    }
    case c3__talk: p_fav = u2t(fav);
    {
      u2_ve_tank(0, u2k(p_fav));
    } break;

    case c3__thou: p_fav = u2t(fav);
    {
      u2_ve_http_respond(u2k(u2h(ovo)), u2k(p_fav));
      break;
    }
    case c3__save: u2_cx_cell(u2t(fav), &p_fav, &q_fav);
    {
      u2_noun pax = u2nc(c3__put, u2k(p_fav));
      c3_c*   pax_c = u2_path(u2_yes, pax);
 
      u2_walk_save(pax_c, 0, u2k(q_fav));
      free(pax_c);
    } break;
    case c3__warn: u2_cx_cell(u2t(fav), &p_fav, &q_fav);
    {
      switch ( p_fav ) {
        case 0: u2_ve_tank(2, u2k(q_fav)); break;
        case 1: u2_ve_tank(4, u2k(q_fav)); break;
        case 2: u2_ve_tank(6, u2k(q_fav)); break;
      }
    } break;
  }
  c3_assert(!"not reached");
  return u2_no;
}
#endif

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

/* _reck_launch_toy(): launch a new reck engine, with toy parms.
*/
static void
_reck_launch_toy(u2_reck* rec_u, u2_noun pax)
{
  //  This is our ONLY remaining off-queue poke.
  //
  _reck_poke
    (rec_u, 
//     u2nc(pax, u2nq(c3__make, c3_s4('z','u','s','e'), 256, u2k(rec_u->now))));
     u2nc(u2k(pax), u2nq(c3__make, c3_s4('z','u','s','e'), 256, 0)));

  if ( u2_nul == rec_u->own ) {
    u2z(pax);
    fprintf(stderr, "make failed?\n"); 
    u2_cm_bail(c3__exit);
  }
  else {
    _reck_poke
      (rec_u,
       u2nc(pax, 
            u2nt(c3__bind,
                 u2k(u2h(rec_u->own)),
                 u2nc(u2_yes, u2_nul))));
  }
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

/* u2_reck_launch(): call reck launch fn (unprotected).
*/
u2_bean
u2_reck_launch(u2_reck* rec_u)
{
  u2_noun hoe;
  u2_noun gud;

  u2_cm_trip();
  if ( 0 != (hoe = u2_cm_trap()) ) {
    u2_cm_purge();
    u2_ve_grab(hoe, 0);

    u2_ve_wine(u2k(u2h(hoe)));
    u2_ve_sway(2, u2_ckb_flop(u2k(u2t(hoe))));
    u2z(hoe);

    gud = u2_no;
  } 
  else {
    {
      u2_noun pax = u2nq(c3__gold, c3__term, '1', u2_nul);
      // u2_noun pax = u2nt(c3__gold, c3__boot, u2_nul);

      _reck_launch_toy(rec_u, pax);
    }
    u2_cm_done();
  
    u2_cm_purge();
    if ( (u2_yes == u2_Flag_Garbage) || (u2_no == u2_wire_lan(u2_Wire)) ) {
      u2_ve_grab(0);
    }

    gud = u2_yes;
  }
  u2_cm_chin();
  return gud;
}

/* u2_reck_http_request(): hear http request on channel (unprotected).
*/
void
u2_reck_http_request(u2_reck* rec_u, u2_bean sec, u2_noun pox, u2_noun req)
{
  u2_reck_plan(rec_u, pox, u2nc((sec == u2_yes) ? c3__this : c3__thin, req));
}

/* u2_reck_line(): apply a reck line (protected).
*/
void
u2_reck_line(u2_reck* rec_u, u2_noun lin)
{
  u2_noun pax = u2nq(c3__gold, c3__term, '0', u2_nul);

  u2_reck_time(rec_u);
  u2_reck_sync(rec_u);
  u2_reck_time(rec_u);

  _reck_poke(rec_u, u2nc(pax, u2nc(c3__line, lin)));
}

/* u2_reck_prick(): query the reck namespace (unprotected).
*/
u2_noun
u2_reck_prick(u2_reck* rec_u, u2_noun hap)
{
  u2_noun hoe;
  u2_noun que;

  if ( 0 != (hoe = u2_cm_trap()) ) {
    u2_cm_purge();
    u2_ve_grab(hoe, 0);

    u2_ve_wine(u2k(u2h(hoe)));
    u2_ve_sway(2, u2_ckb_flop(u2k(u2t(hoe))));
    u2z(hoe);

    return u2_none;
  } 
  else {
    que = u2_reck_peek(rec_u, hap);
    u2_cm_done();
  
    u2_cm_purge();
    if ( (u2_yes == u2_Flag_Garbage) || (u2_no == u2_wire_lan(u2_Wire)) ) {
      u2_ve_grab(0);
    }
  }
  return que;
}

/* _reck_pork(): insert an input ovum (unprotected).
*/
static void
_reck_pork(u2_reck* rec_u, u2_noun ovo)
{
  u2_noun hoe;

  if ( 0 != (hoe = u2_cm_trap()) ) {
    u2_cm_purge();
    u2_ve_grab(hoe, 0);

    u2_ve_wine(u2k(u2h(hoe)));
    u2_ve_sway(2, u2_ckb_flop(u2k(u2t(hoe))));
    u2z(hoe);

    //  trigger fail
    u2_lo_bail(rec_u);
    exit(1);
  } 
  else {
    {
      u2_noun sam = _reck_slop(rec_u, u2nc(u2nc(c3__atom, 0), 
                                           u2k(rec_u->now)),
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
    u2_cm_done();
  
    u2_cm_purge();
    if ( (u2_yes == u2_Flag_Garbage) || (u2_no == u2_wire_lan(u2_Wire)) ) {
      u2_ve_grab(0);
    }
  }
}

/* u2_reck_work(): flush ova (unprotected).
*/
void
u2_reck_work(u2_reck* rec_u)
{
  while ( rec_u->ova.egg_u ) {
    u2_cart* egg_u = rec_u->ova.egg_u;

    _reck_pork(rec_u, egg_u->egg);

    rec_u->ova.egg_u = egg_u->nex_u;
    if ( 0 == rec_u->ova.egg_u ) {
      c3_assert(egg_u == rec_u->ova.geg_u);
      rec_u->ova.geg_u = 0;
    }
    free(egg_u);
  }
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
