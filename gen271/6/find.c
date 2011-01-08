/* j/6/find.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* internals
*/
  static u2_noun
  _find_in(u2_wire wir_r,
           u2_noun van,
           u2_noun sut,
           u2_noun cog,
           u2_noun gil)
  {
    u2_noun p_sut, q_sut, r_sut;

    if ( u2_yes == u2_stud(sut) ) {
      return u2_nul;
    }
    else switch ( u2_h(sut) ) {
      default: return u2_nul;

      case c3__cell: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun taf = _find_in(wir_r, van, p_sut, cog, gil);

          if ( u2_nul == taf ) {
            u2_noun bov = _find_in(wir_r, van, q_sut, cog, gil);

            if ( u2_nul == bov ) {
              return u2_nul;
            } else {
              u2_noun p_bov, q_bov, r_bov;
              u2_noun pro;

              u2_mean(bov, 6, &p_bov, 14, &q_bov, 15, &r_bov, 0);
              pro = u2_bq
                (wir_r, u2_nul,
                        j2_mbc(Pit, peg)(wir_r, 3, p_bov),
                        u2_rx(wir_r, q_bov),
                        u2_rx(wir_r, r_bov));

              u2_rl_lose(wir_r, bov);
              return pro;
            }
          } else {
            u2_noun p_taf, q_taf, r_taf;
            u2_noun pro;

            u2_mean(taf, 6, &p_taf, 14, &q_taf, 15, &r_taf, 0);
            pro = u2_bq
              (wir_r, u2_nul,
                      j2_mbc(Pit, peg)(wir_r, 2, p_taf),
                      u2_rx(wir_r, q_taf),
                      u2_rx(wir_r, r_taf));

            u2_rl_lose(wir_r, taf);
            return pro;
          }
        }
      }
      case c3__core: {
        if ( u2_no == u2_as_qual(sut, 0, &p_sut, &q_sut, &r_sut) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun zem = j2_mby(Pit, look)(wir_r, cog, r_sut);

          if ( u2_nul == zem ) {
            u2_noun taf = _find_in(wir_r, van, p_sut, cog, gil);

            if ( u2_nul == taf ) {
              return u2_nul;
            } else {
              u2_noun p_taf, q_taf, r_taf;
              u2_noun pro;

              u2_mean(taf, 6, &p_taf, 14, &q_taf, 15, &r_taf, 0);
              pro = u2_bq
                (wir_r, u2_nul,
                        j2_mbc(Pit, peg)(wir_r, 2, p_taf),
                        u2_rx(wir_r, q_taf),
                        u2_rx(wir_r, r_taf));

              u2_rl_lose(wir_r, taf);
              return pro;
            }
          }
          else {
            u2_noun p_zem, q_zem;
            u2_noun pro;

            u2_mean(zem, 6, &p_zem, 7, &q_zem, 0);

            pro = u2_bq
              (wir_r, u2_nul,
                      _1,
                      u2_bt(wir_r, u2_nul, 
                                   j2_mbc(Pit, peg)(wir_r, 3, p_zem),
                                   u2_rx(wir_r, q_zem)),
                      j2_mcy(Pit, vane, clay)(wir_r, van, sut));

            u2_rl_lose(wir_r, zem);
            return pro;
          }
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          if ( u2_no == u2_sing(cog, p_sut) ) {
            return u2_nul;
          } else {
            return u2_bq(wir_r, u2_nul, _1, u2_nul, u2_rx(wir_r, q_sut));
          }
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun hax = _find_in(wir_r, van, p_sut, cog, gil);
          u2_noun yor = _find_in(wir_r, van, q_sut, cog, gil);
          u2_noun p_hax, q_hax, r_hax;
          u2_noun p_yor, q_yor, r_yor;
          u2_noun pro;

          if ( u2_nul == hax ) {
            if ( u2_nul == yor ) {
              return u2_nul;
            } else {
              u2_mean(yor, 6, &p_yor, 14, &q_yor, 15, &r_yor, 0);
              {
                u2_noun vum = j2_mcy(Pit, vane, peek)
                  (wir_r, van, p_sut, p_yor);

                if ( c3__blot != vum ) {
                  return u2_bl_bail(wir_r);
                }
                else return yor;
              }
            }
          }
          else {
            if ( u2_nul == hax ) {
              u2_mean(hax, 6, &p_hax, 14, &q_hax, 15, &r_hax, 0);
              {
                u2_noun vum = j2_mcy(Pit, vane, peek)
                  (wir_r, van, p_sut, p_hax);

                if ( c3__blot != vum ) {
                  return u2_bl_bail(wir_r);
                }
                else return hax;
              }
            }
            else {
              if ( u2_yes == u2_sing(hax, yor) ) {
                u2_rl_lose(wir_r, yor);

                return hax;
              } else {
                u2_mean(hax, 6, &p_hax, 14, &q_hax, 15, &r_hax, 0);
                u2_mean(yor, 6, &p_yor, 14, &q_yor, 15, &r_yor, 0);

                if ( (u2_yes == u2_sing(p_hax, p_yor)) &&
                     (u2_nul == q_hax) &&
                     (u2_nul == q_yor) )
                {
                  pro = u2_bq
                    (wir_r, 
                     u2_nul,
                     u2_rx(wir_r, p_hax),
                     u2_nul,
                     j2_mby(Pit, eith)
                        (wir_r, u2_rx(wir_r, r_hax), u2_rx(wir_r, r_yor)));

                  u2_rl_lose(wir_r, hax);
                  u2_rl_lose(wir_r, yor);

                  return pro;
                }
              }
            }
          }
        }
      } 
      case c3__hold: {
        u2_rl_ok(wir_r, sut);
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, gil, sut)) ) {
            return u2_nul;
          } 
          else {
            u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, gil, sut);
            u2_type fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
            u2_noun pro = _find_in(wir_r, van, fop, cog, zoc);

            u2_rl_lose(wir_r, fop);
            u2_rl_lose(wir_r, zoc);

            return pro;
          }
        }
      }
    }
  }

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, find)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun cog)                            //  retain
  {
    u2_noun fin = _find_in(wir_r, van, sut, cog, u2_nul);

    if ( u2_nul == fin ) {
      j2_mcy(Pit, vane, dupt)(wir_r, van, "sut", sut);
      return u2_bl_bail(wir_r);
    } else {
      u2_noun pro = u2_rx(wir_r, u2_t(fin));

      u2_rl_lose(wir_r, fin);
      return pro;
    }
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, find)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, cog, van;

    if ( (u2_no == u2_mean(cor, 4, &cog, 5, &van, 0)) ||
         (u2_no == u2_stud(cog)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, find)(wir_r, van, sut, cog);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, find)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, find), SafeTier6, u2_none, u2_none },
    { }
  };
