/* _cong_flat(): forb atomicity, with background (raf).
*/
static u4_t
_cong_flat(u4_milr m,
           u4_bag  vit,
           u4_log  raf,
           u4_type tip)
{
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_blot, tip) ) {
    return 1;
  }
  else if ( u4_n_eq(u4_atom_atom, tip) ) {
    return 1;
  }
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
    return 0;
  }
  else if ( u4_b_pq(tip, u4_atom_bone, &p_tip, &q_tip) ) {
    return 0;
  }
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return u4_n_atom(p_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return ( (_mill_cull(m, p_tip, raf) || _cong_flat(m, vit, raf, p_tip)) &&
             (_mill_cull(m, q_tip, raf) || _cong_flat(m, vit, raf, q_tip)) );
  }
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return _cong_flat(m, vit, raf, p_tip) ||
           _cong_flat(m, vit, u4_k_cell(m->lane, p_tip, raf), q_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    u4_type laf = _mill_pull(m, raf, tip);

    if ( u4_bag_in(laf, vit) ) {
      return 1;
    }
    else {
      u4_type vaz;

      // printf("\n");
      // u4_burp(m->lane, "cf: type", _mill_dump(m, p_tip));
      // u4_burp(m->lane, "cf: gene", u4_pump_prep(m->lane, q_tip));

      vaz = _mill_repo(m, p_tip, q_tip);
      // u4_burp(m->lane, "cf: repo", _mill_dump(m, vaz));

      return _cong_flat(m, u4_bag_add(m->lane, laf, vit), raf, vaz);
    }
  }
  else return _cong_flat(m, vit, raf, _mill_reap(m, tip));
} 

/* _cong_deep(): forb non-atomicity, with background (raf).
*/
static u4_t
_cong_deep(u4_milr m,
           u4_bag  vit,
           u4_log  raf,
           u4_type tip)
{
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_blot, tip) ) {
    return 1;
  }
  else if ( u4_n_eq(u4_atom_atom, tip) ) {
    return 0;
  }
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
    return 0;
  }
  else if ( u4_b_pq(tip, u4_atom_bone, &p_tip, &q_tip) ) {
    return 1;
  }
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return !u4_n_atom(p_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return ( (_mill_cull(m, p_tip, raf) || _cong_deep(m, vit, raf, p_tip)) &&
             (_mill_cull(m, q_tip, raf) || _cong_deep(m, vit, raf, q_tip)) );
  }
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return _cong_deep(m, vit, raf, p_tip) ||
           _cong_deep(m, vit, u4_k_cell(m->lane, p_tip, raf), q_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    u4_type laf = _mill_pull(m, raf, tip);

    if ( u4_bag_in(laf, vit) ) {
      return 1;
    }
    else {
      return _cong_deep
        (m, u4_bag_add(m->lane, laf, vit), raf, _mill_repo(m, p_tip, q_tip));
    }
  }
  else return _cong_deep(m, vit, raf, _mill_reap(m, tip));
} 

/* _cong_leaf(): constant forb.
*/
static u4_t
_cong_leaf(u4_milr m,
           u4_bag  vit,
           u4_log  raf,
           u4_atom p_gan,
           u4_type tip)
{
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_blot, tip) ) {
    return 1;
  }
  else if ( u4_n_eq(u4_atom_atom, tip) ) {
    return 0;
  }
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
    return 0;
  }
  else if ( u4_b_pq(tip, u4_atom_bone, &p_tip, &q_tip) ) {
    return 0;
  }
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return u4_n_eq(p_gan, p_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return ( ( _mill_cull(m, p_tip, raf) || 
               _cong_leaf(m, vit, raf, p_gan, p_tip)
             ) &&
             ( _mill_cull(m, q_tip, raf) || 
               _cong_leaf(m, vit, raf, p_gan, q_tip)
             ) );
  }
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    return _cong_leaf(m, vit, raf, p_gan, p_tip) ||
           _cong_leaf(m, vit, u4_k_cell(m->lane, p_tip, raf), p_gan, q_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    u4_type laf = _mill_pull(m, raf, tip);

    if ( u4_bag_in(laf, vit) ) {
      return 1;
    }
    else {
      vit = u4_bag_add(m->lane, laf, vit);
      return _cong_leaf(m, vit, raf, p_gan, _mill_repo(m, p_tip, q_tip));
    }
  }
  else return _cong_leaf(m, vit, raf, p_gan, _mill_reap(m, tip));
}

/* _cong_bone(): congruence to bone.
*/
static u4_t
_cong_bone(u4_milr m,
           u4_bag  gil,
           u4_axis p_gan,
           u4_type q_gan,
           u4_type tip)
{
  if ( u4_n_eq(u4_atom_blot, tip) ) {
    return 1;
  }
  else if ( u4_n_eq(u4_noun_1, p_gan) ) {
    return _cong_main(m, gil, q_gan, tip);
  }
  else {
    if ( !_cong_deep(m, u4_noun_0, u4_noun_0, tip) ) {
      return 0;
    }
    else {
      u4_axis wex = u4_op_tip(p_gan);
      u4_axis hir = u4_op_tap(m->lane, p_gan);
      u4_type fug = _mill_hack(m, wex, tip);

      return _cong_bone(m, gil, hir, q_gan, fug);
    }
  }
}

