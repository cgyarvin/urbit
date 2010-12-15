/* j/6/cons.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, cons)(u2_wire wir_r, 
                    u2_noun vur,                                  //  retain
                    u2_noun sed)                                  //  retain
  {
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, cons)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun vur, sed;

    if ( u2_no == u2_mean(cor, 8, &vur, 9, &sed, 0) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, cons)(wir_r, vur, sed);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, cons)[] = {
    { ".3", c3__hevy, j2_mb(Pit, cons), u2_no, u2_none, u2_none },
    { }
  };
