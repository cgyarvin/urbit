/* j/1/dec.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, dec)(u2_wire wir_r, u2_atom sam)
  {
    if ( _0 == sam ) {
      return u2_bl_bail(wir_r);
    } else {
      mpz_t sam_mp;

      u2_mp(sam_mp, sam);
      mpz_sub_ui(sam_mp, sam_mp, 1);

      return u2_bn_mp(wir_r, sam_mp);
    }
  }
  u2_noun
  j2_mb(Pit, dec)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun sam;

    sam = u2_bi_frag(wir_r, 4, cor);
    sam = u2_bl_flat(wir_r, sam);
    {
      return j2_mbc(Pit, dec)(wir_r, sam);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, dec)[] = { 
    { ".3", j2_mb(Pit, dec), u2_yes, u2_none, u2_none },
    { }
  };
