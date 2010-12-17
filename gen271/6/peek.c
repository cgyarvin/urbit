/* j/6/peek.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, peek)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_atom axe)                            //  retain
  {
    if ( _1 == axe ) {
      return u2_rx(wir_r, sut);
    }
    else {
      u2_noun p_sut, q_sut, r_sut;
      u2_noun pro;

      if ( (u2_no == u2_dust(sut)) ) switch ( sut ) {
        default: return u2_bl_bail(wir_r);

        case c3__atom: {
          return c3__blot;
        }
        case c3__blot: {
          return c3__blot;
        }
        case c3__blur: {
          return c3__blur;
        }
      }
      else switch ( u2_h(sut) ) {
        default: return u2_bl_bail(wir_r);

        case c3__cell: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_atom tip = j2_mbc(Pit, cap)(wir_r, axe);
            u2_atom tap = j2_mbc(Pit, mas)(wir_r, axe);

            if ( _2 == tip ) {
              pro = j2_mcy(Pit, vane, peek)(wir_r, van, p_sut, tap);
            }
            else {
              pro = j2_mcy(Pit, vane, peek)(wir_r, van, q_sut, tap);
            }
            u2_rl_lose(wir_r, tap); 
            u2_rl_lose(wir_r, tip);

            return pro;
          }
        }
        case c3__core: {
          if ( u2_no == u2_as_qual(sut, 0, &p_sut, &q_sut, &r_sut) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_atom tip = j2_mbc(Pit, cap)(wir_r, axe);
            u2_atom tap = j2_mbc(Pit, mas)(wir_r, axe);

            if ( _2 == tip ) {
              pro = j2_mcy(Pit, vane, peek)(wir_r, van, p_sut, tap);
            }
            else {
              pro = c3__blur;
            }
            u2_rl_lose(wir_r, tap); 
            u2_rl_lose(wir_r, tip);

            return pro;
          }
        }
        case c3__cube: {
          p_sut = u2_t(sut);
          {
            u2_noun gud;

            if ( u2_none == (gud = u2_frag(axe, p_sut)) ) {
              return c3__blot;
            } else {
              return u2_rx(wir_r, gud);
            }
          }
        }
        case c3__face: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            return j2_mcy(Pit, vane, peek)(wir_r, van, q_sut, axe);
          }
        }
        case c3__fork: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun hed = j2_mcy(Pit, vane, peek)(wir_r, van, p_sut, axe);
            u2_noun tal = j2_mcy(Pit, vane, peek)(wir_r, van, q_sut, axe);

            pro = j2_mby(Pit, eith)(wir_r, hed, tal);

            u2_rl_lose(wir_r, hed);
            u2_rl_lose(wir_r, tal);

            return pro;
          }
        } 
        case c3__hold: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);

            pro = j2_mcy(Pit, vane, peek)(wir_r, van, fop, axe);

            u2_rl_lose(wir_r, fop);
            return pro;
          }
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, peek)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, axe, van;

    if ( (u2_no == u2_mean(cor, 4, &axe, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, peek)(wir_r, van, sut, axe);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, peek)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, peek), u2_no, u2_none, u2_none },
    { }
  };
