/* mill/x/drop.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_drop()::
*/
u4_loaf
_mill_x_drop(u4_milr m, 
             u4_noun daq,
             u4_type tip)
{
  u4_lane lane = m->lane;

  return u4_k_cell
    (lane, u4_k_cell(lane, u4_atom_cube, daq),
           u4_k_cell(lane, u4_noun_1, daq));
}
