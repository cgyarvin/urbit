/* mill/dump.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

    /** Forward declarations.
    **/
      static u4_prep
      _dump_main(u4_milr, u4_bag, u4_bag, u4_type);


/* _dump_count()::
*/
static u4_atom
_dump_count(u4_lane lane, u4_noun q_typ)
{
  if ( u4_n_atom(u4_ch(q_typ)) ) {
    return u4_noun_1;
  }
  else {
    return u4_op_add
      (lane, _dump_count(lane, u4_ch(q_typ)), 
             _dump_count(lane, u4_ct(q_typ)));
  }
}

static u4_noun
_dump_crib(u4_milr m,
           u4_bag  gil,
           u4_bag  nip,
           u4_noun p_typ)
{
  u4_lane lane    = m->lane;

  if ( u4_n_zero(p_typ) ) {
    return u4_noun_0;
  }
  else {
    u4_noun ip_typ  = u4_ch(p_typ);
    u4_term pip_typ = u4_ch(ip_typ);
    u4_noun tp_typ  = u4_ct(p_typ);
    u4_type qip_typ = u4_ct(ip_typ);
    {
      u4_prep zem     = _dump_main(m, gil, nip, qip_typ);
      u4_noun gud     = _dump_crib(m, gil, nip, tp_typ);

      if ( u4_n_zero(pip_typ) ) {
        return u4_k_cell(lane, zem, gud);
      }
      else {
        u4_prep hep;

        hep = u4_k_list
          (lane, u4_atom_nail, 
                 u4_prep_textual(lane, pip_typ),
                 u4_cod_in(':'),
                 zem,
                 0);
  
        return u4_k_cell(lane, hep, gud);
      }
    }
  }
}

/* _dump_cone(): dump a cone.
*/
static u4_prep
_dump_cone(u4_milr m,
           u4_bag  gil,
           u4_bag  nip,
           u4_type p_typ,
           u4_clip q_typ)
{
  u4_lane lane = m->lane;
  u4_prep gum;
  u4_prep zib;
  u4_prep bor;

  zib = _dump_main(m, gil, nip, p_typ);
  bor = u4_k_atom_cat
    (lane, u4_cod_in('+'),
           u4_k_atom_cat
             (lane, u4_prep_decimal(lane, _dump_count(lane, q_typ)),
                    u4_k_atom_cat
                      (lane, u4_cod_in('.'),
                             u4_prep_hexinal
                                (lane, u4_cod_in(u4_n_nub(q_typ) & 0xffff)))));

  gum = u4_prep_close
    (lane, '[', ']', u4_k_list(lane, zib, bor, 0));

  return gum;
}

/* _dump_forks(): produce a dump list of forks.
*/
static u4_noun
_dump_forks(u4_milr m,
            u4_bag  gil,
            u4_bag  nip,
            u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
    return u4_log_cat
      (lane, _dump_forks(m, gil, nip, p_typ),
             _dump_forks(m, gil, nip, q_typ));
  }
  else if ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) && 
            !u4_bag_in(typ, gil) )
  {
    return _dump_forks(m, gil, nip, _mill_repo(m, p_typ, q_typ));
  }
  else return u4_k_cell(lane, _dump_main(m, gil, nip, typ), u4_noun_0);
}

/* _dump_main(): dump with gil and nip.
*/
static u4_prep
_dump_main(u4_milr m,
           u4_bag  gil,
           u4_bag  nip,
           u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  if ( u4_n_atom(typ) ) {
    if ( u4_n_eq(u4_atom_atom, typ) ) {
      return u4_cod_in('@');
    }
    else if ( u4_n_eq(u4_atom_blot, typ) ) {
      return u4_cod_in('#');
    }
    else if ( u4_n_eq(u4_atom_blur, typ) ) {
      return u4_cod_in('*');
    }
    else return u4_trip;
  }
  else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
    u4_type gan = u4_k_qual
      (lane, u4_atom_crib, 
             u4_k_cell(lane, u4_noun_0, p_typ), 
             u4_k_cell(lane, u4_noun_0, q_typ), 
             u4_noun_0);

    return _dump_main(m, gil, nip, gan);
  }

  else if ( u4_b_p(typ, u4_atom_crib, &p_typ) ) {
    return u4_prep_close
      (lane, '[', ']', _dump_crib(m, gil, nip, p_typ));
  }

  else if ( u4_b_pq(typ, u4_atom_cone, &p_typ, &q_typ) ) {
    return _dump_cone(m, gil, nip, p_typ, q_typ);
  }

  else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
    if ( u4_n_zero(p_typ) ) {
      return u4_cod_in('~');
    }
    else if ( u4_n_atom(p_typ) ) {
      return u4_k_atom_cat
        (lane, u4_cod_in('%'), u4_prep_textual(lane, p_typ));
    }
    else {
      return u4_k_list
        (lane,
         u4_atom_nail,
         u4_cod_in('%'),
         u4_pump_prep(lane, p_typ),
         0);
    }
  }

  else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
    u4_prep hep = 
      u4_prep_close
        (lane, '{', '}', _dump_forks(m, gil, nip, typ));

    return hep;
  }

  else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
    return u4_prep_close
      (lane, '{', '}', 
             u4_k_list(lane,
                       u4_atom_fuse,
                       _dump_main(m, gil, nip, p_typ),
                       _dump_main(m, gil, nip, q_typ),
                       0));
  }

  else if ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) ) {
    if ( u4_bag_in(typ, gil) ) {
      u4_noun fez = u4_k_atom_cat
          (lane, u4_cod_in('$'), 
                 u4_prep_decimal(lane, u4_bag_at(lane, typ, u4_noun_1, gil)));

      if ( u4_bag_in(typ, nip) ) {
        return fez;
      }
      else {
        u4_prep hod = 
          _dump_main(m, gil, 
                        u4_bag_add(lane, typ, nip),
                        _mill_repo(m, p_typ, q_typ));

        return u4_k_list
          (lane, u4_atom_nail, 
                 fez,
                 u4_cod_in('='),
                 hod,
                 u4_noun_0,
                 0);
      }
    }
    else {
      return _dump_main(m, gil, nip, _mill_repo(m, p_typ, q_typ));
    }
  }
  else {
    return u4_trip;
  }
}

u4_prep
_mill_dump(u4_milr m,
           u4_type typ)
{
  u4_bag gil = _mill_seal(m, typ);

  u4_assert(u4_bag_ok(gil));
  return _dump_main(m, gil, u4_noun_0, typ);
}
