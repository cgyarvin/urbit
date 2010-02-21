/* mill/salt.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _salt_boil(): apply a change list to a type.
*/
u4_type
_salt_boil(u4_milr m,
           u4_tape lub,
           u4_type zor)
{
  if ( u4_n_zero(lub) ) {
    return zor;
  }
  else {
    u4_tack i_lub = u4_ch(lub);
    u4_tape t_lub = u4_ct(lub);

    return _salt_boil
      (m, t_lub, _mill_weld(m, u4_ch(i_lub), u4_ct(i_lub), zor));
  }
}

/* _salt_walk(): produce type and formula modifications.
*/
static void
_salt_walk(u4_milr m,
           u4_bolt suc,
           u4_type zor,
           u4_type hel,
           u4_tape *lub,
           u4_belt *vix)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(suc) ) {
    *vix = u4_noun_0;
    *lub = u4_noun_0;
  }
  else {
    u4_nail i_suc  = u4_ch(suc);
    u4_rope pi_suc = u4_ch(i_suc);
    u4_gene qi_suc = u4_ct(i_suc);
    u4_loaf pas    = _mill_look(m, pi_suc, hel);
    u4_loaf wid    = _mill_make(m, qi_suc, zor);
    u4_type p_pas  = u4_ch(pas);
    u4_form q_pas  = u4_ct(pas);
    u4_type p_wid  = u4_ch(wid);
    u4_form q_wid  = u4_ct(wid);
    u4_axis axe;

    if ( !u4_b_p(q_pas, u4_noun_0, &axe) ) {
      _mill_fail(m, "salt: bad walk a"); return;
    }
    if ( u4_atom_blot == p_pas ) {
      _mill_fail(m, "salt: bad walk b"); return;
    }

    _salt_walk(m, u4_ct(suc), zor, hel, lub, vix);

    *lub = u4_k_cell
      (lane, 
       u4_k_cell(lane, pi_suc, _mill_snap(m, p_pas, p_wid)),
       *lub);

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
**    hel: target:   type
**    ped: fragment: axis
*/
u4_loaf
_mill_salt(u4_milr m,
           u4_bolt suc,
           u4_type pex,
           u4_type hel,
           u4_axis ped)
{
  u4_belt vix;
  u4_tape lub;
  u4_type gob;
  u4_form fol;

  _salt_walk(m, suc, pex, hel, &lub, &vix);

  gob = _salt_boil(m, lub, hel);
  fol = _mill_hike(m, ped, vix);

  return u4_k_cell(m->lane, gob, fol);
}
