/* l/new.c
** 
** This file is in the public domain.
*/
#include "all.h"

#include <stdio.h>

/* u3_ln_bytes():
**
**   Copy (a_w) bytes from (b_y) into an atom on the hat of (l).
*/
u3_rat
u3_ln_bytes(u3_lv       lv,
            c3_w        a_w,
            const c3_y  *b_y)
{
  u3_l l = lv;

  /* Strip trailing zeroes.
  */
  while ( a_w && !b_y[a_w - 1] ) {
    a_w--;
  }

  /* Check for cat.
  */
  if ( a_w <= 4 ) {
    if ( !a_w ) {
      return 0;
    }
    else if ( a_w == 1 ) {
      return b_y[0];
    }
    else if ( a_w == 2 ) {
      return (b_y[0] | (b_y[1] << 8));
    }
    else if ( a_w == 3 ) {
      return (b_y[0] | (b_y[1] << 8) | (b_y[2] << 16));
    }
    else if ( (b_y[3] <= 0x7f) ) {
      return (b_y[0] | (b_y[1] << 8) | (b_y[2] << 16) | (b_y[3] << 24));
    }
  }

  /* Allocate, fill, return.
  */
  {
    c3_w len_w = (a_w + 3) >> 2;

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

      /* Clear the words.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < len_w; i_w++ ) {
          *u3_at_pig_buf(l, nov, i_w) = 0;
        }
      }

      /* Fill the bytes.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < a_w; i_w++ ) {
          *u3_at_pig_buf(l, nov, (i_w >> 2))
            |=
              (b_y[i_w] << ((i_w & 3) * 8));
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
u3_rat
u3_ln_string(u3_lv      lv,
             const c3_c *c_a)
{
  u3_l l = lv;

  return u3_ln_bytes(l, strlen(c_a), (c3_y *)c_a);
}

/* u3_ln_cell(): 
**
**   Produce the cell (a b) on the hat of (l), or u3_none if
**   this would overflow the clam.
*/
u3_rat
u3_ln_cell(u3_lv    lv,
           u3_fox a,
           u3_fox b)
{
  u3_l l = lv;

  c3_assert(u3_none != a);
  c3_assert(u3_none != b);

  if ( u3_none == (a = u3_ln_ice(l, a)) ) {
    return u3_none;
  }
  else if ( u3_none == (b = u3_ln_ice(l, b)) ) {
    return u3_none;
  }
  else if ( u3_no == u3_lm_open(l, c3_wiseof(struct u3_cell)) ) {
    printf("not open\n");
    return u3_none;
  }
  else {
    u3_ray ray_nov;
    u3_fox nov;

    ray_nov = l->hat_ray;
    l->hat_ray += c3_wiseof(struct u3_cell);
    nov = u3_hog_of(ray_nov, 0);

    *u3_at_dog_mug(l, nov) = 0;
    *u3_at_hog_hed(l, nov) = a;
    *u3_at_hog_tel(l, nov) = b;

    return nov;
  }
}

/* u3_ln_ice():
**
**   Produce a noun equivalent to (a), which does not reference
**   any data on the can of (l).
*/
u3_rat
u3_ln_ice(u3_lv    lv,
          u3_fox a)
{
  u3_l l = lv;

  if ( u3_rat_is_cat(a) ) {
    return a;
  }
  else {
    u3_ray ray_a = u3_dog_a(a);

    if ( (u3_ray_a(ray_a) == u3_ray_a(l->hat_ray)) ||
         (ray_a < l->mat_ray) )
    {
      return a;
    }
    else {
      if ( u3_dog_is_hog(a) ) {
        if ( u3_no == u3_lm_open(l, c3_wiseof(struct u3_cell)) ) {
          return u3_none;
        }
        else {
          u3_fox hed = u3_ln_ice(l, *u3_at_hog_hed(l, a));
          u3_fox tel = u3_ln_ice(l, *u3_at_hog_tel(l, a));
          u3_ray ray_nov;
          u3_fox nov;

          ray_nov = l->hat_ray;
          l->hat_ray += c3_wiseof(struct u3_cell);
          nov = u3_hog_of(ray_nov, 0);

          *u3_at_dog_mug(l, nov) = *u3_at_dog_mug(l, a);
          *u3_at_hog_hed(l, nov) = hed;
          *u3_at_hog_tel(l, nov) = tel;

          l->cop_w += 3;
          return nov;
        }
      }
      else {
        c3_w len_w = *u3_at_pig_len(l, a);

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
              *u3_at_pig_buf(l, nov, i_w) = *u3_at_pig_buf(l, a, i_w);
            }
          }

          l->cop_w += (2 + len_w);
          return nov;
        }
      }
    }
  }
}

