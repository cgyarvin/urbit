/* mill/q/glax.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_glax():
*/
u4_noun
_mill_q_glax(u4_milr m, 
             u4_gene feg,
             u4_noun bem)
{
  u4_lane lane = m->lane;

  //  :*
  //    %pont
  //    feg
  //    :*
  //      %zact
  //      [%zarb 2]
  //      bem
  //    ==
  //  ==
  //
  return u4_k_trel
   (lane, 
    u4_atom_pont,
    feg,
    u4_k_trel
     (lane,
      u4_atom_zact,
      u4_k_cell(lane, u4_atom_zarb, u4_noun_2),
      bem));
}
