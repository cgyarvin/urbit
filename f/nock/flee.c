/* l/nock/flee.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_zn_nock_here():
**
**    As `u2_zn_nock_flee()`, but without cap reduction.
*/
u2_weak
u2_zn_nock_here(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  return u2_zn_nock_flee(wir_r, u2_zone_cap(wir_r), bus, fol);
}

/* u2_zn_nock_flee():
**
**    Execute (nock bus fol) in the `flee` memory style.
**
**    After using `bus`, reduce `cap` to `net`.
*/
u2_weak
u2_zn_nock_flee(u2_ray  wir_r,
                u2_ray  net_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_noun hib, gal;

  while ( 1 ) {
    if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
      return u2_none;
    }

    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz, riv;

      if ( u2_none == (poz = u2_zn_nock_here(wir_r, bus, hib)) ) {
        return u2_none;
      }
      if ( u2_none == (riv = u2_zn_nock_flee(wir_r, net_r, bus, gal)) ) {
        return u2_none;
      }
      return u2_zn_cell(wir_r, poz, riv);
    }
    else switch ( hib ) {
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
            u2_noun hep = u2_zn_ice(wir_r, dof);

            u2_zone_cap(wir_r) = net_r;
            return hep;
          }
        }
      }

      case 1: {
        u2_zone_cap(wir_r) = net_r;

        return u2_zn_ice(wir_r, gal);
      }

      case 2: {
        if ( (u2_no == u2_dust(gal)) || (u2_no == u2_dust(u2_h(gal))) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_noun sep, dom;

          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (dom = u2_zn_nock_here(wir_r, bus, paz)) ) {
              return u2_none;
            }
            if ( u2_none == (sep = u2_zn_nock_here(wir_r, bus, mis)) ) {
              return u2_none;
            }
          }
          u2_zn_fall(wir_r);

          if ( (u2_no == u2_zn_senior(wir_r, dom)) ||
               (u2_no == u2_zn_clear(sep, net_r, bat_r)) ) 
          {
            /* Tail compaction will not succeed.
            */
            u2_noun doy;

            doy = u2_zn_nock_here(wir_r, sep, dom);

            u2_zone_cap(wir_r) = net_r;
            return doy;
          } 
          else {
            /* Tail compaction will succeed.
            */
            sep = u2_zn_tamp(wir_r, sep, net_r, bat_r);

            bus = sep;
            fol = dom;
            continue;
          }
        }
      }

      case 3: {
        u2_weak gof;

        if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
        {
          gof = u2_zn_nock_here(wir_r, bus, gal);
        }
        u2_zn_fall(wir_r);

        if ( u2_none == gof ) {
          return u2_none;
        }
        else {
          u2_zone_cap(wir_r) = net_r;

          return u2_dust(gof);
        }
      }

      case 4: {
        u2_weak gof;

        if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
        {
          gof = u2_zn_nock_here(wir_r, bus, gal);
        }
        u2_zn_fall(wir_r);

        if ( (u2_none == gof) || (u2_no == u2_stud(gof)) ) {
          return u2_none;
        }
        else {
          mpz_t mp_gof;

          u2_mp(mp_gof, gof); 
          mpz_add_ui(mp_gof, mp_gof, 1);

          u2_zone_cap(wir_r) = net_r;
          return u2_zn_mp(zon_r, mp_gof);
        }
      } 

      case 5: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        }
        else {
          u2_weak dib, rum, laz;

          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            dib = u2_zn_nock_here(wir_r, bus, u2_h(gal));
            rum = u2_zn_nock_here(wir_r, bus, u2_t(gal));
          }
          u2_zn_fall(wir_r);

          if ( (u2_none == dib) || (u2_none == rum) ) {
            return u2_none;
          }
          else {
            u2_zone_cap(wir_r) = net_r;
            return u2_sing(dib, rum);
          }
        }
      }

      case 6: {
        u2_weak yor, fli, paw;

        if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
          return u2_none;
        } 
        else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_weak gyl;
          
          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            gyl = u2_zn_nock_here(wir_r, bus, yor);
          }
          u2_zn_fall(wir_r);
          u2_zone_cap(wir_r) = bat_r;

          switch ( gyl ) {
            default: return u2_none;

            case u2_yes: {
              fol = fli;
              continue;
            }
            case u2_no: {
              fol = paw;
              continue;
            }
          }
        }
      }

      case 7: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none; 
        } else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod;

          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (bod = u2_zn_nock_here(wir_r, bus, meg)) ) {
              return u2_none;
            }
          }
          u2_zn_fall(wir_r);

          if ( (u2_no == u2_zn_clear(bod, net_r, bat_r)) ) 
          {
            /* Tail compaction will not succeed.
            */
            u2_noun doy;

            doy = u2_zn_nock_here(wir_r, bod, fas);

            u2_zone_cap(wir_r) = net_r;
            return doy;
          } 
          else {
            /* Tail compaction will succeed.
            */
            sep = u2_zn_tamp(wir_r, sep, net_r, bat_r);

            bus = sep;
            fol = fas;
            continue;
          }
        }
      }

      case 8: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none; 
        } else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod, har;

          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (bod = u2_zn_nock_here(wir_r, bus, meg)) ) {
              return u2_none;
            }
          }
          u2_zn_fall(wir_r);

          if ( u2_none == (har = u2_zn_cell(zon_r, bod, bus)) ) {
            return u2_none;
          }

          bus = har;
          fol = fas;
          continue;
        }
      }

      case 9: {
        if ( u2_no == u2_dust(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_noun sid = u2_h(gal);
          u2_noun hoy = u2_t(gal);
          u2_noun pec, vud, liz, mon, yaq, wod;

          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (pec = u2_zn_nock_here(wir_r, bus, sid)) ) {
              return u2_none;
            }
            if ( u2_none == (vud = u2_zn_nock_here(wir_r, bus, hoy)) ) {
              return u2_none;
            }

            liz = u2_t(u2_h(pec));
            mon = u2_t(pec);

            if ( u2_none == (yaq = u2_zn_cell(wir_r, vud, liz)) ) {
              return u2_none;
            }
            if ( u2_none == (wod = u2_zn_cell(wir_r, yaq, mon)) ) {
              return u2_none;
            }
          }
          u2_zn_fall(wir_r);

          if ( (u2_no == u2_zn_senior(wir_r, mon)) ||
               (u2_no == u2_zn_clear(wod, net_r, bat_r)) ) 
          {
            /* Tail compaction will not succeed.
            */
            u2_noun doy;

            doy = u2_zn_nock_here(wir_r, wod, mon);

            u2_zone_cap(wir_r) = net_r;
            return doy;
          } 
          else {
            /* Tail compaction will succeed.
            */
            wod = u2_zn_tamp(wir_r, wod, net_r, bat_r);

            bus = wod;
            fol = mon;
            continue;
          }
        }
      }

      case 10: {
        c3_assert(0); return 0;
      }

      case 11: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_noun yeq = u2_h(gal);
          u2_noun zom = u2_t(gal);
          u2_weak hig;

          if ( u2_no == u2_zn_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            hig = u2_zn_nock_here(wir_r, bus, yeq);
          }
          u2_zn_fall(wir_r);

          u2_zone_cap(wir_r) = bat_r;
          fol = zom;
          continue;
        }
      }

      case 12: {
        if ( u2_no == u2_dust(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_weak cul, han, guc;

          if ( u2_none == (cul = u2_zn_ice(wir_r, bus)) ) {
            return u2_none;
          }

          if ( u2_none == (han = u2_zn_ice(wir_r, u2_t(gal))) ) {
            return u2_none;
          }

          if ( u2_none == (guc = u2_zn_cell(wir_r, cul, han)) ) {
            return u2_none;
          }

          u2_zone_cap(wir_r) = net_r;
          return guc;
        }
      }
    }
  }
}
