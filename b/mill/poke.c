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
           u4_type hur,
           u4_rail bar,
           u4_noun p_wac)
{
  u4_lane lane    = m->lane;
  u4_noun ip_wac  = u4_ch(p_wac);
  u4_term pip_wac = u4_ch(ip_wac);
  u4_type qip_wac = u4_ct(ip_wac);
  u4_noun tp_wac  = u4_ct(p_wac);

  if ( u4_n_zero(tp_wac) ) {
    return u4_k_cell
        (lane, u4_k_cell
                (lane, pip_wac, 
                       _mill_poke(m, axe, hur, bar, qip_wac)),
               u4_noun_0);
  }
  else {
    u4_axis sud = u4_op_tip(axe);
    u4_axis hec = u4_op_tap(lane, axe);
    u4_rail fub = _mill_slip(m, sud, bar);

    if ( u4_n_eq(u4_noun_2, sud) ) {
      return u4_k_cell
        (lane, u4_k_cell
                (lane, pip_wac,
                       _mill_poke(m, hec, hur, fub, qip_wac)),
               tp_wac);
    } else {
      return u4_k_cell
        (lane, ip_wac, 
               _poke_crib(m, hec, hur, fub, tp_wac));
    }
  }
}

/* _mill_poke(): modify type to reflect poke assignment, if any.
*/
u4_type
_mill_poke(u4_milr m,
           u4_axis axe,
           u4_type hur,
           u4_rail bar,
           u4_type wac)
{
  u4_lane lane = m->lane;
  u4_axis sud = u4_op_tip(axe);
  u4_axis hec = u4_op_tap(lane, axe);

  if ( u4_n_eq(u4_noun_1, axe) ) {
    return hur;
  } 
  else {
    u4_noun p_wac, q_wac;

    // %atom
    // %blot
    // %blur
    //
    if ( u4_n_eq(u4_atom_atom, wac) ||
         u4_n_eq(u4_atom_blur, wac) )
    {
      // This is generally a case of user misbehavior.
      //
      return u4_atom_blur;
    }

    // <%crib p={list ~[(term) (type)]}>
    //
    if ( u4_b_p(wac, u4_atom_crib, &p_wac) ) {
      return u4_k_cell
        (lane, u4_atom_crib, 
               _poke_crib(m, axe, hur, bar, p_wac));
    }

    // <%cell p=(type) q=(type)>
    //
    else if ( u4_b_pq(wac, u4_atom_cell, &p_wac, &q_wac) ) {
      u4_rail fub = _mill_slip(m, sud, bar);

      if ( u4_n_eq(u4_noun_2, sud) ) {
        return u4_k_trel
          (lane, u4_atom_cell, _mill_poke(m, hec, hur, fub, p_wac), q_wac);
      } else {
        return u4_k_trel
          (lane, u4_atom_cell, p_wac, _mill_poke(m, hec, hur, fub, q_wac));
      }
    }

    // <%cone p=(type) q={bush term type}>
    //
    else if ( u4_b_pq(wac, u4_atom_cone, &p_wac, &q_wac) ) {
#if 0
      u4_rail fub = _mill_slip(m, sud, bar);

      if ( u4_n_eq(u4_noun_2, sud) ) {
        // XX: insert safety here.
        //
        return u4_k_trel
          (lane, u4_atom_cone, _mill_poke(m, hec, hur, fub, p_wac), q_wac);
      } else {
        return _mill_fail(m, "code poke");
      }
#else
      u4_burp(lane, "hur", _mill_dump(m, hur));
      return _mill_fail(m, "cone poke");
#endif
    }

    // <%cube p=*>
    // 
    else if ( u4_b_p(wac, u4_atom_cube, &p_wac) ) {
      // Further bad behavior by user.
      //
      return u4_atom_blur;
    }

    // <%fork p=(type) q=(type)>
    //
    else if ( u4_b_pq(wac, u4_atom_fork, &p_wac, &q_wac) ) {
      if ( _mill_cull(m, bar, p_wac) ) {
        return _mill_poke(m, axe, hur, bar, q_wac);
      }
      else if ( _mill_cull(m, bar, q_wac) ) {
        return _mill_poke(m, axe, hur, bar, p_wac);
      }
      else {
        return _mill_eith
          (m, _mill_poke(m, axe, hur, bar, p_wac),
              _mill_poke(m, axe, hur, bar, q_wac));
      }
    }

    // <%fuse p=(type) q=(type)>
    //
    else if ( u4_b_pq(wac, u4_atom_fuse, &p_wac, &q_wac) ) {
      return _mill_both
        (m, _mill_poke(m, axe, u4_atom_blur, bar, p_wac), 
            _mill_poke(m, axe, hur, u4_k_cell(lane, p_wac, bar), q_wac));
    }

    // <%gate p=(type) q=(gene)>
    //
    else if ( u4_b_pq(wac, u4_atom_gate, &p_wac, &q_wac) ) {
      return _mill_poke(m, axe, hur, bar, _mill_repo(m, p_wac, q_wac));
    }

    // [%wing p=axis q=type]
    //
    else if ( u4_b_pq(wac, u4_atom_wing, &p_wac, &q_wac) ) {
      if ( !u4_n_eq(sud, u4_op_tip(p_wac)) ) {
        return wac;
      }
      else {
        u4_rail fub = _mill_slip(m, sud, bar);
        u4_axis nod = u4_op_tap(lane, p_wac);
        u4_type vem, sig;

        if ( u4_n_eq(u4_noun_1, nod) ) {
          vem = q_wac;
        } else {
          vem = u4_k_trel(lane, u4_atom_wing, nod, q_wac);
        }
        sig = _mill_poke(m, hec, hur, fub, vem);

        return _mill_sail(m, sud, sig);
      }
    }
    else return u4_trip;
  }
}
