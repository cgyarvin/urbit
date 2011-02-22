/* j/6/mint.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  static u2_noun
  _mint_flag(u2_wire wir_r)
  {
    return u2_bt(wir_r, c3__fork, u2_bc(wir_r, c3__cube, _0),
                                  u2_bc(wir_r, c3__cube, _1));
  }

  static u2_flag
  _mint_vet(u2_wire wir_r, 
            u2_noun van)
  {
    u2_flag vet = u2_bn_hook(wir_r, van, "vet");

    switch ( vet ) {
      u2_no: u2_yes: return vet;
      default: return u2_bl_bail(wir_r); 
    }
  }
  static u2_noun
  _mint_make(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun gol,
             u2_noun gen)
  {
    u2_noun mil = j2_mcy(Pit, ut, mint)(wir_r, van, sut, gol, gen);
    u2_noun fol = u2_rx(wir_r, u2_t(mil));

    u2_rl_lose(wir_r, mil);
    return fol;
  }

  static u2_noun                                                  //  transfer
  _mint_nice(u2_wire wir_r,
             u2_noun van,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_noun typ)                                         //  transfer
  {
    if ( (u2_yes == _mint_vet(wir_r, van)) &&
         (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, typ)) ) 
    {
      return u2_bl_bail(wir_r);
    }
    else return typ;
  }

  static u2_noun 
  _mint_crow(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun gol,
             u2_atom mel,
             u2_noun ruf,
             u2_noun dab)
  {
    u2_noun dan = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, ruf);
    u2_noun p_dan = u2_h(dan);
    u2_noun q_dan = u2_t(dan);
    u2_noun toc = j2_mby(Pit, core)
      (wir_r, u2_rx(wir_r, p_dan),
              u2_bt(wir_r, c3__gold, 
                           u2_rx(wir_r, p_dan), 
                           u2_bt(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun dez = j2_mcy(Pit, ut, bake)(wir_r, van, toc, dab);
    u2_noun cot = j2_mby(Pit, core)
      (wir_r, u2_rx(wir_r, p_dan),
              u2_bt(wir_r, mel, 
                           u2_rx(wir_r, p_dan), 
                           u2_bt(wir_r, u2_rx(wir_r, dez), u2_rx(wir_r, dab))));
    u2_noun ret = u2_bc
      (wir_r, 
       _mint_nice(wir_r, van, gol, cot),
       j2_mby(Pit, ut, cons)(wir_r, q_dan, u2_bc(wir_r, 1, dez)));

    u2_rz(wir_r, toc);
    return ret;
  }

  static u2_noun 
  _mint_wren(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun gol,
             u2_noun ruf,
             u2_noun dab)
  {
    u2_noun dan = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, ruf);
    u2_noun p_dan = u2_h(dan);
    u2_noun q_dan = u2_t(dan);
    u2_noun toc = j2_mby(Pit, core)
      (wir_r, u2_rx(wir_r, p_dan),
              u2_bt(wir_r, c3__gold, 
                           u2_rx(wir_r, p_dan), 
                           u2_bt(wir_r, u2_nul, u2_rx(wir_r, dab))));
    u2_noun von = u2_bn_cook(wir_r, van, "vet", u2_no);
    u2_noun dez = j2_mcy(Pit, ut, bake)(wir_r, von, toc, dab);
    u2_noun cot = j2_mby(Pit, core)
      (wir_r, u2_rx(wir_r, p_dan),
              u2_bt(wir_r, mel, 
                           u2_rx(wir_r, p_dan), 
                           u2_bt(wir_r, u2_rx(wir_r, dez), u2_rx(wir_r, dab))));
    u2_noun ret = u2_bc
      (wir_r, 
       _mint_nice(wir_r, van, gol, cot),
       j2_mby(Pit, ut, cons)(wir_r, q_dan, u2_bc(wir_r, 1, dez)));

    u2_rz(wir_r, von);
    u2_rz(wir_r, toc);
    return ret;
  }

  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, mint)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gol,
                        u2_noun gen)                              //  retain
  {
    u2_noun p_gen, q_gen, r_gen, s_gen;

    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mby(Pit, open)(wir_r, gen);

      pro = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, rex);
      u2_rl_lose(wir_r, rex);
      return pro;
    } 
    else switch ( u2_h(gen) ) {
      default: {
        u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

        pro = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, rex);
        u2_rl_lose(wir_r, rex);
        return pro;
      }
      
      case c3__bnld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun fid = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, p_gen);
        u2_noun p_fid = u2_h(fid);
        u2_noun q_fid = u2_t(fid);
        u2_noun dov = j2_mcx(Pit, ut, mint)(wir_r, van, p_fid, gol, q_gen);
        u2_noun p_dov = u2_h(dov);
        u2_noun q_dov = u2_t(dov);

        pro = u2_bc
          (wir_r, u2_rx(wir_r, p_dov),
                  j2_mbc(Pit, comb)(wir_r, q_fid, q_dov));

        u2_rl_lose(wir_r, fid); 
        u2_rl_lose(wir_r, dov);
        return pro;
      }
      case c3__csbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun vol = _mint_make(wir_r, van, sut, c3__noun, q_gen);
        u2_noun wam = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);

        if ( _0 != u2_h(vol) ) {
          return u2_bl_bail(wir_r);
        } 
        else {
          pro = u2_bc
            (wir_r,
             _mint_nice(wir_r, van, gol, _mint_flag(wir_r)),
             j2_mcy(Pit, ut, fish)(wir_r, van, wam, u2_t(vol)));

          u2_rl_lose(wir_r, vol);
          u2_rl_lose(wir_r, wam);

          return pro;
        }
      }
      case c3__csdg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun bol = _mint_flag(wir_r);
        u2_noun nor = j2_mcx(Pit, ut, mint)(wir_r, van, sut, bol, p_gen);
        u2_noun fex = j2_mcy(Pit, ut, gain)(wir_r, van, sut, p_gen);

        if ( c3__void == fex ) {
          return j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, r_gen);
        } else {
          u2_noun hiq = j2_mcx(Pit, ut, mint)(wir_r, van, fex, gol, q_gen);
          u2_noun ran = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, r_gen);

          pro = u2_bc
            (wir_r, j2_mby(Pit, fork)(wir_r, u2_h(hiq), u2_h(ran)),
                    u2_bq(wir_r, 
                          _6,
                          u2_rx(wir_r, u2_t(nor)),
                          u2_rx(wir_r, u2_t(hiq)),
                          u2_rx(wir_r, u2_t(ran))));
          
          u2_rl_lose(wir_r, bol);
          u2_rl_lose(wir_r, nor);
          u2_rl_lose(wir_r, fex);
          u2_rl_lose(wir_r, hiq);
          u2_rl_lose(wir_r, ran);

          return pro;
        }
      }
      case c3__dgdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
          u2_noun hed = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, p_gen);
          u2_noun tal = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, q_gen);
          u2_noun typ = 
             u2_bt(wir_r, c3__cell, u2_rx(wir_r, u2_h(hed)), 
                                    u2_rx(wir_r, u2_h(tal))),
          pro = u2_bc
            (wir_r,
             _mint_nice(wir_r, van, gol, typ),
             j2_mby(Pit, cons)(wir_r, 
                               u2_t(hed),
                               u2_t(tal)));

          u2_rl_lose(wir_r, hed);
          u2_rl_lose(wir_r, tal);

          return pro;
      }
      case c3__dtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun dis = _mint_make(wir_r, van, sut, c3__noun, p_gen);
        u2_noun dat = _mint_make(wir_r, van, sut, c3__noun, q_gen);

        return u2_bc
          (wir_r,
           _mint_nice(wir_r, van, gol, _mint_flag(wir_r)),
           u2_bt(wir_r, _5, dis, dat));
      }
      case c3__dtcs: p_gen = u2_t(gen);
      {
        u2_noun vod = _mint_make(wir_r, van, sut, c3__noun, p_gen);

        return u2_bc
          (wir_r, 
           _mint_nice(wir_r, van, gol, _mint_flag(wir_r)), 
           u2_bc(wir_r, _3, vod));
      }
      case c3__dtkt: p_gen = u2_t(gen);
      {
        u2_noun sam = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__atom, p_gen);

        pro = u2_bc
          (wir_r,
           c3__atom, 
           u2_bc(wir_r, _4, u2_rx(wir_r, u2_t(sam))));

        u2_rl_lose(wir_r, sam);
        return pro;
      }
      case c3__dttg: p_gen = u2_t(gen);
      {
        u2_noun typ = u2_bc(wir_r, c3__cube, u2_rx(wir_r, p_gen));

        return u2_bc
          (wir_r,
           _mint_nice(wir_r, van, gol, typ),
           u2_bc(wir_r, _1, u2_rx(wir_r, p_gen)));
      }
      case c3__dttr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun dis = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, p_gen);
        u2_noun dat = j2_mcx(Pit, ut, mint)(wir_r, van, sut, c3__noun, q_gen);

        pro = u2_bc
          (wir_r,
           _mint_nice(wir_r, van, gol, c3__noun),
           u2_bt
            (wir_r,
             _2,
             u2_rx(wir_r, u2_t(dis)),
             u2_rx(wir_r, u2_t(dat))));

        u2_rl_lose(wir_r, dis);
        u2_rl_lose(wir_r, dat);

        return pro;
      }
      case c3__ktbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun vat = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, q_gen);
     
        pro = u2_bc
          (wir_r,
           u2_bt(wir_r, c3__face,
                        u2_rx(wir_r, p_gen), 
                        u2_rx(wir_r, u2_h(vat))),
           u2_rx(wir_r, u2_t(vat)));

        u2_rl_lose(wir_r, vat);
        return pro;
      }
      case c3__ktdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hif = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);

        return u2_bc
          (wir_r,
           _mint_nice(wir_r, van, gol, hif),
           _mint_make(wir_r, van, sut, hif, q_gen));
      }
      case c3__ktpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun zut = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);

        if ( (u2_yes ==_mint_vet(wir_r, van)) &&
             (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, gol, zut)) )
        {
          printf("ktpd: nest failure\n");
          return u2_bl_bail(wir_r);
        }
        else {
          pro = j2_mcx(Pit, ut, mint)(wir_r, van, sut, zut, q_gen);

          u2_rl_lose(wir_r, zut);
          return pro;
        }
      }
      case c3__kttg: p_gen = u2_t(gen);
      {
        u2_noun cag = j2_mcy(Pit, ut, burn)(wir_r, van, sut);
        u2_noun nef = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, p_gen);
        
        pro = u2_bt
          (wir_r, u2_rx(u2_h(nef)),
                  _1,
                  u2_nk_nock(wir_r, cag, u2_t(nef)));

        u2_rz(wir_r, nef);
        return pro;
      }
      case c3__mtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun lar = u2_mcy(Pit, ut, seek)(wir_r, van, sut, c3__read, p_gen);
        u2_noun p_lar, q_lar, r_lar;

        u2_bi_trel(wir_r, lar, &p_lar, &q_lar, &r_lar);
        {
          u2_noun fup = j2_mcy(Pit, ut, emit)
              (wir_r, van, sut, p_lar, r_lar, q_gen);
          u2_noun p_fup = u2_h(fup);
          u2_noun q_fup = u2_t(fup);

          if ( u2_nul == q_lar ) {
            pro = u2_bc
              (wir_r, _mint_nice(wir_r, van, sut, gol, u2_rx(wir_r, p_fup)),
                      u2_rx(wir_r, q_fup));
          } else {
            u2_noun uq_lar = u2_t(q_lar);
            uq_noun puq_lar = u2_h(uq_lar);
            u2_noun quq_lar = u2_t(uq_lar);
            u2_noun rip = j2_mcy(Pit, ut, fire)(wir_r, van, p_fup, quq_lar);
           
            pro = u2_bc
              (wir_r, 
               _mint_nice(wir_r, van, sut, gol, rip),
               u2_bt
                (wir_r, _9, u2_rx(wir_r, puq_lar), u2_rx(wir_r, q_fup)));
          }
          u2_rl_lose(wir_r, lar);
          u2_rl_lose(wir_r, fup);
          return pro;
        }
      }
      case c3__pmbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _mint_crow(wir_r, van, sut, gol, c3__lead, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmdg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _mint_crow(wir_r, van, sut, gol, c3__iron, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmdt: p_gen = u2_t(gen);
      {
        u2_noun ruf = u2_bc(wir_r, u2_nul, _1);
        u2_noun ret = _mint_crow(wir_r, van, sut, gol, c3__gold, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__pmmt: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun ruf = u2_bt
          (wir_r, c3__dgdp, 
                  u2_rx(wir_r, p_gen),
                  u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, q_gen), u2_nul, _1));
        u2_noun ret = _mint_crow(wir_r, van, sut, gol, c3__zinc, ruf, r_gen);

        u2_rz(wir_r, ruf);
      }
      case c3__pmtr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun ruf = u2_bq(wir_r, c3__dgdp, u2_rx(wir_r, p_gen), u2_nul, _1);
        u2_noun ret = _mint_wren(wir_r, van, sut, gol, ruf, q_gen);

        u2_rz(wir_r, ruf);
        return ret;
      }
      case c3__tgld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun hum = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, q_gen);
        u2_noun bez;

        if ( u2_yes == u2_stud(p_gen) ) {
          bez = u2_rx(wir_r, p_gen);
        } else {
          bez = u2_bc(wir_r, u2_rx(wir_r, u2_h(p_gen)),
                             _mint_make
                               (wir_r, van, sut, c3__noun, u2_t(p_gen)));
        }
        pro = u2_bc(wir_r, 
                    u2_rx(wir_r, u2_h(hum)),
                    u2_bt(wir_r, _10, bez, u2_rx(wir_r, u2_t(hum))));

        u2_rl_lose(wir_r, hum);
        return pro;
      }
      case c3__zpbn: p_gen = u2_t(gen);
      {
        u2_noun sev = _mint_make(wir_r, van, sut, c3__noun, p_gen);

        return u2_bc(wir_r, c3__noun, u2_bc(wir_r, _1, sev));
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, q_gen);
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        return j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, p_gen);
      }
      case c3__zpzp:
      {
        return u2_bt(wir_r, c3__void, _0, _0);
      }
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, mint)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, mint)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, gol, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &gol, 
                                u2_cv_sam_3, &gen,
                                u2_cv_con, &van, 
                                0)) ||
         (u2_no == u2_stud(gen)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, gen);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, mint)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun gol,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "mint");

    if ( u2_none == hoc ) {
      c3_assert(!"register mint");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cv_sam_2, u2_rx(wir_r, gol), 
                                      u2_cv_sam_3, u2_rx(wir_r, gen), 
                                      0);

      if ( (u2_none == j2_mcj(Pit, ut, mint)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, mint)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, mint)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gol,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, mint)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, gen);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, mint)(wir_r, van, sut, gol, gen);
        sof = u2_nk_soft(wir_r, cor, u2_frag(u2_cv_noc, cor));

        return u2_bl_good(wir_r, sof);
      }
      case u2_jet_limp: {
        u2_weak had, cor, sof;

        /* Compute `had`, the C version.  Jet is full-on recursive.
        ** Catch bails.
        */
        {
          jet_j->sat_s = u2_jet_live;
          {
            u2_ray jub_r = u2_bl_open(wir_r);

            if ( u2_bl_set(wir_r) ) {
              u2_bl_done(wir_r, jub_r);
              had = u2_none;
            } 
            else {
              had = j2_mcx(Pit, ut, mint)(wir_r, van, sut, gol, gen);
              u2_bl_done(wir_r, jub_r);
            }
          }
          jet_j->sat_s = u2_jet_limp;
        }

        /* Compute `sof`, the Nock version.  Jet is full-off recursively.
        */
        {
          jet_j->sat_s = u2_jet_dead;
          {
            cor = j2_mci(Pit, ut, mint)(wir_r, van, sut, gol, gen);
            sof = u2_nk_soft(wir_r, u2_rx(wir_r, cor), 
                                    u2_frag(u2_cv_noc, cor));
          }
          jet_j->sat_s = u2_jet_limp;
        }
        u2_ho_test(jet_j, cor, sof, had);
        u2_rl_lose(wir_r, cor);

        if ( u2_none == sof ) {
          return had;
        } else {
          u2_rl_lose(wir_r, had);
          return sof;
        }
      }
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, mint)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, mint), SafeTier6, u2_none, u2_none },
    { }
  };
