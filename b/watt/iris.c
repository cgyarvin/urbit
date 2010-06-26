/* watt/iris.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* burn:iris:rose:crow
*/
  static u4_type
  _iris_burn_sint(u4_crow, u4_type, u4_rail, u4_axis, u4_flag, u4_tack);

  static u4_type
  _iris_burn_dext(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_flag vef,
                  u4_tack tac)
  {
    u4_lane lan = p->lan;
    u4_noun p_tac, q_tac;
    u4_noun p_sub, q_sub;

    if ( u4_n_zero(tac) ) {
      return sub;
    }
    else if ( u4_b_p(tac, u4_atom_leaf, &p_tac) ) {
      return _iris_snap(p, sub, bar, axe, p_tac);
    }
    else if ( u4_b_pq(tac, u4_atom_name, &p_tac, &q_tac) ) {
      if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
        if ( u4_n_eq(p_sub, p_tac) ) {
          return u4_kt
            (lan, 
             u4_atom_face, 
             p_tac, 
             _iris_burn_dext(p, q_sub, bar, axe, vef, q_tac));
        }
        else {
          return u4_kt
            (lan,
             u4_atom_face,
             p_tac,
             _iris_burn_dext(p, sub, bar, axe, vef, q_tac));
        }
      }
      else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) )
      {
        return _iris_burn_sint(p, sub, bar, axe, vef, tac);
      }
      else {
        return u4_kt
          (lan,
           u4_atom_face,
           p_tac,
           _iris_burn_dext(p, sub, bar, axe, vef, q_tac));
      }
    }
    else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
      if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
        u4_noun l_sub, l_bar, l_axe;
        u4_noun r_sub, r_bar, r_axe;

        l_sub = sub; l_bar = bar; l_axe = axe;
        _iris_slip(p, &l_sub, &l_bar, &l_axe, u4_noun_2);

        r_sub = sub; r_bar = bar; r_axe = axe;
        _iris_slip(p, &r_sub, &r_bar, &r_axe, u4_noun_3);

        return u4_kt
          (lan,
           u4_atom_cell,
           _iris_burn_dext(p, l_sub, l_bar, l_axe, vef, p_tac),
           _iris_burn_dext(p, r_sub, r_bar, r_axe, vef, q_tac));
      }
      else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
        u4_noun l_sub, l_bar, l_axe;
        u4_type ham;

        l_sub = sub; l_bar = bar; l_axe = axe;
        _iris_slip(p, &l_sub, &l_bar, &l_axe, u4_noun_2);

        ham = _iris_burn_dext(p, l_sub, l_bar, l_axe, vef, p_tac);
        sub = u4_kt(lan, u4_atom_core, ham, q_sub);

        return u4_or(vef, _rose_fine(p, sub));
      }
      else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ||
                u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) )
      {
        return _iris_burn_sint(p, sub, bar, axe, vef, tac);
      }
      else {
        u4_noun poq = u4_kt
          (lan,
           u4_atom_cell,
           _iris_half(p, sub, bar, axe, u4_noun_2),
           _iris_half(p, sub, bar, axe, u4_noun_3));

        return _iris_burn_dext(p, poq, bar, axe, vef, tac);
      }
    }
    else return u4_trip;
  }
  static u4_unit
  _iris_burn_swim(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_flag vef,
                  u4_tack tac)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit yop = _iris_burn_swim(p, p_sub, bar, axe, vef, tac);
      u4_unit paf = _iris_burn_swim(p, q_sub, bar, axe, vef, tac);

      if ( u4_n_zero(yop) ) {
        return paf;
      } else if ( u4_n_zero(paf) ) {
        return yop;
      }
      else {
        return u4_kc
          (lan,
           u4_noun_0,
           u4_kt
            (lan,
             u4_atom_fork, u4_ct(yop), u4_ct(paf)));
      }
    }
    else {
      if ( _iris_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else {
        return u4_kc
          (lan, u4_noun_0, _iris_burn_dext(p, sub, bar, axe, vef, tac));
      }
    }
  }
  static u4_type
  _iris_burn_sint(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_flag vef,
                  u4_tack tac)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return u4_kt
        (lan, 
         u4_atom_face,
         p_sub,
         _iris_burn_dext(p, q_sub, bar, axe, vef, tac));
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_ct(_iris_burn_swim(p, sub, bar, axe, vef, tac));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return u4_kt
        (lan, 
         u4_atom_fuse,
         _iris_burn_dext(p, p_sub, bar, axe, vef, _lark_dull(p, sub, tac)),
         _iris_burn_dext(p, q_sub, u4_kc(lan, p_sub, bar), axe, vef, tac));
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      return _iris_burn_dext
        (p, _rose_repo(p, p_sub, q_sub), bar, axe, vef, tac); 
    }
    else return u4_trip;
  }
