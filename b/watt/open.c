/* watt/open.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

#define _open_p(stem) \
  if ( u4_b_p(gen, u4_atom_##stem, &p_gen) ) { \
    return _open_in_##stem(p, p_gen); \
  }

#define _open_pq(stem) \
  if ( u4_b_pq(gen, u4_atom_##stem, &p_gen, &q_gen) ) { \
    return _open_in_##stem(p, p_gen, q_gen); \
  }

#define _open_pqr(stem) \
  if ( u4_b_pqr(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen) ) {\
    return _open_in_##stem(p, p_gen, q_gen, r_gen); \
  }

#define _open_pqrs(stem) \
  if ( u4_b_pqrs(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen, &s_gen) ) {\
    return _open_in_##stem(p, p_gen, q_gen, r_gen, s_gen); \
  }

#define _open_do_p(stem)  \
  static u4_gene _open_in_##stem \
    (u4_crow p, u4_noun p_gen)

#define _open_do_pq(stem)  \
  static u4_gene _open_in_##stem \
    (u4_crow p, u4_noun p_gen, u4_noun q_gen)

#define _open_do_pqr(stem)  \
  static u4_gene _open_in_##stem \
    (u4_crow p, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)

#define _open_do_pqrs(stem)  \
  static u4_gene _open_in_##stem \
    (u4_crow p, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen, u4_noun s_gen)

/* coin:open:crow
*/
  static u4_gene
  _open_coin(u4_crow, u4_gene);

  static u4_gene 
  _open_coin_fix(u4_crow p,
                 u4_gene gen,
                 u4_axis axe)
  {
    u4_lane lan = p->lan;
    u4_noun p_gen, q_gen;

    if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return _open_coin_fix(p, p_gen, axe);
    }
    else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, 
         u4_atom_cell,
         _open_coin_fix(p, p_gen, u4_op_peg(lan, axe, u4_noun_2)),
         _open_coin_fix(p, q_gen, u4_op_peg(lan, axe, u4_noun_2)));
    }
    else if ( u4_b_pq(gen, u4_atom_clip, &p_gen, &q_gen) ) {
      u4_tool ryx = u4_kc(lan, u4_atom_frag, axe);

      return u4_kt
        (lan, 
         u4_atom_link,
         u4_kt(lan, 
               u4_atom_take, 
               u4_blip,
               u4_kl
                (lan,
                 u4_kc
                  (lan, 
                   ryx,
                   u4_kq
                    (lan, u4_atom_call, _open_coin(p, q_gen), ryx, u4_nul)))),
         _open_coin_fix(p, p_gen, axe));
    }
    else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, u4_atom_name, p_gen, _open_coin_fix(p, q_gen, axe));
    }
    if ( u4_b_pq(gen, u4_atom_sock, &p_gen, &q_gen) ) {
      return _open_coin_fix(p, q_gen, axe);
    } 
    else {
      u4_gene bog = _crow_open(p, gen);

      if ( !u4_n_eq(gen, bog) ) {
        return _open_coin_fix(p, bog, axe);
      }
      else {
        u4_tool ryx = u4_kc(lan, u4_atom_frag, axe);

        return u4_kt
          (lan,
           u4_atom_then, 
           u4_kt(lan, u4_atom_like, gen, ryx), 
           ryx);
      }
    }
  }
