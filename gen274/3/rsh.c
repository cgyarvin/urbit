/* j/3/rsh.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, rsh)(u2_wire wir_r, u2_atom one, u2_atom two, u2_atom tri)
  {
    if ( _0 == two ) {
      return tri;
    }
    else if ( !u2_fly_is_cat(one) || (one >= 32) ) {
      return _0;
    }
    else if ( !u2_fly_is_cat(two) ) {
      return _0;
    }
    else {
      c3_g one_g = one;
      c3_w two_w = two;
      c3_w ler_w = u2_met(one_g, tri); 

      if ( ler_w <= two_w ) {
        return _0;
      } else {
        c3_w wid_w = (ler_w - two_w);
        u2_ray sal_r = u2_bn_slaq(wir_r, one_g, (ler_w - two_w));

        u2_chop(one_g, two, lew_w, 0, sal_r, two);
      u2_chop(one_g, 0, ler_w, lew_w, sal_r, tri);
    }
  }

  u2_noun
  j2_mb(Pit, rsh)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun one, two, tri;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &one, 18, &two, 19, &tri, 0));
    one = u2_bl_flat(wir_r, one);
    two = u2_bl_flat(wir_r, two);
    tri = u2_bl_flat(wir_r, tri);
    {
      return j2_mbc(Pit, rsh)(wir_r, one, two);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, rsh)[] = {
    { ".3", j2_mb(Pit, rsh), u2_no, u2_none, u2_none },
    { }
  };
