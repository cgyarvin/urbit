/* l/manage.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_lm_new():
**
**   Create a fresh loom, mallocing (1 << a_y) words of memory.  Return
**   null if malloc fails.
**
**   A loom can be freed with free() - it uses no external resources, 
**   so there is no destructor.
*/
u3_l
u3_lm_new(c3_y a_y)
{
  c3_assert(a_y >= 8);
  c3_assert(a_y <= 28);
  {
    u3_l l = malloc(4 << a_y);

    if ( !l ) {
      return 0;
    }
    else {
      l->bat_nit = ((1 << a_y) - 1);

      l->hat_ray = u3_ray_of(1, 0);
      l->cap_ray = u3_ray_of(0, c3_wiseof(struct u3_loom));

      l->mat_ray = l->cap_ray;
      l->cop_w = 0;
      return l;
    }
  }
}

/* u3_lm_alloc():
**
**   Allocate (a_w) words of C storage on the hat.
*/
void *
u3_lm_alloc(u3_lv lv,
            c3_w  a_w)
{
  u3_l l = lv;

  if ( u3_no == u3_lm_open(l, a_w) ) {
    return 0;
  } else {
    u3_ray hat_ray = l->hat_ray;

    l->hat_ray += a_w;

    if ( u3_ray_a(hat_ray) ) {
      return u3_at_ray(l, hat_ray + (a_w - 1));
    }
    else {
      return u3_at_ray(l, hat_ray);
    }
  }
}

