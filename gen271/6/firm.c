/* j/6/firm.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_flag
  j2_mcx(Pit, vane, firm)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun bax = u2_bt(wir_r, sut, ref, gen);
    u2_noun ver = u2_frag(42, van); 

    if ( u2_yes == j2_mcc(Pit, in, has)(wir_r, ver, bax) ) {
      u2_rl_lose(wir_r, bax);
      return u2_yes;
    }
    else {
      u2_noun vor = j2_mcc(Pit, in, put)(wir_r, ver, bax);
      u2_noun von = u2_bn_molt(wir_r, van, 42, vor, 0);
      u2_noun old = j2_mcy(Pit, vane, make)(wir_r, van, sut, gen);
      u2_noun new = j2_mcy(Pit, vane, make)(wir_r, van, ref, gen);
      u2_flag pro = u2_sing(old, new);

      u2_rl_lose(wir_r, new);
      u2_rl_lose(wir_r, old);
      u2_rl_lose(wir_r, von);
      u2_rl_lose(wir_r, vor);

      return pro;
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, firm)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, firm)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun van, sut, ref, gen;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &ref, 
                                u2_cv_sam_3, &gen,
                                u2_cv_con, &van, 
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, vane, firm)(wir_r, van, sut, ref, gen);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, vane, firm)(u2_wire wir_r,
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "firm");

    if ( u2_none == hoc ) {
      c3_assert(!"register firm");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam_2, u2_rx(wir_r, ref), 
                                           u2_cv_sam_3, u2_rx(wir_r, gen),
                                           0);

      if ( (u2_none == j2_mcj(Pit, vane, firm)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, vane, firm)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun
  j2_mcy(Pit, vane, firm)(u2_wire wir_r,
                          u2_noun van,
                          u2_noun sut,
                          u2_noun ref,
                          u2_noun gen)
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, vane, firm)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_none;

      case u2_jet_live: {
        return j2_mcx(Pit, vane, firm)(wir_r, van, sut, ref, gen);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, vane, firm)(wir_r, van, sut, ref, gen);
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
              had = j2_mcx(Pit, vane, firm)(wir_r, van, sut, ref, gen);
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
            cor = j2_mci(Pit, vane, firm)(wir_r, van, sut, ref, gen);
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
  j2_mcj(Pit, vane, firm)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, firm), SafeTier6_b, u2_none, u2_none },
    { }
  };

