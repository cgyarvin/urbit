/* j/6/hack.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, hack)(u2_wire wir_r, 
                    u2_noun gen)                                  //  retain
  {
    u2_noun p_gen, q_gen;
    u2_noun ret;

    if ( u2_yes == u2_dust(gen) ) {
      u2_noun h_gen = u2_h(gen);

      if ( (c3__zpcb == h_gen) || (c3__bnld == h_gen) ) {
        if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun pyr = j2_mby(Pit, hack)(wir_r, q_gen);

          if ( u2_yes == u2_h(pyr) ) {
            ret = u2_bt
              (wir_r, u2_yes,
                      u2_bt(wir_r, h_gen, 
                                   u2_rx(wir_r, p_gen), 
                                   u2_rx(wir_r, u2_h(u2_t(pyr)))),
                      u2_bt(wir_r, h_gen, 
                                   u2_rx(wir_r, p_gen), 
                                   u2_rx(wir_r, u2_t(u2_t(pyr)))));
          }
          else {
            ret = u2_bc
              (wir_r, u2_no,
                      u2_bt(wir_r, h_gen, 
                                   u2_rx(wir_r, p_gen), 
                                   u2_rx(wir_r, u2_t(pyr))));
          }
          u2_rl_lose(wir_r, pyr);
          return ret;
        }
      }
      else if ( c3__dgdp == u2_h(gen) ) {
        if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return u2_bt(wir_r, u2_yes, 
                              u2_rx(wir_r, p_gen),
                              u2_rx(wir_r, q_gen));
        }
      }
    }

    {
      u2_noun voq = j2_mby(Pit, open)(wir_r, gen);

      if ( u2_yes == u2_sing(voq, gen) ) {
        return u2_bc(wir_r, u2_no, voq);
      }
      else {
        ret = j2_mby(Pit, hack)(wir_r, voq); 

        u2_rl_lose(wir_r, voq);
        return ret;
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mb(Pit, hack)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun gen;

    if ( u2_none == (gen = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, hack)(wir_r, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, hack)[] = {
    { ".3", c3__hevy, j2_mb(Pit, hack), SafeTier6_c, u2_none, u2_none },
    { }
  };
