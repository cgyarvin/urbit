/* l/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

    /** Forward declarations.
    **/
      static u2_weak
      _nock_jet(u2_wire wir_r, u2_noun bus, u2_noun fol);

    /** Internal variables.
    **/

/* _nock_warm():
**
**    Execute `(nock bus fol)`.  
**
**    Caller transfers `bus`, retains `fol`.
**    Function transfers result, if any.
*/
static u2_weak                                                    //  transfer
_nock_warm(u2_wire wir_r,
           u2_noun bus,                                           //  transfer
           u2_noun fol)                                           //  retain
{
# define _nock_warm_keep(wir_r, vid, heb) \
    _nock_warm(wir_r, u2_rl_gain(wir_r, vid), heb)
  u2_noun hib, gal;

  while ( 1 ) {
    u2_bx_step(wir_r);
    u2_bx_mark(wir_r);

    if ( LoomStop ) {
      fprintf(stderr, "<<stop>>\n");
      LoomStop = 0;
      u2_rl_lose(wir_r, bus);
      return u2_none;
    }

    if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
      u2_rl_lose(wir_r, bus);
      return u2_none;
    }
    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz, riv, hux;

      LoomSink; u2_bx_sink(wir_r);
      poz = _nock_warm_keep(wir_r, bus, hib);
      u2_bx_rise(wir_r); LoomRise;

      if ( u2_none == poz ) {
        u2_rl_lose(wir_r, bus);
        return u2_none;
      }

      LoomSink; u2_bx_sink(wir_r);
      riv = _nock_warm(wir_r, bus, gal);
      u2_bx_rise(wir_r); LoomRise;

      if ( u2_none == riv ) {
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

          LoomSink; u2_bx_sink(wir_r);
          dom = _nock_warm_keep(wir_r, bus, paz);
          u2_bx_rise(wir_r); LoomRise;

          if ( u2_none == dom ) { 
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }

          LoomSink; u2_bx_sink(wir_r);
          sep = _nock_warm(wir_r, bus, mis);
          u2_bx_rise(wir_r); LoomRise;

          if ( u2_none == sep ) {
            u2_rl_lose(wir_r, dom);
            return u2_none;
          }
          if ( u2_no == u2_rl_senior(wir_r, dom) ) {
            u2_weak hoz;
           
            LoomSink; u2_bx_sink(wir_r);
            hoz = _nock_warm(wir_r, sep, dom);
            u2_bx_rise(wir_r); LoomRise;

            u2_rl_lose(wir_r, dom);
            return hoz;
          }
          else {
            /* Attempt jet propulsion.
            */
            {
              u2_noun pro;

              if ( u2_none != (pro = _nock_jet(wir_r, sep, dom)) ) {
                u2_rl_lose(wir_r, sep);

                return pro;
              }
            }

            bus = sep;
            fol = dom;
            continue;
          }
        }
      }
    /* dust
    */
      case u2_nock_dust: {
        u2_weak gof, laz;

        LoomSink; u2_bx_sink(wir_r);
        gof = _nock_warm(wir_r, bus, gal);
        u2_bx_rise(wir_r); LoomRise;

        laz = (gof == u2_none) ? u2_none : u2_dust(gof);

        u2_rl_lose(wir_r, gof);
        return laz;
      }
    /* vint
    */
      case u2_nock_vint: {
        u2_weak gof, laz;
       
        LoomSink; u2_bx_sink(wir_r);
        gof = _nock_warm(wir_r, bus, gal);
        u2_bx_rise(wir_r); LoomRise;

        laz = u2_rl_vint(wir_r, gof);
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
          u2_weak dib, rum, laz;
         
          LoomSink; u2_bx_sink(wir_r);
          dib = _nock_warm_keep(wir_r, bus, u2_h(gal));
          rum = _nock_warm(wir_r, bus, u2_t(gal));
          u2_bx_rise(wir_r); LoomRise;

          if ( (u2_none == dib) || (u2_none == rum) ) {
            laz = u2_none;
          }
          else {
            laz = u2_sing(dib, rum);
          }

          u2_rl_lose(wir_r, dib);
          u2_rl_lose(wir_r, rum);
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
          u2_weak gyl;
         
          LoomSink; u2_bx_sink(wir_r);
          gyl = _nock_warm_keep(wir_r, bus, yor);
          u2_bx_rise(wir_r); LoomRise;

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
              u2_rl_lose(wir_r, gyl);
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

          LoomSink; u2_bx_sink(wir_r);
          bod = _nock_warm(wir_r, bus, meg);
          u2_bx_rise(wir_r); LoomRise;

          if ( u2_none == bod ) {
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

          LoomSink; u2_bx_sink(wir_r); 
          bod = _nock_warm_keep(wir_r, bus, meg);
          u2_bx_rise(wir_r); LoomRise;

          if ( u2_none == bod ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (har = u2_rl_cell(wir_r, bod, bus)) ) {
            return u2_none;
          }
          bus = har;
          fol = fas;
          continue;
        }
      }
    /* kick
    */
      case u2_nock_kick: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);

          return u2_none; 
        } else {
          u2_noun fac = u2_h(gal);
          u2_noun dym = u2_t(gal);
          u2_noun sep, dom, pro;

          if ( u2_no == u2_stud(fac) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          else {
            LoomSink; u2_bx_sink(wir_r);
            sep = _nock_warm(wir_r, bus, dym);
            u2_bx_rise(wir_r); LoomRise;

            if ( u2_none == sep ) {
              return u2_none;
            }
            if ( u2_none == (dom = u2_frag(fac, sep)) ) {
              u2_rl_lose(wir_r, sep);
              return u2_none;
            }
            if ( u2_no == u2_rl_senior(wir_r, dom) ) {
              u2_rl_gain(wir_r, dom);

              LoomSink; u2_bx_sink(wir_r);
              pro = _nock_warm(wir_r, sep, dom);
              u2_bx_rise(wir_r); LoomRise;

              u2_rl_lose(wir_r, dom);
              return pro;
            }
            if ( u2_none != (pro = _nock_jet(wir_r, sep, dom)) ) {
              u2_rl_lose(wir_r, sep);

              return pro;
            }

            bus = sep;
            fol = dom;
            continue;
          }
        }
      }
    /* hint
    */
      case u2_nock_hint: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_noun guz = u2_h(gal);
          u2_noun zom = u2_t(gal);
          u2_weak zep, hod, pro;

          if ( u2_no == u2_dust(guz) ) {
            zep = guz;
            hod = u2_nul;
          }
          else {
            zep = u2_h(guz);
            hod = _nock_warm_keep(wir_r, bus, u2_t(guz));

            if ( u2_none == hod ) {
              u2_rl_lose(wir_r, bus);
              return u2_none;
            }
          }

          switch ( zep ) {
            default: u2_rl_lose(wir_r, hod); fol = zom; continue;

            case c3__bean: {
              u2_bx_bean_ent(wir_r, hod);
              {
                LoomSink; u2_bx_sink(wir_r);
                if ( (pro = _nock_warm(wir_r, bus, zom)) != u2_none ) {
                  u2_bx_bean_out(wir_r);
                }
                u2_bx_rise(wir_r); LoomRise;
              }
              return pro;
            }

            case c3__loaf: {
              u2_err(wir_r, "loaf", hod);
              u2_rl_lose(wir_r, hod);
              fol = zom; 
              continue;
            }

            case c3__mine: {
              LoomSink; u2_bx_sink(wir_r);
              pro = _nock_warm(wir_r, bus, zom);
              u2_bx_rise(wir_r); LoomRise; 

              if ( u2_none == pro ) {
                u2_rl_lose(wir_r, hod);

                return u2_none;
              }
              else {
                pro = u2_sh_mine(wir_r, hod, pro);
         
                u2_rl_lose(wir_r, hod);
                return pro;
              }
            }

            case c3__memo: {
              u2_rl_lose(wir_r, hod);
              {
                pro = u2_ba_find(wir_r, bus, zom);

                if ( pro != u2_none ) {
                  u2_rl_lose(wir_r, bus);

                  return pro;
                } else {
                  LoomSink; u2_bx_sink(wir_r);
                  pro = _nock_warm_keep(wir_r, bus, zom);
                  u2_bx_rise(wir_r); LoomRise;

                  if ( u2_none == pro ) {
                    return u2_none;
                  }
                  else {
                    pro = u2_ba_save(wir_r, bus, zom, pro);

                    u2_rl_lose(wir_r, bus);
                    return pro;
                  }
                }
              }
            }

            case c3__ping: {
              u2_rl_lose(wir_r, hod);
              u2_bx_used(wir_r);

              fol = zom;
              continue;
            }

            case c3__sole: {
              u2_rl_lose(wir_r, hod);
              {
                LoomSink; u2_bx_sink(wir_r);
                pro = u2_nk_nock(wir_r, bus, zom);
                u2_bx_rise(wir_r); LoomRise;

                if ( u2_none == pro ) {
                  return u2_none;
                }
                else return u2_ba_sole(wir_r, pro);
              }
            }

            case c3__spot: {
              u2_bx_spot(wir_r, hod);

              fol = zom;
              continue;
            }
          }
        }
      }
    }
  }
}

