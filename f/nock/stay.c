/* l/nock/stay.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_zn_nock_stay():
**
**    Execute `(nock bus fol)` in the `%stay` memory style.
**
**    If `bop` is true, lose `bus` after computation.
*/
u2_weak
u2_zn_nock_stay(u2_ray  zon_r,
                c3_t    bop_t,
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
      else {
        if ( c3_true == bop_t ) {
          u2_zn_lose(zon_r, bus);
        }
        return u2_zn_cell(zon_r, poz, riv);
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
            else {
              if ( c3_true == bop_t ) {
                u2_zn_lose(zon_r, bus);
              }
              return u2_zn_ice(zon_r, dof);
            }
          }
        }
        case 1: {
          return u2_zn_ice(zon_r, gal);
        }
        case 2: {
          if ( (u2_no == u2_dust(gal)) || (u2_no == u2_dust(u2_h(gal))) ) {
            return u2_none;
          } else {
            u2_noun hud;

            u2_leap(zon_r, c3__slid);
            hud = u2_zn_nock_flee(zon_r, u2_zone_cap(zon_r), bus, gal);
            u2_fall(zon_r);

            if ( u2_zn_clear(hud, net_r, bat_r) ) {
              hud = u2_zn_tamp(zon_r, gan, net_r, bat_r);

              /* Tail-call optimization successful.
              */
              bus = u2_h(hud);
              fol = u2_t(gan);
              continue;
            }
            else {
              u2_noun doy;

              /* Tail-call optimization unsuccessful.
              */
              doy = u2_zon_nock_flee(zon_r, u2_zone_cap(zon_r), sep, dom);

              u2_zone_cap(zon_r) = net_r;
              return doy;
            }
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
            u2_noun hem = u2_h(gal);
            u2_noun vig = u2_t(gal);
            u2_noun bod;

            bod = u2_zn_nocs(zon_r, way_m, net_r, lav, bus, hem);

                  sub = bod; 
                  lav = bod;
                  fol = vig;
                  continue;
                }
            u2_
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
