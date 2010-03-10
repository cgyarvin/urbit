/* mill/nest.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

  /** Forward declarations.
  **/
    static u4_t _nest_main(u4_milr, u4_bag, u4_rail, u4_mold, u4_mold);


/* _nest_atom(): congruence iff bead.
*/
static u4_t
_nest_atom(u4_milr m,
           u4_bag  hax,
           u4_rail meg,
           u4_mold gan)
{
  u4_lane lane = m->lane;
  u4_noun p_gan, q_gan;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, gan) ) {
    return u4_true;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, gan) ) {
    return u4_false;
  }

  // [%cell p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_cell, &p_gan, &q_gan) ) {
    return u4_false;
  }

  // [%cone p=mold q=bush+[term mold]]
  //
  else if ( u4_b_pq(gan, u4_atom_cone, &p_gan, &q_gan) ) {
    return u4_false;
  }

  // [%cube p=noun]
  // 
  else if ( u4_b_p(gan, u4_atom_cube, &p_gan) ) {
    if ( u4_n_atom(p_gan) ) {
      return u4_true;
    }
    else return u4_false;
  }

  // [%face p=mark q=mold]
  //
  if ( u4_b_pq(gan, u4_atom_face, &p_gan, &q_gan) ) {
    return _nest_atom(m, hax, meg, q_gan);
  }

  // [%fork p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fork, &p_gan, &q_gan) ) {
    return ( (_mill_cull(m, meg, p_gan) || _nest_atom(m, hax, meg, p_gan)) &&
             (_mill_cull(m, meg, q_gan) || _nest_atom(m, hax, meg, q_gan)) );
  }

  // [%fuse p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fuse, &p_gan, &q_gan) ) {
    return _nest_atom(m, hax, meg, p_gan) ||
           _nest_atom(m, hax, u4_k_cell(lane, p_gan, meg), q_gan);
  }

  // [%hold p=mold q=gene]
  //
  else if ( u4_b_pq(gan, u4_atom_hold, &p_gan, &q_gan) ) {
    u4_noun dit = u4_k_cell(lane, meg, gan);

    if ( u4_bag_in(dit, hax) ) {
      return 1;
    } else {
      return _nest_atom(m, u4_bag_add(lane, dit, hax), 
                           meg, 
                           _mill_repo(m, p_gan, q_gan));
    }
  }
  else return u4_trip;
}

/* _nest_plum(): congruence for atomic constant.
*/
static u4_t
_nest_plum(u4_milr m,
           u4_bag  hax,
           u4_noun p_typ,
           u4_rail meg,
           u4_mold gan)
{
  u4_lane lane = m->lane;
  u4_noun p_gan, q_gan;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, gan) ) {
    return u4_false;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, gan) ) {
    return u4_false;
  }

  // [%cell p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_cell, &p_gan, &q_gan) ) {
    return u4_false;
  }

  // [%cone p=mold q=bush+[term mold]]
  //
  else if ( u4_b_pq(gan, u4_atom_cone, &p_gan, &q_gan) ) {
    return u4_false;
  }

  // [%cube p=noun]
  // 
  else if ( u4_b_p(gan, u4_atom_cube, &p_gan) ) {
    return u4_n_eq(p_typ, p_gan);
  }

  // [%face p=mark q=mold]
  //
  if ( u4_b_pq(gan, u4_atom_face, &p_gan, &q_gan) ) {
    return _nest_plum(m, hax, p_typ, meg, q_gan);
  }

  // [%fork p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fork, &p_gan, &q_gan) ) {
    return ( ( _mill_cull(m, meg, p_gan) || 
               _nest_plum(m, hax, p_typ, meg, p_gan) ) &&
             ( _mill_cull(m, meg, q_gan) || 
               _nest_plum(m, hax, p_typ, meg, q_gan) ) );
  }

  // [%fuse p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fuse, &p_gan, &q_gan) ) {
    return _nest_plum(m, hax, p_typ, meg, p_gan) ||
           _nest_plum(m, hax, p_typ, u4_k_cell(lane, p_gan, meg), q_gan);
  }

  // [%hold p=mold q=gene]
  //
  else if ( u4_b_pq(gan, u4_atom_hold, &p_gan, &q_gan) ) {
    u4_noun dit = u4_k_cell(lane, meg, gan);

    if ( u4_bag_in(dit, hax) ) {
      return 1;
    } else {
      return _nest_plum(m, u4_bag_add(lane, dit, hax), 
                           p_typ,
                           meg, 
                           _mill_repo(m, p_gan, q_gan));
    }
  }
  else return u4_trip;
}

