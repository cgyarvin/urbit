/* mill/stub.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _stub_peft_in(): convert peft items to slon list.
*/
u4_noun
_stub_peft_in(u4_milr m,
              u4_noun wix)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(wix) ) {
    return u4_noun_0;
  } 
  else {
    u4_noun i_wix = u4_ch(wix);
    u4_noun t_wix = u4_ct(wix);
    u4_mark pi_wix = u4_ch(i_wix);
    u4_skel qi_wix = u4_ct(i_wix);

    return u4_k_cell
      (lane, u4_k_cell(lane, pi_wix, _mill_stub(m, qi_wix)),
             _stub_peft_in(m, t_wix));
  }
}

/* _mill_stub(): generate direct skel.
*/
u4_gene
_mill_stub(u4_milr m,
           u4_skel kel)
{
  u4_lane lane = m->lane;
  u4_noun p_kel, q_kel;

  if ( u4_b_p(kel, u4_atom_chob, &p_kel) ) {
    u4_rope hep = p_kel;

    return u4_k_qual(lane, u4_atom_slem, u4_atom_slop, hep, u4_noun_0);
  }
  else if ( u4_b_p(kel, u4_atom_dept, &p_kel) ) {
    u4_skel hup = p_kel;

    return _mill_fiat(m, hup);
  }
  else if ( u4_b_pq(kel, u4_atom_drib, &p_kel, &q_kel) ) {
    u4_noun piv = q_kel;

    return _mill_stub(m, piv);
  }
  else if ( u4_b_p(kel, u4_atom_felk, &p_kel) ) {
    u4_bead hin = p_kel;

    return u4_k_cell(lane, u4_atom_dron, hin); 
  } 
  else if ( u4_b_p(kel, u4_atom_flit, &p_kel) ) {
    u4_gene gen = p_kel;

    return u4_k_cell(lane, u4_atom_slem, gen);
  }
  else if ( u4_b_p(kel, u4_atom_galb, &p_kel) ) {
    u4_bead hin = p_kel;

    return u4_k_cell(lane, u4_atom_draz, hin);
  } 
  else if ( u4_b_pq(kel, u4_atom_gorm, &p_kel, &q_kel) ) {
    u4_skel pef = p_kel;
    u4_skel niz = q_kel;

    return u4_k_cell
      (lane,
       u4_atom_slem,
       u4_k_qual
       (lane, u4_atom_slid, 
              _mill_stub(m, pef),
              _mill_stub(m, niz),
              u4_noun_0));
  }
  else if ( u4_b_p(kel, u4_atom_grop, &p_kel) ) {
    u4_bead hin = p_kel;

    return u4_k_cell(lane, u4_atom_drop, hin);
  }
  else if ( u4_b_p(kel, u4_atom_peft, &p_kel) ) {
    u4_noun wix = p_kel;

    return u4_k_cell(lane, u4_atom_slon, _stub_peft_in(m, wix));
  }
  else if ( u4_b_pq(kel, u4_atom_shud, &p_kel, &q_kel) ) {
    u4_skel hup = p_kel;
    u4_skel sim = q_kel;

    return u4_k_qual
      (lane,
       u4_atom_plat,
       _mill_stub(m, hup),
       u4_atom_stop,
       _mill_stub(m, sim));

  }
  else if ( u4_b_p(kel, u4_atom_warx, &p_kel) ) {
    u4_noun bec = p_kel;
    u4_skel i_bec = u4_ch(bec);
    u4_gene hez   = _mill_stub(m, i_bec);
      
    return u4_k_qual
      (lane,
       u4_atom_slid,
       _mill_fiat(m, kel),
       u4_k_cell(lane, u4_atom_glon, hez),
       u4_noun_0);
  }
  else return u4_trip;
}
