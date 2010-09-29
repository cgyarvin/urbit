/* l/nock/lame.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* _lame(): substance of u2_wr_nock_lame().
*/
static u2_weak
_lame(u2_ray  wir_r,
      u2_noun bus,
      u2_noun fol)
{
  u2_noun hib, gal;

  u2_bx_mark(wir_r);
  u2_bx_step(wir_r);

  /* Attempt jet propulsion.
  */
  {
    u2_noun pro;

    if ( u2_none != (pro = u2_wr_nock_jet(wir_r, bus, fol)) ) {
      return pro;
    }
  }

  if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
    return u2_none;
  }
  else {
    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz = u2_wr_nock_lame(wir_r, bus, hib);
      u2_weak riv = u2_wr_nock_lame(wir_r, bus, gal);

      if ( (u2_none == poz) || (u2_none == riv) ) {
        return u2_none;
      }
      else return u2_rl_cell(wir_r, poz, riv);
    }
    else switch ( hib ) {
      default: return u2_none;

      case u2_nock_frag: {
        if ( u2_no == u2_stud(gal) ) {
          return u2_none;
        }
        else {
          u2_weak dof = u2_frag(gal, bus);

          if ( u2_none == dof ) {
            return u2_none;
          }
          else return u2_wr_ice(wir_r, dof);
        }
      }

      case u2_nock_bone: {
        return u2_wr_ice(wir_r, gal);
      }

      case u2_nock_sail: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_noun sep, dom;

          sep = u2_wr_nock_lame(wir_r, bus, mis);
          dom = u2_wr_nock_lame(wir_r, bus, paz);

          return u2_wr_nock_lame(wir_r, sep, dom);
        }
      }

      case u2_nock_dust: {
        u2_weak gof = u2_wr_nock_lame(wir_r, bus, gal);

        if ( u2_none == gof ) {
          return u2_none;
        }
        else return u2_dust(gof);
      }

      case u2_nock_vint: {
        u2_weak gof = u2_wr_nock_lame(wir_r, bus, gal);

        if ( (u2_none == gof) || (u2_no == u2_stud(gof)) ) {
          return u2_none;
        }
        else {
          mpz_t mp_gof;

          u2_mp(mp_gof, gof); 
          mpz_add_ui(mp_gof, mp_gof, 1);

          return u2_rl_mp(wir_r, mp_gof);
        }
      } 

      case u2_nock_sing: {
        u2_weak gof = u2_wr_nock_lame(wir_r, bus, gal);

        if ( (u2_none == gof) || (u2_no == u2_dust(gof)) ) {
          return u2_none;
        }
        else {
          return u2_sing(u2_h(gof), u2_t(gof));
        }
      }

      case u2_nock_trol: {
        u2_weak yor, fli, paw;

        if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
          return u2_none;
        } 
        else {
          u2_weak gyl = u2_wr_nock_lame(wir_r, bus, yor);

          switch ( gyl ) {
            case 0 : return u2_wr_nock_lame(wir_r, bus, fli);
            case 1 : return u2_wr_nock_lame(wir_r, bus, paw);
            default: return u2_none;
          }
        }
      }

      case u2_nock_flac: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_weak bod = u2_wr_nock_lame(wir_r, bus, u2_h(gal));
   
          if ( u2_none == bod ) {
            return u2_none;
          } else {
            return u2_wr_nock_lame(wir_r, bod, u2_t(gal));
          }
        }
      }

      case u2_nock_gant: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_weak bod = u2_wr_nock_lame(wir_r, bus, u2_h(gal));
   
          if ( u2_none == bod ) {
            return u2_none;
          } else {
            return u2_wr_nock_lame
              (wir_r, u2_rl_cell(wir_r, bod, bus), u2_t(gal));
          }
        }
      }

      case u2_nock_mung: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_weak pec = u2_wr_nock_lame(wir_r, bus, u2_h(gal));
          u2_weak vud = u2_wr_nock_lame(wir_r, bus, u2_t(gal)); 

          if ( (u2_no == u2_dust(pec)) || (u2_no == u2_dust(u2_h(pec))) ) {
            return u2_none;
          } else {
            return u2_wr_nock_lame
              (wir_r,
               u2_zc(wir_r,
                     u2_zc(wir_r, vud, u2_t(u2_h(pec))),
                     u2_t(pec)),
               u2_t(pec));
          }
        }
      }

      case u2_nock_germ: {
        c3_assert(0);
      }

      case u2_nock_hint: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_noun hin = u2_wr_nock_lame(wir_r, bus, u2_h(gal));

          return u2_wr_nock_hint(wir_r, hin, bus, u2_t(gal)); 
        }
      }
      case u2_nock_coat: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          return u2_rl_cell(wir_r, bus, u2_t(gal));
        }
      }
    }
  }
}

/* u2_wr_nock_lame():
**
**    Execute `(nock bus fol)` with a simple reference interpreter.
*/
u2_weak
u2_wr_nock_lame(u2_ray  wir_r,
                u2_noun bus,
                u2_noun fol)
{
  u2_weak fut;

  u2_bx_fall(wir_r);
  fut = _lame(wir_r, bus, fol);

  u2_bx_mark(wir_r);
  u2_bx_rise(wir_r);
  return fut;
}

