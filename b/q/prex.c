/* mill/q/quet.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_quet():
*/
u4_noun
_mill_q_quet(u4_milr m, 
             u4_gene tes,
             u4_gene hob)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_quol, tes, u4_k_cell(lane, u4_atom_plac, u4_noun_0), hob);
}
