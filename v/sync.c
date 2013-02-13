/* v/sync.c
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


/* _sync_peek_arch(): (unit arch) for cay-path.
**
**  XX: Both this and sync_peek_home() are lame.
*/
static u2_noun
_sync_peek_arch(u2_reck* rec_u, u2_noun pos, u2_noun bok)
{
  if ( u2_nul == rec_u->own ) {
    u2z(pos); u2z(bok);
    
    return u2_nul;
  }
  else {
    return u2_reck_prick
      (rec_u, u2k(u2h(rec_u->own)),
                   u2nc(c3_s2('c','z'),
                   u2nq(u2k(rec_u->wen),
                            pos, 
                            bok,
                            u2_nul)));
  }
}

/* _sync_peek_home(): test if we even hold a plot.
*/
static u2_bean
_sync_peek_home(u2_reck* rec_u, u2_noun pos)
{
  if ( u2_nul == rec_u->own ) {
    u2z(pos);
    return u2_nul;
  }
  else {
    u2_noun pec = u2_reck_prick
      (rec_u, u2k(u2h(rec_u->own)),
              u2nc('a',
                   u2nq(u2k(rec_u->wen),
                            pos,
                            c3__mark,
                            u2_nul)));

    if ( u2_no == u2du(pec) ) {
      c3_assert(!"peek_home is hosed\n");
    }
    else {
      u2_bean cep = u2t(pec);

      if ( u2_no == cep ) {
        printf("rejected!\n");
      }
      u2z(pec);
      return cep;
    }
  }
}

#if 0
/* _sync_unix(): unix path as by dir/file.ext or dir/subdir protocol.
*/
static c3_c*
_sync_unix(u2_bean dir, u2_noun hac)
{
  c3_w len_w;
  c3_c *pas_c;

  //  measure
  //
  len_w = strlen(u2_Local) + 4;
  {
    u2_noun wiz = hac;

    while ( u2_nul != wiz ) {
      len_w += (1 + u2_cr_met(3, u2h(wiz)));
      wiz = u2t(wiz);
    }
  }

  //  cut
  //
  pas_c = malloc(len_w + 1);
  strcpy(pas_c, u2_Local);
  strcat(pas_c, "/cay");
  {
    u2_noun wiz   = hac;
    c3_c*   waq_c = (pas_c + strlen(pas_c));

    while ( u2_nul != wiz ) {
      c3_w tis_w = u2_cr_met(3, u2h(wiz));

      if ( (u2_no == dir) && (u2_nul == u2t(wiz)) ) {
        *waq_c++ = '.';
      } else *waq_c++ = '/';

      u2_cr_bytes(0, tis_w, (c3_y*)waq_c, u2h(wiz));
      waq_c += tis_w;

      wiz = u2t(wiz);
    }
    *waq_c = 0;
  }
  u2z(hac);
  return pas_c;
}

/* _sync_norm_e(): construct editing path as noun.
*/
static u2_noun
_sync_norm_e(u2_noun pos, u2_noun bok, u2_noun ram)
{
  return u2nq(pos, bok, 'e', u2_ckb_flop(ram));
}

/* _sync_unix_data(): editing data from path.
*/
static u2_noun
_sync_unix_data(u2_noun pos, u2_noun bok, u2_noun ram)
{
  u2_noun hac   = _sync_norm_e(pos, bok, ram);
  c3_c*   pax_c = _sync_unix(u2_no, hac);
  u2_noun dat   = u2_walk_load(pax_c);

  free(pax_c);
  return dat;
}
#endif

/* _sync_take(): apply ukazy.
*/
static void
_sync_take(u2_reck* rec_u,
           u2_noun  uzy)
{
  // u2_noun pax = u2h(uzy);
  // u2_noun act = u2t(uzy);

  printf("sync_take\n");
  {
  }
  u2z(uzy);
}

/* _sync_edit(): sync in editable directory.
*/
static u2_noun
_sync_edit(u2_reck* rec_u, 
           u2_noun  pos,              //  post
           u2_noun  bok,              //  book
           u2_noun  nod,              //  arch
           u2_noun  det)              //  change list
{
  u2_noun cay = _sync_peek_arch(rec_u, u2k(pos), u2k(bok));
  u2_noun dul;

  if ( u2_nul == cay ) {
    cay = u2nt(u2_no, 0, u2_nul);
  } else {
    u2_noun rac = u2k(u2t(cay));

    u2z(cay); cay = rac;
  }

  dul = u2_cn_mung(u2k(rec_u->toy.duel), u2nc(u2k(cay), u2k(nod)));

  det = u2_ckb_weld(u2k(u2h(dul)), det);
  if ( u2_nul != u2t(dul) ) {
    _sync_take(rec_u, u2k(u2t(dul)));
  }

  u2z(dul);
  return det;
}

