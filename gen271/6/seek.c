/* j/6/seek.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, seek)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun rep)                            //  retain
  {
    if ( u2_nul == rep ) {
      return u2_bt
        (wir_r, _1, u2_nul, u2_rx(wir_r, sut));
    }
    else if ( u2_no == u2_dust(rep) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      u2_noun i_rep = u2_h(rep);
      u2_noun t_rep = u2_t(rep);
      u2_noun vag = j2_mcy(Pit, vane, seek)(wir_r, van, sut, t_rep);
      u2_noun p_vag, q_vag, r_vag;
      u2_noun pro;

      u2_as_trel(vag, &p_vag, &q_vag, &r_vag);
      j2_mby(Pit, type)(wir_r, r_vag); 

      if ( u2_no == u2_dust(i_rep) ) {
        u2_noun hup = j2_mcy(Pit, vane, find)(wir_r, van, r_vag, i_rep);
        u2_noun p_hup, q_hup, r_hup;

        u2_as_trel(hup, &p_hup, &q_hup, &r_hup);

        pro = u2_bt
          (wir_r, j2_mbc(Pit, peg)(wir_r, p_vag, p_hup), 
                  u2_rx(wir_r, q_hup),
                  u2_rx(wir_r, r_hup));

        u2_rl_lose(wir_r, vag);
        u2_rl_lose(wir_r, hup);

        return pro;
      } 
      else {
        u2_noun hi_rep = u2_h(i_rep);
        u2_noun pi_rep = u2_t(i_rep);

        if ( (u2_nul != hi_rep) || (u2_no == u2_stud(pi_rep)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          pro = u2_bt
            (wir_r, j2_mbc(Pit, peg)(wir_r, p_vag, pi_rep),
                    u2_nul,
                    j2_mcy(Pit, vane, peek)(wir_r, van, r_vag, pi_rep));

          u2_rl_lose(wir_r, vag);
          return pro;
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, seek)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, rep, van;

    if ( (u2_no == u2_mean(cor, 4, &rep, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, seek)(wir_r, van, sut, rep);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, seek)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, seek), SafeTier6, u2_none, u2_none },
    { }
  };
