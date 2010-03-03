/* mill/edit.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

  /** Forward declarations.
  **/
      u4_type
      _edit_mask(u4_milr, u4_plox);


/* _edit_plox_take_half(): produce head or tail of plox.
*/
static u4_plox
_edit_plox_take_half(u4_milr m,
                     u4_axis haf,
                     u4_plox zel)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(zel) ) {
    return u4_noun_0;
  }
  else {
    u4_glep i_zel  = u4_ch(zel);
    u4_plox t_zel  = u4_ct(zel);
    u4_tape pi_zel = u4_ch(i_zel);
    u4_type qi_zel = u4_ct(i_zel);

    u4_assert(!u4_n_zero(pi_zel));
    {
      u4_tack ipi_zel = u4_ch(pi_zel);
      u4_tape tpi_zel = u4_ct(pi_zel);

      if ( u4_n_eq(u4_atom_axis, u4_ch(ipi_zel)) ) {
        u4_axis axe = u4_ct(ipi_zel);
        
        if ( u4_n_eq(haf, u4_op_tip(axe)) ) {
          u4_axis nem = u4_op_tap(lane, axe);

          if ( !u4_n_eq(u4_noun_1, nem) ) {
            pi_zel = u4_k_cell
              (lane, u4_k_cell(lane, u4_atom_axis, nem), tpi_zel);
          }
          else {
            pi_zel = tpi_zel;
          }
          return u4_k_cell
            (lane, u4_k_cell(lane, pi_zel, qi_zel),
                   _edit_plox_take_half(m, haf, t_zel));
        }
        else {
          return _edit_plox_take_half(m, haf, t_zel);
        }
      }
      else {
        // Cutting through a term.  Probably never executed.  But...
        //
        return _edit_plox_take_half
          (m, haf, u4_k_cell(lane, u4_k_cell(lane, tpi_zel, qi_zel), t_zel));
      }
    }
  }
}

/* _edit_plox_take_hed(): produce head of plox.
*/
static u4_plox
_edit_plox_take_hed(u4_milr m,
                    u4_plox zel)
{
  return _edit_plox_take_half(m, u4_noun_2, zel);
}

/* _edit_plox_take_tal(): produce tail of plox.
*/
static u4_plox
_edit_plox_take_tal(u4_milr m,
                    u4_plox zel)
{
  return _edit_plox_take_half(m, u4_noun_3, zel);
}

/* _edit_plox_kil(): convert all types in plox to blur.
*/
static u4_plox
_edit_plox_kil(u4_milr m,
               u4_plox zel)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(zel) ) {
    return u4_noun_0;
  }
  else {
    u4_glep i_zel  = u4_ch(zel);
    u4_plox t_zel  = u4_ct(zel);
    u4_tape pi_zel = u4_ch(i_zel);

    return u4_k_cell
      (lane, u4_k_cell(lane, pi_zel, u4_atom_blur),
             _edit_plox_kil(m, t_zel));
  }
}

/* _edit_plox_is_end(): true iff plox is finished.
*/
static u4_t
_edit_plox_is_end(u4_milr m,
                  u4_plox zel,
                  u4_type *nuf)
{
  if ( u4_n_zero(u4_ct(zel)) && u4_n_zero(u4_chh(zel)) ) {
    *nuf = u4_cht(zel);
    return 1;
  }
  else {
    return 0;
  }
}

/* _edit_plox_take_tag(): see _edit_plox_is_tag().
*/
static u4_plox
_edit_plox_take_tag(u4_milr m,
                    u4_plox zel,
                    u4_mark *cox)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(zel) ) {
    return u4_noun_0;
  }
  else {
    u4_glep i_zel  = u4_ch(zel);
    u4_plox t_zel  = u4_ct(zel);
    u4_tape pi_zel = u4_ch(i_zel);
    u4_type qi_zel = u4_ct(i_zel);

    u4_assert(!u4_n_zero(pi_zel));
    {
      u4_tack ipi_zel = u4_ch(pi_zel);
      u4_tape tpi_zel = u4_ct(pi_zel);

      if ( u4_n_eq(u4_atom_term, u4_ch(ipi_zel)) ) {
        if ( u4_n_zero(*cox) ) {
          *cox = u4_ct(ipi_zel);
        }
        else u4_assert(u4_n_eq(*cox, u4_ct(ipi_zel)));

        return u4_k_cell
          (lane, u4_k_cell(lane, tpi_zel, qi_zel),
                 _edit_plox_take_tag(m, t_zel, cox));
      }
      else return u4_k_cell
        (lane, i_zel,
               _edit_plox_take_tag(m, t_zel, cox));
    }
  }
}