/* _li_mash(): map (w_nud) to another 32-bit word.
*/
static c3_w
_li_mash(c3_w w_nud) 
{
  static c3_w w_cog[256] = {
    0x352598d8, 0xba9cd382, 0xa9afcd63, 0xfe8c511a, 0xf40f7a8d, 0x6220ecc5,
    0xf8820121, 0x99267e88, 0xdee5b579, 0x7824fff6, 0x7c8f831a, 0x766ff6ec,
    0xb0cd88c6, 0x1994625d, 0xccffce0a,  0xc100eda, 0xda4952df, 0x62bcfdef,
    0xf00fc9e2, 0x3a30bdd8, 0xd156e14b, 0x22b9bd9c, 0xeb9f040e, 0x9570fa83,
    0x151f4b17, 0x4c680e34, 0xc62f6816, 0x5c43205e, 0xe2ddee5a, 0x87652d85,
    0x80722ba6, 0xa158b454, 0x5022a039, 0xbc457a9d, 0x3ce83919, 0x7990bd4e,
    0xf44c697e, 0xf60ee7be, 0xdd68fcd2, 0xd3bfabae, 0x2ba16060, 0x23171ec6,
    0x9b9e2cec, 0x683fa466, 0x103b81cf, 0x40acd8dc, 0xe14077a2, 0x123e5e9f,
    0xcfbeae41,  0xf4bb673, 0xf537ea14, 0xae87124c, 0xaed1093b, 0x513ce98d,
    0x5f606388, 0x1e458e1d, 0x88fd1802, 0x3b7aa391, 0x5caf8a56, 0xbddd8a18,
    0x9187837c, 0xc5e102b2, 0xf192cbcd, 0xb2078d1a, 0xf593e52b, 0xbbc96404,
    0x2fe5b7f9, 0x5eab8eac, 0x65a14a04, 0x6dd6f5f8,  0x8835b42, 0x713fffa2,
    0x3cab1b6f, 0x63dd42a0, 0xb81a7b1d, 0x29079afa, 0xdecc1486, 0x18494012,
    0x68d8efa2, 0x873b540e, 0x3052b642, 0x81f4f7ca, 0x44337e55, 0x86c7973e,
    0x83539726, 0x8e498a90, 0xe808ec02, 0x48d76271, 0xdeb0aa12, 0xb7a9e735,
    0x8f1d0a6e, 0x8a1fd93a, 0xd2e1d0d1, 0x9093fa5f, 0xbe74ea0b, 0xd3ea1b9d,
    0x51a573dd, 0x51634e92, 0xb3275702, 0x4c41d2c6, 0x6717fa39, 0x56a8a01c,
    0x948328b1, 0xdbaf1fa2, 0x3bffc889, 0x7fb44be7, 0x475d8534, 0x5eba8280,
    0xc090c33b,  0x35857a4, 0x95b1eb1f, 0x5dcd3652, 0x1b973827, 0x5e24070c,
    0x7367a5f9,   0xf3ef4e, 0xb3bcada3, 0xcf3e4033, 0x1a9d0bd3, 0xa46b9dd7,
    0xa234566b, 0x61f4a52d, 0x44844992, 0xfaffdd23, 0x14187d04, 0x7c600063,
    0xa9417956, 0xd10faca2, 0x78eea53d, 0x474c90cf, 0x37f42e48, 0xa3765510,
    0xe6ffe2fb, 0xe83350f0, 0x3e5ec58d, 0xdeeedce8, 0xb5c0da93, 0xa01ebf2b,
    0xb3ed287a, 0x13beec00,  0x26c78ab, 0xc845a9e2, 0xb6315b6a, 0xe5d5238e,
    0x62dc97c6, 0x6a52c674, 0x370f9e65, 0xe777884a, 0x3beb6b4d, 0x95cdc493,
    0xb265b0ee, 0xac4fc47f, 0xc415321c, 0xe9fc60eb, 0x4237062e, 0x566dd09c,
     0x5af69ed, 0xa7589924, 0xe030c8ed, 0x3f52439e, 0x85ac98d2, 0x2026a870,
    0xfdf004ca, 0x28329ab3, 0x70c78bcc, 0x111a1094, 0x9036b901, 0x712f6316,
    0x4354f3e7,  0x617eda8, 0x7fe89a8b, 0x637d01f5,  0xfa54e14, 0x72fb1b49,
    0xd82afef8, 0x1055a07d,  0xf4c5845, 0x4f112d16, 0xe2c0936d, 0x96923c87,
    0xf5b59c3c,  0x3a1f284, 0xc63a1157, 0x72553aee, 0x88502921, 0xbdf13b8c,
    0xf54a4761, 0x54447c57, 0xeefbdb16, 0x19c11553, 0x1b06df20, 0xe4395998,
    0x3bf794dc, 0x261c8938, 0x875f1bb9, 0x8b29fd75, 0xc50dca03, 0xe95eacb5,
    0x121c9f64, 0xdce5b8fa, 0x167cf21d, 0xab1f9401, 0xc7eb6480, 0x48f0ac44,
    0x31325eca, 0x70186f9e, 0x9887957d, 0xfd0dbfee, 0xb799e1be, 0xb1c38ca7,
     0xc32efad, 0xfc36ca9d, 0xff307dd2, 0x7b941dc3, 0x9182f20d, 0x78a5c74c,
     0xbc99c47, 0xf82cb4ad, 0x4bbb0ecf, 0xbc816aba, 0xa47337b1, 0x5242aa7a,
    0x40b92e52, 0x3f55045c, 0x6deac45d, 0x52c0256a,  0x209e49e, 0x381585e2,
    0x2d4774c2, 0x5fb51d73, 0x1b456773, 0x180d4405, 0x4b72be7f, 0x54464f51,
    0xfbfbdac7, 0xb9df9e63, 0x12ad4163, 0x5d56c751, 0x6d4b9a3e, 0x75d9c4e1,
    0x1804e2a5, 0x3e77ee18, 0x12924b1a,  0xcfd4d14, 0xc5cd423e, 0xe3533b5b,
    0xa53ef834, 0x6f8b9c36, 0xb9e06f14, 0x76d680b9, 0x52ca46d8,  0x8445336,
    0xbb412e03, 0x2ae29f22, 0xeec357b8, 0x45bd2fb7
  };
  
  return w_cog[(w_nud >> 0) & 255] +
         w_cog[(w_nud >> 8) & 255] +
         w_cog[(w_nud >> 16) & 255] +
         w_cog[(w_nud >> 24) & 255];
}

