/* j/6/flan.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, flan)(u2_wire wir_r, 
                    u2_weak bos,                                  //  retain
                    u2_weak nif)                                  //  retain
  {
    return u2_none;
  }

  u2_weak                                                         //  transfer
  j2_mb(Pit, flan)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun bos, nif;

    if ( u2_no == u2_mean(cor, 8, &bos, 9, &nif, 0) ) {
      return u2_none;
    } else {
      return j2_mbc(Pit, flan)(wir_r, bos, nif);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, flan)[] = {
    { ".3", j2_mb(Pit, flan), u2_no, u2_none, u2_none },
    { }
  };
