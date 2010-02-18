/* mill/q/plat.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_plat():
*/
u4_noun
_mill_q_plat(u4_milr m, 
             u4_gene hig,
             u4_gene muc)
{
  u4_lane lane = m->lane;

  //  :.
  //    %grat
  //    [%slux hig [%slet 1] ~]
  //    muc
  //  ==

  return u4_k_trel
    (lane, u4_atom_grat,
           u4_k_qual
            (lane, u4_atom_slux, 
                   hig,
                   u4_k_cell(lane, u4_atom_slet, u4_noun_1),
                   u4_noun_0),
           muc);
}
