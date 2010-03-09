/* mill/x/home.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_p_home()::
*/
u4_type
_mill_p_home(u4_milr m, 
             u4_noun cux,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun buv = m->nix;
  u4_type zer;

  m->nix = cux;
  zer = _mill_play(m, lyq, tip);
  m->nix = buv;

  return zer;
}

/* _mill_b_home()::
*/
u4_form
_mill_b_home(u4_milr m, 
             u4_noun cux,
             u4_gene lyq, 
             u4_type tip)
{
  u4_noun buv = m->nix;
  u4_form gum;

  m->nix = cux;
  gum = _mill_bake(m, lyq, tip);
  m->nix = buv;

  return gum;
}

/* _mill_m_home()::
*/
u4_loaf
_mill_m_home(u4_milr m, 
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
