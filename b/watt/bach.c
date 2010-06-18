/* watt/bach.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* dope:bach:pitt
*/
  static u4_flag
  _bach_dope_hard(u4_pitt p,
                  u4_type sub,
                  u4_spec dab)
  {
    u4_noun p_dab, q_dab;

    if ( u4_b_pq(dab, u4_atom_none, &p_dab) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(dab, u4_atom_leaf, &p_dab, &q_dab) ) {
      return _bach_show(p, sub, q.dab);
    }
    else if ( u4_b_fork(dab, &p_dab, &q_dab) ) {
      return 
        u4_and(_bach_dope_hard(p, sub, p_dab), 
               _bach_dope_hard(p, sub, q_dab));
    }
  } 
  static u4_flag
  _bach_dope_soft(u4_pitt p,
                  u4_type sub,
                  u4_type gar,
                  u4_spec dab)
  {
    u4_lane lan = p->lan;

    if ( u4_b_pq(dab, u4_atom_none, &p_dab) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(dab, u4_atom_leaf, &p_dab, &q_dab) ) {
      if ( !_bach_show(p, sub, q_dab) ) {
        return u4_no;
      }
      else {
        u4_tool vac = _bach_make(p, sub, q_dab);
        u4_tool foh = _bach_make(p, gar, q_dab);

        return u4_say(u4_n_eq(vac, foh));
      }
    }
    else if ( u4_b_fork(dab, &p_dab, &q_dab) ) {
      return 
        u4_and(_bach_dope_hard(p, sub, p_dab), 
               _bach_dope_hard(p, sub, q_dab));
    }
  }
u4_flag
_bach_dope(u4_pitt p,
           u4_type sub)
{
  u4_lane lan = p->lane;
  u4_noun p_sub, q_sub, pq_sub, qq_sub;

  if ( !u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
    return u4_trip;
  }
  else {
    if ( u4_b_p(q_sub, u4_atom_hard, &pq_sub) ) {
      return _bach_dope_hard(p, sub, pq_sub);
    }
    else if ( u4_b_pq(q_sub, u4_atom_soft, &pq_sub, &qq_sub) ) {
      if ( u4_bag_in(sub, p->ver) ) {
        return u4_yes;
      }
      else {
        u4_pool faz = u4_bag_add(an, sub, p->ver);
        u4_pool ver;
        u4_flag dem;

        ver = p->ver;
        p->ver = faz;
        dem = _bach_dope_soft(p, sub, pq_sub, qq_sub);

        p->ver = ver;
        return dem;
      }
    }
    else return u4_trip;
  }
}

/* edit:bach:pitt
*/
u4_type
_bach_edit(u4_pitt p,
           u4_type sub,
           u4_list mut)
{
  u4_lane lan = p->lane;
  u4_tack tac = u4_k_cell(lan, u4_atom_none, u4_noun_0);

  tac = _reck_feed(p, sub, tac, mut);

  return _hume_burn(p, sub, u4_noun_0, u4_noun_1, u4_no, tac);
}

/* gain:bach:pitt
*/
  static u4_rack
  _bach_gain_hunt(u4_pitt, u4_type, u4_gene);

  static u4_rack
  _bach_gain_hunt_a(u4_pitt p,
                    u4_type sub,
                    u4_bank vof)
  {
    if ( u4_n_zero(vof) ) {
      return u4_noun_0;
    }
    else return u4_log_cat(p->lan, _bach_gain_hunt(p, sub, u4_ch(vof)),
                                   _bach_gain_hunt_a(p, sub, u4_ct(vof)));
  }
  static u4_rack
  _bach_gain_hunt(u4_pitt p,
                  u4_type sub,
                  u4_gene gen)
  {
    u4_lane lan = p->lane;
    u4_noun p_gen;

    if ( u4_b_pq(sub, u4_atom_like, &p_gen, &q_gen) ) {
      return u4_k_cell(lan, u4_k_cell(lan, p_gen, q_gen), u4_noun_0);
    }
    else if ( u4_b_pq(sub, u4_atom_sand, &p_gen) ) {
      return _bach_gain_hunt_a(p, sub, p_gen);
    }
  }
  static u4_type
  _bach_gain_gild(u4_pitt p,
                  u4_type sub,
                  u4_plot mut)
  {
    u4_lane lan = p->lane;

    return u4_k_trel
      (lan, 
       u4_atom_fuse,
       u4_hume_burn
        (p,
         u4_atom_blur,
         u4_noun_0,
         u4_no,
         _reck_feed(p, sub, u4_noun_0, mut)),
       sub);
  }
