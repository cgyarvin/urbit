/* j/watt.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "pit.h"

/* declarations
*/
  /* tier 1
  */
    extern u2_ho_jet j2_mbj(Pit, add)[];
    extern u2_ho_jet j2_mbj(Pit, bex)[];
    extern u2_ho_jet j2_mbj(Pit, dec)[];
    extern u2_ho_jet j2_mbj(Pit, div)[];
    extern u2_ho_jet j2_mbj(Pit, gte)[];
    extern u2_ho_jet j2_mbj(Pit, gth)[];
    extern u2_ho_jet j2_mbj(Pit, lte)[];
    extern u2_ho_jet j2_mbj(Pit, lth)[];
    extern u2_ho_jet j2_mbj(Pit, mod)[];
    extern u2_ho_jet j2_mbj(Pit, mul)[];
    extern u2_ho_jet j2_mbj(Pit, sub)[];
 
  /* tier 3
  */
    extern u2_ho_jet j2_mbj(Pit, mug)[];
    extern u2_ho_jet j2_mbj(Pit, rip)[];

/* structures
*/
  static u2_ho_driver 
  _watt_drivers[] = {
    /* tier 1
    */
      { j2_sb(Pit, add), j2_mbj(Pit, add), 0, 0, u2_none },
      { j2_sb(Pit, bex), j2_mbj(Pit, bex), 0, 0, u2_none },
      { j2_sb(Pit, dec), j2_mbj(Pit, dec), 0, 0, u2_none },
      { j2_sb(Pit, div), j2_mbj(Pit, div), 0, 0, u2_none },
      { j2_sb(Pit, gte), j2_mbj(Pit, gte), 0, 0, u2_none },
      { j2_sb(Pit, gth), j2_mbj(Pit, gth), 0, 0, u2_none },
      { j2_sb(Pit, lte), j2_mbj(Pit, lte), 0, 0, u2_none },
      { j2_sb(Pit, lth), j2_mbj(Pit, lth), 0, 0, u2_none },
      { j2_sb(Pit, mod), j2_mbj(Pit, mod), 0, 0, u2_none },
      { j2_sb(Pit, mul), j2_mbj(Pit, mul), 0, 0, u2_none },
      { j2_sb(Pit, sub), j2_mbj(Pit, sub), 0, 0, u2_none },

    /* tier 3
    */
      { j2_sb(Pit, mug), j2_mbj(Pit, mug), 0, 0, u2_none },
      { j2_sb(Pit, rip), j2_mbj(Pit, rip), 0, 0, u2_none },
    { }
  };

  u2_ho_driver
  j2_da(Pit) = 
    { j2_sa(Pit), 0, _watt_drivers, 0, u2_none };
