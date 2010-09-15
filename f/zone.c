/* l/zone.c
** 
** This file is in the public domain.
*/
#include "all.h"

/* u2_zn_boot():
**
**  Create an empty zone in an empty loom, with memory model `hip`.
**  See u2_zn_leap() for storage policies.
*/
u2_ray
u2_zn_boot(c3_m hip_m)
{
  u2_ray zon_r = u2_ray_of(0, 0);
  u2_ray mat_r = u2_ray_of(0, c3_wiseof(u2_loom_zone));
  u2_ray cap_r = mat_r;
  u2_ray hat_r = u2_ray_of(1, 0);
  u2_ray rut_r = hat_r;
  u2_ray pot_r = mat_r;

  if ( hip_m == c3__warm ) {
    cap_r += c3_wiseof(u2_loom_zone_warm);
    u2_zone_warm_fre(pot_r) = 0;
  } 
  else if ( hip_m == c3__cold ) {
    cap_r += c3_wiseof(u2_loom_zone_pot);
  } 
  else c3_assert(0);

  u2_zone_pot_mat(pot_r) = 0;
  u2_zone_pot_rut(pot_r) = 0;

  u2_zone_cap(zon_r) = cap_r;
  u2_zone_hat(zon_r) = hat_r;
  u2_zone_mat(zon_r) = mat_r;
  u2_zone_rut(zon_r) = rut_r;

  u2_zone_hip(zon_r) = hip_m;
  u2_zone_cop(zon_r) = 0;

  return zon_r;
}

#if 0
/* _zn_bloq_valid()::
*/
static void
_zn_bloq_valid(u2_ray zon_r)
{
  if ( c3__warm == u2_zone_hip(zon_r) ) {
    u2_ray pot_r = u2_zone_mat(zon_r);
    u2_ray fre_r = u2_zone_warm_fre(pot_r);

    while ( fre_r ) {
      if ( u2_ray_a(fre_r) > 1 ) {
        c3_assert(0);
      }
      if ( u2_ray_a(fre_r) != u2_ray_a(u2_zone_hat(zon_r)) ) {
        c3_assert(0);
      }
      if ( (fre_r + u2_zone_hut_siz(fre_r)) >= u2_zone_hat(zon_r) ) {
        c3_assert(0);
      }
      if ( (0 != u2_zone_hut_pre(fre_r)) ) {
        if ( u2_ray_a(u2_zone_hut_pre(fre_r)) > 1 ) {
          {
            printf("fre %d:%x; pre %d:%x\n",
                    u2_ray_a(fre_r),
                    u2_ray_b(fre_r),
                    u2_ray_a(u2_zone_hut_pre(fre_r)),
                    u2_ray_b(u2_zone_hut_pre(fre_r)));
          }
          c3_assert(0);
        }
        c3_assert(fre_r == u2_zone_hut_nex(u2_zone_hut_pre(fre_r)));
      }
      if ( (0 != u2_zone_hut_nex(fre_r)) ) {
        if ( u2_ray_a(u2_zone_hut_nex(fre_r)) > 1 ) {
          c3_assert(0);
        }
        c3_assert(fre_r == u2_zone_hut_pre(u2_zone_hut_nex(fre_r)));
      }
      fre_r = u2_zone_hut_nex(fre_r);
    }
  }
}
#endif

/* _zn_bloq_make():
**
**  Install a liquid block at `box_r`, with size `siz_w` and 
**  use count `use_w`.
*/
static void
_zn_bloq_make(u2_ray zon_r,
              u2_ray box_r,
              c3_w   siz_w,
              c3_w   use_w)
{
  c3_assert(siz_w >= 6);
  {
    *u2_at_ray(box_r) = siz_w;
    *u2_at_ray(box_r + 1) = use_w;
    *u2_at_ray(box_r + siz_w - 1) = siz_w;
  }
}

