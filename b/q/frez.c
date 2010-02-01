/* mill/q/frez.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_frez():
*/
u4_noun
_mill_q_frez(u4_milr m, 
             u4_gene dil)
{
  u4_lane lane = m->lane;

  //  [%gult 7 dil]

  return u4_k_trel(lane, u4_atom_gult, u4_noun_7, dil);
}
