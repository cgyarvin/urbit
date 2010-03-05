/* mill/orth.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_orth(): orthogonality.
*/
u4_t
_mill_orth(u4_milr m,
           u4_type tip,
           u4_type gan)
{
  return _mill_null(m, u4_k_trel(m->lane, u4_atom_fuse, tip, gan));
}
