/* j/6/open.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* internals
*/
  static u2_noun _open_mast_pax(u2_wire, u2_noun);
  static u2_noun _open_mast_fix(u2_wire, u2_noun, u2_atom);
  static u2_noun _open_fist(u2_wire, u2_noun);
  static u2_noun _open_mast(u2_wire, u2_noun);

  static u2_noun
  _open_mast_pax(u2_wire wir_r,
                 u2_noun gen)
  {
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_as_pq(gen, c3__ktdg, &p_gen, &q_gen) ) {
      return _open_mast_pax(wir_r, u2_rx(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktdl, &p_gen, &q_gen) ) {
      return u2_bt(wir_r, c3__ktdl, 
                          u2_rx(wir_r, p_gen),
                          _open_mast(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktmt, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r,
         c3__bnpd,
         u2_bt(wir_r, c3__ktsg, c3__ktsr, u2_rx(wir_r, q_gen)),
         u2_bc
          (wir_r,
           c3__brbn,
           u2_bt
            (wir_r, 
             c3__bnld,
              u2_bt
                (wir_r,
                 c3__mtbn,
                 u2_blip,
                 u2_bo
                  (wir_r,
                   u2_bc
                    (wir_r, 
                     u2_bc(wir_r, u2_nul, _4),
                     u2_bq
                      (wir_r, c3__mtnp, 
                              _open_mast(wir_r, q_gen), 
                              u2_bc(wir_r, u2_nul, _4), 
                              u2_nul)))),
             _open_mast_fix(wir_r, p_gen, _4))));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktnp, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r,
         c3__bnpd,
         u2_bt(wir_r, c3__ktsg, c3__ktsr, u2_rx(wir_r, q_gen)),
         u2_bc(wir_r, c3__brbn, _open_mast_fix(wir_r, p_gen, _4)));
    }
    else if ( u2_yes == u2_as_p(gen, c3__mtsr, &p_gen) ) {
      return u2_rx(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktld, &p_gen, &q_gen) ) {
      return u2_bt(wir_r, c3__ktld, 
                          u2_rx(wir_r, p_gen), 
                          _open_mast(wir_r, q_gen));
    }
    else {
      u2_noun bog = j2_mby(Pit, open)(wir_r, gen);
      u2_noun gad; 

      if ( !(u2_yes == u2_sing(gen, bog)) ) {
        gad =_open_mast(wir_r, bog);
      }
      else {
        gad = u2_bt
          (wir_r,
           c3__bnpd,
           u2_bt(wir_r, c3__ktsg, c3__ktsr, u2_rx(wir_r, gen)),
           u2_bc(wir_r, c3__brbn, _open_mast_fix(wir_r, gen, _4)));
      }
      u2_rl_lose(wir_r, bog);
      return gad;
    }
  }

  static u2_noun 
  _open_mast_fix(u2_wire wir_r,
                 u2_noun gen,
                 u2_atom axe)
  {
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_as_pq(gen, c3__dgnp, &p_gen, &q_gen) ) {
      u2_atom lef = j2_mbc(Pit, peg)(wir_r, axe, _2);
      u2_atom rit = j2_mbc(Pit, peg)(wir_r, axe, _3);
      u2_noun gad;
        
      gad = u2_bt
        (wir_r, 
         c3__dgnp,
         _open_mast_fix(wir_r, p_gen, lef),
         _open_mast_fix(wir_r, q_gen, rit));

      u2_rl_lose(wir_r, lef);
      u2_rl_lose(wir_r, rit);
      return gad;
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktbn, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktbn, 
                u2_rx(wir_r, p_gen), 
                _open_mast_fix(wir_r, q_gen, axe));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktdg, &p_gen, &q_gen) ) {
      return _open_mast_fix(wir_r, q_gen, axe);
    } 
    else if ( u2_yes == u2_as_pq(gen, c3__ktdl, &p_gen, &q_gen) ) {
      return u2_bt(wir_r, c3__ktld, 
                          u2_rx(wir_r, p_gen),
                          _open_mast_fix(wir_r, q_gen, axe));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktnp, &p_gen, &q_gen) ) {
      return _open_mast_fix(wir_r, p_gen, axe);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktmt, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, 
         c3__bnld,
         u2_bt(wir_r, 
               c3__mtbn, 
               u2_blip,
               u2_bo
                (wir_r,
                 u2_bc
                  (wir_r, 
                   u2_bc(wir_r, u2_nul, u2_rx(wir_r, axe)),
                   u2_bq
                    (wir_r, 
                     c3__mtnp, _open_mast(wir_r, q_gen), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, axe)),
                               u2_nul)))),
         _open_mast_fix(wir_r, p_gen, axe));
    }
    else if ( u2_yes == u2_as_p(gen, c3__mtsr, &p_gen) ) {
      return u2_bq
        (wir_r, c3__mtnp,
                u2_rx(wir_r, p_gen),
                u2_bc(wir_r, u2_nul, u2_rx(wir_r, axe)),
                u2_nul);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktld, &p_gen, &q_gen) ) {
      return u2_bt(wir_r, c3__ktld, 
                          u2_rx(wir_r, p_gen), 
                          _open_mast_fix(wir_r, q_gen, axe));
    }
    else {
      u2_noun bog = j2_mby(Pit, open)(wir_r, gen);
      u2_noun gad;

      if ( !(u2_yes == u2_sing(gen, bog)) ) {
        gad = _open_mast_fix(wir_r, bog, axe);
      }
      else {
        gad = u2_bt
          (wir_r,
           c3__csld, 
           u2_bt(wir_r, c3__csbn, 
                        u2_rx(wir_r, gen), 
                        u2_bc(wir_r, u2_nul, u2_rx(wir_r, axe))),
           u2_bc(wir_r, u2_nul, u2_rx(wir_r, axe)));
      }
      u2_rl_lose(wir_r, bog);
      return gad;
    }
  }

  static u2_noun
  _open_mast(u2_wire wir_r,
             u2_noun gen)
  {
    return _open_mast_pax(wir_r, gen);
  }

    static u2_list
    _open_fist_a(u2_wire wir_r,
                 u2_noun ban)
    {
      if ( (u2_nul == ban) ) {
        return u2_nul;
      }
      else {
        return u2_bc
          (wir_r, _open_fist(wir_r, u2_h(ban)), 
                  _open_fist_a(wir_r, u2_t(ban)));
      }
    }
  static u2_noun
  _open_fist(u2_wire wir_r,
             u2_noun gen)
  {
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_as_pq(gen, c3__dgnp, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__dgnp, 
                _open_fist(wir_r, p_gen), 
                _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__dtsg, &p_gen) ) {
      return u2_rx(wir_r, gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktbn, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktbn, 
                u2_rx(wir_r, p_gen), 
                _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktdg, &p_gen, &q_gen) ) {
      return _open_fist(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktdl, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktdl, 
                u2_rx(wir_r, p_gen), 
                _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktnp, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktnp, 
                u2_rx(wir_r, p_gen), 
                _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__ktsg, &p_gen) ) {
      return u2_rx(wir_r, gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__tmbn, &p_gen) ) {
      return u2_rx(wir_r, gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktmt, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktmt, 
                _open_fist(wir_r, p_gen), 
                _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktld, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktld, 
                u2_rx(wir_r, p_gen), 
                _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__tmpd, &p_gen) ) {
      return _open_fist(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__mtsr, &p_gen) ) {
      u2_noun pp_gen;

      if ( u2_yes == u2_as_p(p_gen, c3__brcs, &pp_gen) ) {
        return u2_bt(wir_r, c3__mtsr,  
                            c3__brcs, 
                            _open_fist_a(wir_r, pp_gen));
      }
      else {
        return u2_bc(wir_r, c3__tmbn, c3__blur);
      }
    }
    else {
      u2_noun bog = j2_mby(Pit, open)(wir_r, gen);
      u2_noun gad;

      if ( !(u2_yes == u2_sing(gen, bog)) ) {
        gad =_open_fist(wir_r, bog);
      }
      else {
        gad = u2_bc(wir_r, c3__tmbn, c3__blur);
      }
      u2_rl_lose(wir_r, bog);
      return gad;
    }
  }

