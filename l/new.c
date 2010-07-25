/* l/new.c
** 
** This file is in the public domain.
*/
#include "all.h"

#include <stdio.h>

/* u3_ln_bytes():
**
**   Copy (w_a) bytes from (y_b) into an atom on the hat of (l).
*/
u3_l_rat
u3_ln_bytes(u3_lv       lv,
            u3_w        w_a,
            const u3_y  *y_b)
{
  u3_l l = lv;

  /* Strip trailing zeroes.
  */
  while ( w_a && !y_b[w_a - 1] ) {
    w_a--;
  }

  /* Check for cat.
  */
  if ( w_a <= 4 ) {
    if ( !w_a ) {
      return 0;
    }
    else if ( w_a == 1 ) {
      return y_b[0];
    }
    else if ( w_a == 2 ) {
      return (y_b[0] | (y_b[1] << 8));
    }
    else if ( w_a == 3 ) {
      return (y_b[0] | (y_b[1] << 8) | (y_b[2] << 16));
    }
    else if ( (y_b[3] <= 0x7f) ) {
      return (y_b[0] | (y_b[1] << 8) | (y_b[2] << 16) | (y_b[3] << 24));
    }
  }

  /* Allocate, fill, return.
  */
  {
    u3_w w_len = (w_a + 3) >> 2;

    if ( u3_no == u3_lm_open(l, (w_len + u3_wiseof(struct u3_li_atom))) ) {
      return u3_none;
    }
    else { 
      u3_ray ray_nov;
      u3_fox nov;

      ray_nov = l->ray_hat;
      l->ray_hat += (w_len + u3_wiseof(struct u3_li_atom));
      nov = u3_li_pig_of(ray_nov, 0);

      *u3_li_at_hog_mug(l, nov) = 0;
      *u3_li_at_pig_len(l, nov) = w_len;

      /* Clear the words.
      */
      {
        u3_w w_i;

        for ( w_i=0; w_i < w_len; w_i++ ) {
          *u3_li_at_pig_buf(l, nov, w_i) = 0;
        }
      }

      /* Fill the bytes.
      */
      {
        u3_w w_i;

        for ( w_i=0; w_i < w_a; w_i++ ) {
          *u3_li_at_pig_buf(l, nov, (w_i >> 2))
            |=
              (y_b[w_i] << ((w_i & 3) * 8));
        }
      }
      return nov;
    }
  }
}

/* u3_ln_string():
**
**   Copy the C string (c_a) into an atom.
*/
u3_l_rat
u3_ln_string(u3_lv      lv,
             const u3_c *c_a)
{
  u3_l l = lv;

  return u3_ln_bytes(l, strlen(c_a), (u3_y *)c_a);
}

/* u3_ln_cell(): 
**
**   Produce the cell (a b) on the hat of (l), or u3_l_none if
**   this would overflow the clam.
*/
u3_l_rat
u3_ln_cell(u3_lv    lv,
           u3_l_fox a,
           u3_l_fox b)
{
  u3_l l = lv;

  u3_assert(u3_none != a);
  u3_assert(u3_none != b);

  if ( u3_none == (a = u3_ln_ice(l, a)) ) {
    return u3_none;
  }
  else if ( u3_none == (b = u3_ln_ice(l, b)) ) {
    return u3_none;
  }
  else if ( u3_no == u3_lm_open(l, u3_wiseof(struct u3_li_cell)) ) {
    printf("not open\n");
    return u3_none;
  }
  else {
    u3_ray ray_nov;
    u3_fox nov;

    ray_nov = l->ray_hat;
    l->ray_hat += u3_wiseof(struct u3_li_cell);
    nov = u3_li_dog_of(ray_nov, 0);

    *u3_li_at_hog_mug(l, nov) = 0;
    *u3_li_at_dog_hed(l, nov) = a;
    *u3_li_at_dog_tel(l, nov) = b;

    return nov;
  }
}

