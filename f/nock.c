/* f/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

    /** Internal variables.
    **/

/* _nock_rock():
**
**    Execute `(nock bus fol)`.  
**
**    Caller transfers `bus`, retains `fol`.
**    Function transfers result, if any.
*/
static u2_weak                                                    //  transfer
_nock_rock(u2_wire wir_r,
           u2_noun bus,                                           //  transfer
           u2_noun fol)                                           //  retain
{
# define _nock_rock_keep(wir_r, vid, heb) \
    _nock_rock(wir_r, u2_rl_gain(wir_r, vid), heb)
  u2_noun hib, gal;

  while ( 1 ) {
    u2_tx_did_hop(wir_r, 1);

    // c3_assert(u2_wrac_at(wir_r, wer.sys) == u2_no);

    if ( LoomStop ) {
      if ( LoomIntr ) {
        fprintf(stderr, "{interrupt}\n");
      } else {
        fprintf(stderr, "{stack overflow}\n");
      }
      LoomStop = LoomIntr = 0;
      u2_rl_lose(wir_r, bus);
      return u2_none;
    }

    if ( u2_no == u2_as_cell(fol, &hib, &gal) ) {
      u2_rl_lose(wir_r, bus);
      return u2_none;
    }
    if ( u2_yes == u2_dust(hib) ) {
      u2_weak poz, riv, hux;

      LoomSink; u2_tx_sink_cas(wir_r);
      poz = _nock_rock_keep(wir_r, bus, hib);
      u2_tx_rise_cas(wir_r); LoomRise;

      if ( u2_none == poz ) {
        u2_rl_lose(wir_r, bus);
        return u2_none;
      }

      LoomSink; u2_tx_sink_cas(wir_r);
      riv = _nock_rock(wir_r, bus, gal);
      u2_tx_rise_cas(wir_r); LoomRise;

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
      case u2_nock_0: {
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
      case u2_nock_1: {
        u2_noun sug;

        u2_rl_lose(wir_r, bus);

        sug = u2_wr_ice(wir_r, gal);
        return sug;
      }
      case u2_nock_2: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        } else {
          u2_noun mis = u2_h(gal);
          u2_noun paz = u2_t(gal);
          u2_weak sep, dom;

          LoomSink; u2_tx_sink_cas(wir_r);
          dom = _nock_rock_keep(wir_r, bus, paz);
          u2_tx_rise_cas(wir_r); LoomRise;

          if ( u2_none == dom ) { 
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }

          LoomSink; u2_tx_sink_cas(wir_r);
          sep = _nock_rock(wir_r, bus, mis);
          u2_tx_rise_cas(wir_r); LoomRise;

          if ( u2_none == sep ) {
            u2_rl_lose(wir_r, dom);
            return u2_none;
          }
          if ( u2_no == u2_rl_senior(wir_r, dom) ) {
            u2_weak hoz;
           
            LoomSink; u2_tx_sink_cas(wir_r);
            hoz = _nock_rock(wir_r, sep, dom);
            u2_tx_rise_cas(wir_r); LoomRise;

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
      case u2_nock_3: {
        u2_weak gof, laz;

        LoomSink; u2_tx_sink_cas(wir_r);
        gof = _nock_rock(wir_r, bus, gal);
        u2_tx_rise_cas(wir_r); LoomRise;

        laz = (gof == u2_none) ? u2_none : u2_dust(gof);

        u2_rl_lose(wir_r, gof);
        return laz;
      }
      case u2_nock_4: {
        u2_weak gof, laz;
       
        LoomSink; u2_tx_sink_cas(wir_r);
        gof = _nock_rock(wir_r, bus, gal);
        u2_tx_rise_cas(wir_r); LoomRise;

        laz = u2_rl_vint(wir_r, gof);
        return laz;
      }
      case u2_nock_5: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        }
        else {
          u2_weak dib, rum, laz;
         
          LoomSink; u2_tx_sink_cas(wir_r);
          dib = _nock_rock_keep(wir_r, bus, u2_h(gal));
          rum = _nock_rock(wir_r, bus, u2_t(gal));
          u2_tx_rise_cas(wir_r); LoomRise;

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
      case u2_nock_6: {
        u2_weak yor, fli, paw;

        if ( u2_no == u2_as_trel(gal, &yor, &fli, &paw) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none;
        } 
        else {
          u2_weak gyl;
         
          LoomSink; u2_tx_sink_cas(wir_r);
          gyl = _nock_rock_keep(wir_r, bus, yor);
          u2_tx_rise_cas(wir_r); LoomRise;

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
      case u2_nock_7: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);

          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod;

          LoomSink; u2_tx_sink_cas(wir_r);
          bod = _nock_rock(wir_r, bus, meg);
          u2_tx_rise_cas(wir_r); LoomRise;

          if ( u2_none == bod ) {
            return u2_none;
          }
          bus = bod;
          fol = fas;
          continue;
        }
      }
      case u2_nock_8: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);
          return u2_none; 
        } else {
          u2_noun meg = u2_h(gal);
          u2_noun fas = u2_t(gal);
          u2_noun bod, har;

          LoomSink; u2_tx_sink_cas(wir_r); 
          bod = _nock_rock_keep(wir_r, bus, meg);
          u2_tx_rise_cas(wir_r); LoomRise;

          if ( u2_none == bod ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          if ( u2_none == (har = u2_rl_cell(wir_r, bus, bod)) ) {
            return u2_none;
          }
          bus = har;
          fol = fas;
          continue;
        }
      }
      case u2_nock_9: {
        if ( u2_no == u2_dust(gal) ) {
          u2_rl_lose(wir_r, bus);

          return u2_none; 
        } else {
          u2_noun fac = u2_h(gal);
          u2_noun dym = u2_t(gal);
          u2_noun sep, dom, pro, xip;

          if ( u2_no == u2_stud(fac) ) {
            u2_rl_lose(wir_r, bus);
            return u2_none;
          }
          else {
            LoomSink; u2_tx_sink_cas(wir_r);
            sep = _nock_rock(wir_r, bus, dym);
            u2_tx_rise_cas(wir_r); LoomRise;

            if ( u2_none == sep ) {
              return u2_none;
            }
            u2_tx_sys_bit(wir_r, u2_yes);

            if ( u2_none != (xip = u2_ds_find(wir_r, sep)) ) {
#if 0
              {
                c3_c *cos_c = u2_ho_cstring(xip);

                printf("jet %s\n", cos_c);
#if 0
                u2_noun cos = u2_bn_string(wir_r, cos_c);
                
                u2_tx_did_act(wir_r, cos);
                u2_rz(wir_r, cos);
#endif
                free(cos_c);
              }
#endif
              pro = u2_ho_kick(wir_r, xip, sep, fac);
              u2_tx_sys_bit(wir_r, u2_no);

              u2_rl_lose(wir_r, sep);
              return pro;
            }
            else {
              u2_tx_sys_bit(wir_r, u2_no);
            }

            if ( u2_none == (dom = u2_frag(fac, sep)) ) {
              u2_rl_lose(wir_r, sep);
              return u2_none;
            }
            if ( u2_no == u2_rl_senior(wir_r, dom) ) {
              u2_rl_gain(wir_r, dom);

              LoomSink; u2_tx_sink_cas(wir_r);
              pro = _nock_rock(wir_r, sep, dom);
              u2_tx_rise_cas(wir_r); LoomRise;

              u2_rl_lose(wir_r, dom);
              return pro;
            }

            bus = sep;
            fol = dom;
            continue;
          }
        }
      }
      case u2_nock_10: {
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
            hod = _nock_rock_keep(wir_r, bus, u2_t(guz));

            if ( u2_none == hod ) {
              u2_rl_lose(wir_r, bus);
              return u2_none;
            }
          }

          switch ( zep ) {
            default: u2_rl_lose(wir_r, hod); fol = zom; continue;

            case c3__bean: {
              u2_noun tax = u2_rx(wir_r, u2_wire_tax(wir_r));
              u2_noun tac = u2_rc(wir_r, c3__bean, hod);

              u2_wire_tax(wir_r) = u2_rc(wir_r, tac, tax);
              {
                LoomSink; u2_tx_sink_cas(wir_r);
                pro = _nock_rock(wir_r, bus, zom);
                u2_tx_rise_cas(wir_r); LoomRise;
              }

              if ( pro != u2_none ) {
                u2_rz(wir_r, u2_wire_tax(wir_r));
                u2_wire_tax(wir_r) = tax;
              }
              return pro;
            }
            case c3__mean: {
              u2_noun tax = u2_rx(wir_r, u2_wire_tax(wir_r));
              u2_noun tac = u2_rc(wir_r, c3__mean, hod);

              u2_wire_tax(wir_r) = u2_rc(wir_r, tac, tax);
              {
                LoomSink; u2_tx_sink_cas(wir_r);
                pro = _nock_rock(wir_r, bus, zom);
                u2_tx_rise_cas(wir_r); LoomRise;
              }

              if ( pro != u2_none ) {
                u2_rz(wir_r, u2_wire_tax(wir_r));
                u2_wire_tax(wir_r) = tax;
              }
              return pro;
            }
            case c3__spot: {
              u2_noun tax = u2_rx(wir_r, u2_wire_tax(wir_r));
              u2_noun tac = u2_rc(wir_r, c3__spot, hod);

              if ( (u2_no == u2_dust(hod)) || (u2_no == u2_stud(u2_h(hod))) ){
                u2_err(wir_r, "bad guz", guz);
                u2_err(wir_r, "bad hod", hod);
                c3_assert(0);
              }
              u2_wire_tax(wir_r) = u2_rc(wir_r, tac, tax);
              {
                LoomSink; u2_tx_sink_cas(wir_r);
                pro = _nock_rock(wir_r, bus, zom);
                u2_tx_rise_cas(wir_r); LoomRise;
              }

              if ( pro != u2_none ) {
                u2_rz(wir_r, u2_wire_tax(wir_r));
                u2_wire_tax(wir_r) = tax;
              }
              return pro;
            }

            case c3__loaf: {
              u2_tx_sys_bit(wir_r, u2_yes);
              u2_tx_loaf(wir_r, hod);
              u2_tx_sys_bit(wir_r, u2_no);

              u2_rl_lose(wir_r, hod);
              fol = zom; 
              continue;
            }

            case c3__turd: {
              u2_tx_sys_bit(wir_r, u2_yes);
              u2_err(wir_r, "turd", hod);
              u2_tx_sys_bit(wir_r, u2_no);

              u2_rl_lose(wir_r, hod);
              fol = zom; 
              continue;
            }

            case c3__mine: {
              LoomSink; u2_tx_sink_cas(wir_r);
              pro = _nock_rock(wir_r, bus, zom);
              u2_tx_rise_cas(wir_r); LoomRise; 

              if ( u2_none == pro ) {
                u2_rl_lose(wir_r, hod);

                return u2_none;
              }
              else {
                u2_tx_sys_bit(wir_r, u2_yes);
                pro = u2_ds_mine(wir_r, hod, pro);
                u2_tx_sys_bit(wir_r, u2_no);
         
                u2_rl_lose(wir_r, hod);
                return pro;
              }
            }
            case c3__fast: {
              LoomSink; u2_tx_sink_cas(wir_r);
              pro = _nock_rock(wir_r, bus, zom);
              u2_tx_rise_cas(wir_r); LoomRise; 

              if ( u2_none == pro ) {
                u2_rl_lose(wir_r, hod);

                return u2_none;
              }
              else {
                u2_noun p_hod, q_hod, r_hod;

                /* XX: translate hod to old clue form.
                */
                if ( u2_no == u2_as_trel(hod, &p_hod, &q_hod, &r_hod) ) {
                  u2_rz(wir_r, hod);
                  return pro;
                }
                else {
                  u2_noun xod;

                  if ( u2_yes == u2_dust(q_hod) &&
                       (_1 == u2_h(q_hod)) &&
                       (_0 == u2_t(q_hod)) ) {
                    q_hod = 0;
                  }
                  xod = u2_rt(wir_r, u2_rx(wir_r, q_hod),
                                     u2_rx(wir_r, p_hod),
                                     u2_rx(wir_r, r_hod));
                  u2_rz(wir_r, hod);
                  hod = xod;
                }
                u2_tx_sys_bit(wir_r, u2_yes);
                pro = u2_ds_mine(wir_r, hod, pro);
                u2_tx_sys_bit(wir_r, u2_no);
         
                u2_rl_lose(wir_r, hod);
                return pro;
              }
            }
            case c3__memo: {
              u2_rl_lose(wir_r, hod);
              {
#if 0
                pro = u2_ba_find(wir_r, bus, zom);
#else
                pro = u2_rl_find_cell(wir_r, 0, bus, zom);
#endif
                if ( pro != u2_none ) {
                  u2_tx_did_fin(wir_r, 1);
                  u2_rl_lose(wir_r, bus);

                  return pro;
                } else {
                  LoomSink; u2_tx_sink_cas(wir_r);
                  pro = _nock_rock_keep(wir_r, bus, zom);
                  u2_tx_rise_cas(wir_r); LoomRise;

                  if ( u2_none == pro ) {
                    return u2_none;
                  }
                  else {
                    u2_noun sav;
                    
                    u2_tx_sys_bit(wir_r, u2_yes);
#if 0
                    sav = u2_ba_save(wir_r, bus, zom, pro);
#else
                    sav = u2_rl_save_cell(wir_r, 0, bus, zom, pro);
#endif
                    u2_tx_sys_bit(wir_r, u2_no);

                    u2_tx_did_pod(wir_r, 1);
                    u2_tx_did_fin(wir_r, 1);

                    u2_rl_lose(wir_r, bus);
#if 0
                    if ( sav != u2_none ) {
                      u2_rl_lose(wir_r, pro);
                      return sav;
                    } else {
                      return pro;
                    }
#else
                    return sav;
#endif
                  }
                }
              }
            }

            case c3__ping: {
              u2_tx_sys_bit(wir_r, u2_yes);
              u2_tx_did_act(wir_r, hod);
              u2_tx_sys_bit(wir_r, u2_no);
              u2_rz(wir_r, hod);

              fol = zom;
              continue;
            }

            case c3__live: {
              u2_flag qox;

              u2_tx_sys_bit(wir_r, u2_yes);
              qox = u2_tx_task_in(wir_r, hod);
              u2_tx_sys_bit(wir_r, u2_no);

              u2_rz(wir_r, hod);
              if ( u2_no == qox ) {
                fol = zom; 
                continue;
              } else {
                LoomSink; u2_tx_sink_cas(wir_r);
                pro = _nock_rock(wir_r, bus, zom);
                u2_tx_rise_cas(wir_r); LoomRise;

                u2_tx_task_out(wir_r);
                return pro;
              }
            }

            case c3__sole: {
              u2_rl_lose(wir_r, hod);
              {
                LoomSink; u2_tx_sink_cas(wir_r);
                pro = _nock_rock(wir_r, bus, zom);
                u2_tx_rise_cas(wir_r); LoomRise;

                if ( u2_none == pro ) {
                  return u2_none;
                }
                else { 
                  u2_noun nuu;

                  u2_tx_sys_bit(wir_r, u2_yes);
                  nuu = u2_rl_uniq(wir_r, pro);
                  u2_tx_sys_bit(wir_r, u2_no);

                  u2_tx_did_fin(wir_r, 1);
                  if ( nuu == pro ) {
                    u2_tx_did_pod(wir_r, 1);
                  }
                  return pro;
                }
              }
            }
          }
        }
      }
    }
  }
}

