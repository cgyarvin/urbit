/* x/xeno.c
**
** This file is in the public domain.
*/
#include "all.h"

/* _xi_boot_l(): boot the l (loom) layer.
*/
static void
_xi_boot_l(u3_x x)
{
  x->l.cap_ray += (c3_wiseof(struct u3_xeno) - 
                   c3_wiseof(struct u3_loom));
}

/* _xi_boot_n(): boot the n (nock) layer.
*/
static void
_xi_boot_n(u3_x x)
{
  x->n.lab_ray = 0;
}

#if 0
/* _xi_boot_qdec(): boot decrement for testing.
*/
static u3_flag
_xi_boot_qdec(u3_x x)
{
  u3_rat nax = u3_b_load(&x->l, u3_cm_dec);

  if ( u3_none == nax ) {
    return u3_no;
  }
  else {
    u3_rat gaq = u3_b_watt(&x->l, nax);

    if ( u3_none == gaq ) {
      return u3_no;
    } else {
      /* fip: initial mold
      ** gub: [mold form] of kernel gene
      */
      u3_fox fip = u3_ln_trel
        (x, u3_cm_crib, 
            u3_ln_cell(x, 'a', u3_cm_atom),
            0);
      u3_rat gub = u3_b_mill(&x->l, gaq, fip);
 
      if ( u3_none == gub ) {
        return u3_no;
      }
      else {
        x->q.dec = u3_t(x, gub);

        return u3_yes;
      }
    }
  }
}

/* _xi_boot_q(): boot the q (watt) layer.
*/
static u3_flag
_xi_boot_q(u3_x x)
{
  u3_rat poc = u3_b_load(&x->l, u3_cm_reck);

  if ( u3_none == poc ) {
    return u3_no;
  }
  else {
    /* xum: kernel gene
    */
    u3_rat xum = u3_b_watt(&x->l, poc);

    if ( u3_none == xum ) {
      return u3_no;
    }
    else {
      /* fip: initial mold
      ** gub: [mold form] of kernel gene
      */
      u3_fox fip = u3_ln_cell(x, u3_cm_cube, 0);
      u3_rat gub = u3_b_mill(&x->l, xum, fip);
 
      if ( u3_none == gub ) {
        return u3_no;
      }
      else {
        /* har: kernel mold
        ** fet: kernel form
        ** cug: kernel grit
        */
        u3_fox har = u3_h(x, gub);
        u3_fox fet = u3_t(x, gub);
        u3_fox cug;

        if ( (0 != u3_x_run(x, &cug, 0, fet, 0)) ) {
          return u3_no;
        }
        else {
          x->q.tef = u3_ln_cell(x, har, cug);
          return u3_yes;
        }
      }
    }
  }
}
#endif

/* u3_x_do():
**
**   Execute (nock a b), asserting on failure.
*/
u3_fox
u3_x_do(u3_x   x,
        u3_fox a,
        u3_fox b)
{
  u3_fox fev;

  if ( 0 == u3_x_run(x, &fev, a, b, 0) ) {
    return fev;
  }
  else {
    c3_assert(0); return 0;
  }
}

/* u3_x_new():
**
**   Create a xeno core, mallocing (1 << y_a) words of memory.
**   Return 0 if malloc fails.  Free with free().
*/
u3_x
u3_x_new(c3_y y_a)
{
  u3_l l;

  if ( !(l = u3_lm_new(y_a) ) ) {
    return 0;
  }
  else {
    u3_x x = (void *)l;

    _xi_boot_l(x);
    _xi_boot_n(x);

#if 0
    if ( u3_no == _xi_boot_q(x) ) {
      free(x); return 0;
    }
    if ( u3_no == _xi_boot_qdec(x) ) {
      free(x); return 0;
    }
    if ( u3_no == u3_xj_boot(x, 255) ) {
      free(x); return 0;
    }
#endif
    return x;
  }
}
