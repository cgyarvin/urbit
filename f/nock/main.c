/* l/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_zn_nock_keep(wir, bus, fol):
*/
u2_weak
u2_zn_nock_keep(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_zn_gain(wir_r, bus);

  return u2_zn_nock_toss(wir_r, bus, fol);
}

/* u2_zn_nock_main(wir, bus, fol):
**
**  wir:  wire
**  bus:  subject
**  fol:  formula
**
**    Execute `(nock bus fol)`, allocating on `hat`.
**
**    If computation fails for any reason, return `u2_none`.
**    Failure must leave the loom undamaged.
*/
u2_weak
u2_zn_nock_main(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  switch ( u2_zone_hip(wir_r) ) {
    default: c3_assert(0); return u2_none;

    case c3__cold: {
      u2_ray  cap_r = u2_zone_cap(wir_r);
      u2_ray  hat_r = u2_zone_hat(wir_r);
      u2_ray  mat_r = u2_zone_mat(wir_r);
      u2_ray  rut_r = u2_zone_rut(wir_r);
      u2_noun pro;

      pro = u2_zn_nock_flee(wir_r, cap_r, bus, fol);

      if ( u2_none == pro ) {
        u2_zone_cap(wir_r) = cap_r;
        u2_zone_hat(wir_r) = hat_r;
        u2_zone_mat(wir_r) = mat_r;
        u2_zone_rut(wir_r) = rut_r;
        u2_zone_hip(wir_r) = c3__cold;
      }
      return pro;
    }

    case c3__warm: {
      return u2_zn_nock_keep(wir_r, bus, fol);
    }
  }
}
