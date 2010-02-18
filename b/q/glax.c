/* mill/q/quid.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_quid():
*/
u4_noun
_mill_q_quid(u4_milr m, 
             u4_gene feg,
             u4_noun bem)
{
  u4_lane lane = m->lane;

  //  :*
  //    %plat
  //    feg
  //    :*
  //      %quem
  //      [%slet 2]
  //      bem
  //    ==
  //  ==
  //
  return u4_k_trel
   (lane, 
    u4_atom_plat,
    feg,
    u4_k_trel
     (lane,
      u4_atom_quem,
      u4_k_cell(lane, u4_atom_slet, u4_noun_2),
      bem));
}