/* _zn_bloq_attach():
**
**  Attach the bloq at `box_r` to the free list.
*/
static void
_zn_bloq_attach(u2_ray zon_r, 
                u2_ray box_r)
{
  u2_ray pot_r = u2_zone_mat(zon_r);
  u2_ray fre_r = u2_zone_warm_fre(pot_r);

  u2_zone_hut_pre(box_r) = 0;
  u2_zone_hut_nex(box_r) = u2_zone_warm_fre(pot_r);

  if ( 0 != fre_r ) {
    c3_assert(u2_zone_hut_pre(fre_r) == 0);
    u2_zone_hut_pre(fre_r) = box_r;
  }

  u2_zone_warm_fre(pot_r) = box_r;
}

/* _zn_bloq_detach():
**
**  Unlist the bloq at `box_r` from the free list.
*/
static void
_zn_bloq_detach(u2_ray zon_r,
                u2_ray box_r)
{
  u2_ray pot_r = u2_zone_mat(zon_r);
  u2_ray pre_r = u2_zone_hut_pre(box_r);
  u2_ray nex_r = u2_zone_hut_nex(box_r);

  if ( 0 != pre_r ) {
    u2_zone_hut_nex(pre_r) = nex_r;
  } else {
    u2_zone_warm_fre(pot_r) = u2_zone_hut_nex(box_r);
  }

  if ( 0 != nex_r ) {
    u2_zone_hut_pre(nex_r) = pre_r;
  }
}

/* _zn_bloq_grab():
**
**  Allocate [len_w] words of memory on [zon_r], or return 0.
*/
static u2_ray
_zn_bloq_grab(u2_ray zon_r,
              c3_w   len_w)
{
  if ( c3__cold == u2_zone_hip(zon_r) ) {
    /* Cold allocation - without a box.
    */
    if ( u2_no == u2_zn_open(zon_r, len_w) ) {
      return 0;
    }
    else { 
      u2_ray box_r;

      box_r = u2_zone_hat(zon_r);
      u2_zone_hat(zon_r) += len_w;
      return box_r;
    }
  }
  else if ( c3__warm == u2_zone_hip(zon_r) ) {
    c3_w   siz_w = (len_w + c3_wiseof(u2_loom_zone_box) + 1);
    u2_ray pot_r = u2_zone_mat(zon_r);
    u2_ray pfr_r = u2_aftr(pot_r, u2_loom_zone_warm, fre_r);

    while ( 1 ) {
      u2_ray fre_r = *u2_at_ray(pfr_r);
      u2_ray box_r;

      if ( 0 == fre_r ) {
        /* Nothing found in the free list.  Try to allocate on the hat.
        */
        if ( u2_no == u2_zn_open(zon_r, siz_w) ) {
          return 0;
        }
        else { 
          box_r = u2_zone_hat(zon_r);
          u2_zone_hat(zon_r) += siz_w;

          _zn_bloq_make(zon_r, box_r, siz_w, 1);
          return (box_r + c3_wiseof(u2_loom_zone_box));
        }
      } else {
        if ( u2_ray_a(fre_r) > 1 ) {
          c3_assert(0);
        }
        if ( siz_w > u2_zone_hut_siz(fre_r) ) {
          /* This free block is too small.  Continue searching.
          */
          pfr_r = u2_aftr(fre_r, u2_loom_zone_hut, nex_r);
        } 
        else {
          /* We have found a free block of adequate size.  Remove it
          ** from the free list.
          */
          box_r = fre_r;
          _zn_bloq_detach(zon_r, box_r);

          *u2_at_ray(pfr_r) = u2_zone_hut_nex(box_r);

          if ( (siz_w + 6) < u2_zone_hut_siz(box_r) ) {
            /* Split the block.
            */
            u2_ray end_r = (box_r + siz_w);

            _zn_bloq_make(zon_r, end_r, u2_zone_hut_siz(fre_r) - siz_w, 0);
            _zn_bloq_attach(zon_r, end_r);
            _zn_bloq_make(zon_r, box_r, siz_w, 1);
          }
          else {
            c3_assert(u2_zone_box_use(box_r) == 0);
            u2_zone_box_use(box_r) = 1;
          }
          return (box_r + c3_wiseof(u2_loom_zone_box));
        }
      }
    }
  }
  else { c3_assert(0); return 0; }
}