u4_type
_iris_burn(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_flag vef,
           u4_tack tac)
{
  return _iris_burn_dext(p, sub, bar, axe, vef, tac);
}

/* cull:iris:rose:crow
*/
  static u4_flag
  _iris_cull_a(u4_crow p,
               u4_type sub,
               u4_rail bar,
               u4_axis axe)
  {
    if ( u4_n_zero(bar) ) {
      return u4_no;
    }
    else if ( _rose_orth(p, sub, u4_ch(bar)) ) {
      return u4_yes;
    }
    else return _iris_cull_a(p, sub, u4_ct(bar), axe);
  }
u4_flag
_iris_cull(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe)
{
  if ( _rose_null(p, sub) ) {
    return u4_yes;
  }
  else {
    return _iris_cull_a(p, sub, bar, axe);
  }
}

/* find:iris:rose:crow
*/
  static u4_unit _iris_find_main
    (u4_crow, u4_type, u4_rail, u4_axis, u4_pool, u4_term);

  static u4_unit
  _iris_find_half(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_term cog,
                  u4_axis cap)
  {
    _iris_slip(p, &sub, &bar, &axe, cap);

    return _iris_find_main(p, sub, bar, axe, gil, cog);
  }
  static u4_unit
  _iris_find_swim(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_term cog)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit yop = _iris_find_swim(p, p_sub, bar, axe, gil, cog);
      u4_unit paf = _iris_find_swim(p, q_sub, bar, axe, gil, cog);

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
          else return _crow_fail(p, "fork conflict");
        }
        else if ( u4_n_zero(gam) ) {
          return _crow_fail(p, "fork conflict");
        }
        else {
          u4_plan u_lep = u4_ct(lep);
          u4_plan u_gam = u4_ct(gam);

          if ( !u4_n_eq(u4_ch(u_lep), u4_ch(u_gam)) ||
               !u4_n_eq(u4_ch(u4_ct(u_lep)), u4_ch(u4_ct(u_gam))) )
          {
            return u4_kc
              (lan,
               u4_noun_0,
               u4_kt
                (lan, 
                 u4_ch(u_lep),
                 u4_ch(u4_ct(u_lep)),
                 u4_kt
                  (lan,
                   u4_atom_fork,
                   u4_ct(u4_ct(u_lep)),
                   u4_ct(u4_ct(u_gam)))));
          }
          else return _crow_fail(p, "fork conflict");
        }
      }
    }
    else {
      if ( _iris_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else {
        return u4_kc
          (lan, u4_noun_0, _iris_find_main(p, sub, bar, axe, gil, cog));
      }
    }
  }
  static u4_unit
  _iris_find_main(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_term cog)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_n_eq(u4_atom_atom, sub) ||
         u4_n_eq(u4_atom_blur, sub) ||
         u4_n_eq(u4_atom_blot, sub) ||
         u4_b_p(sub, u4_atom_cube, &p_sub) )
    {
      return u4_noun_0;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      u4_unit taf = _iris_find_half(p, sub, bar, axe, gil, cog, u4_noun_2);
      u4_unit bov = _iris_find_half(p, sub, bar, axe, gil, cog, u4_noun_3);

      if ( u4_n_zero(taf) ) {
        return bov;
      }
      else if ( u4_n_zero(bov) ) {
        return taf;
      }
      else return _crow_fail(p, "cell conflict");
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      u4_spec dab;
      u4_unit zem;

      if ( !u4_b_p(q_sub, u4_atom_hard, &dab) ) {
        u4_b_pq(q_sub, u4_atom_soft, 0, &dab);
      }
      zem = _gull_look(p, dab, cog);
      if ( u4_n_zero(zem) ) {
        return _iris_find_half(p, sub, bar, axe, gil, cog, u4_noun_2);
      }
      else return 
        u4_kc
          (lan, 
           u4_noun_0, 
           u4_kt
            (lan, 
             axe, 
             u4_kq
              (lan, 
               u4_noun_0, 
               u4_ch(u4_ct(zem)),
               sub,
               u4_ct(u4_ct(zem))),
             sub));
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      if ( u4_n_eq(cog, p_sub) ) {
        return u4_kq
          (lan, u4_noun_0, axe, u4_noun_0, sub);
      }
      else return u4_noun_0;
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit foz = _iris_find_swim(p, sub, bar, axe, gil, cog);

      if ( u4_n_zero(foz) ) {
        return _crow_fail(p, "fork failure");
      }
      return u4_ct(foz);
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      u4_unit hax = _iris_find_main
        (p, p_sub, bar, axe, gil, cog);
      u4_unit yor = _iris_find_main
        (p, q_sub, u4_kc(lan, p_sub, bar), axe, gil, cog);

      if ( u4_n_zero(yor) ) {
        if ( u4_n_zero(hax) ) {
          return u4_noun_0;
        }
        else {
          u4_noun u_hax = u4_ct(hax);
          u4_noun pu_hax = u4_ch(u_hax);
          u4_noun qu_hax = u4_ch(u4_ct(u_hax));
          u4_noun ru_hax = u4_ct(u4_ct(u_hax));

          return u4_kc
            (lan, 
             u4_noun_0,
             u4_kt
              (lan,
               pu_hax,
               qu_hax,
               u4_kt
                (lan,
                 u4_atom_fuse,
                 ru_hax,
                 _iris_peek
                  (p, q_sub, u4_kc(lan, p_sub, bar), axe, pu_hax))));
        }
      }
      else {
        u4_noun u_yor = u4_ct(yor);
        u4_noun pu_yor = u4_ch(u_yor);
        u4_noun qu_yor = u4_ch(u4_ct(u_yor));
        u4_noun ru_yor = u4_ct(u4_ct(u_yor));

        if ( u4_n_zero(hax) ) {
          return u4_kc
            (lan, 
             u4_noun_0,
             u4_kt
              (lan,
               pu_yor,
               qu_yor,
               u4_kt
                (lan,
                 u4_atom_fuse,
                 _iris_peek(p, p_sub, bar, axe, pu_yor),
                 ru_yor)));
        }
        else {
          u4_noun u_hax = u4_ct(hax);
          u4_noun pu_hax = u4_ch(u_hax);
          u4_noun qu_hax = u4_ch(u4_ct(u_hax));
          u4_noun ru_hax = u4_ct(u4_ct(u_hax));

          if ( !(u4_n_eq(pu_hax, pu_yor) && u4_n_eq(qu_hax, qu_yor)) ) {
            ru_hax = _iris_peek(p, p_sub, bar, axe, pu_yor);
          }
          return u4_kc
            (lan, 
             u4_noun_0,
             u4_kt
              (lan,
               pu_yor,
               qu_yor,
               u4_kt(lan, u4_atom_fuse, ru_hax, ru_yor)));
        }
      }
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      u4_noun dit = u4_kc(lan, bar, sub);

      if ( u4_bag_in(dit, gil) ) {
        return u4_noun_0;
      } else {
        return _iris_find_main
          (p,
           _rose_repo(p, p_sub, q_sub), 
           bar,
           axe,
           u4_bag_add(lan, dit, gil), 
           cog);
      }
    }
    else return u4_trip;
  }
