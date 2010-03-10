/* mill/mold.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

  /** Types:
  **/
  /** Forward declarations.
  **/
    static u4_noun
    _mold_book(u4_milr, u4_lump);

    static u4_noun
    _mold_mark(u4_milr, u4_lump);


/* _mill_mold(): normalize mold.
*/
u4_mold
_mill_mold(u4_milr m,
           u4_lump muf)
{
  u4_lane lane = m->lane;
  u4_noun p_muf, q_muf, r_muf;

  // %atom
  // %blot
  // %blur
  //
  if ( u4_n_eq(u4_atom_atom, muf) ||
       u4_n_eq(u4_atom_blot, muf) ||
       u4_n_eq(u4_atom_blur, muf) )
  {
    return muf;
  }

  // [%cell p=mold q=mold]
  //
  else if ( u4_b_pq(muf, u4_atom_cell, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_cell, _mill_mold(m, p_muf), _mill_mold(m, q_muf));
  }

  // [%cone p=mold q=bush+[mark gene]]
  //
  else if ( u4_b_pq(muf, u4_atom_cone, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_cone, _mill_mold(m, p_muf), _mold_book(m, q_muf));
  }

  // [%cube p=clod]
  // 
  else if ( u4_b_p(muf, u4_atom_cube, &p_muf) ) {
    return muf;
  }

  // [%face p=mark q=mold]
  //
  else if ( u4_b_pq(muf, u4_atom_face, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_face, _mold_mark(m, p_muf), _mill_mold(m, q_muf));
  }

  // [%fork p=mold q=mold]
  //
  else if ( u4_b_pq(muf, u4_atom_fork, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_fork, _mill_mold(m, p_muf), _mill_mold(m, q_muf));
  }

  // [%fuse p=mold q=mold]
  //
  else if ( u4_b_pq(muf, u4_atom_fuse, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_fuse, _mill_mold(m, p_muf), _mill_mold(m, q_muf));
  }

  // [%hold p=(mold) q=(gene)]
  //
  else if ( u4_b_pq(muf, u4_atom_hold, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_hold, _mill_mold(m, p_muf), _mill_gene(m, q_muf));
  }

  else {
    return _mill_fail(m, "mold: flot");
  }
}

/* _mold_book(): normalize book.
*/
static u4_noun
_mold_book(u4_milr m,
           u4_lump beq)
{
  if ( u4_n_cell(u4_ch(beq)) ) {
    return u4_k_cell
      (m->lane, _mold_book(m, u4_ch(beq)), _mold_book(m, u4_ct(beq)));
  }
  else {
    return u4_k_cell(m->lane, u4_ch(beq), _mill_gene(m, u4_ct(beq)));
  }
}

/* _mold_mark(): normalize mark.
*/
static u4_noun
_mold_mark(u4_milr m,
           u4_lump vof)
{
  if ( !u4_n_atom(vof) ) {
    return _mill_fail(m, "mold: invalid mark");
  }
  else return vof;
}
