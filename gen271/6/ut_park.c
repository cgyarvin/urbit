/* j/6/ut_park.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_flag                                                         //  transfer
  j2_mcx(Pit, ut, park)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun way,                              //  retain
                        u2_atom axe)                              //  retain
  {
    if ( u2_no == u2_dust(sut) || c3__core != u2_h(sut) ) {
      return u2_bl_bail(wir_r);
    }
    else {
      u2_noun p_sut, q_sut, pq_sut, qq_sut;

      u2_bi_cell(wir_r, u2_t(sut), &p_sut, &q_sut);
      u2_bi_cell(wir_r, q_sut, &pq_sut, 0);

      if ( c3__nest == way ) {
        return u2_yes;
      }
      else if ( c3__read == way ) {
        switch ( pq_sut ) {
          default: return u2_bl_bail(wir_r);

          case c3__gold: return u2_sing(_3, j2_mbc(Pit, cap)(wir_r, axe));
          case c3__iron: return u2_sing(_3, j2_mbc(Pit, cap)(wir_r, axe));
          case c3__lead: return u2_yes;
          case c3__wood: return u2_yes;
          case c3__zinc: return u2_yes;
        }
      }
      else if ( c3__rite == way ) {
        switch ( pq_sut ) {
          default: return u2_bl_bail(wir_r);

          case c3__gold: return u2_yes;
          case c3__iron: 
          {
            if ( u2_sing(_2, j2_mbc(Pit, cap)(wir_r, axe)) ) {
              return u2_yes;
            } else {
              u2_noun lat = j2_mbc(Pit, mas)(wir_r, axe);

              return u2_and
                (u2_not(u2_sing(_1, lat)),
                 u2_sing(_3, j2_mbc(Pit, cap)(wir_r, axe)));
            }
          }
          case c3__lead: return u2_yes;
          case c3__wood: return u2_yes;
          case c3__zinc: return u2_sing(_3, j2_mbc(Pit, cap)(wir_r, axe));
        }
      }
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, park)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, park)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, way, axe, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &way, 
                                u2_cv_sam_3, &axe,
                                u2_cv_con, &van, 0)) ||
         (u2_no == u2_stud(axe)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, park)(wir_r, van, sut, way, axe);
    }
  }

  u2_flag
  j2_mci(Pit, ut, park)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun way,                              //  retain
                        u2_noun axe)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "park");

    if ( u2_none == hoc ) {
      c3_assert(!"register park");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cv_sam_2, u2_rx(wir_r, way), 
                                      u2_cv_sam_3, u2_rx(wir_r, axe), 
                                      0);

      if ( (u2_none == j2_mcj(Pit, ut, park)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, park)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, park)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun way,                              //  retain
                        u2_noun axe)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, park)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, park)(wir_r, van, sut, way, axe);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, park)(wir_r, van, sut, way, axe);
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
              had = j2_mcx(Pit, ut, park)(wir_r, van, sut, way, axe);
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
            cor = j2_mci(Pit, ut, park)(wir_r, van, sut, way, axe);
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
  j2_mcj(Pit, ut, park)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, park), SafeTier6, u2_none, u2_none },
    { }
  };
