/* j/6/fern.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../Pit.h"

/* test cr*p
*/
  extern int FUN;
  u2_flag                                                         //  stable
  j2_mcx(Pit, ut, fern)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun dox,                              //  retain
                        u2_noun gen);                             //  retain

  static u2_noun
  _furn_in(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_flag
  _furn_x(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_noun
  _farn_in(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun);
  static u2_flag
  _farn_x(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_noun                                                  //  produce
  _fear_turn(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun sut,                                         //  retain
             u2_noun p_sut,                                       //  retain
             u2_noun qq_sut,                                      //  retain
             u2_noun dox,                                         //  retain
             u2_flag vet,                                         //  retain
             u2_noun hag)                                         //  retain
  {
    if ( u2_nul == hag ) {
      return u2_nul;
    } else {
      u2_noun i_hag = u2_h(hag);
      u2_noun pi_hag = u2_h(i_hag);
      u2_noun qi_hag = u2_t(i_hag);
      u2_noun t_hag = u2_t(hag);

      if ( u2_yes == pi_hag ) {
#if 0
        if ( (u2_yes == vet) &&
             (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, qq_sut, p_sut)) )
        {
          return u2_bl_error(wir_r, "fear-hard");
        } else
#endif
        {
          return u2_bc
            (wir_r, u2_bc(wir_r, u2_rx(wir_r, dox),
                                 u2_rx(wir_r, qi_hag)),
                    _fear_turn
                      (wir_r, van, sut, p_sut, qq_sut, dox, vet, t_hag));
        }
      } else {
#if 1
        if ( (u2_yes == vet) &&
             (u2_no == u2_sing(p_sut, qq_sut)) &&
             (u2_no == _furn_x(wir_r, van, sut, dox, qi_hag)) )
        {
          return u2_bl_error(wir_r, "fear-soft");
        } else 
#endif
        {
          return u2_bc
            (wir_r, u2_bc(wir_r, u2_rx(wir_r, sut),
                                 u2_rx(wir_r, qi_hag)),
                    _fear_turn
                      (wir_r, van, sut, p_sut, qq_sut, dox, vet, t_hag));
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, fear)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun hag)                              //  retain
  {
    u2_flag vet = u2_frag(j2_ut_van_vet, van);
    u2_noun p_sut, q_sut;

    if ( u2_no == u2_as_pq(sut, c3__core, &p_sut, &q_sut) ) {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      u2_noun pq_sut, qq_sut, rq_sut;

      u2_bi_trel(wir_r, q_sut, &pq_sut, &qq_sut, &rq_sut);
      {
        u2_noun dox = u2_bt
          (wir_r, c3__core, u2_rx(wir_r, qq_sut), u2_rx(wir_r, q_sut));
        u2_noun ret;

        ret = u2_bc
          (wir_r, c3__hold,
                  _fear_turn
                    (wir_r, van, sut, p_sut, qq_sut, dox, vet, hag));

        u2_rz(wir_r, dox);
        return ret;
      }
    }
  }
  
/* logic (farn)
*/
  static u2_noun
  _farn_in(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_noun
  _farn_flag(u2_wire wir_r)
  {
    return u2_bt(wir_r, c3__fork, u2_bc(wir_r, c3__cube, _0),
                                  u2_bc(wir_r, c3__cube, _1));
  }

  static u2_flag
  _farn_vet(u2_wire wir_r, 
            u2_noun van)
  {
    // u2_flag vet = u2_bn_hook(wir_r, van, "vet");
    u2_flag vet = u2_frag(j2_ut_van_vet, van);

    switch ( vet ) {
      case u2_no: 
      case u2_yes: return vet;
      default: return u2_bl_bail(wir_r, c3__fail); 
    }
  }

  static u2_flag
  _farn_make(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_flag tov,
             u2_noun gen)
  {
    u2_noun von;
    
    switch ( tov ) {
      default: return u2_bl_bail(wir_r, c3__fail);
      case u2_yes: 
        von = u2_rx(wir_r, van); break;
      case u2_no: 
        von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0); break;
    }
    {
      u2_noun hel = _farn_x(wir_r, von, sut, dox, gen);
 
      u2_rz(wir_r, hel);
      u2_rz(wir_r, von);
      return u2_yes;
    }
  }

  static u2_flag
  _farn_boil(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_noun dab)
  {
    if ( (u2_nul == dab) ) {
      return u2_yes;
    }
    else {
      u2_noun n_dab, l_dab, r_dab; 
     
      u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
      if ( u2_no == u2_dust(n_dab) ) {
        return u2_bl_bail(wir_r, c3__fail);
      } 
      else {
        u2_noun qn_dab = u2_t(n_dab);
        u2_noun pqn_dab = u2_t(qn_dab);   //  xx actual wing support
        u2_noun ppqn_dab = u2_h(pqn_dab);
        u2_noun qpqn_dab = u2_t(pqn_dab);

        // _farn_make(wir_r, van, sut, dox, ppqn_dab, qpqn_dab);

        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          return u2_yes;
        }
        else if ( (u2_nul == l_dab) ) {
          return _farn_boil(wir_r, van, sut, dox, r_dab);
        }
        else if ( (u2_nul == r_dab) ) {
          return _farn_boil(wir_r, van, sut, dox, l_dab);
        }
        else {
          return u2_and
            (_farn_boil(wir_r, van, sut, dox, l_dab),
             _farn_boil(wir_r, van, sut, dox, r_dab));
        }
      }
    }
  }

  static u2_noun                                                  //  produce
  _farn_nice(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_noun typ)                                         //  submit
  {
    if ( (u2_yes == _farn_vet(wir_r, van)) &&
         (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, typ)) ) 
    {
      return u2_bl_error(wir_r, "farn-nice");
    }
    else return typ;
  }

  static u2_noun                                                  //  produce
  _farn_crow(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun sut,                                         //  retain
             u2_noun dox,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_atom mel,                                         //  retain
             u2_noun ruf,                                         //  retain
             u2_noun dab)                                         //  retain
  {
    u2_noun dan   = _farn_in(wir_r, van, sut, dox, ruf, c3__noun);
    u2_noun p_toc = 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_h(dan)),
                  u2_bt(wir_r, c3__gold, 
                               u2_rx(wir_r, u2_h(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun q_toc = 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_t(dan)),
                  u2_bt(wir_r, c3__gold, 
                               u2_rx(wir_r, u2_t(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun ret;

    // _farn_boil(wir_r, van, p_toc, q_toc, dab);

    ret = u2_bc
      (wir_r, 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_h(dan)),
                  u2_bt(wir_r, u2_rx(wir_r, mel),
                               u2_rx(wir_r, u2_h(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab)))),
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_t(dan)),
                  u2_bt(wir_r, u2_rx(wir_r, mel),
                               u2_rx(wir_r, u2_t(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab)))));
    u2_rz(wir_r, dan);
    u2_rz(wir_r, p_toc);
    u2_rz(wir_r, q_toc);

    return ret;
  }

  static u2_noun                                                  //  produce
  _farn_loc(u2_wire wir_r,
            u2_noun van,                                          //  retain
            u2_noun loc)                                          //  retain
  {
    u2_noun goo = u2_bn_hook(wir_r, van, "go");
    u2_noun gon = u2_bn_wait(wir_r, goo, loc, "loc");

    u2_rz(wir_r, goo);
    return gon;
  }

  static u2_noun                                                  //  produce
  _farn_in(u2_wire wir_r, 
           u2_noun van,                                           //  retain
           u2_noun sut,                                           //  retain
           u2_noun dox,                                           //  retain
           u2_noun gen,                                           //  retain
           u2_noun gol)                                           //  retain
#if 1
  {
    // u2_bx_used(wir_r);

    return u2_bc
      (wir_r, j2_mcy(Pit, ut, play)(wir_r, van, sut, gen),
              j2_mcy(Pit, ut, play)(wir_r, van, dox, gen));
  }
#else
  {
    u2_noun p_gen, q_gen, r_gen;
    u2_noun ret;

    van = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0);
    // u2_bx_used(wir_r);
    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

      ret = _farn_in(wir_r, van, sut, dox, rex, gol);
      u2_rl_lose(wir_r, rex);

      return ret;
    } 
    else switch ( u2_h(gen) ) {
      default: {
        u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

        if ( u2_yes == u2_sing(rex, gen) ) {
          // u2_err(wir_r, "hrex", u2_h(rex));
          c3_assert(0);
          return u2_bl_error(wir_r, "farn-open");
        }
        ret = _farn_in(wir_r, van, sut, dox, rex, gol);
        u2_rl_lose(wir_r, rex);

        return ret;
      }
 
      case c3__bnld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun fid = _farn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = _farn_in(wir_r, van, u2_h(fid), u2_t(fid), q_gen, gol);

        u2_rz(wir_r, fid);
        
        return ret;
      }
      case c3__csbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hel = _farn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun bol = _farn_flag(wir_r);
        u2_noun ret = u2_bc
          (wir_r, _farn_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, hel);
        
        return ret;
      }
      case c3__csdg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun bol   = _farn_flag(wir_r);
        u2_noun nor   = _farn_in(wir_r, van, sut, dox, p_gen, bol);
        u2_noun p_fex = j2_mcy(Pit, ut, gain)(wir_r, van, sut, p_gen);
        u2_noun q_fex = j2_mcy(Pit, ut, gain)(wir_r, van, dox, p_gen);
        u2_noun ret;

        if ( c3__void == p_fex ) {
          ret = _farn_in(wir_r, van, sut, dox, r_gen, gol);
        }
        else {
          if ( c3__void == q_fex ) {
            return u2_bl_error(wir_r, "farn-lump");
          }
          else {
            u2_noun hiq = _farn_in(wir_r, van, p_fex, q_fex, q_gen, gol);
            u2_noun ran = _farn_in(wir_r, van, sut, dox, r_gen, gol);

            ret = u2_bc
              (wir_r, j2_mby(Pit, fork)(wir_r, u2_h(hiq), u2_h(ran)),
                      j2_mby(Pit, fork)(wir_r, u2_t(hiq), u2_t(ran)));

            u2_rz(wir_r, hiq);
            u2_rz(wir_r, ran);
          }
        }
        u2_rz(wir_r, p_fex);
        u2_rz(wir_r, q_fex);
        u2_rz(wir_r, bol);
        u2_rz(wir_r, nor);

        return ret;
      }
      case c3__dgdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hed = _farn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun tal = _farn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret;
  
        ret = u2_bc(wir_r, 
                    _farn_nice
                      (wir_r, van, gol, 
                              j2_mby(Pit, cell)(wir_r, u2_h(hed), u2_h(tal))),
                    j2_mby(Pit, cell)(wir_r, u2_t(hed), u2_t(tal)));

        u2_rz(wir_r, hed);
        u2_rz(wir_r, tal);

        return ret;
      }
      case c3__dtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun bol   = _farn_flag(wir_r);
        u2_noun p_hel = _farn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun q_hel = _farn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _farn_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, p_hel);
        u2_rz(wir_r, q_hel);

        return ret;
      }
      case c3__dtcs: p_gen = u2_t(gen);
      {
        u2_noun bol = _farn_flag(wir_r);
        u2_noun hel = _farn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _farn_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, hel);
        return ret;
      }
      case c3__dtpd: p_gen = u2_t(gen);
      {
        u2_noun hel = _farn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _farn_nice(wir_r, van, gol, c3__atom), c3__atom);
     
        u2_rz(wir_r, hel);
        return ret;
      }
      case c3__dtsg: p_gen = u2_t(gen);
      {
        u2_noun nik = u2_bc(wir_r, c3__cube, u2_rx(wir_r, p_gen));
        u2_noun ret = u2_bc
          (wir_r, _farn_nice(wir_r, van, gol, u2_rx(wir_r, nik)), nik);

        return ret;
      }
      case c3__dttr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun p_hel = _farn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun q_hel = _farn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _farn_nice(wir_r, van, gol, c3__noun), c3__noun);
     
        u2_rz(wir_r, p_hel);
        u2_rz(wir_r, q_hel);

        return ret;
      }
      case c3__ktbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun vat = _farn_in(wir_r, van, sut, dox, q_gen, gol);

        u2_noun ret = u2_bc
          (wir_r,
           j2_mby(Pit, face)(wir_r, p_gen, u2_h(vat)), 
           j2_mby(Pit, face)(wir_r, p_gen, u2_t(vat)));

        u2_rz(wir_r, vat);
        return ret;
      }
      case c3__ktdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun p_hif = _farn_nice
          (wir_r, van, gol, j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen));
        u2_noun q_hif = j2_mcy(Pit, ut, play)(wir_r, van, dox, p_gen);
        u2_noun hel = _farn_in(wir_r, van, sut, dox, q_gen, p_hif);
        u2_noun ret = u2_bc(wir_r, p_hif, q_hif);

        u2_rz(wir_r, hel);

        return ret;
      }
      case c3__ktpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun zut = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);

        if ( (u2_yes ==_farn_vet(wir_r, van)) &&
             (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, zut)) )
        {
          return u2_bl_error(wir_r, "farn-cool");
        }
        else {
          ret = _farn_in(wir_r, van, sut, dox, q_gen, zut);

          u2_rl_lose(wir_r, zut);
          return ret;
        }
      }
      case c3__ktsg: p_gen = u2_t(gen);
      {
        return _farn_in(wir_r, van, sut, dox, p_gen, gol);
      }
      case c3__mtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      }
