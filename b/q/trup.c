/* mill/q/quac.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_quac():
*/
u4_noun
_mill_q_quac(u4_milr m, 
             u4_gene gix)
{
  u4_lane lane = m->lane;

  //  :*
  //    %quol
  //    gix
  //    [%drop 1]
  //    [%drop 0]
  //  ==

  return u4_k_qual
    (lane, u4_atom_quol, 
           gix,
           u4_k_cell(lane, u4_atom_drop, u4_noun_1),
           u4_k_cell(lane, u4_atom_drop, u4_noun_0));
}
