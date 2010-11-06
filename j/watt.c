/* j/watt.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "hpit.h"

/* declarations
*/
  /* tier 1
  */
    extern u2_ho_jet j2_mbj(Pit, add)[];
    extern u2_ho_jet j2_mbj(Pit, dec)[];
  
/* structures
*/
  static u2_ho_driver 
  _watt_drivers[] = {
    /* tier 1
    */
      { j2_sb(Pit, add), j2_mbj(Pit, add), 0, 0, u2_none },
      { j2_sb(Pit, dec), j2_mbj(Pit, dec), 0, 0, u2_none },
    { }
  };

  u2_ho_driver
  j2_da(Pit) = 
    { j2_sa(Pit), 0, _watt_drivers, 0, u2_none };
