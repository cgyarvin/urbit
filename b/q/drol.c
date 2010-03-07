/* mill/q/drol.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_drol():
*/
u4_noun
_mill_q_drol(u4_milr m, 
             u4_bone nix,
             u4_bone tep,
             u4_gene von)
{
  u4_lane lane = m->lane;

  //  :*
  //    %trop
  //    (lump tep)
  //    :*  
  //      %lome
  //      :*  
  //        %cast 
  //        (lump nix)
  //        %flot
  //        von 
  //      ==
  //    ==
  //  ==

  return u4_k_qual
    (lane, u4_atom_trop,
           _mill_lump(m, tep),
           u4_atom_lome,
           u4_k_qual
             (lane, u4_atom_cast,
                    _mill_lump(m, nix),
                    u4_atom_flot,
                    von));
}
