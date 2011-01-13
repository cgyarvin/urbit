/* j/6/tuck.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

  static u2_noun
  _tuck_pur(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun, u2_atom);


/* internals
*/
  static u2_noun
  _tuck_term(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_atom p_wer,
             u2_noun p_giv)
  {
    u2_noun p_sut, q_sut, r_sut;

    if ( u2_yes == u2_stud(sut) ) switch( sut ) {
      default: return u2_bl_bail(wir_r);
    } else switch( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else {
          if ( _1 == p_wer ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun tip = j2_mbc(Pit, cap)(wir_r, p_wer);
            u2_noun tap = j2_mbc(Pit, mas)(wir_r, p_wer);
            u2_noun pro;

            if ( _2 == tip ) {
              pro = u2_bt
                (wir_r, c3__cell, _tuck_term(wir_r, van, p_sut, tap, p_giv), 
                                  u2_bx(wir_r, q_sut));
            }
            else {
              pro = u2_bt
                (wir_r, c3__cell, u2_bx(wir_r, p_sut),
                                  _tuck_term(wir_r, van, q_sut, tap, p_giv));
            }
            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
      }
      case c3__core: {
        if ( u2_no == u2_as_qual(sut, 0, &p_sut, &q_sut, &r_sut) ) {
          return u2_bl_bail(wir_r);
        } else {
          if ( _1 == p_wer ) {
            return u2_bx(wir_r, p_giv);
          }
          else {
            u2_noun tip = j2_mbc(Pit, cap)(wir_r, p_wer);
            u2_noun tap = j2_mbc(Pit, mas)(wir_r, p_wer);
            u2_noun pro;

            if ( _2 == tip ) {
              u2_noun gac = _tuck_term(wir_r, van, p_sut, tap, p_giv);
              u2_noun huq;

              if ( u2_yes == u2_stud(q_sut) ) switch ( q_sut ) {
                default: return u2_bl_bail(wir_r);

                case c3__blue: {
                  huq = u2_bc(wir_r, c3__gray, u2_bx(wir_r, p_sut));
                  break;
                }
                case c3__pink: {
                  huq = u2_bc(wir_r, c3__teal, u2_bx(wir_r, p_sut));
                  break;
                }
              }
              else huq = u2_bx(wir_r, q_sut);

              pro = u2_bq(wir_r, c3__core, gac, huq, u2_bx(wir_r, r_sut));
            }
            else {
              return u2_bl_bail(wir_r);
            }
            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return u2_bt
            (wir_r, c3__face, u2_bx(wir_r, p_sut), u2_bx(wir_r, p_giv));
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return j2_mby(Pit, eith)
            (wir_r, _tuck_term(wir_r, van, p_sut, p_wer, p_giv),
                    _tuck_term(wir_r, van, q_sut, p_wer, p_giv));
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
          u2_noun pro = _tuck_term(wir_r, van, fop, p_wer, p_giv);

          u2_rl_lose(wir_r, fop);
          return pro;
        }
      }
    }
  }

  static u2_noun
  _tuck_frag(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_atom pi_pur,
             u2_noun p_giv)
  {
    u2_noun p_sut, q_sut, r_sut;

    if ( _1 == pi_pur ) {
      return u2_rx(wir_r, p_giv);
    }
    else {
      if ( u2_yes == u2_stud(sut) ) switch( sut ) {
        default: return u2_bl_bail(wir_r);

        case c3__blur: {
          u2_noun fop = u2_bt(wir_r, c3__cell, c3__blur, c3__blur);
          u2_noun pro = _tuck_frag(wir_r, van, fop, pi_pur, p_giv);

          u2_rl_lose(wir_r, fop);
          return pro;
        }
      } else switch( u2_h(sut) ) {
        default: return u2_bl_bail(wir_r);

        case c3__cell: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun tip = j2_mbc(Pit, cap)(wir_r, pi_pur);
            u2_noun tap = j2_mbc(Pit, mas)(wir_r, pi_pur);
            u2_noun pro;

            if ( _2 == tip ) {
              pro = u2_bt
                (wir_r, c3__cell, 
                       _tuck_frag(wir_r, van, p_sut, tap, p_giv), 
                       u2_bx(wir_r, q_sut));
            }
            else {
              pro = u2_bt
                (wir_r, c3__cell, 
                        u2_bx(wir_r, p_sut),
                       _tuck_frag(wir_r, van, q_sut, tap, p_giv));
            }
            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
        case c3__core: {
          if ( u2_no == u2_as_qual(sut, 0, &p_sut, &q_sut, &r_sut) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun tip = j2_mbc(Pit, cap)(wir_r, pi_pur);
            u2_noun tap = j2_mbc(Pit, mas)(wir_r, pi_pur);
            u2_noun pro;

            if ( _2 != tip ) {
              return u2_bl_bail(wir_r);
            } else {
              u2_noun gac = _tuck_frag(wir_r, van, p_sut, tap, p_giv);
              u2_noun huq;

              if ( u2_yes == u2_stud(q_sut) ) switch ( q_sut ) {
                default: return u2_bl_bail(wir_r);

                case c3__blue: {
                  huq = u2_bc(wir_r, c3__gray, u2_bx(wir_r, p_sut));
                  break;
                }
                case c3__pink: {
                  huq = u2_bc(wir_r, c3__teal, u2_bx(wir_r, p_sut));
                  break;
                }
              }
              else huq = u2_bx(wir_r, q_sut);

              pro = u2_bq(wir_r, c3__core, gac, huq, u2_bx(wir_r, r_sut));
            }
            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
        case c3__cube: {
          p_sut = u2_t(sut);

          if ( u2_no == u2_dust(p_sut) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun fop = u2_bt(wir_r, c3__cell, 
                                       u2_bc(wir_r, c3__cube, u2_h(p_sut)),
                                       u2_bc(wir_r, c3__cube, u2_t(p_sut)));
            u2_noun pro = _tuck_frag(wir_r, van, fop, pi_pur, p_giv);

            u2_rl_lose(wir_r, fop);
            return pro;
          }
        }
        case c3__face: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else { 
            return u2_bt
              (wir_r, c3__face,
                      u2_bx(wir_r, p_sut), 
                      _tuck_frag(wir_r, van, q_sut, pi_pur, p_giv));
          }
        }
        case c3__fork: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            return j2_mby(Pit, eith)
              (wir_r, _tuck_frag(wir_r, van, p_sut, pi_pur, p_giv),
                      _tuck_frag(wir_r, van, q_sut, pi_pur, p_giv));
          }
        } 
        case c3__hold: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
            u2_noun pro = _tuck_frag(wir_r, van, fop, pi_pur, p_giv);

            u2_rl_lose(wir_r, fop);
            return pro;
          }
        }
      }
    }
  }

  static u2_noun                                                  //  transfer
  _tuck_pur(u2_wire wir_r, 
            u2_noun van,                                          //  retain
            u2_noun sut,                                          //  retain
            u2_noun pur,                                          //  retain
            u2_noun boz,                                          //  retain
            u2_noun rix,                                          //  retain
            u2_atom axe)                                          //  retain
  {
    u2_noun tuk;

    if ( u2_nul == pur ) {
      u2_noun lof = j2_mcy(Pit, vane, mill)(wir_r, van, boz, rix);
      u2_noun p_lof = u2_h(lof);
      u2_noun q_lof = u2_t(lof);

      tuk = u2_bt(wir_r, u2_rx(wir_r, p_lof), axe, u2_rx(wir_r, q_lof));
      u2_rl_lose(wir_r, lof);

      return tuk;
    }
    else {
      u2_noun i_pur = u2_h(pur);
      u2_noun t_pur = u2_t(pur);

      if ( u2_yes == u2_stud(i_pur) ) {
        u2_noun wer = j2_mcy(Pit, vane, find)(wir_r, van, sut, i_pur);
        u2_noun p_wer, r_wer;

        u2_as_trel(wer, &p_wer, 0, &r_wer);
        {
          u2_noun nax   = j2_mbc(Pit, peg)(wir_r, axe, p_wer); 
          u2_noun giv   = _tuck_pur(wir_r, van, r_wer, t_pur, boz, rix, nax);
          u2_noun p_giv = u2_h(giv);
          u2_noun q_giv = u2_t(giv);
          u2_noun typ   = _tuck_term(wir_r, van, sut, p_wer, p_giv);
          u2_noun tuk;

          tuk = u2_bc(wir_r, typ, u2_rx(wir_r, q_giv));

          u2_rl_lose(wir_r, nax);
          u2_rl_lose(wir_r, giv);
          u2_rl_lose(wir_r, wer);

          return tuk;
        }
      }
      else {
        u2_noun pi_pur = u2_t(i_pur);
        u2_noun vas    = j2_mcy(Pit, vane, peek)(wir_r, van, sut, pi_pur);
        u2_noun rox;

        if ( u2_nul == t_pur ) {
          rox = j2_mcy(Pit, vane, snap)(wir_r, van, vas, boz, rix);
        } else rox = u2_rx(wir_r, rix);
        
        {
          u2_noun nax   = j2_mbc(Pit, peg)(wir_r, axe, pi_pur); 
          u2_noun giv   = _tuck_pur(wir_r, van, vas, t_pur, boz, rox, nax);
          u2_noun p_giv = u2_h(giv);
          u2_noun q_giv = u2_t(giv);
          u2_noun typ   = _tuck_frag(wir_r, van, sut, pi_pur, p_giv);
          u2_noun tuk;

          tuk = u2_bc(wir_r, typ, u2_rx(wir_r, q_giv));

          u2_rl_lose(wir_r, rox);
          u2_rl_lose(wir_r, nax);
          u2_rl_lose(wir_r, giv);

          return tuk;
        }
      }
    }
  }

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcx(Pit, vane, tuck)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun rup,                            //  retain
                          u2_noun boz,                            //  retain
                          u2_noun rix)                            //  retain
  {
    u2_noun pur = j2_mbc(Pit, flop)(wir_r, rup);
    u2_noun pro = _tuck_pur(wir_r, van, sut, pur, boz, rix, _1);

    u2_rl_lose(wir_r, pur);
    return pro;
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, tuck)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, tuck)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun van, sut, rup, boz, rix;

    if ( (u2_no == u2_mean(cor, u2_cv_sam_2, &rup, 
                                u2_cv_sam_6, &boz,
                                u2_cv_sam_7, &rix,
                                u2_cv_con, &van, 
                                0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, vane, tuck)(wir_r, van, sut, rup, boz, rix);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, vane, tuck)(u2_wire wir_r,
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun rup,                            //  retain
                          u2_noun boz,                            //  retain
                          u2_noun rix)                            //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "tuck");

    if ( u2_none == hoc ) {
      c3_assert(!"register tuck");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam_2, u2_rx(wir_r, rup), 
                                           u2_cv_sam_6, u2_rx(wir_r, boz),
                                           u2_cv_sam_7, u2_rx(wir_r, rix),
                                           0);

      if ( (u2_none == j2_mcj(Pit, vane, tuck)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, vane, tuck)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun
  j2_mcy(Pit, vane, tuck)(u2_wire wir_r,
                          u2_noun van,
                          u2_noun sut,
                          u2_noun rup,
                          u2_noun boz,
                          u2_noun rix)
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, vane, tuck)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_none;

      case u2_jet_live: {
        return j2_mcx(Pit, vane, tuck)(wir_r, van, sut, rup, boz, rix);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, vane, tuck)(wir_r, van, sut, rup, boz, rix);
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
              had = j2_mcx(Pit, vane, tuck)(wir_r, van, sut, rup, boz, rix);
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
            cor = j2_mci(Pit, vane, tuck)(wir_r, van, sut, rup, boz, rix);
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
  j2_mcj(Pit, vane, tuck)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, tuck), SafeTier6_b, u2_none, u2_none },
    { }
  };

