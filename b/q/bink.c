/* mill/q/bink.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_bink():
*/
u4_noun
_mill_q_bink(u4_milr m, 
             u4_bone mef)
{
  u4_gene gen = _mill_gate(m, mef);

  if ( !u4_n_zero(m->rux) ) {
    u4_err(m->lane, "gen", gen);
  }
  return gen;
}
