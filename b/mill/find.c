/* mill/find.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

    /** Forward declarations.
    **/
      static u4_loaf
      _find_main(u4_milr, u4_mark, u4_bag, u4_rail, u4_type);


/* _find_hang(): attach a loaf by an axis.
*/
static u4_loaf
_find_hang(u4_milr m,
           u4_axis axe,
           u4_loaf tub)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(tub) ) {
    return tub;
  }
  else {
    return u4_k_cell
      (lane, 
       u4_ch(tub), 
       _mill_comp(m, u4_k_cell(lane, u4_noun_0, axe), u4_ct(tub)));
  }
}

/* _find_slip(): as _find_main(), but typ is at axis.
*/
static u4_loaf
_find_slip(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_axis axe,
           u4_rail bar,
           u4_type typ)
{
  return 
    _find_hang(m, axe, 
                  _find_main(m, cox, gil, _mill_slip(m, axe, bar), typ));
}

/* _find_seek(): search in clip with axis.  Produces |(~, [axis gene]).
*/
static u4_carb
_find_seek(u4_milr m,
           u4_axis axe,
           u4_mark cox,
           u4_clip hig)
{
  u4_lane lane  = m->lane;
  u4_noun p_hig = u4_ch(hig);
  u4_noun q_hig = u4_ct(hig);

  if ( !u4_n_atom(p_hig) ) {
    u4_carb bek = _find_seek(m, u4_op_peg(lane, axe, u4_noun_2), cox, p_hig);
    u4_carb lod = _find_seek(m, u4_op_peg(lane, axe, u4_noun_3), cox, q_hig);

    if ( !u4_n_zero(bek) ) {
      if ( !u4_n_zero(lod) ) {
        return _mill_fail(m, "find: clip conflict");
      }
      else return bek;
    }
    else return lod;
  }
  else {
    if ( u4_n_eq(cox, p_hig) ) {
      return u4_k_cell(lane, axe, q_hig);
    }
    else return u4_noun_0;
  }
}

/* _find_cell(): as _find_main(), for [%cell p_typ q_typ].
*/
static u4_loaf
_find_cell(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_rail bar,
           u4_type p_typ,
           u4_type q_typ)
{
  u4_loaf gul = _find_slip(m, cox, gil, u4_noun_2, bar, p_typ);
  u4_loaf das = _find_slip(m, cox, gil, u4_noun_3, bar, q_typ);

  if ( !u4_n_zero(gul) && !u4_n_zero(das) ) {
    return _mill_fail(m, "find: cell conflict a");
  }
  else if ( !u4_n_zero(gul) ) {
    return gul;
  }
  else return das;
}

/* _find_cone(): as _find_main(), for [%cone p_typ q_typ].
*/
static u4_loaf
_find_cone(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_rail bar,
           u4_type p_typ,
           u4_clip q_typ)
{
  u4_lane lane = m->lane;
  u4_carb gos = _find_seek(m, u4_noun_1, cox, q_typ);

  if ( u4_n_zero(gos) ) {
    return _find_slip(m, cox, gil, u4_noun_2, bar, p_typ);
  }
  else {
    u4_axis p_gos = u4_ch(gos);
    u4_gene q_gos = u4_ct(gos);
    u4_axis gal   = u4_op_peg(lane, u4_noun_3, p_gos);

    return u4_k_cell
      (lane,
       u4_k_trel(lane, u4_atom_gate, 
                       u4_k_trel(lane, u4_atom_cone, p_typ, q_typ),
                       q_gos),
       u4_k_trel(lane, u4_noun_3,
                       u4_k_cell(lane, u4_noun_0, u4_noun_1),
                       u4_k_cell(lane, u4_noun_0, gal)));
  }
}

/* _find_crib(): as _find_main(), for [%crib p_typ].
*/
static u4_loaf
_find_crib(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_rail bar,
           u4_noun p_typ)
{
  u4_lane lane = m->lane;
  u4_noun ip_typ = u4_ch(p_typ);
  u4_noun tp_typ = u4_ct(p_typ);
  u4_mark pip_typ = u4_ch(ip_typ);
  u4_type qip_typ = u4_ct(ip_typ);

  if ( u4_n_zero(tp_typ) ) {
    if ( u4_n_zero(pip_typ) ) {
      return _find_main(m, cox, gil, bar, qip_typ);
    }
    else if ( u4_n_eq(cox, pip_typ) ) {
      return u4_k_trel(lane, qip_typ, u4_noun_0, u4_noun_1);
    }
    else return u4_noun_0;
  }
  else {
    if ( u4_n_zero(pip_typ) ) {
      u4_type fov = u4_k_cell(lane, u4_atom_crib, tp_typ);
      u4_loaf gul = _find_slip(m, cox, gil, u4_noun_2, bar, qip_typ);
      u4_loaf das = _find_slip(m, cox, gil, u4_noun_3, bar, fov);

      if ( !u4_n_zero(gul) && !u4_n_zero(das) ) {
        u4_burp(lane, "qip", _mill_dump(m, qip_typ));
        u4_burp(lane, "fov", _mill_dump(m, fov));

        u4_err(lane, "t_gul", u4_ct(gul));
        u4_err(lane, "t_das", u4_ct(das));

        u4_trip; 
        return _mill_fail(m, "find: cell conflict b");
      }
      else if ( !u4_n_zero(gul) ) {
        return gul;
      }
      else return das;
    }
    else if ( u4_n_eq(cox, pip_typ) ) {
      return u4_k_trel(lane, qip_typ, u4_noun_0, u4_noun_2);
    }
    else {
      return _find_slip
        (m, cox, gil, u4_noun_3, bar, u4_k_cell(lane, u4_atom_crib, tp_typ));
    }
  }
}

