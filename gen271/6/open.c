/* j/6/open.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* internals
*/
  static u2_noun _open_sift(u2_wire, u2_noun);
  static u2_noun _open_mold(u2_wire, u2_noun, u2_noun);

  static u2_noun
  _open_mold(u2_wire wir_r,
             u2_noun hep,
             u2_noun gen)
  {
    u2_noun p_gen, q_gen;
    if ( u2_no == u2_dust(gen) ) {
      goto plain;
    } else switch ( u2_h(gen) ) {
      default: goto plain;

      case c3__dgdp:  if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) )
                        return u2_bl_bail(wir_r); else
      {
        u2_noun hed = u2_bc(wir_r, u2_bc(wir_r, u2_nul, _2), u2_rx(wir_r, hep));
        u2_noun tal = u2_bc(wir_r, u2_bc(wir_r, u2_nul, _3), u2_rx(wir_r, hep));
        u2_noun lag = u2_bt
          (wir_r, c3__dgdp,
                  _open_mold(wir_r, hed, p_gen),
                  _open_mold(wir_r, tal, q_gen));

        u2_rl_lose(wir_r, hed); 
        u2_rl_lose(wir_r, tal);
        return lag;
      }
      case c3__ktbn:  if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) )
                        return u2_bl_bail(wir_r); else
      {
        return u2_bt
          (wir_r, c3__ktbn, 
                  u2_rx(wir_r, p_gen), 
                  _open_mold(wir_r, hep, q_gen));
      }
      case c3__ktdp:  if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) )
                        return u2_bl_bail(wir_r); else
      {
        return _open_mold(wir_r, hep, p_gen);
      }
      case c3__ktpd:  if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) )
                        return u2_bl_bail(wir_r); else
      {
        return u2_bt
          (wir_r, c3__ktpd, 
                  u2_rx(wir_r, p_gen), 
                  _open_mold(wir_r, hep, q_gen));
      }
      case c3__mttr:  p_gen = u2_t(gen);
      {
        return u2_bq
          (wir_r, c3__mtdp,
                  u2_rx(wir_r, p_gen),
                  u2_bt(wir_r, c3__mtbn, u2_rx(wir_r, hep), u2_nul),
                  u2_nul);
      }
      case c3__zpcb:  if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) )
                        return u2_bl_bail(wir_r); else
      {
        return u2_bt
          (wir_r, c3__zpcb, 
                  u2_rx(wir_r, p_gen), 
                  _open_mold(wir_r, hep, q_gen));
      }
      case c3__zpdx:  p_gen = u2_t(gen);
      {
        return u2_bc
          (wir_r, c3__zpcb, _open_mold(wir_r, hep, p_gen));
      }
    }

    plain: {
      u2_noun bog = j2_mby(Pit, open)(wir_r, gen);
      u2_noun gad;

      if ( u2_no == u2_sing(bog, gen) ) {
        gad = _open_mold(wir_r, hep, bog);
      }
      else {
        gad = u2_bt
          (wir_r,
           c3__csld, 
           u2_bt(wir_r, c3__csbn, 
                        u2_rx(wir_r, gen), 
                        u2_bt(wir_r, c3__mtbn, u2_rx(wir_r, hep), u2_nul)),
                  u2_bt(wir_r, c3__mtbn, u2_rx(wir_r, hep), u2_nul));
      }
      u2_rl_lose(wir_r, bog);
      return gad;
    }
  }

    static u2_list
    _open_sift_a(u2_wire wir_r,
                 u2_noun ban)
    {
      if ( (u2_nul == ban) ) {
        return u2_nul;
      }
      else {
        return u2_bc
          (wir_r, _open_sift(wir_r, u2_h(ban)), 
                  _open_sift_a(wir_r, u2_t(ban)));
      }
    }
  static u2_noun
  _open_sift(u2_wire wir_r,
             u2_noun gen)
  {
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_as_pq(gen, c3__dgdp, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__dgdp, 
                _open_sift(wir_r, p_gen), 
                _open_sift(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__dtsg, &p_gen) ) {
      return u2_rx(wir_r, gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktbn, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktbn, 
                u2_rx(wir_r, p_gen), 
                _open_sift(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktpd, &p_gen, &q_gen) ) {
      return _open_sift(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__ktsg, &p_gen) ) {
      return u2_rx(wir_r, gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__ktmt, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__ktmt, 
                _open_sift(wir_r, p_gen), 
                _open_sift(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__mttr, &p_gen) ) {
      u2_noun pp_gen;

      if ( u2_yes == u2_as_p(p_gen, c3__brcs, &pp_gen) ) {
        return u2_bt(wir_r, c3__mttr,  
                            c3__brcs, 
                            _open_sift_a(wir_r, pp_gen));
      }
      else {
        return u2_bc(wir_r, c3__tmbn, c3__blur);
      }
    }
    else if ( u2_yes == u2_as_p(gen, c3__tmbn, &p_gen) ) {
      return u2_rx(wir_r, gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__tmdp, &p_gen) ) {    // XX delete
      return _open_sift(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__zpcb, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__zpcb, u2_rx(wir_r, p_gen), _open_sift(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__zpdx, &p_gen) ) {
      return u2_bc
        (wir_r, c3__zpdx, _open_sift(wir_r, q_gen));
    }
    else {
      u2_noun bog = j2_mby(Pit, open)(wir_r, gen);
      u2_noun gad;

      if ( !(u2_yes == u2_sing(gen, bog)) ) {
        gad =_open_sift(wir_r, bog);
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

/***
****
***/
  _open_do_pq(bndl)   //  =<
  {
    return u2_bt(wir_r, c3__bnld, u2_rx(wir_r, q_gen), 
                                  u2_rx(wir_r, p_gen));
  }

  _open_do_pq(bndp)   //  =-
  {
    return u2_bt(wir_r, c3__bnpd, u2_rx(wir_r, q_gen), 
                                  u2_rx(wir_r, p_gen));
  }

  _open_do_pq(bnpd)   //  =+
  {
    return u2_bt
      (wir_r, c3__bnld,
              u2_bt(wir_r, c3__dgdp, 
                           u2_rx(wir_r, p_gen), 
                           u2_bc(wir_r, u2_nul, _1)),
              u2_rx(wir_r, q_gen));
  }
/***
****
***/
  _open_do_p(brbn)    //  |=
  {
    return u2_bc
      (wir_r, c3__brtr,
              u2_bo(wir_r, u2_bc(wir_r, u2_blip, u2_rx(wir_r, p_gen))));
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
         c3__brld,
         u2_bt(wir_r, c3__ktdp, u2_bc(wir_r, c3__tmbn, c3__blur),
                                u2_rx(wir_r, ip_gen)),
         u2_bt(wir_r, c3__cstr,
                      u2_bc(wir_r, u2_nul, _4),
                      u2_rx(wir_r, p_gen)));
    }
  }
  _open_do_p(brdg)    //  |:
  {
    return u2_bt
      (wir_r, c3__brmt, 
              u2_bc(wir_r, u2_blip, u2_rx(wir_r, p_gen)),
              u2_nul);
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
  _open_do_p(brdp)    //  |-
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
                     c3__mtdp,
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
/***
****
***/
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
  _open_do_pq(csdl)   //  ?<
  {
    return u2_bq
      (wir_r, c3__csdg,
            u2_rx(wir_r, p_gen),
            u2_bc(wir_r, c3__zpzp, u2_nul),
            u2_rx(wir_r, q_gen));
  }
  _open_do_pqr(csdt)  //  ?.
  {
    return u2_bq(wir_r, c3__csdg, 
                        u2_rx(wir_r, p_gen), 
                        u2_rx(wir_r, r_gen), 
                        u2_rx(wir_r, q_gen));
  }
  _open_do_pq(csld)   //  ?>
  {
    return u2_bq
      (wir_r, c3__csdg, 
              u2_rx(wir_r, p_gen), 
              u2_rx(wir_r, q_gen), 
              u2_bc(wir_r, c3__zpzp, u2_nul));
  }
  _open_do_pq(csdp)   //  ?-
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
                      _open_sift(wir_r, piq_gen), 
                      u2_rx(wir_r, p_gen)),
         u2_bt
          (wir_r, c3__bnld,
                  u2_bq(wir_r, c3__mtbn,
                               u2_nul,
                               u2_bc(wir_r, 
                                     u2_rx(wir_r, p_gen),               
                                     u2_bt(wir_r, c3__ktpd,
                                                  u2_rx(wir_r, piq_gen),
                                                  u2_rx(wir_r, p_gen))),
                               u2_nul),
                  u2_rx(wir_r, qiq_gen)),
        _open_in_csdp(wir_r, p_gen, tq_gen));
    }
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
  _open_do_pq(cstr)   //  ?*
  {
    if ( (u2_nul == q_gen) ) {
      return u2_bc(wir_r, c3__zpzp, u2_nul);
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);
      u2_noun rak = j2_mby(Pit, rake)(wir_r, p_gen);
      u2_noun sif = _open_sift(wir_r, iq_gen);
      u2_noun mol = _open_mold(wir_r, rak, iq_gen);

      return u2_bq
        (wir_r,
         c3__csdg,
         u2_bt(wir_r, c3__csbn,
                      sif,
                      u2_bt(wir_r, c3__mtbn, rak, u2_nul)),
         mol,
         _open_in_cstr(wir_r, p_gen, tq_gen));
    }
  }
  _open_do_pqr(cssg)  //  ?~
  {
    return u2_bt
      (wir_r,
       c3__csdp,
       u2_rx(wir_r, p_gen),
       u2_bt
        (wir_r,
         u2_bc(wir_r, u2_bc(wir_r, c3__dtsg, u2_nul), u2_rx(wir_r, q_gen)),
         u2_bc(wir_r, u2_bc(wir_r, c3__tmbn, c3__cell), u2_rx(wir_r, r_gen)),
         u2_nul));
  }
  _open_do_p(cszp)    //  ?!
  {
    return u2_bq
      (wir_r, c3__csdg,
              u2_rx(wir_r, p_gen),
              u2_bc(wir_r, c3__dtsg, u2_no),
              u2_bc(wir_r, c3__dtsg, u2_yes));
  }
/***
****
***/
  _open_do_pqrs(dgkt) //  :^
  {
    return u2_bt
      (wir_r, c3__dgdp,
              u2_rx(wir_r, p_gen),
              u2_bt
                (wir_r, c3__dgdp,
                        u2_rx(wir_r, q_gen),
                        u2_bt(wir_r, c3__dgdp, u2_rx(wir_r, r_gen), 
                                               u2_rx(wir_r, s_gen))));
  }
  _open_do_pqr(dgpd)  //  :+
  {
    return u2_bt
      (wir_r, c3__dgdp,
              u2_rx(wir_r, p_gen),
              u2_bt(wir_r, c3__dgdp, u2_rx(wir_r, q_gen), 
                                     u2_rx(wir_r, r_gen)));
  }
  _open_do_p(dgsg)    //  :~
  {
    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__dtsg, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bt(wir_r, c3__dgdp, 
                          u2_rx(wir_r, ip_gen), 
                          _open_in_dgsg(wir_r, tp_gen));
    }
  }
  _open_do_p(dgtr)    //  :*
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
          (wir_r, c3__dgdp, u2_rx(wir_r, ip_gen), 
                            _open_in_dgtr(wir_r, tp_gen));
      }
    }
  }
