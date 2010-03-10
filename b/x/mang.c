/* mill/x/mang.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mang_type(): mangle types.
*/
static u4_type
_mang_type(u4_milr m,
           u4_type gar,
           u4_type woc)
{
  u4_lane lane = m->lane;
  u4_tack tak  = u4_k_cell(lane, u4_atom_axis, u4_noun_4);
  u4_tape bel  = u4_k_cell(lane, tak, u4_noun_0);
  u4_glep pug  = u4_k_cell(lane, bel, woc);
  u4_plox zel  = u4_k_cell(lane, pug, u4_noun_0);
  u4_type bim  = _mill_edit(m, zel, u4_noun_0, gar);
  u4_loaf hax  = _mill_find(m, u4_noun_0, u4_noun_0, bim);

  if ( u4_n_zero(hax) ) {
    return _mill_fail(m, "bad gate");
  }
  else return u4_ch(hax);
}

/* _mill_p_mang()::
*/
u4_type
_mill_p_mang(u4_milr m, 
             u4_gene buz,
             u4_gene lep,
             u4_type typ)
{
  u4_type gar = _mill_play(m, buz, typ);
  u4_type tum = _mill_play(m, lep, typ);
  u4_type dex = _mill_peek(m, u4_noun_4, u4_noun_0, gar);
  u4_type woc = _mill_snap(m, dex, tum);

  return _mang_type(m, gar, woc);
}

/* _mill_b_mang()::
*/
u4_form
_mill_b_mang(u4_milr m, 
             u4_gene buz,
             u4_gene lep,
             u4_type typ)
{
  u4_form dev  = _mill_bake(m, buz, typ);
  u4_form zon  = _mill_bake(m, lep, typ);

  return _mill_fire(m, dev, zon);
}

/* _mill_m_mang()::
*/
u4_loaf
_mill_m_mang(u4_milr m, 
             u4_gene buz,
             u4_gene lep,
             u4_type typ)
{
  u4_lane lane    = m->lane;
  u4_loaf pog     = _mill_make(m, buz, typ);
  u4_loaf cas     = _mill_make(m, lep, typ);
  u4_type gar = u4_ch(pog);
  u4_form dev = u4_ct(pog);
  u4_type tum = u4_ch(cas);
  u4_form zon = u4_ct(cas);
  u4_type dex = _mill_peek(m, u4_noun_4, u4_noun_0, gar);
  u4_type woc = _mill_snap(m, dex, tum);

  return u4_k_cell
    (lane, _mang_type(m, gar, woc),
           _mill_fire(m, dev, zon));
}
