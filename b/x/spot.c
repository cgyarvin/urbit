/* mill/x/spot.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_spot()::
*/
u4_loaf
_mill_x_spot(u4_milr m, 
             u4_noun xed,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun muw = m->zud;
  u4_loaf fod;

  m->zud = xed;
  fod = _mill_make(m, lyq, tip);
  m->zud = muw;

  return fod;
}
