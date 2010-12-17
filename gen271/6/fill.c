/* j/6/fill.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, fill)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun sem)                            //  retain
  {
    return j2_mcc(Pit, by, gas)(wir_r, u2_nul, sem);
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, fill)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, sem, van;

    if ( (u2_no == u2_mean(cor, 4, &sem, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, fill)(wir_r, van, sut, sem);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, fill)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, fill), u2_no, u2_none, u2_none },
    { }
  };