/* _edit_plox_is_tag(): true iff plox affixes a tag.
*/
static u4_t
_edit_plox_is_tag(u4_milr m,
                  u4_plox zel,
                  u4_mark *cox,
                  u4_plox *hom)
{
  *cox = u4_noun_0;
  *hom = _edit_plox_take_tag(m, zel, cox);

  if ( u4_n_zero(*cox) ) {
    return 0;
  }
  else return 1;
}

/* _edit_fuse(): edit a fuse.
*/
static u4_type
_edit_fuse(u4_milr m,
           u4_plox zel,
           u4_rail bar,
           u4_type p_gom,
           u4_type q_gom)
{
  u4_lane lane = m->lane;
  u4_type nuf;

  if ( _edit_plox_is_end(m, zel, &nuf) ) {
    return nuf;
  }
  else {
    u4_rail sor  = u4_k_cell(lane, p_gom, bar);
    u4_plox zig  = _edit_plox_kil(m, zel);
    u4_type vep;
    u4_type gor;

    vep = _mill_edit(m, zig, bar, p_gom);
    gor = _mill_edit(m, zel, sor, q_gom);

    if ( _mill_nest(m, gor, vep) ) {
      return gor;
    }
    else {
      return u4_k_trel(lane, u4_atom_fuse, vep, gor);
    }
  }
}

/* _edit_cone_fab(): try to fabricate a cone.
*/
static u4_t
_edit_cone_fab(u4_milr m,
               u4_type doz,
               u4_type p_gom,
               u4_type q_gom)
{
  return u4_stub;
}

/* _edit_cone(): edit a cone.
*/
static u4_type
_edit_cone(u4_milr m,
           u4_plox zel,
           u4_rail bar,
           u4_type p_gom,
           u4_clip q_gom)
{
  u4_lane lane = m->lane;
  u4_type nuf;

  if ( _edit_plox_is_end(m, zel, &nuf) ) {
    return nuf;
  }
  else {
    u4_plox tig  = _edit_plox_take_hed(m, zel);
    u4_plox par  = _edit_plox_take_tal(m, zel);

    if ( !u4_n_zero(par) ) {
      return _mill_fail(m, "cone write");
    }
    else {
      u4_rail sed = _mill_slip(m, u4_noun_2, bar);
      u4_type doz = _mill_edit(m, tig, sed, p_gom);

      u4_burp(lane, "p_gom", _mill_dump(m, p_gom));
      u4_err(lane, "doz", doz);

      u4_burp(lane, "doz", _mill_dump(m, doz));

      if ( _mill_nest(m, doz, p_gom) ) {
        if ( _mill_nest(m, p_gom, doz) ) {
          return u4_k_trel(lane, u4_atom_cone, p_gom, q_gom);
        }
        else {
          return u4_k_trel
            (lane, u4_atom_fuse,
                   _mill_edit(m, zel, bar, u4_atom_blur),
                   u4_k_trel(lane, u4_atom_cone, p_gom, q_gom));
        }
      }
      else {
        if ( _edit_cone_fab(m, doz, p_gom, q_gom) ) {
          return u4_k_trel(lane, u4_atom_cone, doz, q_gom);
        }
        else {
          return _mill_fail(m, "edit: cone violation");
        }
      }
    }
  }
}

