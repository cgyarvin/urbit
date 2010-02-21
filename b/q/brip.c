/* mill/q/slip.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_slip():
*/
u4_noun
_mill_q_slip(u4_milr m, 
             u4_skel mef)
{
  u4_gene gen = _mill_fiat(m, mef);

  return gen;
}
