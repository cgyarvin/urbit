/* mill/q/slem.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_slem():
*/
u4_noun
_mill_q_slem(u4_milr m, 
             u4_gene buz)
{
  u4_lane lane = m->lane;

  //  :*
  //    %grat
  //    buz
  //    [%slat 0 %%]
  //  ==
  
  return u4_k_trel
    (lane, u4_atom_grat, 
           buz,
           u4_k_trel(lane, u4_atom_slat, u4_noun_0, u4_noun_0));
}
