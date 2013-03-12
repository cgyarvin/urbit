/* f/loom.c
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
  LoomIntr = 1;
}

/* u2_boot():
**
**   Instantiate the loom.
*/
void
u2_boot(void)
{
  void *map;
  
  map = mmap((void *)U2_OS_LoomBase,
             (HalfSize << 3),
             (PROT_READ | PROT_WRITE), 
             (MAP_ANON | MAP_FIXED | MAP_PRIVATE),
             -1, 0);

  if ( -1 == (c3_ps)map ) {
    map = mmap((void *)0,
               (HalfSize << 3),
               (PROT_READ | PROT_WRITE), 
                MAP_ANON | MAP_PRIVATE,
               -1, 0);

    if ( -1 == (c3_ps)map ) {
      fprintf(stderr, "map failed twice\n");
    } else {
      fprintf(stderr, "map failed - try U2_OS_LoomBase %p\n", map);
    }
    exit(1);
  }

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

  static u2_bean
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

u2_bean
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
      if ( u2_no == u2_dust(b) ) {
        return u2_none;
      }
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
**   Compute and/or recall the mug (31-bit FNV1a hash) of (a).
*/
static __inline__ c3_w
_mug_fnv(c3_w has_w)
{
  return (has_w * ((c3_w)16777619));
}

static __inline__ c3_w
_mug_out(c3_w has_w)
{
  return (has_w >> 31) ^ (has_w & 0x7fffffff);
}

static __inline__ c3_w
_mug_both(c3_w lef_w, c3_w rit_w)
{
  c3_w bot_w = _mug_fnv(lef_w ^ _mug_fnv(rit_w));
  c3_w out_w = _mug_out(bot_w);

  if ( 0 != out_w ) { 
    return out_w;
  }
  else {
    return _mug_both(lef_w, ++rit_w);
  }
}

c3_w
u2_mug_both(c3_w lef_w, c3_w rit_w)
{
  return _mug_both(lef_w, rit_w);
}

static __inline__ c3_w
_mug_bytes_in(c3_w off_w, c3_w nby_w, c3_y* byt_y)
{
  c3_w i_w;

  for ( i_w = 0; i_w < nby_w; i_w++ ) {
    off_w = _mug_fnv(off_w ^ byt_y[i_w]);
  }
  return off_w;
}

static c3_w
_mug_bytes(c3_w off_w, c3_w nby_w, c3_y* byt_y)
{
  c3_w has_w = _mug_bytes_in(off_w, nby_w, byt_y);
  c3_w out_w = _mug_out(has_w);

  if ( 0 != out_w ) { 
    return out_w;
  }
  else {
    return _mug_bytes(++off_w, nby_w, byt_y);
  }
}

static __inline__ c3_w
_mug_words_in_buf(c3_w off_w, c3_w nwd_w, u2_noun veb)
{
  if ( 0 == nwd_w ) {
    return off_w;
  } else {
    c3_w i_w, x_w;

    for ( i_w = 0; i_w < (nwd_w - 1); i_w++ ) {
      x_w = *u2_at_pug_buf(veb, i_w);
      {
        c3_y a_y = (x_w & 0xff);
        c3_y b_y = ((x_w >> 8) & 0xff);
        c3_y c_y = ((x_w >> 16) & 0xff);
        c3_y d_y = ((x_w >> 24) & 0xff);

        off_w = _mug_fnv(off_w ^ a_y);
        off_w = _mug_fnv(off_w ^ b_y);
        off_w = _mug_fnv(off_w ^ c_y);
        off_w = _mug_fnv(off_w ^ d_y);
      }
    }
    x_w = *u2_at_pug_buf(veb, (nwd_w - 1));

    if ( x_w ) {
      off_w = _mug_fnv(off_w ^ (x_w & 0xff));
      x_w >>= 8;

      if ( x_w ) {
        off_w = _mug_fnv(off_w ^ (x_w & 0xff));
        x_w >>= 8;

        if ( x_w ) {
          off_w = _mug_fnv(off_w ^ (x_w & 0xff));
          x_w >>= 8;

          if ( x_w ) {
            off_w = _mug_fnv(off_w ^ (x_w & 0xff));
          }
        }
      }
    }
  }
  return off_w;
}

static __inline__ c3_w
_mug_words_in(c3_w off_w, c3_w nwd_w, const c3_w* wod_w)
{
  if ( 0 == nwd_w ) {
    return off_w;
  } else {
    c3_w i_w, x_w;

    for ( i_w = 0; i_w < (nwd_w - 1); i_w++ ) {
      x_w = wod_w[i_w];
      {
        c3_y a_y = (x_w & 0xff);
        c3_y b_y = ((x_w >> 8) & 0xff);
        c3_y c_y = ((x_w >> 16) & 0xff);
        c3_y d_y = ((x_w >> 24) & 0xff);

        off_w = _mug_fnv(off_w ^ a_y);
        off_w = _mug_fnv(off_w ^ b_y);
        off_w = _mug_fnv(off_w ^ c_y);
        off_w = _mug_fnv(off_w ^ d_y);
      }
    }
    x_w = wod_w[nwd_w - 1];

    if ( x_w ) {
      off_w = _mug_fnv(off_w ^ (x_w & 0xff));
      x_w >>= 8;

      if ( x_w ) {
        off_w = _mug_fnv(off_w ^ (x_w & 0xff));
        x_w >>= 8;

        if ( x_w ) {
          off_w = _mug_fnv(off_w ^ (x_w & 0xff));
          x_w >>= 8;

          if ( x_w ) {
            off_w = _mug_fnv(off_w ^ (x_w & 0xff));
          }
        }
      }
    }
  }
  return off_w;
}

static c3_w
_mug_words(c3_w off_w, c3_w nwd_w, const c3_w* wod_w)
{
  c3_w has_w = _mug_words_in(off_w, nwd_w, wod_w);
  c3_w out_w = _mug_out(has_w);

  if ( 0 != out_w ) { 
    return out_w;
  }
  else {
    return _mug_words(++off_w, nwd_w, wod_w);
  }
}

static c3_w
_mug_words_buf(c3_w off_w, c3_w nwd_w, u2_noun veb)
{
  c3_w has_w = _mug_words_in_buf(off_w, nwd_w, veb);
  c3_w out_w = _mug_out(has_w);

  if ( 0 != out_w ) { 
    return out_w;
  }
  else {
    return _mug_words_buf(++off_w, nwd_w, veb);
  }
}

c3_w
u2_mug(u2_noun veb)
{
  c3_assert(u2_none != veb);

  if ( u2_fly_is_cat(veb) ) {
    c3_w x_w = veb;

    return _mug_words(2166136261, (veb ? 1 : 0), &x_w);
  } else {
    if ( *u2_at_dog_mug(veb) ) {
      c3_w mug_w = *u2_at_dog_mug(veb);

      return mug_w;
    }
    else {
      c3_w mug_w;

      if ( u2_dog_is_pom(veb) ) {
        u2_noun hed = *u2_at_pom_hed(veb);
        u2_noun tel = *u2_at_pom_tel(veb);

        mug_w = u2_mug_cell(hed, tel);
      }
      else {
        c3_w len_w = *u2_at_pug_len(veb);

        mug_w = _mug_words_buf(2166136261, len_w, veb);
      }

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
  return _mug_words(2166136261, len_w, buf_w);
}

/* u2_mug_string():
**
**   Compute the mug of `a`, LSB first.
*/
c3_w
u2_mug_string(const c3_c *a_c)
{
  return _mug_bytes(2166136261, strlen(a_c), (c3_y *)a_c);
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

/* u2_mug_trel():
**
**   Compute the mug of `[a b c]`.
*/
c3_w
u2_mug_trel(u2_noun a,
            u2_noun b,
            u2_noun c)
{
  return u2_mug_both(u2_mug(a), u2_mug_both(u2_mug(b), u2_mug(c)));
}

/* u2_mug_qual():
**
**   Compute the mug of `[a b c d]`.
*/
c3_w
u2_mug_qual(u2_noun a,
            u2_noun b,
            u2_noun c,
            u2_noun d)
{
  return u2_mug_both(u2_mug(a), 
                     u2_mug_both(u2_mug(b), 
                                 u2_mug_both(u2_mug(c), u2_mug(d))));
}

#ifdef U2_PROFILE
  c3_w X;   // XX not thread-safe
  c3_w FUN;
#endif

/* _sing_x():
**
**   Yes iff (a) and (b) are the same noun.
*/
static u2_bean
_sing_x(u2_noun a,
        u2_noun b)
{
  c3_assert(u2_none != a);
  c3_assert(u2_none != b);

  if ( a == b ) {
    return u2_yes;
  }
  else {
#ifdef U2_PROFILE
    X++;
#endif

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
          if ( u2_no == _sing_x(u2_h(a), u2_h(b)) ) {
            return u2_no;
          }
          else return _sing_x(u2_t(a), u2_t(b));
        }
      }
    }
  }
}

#ifdef U2_PROFILE
/* _weight(): count subordinate nouns.
*/
static c3_w
_weight(u2_noun n)
{
  if ( u2_yes == u2_stud(n) ) {
    return 1;
  } else {
    return _weight(u2_h(n)) + _weight(u2_t(n));
  }
}
#endif

/* u2_sing():
**
**   Yes iff (a) and (b) are the same noun.
*/
u2_bean
u2_sing(u2_noun a,
        u2_noun b)
{
#ifndef U2_PROFILE
  return _sing_x(a, b);
#else
  X=0;
  {
    u2_bean sit = _sing_x(a, b);

    if ( (u2_yes == sit) && (a != b) ) {
      u2_tx_did_nod(0, X);
    }
    if ( FUN && (X > 10) ) {
      // printf("mug %x, X %d\n", u2_mug(a), X);
      // if ( u2_mug(a) == 0xe5c2279 ) 
      // { printf("a %x, b %x\n", a, b); c3_assert(0); }
    }
    return sit;
  }
#endif
}

u2_bean
u2_fing(u2_noun a, 
        u2_noun b)
{
  return (a == b) ? u2_yes : u2_no;
}

/* u2_sing_cell():
**
**   Yes iff `[p q]` and `b` are the same noun.
*/
u2_bean
u2_sing_cell(u2_noun p,
             u2_noun q,
             u2_noun b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_sing(p, u2_h(b)), 
                       u2_sing(q, u2_t(b))));
}
u2_bean
u2_fing_cell(u2_noun p,
             u2_noun q,
             u2_noun b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_fing(p, u2_h(b)), 
                       u2_fing(q, u2_t(b))));
}

