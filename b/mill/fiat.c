/* mill/fiat.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _fiat_stub(): lamb from stub.
*/
static u4_gene
_fiat_stub(u4_milr m,
           u4_skel kel)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_grat,
           u4_k_cell(lane, u4_atom_dron, u4_noun_0),
           u4_atom_stop,
           _mill_stub(m, kel));
}

/* _fiat_peft_in()::
*/
static u4_noun
_fiat_peft_in(u4_milr m,
              u4_axis axe,
              u4_noun wix)
{
  u4_lane lane  = m->lane;
  u4_noun i_wix = u4_ch(wix);
  u4_noun t_wix = u4_ct(wix);
  u4_mark pi_wix = u4_ch(i_wix);
  u4_skel qi_wix = u4_ct(i_wix);

  if ( u4_n_zero(t_wix) ) {
    return u4_k_cell
      (lane, u4_k_cell
               (lane, pi_wix, 
                      u4_k_qual
                        (lane, u4_atom_slid, 
                               _mill_fiat(m, qi_wix), 
                                u4_k_cell(lane, u4_atom_slet, axe),
                                u4_noun_0)),
              u4_noun_0);
  }
  else {
    u4_axis piq = u4_op_peg(lane, axe, u4_noun_2);
    u4_axis guz = u4_op_peg(lane, axe, u4_noun_3);

    return u4_k_cell
      (lane, u4_k_cell
               (lane, pi_wix, 
                      u4_k_qual
                        (lane, u4_atom_slid, 
                               _mill_fiat(m, qi_wix), 
                                u4_k_cell(lane, u4_atom_slet, piq),
                                u4_noun_0)),
              _fiat_peft_in(m, guz, t_wix));
  }
}

/* _fiat_peft()::
*/
static u4_gene
_fiat_peft(u4_milr m,
           u4_noun wix)
{
  u4_lane lane = m->lane;

  return u4_k_quil
    (lane,
     u4_atom_grat,
     u4_k_cell(lane, u4_atom_dron, u4_noun_0),
     u4_atom_stop,
     u4_atom_slon,
     _fiat_peft_in(m, u4_noun_4, wix));
}

/* _fiat_warx_in()::
*/
static u4_noun
_fiat_warx_in(u4_milr m,
              u4_noun bec)
{
  u4_lane lane  = m->lane;
  u4_skel i_bec = u4_ch(bec);
  u4_noun t_bec = u4_ct(bec);

  if ( u4_n_zero(t_bec) ) {
    return u4_noun_0;
  } else {
    return u4_k_cell
      (lane, u4_k_cell(lane, u4_atom_fing, i_bec),
             _fiat_warx_in(m, t_bec));
  }
}

/* _fiat_warx()::
*/
static u4_gene
_fiat_warx(u4_milr m,
           u4_noun bec)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane,
     u4_atom_grat,
     u4_k_cell(lane, u4_atom_dron, u4_noun_0),
     u4_atom_stop,
     u4_k_trel
      (lane,
       u4_atom_quem,
       u4_k_cell(lane, u4_atom_slet, u4_noun_4),
       _fiat_warx_in(m, bec)));
}

/* _mill_fiat(): generate lamb gene. 
*/
u4_gene
_mill_fiat(u4_milr m,
           u4_skel kel)
{
  u4_lane lane = m->lane;
  u4_noun p_kel, q_kel;

  if ( u4_b_p(kel, u4_atom_chob, &p_kel) ) {
    u4_rope hep = p_kel;

    return u4_k_trel(lane, u4_atom_slop, hep, u4_noun_0);
  }
  else if ( u4_b_p(kel, u4_atom_dept, &p_kel) ) {
    return _fiat_stub(m, kel);
  }
  else if ( u4_b_pq(kel, u4_atom_drib, &p_kel, &q_kel) ) {
    u4_noun piv = q_kel;

    return _mill_fiat(m, piv);
  }
  else if ( u4_b_p(kel, u4_atom_felk, &p_kel) ) {
    return _fiat_stub(m, kel);
  } 
  else if ( u4_b_p(kel, u4_atom_flit, &p_kel) ) {
    u4_gene gen = p_kel;

    return gen;
  }
  else if ( u4_b_p(kel, u4_atom_galb, &p_kel) ) {
    return _fiat_stub(m, kel);
  } 
  else if ( u4_b_pq(kel, u4_atom_gorm, &p_kel, &q_kel) ) {
    u4_skel pef = p_kel;
    u4_skel niz = q_kel;

    return u4_k_qual
       (lane, u4_atom_slid, 
              _mill_stub(m, pef),
              _mill_stub(m, niz),
              u4_noun_0);
  }
  else if ( u4_b_p(kel, u4_atom_grop, &p_kel) ) {
    return _fiat_stub(m, kel);
  }
  else if ( u4_b_p(kel, u4_atom_peft, &p_kel) ) {
    u4_noun wix = p_kel;

    return _fiat_peft(m, wix);
  }
  else if ( u4_b_pq(kel, u4_atom_shud, &p_kel, &q_kel) ) {
    return _fiat_stub(m, kel);
  }
  else if ( u4_b_p(kel, u4_atom_warx, &p_kel) ) {
    u4_noun bec = p_kel;

    return _fiat_warx(m, bec);
  }
  else return u4_trip;
}