/* _nest_cell(): congruence for cell.
*/
static u4_t
_nest_cell(u4_milr m,
           u4_bag  gil,
           u4_bag  hax,
           u4_mold p_typ,
           u4_mold q_typ,
           u4_rail meg,
           u4_mold gan)
{
  u4_lane lane = m->lane;
  u4_noun p_gan, q_gan;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, gan) ) {
    return u4_false;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, gan) ) {
    return u4_false;
  }

  // [%cell p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_cell, &p_gan, &q_gan) ) {
    return _nest_main(m, gil, _mill_slip(m, u4_noun_2, meg), p_gan, p_typ) &&
           _nest_main(m, gil, _mill_slip(m, u4_noun_3, meg), q_gan, q_typ);
  }

  // [%cone p=mold q=bush+[term mold]]
  //
  else if ( u4_b_pq(gan, u4_atom_cone, &p_gan, &q_gan) ) {
    // Daring and unorthodox - but not impossibly useful.
    //
    return _nest_main(m, gil, _mill_slip(m, u4_noun_2, meg), p_gan, p_typ) &&
           _nest_main(m, gil, u4_noun_0, u4_atom_blur, q_typ);
  }

  // [%cube p=noun]
  // 
  else if ( u4_b_p(gan, u4_atom_cube, &p_gan) ) {
    if ( u4_n_atom(p_gan) ) {
      return u4_false;
    } else {
      return _nest_cell(m, gil, hax, p_typ, q_typ, meg, _mill_reap(m, gan));
    }
  }

  // [%face p=mark q=mold]
  //
  if ( u4_b_pq(gan, u4_atom_face, &p_gan, &q_gan) ) {
    return _nest_cell(m, gil, hax, p_typ, q_typ, meg, q_gan);
  }

  // [%fork p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fork, &p_gan, &q_gan) ) {
    return ( ( _mill_cull(m, meg, p_gan) || 
               _nest_cell(m, gil, hax, p_typ, q_typ, meg, p_gan) ) &&
             ( _mill_cull(m, meg, q_gan) || 
               _nest_cell(m, gil, hax, p_typ, q_typ, meg, q_gan) ) );
  }

  // [%fuse p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fuse, &p_gan, &q_gan) ) {
    return _nest_cell(m, gil, hax, p_typ, q_typ, meg, p_gan) ||
           _nest_cell(m, gil, hax, p_typ, 
                                   q_typ, 
                                   u4_k_cell(lane, p_gan, meg), 
                                   q_gan);
  }

  // [%hold p=mold q=gene]
  //
  else if ( u4_b_pq(gan, u4_atom_hold, &p_gan, &q_gan) ) {
    u4_noun dit = u4_k_cell(lane, meg, gan);

    if ( u4_bag_in(dit, hax) ) {
      return 1;
    } else {
      return _nest_cell(m, gil, u4_bag_add(lane, dit, hax), 
                                p_typ,
                                q_typ, 
                                meg, 
                                _mill_repo(m, p_gan, q_gan));
    }
  }
  else return u4_trip;
}