#if 0
/* _zn_bloq_grap()::
*/
static u2_ray
_zn_bloq_grap(u2_ray zon_r,
              c3_w   len_w)
{
  u2_ray nov_r;

  if ( random() & 1 ) {
    nov_r = _zn_bloq_grab(zon_r, len_w + (random() % 1023));
  } else {
    nov_r = _zn_bloq_grab(zon_r, len_w);
  }
  {
    c3_w i_w;

    for ( i_w = 0; i_w < len_w; i_w++ ) {
      *u2_at_ray(nov_r + i_w) = 0xdeadbeef + i_w;
    }
  }

  return nov_r;
}
#endif

/* _zn_bloq_free():
**
**    Release and coalesce a block.
*/
static void
_zn_bloq_free(u2_ray zon_r,
              u2_ray box_r)
{
  u2_ray rut_r = u2_zone_rut(zon_r);
  u2_ray hat_r = u2_zone_hat(zon_r);

  c3_assert(u2_zone_hut_use(box_r) == 0);
  c3_assert(u2_ray_a(box_r) == u2_ray_a(rut_r));
  c3_assert(box_r >= rut_r);

  // return;

  /* Try to coalesce with the previous block.
  */
  if ( box_r != rut_r ) {
    c3_w   las_w = *u2_at_ray(box_r - 1);
    u2_ray tod_r = (box_r - las_w);

    if ( 0 == u2_zone_hut_use(tod_r) ) {
      _zn_bloq_detach(zon_r, tod_r);
      _zn_bloq_make(zon_r, tod_r, (las_w + u2_zone_hut_siz(box_r)), 0);
      box_r = tod_r;
    }
  }

  /* Try to coalesce with the next block, or with the wilderness.
  */
  {
    c3_w siz_w = u2_zone_hut_siz(box_r);

    if ( (box_r + siz_w == hat_r) ) {
      u2_zone_hat(zon_r) = box_r;
    }
    else {
      u2_ray hob_r = (box_r + siz_w);

      if ( 0 == u2_zone_hut_use(hob_r) ) {
        _zn_bloq_detach(zon_r, hob_r);
        _zn_bloq_make(zon_r, box_r, (siz_w + u2_zone_hut_siz(hob_r)), 0);
      }

      /* Add to the free list.
      */
      _zn_bloq_attach(zon_r, box_r);
    }
  }
}

/* u2_zn_leap():
**
**   Reverse the beams forward.
*/
u2_flag
u2_zn_leap(u2_ray zon_r,
           c3_m   hop_m)
{
  if ( hop_m == c3__warm ) {
    if ( u2_no == u2_zn_open(zon_r, c3_wiseof(u2_loom_zone_warm)) ) {
      return u2_no;
    }
  } else {
    if ( u2_no == u2_zn_open(zon_r, c3_wiseof(u2_loom_zone_pot)) ) {
      return u2_no;
    }
  }

  /*    Before: 
  * 0           rut   hat                                  1GB
  * |            |     |                                     | 
  * |-------------------########-----------------------------|
  * |                           |      |                     |
  *                            cap    mat
  *//*  After:
  * 0                 mat cap                              1GB
  * |                  | /                                   | 
  * |--------------------#######-----------------------------|
  * |                           |                            |
  *                          hat+rut 
  */
  {
    u2_ray cap_r = u2_zone_cap(zon_r);
    u2_ray hat_r = u2_zone_hat(zon_r);
    u2_ray mat_r = u2_zone_mat(zon_r);
    u2_ray rut_r = u2_zone_rut(zon_r);
    c3_m   hip_m = u2_zone_hip(zon_r);

    /* Classical beam reversal.
    */
    {
      u2_zone_cap(zon_r) = hat_r;
      u2_zone_hat(zon_r) = cap_r;
      u2_zone_mat(zon_r) = hat_r; 
      u2_zone_rut(zon_r) = cap_r;
      u2_zone_hip(zon_r) = hop_m;
    }

    /* Save the old beam in the pot.
    */
    {
      u2_ray pot_r = hat_r;

      if ( hop_m == c3__warm ) {
        u2_zone_cap(zon_r) += c3_wiseof(u2_loom_zone_warm);
        u2_zone_warm_fre(pot_r) = 0;
      } 
      else if ( hop_m == c3__cold ) {
        u2_zone_cap(zon_r) += c3_wiseof(u2_loom_zone_pot);
      } 
      else c3_assert(0);

      u2_zone_pot_mat(pot_r) = mat_r;
      u2_zone_pot_rut(pot_r) = rut_r;
      u2_zone_pot_hip(pot_r) = hip_m;
    }
  }
  return u2_yes;
}

