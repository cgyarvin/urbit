/* j/6/flip.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, flip)(u2_wire wir_r, 
                    u2_weak hel)                                  //  retain
  {
    if ( (u2_none == mal) || (u2_none == buz) ) {
      return u2_none;
    }
    else {
      u2_noun p_mal, q_mal, p_buz, q_buz, pp_buz, pq_buz;

      if ( u2_yes == u2_as_p(mal, u2_nock_frag, &p_mal) ) {
        if ( u2_yes == u2_as_p(buz, u2_nock_frag, &p_buz) ) {
          return u2_rc(wir_r, 
                       u2_nock_frag, 
                       j2_mbc(Pit, peg)(wir_r, p_mal, p_buz));
        }
        else if ( u2_yes == u2_as_pq(buz, u2_nock_sail, &p_buz, &q_buz) &&
                  u2_yes == u2_as_p(p_buz, u2_nock_frag, &pp_buz) &&
                  u2_yes == u2_as_p(q_buz, u2_nock_frag, &pq_buz) )
        {
          return u2_rt
            (wir_r, u2_nock_sail, 
                   u2_rc(wir_r, u2_nock_frag, 
                                j2_mbc(Pit, peg)(wir_r, p_mal, pp_buz)),
                   u2_rc(wir_r, u2_nock_frag, 
                                j2_mbc(Pit, peg)(wir_r, p_mal, pq_buz)));
        }
        else return u2_rt(wir_r, u2_nock_flac, u2_rx(wir_r, mal), 
                                               u2_rx(wir_r, buz));
      }
      else if ( (u2_yes == u2_as_bush(mal, &p_mal, &q_mal)) &&
                (u2_yes == u2_dust(q_mal)) && 
                (_0 == u2_h(q_mal)) &&
                (_1 == u2_t(q_mal)) )
      {
        return u2_rt(wir_r, u2_nock_gant, u2_rx(wir_r, p_mal), 
                                          u2_rx(wir_r, buz));
      }
      else if ( (u2_yes == u2_as_p(buz, u2_nock_frag, &p_buz)) &&
                (u2_yes == u2_sing(_1, p_buz)) )
      {
        return u2_rx(wir_r, mal);
      }
      else return u2_rt(wir_r, u2_nock_flac, u2_rx(wir_r, mal), 
                                             u2_rx(wir_r, buz));
    }
  }
  u2_weak                                                         //  transfer
  j2_mb(Pit, flip)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun hel;

    if ( u2_none == (hel = u2_frag(4, cor)) ) {
      return u2_none;
    } else {
      return j2_mbc(Pit, flip)(wir_r, hel);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, flip)[] = {
    { ".3", j2_mb(Pit, flip), u2_no, u2_none, u2_none },
    { }
  };