/* u3_lm_mug():
**
**   Compute and/or recall the mug (short hash) of (veb).
*/
c3_w
u3_lm_mug(u3_lv    lv,
          u3_fox veb)
{
  u3_l l = lv;

  if ( u3_rat_is_cat(veb) ) {
    c3_w w_zon = 0x18d0a625;

    if ( !veb ) {
      return w_zon;
    } 
    else while ( 1 ) {
      c3_w w_dav = 0x7fffffff & _li_mash(w_zon ^ veb);

      if ( w_dav ) {
        return w_dav;
      } 
      else w_zon++;
    }
  }
  else {
    if ( *u3_at_dog_mug(l, veb) ) {
      return *u3_at_dog_mug(l, veb);
    }
    else {
      if ( u3_dog_is_hog(veb) ) {
        u3_fox hed   = *u3_at_hog_hed(l, veb);
        u3_fox tel   = *u3_at_hog_tel(l, veb);
        c3_w   w_lus = u3_lm_mug(l, hed);
        c3_w   w_biq = u3_lm_mug(l, tel);
        c3_w   w_hur = (w_lus ^ (w_biq >> 24) ^ (w_biq << 8));

        while ( 1 ) {
          c3_w w_dav = 0x7fffffff & _li_mash(w_hur);

          if ( w_dav ) {
            *u3_at_dog_mug(l, veb) = w_dav;
            return w_dav;
          } 
          else w_hur++;
        }
      }
      else {
        c3_w w_len = *u3_at_pig_len(l, veb);
        c3_w w_zon = 0x18d0a625;
        c3_w i_w;

        while ( 1 ) {
          c3_w w_gid = w_zon;
          c3_w w_dav;

          for ( i_w=0; i_w < w_len; i_w++ ) {
            w_gid ^= *u3_at_pig_buf(l, veb, i_w);
            w_gid = _li_mash(w_gid);
          }
          w_dav = 0x7fffffff & w_gid;

          if ( w_dav ) {
            *u3_at_dog_mug(l, veb) = w_dav;
            return w_dav;
          } 
          else w_zon++;
        }
      }
    }
  }
}

/* u3_lm_nuke():
**
**   Zero all data between cap and hat.  For debugging.
*/
void
u3_lm_nuke(u3_lv lv)
{
  u3_l     l       = lv;
  u3_nit nit_cuv = u3_ray_nit(l, l->hat_ray);
  u3_nit nit_zac = u3_ray_nit(l, l->cap_ray);
  u3_nit nit_nif;

  if ( nit_zac < nit_cuv ) {
    for ( nit_nif = nit_zac; nit_nif <= nit_cuv; nit_nif++ ) {
      *u3_at_nit(l, nit_nif) = 0;
    }
  } else {
    for ( nit_nif = nit_cuv; nit_nif <= nit_zac; nit_nif++ ) {
      *u3_at_nit(l, nit_nif) = 0;
    }
  }
}

/* u3_lm_flap():
**
**   Reverse the beams forward, returning the old mat.
*/
u3_ray
u3_lm_flap(u3_lv lv)
{
  u3_l   l       = lv;
  u3_ray mat_ray = l->mat_ray;

  // c3_assert(u3_ray_a(l->cap_ray) == u3_ray_a(l->mat_ray));
  // c3_assert(u3_ray_a(l->hat_ray) != u3_ray_a(l->cap_ray));
  // c3_assert(u3_ray_b(l->cap_ray) >= u3_ray_b(l->mat_ray));

  l->mat_ray = l->hat_ray;
  l->hat_ray = l->cap_ray;
  l->cap_ray = l->mat_ray;

  return mat_ray;
}

/* u3_lm_flop():
**
**   Reverse the beams backward, restoring the old mat.
*/
void
u3_lm_flop(u3_lv    lv,
           u3_ray mat_ray)
{
  u3_l l = lv;

  // c3_assert(u3_ray_a(l->cap_ray) == u3_ray_a(l->mat_ray));
  // c3_assert(u3_ray_a(l->hat_ray) != u3_ray_a(l->cap_ray));
  // c3_assert(u3_ray_b(l->cap_ray) >= u3_ray_b(l->mat_ray));

  l->cap_ray = l->hat_ray;
  l->hat_ray = l->mat_ray;
  l->mat_ray = mat_ray;
}

/* u3_lm_flog():
**
**   Release the can, setting the cap to the mat.
*/
void
u3_lm_flog(u3_lv lv)
{
  u3_l l = lv;

  l->cap_ray = l->mat_ray;
}

/* u3_lm_clear():
**
**   Yes iff [lef] does not point into any word >= [lid]
**   and < [nut].
*/
u3_flag
u3_lm_clear(u3_lv  lv,
            u3_fox lef,
            u3_ray lid_ray,
            u3_ray nut_ray)
{
  u3_l l = lv;

  c3_assert(u3_ray_a(lid_ray) == u3_ray_a(nut_ray));

  if ( u3_rat_is_cat(lef) ) {
    return u3_yes;
  } else {
    u3_ray ray_lef = u3_dog_a(lef);

    if ( u3_ray_a(ray_lef) != u3_ray_a(lid_ray) ) {
      return u3_yes;
    }
    else if ( ray_lef < lid_ray ) {
      return u3_yes;
    }
    else if ( ray_lef >= nut_ray ) {
      if ( u3_dog_is_hog(lef) ) {
        u3_fox hed = *u3_at_hog_hed(l, lef);
        u3_fox tel = *u3_at_hog_tel(l, lef);

        if ( (u3_yes == u3_lm_clear(l, hed, lid_ray, nut_ray)) &&
             (u3_yes == u3_lm_clear(l, tel, lid_ray, nut_ray)) ) {
          return u3_yes;
        }
        else return u3_no;
      }
      else return u3_yes;
    }
    else return u3_no;
  }
}

