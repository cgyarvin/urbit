/* mill/q/slet.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_slet():
*/
u4_noun
_mill_q_slet(u4_milr m, 
             u4_atom haz)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, u4_atom_slop,
           u4_k_cell(lane, u4_k_cell(lane, u4_atom_slet, haz), u4_noun_0),
           u4_noun_0);
}
