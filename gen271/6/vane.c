/* j/6/vane.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* declarations
*/
  extern u2_ho_jet j2_mcj(Pit, vane, nest)[];

/* structures
*/
  u2_ho_driver 
  j2_mbd(Pit, vane)[] = {
//    { j2_sc(Pit, vane, nest), j2_mcj(Pit, vane, nest), 0, 0, u2_none },
    { }
  };

  u2_ho_driver
  j2_db(Pit, vane) = 
    { j2_sb(Pit, vane), 0, j2_mbd(Pit, vane), 0, u2_none };