/* _li_tamp_swizzle()::
**
**   Shift the root [lef], above [nut], down by [pif].
*/
static void
_li_tamp_swizzle(u3_l   l,
                 u3_fox lef,
                 c3_w   pif_w,
                 u3_ray nut_ray,
                 c3_b   nax_b[])
{
  /* Totally unnecessary assertions.
  */
  {
    c3_assert(u3_rat_is_dog(lef));
    c3_assert(u3_dog_a(lef) >= nut_ray);
  }

  /* Only hogs are fixed.
  */
  if ( u3_dog_is_hog(lef) ) {
    u3_ray ray_lef = u3_dog_a(lef);
    
    /* Is this hog fixed?
    */
    if ( nax_b[ray_lef - nut_ray] ) {
      return;
    }
    else {
      /* Fix the hog!
      */
      nax_b[ray_lef - nut_ray] = 1;
      {
        u3_fox fes = *u3_at_hog_hed(l, lef);
        u3_fox hoz = *u3_at_hog_tel(l, lef);

        if ( u3_rat_is_dog(fes) &&
             (u3_dog_beam(fes) == u3_ray_beam(nut_ray)) &&
             (u3_dog_ray(fes) >= nut_ray) )
        {
          /* Rewrite the pointer.
          */
          *u3_at_hog_hed(l, lef) = (fes - (pif_w << 2));
          
          /* Swizzle into it.
          */
          _li_tamp_swizzle(l, fes, pif_w, nut_ray, nax_b);
        }

        if ( u3_rat_is_dog(hoz) &&
             (u3_dog_beam(hoz) == u3_ray_beam(nut_ray)) &&
             (u3_dog_ray(hoz) >= nut_ray) )
        {
          /* Rewrite the pointer.
          */
          *u3_at_hog_tel(l, lef) = (hoz - (pif_w << 2));
          
          /* Swizzle into it.
          */
          _li_tamp_swizzle(l, hoz, pif_w, nut_ray, nax_b);
        }
      }
    }
  }
}

/* u3_lm_tamp():
**
**   Tamp, eliding the segment from [lid_ray] up to [nut_ray],
**   preserving the root [lef].
**
**   Assumes u3_lm_clear() with the same arguments.
*/
u3_fox
u3_lm_tamp(u3_lv  lv,
           u3_fox lef,
           u3_ray lid_ray,
           u3_ray nut_ray)
{
  /* pif: length of the segment to elide.
  ** lam: length of the segment to shift down over it.
  */
  u3_l l     = lv;
  c3_w pif_w = (nut_ray - lid_ray);
  c3_w lam_w = (l->cap_ray - nut_ray);
  c3_w i_w;

  /* Stupid, unnecessary assertions.
  */
  {
    /* Layer should at least handle this case, actually.
    */
    c3_assert(u3_rat_is_dog(lef));

    c3_assert(u3_ray_a(nut_ray) == u3_ray_a(lid_ray));
    c3_assert(u3_ray_a(u3_dog_a(lef)) == u3_ray_a(lid_ray));
    c3_assert(u3_dog_a(lef) >= nut_ray);
  }

  /* Swizzle the good segment down to its new location.
  **
  **   nax[i_w]: 1 iff a hog at nut[i_w] has been fixed.
  */
  {
    c3_b nax_b[lam_w];
    c3_w i_w;

    for ( i_w = 0; i_w < lam_w; i_w++ ) {
      nax_b[i_w] = 0;
    }
    _li_tamp_swizzle(l, lef, pif_w, nut_ray, nax_b);
  }

  /* Move the good segment down.
  */
  for ( i_w = 0; i_w < lam_w; i_w++ ) {
    *u3_at_ray(l, (lid_ray + i_w)) = *u3_at_ray(l, (nut_ray + i_w));
  }
  l->cap_ray -= pif_w;

  /* Move and return [lef].
  */
  return (lef - (pif_w << 2));
}

