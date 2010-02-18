/* mill/q/quax.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_quax():
*/
u4_noun
_mill_q_quax(u4_milr m, 
             u4_noun das)
{
  u4_lane lane = m->lane;

  //  ?-  das
  //    -   ~       [%drop %0]
  //    -   [i t]   [%quol i.das $(das t.das) [%drop %1]]
  //  ==

  if ( u4_n_zero(das) ) {
    return u4_k_cell(lane, u4_atom_drop, u4_noun_0);
  }
  else {
    return u4_k_qual
      (lane,
       u4_atom_quol,
       u4_ch(das),
       _mill_q_quax(m, u4_ct(das)),
       u4_k_cell(lane, u4_atom_drop, u4_noun_1));
  }
}
