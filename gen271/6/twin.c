/* j/6/twin.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, twin)(u2_wire wir_r, 
                    u2_noun hed,                                  //  retain
                    u2_noun tal)                                  //  retain
  {
    if ( (c3__blot == hed) || (c3__blot == tal) ) {
      return c3__blot;
    } else {
      return u2_bt(wir_r, c3__cell, hed, tal);
    }
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, twin)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun hed, tal;

    if ( u2_no == u2_mean(cor, 8, &hed, 9, &tal, 0) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, twin)(wir_r, hed, tal);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, twin)[] = {
    { ".3", c3__hevy, j2_mb(Pit, twin), SafeTier6_a, u2_none, u2_none },
    { }
  };
