/* j/2/drop.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun
  j2_mbc(Pit, drop)(u2_wire wir_r, u2_noun a)
  {
    if ( _0 == a ) {
      return u2_nul;
    }
    else {
      return u2_bc(wir_r, u2_bi_t(a), u2_nul);
    }
  }
  u2_noun
  j2_mb(Pit, drop)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a, b;

    a = u2_bi_frag(wir_r, 4, cor);
    {
      return j2_mbc(Pit, drop)(wir_r, a);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, drop)[] = {
    { ".3", j2_mb(Pit, drop), u2_yes, u2_none, u2_none },
    { }
  };
