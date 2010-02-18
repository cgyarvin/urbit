/* mill/q/quat.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_quat():
*/
u4_noun
_mill_q_quat(u4_milr m, 
             u4_gene tes,
             u4_gene bif)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_quol,
           tes,
           bif,
           u4_k_cell(lane, u4_atom_plac, u4_noun_0));
}