/* _nest_cone(): congruence for cone.
*/
static u4_t
_nest_cone(u4_milr m,
           u4_bag  gil,
           u4_bag  hax,
           u4_mold p_typ,
           u4_noun q_typ,
           u4_rail meg,
           u4_mold gan)
{
  u4_lane lane = m->lane;
  u4_noun p_gan, q_gan;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, gan) ) {
    return u4_false;
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, gan) ) {
    return u4_false;
  }

  // [%cell p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_cell, &p_gan, &q_gan) ) {
    return u4_false;
  }

  // [%cone p=mold q=bush+[term mold]]
  //
  else if ( u4_b_pq(gan, u4_atom_cone, &p_gan, &q_gan) ) {
    return _nest_main(m, gil, _mill_slip(m, u4_noun_2, meg), p_gan, p_typ) &&
           u4_n_eq(q_typ, q_gan);
  }

  // [%cube p=noun]
  // 
  else if ( u4_b_p(gan, u4_atom_cube, &p_gan) ) {
    return u4_false;
  }

  // [%face p=mark q=mold]
  //
  if ( u4_b_pq(gan, u4_atom_face, &p_gan, &q_gan) ) {
    return _nest_cone(m, gil, hax, p_typ, q_typ, meg, q_gan);
  }

  // [%fork p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fork, &p_gan, &q_gan) ) {
    return ( ( _mill_cull(m, meg, p_gan) || 
               _nest_cone(m, gil, hax, p_typ, q_typ, meg, p_gan) ) &&
             ( _mill_cull(m, meg, q_gan) || 
               _nest_cone(m, gil, hax, p_typ, q_typ, meg, q_gan) ) );
  }

  // [%fuse p=mold q=mold]
  //
  else if ( u4_b_pq(gan, u4_atom_fuse, &p_gan, &q_gan) ) {
    return _nest_cone(m, gil, hax, p_typ, q_typ, meg, p_gan) ||
           _nest_cone(m, gil, hax, p_typ, 
                                   q_typ, 
                                   u4_k_cell(lane, p_gan, meg), 
                                   q_gan);
  }

  // [%hold p=mold q=gene]
  //
  else if ( u4_b_pq(gan, u4_atom_hold, &p_gan, &q_gan) ) {
    u4_noun dit = u4_k_cell(lane, meg, gan);

    if ( u4_bag_in(dit, hax) ) {
      return 1;
    } else {
      return _nest_cone(m, gil, u4_bag_add(lane, dit, hax), 
                                p_typ,
                                q_typ, 
                                meg, 
                                _mill_repo(m, p_gan, q_gan));
    }
  }
  else return u4_trip;
}

/* _nest_fork_row(): congruence for each.
*/
static u4_t
_nest_fork_row(u4_milr m,
               u4_bag  gil,
               u4_rail meg,
               u4_mold i_vig,
               u4_log  lec)
{
  while ( !u4_n_zero(lec) ) {
    u4_mold i_lec = u4_ch(lec);
    {
      if ( _nest_main(m, gil, meg, i_vig, i_lec) ) {
        return 1;
      }
    }
    lec = u4_ct(lec);
  }
  return 0;
}

/* _nest_fork_square(): congruence across.
*/
static u4_t
_nest_fork_square(u4_milr m,
                  u4_bag  gil,
                  u4_rail meg,
                  u4_log  vig,
                  u4_log  lec)
{
  while ( !u4_n_zero(vig) ) {
    u4_mold i_vig = u4_ch(vig);
    {
      if ( !_nest_fork_row(m, gil, meg, i_vig, lec) ) {
        return 0;
      }
      vig = u4_ct(vig);
    }
  }
  return 1;
}

/* _nest_forks(): accumulate fork-tree leaves.
*/
static u4_log
_nest_forks(u4_milr m,
            u4_log  hoc,
            u4_bag  lut,
            u4_mold gav)
{
  u4_lane lane = m->lane;
  u4_noun p_gav, q_gav;

  if ( u4_n_atom(gav) || 
       u4_b_pq(gav,  u4_atom_cell, &p_gav, &q_gav) ||
       u4_b_pq(gav,  u4_atom_cone, &p_gav, &q_gav) ||
       u4_b_p(gav,   u4_atom_cube, &p_gav) ||
       u4_b_pq(gav,  u4_atom_fuse, &p_gav, &q_gav) )
  {
    return u4_k_cell(lane, gav, hoc);
  }
  else if ( u4_b_pq(gav, u4_atom_face, &p_gav, &q_gav) ) {
    return _nest_forks(m, hoc, lut, q_gav);
  }
  else if ( u4_b_pq(gav, u4_atom_fork, &p_gav, &q_gav) ) {
    return _nest_forks(m, _nest_forks(m, hoc, lut, p_gav), lut, q_gav);
  }
  else if ( u4_b_pq(gav, u4_atom_hold, &p_gav, &q_gav) ) {
    if ( u4_bag_in(gav, lut) ) {
      return hoc;
    }
    else {
      lut = u4_bag_add(lane, gav, lut);

      return _nest_forks(m, hoc, lut, _mill_repo(m, p_gav, q_gav));
    }
  }
  else return u4_trip;
}

