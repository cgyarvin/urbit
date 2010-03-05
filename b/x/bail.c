/* mill/x/bail.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_bail()::
*/
u4_loaf
_mill_x_bail(u4_milr m, 
             u4_noun guk)
{
  u4_lane lane  = m->lane;

  u4_assert(u4_noun_0 == guk);

  return u4_k_cell
      (lane, u4_atom_blot,
             u4_k_cell(lane, u4_noun_0, u4_noun_0));
}
