/* l/read.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_lr_bin(): 
**
**   Return the size of (b) in bits, rounded up to
**   (1 << y_a). 
**
**   For example, (y_a == 3) returns the size in bytes.
*/
c3_w
u3_lr_bin(u3_lv     lv,
          c3_y      y_a,
          u3_l_atom b)
{
  u3_l l = lv;

  c3_assert(u3_none != b);
  c3_assert(u3_li_rat_is_atom(b));

  if ( b == 0 ) {
    return 0;
  }
  else {
    /* w_gal: number of words besides (w_daz) in (b).
    ** w_daz: top word in (b).
    */
    c3_w w_gal;
    c3_w w_daz;

    if ( u3_li_rat_is_cat(b) ) {
      w_gal = 0;
      w_daz = b;
    }
    else {
      w_gal = (*u3_li_at_pig_len(l, b)) - 1;
      w_daz = (*u3_li_at_pig_buf(l, b, w_gal));
    } 

    switch ( y_a ) {
      case 0:
      case 1:
      case 2: {
        /* y_woq: table of bits per byte
        ** w_col: number of bits in (w_daz)
        ** w_bif: number of bits in (b)
        */
        c3_w w_col, w_bif;
        static c3_y y_woq[] = {
          0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
          5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
          6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
          6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
          7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
          7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
          7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
          7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
          8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
        };

        w_col = (w_daz >> 24) 
          ? (24 + y_woq[w_daz >> 24])
          : (w_daz >> 16)
            ? (16 + y_woq[w_daz >> 16])
            : (w_daz >> 8)
              ? (8 + y_woq[w_daz >> 8])
              : y_woq[w_daz];

        w_bif = w_col + (w_gal << 5);

        return (w_bif + ((1 << y_a) - 1)) >> y_a;
      }
      case 3: {
        return  (w_gal << 2)
              + ((w_daz >> 24) ? 4 : (w_daz >> 16) ? 3 : (w_daz >> 8) ? 2 : 1);
      }
      case 4: {
        return  (w_gal << 1)
              + ((w_daz >> 16) ? 2 : 1);
      }
      default: {
        c3_y y_gow = (y_a - 5);

        return ((w_gal + 1) + ((1 << y_gow) - 1)) >> y_gow;
      }
    }
  }
}

/* u3_lr_bit():
**
**   Return bit (w_a) of (b).
*/
c3_b
u3_lr_bit(u3_lv     lv,
          c3_w      w_a,
          u3_l_atom b)
{
  u3_l l = lv;

  c3_assert(u3_none != b);
  c3_assert(u3_li_rat_is_atom(b));

  if ( u3_li_rat_is_cat(b) ) {
    if ( w_a >= 31 ) {
      return 0;
    }
    else return (1 & (b >> w_a));
  }
  else {
    c3_y y_vut = (w_a & 31);
    c3_w w_pix = (w_a >> 5);

    if ( w_pix >= *u3_li_at_pig_len(l, b) ) {
      return 0;
    }
    else {
      c3_w w_nys = *u3_li_at_pig_buf(l, b, w_pix);

      return (1 & (w_nys >> y_vut));
    }
  }
}

/* u3_lr_byte():
**
**   Return byte (w_a) of (b).
*/
c3_y
u3_lr_byte(u3_lv     lv,
           c3_w      w_a,
           u3_l_atom b)
{
  u3_l l = lv;

  c3_assert(u3_none != b);
  c3_assert(u3_li_rat_is_atom(b));

  if ( u3_li_rat_is_cat(b) ) {
    if ( w_a > 3 ) {
      return 0;
    }
    else return (255 & (b >> (w_a << 3)));
  }
  else {
    c3_y y_vut = (w_a & 3);
    c3_w w_pix = (w_a >> 2);

    if ( w_pix >= *u3_li_at_pig_len(l, b) ) {
      return 0;
    }
    else {
      c3_w w_nys = *u3_li_at_pig_buf(l, b, w_pix);

      return (255 & (w_nys >> (y_vut << 3)));
    }
  }
}

/* u3_lr_bytes():
**
**  Copy bytes (w_a) through (w_a + w_b - 1) from (d) to (c).
*/
void
u3_lr_bytes(u3_lv     lv,
            c3_w      w_a,
            c3_w      w_b,
            c3_y      *y_c,
            u3_l_atom d)
{
  u3_l l = lv;
  c3_w w_i;

  /* Efficiency: don't call u3_lr_word().
  */
  for ( w_i = 0; w_i < w_b; w_i++ ) {
    y_c[w_i] = u3_lr_byte(l, (w_a + w_i), d);
  }
}

