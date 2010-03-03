/* mill/burn.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _burn_crib()::
*/
static u4_noun
_burn_crib(u4_milr m,
           u4_axis axe,
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
                       _mill_burn(m, axe, bar, qip_tip)),
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
                       _mill_burn(m, hec, fub, qip_tip)),
               tp_tip);
    } else {
      return u4_k_cell
        (lane, ip_tip, 
               _burn_crib(m, hec, fub, tp_tip));
    }
  }
}

/* _mill_burn(): modify type to destroy all information at (axe).
*/
u4_type
_mill_burn(u4_milr m,
           u4_axis axe,
           u4_rail bar,
           u4_type tip)
{
  u4_lane lane = m->lane;

  if ( u4_n_eq(u4_noun_1, axe) ) {
    return u4_atom_blur;
  } 
  else {
    // %atom, %blur, %blot
    //
    if ( u4_n_atom(tip) ) {
      return u4_atom_blur;
    }

    // <%cell p=(type) q=(type)>
    //
    else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
      u4_axis sud = u4_op_tip(axe);
      u4_axis hec = u4_op_tap(lane, axe);
      u4_rail fub = _mill_slip(m, sud, bar);

      if ( u4_n_eq(u4_noun_2, sud) ) {
        return u4_k_trel
          (lane, u4_atom_cell, _mill_burn(m, hec, fub, p_tip), q_tip);
      } else {
        return u4_k_trel
          (lane, u4_atom_cell, p_tip, _mill_burn(m, hec, fub, q_tip));
      }
    }

    // <%crib p={list ~[(term) (type)]}>
    //
    if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
      return u4_k_cell
        (lane, u4_atom_crib, _burn_crib(m, axe, bar, p_tip));
    }

    // <%cone p=(type) q={bush term type}>
    //
    else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
      // I don't believe this can actually be invoked.  If it is,
      // though, it is clearly user error.
      //
      return _mill_fail(m, "cone burn");
    }

    // <%cube p=*>
    // 
    else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
      return u4_atom_blur;
    }

    // <%fork p=(type) q=(type)>
    //
    else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
      if ( _mill_cull(m, bar, p_tip) ) {
        return _mill_burn(m, axe, bar, q_tip);
      }
      else if ( _mill_cull(m, bar, q_tip) ) {
        return _mill_burn(m, axe, bar, p_tip);
      }
      else {
        return _mill_eith
          (m, _mill_burn(m, axe, bar, p_tip),
              _mill_burn(m, axe, bar, q_tip));
      }
    }

    // <%fuse p=(type) q=(type)>
    //
    else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
      return _mill_both
        (m, _mill_burn(m, axe, bar, p_tip), 
            _mill_burn(m, axe, u4_k_cell(lane, p_tip, bar), q_tip));
    }

    // <%gate p=(type) q=(gene)>
    //
    else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
      u4_noun buz = _mill_repo(m, p_tip, q_tip);
      u4_noun zel = _mill_burn(m, axe, bar, buz);

      if ( u4_n_eq(zel, buz) ) {
        return tip;
      }
      else return zel;
    }

    // [%wing p=axis q=type]
    //
    else if ( u4_b_pq(tip, u4_atom_wing, &p_tip, &q_tip) ) {
      u4_nopt pan = u4_op_pan(lane, axe, p_tip);

      if ( u4_bull == pan ) {
        return tip;
      }
      else {
        if ( u4_n_eq(u4_noun_1, u4_ch(pan)) ) {
          return u4_atom_blur;
        }
        else {
          return _mill_sail(
      }
    }

    else return u4_trip;
  }
}
