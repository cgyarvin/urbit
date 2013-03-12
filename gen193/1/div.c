/* j/1/div.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pt1, div)(u2_wire wir_r, 
                   u2_atom a,                                     //  retain
                   u2_atom b)                                     //  retain
  {
    if ( _0 == b ) {
      return u2_bl_bail(wir_r, c3__exit);
    } 
    else {
      mpz_t a_mp, b_mp;

      u2_mp(a_mp, a);
      u2_mp(b_mp, b);

      mpz_tdiv_q(a_mp, a_mp, b_mp);
      mpz_clear(b_mp);

      return u2_rl_mp(wir_r, a_mp);
    }
  }
  u2_weak                                                         //  transfer
  j2_mb(Pt1, div)(u2_wire wir_r, 
                  u2_noun cor)                                    //  retain
  {
    u2_noun a, b;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &a, u2_cv_sam_3, &b, 0)) ||
         (u2_no == u2_stud(a)) ||
         (u2_no == u2_stud(b)) )
    {
      return u2_bl_bail(wir_r, c3__exit);
    } else {
      return j2_mbc(Pt1, div)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pt1, div)[] = {
    { ".2", c3__lite, j2_mb(Pt1, div), u2_jet_live, u2_none, u2_none },
    { }
  };
