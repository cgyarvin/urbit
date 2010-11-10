/* j/3/rip.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "hpit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, rip)(u2_wire wir_r, u2_atom dis, u2_atom dat)
  {
    if ( !u2_fly_is_cat(dis) || (dis >= 32) ) {
      return dat;
    }
    else {
      c3_y dis_y = dis;
      c3_w met_w = u2_met(dis_y, dat);

      if ( dis_y < 5 ) {
        c3_w 
      }
      else {
        c3_w san_w = 1 << (dis_y - 5);

      }
    }
  }
  u2_noun
  j2_mb(Pit, rip)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun dis, dat;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &dis, 9, &dat, 0));
    dis = u2_bl_flat(wir_r, dis);
    dat = u2_bl_flat(wir_r, dat);
    {
      return j2_mbc(Pit, rip)(wir_r, dis, dat);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, rip)[] = {
    { ".3", j2_mb(Pit, rip), u2_no, u2_none, u2_none },
    { }
  };
