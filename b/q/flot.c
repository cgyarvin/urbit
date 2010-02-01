/* mill/q/flot.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_flot():
*/
u4_noun
_mill_q_flot(u4_milr m, 
             u4_gene cug)
{
  u4_lane lane = m->lane;

  //  :*
  //    %slon
  //    [%clep [%% cug]]
  //    [%lect %%]
  //  ==

  return u4_k_trel
    (lane, u4_atom_slon,
           u4_k_trel(lane, u4_atom_clep, u4_noun_0, cug),
           u4_k_cell(lane, u4_atom_lect, u4_noun_0));
}