u4_plan
_iris_find(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_term cog)
{
  return u4_ct(_iris_find_main(p, sub, bar, axe, u4_noun_0, cog));
}

/* fish:iris:rose:crow
*/
  static u4_tool
  _iris_fish_slip(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_axis had)
  {
    _iris_slip(p, &sub, &bar, &axe, had);
    return _iris_fish(p, sub, bar, axe);
  }
  static u4_unit
  _iris_fish_swim(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit doz = _iris_fish_swim(p, p_sub, bar, axe);
      u4_unit ryg = _iris_fish_swim(p, q_sub, bar, axe);
    
      if ( u4_n_zero(doz) ) return ryg;
      else if ( u4_n_zero(ryg) ) return doz;
      else return u4_kc
        (lan, u4_noun_0, 
              _lily_flor(p, u4_ct(doz), u4_ct(ryg)));
    }
    else {
      if ( _iris_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else {
        return u4_kc
          (lan, u4_noun_0, _iris_fish(p, sub, bar, axe));
      }
    }
  }
u4_tool
_iris_fish(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe)
{
  u4_lane lan = p->lan;
  u4_noun p_sub, q_sub;

  if ( u4_n_eq(u4_atom_atom, sub) ) {
    return _lily_flop
      (p, u4_kt(lan, u4_noun_4, u4_noun_0, axe));
  }
  else if ( u4_n_eq(u4_atom_blur, sub) ) {
    return u4_kc(lan, u4_noun_1, u4_noun_0);
  }
  else if ( u4_n_eq(u4_atom_blot, sub) ) {
    return u4_kc(lan, u4_noun_1, u4_noun_1);
  }
  else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
    return u4_kc(lan, u4_noun_0, u4_noun_0);
  }
  else if ( u4_b_p(sub, u4_atom_cube, &p_sub) ) {
    return u4_kt
      (lan, u4_noun_6, 
            u4_kc(lan, u4_noun_1, p_sub),
            u4_kc(lan, u4_noun_0, axe));
  }
  else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
    return _lily_flan
      (p,
       u4_kt(lan, u4_noun_4, u4_noun_0, axe),
       _lily_flan
        (p, _iris_fish_slip(p, sub, bar, axe, u4_noun_2),
            _iris_fish_slip(p, sub, bar, axe, u4_noun_3)));
  }
  else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
    return u4_ct(_iris_fish_swim(p, sub, bar, axe));
  }
  else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
    return _lily_flan
      (p, 
       _iris_fish(p, p_sub, bar, axe),
       _iris_fish(p, q_sub, u4_kc(lan, p_sub, bar), axe));
  }
  else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
    /** XX: no recursion stop
    **/
    return _iris_fish(p, _rose_repo(p, p_sub, q_sub), bar, axe);
  }
  else return u4_trip;
}

