/* mill/x/poos.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_x_poos()::
*/
u4_loaf
_mill_x_poos(u4_milr m, 
             u4_noun cux,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun buv = m->nix;
  u4_loaf fod;

  m->nix = cux;
  fod = _mill_make(m, lyq, tip);
  m->nix = buv;

  return fod;
}
