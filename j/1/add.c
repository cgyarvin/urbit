/* j/1/add.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "hpit.h"

/* functions
*/
  u2_atom
  j2_mbc(Pit, add)(u2_wire wir_r, u2_atom dis, u2_atom dat)
  {
    mpz_t dis_mp, dat_mp;

    u2_mp(dis_mp, dis);
    u2_mp(dat_mp, dat);

    mpz_add(dis_mp, dis_mp, dat_mp);
    mpz_clear(dat_mp);

    return u2_bn_mp(wir_r, dis_mp);
  }
  u2_noun
  j2_mb(Pit, add)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun dis, dat;

    u2_bl_yes(wir_r, u2_mean(cor, 8, &dis, 9, &dat, 0));
    dis = u2_bl_flat(wir_r, dis);
    dat = u2_bl_flat(wir_r, dat);
    {
      return j2_mbc(Pit, add)(wir_r, dis, dat);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, add)[] = {
    { ".3", j2_mb(Pit, add), u2_yes, u2_none, u2_none },
    { }
  };
