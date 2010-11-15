/* j/3/cat.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, cat)(u2_wire wir_r, u2_atom a, u2_atom b, u2_atom c)
  {
    if ( !u2_fly_is_cat(a) || (a >= 32) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      c3_g   a_g = a;
      c3_w   lew_w = u2_met(a_g, b);
      c3_w   ler_w = u2_met(a_g, c); 
      u2_ray sal_r = u2_bn_slaq(wir_r, a_g, (lew_w + ler_w));

      u2_chop(a_g, 0, lew_w, 0, sal_r, b);
      u2_chop(a_g, 0, ler_w, lew_w, sal_r, c);
    }
  }

  u2_noun
  j2_mb(Pit, cat)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a, b, c;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &a, 18, &b, 19, &c, 0));
    a = u2_bl_flat(wir_r, a);
    b = u2_bl_flat(wir_r, b);
    c = u2_bl_flat(wir_r, c);
    {
      return j2_mbc(Pit, cat)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, cat)[] = {
    { ".3", j2_mb(Pit, cat), u2_no, u2_na, u2_na },
    { }
  };
