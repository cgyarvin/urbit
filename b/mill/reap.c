/* mill/reap.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_reap(): expand type.
*/
u4_type
_mill_reap(u4_milr m,
           u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  if ( u4_n_eq(u4_atom_atom, typ) ||
       u4_n_eq(u4_atom_blot, typ) ||
       u4_n_eq(u4_atom_blur, typ) )
  {
    return typ;
  }

  else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
    return typ;
  }

  else if ( u4_b_pq(typ, u4_atom_cone, &p_typ, &q_typ) ) {
    return u4_k_trel(lane, u4_atom_cell, p_typ, u4_atom_blur);
  }

  else if ( u4_b_p(typ, u4_atom_crib, &p_typ) ) {
    u4_noun ip_typ  = u4_ch(p_typ);
    u4_type qip_typ = u4_ct(ip_typ);
    u4_rail tp_typ  = u4_ct(p_typ);

    if ( u4_n_zero(tp_typ) ) {
      return qip_typ;
    }
    else {
      return u4_k_qual(lane, u4_atom_cell, qip_typ, u4_atom_crib, tp_typ);
    }
  }

  else if ( u4_b_p(typ, u4_atom_cube, &p_typ) && !u4_n_atom(p_typ) ) {
    u4_type foo = u4_k_cell(lane, u4_atom_cube, u4_ch(p_typ));
    u4_type bar = u4_k_cell(lane, u4_atom_cube, u4_ct(p_typ));

    return u4_k_trel(lane, u4_atom_cell, foo, bar);
  }

  else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
    return typ;
  }

  else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
    return typ;
  }

  else if ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) ) {
    return _mill_repo(m, p_typ, q_typ);
  }

  else if ( u4_b_pq(typ, u4_atom_wing, &p_typ, &q_typ) ) {
    u4_axis sud = u4_op_tip(p_typ);
    u4_axis zan = u4_op_tap(lane, p_typ);
    u4_type nel = _mill_sail(m, zan, q_typ);

    if ( u4_n_eq(u4_noun_2, sud) ) {
      return u4_k_trel(lane, u4_atom_cell, nel, u4_atom_blur);
    }
    else {
      return u4_k_trel(lane, u4_atom_cell, u4_atom_blur, nel);
    }
  }

  else {
    u4_err(lane, "strange reap", typ);
    return u4_trip;
  }
}
