/* mill/q/flec.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_flec():
*/
u4_noun
_mill_q_flec(u4_milr m, 
             u4_gene buz)
{
  u4_lane lane = m->lane;

  //  :*
  //    %slon
  //    buz
  //    [%lect %%]
  //  ==
  
  return u4_k_trel
    (lane, u4_atom_slon, 
           buz,
           u4_k_cell(lane, u4_atom_lect, u4_noun_0));
}