#else
      {
        u2_noun von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0);
#if 0
        u2_noun dow = j2_mcy(Pit, ut, mint)(wir_r, van, sut, gol, gen);
        u2_noun h_dow = u2_rx(wir_r, u2_h(dow));
#else
        u2_noun dow = 0;
        u2_noun h_dow = j2_mcy(Pit, ut, play)(wir_r, von, sut, gen);
#endif
#if 0
        u2_noun rux = j2_mcy(Pit, ut, mint)(wir_r, von, dox, gol, gen);
        u2_noun h_rux = u2_rx(wir_r, u2_h(rux));
#else
        u2_noun rux = 0;
        u2_noun h_rux = j2_mcy(Pit, ut, play)(wir_r, von, dox, gen);
#endif
        u2_noun ret;
#if 0
        if ( u2_no == u2_sing(u2_t(dow), u2_t(rux)) ) {
          return u2_bl_error(wir_r, "farn-rage");
        }
#endif
        ret = u2_bc(wir_r, h_dow, h_rux);

        u2_rz(wir_r, von);
        u2_rz(wir_r, dow);
        u2_rz(wir_r, rux);

        return ret;
      }
#endif
      case c3__pmdg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _farn_crow
          (wir_r, van, sut, dox, gol, c3__lead, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmdt: p_gen = u2_t(gen);
      {
        u2_noun ruf = u2_bc(wir_r, u2_nul, _1);

        ret = _farn_crow(wir_r, van, sut, dox, gol, c3__gold, ruf, p_gen);
        u2_rz(wir_r, ruf);

        return ret;
      }
      case c3__pmpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _farn_crow
          (wir_r, van, sut, dox, gol, c3__iron, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__sgld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _farn_in(wir_r, van, sut, dox, q_gen, gol);
      }
      case c3__zpbn: p_gen = u2_t(gen);
      {
        return u2_bc(wir_r, c3__noun, c3__noun);
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ret;
#if 0
        u2_bl_push(wir_r, u2_bc(wir_r, c3__mean, _farn_loc(wir_r, van, p_gen)));
        {
          ret = _farn_in(wir_r, van, sut, dox, q_gen, gol);
        }
        u2_bl_drop(wir_r);
#else
        ret = _farn_in(wir_r, van, sut, dox, q_gen, gol);
#endif
        return ret;
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        return _farn_in(wir_r, van, sut, dox, p_gen, gol);
      }
      case c3__zpzp:
      {
        return u2_bc(wir_r, c3__void, c3__void);
      }
    }
  } 
