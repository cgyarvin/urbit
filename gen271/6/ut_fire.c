/* j/6/fire.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* logic
*/
  static u2_flag
  _fire_levy(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_noun dox,
             u2_noun hag)
  {
    if ( u2_nul == hag ) {
      return u2_yes;
    } else {
      u2_noun i_hag = u2_h(hag);
      u2_noun t_hag = u2_t(hag);
      u2_noun gen = i_hag;
      {
        u2_noun rib = u2_bn_hook(wir_r, van, "rib");
        u2_noun key = u2_bt(wir_r, u2_rx(wir_r, sut),
                                   u2_rx(wir_r, dox),
                                   u2_rx(wir_r, gen));
        u2_noun ret;
        
        if ( u2_yes == j2_mcc(Pit, in, has)(wir_r, rib, key) ) {
          ret = _fire_levy(wir_r, van, sut, dox, t_hag);
        }
        else {
          u2_noun rob = j2_mcc(Pit, in, put)(wir_r, rib, key);
          u2_noun von = u2_bn_cook(wir_r, van, "rib", rob);
          u2_noun vin = u2_bn_cook(wir_r, von, "vet", u2_no);
          u2_noun dis = j2_mcy(Pit, in, mint)(wir_r, von, sut, c3__noun, gen);
          u2_noun dat = j2_mcy(Pit, in, mint)(wir_r, vin, dox, c3__noun, gen);

          if ( u2_no == u2_sing(u2_t(dis), u2_t(dat)) ) {
            ret = u2_no;
          }
          else ret = _fire_levy(wir_r, van, sut, dox, t_hag);

          u2_rz(wir_r, von);
          u2_rz(wir_r, vin);
          u2_rz(wir_r, dis);
          u2_rz(wir_r, dat);
        }

        u2_rz(wir_r, rib);
        u2_rz(wir_r, key);

        return ret;
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, fire)(u2_wire wir_r, 
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun hag)                              //  retain
  {
    u2_noun p_sut, q_sut;
    u2_noun pq_sut, qq_sut, rq_sut;
    u2_flag vet = u2_bn_hook(wir_r, van, "vet");

    if ( u2_no == u2_b_pq(sut, c3__core, &p_sut, &q_sut) ) {
      return u2_bl_bail(wir_r);
    } else {
      u2_noun pq_sut, qq_sut, rq_sut;

      u2_bi_trel(q_sut, &pq_sut, &qq_sut, &rq_sut)
      {
        u2_noun dox = u2_bt
          (wir_r, c3__core, u2_rx(wir_r, qq_sut), u2_rx(wir_r, q_sut));
        u2_noun typ;

        if ( c3__wood != pq_sut ) {
          typ = u2_rx(wir_r, dox);

          if ( (u2_yes == vet) && 
               (u2_no == j2_mcy(Pit, ut, nest)(wir_r, van, qq_sut, p_sut)) )
          {
            printf("fire: metal: nest fail\n");

            return u2_bl_bail(wir_r);
          }
        }
        else {
          typ = u2_rx(wir_r, dox);

          if ( u2_yes == vet &&
               (u2_no == u2_sing(p_sut, qq_sut)) &&
               _fire_levy(wir_r, van, sut, dox, hag) )
          {
            printf("fire: wood: levy fail\n");
            return u2_bl_bail(wir_r);
          }
        }  
      }
    }
  }
  
/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, fire)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, fire)(u2_wire wir_r, 
                       u2_noun cor)                               //  retain
  {
    u2_noun sut, hag, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam, &hag, u2_cv_con, &van, 0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, fire)(wir_r, van, sut, hag);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, fire)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun hag)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "fire");

    if ( u2_none == hoc ) {
      c3_assert(!"register fire");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam, u2_rx(wir_r, hag), 0);

      if ( (u2_none == j2_mcj(Pit, ut, fire)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, fire)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, fire)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun hag)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, fire)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, fire)(wir_r, van, sut, hag);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, fire)(wir_r, van, sut, hag);
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
              had = j2_mcx(Pit, ut, fire)(wir_r, van, sut, hag);
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
            cor = j2_mci(Pit, ut, fire)(wir_r, van, sut, hag);
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
  j2_mcj(Pit, ut, fire)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, fire), SafeTier6, u2_none, u2_none },
    { }
  };


