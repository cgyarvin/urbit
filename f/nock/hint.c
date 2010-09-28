/* l/nock/hint.c
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

      if ( !(bas_r = u2_wire_bas_r(wir_r) ) ) {
        return u2_none;
      }
      else {
        u2_noun pro;

        if ( u2_none != (pro = u2_ba_find(bas_r, bus, fol)) ) {
          return pro;
        }
        else {
          if ( u2_none == (pro = u2_wr_nock_main(wir_r, bus, fol)) ) {
            return u2_none;
          } else {
            u2_ba_save(bas_r, bus, fol, pro);
            return pro;
          }
        }
      }
    }
    case c3__mine: {
      u2_ray sad_r;

      if ( !(sad_r = u2_wire_sad_r(wir_r)) ) {
        return u2_none;
      }
      else {
        u2_noun cor = u2_wr_nock_main(wir_r, bus, fol);

        if ( u2_yes == u2_dust(cor) ) {
          u2_noun pay = u2_ch(cor);
          u2_noun bat = u2_ct(cor);
          u2_noun bot;

          bot = u2_sh_save(sad_r, hod, pay, bat);
          if ( bot != bat ) {
            cor = u2_rl_cell(wir_r, pay, bot);
          }
        }
        return cor;
      }
    }
  }
}
