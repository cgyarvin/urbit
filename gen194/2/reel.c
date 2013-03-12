/* j/2/reel.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pt2, reel)(u2_wire wir_r, 
                    u2_noun a,                                    //  retain
                    u2_noun b)                                    //  retain
  {
    if ( _0 == a ) {
      return u2_rx(wir_r, u2_frag(u2_cv_sam_3, b));
    }
    else if ( u2_no == u2_dust(a) ) {
      return u2_bl_bail(wir_r, c3__exit);
    }
    else {
      u2_weak gim = u2_rx(wir_r, u2_h(a));
      u2_weak hur = j2_mbc(Pt2, reel)(wir_r, u2_t(a), b);
      
      return u2_nk_mong(wir_r, b, u2_rc(wir_r, gim, hur));
    }
  }
  u2_noun                                                         // transfer
  j2_mb(Pt2, reel)(u2_wire wir_r, 
                   u2_noun cor)                                   // retain
  {
    u2_noun a, b;

    if ( u2_no == u2_mean(cor, u2_cv_sam_2, &a, u2_cv_sam_3, &b, 0) ) {
      return u2_bl_bail(wir_r, c3__exit);
    } else {
      return j2_mbc(Pt2, reel)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pt2, reel)[] = {
    { ".2", c3__lite, j2_mb(Pt2, reel), Tier2, u2_none, u2_none },
    { }
  };