/* _edit_cell(): edit a cell.
*/
static u4_type
_edit_cell(u4_milr m,
           u4_plox zel,
           u4_rail bar,
           u4_type p_gom,
           u4_type q_gom)
{
  u4_lane lane = m->lane;
  u4_type nuf;

  if ( _edit_plox_is_end(m, zel, &nuf) ) {
    return nuf;
  }
  else {
    u4_plox tig  = _edit_plox_take_hed(m, zel);
    u4_plox par  = _edit_plox_take_tal(m, zel);
    u4_rail sed  = _mill_slip(m, u4_noun_2, bar);
    u4_rail dus  = _mill_slip(m, u4_noun_3, bar);

    return u4_k_trel
      (lane, u4_atom_cell,
             _mill_edit(m, tig, sed, p_gom),
             _mill_edit(m, par, dus, q_gom));
  }
}

/* _edit_crib(): edit a crib.
*/
static u4_noun
_edit_crib(u4_milr m,
           u4_plox zel,
           u4_rail bar,
           u4_noun p_gom)
{
  u4_lane lane = m->lane;
  u4_noun ip_gom = u4_ch(p_gom);
  u4_noun tp_gom = u4_ct(p_gom);
  u4_term pip_gom = u4_ch(ip_gom);
  u4_type qip_gom = u4_ct(ip_gom);
  u4_noun hed, tal;
  u4_plox hom;
  u4_mark cox;
  u4_type nuf;

  if ( u4_n_zero(zel) ) {
    return p_gom;
  }
  else {
    if ( u4_n_zero(tp_gom) ) {
      if ( u4_n_zero(zel) ) {
        hed = ip_gom;
      }
      else if ( _edit_plox_is_end(m, zel, &nuf) ) {
        hed = u4_k_cell(lane, pip_gom, nuf);
      }
      else if ( _edit_plox_is_tag(m, zel, &cox, &hom) ) {
        hed = u4_k_cell(lane, cox, _mill_edit(m, hom, bar, qip_gom));
      }
      else {
        hed = u4_k_cell(lane, pip_gom, _mill_edit(m, zel, bar, qip_gom));
      }

      tal = u4_noun_0;
    }
    else {
      u4_rail sed = _mill_slip(m, u4_noun_2, bar);
      u4_rail dus = _mill_slip(m, u4_noun_3, bar);
      u4_plox tig = _edit_plox_take_hed(m, zel);
      u4_plox par = _edit_plox_take_tal(m, zel);

      if ( u4_n_zero(tig) ) {
        hed = ip_gom;
      }
      else if ( _edit_plox_is_end(m, tig, &nuf) ) {
        hed = u4_k_cell(lane, pip_gom, nuf);
      }
      else if ( _edit_plox_is_tag(m, tig, &cox, &hom) ) {
        u4_err(lane, "hom", hom);
        u4_err(lane, "qip_gom", qip_gom);
        hed = u4_k_cell(lane, cox, _mill_edit(m, hom, sed, qip_gom));
      }
      else {
        hed = u4_k_cell(lane, pip_gom, _mill_edit(m, tig, sed, qip_gom));
      }

      tal = _edit_crib(m, par, dus, tp_gom);
    }
    return u4_k_cell(lane, hed, tal);
  }
}

/* _edit_mask_crib(): mask crib tail.
*/
static u4_noun
_edit_mask_crib(u4_milr m,
                u4_plox tig,
                u4_plox par)
{
  u4_lane lane = m->lane;
  u4_type nuf;
  u4_plox doq;
  u4_mark cox;
  u4_noun hed, tal;

  if ( u4_n_zero(tig) ) {
    hed = u4_k_cell(lane, u4_noun_0, u4_atom_blur);
  }
  else if ( _edit_plox_is_end(m, tig, &nuf) ) {
    hed = u4_k_cell(lane, u4_noun_0, nuf);
  }
  else if ( _edit_plox_is_tag(m, tig, &cox, &doq) ) {
    hed = u4_k_cell(lane, cox, _edit_mask(m, doq));
  }
  else {
    hed = u4_k_cell(lane, u4_noun_0, _edit_mask(m, tig));
  }

  if ( u4_n_zero(par) ) {
    tal = u4_k_cell
      (lane, u4_k_cell(lane, u4_noun_0, u4_atom_blur), 
             u4_noun_0);
  }
  else if ( _edit_plox_is_end(m, par, &nuf) ) {
    tal = u4_k_cell
      (lane, u4_k_cell(lane, u4_noun_0, nuf), 
             u4_noun_0);
  }
  else if ( _edit_plox_is_tag(m, par, &cox, &doq) ) {
    tal = u4_k_cell
      (lane, u4_k_cell(lane, cox, _edit_mask(m, doq)),
             u4_noun_0);
  }
  else {
    tal = _edit_mask_crib
      (m, _edit_plox_take_hed(m, par), _edit_plox_take_tal(m, par));
  }

  return u4_k_cell(lane, hed, tal);
}

