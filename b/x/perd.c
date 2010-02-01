/* mill/x/perd.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_perd()::
*/
u4_loaf
_mill_x_perd(u4_milr m, 
             u4_gene fes,
             u4_gene rum, 
             u4_type tip)
{
  u4_lane lane = m->lane;
  u4_type gan  = _mill_play(m, fes, tip);
  u4_form fal  = _mill_bake(m, rum, tip);

  // XX: safe

  return u4_k_cell(lane, gan, fal);
}
