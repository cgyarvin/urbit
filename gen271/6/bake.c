/* j/6/bake.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, bake)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun dab)                            //  retain
  {
    if ( (u2_nul == dab) ) {
      return _0;
    }
    else {
      u2_noun n_dab, l_dab, r_dab, qn_dab;

      u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
      qn_dab = u2_t(n_dab);
      
      if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
        return j2_mcy(Pit, vane, make)(wir_r, van, sut, qn_dab);
      }
      else if ( (u2_nul == l_dab) ) {
        return u2_bc
          (wir_r, j2_mcy(Pit, vane, make)(wir_r, van, sut, qn_dab),
                  j2_mcy(Pit, vane, bake)(wir_r, van, sut, r_dab));
      }
      else if ( (u2_nul == r_dab) ) {
        return u2_bc
          (wir_r, j2_mcy(Pit, vane, make)(wir_r, van, sut, qn_dab),
                  j2_mcy(Pit, vane, bake)(wir_r, van, sut, l_dab));
      }
      else {
        return u2_bt
          (wir_r, j2_mcy(Pit, vane, make)(wir_r, van, sut, qn_dab),
                  j2_mcy(Pit, vane, bake)(wir_r, van, sut, l_dab),
                  j2_mcy(Pit, vane, bake)(wir_r, van, sut, r_dab));
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, bake)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, dab, van;

    if ( (u2_no == u2_mean(cor, 4, &dab, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, bake)(wir_r, van, sut, dab);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, bake)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, bake), u2_no, u2_none, u2_none },
    { }
  };