static u4_gene
_open_coin(u4_crow p,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun p_gen, q_gen;

  if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
    return u4_kt
      (lan,
       u4_atom_push,
       u4_kt(lan, u4_atom_cool, u4_atom_wash, q_gen),
       u4_kc(lan, u4_atom_gate, _open_coin_fix(p, p_gen, u4_noun_4)));
  }
  else if ( u4_b_pq(gen, u4_atom_sock, &p_gen, &q_gen) ) {
    return _open_coin(p, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_punt, &p_gen) ) {
    return p_gen;
  }
  else if ( u4_b_pq(gen, u4_atom_clip, &p_gen, &q_gen) ) {
    u4_tool ryx = u4_kc(lan, u4_atom_frag, u4_noun_4);

    return u4_kt
      (lan,
       u4_atom_push,
       u4_kt(lan, u4_atom_cool, u4_atom_wash, q_gen),
       u4_kc
        (lan,
         u4_atom_gate,
         u4_kt
          (lan, 
           u4_atom_link,
            u4_kt
              (lan,
               u4_atom_take,
               u4_blip,
               u4_kl
                (lan,
                 u4_kc
                  (lan, 
                   ryx,
                   u4_kq
                    (lan, u4_atom_call, _open_coin(p, q_gen), ryx, u4_nul)))),
           _open_coin_fix(p, p_gen, u4_noun_4))));
  }
  else {
    u4_gene bog = _crow_open(p, gen);

    if ( !u4_n_eq(gen, bog) ) {
      return _open_coin(p, bog);
    }
    else {
      return u4_kt
        (lan,
         u4_atom_push,
         u4_kt(lan, u4_atom_cool, u4_atom_wash, gen),
         u4_kc(lan, u4_atom_gate, _open_coin_fix(p, gen, u4_noun_4)));
    }
  }
}

/* grip:open:crow
*/
  static u4_gene
  _open_grip(u4_crow, u4_gene);

  static u4_gene
  _open_grip_a(u4_crow p,
               u4_bank ban)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(ban) ) {
      return u4_noun_0;
    }
    else {
      return u4_kc
        (lan, _open_grip(p, u4_ch(ban)), _open_grip_a(p, u4_ct(ban)));
    }
  }
