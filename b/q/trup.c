/* mill/q/trup.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_trup():
*/
u4_noun
_mill_q_trup(u4_milr m, 
             u4_gene gix)
{
  u4_lane lane = m->lane;

  //  :*
  //    %stol
  //    gix
  //    [%pret 1]
  //    [%pret 0]
  //  ==

  return u4_k_qual
    (lane, u4_atom_stol, 
           gix,
           u4_k_cell(lane, u4_atom_pret, u4_noun_1),
           u4_k_cell(lane, u4_atom_pret, u4_noun_0));
}