u4_type
_bach_gain(u4_pitt p,
           u4_type sub,
           u4_gene gen)
{
  u4_rack zet = _bach_gain_hunt(p, sub, gen);

  return _bach_gain_gild(p, sub, zet);
}

/* make:bach:pitt
*/
  u4_tool
  _bach_make_boil_a(u4_pitt p,
                    u4_type sub,
                    u4_list rem)
  {
    if ( u4_n_zero(rem) ) {
      return u4_noun_0;
    }
    else {
      u4_noun i_rem  = u4_ch(rem);
      u4_noun t_rem  = u4_ct(rem);
      u4_gene pi_rem = u4_ch(i_rem);
      u4_tool qi_rem = u4_ct(i_rem);
      u4_plan giz    = _bach_seek(p, sub, pi_rem);
      u4_axis p_giz  = u4_ch(giz);

      return u4_k_cell(lan, u4_k_cell(lan, u4_ch(giz), qi_rem),
                            _bach_make_boil_a(p, sub, t_rem));
    }
  }
  u4_tool
  _bach_make_boil(u4_pitt p,
                  u4_type sub,
                  u4_axis axe,
                  u4_list rem)
  {
    return _hill_hike(p, axe, _bach_make_boil_a(p, sub, rem));
  }
  u4_tool 
  _bach_bake(u4_pitt p,
             u4_type sub,
             u4_spec sep)
  {
    u4_lane lan = p->lan;
    u4_noun p_sep, q_sep;

    if ( u4_b_fork(sep, &p_sep, &q_sep) ) {
      return u4_k_cell(lan, _bach_bake(p, sub, p_sep),
                            _bach_bake(p, sub, q_sep));
    }
    else if ( u4_b_p(sep, u4_atom_none, &p_sep) ) {
      return u4_k_cell(lan, u4_noun_0, u4_noun_0);
    }
    else if ( u4_b_pq(sep, u4_atom_leaf, &p_sep, &q_sep) ) {
      return _bach_make(p, sub, q_sep);
    }
    else return u4_trip;
  }
  u4_noun
  _bach_make_a(u4_pitt p,
               u4_type sub,
               u4_rack dus)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(dus) ) {
      return u4_noun_0;
    }
    else {
      u4_noun i_dus = u4_ch(dus);
      u4_noun t_dus = u4_ct(dus);

      return u4_k_cell
        (lan,
         u4_k_cell(lan, u4_ch(i_dus), _bach_make(p, sub, u4_ct(i_dus))),
         t_dus);
    }
  }
