/* mill/q/stem.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_stem():
*/
u4_noun
_mill_q_stem(u4_milr m, 
             u4_gene cug)
{
  u4_lane lane = m->lane;

  //  :*
  //    %grat
  //    [%stig [%% cug]]
  //    [%slat 0 %%]
  //  ==

  return u4_k_trel
    (lane, u4_atom_grat,
           u4_k_trel(lane, u4_atom_stig, u4_noun_0, cug),
           u4_k_trel(lane, u4_atom_slat, u4_noun_0, u4_noun_0));
}