/* half:iris:rose:crow
*/
  static u4_unit
  _iris_half_swim(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_axis had)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit doz = _iris_half_swim(p, p_sub, bar, axe, had);
      u4_unit ryg = _iris_half_swim(p, q_sub, bar, axe, had);

      if ( u4_n_zero(doz) ) return ryg;
      else if ( u4_n_zero(ryg) ) return doz;
      else return u4_kc
        (lan, u4_noun_0, u4_kt(lan, u4_atom_fork, u4_ct(doz), u4_ct(ryg)));
    }
    else {
      if ( _iris_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else {
        return u4_kc
          (lan, u4_noun_0, _iris_half(p, sub, bar, axe, had));
      }
    }
  }
u4_type
_iris_half(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_axis had)
{
  u4_lane lan = p->lan;
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
    if ( u4_n_eq(u4_noun_2, had) ) {
      return p_sub;
    } else return q_sub;
  }
  else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
    if ( u4_n_eq(u4_noun_2, had) ) {
      return p_sub;
    } else return u4_atom_blur;
  }
  else if ( u4_b_p(sub, u4_atom_cube, &p_sub) )  {
    if ( u4_n_atom(p_sub) ) {
      return u4_atom_blot;
    }
    else if ( u4_n_eq(u4_noun_2, had) ) {
      return u4_kc(lan, u4_atom_cube, u4_ch(p_sub));
    } else return u4_kc(lan, u4_atom_cube, u4_ct(p_sub));
  }
  else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
    return _iris_half(p, q_sub, bar, axe, had);
  }
  else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
    return u4_ct(_iris_half_swim(p, sub, bar, axe, had));
  }
  else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
    return u4_kt
      (lan, u4_atom_fuse,
            _iris_half(p, p_sub, bar, axe, had),
            _iris_half(p, q_sub, u4_kc(lan, p_sub, bar), axe, had));
  }
  else return u4_trip;
}

