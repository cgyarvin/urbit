/* j/6/fish.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  static u2_noun
  _fish_in(u2_wire wir_r,
           u2_noun van,
           u2_noun sut,
           u2_atom axe,
           u2_noun vit)
  {
    u2_noun p_sut, q_sut;

    if ( u2_yes == u2_stud(sut) ) switch ( sut ) {
      default: return u2_bl_bail(wir_r);

      case c3__atom: {
        u2_noun ton = u2_bt(wir_r, _3, _0, u2_rx(wir_r, axe));
        u2_noun pro = j2_mby(Pit, flip)(wir_r, ton);

        u2_rl_lose(wir_r, ton);
        return pro;
      }
      case c3__noun: {
        return u2_bc(wir_r, _1, _0);
      }
      case c3__void: {
        return u2_bc(wir_r, _1, _1);
      }
    }
    else switch ( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun hut = u2_bt(wir_r, _3, _0, u2_rx(wir_r, axe));
          u2_noun lef = j2_mbc(Pit, peg)(wir_r, axe, _2);
          u2_noun rit = j2_mbc(Pit, peg)(wir_r, axe, _3);
          u2_noun hed = _fish_in(wir_r, van, p_sut, lef, vit);
          u2_noun tal = _fish_in(wir_r, van, q_sut, rit, vit);
          u2_noun hob = j2_mby(Pit, flan)(wir_r, hed, tal);
          u2_noun vug = j2_mby(Pit, flan)(wir_r, hut, hob);

          u2_rl_lose(wir_r, hob);
          u2_rl_lose(wir_r, tal);
          u2_rl_lose(wir_r, hed);
          u2_rl_lose(wir_r, rit);
          u2_rl_lose(wir_r, lef);
          u2_rl_lose(wir_r, hut);

          return vug;
        }
      }
      case c3__core: {
        return u2_bc(wir_r, _0, _0);
      }
      case c3__cube: {
        p_sut = u2_t(sut);
        {
          return u2_bt
            (wir_r, _5, 
                    u2_bc(wir_r, _1, u2_rx(wir_r, p_sut)),
                    u2_bc(wir_r, _0, u2_rx(wir_r, axe)));
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return _fish_in(wir_r, van, q_sut, axe, vit);
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun hed = _fish_in(wir_r, van, p_sut, axe, vit);
          u2_noun tal = _fish_in(wir_r, van, q_sut, axe, vit);
          u2_noun pro = j2_mby(Pit, flor)(wir_r, hed, tal);

          u2_rl_lose(wir_r, hed);
          u2_rl_lose(wir_r, tal);

          return pro;
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, vit, sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, vit, sut);
            u2_noun fop = j2_mcy(Pit, ut, play)(wir_r, van, p_sut, q_sut);
            u2_noun pro = _fish_in(wir_r, van, fop, axe, zoc);

            u2_rl_lose(wir_r, fop);
            u2_rl_lose(wir_r, zoc);

            return pro;
          }
        }
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, fish)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_atom axe)                              //  retain
  {
    return _fish_in(wir_r, van, sut, axe, u2_nul);
  }


/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, fish)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, fish)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, axe, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam, &axe, u2_cv_con, &van, 0)) ||
         (u2_no == u2_stud(axe)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, fish)(wir_r, van, sut, axe);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, fish)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun axe)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "fish");

    if ( u2_none == hoc ) {
      c3_assert(!"register fish");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam, u2_rx(wir_r, axe), 0);

      if ( (u2_none == j2_mcj(Pit, ut, fish)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, fish)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, fish)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun axe)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, fish)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, fish)(wir_r, van, sut, axe);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, fish)(wir_r, van, sut, axe);
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
              had = j2_mcx(Pit, ut, fish)(wir_r, van, sut, axe);
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
            cor = j2_mci(Pit, ut, fish)(wir_r, van, sut, axe);
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
  j2_mcj(Pit, ut, fish)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, fish), SafeTier6, u2_none, u2_none },
    { }
  };
