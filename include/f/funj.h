/* include/funj.h
**
** This file is in the public domain.
*/
  /** Data structures.
  **/
    typedef u2_noun u2_prep;
    typedef u2_noun u2_dump;

  /** Functions.
  **/
    /** Miscellaneous operators - all old.
    **/
      /* u2_fj_op_add(): 
      **
      **   Produce the sum of (a) and (b).
      */
        u2_atom
        u2_fj_op_add(u2_ray  wir_r,
                     u2_atom a,
                     u2_atom b);

      /* u2_fj_op_con():
      **
      **   Produce (a | b).
      */
        u2_atom
        u2_fj_op_con(u2_ray  wir_r,
                     u2_atom a,
                     u2_atom b);

      /* u2_fj_op_dec():
      **
      **   Produce (atom - 1), or bull if (atom) is 0.
      */
        u2_weak
        u2_fj_op_dec(u2_ray  wir_r,
                     u2_atom atom);

      /* u2_fj_op_div():
      **
      **   Produce (b / a), or bull if (a) is 0.
      */
        u2_weak
        u2_fj_op_div(u2_ray  wir_r,
                     u2_atom a,
                     u2_atom b);

      /* u2_fj_op_inc():
      **
      **   Produce (atom + 1).
      */
        u2_atom
        u2_fj_op_inc(u2_ray  wir_r,
                     u2_atom atom);

      /* u2_fj_op_log():
      **
      **   Produce the lowest m_log such that (1 << m_log) > m.
      */
        u2_atom
        u2_fj_op_log(u2_ray  wir_r,
                     u2_atom atom);
        
      /* u2_fj_op_lsh():
      **
      **   Produce (b << a).
      */
        u2_atom
        u2_fj_op_lsh(u2_ray  wir_r,
                     u2_atom a,
                     u2_atom b);

      /* u2_fj_op_peg():
      **
      **   Concatenate (twig_a) above (twig_b).
      */
        u2_atom
        u2_fj_op_peg(u2_ray  wir_r,
                     u2_atom twig_a,
                     u2_atom twig_b);

      /* u2_fj_op_rsh():
      **
      **   Produce (b >> a).
      */
        u2_atom
        u2_fj_op_rsh(u2_ray  wir_r,
                     u2_atom a,
                     u2_atom b);

      /* u2_fj_op_sub():
      **
      **   Produce (b - a), or bull if (a > b).
      */
        u2_weak
        u2_fj_op_sub(u2_ray  wir_r,
                  u2_atom a,
                  u2_atom b);

      /* u2_fj_op_tip():
      **
      **   Produce the root of (twig) - 2 or 3; o4 bull if (twig) is 1.
      */
        u2_weak
        u2_fj_op_tip(u2_atom twig);

      /* u2_fj_op_tap():
      **
      **   Produce (twig) with the root bit removed, or bull if (twig) is 1.
      */
        u2_weak
        u2_fj_op_tap(u2_ray  wir_r,
                     u2_atom twig);


    /** Pools (sets).
    **/
      /* u2_fj_pool_ok(): sanity test for pool.
      */
        c3_t
        u2_fj_pool_ok(u2_pool pool);

      /* u2_fj_pool_in():
      **
      **   Return 1 iff (pig) is in (pool).
      */
        c3_t
        u2_fj_pool_in(u2_noun pig,
                      u2_pool pool);

      /* u2_fj_pool_add():
      **
      **   Produce a version of (pool_sub) which includes (pig).
      */
        u2_noun
        u2_fj_pool_add(u2_ray  wir_r,
                       u2_noun pig,
                       u2_pool pool_sub);
   
      /* u2_fj_pool_list():
      **
      **   Convert (pool) to a pseudo-randomly sorted list, 
      **   prepending to (list).
      */
        u2_list
        u2_fj_pool_list(u2_ray  wir_r,
                        u2_list list,
                        u2_pool pool);

      /* u2_fj_pool_cat():
      **
      **   Produce a version of (pool_b) which includes all entries
      **   in (pool_a).
      */
        u2_noun
        u2_fj_pool_cat(u2_ray  wir_r,
                       u2_pool pool_a,
                       u2_pool pool_b);

    /** Books (associative arrays).
    **/
      /* u2_fj_book_is():
      **
      **   Return 1 iff (noun) is a book.
      */
        c3_t
        u2_fj_book_is(u2_noun book);

      /* u2_fj_book_in():
      **
      **   Return 1 iff (tag_in) is in (book).
      */
        c3_t
        u2_fj_book_in(u2_noun tag_in,
                      u2_book  book);

      /* u2_fj_book_get(): 
      **
      **   Produce the dog in (book) matching (tag_get), or u2_none.
      */
        u2_weak
        u2_fj_book_get(u2_noun tag_get,
                       u2_book  book);

      /* u2_fj_book_add():
      **
      **   Produce a new book which adds (tag_add dog_add) to (book).
      **   Replace old dog, if any.
      */
        u2_book
        u2_fj_book_add(u2_ray  wir_r,
                       u2_noun tag_add,
                       u2_noun dog_add,
                       u2_book  book);

      /* u2_fj_book_add_list():
      **
      **   Produce a new book which adds all (tag dog) cells in
      **   (list) to (book).  Replace old dog, if any.
      */
        u2_book
        u2_fj_book_add_list(u2_ray  wir_r,
                            u2_list  list,
                            u2_book  book);

      /* u2_fj_book_list():
      **
      **   Convert (book) to a pseudo-randomly sorted list of (tag dog) 
      **   cells, prepending to (list).
      */
        u2_list
        u2_fj_book_list(u2_ray  wir_r,
                        u2_list list,
                        u2_book book);

    /** Prep and pump (prettyprinting).
    **/
      /* u2_fj_prep_textual():
      **
      **   Prep with a text bias; fall back to decimal.
      */
        u2_prep
        u2_fj_prep_textual(u2_ray  wir_r,
                           u2_atom atom);

      /* u2_fj_prep_decimal():
      **
      **   Prep a decimal value.
      */
        u2_prep
        u2_fj_prep_decimal(u2_ray  wir_r,
                           u2_atom atom);

      /* u2_fj_prep_heximal():
      **
      **   Prep a hexadecimal value, with 0x.
      */
        u2_prep
        u2_fj_prep_heximal(u2_ray  wir_r,
                           u2_atom atom);

      /* u2_fj_prep_hexinal():
      **
      **   Prep a heximal value, without 0x.
      */
        u2_prep
        u2_fj_prep_hexinal(u2_ray  wir_r,
                           u2_atom atom);

      /* u2_fj_prep_noun():
      **
      **   Convert (noun) to a prep, which is
      **
      **      (text)
      **    | (.glue *prep)
      **    | (.nail *prep)
      */
        u2_prep
        u2_fj_prep_noun(u2_ray  wir_r,
                        u2_noun noun);

      /* u2_fj_prep_close():
      **
      **   Prep a list of preps, in (xb_a, xb_b).
      */
        u2_prep
        u2_fj_prep_close(u2_ray  wir_r,
                         c3_y    xb_a,
                         c3_y    xb_b,
                         u2_list gah);

      /* u2_fj_pump_dump():
      **
      **   Convert (prep) to a dump, printing (cols) wide.
      */
        u2_dump
        u2_fj_pump_dump(u2_ray wir_r,
                        c3_w    xw_cols,
                        u2_prep prep);

      /* u2_err():
      **
      **   Print (nopt) with (caption), using (lane).
      */
        void
        u2_err(u2_ray      wir_r,
               const c3_c* cl_caption,
               u2_weak     noun);

      /* u2_burp():
      **
      **   Print (prep) with (caption), using (lane).
      */
        void
        u2_burp(u2_ray      wir_r,
                const c3_c* cl_caption,
                u2_prep     prep);