/* u3_lr_cell():
**
**   Factor (a) as a cell (b c).
*/
u3_l_flag
u3_lr_cell(u3_lv    lv,
           u3_l_fox a,
           u3_l_rat *b,
           u3_l_rat *c)
{
  u3_l l = lv;

  c3_assert(u3_none != a);

  if ( u3_li_rat_is_atom(a) ) {
    return u3_no;
  }
  else {
    *b = u3_lr_h(l, a);
    *c = u3_lr_t(l, a);
    return u3_yes;
  }
}

/* u3_lr_fork():
**
**   Factor (a) as a fork [b.[p q] c].
*/
u3_l_flag
u3_lr_fork(u3_lv    lv,
           u3_l_fox a,
           u3_l_rat *b,
           u3_l_rat *c)
{
  u3_l l = lv;

  c3_assert(u3_none != a);

  if ( u3_li_rat_is_atom(a) ) {
    return u3_no;
  }
  else {
    *b = u3_lr_h(l, a);

    if ( u3_li_rat_is_atom(*b) ) {
      return u3_no;
    } else {
      *c = u3_lr_t(l, a);
      return u3_yes;
    }
  }
}

/* u3_lr_p():
**
**   & [0] if [a] is of the form [b *c].
*/
u3_l_flag
u3_lr_p(u3_lv    l,
        u3_l_fox a,
        u3_l_fox b,
        u3_l_fox *c)
{
  u3_fox feg, nux;

  if ( (u3_yes == u3_lr_cell(l, a, &feg, &nux)) &&
       (u3_yes == u3_lr_sing(l, feg, b)) )
  {
    *c = nux;
    return u3_yes;
  }
  else return u3_no; 
}

/* u3_lr_pq():
**
**   & [0] if [a] is of the form [b *c d].
*/
u3_l_flag
u3_lr_pq(u3_lv lv,
         u3_l_fox a,
         u3_l_fox b,
         u3_l_fox *c,
         u3_l_fox *d)
{
  u3_l   l = lv;
  u3_fox nux;

  if ( (u3_yes == u3_lr_p(l, a, b, &nux)) && 
       (u3_yes == u3_lr_cell(l, nux, c, d)) )
  {
    return u3_yes;
  }
  else return u3_no;
}

/* u3_lr_pqr():
**
**   & [0] if [a] is of the form [b *c *d *e].
*/
u3_l_flag
u3_lr_pqr(u3_lv lv,
          u3_l_fox a,
          u3_l_fox b,
          u3_l_fox *c,
          u3_l_fox *d,
          u3_l_fox *e)
{
  u3_l   l = lv;
  u3_fox nux;

  if ( (u3_yes == u3_lr_p(l, a, b, &nux)) && 
       (u3_yes == u3_lr_trel(l, nux, c, d, e)) )
  {
    return u3_yes;
  }
  else return u3_no;
}

/* u3_lr_sing():
**
**   Yes iff (a) is the same noun as (b).
*/
u3_l_flag
u3_lr_sing(u3_lv    lv,
         u3_l_fox a,
         u3_l_fox b)
{
  u3_l l = lv;

#if 1
  return (u3_lr_ord(l, a, b) == 1) ? u3_yes : u3_no;
#else
  c3_assert(u3_none != a);
  c3_assert(u3_none != b);

  if ( a == b ) {
    return u3_yes;
  }
  else {
    if ( u3_li_rat_is_atom(a) ) {
      if ( !u3_li_rat_is_atom(b) || 
           u3_li_rat_is_cat(a) || 
           u3_li_rat_is_cat(b) )
      {
        return u3_no;
      }
      else {
        if ( *u3_li_at_hog_mug(l, a) &&
             *u3_li_at_hog_mug(l, b) &&
             (*u3_li_at_hog_mug(l, a) != *u3_li_at_hog_mug(l, b)) )
        {
          return u3_no;
        }
        else {
          c3_w w_rez = *u3_li_at_pig_len(l, a);
          c3_w w_mox = *u3_li_at_pig_len(l, b);

          if ( w_rez != w_mox ) {
            return u3_no;
          }
          else {
            c3_w w_i;

            for ( w_i = 0; w_i < w_rez; w_i++ ) {
              if ( (*u3_li_at_pig_buf(l, a, w_i)) != 
                   (*u3_li_at_pig_buf(l, b, w_i)) )
              {
                return u3_no;
              }
            }
            return u3_yes;
          }
        }
      }
    }
    else {
      if ( u3_li_rat_is_atom(b) ) {
        return u3_no;
      }
      else {
        if ( *u3_li_at_hog_mug(l, a) &&
             *u3_li_at_hog_mug(l, b) &&
             (*u3_li_at_hog_mug(l, a) != *u3_li_at_hog_mug(l, b)) )
        {
          return u3_no;
        }
        else {
          if ( u3_no == u3_lr_sing(l, u3_h(l, a), u3_h(l, b)) ) {
            return u3_no;
          }
          else return u3_lr_sing(l, u3_t(l, a), u3_t(l, b));
        }
      }
    }
  }
#endif
}

