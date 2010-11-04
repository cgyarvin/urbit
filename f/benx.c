/* l/benx.c
**
** This file is in the public domain.
*/
#include "all.h"
 
/* u2_bx_boot(): reset the performance log.
*/
void
u2_bx_boot(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, sap_d) = 0;
    u2_benx_be(bex_r, c3_d, cop_d) = 0;
    u2_benx_be(bex_r, c3_d, jax_d) = 0;
    u2_benx_be(bex_r, c3_d, use_d) = 0;

    u2_benx_be(bex_r, c3_w, wac_w) = 0;
    u2_benx_be(bex_r, c3_w, wax_w) = 0;

    u2_benx_be(bex_r, c3_ws, sew_ws) = 0;
    u2_benx_be(bex_r, c3_ws, bax_ws) = 0;
  
    if ( 0 == u2_ray_a(u2_rail_cap_r(wir_r)) ) {
      u2_benx_at(bex_r, wab_r) = u2_rail_cap_r(wir_r);
      u2_benx_at(bex_r, eab_r) = u2_rail_hat_r(wir_r);
    } else {
      u2_benx_at(bex_r, wab_r) = u2_rail_hat_r(wir_r);
      u2_benx_at(bex_r, eab_r) = u2_rail_cap_r(wir_r);
    }
    u2_benx_at(bex_r, wst_r) = u2_benx_at(bex_r, wab_r);
    u2_benx_at(bex_r, est_r) = u2_benx_at(bex_r, eab_r);

    if ( u2_wire_bas_r(wir_r) ) {
      u2_rail_bav_r(u2_wire_bas_r(wir_r)) = 
        u2_aftr(bex_r, u2_loom_benx, sew_ws);
    }
    if ( u2_wire_sad_r(wir_r) ) {
      u2_rail_bav_r(u2_wire_sad_r(wir_r)) = 
        u2_aftr(bex_r, u2_loom_benx, bax_ws);
    }
    {
      struct timeval tv;

      gettimeofday(&tv, 0);
      u2_benx_at(bex_r, sec_w) = tv.tv_sec;
      u2_benx_at(bex_r, usc_w) = tv.tv_usec;
    }
  }
}

/* u2_bx_post(): export and reset the performance log.
**
**  sap: number of steps
**  cop: number of words copied
**  jax: number of jet activations
**  use: number of user counts
**  wax: maximum depth of C stack
**  moc: number of words touched
**  hix: number of words acquired
**  sew: number of words in shed allocated/freed
**  bax: number of words in basket allocated/freed
**  ums: number of milliseconds consumed
*/
u2_flag
u2_bx_post(u2_ray wir_r,
           c3_d*  sap_d,
           c3_d*  cop_d,
           c3_d*  jax_d,
           c3_d*  use_d,
           c3_w*  wax_w,
           c3_w*  moc_w,
           c3_w*  hix_w,
           c3_ws* sew_ws,
           c3_ws* bax_ws,
           c3_w*  ums_w)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return u2_no;
  } else {
    u2_ray eab_r, wab_r;
    c3_w   sec_w, usc_w;

    *sap_d = u2_benx_be(bex_r, c3_d, sap_d);
    *cop_d = u2_benx_be(bex_r, c3_d, cop_d);
    *jax_d = u2_benx_be(bex_r, c3_d, jax_d);
    *use_d = u2_benx_be(bex_r, c3_d, use_d);

    *wax_w = u2_benx_at(bex_r, wax_w);

    *sew_ws = u2_benx_at(bex_r, sew_ws);
    *bax_ws = u2_benx_at(bex_r, bax_ws);

    *moc_w = (u2_benx_at(bex_r, wst_r) - u2_benx_at(bex_r, wab_r)) + 
             (u2_benx_at(bex_r, est_r) - u2_benx_at(bex_r, eab_r));

    wab_r = u2_benx_at(bex_r, wab_r);
    eab_r = u2_benx_at(bex_r, eab_r);
    sec_w = u2_benx_at(bex_r, sec_w);
    usc_w = u2_benx_at(bex_r, usc_w);
    u2_bx_boot(wir_r);

    /* Measure and return saved words.
    */
    {
      *hix_w = 0;
      if ( u2_benx_at(bex_r, wab_r) > wab_r ) {
        *hix_w += (u2_benx_at(bex_r, wab_r) - wab_r);
      }
      if ( u2_benx_at(bex_r, eab_r) > eab_r ) {
        *hix_w += (u2_benx_at(bex_r, wab_r) - wab_r);
      }
    }

    /* Measure and return time change.
    */
    {
      c3_d old_d, new_d;

      old_d = sec_w;
      old_d *= 1000000ULL;
      old_d += usc_w;

      new_d = u2_benx_at(bex_r, sec_w);
      new_d *= 1000000ULL;
      new_d += u2_benx_at(bex_r, usc_w);

      *ums_w = (c3_w) (((new_d - old_d) + 999ULL) / 1000ULL);
    }
    return u2_yes;
  }
}

