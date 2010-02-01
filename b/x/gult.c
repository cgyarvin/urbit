/* mill/x/gult.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_gult()::
*/
u4_loaf
_mill_x_gult(u4_milr m, 
             u4_atom fiz,
             u4_gene dil, 
             u4_type tip)
{
  u4_lane lane  = m->lane;
  u4_loaf fod   = _mill_make(m, dil, tip);
  u4_form q_fod = u4_ct(fod);
  u4_type gan;

  // XX: safety
  //
  if ( u4_n_eq(u4_noun_3, fiz) || u4_n_eq(u4_noun_7, fiz) ) {
    gan = u4_atom_blur;
  }
  else if ( u4_n_eq(u4_noun_4, fiz) || u4_n_eq(u4_noun_6, fiz) ) {
    gan = u4_k_trel
      (lane, u4_atom_fork, 
             u4_k_cell(lane, u4_atom_cube, u4_noun_0),
             u4_k_cell(lane, u4_atom_cube, u4_noun_1));
  }
  else if ( u4_n_eq(u4_noun_5, fiz) ) {
    gan = u4_atom_atom;
  }

  return u4_k_cell(lane, gan, u4_k_cell(lane, fiz, q_fod));
}
