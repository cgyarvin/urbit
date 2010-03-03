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
                u4_rope p_wod,
                u4_rail bar,
                u4_rope p_sug)
{
  u4_lane lane    = m->lane;
  u4_hair ip_wod  = u4_ch(p_wod);
  u4_term pip_wod = u4_ch(ip_wod);
  u4_type qip_wod = u4_ct(ip_wod);
  u4_rope tp_wod  = u4_ct(p_wod);
  u4_hair ip_sug  = u4_ch(p_sug);
  u4_term pip_sug = u4_ch(ip_sug);
  u4_type qip_sug = u4_ct(ip_sug);
  u4_rope tp_sug  = u4_ct(p_sug);

  if ( u4_n_zero(tp_sug) ) {
    if ( !u4_n_zero(tp_wod) ) {
      u4_type wod = u4_k_cell(lane, u4_atom_crib, p_wod);

      return u4_k_cell
        (lane, u4_k_cell
                 (lane, pip_sug, 
                        _snap_main(m, gil, meg, wod, bar, qip_sug)),
               u4_noun_0);
    }
    else {
      u4_term tir;
      
      tir = (u4_n_zero(pip_sug) && !u4_n_zero(pip_wod)) ? pip_wod : pip_sug;

      return u4_k_cell(lane, u4_k_cell(lane, tir, qip_sug), u4_noun_0);
    }
  }
  else {
    if ( u4_n_zero(tp_wod) ) {
      // Definitely not user's day.
      //
      return p_sug;
    }
    else {
      u4_term tir;
      u4_type huz;

      tir = (u4_n_zero(pip_sug) && !u4_n_zero(pip_wod)) ? pip_wod : pip_sug;
      huz = _snap_main(m, gil, 
                          _mill_slip(m, u4_noun_2, meg),
                          qip_wod,
                          _mill_slip(m, u4_noun_2, bar),
                          qip_sug);
     
      return u4_k_cell
        (lane, u4_k_cell(lane, tir, huz), 
               _snap_crib_crib
                  (m, gil,
                      _mill_slip(m, u4_noun_3, meg),
                      tp_wod,
                      _mill_slip(m, u4_noun_3, bar),
                      tp_sug));
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
           u4_type wod,
           u4_rail bar,
           u4_rope p_sug)
{
  u4_lane lane = m->lane;
  u4_noun p_wod, q_wod;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, wod) ) {
    return p_sug;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, wod) ) {
    return p_sug;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  if ( u4_b_p(wod, u4_atom_crib, &p_wod) ) {
    return _snap_crib_crib(m, gil, meg, p_wod, bar, p_sug);
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(wod, u4_atom_cell, &p_wod, &q_wod) ) {
    return _snap_crib_crib
      (m, gil, meg, 
               u4_k_trel(lane, p_wod, q_wod, u4_noun_0),
               bar,
               p_sug);
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(wod, u4_atom_cone, &p_wod, &q_wod) ) {
    // User completely out of his gourd.
    //
    return p_sug;
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(wod, u4_atom_cube, &p_wod) ) {
    return p_sug;
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(wod, u4_atom_fork, &p_wod, &q_wod) ) {
    if ( _mill_cull(m, meg, p_wod) ) {
      return _snap_crib(m, gil, lum, meg, q_wod, bar, p_sug);
    }
    else if ( _mill_cull(m, meg, q_wod) ) {
      return _snap_crib(m, gil, lum, meg, p_wod, bar, p_sug);
    } 
    else {
      u4_rope hus = _snap_crib(m, gil, lum, meg, p_wod, bar, p_sug);
      u4_rope sel = _snap_crib(m, gil, lum, meg, q_wod, bar, p_sug);

      if ( u4_n_eq(hus, sel) ) {
        return hus;
      } else {
        return _mill_fail(m, "snap: fork conflict");
      }
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(wod, u4_atom_fuse, &p_wod, &q_wod) ) {
    u4_rail loz = u4_k_cell(lane, p_wod, meg);
    u4_rope bup = _snap_crib(m, gil, lum, loz, q_wod, bar, p_sug);

    return _snap_crib(m, gil, lum, meg, p_wod, bar, bup);
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(wod, u4_atom_gate, &p_wod, &q_wod) ) {
    if ( u4_bag_in(wod, lum) ) {
      return p_sug;
    }
    else {
      u4_type yot = _mill_repo(m, p_wod, q_wod);

      return _snap_crib
        (m, gil, u4_bag_add(lane, wod, lum), meg, yot, bar, p_sug);
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
           u4_type wod,
           u4_rail bar,
           u4_type sug)
{
  u4_lane lane = m->lane;
  u4_noun p_sug, q_sug;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, sug) ) {
    return sug;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, sug) ) {
    return sug;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  if ( u4_b_p(sug, u4_atom_crib, &p_sug) ) {
    return u4_k_cell
      (lane,
       u4_atom_crib,
       _snap_crib(m, gil, u4_noun_0, meg, wod, bar, p_sug));
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(sug, u4_atom_cell, &p_sug, &q_sug) ) {
    return u4_k_cell
      (lane,
       u4_atom_crib,
       _snap_crib
         (m, gil, u4_noun_0, 
                  meg, 
                  wod, 
                  bar, 
                  u4_k_trel
                    (lane, u4_k_cell(lane, u4_noun_0, p_sug), 
                           u4_k_cell(lane, u4_noun_0, q_sug), 
                           u4_noun_0)));
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(sug, u4_atom_cone, &p_sug, &q_sug) ) {
    return sug;
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(sug, u4_atom_cube, &p_sug) ) {
    return sug;
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(sug, u4_atom_fork, &p_sug, &q_sug) ) {
    if ( _mill_cull(m, bar, p_sug) ) {
      return _snap_main(m, gil, meg, wod, bar, q_sug);
    }
    else if ( _mill_cull(m, bar, q_sug) ) {
      return _snap_main(m, gil, meg, wod, bar, p_sug);
    }
    else { 
      return _mill_eith
        (m, _snap_main(m, gil, meg, wod, bar, p_sug),
            _snap_main(m, gil, meg, wod, bar, q_sug));
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(sug, u4_atom_fuse, &p_sug, &q_sug) ) {
    return _mill_both
      (m, _snap_main(m, gil, meg, wod, bar, p_sug),
          _snap_main(m, gil, meg, wod, u4_k_cell(lane, p_sug, bar), q_sug));
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(sug, u4_atom_gate, &p_sug, &q_sug) ) {
    u4_noun res = u4_k_cell
      (lane, u4_k_cell(lane, meg, wod), 
             u4_k_cell(lane, bar, sug));

    if ( u4_bag_in(res, gil) ) {
      /* Conservative search.
      */
      return sug;
    }
    else {
      u4_type hef = _mill_repo(m, p_sug, q_sug);
      u4_type ved;

      gil = u4_bag_add(lane, res, gil);
      ved = _snap_main(m, gil, meg, wod, bar, hef);

      if ( u4_n_eq(ved, hef) ) {
        return sug;
      }
      else return ved;
    }
  }

  // [%wing p=axis q=type]
  //
  else if ( u4_b_pq(sug, u4_atom_wing, &p_sug, &q_sug) ) {
    return _snap_main(m, gil, meg, wod, bar, _mill_reap(m, sug));
  }
  else return u4_trip;
}

/* _mill_snap(): adjust sug for assignment into wod.
*/
u4_type
_mill_snap(u4_milr m,
           u4_type wod,
           u4_type sug)
{
  u4_type mel;

  if ( !u4_n_zero(m->rux) ) {
    printf("\n\n");
    u4_burp(m->lane, "wod", _mill_dump(m, wod));
    u4_burp(m->lane, "sug", _mill_dump(m, sug));
  }

  if ( _mill_nest(m, wod, sug) && _mill_nest(m, sug, wod) ) {
    if ( !u4_n_zero(m->rux) ) {
      u4_burp(m->lane, "zox", _mill_dump(m, wod));
    }
    return wod;
  }
  else {
    mel = _snap_main(m, u4_noun_0, u4_noun_0, wod, u4_noun_0, sug);

    if ( !u4_n_zero(m->rux) ) {
      u4_burp(m->lane, "mel", _mill_dump(m, mel));
    }
    return mel;
  }
}
