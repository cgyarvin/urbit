/* mill/q/stix.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_stix():
*/
u4_noun
_mill_q_stix(u4_milr m, 
             u4_skel nix,
             u4_skel tep,
             u4_gene von)
{
  u4_lane lane = m->lane;

  //  :*
  //    %plat
  //    (stub tep)
  //    :*  
  //      %stop
  //      :*  
  //        %glid 
  //        (stub nix)
  //        %stem
  //        von 
  //      ==
  //    ==
  //  ==

  return u4_k_qual
    (lane, u4_atom_plat,
           _mill_stub(m, tep),
           u4_atom_stop,
           u4_k_qual
             (lane, u4_atom_glid,
                    _mill_stub(m, nix),
                    u4_atom_stem,
                    von));
}