/***
****
***/
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
/***
****
***/
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
      (wir_r, c3__mtdp, 
              u2_rx(wir_r, q_gen), 
              u2_bc(wir_r, u2_rx(wir_r, p_gen), u2_nul));
  }
  _open_do_pqrs(mtkt) //  %^
  {
    return u2_bq
      (wir_r, c3__mtdp, 
              u2_rx(wir_r, p_gen),
              u2_rx(wir_r, q_gen),
              u2_bt(wir_r, u2_rx(wir_r, r_gen), 
                           u2_rx(wir_r, s_gen), 
                           u2_nul));
  }
  _open_do_pq(mtdp)   //  %-
  {
    if ( (u2_nul == q_gen) ) {
      return u2_bt
        (wir_r, c3__bnld, 
                u2_rx(wir_r, p_gen),
                u2_blip);
    } else {
      return u2_bq(wir_r, c3__mtdg, 
                          u2_rx(wir_r, p_gen), 
                          c3__dgtr, 
                          u2_rx(wir_r, q_gen));
    }
  }
  _open_do_pqr(mtpd)  //  %+
  {
    return u2_bc
      (wir_r, c3__mtdp, 
              u2_bq(wir_r, u2_rx(wir_r, p_gen), 
                           u2_rx(wir_r, q_gen), 
                           u2_rx(wir_r, r_gen), 
                           u2_nul));
  }
  _open_do_p(mttr)    //  %*
  {
    return u2_bt(wir_r, c3__bnld,
                        u2_rx(wir_r, p_gen),
                        u2_bt(wir_r, c3__mtbn, 
                                     u2_bo(wir_r, u2_blip),
                                     u2_nul));
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
/***
****
***/
  _open_do_p(tmbn)    //  ;=
  {
    if ( u2_yes == u2_sing(c3__atom, p_gen) ) {
      return u2_bt
        (wir_r, c3__ktdp, 
              u2_bt(wir_r, c3__dtkt, c3__dtsg, _0),
              u2_bc(wir_r, c3__dtsg, _0));
    }
    else if ( u2_yes == u2_sing(c3__blur, p_gen) ) {
      u2_noun dud = u2_bc(wir_r, c3__dtsg, u2_nul);

      return u2_bt
        (wir_r, c3__ktdp, 
                u2_bt(wir_r, c3__dttr, 
                             u2_rx(wir_r, dud), 
                             u2_rx(wir_r, dud)),
                dud);
    }
    else if ( u2_yes == u2_sing(c3__cell, p_gen) ) {
      return u2_bt
        (wir_r, c3__dgdp,
              u2_bc(wir_r, c3__tmbn, c3__blur),
              u2_bc(wir_r, c3__tmbn, c3__blur));
    }
    else if ( u2_yes == u2_sing(c3__flag, p_gen) ) {
      return u2_bt
        (wir_r, c3__ktdp,
              u2_bt(wir_r, c3__dtcs, c3__dtsg, _0),
              u2_bc(wir_r, c3__dtsg, u2_yes));
    }
    else if ( u2_yes == u2_sing(c3__null, p_gen) ) {
        return u2_bc(wir_r, c3__dtsg, u2_nul);
    }
    else return u2_bl_bail(wir_r);
  }
  _open_do_p(tmdp)    //  ;-
  {
    return _open_sift(wir_r, p_gen);
  }
  _open_do_pq(tmpd)    //  ;+
  {
    u2_noun rak = j2_mby(Pit, rake)(wir_r, q_gen);
    u2_noun pro = _open_mold(wir_r, rak, p_gen);

    u2_rl_lose(wir_r, rak);
    return pro;
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
      _open_pq  (bndp);
      _open_pq  (bnpd);

      _open_p   (brbn);
      _open_p   (brdg);
      _open_pq  (brdl);
      _open_pq  (brsg);
      _open_p   (brdp);
      _open_p   (brcs);
      _open_pq  (brld);

      _open_pqrs(dgkt);
      _open_pqr (dgpd);
      _open_p   (dgtr);
      _open_p   (dgsg);

      _open_p   (csbr);
      _open_pqr (csdt);
      _open_pq  (csdl);
      _open_p   (cszp);
      _open_pq  (cstr);
      _open_p   (cspm);
      _open_pq  (csdp);
      _open_pqr (cssg);
      _open_pq  (csld);

      _open_pq  (ktdl);

      _open_pqr (mtbr);
      _open_pq  (mtdg);
      _open_pq  (mtdt);
      _open_pqrs(mtkt);
      _open_pq  (mtdp);
      _open_pqr (mtpd);
      _open_p   (mttr);
      _open_pqr (mtsg);

      _open_p   (tmbn);
      _open_p   (tmdp);
      _open_pq  (tmpd);
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
    { ".3", c3__hevy, j2_mb(Pit, open), SafeTier6_c, u2_none, u2_none },
    { }
  };