/* _nest_main(): geometric congruence, with loop control (gil).
*/
static u4_t
_nest_main(u4_milr m,
           u4_bag  gil,
           u4_rail meg,
           u4_mold gan,
           u4_mold typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  // u4_burp(lane, "nm: gan", _mill_dump(m, gan));
  // u4_burp(lane, "nm: typ", _mill_dump(m, typ));

  // %atom
  // 
  if ( u4_n_eq(u4_atom_atom, typ) ) {
    return _nest_atom(m, u4_noun_0, meg, gan);
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, typ) ) {
    return 1;
  }

  // [%cell p=mold q=mold]
  //
  else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
    return _nest_cell(m, gil, u4_noun_0, p_typ, q_typ, meg, gan);
  }

  // [%cone p=mold q=bush+[term mold]]
  //
  else if ( u4_b_pq(typ, u4_atom_cone, &p_typ, &q_typ) ) {
    return _nest_cone(m, gil, u4_noun_0, p_typ, q_typ, meg, gan);
  }

  // [%cube p=noun]
  // 
  else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
    if ( u4_n_cell(p_typ) ) {
      return _nest_main(m, gil, meg, gan, _mill_reap(m, typ));
    }
    else {
      return _nest_plum(m, u4_noun_0, p_typ, meg, gan);
    }
  }

  // [%face p=mark q=mold]
  //
  if ( u4_b_pq(typ, u4_atom_face, &p_typ, &q_typ) ) {
    return _nest_main(m, gil, meg, gan, q_typ);
  }

  // [%fork p=mold q=mold]
  //
  else if ( u4_b_pq(typ, u4_atom_fork, 0, 0) ) {
    u4_log vig = _nest_forks(m, u4_noun_0, u4_noun_0, gan);
    u4_log lec = _nest_forks(m, u4_noun_0, u4_noun_0, typ);

    /* Frankly and unabashedly conservative.  O(n^2), too.
    */
    return _nest_fork_square(m, gil, meg, vig, lec);
  }

  // [%fuse p=mold q=mold]
  //
  else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
    return _nest_main(m, gil, meg, gan, p_typ) &&
           _nest_main(m, gil, meg, gan, q_typ);
  }

  // [%hold p=mold q=gene]
  //
  else if ( u4_b_pq(typ, u4_atom_hold, &p_typ, &q_typ) ) {
    u4_noun res = u4_k_cell(lane, gan, typ);

    if ( u4_bag_in(res, gil) ) {
      /* Conservative search.
      */
      return 1;
    }
    else {
      gil = u4_bag_add(lane, res, gil);

      return _nest_main(m, gil, meg, gan, _mill_repo(m, p_typ, q_typ));
    }
  }

  else return u4_trip;
}

/* _mill_nest(): test geometric congruence.
**
**    [gan] is geometrically congruent with [typ] iff 
**    every noun in [gan] is also in [typ].  Ie: [gan] <: mold.
*/
u4_t
_mill_nest(u4_milr m,
           u4_mold gan,
           u4_mold typ)
{
  if ( u4_n_eq(gan, typ) ) {
    // XX: a property of the algorithm that should be 
    // checked, not assumed.
    //
    return 1;
  }
  else if ( _mill_null(m, gan) ) {
    printf("null gan\n");
    return 1;
  }
  else if ( _mill_null(m, typ) ) {
    return 0;
  }
  else {
    u4_noun qof = u4_k_cell(m->lane, gan, typ);
    u4_nopt zod = u4_tab_get(qof, m->vus);

    if ( zod != u4_bull ) {
      return u4_n_zero(zod);
    }
    else {
      u4_t t_zod = _nest_main(m, u4_noun_0, u4_noun_0, gan, typ);

      zod = (t_zod ? u4_noun_0 : u4_noun_1);

      m->vus = u4_tab_add(m->lane, qof, zod, m->vus);
      return t_zod;
    }
  }
}
