/* mill/q/flic.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_flic():
*/
u4_noun
_mill_q_flic(u4_milr m, 
             u4_skel tep,
             u4_gene von)
{
  u4_lane lane = m->lane;

  //  :*
  //    %trop
  //    (stub tep)
  //    :*  
  //      %lome
  //      von
  //    ==
  //  ==

  return u4_k_qual
    (lane, u4_atom_trop,
           _mill_stub(m, tep),
           u4_atom_lome,
           von);
}