/* nest:iris:rose:crow
*/
  static u4_flag
  _iris_nest_sint
    (u4_crow, u4_type, u4_rail, u4_axis, u4_pool, u4_type, u4_rail, u4_axis); 
  static u4_flag
  _iris_nest_dext
    (u4_crow, u4_type, u4_rail, u4_axis, u4_pool, u4_type, u4_rail, u4_axis); 

  static u4_flag
  _iris_nest_dext_slip(u4_crow p,
                       u4_type sub,
                       u4_rail bar,
                       u4_axis axe,
                       u4_pool gil,
                       u4_type bon,
                       u4_rail nef,
                       u4_axis ful,
                       u4_axis had)
  {
    _iris_slip(p, &sub, &bar, &axe, had);
    _iris_slip(p, &bon, &nef, &ful, had);

    return _iris_nest_dext(p, sub, bar, axe, gil, bon, nef, ful);
  }
  static u4_flag
  _iris_nest_dext_swim(u4_crow p,
                       u4_type sub,
                       u4_rail bar,
                       u4_axis axe,
                       u4_pool gil,
                       u4_type bon,
                       u4_rail nef,
                       u4_axis ful)
  {
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_or
        (_iris_nest_dext_swim(p, p_sub, bar, axe, gil, bon, nef, ful),
         _iris_nest_dext_swim(p, q_sub, bar, axe, gil, bon, nef, ful));
    }
    else {
      if ( _iris_cull(p, sub, bar, axe) ) {
        return u4_no;
      }
      else return _iris_nest_dext
        (p, sub, bar, axe, gil, bon, nef, ful);
    }
  }
  static u4_flag
  _iris_nest_dext(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_type bon,
                  u4_rail nef,
                  u4_axis ful)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;
    u4_noun p_bon, q_bon;

    if ( u4_n_eq(sub, u4_atom_atom) ) {
      if ( u4_n_eq(bon, u4_atom_atom) ) {
        return u4_yes;
      }
      else if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
        return u4_say(u4_n_atom(p_bon));
      }
      else return _iris_nest_sint(p, sub, bar, axe, gil, bon, nef, ful);
    }
    else if ( u4_n_eq(sub, u4_atom_blur) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      if ( u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ) {
        return u4_say(u4_n_eq(sub, bon));
      }
      else return _iris_nest_sint(p, sub, bar, axe, gil, bon, nef, ful);
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
        return u4_and
          (_iris_nest_dext_slip
              (p, sub, bar, axe, gil, bon, nef, ful, u4_noun_2),
           _iris_nest_dext_slip
              (p, sub, bar, axe, gil, bon, nef, ful, u4_noun_3));
      }
      else {
        return _iris_nest_sint(p, sub, bar, axe, gil, bon, nef, ful);
      }
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return _iris_nest_dext(p, q_sub, bar, axe, gil, bon, nef, ful);
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      if ( u4_n_atom(bon) ||
           u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ||
           u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ||
           u4_b_p(bon, u4_atom_cube, &p_bon) ) 
      {
        return _iris_nest_dext_swim
          (p, sub, bar, axe, gil, bon, nef, ful);
      }
      else {
        return _iris_nest_sint(p, sub, bar, axe, gil, bon, nef, ful);
      }
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      u4_rail buz = u4_kc(lan, p_sub, bar);

      return u4_and
        (_iris_nest_dext(p, p_sub, bar, axe, gil, bon, nef, ful),
         _iris_nest_dext(p, q_sub, buz, axe, gil, bon, nef, ful));
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      u4_noun duq = u4_kq(lan, sub, bar, bon, nef);

      if ( u4_bag_in(duq, gil) ) {
        return u4_yes;
      } else {
        return _iris_nest_dext
          (p, _rose_repo(p, p_sub, q_sub),
              bar,
              axe,
              u4_bag_add(lan, duq, gil),
              bon, 
              nef, 
              ful);
      }
    }
    else {
      return u4_trip;
    }
  }
  static u4_flag
  _iris_nest_sint_swim(u4_crow p,
                       u4_type sub,
                       u4_rail bar,
                       u4_axis axe,
                       u4_pool gil,
                       u4_type bon,
                       u4_rail nef,
                       u4_axis ful)
  {
    u4_noun p_bon, q_bon;

    if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
      return u4_and
        (_iris_nest_sint_swim(p, sub, bar, axe, gil, p_bon, nef, ful),
         _iris_nest_sint_swim(p, sub, bar, axe, gil, q_bon, nef, ful));
    }
    else {
      if ( _iris_cull(p, bon, nef, ful) ) {
        return u4_yes;
      }
      else return _iris_nest_dext
        (p, sub, bar, axe, gil, bon, nef, ful);
    }
  }
  static u4_flag
  _iris_nest_sint(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_pool gil,
                  u4_type bon,
                  u4_rail nef,
                  u4_axis ful)
  {
    u4_lane lan = p->lan;
    u4_noun p_bon, q_bon;

    if ( u4_n_eq(bon, u4_atom_atom) || u4_n_eq(bon, u4_atom_blur) ) {
      return u4_no;
    }
    else if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
      return u4_no;
    }
    else if ( u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ) {
      bon = u4_kt(lan, u4_atom_cell, p_bon, u4_atom_blur);

      return _iris_nest_dext(p, sub, bar, axe, gil, bon, nef, ful);
    }
    else if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
      if ( u4_n_atom(p_bon) ) {
        return u4_no;
      }
      else {
        bon = u4_kt
          (lan, u4_atom_cell,
                u4_kc(lan, u4_atom_cube, u4_ch(p_bon)),
                u4_kc(lan, u4_atom_cube, u4_ct(p_bon)));

        return _iris_nest_dext(p, sub, bar, axe, gil, bon, nef, ful);
      }
    }
    else if ( u4_b_pq(bon, u4_atom_face, &p_bon, &q_bon) ) {
      return _iris_nest_dext(p, sub, bar, axe, gil, q_bon, nef, ful);
    }
    else if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
      return _iris_nest_sint_swim(p, sub, bar, axe, gil, bon, nef, ful);
    }
    else if ( u4_b_pq(bon, u4_atom_fuse, &p_bon, &q_bon) ) {
      u4_rail gok = u4_kc(lan, p_bon, nef);

      return u4_or
        (_iris_nest_dext(p, sub, bar, axe, gil, p_bon, nef, ful),
         _iris_nest_dext(p, sub, bar, axe, gil, q_bon, gok, ful));
    }
    else if ( u4_b_pq(bon, u4_atom_hold, &p_bon, &q_bon) ) {
      u4_noun duq = u4_kq(lan, sub, bar, bon, nef);

      if ( u4_bag_in(duq, gil) ) {
        return u4_yes;
      } else {
        return _iris_nest_dext
          (p, sub,
              bar,
              axe,
              u4_bag_add(lan, duq, gil),
              _rose_repo(p, p_bon, q_bon),
              nef, 
              ful);
      }
    }
    else return u4_trip;
  }
