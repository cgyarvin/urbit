/* l/nock/toss.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* _toss(): substance of u2_wr_nock_toss().
**
**    Execute `(nock bus fol)`, losing `bus`, holding `fol`.
*/
static u2_weak
_toss(u2_ray  wir_r,
           u2_noun bus,
           u2_noun fol)
{
  u2_noun hib, gal;

  while ( 1 ) {
    u2_bx_step(wir_r);
    u2_bx_mark(wir_r);

    /* Attempt jet propulsion.
    */
    {
      u2_noun pro;

      if ( u2_none != (pro = u2_wr_nock_jet(wir_r, bus, fol)) ) {
        u2_rl_lose(wir_r, bus);

        return pro;
      }
    }

    if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
      return u2_none;
    }
    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz, riv, hux;

      if ( (u2_none == (poz = u2_wr_nock_keep(wir_r, bus, hib))) ) {
        u2_rl_lose(wir_r, bus);
        return u2_none;
      }
      if ( (u2_none == (riv = u2_wr_nock_toss(wir_r, bus, gal)) ) ) {
        u2_rl_lose(wir_r, poz);
        return u2_none;
      }
      hux = u2_rl_cell(wir_r, poz, riv);
      return hux;
    } 
    else switch ( hib ) {
      default: {
        u2_rl_lose(wir_r, bus);
        return u2_none;
      }
    /* frag
    */
      case u2_nock_frag: {
        if ( u2_no == u2_stud(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        }
        else {
          u2_weak dof = u2_frag(gal, bus);

          if ( u2_none == dof ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          else {
            u2_weak cul;
            
            cul = u2_wr_ice(wir_r, dof);

            u2_rl_lose(wir_r, bus);
            return cul;
          }
        }
      }
    /* bone
    */
      case u2_nock_bone: {
        u2_noun sug;

        u2_rl_lose(wir_r, bus);

        sug = u2_wr_ice(wir_r, gal);
        return sug;
      }
    /* sail
    */
      case u2_nock_sail: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_weak sep, dom;

          if ( u2_none == (dom = u2_wr_nock_keep(wir_r, bus, paz)) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (sep = u2_wr_nock_toss(wir_r, bus, mis)) ) {
            u2_rl_lose(wir_r, dom);
            return u2_none;
          }
          if ( u2_no == u2_rl_senior(wir_r, dom) ) {
            u2_weak hoz = u2_wr_nock_toss(wir_r, sep, dom);

            u2_rl_lose(wir_r, dom);
            return hoz;
          }
          else {
            bus = sep;
            fol = dom;
            continue;
          }
        }
      }
    /* dust
    */
      case u2_nock_dust: {
        u2_ray  bat_r = u2_rail_cap_r(wir_r);
        u2_weak gof, laz;

        if ( u2_no == u2_rl_leap(wir_r, c3__warm) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        }
        {
          gof = u2_wr_nock_keep(wir_r, bus, gal);
        }
        u2_rl_fall(wir_r);

        laz = (u2_none == gof) ? u2_none : u2_dust(gof);

        u2_rail_cap_r(wir_r) = bat_r;
        u2_rl_lose(wir_r, bus);

        return laz;
      }
    /* vint
    */
      case u2_nock_vint: {
        u2_ray  bat_r = u2_rail_cap_r(wir_r);
        u2_weak gof, laz;

        if ( u2_no == u2_rl_leap(wir_r, c3__warm) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        }
        {
          gof = u2_wr_nock_keep(wir_r, bus, gal);
        }
        u2_rl_fall(wir_r);

        if ( u2_none == gof ) {
          laz = u2_none;
        } else {
          mpz_t mp_gof;

          u2_mp(mp_gof, gof);
          mpz_add_ui(mp_gof, mp_gof, 1);

          laz = u2_rl_mp(wir_r, mp_gof);
        }

        u2_rail_cap_r(wir_r) = bat_r;
        u2_rl_lose(wir_r, bus);

        return laz;
      }
    /* sing
    */
      case u2_nock_sing: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        }
        else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_weak dib, rum, laz;

          if ( u2_no == u2_rl_leap(wir_r, c3__warm) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          {
            dib = u2_wr_nock_keep(wir_r, bus, u2_h(gal));
            rum = u2_wr_nock_keep(wir_r, bus, u2_t(gal));
          }
          u2_rl_fall(wir_r);

          if ( (u2_none == dib) || (u2_none == rum) ) {
            laz = u2_none;
          }
          else {
            laz = u2_sing(dib, rum);
          }

          u2_rail_cap_r(wir_r) = bat_r;
          u2_rl_lose(wir_r, bus);

          return laz;
        }
      }
    /* trol
    */
      case u2_nock_trol: {
        u2_weak yor, fli, paw;

        if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        } 
        else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_weak gyl;

          if ( u2_no == u2_rl_leap(wir_r, c3__warm) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          {
            gyl = u2_wr_nock_keep(wir_r, bus, yor);
          }
          u2_rl_fall(wir_r);
          u2_rail_cap_r(wir_r) = bat_r;

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
              u2_rl_lose(wir_r, bus);
              return u2_none;
            }
          }
        }
      }
    /* flac
    */
      case u2_nock_flac: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod;

          if ( u2_none == (bod = u2_wr_nock_toss(wir_r, bus, meg)) ) {
            return u2_none;
          }
          bus = bod;
          fol = fas;
          continue;
        }
      }
    /* gant
    */
      case u2_nock_gant: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod, har;

          if ( u2_none == (bod = u2_wr_nock_keep(wir_r, bus, meg)) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (har = u2_rl_cell(wir_r, bod, bus)) ) {
            u2_rl_lose(wir_r, bod);
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          bus = har;
          fol = fas;
          continue;
        }
      }
    /* mung
    */
      case u2_nock_mung: {
#if 1
        c3_assert(0); return 0;
#else
#endif
      }
    /* germ
    */
      case u2_nock_germ: {
        c3_assert(0);
      }
    /* hint
    */
      case u2_nock_hint: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_noun yeq = u2_h(gal);
          u2_noun zom = u2_t(gal);
          u2_weak hig, lut;

          if ( u2_no == u2_rl_leap(wir_r, c3__warm) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          {
            hig = u2_wr_nock_keep(wir_r, bus, yeq);
          }
          u2_rl_fall(wir_r);

          lut = u2_wr_nock_hint(wir_r, hig, bus, zom);

          u2_rail_cap_r(wir_r) = bat_r;
          return lut;
        }
      }
    /* coat
    */
      case u2_nock_coat: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_weak cul, han, guc;

          if ( u2_none == (cul = u2_wr_ice(wir_r, bus)) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          u2_rl_lose(wir_r, bus);

          if ( u2_none == (han = u2_wr_ice(wir_r, u2_t(gal))) ) {
            u2_rl_lose(wir_r, cul);
            return u2_none;
          }

          if ( u2_none == (guc = u2_rl_cell(wir_r, cul, han)) ) {
            u2_rl_lose(wir_r, cul);
            u2_rl_lose(wir_r, han);
            return u2_none;
          }
          return guc;
        }
      }
    }
  }
}

/* u2_wr_nock_toss():
**
**    Execute `(nock bus fol)`, losing `bus`, holding `fol`.
*/
u2_weak
u2_wr_nock_toss(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_weak fut;

  u2_bx_fall(wir_r);
  fut = _toss(wir_r, bus, fol);

  u2_bx_mark(wir_r);
  u2_bx_rise(wir_r);
  return fut;
}
