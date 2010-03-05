/* mill/type.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

  /** Types:
  **/
  /** Forward declarations.
  **/
    static u4_noun
    _type_clip(u4_milr, u4_lump);

    static u4_noun
    _type_mark(u4_milr, u4_lump);


/* _mill_type(): normalize type.
*/
u4_type
_mill_type(u4_milr m,
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

  // [%cell p=type q=type]
  //
  else if ( u4_b_pq(muf, u4_atom_cell, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_cell, _mill_type(m, p_muf), _mill_type(m, q_muf));
  }

  // [%cone p=type q=bush+[mark gene]]
  //
  else if ( u4_b_pq(muf, u4_atom_cone, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_cone, _mill_type(m, p_muf), _type_clip(m, q_muf));
  }

  // [%cube p=clod]
  // 
  else if ( u4_b_p(muf, u4_atom_cube, &p_muf) ) {
    return muf;
  }

  // [%face p=mark q=type]
  //
  else if ( u4_b_pq(muf, u4_atom_face, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_face, _type_mark(m, p_muf), _mill_type(m, q_muf));
  }

  // [%fork p=type q=type]
  //
  else if ( u4_b_pq(muf, u4_atom_fork, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_fork, _mill_type(m, p_muf), _mill_type(m, q_muf));
  }

  // [%fuse p=type q=type]
  //
  else if ( u4_b_pq(muf, u4_atom_fuse, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_fuse, _mill_type(m, p_muf), _mill_type(m, q_muf));
  }

  // [%hold p=(type) q=(gene)]
  //
  else if ( u4_b_pq(muf, u4_atom_hold, &p_muf, &q_muf) ) {
    return u4_k_trel
      (lane, u4_atom_hold, _mill_type(m, p_muf), _mill_gene(m, q_muf));
  }

  else {
    return _mill_fail(m, "type: flot");
  }
}

/* _type_clip(): normalize clip.
*/
static u4_noun
_type_clip(u4_milr m,
           u4_lump beq)
{
  if ( u4_n_cell(u4_ch(beq)) ) {
    return u4_k_cell
      (m->lane, _type_clip(m, u4_ch(beq)), _type_clip(m, u4_ct(beq)));
  }
  else {
    return u4_k_cell(m->lane, u4_ch(beq), _mill_gene(m, u4_ct(beq)));
  }
}

/* _type_mark(): normalize mark.
*/
static u4_noun
_type_mark(u4_milr m,
           u4_lump vof)
{
  if ( !u4_n_atom(vof) ) {
    return _mill_fail(m, "type: invalid mark");
  }
  else return vof;
}
