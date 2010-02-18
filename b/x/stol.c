/* mill/x/quol.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_quol()::
*/
u4_loaf
_mill_x_quol(u4_milr m, 
             u4_gene tes,
             u4_gene bif, 
             u4_gene hob, 
             u4_type tip)
{
  u4_lane lane = m->lane;
  u4_loaf ruf  = _mill_test(m, tes, tip);
  u4_loaf hig  = _mill_make(m, bif, u4_ch(ruf));
  u4_loaf goz  = _mill_make(m, hob, tip);
  u4_form fal  = u4_ct(ruf);

  if ( u4_n_eq(u4_noun_1, u4_ch(fal)) ) {
    if ( u4_n_eq(u4_noun_0, u4_ct(fal)) ) {
      return hig;
    } else {
      return goz;
    }
  }
  else {
    return u4_k_cell
      (lane, 
       _mill_eith(m, u4_ch(hig), u4_ch(goz)),
       u4_k_qual(m->lane, u4_noun_2, fal, u4_ct(hig), u4_ct(goz)));
  }
}
