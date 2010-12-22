/* j/6/fair.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_flag
  j2_mcy(Pit, vane, fair)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref,                            //  retain
                          u2_noun dab)                            //  retain
  {
    if ( u2_nul == dab ) {
      return u2_yes;
    }
    else {
      u2_noun n_dab, l_dab, r_dab; 
     
      u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
      if ( u2_no == u2_dust(n_dab) ) {
        return u2_bl_bail(wir_r);
      } 
      else {
        u2_noun qn_dab = u2_t(n_dab);
      
        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          return j2_mcy(Pit, vane, firm)(wir_r, van, sut, ref, qn_dab);
        }
        else if ( (u2_nul == l_dab) ) {
          return u2_and
            (j2_mcy(Pit, vane, firm)(wir_r, van, sut, ref, qn_dab),
             j2_mcy(Pit, vane, fair)(wir_r, van, sut, ref, r_dab));
        }
        else if ( (u2_nul == r_dab) ) {
          return u2_and
            (j2_mcy(Pit, vane, firm)(wir_r, van, sut, ref, qn_dab),
             j2_mcy(Pit, vane, fair)(wir_r, van, sut, ref, l_dab));
        }
        else {
          return u2_and
            (j2_mcy(Pit, vane, firm)(wir_r, van, sut, ref, qn_dab),
             u2_and(j2_mcy(Pit, vane, fair)(wir_r, van, sut, ref, l_dab),
                    j2_mcy(Pit, vane, fair)(wir_r, van, sut, ref, r_dab)));
        }
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, fair)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, van, ref, dab;

    if ( (u2_no == u2_mean(cor, 8, &ref, 9, &dab, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, fair)(wir_r, van, sut, ref, dab);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, fair)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, fair), u2_no, u2_none, u2_none },
    { }
  };
