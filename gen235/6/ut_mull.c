/* j/6/mull.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/

# define _mull_used(wir_r)

  u2_noun                                                         //  transfer
  j2_mcx(Pt6, ut, mull)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gol,                              //  retain
                        u2_noun dox,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_noun p_gen, q_gen, r_gen;
    u2_noun ret;

    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mcy(Pt6, ap, open)(wir_r, gen);

      ret = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, dox, rex);
      u2_rl_lose(wir_r, rex);

      return ret;
    } 
    else switch ( u2_h(gen) ) {
      default: {
        u2_noun rex = j2_mcy(Pt6, ap, open)(wir_r, gen);

        if ( u2_yes == u2_sing(rex, gen) ) {
#if 1
          u2_noun zix = j2_mcy(Pt6, ut, shep)
                (wir_r, van, "gene", 'q', u2_rx(wir_r, gen));

          u2_bl_push(wir_r, u2_bc(wir_r, c3__mean, zix));
          return u2_bl_error(wir_r, "mull-open");
#else
          u2_err(wir_r, "h", u2_h(gen));
          return u2_bl_bail(wir_r, c3__fail);
#endif
        }
        ret = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, dox, rex);
        u2_rl_lose(wir_r, rex);

        return ret;
      }
      
      case c3__cslc: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__csdg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      _mull_used(wir_r);
      {
      }
      case c3__cssg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      _mull_used(wir_r);
      {
      }
      case c3__dgsp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__dtlc: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__dtcs: p_gen = u2_t(gen);
      _mull_used(wir_r);
      {
      }
      case c3__dtps: p_gen = u2_t(gen);
      _mull_used(wir_r);
      {
      }
      case c3__dtsg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__dttr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__dtwt: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__ktlc: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__ktdl: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__ktld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
      }
      case c3__ktsg: p_gen = u2_t(gen);
      _mull_used(wir_r);
      {
        u2_noun nef = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, p_gen);
        u2_noun p_nef = u2_h(nef);
        u2_noun q_nef = u2_t(nef);
        u2_flag fab = _mull_fab(wir_r, van);

        if ( u2_no == fab ) {
          ret = u2_bc(wir_r, u2_rx(wir_r, p_nef), u2_bc(wir_r, _0, _0));
        } else {
          u2_noun cag = j2_mcy(Pt6, ut, burn)(wir_r, van, sut);
          u2_noun cod;

          {
            cod = u2_nk_nock(wir_r, cag, q_nef);
            if ( u2_none == cod ) {
              return u2_bl_error(wir_r, "mull-burn");
            }
          }
          ret = u2_bc(wir_r, u2_rx(wir_r, p_nef), u2_bc(wir_r, _1, cod));
        }
        u2_rz(wir_r, nef);
        return ret;
      }
      case c3__mtlc: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
        u2_noun lar = j2_mcy(Pt6, ut, seek)(wir_r, van, sut, c3__read, p_gen);
        u2_noun p_lar, q_lar;
        u2_noun ret;

        u2_bi_cell(wir_r, lar, &p_lar, &q_lar);

        if ( u2_yes == u2_h(q_lar) ) {
          u2_noun pq_lar = u2_t(q_lar);
          u2_noun gix = u2_bc
            (wir_r,
             u2_bc(wir_r, u2_rx(wir_r, pq_lar),
                          u2_bt(wir_r, u2_yes, u2_nul, _1)),
             u2_nul);
          u2_noun fup = j2_mcy(Pt6, ut, emit)
                          (wir_r, van, sut, p_lar, gix, q_gen);
          u2_noun p_fup = u2_h(fup);
          u2_noun q_fup = u2_t(fup);

          ret = u2_bc(wir_r,
                      _mull_nice
                        (wir_r, van, gol, u2_rx(wir_r, u2_h(u2_h(p_fup)))),
                      u2_rx(wir_r, q_fup));
          
          u2_rz(wir_r, gix);
          u2_rz(wir_r, fup);
        }
        else {
          u2_noun pq_lar, qq_lar;

          u2_bi_cell(wir_r, u2_t(q_lar), &pq_lar, &qq_lar);
          {
            u2_noun fup = j2_mcy(Pt6, ut, emit)
              (wir_r, van, sut, p_lar, qq_lar, q_gen);
            u2_noun p_fup = u2_h(fup);
            u2_noun q_fup = u2_t(fup);
            u2_noun qir = j2_mcy(Pt6, ut, fire)(wir_r, van, sut, p_fup);

            ret = u2_bc(wir_r,
                        _mull_nice(wir_r, van, gol, qir),
                        u2_bt(wir_r,
                              _9,
                              u2_rx(wir_r, pq_lar), 
                              u2_rx(wir_r, q_fup)));

            u2_rz(wir_r, fup);
          }
        }
        u2_rz(wir_r, lar);
        return ret;
      }
      case c3__pmdg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
        u2_noun ruf = u2_bt
          (wir_r, c3__dgsp, 
                  u2_bc(wir_r, u2_nul, _1),
                  u2_rx(wir_r, p_gen));
        u2_noun ret = _mull_grow(wir_r, van, sut, gol, c3__zinc, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmdt: p_gen = u2_t(gen);
      _mull_used(wir_r);
      {
        u2_noun ruf = u2_bc(wir_r, u2_nul, _1);

        ret = _mull_grow(wir_r, van, sut, gol, c3__gold, ruf, p_gen);
        u2_rz(wir_r, ruf);

        return ret;
      }
      case c3__pmmt: p_gen = u2_t(gen);
      _mull_used(wir_r);
      {
        u2_noun ruf = u2_bc(wir_r, u2_nul, _1);

        ret = _mull_grow(wir_r, van, sut, gol, c3__lead, ruf, p_gen);
        u2_rz(wir_r, ruf);

        return ret;
      }
      case c3__pmps: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
        u2_noun ruf = u2_bt
          (wir_r, c3__dgsp, 
                  u2_bc(wir_r, u2_nul, _1),
                  u2_rx(wir_r, p_gen));
        u2_noun ret = _mull_grow(wir_r, van, sut, gol, c3__iron, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__sgld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
        u2_noun hum = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, q_gen);
        u2_flag fab = _mull_fab(wir_r, van);

        if ( u2_no == fab ) {
          ret = u2_bc(wir_r, 
                      u2_rx(wir_r, u2_h(hum)),
                      u2_bc(wir_r, _0, _0));
        } else {
          u2_noun bez;
        
            if ( u2_yes == u2_stud(p_gen) ) {
              bez = u2_rx(wir_r, p_gen);
            } else {
              bez = u2_bc(wir_r, u2_rx(wir_r, u2_h(p_gen)),
                                 _mull_make
                                   (wir_r, van, sut, c3__noun, u2_t(p_gen)));
            }
            ret = u2_bc(wir_r, 
                        u2_rx(wir_r, u2_h(hum)),
                        u2_bt(wir_r, _10, bez, u2_rx(wir_r, u2_t(hum))));
        }
        u2_rl_lose(wir_r, hum);
        return ret;
      }
      case c3__zplc: p_gen = u2_t(gen);
      _mull_used(wir_r);
      {
        u2_flag fab = _mull_fab(wir_r, van);

        if ( u2_no == fab ) {
          return u2_bc(wir_r, c3__noun, u2_bc(wir_r, _0, _0));
        }
        else {
          u2_noun von = u2_bn_molt(wir_r, van, j2_ut_van_vet, u2_no, 0);
          u2_noun sev = _mull_make(wir_r, von, sut, c3__noun, p_gen);

          u2_rz(wir_r, von);

          return u2_bc(wir_r, c3__noun, u2_bc(wir_r, _1, sev));
        }
      }
      case c3__zpcm: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
        return u2_bc
          (wir_r, 
           _mull_nice(wir_r, van, 
                             gol, 
                             j2_mcy(Pt6, ut, play)(wir_r, van, sut, p_gen)),
           u2_bc(wir_r, 1, u2_rx(wir_r, q_gen)));
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_bl_push(wir_r, u2_bc(wir_r, c3__mean, _mull_loc(wir_r, van, p_gen)));
        {
          u2_noun hum = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, q_gen);
          u2_noun bez = u2_bt(wir_r, c3__spot, _1, u2_rx(wir_r, p_gen));

          ret = u2_bc(wir_r, 
                      u2_rx(wir_r, u2_h(hum)),
                      u2_bt(wir_r, _10, bez, u2_rx(wir_r, u2_t(hum))));

          u2_rz(wir_r, hum);
        }
        u2_bl_drop(wir_r);
        return ret;
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        u2_bx_used(wir_r);
        return j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, p_gen);
      }
      case c3__zpmt:
      _mull_used(wir_r);
      {
        u2_noun pet   = u2_bn_hook(wir_r, van, "seed");
        u2_noun p_pet = u2_h(pet);
        u2_noun q_pet = u2_t(pet);
        u2_noun ret;

        ret = u2_bc(wir_r, _mull_nice(wir_r, van, gol, u2_rx(wir_r, p_pet)),
                           u2_bc(wir_r, _1, u2_rx(wir_r, q_pet)));

        u2_rz(wir_r, pet);
        return ret;
      }
      case c3__zptm: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      _mull_used(wir_r);
      {
        u2_flag fab = _mull_fab(wir_r, van);
        u2_noun vos   = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, c3__noun, q_gen);
        u2_noun zur   = j2_mcy(Pt6, ut, play)(wir_r, van, sut, p_gen);
        u2_noun p_vos = u2_h(vos);
        u2_noun q_vos = u2_t(vos);
        u2_noun waz   = u2_bc(wir_r, _1, u2_rx(wir_r, p_vos));
        u2_noun cig   = j2_mby(Pt6, cell)(wir_r, zur, p_vos);
        u2_noun ret;

        ret = u2_bc(wir_r,
                    _mull_nice(wir_r, van, gol, cig),
                    (u2_no == fab) 
                      ? u2_bc(wir_r, _0, _0)
                      : j2_mby(Pt6, cons)(wir_r, waz, q_vos));

        u2_rz(wir_r, waz);
        u2_rz(wir_r, zur);
        u2_rz(wir_r, vos);

        return ret;
      }
      case c3__zpzp:
      _mull_used(wir_r);
      {
        return u2_bt(wir_r, c3__void, _0, _0);
      }
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pt6, ut, mull)[];

  u2_noun                                                         //  produce
  j2_mc(Pt6, ut, mull)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, gol, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, 
                                u2_cw_sam_2, &gol, 
                                u2_cw_sam_3, &gen,
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, gen);
    }
  }

  u2_weak                                                         //  produce
  j2_mci(Pt6, ut, mull)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun gol,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_weak hoc = u2_ds_look(wir_r, van, "mull");

    if ( u2_none == hoc ) {
      c3_assert(!"register mull");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cw_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cw_sam_2, u2_rx(wir_r, gol), 
                                      u2_cw_sam_3, u2_rx(wir_r, gen), 
                                      0);

      if ( (u2_none == j2_mcj(Pt6, ut, mull)[0].xip) ) {
        u2_noun xip = u2_ds_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pt6, ut, mull)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  produce
  j2_mcy(Pt6, ut, mull)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gol,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pt6, ut, mull)[0];

    if ( (jet_j->sat_s & u2_jet_live) && !(jet_j->sat_s & u2_jet_test) ) {
      if ( !(jet_j->sat_s & u2_jet_memo) ) {
        return j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, gen);
      }
      else {
        c3_m    fun_m = u2_jet_fun_m(jet_j);
        u2_noun vrf   = u2_frag(j2_ut_van_vrf, van);
        u2_noun pro   = u2_rl_find_qual(wir_r, fun_m, vrf, sut, gol, gen);

        if ( u2_none != pro ) {
          return pro;
        }
        else {
          pro = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, gen);

          return u2_rl_save_qual(wir_r, fun_m, vrf, sut, gol, gen, pro);
        }
      }
    }
    else {
      u2_noun cor, fol, pro;

      cor = j2_mci(Pt6, ut, mull)(wir_r, van, sut, gol, gen);
      fol = u2_t(cor);

      pro = u2_ho_use(wir_r, jet_j, cor, fol);
      if ( u2_none == pro ) return u2_bl_bail(wir_r, c3__fail);

      u2_rz(wir_r, cor);
      u2_rz(wir_r, fol);

      return pro;
    }
  }
/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pt6, ut, mull)[];

  u2_noun                                                         //  transfer
  j2_mc(Pt6, ut, mull)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, dox, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, 
                                u2_cw_sam_2, &gol, 
                                u2_cw_sam_6, &dox, 
                                u2_cw_sam_7, &gen,
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_bl_bail(wir_r, c3__fail);
    } else {
      return j2_mcx(Pt6, ut, mull)(wir_r, van, sut, dox, gen);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pt6, ut, mull)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun gol,                              //  retain 
                        u2_noun dox,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_weak hoc = u2_ds_look(wir_r, van, "mull");

    if ( u2_none == hoc ) {
      c3_assert(!"register mull");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cw_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cw_sam_2, u2_rx(wir_r, gol), 
                                      u2_cw_sam_6, u2_rx(wir_r, dox), 
                                      u2_cw_sam_7, u2_rx(wir_r, gen), 
                                      0);

      if ( (u2_none == j2_mcj(Pt6, ut, mull)[0].xip) ) {
        u2_noun xip = u2_ds_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pt6, ut, mull)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pt6, ut, mull)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gol,                              //  retain
                        u2_noun dox,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pt6, ut, mull)[0];

    if ( (jet_j->sat_s & u2_jet_live) && !(jet_j->sat_s & u2_jet_test) ) {
      if ( !(jet_j->sat_s & u2_jet_memo) ) {
        return j2_mcx(Pt6, ut, mull)(wir_r, van, sut, gol, dox, gen);
      }
      else {
        c3_m    fun_m = u2_jet_fun_m(jet_j);
        u2_noun pro   = u2_rl_find_qual(wir_r, fun_m, sut, gol, dox, gen);

        if ( u2_none != pro ) {
          return pro;
        }
        else {
          pro = j2_mcx(Pt6, ut, mull)(wir_r, van, sut, dox, gen);

          return u2_rl_save_qual(wir_r, fun_m, sut, gol, dox, gen, pro);
        }
      }
    }
    else {
      u2_noun cor, fol, pro;

      cor = j2_mci(Pt6, ut, mull)(wir_r, van, sut, gol, dox, gen);
      fol = u2_t(cor);

      pro = u2_ho_use(wir_r, jet_j, cor, fol);
      if ( u2_none == pro ) return u2_bl_bail(wir_r, c3__fail);

      u2_rz(wir_r, cor);
      u2_rz(wir_r, fol);

      return pro;
    }
  }

/* structures
*/
  u2_weak
  j2_mck(Pt6, ut, mull)(u2_wire wir_r,
                        u2_noun cor)
  {
    u2_noun sut, dox, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cw_con, &van, 
                                u2_cw_sam_2, &gol, 
                                u2_cw_sam_6, &dox,
                                u2_cw_sam_7, &gen,
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cw_sam, van))) )
    {
      return u2_none;
    } else {
      return u2_rq
        (wir_r, u2_rx(wir_r, sut), 
                u2_rx(wir_r, gol), 
                u2_rx(wir_r, dox), 
                u2_rx(wir_r, gen));
    }
  }

  u2_ho_jet 
  j2_mcj(Pt6, ut, mull)[] = {
    { ".3", c3__hevy, 
        j2_mc(Pt6, ut, mull), 
        Tier6_b_memo,
        u2_none, u2_none,
        j2_mck(Pt6, ut, mull)
    },
    { }
  };
