/* mill/q/lome.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_lome():
*/
u4_noun
_mill_q_lome(u4_milr m, 
             u4_gene cug)
{
  u4_lane lane = m->lane;

  //  [%load [%% cug]]

  return u4_k_trel(lane, u4_atom_load, u4_noun_0, cug);
}
