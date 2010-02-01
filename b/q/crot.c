/* mill/q/crot.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_crot():
*/
u4_noun
_mill_q_crot(u4_milr m, 
             u4_gene rum)
{
  u4_lane lane = m->lane;

  //  :*
  //    %perd
  //    [%gult 5 %pret 0]
  //    rum
  //  ==
  
  return u4_k_trel
    (lane, u4_atom_perd,
           u4_k_qual(lane, u4_atom_gult, u4_noun_5, u4_atom_pret, u4_noun_0),
           rum);
}
