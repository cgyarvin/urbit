/* j/1/bex.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, bex)(u2_wire wir_r, u2_atom sam)
  {
    mpz_t sam_mp;

    if ( !u2_fly_is_cat(sam) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      mpz_init_set_ui(sam_mp, 1);
      mpz_mul_2exp(sam_mp, sam_mp, sam);

      return u2_bn_mp(wir_r, sam_mp);
    }
  }
  u2_noun
  j2_mb(Pit, bex)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun sam;

    sam = u2_bi_frag(wir_r, 4, cor);
    sam = u2_bl_flat(wir_r, sam);
    {
      return j2_mbc(Pit, bex)(wir_r, sam);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, bex)[] = { 
    { ".3", j2_mb(Pit, bex), u2_yes, u2_none, u2_none },
    { }
  };
