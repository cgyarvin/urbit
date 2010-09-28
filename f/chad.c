/* l/chad.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_ch_find():
**
**   Find value for `nam` in `cad`, or return `u2_none`.
*/
u2_weak
u2_ch_find(u2_ray  cad_r,
           u2_noun nam)
{
  c3_w mug_w = u2_mug(nam);
  c3_w off_w = 0;

  while ( 1 ) {
    if ( off_w == 32 ) {
      /* Linear search in a list of 16 total collisions.
      ** Overflow probability: (n/(2^31))^15 ~= 0.
      */
      c3_w i_w;

      for ( i_w = 0; i_w < 16; i_w++ ) {
        u2_ray  per_r = (cad_r + (c3_wiseof(u2_loom_pear) * i_w));
        u2_noun nom = *u2_at(per_r, u2_loom_pear, nam);

        if ( (u2_none != nom) && (u2_yes == u2_sing(nam, nom)) ) {
          return *u2_at(per_r, u2_loom_pear, val);
        }
      }
      return u2_none;
    }
    else {
      c3_w    fat_w = (mug_w >> off_w) & 15;
      u2_ray  per_r = (cad_r + (c3_wiseof(u2_loom_pear) * fat_w));
      u2_noun nom = *u2_at(per_r, u2_loom_pear, nam);

      if ( u2_none == nom ) {
        cad_r = *u2_at(per_r, u2_loom_pear, val);

        if ( 0 == cad_r ) {
          return u2_none;
        } else {
          off_w += 4;
          continue;
        }
      }
      else if ( u2_yes == u2_sing(nam, nom) ) {
        return *u2_at(per_r, u2_loom_pear, val);
      }
    }
  }
}

/* u2_ch_find_cell():
**
**   Find value for `[hed tal]` in `cad`, or return `u2_none`.
*/
u2_weak
u2_ch_find_cell(u2_ray  cad_r,
                u2_noun hed,
                u2_noun tal)
{
  c3_w mug_w = u2_mug_cell(hed, tal);
  c3_w off_w = 0;

  while ( 1 ) {
    if ( off_w == 32 ) {
      /* Linear search in a list of 16 total collisions.
      ** Overflow probability: (n/(2^31))^15 ~= 0.
      */
      c3_w i_w;

      for ( i_w = 0; i_w < 16; i_w++ ) {
        u2_ray  per_r = (cad_r + (c3_wiseof(u2_loom_pear) * i_w));
        u2_noun nom = *u2_at(per_r, u2_loom_pear, nam);

        if ( (u2_none != nom) && 
             (u2_yes == u2_dust(nom)) &&
             (u2_yes == u2_sing(hed, u2_h(nom))) &&
             (u2_yes == u2_sing(tal, u2_t(nom))) )
        {
          return *u2_at(per_r, u2_loom_pear, val);
        }
      }
      return u2_none;
    }
    else {
      c3_w    fat_w = (mug_w >> off_w) & 15;
      u2_ray  per_r = (cad_r + (c3_wiseof(u2_loom_pear )* fat_w));
      u2_noun nom = *u2_at(per_r, u2_loom_pear, nam);

      if ( u2_none == nom ) {
        cad_r = *u2_at(per_r, u2_loom_pear, val);

        if ( 0 == cad_r ) {
          return u2_none;
        } else {
          off_w += 4;
          continue;
        }
      }
      else if ( u2_yes == u2_dust(nom) && 
               (u2_yes == u2_sing(hed, u2_h(nom))) &&
               (u2_yes == u2_sing(tal, u2_t(nom))) )
      {
        return *u2_at(per_r, u2_loom_pear, val);
      }
    }
  }
}

