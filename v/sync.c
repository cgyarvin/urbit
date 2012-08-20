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

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

/* _sync_peek_arch(): (unit meta) for cary-path.
*/
static u2_noun
_sync_peek_arch(u2_reck* rec_u, u2_noun pos, u2_noun bok)
{
  return u2_reck_peek
    (rec_u, u2nq(c3__cary, pos, bok, u2nt(u2k(rec_u->wen), 'a', u2_nul)));
}

#if 0
/* _sync_unix(): unix path as by dir/file.ext or dir/subdir protocol.
*/
static c3_c*
_sync_unix(u2_flag dir, u2_noun hac)
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
  strcat(pas_c, "/car");
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
  printf("UZY!\n");
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
  u2_noun car = _sync_peek_arch(rec_u, u2k(pos), u2k(bok));
  u2_noun dul;

  if ( u2_nul == car ) {
    car = u2nt(u2_no, 0, u2_nul);
  } else {
    u2_noun rac = u2k(u2t(car));

    u2z(car); car = rac;
  }

  dul = u2_cn_mung(u2k(rec_u->toy.duel), u2nc(u2k(car), u2k(nod)));

  if ( u2_nul != u2h(dul) ) {
    det = u2nc
          (u2nc(c3__cary, 
                u2nt(c3_s2('p','i'),
                     u2nt(pos, bok, u2_nul),
                     u2nc(c3_s2('d','o'), u2k(u2h(dul))))),
           det);
  }
  if ( u2_nul != u2t(dul) ) {
    _sync_take(rec_u, u2k(u2t(dul)));
  }

  u2z(dul);
  return det;
}

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
_sync_book(u2_reck* rec_u, u2_noun pos, u2_noun bok, u2_noun nod, u2_noun det)
{
  if ( u2_yes == u2h(nod) ) {
    //  XX  user error
    u2z(nod); u2z(bok); u2z(pos);
    return det;
  }
  else {
    det = _sync_edit_m(rec_u, pos, bok, u2k(u2t(u2t(nod))), det);
    u2z(nod);

    return det;
  }
}

/* _sync_book_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_book_m(u2_reck* rec_u, u2_noun pos, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(pos);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    det = _sync_book_m(rec_u, u2k(pos), u2k(l_map), det);
    det = _sync_book_m(rec_u, u2k(pos), u2k(r_map), det);
    det = _sync_book(rec_u, pos, u2k(pn_map), u2k(qn_map), det);

    u2z(map);
    return det;
  }
}

/* _sync_post(): sync `nod` as a base change.
*/
static u2_noun
_sync_post(u2_reck* rec_u, u2_noun pos, u2_noun nod, u2_noun det)
{
  if ( (u2_nul == nod) || (u2_yes == u2h(nod)) ) {
    u2z(pos);
    u2z(nod);
    return det;
  }
  else {
    det = _sync_book_m(rec_u, pos, u2k(u2t(u2t(nod))), det);
    u2z(nod);
    return det;
  }
}

/* _sync_post_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_post_m(u2_reck* rec_u, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cx_trel(map, &n_map, &l_map, &r_map);
    u2_cx_cell(n_map, &pn_map, &qn_map);

    det = _sync_post(rec_u, u2k(pn_map), u2k(qn_map), det);
    det = _sync_post_m(rec_u, u2k(l_map), det);
    det = _sync_post_m(rec_u, u2k(r_map), det);

    u2z(map);
    return det;
  }
}

/* u2_sync_reck(): traverse filesystem for changes -> lamb
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
    u2_noun det = u2_nul;
    u2_noun map = u2t(u2t(nod));

    det = _sync_post_m(rec_u, u2k(map), det);
    u2z(nod);

    return u2nc('o', det);
  }
}
