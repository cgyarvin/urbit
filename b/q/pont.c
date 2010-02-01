/* mill/q/pont.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_pont():
*/
u4_noun
_mill_q_pont(u4_milr m, 
             u4_mark han,
             u4_gene dur,
             u4_gene leb)
{
  u4_lane lane = m->lane;

  //  :*
  //    %slon
  //    [%sard [han dur] [%% [%zarb 1]] ~]
  //    leb
  //  ==
  //
  return u4_k_trel
    (lane, 
     u4_atom_slon,
     u4_k_qual
       (lane,
        u4_atom_sard, 
        u4_k_cell(lane, han, dur),
        u4_k_cell(lane, u4_noun_0, u4_k_cell(lane, u4_atom_zarb, u4_noun_1)),
        u4_noun_0),
     leb);
}
