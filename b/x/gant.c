/* mill/x/gant.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _gant_weld(): apply a change list to a type.
*/
u4_type
_gant_weld(u4_milr m,
           u4_tape lub,
           u4_type tip)
{
  if ( u4_n_zero(lub) ) {
    return tip;
  }
  else {
    u4_tack i_lub = u4_ch(lub);
    u4_tape t_lub = u4_ct(lub);

    return _gant_weld
      (m, t_lub, _mill_weld(m, u4_ch(i_lub), u4_ct(i_lub), tip));
  }
}

/* _gant_walk(): produce type and formula modifications.
*/
static void
_gant_walk(u4_milr m,
           u4_bolt suc,
           u4_type tip,
           u4_type gan,
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
    u4_loaf pas    = _mill_look(m, pi_suc, gan);
    u4_loaf wid    = _mill_make(m, qi_suc, tip);
    u4_type p_pas  = u4_ch(pas);
    u4_form q_pas  = u4_ct(pas);
    u4_type p_wid  = u4_ch(wid);
    u4_form q_wid  = u4_ct(wid);
    u4_axis axe;

    if ( !u4_b_p(q_pas, u4_noun_0, &axe) ) {
      _mill_fail(m, "gant: bad walk a"); return;
    }
    if ( u4_atom_blot == p_pas ) {
      _mill_fail(m, "gant: bad walk b"); return;
    }

    _gant_walk(m, u4_ct(suc), tip, gan, lub, vix);

    *lub = u4_k_cell
      (lane, 
       u4_k_cell(lane, pi_suc, _mill_snap(m, p_wid, p_pas)),
       *lub);

    *vix = u4_k_cell
      (lane, 
       u4_k_cell(lane, axe, q_wid), 
       *vix);
  }
}

/* _gant_cook(): modify the target of a gant.
*/
static u4_loaf
_gant_cook(u4_milr m,
           u4_bolt suc,
           u4_type tip,
           u4_type gan,
           u4_axis ped)
{
  u4_belt vix;
  u4_tape lub;

  _gant_walk(m, suc, tip, gan, &lub, &vix);

  return u4_k_cell
    (m->lane,
     _gant_weld(m, lub, gan), 
     _mill_hike(m, ped, vix));
}

/* _mill_gant(): gant port.
*/
u4_loaf
_mill_x_gant(u4_milr m,
             u4_rope ved,
             u4_bolt suc,
             u4_type tip)
{
  u4_lane lane = m->lane;
  u4_loaf rec;

  rec = _mill_look(m, ved, tip);

  if ( u4_n_zero(rec) ) {
    return _mill_fail(m, "gant: broken");
  }
  else {
    u4_type gan = u4_ch(rec);
    u4_form nol = u4_ct(rec);
    u4_noun p_nol, q_nol;
    u4_type p_gan;
    u4_gene q_gan;
    u4_axis ped;

    if ( u4_b_p(nol, u4_noun_0, &p_nol) ) {
      ped = p_nol;

      return _gant_cook(m, suc, tip, gan, ped);
    }

    else if ( u4_b_pq(nol, u4_noun_3, &p_nol, 0) &&
              u4_b_p(p_nol, u4_noun_0, &ped) &&
              u4_b_pq(gan, u4_atom_gate, &p_gan, &q_gan) )
    {
      u4_loaf das = _gant_cook(m, suc, tip, p_gan, ped);
      u4_type p_das = u4_ch(das);
      u4_form q_das = u4_ct(das);

      return u4_k_cell
        (lane,
         u4_k_trel(lane, u4_atom_gate, p_das, q_gan),
         u4_k_trel(lane, u4_noun_3, q_das, q_nol));
    }

    else {
      return _mill_fail(m, "gant: ugly");
    }
  }
}