/* u2_zn_fall():
**
**   Reverse the beams backward, restoring the old mat and rut.
*/
void
u2_zn_fall(u2_ray zon_r)
{
  /*    Before: 
  * 0           rut   hat                                  1GB
  * |            |     |                                     | 
  * |-------------------########-----------------------------|
  * |                           |      |                     |
  *                            cap    mat
  *//*  After:
  * 0      mat        cap                                  1GB
  * |       |          |                                     | 
  * |-------------------###############----------------------|
  * |                                  |      |              |
  *                                   hat    rut
  */
  {
    u2_ray hat_r = u2_zone_hat(zon_r);
    u2_ray mat_r = u2_zone_mat(zon_r);
    u2_ray pot_r = mat_r;
   
    u2_zone_cap(zon_r) = hat_r;
    u2_zone_hat(zon_r) = mat_r;
    u2_zone_mat(zon_r) = u2_zone_pot_mat(pot_r);
    u2_zone_rut(zon_r) = u2_zone_pot_rut(pot_r);
    u2_zone_hip(zon_r) = u2_zone_pot_hip(pot_r);
  }
}

/* u2_zn_gain():
**
**   Gain a reference to [som] in [zon_r].
*/
void
u2_zn_gain(u2_ray  zon_r,
           u2_noun som)
{
  if ( u2_fly_is_dog(som) ) {
    u2_ray som_r = u2_dog_a(som);
    u2_ray hat_r = u2_zone_hat(zon_r);

    if ( u2_ray_a(som_r) == u2_ray_a(hat_r) ) {
      c3_m   hip_m = u2_zone_hip(zon_r);

      if ( c3__warm == hip_m ) {
        u2_ray rut_r = u2_zone_rut(zon_r);
        
        if ( som_r > rut_r ) {
          u2_ray box_r = (som_r - c3_wiseof(u2_loom_zone_box));
          c3_w   use_w = u2_zone_box_use(box_r);

          c3_assert(use_w != 0);
          if ( use_w != 0xffffffff ) {
            u2_zone_box_use(box_r) = (use_w + 1);
          }
        }
      }
    }
    else {
      /* In the can (above the mat), counting propagates down.
      */
      if ( u2_dog_is_pom(som) ) {
        u2_ray mat_r = u2_zone_mat(zon_r);

        if ( som_r >= mat_r ) {
          u2_zn_gain(zon_r, *u2_at(som_r, u2_loom_cell, hed_r));
          u2_zn_gain(zon_r, *u2_at(som_r, u2_loom_cell, tel_r));
        }
      }
    }
  }
}

/* u2_zn_lose():
**
**   Lose a reference to (som).  Free it if refcount == 0.
*/
void
u2_zn_lose(u2_ray  zon_r, 
           u2_noun som)
{
  if ( u2_fly_is_dog(som) ) {
    u2_ray som_r = u2_dog_a(som);
    u2_ray hat_r = u2_zone_hat(zon_r);

    if ( u2_ray_a(som_r) == u2_ray_a(hat_r) ) {
      c3_m hip_m = u2_zone_hip(zon_r);

      if ( c3__warm == hip_m ) {
        u2_ray rut_r = u2_zone_rut(zon_r);
        
        if ( som_r >= rut_r ) {
          u2_ray box_r = (som_r - c3_wiseof(u2_loom_zone_box));
          c3_w   use_w = u2_zone_box_use(box_r);

          if ( 1 == use_w ) {
            if ( u2_dog_is_pom(som) ) {
              u2_zn_lose(zon_r, u2_h(som));
              u2_zn_lose(zon_r, u2_t(som));
            }
            u2_zone_box_use(box_r) = 0;
            _zn_bloq_free(zon_r, box_r);
          }
          else {
            if ( use_w != 0xffffffff ) {
              u2_zone_box_use(box_r) = (use_w - 1);
            }
          }
        }
      }
    }
    else {
      /* In the can (above the mat), counting propagates down.
      */
      if ( u2_dog_is_pom(som) ) {
        u2_ray mat_r = u2_zone_mat(zon_r);

        if ( som_r >= mat_r ) {
          u2_zn_lose(zon_r, *u2_at(som_r, u2_loom_cell, hed_r));
          u2_zn_lose(zon_r, *u2_at(som_r, u2_loom_cell, tel_r));
        }
      }
    }
  }
}

