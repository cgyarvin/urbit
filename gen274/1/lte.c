/* j/1/lte.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, lte)(u2_wire wir_r, u2_atom a, u2_atom b)
  {
    mpz_t   a_mp, b_mp;
    u2_flag cmp;

    u2_mp(a_mp, a);
    u2_mp(b_mp, b);

    cmp = (mpz_cmp(a_mp, b_mp) <= 0) ? u3_yes : u3_no;

    mpz_clear(a_mp);
    mpz_clear(b_mp);

    return cmp;
  }
  u2_noun
  j2_mb(Pit, lte)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun a, b;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &a, 9, &b, 0));
    a = u2_bl_flat(wir_r, a);
    b = u2_bl_flat(wir_r, b);
    {
      return j2_mbc(Pit, lte)(wir_r, a, b);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, lte)[] = {
    { ".3", j2_mb(Pit, lte), u2_yes, u2_none, u2_none },
    { }
  };
