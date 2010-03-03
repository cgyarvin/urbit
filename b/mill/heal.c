/* mill/heal.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_heal(): modify type to reflect refinement.
**
**   niv: change axis
**   hur: refined type
**   wac: background type
*/
u4_type
_mill_heal(u4_milr m,
           u4_axis niv,
           u4_type hur,
           u4_type wac)
{
  u4_lane lane = m->lane;

  if ( _mill_nest(m, u4_atom_blur, wac) ) {
    return _mill_sail(m, niv, hur);
  }
  else {
    return u4_k_trel
      (lane, u4_atom_fuse, _mill_sail(m, niv, hur), wac);
  }
}