/* u2_sing_mixt():
**
**   Yes iff `[p q]` and `b` are the same noun.
*/
u2_bean
u2_sing_mixt(const c3_c* p_c,
             u2_noun     q,
             u2_noun     b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_sing_c(p_c, u2_h(b)), 
                       u2_sing(q, u2_t(b))));
}
u2_bean
u2_fing_mixt(const c3_c* p_c,
             u2_noun     q,
             u2_noun     b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_sing_c(p_c, u2_h(b)), 
                       u2_fing(q, u2_t(b))));
}

/* u2_sing_trel():
**
**   Yes iff `[p q r]` and `b` are the same noun.
*/
u2_bean
u2_sing_trel(u2_noun p,
             u2_noun q,
             u2_noun r,
             u2_noun b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_sing(p, u2_h(b)), 
                       u2_sing_cell(q, r, u2_t(b))));
}
u2_bean
u2_fing_trel(u2_noun p,
             u2_noun q,
             u2_noun r,
             u2_noun b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_fing(p, u2_h(b)), 
                       u2_fing_cell(q, r, u2_t(b))));
}

/* u2_sing_qual():
**
**   Yes iff `[p q r]` and `b` are the same noun.
*/
u2_bean
u2_sing_qual(u2_noun p,
             u2_noun q,
             u2_noun r,
             u2_noun s,
             u2_noun b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_sing(p, u2_h(b)), 
                       u2_sing_trel(q, r, s, u2_t(b))));
}
u2_bean
u2_fing_qual(u2_noun p,
             u2_noun q,
             u2_noun r,
             u2_noun s,
             u2_noun b)
{
  return u2_and(u2_dust(b),
                u2_and(u2_fing(p, u2_h(b)), 
                       u2_fing_trel(q, r, s, u2_t(b))));
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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
u2_bean
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

/* u2_chub():
**
**   Return double-word (a_w) of (b).
*/
c3_d
u2_chub(c3_w  a_w,
        u2_atom b)
{
  c3_w wlo_w = u2_word(a_w * 2, b);
  c3_w whi_w = u2_word(1 + (a_w * 2), b);

  return (((uint64_t)whi_w) << 32ULL) | ((uint64_t)wlo_w);
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
    c3_w len_w = (u2_fly_is_cat(src) ? 1 : *u2_at_pug_len(src));
    c3_g hut_g = (met_g - 5);
    c3_w san_w = (1 << hut_g);
    c3_w j_w;

    for ( i_w = 0; i_w < wid_w; i_w++ ) {
      c3_w wuf_w = (fum_w + i_w) << hut_g;
      c3_w wut_w = (tou_w + i_w) << hut_g;

      for ( j_w = 0; j_w < san_w; j_w++ ) {
        *u2_at_ray(dst_r + wut_w + j_w) ^= 
            ((wuf_w + j_w) >= len_w)
              ? 0
              : u2_atom_word(src, wuf_w + j_w);
      }
    }
  }
}
