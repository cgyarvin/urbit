/* mill/q/blem.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_q_blem():
*/
u4_noun
_mill_q_blem(u4_milr m, 
             u4_gene gix)
{
  u4_lane lane = m->lane;

  //  :*
  //    %quiz
  //    gix
  //    [%rock 1]
  //    [%rock 0]
  //  ==

  return u4_k_qual
    (lane, u4_atom_quiz, 
           gix,
           u4_k_cell(lane, u4_atom_rock, u4_noun_1),
           u4_k_cell(lane, u4_atom_rock, u4_noun_0));
}
