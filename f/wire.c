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
  u2_rail_hat_r(wir_r) += (c3_wiseof(u2_loom_wire) - c3_wiseof(u2_loom_rail));

  u2_wire_bas_r(wir_r) = 0;
  u2_wire_wat_r(wir_r) = 0;
  u2_wire_plo_r(wir_r) = 0;
  u2_wire_jub_r(wir_r) = 0;

  /* Trace stacks.
  */
  {
    u2_wire_loc(wir_r) = u2_nul;
    u2_wire_tac(wir_r) = u2_nul;
    u2_wire_toc(wir_r) = u2_nul;
  }

#if 1
  /* Central memoization basket = 1/4 of address space.
  */
  {
    c3_w   tip_w = (c3_wiseof(u2_loom_bask) - c3_wiseof(u2_loom_rail));
    u2_ray bas_r;

    bas_r = u2_rl_leap_part(wir_r, c3__sand, 1, 4, tip_w);
    u2_wire_bas_r(wir_r) = bas_r;
    u2_ba_init(wir_r, 0);
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

  /* Special support.
  */
  {
    u2_wire_plo_r(wir_r) = u2_rl_ralloc(wir_r, c3_wiseof(u2_loom_plow));

    u2_pl_boot(wir_r);
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
