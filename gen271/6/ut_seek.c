/* j/6/seek.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, seek)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun way,                              //  retain
                        u2_noun hep)                              //  retain
  {
    if ( u2_nul == hep ) {
      return u2_bt
        (wir_r, _1, u2_nul, u2_rx(wir_r, sut));
    }
    else if ( u2_no == u2_dust(hep) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      u2_noun i_hep = u2_h(hep);
      u2_noun t_hep = u2_t(hep);
      u2_noun vag = j2_mcx(Pit, ut, seek)(wir_r, van, sut, way, t_hep);
      u2_noun p_vag, q_vag, r_vag;
      u2_noun pro;

      u2_as_trel(vag, &p_vag, &q_vag, &r_vag);

      if ( u2_no == u2_dust(i_hep) ) {
        u2_noun hup = j2_mcy(Pit, ut, find)(wir_r, van, r_vag, way, i_hep);
        u2_noun p_hup, q_hup, r_hup;

        u2_as_trel(hup, &p_hup, &q_hup, &r_hup);

        pro = u2_bt
          (wir_r, j2_mbc(Pit, peg)(wir_r, p_vag, p_hup), 
                  u2_rx(wir_r, q_hup),
                  u2_rx(wir_r, r_hup));

        u2_rl_lose(wir_r, vag);
        u2_rl_lose(wir_r, hup);

        return pro;
      } 
      else {
        u2_noun hi_hep = u2_h(i_hep);
        u2_noun pi_hep = u2_t(i_hep);

        if ( (u2_nul != hi_hep) || (u2_no == u2_stud(pi_hep)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          pro = u2_bt
            (wir_r, j2_mbc(Pit, peg)(wir_r, p_vag, pi_hep),
                    u2_nul,
                    j2_mcy(Pit, ut, peek)(wir_r, van, r_vag, way, pi_hep));

          u2_rl_lose(wir_r, vag);
          return pro;
        }
      }
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, seek)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, seek)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, way, hep, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &way, 
                                u2_cv_sam_3, &hep, 
                                u2_cv_con, &van, 0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, seek)(wir_r, van, sut, way, hep);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, seek)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun way,                              //  retain
                        u2_noun hep)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "seek");

    if ( u2_none == hoc ) {
      c3_assert(!"register seek");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cv_sam_2, u2_rx(wir_r, way), 
                                      u2_cv_sam_3, u2_rx(wir_r, hep), 
                                      0);

      if ( (u2_none == j2_mcj(Pit, ut, seek)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, seek)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, seek)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun way,
                        u2_noun hep)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, seek)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, seek)(wir_r, van, sut, way, hep);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, seek)(wir_r, van, sut, way, hep);
        sof = u2_nk_soft(wir_r, cor, u2_frag(u2_cv_noc, cor));

        if ( u2_none == sof ) {
          j2_mcy(Pit, ut, dupt)(wir_r, van, "seek: sut", sut);
          u2_err(wir_r, "seek: sut", sut);
          u2_err(wir_r, "seek: hep", hep);
        }
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
              had = j2_mcx(Pit, ut, seek)(wir_r, van, sut, way, hep);
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
            cor = j2_mci(Pit, ut, seek)(wir_r, van, sut, way, hep);
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
  j2_mcj(Pit, ut, seek)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, seek), SafeTier6, u2_none, u2_none },
    { }
  };