/* _cong_cone(): congruence to cone; fop is background.
*/
static u4_t
_cong_cone(u4_milr m,
           u4_bag  gil,
           u4_bag  vit,
           u4_type p_gan,
           u4_type q_gan,
           u4_type tip,
           u4_log  fop)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_blot, tip) ) {
    return 1;
  }
  else if (  u4_n_atom(tip) || u4_b_pq(tip, u4_atom_bone, &p_tip, &q_tip) ) {
    return 0;
  }
  else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
    u4_type nac = _mill_pull(m, _mill_slip(m, u4_noun_2, fop), p_tip);

    return (u4_n_eq(q_gan, q_tip) && _cong_main(m, gil, p_gan, nac));
  }
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return
      ( (_mill_cull(m, p_tip, fop) || 
         _cong_cone(m, gil, vit, p_gan, q_gan, p_tip, fop)) &&
        (_mill_cull(m, q_tip, fop) ||
         _cong_cone(m, gil, vit, p_gan, q_gan, q_tip, fop)) );
  }
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    u4_log dov = u4_k_cell(lane, p_tip, fop);

    return
      ( _cong_cone(m, gil, vit, p_gan, q_gan, p_tip, fop) ||
        _cong_cone(m, gil, vit, p_gan, q_gan, q_tip, dov) );
  }
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    u4_type laf = _mill_pull(m, fop, tip);

    if ( u4_bag_in(laf, vit) ) {
      return 1;
    }
    else {
      vit = u4_bag_add(m->lane, laf, vit);
      return _cong_cone
        (m, gil, vit, p_gan, q_gan, _mill_repo(m, p_tip, q_tip), fop);
    }
  }
  else {
    return _cong_cone(m, gil, vit, p_gan, q_gan, _mill_reap(m, tip), fop);
  }
}

/* _cong_skin(): congruence to skin; fop is background.
*/
static u4_t
_cong_skin(u4_milr m,
           u4_bag  gil,
           u4_bag  vit,
           u4_term p_gan,
           u4_type q_gan,
           u4_type tip,
           u4_log  fop)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_blot, tip) ) {
    return 1;
  }
  else if ( u4_n_atom(tip) || 
       u4_b_pq(tip, u4_atom_bone, &p_tip, &q_tip) ||
       u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) )
  {
    return 0;
  }
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return
      ( (_mill_cull(m, p_tip, fop) || 
         _cong_skin(m, gil, vit, p_gan, q_gan, p_tip, fop)) &&
        (_mill_cull(m, q_tip, fop) ||
         _cong_skin(m, gil, vit, p_gan, q_gan, q_tip, fop)) );
  }
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    u4_log dov = u4_k_cell(lane, p_tip, fop);

    return
      ( _cong_skin(m, gil, vit, p_gan, q_gan, p_tip, fop) ||
        _cong_skin(m, gil, vit, p_gan, q_gan, q_tip, dov) );
  }
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    u4_type laf = _mill_pull(m, fop, tip);

    if ( u4_bag_in(laf, vit) ) {
      return 1;
    }
    else {
      vit = u4_bag_add(m->lane, laf, vit);
      return _cong_skin
        (m, gil, vit, p_gan, q_gan, _mill_repo(m, p_tip, q_tip), fop);
    }
  }
  else if ( u4_b_pq(tip, u4_atom_skin, &p_tip, &q_tip) ) {
    u4_type ros = _mill_pull(m, fop, q_tip);

    return (u4_n_eq(p_gan, p_tip) && _cong_main(m, gil, q_gan, ros));
  }
  else {
    return _cong_skin(m, gil, vit, p_gan, q_gan, _mill_reap(m, tip), fop);
  }
}

/* _cong_forks(): lhs.
*/
static u4_log
_cong_forks(u4_milr m,
            u4_bag  lut,
            u4_type gav)
{
  u4_lane lane = m->lane;
  u4_noun p_gav, q_gav;

  if ( u4_n_atom(gav) || 
       u4_b_pq(gav,  u4_atom_bone, &p_gav, &q_gav) ||
       u4_b_pq(gav,  u4_atom_cone, &p_gav, &q_gav) ||
       u4_b_p(gav,   u4_atom_cube, &p_gav) ||
       u4_b_pq(gav,  u4_atom_fuse, &p_gav, &q_gav) )
  {
    if ( u4_n_eq(u4_atom_blot, gav) ) {
      return u4_trip;
    }
    return u4_k_cell(lane, gav, u4_noun_0);
  }
  else if ( u4_b_pq(gav, u4_atom_fork, &p_gav, &q_gav) ) {
    u4_log juk = _cong_forks(m, lut, p_gav);
    u4_log ryd = _cong_forks(m, lut, q_gav);

    return u4_log_cat(lane, juk, ryd);
  }
  else if ( u4_b_pq(gav, u4_atom_gate, &p_gav, &q_gav) ) {
    if ( u4_bag_in(gav, lut) ) {
      return u4_noun_0;
    }
    else {
      lut = u4_bag_add(lane, gav, lut);

      return _cong_forks(m, lut, _mill_repo(m, p_gav, q_gav));
    }
  }
  else {
    return _cong_forks(m, lut, _mill_reap(m, gav));
  }
}


/* _cong_fork_row(): congruence for each.
*/
static u4_t
_cong_fork_row(u4_milr m,
               u4_bag  gil,
               u4_log  gal,
               u4_type i_hef)
{
  while ( !u4_n_zero(gal) ) {
    u4_type i_gal = u4_ch(gal);
    {
      if ( _cong_main(m, gil, i_gal, i_hef) ) {
        return 1;
      }
    }
    gal = u4_ct(gal);
  }
  return 0;
}

/* _cong_fork_square(): congruence across.
*/
static u4_t
_cong_fork_square(u4_milr m,
                  u4_bag gil,
                  u4_log gal,
                  u4_log hef)
{
  while ( !u4_n_zero(hef) ) {
    u4_type i_hef = u4_ch(hef);
    {
      if ( !_cong_fork_row(m, gil, gal, i_hef) ) {
        return 0;
      }
      hef = u4_ct(hef);
    }
  }
  return 1;
}

