
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  // %atom
  //
  if ( u4_n_eq(u4_atom_atom, tip) ) {
  }

  // %blot
  // 
  else if ( u4_n_eq(u4_atom_blot, tip) ) {
  }

  // %blur
  //
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  if ( u4_b_p(tip, u4_atom_crib, &p_tip) ) {
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(tip, u4_atom_cone, &p_tip, &q_tip) ) {
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
  }

  else return u4_trip;