u4_flag
_iris_nest(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_type bon)
{
  if ( _rose_null(p, bon) ) {
    return u4_yes;
  }
  else if ( _rose_null(p, sub) ) {
    return u4_no;
  }
  else {
    u4_pool gil = u4_noun_0;
    u4_rail nef = u4_noun_0;
    u4_axis ful = u4_noun_1;

    return _iris_nest_dext(p, sub, bar, axe, gil, bon, nef, ful);
  }
}

/* peek:iris:rose:crow
*/
u4_type
_iris_peek(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_axis bow)
{
  u4_lane lan = p->lan;

  if ( u4_n_eq(u4_noun_1, bow) ) {
    return sub;
  } else {
    _iris_slip(p, &sub, &bar, &axe, u4_op_tip(bow));

    return _iris_peek(p, sub, bar, axe, u4_op_tap(lan, bow));
  }
}

/* slip:iris:rose:crow
*/
  static u4_rail
  _iris_slip_a(u4_crow p,
               u4_rail bar,
               u4_axis had)
  {
    if ( u4_n_zero(bar) ) {
      return u4_noun_0;
    }
    else {
      return u4_kc
        (p->lan, _iris_half(p, u4_ch(bar), u4_noun_0, u4_noun_1, had),
                 _iris_slip_a(p, u4_ct(bar), had));
    } 
  }
