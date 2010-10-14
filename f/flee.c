/* l/nock/flee.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_wr_nock_here():
**
**    As `u2_wr_nock_flee()`, but without cap reduction.
*/
u2_weak
u2_wr_nock_here(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  return u2_wr_nock_flee(wir_r, u2_rail_cap_r(wir_r), bus, fol);
}

/* _flee(): substance of u2_wr_nock_flee().
*/
static u2_weak
_flee(u2_ray  wir_r,
      u2_ray  net_r,
      u2_noun bus,
      u2_noun fol)
{
  u2_noun hib, gal;

  while ( 1 ) {
    u2_bx_mark(wir_r);
    u2_bx_step(wir_r);

    if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
      return u2_none;
    }

    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz, riv;

      if ( u2_none == (poz = u2_wr_nock_here(wir_r, bus, hib)) ) {
        return u2_none;
      }
      if ( u2_none == (riv = u2_wr_nock_flee(wir_r, net_r, bus, gal)) ) {
        return u2_none;
      }
      return u2_rl_cell(wir_r, poz, riv);
    }
    else switch ( hib ) {
      default: return u2_none;
    /* frag = 0
    */
      case u2_nock_frag: {
        if ( u2_no == u2_stud(gal) ) {
          return u2_none;
        }
        else {
          u2_weak dof = u2_frag(gal, bus);

          if ( u2_none == dof ) {
            return u2_none;
          }
          else {
            u2_noun hep = u2_wr_ice(wir_r, dof);

            u2_rail_cap_r(wir_r) = net_r;
            return hep;
          }
        }
      }
    /* bone = 1
    */
      case u2_nock_bone: {
        u2_rail_cap_r(wir_r) = net_r;

        return u2_wr_ice(wir_r, gal);
      }
    /* sail = 2
    */
      case u2_nock_sail: {
        if ( (u2_no == u2_dust(gal)) || (u2_no == u2_dust(u2_h(gal))) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_noun sep, dom;

          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (dom = u2_wr_nock_here(wir_r, bus, paz)) ) 
            {
              return u2_none;
            }
            if ( u2_none == (sep = u2_wr_nock_here(wir_r, bus, mis)) )
            {
              return u2_none;
            }
          }
          u2_rl_fall(wir_r);

          /* Attempt jet propulsion.
          */
          {
            u2_noun pro;

            if ( u2_none != (pro = u2_wr_nock_jet(wir_r, bus, fol)) ) {
              u2_rail_cap_r(wir_r) = net_r;

              return pro;
            }
          }

          if ( (u2_no == u2_rl_senior(wir_r, dom)) ||
               (u2_no == u2_rl_clear(sep, net_r, bat_r)) ) 
          {
            /* Tail compaction will not succeed.
            */
            u2_noun doy;

            doy = u2_wr_nock_here(wir_r, sep, dom);

            u2_rail_cap_r(wir_r) = net_r;
            return doy;
          } 
          else {
            /* Tail compaction will succeed.
            */
            sep = u2_rl_tamp(wir_r, sep, net_r, bat_r);

            bus = sep;
            fol = dom;
            continue;
          }
        }
      }
    /* dust = 3 
    */
      case u2_nock_dust: {
        u2_weak gof;

        if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
        {
          gof = u2_wr_nock_here(wir_r, bus, gal);
        }
        u2_rl_fall(wir_r);

        if ( u2_none == gof ) {
          return u2_none;
        }
        else {
          u2_rail_cap_r(wir_r) = net_r;

          return u2_dust(gof);
        }
      }
    /* vint = 4
    */
      case u2_nock_vint: {
        u2_weak gof;

        if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
        {
          gof = u2_wr_nock_here(wir_r, bus, gal);
        }
        u2_rl_fall(wir_r);

        if ( (u2_none == gof) || (u2_no == u2_stud(gof)) ) {
          return u2_none;
        }
        else {
          mpz_t mp_gof;

          u2_mp(mp_gof, gof); 
          mpz_add_ui(mp_gof, mp_gof, 1);

          u2_rail_cap_r(wir_r) = net_r;
          return u2_rl_mp(wir_r, mp_gof);
        }
      } 
    /* sing = 5
    */
      case u2_nock_sing: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        }
        else {
          u2_weak dib, rum;

          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            dib = u2_wr_nock_here(wir_r, bus, u2_h(gal));
            rum = u2_wr_nock_here(wir_r, bus, u2_t(gal));
          }
          u2_rl_fall(wir_r);

          if ( (u2_none == dib) || (u2_none == rum) ) {
            return u2_none;
          }
          else {
            u2_rail_cap_r(wir_r) = net_r;
            return u2_sing(dib, rum);
          }
        }
      }
    /* trol = 6
    */
      case u2_nock_trol: {
        u2_weak yor, fli, paw;

        if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
          return u2_none;
        } 
        else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_weak gyl;
          
          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            gyl = u2_wr_nock_here(wir_r, bus, yor);
          }
          u2_rl_fall(wir_r);
          u2_rail_cap_r(wir_r) = bat_r;

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
    /* flac = 7
    */
      case u2_nock_flac: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod;

          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (bod = u2_wr_nock_here(wir_r, bus, meg)) )
            {
              return u2_none;
            }
          }
          u2_rl_fall(wir_r);

          bus = bod;
          fol = fas;
          continue;
        }
      }
    /* gant = 8
    */
      case u2_nock_gant: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod, har;

          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( u2_none == (bod = u2_wr_nock_here(wir_r, bus, meg)) ) {
              return u2_none;
            }
            if ( u2_none == (har = u2_rl_cell(wir_r, bod, bus)) ) {
              return u2_none;
            }
          }
          u2_rl_fall(wir_r);

          bus = har;
          fol = fas;
          continue;
        }
      }
    /* mung = 9
    */
      case u2_nock_mung: {
#if 1
        c3_assert(0); return 0;
#else
#endif
      }
    /* germ = 10
    */
      case u2_nock_germ: {
        c3_assert(0); return 0;
      }
    /* hint = 11
    */
      case u2_nock_hint: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_noun yeq = u2_h(gal);
          u2_noun zom = u2_t(gal);
          u2_weak hig, zep, hod, lut;

          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            hig = u2_wr_nock_here(wir_r, bus, yeq);
            if ( u2_yes == u2_stud(hig) ) {
              zep = hig; hod = u2_nul;
            } else {
              zep = u2_h(hig); hod = u2_t(hig);
            }
          }
          u2_rl_fall(wir_r);

          lut = u2_wr_nock_hint(wir_r, zep, hod, bus, zom);

          u2_rail_cap_r(wir_r) = bat_r;
          return lut;
        }
      }
    /* coat = 12
    */
      case u2_nock_coat: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_weak cul, han, guc;

          if ( u2_none == (cul = u2_wr_ice(wir_r, bus)) ) {
            return u2_none;
          }

          if ( u2_none == (han = u2_wr_ice(wir_r, u2_t(gal))) ) {
            return u2_none;
          }

          if ( u2_none == (guc = u2_rl_cell(wir_r, cul, han)) ) {
            return u2_none;
          }

          u2_rail_cap_r(wir_r) = net_r;
          return guc;
        }
      }
    }
  }
}

/* u2_wr_nock_flee():
**
**    Execute `(nock bus fol)` in the `flee` memory style.
**
**    After using `bus`, reduce `cap` to `net`.
*/
u2_weak
u2_wr_nock_flee(u2_ray  wir_r,
                u2_ray  net_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_weak fut;

  u2_bx_fall(wir_r);
  fut = _flee(wir_r, net_r, bus, fol);

  u2_bx_mark(wir_r);
  u2_bx_rise(wir_r);
  return fut;
}
