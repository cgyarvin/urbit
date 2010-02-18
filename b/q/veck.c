/* mill/q/bron.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_bron():
*/
u4_noun
_mill_q_bron(u4_milr m, 
             u4_gene dil)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_brov, u4_noun_3, dil);
}
