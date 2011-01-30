/* j/6/core.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, core)(u2_wire wir_r, 
                    u2_noun vod,                                  //  retain
                    u2_noun suz,                                  //  retain
                    u2_noun hel,                                  //  retain
                    u2_noun don)                                  //  retain
  {
    if ( c3__blot == vod ) {
      return c3__blot;
    }
    else {
      u2_noun caf;

      if ( u2_no == u2_dust(hel) ) {
        if ( c3__blue == hel ) {
          if ( u2_yes == u2_sing(vod, suz) ) {
            caf = c3__blue;
          } else caf = u2_bc(wir_r, c3__gray, u2_rx(wir_r, suz));
        }
        else if ( c3__pink == hel ) {
          if ( u2_yes == u2_sing(vod, suz) ) {
            caf = c3__pink;
          } else caf = u2_bc(wir_r, c3__teal, u2_rx(wir_r, suz));
        }
        else return u2_bl_bail(wir_r);
      } else {
        if ( c3__gray == u2_h(hel) ) {
          if ( u2_yes == u2_sing(vod, u2_t(hel)) ) {
            caf = c3__blue;
          } else {
            caf= u2_rx(wir_r, hel);
          }
        }
        else if ( c3__teal == u2_h(hel) ) {
          if ( u2_yes == u2_sing(vod, u2_t(hel)) ) {
            caf = c3__pink;
          } else {
            caf= u2_rx(wir_r, hel);
          }
        }
        else return u2_bl_bail(wir_r);
      }
      return u2_bq(wir_r, c3__core, u2_rx(wir_r, vod), caf, u2_rx(wir_r, don));
    }
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, core)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun vod, suz, hel, don;

    if ( u2_no == u2_mean(cor, 8, &vod, 18, &suz, 38, &hel, 39, &don, 0) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, core)(wir_r, vod, suz, hel, don);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, core)[] = {
    { ".3", c3__hevy, j2_mb(Pit, core), SafeTier6_c, u2_none, u2_none },
    { }
  };
