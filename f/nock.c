/* f/nock.c
** 
** This file is in the public domain.
*/
#include "all.h"

extern u2_flag u2_Flag_Profile;

/* _nock_pray(): load from namespace.  Crude.
*/
static u2_noun
_nock_pray(u2_noun gof)
{
  u2_cm_push(u2nc(c3__pray, u2k(gof)));
  {
    u2_pryr god_p = u2_hevn_be(u2_pryr, god);
    u2_noun out;

    if ( 0 == god_p ) {
      return u2_cm_bail(c3__exit); 
    }
    out = god_p(gof);
    if ( u2_nul == out ) {
      return u2_cm_bail(c3__exit);
    }
    else if ( (u2_no == u2du(out)) || (u2_nul != u2h(out)) ) {
      return u2_cm_bail(c3__fail);
    }
    else {
      u2_noun pro = u2k(u2t(out));

      u2z(out);
      return pro;
    }
  }
  u2_cm_drop();
}

/* _nock_hint(): hint with code, data, subject, formula.  nock/mock.
*/
  static u2_noun _nock_cool(u2_noun, u2_noun);
  static u2_noun _nock_mool(u2_noun, u2_noun, u2_flag*);

static u2_noun                                                    //  produce
_nock_hint(u2_noun  zep,                                          //  transfer
           u2_noun  hod,                                          //  transfer
           u2_noun  bus,                                          //  transfer
           u2_noun  nex,                                          //  transfer
           u2_flag* pon)
{
  u2_noun pro;

  switch ( zep ) {
    default: u2z(zep); u2z(hod); 
             return pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);

    case c3__bean: 
    case c3__mean:
    case c3__spot: {
      u2_noun tax = u2k(u2_wire_tax(u2_Wire));
      u2_noun tac = u2nc(zep, hod);

      u2_wire_tax(u2_Wire) = u2nc(tac, tax);
      {
        pro = pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);
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
      return pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);
    }

    case c3__turd: {
      u2_tx_sys_bit(u2_Wire, u2_yes);
      u2_err(u2_Wire, "turd", hod);
      u2_tx_sys_bit(u2_Wire, u2_no);

      u2z(hod);
      return pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);
    }

    case c3__mine: {
      pro = pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);
     
      if ( !pon || (u2_no != *pon) ) {
        u2_tx_sys_bit(u2_Wire, u2_yes);
        pro = u2_ds_mine(u2_Wire, hod, pro);
        u2_tx_sys_bit(u2_Wire, u2_no);
      }
      u2z(hod);
      return pro;
    }

    case c3__fast: {
      pro = pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);

      if ( !pon || (u2_no != *pon) ) {
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
      } 
      u2z(hod);
      return pro;
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
          u2_noun sav;
            
          pro = pon ? _nock_mool(u2k(bus), u2k(nex), pon) 
                    : _nock_cool(u2k(bus), u2k(nex));

          if ( !pon || (u2_no != *pon) ) {
            u2_tx_sys_bit(u2_Wire, u2_yes);
            sav = u2_rl_save_cell(u2_Wire, 0, bus, nex, pro);
            u2_tx_sys_bit(u2_Wire, u2_no);

            u2_tx_did_pod(u2_Wire, 1);
            u2_tx_did_fin(u2_Wire, 1);
          }
          else sav = pro;

          u2z(bus); u2z(nex);
          return sav;
        }
      }
    }

    case c3__ping: {
      u2_tx_sys_bit(u2_Wire, u2_yes);
      u2_tx_did_act(u2_Wire, hod);
      u2_tx_sys_bit(u2_Wire, u2_no);
      u2z(hod);

      return pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);
    }

    case c3__live: {
      u2_flag qox;

      u2_tx_sys_bit(u2_Wire, u2_yes);
      qox = u2_tx_task_in(u2_Wire, hod);
      u2_tx_sys_bit(u2_Wire, u2_no);

      u2z(hod);
      if ( u2_no == qox ) {
        return pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);
      } else {
        pro = pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);

        u2_tx_task_out(u2_Wire);
        return pro;
      }
    }

    case c3__sole: {
      u2z(hod);
      {
        pro = pon ? _nock_mool(bus, nex, pon) : _nock_cool(bus, nex);

        if ( u2_none == pro ) {
          return u2_none;
        }
        else if ( !pon || (u2_no != *pon) ) {
          u2_noun nuu;

          u2_tx_sys_bit(u2_Wire, u2_yes);
          nuu = u2_rl_uniq(u2_Wire, pro);
          u2_tx_sys_bit(u2_Wire, u2_no);

          u2_tx_did_fin(u2_Wire, 1);
          if ( nuu == pro ) {
            u2_tx_did_pod(u2_Wire, 1);
          }
        }
        return pro;
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

  while ( 1 ) {
    u2_cm_poll();
    u2_tx_did_hop(u2_Wire, 1);

    if ( u2_no == u2du(fol) ) {
      return u2_cm_bail(c3__exit);
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
      return u2_cn_cell(poz, riv);
    }
    else switch ( hib ) {
      default: return u2_cm_bail(c3__exit);

      case 0: {
        if ( u2_no == u2_cr_ud(gal) ) {
          return u2_cm_bail(c3__exit);
        }
        else {
          u2_noun pro = u2k(u2at(gal, bus));

          u2z(bus); u2z(fol);
          return pro;
        }
      }
      case 1: {
        u2_noun pro = u2k(gal);

        u2z(bus); u2z(fol);
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
        return pro;
      }
      c3_assert(!"not reached");

      case 4: {
        u2_noun gof, pro;

        gof = _nock_cool(bus, u2k(gal));
        pro = u2_rl_vint(u2_Wire, gof);

        u2z(gof); u2z(fol);
        return pro;
      }
      c3_assert(!"not reached");

      case 5: {
        if ( u2_no == u2du(gal) ) {
          return u2_cm_bail(c3__exit);
        }
        else {
          u2_noun dib = _nock_cool(u2k(bus), u2k(u2fh(gal)));
          u2_noun rum = _nock_cool(bus, u2k(u2ft(gal)));
          u2_noun pro = u2_cr_sing(dib, rum);

          u2z(rum); u2z(dib); u2z(fol);
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
          } else return u2_cm_bail(c3__exit);

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
          return u2_cm_bail(c3__exit);
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
              return u2_cm_bail(c3__exit);
            } 
            else {
              u2z(seb); u2z(fol);
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
          pro = _nock_hint(zep, hod, bus, nex, 0);
          return pro; 
        }
      }

      case 11: {
        u2_noun gof, pro;

        gof = _nock_cool(bus, u2k(gal));
        pro = _nock_pray(gof);

        u2z(gof); u2z(fol);

        return pro;
      }
      c3_assert(!"not reached");
    }
  }
}

