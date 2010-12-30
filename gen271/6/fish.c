/* j/6/fish.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  static u2_noun
  _fish_in(u2_wire wir_r,
           u2_noun van,
           u2_noun sut,
           u2_atom axe,
           u2_noun vit)
  {
    u2_noun p_sut, q_sut;

    if ( u2_yes == u2_stud(sut) ) switch ( sut ) {
      default: return u2_bl_bail(wir_r);

      case c3__atom: {
        u2_noun ton = u2_bt(wir_r, _3, _0, u2_rx(wir_r, axe));
        u2_noun pro = j2_mby(Pit, flip)(wir_r, ton);

        u2_rl_lose(wir_r, ton);
        return pro;
      }
      case c3__blot: {
        return u2_bc(wir_r, _1, _1);
      }
      case c3__blur: {
        return u2_bc(wir_r, _1, _0);
      }
    }
    else switch ( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun hut = u2_bt(wir_r, _3, _0, u2_rx(wir_r, axe));
          u2_noun lef = j2_mbc(Pit, peg)(wir_r, axe, _2);
          u2_noun rit = j2_mbc(Pit, peg)(wir_r, axe, _3);
          u2_noun hed = _fish_in(wir_r, van, p_sut, lef, vit);
          u2_noun tal = _fish_in(wir_r, van, q_sut, rit, vit);
          u2_noun hob = j2_mby(Pit, flan)(wir_r, hed, tal);
          u2_noun vug = j2_mby(Pit, flan)(wir_r, hut, hob);

          u2_rl_lose(wir_r, hob);
          u2_rl_lose(wir_r, tal);
          u2_rl_lose(wir_r, hed);
          u2_rl_lose(wir_r, rit);
          u2_rl_lose(wir_r, lef);
          u2_rl_lose(wir_r, hut);

          return vug;
        }
      }
      case c3__core: {
        return u2_bc(wir_r, _0, _0);
      }
      case c3__cube: {
        p_sut = u2_t(sut);
        {
          return u2_bt
            (wir_r, _5, 
                    u2_bc(wir_r, _1, u2_rx(wir_r, p_sut)),
                    u2_bc(wir_r, _0, u2_rx(wir_r, axe)));
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return _fish_in(wir_r, van, q_sut, axe, vit);
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun hed = _fish_in(wir_r, van, p_sut, axe, vit);
          u2_noun tal = _fish_in(wir_r, van, q_sut, axe, vit);
          u2_noun pro = j2_mby(Pit, flor)(wir_r, hed, tal);

          u2_rl_lose(wir_r, hed);
          u2_rl_lose(wir_r, tal);

          return pro;
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, vit, sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, vit, sut);
            u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
            u2_noun pro = _fish_in(wir_r, van, fop, axe, zoc);

            u2_rl_lose(wir_r, fop);
            u2_rl_lose(wir_r, zoc);

            return pro;
          }
        }
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, fish)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_atom axe)                            //  retain
  {
    return _fish_in(wir_r, van, sut, axe, u2_nul);
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, fish)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, axe, van;

    if ( (u2_no == u2_mean(cor, 4, &axe, 5, &van, 0)) ||
         (u2_no == u2_stud(axe)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, fish)(wir_r, van, sut, axe);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, fish)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, fish), u2_no, u2_none, u2_none },
    { }
  };
