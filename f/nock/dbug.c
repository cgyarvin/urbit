/* l/nock_lame.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_zn_nock_lame():
**
**    Execute (nock_lame bus fol) with a trivial interpreter.
*/
u2_weak
u2_zn_nock_lame(u2_ray  zon_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_noun hib, gal;

  if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
    return u2_none;
  }
  else {
    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz = u2_zn_nock_lame(zon_r, bus, hib);
      u2_weak riv = u2_zn_nock_lame(zon_r, bus, gal);

      if ( (u2_none == poz) || (u2_none == riv) ) {
        return u2_none;
      }
      else return u2_zn_cell(zon_r, poz, riv);
    }
    else {
      switch ( hib ) {
        default: return u2_none;

        case 0: {
          if ( u2_no == u2_stud(gal) ) {
            return u2_none;
          }
          else {
            u2_weak dof = u2_frag(gal, bus);

            if ( u2_none == dof ) {
              return u2_none;
            }
            else return u2_zn_ice(zon_r, dof);
          }
        }
        case 1: {
          return u2_zn_ice(zon_r, gal);
        }
        case 2: {
          u2_weak gof = u2_zn_nock_lame(zon_r, bus, gal);

          if ( (u2_none == gof) || (u2_no == u2_dust(gof)) ) {
            return u2_none;
          }
          else {
            return u2_zn_nock_lame(zon_r, u2_h(gof), u2_t(gof));
          }
        }
        case 3: {
          u2_weak gof = u2_zn_nock_lame(zon_r, bus, gal);

          if ( u2_none == gof ) {
            return u2_none;
          }
          else return u2_dust(gof);
        }
        case 4: {
          u2_weak gof = u2_zn_nock_lame(zon_r, bus, gal);

          if ( (u2_none == gof) || (u2_no == u2_stud(gof)) ) {
            return u2_none;
          }
          else {
            mpz_t mp_gof;

            u2_mp(mp_gof, gof); 
            mpz_add_ui(mp_gof, mp_gof, 1);

            return u2_zn_mp(zon_r, mp_gof);
          }
        } 
        case 5: {
          u2_weak gof = u2_zn_nock_lame(zon_r, bus, gal);

          if ( (u2_none == gof) || (u2_no == u2_dust(gof)) ) {
            return u2_none;
          }
          else {
            return u2_sing(u2_h(gof), u2_t(gof));
          }
        }
        case 6: {
          u2_weak yor, fli, paw;

          if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
            return u2_none;
          } 
          else {
            u2_weak gyl = u2_zn_nock_lame(zon_r, bus, yor);

            switch ( gyl ) {
              case 0 : return u2_zn_nock_lame(zon_r, bus, fli);
              case 1 : return u2_zn_nock_lame(zon_r, bus, paw);
              default: return u2_none;
            }
          }
        }
        case 7: {
          if ( u2_no == u2_dust(gal) ) {
            return u2_none;
          } else {
            u2_weak bud = u2_zn_nock_lame(zon_r, bus, u2_h(gal));
     
            if ( u2_none == bud ) {
              return u2_none;
            } else {
              return u2_zn_nock_lame(zon_r, bud, u2_t(gal));
            }
          }
        }
        case 8: {
          if ( u2_no == u2_dust(gal) ) {
            return u2_none;
          } else {
            u2_weak bud = u2_zn_nock_lame(zon_r, bus, u2_h(gal));
     
            if ( u2_none == bud ) {
              return u2_none;
            } else {
              return u2_zn_nock_lame
                (zon_r, u2_zn_cell(zon_r, bud, bus), u2_t(gal));
            }
          }
        }
        case 11: {
          if ( u2_no == u2_dust(gal) ) {
            return u2_none;
          } else {
            return u2_zn_nock_lame(zon_r, bus, u2_t(gal));
          }
        }
        case 12: {
          if ( u2_no == u2_dust(gal) ) {
            return u2_none;
          } else {
            return u2_zn_cell(zon_r, bus, u2_t(gal));
          }
        }
      }
    }
  }
}
