/* j/6/make.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, make)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun pox = j2_mcy(Pit, vane, mill)(wir_r, van, sut, gen);
    u2_noun t_pox = u2_t(pox);

    u2_rl_gain(wir_r, t_pox);
    u2_rl_lose(wir_r, pox); 
    return t_pox;
  }
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, make)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, gen, van;

    if ( (u2_no == u2_mean(cor, 4, &gen, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, make)(wir_r, van, sut, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, make)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, make), u2_no, u2_none, u2_none },
    { }
  };