/* _nock_cold(): 
**
**   In cold memory, produce `(nock bus fol)` on the hat; then reduce
**   the cap to `net_r`.
*/
static u2_weak                                                    //  transfer
_nock_cold(u2_wire wir_r,
           u2_ray  net_r,
           u2_noun bus,                                           //  retain
           u2_noun fol)                                           //  retain
{
# define _nock_cold_here(wir_r, bus, fol) \
    _nock_cold(wir_r, u2_rail_cap_r(wir_r), bus, fol)
  u2_noun hib, gal;

  while ( 1 ) {
    u2_bx_mark(wir_r);
    u2_bx_step(wir_r);

    if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
      return u2_none;
    }

    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz, riv;

      if ( u2_none == (poz = _nock_cold_here(wir_r, bus, hib)) ) {
        return u2_none;
      }
      if ( u2_none == (riv = _nock_cold(wir_r, net_r, bus, gal)) ) {
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
            if ( u2_none == (dom = _nock_cold_here(wir_r, bus, paz)) ) 
            {
              return u2_none;
            }
            if ( u2_none == (sep = _nock_cold_here(wir_r, bus, mis)) )
            {
              return u2_none;
            }
          }
          u2_rl_fall(wir_r);

          /* Attempt jet propulsion.
          */
          {
            u2_noun pro;

            if ( u2_none != (pro = _nock_jet(wir_r, bus, fol)) ) {
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

            doy = _nock_cold_here(wir_r, sep, dom);

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
          gof = _nock_cold_here(wir_r, bus, gal);
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
          gof = _nock_cold_here(wir_r, bus, gal);
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
            dib = _nock_cold_here(wir_r, bus, u2_h(gal));
            rum = _nock_cold_here(wir_r, bus, u2_t(gal));
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
            gyl = _nock_cold_here(wir_r, bus, yor);
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
            if ( u2_none == (bod = _nock_cold_here(wir_r, bus, meg)) )
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
            if ( u2_none == (bod = _nock_cold_here(wir_r, bus, meg)) ) {
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
    /* kick = 9
    */
      case u2_nock_kick: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none; 
        } else {
          u2_noun fac = u2_h(gal);
          u2_noun dym = u2_t(gal);
          u2_noun bod, vig;

          if ( u2_no == u2_stud(fac) ) {
            return u2_none;
          }
          if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
          {
            if ( (u2_none == (bod = _nock_cold_here(wir_r, bus, dym))) ||
                 (u2_none == (vig = u2_frag(fac, bod))) )
            {
              return u2_none;
            }
          }
          u2_rl_fall(wir_r);

          bus = bod;
          fol = vig;
          continue;
        }
      }
    /* hint = 10
    */
      case u2_nock_hint: {
        if ( u2_no == u2_dust(gal) ) {
          return u2_none;
        } else {
          u2_ray  bat_r = u2_rail_cap_r(wir_r);
          u2_noun guz = u2_h(gal);
          u2_noun zom = u2_t(gal);
          u2_weak zep, hod;

          if ( u2_no == u2_dust(guz) ) {
            zep = guz;
            hod = u2_nul;
          } else { 
            zep = u2_h(guz);

            if ( u2_no == u2_rl_leap(wir_r, c3__cold) ) { return u2_none; }
            {
              hod = _nock_cold_here(wir_r, bus, u2_t(guz));
            }
          }
          u2_rl_fall(wir_r);
          u2_rail_cap_r(wir_r) = bat_r;

          fol = zom;
          continue;
        }
      }
    }
  }
}

