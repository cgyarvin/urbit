/* mill/x/slon.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _slon_make(): mill a slon.
*/
static void
_slon_make(u4_milr m,
           u4_noun caw,
           u4_type tip,
           u4_type *gor,
           u4_form *fal)
{
  u4_lane lane   = m->lane;
  u4_noun i_caw  = u4_ch(caw);
  u4_mark pi_caw = u4_ch(i_caw);
  u4_gene qi_caw = u4_ct(i_caw);
  u4_noun t_caw  = u4_ct(caw);
  u4_loaf fod    = _mill_make(m, qi_caw, tip);

  if ( u4_n_zero(t_caw) ) {
    *gor = u4_k_trel
      (lane, u4_atom_crib, 
             u4_k_cell(lane, pi_caw, u4_ch(fod)),
             u4_noun_0);

    *fal = u4_ct(fod);
  } 
  else {
    _slon_make(m, t_caw, tip, gor, fal);

    *gor = u4_k_trel
      (lane, u4_atom_crib,
             u4_k_cell(lane, pi_caw, u4_ch(fod)),
             u4_ct(*gor));
    
    *fal = _mill_cons(m, u4_ct(fod), *fal);
  }
}

/* _mill_x_slon()::
*/
u4_loaf
_mill_x_slon(u4_milr m, 
             u4_noun caw,
             u4_type tip)
{
  u4_lane lane = m->lane;
  u4_type gor;
  u4_form fal;

  _slon_make(m, caw, tip, &gor, &fal);
  return u4_k_cell(lane, gor, fal);
}