#endif

  int FAR;
  static u2_flag                                                  //  stable
  _farn_x(u2_wire wir_r, 
          u2_noun van,                              //  retain
          u2_noun sut,                              //  retain
          u2_noun dox,                              //  retain
          u2_noun gen)                              //  retain
  {
    u2_noun gol = c3__noun;
    u2_noun hel;

    c3_assert(FAR==0);
    FAR=1;
    hel = _farn_in(wir_r, van, sut, dox, gen, gol);
    FAR=0;

    u2_rz(wir_r, hel);
    return u2_yes;

    hel = _farn_in(wir_r, van, sut, dox, gen, gol);
    u2_rz(wir_r, hel);

    hel = _farn_in(wir_r, van, sut, dox, gen, gol);
    u2_rz(wir_r, hel);

    return u2_yes;
  }

/* logic (furn)
*/
  static u2_noun
  _furn_in(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_noun
  _furn_flag(u2_wire wir_r)
  {
    return u2_bt(wir_r, c3__fork, u2_bc(wir_r, c3__cube, _0),
                                  u2_bc(wir_r, c3__cube, _1));
  }

  static u2_flag
  _furn_vet(u2_wire wir_r, 
            u2_noun van)
  {
    // u2_flag vet = u2_bn_hook(wir_r, van, "vet");
    u2_flag vet = u2_frag(j2_ut_van_vet, van);

    switch ( vet ) {
      case u2_no: 
      case u2_yes: return vet;
      default: return u2_bl_bail(wir_r, c3__fail); 
    }
  }

  static u2_flag
  _furn_make(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_flag tov,
             u2_noun gen)
  {
    u2_noun von;
    
    switch ( tov ) {
      default: return u2_bl_bail(wir_r, c3__fail);
      case u2_yes: 
        von = u2_rx(wir_r, van); break;
      case u2_no: 
        von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0); break;
    }
    {
      u2_noun hel = _farn_x(wir_r, von, sut, dox, gen);
 
      u2_rz(wir_r, hel);
      u2_rz(wir_r, von);
      return u2_yes;
    }
  }

  static u2_flag
  _furn_boil(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_noun dab)
  {
    if ( (u2_nul == dab) ) {
      return u2_yes;
    }
    else {
      u2_noun n_dab, l_dab, r_dab; 
     
      u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
      if ( u2_no == u2_dust(n_dab) ) {
        return u2_bl_bail(wir_r, c3__fail);
      } 
      else {
        u2_noun qn_dab = u2_t(n_dab);
        u2_noun pqn_dab = u2_t(qn_dab);   //  xx actual wing support
        u2_noun ppqn_dab = u2_h(pqn_dab);
        u2_noun qpqn_dab = u2_t(pqn_dab);

        _furn_make(wir_r, van, sut, dox, ppqn_dab, qpqn_dab);

        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          return u2_yes;
        }
        else if ( (u2_nul == l_dab) ) {
          return _furn_boil(wir_r, van, sut, dox, r_dab);
        }
        else if ( (u2_nul == r_dab) ) {
          return _furn_boil(wir_r, van, sut, dox, l_dab);
        }
        else {
          return u2_and
            (_furn_boil(wir_r, van, sut, dox, l_dab),
             _furn_boil(wir_r, van, sut, dox, r_dab));
        }
      }
    }
  }

  static u2_noun                                                  //  produce
  _furn_nice(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_noun typ)                                         //  submit
  {
    if ( (u2_yes == _furn_vet(wir_r, van)) &&
         (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, typ)) ) 
    {
      return u2_bl_error(wir_r, "furn-nice");
    }
    else return typ;
  }

  static u2_noun                                                  //  produce
  _furn_crow(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun sut,                                         //  retain
             u2_noun dox,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_atom mel,                                         //  retain
             u2_noun ruf,                                         //  retain
             u2_noun dab)                                         //  retain
  {
    u2_noun dan   = _furn_in(wir_r, van, sut, dox, ruf, c3__noun);
    u2_noun p_toc = 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_h(dan)),
                  u2_bt(wir_r, c3__gold, 
                               u2_rx(wir_r, u2_h(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun q_toc = 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_t(dan)),
                  u2_bt(wir_r, c3__gold, 
                               u2_rx(wir_r, u2_t(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun ret;

    _furn_boil(wir_r, van, p_toc, q_toc, dab);

    ret = u2_bc
      (wir_r, 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_h(dan)),
                  u2_bt(wir_r, u2_rx(wir_r, mel),
                               u2_rx(wir_r, u2_h(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab)))),
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_t(dan)),
                  u2_bt(wir_r, u2_rx(wir_r, mel),
                               u2_rx(wir_r, u2_t(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab)))));
    u2_rz(wir_r, dan);
    u2_rz(wir_r, p_toc);
    u2_rz(wir_r, q_toc);

    return ret;
  }

  static u2_noun                                                  //  produce
  _furn_loc(u2_wire wir_r,
            u2_noun van,                                          //  retain
            u2_noun loc)                                          //  retain
  {
    u2_noun goo = u2_bn_hook(wir_r, van, "go");
    u2_noun gon = u2_bn_wait(wir_r, goo, loc, "loc");

    u2_rz(wir_r, goo);
    return gon;
  }

  static u2_noun                                                  //  produce
  _furn_in(u2_wire wir_r, 
           u2_noun van,                                           //  retain
           u2_noun sut,                                           //  retain
           u2_noun dox,                                           //  retain
           u2_noun gen,                                           //  retain
           u2_noun gol)                                           //  retain
  {
    u2_noun p_gen, q_gen, r_gen;
    u2_noun ret;

    // u2_bx_used(wir_r);
    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

      ret = _furn_in(wir_r, van, sut, dox, rex, gol);
      u2_rl_lose(wir_r, rex);

      return ret;
    } 
    else switch ( u2_h(gen) ) {
      default: {
        u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

        if ( u2_yes == u2_sing(rex, gen) ) {
          // u2_err(wir_r, "hrex", u2_h(rex));
          c3_assert(0);
          return u2_bl_error(wir_r, "furn-open");
        }
        ret = _furn_in(wir_r, van, sut, dox, rex, gol);
        u2_rl_lose(wir_r, rex);

        return ret;
      }
 
      case c3__bnld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun fid = _furn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = _furn_in(wir_r, van, u2_h(fid), u2_t(fid), q_gen, gol);

        u2_rz(wir_r, fid);
        
        return ret;
      }
      case c3__csbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hel = _furn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun bol = _furn_flag(wir_r);
        u2_noun ret = u2_bc
          (wir_r, _furn_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, hel);
        
        return ret;
      }
      case c3__csdg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun bol   = _furn_flag(wir_r);
        u2_noun nor   = _furn_in(wir_r, van, sut, dox, p_gen, bol);
        u2_noun p_fex = j2_mcy(Pit, ut, gain)(wir_r, van, sut, p_gen);
        u2_noun q_fex = j2_mcy(Pit, ut, gain)(wir_r, van, dox, p_gen);
        u2_noun ret;

        if ( c3__void == p_fex ) {
          ret = _furn_in(wir_r, van, sut, dox, r_gen, gol);
        }
        else {
          if ( c3__void == q_fex ) {
            return u2_bl_error(wir_r, "furn-lump");
          }
          else {
            u2_noun hiq = _furn_in(wir_r, van, p_fex, q_fex, q_gen, gol);
            u2_noun ran = _furn_in(wir_r, van, sut, dox, r_gen, gol);

            ret = u2_bc
              (wir_r, j2_mby(Pit, fork)(wir_r, u2_h(hiq), u2_h(ran)),
                      j2_mby(Pit, fork)(wir_r, u2_t(hiq), u2_t(ran)));

            u2_rz(wir_r, hiq);
            u2_rz(wir_r, ran);
          }
        }
        u2_rz(wir_r, p_fex);
        u2_rz(wir_r, q_fex);
        u2_rz(wir_r, bol);
        u2_rz(wir_r, nor);

        return ret;
      }
      case c3__dgdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hed = _furn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun tal = _furn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret;
  
        ret = u2_bc(wir_r, 
                    _furn_nice
                      (wir_r, van, gol, 
                              j2_mby(Pit, cell)(wir_r, u2_h(hed), u2_h(tal))),
                    j2_mby(Pit, cell)(wir_r, u2_t(hed), u2_t(tal)));

        u2_rz(wir_r, hed);
        u2_rz(wir_r, tal);

        return ret;
      }
      case c3__dtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun bol   = _furn_flag(wir_r);
        u2_noun p_hel = _furn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun q_hel = _furn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _furn_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, p_hel);
        u2_rz(wir_r, q_hel);

        return ret;
      }
      case c3__dtcs: p_gen = u2_t(gen);
      {
        u2_noun bol = _furn_flag(wir_r);
        u2_noun hel = _furn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _furn_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, hel);
        return ret;
      }
      case c3__dtpd: p_gen = u2_t(gen);
      {
        u2_noun hel = _furn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _furn_nice(wir_r, van, gol, c3__atom), c3__atom);
     
        u2_rz(wir_r, hel);
        return ret;
      }
      case c3__dtsg: p_gen = u2_t(gen);
      {
        u2_noun nik = u2_bc(wir_r, c3__cube, u2_rx(wir_r, p_gen));
        u2_noun ret = u2_bc
          (wir_r, _furn_nice(wir_r, van, gol, u2_rx(wir_r, nik)), nik);

        return ret;
      }
      case c3__dttr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun p_hel = _furn_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun q_hel = _furn_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _furn_nice(wir_r, van, gol, c3__noun), c3__noun);
     
        u2_rz(wir_r, p_hel);
        u2_rz(wir_r, q_hel);

        return ret;
      }
      case c3__ktbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun vat = _furn_in(wir_r, van, sut, dox, q_gen, gol);

        u2_noun ret = u2_bc
          (wir_r,
           j2_mby(Pit, face)(wir_r, p_gen, u2_h(vat)), 
           j2_mby(Pit, face)(wir_r, p_gen, u2_t(vat)));

        u2_rz(wir_r, vat);
        return ret;
      }
      case c3__ktdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun p_hif = _furn_nice
          (wir_r, van, gol, j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen));
        u2_noun q_hif = j2_mcy(Pit, ut, play)(wir_r, van, dox, p_gen);
        u2_noun hel = _furn_in(wir_r, van, sut, dox, q_gen, p_hif);
        u2_noun ret = u2_bc(wir_r, p_hif, q_hif);

        u2_rz(wir_r, hel);

        return ret;
      }
      case c3__ktpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun zut = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);

        if ( (u2_yes ==_furn_vet(wir_r, van)) &&
             (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, zut)) )
        {
          return u2_bl_error(wir_r, "furn-cool");
        }
        else {
          ret = _furn_in(wir_r, van, sut, dox, q_gen, zut);

          u2_rl_lose(wir_r, zut);
          return ret;
        }
      }
      case c3__ktsg: p_gen = u2_t(gen);
      {
        return _furn_in(wir_r, van, sut, dox, p_gen, gol);
      }
      case c3__mtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
