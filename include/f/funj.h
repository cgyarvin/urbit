/* include/funj.h
**
** This file is in the public domain.
*/
  /** Data structures.
  **/
    typedef u2_noun u2_prep;

  /** Functions.
  **/
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
