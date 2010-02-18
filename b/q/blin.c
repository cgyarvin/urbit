/* mill/q/ston.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_ston():
*/
u4_noun
_mill_q_ston(u4_milr m, 
             u4_gene bov,
             u4_noun pir)
{
  u4_lane lane = m->lane;

  //  :*
  //    %grat
  //    [%stid pir]
  //    bov
  //  ==
  
  return u4_k_trel
    (lane,
     u4_atom_grat,
     u4_k_cell(lane, u4_atom_stid, pir),
     bov);
}
