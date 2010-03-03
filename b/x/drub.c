/* mill/x/sliv.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_sliv(): name a face.
*/
u4_loaf
_mill_x_sliv(u4_milr m,
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
