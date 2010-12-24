/* l/loom.c
**
** This file is in the public domain.
*/
#include "all.h"

/* _loom_stop(): signal handler to stop computation.
*/
static void
_loom_stop(c3_i sig)
{
  LoomStop = 1;
}

/* u2_boot():
**
**   Instantiate the loom.
*/
void
u2_boot(void)
{
   mmap((void *)U2_OS_LoomBase,
        (LoomSize << 3),
        (PROT_READ | PROT_WRITE), 
        (MAP_ANON | MAP_FIXED),
        -1, 0);

  {
    struct rlimit rlm;

    getrlimit(RLIMIT_STACK, &rlm);
    rlm.rlim_cur = 65536 << 10;
    setrlimit(RLIMIT_STACK, &rlm);
  }

  signal(SIGINT, _loom_stop);
}

/* u2_mean():
**
**   Attempt to deconstruct `a` by axis, noun pairs; 0 terminates.
**   Axes must be sorted in tree order.
*/
  struct _mean_pair {
    c3_w    axe_w;
    u2_noun* som;
  };

  static c3_w
  _mean_cut(c3_w               len_w,
            struct _mean_pair* prs_m)
  {
    c3_w i_w, cut_t, cut_w;

    cut_t = c3_false;
    cut_w = 0;
    for ( i_w = 0; i_w < len_w; i_w++ ) {
      c3_w axe_w = prs_m[i_w].axe_w;

      if ( (cut_t == c3_false) && (3 == u2_ax_cap(axe_w)) ) {
        cut_t = c3_true;
        cut_w = i_w;
      }
      prs_m[i_w].axe_w = u2_ax_mas(axe_w);
    }
    return cut_t ? cut_w : i_w;
  }

  static u2_flag
  _mean_extract(u2_noun            som,
                c3_w               len_w,
                struct _mean_pair* prs_m)
  {
    if ( len_w == 0 ) {
      return u2_yes;
    }
    else if ( (len_w == 1) && (1 == prs_m[0].axe_w) ) {
      *prs_m->som = som;
      return u2_yes;
    }
    else {
      if ( u2_no == u2_dust(som) ) {
        return u2_no;
      } else {
        c3_w cut_w = _mean_cut(len_w, prs_m);

        return u2_and
          (_mean_extract(u2_h(som), cut_w, prs_m),
           _mean_extract(u2_t(som), (len_w - cut_w), (prs_m + cut_w)));
      }
    }
  }

u2_flag
u2_mean(u2_noun som,
        ...)
{
  va_list            ap;
  c3_w               len_w;
  struct _mean_pair* prs_m;

  c3_assert(u2_none != som);

  /* Count.
  */
  len_w = 0;
  {
    va_start(ap, som);
    while ( 1 ) {
      if ( 0 == va_arg(ap, c3_w) ) {
        break;
      }
      va_arg(ap, u2_noun*);
      len_w++;
    }
    va_end(ap);
  }
  prs_m = alloca(len_w * sizeof(struct _mean_pair));

  /* Install.
  */
  {
    c3_w i_w;

    va_start(ap, som);
    for ( i_w = 0; i_w < len_w; i_w++ ) {
      prs_m[i_w].axe_w = va_arg(ap, c3_w);
      prs_m[i_w].som = va_arg(ap, u2_noun*);
    }
    va_end(ap);
  }

  /* Extract.
  */
  return _mean_extract(som, len_w, prs_m);
}

/* u2_frag():
**
**   Return fragment (a) of (b), or u2_none if not applicable.
*/
u2_weak
u2_frag(u2_atom a,
        u2_noun b)
{
  c3_assert(u2_none != a);
  c3_assert(u2_none != b);

  if ( _0 == a ) {
    return u2_none;
  }

  if ( u2_fly_is_cat(a) ) {
    c3_w dep_w = u2_ax_dep(a);

    while ( dep_w ) {
      if ( a & (1 << (dep_w - 1)) ) {
        b = u2_t(b);
      } else {
        b = u2_h(b);
      }
      dep_w--;
    }

    return b;
  }
  else {
    c3_w  fol_w = (u2_met(0, a) - 1);
    c3_w  i_w;
    mpz_t a_mp;

    c3_assert(u2_none != b);
    u2_mp(a_mp, a);
   
    for ( i_w=0; i_w < fol_w; i_w++ ) {
      c3_w lum_w = (fol_w - (i_w + 1));

      if ( u2_no == u2_dust(b) ) {
        mpz_clear(a_mp);

        return u2_none;
      }
      else {
        if ( (mpz_tstbit(a_mp, lum_w) == 0) ) {
          b = u2_h(b);
        } else {
          b = u2_t(b);
        }
      }
    }
    mpz_clear(a_mp);
    return b;
  }
}

