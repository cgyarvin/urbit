/* mill/x/rock.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_p_rock()::
*/
u4_type
_mill_p_rock(u4_milr m, 
             u4_noun daq,
             u4_type tip)
{
  u4_lane lane = m->lane;

  return u4_k_cell(lane, u4_atom_cube, daq);
}

/* _mill_b_rock()::
*/
u4_form
_mill_b_rock(u4_milr m, 
             u4_noun daq,
             u4_type tip)
{
  u4_lane lane = m->lane;

  return u4_k_cell(lane, u4_noun_1, daq);
}

/* _mill_m_rock()::
*/
u4_loaf
_mill_m_rock(u4_milr m, 
             u4_noun daq,
             u4_type tip)
{
  u4_lane lane = m->lane;

  return u4_k_cell
    (lane, _mill_p_rock(m, daq, tip),
           _mill_b_rock(m, daq, tip));
}
