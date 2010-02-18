/* mill/q/sloc.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_sloc():
*/
u4_noun
_mill_q_sloc(u4_milr m, 
             u4_gene buz,
             u4_gene lep)
{
  u4_lane lane = m->lane;

  //  :.
  //    %plat 
  //    buz
  //    :.
  //      %slop
  //      [[%slet 2] %% ~]
  //      :.  :.  [[%slet 4] ~]
  //              [%grat [%slet 3] lep]]
  //          ==
  //          ~
  //      ==
  //    ==
  //  ==

  return u4_k_trel
    (lane, 
     u4_atom_plat,
     buz,
     u4_k_trel
      (lane,
       u4_atom_slop,
       u4_k_trel
        (lane, 
         u4_k_cell(lane, u4_atom_slet, u4_noun_2),
         u4_noun_0, 
         u4_noun_0),
       u4_k_cell
        (lane,
         u4_k_cell
          (lane,
           u4_k_cell
            (lane, u4_k_cell(lane, u4_atom_slet, u4_noun_4), u4_noun_0),
           u4_k_trel
            (lane, 
             u4_atom_grat, 
             u4_k_cell(lane, u4_atom_slet, u4_noun_3), 
             lep)),
         u4_noun_0)));
}
