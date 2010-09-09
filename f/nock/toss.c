/* l/nock/toss.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_zn_nock_toss():
**
**    Execute `(nock bus fol)`, losing `bus`, holding `fol`.
*/
u2_weak
u2_zn_nock_toss(u2_ray  wir_r,
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

      if ( (u2_none == (poz = u2_zn_nock_keep(wir_r, bus, hib))) ) {
        u2_zn_lose(wir_r, bus);
        return u2_none;
      }
      if ( (u2_none == (riv = u2_zn_nock_toss(wir_r, bus, gal)) ) ) {
        u2_zn_lose(wir_r, poz);
        return u2_none;
      }
      return u2_zn_cell(wir_r, poz, riv);
    } 
    else switch ( hib ) {
      default: {
        u2_zn_lose(wir_r, bus);
        return u2_none;
      }

      case 0: {
        if ( u2_no == u2_stud(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        }
        else {
          u2_weak dof = u2_frag(gal, bus);

          if ( u2_none == dof ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          else {
            u2_weak cul = u2_zn_ice(wir_r, dof);

            u2_zn_lose(wir_r, bus);
            return cul;
          }
        }
      }

      case 1: {
        u2_zn_lose(wir_r, bus);

        return u2_zn_ice(wir_r, gal);
      }

      case 2: {
        if ( u2_no == u2_dust(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_weak sep, dom;

          if ( u2_none == (dom = u2_zn_nock_keep(wir_r, bus, paz)) ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (sep = u2_zn_nock_toss(wir_r, bus, mis)) ) {
            u2_zn_lose(wir_r, dom);
            return u2_none;
          }

          if ( u2_no == u2_zn_senior(wir_r, dom) ) {
            u2_weak hoz = u2_zn_nock_toss(wir_r, sep, dom);

            u2_zn_lose(wir_r, dom);
            return hoz;
          }
          else {
            bus = sep;
            fol = dom;
            continue;
          }
        }
      }

      case 3: {
        u2_ray  bat_r = u2_zone_cap(wir_r);
        u2_weak gof, laz;

        if ( u2_no == u2_zn_leap(wir_r, c3__warm) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        }
        {
          gof = u2_zn_nock_keep(wir_r, bus, gal);
        }
        u2_zn_fall(wir_r);

        laz = (u2_none == gof) ? u2_none : u2_dust(gof);

        u2_zone_cap(wir_r) = bat_r;
        u2_zn_lose(wir_r, bus);

        return laz;
      }

      case 4: {
        u2_ray  bat_r = u2_zone_cap(wir_r);
        u2_weak gof, laz;

        if ( u2_no == u2_zn_leap(wir_r, c3__warm) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        }
        {
          gof = u2_zn_nock_keep(wir_r, bus, gal);
        }
        u2_zn_fall(wir_r);

        if ( u2_none == gof ) {
          laz = u2_none;
        } else {
          mpz_t mp_gof;

          u2_mp(mp_gof, gof);
          mpz_add_ui(mp_gof, mp_gof, 1);

          laz = u2_zn_mp(wir_r, mp_gof);
        }

        u2_zone_cap(wir_r) = bat_r;
        u2_zn_lose(wir_r, bus);

        return laz;
      }

      case 5: {
        if ( u2_no == u2_dust(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        }
        else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_weak dib, rum, laz;

          if ( u2_no == u2_zn_leap(wir_r, c3__warm) ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          {
            dib = u2_zn_nock_keep(wir_r, bus, u2_h(gal));
            rum = u2_zn_nock_keep(wir_r, bus, u2_t(gal));
          }
          u2_zn_fall(wir_r);

          if ( (u2_none == dib) || (u2_none == rum) ) {
            laz = u2_none;
          }
          else {
            laz = u2_sing(dib, rum);
          }

          u2_zone_cap(wir_r) = bat_r;
          u2_zn_lose(wir_r, bus);

          return laz;
        }
      }

      case 6: {
        u2_weak yor, fli, paw;

        if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none;
        } 
        else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_weak gyl;

          if ( u2_no == u2_zn_leap(wir_r, c3__warm) ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          {
            gyl = u2_zn_nock_keep(wir_r, bus, yor);
          }
          u2_zn_fall(wir_r);
          u2_zone_cap(wir_r) = bat_r;

          switch ( gyl ) {
            case 0: {
              fol = fli;
              continue;
            }
            case 1: {
              fol = paw;
              continue;
            }
            default: {
              u2_zn_lose(wir_r, bus);
              return u2_none;
            }
          }
        }
      }

      case 7: {
        if ( u2_no == u2_dust(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod;

          if ( u2_none == (bod = u2_zn_nock_toss(wir_r, bus, meg)) ) {
            return u2_none;
          }
          bus = bod;
          fol = fas;
          continue;
        }
      }

      case 8: {
        if ( u2_no == u2_dust(gal) ) {
          u2_zn_lose(wir_r, bus);
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod, har;

          if ( u2_none == (bod = u2_zn_nock_keep(wir_r, bus, meg)) ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (har = u2_zn_cell(wir_r, bod, bus)) ) {
            u2_zn_lose(wir_r, bod);
            u2_zn_lose(wir_r, bus);
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
          u2_noun sid = u2_h(gal);
          u2_noun hoy = u2_t(gal);
          u2_noun pec, vud, liz, mon, yaq, wod;

          if ( u2_none == (pec = u2_zn_nock_keep(wir_r, bus, sid)) ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (vud = u2_zn_nock_toss(wir_r, bus, hoy)) ) {
            u2_zn_lose(wir_r, pec);
            return u2_none;
          }

          liz = u2_t(u2_h(pec));
          mon = u2_t(pec);
          u2_zn_gain(wir_r, liz);
          u2_zn_gain(wir_r, mon);
          u2_zn_lose(wir_r, pec);

          if ( u2_none == (yaq = u2_zc(wir_r, vud, liz)) ) {
            u2_zn_lose(wir_r, vud);
            u2_zn_lose(wir_r, liz);
            u2_zn_lose(wir_r, mon);
            return u2_none;
          }
          if ( u2_none == (wod = u2_zc(wir_r, yaq, mon)) ) {
            u2_zn_lose(wir_r, yaq);
            u2_zn_lose(wir_r, mon);
            return u2_none;
          }

          if ( (u2_no == u2_zn_senior(wir_r, mon)) ) {
            u2_noun ruy;

            u2_zn_gain(wir_r, mon);
            ruy = u2_zn_nock_toss(wir_r, wod, mon);
            u2_zn_lose(wir_r, mon);
            
            return ruy;
          }
          else {
            bus = wod;
            fol = mon;
            continue;
          }
        }
      }

      case 10: {
        c3_assert(0);
      }

      case 11: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_zone_cap(wir_r);
          u2_noun yeq = u2_h(gal);
          u2_noun zom = u2_t(gal);
          u2_weak hig;

          if ( u2_no == u2_zn_leap(wir_r, c3__warm) ) {
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          {
            hig = u2_zn_nock_keep(wir_r, bus, yeq);
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
            u2_zn_lose(wir_r, bus);
            return u2_none;
          }
          u2_zn_lose(wir_r, bus);

          if ( u2_none == (han = u2_zn_ice(wir_r, u2_t(gal))) ) {
            u2_zn_lose(wir_r, cul);
            return u2_none;
          }

          if ( u2_none == (guc = u2_zn_cell(wir_r, cul, han)) ) {
            u2_zn_lose(wir_r, cul);
            u2_zn_lose(wir_r, han);
            return u2_none;
          }
          return guc;
        }
      }
    }
  }
}
