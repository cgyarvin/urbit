/* mill/x/lift.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _lift_book(): bake a book.
*/
static u4_noun
_lift_book(u4_milr m, u4_noun pir, u4_mold tip)
{
  u4_lane lane = m->lane;

  if ( u4_n_cell(u4_ch(pir)) ) {
    return u4_k_cell(lane, _lift_book(m, u4_ch(pir), tip),
                           _lift_book(m, u4_ct(pir), tip));
  }
  else {
    return _mill_bake(m, u4_ct(pir), tip);
  }
}

/* _mill_p_lift()::
*/
u4_mold
_mill_p_lift(u4_milr m, 
             u4_noun pir,
             u4_mold tip)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_dome, tip, pir);
}

/* _mill_b_lift()::
*/
u4_nock
_mill_b_lift(u4_milr m, 
             u4_noun pir,
             u4_mold tip)
{
  u4_lane lane = m->lane;
  u4_mold heg  = u4_k_trel(lane, u4_atom_cone, tip, pir);
  u4_noun fez  = _lift_book(m, pir, heg);

  return u4_k_cell
          (lane, u4_k_cell(lane, u4_noun_0, u4_noun_1),
                 u4_k_cell(lane, u4_noun_1, fez));
}

/* _mill_m_lift()::
*/
u4_loaf
_mill_m_lift(u4_milr m, 
             u4_noun pir,
             u4_mold tip)
{
  u4_lane lane = m->lane;
  u4_mold gan  = u4_k_trel(lane, u4_atom_dome, tip, pir);
  u4_mold heg  = u4_k_trel(lane, u4_atom_cone, tip, pir);
  u4_noun fez  = _lift_book(m, pir, heg);

  return u4_k_cell
    (lane, gan,
           u4_k_cell
            (lane, u4_k_cell(lane, u4_noun_0, u4_noun_1),
                   u4_k_cell(lane, u4_noun_1, fez)));
}

