/* mill/bake.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_bake(): bake a gene, milling and discarding type.
*/
u4_form
_mill_bake(u4_milr m, 
           u4_gene gen,
           u4_type tip)
{
  u4_loaf fod = _mill_make(m, gen, tip);

  return u4_ct(fod);
}
