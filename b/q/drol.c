/* mill/q/drol.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_drol():
*/
u4_noun
_mill_q_drol(u4_milr m, 
             u4_skel nix,
             u4_skel tep,
             u4_gene von)
{
  u4_lane lane = m->lane;

  //  :*
  //    %glem
  //    (stub tep)
  //    :*  
  //      %lome
  //      :*  
  //        %perd 
  //        (stub nix)
  //        %flot
  //        von 
  //      ==
  //    ==
  //  ==

  return u4_k_qual
    (lane, u4_atom_glem,
           _mill_stub(m, tep),
           u4_atom_lome,
           u4_k_qual
             (lane, u4_atom_perd,
                    _mill_stub(m, nix),
                    u4_atom_flot,
                    von));
}
