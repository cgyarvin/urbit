/* mill/turn.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _turn_crib(): adjust crib to refslat grip assignment, if any.
*/
static u4_noun
_turn_crib(u4_milr m,
           u4_term cox,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_noun p_typ)
{
  u4_lane lane = m->lane;
  u4_noun ip_typ = u4_ch(p_typ);
  u4_noun tp_typ = u4_ct(p_typ);
  u4_term pip_typ = u4_ch(ip_typ);
  u4_type qip_typ = u4_ct(ip_typ);

  // printf("\n\n");
  // u4_err(lane, "crib: cox", cox);
  // u4_err(lane, "crib: axe", axe);
  // u4_burp(lane, "crib: gan", _mill_dump(m, gan));
  // u4_burp(lane, "crib: typ", _mill_dump(m, u4_k_cell(lane, u4_atom_crib, p_typ)));

  if ( u4_n_eq(u4_noun_1, axe) ) {
    u4_assert(u4_n_zero(tp_typ));
    u4_assert(u4_n_eq(cox, pip_typ));

    return u4_k_cell(lane, u4_k_cell(lane, cox, gan), u4_noun_0);
  }
  else {
    if ( u4_n_zero(tp_typ) ) {
      u4_assert(u4_n_zero(pip_typ));

      return u4_k_cell
        (lane, u4_k_cell
                (lane, u4_noun_0, 
                       _mill_turn(m, cox, axe, gan, bar, qip_typ)),
               u4_noun_0);
    }
    else {
      u4_axis hem = u4_op_tip(axe);
      u4_axis gor = u4_op_tap(lane, axe);

      bar = _mill_slip(m, hem, bar);

      if ( u4_n_eq(u4_noun_2, hem) ) {
        if ( u4_n_zero(pip_typ) ) {
          return u4_k_cell
            (lane, u4_k_cell
                    (lane, u4_noun_0,
                           _mill_turn(m, cox, gor, gan, bar, qip_typ)),
                   tp_typ);
        }
        else {
          u4_assert(u4_n_eq(cox, pip_typ));
          u4_assert(u4_n_eq(u4_noun_1, gor));

          return u4_k_cell
            (lane, u4_k_cell(lane, pip_typ, gan),
                   tp_typ);
        }
      }
      else {
        return u4_k_cell
          (lane, ip_typ,
                 _turn_crib(m, cox, gor, gan, bar, tp_typ));
      }
    }
  }
}

/* _turn_fuse(): adjust fuse to refslat grip assignment, if any.
*/
static u4_type
_turn_fuse(u4_milr m,
           u4_term cox,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_type p_typ,
           u4_type q_typ)
{
  u4_lane lane = m->lane;
  u4_rail dax  = u4_k_cell(lane, p_typ, bar);
  u4_loaf guf  = _mill_find(m, cox, dax, q_typ);

  if ( u4_n_zero(guf) ) {
    u4_type heb = _mill_turn(m, cox, axe, gan, bar, p_typ);

    return _mill_both(m, heb, _mill_poke(m, axe, gan, dax, q_typ));
  }
  else {
    u4_type cud = _mill_turn(m, cox, axe, gan, dax, q_typ);
    u4_loaf bav = _mill_find(m, cox, dax, p_typ);

    if ( !u4_n_zero(bav) ) {
      u4_axis pug;

      if ( u4_b_p(u4_ct(bav), u4_noun_0, &pug) && 
           u4_n_eq(pug, axe) )
      {
        return _mill_both(m, u4_ch(bav), cud);
      }
    }
    return _mill_both(m, _mill_poke(m, axe, gan, bar, p_typ), cud);
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
           u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  // %atom
  // 
  if ( u4_n_eq(u4_atom_atom, typ) ) {
    return _mill_fail(m, "turn: poke crash a");
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, typ) ) {
    /* this is a policy decision - type can be lost.
    */
    return typ;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  else if ( u4_b_p(typ, u4_atom_crib, &p_typ) ) {
    return u4_k_cell
      (lane, u4_atom_crib, _turn_crib(m, cox, axe, gan, bar, p_typ));
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
    u4_axis sud = u4_op_tip(axe);
    u4_axis hec = u4_op_tap(lane, axe);
    u4_rail vug = _mill_slip(m, sud, bar);

    if ( u4_n_eq(u4_noun_2, sud) ) {
      return u4_k_trel
        (lane, u4_atom_cell,
               _mill_turn(m, cox, hec, gan, vug, p_typ),
               q_typ);
    } else {
      return u4_k_trel
        (lane, u4_atom_cell,
               p_typ,
               _mill_turn(m, cox, hec, gan, vug, q_typ));
    }
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(typ, u4_atom_cone, &p_typ, &q_typ) ) {
    // XX: safety!
    //
    return u4_k_trel
      (lane, u4_atom_cone,
             _mill_turn
                (m, cox, 
                    u4_op_tap(lane, axe), 
                    gan, 
                    _mill_slip(m, u4_noun_2, bar), 
                    p_typ),
             q_typ);
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
    return _mill_fail(m, "turn: poke crash b");
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
    if ( _mill_cull(m, bar, p_typ) ) {
      return _mill_turn(m, cox, axe, gan, bar, q_typ);
    }
    else if ( _mill_cull(m, bar, q_typ) ) {
      return _mill_turn(m, cox, axe, gan, bar, p_typ);
    }
    else {
      return _mill_eith
        (m, _mill_turn(m, cox, axe, gan, bar, p_typ),
            _mill_turn(m, cox, axe, gan, bar, q_typ));
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
    return _turn_fuse
      (m, cox, axe, gan, bar, p_typ, q_typ);
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) ) {
    return _mill_turn(m, cox, axe, gan, bar, _mill_repo(m, p_typ, q_typ));
  }

  else {
    u4_err(lane, "typ", typ);
    // u4_burp(lane, "typ", _mill_dump(m, typ));
    return u4_trip;
  }
}
