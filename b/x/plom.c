/* mill/x/slux.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_slux(): nameless tuple.
*/
u4_loaf
_mill_x_slux(u4_milr m,
             u4_noun fut,
             u4_type pex)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(fut) ) {
    return _mill_fail(m, "empty slux");
  }
  else if ( u4_n_zero(u4_ct(fut)) ) {
    return _mill_make(m, u4_ch(fut), pex);
  }
  else {
    u4_loaf deg = _mill_make(m, u4_ch(fut), pex);
    u4_loaf har = _mill_x_slux(m, u4_ct(fut), pex);

    return u4_k_cell
      (lane, u4_k_trel(lane, u4_atom_cell, u4_ch(deg), u4_ch(har)),
             _mill_cons(m, u4_ct(deg), u4_ct(har)));
  }
}
