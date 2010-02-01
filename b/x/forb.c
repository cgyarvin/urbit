/* mill/x/forb.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_forb()::
*/
u4_loaf
_mill_x_forb(u4_milr m, 
             u4_rope rid,
             u4_gene bul, 
             u4_type tip)
{
  u4_lane lane = m->lane;
  u4_loaf fod  = _mill_look(m, rid, tip);
  u4_type gan  = _mill_play(m, bul, tip);
  u4_axis axe;

  if ( !u4_b_p(u4_ct(fod), u4_noun_0, &axe) ) {
    return _mill_fail(m, "make: fat like");
  }
  else {
    // u4_form zur = _mill_diff(m, axe, u4_ch(fod), gan);
    u4_form zur = _mill_fish(m, axe, gan);

    return u4_k_cell
      (lane, zur,  
             u4_k_trel
              (lane, 
               u4_atom_fork, 
               u4_k_cell(lane, u4_atom_cube, u4_noun_0),
               u4_k_cell(lane, u4_atom_cube, u4_noun_1)));
  }
}
