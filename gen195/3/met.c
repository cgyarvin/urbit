/* j/3/met.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pt3, met)(u2_wire wir_r, 
                   u2_atom a,                                     //  retain
                   u2_atom b)                                     //  retain
  {
    if ( !u2_fly_is_cat(a) || (a >= 32) ) {
      if ( _0 == b ) {
        return _0;
      } else return _1;
    }
    else {
      c3_w met_w = u2_met(a, b);

      if ( !u2_fly_is_cat(met_w) ) {
        return u2_rl_words(wir_r, 1, &met_w);
      }
      else return u2_met(a, b);
    }
  }
  u2_weak                                                         //  transfer
  j2_mb(Pt3, met)(u2_wire wir_r, 
                  u2_noun cor)                                    //  retain
  {
    u2_noun a, b;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &a, u2_cv_sam_3, &b, 0)) ||
         (u2_no == u2_stud(a)) ||
         (u2_no == u2_stud(b)) )
    {
      return u2_bl_bail(wir_r, c3__exit);
    } else {
      return j2_mbc(Pt3, met)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pt3, met)[] = {
    { ".2", c3__lite, j2_mb(Pt3, met), Tier3, u2_none, u2_none },
    { }
  };
