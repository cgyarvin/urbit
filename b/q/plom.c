/* mill/q/slux.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _slux_loop()::
*/
static u4_noun
_slux_loop(u4_milr m,
           u4_noun fut)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(fut) ) {
    return u4_noun_0;
  }
  else {
    return 
      u4_k_cell(lane, u4_k_cell(lane, u4_noun_0, u4_ch(fut)),
                      _slux_loop(m, u4_ct(fut)));
  }
}

/* _mill_q_slux():
*/
u4_noun
_mill_q_slux(u4_milr m, 
             u4_noun fut)
{
  u4_lane lane = m->lane;

  //  ?-  fut
  //    -   ~       ~
  //    -   [i t]   [i=[%% i.fut] t=$(fut t.fut)]
  //  ==

  return u4_k_cell(lane, u4_atom_slon, _slux_loop(m, fut));
}
