/* l/wire.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_wr_init():
**
**   Install an empty wire within `hat_r` and `mat_r` in the loom,
**   with memory model `hip`.
**
**   Returns ray to wire, which always equalls the passed `mat_r`.
*/
u2_ray
u2_wr_init(c3_m   hip_m,
           u2_ray hat_r,
           u2_ray mat_r)
{
  u2_ray wir_r;

  wir_r = u2_rl_init(hip_m, hat_r, mat_r);
  u2_rail_cap_r(wir_r) += (c3_wiseof(u2_loom_wire) - c3_wiseof(u2_loom_rail));

  u2_wire_sad_r(wir_r) = 0;
  u2_wire_bas_r(wir_r) = 0;
  u2_wire_wat_r(wir_r) = 0;
  u2_wire_jub_r(wir_r) = 0;

  return wir_r;
#if 0
  /* Jet shed = 1/32 of address space.
  */
  {
    c3_w gap_w = u2_ray_gap(u2_rail_cap_r(wir_r), u2_rail_hat_r(wir_r));
    c3_w siz_w = (gap_w / 32);
    {
      u2_ray sad_r = u2_sh_init(cap_r, siz_w, u2_rail_rut_r(wir_r));

      u2_rail_cap_r(wir_r) += siz_w;
      u2_wire_sad_r(wir_r) = sad_w;
    }
  }
 
  /* Central memoization basket = 1/16 of address space.
  */
  {
    c3_w gap_w = u2_ray_gap(u2_rail_cap_r(wir_r), u2_rail_hat_r(wir_r));
    c3_w siz_w = (gap_w / 8);
    {
      u2_ray bas_r = u2_ba_init(cap_r, siz_w, u2_rail_rut_r(wir_r));

      u2_rail_cap_r(wir_r) += siz_w;
      u2_wire_bas_r(wir_r) = bas_w;
    }
  }
#endif
}

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
  
  if ( u2_ray_a(u2_rail_cap_r(wir_r)) == 0 ) {
    if ( u2_rail_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wst_r) = u2_rail_cap_r(wir_r);
    }
    if ( u2_rail_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.est_r) = u2_rail_hat_r(wir_r);
    }
  } else {
    if ( u2_rail_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.est_r) = u2_rail_cap_r(wir_r);
    }
    if ( u2_rail_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wst_r) = u2_rail_hat_r(wir_r);
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

  if ( u2_ray_a(u2_rail_cap_r(wir_r)) == 0 ) {
    if ( u2_rail_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wab_r) = u2_rail_cap_r(wir_r);
    }
    if ( u2_rail_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.eab_r) = u2_rail_hat_r(wir_r);
    }
  } else {
    if ( u2_rail_cap_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.est_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.eab_r) = u2_rail_cap_r(wir_r);
    }
    if ( u2_rail_hat_r(wir_r) > *u2_at(wir_r, u2_loom_wire, d.wst_r) ) {
      *u2_at(wir_r, u2_loom_wire, d.wab_r) = u2_rail_hat_r(wir_r);
    }
  }
  *u2_at(wir_r, u2_loom_wire, d.wst_r) = *u2_at(wir_r, u2_loom_wire, d.wab_r);
  *u2_at(wir_r, u2_loom_wire, d.est_r) = *u2_at(wir_r, u2_loom_wire, d.eab_r);
}
#endif
