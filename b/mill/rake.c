/* mill/rake.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_rake(): excise all superficial gas.
*/
u4_type
_mill_rake(u4_milr m,
           u4_type typ)
{
  u4_noun p_typ, q_typ; 

  while ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) ) {
    typ = _mill_repo(m, p_typ, q_typ);
  }
  return typ;
}
