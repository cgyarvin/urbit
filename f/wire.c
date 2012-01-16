/* f/wire.c
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
  u2_rail_hat_r(wir_r) += (c3_wiseof(u2_loom_wire) - c3_wiseof(u2_loom_rail));

#if 1
  u2_wire_bas_r(wir_r) = 0;
#endif

  u2_wire_kit_r(wir_r) = 0;

  u2_cs_init(u2_wire_des_r(wir_r));

  /* Trace stack.
  */
  {
    u2_wire_tax(wir_r) = u2_nul;
  }

#if 1
  /* Permanent basket = 1/16 of address space.
  */
  {
    u2_ray bas_r;

    bas_r = u2_rl_leap_part(wir_r, c3__sand, 1, 16, 0);
    u2_wire_bas_r(wir_r) = bas_r;
    // u2_ba_init(wir_r, 0);
  }
#endif

#if 1
  /* Host control.
  */
  {
    u2_ho_push();
  }
#endif

  /* Basic performance tracking.
  */
  {
    u2_wire_bex_r(wir_r) = u2_rl_ralloc(wir_r, c3_wiseof(u2_loom_benx));

    u2_bx_boot(wir_r);
  }

  /* New performance tracking.
  */
  {
    u2_wire_rac_r(wir_r) = 
    u2_tx_init(wir_r);
  }

  return wir_r;
}


/* u2_wr_ice(): u2_rl_ice(), with u2_bx_copy().
*/
u2_weak
u2_wr_ice(u2_ray  wir_r,
          u2_noun fiz)
{
  u2_ray  hat_r = u2_rail_hat_r(wir_r);
  u2_noun buz;
  c3_w    cop_w;

  buz = u2_rl_ice(wir_r, fiz);

  cop_w = u2_rail_hat_r(wir_r) - hat_r;
  if ( cop_w ) {
    u2_bx_copy(wir_r, cop_w);
  }
  return buz;
}

/* u2_wr_mark():
**
**   Mark all roots in a wire and return their allocation size.
*/
c3_w
u2_wr_mark(u2_ray wir_r)
{
  c3_w siz_w = 0;

  c3_assert(c3__rock == u2_rail_hip_m(wir_r));
  {
    if ( u2_wire_kit_r(wir_r) ) {
      siz_w += u2_rl_gc_mark_ptr(wir_r, u2_wire_kit_r(wir_r));
    }
    siz_w += u2_rl_gc_mark_ptr(wir_r, u2_wire_bex_r(wir_r));
    siz_w += u2_rl_gc_mark_ptr(wir_r, u2_wire_rac_r(wir_r));
  }
  siz_w += u2_rl_gc_mark(wir_r);

  return siz_w;
}
