/* j/list.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u2_fj_list_cat(): concatenate list.
*/
u2_list
u2_fj_list_cat(u2_ray  wir_r,
               u2_list lit,
               u2_list lus)
{
  if ( _0 == lit ) {
    return lus;
  } else return u2_bc(wir_r, u2_h(lit), u2_fj_list_cat(wir_r, u2_t(lit), lus));
}
