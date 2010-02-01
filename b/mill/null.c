/* mill/null.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

  /** Forward declarations.
  **/
    static u4_t _null_orth(u4_milr, u4_bag, u4_bag, u4_type, u4_type);
    static u4_t _null_main(u4_milr, u4_bag, u4_type);

/* _null_orth_plum(): as _null_orth(), for atomic cube.
*/
static u4_t
_null_orth_plum(u4_milr m,
                u4_bag  ham, 
                u4_bag  cal,
                u4_atom pp_tip,
                u4_type q_tip)
{
  u4_lane lane = m->lane;
  u4_noun pq_tip, qq_tip;

  if ( u4_n_eq(u4_atom_atom, q_tip) ) {
    return u4_false;
  }

  else if ( u4_n_eq(u4_atom_blur, q_tip) ) {
    return u4_false;
  }

  else if ( u4_b_pq(q_tip, u4_atom_cell, &pq_tip, &qq_tip) ) {
    return u4_true;
  }

  else if ( u4_b_p(q_tip, u4_atom_cube, &pq_tip) ) {
    if ( u4_n_atom(pq_tip) ) {
      return u4_false;
    } 
    else return u4_true;
  }

  else if ( u4_b_pq(q_tip, u4_atom_fork, &pq_tip, &qq_tip) ) {
    return ( _null_main(m, ham, pq_tip) ||
             _null_orth_plum(m, ham, cal, pp_tip, pq_tip) ) &&
           ( _null_main(m, ham, qq_tip) ||
             _null_orth_plum(m, ham, cal, pp_tip, qq_tip) );
  }

  else if ( u4_b_pq(q_tip, u4_atom_fuse, &pq_tip, &qq_tip) ) {
    return _null_orth_plum(m, ham, cal, pp_tip, pq_tip) ||
           _null_orth_plum(m, ham, cal, pp_tip, qq_tip);
  }

  else if ( u4_b_pq(q_tip, u4_atom_gate, &pq_tip, &qq_tip) ) {
    u4_noun p_tip = u4_k_cell(lane, u4_atom_cube, pp_tip);
    u4_noun fum   = u4_k_cell(lane, p_tip, q_tip);

    if ( u4_bag_in(fum, cal) ) {
      return 1;
    }
    else {
      return _null_orth_plum
        (m, ham, 
            u4_bag_add(lane, fum, cal), 
            pp_tip,
            _mill_repo(m, pq_tip, qq_tip));
    }
  }
  else return _null_orth_plum(m, ham, cal, pp_tip, _mill_reap(m, q_tip));
}

/* _null_orth_atom(): as _null_orth(), for bead.
*/
static u4_t
_null_orth_atom(u4_milr m,
                u4_bag  ham,
                u4_bag  cal,
                u4_type q_tip)
{
  u4_lane lane = m->lane;
  u4_noun pq_tip, qq_tip;

  if ( u4_n_eq(u4_atom_atom, q_tip) ) {
    return u4_false;
  }

  else if ( u4_n_eq(u4_atom_blur, q_tip) ) {
    return u4_false;
  }

  else if ( u4_b_pq(q_tip, u4_atom_cell, &pq_tip, &qq_tip) ) {
    return u4_true;
  }

  else if ( u4_b_p(q_tip, u4_atom_cube, &pq_tip) ) {
    if ( u4_n_atom(pq_tip) ) {
      return u4_false;
    } 
    else return u4_true;
  }

  else if ( u4_b_pq(q_tip, u4_atom_fork, &pq_tip, &qq_tip) ) {
    return ( _null_main(m, ham, pq_tip) ||
             _null_orth_atom(m, ham, cal, pq_tip) ) &&
           ( _null_main(m, ham, qq_tip) ||
             _null_orth_atom(m, ham, cal, qq_tip) );
  }

  else if ( u4_b_pq(q_tip, u4_atom_fuse, &pq_tip, &qq_tip) ) {
    return _null_orth_atom(m, ham, cal, pq_tip) ||
           _null_orth_atom(m, ham, cal, qq_tip);
  }

  else if ( u4_b_pq(q_tip, u4_atom_gate, &pq_tip, &qq_tip) ) {
    u4_noun fum   = u4_k_cell(lane, u4_atom_atom, q_tip);

    if ( u4_bag_in(fum, cal) ) {
      return 1;
    }
    else {
      return _null_orth_atom
        (m, ham, 
            u4_bag_add(lane, fum, cal), 
            _mill_repo(m, pq_tip, qq_tip));
    }
  }
  else return _null_orth_atom(m, ham, cal, _mill_reap(m, q_tip));
}

