/* mill/q/malk.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_malk():
*/
u4_noun
_mill_q_malk(u4_milr m, 
             u4_noun pir)
{
  u4_lane lane = m->lane;
  
  // XX: actually balance tree.
  //
  return u4_k_cell(lane, u4_atom_clep, u4_log_tupl(lane, pir));
}
