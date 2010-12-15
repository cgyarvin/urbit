/* j/6/eith.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, eith)(u2_wire wir_r, 
                    u2_noun hoz,                                  //  retain
                    u2_noun bur)                                  //  retain
  {
    if ( u2_yes == u2_sing(hoz, bur) ) {
      return hoz;
    }
    else if ( c3__blot == bur ) {
      return hoz;
    }
    else if ( c3__blot == hoz ) {
      return bur;
    }
    else return u2_bt(wir_r, c3__fork, hoz, bur);
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, eith)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun hoz, bur;

    if ( u2_no == u2_mean(cor, 8, &hoz, 9, &bur, 0) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, eith)(wir_r, hoz, bur);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, eith)[] = {
    { ".3", c3__hevy, j2_mb(Pit, eith), u2_no, u2_none, u2_none },
    { }
  };