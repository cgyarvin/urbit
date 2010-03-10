/* mill/x/sure.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_p_sure()::
*/
u4_type
_mill_p_sure(u4_milr m, 
             u4_gene fes,
             u4_gene gav, 
             u4_gene vep, 
             u4_type tip)
{
  return _mill_play(m, vep, tip);
}

/* _mill_b_sure()::
*/
u4_form
_mill_b_sure(u4_milr m, 
             u4_gene fes,
             u4_gene gav, 
             u4_gene vep, 
             u4_type tip)
{
  u4_type nud = _mill_play(m, fes, tip);
  u4_type gor = _mill_play(m, gav, tip);

  // u4_burp(m->lane, "nud", _mill_dump(m, nud));
  // u4_burp(m->lane, "gor", _mill_dump(m, gor));

  if ( !_mill_nest(m, gor, nud) ) {
    return _mill_fail(m, "type mismatch");
  }
  else {
    return _mill_bake(m, vep, tip);
  }
}

/* _mill_m_sure()::
*/
u4_loaf
_mill_m_sure(u4_milr m, 
             u4_gene fes,
             u4_gene gav, 
             u4_gene vep, 
             u4_type tip)
{
  u4_type nud = _mill_play(m, fes, tip);
  u4_type gor = _mill_play(m, gav, tip);

  // u4_burp(m->lane, "nud", _mill_dump(m, nud));
  // u4_burp(m->lane, "gor", _mill_dump(m, gor));

  if ( !_mill_nest(m, gor, nud) ) {
    return _mill_fail(m, "type mismatch");
  }
  else {
    return _mill_make(m, vep, tip);
  }
}