static u4_gene
_open_grip(u4_crow p,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun p_gen, q_gen;

  if ( u4_b_p(gen, u4_atom_base, &p_gen) ) {
    return gen;
  }
  else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
    return u4_kt
      (lan, u4_atom_cast, p_gen, _open_grip(p, q_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
    return u4_kt
      (lan, u4_atom_cell, _open_grip(p, p_gen), _open_grip(p, q_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_clip, &p_gen, &q_gen) ) {
    return u4_kt
      (lan, u4_atom_clip, _open_grip(p, p_gen), _open_grip(p, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_grip, &p_gen) ) {
    return _open_grip(p, p_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
    return u4_kt
      (lan, u4_atom_name, p_gen, _open_grip(p, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_punt, &p_gen) ) {
    u4_noun pp_gen;

    if ( u4_b_p(p_gen, u4_atom_pick, &pp_gen) ) {
      return u4_kt(lan, u4_atom_punt, u4_atom_pick, _open_grip_a(p, pp_gen));
    }
    else {
      return u4_kc(lan, u4_atom_base, u4_atom_blur);
    }
  }
  else if ( u4_b_pq(gen, u4_atom_sock, &p_gen, &q_gen) ) {
    return _open_grip(p, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
    return gen;
  }
  else {
    u4_gene bog = _crow_open(p, gen);

    if ( !u4_n_eq(gen, bog) ) {
      return _open_grip(p, bog);
    }
    else {
      return u4_kc(lan, u4_atom_base, u4_atom_blur);
    }
  }
}

_open_do_p(base)
{
  u4_lane lan = p->lan;

  if ( u4_n_eq(u4_atom_atom, p_gen) ) {
    return u4_kt
      (lan, u4_atom_cast, 
            u4_kt(lan, u4_atom_bump, u4_atom_rock, u4_noun_0),
            u4_kc(lan, u4_atom_rock, u4_noun_0));
  }
  else if ( u4_n_eq(u4_atom_blur, p_gen) ) {
    return u4_kt
      (lan, u4_atom_cast, 
            u4_kt(lan, u4_atom_nock, u4_atom_rock, u4_noun_0),
            u4_kc(lan, u4_atom_rock, u4_noun_0));
  }
  else if ( u4_n_eq(u4_atom_cell, p_gen) ) {
    return u4_kt
      (lan, u4_atom_cell,
            u4_kc(lan, u4_atom_base, u4_atom_blur),
            u4_kc(lan, u4_atom_base, u4_atom_blur));
  }
  else if ( u4_n_eq(u4_atom_flag, p_gen) ) {
    return u4_kt
      (lan, u4_atom_cast,
            u4_kt(lan, u4_atom_deep, u4_atom_rock, u4_noun_0),
            u4_kc(lan, u4_atom_rock, u4_noun_0));
  }
  else if ( u4_n_eq(u4_atom_null, p_gen) ) {
    return u4_kc(lan, u4_atom_rock, u4_noun_0);
  }
  else return u4_trip;
}

_open_do_pq(bond)
{
  u4_lane lan = p->lan;
  u4_noun beg = u4_kc(lan, u4_atom_frag, u4_noun_4);

  if ( u4_n_zero(q_gen) ) {
    return _crow_fail(p, "bond");
  }
  else {
    u4_noun iq_gen = u4_ch(q_gen);
    u4_noun tq_gen = u4_ct(q_gen);

    if ( u4_n_zero(tq_gen) ) {
      return iq_gen;
    }
    else {
      return u4_kt
        (lan,
         u4_atom_push,
         u4_kt(lan, u4_atom_name, 
                        u4_atom_hez, 
                        _open_in_bond(p, p_gen, tq_gen)),
         u4_kt
          (lan,
           u4_atom_push,
           u4_kt(lan, u4_atom_name,
                          u4_atom_fon,
                          iq_gen),
           u4_kt
            (lan, 
             u4_atom_push,
             u4_kt(lan, u4_atom_take,
                            u4_kt(lan, beg, u4_atom_fon, u4_noun_0),
                            u4_noun_0),
             u4_kc
              (lan,
               u4_atom_slam,
               u4_kq
                (lan,
                 u4_atom_wail,
                 p_gen,
                 u4_kq
                  (lan,
                   u4_atom_call,
                   u4_kc(lan, u4_atom_frag, u4_noun_10),
                   beg,
                   u4_nul),
                u4_kt
                  (lan,
                   u4_atom_take,
                   u4_kc(lan, u4_atom_hez, u4_noun_0),
                   u4_kc
                    (lan,
                     u4_kc(lan, beg, beg),
                     u4_noun_0)))))));
    }
  }
}

_open_do_p(cage)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(p_gen) ) {
    return u4_kc(lan, u4_atom_bail, u4_nul);
  }
  else {
    u4_noun ip_gen = u4_ch(p_gen);
    u4_noun tp_gen = u4_ct(p_gen);

    if ( u4_n_zero(tp_gen) ) {
      return ip_gen;
    } else {
      return u4_kt
        (lan, u4_atom_cell, ip_gen, _open_in_cage(p, tp_gen));
    }
  }
}

_open_do_p(call)
{
  u4_lane lan = p->lan;
  u4_noun ip_gen = u4_ch(p_gen);
  u4_noun tp_gen = u4_ct(p_gen);

  if ( u4_n_zero(tp_gen) ) {
    return u4_kt
      (lan, u4_atom_link, 
            ip_gen,
            u4_kc(lan, u4_atom_port, u4_blip));
  } else {
    if ( u4_n_eq(tp_gen, u4_kc(lan, u4_atom_frag, u4_noun_4)) ) {
      return u4_trip;
    }
    return u4_kt
      (lan, u4_atom_push,
            ip_gen,
            u4_kt
              (lan,
               u4_atom_take,
               u4_kt(lan, 
                     u4_kc(lan, u4_atom_frag, u4_noun_2),
                     u4_kc(lan, u4_atom_port, u4_noun_0),
                     u4_nul),
               u4_kl(lan,
                     u4_kc(lan,
                           u4_kc(lan, u4_atom_frag, u4_noun_4),
                           u4_kt(lan, u4_atom_link, 
                                      u4_kc(lan, u4_atom_frag, u4_noun_3),
                                      u4_kc(lan, u4_atom_cage, tp_gen))))));
  }
}

_open_do_pq(clip)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_push,
          q_gen,
          u4_kt
            (lan, u4_atom_sift,
                  u4_kc(lan, u4_atom_frag, u4_noun_2),
                  u4_kl(lan,
                        u4_kc(lan,
                              u4_kt(lan, u4_atom_link,
                                         u4_kc(lan, u4_atom_frag, u4_noun_3),
                                         q_gen),
                              u4_kc(lan, u4_atom_frag, u4_noun_2)))));
}

_open_do_p(coin)
{
  return _open_coin(p, p_gen);
}

_open_do_p(cool)
{
  return p_gen;
}

_open_do_p(dbug)
{
  return p_gen;
}

_open_do_pq(else)
{
  u4_lane lan = p->lan;

  return u4_kq
    (lan, u4_atom_test,
          p_gen,
          u4_kc(lan, u4_atom_bail, u4_noun_0),
          q_gen);
}

_open_do_p(flip)
{
  u4_lane lan = p->lan;

  return u4_kq
    (lan, u4_atom_test,
          p_gen,
          u4_kc(lan, u4_atom_rock, u4_noun_1),
          u4_kc(lan, u4_atom_rock, u4_noun_0));
}

_open_do_p(flow)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(p_gen) ) {
    return u4_kc(lan, u4_atom_rock, u4_noun_0);
  }
  else {
    u4_noun ip_gen = u4_ch(p_gen);
    u4_noun tp_gen = u4_ct(p_gen);

    return u4_kt(lan, u4_atom_cell, ip_gen, _open_in_flow(p, tp_gen));
  }
}