/* u3_lr_ord():
**
**   0 if a < b, 1 if a == b, 2 if a > b
*/
u3_l_atom
u3_lr_ord(u3_lv    lv,
          u3_l_fox a,
          u3_l_fox b)
{
  u3_l l = lv;

  c3_assert(u3_none != a);
  c3_assert(u3_none != b);

  if ( a == b ) {
    return 1;
  }
  else {
    if ( u3_li_rat_is_atom(a) ) {
      if ( !u3_li_rat_is_atom(b) ) {
        return 0;
      }
      if ( u3_li_rat_is_cat(a) ) {
        if ( u3_li_rat_is_cat(b) ) {
          return (a < b) ? 0 : 2;
        }
        else return 0;
      }
      else {
        if ( u3_li_rat_is_cat(b) ) {
          return 2;
        }
        else {
          c3_w w_rez = *u3_li_at_pig_len(l, a);
          c3_w w_mox = *u3_li_at_pig_len(l, b);

          if ( w_rez < w_mox ) {
            return 0;
          }
          else if ( w_rez > w_mox ) {
            return 2;
          }
          else {
            c3_w w_i;

            for ( w_i = 0; w_i < w_rez; w_i++ ) {
              c3_w w_yef = *u3_li_at_pig_buf(l, a, (w_rez - (w_i + 1)));
              c3_w w_doz = *u3_li_at_pig_buf(l, b, (w_rez - (w_i + 1)));

              if ( w_yef < w_doz ) {
                return 0;
              }
              else if ( w_yef > w_doz ) {
                return 2;
              }
            }
            return 1;
          }
        }
      }
    }
    else {
      if ( u3_li_rat_is_atom(b) ) {
        return 2;
      }
      else {
        switch ( u3_lr_ord(l, u3_h(l, a), u3_h(l, b) ) ) {
          default: c3_assert(0); return 0;

          case 0: return 0;
          case 1: return u3_lr_ord(l, u3_t(l, a), u3_t(l, b));
          case 2: return 2;
        }
      }
    }
  }
}

/* u3_lr_sing_c():
**
**   Yes iff (b) is the same noun as the C string c_a.
*/
u3_l_flag
u3_lr_sing_c(u3_lv    lv,
             c3_c     *c_a,
             u3_l_fox b)
{
  u3_l l = lv;

  c3_assert(u3_none != b);

  if ( !u3_li_rat_is_atom(b) ) {
    return u3_no;
  }
  else {
    c3_w w_sof = strlen(c_a);
    c3_w w_i;

    for ( w_i = 0; w_i < w_sof; w_i++ ) {
      if ( u3_lr_byte(l, w_i, b) != c_a[w_i] ) {
        return u3_no;
      }
    }
    return u3_yes;
  }
}

/* u3_lr_h():
**
**   Return the head of (a).
*/
u3_l_rat
u3_lr_h(u3_lv    lv, 
        u3_l_fox a)
{
  u3_l l = lv;

  c3_assert(u3_none != a);
  c3_assert(!u3_li_rat_is_atom(a));

  return *u3_li_at_dog_hed(l, a);
}

/* u3_lr_mp():
**
**   Copy (b) into (mp_a).
*/
void
u3_lr_mp(u3_lv     lv,
         mpz_t     mp_a,
         u3_l_atom b)
{
  u3_l l = lv;

  c3_assert(u3_none != b);
  c3_assert(u3_li_rat_is_atom(b));

  if ( u3_li_rat_is_cat(b) ) {
    mpz_init_set_ui(mp_a, b);
  }
  else {
    c3_w w_len = *u3_li_at_pig_len(l, b);

    /* Slight deficiency in the GMP API.
    */
    c3_assert(!(w_len >> 27));
    mpz_init2(mp_a, w_len << 5);

    /* Efficiency: horrible.
    */
    {
      c3_w *w_buf = alloca(w_len << 2);
      c3_w w_i;

      for ( w_i=0; w_i < w_len; w_i++ ) {
        w_buf[w_i] = *u3_li_at_pig_buf(l, b, w_i);
      }
      mpz_import(mp_a, w_len, -1, 4, 0, 0, w_buf);
    }
  }
}

/* u3_lr_qual():
**
**   Factor (a) as a qual (b c d e).
*/
u3_l_flag
u3_lr_qual(u3_lv    lv,
           u3_l_fox a,
           u3_l_rat *b,
           u3_l_rat *c,
           u3_l_rat *d,
           u3_l_rat *e)
{
  u3_l     l = lv;
  u3_l_rat guf;

  if ( (u3_yes == u3_lr_cell(l, a, b, &guf)) &&
       (u3_yes == u3_lr_trel(l, guf, c, d, e)) ) {
    return u3_yes;
  }
  else return u3_no;
}

