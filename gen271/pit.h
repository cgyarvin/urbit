/* include/pit.h
**
** This file is in the public domain.
*/
  /** Revision number for built-in jets.
  **/
#   define  Pit   watt_271

  /** Cosmetic noun types.
  **/
#if 0
  // get them from funj.h for now
  //
    typedef u2_noun u2_bank;
    typedef u2_noun u2_cord;
    typedef u2_noun u2_door;
    typedef u2_noun u2_gene;
    typedef u2_noun u2_home;
    typedef u2_noun u2_init;
    typedef u2_noun u2_menu;
    typedef u2_noun u2_plan;
    typedef u2_noun u2_plot;
    typedef u2_noun u2_rack;
    typedef u2_noun u2_rung;
    typedef u2_noun u2_rope;
    typedef u2_noun u2_spec;
    typedef u2_noun u2_tack;
    typedef u2_noun u2_type;
    typedef u2_noun u2_prep;
    typedef u2_noun u2_dump;
#endif

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
      j2_mbc(Pit, dor)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

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
      j2_mbc(Pit, gor)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain

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

      u2_weak                                                     //  transfer
      j2_mbc(Pit, vor)(u2_wire wir_r, 
                       u2_atom a,                                 //  retain
                       u2_atom b);                                //  retain
  
    /** Tier 4.
    **/
      u2_weak                                                     //  transfer
      j2_mcc(Pit, in, put)(u2_wire wir_r, 
                           u2_noun a,                             //  retain
                           u2_noun b);                            //  retain

      u2_flag 
      j2_mcc(Pit, in, has)(u2_wire wir_r, 
                           u2_noun a,                             //  retain
                           u2_noun b);                            //  retain
    /** Tier 6.
    **/
      u2_noun                                                     //  transfer
      j2_mby(Pit, cons)(u2_wire wir_r, 
                        u2_noun vur,                              //  retain
                        u2_noun sed);                             //  retain
      u2_noun                                                     //  transfer
      j2_mby(Pit, hike)(u2_wire wir_r, 
                        u2_noun axe,                              //  retain
                        u2_noun pac);                             //  retain

      u2_noun                                                     //  transfer
      j2_mcy(Pit, vane, make)(u2_wire wir_r, 
                              u2_noun van,                        //  retain
                              u2_noun sut,                        //  retain
                              u2_noun gen);                       //  retain

      u2_noun                                                     //  transfer
      j2_mcy(Pit, vane, mill)(u2_wire wir_r, 
                              u2_noun van,                        //  retain
                              u2_noun sut,                        //  retain
                              u2_noun gen);                       //  retain
      u2_flag                                                     //  transfer
      j2_mcy(Pit, vane, nest)(u2_wire wir_r, 
                              u2_noun van,                        //  retain
                              u2_noun sut,                        //  retain
                              u2_noun bon);                       //  retain
      u2_noun                                                     //  transfer
      j2_mcy(Pit, vane, play)(u2_wire wir_r, 
                              u2_noun van,                        //  retain
                              u2_noun sut,                        //  retain
                              u2_noun gen);                       //  retain