#define _open_do_p(stem)  \
  static u2_noun _open_in_##stem \
    (u2_wire wir_r, u2_noun p_gen)

#define _open_do_pq(stem)  \
  static u2_noun _open_in_##stem \
    (u2_wire wir_r, u2_noun p_gen, u2_noun q_gen)

#define _open_do_pqr(stem)  \
  static u2_noun _open_in_##stem \
    (u2_wire wir_r, u2_noun p_gen, u2_noun q_gen, u2_noun r_gen)

#define _open_do_pqrs(stem)  \
  static u2_noun _open_in_##stem \
    (u2_wire wir_r, u2_noun p_gen, u2_noun q_gen, u2_noun r_gen, u2_noun s_gen)

  _open_do_p(brbn)   //  |=
  {
    return u2_bc
      (wir_r, c3__brsr,
              u2_bo(wir_r, u2_bc(wir_r, u2_blip, u2_rx(wir_r, p_gen))));
  }

  _open_do_p(brdg)   //  |:
  {
    return u2_bt
      (wir_r, c3__brmt, 
              u2_bc(wir_r, u2_blip, u2_rx(wir_r, p_gen)),
              u2_nul);
  }

  _open_do_p(brnp)   //  |-
  {
    return u2_bt
      (wir_r, c3__bnld,
              u2_bc(wir_r, c3__brbn, u2_rx(wir_r, p_gen)),
              u2_blip);
  }

  _open_do_pq(brsg)   //  |~
  {
    if ( (u2_nul == q_gen) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);

      if ( (u2_nul == tq_gen) ) {
        return u2_rx(wir_r, iq_gen);
      }
      else {
        return u2_bt
          (wir_r,
           c3__bnpd,
           _open_in_brsg(wir_r, p_gen, tq_gen),
           u2_bt
            (wir_r,
             c3__bnpd,
             u2_bt(wir_r, c3__bnld,
                        u2_bc(wir_r, u2_nul, _3),
                        u2_rx(wir_r, iq_gen)),
             u2_bt
              (wir_r, 
               c3__bnpd,
               u2_bc(wir_r, u2_nul, _8), 
               u2_bc
                (wir_r,
                 c3__brdg,
                 u2_bq
                  (wir_r,
                   c3__mtpd,
                   u2_bt(wir_r,
                         c3__bnld,
                         u2_bc(wir_r, u2_nul, (23)),
                         u2_rx(wir_r, p_gen)),
                   u2_bq
                    (wir_r,
                     c3__mtnp,
                     u2_bc(wir_r, u2_nul, _10),
                     u2_bc(wir_r, u2_nul, _4),
                     u2_nul),
                  u2_bt
                    (wir_r,
                     c3__mtbn,
                     u2_bc(wir_r, 
                           u2_bc(wir_r, u2_nul, (22)), 
                           u2_nul),
                     u2_bc
                      (wir_r,
                       u2_bc(wir_r, u2_bc(wir_r, u2_nul, _4),
                                    u2_bc(wir_r, u2_nul, _4)),
                       u2_nul)))))));
      }
    }
  }

  _open_do_p(brcs)    //  |?
  {
    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__zpzp, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);

      return u2_bt
        (wir_r,
         c3__bnpd,
         u2_bc(wir_r, c3__ktsr, u2_rx(wir_r, ip_gen)),
         u2_bc(wir_r, c3__brbn,
                      u2_bt(wir_r, c3__cssr, 
                                   u2_bc(wir_r, u2_nul, _4),
                                   u2_rx(wir_r, p_gen))));
    }
  }

  _open_do_pq(brdl)   //  |<
  {
    return u2_bq
      (wir_r, c3__bnpd, p_gen, c3__brdg, q_gen);
  }

  _open_do_pq(brld)   //  |>
  {
    return u2_bq
      (wir_r, c3__bnpd, p_gen, c3__brbn, q_gen);
  }

  _open_do_pq(bndl)   //  =<
  {
    return u2_bt(wir_r, c3__bnld, u2_rx(wir_r, q_gen), 
                                  u2_rx(wir_r, p_gen));
  }

  _open_do_pq(bnnp)   //  =-
  {
    return u2_bt(wir_r, c3__bnpd, u2_rx(wir_r, q_gen), 
                                  u2_rx(wir_r, p_gen));
  }

  _open_do_pq(bnpd)   //  =+
  {
    return u2_bt
      (wir_r, c3__bnld,
              u2_bt(wir_r, c3__dgnp, 
                           u2_rx(wir_r, p_gen), 
                           u2_bc(wir_r, u2_nul, _1)),
              u2_rx(wir_r, q_gen));
  }

  _open_do_pqrs(dgkt) //  :^
  {
    return u2_bt
      (wir_r, c3__dgnp,
              u2_rx(wir_r, p_gen),
              u2_bt
                (wir_r, c3__dgnp,
                        u2_rx(wir_r, q_gen),
                        u2_bt(wir_r, c3__dgnp, u2_rx(wir_r, r_gen), 
                                               u2_rx(wir_r, s_gen))));
  }

  _open_do_pqr(dgpd)  //  :+
  {
    return u2_bt
      (wir_r, c3__dgnp,
              u2_rx(wir_r, p_gen),
              u2_bt(wir_r, c3__dgnp, u2_rx(wir_r, q_gen), 
                                     u2_rx(wir_r, r_gen)));
  }

  _open_do_p(dgsr)    //  :*
  {
    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__zpzp, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      if ( (u2_nul == tp_gen) ) {
        return u2_rx(wir_r, ip_gen);
      } else {
        return u2_bt
          (wir_r, c3__dgnp, u2_rx(wir_r, ip_gen), 
                            _open_in_dgsr(wir_r, tp_gen));
      }
    }
  }

  _open_do_p(dgsg)    //  :~
  {
    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__dtsg, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bt(wir_r, c3__dgnp, 
                          u2_rx(wir_r, ip_gen), 
                          _open_in_dgsg(wir_r, tp_gen));
    }
  }

  _open_do_pq(ktdg)   //  ^:
  {
    return u2_bt
      (wir_r,
       c3__bnpd,
       u2_rx(wir_r, q_gen), 
       u2_bt
        (wir_r,
         c3__bndl,
         u2_bc(wir_r, u2_nul, _2),
         u2_bt(wir_r,
               c3__ktpd,
               u2_bt(wir_r, 
                     c3__bnld, 
                     u2_bc(wir_r, u2_nul, _3), 
                     u2_rx(wir_r, p_gen)),
               u2_bc(wir_r, u2_nul, _2))));
  }

  _open_do_pq(ktmt)   //  ^%
  {
    return u2_bt
      (wir_r, c3__bnpd,
              u2_rx(wir_r, q_gen),
              u2_bt
                (wir_r, c3__csnp,
                      u2_bc(wir_r, u2_nul, _2),
                      u2_bo(wir_r,
                            u2_bc(wir_r,
                                  u2_bt(wir_r, c3__bnld,
                                               u2_bc(wir_r, u2_nul, _3),
                                               u2_rx(wir_r, q_gen)),
                                  u2_bc(wir_r, u2_nul, _2)))));
  }

  _open_do_pq(ktdl)   //  ^<
  {
    return 
      u2_bt
        (wir_r, c3__bndl,
                u2_bt(wir_r, c3__ktld, 
                             u2_rx(wir_r, p_gen), 
                             u2_bc(wir_r, u2_nul, _1)),
                u2_rx(wir_r, q_gen));
  }

  _open_do_p(ktsr)    //  ^*
  {
    return u2_bt
      (wir_r, c3__ktnp, 
            u2_bc(wir_r, c3__tmbn, c3__blur),
            u2_rx(wir_r, p_gen));
  }

  _open_do_p(ktsg)    //  ^~
  {
    return u2_rx(wir_r, p_gen);
  }

  _open_do_p(tmbn)    //  ;=
  {
    if ( u2_yes == u2_sing(c3__atom, p_gen) ) {
      return u2_bt
        (wir_r, c3__ktnp, 
              u2_bt(wir_r, c3__dtkt, c3__dtsg, _0),
              u2_bc(wir_r, c3__dtsg, _0));
    }
    else if ( u2_yes == u2_sing(c3__blur, p_gen) ) {
      u2_noun dud = u2_bc(wir_r, c3__dtsg, u2_nul);

      return u2_bt
        (wir_r, c3__ktnp, 
                u2_bt(wir_r, c3__dtsr, 
                             u2_rx(wir_r, dud), 
                             u2_rx(wir_r, dud)),
                dud);
    }
    else if ( u2_yes == u2_sing(c3__cell, p_gen) ) {
      return u2_bt
        (wir_r, c3__dgnp,
              u2_bc(wir_r, c3__tmbn, c3__blur),
              u2_bc(wir_r, c3__tmbn, c3__blur));
    }
    else if ( u2_yes == u2_sing(c3__flag, p_gen) ) {
      return u2_bt
        (wir_r, c3__ktnp,
              u2_bt(wir_r, c3__dtcs, c3__dtsg, _0),
              u2_bc(wir_r, c3__dtsg, u2_yes));
    }
    else if ( u2_yes == u2_sing(c3__null, p_gen) ) {
        return u2_bc(wir_r, c3__dtsg, u2_nul);
    }
    else return u2_bl_bail(wir_r);
  }

  _open_do_p(tmnp)    //  ;-
  {
    return _open_mast(wir_r, p_gen);
  }

  _open_do_p(tmpd)    //  ;+
  {
    return _open_fist(wir_r, p_gen);
  }

    static u2_noun
    _mtbr_a(u2_wire wir_r,
            u2_noun r_gen)
    {
      if ( (u2_nul == r_gen) ) {
        return u2_nul;
      } 
      else {
        u2_noun ir_gen = u2_h(r_gen);
        u2_noun tr_gen = u2_t(r_gen);
        u2_noun pir_gen = u2_h(ir_gen);
        u2_noun qir_gen = u2_t(ir_gen);

        return u2_bc
          (wir_r, u2_bc(wir_r, 
                        u2_rx(wir_r, pir_gen),
                        u2_bt(wir_r, c3__bnld, 
                                     u2_bc(wir_r, u2_nul, _3),
                                     u2_rx(wir_r, qir_gen))),
                  _mtbr_a(wir_r, tr_gen));
      }
    }
  _open_do_pqr(mtbr)  //  %|
  {
    return u2_bt
      (wir_r, c3__bnpd,
              u2_rx(wir_r, q_gen),
              u2_bt
                (wir_r,
                 c3__mtbn,
                 j2_mbc(Pit, weld)
                    (wir_r, u2_rx(wir_r, p_gen),
                            u2_bc(wir_r, u2_bc(wir_r, u2_nul, _2), u2_nul)),
                 _mtbr_a(wir_r, r_gen)));
  }

  _open_do_pq(mtdg)   //  %:
  {
    return u2_bq
      (wir_r, c3__mtsg,
            u2_bc(wir_r, u2_blip, u2_nul),
            u2_rx(wir_r, p_gen),
            u2_rx(wir_r, q_gen));
  }

  _open_do_pq(mtdt)   //  %.
  {
    return u2_bt
      (wir_r, c3__mtnp, 
              u2_rx(wir_r, q_gen), 
              u2_bc(wir_r, u2_rx(wir_r, p_gen), u2_nul));
  }

  _open_do_pqrs(mtkt) //  %^
  {
    return u2_bq
      (wir_r, c3__mtnp, 
              u2_rx(wir_r, p_gen),
              u2_rx(wir_r, q_gen),
              u2_bt(wir_r, u2_rx(wir_r, r_gen), 
                           u2_rx(wir_r, s_gen), 
                           u2_nul));
  }

  _open_do_pq(mtnp)   //  %-
  {
    if ( (u2_nul == q_gen) ) {
      return u2_bt
        (wir_r, c3__bnld, 
                u2_rx(wir_r, p_gen),
                u2_blip);
    } else {
      return u2_bq(wir_r, c3__mtdg, 
                          u2_rx(wir_r, p_gen), 
                          c3__dgsr, 
                          u2_rx(wir_r, q_gen));
    }
  }

  _open_do_pqr(mtpd)  //  %+
  {
    return u2_bc
      (wir_r, c3__mtnp, 
              u2_bq(wir_r, u2_rx(wir_r, p_gen), 
                           u2_rx(wir_r, q_gen), 
                           u2_rx(wir_r, r_gen), 
                           u2_nul));
  }

  _open_do_p(mtsr)
  {
    return u2_bc
      (wir_r, c3__ktsg,
              u2_bt(wir_r, c3__bnld,
                           u2_rx(wir_r, p_gen),
                           u2_bt(wir_r, c3__mtbn, 
                                      u2_bo(wir_r, u2_blip),
                                      u2_nul)));
  }

  _open_do_pqr(mtsg)  //  %~
  {
    return u2_bq
      (wir_r, c3__mtbr,
              u2_rx(wir_r, p_gen),
              u2_rx(wir_r, q_gen),
              u2_bo(wir_r,
                    u2_bc(wir_r,
                          u2_bc(wir_r, u2_nul, _4),
                          u2_rx(wir_r, r_gen))));
  }

  _open_do_p(csbr)    //  ?|
  {
    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__dtsg, u2_no);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bq
        (wir_r, c3__csdg,
                u2_rx(wir_r, ip_gen),
                u2_bc(wir_r, c3__dtsg, u2_yes),
                _open_in_csbr(wir_r, tp_gen));
    }
  }

  _open_do_pqr(csdt)  //  ?.
  {
    return u2_bq(wir_r, c3__csdg, 
                        u2_rx(wir_r, p_gen), 
                        u2_rx(wir_r, r_gen), 
                        u2_rx(wir_r, q_gen));
  }

  _open_do_pq(csdl)   //  ?<
  {
    return u2_bq
      (wir_r, c3__csdg,
            u2_rx(wir_r, p_gen),
            u2_bc(wir_r, c3__zpzp, u2_nul),
            u2_rx(wir_r, q_gen));
  }

  _open_do_p(cszp)    //  ?!
  {
    return u2_bq
      (wir_r, c3__csdg,
              u2_rx(wir_r, p_gen),
              u2_bc(wir_r, c3__dtsg, u2_no),
              u2_bc(wir_r, c3__dtsg, u2_yes));
  }

  _open_do_p(cspm)    //  ?&
  {
    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__dtsg, u2_yes);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bq
        (wir_r, c3__csdg,
                u2_rx(wir_r, ip_gen),
                _open_in_cspm(wir_r, tp_gen),
                u2_bc(wir_r, c3__dtsg, u2_no));
    }
  }

  _open_do_pq(csnp)   //  ?-
  {
    if ( (u2_nul == q_gen) ) {
      return u2_bc(wir_r, c3__zpzp, u2_nul);
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);
      u2_noun piq_gen = u2_h(iq_gen);
      u2_noun qiq_gen = u2_t(iq_gen);

      return u2_bq
        (wir_r, 
         c3__csdg,
         u2_bt(wir_r, c3__csbn, 
                      _open_fist(wir_r, piq_gen), 
                      u2_rx(wir_r, p_gen)),
         u2_bt
          (wir_r, c3__bnld,
                  u2_bt(wir_r,
                        c3__ktpd,
                        u2_rx(wir_r, piq_gen),
                        u2_rx(wir_r, p_gen)),
                  u2_rx(wir_r, qiq_gen)),
                  _open_in_csnp(wir_r, p_gen, tq_gen));
    }
  }

  _open_do_pq(cssr)   //  ?*
  {
    if ( (u2_nul == q_gen) ) {
      return u2_bc(wir_r, c3__zpzp, u2_nul);
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);

      return u2_bq
        (wir_r,
         c3__csdg,
         u2_bt(wir_r, c3__csbn, 
                      _open_fist(wir_r, iq_gen), 
                      u2_rx(wir_r, p_gen)),
         u2_bq(wir_r, c3__mtnp, 
                      _open_mast(wir_r, iq_gen), 
                      u2_rx(wir_r, p_gen), 
                      u2_nul),
         _open_in_cssr(wir_r, p_gen, tq_gen));
    }
  }

  _open_do_pqr(cssg)  //  ?~
  {
    return u2_bt
      (wir_r,
       c3__csnp,
       u2_rx(wir_r, p_gen),
       u2_bt
        (wir_r,
         u2_bc(wir_r, u2_bc(wir_r, c3__dtsg, u2_nul), u2_rx(wir_r, q_gen)),
         u2_bc(wir_r, u2_bc(wir_r, c3__tmbn, c3__cell), u2_rx(wir_r, r_gen)),
         u2_nul));
  }

  _open_do_pq(csld)
  {
    return u2_bq
      (wir_r, c3__csdg, 
              u2_rx(wir_r, p_gen), 
              u2_rx(wir_r, q_gen), 
              u2_bc(wir_r, c3__zpzp, u2_nul));
  }