/* _edit_mask(): edit into nothing at all.
*/
u4_type
_edit_mask(u4_milr m,
           u4_plox zel)
{
  u4_lane lane = m->lane;
  u4_plox hom;
  u4_mark cox;
  u4_type nuf;

  if ( _edit_plox_is_end(m, zel, &nuf) ) {
    return nuf;
  }
  else if ( _edit_plox_is_tag(m, zel, &cox, &hom) ) {
    return u4_k_trel
      (lane, u4_atom_crib,
             u4_k_cell(lane, cox, _edit_mask(m, hom)),
             u4_noun_0);
  }
  else {
    return u4_k_cell
      (lane, u4_atom_crib,
             _edit_mask_crib(m, _edit_plox_take_hed(m, zel),
                                _edit_plox_take_tal(m, zel)));
  }
}

/* _mill_edit(): edit a type to reflect a list of writes.
**
**  zel: changes: list+[list+[([%axis axis] [%term term]) type]]
*/
u4_type
_mill_edit(u4_milr m,
           u4_plox zel,
           u4_rail bar,
           u4_type gom)
{
  u4_lane lane = m->lane;
  u4_noun p_gom, q_gom;

  if ( u4_n_zero(zel) ) {
    return gom;
  }

  // %atom
  // %blot
  // %blur
  //
  if ( u4_n_eq(u4_atom_atom, gom) ||
       u4_n_eq(u4_atom_blot, gom) ||
       u4_n_eq(u4_atom_blur, gom) )
  {
    return _edit_mask(m, zel);
  }

  // [%crib p=list+[term type]]
  //
  else if ( u4_b_p(gom, u4_atom_crib, &p_gom) ) {
    return u4_k_cell(lane, u4_atom_crib, _edit_crib(m, zel, bar, p_gom));
  }

  // <%cell p=(type) q=(type)>
  //
  else if ( u4_b_pq(gom, u4_atom_cell, &p_gom, &q_gom) ) {

    return _edit_cell(m, zel, bar, p_gom, q_gom);
  }

  // <%cone p=(type) q={bush term type}>
  //
  else if ( u4_b_pq(gom, u4_atom_cone, &p_gom, &q_gom) ) {
    return _edit_cone(m, zel, bar, p_gom, q_gom);
  }

  // <%cube p=*>
  // 
  else if ( u4_b_p(gom, u4_atom_cube, &p_gom) ) {
    return _edit_mask(m, zel);
  }

  // <%fork p=(type) q=(type)>
  //
  else if ( u4_b_pq(gom, u4_atom_fork, &p_gom, &q_gom) ) {
    if ( _mill_cull(m, bar, p_gom) ) {
      return _mill_edit(m, zel, bar, q_gom);
    }
    else if ( _mill_cull(m, bar, q_gom) ) {
      return _mill_edit(m, zel, bar, p_gom);
    }
    else {
      return _mill_eith
        (m, _mill_edit(m, zel, bar, p_gom),
            _mill_edit(m, zel, bar, q_gom));
    }
  }

  // <%fuse p=(type) q=(type)>
  //
  else if ( u4_b_pq(gom, u4_atom_fuse, &p_gom, &q_gom) ) {
    return _edit_fuse(m, zel, bar, p_gom, q_gom);
  }

  // <%gate p=(type) q=(gene)>
  //
  else if ( u4_b_pq(gom, u4_atom_gate, &p_gom, &q_gom) ) {
    u4_noun sul = _mill_repo(m, p_gom, q_gom);
    u4_noun vaq = _mill_edit(m, zel, bar, sul);

    if ( u4_n_eq(sul, vaq) ) {
      return gom;
    }
    else return vaq;
  }
  else return u4_trip;
}
