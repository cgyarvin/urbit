/* j/6/gain.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_noun
  j2_mcx(Pit, ut, gain)(u2_wire, u2_noun, u2_noun, u2_noun);

  static u2_noun
  _gain_cspm(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun p_gen)
  {
    if ( u2_nul == p_gen ) {
      return u2_rx(wir_r, sut);
    } 
    else if ( u2_no == u2_dust(p_gen) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);
      u2_noun lev = j2_mcx(Pit, ut, gain)(wir_r, van, sut, ip_gen);
      u2_noun pro = _gain_cspm(wir_r, van, lev, tp_gen);

      u2_rl_lose(wir_r, lev);
      return pro;
    }
  }
  static u2_noun
  _gain_in(u2_wire wir_r, 
           u2_noun van,
           u2_noun sut,
           u2_noun gen)
  {
    u2_noun p_gen, q_gen;

    if ( u2_no == u2_dust(gen) ) { 
      return u2_rx(wir_r, sut);
    } else switch ( u2_h(gen) ) {
      default: return u2_rx(wir_r, sut);

      case c3__csbn: {
        if ( u2_no == u2_mean(gen, 6, &p_gen, 7, &q_gen, 0) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun rac = j2_mby(Pit, rake)(wir_r, q_gen);
          u2_noun hap = j2_mcy(Pit, ut, play)(wir_r, van, sut, p_gen);
          u2_noun vul = j2_mcy(Pit, ut, play)(wir_r, van, sut, q_gen);
          u2_noun gav = j2_mcy(Pit, ut, reap)(wir_r, van, vul, hap);
          u2_noun tof = u2_bc(wir_r, u2_nul, _1);
          u2_noun tuq = j2_mcy(Pit, ut, tuck)(wir_r, van, sut, rac, gav, tof);
          u2_noun ret = u2_rx(wir_r, u2_h(tuq));

          u2_rl_lose(wir_r, rac);
          u2_rl_lose(wir_r, hap);
          u2_rl_lose(wir_r, vul);
          u2_rl_lose(wir_r, gav);
          u2_rl_lose(wir_r, tof);
          u2_rl_lose(wir_r, tuq);

          return ret;
        }
      }
      case c3__cspm: {
        return _gain_cspm(wir_r, van, sut, u2_t(gen));
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return j2_mcx(Pit, ut, gain)(wir_r, van, sut, q_gen);
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        return j2_mcx(Pit, ut, gain)(wir_r, van, sut, p_gen);
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, gain)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_noun fiz = _gain_in(wir_r, van, sut, gen);

    if ( u2_yes == j2_mcy(Pit, ut, orth)(wir_r, van, c3__noun, fiz) ) {
      u2_rl_lose(wir_r, fiz);
      return c3__void;
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, gain)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, gain)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam, &gen, u2_cv_con, &van, 0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, gain)(wir_r, van, sut, gen);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, gain)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun gen)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "gain");

    if ( u2_none == hoc ) {
      c3_assert(!"register gain");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam, u2_rx(wir_r, gen), 0);

      if ( (u2_none == j2_mcj(Pit, ut, gain)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, gain)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, gain)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, gain)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, gain)(wir_r, van, sut, gen);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, gain)(wir_r, van, sut, gen);
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
              had = j2_mcx(Pit, ut, gain)(wir_r, van, sut, gen);
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
            cor = j2_mci(Pit, ut, gain)(wir_r, van, sut, gen);
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
  j2_mcj(Pit, ut, gain)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, gain), SafeTier6, u2_none, u2_none },
    { }
  };
