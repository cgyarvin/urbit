/* j/6/mesh.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, mesh)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_atom axe,                            //  retain
                          u2_noun mun,                            //  retain
                          u2_noun har)                            //  retain
  {
    u2_noun luf = u2_nul;

    mun = u2_rx(wir_r, mun);
    while ( 1 ) {
      if ( u2_nul == har ) {
        u2_noun pro = u2_bc(wir_r, mun, j2_mby(Pit, hike)(wir_r, axe, luf));

        u2_rl_lose(wir_r, luf);
        return pro;
      }
      else {
        u2_noun i_har = u2_h(har);
        u2_noun t_har = u2_t(har);

        if ( u2_no == u2_dust(i_har) ) {
          u2_noun pi_har = u2_h(i_har);
          u2_noun qi_har = u2_t(i_har);
          u2_noun rep = j2_mby(Pit, rake)(wir_r, pi_har);
          u2_noun cux = j2_mcy(Pit, vane, mill)(wir_r, van, sut, qi_har);
          u2_noun bop = j2_mcy(Pit, vane, make)(wir_r, van, mun, pi_har);
          u2_noun p_cux = u2_h(cux);
          u2_noun q_cux = u2_t(cux);
          u2_noun h_bop = u2_h(bop);
          u2_noun t_bop = u2_t(bop);

          if ( (_0 != h_bop) || (u2_no == u2_stud(t_bop)) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun hec = j2_mcy(Pit, vane, etch)(wir_r, van, mun, rep, p_cux);

            u2_rl_lose(wir_r, mun);
            mun = hec;

            luf = u2_bc(wir_r,
                        u2_bc(wir_r, u2_rx(wir_r, t_bop),
                                     u2_rx(wir_r, q_cux)),
                        luf);

            u2_rl_lose(wir_r, rep);
            u2_rl_lose(wir_r, cux);
            u2_rl_lose(wir_r, bop);
            har = t_har;
          }
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, mesh)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun van, sut, axe, mun, har;

    if ( (u2_no == u2_mean(cor, 8, &axe, 18, &mun, 19, &har,  5, &van, 0)) ||
         (u2_no == u2_stud(axe)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, mesh)(wir_r, van, sut, axe, mun, har);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, mesh)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, mesh), u2_no, u2_none, u2_none },
    { }
  };
