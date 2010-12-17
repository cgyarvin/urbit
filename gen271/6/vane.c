/* j/6/vane.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* declarations
*/
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, clay)(u2_wire wir_r, 
                         u2_noun cor);                            //  retain

  extern u2_ho_jet j2_mcj(Pit, vane, bake)[];
  extern u2_ho_jet j2_mcj(Pit, vane, etch)[];
  extern u2_ho_jet j2_mcj(Pit, vane, find)[];
  extern u2_ho_jet j2_mcj(Pit, vane, make)[];
  extern u2_ho_jet j2_mcj(Pit, vane, mill)[];
  extern u2_ho_jet j2_mcj(Pit, vane, nest)[];
  extern u2_ho_jet j2_mcj(Pit, vane, play)[];
  extern u2_ho_jet j2_mcj(Pit, vane, reap)[];

/* structures
*/
  u2_ho_driver 
  j2_mbd(Pit, vane)[] = {
    { j2_sc(Pit, vane, bake), j2_mcj(Pit, vane, bake), 0, 0, u2_none },
    { j2_sc(Pit, vane, etch), j2_mcj(Pit, vane, etch), 0, 0, u2_none },
    { j2_sc(Pit, vane, make), j2_mcj(Pit, vane, make), 0, 0, u2_none },
    { j2_sc(Pit, vane, mill), j2_mcj(Pit, vane, mill), 0, 0, u2_none },
    { j2_sc(Pit, vane, nest), j2_mcj(Pit, vane, nest), 0, 0, u2_none },
    { j2_sc(Pit, vane, play), j2_mcj(Pit, vane, play), 0, 0, u2_none },
    { j2_sc(Pit, vane, reap), j2_mcj(Pit, vane, reap), 0, 0, u2_none },
    { }
  };

  u2_ho_jet 
  j2_mbj(Pit, vane)[] = {
    { "clay", c3__hevy, j2_mc(Pit, vane, clay), u2_no, u2_none, u2_none },
    { }
  };

  u2_ho_driver
  j2_db(Pit, vane) = 
    { j2_sb(Pit, vane), j2_mbj(Pit, vane), j2_mbd(Pit, vane), 0, u2_none };
