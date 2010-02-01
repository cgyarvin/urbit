/* mill/x/slon.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_slon()::
*/
u4_loaf
_mill_x_slon(u4_milr m, 
             u4_gene del,
             u4_gene zim, 
             u4_type tip)
{
  u4_lane lane  = m->lane;
  u4_loaf fod = _mill_make(m, del, tip);
  u4_loaf saq = _mill_make(m, zim, u4_ch(fod));

  return u4_k_cell
    (lane, u4_ch(saq),
           _mill_comp(m, u4_ct(fod), u4_ct(saq)));
}
