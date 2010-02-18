/* mill/q/slid.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_slid():
*/
u4_noun
_mill_q_slid(u4_milr m, 
             u4_gene buz,
             u4_noun pum)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(pum) ) {
    return u4_k_cell(lane, u4_atom_slem, buz);
  } else {
    return u4_k_qual(lane, u4_atom_sloc, buz, u4_atom_slux, pum);
  }
}
