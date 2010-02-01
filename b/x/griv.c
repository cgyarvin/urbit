/* mill/x/griv.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_griv()::
*/
u4_loaf
_mill_x_griv(u4_milr m, 
             u4_gene dil, 
             u4_noun zep,
             u4_type tip)
{
  u4_lane lane  = m->lane;
  u4_loaf fod   = _mill_make(m, dil, tip);
  u4_form q_fod = u4_ct(fod);

  return u4_k_cell
    (lane, u4_atom_blur, _mill_comp(m, q_fod, zep)); 
}
