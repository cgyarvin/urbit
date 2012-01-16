/* f/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

extern u2_flag u2_Flag_Profile;

/* _nock_sink(), _nock_rise(): stack tracking.
*/
static __inline__ void
_nock_sink()
{
#if 0
  LoomSink; 
  if ( u2_Flag_Profile ) u2_tx_sink_cas(u2_Wire);
#endif
}
static __inline__ void
_nock_rise()
{
#if 0
  if ( u2_Flag_Profile ) u2_tx_rise_cas(u2_Wire); 
  LoomRise;
#endif
}

static u2_noun
_nock_exit()
{
  u2_tx_sys_bit(u2_Wire, u2_yes);

  return u2_cm_bail(c3__exit);
}

/* _nock_hint(): hint with code, data, subject, formula.
*/
  static u2_noun _nock_cool(u2_noun, u2_noun);
static u2_noun 
_nock_hint(u2_noun zep,
           u2_noun hod,
           u2_noun bus,
           u2_noun nex)
{
  u2_noun pro;

  switch ( zep ) {
    default: u2z(zep); u2z(hod); return _nock_cool(bus, nex);

    case c3__bean: 
    case c3__mean:
    case c3__spot: {
      u2_noun tax = u2k(u2_wire_tax(u2_Wire));
      u2_noun tac = u2nc(zep, hod);

      u2_wire_tax(u2_Wire) = u2nc(tac, tax);
      {
        pro = _nock_cool(bus, nex);
      }
      u2z(u2_wire_tax(u2_Wire));
      u2_wire_tax(u2_Wire) = tax;
      
      return pro;
    }

    case c3__loaf: {
      u2_tx_sys_bit(u2_Wire, u2_yes);
      u2_tx_loaf(u2_Wire, hod);
      u2_tx_sys_bit(u2_Wire, u2_no);

      u2z(hod);
      return _nock_cool(bus, nex);
    }

    case c3__turd: {
      u2_tx_sys_bit(u2_Wire, u2_yes);
      u2_err(u2_Wire, "turd", hod);
      u2_tx_sys_bit(u2_Wire, u2_no);

      u2z(hod);
      return _nock_cool(bus, nex);
    }

    case c3__mine: {
      pro = _nock_cool(bus, nex);
      
      u2_tx_sys_bit(u2_Wire, u2_yes);
      pro = u2_ds_mine(u2_Wire, hod, pro);
      u2_tx_sys_bit(u2_Wire, u2_no);
 
      u2z(hod);
      return pro;
    }

    case c3__fast: {
      pro = _nock_cool(bus, nex);

      {
        u2_noun p_hod, q_hod, r_hod;

        /* XX: translate hod to old clue form.
        */
        if ( u2_no == u2_as_trel(hod, &p_hod, &q_hod, &r_hod) ) {
          u2z(hod);
          return pro;
        }
        else {
          u2_noun xod;

          if ( u2_yes == u2_dust(q_hod) &&
               (_1 == u2_h(q_hod)) &&
               (_0 == u2_t(q_hod)) ) {
            q_hod = 0;
          }
          xod = u2_rt(u2_Wire, u2k(q_hod),
                             u2k(p_hod),
                             u2k(r_hod));
          u2z(hod);
          hod = xod;
        }
        u2_tx_sys_bit(u2_Wire, u2_yes);
        pro = u2_ds_mine(u2_Wire, hod, pro);
        u2_tx_sys_bit(u2_Wire, u2_no);
 
        u2z(hod);
        return pro;
      }
    }

    case c3__memo: {
      u2z(hod);
      {
        pro = u2_rl_find_cell(u2_Wire, 0, bus, nex);

        if ( pro != u2_none ) {
          u2_tx_did_fin(u2_Wire, 1);
          u2z(bus);
          u2z(nex);

          return pro;
        } else {
          pro = _nock_cool(u2k(bus), u2k(nex));
          {
            u2_noun sav;
            
            u2_tx_sys_bit(u2_Wire, u2_yes);
            sav = u2_rl_save_cell(u2_Wire, 0, bus, nex, pro);
            u2_tx_sys_bit(u2_Wire, u2_no);

            u2_tx_did_pod(u2_Wire, 1);
            u2_tx_did_fin(u2_Wire, 1);

            u2z(bus); u2z(nex);
            return sav;
          }
        }
      }
    }

    case c3__ping: {
      u2_tx_sys_bit(u2_Wire, u2_yes);
      u2_tx_did_act(u2_Wire, hod);
      u2_tx_sys_bit(u2_Wire, u2_no);
      u2z(hod);

      return _nock_cool(bus, nex);
    }

    case c3__live: {
      u2_flag qox;

      u2_tx_sys_bit(u2_Wire, u2_yes);
      qox = u2_tx_task_in(u2_Wire, hod);
      u2_tx_sys_bit(u2_Wire, u2_no);

      u2z(hod);
      if ( u2_no == qox ) {
        return _nock_cool(bus, nex);
      } else {
        pro = _nock_cool(bus, nex);

        u2_tx_task_out(u2_Wire);
        return pro;
      }
    }

    case c3__sole: {
      u2z(hod);
      {
        pro = _nock_cool(bus, nex);

        if ( u2_none == pro ) {
          return u2_none;
        }
        else { 
          u2_noun nuu;

          u2_tx_sys_bit(u2_Wire, u2_yes);
          nuu = u2_rl_uniq(u2_Wire, pro);
          u2_tx_sys_bit(u2_Wire, u2_no);

          u2_tx_did_fin(u2_Wire, 1);
          if ( nuu == pro ) {
            u2_tx_did_pod(u2_Wire, 1);
          }
          return pro;
        }
      }
    }
  }
}