_open_do_p(frag)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_take, 
          u4_kc(lan, u4_kc(lan, u4_atom_frag, p_gen), u4_nul),
          u4_nul);
}

_open_do_p(grip)
{
  return _open_grip(p, p_gen);
}

_open_do_p(gate)
{
  u4_lane lan = p->lan;

  return u4_kc
    (lan, u4_atom_load,
          u4_kl(lan, u4_kc(lan, u4_blip, p_gen)));
}

_open_do_pq(home)
{
  return q_gen;
}

_open_do_pqr(howl)
{
  u4_lane lan = p->lan;

  return u4_kc
    (lan, u4_atom_call, 
          u4_kq(lan, p_gen, q_gen, r_gen, u4_nul));
}

_open_do_pq(knit)
{
  u4_lane lan = p->lan;

  return u4_kt(lan, u4_atom_link, q_gen, p_gen);
}

_open_do_pqr(lest)
{
  u4_lane lan = p->lan;

  return u4_kq(lan, u4_atom_test, p_gen, r_gen, q_gen);
}

_open_do_p(loop)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_link,
          u4_kc(lan, u4_atom_gate, p_gen),
          u4_kc(lan, u4_atom_port, u4_blip));
}

_open_do_p(mega)
{
  u4_lane lan = p->lan;

  return u4_kc(lan, u4_atom_rock, p_gen);
}

_open_do_pq(mesh)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(q_gen) ) {
    return u4_kc(lan, u4_atom_bail, u4_nul);
  }
  else {
    u4_noun iq_gen = u4_ch(q_gen);
    u4_noun tq_gen = u4_ct(q_gen);

#if 0
    if ( !u4_n_zero(p->bug) ) {
      u4_err(lan, "mesh: iq_gen", iq_gen);
      u4_err(lan, "mesh: grip", _open_grip(p, iq_gen));
      u4_err(lan, "mesh: coin", _open_coin(p, iq_gen));
      u4_err(lan, "mesh: metacoin", _open_coin(p, _open_coin(p, iq_gen)));
      printf("\n");
    }
#endif
    return u4_kq
      (lan,
       u4_atom_test,
       u4_kt(lan, u4_atom_like, _open_grip(p, iq_gen), p_gen),
       u4_kq(lan, u4_atom_call, _open_coin(p, iq_gen), p_gen, u4_nul),
       _open_in_mesh(p, p_gen, tq_gen));
  }
}

_open_do_p(pick)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(p_gen) ) {
    return u4_kc(lan, u4_atom_bail, u4_nul);
  }
  else {
    u4_noun ip_gen = u4_ch(p_gen);

    return u4_kt
      (lan,
       u4_atom_push,
       u4_kc(lan, u4_atom_wash, ip_gen),
       u4_kc(lan, u4_atom_gate,
                  u4_kt(lan, u4_atom_mesh, 
                             u4_kc(lan, u4_atom_frag, u4_noun_4),
                             p_gen)));
  }
}

