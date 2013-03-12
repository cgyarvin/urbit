/* j/6/fork.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pt6, fork)(u2_wire wir_r, 
                    u2_noun hoz,                                  //  retain
                    u2_noun bur)                                  //  retain
  {
    if ( u2_yes == u2_sing(hoz, bur) ) {
      return u2_rx(wir_r, hoz);
    }
    else if ( c3__void == bur ) {
      return u2_rx(wir_r, hoz);
    }
    else if ( c3__void == hoz ) {
      return u2_rx(wir_r, bur);
    }
    else return u2_bt
      (wir_r, c3__fork, u2_rx(wir_r, hoz), u2_rx(wir_r, bur));
  }
  u2_noun                                                         //  transfer
  j2_mb(Pt6, fork)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun hoz, bur;

    if ( u2_no == u2_mean(cor, u2_cv_sam_2, &hoz, u2_cv_sam_3, &bur, 0) ) {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mby(Pt6, fork)(wir_r, hoz, bur);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pt6, fork)[] = {
    { ".2", c3__hevy, j2_mb(Pt6, fork), Tier6_a, u2_none, u2_none },
    { }
  };