/* _null_orth_cell(): as _null_orth(), for cell.
*/
static u4_t
_null_orth_cell(u4_milr m,
                u4_bag  ham,
                u4_bag  cal,
                u4_type pp_tip,
                u4_type qp_tip,
                u4_type q_tip)
{
  u4_lane lane = m->lane;
  u4_noun pq_tip, qq_tip;

  if ( u4_n_eq(u4_atom_atom, q_tip) ) {
    return u4_true;
  }

  else if ( u4_n_eq(u4_atom_blur, q_tip) ) {
    return u4_false;
  }

  else if ( u4_b_pq(q_tip, u4_atom_cell, &pq_tip, &qq_tip) ) {
    return _null_orth(m, ham, cal, pp_tip, pq_tip) ||
           _null_orth(m, ham, cal, pq_tip, qq_tip);
  }

  else if ( u4_b_p(q_tip, u4_atom_cube, &pq_tip) ) {
    if ( u4_n_atom(pq_tip) ) {
      return u4_true;
    } 
    else {
      return _null_orth_cell
        (m, ham, cal, pp_tip, qp_tip, _mill_reap(m, q_tip));
    }
  }

  else if ( u4_b_pq(q_tip, u4_atom_fork, &pq_tip, &qq_tip) ) {
    return ( _null_main(m, ham, pq_tip) ||
             _null_orth_cell(m, ham, cal, pp_tip, qp_tip, pq_tip) ) &&
           ( _null_main(m, ham, qq_tip) ||
             _null_orth_cell(m, ham, cal, pp_tip, qp_tip, qq_tip) );
  }

  else if ( u4_b_pq(q_tip, u4_atom_fuse, &pq_tip, &qq_tip) ) {
    return _null_orth_cell(m, ham, cal, pp_tip, qp_tip, pq_tip) ||
           _null_orth_cell(m, ham, cal, pp_tip, qp_tip, qq_tip);
  }

  else if ( u4_b_pq(q_tip, u4_atom_gate, &pq_tip, &qq_tip) ) {
    u4_noun p_tip = u4_k_trel(lane, u4_atom_cell, pp_tip, qp_tip);
    u4_noun fum   = u4_k_cell(lane, p_tip, q_tip);

    if ( u4_bag_in(fum, cal) ) {
      return u4_true;
    }
    else {
      return _null_orth_cell
        (m, ham, 
            u4_bag_add(lane, fum, cal), 
            pp_tip,
            qp_tip,
            _mill_repo(m, pq_tip, qq_tip));
    }
  }
  else return _null_orth_cell
    (m, ham, cal, pp_tip, qp_tip, _mill_reap(m, q_tip));
}