#if 0
      {
        u2_noun von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0);
        u2_noun p_lar = j2_mcy(Pit, ut, seek)(wir_r, van, sut, c3__read, p_gen);
        u2_noun q_lar = j2_mcy(Pit, ut, seek)(wir_r, von, dox, c3__read, p_gen);
        u2_noun pp_lar, qp_lar, rp_lar;
        u2_noun pq_lar, qq_lar, rq_lar;
        u2_noun ret;

        u2_bi_trel(wir_r, p_lar, &pp_lar, &qp_lar, &rp_lar);
        u2_bi_trel(wir_r, q_lar, &pq_lar, &qq_lar, &rq_lar);

        if ( u2_no == u2_sing(pp_lar, pq_lar) ) {
          return u2_bl_error(wir_r, "furn-bonk");
        } else {
          u2_noun p_wix = j2_mcy(Pit, ut, edit)(wir_r, van, sut, rp_lar, q_gen);
          u2_noun q_wix = j2_mcy(Pit, ut, edit)(wir_r, von, dox, rq_lar, q_gen);

          if ( u2_nul == qp_lar ) {
            if ( u2_nul == qq_lar ) {
              ret = u2_bc(wir_r, p_wix, q_wix);
            }
            else return u2_bl_error(wir_r, "furn-bonk");
          }
          else if ( u2_nul == qq_lar ) {
            return u2_bl_error(wir_r, "furn-bonk");
          }
          else {
            u2_noun p_fer = j2_mcy(Pit, ut, fear)
              (wir_r, van, p_wix, u2_t(u2_t(qp_lar)));
            u2_noun q_fer = j2_mcy(Pit, ut, fire)
              (wir_r, von, q_wix, u2_t(u2_t(qq_lar)));

            u2_rz(wir_r, p_wix);
            u2_rz(wir_r, q_wix);
            ret = u2_bc(wir_r, p_fer, q_fer);
          }
          u2_rz(wir_r, p_lar); u2_rz(wir_r, q_lar);
          u2_rz(wir_r, von);
          return ret;
        }
      }