/* u2_mug():
**
**   Compute and/or recall the mug (31-bit hash) of (a).
*/
  /* _mash(): map (nud_w) to another 32-bit word.
  */
  static c3_w
  _mash(c3_w nud_w) 
  {
    static c3_w cog_w[256] = {
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
   
    nud_w ^= cog_w[(nud_w >> 0) & 255];
    nud_w ^= cog_w[(nud_w >> 8) & 255];
    nud_w ^= cog_w[(nud_w >> 16) & 255];
    nud_w ^= cog_w[(nud_w >> 24) & 255];

    return nud_w;
  }

static c3_w
_mug_dog(u2_noun veb)
{
  if ( u2_dog_is_pom(veb) ) {
    u2_noun hed = *u2_at_pom_hed(veb);
    u2_noun tel = *u2_at_pom_tel(veb);

    return u2_mug_cell(hed, tel);
  }
  else {
    c3_w len_w = *u2_at_pug_len(veb);
    c3_w zun_w = 0x18d0a625;
    c3_w i_w;

    while ( 1 ) {
      c3_w gid_w = zun_w;
      c3_w dav_w;

      for ( i_w=0; i_w < len_w; i_w++ ) {
        gid_w ^= *u2_at_pug_buf(veb, i_w);
        gid_w = _mash(gid_w);
      }
      dav_w = 0x7fffffff & gid_w;

      if ( dav_w ) {
        return dav_w;
      } 
      else zun_w++;
    }
  }
}

c3_w
u2_mug(u2_noun veb)
{
  c3_assert(u2_none != veb);

  if ( u2_fly_is_cat(veb) ) {
    c3_w zun_w = 0x18d0a625;

    if ( !veb ) {
      return zun_w;
    } 
    else while ( 1 ) {
      c3_w dav_w = 0x7fffffff & _mash(zun_w ^ veb);

      if ( dav_w ) {
        return dav_w;
      } 
      else zun_w++;
    }
  }
  else {
    if ( *u2_at_dog_mug(veb) ) {
      c3_w mug_w = *u2_at_dog_mug(veb);
      // c3_w gum_w = _mug_dog(veb);

      // c3_assert(mug_w == gum_w);
      return mug_w;
    }
    else {
      c3_w mug_w = _mug_dog(veb);

      *u2_at_dog_mug(veb) = mug_w;
      return mug_w;
    }
  }
}

/* u2_mug_words():
**
**   Compute the mug of `buf`, `len`, LSW first.
*/
c3_w
u2_mug_words(const c3_w *buf_w,
             c3_w        len_w)
{
  c3_w zun_w = 0x18d0a625;
  c3_w i_w;

  while ( 1 ) {
    c3_w gid_w = zun_w;
    c3_w dav_w;

    for ( i_w=0; i_w < len_w; i_w++ ) {
      gid_w ^= buf_w[i_w];
      gid_w = _mash(gid_w);
    }
    dav_w = 0x7fffffff & gid_w;

    if ( dav_w ) {
      return dav_w;
    } 
    else zun_w++;
  }
}

/* u2_mug_string():
**
**   Compute the mug of `a`, LSB first.
*/
c3_w
u2_mug_string(const c3_c *a_c)
{
  c3_w len_w = strlen(a_c);
  c3_w mal_w = (len_w + 3) >> 2;
  c3_w *buf_w = alloca(mal_w);
  c3_w i_w;

  for ( i_w = 0; i_w < mal_w; i_w++ ) {
    buf_w[i_w] = 0;
  }
  for ( i_w = 0; i_w < len_w; i_w++ ) {
    buf_w[i_w >> 2] |= (a_c[i_w] << (8 * (i_w & 3)));
  }
  return u2_mug_words(buf_w, mal_w);
}

/* u2_mug_both():
**
**   Join two mugs.
*/
c3_w
u2_mug_both(c3_w lus_w,
            c3_w biq_w)
{
  c3_w hur_w = (lus_w ^ (biq_w >> 24) ^ (biq_w << 8));

  while ( 1 ) {
    c3_w dav_w = 0x7fffffff & _mash(hur_w);

    if ( dav_w ) {
      return dav_w;
    } 
    else hur_w++;
  }
}

/* u2_mug_cell():
**
**   Compute the mug of the cell `[hed tel]`.
*/
c3_w
u2_mug_cell(u2_noun hed,
            u2_noun tel)
{
  c3_w   lus_w = u2_mug(hed);
  c3_w   biq_w = u2_mug(tel);

  return u2_mug_both(lus_w, biq_w);
}

/* u2_sing():
**
**   Yes iff (a) and (b) are the same noun.
*/
u2_flag
u2_sing(u2_noun a,
        u2_noun b)
{
  c3_assert(u2_none != a);
  c3_assert(u2_none != b);

  if ( a == b ) {
    return u2_yes;
  }
  else {
    if ( u2_fly_is_atom(a) ) {
      if ( !u2_fly_is_atom(b) || 
           u2_fly_is_cat(a) || 
           u2_fly_is_cat(b) )
      {
        return u2_no;
      }
      else {
        if ( *u2_at_dog_mug(a) &&
             *u2_at_dog_mug(b) &&
             (*u2_at_dog_mug(a) != *u2_at_dog_mug(b)) )
        {
          return u2_no;
        }
        else {
          c3_w w_rez = *u2_at_pug_len(a);
          c3_w w_mox = *u2_at_pug_len(b);

          if ( w_rez != w_mox ) {
            return u2_no;
          }
          else {
            c3_w i_w;

            for ( i_w = 0; i_w < w_rez; i_w++ ) {
              if ( (*u2_at_pug_buf(a, i_w)) != 
                   (*u2_at_pug_buf(b, i_w)) )
              {
                return u2_no;
              }
            }
            return u2_yes;
          }
        }
      }
    }
    else {
      if ( u2_fly_is_atom(b) ) {
        return u2_no;
      }
      else {
        if ( *u2_at_dog_mug(a) &&
             *u2_at_dog_mug(b) &&
             (*u2_at_dog_mug(a) != *u2_at_dog_mug(b)) )
        {
          return u2_no;
        }
        else {
          if ( u2_no == u2_sing(u2_h(a), u2_h(b)) ) {
            return u2_no;
          }
          else return u2_sing(u2_t(a), u2_t(b));
        }
      }
    }
  }
}

/* u2_nord():
**
**   Return 0, 1 or 2 if `a` is below, equal to, or above `b`.
*/
u2_atom
u2_nord(u2_noun a,
        u2_noun b)
{
  c3_assert(u2_none != a);
  c3_assert(u2_none != b);

  if ( a == b ) {
    return _1;
  }
  else {
    if ( u2_fly_is_atom(a) ) {
      if ( !u2_fly_is_atom(b) ) {
        return _0;
      } else {
        if ( u2_fly_is_cat(a) ) {
          if ( u2_fly_is_cat(b) ) {
            return (a < b) ? 0 : 2;
          }
          else return 0;
        }
        else if ( u2_fly_is_cat(b) ) {
          return 2;
        }
        else {
          c3_w w_rez = *u2_at_pug_len(a);
          c3_w w_mox = *u2_at_pug_len(b);

          if ( w_rez != w_mox ) {
            return (w_rez < w_mox) ? _0 : _2;
          }
          else {
            c3_w i_w;

            for ( i_w = 0; i_w < w_rez; i_w++ ) {
              c3_w ai_w = *u2_at_pug_buf(a, i_w);
              c3_w bi_w = *u2_at_pug_buf(b, i_w);

              if ( ai_w != bi_w ) {
                return (ai_w < bi_w) ? _0 : _2;
              }
            }
            return _1;
          }
        }
      }
    } else {
      if ( u2_fly_is_atom(b) ) {
        return _2;
      } else {
        u2_atom c = u2_nord(u2_h(a), u2_h(b));

        if ( _1 == c ) {
          return u2_nord(u2_t(a), u2_t(b));
        } else {
          return c;
        }
      }
    }
  }
}

/* u2_sing_c():
**
**   Yes iff (b) is the same noun as the C string a_c.
*/
u2_flag
u2_sing_c(const c3_c* a_c,
          u2_noun     b)
{
  c3_assert(u2_none != b);

  if ( !u2_fly_is_atom(b) ) {
    return u2_no;
  }
  else {
    c3_w w_sof = strlen(a_c);
    c3_w i_w;

    for ( i_w = 0; i_w < w_sof; i_w++ ) {
      if ( u2_byte(i_w, b) != a_c[i_w] ) {
        return u2_no;
      }
    }
    return u2_yes;
  }
}

/* u2_as_bush():
**
**   Factor [a] as a bush [b.[p q] c].
*/
u2_flag
u2_as_bush(u2_noun  a,
           u2_noun* b,
           u2_noun* c)
{
  c3_assert(u2_none != a);

  if ( u2_fly_is_atom(a) ) {
    return u2_no;
  }
  else {
    *b = u2_h(a);

    if ( u2_fly_is_atom(*b) ) {
      return u2_no;
    } else {
      *c = u2_t(a);
      return u2_yes;
    }
  }
}

/* u2_as_cell():
**
**   Factor (a) as a cell (b c).
*/
u2_flag
u2_as_cell(u2_noun  a,
           u2_noun* b,
           u2_noun* c)
{
  c3_assert(u2_none != a);

  if ( u2_fly_is_atom(a) ) {
    return u2_no;
  }
  else {
    if ( b ) *b = u2_h(a);
    if ( c ) *c = u2_t(a);
    return u2_yes;
  }
}

/* u2_as_hext():
**
**   Factor (a) as a hext (b c d e f g)
*/
u2_flag
u2_as_hext(u2_noun  a,
           u2_noun* b,
           u2_noun* c,
           u2_noun* d,
           u2_noun* e,
           u2_noun* f,
           u2_noun* g)
{
  u2_noun guf;

  if ( (u2_yes == u2_as_cell(a, b, &guf)) &&
       (u2_yes == u2_as_quil(guf, c, d, e, f, g)) ) {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_as_p():
**
**   & [0] if [a] is of the form [b *c].
*/
u2_flag
u2_as_p(u2_noun  a,
        u2_noun  b,
        u2_noun* c)
{
  u2_noun feg, nux;

  if ( (u2_yes == u2_as_cell(a, &feg, &nux)) &&
       (u2_yes == u2_sing(feg, b)) )
  {
    *c = nux;
    return u2_yes;
  }
  else return u2_no; 
}

/* u2_as_pq():
**
**   & [0] if [a] is of the form [b *c d].
*/
u2_flag
u2_as_pq(u2_noun  a,
         u2_noun  b,
         u2_noun* c,
         u2_noun* d)
{
  u2_noun nux;

  if ( (u2_yes == u2_as_p(a, b, &nux)) && 
       (u2_yes == u2_as_cell(nux, c, d)) )
  {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_as_pqr():
**
**   & [0] if [a] is of the form [b *c *d *e].
*/
u2_flag
u2_as_pqr(u2_noun  a,
          u2_noun  b,
          u2_noun* c,
          u2_noun* d,
          u2_noun* e)
{
  u2_noun nux;

  if ( (u2_yes == u2_as_p(a, b, &nux)) && 
       (u2_yes == u2_as_trel(nux, c, d, e)) )
  {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_as_pqrs():
**
**   & [0] if [a] is of the form [b *c *d *e *f].
*/
u2_flag
u2_as_pqrs(u2_noun  a,
           u2_noun  b,
           u2_noun* c,
           u2_noun* d,
           u2_noun* e,
           u2_noun* f)
{
  u2_noun nux;

  if ( (u2_yes == u2_as_p(a, b, &nux)) && 
       (u2_yes == u2_as_qual(nux, c, d, e, f)) )
  {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_as_qual():
**
**   Factor (a) as a qual (b c d e).
*/
u2_flag
u2_as_qual(u2_noun  a,
           u2_noun* b,
           u2_noun* c,
           u2_noun* d,
           u2_noun* e)
{
  u2_noun guf;

  if ( (u2_yes == u2_as_cell(a, b, &guf)) &&
       (u2_yes == u2_as_trel(guf, c, d, e)) ) {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_as_quil():
**
**   Factor (a) as a quil (b c d e f).
*/
u2_flag
u2_as_quil(u2_noun  a,
           u2_noun* b,
           u2_noun* c,
           u2_noun* d,
           u2_noun* e,
           u2_noun* f)
{
  u2_noun guf;

  if ( (u2_yes == u2_as_cell(a, b, &guf)) &&
       (u2_yes == u2_as_qual(guf, c, d, e, f)) ) {
    return u2_yes;
  }
  else return u2_no;
}

/* u2_as_trel():
**
**   Factor (a) as a trel (b c d).
*/
u2_flag
u2_as_trel(u2_noun a,
           u2_noun *b,
           u2_noun *c,
           u2_noun *d)
{
  u2_noun guf;

  if ( (u2_yes == u2_as_cell(a, b, &guf)) &&
       (u2_yes == u2_as_cell(guf, c, d)) ) {
    return u2_yes;
  } 
  else {
    return u2_no;
  }
}

/* u2_sh():
**
**   Return the head of (a), safely.
*/
u2_noun
u2_sh(u2_cell a)
{
  return (a == u2_none) && (u2_yes == u2_dust(a)) ? a : u2_h(a);
}

/* u2_st():
**
**   Return the tail of (a), safely.
*/
u2_noun
u2_st(u2_noun a)
{
  return (a == u2_none) && (u2_yes == u2_dust(a)) ? a : u2_t(a);
}

/* u2_met(): 
**
**   Return the size of (b) in bits, rounded up to
**   (1 << a_y). 
**
**   For example, (a_y == 3) returns the size in bytes.
*/
c3_w
u2_met(c3_y    a_y,
       u2_atom b)
{
  c3_assert(u2_none != b);
  c3_assert(u2_fly_is_atom(b));

  if ( b == 0 ) {
    return 0;
  }
  else {
    /* gal_w: number of words besides (daz_w) in (b).
    ** daz_w: top word in (b).
    */
    c3_w gal_w;
    c3_w daz_w;

    if ( u2_fly_is_cat(b) ) {
      gal_w = 0;
      daz_w = b;
    }
    else {
      gal_w = (*u2_at_pug_len(b)) - 1;
      daz_w = (*u2_at_pug_buf(b, gal_w));
    } 

    switch ( a_y ) {
      case 0:
      case 1:
      case 2: {
        /* col_w: number of bits in (daz_w)
        ** bif_w: number of bits in (b)
        */
        c3_w bif_w, col_w;

        col_w = c3_bits_word(daz_w);
        bif_w = col_w + (gal_w << 5);

        return (bif_w + ((1 << a_y) - 1)) >> a_y;
      }
      case 3: {
        return  (gal_w << 2)
              + ((daz_w >> 24) ? 4 : (daz_w >> 16) ? 3 : (daz_w >> 8) ? 2 : 1);
      }
      case 4: {
        return  (gal_w << 1)
              + ((daz_w >> 16) ? 2 : 1);
      }
      default: {
        c3_y gow_y = (a_y - 5);

        return ((gal_w + 1) + ((1 << gow_y) - 1)) >> gow_y;
      }
    }
  }
}

/* u2_bit():
**
**   Return bit (a_w) of (b).
*/
c3_b
u2_bit(c3_w    a_w,
       u2_atom b)
{
  c3_assert(u2_none != b);
  c3_assert(u2_fly_is_atom(b));

  if ( u2_fly_is_cat(b) ) {
    if ( a_w >= 31 ) {
      return 0;
    }
    else return (1 & (b >> a_w));
  }
  else {
    c3_y vut_y = (a_w & 31);
    c3_w pix_w = (a_w >> 5);

    if ( pix_w >= *u2_at_pug_len(b) ) {
      return 0;
    }
    else {
      c3_w nys_w = *u2_at_pug_buf(b, pix_w);

      return (1 & (nys_w >> vut_y));
    }
  }
}

/* u2_byte():
**
**   Return byte (a_w) of (b).
*/
c3_y
u2_byte(c3_w    a_w,
        u2_atom b)
{
  c3_assert(u2_none != b);
  c3_assert(u2_fly_is_atom(b));

  if ( u2_fly_is_cat(b) ) {
    if ( a_w > 3 ) {
      return 0;
    }
    else return (255 & (b >> (a_w << 3)));
  }
  else {
    c3_y vut_y = (a_w & 3);
    c3_w pix_w = (a_w >> 2);

    if ( pix_w >= *u2_at_pug_len(b) ) {
      return 0;
    }
    else {
      c3_w nys_w = *u2_at_pug_buf(b, pix_w);

      return (255 & (nys_w >> (vut_y << 3)));
    }
  }
}
        
/* u2_bytes():
**
**  Copy bytes (a_w) through (a_w + b_w - 1) from (d) to (c).
*/
void
u2_bytes(c3_w    a_w,
         c3_w    b_w,
         c3_y*   c_y,
         u2_atom d)
{
  c3_w i_w;

  c3_assert(u2_none != d);

  /* Efficiency: don't call u2_word().
  */
  for ( i_w = 0; i_w < b_w; i_w++ ) {
    c_y[i_w] = u2_byte((a_w + i_w), d);
  }
}

/* u2_mp():
**
**   Copy (b) into (a_mp).
*/
void
u2_mp(mpz_t   a_mp,
      u2_atom b)
{
  c3_assert(u2_none != b);
  c3_assert(u2_fly_is_atom(b));

  if ( u2_fly_is_cat(b) ) {
    mpz_init_set_ui(a_mp, b);
  }
  else {
    c3_w len_w = *u2_at_pug_len(b);

    /* Slight deficiency in the GMP API.
    */
    c3_assert(!(len_w >> 27));
    mpz_init2(a_mp, len_w << 5);

    /* Efficiency: horrible.
    */
    {
      c3_w *buf_w = alloca(len_w << 2);
      c3_w i_w;

      for ( i_w=0; i_w < len_w; i_w++ ) {
        buf_w[i_w] = *u2_at_pug_buf(b, i_w);
      }
      mpz_import(a_mp, len_w, -1, 4, 0, 0, buf_w);
    }
  }
}

/* u2_word():
**
**   Return word (a_w) of (b).
*/
c3_w
u2_word(c3_w    a_w,
        u2_atom b)
{
  c3_assert(u2_none != b);
  c3_assert(u2_fly_is_atom(b));

  if ( u2_fly_is_cat(b) ) {
    if ( a_w > 0 ) {
      return 0;
    }
    else return b;
  }
  else {
    if ( a_w >= *u2_at_pug_len(b) ) {
      return 0;
    }
    else return *u2_at_pug_buf(b, a_w);
  }
}

/* u2_words():
**
**  Copy words (a_w) through (a_w + b_w - 1) from (d) to (c).
*/
void
u2_words(c3_w    a_w,
         c3_w    b_w,
         c3_w*   c_w,
         u2_atom d)
{
  c3_w i_w;

  c3_assert(u2_none != d);

  /* Efficiency: don't call u2_word().
  */
  for ( i_w = 0; i_w < b_w; i_w++ ) {
    c_w[i_w] = u2_word((a_w + i_w), d);
  }
}

/* u2_chop():
**
**   Into the bloq space of `met`, from position `fum` for a
**   span of `wid`, to position `tou`, XOR from atom `src`
**   into ray `dst`.
*/
void
u2_chop(c3_g    met_g,
        c3_w    fum_w,
        c3_w    wid_w,
        c3_w    tou_w,
        u2_ray  dst_r,
        u2_atom src)
{
  c3_w i_w;

  c3_assert(u2_none != src);
  c3_assert(u2_fly_is_atom(src));

  if ( met_g < 5 ) {
    c3_w san_w = (1 << met_g); 
    c3_w mek_w = ((1 << san_w) - 1);
    c3_w baf_w = (fum_w << met_g);
    c3_w bat_w = (tou_w << met_g);

    // XX: efficiency: poor.  Iterate by words.
    //
    for ( i_w = 0; i_w < wid_w; i_w++ ) {
      c3_w waf_w = (baf_w >> 5);
      c3_g raf_g = (baf_w & 31);
      c3_w wat_w = (bat_w >> 5);
      c3_g rat_g = (bat_w & 31);
      c3_w hop_w;

      hop_w = u2_atom_word(src, waf_w);
      hop_w = (hop_w >> raf_g) & mek_w;

      *u2_at_ray(dst_r + wat_w) ^= (hop_w << rat_g);

      baf_w += san_w;
      bat_w += san_w;
    }
  }
  else {
    c3_g hut_g = (met_g - 5);
    c3_w san_w = (1 << hut_g);
    c3_w j_w;

    for ( i_w = 0; i_w < wid_w; i_w++ ) {
      c3_w wuf_w = (fum_w + i_w) << hut_g;
      c3_w wut_w = (tou_w + i_w) << hut_g; 

      for ( j_w = 0; j_w < san_w; j_w++ ) {
        *u2_at_ray(dst_r + wut_w + j_w) ^= u2_atom_word(src, wuf_w + j_w);
      }
    }
  }
}
