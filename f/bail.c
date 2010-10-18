/* l/bail.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u2_bl_open(): enter new bail context, returning old.
*/
u2_ray
u2_bl_open(u2_ray wir_r)
{
  u2_ray jub_r = u2_wire_jub_r(wir_r);

  u2_wire_jub_r(wir_r) = u2_rl_ralloc(wir_r, c3_wiseof(jmp_buf));
  if ( 0 == u2_wire_jub_r(wir_r) ) {
    u2_wire_jub_r(wir_r) = jub_r;
    return 0;
  }
  else return jub_r;
}

/* u2_bl_done(): terminate and restore old bail context.
*/
void
u2_bl_done(u2_ray wir_r,
           u2_ray jub_r)
{
  u2_rl_rfree(wir_r, u2_wire_jub_r(wir_r));
  u2_wire_jub_r(wir_r) = jub_r;
}

/* u2_bl_bail(): bail out.
*/
u2_noun
u2_bl_bail(u2_ray wir_r)
{
  longjmp((void *)u2_at_cord(u2_wire_jub_r(wir_r), c3_wiseof(jmp_buf)), 1);
  return u2_none;
}

/* u2_bl_good(): test for u2_none.
*/
u2_noun
u2_bl_good(u2_ray  wir_r,
           u2_weak som)
{
  if ( u2_none == som ) {
    return u2_bl_bail(wir_r);
  }
  else return som;
}

/* u2_bi_h():
**
**   Return the head of (a).
*/
u2_noun
u2_bi_h(u2_ray  wir_r,
        u2_noun a)
{
  if ( u2_no == u2_dust(a) ) return u2_bl_bail(wir_r);

  return u2_h(a);
}

/* u2_bi_t():
**
**   Return the tail of (a).
*/
u2_noun
u2_bi_t(u2_ray  wir_r,
        u2_noun a)
{
  if ( u2_no == u2_dust(a) ) return u2_bl_bail(wir_r);

  return u2_t(a);
}

/* u2_bi_frag():
**
**   Return fragment (a) of (b).
*/
u2_noun
u2_bi_frag(u2_ray  wir_r,
           u2_atom a,
           u2_noun b)
{
  u2_weak c = u2_frag(a, b);

  if ( u2_none == c ) {
    return u2_bl_bail(wir_r);
  } else return c;
}

/* u2_bi_met(): 
**
**   Return the size of (b) in bits, rounded up to
**   (1 << a_y). 
**
**   For example, (a_y == 3) returns the size in bytes.
*/
c3_w
u2_bi_met(u2_ray  wir_r,
          c3_y    a_y,
          u2_noun b)
{
  if ( u2_no == u2_stud(b) ) return u2_bl_bail(wir_r);

  return u2_met(a_y, b);
}

/* u2_bi_bit():
**
**   Return bit (a_w) of (b).
*/
c3_b
u2_bi_bit(u2_ray  wir_r,
          c3_w    a_w,
          u2_noun b)
{
  if ( u2_no == u2_stud(b) ) return u2_bl_bail(wir_r);

  return u2_bit(a_w, b);
}

/* u2_bi_byte():
**
**   Return byte (a_w) of (b).
*/
c3_y
u2_bi_byte(u2_ray  wir_r,
           c3_w    a_w,
           u2_noun b)
{
  if ( u2_no == u2_stud(b) ) return u2_bl_bail(wir_r);

  return u2_byte(a_w, b);
}
        
/* u2_bi_bytes():
**
**  Copy bytes (a_w) through (a_w + b_w - 1) from (d) to (c).
*/
void
u2_bi_bytes(u2_ray  wir_r,
            c3_w    a_w,
            c3_w    b_w,
            c3_y*   c_y,
            u2_noun d)
{
  if ( u2_no == u2_stud(d) ) u2_bl_bail(wir_r);

  u2_bytes(a_w, b_w, c_y, d);
}

/* u2_bi_mp():
**
**   Copy (b) into (a_mp).
*/
void
u2_bi_mp(u2_ray  wir_r,
         mpz_t   a_mp,
         u2_noun b)
{
  if ( u2_no == u2_stud(b) ) u2_bl_bail(wir_r);

  u2_mp(a_mp, b);
}

/* u2_bi_word():
**
**   Return word (a_w) of (b).
*/
c3_w
u2_bi_word(u2_ray  wir_r,
           c3_w    a_w,
           u2_noun b)
{
  if ( u2_no == u2_stud(b) ) return u2_bl_bail(wir_r);

  return u2_word(a_w, b);
}