#else
      {
        u2_noun von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0);
#if 0
        u2_noun dow = j2_mcy(Pit, ut, mint)(wir_r, van, sut, gol, gen);
        u2_noun h_dow = u2_rx(wir_r, u2_h(dow));
#else
        u2_noun dow = 0;
        u2_noun h_dow = j2_mcy(Pit, ut, play)(wir_r, von, sut, gen);
#endif
#if 0
        u2_noun rux = j2_mcy(Pit, ut, mint)(wir_r, von, dox, gol, gen);
        u2_noun h_rux = u2_rx(wir_r, u2_h(rux));
#else
        u2_noun rux = 0;
        u2_noun h_rux = j2_mcy(Pit, ut, play)(wir_r, van, dox, gen);
#endif
        u2_noun ret;
#if 0
        if ( u2_no == u2_sing(u2_t(dow), u2_t(rux)) ) {
          return u2_bl_error(wir_r, "furn-rage");
        }
#endif
        ret = u2_bc(wir_r, h_dow, h_rux);

        u2_rz(wir_r, von);
        u2_rz(wir_r, dow);
        u2_rz(wir_r, rux);

        return ret;
      }
#endif
      case c3__pmdg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _furn_crow
          (wir_r, van, sut, dox, gol, c3__lead, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmdt: p_gen = u2_t(gen);
      {
        u2_noun ruf = u2_bc(wir_r, u2_nul, _1);

        ret = _furn_crow(wir_r, van, sut, dox, gol, c3__gold, ruf, p_gen);
        u2_rz(wir_r, ruf);

        return ret;
      }
      case c3__pmpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _furn_crow
          (wir_r, van, sut, dox, gol, c3__iron, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__sgld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _furn_in(wir_r, van, sut, dox, q_gen, gol);
      }
      case c3__zpbn: p_gen = u2_t(gen);
      {
        return u2_bc(wir_r, c3__noun, c3__noun);
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ret;
#if 0
        u2_bl_push(wir_r, u2_bc(wir_r, c3__mean, _furn_loc(wir_r, van, p_gen)));
        {
          ret = _furn_in(wir_r, van, sut, dox, q_gen, gol);
        }
        u2_bl_drop(wir_r);
#else
        ret = _furn_in(wir_r, van, sut, dox, q_gen, gol);
#endif
        return ret;
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        return _furn_in(wir_r, van, sut, dox, p_gen, gol);
      }
      case c3__zpzp:
      {
        return u2_bc(wir_r, c3__void, c3__void);
      }
    }
  } 

  static u2_flag                                                  //  stable
  _furn_x(u2_wire wir_r, 
          u2_noun van,                              //  retain
          u2_noun sut,                              //  retain
          u2_noun dox,                              //  retain
          u2_noun gen)                              //  retain
  {
    u2_noun gol = c3__noun;
    u2_noun hel;

    FUN++;
    if ( FUN > 2 ) {
      fprintf(stderr, "FUN %d in", FUN);
    }
    hel = _furn_in(wir_r, van, sut, dox, gen, gol);
    if ( FUN > 2 ) {
      fprintf(stderr, " out\n");
    }
    FUN--;

    u2_rz(wir_r, hel);
    return u2_yes;
  }