/* _nock_soft():
**
**   Compute `(nock bus fol)`, interpreter first.
*/
static u2_weak                                                    //  transfer
_nock_soft(u2_wire wir_r,
           u2_noun bus,                                           //  transfer
           u2_noun fol)                                           //  retain
{
  u2_weak pro;

  switch ( u2_rail_hip_m(wir_r) ) {
    default: c3_assert(0); return u2_none;

    case c3__cold: {
      u2_ray  cap_r = u2_rail_cap_r(wir_r);
      u2_ray  hat_r = u2_rail_hat_r(wir_r);
      u2_ray  mat_r = u2_rail_mat_r(wir_r);
      u2_ray  rut_r = u2_rail_rut_r(wir_r);

      LoomSink; u2_bx_sink(wir_r);
      pro = _nock_cold(wir_r, cap_r, bus, fol);
      u2_bx_rise(wir_r); LoomRise;

      if ( u2_none == pro ) {
        u2_rail_cap_r(wir_r) = cap_r;
        u2_rail_hat_r(wir_r) = hat_r;
        u2_rail_mat_r(wir_r) = mat_r;
        u2_rail_rut_r(wir_r) = rut_r;
        u2_rail_hip_m(wir_r) = c3__cold;
      }
      u2_rl_lose(wir_r, bus);

      return pro;
    }

    case c3__warm: {
      LoomSink; u2_bx_sink(wir_r);
      pro = _nock_warm(wir_r, bus, fol);
      u2_bx_rise(wir_r); LoomRise;

      return pro;
    }
  }
}