/* _ch_save(): as u2_ch_save(), with mug and offset, and iced nouns.
*/
static u2_flag
_ch_save(u2_ray  ral_r,
         u2_ray  cad_r,
         u2_noun nim,
         u2_noun vil,
         c3_w    mug_w,
         c3_w    off_w)
{
  while ( 1 ) {
    if ( off_w == 32 ) {
      /* Linear search in a list of 16 total collisions.
      ** Overflow probability: (n/(2^31))^15 ~= 0.
      */
      c3_w i_w;

      for ( i_w = 0; i_w < 15; i_w++ ) {
        u2_ray  per_r = (cad_r + (c3_wiseof(u2_loom_pear) * i_w));
        u2_noun nom = *u2_at(per_r, u2_loom_pear, nam);

        if ( u2_none != nom ) {
          c3_assert(u2_no == u2_sing(nim, nom));
        }
        else {
          *u2_at(per_r, u2_loom_pear, nam) = nim;
          *u2_at(per_r, u2_loom_pear, val) = vil;
          return u2_yes;
        }
      }
      return u2_no;
    }
    else {
      c3_w    fat_w = (mug_w >> off_w) & 15;
      u2_ray  per_r = (cad_r + (c3_wiseof(u2_loom_pear) * fat_w));
      u2_noun nom = *u2_at(per_r, u2_loom_pear, nam);

      if ( u2_none == nom ) {
        cad_r = *u2_at(per_r, u2_loom_pear, val);

        if ( 0 == cad_r ) {
          *u2_at(per_r, u2_loom_pear, nam) = nim;
          *u2_at(per_r, u2_loom_pear, val) = vil;
          return u2_yes;
        } 
        else {
          off_w += 4;
          continue;
        }
      }
      else {
        u2_noun num = *u2_at(per_r, u2_loom_pear, nam);
        u2_noun vul = *u2_at(per_r, u2_loom_pear, val);
        u2_ray  osh_r;
        c3_w    i_w;

        if ( 0 == (osh_r = u2_rl_ralloc(ral_r, c3_wiseof(u2_loom_chad))) ) {
          return u2_no;
        }
        for ( i_w = 0; i_w < 15; i_w++ ) {
          u2_ray por_r = (osh_r + (c3_wiseof(u2_loom_pear) * fat_w));
         
          *u2_at(por_r, u2_loom_pear, nam) = u2_none;
          *u2_at(por_r, u2_loom_pear, val) = 0;
        }

        if ( u2_no == _ch_save(ral_r, osh_r, num, vul, u2_mug(num), 4+off_w) ) {
          u2_rl_rfree(ral_r, osh_r);
          return u2_no;
        }
        if ( u2_no == _ch_save(ral_r, osh_r, nim, vil, mug_w, 4+off_w) ) {
          u2_rl_rfree(ral_r, osh_r);
          return u2_no;
        }
        *u2_at(per_r, u2_loom_pear, nam) = u2_none;
        *u2_at(per_r, u2_loom_pear, val) = osh_r;
        return u2_yes;
      }
    }
  }
}

/* u2_ch_save():
**
**   Save `val` under `nam` in `cad`, allocating in `ral`.
**   Return `u2_no` iff allocation fails.
*/
u2_flag
u2_ch_save(u2_ray  ral_r,
           u2_ray  cad_r,
           u2_noun nam,
           u2_noun val)
{
  u2_weak nim, vil;

  if ( u2_none == (nim = u2_rl_ice(ral_r, nam)) ) {
    return u2_no;
  }
  if ( u2_none == (vil = u2_rl_ice(ral_r, val)) ) {
    u2_rl_lose(ral_r, nim);
    return u2_no;
  }
  if ( u2_no == _ch_save(ral_r, cad_r, nim, vil, u2_mug(nim), 0) ) {
    u2_rl_lose(ral_r, nim);
    u2_rl_lose(ral_r, vil);
    return u2_no;
  }
  return u2_yes;
}

/* u2_ch_save_cell():
**
**   Save `val` under `[hed tal]` in `cad`, allocating in `ral`.
**   Return `u2_no` iff allocation fails.
*/
u2_flag
u2_ch_save_cell(u2_ray  ral_r,
                u2_ray  cad_r,
                u2_noun hed,
                u2_noun tal,
                u2_noun val)
{
  u2_weak hid, til, nim, vil;

  if ( u2_none == (hid = u2_rl_ice(ral_r, hed)) ) {
    return u2_no;
  }
  if ( u2_none == (til = u2_rl_ice(ral_r, tal)) ) {
    u2_rl_lose(ral_r, til);
    return u2_no;
  }
  if ( u2_none == (nim = u2_rl_cell(ral_r, hid, til)) ) {
    u2_rl_lose(ral_r, hid);
    u2_rl_lose(ral_r, til);
    return u2_no;
  }
  if ( u2_none == (vil = u2_rl_ice(ral_r, val)) ) {
    u2_rl_lose(ral_r, nim);
    return u2_no;
  }
  if ( u2_no == _ch_save(ral_r, cad_r, nim, vil, u2_mug(nim), 0) ) {
    u2_rl_lose(ral_r, nim);
    u2_rl_lose(ral_r, vil);
    return u2_no;
  }
  return u2_yes;
}
