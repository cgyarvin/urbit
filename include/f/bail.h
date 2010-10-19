/* include/bail.h
**
** This file is in the public domain.
*/
  /** Functions.
  **/
    /** Fail-specific.
    **/
      /* u2_bl_open(): enter new bail context, returning old (or 0).
      */
        u2_ray
        u2_bl_open(u2_ray wir_r);

      /* u2_bl_done(): terminate and restore old bail context.
      */
        void
        u2_bl_done(u2_ray wir_r,
                   u2_ray jub_r);

      /* u2_bl_set(): wrapper for setjmp().
      */
#     if 0
        c3_t
        u2_bl_set(u2_ray wir_r);
#     else
#       define u2_bl_set(wir_r) \
          setjmp((void *)u2_at_cord(u2_wire_jub_r(wir_r), c3_wiseof(jmp_buf)))
#     endif
           
      /* u2_bl_bail(): bail out.
      */
        u2_noun
        u2_bl_bail(u2_ray wir_r);

      /* u2_bl_good(): test for u2_none.
      */
        u2_noun
        u2_bl_good(u2_ray wir_r, u2_weak som);


    /** General.  All functions bail out on error.
    **/
      /** Cell access.
      **/
        /* u2_bi_h():
        **
        **   Return the head of (a).
        */
          u2_noun
          u2_bi_h(u2_ray  wir_r,
                  u2_noun a);

        /* u2_bi_t():
        **
        **   Return the tail of (a).
        */
          u2_noun
          u2_bi_t(u2_ray  wir_r,
                  u2_noun a);

        /* u2_bi_frag():
        **
        **   Return fragment (a) of (b).
        */
          u2_noun
          u2_bi_frag(u2_ray  wir_r,
                     u2_atom a,
                     u2_noun b);

      /** Atom access.
      **/
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
                    u2_noun b);

        /* u2_bi_bit():
        **
        **   Return bit (a_w) of (b).
        */
          c3_b
          u2_bi_bit(u2_ray  wir_r,
                    c3_w    a_w,
                    u2_noun b);
       
        /* u2_bi_byte():
        **
        **   Return byte (a_w) of (b).
        */
          c3_y
          u2_bi_byte(u2_ray  wir_r,
                     c3_w    a_w,
                     u2_noun b);
                  
        /* u2_bi_bytes():
        **
        **  Copy bytes (a_w) through (a_w + b_w - 1) from (d) to (c).
        */
          void
          u2_bi_bytes(u2_ray  wir_r,
                      c3_w    a_w,
                      c3_w    b_w,
                      c3_y*   c_y,
                      u2_noun d);

        /* u2_bi_mp():
        **
        **   Copy (b) into (a_mp).
        */
          void
          u2_bi_mp(u2_ray  wir_r,
                   mpz_t   a_mp,
                   u2_noun b);

        /* u2_bi_word():
        **
        **   Return word (a_w) of (b).
        */
          c3_w
          u2_bi_word(u2_ray  wir_r,
                     c3_w    a_w,
                     u2_noun b);

        /* u2_bi_words():
        **
        **  Copy words (a_w) through (a_w + b_w - 1) from (d) to (c).
        */
          void
          u2_bi_words(u2_ray  wir_r,
                      c3_w    a_w,
                      c3_w    b_w,
                      c3_w*   c_w,
                      u2_noun d);

        /** Noun construction.
        **/
          /* u2_bn_bytes():
          **
          **   Copy [a] bytes from [b].
          */
            u2_noun
            u2_bn_bytes(u2_ray      wir_r,
                        c3_w        a_w,
                        const c3_y* b_y);

          /* u2_bn_string():
          **
          **   u2_bn_bytes(wir_r, strlen(a_c), (c3_y *)a_c);
          */
            u2_noun
            u2_bn_string(u2_ray      wir_r,
                         const c3_c* a_c);

          /* u2_bn_tape():
          **
          **   Create an atomic string from a list of bytes.
          */
            u2_noun 
            u2_bn_tape(u2_ray  wir_r,
                       u2_list lit);

          /* u2_bn_cell(): 
          **
          **   Produce the cell [a b].
          */
            u2_noun
            u2_bn_cell(u2_ray  wir_r,
                       u2_noun a,
                       u2_noun b);
#         define u2_bc(wir_r, a, b) u2_bn_cell(wir_r, a, b)
#         define u2_bo(wir_r, a)    u2_bn_cell(wir_r, a, _0)

          /* u2_bn_decimal():
          **
          **   On (wir_r), write (list), a list of digits, as a decimal.
          */
            u2_noun
            u2_bn_decimal(u2_ray  wir_r,
                          u2_list lit);

          /* u2_bn_heximal():
          **
          **   On (wir_r), write (lit), a list of digits, as a hexadecimal.
          */
            u2_noun
            u2_bn_heximal(u2_ray  wir_r,
                          u2_list lit);

          /* u2_bn_ice():
          **
          **   Produce `a`, not referencing the can.  Copy or gain reference.
          */
            u2_noun
            u2_bn_ice(u2_ray  wir_r,
                      u2_noun a);

          /* u2_bn_list():
          **
          **   Generate a null-terminated list, with u2_none as terminator.
          */
            u2_noun
            u2_bn_list(u2_ray wir_r, ...);
          
          /* u2_bn_mp():
          **
          **   Copy the GMP integer [a] into an atom.
          */
            u2_noun
            u2_bn_mp(u2_ray wir_r,
                     mpz_t  a_mp);

          /* u2_bn_qual(): 
          **
          **   Produce the quadruple [a b c d].
          */
            u2_noun
            u2_bn_qual(u2_ray  wir_r,
                       u2_noun a,
                       u2_noun b,
                       u2_noun c,
                       u2_noun d);
#         define u2_bq(wir_r, a, b, c, d) u2_bn_qual(wir_r, a, b, c, d)

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
                       u2_noun e);
#         define u2_bu(wir_r, a, b, c, d, e) u2_bn_quil(wir_r, a, b, c, d, e)

          /* u2_bn_trel(): 
          **
          **   Produce the triple [a b c].
          */
            u2_noun
            u2_bn_trel(u2_ray  wir_r,
                       u2_noun a,
                       u2_noun b,
                       u2_noun c);
#         define u2_bt(wir_r, a, b, c) u2_bn_trel(wir_r, a, b, c)

          /* u2_bn_words():
          **
          **   Copy [a] words from [b] into an atom.
          */
            u2_noun
            u2_bn_words(u2_ray      wir_r,
                      c3_w        a_w,
                      const c3_w* b_w);
