/* j/6/ut_repo.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  static u2_noun 
  _repo_hold_gar(u2_wire wir_r,
                 u2_noun van,
                 u2_noun p_sut,
                 u2_noun q_sut)
  {
    if ( u2_no == u2_dust(q_sut) ) {
      return (u2_nul == q_sut ? u2_nul : u2_bl_bail(wir_r));
    } else {
      return u2_bc
        (wir_r, j2_mcy(Pit, ut, play)(wir_r, van, p_sut, u2_h(q_sut)),
                _repo_hold_gar(wir_r, van, p_sut, u2_t(q_sut)));
    }
  }
  static u2_noun
  _repo_hold_nog(u2_wire wir_r,
                 u2_noun van,
                 u2_noun gar)
  {
    u2_noun gun = j2_mcc(Pit, in, gas)(wir_r, u2_nul, gar);
    u2_noun nog = j2_mcc(Pit, in, tap)(wir_r, gun, u2_nul);

    u2_rl_lose(wir_r, gun);
    return nog;
  }
  static u2_noun
  _repo_hold_fub(u2_wire wir_r,
                 u2_noun nog,
                 u2_noun fub)
  {
    if ( u2_no == u2_dust(nog) ) {
      return (u2_nul == q_sut ? u2_rx(wir_r, fub) : u2_bl_bail(wir_r));
    } else {
      u2_noun buf = j2_mby(Pit, fork)(wir_r, fub, u2_h(nog));
      u2_noun rud = _repo_hold_fub(wir_r, u2_t(nog), buf);

      u2_rl_lose(wir_r, buf);
      return rud;
    }
  }

  static u2_noun
  _repo_hold(u2_wire wir_r,
             u2_noun van,
             u2_noun p_sut,
             u2_noun q_sut)
  {
    u2_noun gar = _repo_hold_gar(wir_r, van, p_sut, q_sut);
    u2_noun nog = _repo_hold_nog(wir_r, gar);
    u2_noun fub = _repo_hold_fub(wir_r, nog, c3__blot);

    u2_rl_lose(wir_r, gar);
    u2_rl_lose(wir_r, nog);

    return fub;
  }
  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, repo)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut)                              //  retain
  {
    u2_noun p_sut, q_sut;

    if ( _1 == axe ) {
      return j2_mcy(Pit, ut, fuse)(wir_r, van, sut, ref);
    } else {
      u2_atom now = j2_mbc(Pit, cap)(wir_r, axe);
      u2_atom den = j2_mbc(Pit, mas)(wir_r, axe);

      if ( u2_no == u2_dust(sut) ) switch ( sut ) {
        default: return u2_rx(wir_r, sut);

        case c3__noun: 
          return u2_bt(wir_r, c3__fork, 
                              c3__atom, 
                              u2_bt(wir_r, c3__cell, c3__noun, c3__noun));
      }
      else switch ( u2_h(sut) ) {
        default: return u2_rx(wir_r, sut);

        case c3__core: {
          if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
            return u2_bl_bail(wir_r);
          } else {
            return u2_bt(wir_r, c3__cell, u2_rx(wir_r, p_sut), c3__noun);
          }
        }
        case c3__cube: {
          p_sut = u2_t(sut);
          {
            if ( u2_yes == u2_stud(p_sut) ) {
              return u2_rx(wir_r, p_sut);
            }
            else {
              return u2_bt
                (wir_r, c3__cell,
                        u2_bc(wir_r, c3__cube, u2_rx(wir_r, u2_h(p_sut))),
                        u2_bc(wir_r, c3__cube, u2_rx(wir_r, u2_t(p_sut))));
          }
        }
        case c3__face: {
          if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut)) {
            return u2_bl_bail(wir_r);
          } else {
            return u2_rx(wir_r, q_sut);
          }
        }
        case c3__hold: {
          if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut)) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun fan = u2_bn_hook(wir_r, van, "fan");

            if ( u2_yes == j2_mcc(Pit, in, has)(wir_r, fan, sut) ) {
              printf("jet: inference recursion\n");
              return u2_bl_bail(wir_r);
            }
            else {
              u2_noun nav = u2_bn_cook
                (wir_r, van, 
                        "fan", 
                        j2_mcc(Pit, in, put)(wir_r, fan, _u2_rx(wir_r, sut)));
              u2_noun mez = _repo_hold
                (wir_r, nav, p_sut, q_sut);

              u2_rl_lose(wir_r, nav);
              return mez;
            }
          }
        }
      }   
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, repo)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut;

    if ( u2_none == (sut = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, ut, repo)(wir_r, cor, sut);
    }
  }
