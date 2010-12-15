/* j/6/mill.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, mill)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun vun, pro;

    vun = u2_bn_molt(wir_r, van, 4, sut, 0);
    pro = u2_bn_gart(wir_r, van, "mill", gen);

    u2_rl_lose(wir_r, vun);
    return pro;
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, mill)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
#if 1
    return u2_bl_bail(wir_r);
#else
    u2_noun sut, gen, van;

    if ( (u2_no == u2_mean(cor, 4, &gen, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcc(Pit, vane, mill)(wir_r, van, sut, gen);
    }
#endif
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, mill)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, mill), u2_no, u2_none, u2_none },
    { }
  };
