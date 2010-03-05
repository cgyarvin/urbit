/* mill/both.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_both(): fuse pair.
*/
u4_form
_mill_both(u4_milr m,
           u4_type nem,
           u4_type dif)
{
  if ( u4_n_eq(nem, dif) ) {
    return dif;
  }

  else if ( _mill_nest(m, u4_atom_blur, nem) ) {
    return dif;
  }
  else if ( _mill_nest(m, u4_atom_blur, dif) ) {
    return nem;
  }
  else if ( _mill_nest(m, nem, u4_atom_blot) ||
            _mill_nest(m, dif, u4_atom_blot) )
  {
    return u4_atom_blot;
  }

#if 0
  else if ( u4_n_eq(u4_atom_blur, nem) ) {
    return dif;
  }
  else if ( u4_n_eq(u4_atom_blot, dif) ) {
    return dif;
  }
  else if ( u4_n_eq(u4_atom_blur, dif) ) {
    return nem;
  }
  else if ( u4_n_eq(u4_atom_blot, nem) ) {
    return nem;
  }
#endif

  else {
    // u4_burp(m->lane, "fuse: nem", _mill_dump(m, nem));
    // u4_burp(m->lane, "fuse: dif", _mill_dump(m, dif));

    return u4_k_trel(m->lane, u4_atom_fuse, nem, dif);
  }
}