/* u2_zn_senior():
**
**   Yes iff `som` is senior in `zon` - ie, does not
**   require reference counting.
*/
u2_flag
u2_zn_senior(u2_ray  zon_r,
             u2_noun som)
{
  if ( u2_fly_is_dog(som) ) {
    u2_ray som_r = u2_dog_a(som);
    u2_ray hat_r = u2_zone_hat(zon_r);

    if ( u2_ray_a(som_r) == u2_ray_a(hat_r) ) {
      u2_ray rut_r = u2_zone_rut(zon_r);
      c3_m   hip_m = u2_zone_hip(zon_r);

      if ( (c3__warm == hip_m) && (som_r > rut_r) ) {
        return u2_no;
      }
    }
    else {
      u2_ray mat_r = u2_zone_mat(zon_r);

      if ( som_r >= mat_r ) {
        return u2_no;
      }
    }
  }
  return u2_yes;
}

/* u2_zn_flog():
**
**   Release the can, setting cap to top of pot.
*/
void
u2_zn_flog(u2_ray zon_r)
{
  u2_ray pot_r = u2_zone_mat(zon_r);

  if ( u2_zone_pot_hip(pot_r) == c3__warm ) {
    u2_zone_cap(zon_r) = u2_zone_mat(zon_r) + c3_wiseof(u2_loom_zone_warm);
  } else {
    u2_zone_cap(zon_r) = u2_zone_mat(zon_r) + c3_wiseof(u2_loom_zone_pot);
  }
}

/* u2_zn_open():
**
**   Yes iff [a] more words remain in the pad.
*/
u2_flag
u2_zn_open(u2_ray zon_r,
           c3_w   a_w)
{
  return 
    ((a_w + u2_ray_b(u2_zone_hat(zon_r)) + u2_ray_b(u2_zone_cap(zon_r)))
     >= LoomSize)
    ? u2_no
    : u2_yes;
}

/* u2_zn_clear():
**
**   Yes iff [lef] does not point to any word >= [net]
**   and < [bat].
*/
u2_flag
u2_zn_clear(u2_noun lef,
            u2_ray  net_r,
            u2_ray  bat_r)
{
  c3_assert(u2_ray_a(net_r) == u2_ray_a(bat_r));

  if ( u2_fly_is_cat(lef) ) {
    return u2_yes;
  } else {
    u2_ray ray_lef = u2_dog_a(lef);

    if ( u2_ray_a(ray_lef) != u2_ray_a(net_r) ) {
      return u2_yes;
    }
    else if ( ray_lef < net_r ) {
      return u2_yes;
    }
    else if ( ray_lef >= bat_r ) {
      if ( u2_dog_is_pom(lef) ) {
        u2_noun hed = *u2_at_pom_hed(lef);
        u2_noun tel = *u2_at_pom_tel(lef);

        if ( (u2_yes == u2_zn_clear(hed, net_r, bat_r)) &&
             (u2_yes == u2_zn_clear(tel, net_r, bat_r)) ) {
          return u2_yes;
        }
        else return u2_no;
      }
      else return u2_yes;
    }
    else return u2_no;
  }
}

