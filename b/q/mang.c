/* mill/q/mang.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_mang():
*/
u4_noun
_mill_q_mang(u4_milr m, 
             u4_gene buz,
             u4_gene lep)
{
  u4_lane lane = m->lane;

  //  :.
  //    %trop 
  //    buz
  //    :.
  //      %kick
  //      [[%frag 2] %% ~]
  //      :.  :.  [[%frag 4] ~]
  //              [%link [%frag 3] lep]]
  //          ==
  //          ~
  //      ==
  //    ==
  //  ==

  return u4_k_trel
    (lane, 
     u4_atom_trop,
     buz,
     u4_k_trel
      (lane,
       u4_atom_kick,
       u4_k_trel
        (lane, 
         u4_k_cell(lane, u4_atom_frag, u4_noun_2),
         u4_noun_0, 
         u4_noun_0),
       u4_k_cell
        (lane,
         u4_k_cell
          (lane,
           u4_k_cell
            (lane, u4_k_cell(lane, u4_atom_frag, u4_noun_4), u4_noun_0),
           u4_k_trel
            (lane, 
             u4_atom_link, 
             u4_k_cell(lane, u4_atom_frag, u4_noun_3), 
             lep)),
         u4_noun_0)));
}
