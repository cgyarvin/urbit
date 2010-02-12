/* mill/q/pung.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_pung():
*/
u4_noun
_mill_q_pung(u4_milr m, 
             u4_gene buz,
             u4_gene lep)
{
  u4_lane lane = m->lane;

  //  :.
  //    %glem 
  //    buz
  //    :.
  //      %gant
  //      [[%zarb 2] %% ~]
  //      :.  :.  [[%zarb 4] ~]
  //              [%slon [%zarb 3] lep]]
  //          ==
  //          ~
  //      ==
  //    ==
  //  ==

  return u4_k_trel
    (lane, 
     u4_atom_glem,
     buz,
     u4_k_trel
      (lane,
       u4_atom_gant,
       u4_k_trel
        (lane, 
         u4_k_cell(lane, u4_atom_zarb, u4_noun_2),
         u4_noun_0, 
         u4_noun_0),
       u4_k_cell
        (lane,
         u4_k_cell
          (lane,
           u4_k_cell
            (lane, u4_k_cell(lane, u4_atom_zarb, u4_noun_4), u4_noun_0),
           u4_k_trel
            (lane, 
             u4_atom_slon, 
             u4_k_cell(lane, u4_atom_zarb, u4_noun_3), 
             lep)),
         u4_noun_0)));
}
