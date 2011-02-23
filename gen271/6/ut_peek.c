/* j/6/peek.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, peek)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun way,
                        u2_atom axe)                              //  retain
  {
    if ( _1 == axe ) {
      return u2_rx(wir_r, sut);
    }
    else {
      u2_noun p_sut, q_sut;
      u2_noun pro;

      if ( (u2_no == u2_dust(sut)) ) switch ( sut ) {
        default: return u2_bl_bail(wir_r);

        case c3__atom: {
          return c3__void;
        }
        case c3__noun: {
          return c3__noun;
        }
        case c3__void: {
          return c3__void;
        }
      }
      else switch ( u2_h(sut) ) {
        default: return u2_bl_bail(wir_r);

        case c3__cell: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_atom tip = j2_mbc(Pit, cap)(wir_r, axe);
            u2_atom tap = j2_mbc(Pit, mas)(wir_r, axe);

            if ( _2 == tip ) {
              pro = j2_mcx(Pit, ut, peek)(wir_r, van, p_sut, way, tap);
            }
            else {
              pro = j2_mcx(Pit, ut, peek)(wir_r, van, q_sut, way, tap);
            }
            u2_rl_lose(wir_r, tap); 
            u2_rl_lose(wir_r, tip);

            return pro;
          }
        }
        case c3__core: {
          u2_noun pq_sut, qq_sut, rq_sut;
          u2_noun prq_sut, qrq_sut;

          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ||
               (u2_no == u2_as_trel(q_sut, &pq_sut, &qq_sut, &rq_sut)) ||
               (u2_no == u2_as_cell(rq_sut, &prq_sut, &qrq_sut)) )
          {
            return u2_bl_bail(wir_r);
          } else {
            u2_atom tip = j2_mbc(Pit, cap)(wir_r, axe);
            u2_atom tap = j2_mbc(Pit, mas)(wir_r, axe);

            if ( _2 == tip ) {
              if ( u2_no == j2_mcy(Pit, ut, park)(wir_r, van, sut, way, tap) ) 
              {
                return u2_bl_bail(wir_r);
              }
              else pro = j2_mcx(Pit, ut, peek)(wir_r, van, p_sut, way, tap);
            }
            else {
              pro = c3__noun;
            }
            u2_rl_lose(wir_r, tap); 
            u2_rl_lose(wir_r, tip);

            return pro;
          }
        }
        case c3__cube: {
          p_sut = u2_t(sut);
          {
            u2_noun gud;

            if ( u2_none == (gud = u2_frag(axe, p_sut)) ) {
              return c3__void;
            } else {
              return u2_rx(wir_r, gud);
            }
          }
        }
        case c3__face: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            return j2_mcx(Pit, ut, peek)(wir_r, van, q_sut, way, axe);
          }
        }
        case c3__fork: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun hed = j2_mcx(Pit, ut, peek)(wir_r, van, p_sut, way, axe);
            u2_noun tal = j2_mcx(Pit, ut, peek)(wir_r, van, q_sut, way, axe);

            pro = j2_mby(Pit, fork)(wir_r, hed, tal);

            u2_rl_lose(wir_r, hed);
            u2_rl_lose(wir_r, tal);

            return pro;
          }
        } 
        case c3__hold: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun fop = j2_mcy(Pit, ut, play)(wir_r, van, p_sut, q_sut);

            pro = j2_mcx(Pit, ut, peek)(wir_r, van, fop, way, axe);

            u2_rl_lose(wir_r, fop);
            return pro;
          }
        }
      }
    }
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, peek)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, peek)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, way, axe, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &way, 
                                u2_cv_sam_3, &axe,
                                u2_cv_con, &van, 
                                0)) ||
         (u2_no == u2_stud(axe)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, peek)(wir_r, van, sut, way, axe);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, peek)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun way,                              //  retain
                        u2_noun axe)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "peek");

    if ( u2_none == hoc ) {
      c3_assert(!"register peek");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, 
                                      u2_cv_sam_2, u2_rx(wir_r, way), 
                                      u2_cv_sam_3, u2_rx(wir_r, axe), 
                                      0);

      if ( (u2_none == j2_mcj(Pit, ut, peek)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, peek)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, peek)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun way,                              //  retain
                        u2_noun axe)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, peek)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, peek)(wir_r, van, sut, way, axe);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, peek)(wir_r, van, sut, way, axe);
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
              had = j2_mcx(Pit, ut, peek)(wir_r, van, sut, way, axe);
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
            cor = j2_mci(Pit, ut, peek)(wir_r, van, sut, way, axe);
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
  j2_mcj(Pit, ut, peek)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, peek), SafeTier6, u2_none, u2_none },
    { }
  };
