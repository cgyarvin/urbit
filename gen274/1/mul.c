/* j/1/mul.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, mul)(u2_wire wir_r, u2_atom a, u2_atom b)
  {
    mpz_t a_mp, b_mp;

    u2_mp(a_mp, a);
    u2_mp(b_mp, b);

    mpz_mul(a_mp, a_mp, b_mp);
    mpz_clear(b_mp);

    return u2_bn_mp(wir_r, a_mp);
  }
  u2_noun
  j2_mb(Pit, mul)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a, b;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &a, 9, &b, 0));
    a = u2_bl_flat(wir_r, a);
    b = u2_bl_flat(wir_r, b);
    {
      return j2_mbc(Pit, mul)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, mul)[] = {
    { ".3", j2_mb(Pit, mul), u2_yes, u2_none, u2_none },
    { }
  };