_open_do_pq(poke)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_push,
          p_gen,
          u4_kt
            (lan,
             u4_atom_take,
             u4_kl(lan, u4_kc(lan, u4_atom_frag, u4_noun_2)),
             u4_kl(lan,
                   u4_kc(lan,
                         u4_kc(lan, u4_atom_frag, u4_noun_4),
                         u4_kt(lan, u4_atom_link, 
                                    u4_kc(lan, u4_atom_frag, u4_noun_3),
                                    q_gen)))));
}

_open_do_p(port)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_take, 
          u4_kc(lan, u4_kc(lan, u4_atom_port, p_gen), u4_nul),
          u4_nul);
}

_open_do_pq(pull)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_push, q_gen, p_gen);
}

_open_do_p(punt)
{
  u4_lane lan = p->lan;

  return u4_kc
    (lan, u4_atom_cool,
          u4_kt(lan, u4_atom_link,
                     p_gen,
                     u4_kt(lan, u4_atom_take, 
                                u4_kl(lan, u4_kc(lan, u4_atom_port, u4_blip)),
                                u4_nul)));
}

_open_do_pq(push)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_link,
          u4_kt(lan, u4_atom_cell, 
                     p_gen, 
                     u4_kc(lan, u4_atom_frag, u4_noun_1)),
          q_gen);
}

_open_do_pqrs(qual)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_cell,
          p_gen,
          u4_kt
            (lan, u4_atom_cell,
                  q_gen,
                  u4_kt(lan, u4_atom_cell, r_gen, s_gen)));
}

_open_do_p(sand)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(p_gen) ) {
    return u4_kc(lan, u4_atom_rock, u4_noun_0);
  }
  else {
    u4_noun ip_gen = u4_ch(p_gen);
    u4_noun tp_gen = u4_ct(p_gen);

    return u4_kq
      (lan, u4_atom_test,
            ip_gen,
            _open_in_sand(p, tp_gen),
            u4_kc(lan, u4_atom_rock, u4_noun_1));
  }
}

_open_do_pq(sift)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(q_gen) ) {
    return u4_kc(lan, u4_atom_bail, u4_nul);
  }
  else {
    u4_noun iq_gen = u4_ch(q_gen);
    u4_noun tq_gen = u4_ct(q_gen);
    u4_noun piq_gen = u4_ch(iq_gen);
    u4_noun qiq_gen = u4_ct(iq_gen);

    return u4_kq
      (lan, 
       u4_atom_test,
       u4_kt(lan, u4_atom_like, _open_grip(p, piq_gen), p_gen),
       u4_kt
        (lan, u4_atom_link,
              u4_kt(lan,
                    u4_atom_sure,
                    piq_gen,
                    p_gen),
              qiq_gen),
       _open_in_sift(p, p_gen, tq_gen));
  }
}

_open_do_p(slam)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_lift, 
          u4_kc(lan, u4_blip, p_gen),
          u4_noun_0);
}

_open_do_p(slur)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_cast,
          u4_kc(lan, u4_atom_base, u4_atom_blur),
          p_gen);
}

_open_do_pq(sock)
{
  u4_lane lan = p->lan;
  u4_noun rax = u4_kc(lan, u4_atom_frag, u4_noun_2);

  return u4_kt
    (lan,
     u4_atom_push,
     q_gen, 
     u4_kt
      (lan,
       u4_atom_knit,
       rax,
       u4_kt(lan,
             u4_atom_sure,
             u4_kt(lan, 
                   u4_atom_knit, 
                   u4_kc(lan, u4_atom_frag, u4_noun_2), 
                   p_gen),
             rax)));
}

