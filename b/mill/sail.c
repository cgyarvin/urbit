/* mill/sail.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_sail(): patch type.
*/
u4_type
_mill_sail(u4_milr m,
           u4_axis axe,
           u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  u4_assert(u4_n_atom(axe));
  u4_assert(!u4_n_zero(axe));

  if ( u4_n_eq(u4_noun_1, axe) ) {
    return typ;
  }
  else if ( u4_b_pq(typ, u4_atom_wing, &p_typ, &q_typ) ) {
    return u4_k_trel
      (lane, u4_atom_wing, u4_op_peg(lane, axe, p_typ), q_typ);
  }
  else if ( _mill_nest(m, u4_atom_blur, typ) ) {
    // No blurry wings.
    //
    return u4_atom_blur;
  }
  else {
    return u4_k_trel(lane, u4_atom_wing, axe, typ);
  }
}