/* u3_ln_mp():
**
**   Copy the GMP integer (a_mp) into an atom on the hat of (l).
*/
u3_rat
u3_ln_mp(u3_lv lv,
         mpz_t a_mp)
{
  u3_l l = lv;

  c3_assert(sizeof(mp_limb_t) == 4);

  /* Efficiency: unnecessary copy.
  */
  {
    c3_w pyg_w  = mpz_size(a_mp);
    c3_w *bav_w = alloca(pyg_w * 4);

    mpz_export(bav_w, 0, -1, 4, 0, 0, a_mp);
    mpz_clear(a_mp);

    return u3_ln_words(l, pyg_w, bav_w);
  }
}

/* u3_ln_nock():
**
**    Execute (nock lan sef) with a naive interpreter.
*/
u3_rat
u3_ln_nock(u3_lv  lv,
           u3_fox lan,
           u3_fox sef)
{
  u3_l   l = lv;
  u3_fox hib, fus;

  if ( u3_no == u3_lr_cell(l, sef, &hib, &fus) ) {
    return u3_none;
  }
  else {
    if ( u3_yes == u3_lr_dust(l, hib) ) {
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
          if ( u3_no == u3_lr_stud(l, fus) ) {
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

          if ( (u3_none == gof) || (u3_no == u3_lr_dust(l, gof)) ) {
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
          else return u3_lr_dust(l, gof);
        }
        case 4: {
          u3_rat gof = u3_ln_nock(l, lan, fus);

          if ( (u3_none == gof) || (u3_no == u3_lr_stud(l, gof)) ) {
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

          if ( (u3_none == gof) || (u3_no == u3_lr_dust(l, gof)) ) {
            return u3_none;
          }
          else {
            return u3_lr_sing(l, u3_h(l, gof), u3_t(l, gof));
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
        case 7: {
          if ( u3_no == u3_lr_dust(l, fus) ) {
            return u3_none;
          } else {
            u3_rat bud = u3_ln_nock(l, lan, u3_lr_h(l, fus));
     
            if ( u3_none == bud ) {
              return u3_none;
            } else {
              return u3_ln_nock(l, bud, u3_lr_t(l, fus));
            }
          }
        }
        case 8: {
          if ( u3_no == u3_lr_dust(l, fus) ) {
            return u3_none;
          } else {
            u3_rat bud = u3_ln_nock(l, lan, u3_lr_h(l, fus));
     
            if ( u3_none == bud ) {
              return u3_none;
            } else {
              return u3_ln_nock(l, u3_ln_cell(l, bud, lan), u3_lr_t(l, fus));
            }
          }
        }
        case 11: {
          if ( u3_no == u3_lr_dust(l, fus) ) {
            return u3_none;
          } else {
            return u3_ln_nock(l, lan, u3_lr_t(l, fus));
          }
        }
        case 12: {
          if ( u3_no == u3_lr_dust(l, fus) ) {
            return u3_none;
          } else {
            return u3_ln_cell(l, lan, u3_lr_t(l, fus));
          }
        }
      }
    }
  }
}

/* u3_ln_trel(): 
**
**   Produce the trel [a b c] on the hat of [l], or u3_none if
**   this would overflow the clam.
*/
u3_rat
u3_ln_trel(u3_lv  lv,
           u3_fox a,
           u3_fox b,
           u3_fox c)
{
  u3_l l = lv;

  return u3_ln_cell(l, a, u3_ln_cell(l, b, c));
}

/* u3_ln_words():
**
**   Copy (a_w) words from (w_b) into an atom on the hat of (l).
*/
u3_rat
u3_ln_words(u3_lv      lv,
            c3_w       a_w,
            const c3_w *w_b)
{
  u3_l l = lv;

  /* Strip trailing zeroes.
  */
  while ( a_w && !w_b[a_w - 1] ) {
    a_w--;
  }

  /* Check for cat.
  */
  if ( !a_w ) {
    return 0;
  }
  else if ( (a_w == 1) && !(w_b[0] >> 31) ) {
    return w_b[0];
  }

  /* Allocate, fill, return.
  */
  {
    if ( u3_no == u3_lm_open(l, (a_w + c3_wiseof(struct u3_atom))) ) {
      return u3_none;
    }
    else { 
      u3_ray ray_nov;
      u3_fox nov;

      ray_nov = l->hat_ray;
      l->hat_ray += (a_w + c3_wiseof(struct u3_atom));
      nov = u3_pig_of(ray_nov, 0);

      *u3_at_dog_mug(l, nov) = 0;
      *u3_at_pig_len(l, nov) = a_w;

      /* Fill the words.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < a_w; i_w++ ) {
          *u3_at_pig_buf(l, nov, i_w) = w_b[i_w];
        }
      }
      return nov;
    }
  }
}
