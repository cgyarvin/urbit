/* j/6/firm.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_flag
  j2_mcy(Pit, vane, firm)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun ref,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun bax = u2_bt(wir_r, sut, ref, gen);
    u2_noun ver = u2_frag(42, van); 

    if ( u2_yes == j2_mcc(Pit, in, has)(wir_r, ver, bax) ) {
      u2_rl_lose(wir_r, bax);
      return u2_yes;
    }
    else {
      u2_noun vor = j2_mcc(Pit, in, put)(wir_r, ver, bax);
      u2_noun von = u2_bn_molt(wir_r, van, 42, vor, 0);
      u2_noun old = j2_mcy(Pit, vane, make)(wir_r, van, sut, gen);
      u2_noun new = j2_mcy(Pit, vane, make)(wir_r, van, ref, gen);
      u2_flag pro = u2_sing(old, new);

      u2_rl_lose(wir_r, new);
      u2_rl_lose(wir_r, old);
      u2_rl_lose(wir_r, von);
      u2_rl_lose(wir_r, vor);

      return pro;
    }
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, firm)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, van, ref, gen;

    if ( (u2_no == u2_mean(cor, 8, &ref, 9, &gen, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, firm)(wir_r, van, sut, ref, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, firm)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, firm), u2_no, u2_none, u2_none },
    { }
  };
