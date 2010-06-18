/* watt/hume.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* burn:hume:bach:pitt
*/
  static u4_type
  _hume_burn_sint(u4_pitt, u4_type, u4_rail, u4_axis, u4_flag, u4_tack);

  static u4_type
  _hume_burn_dext(u4_pitt p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_flag vef,
                  u4_tack tac)
  {
    u4_lane lan = p->lane;
    u4_noun p_tac, q_tac;
    u4_noun p_sub, q_sub;

    if ( u4_n_zero(tac) ) {
      return sub;
    }
    else if ( u4_b_p(tac, u4_atom_leaf, &p_tac) ) {
      return p_tac;
    }
    else if ( u4_b_pq(tac, u4_atom_name, &p_tac, &q_tac) ) {
      if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
        if ( u4_n_eq(p_sub, p_tac) ) {
          return u4_k_trel
            (lan, 
             u4_atom_face, 
             p_tac, 
             _hume_burn_dext(p, q_sub, bar, axe, vef, q_tac));
        }
        else {
          return u4_k_trel
            (lan,
             u4_atom_face,
             p_tac,
             _hume_burn_dext(p, sub, bar, axe, vef, q_tac));
        }
      }
      else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) )
      {
        return _hume_burn_sint(p, sub, bar, axe, vef, tac);
      }
    }
    else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
      if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
        u4_noun l_sub, l_bar, l_axe;
        u4_noun r_sub, r_bar, r_axe;

        l_sub = sub; l_bar = bar; l_axe = axe;
        _hume_slip(p, &l_sub, &l_bar, &l_axe, u4_noun_2);

        r_sub = sub; r_bar = bar; r_axe = axe;
        _hume_slip(p, &r_sub, &r_bar, &r_axe, u4_noun_3);

        return u4_k_trel
          (lan,
           u4_atom_cell,
           _hume_burn_dext(p, l_sub, l_bar, l_axe, vef, p_tac),
           _hume_burn_dext(p, r_sub, r_bar, r_axe, vef, q_tac));
      }
      else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
        u4_noun l_sub, l_bar, l_axe;
        u4_type ham;

        l_sub = sub; l_bar = bar; l_axe = axe;
        _hume_slip(p, &l_sub, &l_bar, &l_axe, u4_noun_2);

        ham = _hume_burn_dext(p, l_sub, l_bar, l_axe, vef, p_tac);
        sub = u4_k_trel(lan, u4_atom_core, ham, q_sub);

        return u4_or(vef, _bach_dope(p, sub));
      }
      else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) )
      {
        return _hume_burn_sint(p, sub, bar, axe, vef, tac);
      }
      else {
        u4_noun poq = _u4_k_trel
          (lan,
           u4_atom_cell,
           _hume_half(p, sub, bar, axe, u4_noun_2),
           _hume_half(p, sub, bar, axe, u4_noun_3));

        return _hume_burn_dext(p, poq, bar, axe, vef, tac);
      }
    }
  }
  static u4_unit
  _hume_burn_swim(u4_pitt p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_flag vef,
                  u4_tack tac)
  {
    u4_lane lan = p->lane;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit yop = _hume_burn_swim(p, p_sub, bar, axe, vef, tac);
      u4_unit paf = _hume_burn_swim(p, q_sub, bar, axe, vef, tac);

      if ( u4_n_zero(yop) ) {
        return paf;
      } else if ( u4_n_zero(paf) ) {
        return yop;
      }
      else {
        return u4_k_cell
          (lan,
           u4_noun_0,
           u4_k_trel
            (lan,
             u4_atom_fork, u4_ct(yop), u4_ct(paf)));
      }
    }
    else {
      if ( _hume_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else {
        return u4_k_cell
          (lan, u4_noun_0, _hume_burn_dext(p, sub, bar, axe, vef, tac));
      }
    }
  }
  static u4_type
  _hume_burn_sint(u4_pitt p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_flag vef,
                  u4_tack tac)
  {
    u4_lane lan = p->lane;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return u4_k_trel
        (lan, 
         u4_atom_face,
         p_sub,
         _hume_burn_dext(p, q_sub, bar, axe, vef, tac));
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_ct(_hume_burn_swim(p, sub, bar, axe, vef, tac));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return u4_k_trel
        (lan, 
         u4_atom_fuse,
         _hume_burn_dext(p, p_sub, bar, axe, vef, _reck_dull(p, sub, tac)),
         _hume_burn_dext(p, q_sub, u4_k_cell(lan, p_sub, bar), axe, vef, tac));
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      return _hume_burn_dext
        (p, _bach_repo(p, p_sub, q_sub), bar, axe, vef, tac); 
    }
  }
u4_type
_hume_burn(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_flag vef,
           u4_tack tac)
{
  return _hume_burn_dext(p, sub, bar, axe, vef, tac);
}

