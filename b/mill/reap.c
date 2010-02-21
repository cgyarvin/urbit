/* mill/reap.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_reap(): expand type.
*/
u4_type
_mill_reap(u4_milr m,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_atom, tip) ||
       u4_n_eq(u4_atom_blot, tip) ||
       u4_n_eq(u4_atom_blur, tip) )
  {
    return tip;
  }

  else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
    return tip;
  }

  else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
    return u4_k_trel(lane, u4_atom_cell, p_tip, u4_atom_blur);
  }

  else if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
    u4_noun ip_tip  = u4_ch(p_tip);
    u4_type qip_tip = u4_ct(ip_tip);
    u4_rail tp_tip  = u4_ct(p_tip);

    if ( u4_n_zero(tp_tip) ) {
      return qip_tip;
    }
    else {
      return u4_k_qual(lane, u4_atom_cell, qip_tip, u4_atom_crib, tp_tip);
    }
  }

  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) && !u4_n_atom(p_tip) ) {
    u4_type foo = u4_k_cell(lane, u4_atom_cube, u4_ch(p_tip));
    u4_type bar = u4_k_cell(lane, u4_atom_cube, u4_ct(p_tip));

    return u4_k_trel(lane, u4_atom_cell, foo, bar);
  }

  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return tip;
  }

  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return tip;
  }

  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    return _mill_repo(m, p_tip, q_tip);
  }

  else {
    u4_err(lane, "strange reap", tip);
    return u4_trip;
  }
}