/* _nock_jet():
**
**   Jet-propel `(nock bus fol)`, or return u2_none.
*/
static u2_weak                                                    //  transfer
_nock_jet(u2_wire wir_r,
          u2_noun bus,                                            //  retain
          u2_noun fol)                                            //  retain
{
  u2_noun xip = u2_sh_find(wir_r, bus);

  if ( u2_none == xip ) {
    return u2_none;
  } else {
    u2_noun pro, vet;
    u2_flag saf;

    if ( u2_none == (pro = u2_ho_fire(wir_r, xip, bus, fol, &saf)) ) {
      return u2_none;
    }
    else {
      u2_bx_flew(wir_r);

      if ( u2_yes == saf ) {
        return pro;
      }
      else {
        if ( u2_no == u2_rl_leap(wir_r, u2_rail_hip_m(wir_r)) ) {
          u2_rl_lose(wir_r, pro);
          u2_ho_stet(wir_r, xip, bus, fol, u2_nul, u2_nul);
          return u2_none;
        }
        else {
          u2_rl_gain(wir_r, bus);
          if ( u2_none == (vet = _nock_soft(wir_r, bus, fol)) ) {
            u2_rl_fall(wir_r);
            u2_ho_stet(wir_r, xip, bus, fol, u2_nul, u2_nul);
            u2_rl_lose(wir_r, pro);

            return u2_none;
          }
          else {
            u2_rl_fall(wir_r);
            u2_ho_stet(wir_r, xip, bus, fol, pro, vet);

            return pro;
          }
        }
      }
    }
  }
}

/* u2_nk_nock():
**
**   Compute `(nock bus fol)`.
*/
u2_weak                                                           //  transfer
u2_nk_nock(u2_wire wir_r,
           u2_weak bus,                                           //  transfer
           u2_weak fol)                                           //  retain
{
  u2_noun pro;

  if ( u2_none == fol ) {
    u2_rl_lose(wir_r, bus);
    return u2_none;
  }
  else if ( u2_none == bus ) {
    return u2_none;
  }
#if 1
  else if ( u2_none != (pro = (_nock_jet(wir_r, bus, fol))) ) {
    u2_rl_lose(wir_r, bus);

    return pro;
  }
  else {
    return _nock_soft(wir_r, bus, fol);
  }
#else
  return _nock_warm(wir_r, bus, fol);
#endif
}

/* u2_nk_mung():
**
**   Compute `(nock gat(-< sam) +.gat)`.
*/
u2_weak                                                           //  transfer
u2_nk_mung(u2_wire wir_r,
           u2_weak gat,                                           //  retain
           u2_weak sam)                                           //  transfer
{
  /*  XX: could be slightly faster, but admirably terse.
  */
  return u2_nk_nock
    (wir_r,
     u2_rc
      (wir_r,
       u2_rc(wir_r, sam, u2_rx(wir_r, u2_st(u2_sh(gat)))),
       u2_rx(wir_r, u2_st(gat))),
     u2_st(gat));
}

/* u2_nk_kick():
**
**   Fire `gat` without changing the sample.
*/
u2_weak                                                           //  transfer
u2_nk_kick(u2_wire wir_r,
           u2_weak gat)                                           //  retain
{
  return u2_nk_nock
    (wir_r,
     u2_rx(wir_r, gat),
     u2_st(gat));
}