/* cull:hume:bach:pitt
*/
  static u4_flag
  _hume_cull_a(u4_pitt p,
               u4_type sub,
               u4_rail bar,
               u4_axis axe)
  {
    if ( u4_n_zero(bar) ) {
      return u4_no;
    }
    else if ( _bach_orth(p, sub, u4_ch(bar)) ) {
      return u4_yes;
    }
    else return _hume_cull_a(p, sub, u4_ct(bar), axe);
  }
u4_flag
_hume_cull(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe)
{
  if ( _bach_null(p, sub) ) {
    return u4_yes;
  }
  else {
    return _hume_cull_a(p, sub, bar, axe);
  }
}

/* find:hume:bach:pitt
*/
  static u4_unit _hume_find_main
    (u4_pitt, u4_type, u4_rail, u4_axis, u4_term);

  static u4_unit
  _hume_find_half(u4_pitt p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_term cog,
                  u4_axis cap)
  {
    u4_lane lan = p->lane;

    _hume_slip(p, &sub, &bar, &axe, cap);

    return _hume_find_main(p, sub, bar, axe, gil, cog);
  }
  static u4_unit
  _hume_find_swim(u4_pitt p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_term cog)
  {
    u4_lane lan = p->lane;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit yop = _hume_find_swim(p, p_sub, bar, axe, gil, cog);
      u4_unit paf = _hume_find_swim(p, q_sub, bar, axe, gil, cog);

      if ( u4_n_zero(yop) ) {
        return paf;
      }
      else if ( u4_n_zero(paf) ) {
        return yop;
      }
      else {
        u4_unit lep = u4_ct(yop);
        u4_unit gam = u4_ct(paf);
        
        if ( u4_n_zero(lep) ) {
          if ( u4_n_zero(gam) ) {
            return u4_noun_0;
          }
          else return _pitt_fail(p, "fork conflict");
        }
        else if ( u4_n_zero(gam) ) {
          return _pitt_fail(p, "fork conflict");
        }
        else {
          u4_plan u_lep = u4_ct(lep);
          u4_plan u_gam = u4_ct(gam);

          if ( !u4_n_eq(u4_ch(u_lep), u4_ch(u_gam)) ||
               !u4_n_eq(u4_ch(u4_ct(u_lep)), u4_ch(u4_ct(u_gam))) ) {
          {
            return u4_k_cell
              (lan,
               u4_noun_0,
               u4_k_trel
                (lan, 
                 u4_ch(u_lep),
                 u4_ch(u4_ct(u_lep)),
                 u4_k_trel
                  (lan,
                   u4_atom_fork,
                   u4_ct(u4_ct(u_lep)),
                   u4_ct(u4_ct(u_gam)))));
          }
        }
      }
    }
    else {
      if ( _hume_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else {
        return u4_k_cell
          (lan, u4_noun_0, _hume_find_main(p, sub, bar, axe, gil, cog));
      }
    }
  }
  static u4_unit
  _hume_find_main(u4_pitt p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_term cog)
  {
    u4_lane lan = p->lane;
    u4_noun p_sub, q_sub;

    if ( u4_n_eq(u4_atom_atom, sub) ||
         u4_n_eq(u4_atom_blur, sub) ||
         u4_n_eq(u4_atom_blot, sub) ||
         u4_b_p(sub, u4_atom_cube, &p_sub) )
    {
      return u4_noun_0;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      u4_unit taf = _hume_find_half(p, sub, bar, axe, gil, cog, u4_noun_2);
      u4_unit bov = _hume_find_half(p, sub, bar, axe, gil, cog, u4_noun_3);

      if ( u4_n_zero(taf) ) {
        return bov;
      }
      else if ( u4_n_zero(bov) ) {
        return taf;
      }
      else return _pitt_fail(p, "cell conflict");
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      u4_spec dab;
      u4_unit zem;

      if ( !u4_b_p(q_sub, u4_atom_hard, &dab) ) {
        u4_b_pq(q_sub, u4_atom_soft, 0, &dab);
      }
      zem = _gunn_look(p, dab, cog);
      if ( u4_n_zero(zem) ) {
        return _hume_find_half(p, sub, bar, axe, gil, cog, u4_noun_2);
      }
      else return 
        u4_k_cell
          (lan, 
           u4_noun_0, 
           u4_k_trel
            (lan, 
             axe, 
             u4_k_qual
              (lan, 
               u4_noun_0, 
               u4_ch(u4_ct(zem)),
               sub,
               u4_ct(u4_ct(zem))),
             sub));
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      if ( u4_n_eq(cog, p_sub) ) {
        return u4_k_qual
          (lan, u4_noun_0, axe, u4_noun_0, sub);
      }
      else return u4_noun_0;
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit foz = _hume_find_swim(p, sub, bar, axe, gil, cog);

      if ( u4_n_zero(foz) ) {
        return _pitt_fail(p, "fork failure");
      }
      return u4_ct(foz);
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      u4_unit hax = _hume_find_main
        (p, p_sub, bar, axe, gil, cog);
      u4_unit yor = _hume_find_main
        (p, q_sub, u4_k_cell(lan, p_sub, bar), axe, gil, cog);

      if ( u4_n_zero(yor) ) {
        if ( u4_n_zero(hax) ) {
          return u4_noun_0;
        }
        else {
          u4_noun u_hax = u4_ct(hax);
          u4_noun pu_hax = u4_ch(u_hax);
          u4_noun qu_hax = u4_ch(u4_ct(u_hax));
          u4_noun ru_hax = u4_ct(u4_ct(u_hax));

          return u4_k_cell
            (lan, 
             u4_noun_0,
             u4_k_trel
              (lan,
               pu_hax,
               qu_hax,
               u4_k_trel
                (lan,
                 u4_atom_fuse,
                 ru_hax,
                 _hume_peek
                  (p, q_sub, u4_k_cell(lan, p_sub, bar), axe, pu_hax))));
        }
      }
      else {
        u4_noun u_yor = u4_ct(yor);
        u4_noun pu_yor = u4_ch(u_yor);
        u4_noun qu_yor = u4_ch(u4_ct(u_yor));
        u4_noun ru_yor = u4_ct(u4_ct(u_yor));

        if ( u4_n_zero(hax) ) {
          return u4_k_cell
            (lan, 
             u4_noun_0,
             u4_k_trel
              (lan,
               pu_yor,
               qu_yor,
               u4_k_trel
                (lan,
                 u4_atom_fuse,
                 _hume_peek(p, p_sub, bar, axe, pu_yor),
                 ru_yor)));
        }
        else {
          u4_noun u_hax = u4_ct(hax);
          u4_noun pu_hax = u4_ch(u_hax);
          u4_noun qu_hax = u4_ch(u4_ct(u_hax));
          u4_noun ru_hax = u4_ct(u4_ct(u_hax));

          if ( !(u4_n_eq(pu_hax, pu_yor) && u4_n_eq(qu_hax, qu_yor)) ) {
            ru_hax = _hume_peek(p, p_sub, bar, axe, pu_yor);
          }
          return u4_k_cell
            (lan, 
             u4_noun_0,
             u4_k_trel
              (lan,
               pu_yor,
               qu_yor,
               u4_k_trel(lan, u4_atom_fuse, ru_hax, ru_yor)));
        }
      }
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      u4_noun dit = u4_k_cell(lan, bar, typ);

      if ( u4_bag_in(dit, gil) ) {
        return u4_noun_0;
      } else {
        return _hume_find_main
          (p,
           _bach_repo(p, p_sub, q_sub), 
           bar,
           axe,
           u4_bag_add(lan, dit, gil), 
           cog);
      }
    }
  }
u4_plan
_hume_find(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_term cog)
{
  return u4_ct(_hume_find_main(p, sub, bar, axe, u4_noun_0, cog));
}

/* fish:hume:bach:pitt
*/
u4_tool
_hume_fish(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe)
{
  return u4_stub;
}

/* half:hume:bach:pitt
*/
u4_type
_hume_half(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_axis cap)
{
  u4_lane lan = p->lane;
  u4_noun p_sub, q_sub;

  if ( u4_n_eq(u4_atom_atom, sub) ) {
    return u4_atom_blot;
  }
  else if ( u4_n_eq(u4_atom_blot, sub) ) {
    return u4_atom_blot;
  }
  else if ( u4_n_eq(u4_atom_blur, sub) ) {
    return u4_atom_blur;
  }
  else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
    if ( u4_n_eq(u4_atom_2, cap) ) {
      return p_sub;
    } else return q_sub;
  }
  else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
    if ( u4_n_eq(u4_atom_2, cap) ) {
      return p_sub;
    } else return q_sub;
  }
  else if ( u4_b_p(sub, u4_atom_cube, &p_sub) ) 
}

/* nest:hume:bach:pitt
*/
u4_flag
_hume_nest(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_type bon)
{
  return u4_stub;
}

/* peek:hume:bach:pitt
*/
u4_type
_hume_peek(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_axis bow)
{
  u4_lane lan = p->lane;

  if ( u4_n_eq(u4_noun_1, bow) ) {
    return sub;
  } else {
    _hume_slip(p, &sub, &bar, &axe, u4_op_tip(bow));

    return _hume_peek(p, sub, bar, axe, u4_op_tap(lan, bow));
  }
}

/* slip:hume:bach:pitt
*/
void
_hume_slip(u4_pitt p,
           u4_type *sub,
           u4_rail *bar,
           u4_axis *axe,
           u4_axis cap)
{
}

/* snap:hume:bach:pitt
*/
u4_type
_hume_snap(u4_pitt p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_type bon)
{
  return u4_stub;
}