_open_do_p(some)
{
  u4_lane lan = p->lan;

  if ( u4_n_zero(p_gen) ) {
    return u4_kc(lan, u4_atom_rock, u4_noun_1);
  }
  else {
    u4_noun ip_gen = u4_ch(p_gen);
    u4_noun tp_gen = u4_ct(p_gen);

    return u4_kq
      (lan, u4_atom_test,
            ip_gen,
            u4_kc(lan, u4_atom_rock, u4_noun_0),
            _open_in_some(p, tp_gen));
  }
}

_open_do_pq(spot)
{
  return q_gen;
}

_open_do_pqr(step)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan,
     u4_atom_sift,
     p_gen,
     u4_kt
      (lan,
       u4_kc(lan, u4_kc(lan, u4_atom_rock, u4_noun_0), q_gen),
       u4_kc(lan, u4_kc(lan, u4_atom_base, u4_atom_cell), r_gen),
       u4_nul));
}

_open_do_pq(talk)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_call, q_gen, u4_kc(lan, p_gen, u4_noun_0));
}

_open_do_pq(then)
{
  u4_lane lan = p->lan;
  
  return u4_kq
    (lan, u4_atom_test, p_gen, q_gen, u4_kc(lan, u4_atom_bail, u4_noun_0));
}

_open_do_pqr(trel)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_cell,
          p_gen,
          u4_kt(lan, u4_atom_cell, q_gen, r_gen));
}

_open_do_pqrs(wail)
{
  u4_lane lan = p->lan;

  return u4_kq
    (lan, u4_atom_call, 
          p_gen, 
          q_gen,
          u4_kt(lan, r_gen, s_gen, u4_nul));
}

_open_do_p(wash)
{
  u4_lane lan = p->lan;

  return u4_kt
    (lan, u4_atom_cast, 
          u4_kc(lan, u4_atom_base, u4_atom_blur),
          p_gen);
}

_open_do_pq(yell)
{
  u4_lane lan = p->lan;

  return u4_kt(lan, u4_atom_call, p_gen, q_gen);
}

/* open:crow
*/
u4_gene
_crow_open(u4_crow p,
           u4_gene gen)
{
  u4_noun p_gen, q_gen, r_gen, s_gen;

#if 1
    if ( !u4_n_zero(p->bug) ) {
      u4_err(p->lan, "open: gen", gen);
    }
#endif
  if ( u4_b_fork(gen, &p_gen, &q_gen) ) {
    u4_err(p->lan, "gen", gen);
    return _crow_fail(p, "bad code");
  }
  else {
    _open_p   (coin);
    _open_p   (cool);
    _open_p   (dbug);
    _open_pq  (else);
    _open_p   (flip);
    _open_p   (frag);
    _open_p   (grip);
    _open_p   (gate);
    _open_pq  (home);
    _open_pqr (howl);
    _open_pq  (knit);
    _open_pqr (lest);
    _open_p   (loop);
    _open_p   (mega);
    _open_p   (port);
    _open_pq  (pull);
    _open_p   (punt);
    _open_pq  (push);
    _open_pqrs(qual);
    _open_p   (slam);
    _open_p   (slur);
    _open_pq  (spot);
    _open_pq  (then);
    _open_pqr (trel);
    _open_pqrs(wail);
    _open_p   (wash);

    _open_p   (base);
    _open_pq  (bond);
    _open_p   (cage);
    _open_p   (call);
    _open_pq  (clip);
    _open_p   (flow);
    _open_pq  (mesh);
    _open_p   (pick);
    _open_pq  (poke);
    _open_p   (sand);
    _open_pq  (sift);
    _open_pq  (sock);
    _open_p   (some);
    _open_pqr (step);
    _open_pq  (talk);
    _open_pq  (yell);

    return gen;
  }
}

#if 0
/* _mill_open(): gene expansion.
*/
u4_gene 
_mill_open(u4_crow p,
           u4_gene gen)
{
  u4_nopt zax = u4_tab_get(gen, m->pon);

  if ( u4_bull != zax ) {
    return zax;
  }
  else {
    zax = _open_in(m, gen);

    m->pon = u4_tab_add(m->lane, gen, zax, m->pon);
    return zax;
  }
}
#endif
