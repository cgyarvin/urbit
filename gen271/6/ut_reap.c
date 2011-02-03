/* j/6/reap.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  static u2_noun
  _reap_sint(u2_wire, u2_noun, u2_noun, u2_noun, u2_noun);

  static u2_noun
  _reap_dext(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun ref,
             u2_noun bol)
  {
    u2_noun p_sut, q_sut;
    u2_noun p_ref, q_ref;

    if ( u2_yes == u2_stud(sut) ) switch ( sut ) {
      default: return u2_bl_bail(wir_r);

      case c3__atom: {
        if ( u2_yes == u2_stud(ref) ) switch ( ref ) {
          default: return _reap_sint(wir_r, van, sut, ref, bol);

          case c3__atom:  {
            return c3__atom;
          }
        } else switch ( u2_h(ref) ) {
          default: return _reap_sint(wir_r, van, sut, ref, bol);

          case c3__cube: {
            p_ref = u2_t(ref);
            {
              if ( u2_yes == u2_dust(p_ref) ) {
                return c3__blot;
              } else {
                return u2_bx(wir_r, ref);
              }
            }
          }
        }
      }
      case c3__blot: {
        return c3__blot;
      }
      case c3__blur: {
        return u2_bx(wir_r, ref);
      }
    } else switch ( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun p_ref, q_ref;

          if ( u2_yes == u2_stud(ref) ) switch ( ref ) {
            default: return _reap_sint(wir_r, van, sut, ref, bol);
          } 
          else switch ( u2_h(ref) ) {
            default: return _reap_sint(wir_r, van, sut, ref, bol);

            case c3__cell: {
              if ( (u2_no == u2_as_trel(ref, 0, &p_ref, &q_ref)) ) {
                return u2_bl_bail(wir_r);
              } else {
                return j2_mby(Pit, cell)
                  (wir_r, _reap_dext(wir_r, van, p_sut, p_ref, bol),
                          _reap_dext(wir_r, van, q_sut, q_ref, bol));
              }
            }
            case c3__cube: {
              p_ref = u2_t(ref);
              {
                if ( u2_no == u2_dust(p_ref) ) {
                  return c3__blot;
                }
                else {
                  u2_noun heg, vil, pro;

                  heg = u2_bc(wir_r, c3__cube, u2_rx(wir_r, u2_h(p_ref)));
                  vil = u2_bc(wir_r, c3__cube, u2_rx(wir_r, u2_t(p_ref)));

                  pro = j2_mby(Pit, cell)
                    (wir_r, _reap_dext(wir_r, van, p_sut, heg, bol),
                            _reap_dext(wir_r, van, q_sut, vil, bol));

                  u2_rl_lose(wir_r, heg); 
                  u2_rl_lose(wir_r, vil);
                  return pro;
                }
              }
            }
          }
        }
      }
      case c3__core: {
        return u2_bx(wir_r, sut);
      }
      case c3__cube: {
        p_sut = u2_t(sut);
        {
          if ( u2_yes == u2_stud(ref) ) switch ( ref ) {
            default: return _reap_sint(wir_r, van, sut, ref, bol);

            case c3__atom: {
              if ( u2_no == u2_stud(p_sut) ) {
                return c3__blot;
              } else return u2_bx(wir_r, sut);
            }
          } else switch ( u2_h(ref) ) {
            default: return _reap_sint(wir_r, van, sut, ref, bol);

            case c3__cell: {
              if ( (u2_no == u2_as_trel(ref, 0, &p_ref, &q_ref)) ) {
                return u2_bl_bail(wir_r);
              } else {
                if ( u2_no == u2_dust(p_sut) ) {
                  return c3__blot;
                }
                else {
                  u2_noun heg, vil, pro;

                  heg = u2_bc(wir_r, c3__cube, u2_rx(wir_r, u2_h(p_ref)));
                  vil = u2_bc(wir_r, c3__cube, u2_rx(wir_r, u2_t(p_ref)));

                  pro = j2_mby(Pit, cell)
                    (wir_r, _reap_dext(wir_r, van, p_sut, heg, bol),
                            _reap_dext(wir_r, van, q_sut, vil, bol));

                  u2_rl_lose(wir_r, heg); 
                  u2_rl_lose(wir_r, vil);
                  return pro;
                }
              }
            }
            case c3__cube: {
              p_ref = u2_t(ref);
              {
                if ( u2_yes == u2_sing(p_sut, p_ref) ) {
                  return u2_bx(wir_r, sut);
                } 
                else return c3__blot;
              }
            }
          }
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return j2_mby(Pit, face)
            (wir_r, p_sut, _reap_dext(wir_r, van, q_sut, ref, bol));
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return j2_mby(Pit, fork)
            (wir_r, _reap_dext(wir_r, van, p_sut, ref, bol),
                    _reap_dext(wir_r, van, q_sut, ref, bol));
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun yet = j2_mcy(Pit, ut, play)(wir_r, van, p_sut, q_sut);
          u2_noun woz;

          woz = _reap_dext(wir_r, van, yet, ref, bol);
          if ( u2_yes == u2_sing(woz, yet) ) {
            u2_rl_lose(wir_r, yet);
            u2_rl_lose(wir_r, woz);

            return u2_bx(wir_r, sut);
          }
          else {
            u2_rl_lose(wir_r, yet);

            return woz;
          }
        }
      }
    }
  }
  static u2_noun
  _reap_sint(u2_wire wir_r,
             u2_noun van,
             u2_noun sut, 
             u2_noun ref,
             u2_noun bol)
  {
    u2_noun p_ref, q_ref, r_ref;

    if ( u2_yes == u2_stud(ref) ) switch ( ref ) {
      default: return c3__blot;

      case c3__blur: {
        return u2_bx(wir_r, sut);
      }
    } else switch ( u2_h(ref) ) {
      default: return c3__blot;

      case c3__core: {
        if ( u2_no == u2_as_qual(ref, 0, &p_ref, &q_ref, &r_ref) ) {
          return u2_bl_bail(wir_r);
        } else {
          u2_noun gum = u2_bt(wir_r, c3__cell, u2_bx(wir_r, p_ref), c3__blur);
          u2_noun pro = _reap_dext(wir_r, van, sut, gum, bol);

          u2_rl_lose(wir_r, gum);
          return pro;
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(ref, 0, &p_ref, &q_ref)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return _reap_dext(wir_r, van, sut, q_ref, bol);
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(ref, 0, &p_ref, &q_ref)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return j2_mby(Pit, fork)
            (wir_r, _reap_dext(wir_r, van, sut, p_ref, bol),
                    _reap_dext(wir_r, van, sut, q_ref, bol));
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(ref, 0, &p_ref, &q_ref)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, bol, ref)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, bol, ref);
            u2_type fop = j2_mcy(Pit, ut, play)(wir_r, van, p_ref, q_ref);
            u2_noun hiv = _reap_dext(wir_r, van, sut, fop, zoc);

            u2_rl_lose(wir_r, fop);
            u2_rl_lose(wir_r, zoc);

            return hiv;
          }
        }
      }
    }
  }

  u2_flag                                                         //  transfer
  j2_mcx(Pit, ut, reap)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun ref)                              //  retain
  {
    return _reap_dext(wir_r, van, sut, ref, u2_nul);
  }
 
/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, reap)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, reap)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, ref, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam, &ref, u2_cv_con, &van, 0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, reap)(wir_r, van, sut, ref);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, reap)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun ref)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "reap");

    if ( u2_none == hoc ) {
      c3_assert(!"register reap");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam, u2_rx(wir_r, ref), 0);

      if ( (u2_none == j2_mcj(Pit, ut, reap)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, reap)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, reap)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun ref)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, reap)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, reap)(wir_r, van, sut, ref);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, reap)(wir_r, van, sut, ref);
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
              had = j2_mcx(Pit, ut, reap)(wir_r, van, sut, ref);
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
            cor = j2_mci(Pit, ut, reap)(wir_r, van, sut, ref);
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
  j2_mcj(Pit, ut, reap)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, reap), SafeTier6, u2_none, u2_none },
    { }
  };


