/* j/sub.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_zx_sub_c():
*/
u3_fox
u3_zx_sub_c(u3_z   z,
            u3_fox a,
            u3_fox b)
{
  mpz_t mp_a, mp_b;

  u3_lr_mp(z, mp_a, a);
  u3_lr_mp(z, mp_b, b);

  if ( mpz_cmp(mp_b, mp_a) < 0 ) {
    mpz_clear(mp_a);
    mpz_clear(mp_b);

    return u3_zc_tank(z, u3_cm_exit);
  }
  else {
    mpz_sub(mp_b, mp_b, mp_a); 
    mpz_clear(mp_a);

    return u3_zc_mp(z, mp_b);
  }
}

/* u3_zx_sub():
*/
u3_fox
u3_zx_sub(u3_z   z,
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
    return u3_zx_sub_c(z, a, b);
  }
}
