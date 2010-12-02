/* j/3/peg.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, peg)(u2_wire wir_r, 
                   u2_atom a,                                     //  transfer
                   u2_atom b)                                     //  transfer
  {
    u2_atom c, d, e, f, g, h;

    c = u2_met(0, b);
    d = j2_mbc(Pit, dec)(wir_r, c);
    e = j2_mbc(Pit, lsh)(wir_r, _0, u2_rx(wir_r, d), 1);
    f = j2_mbc(Pit, sub)(wir_r, b, e);
    g = j2_mbc(Pit, lsh)(wir_r, _0, d, a);

    return j2_mbc(Pit, add)(wir_r, f, g);
  }
  u2_weak                                                         //  transfer
  j2_mb(Pit, peg)(u2_wire wir_r, 
                  u2_noun cor)                                    //  retain
  {
    u2_noun a, b;

    if ( (u2_no == u2_mean(cor, 8, &a, 9, &b, 0)) ||
         (u2_no == u2_stud(a)) ||
         (u2_no == u2_stud(b)) )
    {
      return u2_none;
    } else {
      return j2_mbc(Pit, peg)(wir_r, u2_rx(wir_r, a), u2_rx(wir_r, b));
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, peg)[] = {
    { ".3", j2_mb(Pit, peg), u2_yes, u2_none, u2_none },
    { }
  };