/* nock_mool(): fast internal mock interface.
*/
u2_noun
_nock_mool(u2_noun  bus, 
           u2_noun  fol,
           u2_flag* pon)
{
  u2_noun hib, gal;

  c3_assert(u2_yes == *pon);

  while ( 1 ) {
    u2_cm_poll();
    u2_tx_did_hop(u2_Wire, 1);

    if ( u2_no == u2du(fol) ) {
      return u2_cm_bail(c3__exit);
    }
    else { 
      hib = u2fh(fol);
      gal = u2ft(fol);
    }

    if ( u2_yes == u2du(hib) ) {
      u2_noun poz, riv;
      u2_flag h_pon = u2_yes, t_pon = u2_yes;

      poz = _nock_mool(u2k(bus), u2k(hib), &h_pon);
      riv = _nock_mool(bus, u2k(gal), &t_pon);
      u2z(fol);

      if ( (u2_no == h_pon) || (u2_no == t_pon) ) {
        u2_noun lal;

        *pon = u2_no;

        if ( u2_yes == h_pon ) {
          u2z(poz); lal = riv;
        } else if ( u2_yes == t_pon ) {
          u2z(riv); lal = poz;
        } else {
          lal = u2_ckb_weld(poz, riv);
        }
        return lal;
      }
      return u2_cn_cell(poz, riv);
    }
    else switch ( hib ) {
      default: return u2_cm_bail(c3__exit);

      case 0: {
        if ( u2_no == u2_cr_ud(gal) ) {
          return u2_cm_bail(c3__exit);
        }
        else {
          u2_noun pro = u2k(u2at(gal, bus));

          u2z(bus); u2z(fol);
          return pro;
        }
      }
      case 1: {
        u2_noun pro = u2k(gal);

        u2z(bus); u2z(fol);
        return pro;
      }
      c3_assert(!"not reached");

      case 2: {
        if ( (u2_no == u2du(gal)) || (u2_no == u2du(u2fh(gal))) ) {
          return u2_cm_bail(c3__exit);
        }
        else {
          u2_noun neb;
          
          neb = _nock_mool(bus, u2k(gal), pon);
          u2z(fol);
          if ( u2_no == *pon ) { return neb; } 

          bus = u2fh(neb);
          fol = u2ft(neb);
          continue;
        }
      }
      c3_assert(!"not reached");

      case 3: {
        u2_noun gof, pro;

        gof = _nock_mool(bus, u2k(gal), pon);
        u2z(fol);
        if ( u2_no == *pon ) { return gof; }

        pro = u2du(gof);
        u2z(gof);

        return pro;
      }
      c3_assert(!"not reached");

      case 4: {
        u2_noun gof, pro;

        gof = _nock_mool(bus, u2k(gal), pon);
        u2z(fol);
        if ( u2_no == *pon ) { return gof; }

        pro = u2_rl_vint(u2_Wire, gof);
        u2z(gof);

        return pro;
      }
      c3_assert(!"not reached");

      case 5: {
        if ( (u2_no == u2du(gal)) || (u2_no == u2du(u2fh(gal))) ) {
          return u2_cm_bail(c3__exit);
        }
        else {
          u2_noun neb, pro;
          
          neb = _nock_mool(bus, u2k(gal), pon);
          u2z(fol);
          if ( u2_no == *pon ) { return neb; } 

          pro = u2_cr_sing(u2fh(neb), u2ft(neb));
          u2z(neb);

          return pro;
        }
      }
      c3_assert(!"not reached");

      case 6: {
        u2_noun b_gal, c_gal, d_gal;

        u2_cx_trel(gal, &b_gal, &c_gal, &d_gal);
        {
          u2_noun tys, nex;
          
          tys = _nock_mool(u2k(bus), u2k(b_gal), pon);
          if ( u2_no == *pon ) { u2z(fol); return tys; }

          if ( 0 == tys ) {
            nex = u2k(c_gal);
          } else if ( 1 == tys ) {
            nex = u2k(d_gal);
          } else return u2_cm_bail(c3__exit);

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
          u2_noun bod, nex;
          
          bod = _nock_mool(bus, u2k(b_gal), pon);
          if ( u2_no == *pon ) { u2z(fol); return bod; }
          
          nex = u2k(c_gal);
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
          u2_noun wib, bod, nex;

          wib = _nock_mool(u2k(bus), u2k(b_gal), pon);
          if ( u2_no == *pon ) { u2z(fol); return wib; }

          bod = u2nc(bus, wib);
          nex = u2k(c_gal);
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
          return u2_cm_bail(c3__exit);
        } 
        else {
          u2_noun seb;
          u2_weak xip;

          seb = _nock_mool(bus, u2k(c_gal), pon);
          u2z(fol); 
          if ( u2_no == *pon ) { return seb; }

          u2_tx_sys_bit(u2_Wire, u2_yes);
          xip = u2_ds_find(u2_Wire, seb);
          u2_tx_sys_bit(u2_Wire, u2_no);

          if ( u2_none != xip ) {
            u2_noun pro;
            
            u2_tx_sys_bit(u2_Wire, u2_yes);
            pro = u2_ho_kicq(u2_Wire, xip, seb, b_gal, pon);
            u2_tx_sys_bit(u2_Wire, u2_no);
            u2z(seb); 

            if ( u2_none == pro ) {
              return u2_cm_bail(c3__exit);
            } 
            else return pro;
          }
          else {
            u2_noun nex = u2k(u2at(b_gal, seb));

            bus = seb;
            fol = nex;
            continue;
          }
        }
      }
      c3_assert(!"not reached");

      case 10: {
        u2_noun p_gal, q_gal;
      
        u2_cx_cell(gal, &p_gal, &q_gal);
        {
          u2_noun zep, hod, nex;

          if ( u2_yes == u2du(p_gal) ) {
            u2_noun b_gal = u2fh(p_gal);
            u2_noun c_gal = u2ft(p_gal);
            u2_noun d_gal = q_gal;

            hod = _nock_mool(u2k(bus), u2_ct(c_gal), pon);
            if ( u2_no == *pon ) { u2z(fol); return hod; } 

            zep = u2k(b_gal);
            nex = u2k(d_gal);
            u2z(fol);
          } 
          else {
            u2_noun b_gal = p_gal;
            u2_noun c_gal = q_gal;

            zep = u2k(b_gal);
            hod = u2_nul;
            nex = u2k(c_gal);

            u2z(fol);
          }

          return _nock_hint(zep, hod, bus, nex, pon);
        }
      }

      case 11: {
        u2_noun gof, pro;

        gof = _nock_cool(bus, u2k(gal));
        pro = _nock_pray(gof);

        u2z(gof); u2z(fol);

        return pro;
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
  u2_noun pro;
  u2_flag bit;

  bit = u2_tx_sys_bit(u2_Wire, u2_no);
  c3_assert(bit == u2_yes);
  bit = u2_tx_glu_bit(u2_Wire, u2_yes);

  pro = _nock_cool(bus, fol);

  u2_tx_sys_bit(u2_Wire, u2_yes);
  u2_tx_glu_bit(u2_Wire, bit);

  return pro;
} 

/* u2_cn_mung():
**
**   Call `(function sample)`.
*/
u2_noun
u2_cn_mung(u2_noun fun,
           u2_noun sam)
{
  u2_noun cor, xip, fol;

  fol = u2k(u2t(fun));
  cor = u2nc(u2nc(u2k(u2h(u2h(fun))), sam), u2k(fol));
  u2z(fun);

  if ( u2_none != (xip = u2_ds_find(u2_Wire, cor)) ) {
    u2_noun pro = u2_ho_kick(u2_Wire, xip, cor, u2_cw_noc);

    u2z(fol); u2z(cor);
    return pro;
  }
  else return u2_cn_nock(cor, fol);
}

/* u2_cn_mock(): logical virtual nock.
*/
u2_noun
u2_cn_mock(u2_noun bus,
           u2_noun fol)
{
  u2_noun pro, res;
  u2_flag bit, pon;

  bit = u2_tx_sys_bit(u2_Wire, u2_no);
  c3_assert(bit == u2_yes);
  bit = u2_tx_glu_bit(u2_Wire, u2_yes);

  pon = u2_yes;
  {
    c3_w poq_w;
    u2_noun how;

    u2_cm_trip();
    poq_w = u2_cm_wind();

    if ( 0 != (how = u2_cm_trap()) ) {
      u2_noun rap = u2_cm_trac();
      u2_cm_done(poq_w);

      //  gc with rap as root
      //  trac logic not correct
      //  lots of mild broken here
      //
      c3_assert(c3__exit == how);
      res = u2nc(2, rap);
    } 
    else {
      pro = _nock_mool(bus, fol, &pon);

      if ( u2_no == pon ) {
        res = u2nc(1, pro);
      } else res = u2nc(0, pro);
    }
  }

  u2_tx_sys_bit(u2_Wire, u2_yes);
  u2_tx_glu_bit(u2_Wire, bit);

  return res;
} 

/*** Deprecated:
***/

/* u2_nk_soft():
**
**   Compute `(nock bus fol)`, interpreter first.
*/
u2_noun                                                           //  transfer
u2_nk_soft(u2_wire wir_r,
           u2_noun bus,                                           //  transfer
           u2_noun fol)                                           //  retain
{
  return u2_cn_nock(bus, u2_ct(fol));
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
    u2_noun pro = u2_ho_kick(wir_r, xip, gat, u2_cw_noc);

    return pro;
  }
  else {
    return u2_nk_nock
      (wir_r,
       u2_rx(wir_r, gat),
       u2_st(gat));
  }
}

/* u2_nk_mong():
**
**   Call with new convention.
*/
u2_noun                                                           //  transfer
u2_nk_mong(u2_wire wir_r,
           u2_noun gat,                                           //  retain
           u2_noun sam)                                           //  transfer
{
  u2_noun cor, xip;

  cor = u2_rc
      (wir_r,
       u2_rc(wir_r, u2_rx(wir_r, u2_sh(u2_sh(gat))), sam),
       u2_rx(wir_r, u2_st(gat)));

  if ( u2_none != (xip = u2_ds_find(wir_r, cor)) ) {
    u2_noun pro = u2_ho_kick(wir_r, xip, cor, u2_cw_noc);

    u2_rz(wir_r, cor);
    return pro;
  }
  else return u2_nk_nock(wir_r, cor, u2_st(gat));
}