/* _null_orth(): null, with double recursion control.
*/
static u4_t
_null_orth(u4_milr m,
           u4_bag  ham,
           u4_bag  cal,
           u4_type p_tip,
           u4_type q_tip)
{
  u4_lane lane = m->lane;
  u4_noun pp_tip, qp_tip;

  if ( u4_n_eq(u4_atom_atom, p_tip) ) {
    return _null_orth_atom(m, ham, cal, q_tip);
  }

  else if ( u4_n_eq(u4_atom_blur, p_tip) ) {
    return u4_false;
  }

  else if ( u4_b_pq(p_tip, u4_atom_cell, &pp_tip, &qp_tip) ) {
    return _null_orth_cell(m, ham, cal, pp_tip, qp_tip, q_tip);
  }

  else if ( u4_b_p(p_tip, u4_atom_cube, &pp_tip) ) {
    if ( u4_n_atom(pp_tip) ) {
      return _null_orth_plum(m, ham, cal, pp_tip, q_tip);
    }
    else return _null_orth(m, ham, cal, _mill_reap(m, p_tip), q_tip);
  }

  else if ( u4_b_pq(p_tip, u4_atom_fork, &pp_tip, &qp_tip) ) {
    return ( ( _null_main(m, ham, pp_tip) ||
               _null_orth(m, ham, cal, pp_tip, q_tip) ) &&
             ( _null_main(m, ham, qp_tip) ||
               _null_orth(m, ham, cal, qp_tip, q_tip) ) );
  }

  else if ( u4_b_pq(p_tip, u4_atom_fuse, &pp_tip, &qp_tip) ) {
    return _null_orth(m, ham, cal, pp_tip, q_tip) ||
           _null_orth(m, ham, cal, qp_tip, q_tip);
  }

  else if ( u4_b_pq(p_tip, u4_atom_gate, &pp_tip, &qp_tip) ) {
    u4_noun fum = u4_k_cell(lane, p_tip, q_tip);

    if ( u4_bag_in(fum, cal) ) {
      return u4_true;
    }
    else {
      return _null_orth
        (m, ham, 
            u4_bag_add(lane, fum, cal), 
            _mill_repo(m, pp_tip, qp_tip),
            q_tip);
    }
  }

  else return _null_orth(m, ham, cal, _mill_reap(m, p_tip), q_tip);
}

/* _null_main(): null, with recursion control.
*/
static u4_t
_null_main(u4_milr m,
           u4_bag  ham,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_tip, q_tip;

  if ( u4_n_eq(u4_atom_atom, tip) ) {
    return u4_false;
  }
  else if ( u4_n_eq(u4_atom_blot, tip) ) {
    return u4_true;
  }
  else if ( u4_n_eq(u4_atom_blur, tip) ) {
    return u4_false;
  }
  else if ( u4_b_pq(tip, u4_atom_cell, &p_tip, &q_tip) ) {
    return _null_main(m, ham, p_tip) || _null_main(m, ham, q_tip);
  }
  else if ( u4_b_p(tip, u4_atom_cube, &p_tip) ) {
    return u4_false;
  }
  else if ( u4_b_pq(tip, u4_atom_fork, &p_tip, &q_tip) ) {
    return _null_main(m, ham, p_tip) && _null_main(m, ham, q_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_fuse, &p_tip, &q_tip) ) {
    u4_bag cal = u4_bag_add(lane, u4_k_cell(lane, p_tip, q_tip), u4_noun_0);

    return _null_main(m, ham, p_tip) ||
           _null_main(m, ham, q_tip) ||
           _null_orth(m, ham, cal, p_tip, q_tip);
  }
  else if ( u4_b_pq(tip, u4_atom_gate, &p_tip, &q_tip) ) {
    if ( u4_bag_in(tip, ham) ) {
      /* We can do this because we're searching conservatively.
      */
      return u4_true;
    }
    else {
      return _null_main
        (m, u4_bag_add(lane, tip, ham), _mill_repo(m, p_tip, q_tip));
    }
  }
  else return _null_main(m, ham, _mill_reap(m, tip));
}


/* _mill_null(): true if type is empty.
*/
u4_t
_mill_null(u4_milr m,
           u4_type tip)
{
  u4_nopt reb = u4_tab_get(tip, m->dam);

  if ( reb != u4_bull ) {
    return u4_n_zero(reb);
  }
  else {
    u4_t t_reb = _null_main(m, u4_bag_add(m->lane, tip, u4_noun_0), tip);

    m->dam = u4_tab_add(m->lane, tip, (t_reb ? u4_noun_0 : u4_noun_1), m->dam);
    return t_reb;
  }
}
