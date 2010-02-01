/* mill/q/peld.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_peld():
*/
u4_noun
_mill_q_peld(u4_milr m, 
             u4_noun das)
{
  u4_lane lane = m->lane;

  //  ?-  das
  //    -   ~       [%pret %1]
  //    -   [i t]   [%stol i.das [%pret %0] $(das t.das)]
  //  ==
  
  if ( u4_n_zero(das) ) {
    return u4_k_cell(lane, u4_atom_pret, u4_noun_1);
  }
  else {
    return u4_k_qual
      (lane,
       u4_atom_stol,
       u4_ch(das),
       u4_k_cell(lane, u4_atom_pret, u4_noun_0),
       _mill_q_peld(m, u4_ct(das)));
  }
}
