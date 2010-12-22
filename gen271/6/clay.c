/* j/6/vane.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* 
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, clay)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut)                            //  retain
  {
    u2_noun p_sut, q_sut, r_sut;

    if ( u2_no == u2_as_pqr(sut, c3__core, &p_sut, &q_sut, &r_sut) ) {
      return u2_bl_bail(wir_r);
    } else{
      if ( u2_yes == u2_stud(q_sut) ) {
        return u2_rx(wir_r, sut);
      } else {
        u2_noun hq_sut = u2_h(q_sut);
        u2_noun pq_sut = u2_t(q_sut);
        u2_noun vet;

        if ( (u2_none == (vet = u2_frag(87, van))) ||
             ((vet != u2_no) && (vet != u2_yes)) )
        {
          return u2_bl_bail(wir_r);
        }
        else if ( c3__gray == hq_sut ) {
          if ( (vet == u2_yes) &&
               (u2_no == j2_mcy(Pit, vane, nest)(wir_r, van, pq_sut, p_sut)) )
          {
            fprintf(stderr, "clay: gray error\n");
            return u2_bl_bail(wir_r);
          }
          return u2_bq
            (wir_r, c3__core,
                    u2_rx(wir_r, p_sut),
                    c3__blue,
                    u2_rx(wir_r, r_sut));
        }
        else if ( c3__teal == hq_sut ) {
          if ( vet == u2_yes ) {
            u2_noun dox = u2_bq
              (wir_r, c3__core, 
                      u2_rx(wir_r, pq_sut), 
                      c3__pink, 
                      u2_rx(wir_r, r_sut));

            if ( u2_no == j2_mcy(Pit, vane, fair)
                (wir_r, van, sut, dox, r_sut) ) 
            {
              fprintf(stderr, "clay: pink error\n");

              u2_rl_lose(wir_r, dox);
              return u2_bl_bail(wir_r);
            }
            else u2_rl_lose(wir_r, dox);
          }
          return u2_rx(wir_r, sut);
        }
      }
    }
    return u2_bl_bail(wir_r);
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, clay)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut;

    if ( u2_none == (sut = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, clay)(wir_r, cor, sut);
    }
  }