/* u2_bi_words():
**
**  Copy words (a_w) through (a_w + b_w - 1) from (d) to (c).
*/
void
u2_bi_words(u2_ray  wir_r,
            c3_w    a_w,
            c3_w    b_w,
            c3_w*   c_w,
            u2_noun d)
{
  if ( u2_no == u2_stud(d) ) u2_bl_bail(wir_r);

  u2_words(a_w, b_w, c_w, d);
}

/* u2_bn_bytes():
**
**   Copy [a] bytes from [b].
*/
u2_noun
u2_bn_bytes(u2_ray      wir_r,
            c3_w        a_w,
            const c3_y* b_y)
{
  return u2_bl_good(wir_r, u2_rl_bytes(wir_r, a_w, b_y));
}

/* u2_bn_string():
**
**   u2_bn_bytes(wir_r, strlen(a_c), (c3_y *)a_c);
*/
u2_noun
u2_bn_string(u2_ray      wir_r,
             const c3_c* a_c)
{
  return u2_bl_good(wir_r, u2_rl_string(wir_r, a_c));
}

/* u2_bn_cell(): 
**
**   Produce the cell [a b].
*/
u2_noun
u2_bn_cell(u2_ray  wir_r,
           u2_noun a,
           u2_noun b)
{
  return u2_bl_good(wir_r, u2_rl_cell(wir_r, a, b));
}

/* u2_bn_ice():
**
**   Produce `a`, not referencing the can.  Copy or gain reference.
*/
u2_noun
u2_bn_ice(u2_ray  wir_r,
          u2_noun a)
{
  return u2_bl_good(wir_r, u2_rl_ice(wir_r, a));
}

/* u2_bn_list():
**
**   Generate a null-terminated list, with a 0 terminator.
*/
u2_noun
u2_bn_list(u2_ray wir_r, ...)
{
  c3_w    len_w = 0;
  va_list ap;

  /* Count.
  */
  {
    va_start(ap, wir_r);
    while ( u2_none != va_arg(ap, u2_noun) ) {
      len_w++;
    }
    va_end(ap);
  }

  /* Allocate.
  */
  {
    c3_w    i_w;
    u2_noun yit[len_w];

    va_start(ap, wir_r);
    for ( i_w = 0; i_w < len_w; i_w++ ) {
      yit[i_w] = va_arg(ap, u2_noun);
    }
    va_end(ap);

    /* Construct.
    */
    {
      u2_noun woq = u2_nul;

      for ( i_w = 0; i_w < len_w; i_w++ ) {
        woq = u2_bc(wir_r, yit[len_w - (i_w + 1)], woq);
      }
      return woq;
    }
  }
}
          
/* u2_bn_mp():
**
**   Copy the GMP integer [a] into an atom.
*/
u2_noun
u2_bn_mp(u2_ray wir_r,
         mpz_t  a_mp)
{
  return u2_bl_good(wir_r, u2_rl_mp(wir_r, a_mp));
}

/* u2_bn_qual(): 
**
**   Produce the quadruple [a b c d].
*/
u2_noun
u2_bn_qual(u2_ray  wir_r,
           u2_noun a,
           u2_noun b,
           u2_noun c,
           u2_noun d)
{
  return u2_bl_good(wir_r, u2_rl_qual(wir_r, a, b, c, d));
}

/* u2_bn_quil(): 
**
**   Produce the quintuple [a b c d].
*/
u2_noun
u2_bn_quil(u2_ray  wir_r,
           u2_noun a,
           u2_noun b,
           u2_noun c,
           u2_noun d,
           u2_noun e)
{
  return u2_bn_cell(wir_r, a, u2_bn_qual(wir_r, b, c, d, e));
}

/* u2_bn_trel(): 
**
**   Produce the triple [a b c].
*/
u2_noun
u2_bn_trel(u2_ray  wir_r,
           u2_noun a,
           u2_noun b,
           u2_noun c)
{
  return u2_bl_good(wir_r, u2_rl_trel(wir_r, a, b, c));
}

/* u2_bn_words():
**
**   Copy [a] words from [b] into an atom.
*/
u2_noun
u2_bn_words(u2_ray      wir_r,
            c3_w        a_w,
            const c3_w* b_w)
{
  return u2_bl_good(wir_r, u2_rl_words(wir_r, a_w, b_w));
}