u4_tool
_bach_make(u4_pitt p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lane;
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_pq(gen, u4_atom_bail, &p_gen) ) {
    return u4_k_cell(lan, u4_noun_0, u4_noun_0);
  }
  else if ( u4_b_pq(gen, u4_atom_boot, &p_gen) ) {
    return u4_trip;
  }
  else if ( u4_b_pq(gen, u4_atom_bump, &p_gen) ) {
    return u4_k_cell(lan, u4_noun_5, _bach_make(p, sub, p_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
    return _bach_make(p, sub, q_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
    return _hill_cons
      (p, _bach_make(p, sub, p_gen), _bach_make(p, sub, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_cool, &p_gen) ) {
    return _bach_make(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
    u4_tool guz;
    u4_atom bug;

    bug = p->bug;
    p->bug = u4_op_inc(lan, p->bug);

    guz = _bach_make(p, sub, p_gen);
    
    p->bug = bug;
    return guz;
  }
  else if ( u4_b_p(gen, u4_atom_deep, &p_gen) ) {
    return u4_k_cell(lan, u4_atom_4, _bach_make(p, sub, p_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_home, &p_gen, &q_gen) ) {
    return _bach_make(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_lift, &p_gen) ) {
    return _bach_make_bake(p, _bach_play(p, sub, gen), p_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
    u4_plan lar = _bach_seek(p, sub, p_gen);
    u4_axis p_lar = u4_ch(lar);
    u4_type r_lar = u4_ct(u4_ct(lar));

    if ( !u4_n_zero(u4_ch(u4_ct(lar))) ) {
      return _pitt_fail(m, "bad like");
    }
    else {
      return _hume_fish(p, r_lar, u4_noun_0, p_lar);
    }
  }
  else if ( u4_b_pq(gen, u4_atom_link, &p_gen, &q_gen) ) {
    return _hill_comb
      (p,
       _bach_make(p, sub, p_gen),
       _bach_make(p, _bach_play(p, sub, p_gen), q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_load, &p_gen) ) {
    return _bach_make_bake(p, _bach_play(p, sub, gen), p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_meta, &p_gen) ) {
    return u4_trip;
  }
  else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
    return _bach_make(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_nock, &p_gen) ) {
    return u4_k_cell(lan, u4_noun_3, _bach_make(p, sub, p_gen));
  }
  else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
    return u4_k_cell(lan, u4_noun_1, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_spot, &p_gen, &q_gen) ) {
    return _bach_make(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_sure, &p_gen, &q_gen) ) {
    return _bach_make(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_take, &p_gen, &q_gen) ) {
    u4_plan lar = _bach_seek(p, sub, p_gen);
    u4_noun rem = _bach_make_a(p, sub, q_gen);
    u4_axis p_lar = u4_ch(lar);
    u4_noun q_lar = u4_ch(u4_ct(lar));
    u4_type r_lar = u4_ct(u4_ct(lar));

    if ( u4_n_zero(q_lar) ) {
      return _bach_make_boil(p, r_lar, p_lar, rem);
    }
    else {
      u4_door uq_lar  = u4_ct(q_lar);
      u4_axis puq_lar = u4_ch(uq_lar);
      u4_type quq_lar = u4_ch(u4_ct(uq_lar));

      return u4_k_trel
        (lan,
         u4_noun_3,
         _bach_make_boil(p, quq_lar, p_lar, rem),
         u4_k_cell(lan, u4_noun_0, puq_lar));
    }
  }
  else if ( u4_b_pqr(gen, u4_atom_test, &p_gen, &q_gen, &r_gen) ) {
    return u4_k_qual
      (lan,
       u4_noun_2,
       _bach_make(p, sub, p_gen),
       _bach_make(p, _bach_gain(p, sub, p_gen), q_gen),
       _bach_make(p, sub, r_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_twin, &p_gen, &q_gen) ) {
    return u4_k_trel
      (lan,
       u4_noun_6,
       _bach_make(p, sub, p_gen),
       _bach_make(p, sub, q_gen));
  }
}

/* null:bach:pitt
*/
  static u4_flag
  _bach_null_a(u4_pitt p,
               u4_type sub,
               u4_pool hem)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_n_eq(sub, u4_atom_atom) ) {
      return u4_no;
    }
    else if ( u4_n_eq(sub, u4_atom_blur) ) {
      return u4_no;
    }
    else if ( u4_n_eq(sub, u4_atom_blot) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      return u4_or(_bach_null_a(p, p_sub, hem), _bach_null_a(p, q_sub, hem));
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      return _bach_null_a(p, p_sub, hem);
    }
    else if ( u4_b_p(sub, u4_atom_cube, &p_sub) ) {
      return u4_no;
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return _bach_null_a(p, q_sub, hem);
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_and(_bach_null_a(p, p_sub, hem), _bach_null_a(p, q_sub, hem));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return _bach_orth(p, p_sub, q_sub);
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      if ( u4_bag_in(sub, hem) ) {
        return u4_yes;
      } else {
        return _bach_null_a
          (p, _bach_repo(p, p_sub, q_sub), u4_bag_add(lan, sub, hem));
      }
    } 
  }
u4_flag
_bach_null(u4_pitt p,
           u4_type sub)
{
  return _bach_null_a(p, sub, u4_noun_0);
}

/* orth:bach:pitt
*/
  static u4_flag
  _bach_orth_a(u4_pitt p,
               u4_type sub,
               u4_type ref,
               u4_pool bol)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;
    u4_noun p_ref, q_ref;

    if ( u4_n_eq(sub, u4_atom_atom) ) {
      if ( u4_n_eq(ref, u4_atom_atom) ) {
        return u4_no;
      }
      else if ( u4_b_pq(ref, u4_atom_cell, &p_sub, &q_sub) ) {
        return u4_yes;
      }
      else return _bach_orth_a(p, ref, sub, bol);
    }
    else if ( u4_n_eq(sub, u4_atom_blur) ) {
      return u4_no;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      if ( u4_b_pq(ref, u4_atom_ref, &p_ref, &q_ref) ) {
        return u4_or(_bach_orth_a(p, p_sub, p_ref, bol),
                     _bach_orth_a(p, q_sub, q_ref, bol));
      }
      else {
        return _bach_orth_a(p, ref, sub, bol);
      }
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      return _bach_orth_a
        (p, u4_k_trel(lan, u4_atom_cell, p_sub, u4_atom_blur));
    }
    else if ( u4_b_p(sub, u4_atom_cube, &p_sub) ) {
      if ( u4_n_eq(u4_atom_atom, ref) ) {
        return u4_n_atom(p_sub) ? u4_no : u4_yes;
      }
      else if ( u4_b_p(ref, u4_atom_cube, &p_ref) ) {
        return u4_say(u4_n_eq(p_sub, p_ref));
      }
      else if ( u4_b_pq(ref, u4_atom_cell, &p_ref, &q_ref) ) {
        if ( u4_n_atom(p_sub) ) {
          return u4_yes;
        } else {
          u4_type hed = u4_k_cell(lan, u4_atom_cube, u4_ch(p_sub));
          u4_type tal = u4_k_cell(lan, u4_atom_cube, u4_ct(p_sub));

          return u4_or(_bach_orth_a(p, hed, p_ref, bol),
                       _bach_orth_a(p, tal, q_ref, bol));
        }
      }
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return _bach_orth_a(p, q_sub, ref, bol);
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_and(_bach_orth_a(p, p_sub, ref),
                    _bach_orth_a(p, q_sub, ref));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return u4_or(_bach_orth_a(p, p_sub, ref),
                   _bach_orth_a(p, q_sub, ref));
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      u4_noun gob = u4_k_cell(lan, sub, ref);

      if ( u4_bag_in(gob, bol) ) {
        return u4_yes;
      } else {
        return _bach_orth_a
          (p, _bach_repo(p, p_sub, q_sub), ref, u4_bag_add(lan, gob, bol));
      }
    } 
  }
u4_flag
_bach_orth(u4_pitt p,
           u4_type sub,
           u4_type ref)
{
  return _bach_orth_a(p, sub, ref, u4_noun_0);
}

/* play:bach:pitt
*/
u4_type
_bach_play(u4_pitt p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lane;
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_pq(gen, u4_atom_bail, &p_gen) ) {
    return u4_atom_blot;
  }
  else if ( u4_b_pq(gen, u4_atom_boot, &p_gen) ) {
    return u4_trip;
  }
  else if ( u4_b_pq(gen, u4_atom_bump, &p_gen) ) {
    return u4_atom_atom;
  }
  else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
    return _bach_play(p, sub, p_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
    return u4_k_trel
      (lan, u4_atom_cell,
            _bach_play(p, sub, p_gen),
            _bach_play(p, sub, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_cool, &p_gen) ) {
    return _bach_play(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
    u4_type soq;
    u4_atom bug;

    bug = p->bug;
    p->bug = u4_op_inc(lan, p->bug);

    soq = _bach_play(p, sub, p_gen);
    
    p->bug = bug;
    return soq;
  }
  else if ( u4_b_p(gen, u4_atom_deep, &p_gen) ) {
    return u4_k_trel
      (lan,
       u4_atom_fork,
       u4_k_cell(lan, u4_atom_rock, u4_noun_0),
       u4_k_cell(lan, u4_atom_rock, u4_noun_1));
  }
  else if ( u4_b_pq(gen, u4_atom_home, &p_gen, &q_gen) ) {
    return _bach_play(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_lift, &p_gen) ) {
    return u4_k_trel
      (lan, u4_atom_core, 
            sub, 
            u4_k_trel
              (lan,
               u4_atom_soft,
               sub,
               _gunn_fill(p, p_gen)));
  }
  else if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
    return u4_k_trel
      (lan,
       u4_atom_fork,
       u4_k_cell(lan, u4_atom_rock, u4_noun_0),
       u4_k_cell(lan, u4_atom_rock, u4_noun_1));
  }
  else if ( u4_b_pq(gen, u4_atom_link, &p_gen, &q_gen) ) {
    return _bach_play(p, _bach_play(p, sub, p_gen), q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_load, &p_gen) ) {
    return u4_k_cell
      (lan, u4_atom_core,
            sub,
            u4_k_cell
              (lan, 
               u4_atom_hard,
               _gunn_fill(p, p_gen)));
  }
  else if ( u4_b_p(gen, u4_atom_meta, &p_gen) ) {
    return u4_trip;
  }
  else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
    return u4_k_trel(lan, u4_atom_face, p_gen, _bach_play(p, sub, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_nock, &p_gen) ) {
    return u4_atom_blur;
  }
  else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
    return u4_k_cell(lan, u4_atom_cube, p_gen); 
  }
  else if ( u4_b_p(gen, u4_atom_spot, &p_gen, &q_gen) ) {
    return _bach_play(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_sure, &p_gen, &q_gen) ) {
    return _bach_play(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_take, &p_gen, &q_gen) ) {
    u4_plan lar = _bach_seek(p, sub, p_gen);
    u4_noun huz = _bach_play_a(p, sub, q_gen);
    u4_axis p_lar = u4_ch(lar);
    u4_noun q_lar = u4_ch(u4_ct(lar));
    u4_type r_lar = u4_ct(u4_ct(lar));

    if ( u4_n_zero(q_lar) ) {
      return _bach_edit(p, r_lar, huz);
    }
    else {
      u4_door uq_lar  = u4_ct(q_lar);
      u4_axis puq_lar = u4_ch(uq_lar);
      u4_type quq_lar = u4_ch(u4_ct(uq_lar));
      u4_type ruq_lar = u4_ct(u4_ct(uq_lar));

      return u4_k_trel
        (lan,
         u4_atom_hold,
         _bach_edit(p, quq_lar, huz),
         ruq_lar);
    }
  }
  else if ( u4_b_pqr(gen, u4_atom_test, &p_gen, &q_gen, &r_gen) ) {
    return u4_k_trel
      (lan,
       u4_atom_fork,
       _bach_play(p, _bach_gain(p, sub, p_gen), q_gen),
       _bach_play(p, sub, r_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_twin, &p_gen, &q_gen) ) {
    return u4_k_trel
      (lan,
       u4_atom_fork,
       u4_k_cell(lan, u4_atom_rock, u4_noun_0),
       u4_k_cell(lan, u4_atom_rock, u4_noun_1));
  }
}

/* repo:bach:pitt
*/
u4_type
_bach_repo(u4_pitt p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun vax = u4_k_cell(lan, sub, gen);

  if ( u4_bag_in(vax, p->fan) ) {
    return _pitt_fail(p, "inference recursion");
  }
  else {
    u4_noun fan;
    u4_type gex;

    fan = p->fan;
    p->fan = u4_bag_add(lan, vax, p->fan);

    gex = _bach_play(p, sub, gen);
    p->fan = fan;
    return gex;
  }
}

/* safe:bach:pitt
*/
u4_flag
_bach_safe(u4_pitt p,
           u4_type sub,
           u4_plot mut)
{
  u4_tack tac = _reck_feed(p, sub, u4_noun_0, mut);

  _hume_burn(p, tac, u4_noun_0, u4_noun_1, u4_yes, mut);
  return u4_yes;
}

/* seek:bach:pitt
*/
  static u4_plan
  _bach_seek_a(u4_pitt p,
               u4_type sub,
               u4_rope rop,
               u4_axis axe,
               u4_unit act)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(rop) ) {
      return u4_k_trel(lan, axe, act, sub);
    }
    else {
      u4_noun i_rop = u4_ch(rop);
      u4_noun t_rop = u4_ct(rop);
      u4_noun pi_rop;

      if ( u4_n_atom(i_rop) ) {
        return _bach_seek_a
          (p, sub, 
              u4_k_cell(lan, u4_k_cell(lan, u4_atom_port, i_rop), t_rop),
              axe,
              act);
      }
      else if ( u4_b_pq(i_rop, u4_atom_frag, &pi_rop) ) {
        return _bach_seek_a
          (p, _hume_peek(p, sub, u4_noun_0, u4_noun_1, pi_rop), 
              t_rop,
              u4_noun_0,
              u4_op_peg(lan, axe, pi_rop));
      }
      else if ( u4_b_pq(i_rop, u4_atom_port, &pi_rop) ) {
        u4_plan sap = _hume_find(p, sub, u4_noun_0, u4_noun_1, pi_rop);
        u4_axis p_sap = u4_ch(sap);
        u4_unit q_sap = u4_ch(u4_ct(sap));
        u4_type r_sap = u4_ct(u4_ct(sap));

        return _bach_seek_a
          (p, r_sap, t_rop, u4_op_peg(lan, axe, p_sap), q_sap);
      }
      else if ( u4_b_pq(i_rop, u4_atom_pith, &pi_rop) ) {
        u4_plan sap = _hume_find(p, sub, u4_noun_0, u4_noun_1, pi_rop);
        u4_axis p_sap = u4_ch(sap);
        u4_unit q_sap = u4_ch(u4_ct(sap));
        u4_type r_sap = u4_ct(u4_ct(sap));
        
        return _bach_seek_a
          (p, r_sap, t_rop, u4_op_peg(lan, axe, p_sap), u4_noun_0);
      }
    }
  }
u4_plan
_bach_seek(u4_pitt p,
           u4_type sub,
           u4_gene gen)
{
  u4_rope rop = _pitt_rake(p, gen);

  return _bach_seek_a(p, sub, rop);
}

/* show:bach:pitt
*/
  u4_flag
  _bach_show_nest(u4_pitt p,
                  u4_type sub,
                  u4_type bon)
  {
    if ( !u4_so(_hume_nest(p, u4_atom_atom, u4_noun_0, u4_noun_1, bon)) ) {
      return _pitt_fail(p, "nest: bump");
    }
    else return u4_yes;
  }
u4_flag
_bach_show(u4_pitt p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lan;

  if ( u4_b_pq(gen, u4_atom_bail, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_pq(gen, u4_atom_boot, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_pq(gen, u4_atom_bump, &p_gen) ) {
    return _bach_show(p, sub, p_gen) &&
           _bach_show_nest(p, u4_atom_atom, _bach_play(p, sub, p_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
    u4_type deg = _bach_play(p, sub, p_gen);
    u4_type bon = _bach_play(p, sub, q_gen);

    return _bach_show_nest(p, deg, bon);
  }
  else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
    return u4_and(_bach_show(p, sub, p_gen), _bach_show(p, sub, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_cool, &p_gen) ) {
    return _bach_show(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
    u4_flag zic;
    u4_atom bug;

    bug = p->bug;
    p->bug = u4_op_inc(lan, p->bug);

    zic = _bach_show(p, sub, p_gen);
    
    p->bug = bug;
    return zic;
  }
  else if ( u4_b_p(gen, u4_atom_deep, &p_gen) ) {
    return _bach_show(p, sub, p_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_home, &p_gen, &q_gen) ) {
    return _bach_show(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_lift, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
    return u4_and(_bach_show(p, sub, p_gen), 
                  _bach_show(p, sub, q_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_link, &p_gen, &q_gen) ) {
    return _u4_and(_bach_show(p, sub, p_gen),
                   _bach_show(p, _bach_play(p, sub, p_gen), q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_load, &p_gen) ) {
    return _bach_dope(p, sub, _bach_play(p, sub, gen)); 
  }
  else if ( u4_b_p(gen, u4_atom_meta, &p_gen) ) {
    return u4_trip;
  }
  else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
    return _bach_show(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_nock, &p_gen) ) {
    return _bach_show(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_p(gen, u4_atom_spot, &p_gen, &q_gen) ) {
    return _bach_show(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_sure, &p_gen, &q_gen) ) {
    u4_type deg = _bach_play(p, sub, p_gen);
    u4_type bon = _bach_play(p, sub, q_gen);

    return _bach_show_nest(p, deg, bon);
  }
  else if ( u4_b_p(gen, u4_atom_take, &p_gen, &q_gen) ) {
    u4_plan lar = _bach_seek(p, sub, p_gen);
    u4_noun huz = _bach_play_a(p, sub, q_gen);
    u4_axis p_lar = u4_ch(lar);
    u4_noun q_lar = u4_ch(u4_ct(lar));
    u4_type r_lar = u4_ct(u4_ct(lar));

    if ( u4_n_zero(q_lar) ) {
      return _bach_safe(p, r_lar, huz);
    }
    else {
      u4_door uq_lar  = u4_ct(q_lar);
      u4_type quq_lar = u4_ch(u4_ct(uq_lar));

      return _bach_safe(p, quq_lar, huz);
    }
  }
  else if ( u4_b_pqr(gen, u4_atom_test, &p_gen, &q_gen, &r_gen) ) {
    return u4_k_qual
      (lan,
       u4_noun_2,
       _bach_make(p, sub, p_gen),
       _bach_make(p, _bach_gain(p, sub, p_gen), q_gen),
       _bach_make(p, sub, r_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_twin, &p_gen, &q_gen) ) {
    return u4_and
      (_bach_safe(p, sub, p_gen),
       _bach_safe(p, sub, q_gen));
  }
}
