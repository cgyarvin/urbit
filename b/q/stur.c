/* mill/q/stol.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_stol():
*/
u4_noun
_mill_q_stol(u4_milr m, 
             u4_skel tep,
             u4_gene von)
{
  u4_lane lane = m->lane;

  //  :*
  //    %plat
  //    (stub tep)
  //    :*  
  //      %stop
  //      von
  //    ==
  //  ==

  return u4_k_qual
    (lane, u4_atom_plat,
           _mill_stub(m, tep),
           u4_atom_stop,
           von);
}