#if 0
/* _sync_edit_m():
*/
static u2_noun
_sync_edit_m(u2_reck* rec_u, u2_noun pos, u2_noun bok, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(pos); u2z(bok);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    if ( ('e' == pn_map) ) {
      det = _sync_edit_m(rec_u, u2k(pos), u2k(bok), u2k(l_map), det);
      det = _sync_edit_m(rec_u, u2k(pos), u2k(bok), u2k(r_map), det);
      det = _sync_edit(rec_u, u2k(pos), u2k(bok), u2k(qn_map), u2_nul);
    }
    u2z(map); u2z(pos); u2z(bok);

    return det;
  }
}

/* _sync_book(): sync `nod` as a project change to `pos`, `bok`.
*/
static u2_noun
_sync_book(u2_reck* rec_u, u2_noun pos, u2_noun bok, u2_noun nod)
{
  if ( u2_yes == u2h(nod) ) {
    u2z(nod); u2z(bok); u2z(pos);
    return u2_nul;
  }
  else {
    u2_noun det = _sync_edit_m(rec_u, pos, bok, u2k(u2t(u2t(nod))), u2_nul);
    u2z(nod);

    return det;
  }
}
#endif

/* _sync_book_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_book_m(u2_reck* rec_u, u2_noun own, u2_noun pos, u2_noun map, u2_noun ova)
{
  if ( u2_nul == map ) {
    u2z(own);
    u2z(pos);
    return ova;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;
    u2_noun bok, det;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);
    bok = pn_map;

    ova = _sync_book_m(rec_u, u2k(own), u2k(pos), u2k(l_map), ova);
    ova = _sync_book_m(rec_u, u2k(own), u2k(pos), u2k(r_map), ova);
    det = _sync_edit(rec_u, pos, u2k(bok), u2k(qn_map), u2_nul);

    if ( u2_nul != det ) {
      ova = u2nc(u2nc(u2nq(c3__gold, c3__sync, u2k(rec_u->sen), u2_nul),
                      u2nq(c3__edit, own, u2k(bok), det)),
                 ova);
    } else {
      u2z(own);
    }
    u2z(map);
    return ova;
  }
}

/* _sync_post(): sync `nod` as a base change.
*/
static u2_noun
_sync_post(u2_reck* rec_u, u2_noun own, u2_noun pos, u2_noun nod, u2_noun ova)
{
  if ( (u2_nul == nod) || 
       (u2_yes == u2h(nod)) ||
       (u2_no == _sync_peek_home(rec_u, u2k(pos))) ) 
  {
    u2z(own);
    u2z(pos);
    u2z(nod);
    return ova;
  }
  else {
    ova = _sync_book_m(rec_u, own, pos, u2k(u2t(u2t(nod))), ova);
    u2z(nod);
    return ova;
  }
}

/* _sync_post_m(): sync `map` to a change list `ova`.
*/
static u2_noun
_sync_post_m(u2_reck* rec_u, u2_noun map, u2_noun ova)
{
  if ( u2_nul == map ) {
    return ova;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;
    u2_noun pos, own;

    u2_cx_trel(map, &n_map, &l_map, &r_map);
    u2_cx_cell(n_map, &pn_map, &qn_map);
    pos = pn_map;

    {
      u2_noun say = u2_cn_mung(u2k(rec_u->toy.slay), u2k(pos));

      if ( (u2_no == u2du(say)) || 
           (u2_nul != u2h(say)) || 
           (u2_nul != u2h(u2_t(say))) || 
           ('p' != u2h(u2t(u2t(say)))) ) 
      {
        u2_err(u2_Wire, "bad say", say);
        u2z(say);
        return ova;
      } 
      else {
        own = u2k(u2t(u2t(u2t(say))));
        u2z(say);
      }
    }
    ova = _sync_post(rec_u, own, u2k(pos), u2k(qn_map), ova);
    ova = _sync_post_m(rec_u, u2k(l_map), ova);
    ova = _sync_post_m(rec_u, u2k(r_map), ova);

    u2z(map);
    return ova;
  }
}

/* u2_sync_reck(): traverse filesystem for changes -> (list ovum)
*/
u2_noun
u2_sync_reck(u2_reck* rec_u)
{
  c3_c*   pas_c = malloc(strlen(u2_Local) + 1 + 3 + 1);
  u2_noun nod; 

  strcpy(pas_c, u2_Local);
  strcat(pas_c, "/car");
 
  nod = u2_walk(rec_u, pas_c, 0);
  free(pas_c);

  if ( (u2_nul == nod) || (u2_yes == u2h(nod)) ) {
    u2z(nod);
    return u2_nul;
  }
  else {
    u2_noun ova = u2_nul;
    u2_noun map = u2t(u2t(nod));

    ova = _sync_post_m(rec_u, u2k(map), ova);
    u2z(nod);

    return ova;
  }
}
