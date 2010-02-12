/* mill/q/prex.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_prex():
*/
u4_noun
_mill_q_prex(u4_milr m, 
             u4_gene tes,
             u4_gene hob)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_stol, tes, u4_k_cell(lane, u4_atom_tram, u4_noun_0), hob);
}
