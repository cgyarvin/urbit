/* watt/gull.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* size:gull:crow
*/
u4_atom
_gull_size(u4_crow p,
           u4_spec dab)
{
  u4_lane lan = p->lan;
  u4_noun p_dab, q_dab;

  if ( u4_b_p(dab, u4_atom_none, &p_dab) ) {
    return u4_noun_0;
  }
  else if ( u4_b_pq(dab, u4_atom_leaf, &p_dab, &q_dab) ) {
    return u4_noun_1;
  }
  else if ( u4_b_fork(dab, &p_dab, &q_dab) ) {
    return u4_op_add(lan, _gull_size(p, p_dab), _gull_size(p, q_dab));
  }
  else {
    u4_err(lan, "dab", dab);

    return u4_trip;
  }
}

/* fill:gull:crow
*/
u4_spec
_gull_fill(u4_crow p,
           u4_spec dab,
           u4_menu sem)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(sem) ) {
    return dab;
  }
  else {
    u4_noun i_sem = u4_ch(sem);
    u4_noun t_sem = u4_ct(sem);
    u4_noun pi_sem = u4_ch(i_sem);
    u4_noun qi_sem = u4_ct(i_sem);
    u4_noun pyr    = u4_kt(lan, u4_atom_leaf, pi_sem, qi_sem);
    u4_noun p_dab;

    if ( u4_b_p(dab, u4_atom_none, &p_dab) ) {
      return _gull_fill(p, pyr, t_sem);
    }
    else {
      return _gull_fill(p, u4_kc(lan, pyr, dab), t_sem);
    }
  }
}

/* look:gull:crow
*/
  static u4_unit
  _gull_look_a(u4_crow p,
               u4_spec dab,
               u4_term cog,
               u4_axis axe)
  {
    u4_lane lan = p->lan;
    u4_noun p_dab, q_dab;

    if ( u4_b_p(dab, u4_atom_none, &p_dab) ) {
      return u4_noun_0;
    }
    else if ( u4_b_pq(dab, u4_atom_leaf, &p_dab, &q_dab) ) {
      if ( u4_n_eq(p_dab, cog) ) {
        return u4_kt(lan, u4_noun_0, axe, q_dab);
      }
      else return u4_noun_0;
    }
    else if ( u4_b_fork(dab, &p_dab, &q_dab) ) {
      u4_unit hut = _gull_look_a(p, p_dab, cog, u4_op_peg(lan, axe, u4_noun_2));
      u4_unit zig = _gull_look_a(p, q_dab, cog, u4_op_peg(lan, axe, u4_noun_3));

      if ( u4_n_zero(hut) ) return zig;
      if ( u4_n_zero(zig) ) return hut;

      return _crow_fail(p, "gull");
    }
    else return u4_trip;
  }
u4_unit
_gull_look(u4_crow p,
           u4_spec dab,
           u4_term cog)
{
  return _gull_look_a(p, dab, cog, u4_noun_1);
}