/* u2_bx_step(): note interpreter step.
*/
void
u2_bx_step(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, sap_d) += (c3_d) 1;
  }
}

/* u2_bx_copy(): note `cop` copied words.
*/
void 
u2_bx_copy(u2_ray wir_r,
           c3_w   cop_w)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, cop_d) += (c3_d) cop_w;
  }
}

/* u2_bx_fall(): go deeper (call) in the C stack.
*/
void
u2_bx_fall(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_at(bex_r, wac_w) += 1;

    if ( u2_benx_at(bex_r, wac_w) > u2_benx_at(bex_r, wax_w) ) {
      u2_benx_at(bex_r, wax_w) = u2_benx_at(bex_r, wac_w);
    }
  }
}

/* u2_bx_rise(): go shallower (return) in the C stack.
*/
void 
u2_bx_rise(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_at(bex_r, wac_w) -= 1;
  }
}

/* u2_bx_used(): report a user count.
*/
void
u2_bx_used(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, use_d) += (c3_d) 1;
  }
}

/* u2_bx_flew(): report a jet activation.
*/
void
u2_bx_flew(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, jax_d) += (c3_d) 1;
  }
}

/* u2_bx_mark(): apply memory watermarks.
*/
void
u2_bx_mark(u2_ray wir_r)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    if ( u2_ray_a(u2_rail_cap_r(wir_r)) == 0 ) {
      if ( u2_rail_cap_r(wir_r) > u2_benx_at(bex_r, wst_r) ) {
        u2_benx_at(bex_r, wst_r) = u2_rail_cap_r(wir_r);
      }
      if ( u2_rail_hat_r(wir_r) > u2_benx_at(bex_r, est_r) ) {
        u2_benx_at(bex_r, est_r) = u2_rail_hat_r(wir_r);
      }
    } else {
      if ( u2_rail_cap_r(wir_r) > u2_benx_at(bex_r, est_r) ) {
        u2_benx_at(bex_r, est_r) = u2_rail_cap_r(wir_r);
      }
      if ( u2_rail_hat_r(wir_r) > u2_benx_at(bex_r, wst_r) ) {
        u2_benx_at(bex_r, wst_r) = u2_rail_hat_r(wir_r);
      }
    }
  }
}

/* u2_bx_shed(): note `wad` allocated/freed words in hangar.
*/
void
u2_bx_shed(u2_ray wir_r,
           c3_ws  wad_ws)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, sew_ws) += wad_ws;
  }
}

/* u2_bx_bask(): note `wad` allocated/freed words in basket.
*/
void
u2_bx_bask(u2_ray wir_r,
           c3_ws  wad_ws)
{
  u2_ray bex_r;

  if ( 0 == (bex_r = u2_wire_bex_r(wir_r)) ) {
    return;
  } else {
    u2_benx_be(bex_r, c3_d, bax_ws) += wad_ws;
  }
}
