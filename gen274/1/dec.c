/* j/1/dec.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, dec)(u2_wire wir_r, u2_atom a)
  {
    if ( _0 == a ) {
      return u2_bl_bail(wir_r);
    } else {
      mpz_t a_mp;

      u2_mp(a_mp, a);
      mpz_sub_ui(a_mp, a_mp, 1);

      return u2_bn_mp(wir_r, a_mp);
    }
  }
  u2_noun
  j2_mb(Pit, dec)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a;

    a = u2_bi_frag(wir_r, 4, cor);
    a = u2_bl_flat(wir_r, a);
    {
      return j2_mbc(Pit, dec)(wir_r, a);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, dec)[] = { 
    { ".3", j2_mb(Pit, dec), u2_yes, u2_none, u2_none },
    { }
  };