/* logic (fern)
*/
  static u2_noun
  _fern_in(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_noun
  _fern_flag(u2_wire wir_r)
  {
    return u2_bt(wir_r, c3__fork, u2_bc(wir_r, c3__cube, _0),
                                  u2_bc(wir_r, c3__cube, _1));
  }

  static u2_flag
  _fern_vet(u2_wire wir_r, 
            u2_noun van)
  {
    // u2_flag vet = u2_bn_hook(wir_r, van, "vet");
    u2_flag vet = u2_frag(j2_ut_van_vet, van);

    switch ( vet ) {
      case u2_no: 
      case u2_yes: return vet;
      default: return u2_bl_bail(wir_r, c3__fail); 
    }
  }

  static u2_flag
  _fern_make(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_flag tov,
             u2_noun gen)
  {
    u2_noun von;
    
    switch ( tov ) {
      default: return u2_bl_bail(wir_r, c3__fail);
      case u2_yes: 
        von = u2_rx(wir_r, van); break;
      case u2_no: 
        von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0); break;
    }
    {
      u2_noun hel = j2_mcy(Pit, ut, fern)(wir_r, von, sut, dox, gen);
 
      u2_rz(wir_r, hel);
      u2_rz(wir_r, von);
      return u2_yes;
    }
  }

  static u2_flag
  _fern_boil(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_noun dab)
  {
    if ( (u2_nul == dab) ) {
      return u2_yes;
    }
    else {
      u2_noun n_dab, l_dab, r_dab; 
     
      u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
      if ( u2_no == u2_dust(n_dab) ) {
        return u2_bl_bail(wir_r, c3__fail);
      } 
      else {
        u2_noun qn_dab = u2_t(n_dab);
        u2_noun pqn_dab = u2_t(qn_dab);   //  XX actual wing support
        u2_noun ppqn_dab = u2_h(pqn_dab);
        u2_noun qpqn_dab = u2_t(pqn_dab);

        _fern_make(wir_r, van, sut, dox, ppqn_dab, qpqn_dab);

        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          return u2_yes;
        }
        else if ( (u2_nul == l_dab) ) {
          return _fern_boil(wir_r, van, sut, dox, r_dab);
        }
        else if ( (u2_nul == r_dab) ) {
          return _fern_boil(wir_r, van, sut, dox, l_dab);
        }
        else {
          return u2_and
            (_fern_boil(wir_r, van, sut, dox, l_dab),
             _fern_boil(wir_r, van, sut, dox, r_dab));
        }
      }
    }
  }

  static u2_noun                                                  //  produce
  _fern_nice(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_noun typ)                                         //  submit
  {
    if ( (u2_yes == _fern_vet(wir_r, van)) &&
         (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, typ)) ) 
    {
      return u2_bl_error(wir_r, "fern-nice");
    }
    else return typ;
  }

  static u2_noun                                                  //  produce
  _fern_crow(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun sut,                                         //  retain
             u2_noun dox,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_atom mel,                                         //  retain
             u2_noun ruf,                                         //  retain
             u2_noun dab)                                         //  retain
  {
    u2_noun dan   = _fern_in(wir_r, van, sut, dox, ruf, c3__noun);
    u2_noun p_toc = 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_h(dan)),
                  u2_bt(wir_r, c3__gold, 
                               u2_rx(wir_r, u2_h(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun q_toc = 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_t(dan)),
                  u2_bt(wir_r, c3__gold, 
                               u2_rx(wir_r, u2_t(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun ret;

    _fern_boil(wir_r, van, p_toc, q_toc, dab);

    ret = u2_bc
      (wir_r, 
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_h(dan)),
                  u2_bt(wir_r, u2_rx(wir_r, mel),
                               u2_rx(wir_r, u2_h(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab)))),
       j2_mby(Pit, core)
          (wir_r, u2_rx(wir_r, u2_t(dan)),
                  u2_bt(wir_r, u2_rx(wir_r, mel),
                               u2_rx(wir_r, u2_t(dan)), 
                               u2_bc(wir_r, u2_nul, u2_rx(wir_r, dab)))));
    u2_rz(wir_r, dan);
    u2_rz(wir_r, p_toc);
    u2_rz(wir_r, q_toc);

    return ret;
  }

  static u2_noun                                                  //  produce
  _fern_loc(u2_wire wir_r,
            u2_noun van,                                          //  retain
            u2_noun loc)                                          //  retain
  {
    u2_noun goo = u2_bn_hook(wir_r, van, "go");
    u2_noun gon = u2_bn_wait(wir_r, goo, loc, "loc");

    u2_rz(wir_r, goo);
    return gon;
  }

  static u2_noun                                                  //  produce
  _fern_in(u2_wire wir_r, 
           u2_noun van,                                           //  retain
           u2_noun sut,                                           //  retain
           u2_noun dox,                                           //  retain
           u2_noun gen,                                           //  retain
           u2_noun gol)                                           //  retain
  {
    u2_noun p_gen, q_gen, r_gen;
    u2_noun ret;

    // u2_bx_used(wir_r);
    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

      ret = _fern_in(wir_r, van, sut, dox, rex, gol);
      u2_rl_lose(wir_r, rex);

      return ret;
    } 
    else switch ( u2_h(gen) ) {
      default: {
        u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

        if ( u2_yes == u2_sing(rex, gen) ) {
          // u2_err(wir_r, "hrex", u2_h(rex));
          c3_assert(0);
          return u2_bl_error(wir_r, "fern-open");
        }
        ret = _fern_in(wir_r, van, sut, dox, rex, gol);
        u2_rl_lose(wir_r, rex);

        return ret;
      }
 
      case c3__bnld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun fid = _fern_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = _fern_in(wir_r, van, u2_h(fid), u2_t(fid), q_gen, gol);

        u2_rz(wir_r, fid);
        
        return ret;
      }
      case c3__csbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hel = _fern_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun bol = _fern_flag(wir_r);
        u2_noun ret = u2_bc
          (wir_r, _fern_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, hel);
        
        return ret;
      }
      case c3__csdg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun bol   = _fern_flag(wir_r);
        u2_noun nor   = _fern_in(wir_r, van, sut, dox, p_gen, bol);
        u2_noun p_fex = j2_mcy(Pit, ut, gain)(wir_r, van, sut, p_gen);
        u2_noun q_fex = j2_mcy(Pit, ut, gain)(wir_r, van, dox, p_gen);
        u2_noun ret;

        if ( c3__void == p_fex ) {
          ret = _fern_in(wir_r, van, sut, dox, r_gen, gol);
        }
        else {
          if ( c3__void == q_fex ) {
            return u2_bl_error(wir_r, "fern-lump");
          }
          else {
            u2_noun hiq = _fern_in(wir_r, van, p_fex, q_fex, q_gen, gol);
            u2_noun ran = _fern_in(wir_r, van, sut, dox, r_gen, gol);

            ret = u2_bc
              (wir_r, j2_mby(Pit, fork)(wir_r, u2_h(hiq), u2_h(ran)),
                      j2_mby(Pit, fork)(wir_r, u2_t(hiq), u2_t(ran)));

            u2_rz(wir_r, hiq);
            u2_rz(wir_r, ran);
          }
        }
        u2_rz(wir_r, p_fex);
        u2_rz(wir_r, q_fex);
        u2_rz(wir_r, bol);
        u2_rz(wir_r, nor);

        return ret;
      }
      case c3__dgdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hed = _fern_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun tal = _fern_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret;
  
        ret = u2_bc(wir_r, 
                    _fern_nice
                      (wir_r, van, gol, 
                              j2_mby(Pit, cell)(wir_r, u2_h(hed), u2_h(tal))),
                    j2_mby(Pit, cell)(wir_r, u2_t(hed), u2_t(tal)));

        u2_rz(wir_r, hed);
        u2_rz(wir_r, tal);

        return ret;
      }
      case c3__dtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun bol   = _fern_flag(wir_r);
        u2_noun p_hel = _fern_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun q_hel = _fern_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _fern_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, p_hel);
        u2_rz(wir_r, q_hel);

        return ret;
      }
      case c3__dtcs: p_gen = u2_t(gen);
      {
        u2_noun bol = _fern_flag(wir_r);
        u2_noun hel = _fern_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _fern_nice(wir_r, van, gol, u2_rx(wir_r, bol)), bol);
     
        u2_rz(wir_r, hel);
        return ret;
      }
      case c3__dtpd: p_gen = u2_t(gen);
      {
        u2_noun hel = _fern_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _fern_nice(wir_r, van, gol, c3__atom), c3__atom);
     
        u2_rz(wir_r, hel);
        return ret;
      }
      case c3__dtsg: p_gen = u2_t(gen);
      {
        u2_noun nik = u2_bc(wir_r, c3__cube, u2_rx(wir_r, p_gen));
        u2_noun ret = u2_bc
          (wir_r, _fern_nice(wir_r, van, gol, u2_rx(wir_r, nik)), nik);

        return ret;
      }
      case c3__dttr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun p_hel = _fern_in(wir_r, van, sut, dox, p_gen, c3__noun);
        u2_noun q_hel = _fern_in(wir_r, van, sut, dox, q_gen, c3__noun);
        u2_noun ret = u2_bc
          (wir_r, _fern_nice(wir_r, van, gol, c3__noun), c3__noun);
     
        u2_rz(wir_r, p_hel);
        u2_rz(wir_r, q_hel);

        return ret;
      }
      case c3__ktbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun vat = _fern_in(wir_r, van, sut, dox, q_gen, gol);

        u2_noun ret = u2_bc
          (wir_r,
           j2_mby(Pit, face)(wir_r, p_gen, u2_h(vat)), 
           j2_mby(Pit, face)(wir_r, p_gen, u2_t(vat)));

        u2_rz(wir_r, vat);
        return ret;
      }
      case c3__ktdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun p_hif = _fern_nice
          (wir_r, van, gol, j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen));
        u2_noun q_hif = j2_mcy(Pit, ut, play)(wir_r, van, dox, p_gen);
        u2_noun hel = _fern_in(wir_r, van, sut, dox, q_gen, p_hif);
        u2_noun ret = u2_bc(wir_r, p_hif, q_hif);

        u2_rz(wir_r, hel);

        return ret;
      }
      case c3__ktpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun zut = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);

        if ( (u2_yes ==_fern_vet(wir_r, van)) &&
             (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, zut)) )
        {
          return u2_bl_error(wir_r, "fern-cool");
        }
        else {
          ret = _fern_in(wir_r, van, sut, dox, q_gen, zut);

          u2_rl_lose(wir_r, zut);
          return ret;
        }
      }
      case c3__ktsg: p_gen = u2_t(gen);
      {
        return _fern_in(wir_r, van, sut, dox, p_gen, gol);
      }
      case c3__mtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0);
        u2_noun p_lar = j2_mcy(Pit, ut, seek)(wir_r, van, sut, c3__read, p_gen);
        u2_noun q_lar = j2_mcy(Pit, ut, seek)(wir_r, von, dox, c3__read, p_gen);
        u2_noun pp_lar, qp_lar, rp_lar;
        u2_noun pq_lar, qq_lar, rq_lar;
        u2_noun ret;

        u2_bi_trel(wir_r, p_lar, &pp_lar, &qp_lar, &rp_lar);
        u2_bi_trel(wir_r, q_lar, &pq_lar, &qq_lar, &rq_lar);

        if ( u2_no == u2_sing(pp_lar, pq_lar) ) {
          return u2_bl_error(wir_r, "fern-bonk");
        } else {
          u2_noun p_wix = j2_mcy(Pit, ut, edit)(wir_r, van, sut, rp_lar, q_gen);
          u2_noun q_wix = j2_mcy(Pit, ut, edit)(wir_r, von, dox, rq_lar, q_gen);

          if ( u2_nul == qp_lar ) {
            if ( u2_nul == qq_lar ) {
              ret = u2_bc(wir_r, p_wix, q_wix);
            }
            else return u2_bl_error(wir_r, "fern-bonk");
          }
          else if ( u2_nul == qq_lar ) {
            return u2_bl_error(wir_r, "fern-bonk");
          }
          else {
            u2_noun p_fer = j2_mcy(Pit, ut, fear)
              (wir_r, van, p_wix, u2_t(u2_t(qp_lar)));
            u2_noun q_fer = j2_mcy(Pit, ut, fire)
              (wir_r, von, q_wix, u2_t(u2_t(qq_lar)));

            u2_rz(wir_r, p_wix);
            u2_rz(wir_r, q_wix);
            ret = u2_bc(wir_r, p_fer, q_fer);
          }
          u2_rz(wir_r, p_lar); u2_rz(wir_r, q_lar);
          u2_rz(wir_r, von);
          return ret;
        }
      }
