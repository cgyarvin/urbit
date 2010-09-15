/* l/nock/lame.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_wr_nock_lame():
**
**    Execute `(nock bus fol)` with a simple reference interpreter.
*/
u2_weak
u2_wr_nock_lame(u2_ray  wir_r,
                c3_w    stk_w,
                u2_noun bus,
                u2_noun fol)
{
  u2_noun hib, gal;

  u2_wr_bench(wir_r, stk_w);

  if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
    return u2_none;
  }
  else {
    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz = u2_wr_nock_lame(wir_r, 1+stk_w, bus, hib);
      u2_weak riv = u2_wr_nock_lame(wir_r, 1+stk_w, bus, gal);

      if ( (u2_none == poz) || (u2_none == riv) ) {
        return u2_none;
      }
      else return u2_zn_cell(wir_r, poz, riv);
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
          else return u2_zn_ice(wir_r, dof);
        }
      }

      case 1: {
        return u2_zn_ice(wir_r, gal);
      }

      case 2: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_noun sep, dom;

          sep = u2_wr_nock_lame(wir_r, 1+stk_w, bus, mis);
          dom = u2_wr_nock_lame(wir_r, 1+stk_w, bus, paz);

          return u2_wr_nock_lame(wir_r, 1+stk_w, sep, dom);
        }
      }

      case 3: {
        u2_weak gof = u2_wr_nock_lame(wir_r, 1+stk_w, bus, gal);

        if ( u2_none == gof ) {
          return u2_none;
        }
        else return u2_dust(gof);
      }

      case 4: {
        u2_weak gof = u2_wr_nock_lame(wir_r, 1+stk_w, bus, gal);

        if ( (u2_none == gof) || (u2_no == u2_stud(gof)) ) {
          return u2_none;
        }
        else {
          mpz_t mp_gof;

          u2_mp(mp_gof, gof); 
          mpz_add_ui(mp_gof, mp_gof, 1);

          return u2_zn_mp(wir_r, mp_gof);
        }
      } 

      case 5: {
        u2_weak gof = u2_wr_nock_lame(wir_r, 1+stk_w, bus, gal);

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
          u2_weak gyl = u2_wr_nock_lame(wir_r, 1+stk_w, bus, yor);

          switch ( gyl ) {
            case 0 : return u2_wr_nock_lame(wir_r, 1+stk_w, bus, fli);
            case 1 : return u2_wr_nock_lame(wir_r, 1+stk_w, bus, paw);
            default: return u2_none;
          }
        }
      }

      case 7: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_weak bod = u2_wr_nock_lame(wir_r, 1+stk_w, bus, u2_h(gal));
   
          if ( u2_none == bod ) {
            return u2_none;
          } else {
            return u2_wr_nock_lame(wir_r, 1+stk_w, bod, u2_t(gal));
          }
        }
      }

      case 8: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_weak bod = u2_wr_nock_lame(wir_r, 1+stk_w, bus, u2_h(gal));
   
          if ( u2_none == bod ) {
            return u2_none;
          } else {
            return u2_wr_nock_lame
              (wir_r, 1+stk_w, u2_zn_cell(wir_r, bod, bus), u2_t(gal));
          }
        }
      }

      case 9: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_weak pec = u2_wr_nock_lame(wir_r, 1+stk_w, bus, u2_h(gal));
          u2_weak vud = u2_wr_nock_lame(wir_r, 1+stk_w, bus, u2_t(gal)); 

          if ( (u2_no == u2_dust(pec)) || (u2_no == u2_dust(u2_h(pec))) ) {
            return u2_none;
          } else {
            return u2_wr_nock_lame
              (wir_r,
               1+stk_w,
               u2_zc(wir_r,
                     u2_zc(wir_r, vud, u2_t(u2_h(pec))),
                     u2_t(pec)),
               u2_t(pec));
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
          u2_wr_nock_lame(wir_r, 1+stk_w, bus, u2_h(gal));

          return u2_wr_nock_lame(wir_r, 1+stk_w, bus, u2_t(gal)); 
        }
      }
      case 12: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          return u2_zn_cell(wir_r, bus, u2_t(gal));
        }
      }
    }
  }
}
