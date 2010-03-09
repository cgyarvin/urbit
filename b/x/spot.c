/* mill/x/spot.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_p_spot()::
*/
u4_type
_mill_p_spot(u4_milr m, 
             u4_noun xed,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun muw = m->zud;
  u4_type soq;

  m->zud = xed;
  soq = _mill_play(m, lyq, tip);
  m->zud = muw;

  return soq;
}

/* _mill_b_spot()::
*/
u4_form
_mill_b_spot(u4_milr m, 
             u4_noun xed,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun muw = m->zud;
  u4_form qip;

  m->zud = xed;
  qip = _mill_bake(m, lyq, tip);
  m->zud = muw;

  return qip;
}

/* _mill_m_spot()::
*/
u4_loaf
_mill_m_spot(u4_milr m, 
             u4_noun xed,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun muw = m->zud;
  u4_loaf fod;

  m->zud = xed;
  fod = _mill_make(m, lyq, tip);
  m->zud = muw;

  return fod;
}
