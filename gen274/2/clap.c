/* j/2/clap.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun
  j2_mbc(Pit, clap)(u2_wire wir_r, u2_noun a, u2_noun b, u2_noun c)
  {
    if ( _0 == _a ) {
      return u2_rl_gain(wir_r, b);
    } else if ( _0 == _b ) {
      return u2_rl_gain(wir_r, a);
    }
    else {
      return u2_bc
        (wir_r, _0, 
                u2_bn_mung_2
                  (wir_r, c, u2_rl_gain(wir_r, u2_bi_t(wir_r, a)),
                             u2_rl_gain(wir_r, u2_bi_t(wir_r, b))));
    }
  }
  u2_noun
  j2_mb(Pit, clap)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a, b, c;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &a, 18, &b, 19, &c, 0));
    {
      return j2_mbc(Pit, clap)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, clap)[] = {
    { ".3", j2_mb(Pit, clap), u2_yes, u2_none, u2_none },
    { }
  };