/* u2_zn_tamp():
**
**   Tamp, eneting the segment from [net_r] up to [bat_r],
**   preserving the root [lef].
**
**   Assumes u2_zn_clear() with the same arguments.
*/
  /* _tamp_swizzle()::
  **
  **   Shift the root [lef], above [bat], down by [pif].
  */
  static void
  _tamp_swizzle(u2_noun lef,
                c3_w    pif_w,
                u2_ray  bat_r,
                c3_b    nax_b[])
  {
    /* Totally unnecessary assertions.
    */
    {
      c3_assert(u2_fly_is_dog(lef));
      c3_assert(u2_dog_a(lef) >= bat_r);
    }

    /* Only poms are fixed.
    */
    if ( u2_dog_is_pom(lef) ) {
      u2_ray ray_lef = u2_dog_a(lef);
      
      /* Is this pom fixed?
      */
      if ( nax_b[ray_lef - bat_r] ) {
        return;
      }
      else {
        /* Fix the pom!
        */
        nax_b[ray_lef - bat_r] = 1;
        {
          u2_noun fes = *u2_at_pom_hed(lef);
          u2_noun hoz = *u2_at_pom_tel(lef);

          if ( u2_fly_is_dog(fes) &&
               (u2_dog_beam(fes) == u2_ray_beam(bat_r)) &&
               (u2_dog_ray(fes) >= bat_r) )
          {
            /* Rewrite the pointer.
            */
            *u2_at_pom_hed(lef) = (fes - (pif_w << 2));
            
            /* Swizzle into it.
            */
            _tamp_swizzle(fes, pif_w, bat_r, nax_b);
          }

          if ( u2_fly_is_dog(hoz) &&
               (u2_dog_beam(hoz) == u2_ray_beam(bat_r)) &&
               (u2_dog_ray(hoz) >= bat_r) )
          {
            /* Rewrite the pointer.
            */
            *u2_at_pom_tel(lef) = (hoz - (pif_w << 2));
            
            /* Swizzle into it.
            */
            _tamp_swizzle(hoz, pif_w, bat_r, nax_b);
          }
        }
      }
    }
  }
u2_noun
u2_zn_tamp(u2_ray  zon_r,
           u2_noun lef,
           u2_ray  net_r,
           u2_ray  bat_r)
{
  /* pif: length of the segment to enete.
  ** lam: length of the segment to shift down over it.
  */
  c3_w pif_w = (bat_r - net_r);
  c3_w lam_w = (u2_zone_cap(zon_r) - bat_r);
  c3_w i_w;

  /* Stupid, unnecessary assertions.
  */
  {
    /* Layer should at least handle this case, actually.
    */
    c3_assert(u2_fly_is_dog(lef));

    c3_assert(u2_ray_a(bat_r) == u2_ray_a(net_r));
    c3_assert(u2_ray_a(u2_dog_a(lef)) == u2_ray_a(net_r));
    c3_assert(u2_dog_a(lef) >= bat_r);
  }

  /* Swizzle the good segment down to its new location.
  **
  **   nax[i_w]: 1 iff a pom at bat[i_w] has been fixed.
  */
  {
    c3_b nax_b[lam_w];
    c3_w i_w;

    for ( i_w = 0; i_w < lam_w; i_w++ ) {
      nax_b[i_w] = 0;
    }
    _tamp_swizzle(lef, pif_w, bat_r, nax_b);
  }

  /* Move the good segment down.
  */
  for ( i_w = 0; i_w < lam_w; i_w++ ) {
    *u2_at_ray((net_r + i_w)) = *u2_at_ray((bat_r + i_w));
  }
  u2_zone_cap(zon_r) -= pif_w;

  /* Move and return [lef].
  */
  return (lef - (pif_w << 2));
}

/* u2_zn_water():
**
**   Return east and west watermarks, respectively.
*/
void
u2_zn_water(u2_ray zon_r,
            c3_w*  maz_w,
            c3_w*  buc_w)
{
  if ( !u2_ray_beam(u2_zone_hat(zon_r)) ) {
    *maz_w = u2_ray_point(u2_zone_hat(zon_r));
    *buc_w = u2_ray_point(u2_zone_cap(zon_r));
  } else {
    *maz_w = u2_ray_point(u2_zone_cap(zon_r));
    *buc_w = u2_ray_point(u2_zone_hat(zon_r));
  }
}