/* u3_ln_ice():
**
**   Produce a noun equivalent to (a), which does not reference
**   any data on the can of (l).
*/
u3_l_rat
u3_ln_ice(u3_lv    lv,
          u3_l_fox a)
{
  u3_l l = lv;

  if ( u3_li_rat_is_cat(a) ) {
    return a;
  }
  else {
    u3_ray ray_a = u3_li_hog_a(a);

    if ( (u3_li_ray_a(ray_a) == u3_li_ray_a(l->ray_hat)) ||
         (ray_a < l->ray_mat) )
    {
      return a;
    }
    else {
      if ( u3_li_hog_is_dog(a) ) {
        if ( u3_no == u3_lm_open(l, u3_wiseof(struct u3_li_cell)) ) {
          return u3_none;
        }
        else {
          u3_fox hed = u3_ln_ice(l, *u3_li_at_dog_hed(l, a));
          u3_fox tel = u3_ln_ice(l, *u3_li_at_dog_tel(l, a));
          u3_ray ray_nov;
          u3_fox nov;

          ray_nov = l->ray_hat;
          l->ray_hat += u3_wiseof(struct u3_li_cell);
          nov = u3_li_dog_of(ray_nov, 0);

          *u3_li_at_hog_mug(l, nov) = *u3_li_at_hog_mug(l, a);
          *u3_li_at_dog_hed(l, nov) = hed;
          *u3_li_at_dog_tel(l, nov) = tel;

          l->w_cop += 3;
          return nov;
        }
      }
      else {
        u3_w w_len = *u3_li_at_pig_len(l, a);

        if ( u3_no == u3_lm_open(l, (w_len + u3_wiseof(struct u3_li_atom))) ) {
          return u3_none;
        }
        else {
          u3_ray ray_nov;
          u3_fox nov;

          ray_nov = l->ray_hat;
          l->ray_hat += (w_len + u3_wiseof(struct u3_li_atom));
          nov = u3_li_pig_of(ray_nov, 0);

          *u3_li_at_hog_mug(l, nov) = 0;
          *u3_li_at_pig_len(l, nov) = w_len;

          /* Fill the pig.
          */
          {
            u3_w w_i;

            for ( w_i=0; w_i < w_len; w_i++ ) {
              *u3_li_at_pig_buf(l, nov, w_i) = *u3_li_at_pig_buf(l, a, w_i);
            }
          }

          l->w_cop += (2 + w_len);
          return nov;
        }
      }
    }
  }
}

/* u3_ln_mp():
**
**   Copy the GMP integer (mp_a) into an atom on the hat of (l).
*/
u3_l_rat
u3_ln_mp(u3_lv lv,
         mpz_t mp_a)
{
  u3_l l = lv;

  u3_assert(sizeof(mp_limb_t) == 4);

  /* Efficiency: unnecessary copy.
  */
  {
    u3_w w_pug  = mpz_size(mp_a);
    u3_w *w_bav = alloca(w_pug * 4);

    mpz_export(w_bav, 0, -1, 4, 0, 0, mp_a);
    mpz_clear(mp_a);

    return u3_ln_words(l, w_pug, w_bav);
  }
}

