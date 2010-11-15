/* j/2/bind.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun
  j2_mbc(Pit, bind)(u2_wire wir_r, u2_noun a, u2_noun b)
  {
    if ( _0 == a ) {
      return _0;
    } 
    else {
      return u2_bc(wir_r, _0, u2_bn_mung(wir_r, b, u2_bi_t(wir_r, a)));
    }
  }
  u2_noun
  j2_mb(Pit, bind)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a, b;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &a, 9, &b, 0));
    {
      return j2_mbc(Pit, bind)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, bind)[] = {
    { ".3", j2_mb(Pit, bind), u2_no, u2_none, u2_none },
    { }
  };
