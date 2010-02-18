/* mill/q/stid.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_stid():
*/
u4_noun
_mill_q_stid(u4_milr m, 
             u4_noun pir)
{
  u4_lane lane = m->lane;
  
  // XX: actually balance tree.
  //
  return u4_k_cell(lane, u4_atom_stig, u4_log_tupl(lane, pir));
}
