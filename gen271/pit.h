/* include/pit.h
**
** This file is in the public domain.
*/
  /** Revision number for built-in jets.
  **/
#   define  Pit   watt_271

  /** Direct C interfaces.
  **/
    /** Tier 1.
    **/
      u2_weak                                                     //  transfer
      j2_mbc(Pit, add)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, bex)(u2_wire wir_r, 
                       u2_atom a);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, dec)(u2_wire wir_r, 
                       u2_atom a);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, div)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, gte)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, gth)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, lte)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, lth)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, mul)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, sub)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
    /** Tier 2.
    **/
      u2_weak                                                     //  transfer
      j2_mbc(Pit, bind)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, clap)(u2_wire wir_r,  
                        u2_noun a,                                //  retain
                        u2_noun b,                                //  retain
                        u2_noun c);                               //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, drop)(u2_wire wir_r, 
                        u2_noun a);                               //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, flop)(u2_wire wir_r, 
                        u2_noun a);                               //  retain
      u2_weak                                                     //  transfer
      j2_mbc(Pit, lent)(u2_wire wir_r, 
                        u2_noun a);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, levy)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, lien)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, need)(u2_wire wir_r, 
                        u2_noun a);                               //  retain


      u2_weak                                                     //  transfer
      j2_mbc(Pit, reel)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, roll)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, skim)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, skip)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, snag)(u2_wire wir_r, 
                        u2_atom a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, sort)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, turn)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, weld)(u2_wire wir_r, 
                        u2_noun a,                                //  retain
                        u2_noun b);                               //  retain
    /** Tier 3.
    **/
      u2_weak                                                     //  transfer
      j2_mbc(Pit, cat)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b,                                 //  retain
                       u2_atom c);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, con)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, cut)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b,                                 //  retain
                       u2_atom c,                                 //  retain
                       u2_atom d);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, dis)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain


      u2_weak                                                     //  transfer
      j2_mbc(Pit, end)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b,                                 //  retain
                       u2_atom c);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, lsh)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b,                                 //  retain
                       u2_atom c);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, met)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, mix)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, peg)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, rap)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_noun b);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, rip)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

      u2_weak                                                     //  transfer
      j2_mbc(Pit, rsh)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b,                                 //  retain
                       u2_atom c);                                //  retain
