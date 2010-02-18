/* mill/make.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

#define _make_p(stem) \
  if ( u4_b_p(gen, u4_atom_##stem, &p_gen) ) { \
    u4_wire _mill_x_##stem(u4_milr, u4_noun, u4_type); \
    return _mill_x_##stem(m, p_gen, tip); \
  }

#define _make_pq(stem) \
  if ( u4_b_pq(gen, u4_atom_##stem, &p_gen, &q_gen) ) { \
    u4_wire _mill_x_##stem(u4_milr, u4_noun, u4_noun, u4_type); \
    return _mill_x_##stem(m, p_gen, q_gen, tip); \
  }

#define _make_pqr(stem) \
  if ( u4_b_pqr(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen) ) {\
    u4_wire _mill_x_##stem(u4_milr, u4_noun, u4_noun, u4_noun, u4_type); \
    return _mill_x_##stem(m, p_gen, q_gen, r_gen, tip); \
  }

/* _mill_make_main(): internal of _mill_make().
*/
u4_wire
_mill_make_main(u4_milr m,
                u4_gene gen,
                u4_type tip)
{
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_fork(gen, &p_gen, &q_gen) ) {
    return _mill_make_main
      (m, u4_k_qual(m->lane, u4_atom_slux, p_gen, q_gen, u4_noun_0), tip);
  }
  else {
    _make_pq (grat);    // ~>
    _make_pq (slop);    // :=
    _make_pq (glid);    // ^+
    _make_pq (glem);    // ^-
    _make_p  (plov);
    _make_p  (drop);
    _make_p  (stig);
    _make_pqr(glop);    // ^=
    _make_p  (plac);    // !!
    _make_pq (brov);
    _make_pq (brax);    // &&
    _make_pqr(quol);    // ?:
    _make_p  (slon);    // :*
    _make_pq (plaz);
    _make_pq (plol);
    _make_pq (quop);    // ?= 

    {
      u4_noun rex = _mill_open(m, gen);

      if ( u4_n_eq(rex, gen) ) {
        u4_err(m->lane, "rex", rex);
        return u4_trip;
      }
      else {
        return _mill_make(m, rex, tip);
      }
    }
  }
}

/* _mill_make(): type inference, top level.
*/
u4_wire
_mill_make(u4_milr m,
           u4_gene gen,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun fid  = u4_k_cell(lane, gen, tip);
  u4_nopt raz  = u4_tab_get(fid, m->niq);

  if ( raz ) {
    return raz;
  }
  else {
    /* Memoize.
    */
    raz = _mill_make_main(m, gen, tip);

    m->niq = u4_tab_add(lane, fid, raz, m->niq);
    return raz;
  }
}
