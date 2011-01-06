/* j/6/snap.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, snap)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun p_sut, q_sut;
    u2_noun ret;

    if ( u2_no == u2_dust(sut) ) {
      return u2_rx(wir_r, gen);
    }
    else switch ( u2_h(sut) ) {
      default: return u2_rx(wir_r, gen);

      case c3__cell: {
        if ( (u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun haq = j2_mby(Pit, hack)(wir_r, gen);

          if ( u2_yes == u2_h(haq) ) {
            u2_noun p_haq, q_haq;

            u2_as_cell(u2_t(haq), &p_haq, &q_haq);

            ret = u2_bt
              (wir_r, c3__dgnp,
                     j2_mcy(Pit, vane, snap)(wir_r, van, p_sut, ref, p_haq),
                     j2_mcy(Pit, vane, snap)(wir_r, van, q_sut, ref, q_haq));
          } else {
            ret = u2_rx(wir_r, gen);
          }
          u2_rl_lose(wir_r, haq);
          return ret;
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return u2_bt
            (wir_r, c3__htbn,
                    u2_rx(wir_r, p_sut),
                    j2_mcy(Pit, vane, snap)(wir_r, van, q_sut, ref, gen));
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun vap = j2_mcy(Pit, vane, play)(wir_r, van, ref, gen);

          if ( c3__blot == j2_mcy(Pit, vane, reap)(wir_r, van, p_sut, vap) ) {
            if ( c3__blot == j2_mcy(Pit, vane, reap)(wir_r, van, q_sut, vap) ) {
              ret = u2_rx(wir_r, gen);
            }
            else ret = j2_mcy(Pit, vane, snap)(wir_r, van, q_sut, ref, gen);
          } else {
            if ( c3__blot == j2_mcy(Pit, vane, reap)(wir_r, van, q_sut, vap) ) {
              ret = j2_mcy(Pit, vane, snap)(wir_r, van, p_sut, ref, gen);
            }
            else ret = u2_rx(wir_r, gen);
          }
          u2_rl_lose(wir_r, vap);
          return ret;
        }
      }
      case c3__hold: {
        if ( (u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
          
          ret = j2_mcy(Pit, vane, snap)(wir_r, van, fop, ref, gen);
          u2_rl_lose(wir_r, fop);

          return ret;
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, snap)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, van, ref, gen;

    if ( (u2_no == u2_mean(cor, 8, &ref, 9, &gen, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, snap)(wir_r, van, sut, ref, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, snap)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, snap), u2_no, u2_none, u2_none },
    { }
  };
