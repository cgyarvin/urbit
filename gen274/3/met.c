/* j/3/met.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, met)(u2_wire wir_r, u2_atom dis, u2_atom dat)
  {
    if ( !u2_fly_is_cat(dis) || (dis >= 32) ) {
      if ( _0 == dat ) {
        return _0;
      } else return _1;
    }
    else {
      c3_w met_w = u2_met(dis, dat);

      if ( !u2_fly_is_cat(met_w) ) {
        return u2_bn_words(wir_r, 1, &met_w);
      }
      else return u2_met(dis, dat);
    }
  }
  u2_noun
  j2_mb(Pit, met)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun dis, dat;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &dis, 9, &dat, 0));
    dis = u2_bl_flat(wir_r, dis);
    dat = u2_bl_flat(wir_r, dat);
    {
      return j2_mbc(Pit, met)(wir_r, dis, dat);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, met)[] = {
    { ".3", j2_mb(Pit, met), u2_yes, u2_none, u2_none },
    { }
  };
