/* mill/q/blin.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_blin():
*/
u4_noun
_mill_q_blin(u4_milr m, 
             u4_gene bov,
             u4_noun pir)
{
  u4_lane lane = m->lane;

  //  :*
  //    %slon
  //    [%malk pir]
  //    bov
  //  ==
  
  return u4_k_trel
    (lane,
     u4_atom_slon,
     u4_k_cell(lane, u4_atom_malk, pir),
     bov);
}
