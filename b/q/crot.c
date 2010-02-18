/* mill/q/glaz.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_glaz():
*/
u4_noun
_mill_q_glaz(u4_milr m, 
             u4_gene rum)
{
  u4_lane lane = m->lane;

  //  :*
  //    %glid
  //    [%brov 5 %drop 0]
  //    rum
  //  ==
  
  return u4_k_trel
    (lane, u4_atom_glid,
           u4_k_qual(lane, u4_atom_brov, u4_noun_5, u4_atom_drop, u4_noun_0),
           rum);
}
