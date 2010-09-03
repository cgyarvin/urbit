/* x/c.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_xc_trap():
**
**   Trap with longjmp().  Does not return.
*/
int
u3_xc_trap(u3_x            x,
           enum u3_xc_trap trap_a)
{
  printf("trap: %d\n", trap_a);
  longjmp(x->jmp_lum, trap_a);

  return 0;
}

/* u3_xc_alloc_w(): 
**
**   Allocate (w_a) words on (x).  Traps if allocation fails.
*/
void *
u3_xc_alloc_w(u3_x x,
              u3_w w_a)
{
  void *v_fup = u3_lm_alloc(x, w_a);

  if ( !v_fup ) {
    u3_xc_trap(x, u3_xc_trap_fail);
    return 0;
  }
  else return v_fup;
}

/* u3_xc_bytes():
**
**   Copy (w_a) bytes from (y_b) into an atom on the hat of (l).
*/
u3_fox
u3_xc_bytes(u3_x x,
            u3_w w_a,
            u3_y *y_b)
{
  u3_rat tav = u3_ln_bytes(x, w_a, y_b);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}

/* u3_xc_string():
**
**   u3_xc_bytes(l, strlen(c_a), (u3_y *)c_a);
*/
u3_fox
u3_xc_string(u3_x x,
             u3_c *c_a)
{
  u3_rat tav = u3_ln_string(x, c_a);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}

/* u3_xc_cell(): 
**
**   Produce the cell (a b) on the hat of (l), or u3_l_none if
**   this would overflow the clam.
*/
u3_fox
u3_xc_cell(u3_x   x,
           u3_fox a,
           u3_fox b)
{
  u3_rat tav = u3_ln_cell(x, a, b);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}

/* u3_xc_ice():
**
**   Produce a noun equivalent to (a), which does not reference
**   any data on the can of (l).
*/
u3_fox
u3_xc_ice(u3_x   x,
          u3_fox a)
{
  u3_rat tav = u3_ln_ice(x, a);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}

/* u3_xc_mp():
**
**   Copy the GMP integer (mp_a) into an atom on the hat of (l).
*/
u3_fox
u3_xc_mp(u3_x  x,
         mpz_t mp_a)
{
  u3_rat tav = u3_ln_mp(x, mp_a);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}

/* u3_xc_trel(): 
**
**   Produce the trel [a b c] on the hat of [l], or u3_l_none if
**   this would overflow the clam.
*/
u3_fox
u3_xc_trel(u3_x   x,
           u3_fox a,
           u3_fox b,
           u3_fox c)
{
  u3_rat tav = u3_ln_trel(x, a, b, c);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}

/* u3_xc_words():
**
**   Copy (w_a) words from (w_b) into an atom on the hat of (l).
*/
u3_fox
u3_xc_words(u3_x  x,
            u3_w  w_a,
            u3_w  *w_b)
{
  u3_rat tav = u3_ln_words(x, w_a, w_b);

  if ( u3_none == tav ) {
    return u3_xc_trap(x, u3_xc_trap_fail);
  }
  else return tav;
}
