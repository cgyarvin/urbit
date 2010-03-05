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
  
  if ( u4_n_zero(pir) ) {
    pir = u4_k_cell
      (lane, u4_k_trel(lane, u4_noun_0, u4_atom_bail, u4_noun_0),
             u4_noun_0);
  } 
  // XX: actually balance tree.
  //
  return u4_k_cell(lane, u4_atom_load, u4_log_tupl(lane, pir));
}