/* u3_ln_nock():
**
**    Execute (nock lan sef) with a naive interpreter.
*/
u3_l_rat
u3_ln_nock(u3_lv    lv,
            u3_l_fox lan,
            u3_l_fox sef)
{
  u3_l   l = lv;
  u3_fox hib, fus;

  if ( u3_no == u3_lr_cell(l, sef, &hib, &fus) ) {
    return u3_none;
  }
  else {
    if ( u3_yes == u3_lr_tap(l, hib) ) {
      u3_rat poz = u3_ln_nock(l, lan, hib);
      u3_rat riv = u3_ln_nock(l, lan, fus);

      if ( (u3_none == poz) || (u3_none == riv) ) {
        return u3_none;
      }
      else return u3_ln_cell(l, poz, riv);
    }
    else {
      switch ( hib ) {
        default: return u3_none;

        case 0: {
          if ( u3_no == u3_lr_pat(l, fus) ) {
            return u3_none;
          }
          else {
            u3_rat dof = u3_lr_twig(l, fus, lan);

            if ( u3_none == dof ) {
              return u3_none;
            }
            else return u3_ln_ice(l, dof);
          }
        }
        case 1: {
          return u3_ln_ice(l, fus);
        }
        case 2: {
          u3_rat gof = u3_ln_nock(l, lan, fus);

          if ( (u3_none == gof) || (u3_no == u3_lr_tap(l, gof)) ) {
            return u3_none;
          }
          else {
            return u3_ln_nock(l, u3_h(l, gof), u3_t(l, gof));
          }
        }
        case 3: {
          u3_rat gof = u3_ln_nock(l, lan, fus);

          if ( u3_none == gof ) {
            return u3_none;
          }
          else return u3_lr_tap(l, gof);
        }
        case 4: {
          u3_rat gof = u3_ln_nock(l, lan, fus);

          if ( (u3_none == gof) || (u3_no == u3_lr_pat(l, gof)) ) {
            return u3_none;
          }
          else {
            mpz_t mp_gof;

            u3_lr_mp(l, mp_gof, gof); 
            mpz_add_ui(mp_gof, mp_gof, 1);

            return u3_ln_mp(l, mp_gof);
          }
        } 
        case 5: {
          u3_rat gof = u3_ln_nock(l, lan, fus);

          if ( (u3_none == gof) || (u3_no == u3_lr_tap(l, gof)) ) {
            return u3_none;
          }
          else {
            return u3_lr_eq(l, u3_h(l, gof), u3_t(l, gof));
          }
        }
        case 6: {
          u3_rat yor, fli, paw;

          if ( u3_no == u3_lr_trel(l, fus, &yor, &fli, &paw) ) {
            return u3_none;
          } 
          else {
            u3_rat gyl = u3_ln_nock(l, lan, yor);

            switch ( gyl ) {
              case 0 : return u3_ln_nock(l, lan, fli);
              case 1 : return u3_ln_nock(l, lan, paw);
              default: return u3_none;
            }
          }
        }
      }
    }
  }
}

/* u3_ln_trel(): 
**
**   Produce the trel [a b c] on the hat of [l], or u3_l_none if
**   this would overflow the clam.
*/
u3_l_rat
u3_ln_trel(u3_lv    lv,
           u3_l_fox a,
           u3_l_fox b,
           u3_l_fox c)
{
  u3_l l = lv;

  return u3_ln_cell(l, a, u3_ln_cell(l, b, c));
}

/* u3_ln_words():
**
**   Copy (w_a) words from (w_b) into an atom on the hat of (l).
*/
u3_l_rat
u3_ln_words(u3_lv      lv,
            u3_w       w_a,
            const u3_w *w_b)
{
  u3_l l = lv;

  /* Strip trailing zeroes.
  */
  while ( w_a && !w_b[w_a - 1] ) {
    w_a--;
  }

  /* Check for cat.
  */
  if ( !w_a ) {
    return 0;
  }
  else if ( (w_a == 1) && !(w_b[0] >> 31) ) {
    return w_b[0];
  }

  /* Allocate, fill, return.
  */
  {
    if ( u3_no == u3_lm_open(l, (w_a + u3_wiseof(struct u3_li_atom))) ) {
      return u3_none;
    }
    else { 
      u3_ray ray_nov;
      u3_fox nov;

      ray_nov = l->ray_hat;
      l->ray_hat += (w_a + u3_wiseof(struct u3_li_atom));
      nov = u3_li_pig_of(ray_nov, 0);

      *u3_li_at_hog_mug(l, nov) = 0;
      *u3_li_at_pig_len(l, nov) = w_a;

      /* Fill the words.
      */
      {
        u3_w w_i;

        for ( w_i=0; w_i < w_a; w_i++ ) {
          *u3_li_at_pig_buf(l, nov, w_i) = w_b[w_i];
        }
      }
      return nov;
    }
  }
}
