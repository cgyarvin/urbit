/* mill/poke.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _poke_crib()::
*/
static u4_noun
_poke_crib(u4_milr m,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_noun p_tip)
{
  u4_lane lane    = m->lane;
  u4_noun ip_tip  = u4_ch(p_tip);
  u4_term pip_tip = u4_ch(ip_tip);
  u4_type qip_tip = u4_ct(ip_tip);
  u4_noun tp_tip  = u4_ct(p_tip);

  if ( u4_n_zero(tp_tip) ) {
    return u4_k_cell
        (lane, u4_k_cell
                (lane, pip_tip, 
                       _mill_poke(m, axe, gan, bar, qip_tip)),
               u4_noun_0);
  }
  else {
    u4_axis sud = u4_op_tip(axe);
    u4_axis hec = u4_op_tap(lane, axe);
    u4_rail fub = _mill_slip(m, sud, bar);

    if ( u4_n_eq(u4_noun_2, sud) ) {
      return u4_k_cell
        (lane, u4_k_cell
                (lane, pip_tip,
                       _mill_poke(m, hec, gan, fub, qip_tip)),
               tp_tip);
    } else {
      return u4_k_cell
        (lane, ip_tip, 
               _poke_crib(m, hec, gan, fub, tp_tip));
    }
  }
}

/* _mill_poke(): modify type to reflect poke assignment, if any.
*/
u4_type
_mill_poke(u4_milr m,
           u4_axis axe,
           u4_type gan,
           u4_rail bar,
           u4_type tip)
{
  u4_lane lane = m->lane;

  if ( u4_n_eq(u4_noun_1, axe) ) {
    return gan;
  } 
  else {
    u4_noun p_tip, q_tip;

    // %atom
    // %blot
    // %blur
    //
    if ( u4_n_eq(u4_atom_atom, tip) ||
         u4_n_eq(u4_atom_blur, tip) )
    {
      // This is generally a case of user misbehavior.
      //
      return u4_atom_blur;
    }

    // <%crib p={list ~[(term) (type)]}>
    //
    if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
      return u4_k_cell
        (lane, u4_atom_crib, 
               _poke_crib(m, axe, gan, bar, p_tip));
    }

    // <%cell p=(type) q=(type)>
    //
    else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
      u4_axis sud = u4_op_tip(axe);
      u4_axis hec = u4_op_tap(lane, axe);
      u4_rail fub = _mill_slip(m, sud, bar);

      if ( u4_n_eq(u4_noun_2, sud) ) {
        return u4_k_trel
          (lane, u4_atom_cell, _mill_poke(m, hec, gan, fub, p_tip), q_tip);
      } else {
        return u4_k_trel
          (lane, u4_atom_cell, p_tip, _mill_poke(m, hec, gan, fub, q_tip));
      }
    }

    // <%cone p=(type) q={bush term type}>
    //
    else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
      u4_axis sud = u4_op_tip(axe);
      u4_axis hec = u4_op_tap(lane, axe);
      u4_rail fub = _mill_slip(m, sud, bar);

      if ( u4_n_eq(u4_noun_2, sud) ) {
        // XX: insert safety here.
        //
        return u4_k_trel
          (lane, u4_atom_cone, _mill_poke(m, hec, gan, fub, p_tip), q_tip);
      } else {
        // User has truly screwed the pooch.  Very unorthodox and
        // sketchy behavior.  Do not encourage.
        //
        return u4_atom_blur;
      }
    }

    // <%cube p=*>
    // 
    else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
      // Further bad behavior by user.
      //
      return u4_atom_blur;
    }

    // <%fork p=(type) q=(type)>
    //
    else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
      if ( _mill_cull(m, bar, p_tip) ) {
        return _mill_poke(m, axe, gan, bar, q_tip);
      }
      else if ( _mill_cull(m, bar, q_tip) ) {
        return _mill_poke(m, axe, gan, bar, p_tip);
      }
      else {
        return _mill_eith
          (m, _mill_poke(m, axe, gan, bar, p_tip),
              _mill_poke(m, axe, gan, bar, q_tip));
      }
    }

    // <%fuse p=(type) q=(type)>
    //
    else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
      return _mill_both
        (m, _mill_poke(m, axe, gan, bar, p_tip), 
            _mill_poke(m, axe, gan, u4_k_cell(lane, p_tip, bar), q_tip));
    }

    // <%gate p=(type) q=(gene)>
    //
    else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
      return _mill_poke(m, axe, gan, bar, _mill_repo(m, p_tip, q_tip));
    }
    else return u4_trip;
  }
}