#if 0
      {
#if 0
        u2_noun dow = j2_mcy(Pit, ut, mint)(wir_r, van, sut, gol, gen);
        u2_noun h_dow = u2_rx(wir_r, u2_h(dow));
#else
        u2_noun dow = 0;
        u2_noun h_dow = j2_mcy(Pit, ut, play)(wir_r, van, sut, gen);
#endif
#if 1
        u2_noun rux = j2_mcy(Pit, ut, mint)(wir_r, von, dox, gol, gen);
        u2_noun h_rux = u2_rx(wir_r, u2_h(rux));
#else
        u2_noun rux = 0;
        u2_noun h_rux = j2_mcy(Pit, ut, play)(wir_r, van, dox, gen);
#endif
        u2_noun ret;
#if 0
        if ( u2_no == u2_sing(u2_t(dow), u2_t(rux)) ) {
          return u2_bl_error(wir_r, "fern-rage");
        }
#endif
        ret = u2_bc(wir_r, h_dow, h_rux);

        u2_rz(wir_r, von);
        u2_rz(wir_r, dow);
        u2_rz(wir_r, rux);

        return ret;
      }
#endif
      case c3__pmdg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _fern_crow
          (wir_r, van, sut, dox, gol, c3__lead, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmdt: p_gen = u2_t(gen);
      {
        u2_noun ruf = u2_bc(wir_r, u2_nul, _1);

        ret = _fern_crow(wir_r, van, sut, dox, gol, c3__gold, ruf, p_gen);
        u2_rz(wir_r, ruf);

        return ret;
      }
      case c3__pmpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _fern_crow
          (wir_r, van, sut, dox, gol, c3__iron, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__sgld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _fern_in(wir_r, van, sut, dox, q_gen, gol);
      }
      case c3__zpbn: p_gen = u2_t(gen);
      {
        return u2_bc(wir_r, c3__noun, c3__noun);
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ret;
#if 0
        u2_bl_push(wir_r, u2_bc(wir_r, c3__mean, _fern_loc(wir_r, van, p_gen)));
        {
          ret = _fern_in(wir_r, van, sut, dox, q_gen, gol);
        }
        u2_bl_drop(wir_r);
#else
        ret = _fern_in(wir_r, van, sut, dox, q_gen, gol);
#endif
        return ret;
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        return _fern_in(wir_r, van, sut, dox, p_gen, gol);
      }
      case c3__zpzp:
      {
        return u2_bc(wir_r, c3__void, c3__void);
      }
    }
  } 
  u2_flag                                                         //  stable
  j2_mcx(Pit, ut, fern)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun dox,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_noun gol = c3__noun;
    u2_noun hel;

    FUN++;
    hel = _fern_in(wir_r, van, sut, dox, gen, gol);
    FUN--;

    u2_rz(wir_r, hel);
    return u2_yes;
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, fern)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, fern)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, dox, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &dox, 
                                u2_cv_sam_3, &gen,
                                u2_cv_con, &van, 
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mcx(Pit, ut, fern)(wir_r, van, sut, dox, gen);
    }
  }

  u2_weak                                                         //  produce
  j2_mci(Pit, ut, fern)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun dox,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_weak hoc = u2_ds_look(wir_r, van, "fern");

    if ( u2_none == hoc ) {
      c3_assert(!"register fern");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cv_sam_2, u2_rx(wir_r, dox), 
                                      u2_cv_sam_3, u2_rx(wir_r, gen), 
                                      0);

      if ( (u2_none == j2_mcj(Pit, ut, fern)[0].xip) ) {
        u2_noun xip = u2_ds_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, fern)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  produce
  j2_mcy(Pit, ut, fern)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun dox,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, fern)[0];

    if ( (jet_j->sat_s & u2_jet_live) && !(jet_j->sat_s & u2_jet_test) ) {
      if ( !(jet_j->sat_s & u2_jet_memo) ) {
        return j2_mcx(Pit, ut, fern)(wir_r, van, sut, dox, gen);
      }
      else {
        c3_m    fun_m = u2_jet_fun_m(jet_j);
        u2_noun vet   = u2_frag(j2_ut_van_vet, van);
        u2_noun pro   = u2_rl_find_qual(wir_r, fun_m, vet, sut, dox, gen);

        if ( u2_none != pro ) {
          return pro;
        }
        else {
          pro = j2_mcx(Pit, ut, fern)(wir_r, van, sut, dox, gen);

          return u2_rl_save_qual(wir_r, fun_m, vet, sut, dox, gen, pro);
        }
      }
    }
    else {
      u2_noun cor, fol, pro;

      cor = j2_mci(Pit, ut, fern)(wir_r, van, sut, dox, gen);
      fol = u2_t(cor);

      pro = u2_ho_use(wir_r, jet_j, cor, fol);
      if ( u2_none == pro ) return u2_bl_bail(wir_r, c3__fail);

      u2_rz(wir_r, cor);
      u2_rz(wir_r, fol);

      return pro;
    }
  }

  u2_weak
  j2_mck(Pit, ut, fern)(u2_wire wir_r,
                        u2_noun cor)
  {
    u2_noun sut, dox, gen, vet, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &dox, 
                                u2_cv_sam_3, &gen,
                                u2_cv_con, &van, 
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) ||
         ((vet = u2_frag(j2_ut_van_vet, van)) > 1) )
    {
      return u2_none;
    } else {
      return u2_rq
        (wir_r, vet, u2_rx(wir_r, sut), u2_rx(wir_r, dox), u2_rx(wir_r, gen));
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, fern)[] = {
    { ".3", c3__hevy, 
        j2_mc(Pit, ut, fern), 
        Tier6_b_memo,
        u2_none, u2_none,
        j2_mck(Pit, ut, fern)
    },
    { }
  };