/* _nock_cool(): nock, transferring arguments.
*/
static u2_noun
_nock_cool(u2_noun bus,
           u2_noun fol)
{
  u2_noun hib, gal;

  _nock_sink();

  while ( 1 ) {
    u2_cm_poll();
    u2_tx_did_hop(u2_Wire, 1);

    if ( u2_no == u2du(fol) ) {
      return _nock_exit();
    }
    else { 
      hib = u2fh(fol);
      gal = u2ft(fol);
    }

    if ( u2_yes == u2du(hib) ) {
      u2_noun poz, riv;

      poz = _nock_cool(u2k(bus), u2k(hib));
      riv = _nock_cool(bus, u2k(gal));

      u2z(fol);
      _nock_rise();
      return u2_cn_cell(poz, riv);
    }
    else switch ( hib ) {
      default: return _nock_exit();

      case 0: {
        if ( u2_no == u2_cr_ud(gal) ) {
          return _nock_exit();
        }
        else {
          u2_noun pro = u2k(u2at(gal, bus));

          u2z(bus); u2z(fol);
          _nock_rise();
          return pro;
        }
      }
      case 1: {
        u2_noun pro = u2k(gal);

        u2z(bus); u2z(fol);
        _nock_rise();
        return pro;
      }
      c3_assert(!"not reached");

      case 2: {
        if ( u2_no == u2du(gal) ) {
          return u2_cm_bail(c3__exit);
        }
        else {
          u2_noun nex = _nock_cool(u2k(bus), u2k(u2ft(gal)));
          u2_noun seb = _nock_cool(bus, u2k(u2fh(gal)));

          u2z(fol);
          bus = seb;
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 3: {
        u2_noun gof, pro;

        gof = _nock_cool(bus, u2k(gal));
        pro = u2du(gof);

        u2z(gof); u2z(fol);
        _nock_rise();
        return pro;
      }
      c3_assert(!"not reached");

      case 4: {
        u2_noun gof, pro;

        gof = _nock_cool(bus, u2k(gal));
        pro = u2_rl_vint(u2_Wire, gof);

        u2z(gof); u2z(fol);
        _nock_rise();
        return pro;
      }
      c3_assert(!"not reached");

      case 5: {
        if ( u2_no == u2du(gal) ) {
          return _nock_exit();
        }
        else {
          u2_noun dib = _nock_cool(u2k(bus), u2k(u2fh(gal)));
          u2_noun rum = _nock_cool(bus, u2k(u2ft(gal)));
          u2_noun pro = u2_cr_sing(dib, rum);

          u2z(rum); u2z(dib); u2z(fol);
          _nock_rise();
          return pro;
        }
      }
      c3_assert(!"not reached");

      case 6: {
        u2_noun b_gal, c_gal, d_gal;

        u2_cx_trel(gal, &b_gal, &c_gal, &d_gal);
        {
          u2_noun tys = _nock_cool(u2k(bus), u2k(b_gal));
          u2_noun nex;

          if ( 0 == tys ) {
            nex = u2k(c_gal);
          } else if ( 1 == tys ) {
            nex = u2k(d_gal);
          } else return _nock_exit();

          u2z(fol);
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 7: {
        u2_noun b_gal, c_gal;
      
        u2_cx_cell(gal, &b_gal, &c_gal);
        {
          u2_noun bod = _nock_cool(bus, u2k(b_gal));
          u2_noun nex = u2k(c_gal);

          u2z(fol);
          bus = bod;
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 8: {
        u2_noun b_gal, c_gal;
      
        u2_cx_cell(gal, &b_gal, &c_gal);
        {
          u2_noun bod = u2nc(bus, _nock_cool(u2k(bus), u2k(b_gal)));
          u2_noun nex = u2k(c_gal);

          u2z(fol);
          bus = bod;
          fol = nex;
          continue;
        }
      }
      c3_assert(!"not reached");

      case 9: {
        u2_noun b_gal, c_gal;
      
        u2_cx_cell(gal, &b_gal, &c_gal);
        if ( u2_no == u2ud(b_gal) ) {
          return _nock_exit();
        } 
        else {
          u2_noun seb = _nock_cool(bus, u2k(c_gal));
          u2_weak xip;

          u2_tx_sys_bit(u2_Wire, u2_yes);
          xip = u2_ds_find(u2_Wire, seb);

          if ( u2_none != xip ) {
            u2_noun pro = u2_ho_kick(u2_Wire, xip, seb, b_gal);

            u2_tx_sys_bit(u2_Wire, u2_no);
            if ( u2_none == pro ) {
              return _nock_exit();
            } 
            else {
              u2z(seb); u2z(fol);
              _nock_rise();
              return pro;
            }
          }
          else {
            u2_tx_sys_bit(u2_Wire, u2_no);
            {
              u2_noun nex = u2_ct(u2at(b_gal, seb));

              u2z(fol);
              bus = seb;
              fol = nex;
              continue;
            }
          }
        }
      }
      c3_assert(!"not reached");

      case 10: {
        u2_noun p_gal, q_gal;
      
        u2_cx_cell(gal, &p_gal, &q_gal);
        {
          u2_noun zep, hod, nex, pro;

          if ( u2_yes == u2du(p_gal) ) {
            u2_noun b_gal = u2fh(p_gal);
            u2_noun c_gal = u2ft(p_gal);
            u2_noun d_gal = q_gal;

            zep = u2k(b_gal);
            hod = _nock_cool(u2k(bus), u2_ct(c_gal));
            nex = u2_ct(d_gal);
          } 
          else {
            u2_noun b_gal = p_gal;
            u2_noun c_gal = q_gal;

            zep = u2k(b_gal);
            hod = u2_nul;
            nex = u2_ct(c_gal);
          }

          u2_cz(fol);
          _nock_sink();
          pro = _nock_hint(zep, hod, bus, nex);
          _nock_rise();
          _nock_rise();
          return pro; 
        }
      }
      c3_assert(!"not reached");
    }
  }
}

/* u2_cn_nock(): external nock interface. 
*/
u2_noun
u2_cn_nock(u2_noun bus,
           u2_noun fol)
{
  u2_weak pro;
  u2_flag bit;

  bit = u2_tx_sys_bit(u2_Wire, u2_no);
  c3_assert(bit == u2_yes);
  bit = u2_tx_glu_bit(u2_Wire, u2_yes);

  _nock_sink();
  pro = _nock_cool(bus, fol);
  _nock_rise();

  u2_tx_sys_bit(u2_Wire, u2_yes);
  u2_tx_glu_bit(u2_Wire, bit);

  return pro;
}
