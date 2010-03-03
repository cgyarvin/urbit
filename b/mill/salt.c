/* mill/salt.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _salt_walk(): produce type and formula modifications.
*/
static void
_salt_walk(u4_milr m,
           u4_bolt suc,
           u4_type zor,
           u4_type fuz,
           u4_plox *zel,
           u4_belt *vix)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(suc) ) {
    *vix = u4_noun_0;
    *zel = u4_noun_0;
  }
  else {
    u4_nail i_suc  = u4_ch(suc);
    u4_rope pi_suc = u4_ch(i_suc);
    u4_gene qi_suc = u4_ct(i_suc);
    u4_axis axe    = u4_noun_1;
    u4_type buv;
    u4_tape gut    = _mill_hunt(m, pi_suc, fuz, &axe, &buv);
    u4_loaf wid    = _mill_make(m, qi_suc, zor);
    u4_type p_wid  = u4_ch(wid);
    u4_form q_wid  = u4_ct(wid);
    u4_type nar    = _mill_snap(m, buv, p_wid);

    _salt_walk(m, u4_ct(suc), zor, fuz, zel, vix);

    *zel = u4_k_cell
      (lane, 
       u4_k_cell(lane, gut, nar),
       *zel);

    *vix = u4_k_cell
      (lane, 
       u4_k_cell(lane, axe, q_wid), 
       *vix);
  }
}

/* _mill_salt(): modify a change target.
**
**    suc: changes:  bolt
**    pex: subject:  type
**    fuz: target:   type
**    ped: fragment: axis
*/
u4_loaf
_mill_salt(u4_milr m,
           u4_bolt suc,
           u4_type pex,
           u4_type fuz,
           u4_axis ped)
{
  u4_belt vix = u4_noun_0;
  u4_plox zel = u4_noun_0;
  u4_type gob;
  u4_form fol;

  _salt_walk(m, suc, pex, fuz, &zel, &vix);

  gob = _mill_edit(m, zel, u4_noun_0, fuz);
  fol = _mill_hike(m, ped, vix);

  return u4_k_cell(m->lane, gob, fol);
}
