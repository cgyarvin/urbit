/* mill/q/slon.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _slon_in():
*/
u4_noun
_slon_in(u4_milr m,
         u4_noun caw)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(caw) ) {
    return u4_noun_0;
  }
  else {
    u4_noun i_caw  = u4_ch(caw);
    u4_noun pi_caw = u4_ch(i_caw);
    u4_noun qi_caw = u4_ct(i_caw);
    u4_noun t_caw  = u4_ct(caw);

    if ( u4_n_zero(pi_caw) ) {
      return u4_k_cell(lane, qi_caw, _slon_in(m, t_caw));
    }
    else {
      return u4_k_cell
        (lane, u4_k_trel(lane, u4_atom_sliv, pi_caw, qi_caw),
               _slon_in(m, t_caw));
    }
  }
}

/* _mill_q_slon():
*/
u4_noun
_mill_q_slon(u4_milr m, 
             u4_noun caw)
{
  u4_lane lane = m->lane;

  return u4_k_cell(lane, u4_atom_slux, _slon_in(m, caw));
}
