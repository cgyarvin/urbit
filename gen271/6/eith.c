/* j/6/eith.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, eith)(u2_wire wir_r, 
                    u2_weak hoz,                                  //  retain
                    u2_weak bur)                                  //  retain
  {
    return u2_none;
  }
  u2_weak                                                         //  transfer
  j2_mb(Pit, eith)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun hoz, bur;

    if ( u2_no == u2_mean(cor, 8, &hoz, 9, &bur, 0) ) {
      return u2_none;
    } else {
      return j2_mbc(Pit, eith)(wir_r, hoz, bur);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, eith)[] = {
    { ".3", j2_mb(Pit, eith), u2_no, u2_none, u2_none },
    { }
  };