/* u2_zn_bytes():
**
**   Copy [a] bytes from [b].
*/
u2_weak
u2_zn_bytes(u2_ray      zon_r,
            c3_w        a_w,
            const c3_y* b_y)
{
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

    if ( u2_no == u2_zn_open(zon_r, 
                             (len_w + c3_wiseof(u2_loom_atom))) ) {
      return u2_none;
    }
    else { 
      u2_ray nov_r;
      u2_noun nov;

      nov_r = _zn_bloq_grab(zon_r, (len_w + c3_wiseof(u2_loom_atom)));
      nov = u2_pug_of(nov_r, 0);

      *u2_at_dog_mug(nov) = 0;
      *u2_at_pug_len(nov) = len_w;

      /* Clear the words.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < len_w; i_w++ ) {
          *u2_at_pug_buf(nov, i_w) = 0;
        }
      }

      /* Fill the bytes.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < a_w; i_w++ ) {
          *u2_at_pug_buf(nov, (i_w >> 2))
            |=
              (b_y[i_w] << ((i_w & 3) * 8));
        }
      }
      return nov;
    }
  }
}

/* u2_zn_string():
**
**   u2_zn_bytes(zon_r, strlen(a_c), (c3_y *)a_c)
*/
u2_weak
u2_zn_string(u2_ray      zon_r,
             const c3_c* a_c)
{
  return u2_zn_bytes(zon_r, strlen(a_c), (c3_y *)a_c);
}

/* u2_zn_cell(): 
**
**   Produce the cell [a b].
*/
u2_weak
u2_zn_cell(u2_ray  zon_r,
           u2_noun a,
           u2_noun b)
{
  /* This is just plain illegal.
  */
  {
    c3_assert(u2_none != a);
    c3_assert(u2_none != b);
  }

  /* Seniority restrictions.  Ice if these cannot be met.
  */
  {
    c3_assert(u2_fly_is_cat(a) ||
              (u2_ray_a(u2_dog_a(a)) == u2_ray_a(u2_zone_hat(zon_r))) ||
              (u2_dog_a(a) < u2_zone_mat(zon_r)));

    c3_assert(u2_fly_is_cat(b) ||
              (u2_ray_a(u2_dog_a(b)) == u2_ray_a(u2_zone_hat(zon_r))) ||
              (u2_dog_a(b) < u2_zone_mat(zon_r)));
  }

  if ( u2_no == u2_zn_open(zon_r, c3_wiseof(u2_loom_cell)) ) {
    return u2_none;
  }
  else {
    u2_ray nov_r;
    u2_noun nov;

    nov_r = _zn_bloq_grab(zon_r, c3_wiseof(u2_loom_cell));
    nov = u2_pom_of(nov_r, 0);

    *u2_at_dog_mug(nov) = 0;
    *u2_at_pom_hed(nov) = a;
    *u2_at_pom_tel(nov) = b;

    return nov;
  }
}

/* u2_zn_ice():
**
**   Produce [a], not referencing the can.
*/
u2_weak
u2_zn_ice(u2_ray  zon_r,
          u2_noun fiz)
{
  if ( u2_fly_is_cat(fiz) ) {
    return fiz;
  }
  else {
    u2_ray fiz_ray = u2_dog_a(fiz);

    if ( (u2_ray_a(fiz_ray) == u2_ray_a(u2_zone_hat(zon_r)) ) ) {
      u2_zn_gain(zon_r, fiz);
      return fiz;
    }
    else {
      if ( (fiz_ray < u2_zone_mat(zon_r)) ) {
        return fiz;
      }
      else {
        if ( u2_dog_is_pom(fiz) ) {
          if ( u2_no == u2_zn_open(zon_r, c3_wiseof(u2_loom_cell)) ) {
            return u2_none;
          }
          else {
            u2_noun hed = u2_zn_ice(zon_r, *u2_at_pom_hed(fiz));
            u2_noun tel = u2_zn_ice(zon_r, *u2_at_pom_tel(fiz));
            u2_ray nov_r;
            u2_noun nov;

            nov_r = _zn_bloq_grab(zon_r, c3_wiseof(u2_loom_cell));
            nov = u2_pom_of(nov_r, 0);

            *u2_at_dog_mug(nov) = *u2_at_dog_mug(fiz);
            *u2_at_pom_hed(nov) = hed;
            *u2_at_pom_tel(nov) = tel;

            u2_zone_cop(zon_r) += 3;
            return nov;
          }
        }
        else {
          c3_w len_w = *u2_at_pug_len(fiz);

          if ( u2_no == u2_zn_open(zon_r, 
                                   (len_w + c3_wiseof(u2_loom_atom))) ) {
            return u2_none;
          }
          else {
            u2_ray nov_r;
            u2_noun nov;

            nov_r = _zn_bloq_grab(zon_r, (len_w + c3_wiseof(u2_loom_atom)));
            nov = u2_pug_of(nov_r, 0);

            *u2_at_dog_mug(nov) = 0;
            *u2_at_pug_len(nov) = len_w;

            /* Fill the pug.
            */
            {
              c3_w i_w;

              for ( i_w=0; i_w < len_w; i_w++ ) {
                *u2_at_pug_buf(nov, i_w) = *u2_at_pug_buf(fiz, i_w);
              }
            }

            u2_zone_cop(zon_r) += (2 + len_w);
            return nov;
          }
        }
      }
    }
  }
}

/* u2_zn_mp():
**
**   Copy the GMP integer [a] into an atom.
*/
u2_weak
u2_zn_mp(u2_ray zon_r,
         mpz_t  a_mp)
{
  c3_assert(sizeof(mp_limb_t) == 4);

  /* Efficiency: unnecessary copy.
  */
  {
    c3_w pyg_w  = mpz_size(a_mp);
    c3_w *bav_w = alloca(pyg_w * 4);

    mpz_export(bav_w, 0, -1, 4, 0, 0, a_mp);
    mpz_clear(a_mp);

    return u2_zn_words(zon_r, pyg_w, bav_w);
  }
}

/* u2_zn_qual(): 
**
**   Produce the quadruple [a b c d].
*/
u2_weak
u2_zn_qual(u2_ray  zon_r,
           u2_noun a,
           u2_noun b,
           u2_noun c,
           u2_noun d)
{
  return u2_zn_cell(zon_r, a, u2_zn_trel(zon_r, b, c, d));
}

/* u2_zn_trel(): 
**
**   Produce the triple [a b c].
*/
u2_weak
u2_zn_trel(u2_ray  zon_r,
           u2_noun a,
           u2_noun b,
           u2_noun c)
{
  return u2_zn_cell(zon_r, a, u2_zn_cell(zon_r, b, c));
}

/* u2_zn_words():
**
**   Copy [a] words from [b] into an atom.
*/
u2_weak
u2_zn_words(u2_ray      zon_r,
            c3_w        a_w,
            const c3_w* b_w)
{
  /* Strip trailing zeroes.
  */
  while ( a_w && !b_w[a_w - 1] ) {
    a_w--;
  }

  /* Check for cat.
  */
  if ( !a_w ) {
    return 0;
  }
  else if ( (a_w == 1) && !(b_w[0] >> 31) ) {
    return b_w[0];
  }

  /* Allocate, fill, return.
  */
  {
    if ( u2_no == u2_zn_open(zon_r, (a_w + c3_wiseof(u2_loom_atom))) ) {
      return u2_none;
    }
    else { 
      u2_ray  nov_r;
      u2_noun nov;

      nov_r = _zn_bloq_grab(zon_r, (a_w + c3_wiseof(u2_loom_atom)));
      nov = u2_pug_of(nov_r, 0);

      *u2_at_dog_mug(nov) = 0;
      *u2_at_pug_len(nov) = a_w;

      /* Fill the words.
      */
      {
        c3_w i_w;

        for ( i_w=0; i_w < a_w; i_w++ ) {
          *u2_at_pug_buf(nov, i_w) = b_w[i_w];
        }
      }
      return nov;
    }
  }
}
