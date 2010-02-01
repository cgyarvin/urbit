/* mill/dump.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

    /** Forward declarations.
    **/
      static u4_prep
      _dump_main(u4_milr, u4_tab, u4_xw, u4_type);


/* _dump_count()::
*/
static u4_atom
_dump_count(u4_lane lane, u4_noun q_tip)
{
  if ( u4_n_atom(u4_ch(q_tip)) ) {
    return u4_noun_1;
  }
  else {
    return u4_op_add
      (lane, _dump_count(lane, u4_ch(q_tip)), 
             _dump_count(lane, u4_ct(q_tip)));
  }
}

/* _dump_weight()::
*/
static u4_atom
_dump_weight(u4_lane lane, u4_noun gub)
{
  if ( u4_n_atom(gub) ) {
    return u4_noun_1;
  }
  else {
    return u4_op_add
      (lane, _dump_weight(lane, u4_ch(gub)), 
             _dump_weight(lane, u4_ct(gub)));
  }
}

static u4_noun
_dump_crib(u4_milr m,
           u4_tab  nip,
           u4_xw   xw_zar,
           u4_rope p_tip)
{
  u4_lane lane    = m->lane;

  if ( u4_n_zero(p_tip) ) {
    return u4_noun_0;
  }
  else {
    u4_hair ip_tip  = u4_ch(p_tip);
    u4_term pip_tip = u4_ch(ip_tip);
    u4_rope tp_tip  = u4_ct(p_tip);
    u4_type qip_tip = u4_ct(ip_tip);
    u4_prep zem     = _dump_main(m, nip, xw_zar, qip_tip);
    u4_noun gud     = _dump_crib(m, nip, xw_zar, tp_tip);

    if ( u4_n_zero(pip_tip) ) {
      return u4_k_cell(lane, zem, gud);
    }
    else {
      return u4_k_cell
        (lane, u4_k_qual(lane, u4_atom_glue, pip_tip, u4_cod_in('='), zem),
               gud);
    }
  }
}

static u4_prep
_dump_main(u4_milr m,
           u4_tab  nip,
           u4_xw   xw_zar,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  if ( u4_n_atom(tip) ) {
    return tip;
  }

  else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
    u4_type gan = u4_k_qual(lane, u4_atom_crib, p_tip, q_tip, u4_noun_0);

    return _dump_main(m, nip, xw_zar, gan);
  }

  else if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
    return u4_prep_close
      (lane, '[', ']', _dump_crib(m, nip, xw_zar, p_tip));
  }

  else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
    u4_atom gat;

    gat = u4_k_atom_cat
      (lane, u4_atom_cone, 
             u4_k_atom_cat
               (lane, u4_cod_in('+'), 
                      u4_prep_decimal(lane, _dump_count(lane, q_tip))));

    return u4_prep_close
      (lane, '(', ')', 
       u4_k_list(lane, gat, _dump_main(m, nip, xw_zar, p_tip), 0));
  }
  
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return u4_prep_close
      (lane, '(', ')', 
             u4_k_list(lane, u4_atom_cube, u4_pump_prep(lane, p_tip), 0));
  }

  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return u4_prep_close
      (lane, '(', ')', 
             u4_k_list(lane,
                       u4_atom_fork,
                       _dump_main(m, nip, xw_zar, p_tip),
                       _dump_main(m, nip, xw_zar, q_tip),
                       0));
  }

  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return u4_prep_close
      (lane, '(', ')', 
             u4_k_list(lane,
                       u4_atom_fuse,
                       _dump_main(m, nip, xw_zar, p_tip),
                       _dump_main(m, nip, xw_zar, q_tip),
                       0));
  }

  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
#if 1
    if ( u4_tab_in(tip, nip) ) {
      return u4_k_atom_cat
        (lane, u4_cod_in('#'), u4_tab_get(tip, nip));
    }
    else {
      u4_prep vof;

      nip = u4_tab_add(lane, tip, u4_cod_in('A' + xw_zar), nip); 
      vof = _dump_main(m, nip, xw_zar + 1, _mill_reap(m, tip));

      return u4_k_quil
        (lane, u4_atom_nail, 
               u4_cod_in('A' + xw_zar),
               u4_cod_in('#'), 
               vof,
               u4_noun_0);
    }
#else
    u4_atom gat;

    gat = u4_k_atom_cat
      (lane, u4_atom_gate, 
             u4_k_atom_cat
               (lane, u4_cod_in(':'), 
                      u4_prep_decimal(lane, _dump_weight(lane, q_tip))));

    return u4_prep_close
      (lane, '(', ')', 
       u4_k_list(lane, gat, _dump_main(m, nip, xw_zar, p_tip), 0));
#endif
  }

  else {
    return u4_trip;
  }
}

u4_prep
_mill_dump(u4_milr m,
           u4_type tip)
{
  return _dump_main(m, u4_noun_0, 0, tip);

}
