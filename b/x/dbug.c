/* mill/x/plov.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_plov()::
*/
u4_loaf
_mill_x_plov(u4_milr m, 
             u4_gene lyq,
             u4_type tip)
{
  u4_lane lane = m->lane;
  u4_loaf fod;

  m->rux = u4_op_inc(lane, m->rux);
  fod = _mill_make(m, lyq, tip);
  m->rux = u4_op_dec(lane, m->rux);

  return fod;
}
