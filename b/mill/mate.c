/* mill/mate.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mate_any(): no type enforced.
*/
static u4_gene
_mate_any(u4_milr m)
{
  return u4_k_cell(m->lane, u4_atom_crad, u4_noun_0);
}

/* _mate_peft_in(): convert peft items to cret list.
*/
static u4_noun
_mate_peft_in(u4_milr m,
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
      (lane, u4_k_cell(lane, pi_wix, _mill_mate(m, qi_wix)),
             _mate_peft_in(m, t_wix));
  }
}

/* _mate_warx_in(): convert warx skels to if chain
*/
static u4_noun
_mate_warx_in(u4_milr m,
              u4_noun bec)
{
  u4_noun lane = m->lane;

  if ( u4_n_zero(bec) ) {
    return u4_k_cell(lane, u4_atom_frag, u4_noun_0);
  }
  else {
    u4_skel i_bec = u4_ch(bec);
    u4_noun t_bec = u4_ct(bec);

    //  :*
    //    %quiz 
    //    [%like [%frag 1] (mate i.bec)] 
    //    [%frag 1] 
    //    $(bec t.bec)
    //  ==
    //
    return u4_k_qual
      (lane, u4_atom_quiz,
             u4_k_trel
              (lane, u4_atom_like, 
                     u4_k_cell(lane, u4_atom_frag, u4_noun_1),
                     _mill_mate(m, i_bec)),
              u4_k_cell(lane, u4_atom_frag, u4_noun_1),
              _mate_warx_in(m, t_bec));
  }
}

/* _mate_warx()::
*/
static u4_gene
_mate_warx(u4_milr m,
           u4_noun bec)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_link, _mate_any(m), _mate_peft_in(m, bec));
}

/* _mate_peft()::
*/
static u4_gene
_mate_peft(u4_milr m,
           u4_noun wix)
{
  u4_lane lane = m->lane;

  return u4_k_cell(lane, u4_atom_cret, _mate_peft_in(m, wix));
}

/* _mill_mate(): generate match gene. 
*/
u4_gene
_mill_mate(u4_milr m,
           u4_skel kel)
{
  u4_lane lane = m->lane;
  u4_noun p_kel, q_kel;

  if ( u4_b_p(kel, u4_atom_chob, &p_kel) ) {
    return _mate_any(m);
  }
  else if ( u4_b_p(kel, u4_atom_dept, &p_kel) ) {
    return _mate_any(m);
  }
  else if ( u4_b_pq(kel, u4_atom_drib, &p_kel, &q_kel) ) {
    u4_noun ved = p_kel;

    return _mill_mate(m, ved);
  }
  else if ( u4_b_p(kel, u4_atom_felk, &p_kel) ) {
    u4_bead hin = p_kel;

    return u4_k_cell(lane, u4_atom_crad, hin); 
  } 
  else if ( u4_b_p(kel, u4_atom_flit, &p_kel) ) {
    return _mate_any(m);
  }
  else if ( u4_b_p(kel, u4_atom_galb, &p_kel) ) {
    u4_bead hin = p_kel;

    return u4_k_cell(lane, u4_atom_palt, hin);
  } 
  else if ( u4_b_pq(kel, u4_atom_gorm, &p_kel, &q_kel) ) {
    return _mate_any(m);
  }
  else if ( u4_b_p(kel, u4_atom_grop, &p_kel) ) {
    u4_bead hin = p_kel;

    return u4_k_cell(lane, u4_atom_rock, hin);
  }
  else if ( u4_b_p(kel, u4_atom_peft, &p_kel) ) {
    u4_noun wix = p_kel;

    return _mate_peft(m, wix);
  }
  else if ( u4_b_pq(kel, u4_atom_shud, &p_kel, &q_kel) ) {
    return _mate_any(m);
  }
  else if ( u4_b_p(kel, u4_atom_warx, &p_kel) ) {
    u4_noun bec = p_kel;

    return _mate_warx(m, bec);
  }
  else {
    u4_err(lane, "kel", kel);
    return u4_trip;
  }
}
