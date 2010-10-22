/* l/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_wr_nock_hint():
*/
u2_weak
u2_wr_nock_hint(u2_ray  wir_r,
                u2_noun zep,
                u2_noun hod,
                u2_noun bus,
                u2_noun fol)
{
  u2_weak nuc = u2_wr_hint(wir_r, zep, hod, bus, fol); 

  if ( u2_none != nuc )
    return nuc;
  else return u2_wr_nock_main(wir_r, bus, fol);
}

/* u2_wr_nock_jet():
**
**   Jet-propel `(nock bus fol)`, or return u2_none.
*/
u2_weak
u2_wr_nock_jet(u2_ray  wir_r,
               u2_noun bus,
               u2_noun fol)
{
  u2_noun xip = u2_sh_find(wir_r, bus);

  if ( u2_none == xip ) {
    return u2_none;
  } else {
    u2_noun pro;
    u2_flag saf;

    if ( u2_none == (pro = u2_ho_fire(wir_r, xip, bus, fol, &saf)) ) {
      return u2_none;
    }
    else {
      u2_bx_flew(wir_r);

      if ( u2_yes == saf ) {
        return pro;
        // return u2_none;
      } else {
        u2_noun vet;

        if ( u2_no == u2_rl_leap(wir_r, u2_rail_hip_m(wir_r)) ) {
          u2_rl_lose(wir_r, pro);

          return u2_none;
        }
        else if ( u2_none == (vet = u2_wr_nock_main(wir_r, bus, fol)) ) {
          u2_ho_dive(wir_r, xip);

          u2_rl_fall(wir_r);
          u2_rl_lose(wir_r, pro);

          return u2_none;
        }
        else {
          if ( u2_no == u2_sing(vet, pro) ) {
            u2_ho_dive(wir_r, xip);
          }
          u2_rl_fall(wir_r);
          return pro;
        }
      }
    }
  }
}

/* u2_wr_nock_keep()::
*/
u2_weak
u2_wr_nock_keep(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_rl_gain(wir_r, bus);

  return u2_wr_nock_toss(wir_r, bus, fol);
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
  switch ( u2_rail_hip_m(wir_r) ) {
    default: c3_assert(0); return u2_none;

    case c3__cold: {
      u2_ray  cap_r = u2_rail_cap_r(wir_r);
      u2_ray  hat_r = u2_rail_hat_r(wir_r);
      u2_ray  mat_r = u2_rail_mat_r(wir_r);
      u2_ray  rut_r = u2_rail_rut_r(wir_r);
      u2_noun pro;

      pro = u2_wr_nock_flee(wir_r, cap_r, bus, fol);

      if ( u2_none == pro ) {
        u2_rail_cap_r(wir_r) = cap_r;
        u2_rail_hat_r(wir_r) = hat_r;
        u2_rail_mat_r(wir_r) = mat_r;
        u2_rail_rut_r(wir_r) = rut_r;
        u2_rail_hip_m(wir_r) = c3__cold;
      }
      return pro;
    }

    case c3__warm: {
      return u2_wr_nock_keep(wir_r, bus, fol);
    }
  }
}

/* u2_wr_nock_mung(): call with gate and sample.
*/
u2_weak
u2_wr_nock_mung(u2_ray  wir_r,
                u2_noun gat,
                u2_noun sam)
{
  if ( u2_no == u2_dust(gat) ) {
    return u2_none;
  }
  else {
    u2_noun h_gat = u2_h(gat);
    u2_noun t_gat = u2_t(gat);

    if ( u2_no == u2_dust(h_gat) ) {
      return u2_none;
    } else {
      u2_noun pay = u2_rc(wir_r, sam, u2_t(h_gat));
      u2_noun pro;
      
      if ( u2_none == pay ) {
        return u2_none;
      } else {
        u2_noun cor = u2_rc(wir_r, pay, t_gat);

        if ( u2_none == cor ) {
          u2_rl_lose(wir_r, pay);
          return u2_none;
        }
        else {
          pro = u2_wr_nock_main(wir_r, cor, t_gat);

          u2_rl_lose(wir_r, pay);
          return pro;
        }
      }
    }
  }
}
