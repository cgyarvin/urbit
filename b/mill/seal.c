/* mill/seal.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

    /** Forward declarations.
    **/
      static u4_bag
      _seal_main(u4_milr, u4_bag, u4_type);


/* _seal_main(): as _mill_seal(), with gil.
*/
static u4_loaf
_seal_main(u4_milr m,
           u4_bag  gil,
           u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  // %atom
  // %blur
  //
  if ( u4_n_eq(u4_atom_atom, typ) ||
       u4_n_eq(u4_atom_blur, typ) ||
       u4_n_eq(u4_atom_blot, typ) ) 
  {
    return u4_noun_0;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  else if ( u4_b_p(typ, u4_atom_crib, &p_typ) ) {
    return _seal_main(m, gil, _mill_reap(m, typ));
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
    return u4_bag_cat(lane, _seal_main(m, gil, p_typ),
                            _seal_main(m, gil, q_typ));
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(typ, u4_atom_cone, &p_typ, &q_typ) ) {
    return _seal_main(m, gil, p_typ);
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
    return u4_noun_0;
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
    return u4_bag_cat(lane, _seal_main(m, gil, p_typ),
                            _seal_main(m, gil, q_typ));
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
    return u4_bag_cat(lane, _seal_main(m, gil, p_typ),
                            _seal_main(m, gil, q_typ));
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) ) {
    if ( u4_bag_in(typ, gil) ) {
      return u4_k_trel(lane, typ, u4_noun_0, u4_noun_0);
    } 
    else {
      return _seal_main
        (m, u4_bag_add(lane, typ, gil),
            _mill_repo(m, p_typ, q_typ));
    }
  }

  // [%wing p=axis q=type]
  //
  else if ( u4_b_pq(typ, u4_atom_wing, &p_typ, &q_typ) ) {
    return _seal_main(m, gil, q_typ);
  }

  else {
    u4_bug("strange type", typ);
    return u4_trip;
  }
}

/* _mill_seal(): produce set of gates sealing [typ].
*/
u4_bag
_mill_seal(u4_milr m,
           u4_type typ)
{
  return _seal_main(m, u4_noun_0, typ);
}
