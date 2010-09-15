/* l/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_wr_nock_keep(wir, bus, fol):
*/
u2_weak
u2_wr_nock_keep(u2_ray  wir_r,
                c3_w    stk_w,
                u2_noun bus,
                u2_noun fol)
{
  u2_zn_gain(wir_r, bus);

  return u2_wr_nock_toss(wir_r, stk_w, bus, fol);
}

/* u2_wr_nock_main(wir, bus, fol):
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
u2_wr_nock_main(u2_ray  wir_r,
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

      pro = u2_wr_nock_flee(wir_r, 0, cap_r, bus, fol);

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
      return u2_wr_nock_keep(wir_r, 0, bus, fol);
    }
  }
}

/* u2_wr_boot():
**
**  Create an empty zone in an empty loom, with memory model `hip`.
**  See u2_zn_leap() for storage policies.
*/
u2_ray
u2_wr_boot(c3_m hip_m)
{
  u2_ray wir_r = u2_ray_of(0, 0);
  u2_ray mat_r = u2_ray_of(0, c3_wiseof(u2_loom_wire));
  u2_ray cap_r = mat_r;
  u2_ray hat_r = u2_ray_of(1, 0);
  u2_ray rut_r = hat_r;
  u2_ray pot_r = mat_r;

  if ( hip_m == c3__warm ) {
    cap_r += c3_wiseof(u2_loom_zone_warm);
    u2_zone_warm_fre(pot_r) = 0;
  } 
  else if ( hip_m == c3__cold ) {
    cap_r += c3_wiseof(u2_loom_zone_pot);
  } 
  else c3_assert(0);

  u2_zone_pot_mat(pot_r) = 0;
  u2_zone_pot_rut(pot_r) = 0;

  u2_zone_cap(wir_r) = cap_r;
  u2_zone_hat(wir_r) = hat_r;
  u2_zone_mat(wir_r) = mat_r;
  u2_zone_rut(wir_r) = rut_r;

  u2_zone_hip(wir_r) = hip_m;
  u2_zone_cop(wir_r) = 0;

  /* Development.
  */
  {
    *u2_at(wir_r, u2_loom_wire, d.stk_w) = 0;
    *u2_at(wir_r, u2_loom_wire, d.wab_r) = cap_r;
    *u2_at(wir_r, u2_loom_wire, d.eab_r) = hat_r;
    *u2_at(wir_r, u2_loom_wire, d.wst_r) = cap_r;
    *u2_at(wir_r, u2_loom_wire, d.est_r) = hat_r;
  }

  return wir_r;
}

/* u2_wr_bench():
**
**  Save benchmarks with stack depth.
*/
void
u2_wr_bench(u2_ray wir_r,
            c3_w   stk_w)
{
  if ( stk_w > *u2_at(wir_r, u2_loom_wire, d.stk_w) ) {
    *u2_at(wir_r, u2_loom_wire, d.stk_w) = stk_w;
  }
  
  if ( u2_ray_a(u2_zone_cap(wir_r)) == 0 ) {
    if ( u2_zone_cap(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wst_r) = u2_zone_cap(wir_r);
    }
    if ( u2_zone_hat(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.est_r) = u2_zone_hat(wir_r);
    }
  } else {
    if ( u2_zone_cap(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.est_r) = u2_zone_cap(wir_r);
    }
    if ( u2_zone_hat(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wst_r) = u2_zone_hat(wir_r);
    }
  }
}

/* u2_wr_report():
**
**  Return handy reporting information.  Reset watermarks.
*/
void
u2_wr_report(u2_ray wir_r,
             c3_w*  stk_w,
             c3_w*  wst_w,
             c3_w*  est_w)
{
  *stk_w = *u2_at(wir_r, u2_loom_wire, d.stk_w);
  *wst_w = *u2_at(wir_r, u2_loom_wire, d.wst_r) -
           *u2_at(wir_r, u2_loom_wire, d.wab_r);
  *est_w = *u2_at(wir_r, u2_loom_wire, d.est_r) - 
           *u2_at(wir_r, u2_loom_wire, d.eab_r);

  *u2_at(wir_r, u2_loom_wire, d.stk_w) = 0;

  if ( u2_ray_a(u2_zone_cap(wir_r)) == 0 ) {
    if ( u2_zone_cap(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wab_r) = u2_zone_cap(wir_r);
    }
    if ( u2_zone_hat(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.eab_r) = u2_zone_hat(wir_r);
    }
  } else {
    if ( u2_zone_cap(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.eab_r) = u2_zone_cap(wir_r);
    }
    if ( u2_zone_hat(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wab_r) = u2_zone_hat(wir_r);
    }
  }
  *u2_at(wir_r, u2_loom_wire, d.wst_r) = *u2_at(wir_r, u2_loom_wire, d.wab_r);
  *u2_at(wir_r, u2_loom_wire, d.est_r) = *u2_at(wir_r, u2_loom_wire, d.eab_r);
}
