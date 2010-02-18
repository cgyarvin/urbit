/* mill/q/glon.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_glon():
*/
u4_noun
_mill_q_glon(u4_milr m, 
             u4_gene rum)
{
  u4_lane lane = m->lane;

  // [%glid [%brov 3 %drop 0] rum]
  
  return u4_k_trel
    (lane, u4_atom_glid,
           u4_k_qual(lane, u4_atom_brov, u4_noun_3, u4_atom_drop, u4_noun_0),
           rum);
}
