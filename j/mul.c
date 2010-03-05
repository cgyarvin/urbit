/* j/mul.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_zx_mul_c():
*/
u3_fox
u3_zx_mul_c(u3_z   z,
            u3_fox a,
            u3_fox b)
{
  mpz_t mp_a, mp_b;

  u3_lr_mp(z, mp_a, a);
  u3_lr_mp(z, mp_b, b);

  mpz_mul(mp_a, mp_a, mp_b); 
  mpz_clear(mp_b);

  return u3_zc_mp(z, mp_a);
}

/* u3_zx_mul():
*/
u3_fox
u3_zx_mul(u3_z   z,
          u3_fox cob)
{
  u3_fox a, b;

  if ( (u3_no == u3_lr_cell(z, cob, &a, &b)) ||
       (u3_no == u3_lr_pat(z, a)) ||
       (u3_no == u3_lr_pat(z, b)) )
  {
    return u3_zc_tank(z, u3_cm_punt);
  }
  else {
    return u3_zx_mul_c(z, a, b);
  }
}
