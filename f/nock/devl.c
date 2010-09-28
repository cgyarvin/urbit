/* l/devl.c
**
** This file is in the public domain.
*/

#if 0
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
  
  if ( u2_ray_a(u2_zone_cap_r(wir_r)) == 0 ) {
    if ( u2_zone_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wst_r) = u2_zone_cap_r(wir_r);
    }
    if ( u2_zone_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.est_r) = u2_zone_hat_r(wir_r);
    }
  } else {
    if ( u2_zone_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.est_r) = u2_zone_cap_r(wir_r);
    }
    if ( u2_zone_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wst_r) = u2_zone_hat_r(wir_r);
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

  if ( u2_ray_a(u2_zone_cap_r(wir_r)) == 0 ) {
    if ( u2_zone_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wab_r) = u2_zone_cap_r(wir_r);
    }
    if ( u2_zone_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.eab_r) = u2_zone_hat_r(wir_r);
    }
  } else {
    if ( u2_zone_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.eab_r) = u2_zone_cap_r(wir_r);
    }
    if ( u2_zone_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wab_r) = u2_zone_hat_r(wir_r);
    }
  }
  *u2_at(wir_r, u2_loom_wire, d.wst_r) = *u2_at(wir_r, u2_loom_wire, d.wab_r);
  *u2_at(wir_r, u2_loom_wire, d.est_r) = *u2_at(wir_r, u2_loom_wire, d.eab_r);
}
#endif
