/* l/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_wr_hint():
**
**   Hint directly in a modern style.  Returns `u2_none` if hint
**   processing fails.
*/
u2_weak
u2_wr_hint(u2_ray  wir_r,
           u2_noun zep,
           u2_noun hod,
           u2_noun bus,
           u2_noun fol)
{
  switch ( zep ) {
    default: return u2_none;

    case c3__memo: {
      u2_ray bas_r;

      if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
        return u2_none;
      } else {
        u2_weak pro = u2_ba_find(bas_r, bus, fol);

        if ( pro != u2_none ) {
          printf("found mug %x\n", u2_mug_cell(bus, fol));
          return pro;
        } else {
          printf("not found mug %x\n", u2_mug_cell(bus, fol));

          if ( u2_none != (pro = u2_wr_nock_main(wir_r, bus, fol)) ) {
            printf("saved mug %x\n", u2_mug_cell(bus, fol));
            u2_ba_save(bas_r, bus, fol, pro);
          }
          return pro;
        }
      }
    }
  }
}

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
  u2_ray sad_r;

  if ( !(sad_r = u2_wire_sad_r(wir_r)) || (u2_no == u2_dust(bus)) ) {
    return u2_none;
  }
  else {
    u2_noun pay = u2_h(bus);
    u2_noun bat = u2_t(bus);
    u2_noun dac = u2_none; // u2_sh_find(sad_r, pay, bat);

    if ( u2_none == dac ) {
      return u2_none;
    } else {
      u2_noun pro;
      c3_t    ver_t = c3_false;

      if ( u2_none == (pro = u2_ho_fire(wir_r, dac, bus, fol, &ver_t)) ) {
        return u2_none;
      }
      else {
        if ( c3_false == ver_t ) {
          return pro;
        } else {
          u2_noun vet;

          if ( u2_no == u2_rl_leap(wir_r, u2_rail_hip_m(wir_r)) ) {
            u2_rl_lose(wir_r, pro);

            return u2_none;
          }
          else if ( u2_none == (vet = u2_wr_nock_main(wir_r, bus, fol)) ) {
            u2_ho_dive(wir_r, dac);

            u2_rl_fall(wir_r);
            u2_rl_lose(wir_r, pro);

            return u2_none;
          }
          else {
            if ( u2_no == u2_sing(vet, pro) ) {
              u2_ho_dive(wir_r, dac);
            }
            u2_rl_fall(wir_r);
            return pro;
          }
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
