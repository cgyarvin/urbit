/* j/5/just.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

  static u2_noun                                                  //  produce
  _slip(u2_wire wir_r,
        u2_noun weq,                                              //  retain
        u2_noun naz)                                              //  retain
  {
    u2_noun p_naz, q_naz;

    u2_bi_cell(wir_r, naz, &p_naz, &q_naz);
    if ( 10 == weq ) {
      return u2_bc(wir_r, u2_bl_good(wir_r, 
                                     u2_rl_vint(wir_r, u2_rx(wir_r, p_naz))),
                          1);
    } else {
      return u2_bc(wir_r, u2_rx(wir_r, p_naz),
                          u2_bl_good(wir_r,
                                     u2_rl_vint(wir_r, u2_rx(wir_r, q_naz))));
    }
  }

  static u2_noun                                                  //  produce
  _fail(u2_wire wir_r,
        u2_noun tub)                                              //  retain
  {
    u2_noun p_tub, q_tub;

    u2_bi_cell(wir_r, tub, &p_tub, &q_tub);
    return u2_bc(wir_r, u2_rx(wir_r, p_tub), u2_nul);
  }

  static u2_noun                                                  //  produce
  _next(u2_wire wir_r,
        u2_noun tub)                                              //  retain
  {
    u2_noun p_tub, q_tub;
    u2_noun zac;

    u2_bi_cell(wir_r, tub, &p_tub, &q_tub);
    if ( u2_no == u2_dust(q_tub) ) {
      return _fail(wir_r, tub);
    } 
    else {
      u2_noun iq_tub = u2_h(q_tub);
      u2_noun tq_tub = u2_t(q_tub);

      zac = _slip(wir_r, iq_tub, p_tub);

      return u2_bc
        (wir_r, zac,
                u2_bq(wir_r, u2_nul,
                             u2_rx(wir_r, iq_tub),
                             u2_rx(wir_r, zac),
                             u2_rx(wir_r, tq_tub)));
    }
  }

  u2_noun                                                         //  produce
  j2_mcx(Pt5, just, fun)(u2_wire wir_r,
                         u2_noun daf,                             //  retain
                         u2_noun tub)                             //  retain
  {
    u2_noun p_tub, q_tub;

    u2_bi_cell(wir_r, tub, &p_tub, &q_tub);

    if ( u2_no == u2_dust(q_tub) ) {
      return _fail(wir_r, tub);
    }
    else {
      u2_noun iq_tub = u2_h(q_tub);

      if ( u2_yes == u2_sing(daf, iq_tub) ) {
        return _next(wir_r, tub);
      }
      else return _fail(wir_r, tub);
    }
  }

  u2_noun                                                         //  produce
  j2_mc(Pt5, just, fun)(u2_wire wir_r, 
                        u2_noun cor)                              //  retain
  {
    u2_noun van, daf, tub;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, u2_cw_sam, &tub, 0)) ||
         (u2_none == (daf = u2_frag(u2_cw_sam, van))) )
    {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mcx(Pt5, just, fun)(wir_r, daf, tub);
    }
  }

  u2_ho_jet 
  j2_mcj(Pt5, just, fun)[] = {
    { ".3", c3__hevy, j2_mc(Pt5, just, fun), Tier5_b, u2_none, u2_none },
    { }
  };

/* structures
*/
  u2_ho_driver 
  j2_mbd(Pt5, just)[] = {
    { j2_sc(Pt5, just, fun), j2_mcj(Pt5, just, fun), 0, 0, u2_none },
    { }
  };

  u2_ho_driver
  j2_db(Pt5, just) = 
    { j2_sb(Pt5, just), 0, j2_mbd(Pt5, just), 0, u2_none };
