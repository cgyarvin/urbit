/* j/5/to.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* forward declares
*/
  u2_atom j2_mcy(Pit, to, wit)(u2_wire, u2_noun);

/* functions
*/
    static u2_atom
    _wit_grip_in(u2_wire wir_r,
                 u2_noun q_pup)
    {
      u2_atom foz = 0;
      
      while ( u2_yes == u2_dust(q_pup) ) {
        u2_noun iq_pup = u2_h(q_pup);
        u2_noun tq_pup = u2_t(q_pup);
        u2_noun tiw    = j2_mcy(Pit, to, wit)(wir_r, iq_pup);
        u2_noun xot;

        if ( 0 == foz ) {
          xot = u2_rx(wir_r, foz);
        } else {
          xot = j2_mbc(Pit, add)(wir_r, 1, foz);
        }
        u2_rz(wir_r, foz);

        foz = j2_mbc(Pit, add)(wir_r, xot, tiw);
        u2_rz(wir_r, xot);
        u2_rz(wir_r, tiw);

        q_pup = tq_pup;
      }
      return foz;
    }
    static u2_atom
    _wit_meld_in(u2_wire wir_r,
                 u2_noun p_pup)
    {
      u2_atom foz = 0;
  
      while ( u2_yes == u2_dust(p_pup) ) {
        u2_noun ip_pup = u2_h(p_pup);
        u2_noun tp_pup = u2_t(p_pup);
        u2_noun tiw = j2_mcy(Pit, to, wit)(wir_r, ip_pup);
        u2_noun xot = j2_mbc(Pit, add)(wir_r, foz, tiw);

        u2_rz(wir_r, foz);
        u2_rz(wir_r, tiw);
        foz = xot;

        p_pup = tp_pup;
      }
      return foz;
    }

  u2_atom                                                         //  transfer
  j2_mcy(Pit, to, wit)(u2_wire wir_r,
                       u2_noun pup)                               //  retain
  {
    u2_noun p_pup, q_pup, pp_pup, qp_pup;

    if ( u2_no == u2_dust(pup) ) {
      return j2_mbc(Pit, met)(wir_r, _3, pup);
    } else  switch ( u2_h(pup) ) {
      default: return u2_bl_bail(wir_r);

      case c3__duct: p_pup = u2_t(pup);
      {
        return j2_mbc(Pit, lent)(wir_r, p_pup);
      }
      case c3__grip: u2_bi_cell(wir_r, pup, &p_pup, &q_pup);
                     u2_bi_cell(wir_r, p_pup, &pp_pup, &qp_pup);
      {
        u2_noun zaq = j2_mbc(Pit, met)(wir_r, _3, pp_pup);
        u2_noun lor = j2_mbc(Pit, met)(wir_r, _3, qp_pup);
        u2_noun fod = j2_mbc(Pit, add)(wir_r, zaq, lor);
        u2_noun vux = _wit_grip_in(wir_r, q_pup);
        u2_noun ley = j2_mbc(Pit, add)(wir_r, vux, fod);

        u2_rz(wir_r, zaq);
        u2_rz(wir_r, lor);
        u2_rz(wir_r, vux);
        u2_rz(wir_r, fod);

        return ley;
      }
      case c3__meld: p_pup = u2_t(pup);
      {
        return _wit_meld_in(wir_r, p_pup);
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, to, wit)(u2_wire wir_r, 
                      u2_noun cor)                                //  retain
  {
    u2_noun pup;

    if ( u2_none == (pup = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, to, wit)(wir_r, pup);
    }
  }

/* declarations
*/
  extern u2_ho_jet j2_mcj(Pit, to, fly)[];

  u2_ho_driver 
  j2_mbd(Pit, to)[] = {
//    { j2_sc(Pit, to, fly), j2_mcj(Pit, to, fly), 0, 0, u2_none },
    {}
  };

  u2_ho_jet 
  j2_mbj(Pit, to)[] = {
    { "wit", c3__hevy, j2_mc(Pit, to, wit), Tier5, u2_none, u2_none },
 //   { "ram", c3__hevy, j2_mc(Pit, to, ram), Tier5, u2_none, u2_none },
    { }
  };
