/* j/6/rake.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../Pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, rake)(u2_wire wir_r, 
                    u2_noun gen)                                  //  retain
  {
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, rake)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun gen;

    if ( u2_none == (gen = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, rake)(wir_r, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, rake)[] = {
    { ".3", c3__hevy, j2_mb(Pit, rake), SafeTier6_c, u2_none, u2_none },
    { }
  };
