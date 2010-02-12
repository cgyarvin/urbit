/* mill/snap.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

    /** Forward declarations.
    **/
      static u4_type
      _snap_main(u4_milr, u4_bag, u4_rail, u4_type, u4_rail, u4_type);

/* _snap_crib_crib(): as _mill_snap(), for crib on crib.
*/
static u4_rope
_snap_crib_crib(u4_milr m,
                u4_bag  gil,
                u4_rail meg,
                u4_rope p_gan,
                u4_rail bar,
                u4_rope p_tip)
{
  u4_lane lane    = m->lane;
  u4_hair ip_gan  = u4_ch(p_gan);
  u4_term pip_gan = u4_ch(ip_gan);
  u4_type qip_gan = u4_ct(ip_gan);
  u4_rope tp_gan  = u4_ct(p_gan);
  u4_hair ip_tip  = u4_ch(p_tip);
  u4_term pip_tip = u4_ch(ip_tip);
  u4_type qip_tip = u4_ct(ip_tip);
  u4_rope tp_tip  = u4_ct(p_tip);

  if ( u4_n_zero(tp_tip) ) {
    if ( !u4_n_zero(tp_gan) ) {
      u4_type gan = u4_k_cell(lane, u4_atom_crib, p_gan);

      return u4_k_cell
        (lane, u4_k_cell
                 (lane, pip_tip, 
                        _snap_main(m, gil, meg, gan, bar, qip_tip)),
               u4_noun_0);
    }
    else {
      u4_term tir;
      
      tir = (u4_n_zero(pip_tip) && !u4_n_zero(pip_gan)) ? pip_gan : pip_tip;

      return u4_k_cell(lane, u4_k_cell(lane, tir, qip_tip), u4_noun_0);
    }
  }
  else {
    if ( u4_n_zero(tp_gan) ) {
      // Definitely not user's day.
      //
      return p_tip;
    }
    else {
      u4_term tir;
      u4_type huz;

      tir = (u4_n_zero(pip_tip) && !u4_n_zero(pip_gan)) ? pip_gan : pip_tip;
      huz = _snap_main(m, gil, 
                          _mill_slip(m, u4_noun_2, meg),
                          qip_gan,
                          _mill_slip(m, u4_noun_2, bar),
                          qip_tip);
     
      return u4_k_cell
        (lane, u4_k_cell(lane, tir, huz), 
               _snap_crib_crib
                  (m, gil,
                      _mill_slip(m, u4_noun_3, meg),
                      tp_gan,
                      _mill_slip(m, u4_noun_3, bar),
                      tp_tip));
    }
  }
}

/* _snap_crib(): as _mill_snap(), within crib.
*/
static u4_rope
_snap_crib(u4_milr m,
           u4_bag  gil,
           u4_bag  lum,
           u4_rail meg,
           u4_type gan,
           u4_rail bar,
           u4_rope p_tip)
{
  u4_lane lane = m->lane;
  u4_noun p_gan, q_gan;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, gan) ) {
    return p_tip;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, gan) ) {
    return p_tip;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  if ( u4_b_p(gan, u4_atom_crib, &p_gan) ) {
    return _snap_crib_crib(m, gil, meg, p_gan, bar, p_tip);
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(gan, u4_atom_cell, &p_gan, &q_gan) ) {
    return _snap_crib_crib
      (m, gil, meg, 
               u4_k_trel(lane, p_gan, q_gan, u4_noun_0),
               bar,
               p_tip);
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(gan, u4_atom_cone, &p_gan, &q_gan) ) {
    // User completely out of his gourd.
    //
    return p_tip;
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(gan, u4_atom_cube, &p_gan) ) {
    return p_tip;
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(gan, u4_atom_fork, &p_gan, &q_gan) ) {
    if ( _mill_cull(m, meg, p_gan) ) {
      return _snap_crib(m, gil, lum, meg, q_gan, bar, p_tip);
    }
    else if ( _mill_cull(m, meg, q_gan) ) {
      return _snap_crib(m, gil, lum, meg, p_gan, bar, p_tip);
    } 
    else {
      u4_rope hus = _snap_crib(m, gil, lum, meg, p_gan, bar, p_tip);
      u4_rope sel = _snap_crib(m, gil, lum, meg, q_gan, bar, p_tip);

      if ( u4_n_eq(hus, sel) ) {
        return hus;
      } else {
        return _mill_fail(m, "snap: fork conflict");
      }
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(gan, u4_atom_fuse, &p_gan, &q_gan) ) {
    u4_rail loz = u4_k_cell(lane, p_gan, meg);
    u4_rope bup = _snap_crib(m, gil, lum, loz, q_gan, bar, p_tip);

    return _snap_crib(m, gil, lum, meg, p_gan, bar, bup);
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(gan, u4_atom_gate, &p_gan, &q_gan) ) {
    if ( u4_bag_in(gan, lum) ) {
      return p_tip;
    }
    else {
      u4_type yot = _mill_repo(m, p_gan, q_gan);

      return _snap_crib
        (m, gil, u4_bag_add(lane, gan, lum), meg, yot, bar, p_tip);
    }
  }

  else return u4_trip;
}

/* _snap_main(): as _mill_snap(), with rails and bag.
*/
static u4_type
_snap_main(u4_milr m,
           u4_bag  gil,
           u4_rail meg,
           u4_type gan,
           u4_rail bar,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, tip) ) {
    return tip;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
    return tip;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
    return u4_k_cell
      (lane,
       u4_atom_crib,
       _snap_crib(m, gil, u4_noun_0, meg, gan, bar, p_tip));
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
    return u4_k_cell
      (lane,
       u4_atom_crib,
       _snap_crib
         (m, gil, u4_noun_0, 
                  meg, 
                  gan, 
                  bar, 
                  u4_k_trel(lane, p_tip, q_tip, u4_noun_0)));
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
    return tip;
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return tip;
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    if ( _mill_cull(m, bar, p_tip) ) {
      return _snap_main(m, gil, meg, gan, bar, q_tip);
    }
    else if ( _mill_cull(m, bar, q_tip) ) {
      return _snap_main(m, gil, meg, gan, bar, p_tip);
    }
    else { 
      return _mill_eith
        (m, _snap_main(m, gil, meg, gan, bar, p_tip),
            _snap_main(m, gil, meg, gan, bar, q_tip));
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return _mill_both
      (m, _snap_main(m, gil, meg, gan, bar, p_tip),
          _snap_main(m, gil, meg, gan, u4_k_cell(lane, p_tip, bar), q_tip));
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    u4_noun res = u4_k_cell
      (lane, u4_k_cell(lane, meg, gan), 
             u4_k_cell(lane, bar, tip));

    if ( u4_bag_in(res, gil) ) {
      /* Conservative search.
      */
      return tip;
    }
    else {
      u4_type hef = _mill_repo(m, p_tip, q_tip);
      u4_type ved;

      gil = u4_bag_add(lane, res, gil);
      ved = _snap_main(m, gil, meg, gan, bar, hef);

      if ( u4_n_eq(ved, hef) ) {
        return tip;
      }
      else return ved;
    }
  }

  else return u4_trip;
}

/* _mill_snap(): adjust tip for assignment into gan.
*/
u4_type
_mill_snap(u4_milr m,
           u4_type gan,
           u4_type tip)
{
  return _snap_main(m, u4_noun_0, u4_noun_0, gan, u4_noun_0, tip);
}
