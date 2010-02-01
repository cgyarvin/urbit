/* mill/turn.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _turn_crib(): adjust crib to reflect grip assignment, if any.
*/
static u4_noun
_turn_crib(u4_milr m,
           u4_term cox,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_noun p_tip)
{
  u4_lane lane = m->lane;
  u4_noun ip_tip = u4_ch(p_tip);
  u4_noun tp_tip = u4_ct(p_tip);
  u4_term pip_tip = u4_ch(ip_tip);
  u4_type qip_tip = u4_ct(ip_tip);

  if ( u4_n_zero(tp_tip) ) {
    if ( u4_n_eq(cox, pip_tip) ) {
      return gan;
    }
    else {
      u4_assert(u4_n_zero(pip_tip));

      return u4_k_cell
        (lane, u4_k_cell
                (lane, pip_tip, 
                       _mill_turn(m, cox, axe, gan, bar, qip_tip)),
               u4_noun_0);
    }
  }
  else {
    u4_assert(!u4_n_eq(u4_noun_1, axe));

    if ( u4_n_eq(cox, pip_tip) ) {
      u4_assert(u4_n_eq(u4_noun_2, axe));

      return u4_k_cell
        (lane, u4_k_cell(lane, pip_tip, gan), tp_tip);
    }
    else {
      u4_assert(u4_n_eq(u4_noun_3, u4_op_tip(axe)));

      return u4_k_cell
        (lane, ip_tip,
               _turn_crib
                (m, cox, 
                    u4_op_tap(lane, axe), 
                    gan, 
                    _mill_slip(m, u4_noun_3, bar), 
                    tp_tip));
    }
  }
}

/* _turn_fuse(): adjust fuse to reflect grip assignment, if any.
*/
static u4_type
_turn_fuse(u4_milr m,
           u4_term cox,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_type p_tip,
           u4_type q_tip)
{
  u4_lane lane = m->lane;
  u4_rail dax  = u4_k_cell(lane, p_tip, bar);
  u4_loaf guf  = _mill_find(m, cox, dax, q_tip);

  if ( u4_n_zero(guf) ) {
    u4_type heb = _mill_turn(m, cox, axe, gan, bar, p_tip);

    return _mill_both(m, heb, _mill_poke(m, axe, gan, dax, q_tip));
  }
  else {
    u4_type cud = _mill_turn(m, cox, axe, gan, dax, q_tip);
    u4_loaf bav = _mill_find(m, cox, dax, p_tip);

    if ( !u4_n_zero(bav) ) {
      u4_axis pug;

      if ( u4_b_p(u4_ct(bav), u4_noun_0, &pug) && 
           u4_n_eq(pug, axe) )
      {
        return _mill_both(m, u4_ch(bav), cud);
      }
    }
    return _mill_both(m, _mill_poke(m, axe, gan, bar, p_tip), cud);
  }
}

/* _mill_turn(): write by name, with axe as guide.
*/
u4_type
_mill_turn(u4_milr m,
           u4_term cox,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  // %atom
  // 
  if ( u4_n_eq(u4_atom_atom, tip) ) {
    return _mill_fail(m, "turn: poke crash a");
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
    /* this is a policy decision - type can be lost.
    */
    return tip;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  else if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
    return u4_k_cell
      (lane, u4_atom_crib, _turn_crib(m, cox, axe, gan, bar, p_tip));
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
    u4_axis sud = u4_op_tip(axe);
    u4_axis hec = u4_op_tap(lane, axe);
    u4_rail vug = _mill_slip(m, sud, bar);

    if ( u4_n_eq(u4_noun_2, sud) ) {
      return u4_k_trel
        (lane, u4_atom_cell,
               _mill_turn(m, cox, hec, gan, vug, p_tip),
               q_tip);
    } else {
      return u4_k_trel
        (lane, u4_atom_cell,
               p_tip,
               _mill_turn(m, cox, hec, gan, vug, q_tip));
    }
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
    // XX: safety!
    //
    return u4_k_trel
      (lane, u4_atom_cone,
             _mill_turn
                (m, cox, 
                    u4_op_tap(lane, axe), 
                    gan, 
                    _mill_slip(m, u4_noun_2, bar), 
                    p_tip),
             q_tip);
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return _mill_fail(m, "turn: poke crash b");
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    if ( _mill_cull(m, bar, p_tip) ) {
      return _mill_turn(m, cox, axe, gan, bar, q_tip);
    }
    else if ( _mill_cull(m, bar, q_tip) ) {
      return _mill_turn(m, cox, axe, gan, bar, p_tip);
    }
    else {
      return _mill_eith
        (m, _mill_turn(m, cox, axe, gan, bar, p_tip),
            _mill_turn(m, cox, axe, gan, bar, q_tip));
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return _turn_fuse
      (m, cox, axe, gan, bar, p_tip, q_tip);
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    return _mill_turn(m, cox, axe, gan, bar, _mill_repo(m, p_tip, q_tip));
  }

  else return u4_trip;
}
