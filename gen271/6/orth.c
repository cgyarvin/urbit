/* j/6/orth.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  static u2_flag
  _orth_in(u2_wire wir_r,
           u2_noun van,
           u2_noun sut, 
           u2_noun ref,
           u2_noun bix)
  {
    u2_noun p_sut, q_sut, r_sut;
    u2_noun p_ref, q_ref;

    if ( u2_no == u2_dust(sut) ) switch ( sut ) {
      default: goto fail;

      case c3__atom: {
        if ( u2_no == u2_dust(ref) ) switch ( ref ) {
          default: flip: return _orth_in(wir_r, van, ref, sut, bix);

          case c3__atom: return u2_no;
        } 
        else switch u2_h(ref) {
          default: goto flip;
          
          case c3__cell: return u2_yes;
        }
      }
      case c3__blot: {
        return u2_yes;
      }
      case c3__blur: {
        return j2_mcy(Pit, vane, nest)(wir_r, van, c3__blot, ref);
      }
    } 
    else switch ( u2_h(sut) ) {
      default: fail: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          if ( (u2_yes == u2_dust(ref)) && 
               (c3__cell == u2_h(ref)) &&
               (u2_yes == u2_as_cell(u2_t(ref), &p_ref, &q_ref)) )
          {
            return u2_or(_orth_in(wir_r, van, p_sut, p_ref, bix),
                         _orth_in(wir_r, van, q_sut, q_ref, bix));
          }
          else goto flip;
        }
      }
      case c3__core: {
        if ( u2_no == u2_as_trel(u2_t(sut), &p_sut, &q_sut, &r_sut) ) {
          goto fail;
        } else {
          u2_noun faz = u2_bt(wir_r, c3__cell, p_sut, c3__blur);
          u2_flag ret = _orth_in(wir_r, van, faz, ref, bix);

          u2_rl_lose(wir_r, faz);
          return ret;
        }
      }
      case c3__cube: { 
        p_sut = u2_t(sut);
        {
          if ( u2_no == u2_dust(ref) ) switch ( ref ) {
            default: goto flip;

            case c3__atom: return u2_dust(p_sut);
          } 
          else switch u2_h(ref) {
            default: goto flip;
           
            case c3__cell: {
              if ( u2_no == u2_dust(p_sut) ) {
                return u2_yes;
              } else {
                u2_noun goz = u2_bt
                  (wir_r, c3__cell,
                          u2_bc(wir_r, c3__cube, u2_h(p_sut)),
                          u2_bc(wir_r, c3__cube, u2_t(p_sut)));
                u2_flag ret = _orth_in(wir_r, van, goz, ref, bix);

                u2_rl_lose(wir_r, goz);
                return ret;
              }
            }
            case c3__cube: {
              return u2_not(u2_sing(p_sut, u2_t(ref)));
            }
          }
        }
      case c3__face: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          return _orth_in(wir_r, van, q_sut, ref, bix);
        }
      }
      case c3__fork: {
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          return u2_and(_orth_in(wir_r, van, p_sut, ref, bix),
                        _orth_in(wir_r, van, q_sut, ref, bix));
        }
      }
      case c3__hold:
        if ( u2_no == u2_as_cell(u2_t(sut), &p_sut, &q_sut) ) {
          goto fail;
        } else {
          u2_noun tor = u2_bc(wir_r, u2_rx(wir_r, ref), 
                                     u2_rx(wir_r, sut));

          if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, bix, tor)) ) {
            u2_rl_lose(wir_r, tor);
            return u2_yes;
          } 
          else {
            u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, bix, tor);
            u2_type fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
            u2_noun ret = _orth_in(wir_r, van, fop, ref, zoc);

            u2_rl_lose(wir_r, fop);
            u2_rl_lose(wir_r, zoc);
            u2_rl_lose(wir_r, tor);

            return ret;
          }
        }
      }
    } 
  }
  u2_flag                                                         //  transfer
  j2_mcx(Pit, vane, orth)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref)                            //  retain
  {
    return _orth_in(wir_r, van, sut, ref, u2_nul);
  }
  
/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, orth)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, orth)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, ref, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam, &ref, u2_cv_con, &van, 0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, vane, orth)(wir_r, van, sut, ref);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, vane, orth)(u2_wire wir_r,
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain 
                          u2_noun ref)                            //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "orth");

    if ( u2_none == hoc ) {
      c3_assert(!"register orth");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam, u2_rx(wir_r, ref), 0);

      if ( (u2_none == j2_mcj(Pit, vane, orth)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, vane, orth)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, orth)(u2_wire wir_r,
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref)                            //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, vane, orth)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, vane, orth)(wir_r, van, sut, ref);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, vane, orth)(wir_r, van, sut, ref);
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
              had = j2_mcx(Pit, vane, orth)(wir_r, van, sut, ref);
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
            cor = j2_mci(Pit, vane, orth)(wir_r, van, sut, ref);
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
  j2_mcj(Pit, vane, orth)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, orth), SafeTier6, u2_none, u2_none },
    { }
  };


