/* j/6/gain.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* internals
*/
  static u2_noun
  _gain_skmp(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun p_gen)
  {
    if ( u2_nul == p_gen ) {
      return u2_rx(wir_r, sut);
    } 
    else if ( u2_no == u2_dust(p_gen) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);
      u2_noun lev = j2_mcy(Pit, vane, gain)(wir_r, van, sut, ip_gen);
      u2_noun pro = _gain_skmp(wir_r, van, lev, tp_gen);

      u2_rl_lose(wir_r, lev);
      return pro;
    }
  }

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, gain)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_atom gen)                            //  retain
  {
    u2_noun p_gen, q_gen;

    if ( u2_no == u2_dust(gen) ) { 
      return u2_rx(wir_r, sut);
    } else {
      switch ( u2_h(gen) ) {
        default: return u2_rx(wir_r, sut);

        case c3__htdv:
        case c3__htvd: {
          if ( u2_none == (q_gen = u2_frag(6, gen)) ) {
            return u2_bl_bail(wir_r);
          } else {
            return j2_mcy(Pit, vane, gain)(wir_r, van, sut, q_gen);
          }
        }
        case c3__skbn: {
          if ( u2_no == u2_mean(gen, 6, &p_gen, 7, &q_gen, 0) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun rac = j2_mby(Pit, rake)(wir_r, q_gen);
            u2_noun hap = j2_mcy(Pit, vane, play)(wir_r, van, sut, p_gen);
            u2_noun vul = j2_mcy(Pit, vane, play)(wir_r, van, sut, q_gen);
            u2_noun gav = j2_mcy(Pit, vane, reap)(wir_r, vul, hap);
            u2_noun pro = j2_mcy(Pit, vane, etch)(wir_r, van, sut, rac, gav);

            u2_rl_lose(wir_r, rac);
            u2_rl_lose(wir_r, hap);
            u2_rl_lose(wir_r, vul);
            u2_rl_lose(wir_r, gav);

            return pro;
          }
        }
        case c3__skmp: {
          return _gain_skmp(wir_r, van, sut, u2_t(gen));
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, gain)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, gen, van;

    if ( (u2_no == u2_mean(cor, 4, &gen, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, gain)(wir_r, van, sut, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, gain)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, gain), u2_no, u2_none, u2_none },
    { }
  };
