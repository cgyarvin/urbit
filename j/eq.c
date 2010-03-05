/* j/eq.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_zx_eq():
*/
u3_fox
u3_zx_eq(u3_z   z,
         u3_fox cob)
{
  u3_fox a, b;

  if ( (u3_no == u3_lr_cell(z, cob, &a, &b)) ) {
    return u3_zc_tank(z, u3_cm_exit);
  }
  else return u3_lr_eq(z, a, b);
}