/* _find_fork(): as _find_main(), for [%fork p_typ q_typ].
*/
static u4_loaf
_find_fork(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_rail bar,
           u4_type p_typ,
           u4_type q_typ)
{
  u4_lane lane = m->lane;

  if ( _mill_cull(m, bar, p_typ) ) {
    return _find_main(m, cox, gil, bar, q_typ);
  } 
  else if ( _mill_cull(m, bar, q_typ) ) {
    return _find_main(m, cox, gil, bar, p_typ);
  }
  else {
    u4_loaf dor = _find_main(m, cox, gil, bar, p_typ);
    u4_loaf hum = _find_main(m, cox, gil, bar, q_typ);

    if ( !u4_n_zero(dor) && 
         !u4_n_zero(hum) &&
         u4_n_eq(u4_ct(dor), u4_ct(hum)) )
    {
      return u4_k_cell
        (lane, _mill_eith(m, u4_ch(dor), u4_ch(hum)),
               u4_ct(dor));
    }
    else if ( u4_n_zero(dor) && u4_n_zero(hum) ) {
      return u4_noun_0;
    }
    else return _mill_fail(m, "find: fork conflict");
  }
}

/* _find_fuse(): as _find_main(), for [%fuse p_typ q_typ].
*/
static u4_loaf
_find_fuse(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_rail bar,
           u4_type p_typ,
           u4_type q_typ)
{
  u4_lane lane = m->lane;
  u4_rail dax  = u4_k_cell(lane, p_typ, bar);
  u4_loaf pir  = _find_main(m, cox, gil, dax, q_typ);

  if ( u4_n_zero(pir) ) {
    u4_loaf rex = _find_main(m, cox, gil, bar, p_typ);

    if ( u4_n_zero(rex) ) {
      return u4_noun_0;
    } else {
      u4_axis axe;

      if ( u4_b_p(u4_ct(rex), u4_noun_0, &axe) ) {
        return u4_k_cell
          (lane, _mill_both(m, u4_ch(rex), _mill_peek(m, axe, dax, q_typ)),
                 u4_ct(rex)); 
      }
      else return rex;
    }
  }
  else {
    u4_type gan = u4_ch(pir);
    u4_form fol = u4_ct(pir);
    u4_noun p_fol, p_gan, q_gan;
    u4_axis axe;
    u4_type buc;

    if ( u4_b_p(fol, u4_noun_0, &axe) ) {
      u4_loaf rex = _find_main(m, cox, gil, bar, p_typ);

      if ( u4_n_zero(rex) ) {
        buc = _mill_both(m, _mill_peek(m, axe, bar, p_typ), gan);
      }
      else if ( u4_n_eq(fol, u4_ct(rex)) ) {
        buc = _mill_both(m, u4_ch(rex), gan);
      } 
      else return _mill_fail(m, "find: fuse conflict");
    }
    else if ( u4_b_pq(fol, u4_noun_3, &p_fol, 0) &&
              u4_b_p(p_fol, u4_noun_0, &axe) &&
              u4_b_pq(gan, u4_atom_gate, &p_gan, &q_gan) ) 
    {
      // Fusion polymorphism.  Very powerful and dangerous.
      //
      buc = u4_k_trel
        (lane, u4_atom_gate, 
               _mill_both(m, _mill_peek(m, axe, bar, p_typ), p_gan),
               q_gan);
    }
    else return u4_trip;

    return u4_k_cell(lane, buc, fol);
  }
}

/* _find_main(): as _find_main(), with gil.
*/
static u4_loaf
_find_main(u4_milr m,
           u4_mark cox,
           u4_bag  gil,
           u4_rail bar,
           u4_type typ)
{
  u4_lane lane = m->lane;
  u4_noun p_typ, q_typ;

  // %atom
  // %blur
  //
  if ( u4_n_eq(u4_atom_atom, typ) ||
       u4_n_eq(u4_atom_blur, typ) )
  {
    return u4_noun_0;
  }

  // <%crib p={list ~[(term) (type)]}>
  //
  else if ( u4_b_p(typ, u4_atom_crib, &p_typ) ) {
    return _find_crib(m, cox, gil, bar, p_typ);
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
    return _find_cell(m, cox, gil, bar, p_typ, q_typ);
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(typ, u4_atom_cone, &p_typ, &q_typ) ) {
    return _find_cone(m, cox, gil, bar, p_typ, q_typ);
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
    return u4_noun_0;
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
    return _find_fork(m, cox, gil, bar, p_typ, q_typ);
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
    return _find_fuse(m, cox, gil, bar, p_typ, q_typ);
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(typ, u4_atom_gate, &p_typ, &q_typ) ) {
    u4_noun dit = u4_k_cell(lane, bar, typ);

    if ( u4_bag_in(dit, gil) ) {
      return u4_noun_0;
    } else {
      return _find_main
        (m, cox,
            u4_bag_add(lane, dit, gil), 
            bar,
            _mill_repo(m, p_typ, q_typ));
    }
  }

  // [%wing p=axis q=type]
  //
  else if ( u4_b_pq(typ, u4_atom_wing, &p_typ, &q_typ) ) {
    return u4_noun_0;
  }

  else {
    u4_bug("strange type", typ);
    return u4_trip;
  }
}

/* _mill_find(): look by name.
*/
u4_loaf
_mill_find(u4_milr m,
           u4_mark cox,
           u4_rail bar,
           u4_type typ)
{
  return _find_main(m, cox, u4_noun_0, bar, typ);
}