/* u3_lm_water():
**
**   Return west and east watermarks, respectively.
*/
void
u3_lm_water(u3_lv lv,
            c3_w  *maz_w,
            c3_w  *buc_w)
{
  u3_l l = lv;

  if ( !u3_ray_beam(l->hat_ray) ) {
    *maz_w = u3_ray_point(l->hat_ray);
    *buc_w = u3_ray_point(l->cap_ray);
  } else {
    *maz_w = u3_ray_point(l->cap_ray);
    *buc_w = u3_ray_point(l->hat_ray);
  }
}

#if 0
/* _lm_bask_alloc(): allocate in a basket.  Returns 0 for failure.
*/
static u3_ray
_lm_bask_alloc(u3_l   l,
               u3_ray bas_ray,
               c3_w   siz_z)
{
}

/* _lm_bask_free(): free from basket.
*/
static void
_lm_bask_free(u3_l   l,
              u3_ray bas_ray,
              u3_ray vog_ray)
{
}

/* _lm_bask_save(): save in basket.
**
**  XX: intense copying from u3_ln_ice().
**  XX: does not preserve dag structure.
*/
static u3_rat
_lm_bask_save(u3_l   l,
              u3_ray bas_ray,
              u3_fox fiz)
{
  u3_ray fiz_ray = u3_dog_a(fiz);

  if ( u3_ray_a(fiz_ray) == 0 ) {
    if ( fiz_ray < *u3_to(l, bas_ray, struct u3_bask, m.wst_ray) ) {
      return fiz; 
    }
  } else {
    if ( fiz_ray < *u3_to(l, bas_ray, struct u3_bask, m.est_ray) ) {
      return fiz; 
    }
  }

  if ( u3_dog_is_hog(fiz) ) {
    u3_rat hed = _lm_bask_save(l, *u3_at_hog_hed(l, fiz));
    u3_rat tel = _lm_bask_save(l, *u3_at_hog_tel(l, fiz));
    u3_ray ray_nov;

    if ( (u3_none == hed) || (u3_none == tel) ) {
      return u3_none;
    }
    ray_nov = _lm_bask_alloc(c3_wiseof(struct u3_cell));
    if ( 0 == ray_nov ) {
      return u3_none;
    }

    *u3_at_dog_mug(l, nov) = *u3_at_dog_mug(l, fiz);
    *u3_at_hog_hed(l, nov) = hed;
    *u3_at_hog_tel(l, nov) = tel;

    l->cop_w += 3;
    return nov;
    }
  }
  else {
    c3_w len_w = *u3_at_pig_len(l, fiz);

    if ( u3_no == u3_lm_open(l, (len_w + c3_wiseof(struct u3_atom))) ) {
      return u3_none;
    }
    else {
      u3_ray ray_nov;
      u3_fox nov;

      ray_nov = l->hat_ray;
      l->hat_ray += (len_w + c3_wiseof(struct u3_atom));
      nov = u3_pig_of(ray_nov, 0);

      *u3_at_dog_mug(l, nov) = 0;
      *u3_at_pig_len(l, nov) = len_w;

      /* Fill the pig.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < len_w; i_w++ ) {
          *u3_at_pig_buf(l, nov, i_w) = *u3_at_pig_buf(l, fiz, i_w);
        }
      }

      l->cop_w += (2 + len_w);
      return nov;
    }
  }
  }
}

/* _lm_bask_put():
**
**   Try to insert a name-value pair into a memory basket.
*/
static void
_lm_bask_put(u3_l   l,
             u3_ray bas_ray,
             u3_ray sam_ray,
             c3_w   mug_w,
             c3_y   sft_y,
             u3_fox nam,
             u3_fox val)
{
  while ( 1 ) {
    c3_w zid_w     = (mug_w >> sft_y) & 15;
    u3_ray von_ray = (zid_w * c3_wiseof(struct u3_pair)) + 
                     u3_of(l, sam_ray, struct u3_sham, dol_ray);
    u3_rat nim     = *u3_to(l, von_ray, struct u3_pair, nam);

    if ( u3_none == nim ) {
      u3_ray dul_ray = *u3_to(l, von_ray, struct u3_pair, val);

      if ( 0 == dul_ray ) {
        nam = _lm_bask_save(l, bas_ray, nam);
        val = _lm_bask_save(l, bas_ray, val);

        if ( (u3_none == nam) || (u3_none == val) ) {
          return;
        }
        *u3_to(l, von_ray, struct u3_pair, nam) = nam;
        *u3_to(l, von_ray, struct u3_pair, val) = val;
      } 
      else {
        sam_ray = dul_ray;
        sft_y += 4;
      }
    }
    else {
      c3_w mog_w = u3_lm_mug(l, nim);

      if ( mog_w == mug_w ) {
        /* Collision policy: replace.
        */
        *u3_to(l, von_ray, struct u3_pair, nam) = 
          _lm_bask_save(l, bas_ray, nam);

        *u3_to(l, von_ray, struct u3_pair, val) = 
          _lm_bask_save(l, bas_ray, val);
      }
      else {
        u3_fox wal     = *u3_to(l, von_ray, struct u3_pair, nam);
        u3_ray som_ray = _lm_bask_alloc(l, bas_ray, c3_wiseof(struct u3_sham));
        c3_w   i_w;

        if ( 0 == som_ray ) {
          return;
        }
        for ( i_w = 0; i_w < 16; i_w++ ) {
          u3_ray dul_ray = (zid_w * c3_wiseof(struct u3_pair)) + 
                           u3_of(l, som_ray, struct u3_sham, dol_ray);
          
          *u3_to(l, dul_ray, struct u3_pair, nam) = u3_none;
          *u3_to(l, dul_ray, struct u3_pair, val) = 0;
        }
        sft_y += 4;

        _lm_bask_put(l, bas_ray, dul_ray, mog_w, sft_y, nim, wal);
        sam_ray = dul_ray;
      }
    }
  }
}

/* _lm_bask_get():
**
**   Try to find a name-value pair in a memory basket.
*/
static u3_rat
_lm_bask_get(u3_l   l,
             u3_ray sam_ray,
             c3_w   mug_w,
             u3_fox nam)
{
  while ( 1 ) {
    c3_w zid_w     = (mug_w & 15);
    u3_ray von_ray = (zid_w * c3_wiseof(struct u3_pair)) + 
                     u3_of(l, sam_rayray, struct u3_sham, dol_ray);
    u3_rat nim     = *u3_to(l, von_ray, struct u3_pair, nam);

    if ( u3_none == nim ) {
      u3_ray dul_ray = *u3_to(l, von_ray, struct u3_pair, val);

      if ( 0 == dul_ray ) {
        return u3_none;
      } else {
        sam_ray = dul_ray;
        mug_w >>= 4;
      }
    }
    else {
      if ( u3_yes == u3_lr_sing(l, nim, nam) ) {
        return *u3_to(l, von_ray, struct u3_pair, val);
      } else {
        return u3_none;
      }
    }
  }
}

/* u3_lm_bask_save():
**
**   Try to save a name-value pair in a memory basket.
*/
void
u3_lm_bask_save(u3_lv  lv,
                u3_ray bas_ray,
                u3_fox nam,
                u3_fox val)
{
  u3_l l         = lv;
  u3_ray sam_ray = u3_of(l, bas_ray, struct u3_bask, s);
  c3_w mug_w     = u3_lm_mug(l, nam);

  _lm_bask_fit(l, bas_ray, sam_ray, mug_w, nam, val);
}

/* u3_lm_bask_find():
**
**   Try to find a name-value pair in a memory basket.
*/
u3_rat
u3_lm_bask_find(u3_lv  lv,
                u3_ray bas_ray,
                u3_fox nam)
{
  u3_l l = lv;
  u3_ray sam_ray = u3_of(l, bas_ray, struct u3_bask, s);
  c3_w mug_w     = u3_lm_mug(l, nam);

  return _lm_bask_find(l, sam_ray, mug_w, nam);
}

/* u3_lm_bask_new():
**
**   Push a mane of size (hat_ray - cap_ray) * (num_w / dem_w) on the cap.
*/
c3_b
u3_lm_mane_part(u3_lv  lv,
               c3_w   num_w,
               u3+
{
  c3_w met_w;

  c3_assert(0 == ((1 << 31) & siz_w));
  c3_assert(siz_w > c3_wiseof(struct u3_mane));
  siz_w -= c3_wiseof(struct u3_mane);
  met_w = u3_lr_bin(l, siz_w);

  /* Clear the free lists.
  */
  {
    c3_w i_w;

    for ( i_w=0; i_w < 27; i_w++ ) {
      *u3_at_ray(i_w + u3_of(l, u3_to(l, 
  
}
#endif
