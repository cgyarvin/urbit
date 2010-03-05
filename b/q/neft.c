/* mill/q/neft.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_neft():
*/
u4_noun
_mill_q_neft(u4_milr m, 
             u4_gene dil)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_nock, u4_noun_5, dil);
}