void
_iris_slip(u4_crow p,
           u4_type *sub,
           u4_rail *bar,
           u4_axis *axe,
           u4_axis had)
{
  *sub = _iris_half(p, *sub, *bar, *axe, had);
  *bar = _iris_slip_a(p, *bar,  had);
  *axe = u4_op_peg(p->lan, *axe, had);
}

/* snap:iris:rose:crow
*/
  static u4_type
  _iris_snap_dext(u4_crow, u4_type, u4_rail, u4_axis, u4_type);
  static u4_type
  _iris_snap_sint(u4_crow, u4_type, u4_rail, u4_axis, u4_type);

  static u4_type
  _iris_snap_slip(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_type bon,
                  u4_axis had)
  {
    _iris_slip(p, &sub, &bar, &axe, had);
    return _iris_snap(p, sub, bar, axe, bon);
  }
  static u4_unit
  _iris_snap_swim(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_type bon)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      u4_unit qoz = _iris_snap_swim(p, p_sub, bar, axe, bon);
      u4_unit fyl = _iris_snap_swim(p, q_sub, bar, axe, bon);

      if ( u4_n_zero(qoz) ) return fyl;
      if ( u4_n_zero(fyl) ) return qoz;

      return u4_kt
        (lan, u4_atom_fork, u4_ct(qoz), u4_ct(fyl));
    }
    else {
      if ( _iris_cull(p, sub, bar, axe) ) {
        return u4_noun_0;
      }
      else if ( _rose_orth(p, sub, bon) ) {
        return u4_noun_0;
      }
      else {
        return u4_kc
          (lan, u4_noun_0, _iris_snap_dext(p, sub, bar, axe, bon));
      }
    }
  }
  static u4_type
  _iris_snap_dext(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_type bon)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;
    u4_noun p_bon, q_bon;

    if ( u4_n_eq(sub, u4_atom_atom) ||
         u4_n_eq(sub, u4_atom_blot) ||
         u4_n_eq(sub, u4_atom_blur) ||
         u4_b_p(sub, u4_atom_cube, &p_sub) ||
         u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) )
    {
      return bon;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
        return u4_kt
          (lan,
           u4_atom_cell,
           _iris_snap_slip(p, sub, bar, axe, p_bon, u4_noun_2),
           _iris_snap_slip(p, sub, bar, axe, q_bon, u4_noun_3));
      }
      else {
        return _iris_snap_sint(p, sub, bar, axe, bon);
      }
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      if ( u4_b_pq(bon, u4_atom_face, &p_bon, &q_bon) ) {
        return u4_kt
          (lan, u4_atom_face,
                p_sub,
                _iris_snap_dext(p, q_sub, bar, axe, q_bon));
      }
      else {
        return u4_kt
          (lan, u4_atom_face,
                p_sub,
                _iris_snap_dext(p, q_sub, bar, axe, bon));
      }
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_ct(_iris_snap_swim(p, sub, bar, axe, bon));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return _iris_snap_dext
        (p, q_sub, u4_kc(lan, p_sub, bar), axe, bon);
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      return _iris_snap_dext
        (p, _rose_repo(p, p_sub, q_sub), bar, axe, bon);
    }
    else return u4_trip;
  }
  static u4_type
  _iris_snap_sint(u4_crow p,
                  u4_type sub,
                  u4_rail bar,
                  u4_axis axe,
                  u4_type bon)
  {
    u4_lane lan = p->lan;
    u4_noun p_bon, q_bon;

    if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
      return u4_kt
        (lan, 
         u4_atom_fork, 
         _iris_snap_dext(p, sub, bar, axe, p_bon), 
         _iris_snap_dext(p, sub, bar, axe, q_bon));
    }
    else if ( u4_b_pq(bon, u4_atom_fuse, &p_bon, &q_bon) ) {
      return u4_kt
        (lan, 
         u4_atom_fuse, 
         _iris_snap_dext(p, sub, bar, axe, p_bon), 
         _iris_snap_dext(p, sub, bar, axe, q_bon));
    }
    else return bon;
  }
u4_type
_iris_snap(u4_crow p,
           u4_type sub,
           u4_rail bar,
           u4_axis axe,
           u4_type bon)
{
  return _iris_snap_dext(p, sub, bar, axe, bon);
}