/* u2_nk_soft():
**
**   Compute `(nock bus fol)`, interpreter first.
*/
u2_weak                                                           //  transfer
u2_nk_soft(u2_wire wir_r,
           u2_noun bus,                                           //  transfer
           u2_noun fol)                                           //  retain
{
  u2_weak pro;
  u2_flag bit;

  bit = u2_tx_sys_bit(wir_r, u2_no);
  c3_assert(bit == u2_yes);
  bit = u2_tx_glu_bit(wir_r, u2_yes);

  LoomSink; u2_tx_sink_cas(wir_r);
  pro = _nock_rock(wir_r, bus, fol);
  u2_tx_rise_cas(wir_r); LoomRise;

  u2_tx_sys_bit(wir_r, u2_yes);
  u2_tx_glu_bit(wir_r, bit);

  return pro;
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
  if ( u2_none == fol ) {
    u2_rl_lose(wir_r, bus);
    return u2_none;
  }
  else if ( u2_none == bus ) {
    return u2_none;
  }
  else {
    return u2_nk_soft(wir_r, bus, fol);
  }
}

/* u2_nk_mong():
**
**   Call with new convention.
*/
u2_weak                                                           //  transfer
u2_nk_mong(u2_wire wir_r,
           u2_weak gat,                                           //  retain
           u2_weak sam)                                           //  transfer
{
  u2_noun cor, xip;

  cor = u2_rc
      (wir_r,
       u2_rc(wir_r, u2_rx(wir_r, u2_sh(u2_sh(gat))), sam),
       u2_rx(wir_r, u2_st(gat)));

  if ( u2_none != (xip = u2_ds_find(wir_r, cor)) ) {
    u2_noun pro = u2_ho_kick(wir_r, xip, cor, u2_cv_noc);

    u2_rz(wir_r, cor);
    return pro;
  }
  else return u2_nk_nock(wir_r, cor, u2_st(gat));
}

/* u2_nk_kick():
**
**   Fire `gat` without changing the sample.
*/
u2_weak                                                           //  transfer
u2_nk_kick(u2_wire wir_r,
           u2_weak gat)                                           //  retain
{
  u2_noun xip;

  if ( u2_none != (xip = u2_ds_find(wir_r, gat)) ) {
    u2_noun pro = u2_ho_kick(wir_r, xip, gat, u2_cv_noc);

    return pro;
  }
  else {
    return u2_nk_nock
      (wir_r,
       u2_rx(wir_r, gat),
       u2_st(gat));
  }
}
