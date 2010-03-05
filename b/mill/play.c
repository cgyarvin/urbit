/* mill/play.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_play(): play a gene, milling and discarding formula.
*/
u4_type
_mill_play(u4_milr m, 
           u4_gene gen,
           u4_type tip)
{
  u4_loaf fod = _mill_make(m, gen, tip);

  return u4_ch(fod);
}


