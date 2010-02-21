/* mill/q/slex.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_slex():
*/
u4_noun
_mill_q_slex(u4_milr m, 
             u4_noun vec,
             u4_noun sud)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane,
     u4_atom_grat,
     u4_k_cell
      (lane, u4_atom_slop,
             u4_k_cell(lane, u4_k_cell(lane, u4_atom_slet, u4_noun_0),
                             u4_noun_0)),
     sud);
}
