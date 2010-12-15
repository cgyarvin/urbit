/* j/4/in.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* declarations
*/
  extern u2_ho_jet j2_mcj(Pit, in, put)[];
  extern u2_ho_jet j2_mcj(Pit, in, has)[];

/* structures
*/
  u2_ho_driver 
  j2_mbd(Pit, in)[] = {
    { j2_sc(Pit, in, put), j2_mcj(Pit, in, put), 0, 0, u2_none },
    { j2_sc(Pit, in, has), j2_mcj(Pit, in, has), 0, 0, u2_none },
    {}
  };

  u2_ho_driver
  j2_db(Pit, in) = 
    { j2_sb(Pit, in), 0, j2_mbd(Pit, in) , 0, u2_none };
