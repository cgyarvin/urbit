/* mill/x/name.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_p_name()::
*/
u4_type
_mill_p_name(u4_milr m,
             u4_mark tem,
             u4_gene caf,
             u4_type pex)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_face, tem, _mill_play(m, caf, pex));
}

/* _mill_b_name()::
*/
u4_form
_mill_b_name(u4_milr m,
             u4_mark tem,
             u4_gene caf,
             u4_type pex)
{
  return _mill_bake(m, caf, pex);
}

/* _mill_m_name()::
*/
u4_loaf
_mill_m_name(u4_milr m,
             u4_mark tem,
             u4_gene caf,
             u4_type pex)
{
  u4_lane lane = m->lane;
  u4_loaf rec = _mill_make(m, caf, pex);

  return u4_k_cell
    (lane, u4_k_trel(lane, u4_atom_face, tem, u4_ch(rec)),
           u4_ct(rec));
}