/* u3_lr_quil():
**
**   Factor (a) as a quil (b c d e f).
*/
u3_l_flag
u3_lr_quil(u3_lv    lv,
           u3_l_fox a,
           u3_l_rat *b,
           u3_l_rat *c,
           u3_l_rat *d,
           u3_l_rat *e,
           u3_l_rat *f)
{
  u3_l     l = lv;
  u3_l_rat guf;

  if ( (u3_yes == u3_lr_cell(l, a, b, &guf)) &&
       (u3_yes == u3_lr_qual(l, guf, c, d, e, f)) ) {
    return u3_yes;
  }
  else return u3_no;
}

/* u3_lr_hext():
**
**   Factor (a) as a hext (b c d e f g).
*/
u3_l_flag
u3_lr_hext(u3_lv    lv,
           u3_l_fox a,
           u3_l_rat *b,
           u3_l_rat *c,
           u3_l_rat *d,
           u3_l_rat *e,
           u3_l_rat *f,
           u3_l_rat *g)
{
  u3_l     l = lv;
  u3_l_rat guf;

  if ( (u3_yes == u3_lr_cell(l, a, b, &guf)) &&
       (u3_yes == u3_lr_quil(l, guf, c, d, e, f, g)) ) {
    return u3_yes;
  }
  else return u3_no;
}

/* u3_lr_t():
**
**   Return the tail of (a).
*/
u3_l_rat
u3_lr_t(u3_lv    lv, 
        u3_l_fox a)
{
  u3_l l = lv;

  c3_assert(u3_none != a);
  c3_assert(!u3_li_rat_is_atom(a));

  return *u3_li_at_dog_tel(l, a);
}

/* u3_lr_trel():
**
**   Factor (a) as a trel (b c d).
*/
u3_l_flag
u3_lr_trel(u3_lv    lv,
           u3_l_fox a,
           u3_l_rat *b,
           u3_l_rat *c,
           u3_l_rat *d)
{
  u3_l     l = lv;
  u3_l_rat guf;

  if ( (u3_yes == u3_lr_cell(l, a, b, &guf)) &&
       (u3_yes == u3_lr_cell(l, guf, c, d)) ) {
    return u3_yes;
  } 
  else {
    return u3_no;
  }
}

/* u3_lr_twig():
**
**   Return twig (a) of (b).
*/
u3_l_rat
u3_lr_twig(u3_lv     lv,
           u3_l_atom a,
           u3_l_fox  b)
{
  u3_l  l     = lv;
  c3_w  w_fol = (u3_lr_bin(l, 0, a) - 1);
  c3_w  w_i;
  mpz_t mp_a;

  c3_assert(u3_none != b);
  u3_lr_mp(l, mp_a, a);
 
  for ( w_i=0; w_i < w_fol; w_i++ ) {
    c3_w w_lum = (w_fol - (w_i + 1));

    if ( u3_no == u3_lr_dust(l, b) ) {
      mpz_clear(mp_a);

      return u3_none;
    }
    else {
      if ( (mpz_tstbit(mp_a, w_lum) == 0) ) {
        b = u3_h(l, b);
      } else {
        b = u3_t(l, b);
      }
    }
  }
  mpz_clear(mp_a);
  return b;
}

/* u3_lr_word():
**
**   Return word (w_a) of (b).
*/
c3_w
u3_lr_word(u3_lv     lv,
           c3_w      w_a,
           u3_l_atom b)
{
  u3_l l = lv;

  c3_assert(u3_none != b);
  c3_assert(u3_li_rat_is_atom(b));

  if ( u3_li_rat_is_cat(b) ) {
    if ( w_a > 0 ) {
      return 0;
    }
    else return b;
  }
  else {
    if ( w_a >= *u3_li_at_pig_len(l, b) ) {
      return 0;
    }
    else return *u3_li_at_pig_buf(l, b, w_a);
  }
}

/* u3_lr_words():
**
**  Copy words (w_a) through (w_a + w_b - 1) from (d) to (c).
*/
void
u3_lr_words(u3_lv     lv,
            c3_w      w_a,
            c3_w      w_b,
            c3_w      *w_c,
            u3_l_atom d)
{
  u3_l l = lv;
  c3_w w_i;

  /* Efficiency: don't call u3_lr_word().
  */
  for ( w_i = 0; w_i < w_b; w_i++ ) {
    w_c[w_i] = u3_lr_word(l, (w_a + w_i), d);
  }
}