/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, open)(u2_wire wir_r, 
                    u2_noun gen)                                  //  retain
  {
    u2_noun p_gen, q_gen, r_gen, s_gen;

    if ( u2_yes == u2_stud(gen) ) {
      return u2_bt
        (wir_r, c3__mtbn, 
                u2_bc(wir_r, u2_rx(wir_r, gen), u2_nul),
                u2_nul);
    }
    else switch ( u2_h(gen) ) {
      default: return u2_rx(wir_r, gen);

      case u2_nul: {
        return u2_bt
          (wir_r, c3__mtbn, 
                  u2_bc(wir_r, u2_rx(wir_r, gen), u2_nul),
                  u2_nul);
      }
    
#     define _open_p(stem) \
        case c3__##stem: \
          return _open_in_##stem(wir_r, u2_t(gen)); \

#     define _open_pq(stem) \
        case c3__##stem: \
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) { \
            return u2_bl_bail(wir_r); \
          } else return _open_in_##stem(wir_r, p_gen, q_gen);

#     define _open_pqr(stem) \
        case c3__##stem: \
          if ( u2_no == u2_as_trel(u2_t(gen), &p_gen, &q_gen, &r_gen) ) { \
            return u2_bl_bail(wir_r); \
          } else return _open_in_##stem(wir_r, p_gen, q_gen, r_gen);

#     define _open_pqrs(stem) \
        case c3__##stem: \
          if ( u2_no == u2_as_qual(u2_t(gen), &p_gen, &q_gen, &r_gen, &s_gen) )\
          { \
            return u2_bl_bail(wir_r); \
          } else return _open_in_##stem(wir_r, p_gen, q_gen, r_gen, s_gen);

      _open_pq  (bndl);
      _open_pq  (bnnp);
      _open_pq  (bnpd);

      _open_p   (brbn);
      _open_p   (brdg);
      _open_pq  (brdl);
      _open_pq  (brsg);
      _open_p   (brnp);
      _open_p   (brcs);
      _open_pq  (brld);

      _open_pqrs(dgkt);
      _open_pqr (dgpd);
      _open_p   (dgsr);
      _open_p   (dgsg);

      _open_p   (csbr);
      _open_pqr (csdt);
      _open_pq  (csdl);
      _open_p   (cszp);
      _open_pq  (cssr);
      _open_p   (cspm);
      _open_pq  (csnp);
      _open_pqr (cssg);
      _open_pq  (csld);
      _open_p   (tmbn);
      _open_p   (tmnp);
      _open_p   (tmpd);

      _open_pq  (ktdg);
      _open_pq  (ktdl);
      _open_pq  (ktmt);
      _open_p   (ktsr);
      _open_p   (ktsg);

      _open_pqr (mtbr);
      _open_pq  (mtdg);
      _open_pq  (mtdt);
      _open_pqrs(mtkt);
      _open_pq  (mtnp);
      _open_pqr (mtpd);
      _open_p   (mtsr);
      _open_pqr (mtsg);
    }
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, open)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun gen;

    if ( u2_none == (gen = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, open)(wir_r, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, open)[] = {
    { ".3", c3__hevy, j2_mb(Pit, open), SafeTier6, u2_none, u2_none },
    { }
  };
