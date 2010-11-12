/* j/3/rip.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "hpit.h"

/* functions
*/
  u2_noun
  j2_mbc(Pit, rip)(u2_wire wir_r, u2_atom dis, u2_atom dat)
  {
    if ( !u2_fly_is_cat(dis) || (dis >= 32) ) {
      return dat;
    }
    else {
      u2_noun pir = u2_nul;
      c3_g dis_g = dis;
      c3_w met_w = u2_met(dis_g, dat);
      c3_w i_w;

      if ( dis_g < 5 ) {
        c3_w mek_w = ((1 << (1 << dis_g)) - 1);

        for ( i_w = 0; i_w < met_w; i_w++ ) {
          c3_w pat_w = (met_w - (i_w + 1));
          c3_w bit_w = (pat_w << dis_g);
          c3_w wor_w = (bit_w >> 5);
          c3_w sif_w = (bit_w & 31);
          c3_w src_w = u2_atom_word(dat, wor_w);
          c3_w rip_w = ((src_w >> sif_w) & mek_w);

          pir = u2_bc(wir_r, rip_w, pir);
        }
        return pir;
      }
      else {
        c3_g san_g = (dis_g - 5); 
        c3_w san_w = 1 << san_g;

        for ( i_w = 0; i_w < met_w; i_w++ ) {
          c3_w    pat_w = (met_w - (i_w + 1));
          c3_w    wut_w = (pat_w << san_g);
          u2_ray  sal_r = u2_bn_slab(wir_r, san_w);
          c3_w    j_w;
          u2_atom rip;

          for ( j_w = 0; j_w < san_w; j_w++ ) {
            *u2_at_ray(sal_r + j_w) = u2_atom_word(dat, wut_w + j_w);
          }
          rip = u2_rl_malt(wir_r, sal_r);
          pir = u2_bc(wir_r, rip, pir);
        }
      }
      return pir;
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
    { ".3", j2_mb(Pit, rip), u2_yes, u2_none, u2_none },
    { }
  };
