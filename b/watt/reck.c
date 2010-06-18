/* watt/reck.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* nuke:reck:bach:pitt
*/
  static u4_tack
  _reck_nuke(u4_pitt, u4_type, u4_tack, u4_rope, u4_type);
 
  static u4_tack
  _reck_nuke_port(u4_pitt p,
                  u4_type sub,
                  u4_tack tac,
                  u4_rope rop,
                  u4_type feg,
                  u4_term gos,
                  u4_axis wam,
                  u4_type gur)
  {
    u4_lane lan = p->lane;

    if ( u4_n_eq(u4_noun_1, wam) ) {
      return u4_k_trel
        (lan, u4_atom_name,
              gos,
              _reck_nuke(p, gur, tac, rop, feg));
    }
    else {
      u4_axis tip = u4_op_tip(wam);
      u4_axis tap = u4_op_tap(wam);

      if ( u4_n_eq(u4_noun_2, tip) ) {
        return u4_k_trel
          (lan, 
           u4_atom_pair,
           _reck_nuke_port(p, sub, tac, rop, feg, gos, tap, gur),
           u4_noun_0);
      }
      else {
        return u4_k_trel
          (lan, 
           u4_atom_pair,
           u4_noun_0,
           _reck_nuke_port(p, sub, tac, rop, feg, gos, tap, gur));
      }
    }
  }

  static u4_tack
  _reck_nuke_frag(u4_pitt p,
                  u4_type sub,
                  u4_tack tac,
                  u4_rope rop,
                  u4_type feg,
                  u4_axis wam,
                  u4_type gur)
  {
    if ( u4_n_eq(u4_noun_1, wam) ) {
      return _reck_nuke(p, gur, tac, rop, feg);
    }
    else {
      u4_axis tip = u4_op_tip(wam);
      u4_axis tap = u4_op_tap(wam);

      if ( u4_n_eq(u4_noun_2, tip) ) {
        return u4_k_trel
          (lan, 
           u4_atom_pair,
           _reck_nuke_frag(p, sub, tac, rop, feg, tap, gur),
           u4_noun_0);
      }
      else {
        return u4_k_trel
          (lan, 
           u4_atom_pair,
           u4_noun_0,
           _reck_nuke_frag(p, sub, tac, rop, feg, tap, gur));
      }
    }
  }
static u4_tack
_reck_nuke(u4_pitt p,
           u4_type sub,
           u4_tack tac,
           u4_rope rop,
           u4_type feg)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(rop) ) {
    return u4_k_cell(lan, u4_atom_leaf, feg);
  }
  else {
    u4_cord i_rop = u4_ch(rop);
    u4_rope t_rop = u4_ct(rop);
    u4_noun pi_rop;

    if ( u4_n_atom(i_rop) ) {
      return _reck_nuke
        (p, sub, 
            tac, 
            u4_k_cell(lan, u4_k_cell(lan, u4_atom_port, rop), t_rop));
    }
    else if ( u4_b_pq(i_rop, u4_atom_core, &pi_rop) ) {
      return _reck_nuke
        (p, sub, 
            tac, 
            u4_k_cell(lan, u4_k_cell(lan, u4_atom_port, pi_rop), t_rop));
    }
    else if ( u4_b_pq(i_rop, u4_atom_port, &pi_rop) ) {
      u4_plan lar = _bach_find(p, sub, pi_rop);
      u4_axis p_lar = u4_ch(lar);
      u4_type r_lar = u4_ct(u4_ct(lar));

      return _reck_nuke_port(p, sub, tac, t_rop, feg, pi_rop, p_lar, r_lar);
    }
    else if ( u4_b_pq(i_rop, u4_atom_frag, &pi_rop) ) {
      u4_type gur = _bach_peek(p, sub, pi_rop);

      return _reck_nuke_frag(p, sub, tac, t_rop, feg, pi_rop, gur); 
    }
  }
}

/* cram:reck:bach:pitt
*/
static u4_tack
_reck_cram(u4_pitt p,
           u4_type sub,
           u4_tack tac,
           u4_tack les)
{
  u4_lane lan = p->lan;
  u4_noun p_tac, q_tac, p_les, q_les;

  if ( u4_n_zero(tac) ) {
    return les;
  }
  else if ( u4_n_zero(les) ) {
    return tac;
  }
  else if ( u4_b_pq(tac, u4_atom_name, &p_tac, &q_tac) ) {
    if ( !u4_b_pq(les, u4_atom_name, &p_les, &q_les) ||
         !u4_n_eq(p_tac, p_les) )
    {
      return _pitt_fail(p, "cram crash");
    }
    else return u4_k_trel
      (lan, u4_atom_name,
            p_tac,
            _reck_cram(p, sub, q_tac, q_les));
  }
  else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
    if ( !u4_b_pq(les, u4_atom_pair, &p_les, &q_les) ) {
      return _pitt_fail(p, "cram crash");
    }
    else return u4_k_trel
      (lan, u4_atom_pair,
            _reck_cram(p, sub, p_tac, p_les),
            _reck_cram(p, sub, q_tac, q_les));
  }
  else return _pitt_fail(p, "cram crash");
}

/* feed:reck:bach:pitt
*/
static u4_tack
_reck_feed(u4_pitt p,
           u4_type sub,
           u4_tack tac,
           u4_list mut)
{
  if ( u4_n_zero(mut) ) {
    return u4_noun_0;
  }
  else {
    u4_noun i_mut  = u4_ch(mut);
    u4_list t_mut  = u4_ct(mut);
    u4_gene pi_mut = u4_ch(i_mut);
    u4_type qi_mut = u4_ct(i_mut);
    u4_rope rop    = _pitt_rake(p, pi_mut);
    u4_tack bur    = _reck_nuke(p, sub, tac, rop, qi_mut);

    return _reck_feed
      (p, sub, _reck_cram(p, sub, tac, bur), t_mut);
  }
}

/* dull:reck:bach:pitt
*/
static u4_tack
_reck_dull(u4_pitt p,
           u4_type sub,
           u4_tack tac)
{
  u4_lane lan = p->lan;
  u4_noun p_tac, q_tac;

  if ( u4_n_zero(tac) ) {
    return tac;
  } else if ( u4_b_p(tac, u4_atom_leaf, &p_tac) ) {
    return u4_k_cell(lan, u4_atom_leaf, u4_atom_blur);
  } else if ( u4_b_pq(tac, u4_atom_name, &p_tac, &q_tac) ) {
    return u4_k_trel(lan, u4_atom_name, p_tac, _reck_dull(p, sub, q_tac));
  } else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
    return u4_k_trel
      (lan, 
       u4_atom_pair,
       _reck_dull(p, sub, p_tac),
       _reck_dull(p, sub, q_tac));
  }
}
