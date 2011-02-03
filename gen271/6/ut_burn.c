/* j/6/ut_burn.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, burn)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut)                              //  retain
  {
    u2_noun ret, p_sut, q_sut, r_sut, pr_sut, qr_sut;

    if ( u2_no == u2_dust(sut) ) switch ( sut ) {
      default: return u2_bl_bail(wir_r);

      case c3__atom: return u2_bc(wir_r, c3__atom, _0);
      case c3__blot: return u2_bl_bail(wir_r);
      case c3__blur: return u2_bc(wir_r, c3__blur, _0);
    }
    else switch ( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
      {
        u2_noun hed = j2_mcy(Pit, ut, burn)(wir_r, van, p_sut);
        u2_noun tal = j2_mcy(Pit, ut, burn)(wir_r, van, q_sut);

        ret = u2_bc
          (wir_r, j2_mby(Pit, cell)(wir_r, u2_h(hed)), u2_h(tal)),
                  u2_bc(wir_r, u2_rx(wir_r, u2_t(hed)), 
                               u2_rx(wir_r, u2_t(tal)));

        u2_rl_lose(wir_r, hed);
        u2_rl_lose(wir_r, tal);

        return ret;
      }
      case c3__core: u2_bi_trel(wir_r, u2_t(sut), &p_sut, &q_sut, &r_sut);
                     u2_bi_cell(wir_r, r_sut, &pr_sut, &qr_sut);
      {
        u2_noun dan = j2_mcy(Pit, ut, burn)(wir_r, van, p_sut);

        if ( u2_nul == pr_sut ) {
          ret = u2_bc
            (wir_r, j2_mby(Pit, cell)(wir_r, u2_h(dan), c3__blur),
                    u2_bc(wir_r, u2_rx(wir_r, u2_t(dan)), u2_nul));
        }
        else {
          ret = u2_bc
            (wir_r, j2_mby(Pit, core)(wir_r, u2_h(dan), p_sut, q_sut, r_sut),
                    u2_bc(wir_r, u2_rx(wir_r, u2_t(dan)),
                                 u2_rx(wir_r, pr_sut)));
        }
        u2_rl_lose(wir_r, dan);
        return ret;
      }
      case c3__cube: p_sut = u2_t(sut);
      {
        return u2_bc(wir_r, u2_rx(wir_r, sut), u2_rx(wir_r, p_sut));
      }
      case c3__face: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
      {
        u2_noun fos = j2_mcy(Pit, ut, burn)(wir_r, van, q_sut);

        ret = u2_bc
          (wir_r, j2_mby(Pit, face)(wir_r, p_sut, u2_h(fos)),
                  u2_rx(wir_r, u2_t(fos)));

        u2_rl_lose(wir_r, fos);
        return ret;
      }
      case c3__fork: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
      {
        u2_noun fos = j2_mcy(Pit, ut, burn)(wir_r, van, p_sut);

        ret = u2_bc
          (wir_r, j2_mby(Pit, fork)(wir_r, u2_h(fos), q_sut),
                  u2_rx(wir_r, u2_t(fos)));

        u2_rl_lose(wir_r, fos);
        return ret;
      }
      case c3__hold: u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
      {
        u2_noun rep = j2_mcy(Pit, ut, repo)(wir_r, van, sut);
        u2_noun fos = j2_mcy(Pit, ut, burn)(wir_r, van, rep);

        u2_rl_lose(wir_r, rep);
        return fos;
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, burn)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut;

    if ( u2_none == (sut = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, ut, burn)(wir_r, cor, sut);
    }
  }
