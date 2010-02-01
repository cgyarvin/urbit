/* mill/q/zarb.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_zarb():
*/
u4_noun
_mill_q_zarb(u4_milr m, 
             u4_atom haz)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, u4_atom_gant,
           u4_k_cell(lane, u4_k_cell(lane, u4_atom_zarb, haz), u4_noun_0),
           u4_noun_0);
}
