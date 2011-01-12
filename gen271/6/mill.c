/* j/6/mill.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  static u2_noun
  _mill_flag(u2_wire wir_r)
  {
    return u2_bt
      (wir_r,
       c3__fork,
       u2_bc(wir_r, c3__cube, 0),
       u2_bc(wir_r, c3__cube, 1));
  }

  u2_noun                                                         //  transfer
  j2_mcx(Pit, vane, mill)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun p_gen, q_gen, r_gen;
    u2_noun pro;

    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mby(Pit, open)(wir_r, gen);

      pro = j2_mcx(Pit, vane, mill)(wir_r, van, sut, rex);
      u2_rl_lose(wir_r, rex);
      return pro;
    } 
    else {
      u2_noun vet;

      if ( (u2_none == (vet = u2_frag(87, van))) ||
           ((vet != u2_no) && (vet != u2_yes)) )
      {
        return u2_bl_bail(wir_r);
      }

      switch ( u2_h(gen) ) {
        default: {
          u2_noun rex = j2_mby(Pit, open)(wir_r, gen);

          pro = j2_mcx(Pit, vane, mill)(wir_r, van, sut, rex);
          u2_rl_lose(wir_r, rex);
          return pro;
        }
        case c3__bnvd: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun fid = j2_mcx(Pit, vane, mill)(wir_r, van, sut, p_gen);
            u2_noun p_fid = u2_h(fid);
            u2_noun q_fid = u2_t(fid);
            u2_noun dov = j2_mcx(Pit, vane, mill)(wir_r, van, p_fid, q_gen);
            u2_noun p_dov = u2_h(dov);
            u2_noun q_dov = u2_t(dov);

            pro = u2_bc
              (wir_r, u2_rx(wir_r, p_dov),
                      j2_mbc(Pit, comb)(wir_r, q_fid, q_dov));

            u2_rl_lose(wir_r, fid); 
            u2_rl_lose(wir_r, dov);
            return pro;
          }
        }
        case c3__brmt: {
          p_gen = u2_t(gen);
          {
            u2_noun sac = j2_mcc(Pit, by, gas)(wir_r, u2_nul, p_gen);
            u2_noun toc = u2_bq(wir_r, c3__core,
                                       u2_rx(wir_r, sut),
                                       c3__pink,
                                       sac);
            u2_noun vaq = j2_mcy(Pit, vane, bake)(wir_r, van, toc, sac);

            pro = u2_bc(wir_r, 
                        toc, 
                        u2_bc(wir_r,
                              u2_bc(wir_r, _0, _1),
                              u2_bc(wir_r, _1, vaq)));

            return pro;
          }
        }
        case c3__brrt: {
          p_gen = u2_t(gen);
          {
            u2_noun sac = j2_mcc(Pit, by, gas)(wir_r, u2_nul, p_gen);
            u2_noun toc = u2_bq(wir_r, c3__core,
                                       u2_rx(wir_r, sut),
                                       c3__blue,
                                       sac);
            u2_noun vaq = j2_mcy(Pit, vane, bake)(wir_r, van, toc, sac);

            pro = u2_bc(wir_r, 
                        toc, 
                        u2_bc(wir_r,
                              u2_bc(wir_r, _0, _1),
                              u2_bc(wir_r, _1, vaq)));
            return pro;
          }
        }
        case c3__dgnp: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun hed = j2_mcx(Pit, vane, mill)(wir_r, van, sut, p_gen);
            u2_noun tal = j2_mcx(Pit, vane, mill)(wir_r, van, sut, q_gen);

            pro = u2_bc
              (wir_r,
               u2_bt(wir_r, c3__cell, u2_rx(wir_r, u2_h(hed)), 
                                      u2_rx(wir_r, u2_h(tal))),
               j2_mby(Pit, cons)(wir_r, 
                                 u2_t(hed),
                                 u2_t(tal)));

            u2_rl_lose(wir_r, hed);
            u2_rl_lose(wir_r, tal);

            return pro;
          }
        }
        case c3__dtbn: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun dis = j2_mcy(Pit, vane, make)(wir_r, van, sut, p_gen);
            u2_noun dat = j2_mcy(Pit, vane, make)(wir_r, van, sut, q_gen);

            return u2_bc
              (wir_r,
               _mill_flag(wir_r),
               u2_bt(wir_r, _5, dis, dat));
          }
        }
        case c3__dtkt: {
          p_gen = u2_t(gen);
          {
            u2_noun sam = j2_mcx(Pit, vane, mill)(wir_r, van, sut, p_gen);

            if ( (u2_yes == vet) &&
                 (u2_no == j2_mcy(Pit, vane, nest)
                              (wir_r, van, c3__atom, u2_h(sam))) )
            {
              printf("dtkt: type error\n");
              return u2_bl_bail(wir_r);
            }
            else {
              pro = u2_bc
                (wir_r,
                 c3__atom, 
                 u2_bc(wir_r, _4, u2_rx(wir_r, u2_t(sam))));

              u2_rl_lose(wir_r, sam);
              return pro;
            }
          }
        }
        case c3__dtrt: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun dis = j2_mcx(Pit, vane, mill)(wir_r, van, sut, p_gen);
            u2_noun dat = j2_mcx(Pit, vane, mill)(wir_r, van, sut, q_gen);

            pro = u2_bc
              (wir_r,
               c3__blur,
               u2_bt
                (wir_r,
                 _2,
                 u2_rx(wir_r, u2_t(dis)),
                 u2_rx(wir_r, u2_t(dat))));

            u2_rl_lose(wir_r, dis);
            u2_rl_lose(wir_r, dat);

            return pro;
          }
        }
        case c3__dtsg: {
          p_gen = u2_t(gen);
          {
            return u2_bc
              (wir_r,
               u2_bc(wir_r, c3__cube, u2_rx(wir_r, p_gen)),
               u2_bc(wir_r, _1, u2_rx(wir_r, p_gen)));
          }
        }
        case c3__dtcs: {
          p_gen = u2_t(gen);
          {
            u2_noun vod = j2_mcy(Pit, vane, make)(wir_r, van, sut, p_gen);

            return u2_bc(wir_r, _mill_flag(wir_r), u2_bc(wir_r, _3, vod));
          }
        }
        case c3__bpbn: {
          p_gen = u2_t(gen);
          {
            u2_noun sev = j2_mcy(Pit, vane, make)(wir_r, van, sut, p_gen);

            return u2_bc
              (wir_r, u2_bc(wir_r, c3__cube, sev),
                      u2_bc(wir_r, _1, u2_rx(wir_r, sev)));
          }
        }
        case c3__bpcb: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            return j2_mcx(Pit, vane, mill)(wir_r, van, sut, q_gen);
          }
        }
        case c3__bpdg: {
          p_gen = u2_t(gen);
          {
            u2_noun vot = j2_mcy(Pit, vane, play)(wir_r, van, sut, p_gen);

            return u2_bc
              (wir_r, u2_bc(wir_r, c3__cube, vot),
                      u2_bc(wir_r, _1, u2_rx(wir_r, vot)));
          }
        }
        case c3__bpbp: {
          return u2_bc
            (wir_r, c3__blot,
                    u2_bc(wir_r, _0, _0));
        }
        case c3__bpmt: {
          return u2_bc(wir_r, c3__blur, 
                              u2_bc(wir_r, _1, u2_rx(wir_r, van)));
        }
        case c3__bpdx: {
          p_gen = u2_t(gen);
          {
            u2_noun bug;

            if ( (u2_none == (bug = u2_frag(87, van))) ||
                 (u2_no == u2_stud(bug)) ||
                 !u2_fly_is_cat(bug) ||
                 !u2_fly_is_cat(bug+1) )
            {
              return u2_bl_bail(wir_r);
            }
            else {
              u2_noun vin = u2_bn_molt(wir_r, van, 86, bug+1, 0);
              u2_noun pro = j2_mcx(Pit, vane, mill)(wir_r, vin, sut, p_gen);

              u2_rl_lose(wir_r, vin);
              return pro;
            }
          }
        }
        case c3__ktbn: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun vat = j2_mcx(Pit, vane, mill)(wir_r, van, sut, q_gen);
            
            pro = u2_bc
              (wir_r,
               u2_bt(wir_r, c3__face,
                            u2_rx(wir_r, p_gen), 
                            u2_rx(wir_r, u2_h(vat))),
               u2_rx(wir_r, u2_t(vat)));

            u2_rl_lose(wir_r, vat);
            return pro;
          }
        }
        case c3__ktnp: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            if ( u2_no == vet ) {
              return u2_bt
                (wir_r, j2_mcy(Pit, vane, play)(wir_r, van, sut, p_gen),
                        _0,
                        _0);
            } else {
              u2_noun hif = j2_mcy(Pit, vane, play)(wir_r, van, sut, p_gen);
              u2_noun dan = j2_mcx(Pit, vane, mill)(wir_r, van, sut, q_gen);

              if ( (u2_yes == vet) &&
                   (u2_no == j2_mcy(Pit, vane, nest)
                                (wir_r, van, hif, u2_h(dan))) )
              {
                printf("ktnp: nest failure\n");
                return u2_bl_bail(wir_r);
              }
              else {
                pro = u2_bc(wir_r, hif, u2_rx(wir_r, u2_t(dan)));

                u2_rl_lose(wir_r, dan);
                return pro;
              }
            }
          }
        }
        case c3__ktpd: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun gos = j2_mcy(Pit, vane, play)(wir_r, van, sut, p_gen);
            u2_noun rad = j2_mcy(Pit, vane, play)(wir_r, van, sut, q_gen);

            if ( (u2_yes == vet) &&
                 (u2_no == j2_mcy(Pit, vane, nest)(wir_r, van, gos, rad)) ) 
            {
              printf("ktpd: nest failure\n");
              return u2_bl_bail(wir_r);
            }
            else {
              pro = u2_bc(wir_r, u2_rx(wir_r, sut),
                                 u2_bc(wir_r, _0, _1));

              u2_rl_lose(wir_r, gos);
              u2_rl_lose(wir_r, rad);
              return pro;
            }
          }
        }
        case c3__ktsg: {
          p_gen = u2_t(gen);
          return j2_mcx(Pit, vane, mill)(wir_r, van, sut, p_gen);
        }
        case c3__ktvd: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun hum = j2_mcx(Pit, vane, mill)(wir_r, van, sut, q_gen);
            u2_noun bez;

            if ( u2_yes == u2_stud(p_gen) ) {
              bez = u2_rx(wir_r, p_gen);
            } else {
              bez = u2_bc(wir_r, u2_rx(wir_r, u2_h(p_gen)),
                                 j2_mcy(Pit, vane, make)
                                   (wir_r, van, sut, u2_t(p_gen)));
            }
            pro = u2_bc(wir_r, 
                        u2_rx(wir_r, u2_h(hum)),
                        u2_bt(wir_r, _10, bez, u2_rx(wir_r, u2_t(hum))));

            u2_rl_lose(wir_r, hum);
            return pro;
          }
        }
        case c3__mtbn: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun lar = j2_mcy(Pit, vane, seek)(wir_r, van, sut, p_gen);
            u2_noun p_lar, q_lar, r_lar;

            u2_as_trel(lar, &p_lar, &q_lar, &r_lar);
            {
              u2_noun fup = j2_mcy(Pit, vane, edit)
                              (wir_r, van, sut, p_lar, r_lar, q_gen);

              if ( u2_nul == q_lar ) {
                u2_rl_lose(wir_r, lar);
                return fup;
              } else {
                u2_noun uq_lar = u2_t(q_lar);

                pro = u2_bc
                  (wir_r,
                   u2_bt(wir_r, c3__hold,
                                j2_mcy(Pit, vane, clay)(wir_r, van, u2_h(fup)),
                                u2_rx(wir_r, u2_t(uq_lar))),
                   u2_bt(wir_r, _9,
                                u2_rx(wir_r, u2_h(uq_lar)),
                                u2_rx(wir_r, u2_t(fup))));

                u2_rl_lose(wir_r, fup);
                u2_rl_lose(wir_r, lar);
                return pro;
              }
            }
          }
        }
        case c3__csbn: {
          if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun vol = j2_mcy(Pit, vane, make)(wir_r, van, sut, q_gen);
            u2_noun wam = j2_mcy(Pit, vane, play)(wir_r, van, sut, p_gen);

            if ( _0 != u2_h(vol) ) {
              return u2_bl_bail(wir_r);
            } 
            else {
              pro = u2_bc
                (wir_r,
                 _mill_flag(wir_r),
                 j2_mcy(Pit, vane, fish)(wir_r, van, wam, u2_t(vol)));

              u2_rl_lose(wir_r, vol);
              u2_rl_lose(wir_r, wam);

              return pro;
            }
          }
        }
        case c3__csdg: {
          if ( u2_no == u2_as_trel(u2_t(gen), &p_gen, &q_gen, &r_gen) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun bol = _mill_flag(wir_r);
            u2_noun nor = j2_mcx(Pit, vane, mill)(wir_r, van, sut, p_gen);
            u2_noun fex = j2_mcy(Pit, vane, gain)(wir_r, van, sut, p_gen);
            u2_noun hiq = j2_mcx(Pit, vane, mill)(wir_r, van, fex, q_gen);
            u2_noun ran = j2_mcx(Pit, vane, mill)(wir_r, van, sut, r_gen);

            if ( (u2_yes == vet) &&
                 (u2_no == j2_mcy(Pit, vane, nest)
                    (wir_r, van, bol, u2_h(nor))) ) 
            {
              j2_mcy(Pit, vane, dupt)(wir_r, van, "test", u2_h(nor));
              printf("csdg: nest fail\n");
              return u2_bl_bail(wir_r);
            } else {
              pro = u2_bc
                (wir_r, j2_mby(Pit, eith)(wir_r, u2_h(hiq), u2_h(ran)),
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
        }
      }
    }
  }


/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, mill)[];

  u2_weak
  j2_mci(Pit, vane, mill)(u2_wire wir_r,
                          u2_noun van,
                          u2_noun sut,
                          u2_noun gen)
  {
    u2_weak von = u2_rl_molt(wir_r, van, u2_conv_sam, u2_rx(wir_r, sut), 0);
    u2_weak hoc = u2_sh_look(wir_r, von, "mill");
    u2_weak gat = u2_nk_nock(wir_r, von, hoc);
    u2_weak cor = u2_rl_molt(wir_r, von, u2_conv_sam, u2_rx(wir_r, gen), 0);

    if ( (u2_none == j2_mcj(Pit, vane, mill)[0].xip) ) {
      u2_noun xip = u2_sh_find(wir_r, cor);
   
      c3_assert(u2_none != xip);
      j2_mcj(Pit, vane, mill)[0].xip = xip;
    }

    u2_rl_lose(wir_r, von);
    u2_rl_lose(wir_r, gat);
    return cor;
  }

  u2_noun
  j2_mcy(Pit, vane, mill)(u2_wire wir_r,
                          u2_noun van,
                          u2_noun sut,
                          u2_noun gen)
  {
# if 1
    return j2_mcy(Pit, vane, mill)(wir_r, van, sut, gen);
# else
    u2_ho_jet *jet_j = &j2_mcj(Pit, vane, mill)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_none;

      case u2_jet_live: {
        return j2_mcy(Pit, vane, mill)(wir_r, van, sut, gen);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, vane, mill)(wir_r, van, sut, gen);
        sof = u2_nk_soft(wir_r, cor, u2_frag(u2_conv_noc, cor));

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
              had = j2_mcy(Pit, vane, mill)(wir_r, van, sut, gen);
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
            cor = j2_mci(Pit, vane, mill)(wir_r, van, sut, gen);
            sof = u2_nk_soft(wir_r, u2_rx(wir_r, cor), 
                                    u2_frag(u2_conv_noc, cor));
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
# endif
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, mill)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, gen, van;

    if ( (u2_no == u2_mean(cor, 4, &gen, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, vane, mill)(wir_r, van, sut, gen);
    }
  }


/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, mill)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, mill), SafeTier6, u2_none, u2_none },
    { }
  };
