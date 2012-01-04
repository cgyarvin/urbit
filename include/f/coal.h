/* include/coal.h
**
** This file is in the public domain.
*/
  /** coal.h: common noun substrate.
  ***
  *** Generally modeled on stage 223, but ideally isolated from it.
  *** Currently depends for implementation on direct-linked jets.
  ***
  *** Functions of the same name and tier may vary subtly from 
  *** kernel semantics.  Be wary and read the header comment.
  ***
  *** Most coal functions depend on u2_Wire, a thread-local global,
  *** which addresses all memory and other thread state.  This in
  *** turn depends on u2_System.
  **/
 
  /** Globals.
  **/
    c3_global u2_ray u2_Wire;                 //  __thread or equivalent


  /** Aliases - selective and syntactically unique.
  **/
#   define u2h(som)          u2_cx_h(som)
#   define u2t(som)          u2_cx_t(som)
#   define u2at(axe, som)    u2_cx_at(axe, som)

#   define u2nc(a, b)        u2_cn_cell(a, b)
#   define u2nt(a, b, c)     u2_cn_trel(a, b, c)
#   define u2nq(a, b, c, d)  u2_cn_qual(a, b, c, d)
#   define u2ni(a)           u2ic(a, 0)


  /** u2_cx*: crash-only core traversal.  
  ***
  ***    unless otherwise noted, u2_cx callers *retain* ownership of 
  ***    all argument nouns and pointers, and *preserve* ownership of
  ***    all results.
  ***
  ***    u2_cx functions always bail with c3__exit.
  **/
#if 1
#     define u2_cx_h(som)        u2_bi_h(u2_Wire, som)
#     define u2_cx_t(som)        u2_bi_t(u2_Wire, som)
#     define u2_cx_at(axe, som)  u2_bi_frag(axe, som)
#     define u2_cx_cell(a, b, c)  u2_bi_cell(u2_Wire, a, b, c)
#     define u2_cx_trel(a, b, c, d)  u2_bi_trel(u2_Wire, a, b, c, d)
#     define u2_cx_qual(a, b, c, d)
#else
    /* u2_cx_h (u2h): head.
    */
      u2_noun 
      u2_cx_h(u2_noun som);

    /* u2_cx_t (u2t): tail.
    */
      u2_noun
      u2_cx_t(u2_noun som);

    /* u2_cx_at (u2at): fragment.
    */
      u2_noun
      u2_cx_at(u2_noun som);

    /* u2_cx_cell():
    **
    **   Divide `a` as a cell `[b c]`.
    */
      void
      u2_cx_cell(u2_noun  a,
                 u2_noun* b,
                 u2_noun* c);

    /* u2_cx_trel():
    **
    **   Divide `a` as a trel `[b c d]`, or bail.
    */
      void
      u2_cx_trel(u2_noun  a,
                 u2_noun* b,
                 u2_noun* c,
                 u2_noun* d);

    /* u2_cx_qual():
    **
    **   Divide `a` as a quadruple `[b c d e]`.
    */
      void
      u2_cx_qual(u2_noun  a,
                 u2_noun* b,
                 u2_noun* c,
                 u2_noun* d,
                 u2_noun* e);
    
#endif

  /** u2_cr*: crash-free core traversal.
  ***
  ***    unless otherwise noted, u2_cr callers *retain* ownership of 
  ***    all argument nouns and pointers, and *preserve* ownership of
  ***    all results.
  ***
  ***    u2_cr functions never bail (throw an exception).
  **/
    //  XX: bound by cpp to the older, underlying loom layer.
    //
#if 1
#       define u2_cr_du(a)                     u2_dust(a)
#       define u2_cr_ud(a)                     u2_stud(a)
#       define u2_cr_at(a, b)                  u2_frag(a, b)
#       define u2_cr_mean                      u2_mean
#       define u2_cr_mug(a)                    u2_mug(a)
#       define u2_cr_mug_string(a)             u2_mug_string(a)
#       define u2_cr_mug_words(a)              u2_mug_words(a)
#       define u2_cr_mug_cell(a, b)            u2_mug_cell(a, b)
#       define u2_cr_mug_trel(a, b, c)         u2_mug_cell(a, b, c)
#       define u2_cr_mug_qual(a, b, c, d)      u2_mug_qual(a, b, c, d)
#       define u2_cr_mug_both(a, b)            u2_mug_both(a, b)
#       define u2_cr_fing(a, b)                u2_fing(a, b)
#       define u2_cr_fing_c(a_c, b)            u2_fing_c(a_c, b)
#       define u2_cr_fing_cell(p, q, b)        u2_fing_cell(p, q, b)
#       define u2_cr_fing_mixt(p_c, q, b)      u2_fing_mixt(p_c, q, b)
#       define u2_cr_fing_trel(p, q, r, b)     u2_fing_trel(p, q, r, b)
#       define u2_cr_fing_qual(p, q, r, s, b)  u2_fing_qual(p, q, r, s, b)
#       define u2_cr_sing(a, b)                u2_sing(a, b)
#       define u2_cr_sing_c(a_c, b)            u2_sing_c(a_c, b)
#       define u2_cr_sing_cell(p, q, b)        u2_sing_cell(p, q, b)
#       define u2_cr_sing_mixt(p_c, q, b)      u2_sing_mixt(p_c, q, b)
#       define u2_cr_sing_trel(p, q, r, b)     u2_sing_trel(p, q, r, b)
#       define u2_cr_sing_qual(p, q, r, s, b)  u2_sing_qual(p, q, r, s, b)
#       define u2_cr_nord(a, b)                u2_as_nord(a, b)
#       define u2_cr_bush(a, b, c)             u2_as_bush(a, b, c)
#       define u2_cr_cell(a, b, c)             u2_as_cell(a, b, c)
#       define u2_cr_trel(a, b, c, d)          u2_as_trel(a, b, c, d)
#       define u2_cr_qual(a, b, c, d, e)       u2_as_qual(a, b, c, d, e)
#       define u2_cr_p(a, b, c)                u2_as_p(a, b, c)
#       define u2_cr_pq(a, b, c, d)            u2_as_pq(a, b, c, d)
#       define u2_cr_pqr(a, b, c, d, e)        u2_as_pqr(a, b, c, d, e)
#       define u2_cr_pqrs(a, b, c, d, e, f)    u2_as_pqrs(a, b, c, d, e, f)
#       define u2_cr_pqrs(a, b, c, d, e, f)    u2_as_pqrs(a, b, c, d, e, f)
#       define u2_cr_met(a_y, b)               u2_met(a_y, b)
#       define u2_cr_bit(a_w, b)               u2_bit(a_w, b) 
#       define u2_cr_byte(a_w, b)              u2_byte(a_w, b)
#       define u2_cr_bytes(a_w, b_w, c_y, d)   u2_bytes(a_w, b_w, c_y, d)
#       define u2_cr_chop(m, f, w, t, d, s)    u2_chop(m, f, w, t, d, s)
#       define u2_cr_mp(a_mp, b)               u2_mp(a_mp, b)
#       define u2_cr_word(a_w, b)              u2_word(a_w, b)
#       define u2_cr_words(a_w, b_w, c_w, d)   u2_words(a_w, b_w, c_w, d)
#else
      /* u2_cr_du(): u2_yes iff `a` is cell.
      */
        u2_flag
        u2_cr_du(u2_noun a);

      /* u2_cr_ud(): u2_no iff `a` is cell.
      */
        u2_flag
        u2_cr_ud(u2_noun a);

      /* u2_cr_at(): fragment `a` of `b`, or none.
      */
        u2_weak
        u2_cr_at(u2_atom a, 
                 u2_weak b);

      /* u2_cr_mean():
      **
      **   Attempt to deconstruct `a` by axis, noun pairs; 0 terminates.
      **   Axes must be sorted in tree order.
      */
        u2_flag
        u2_cr_mean(u2_noun a,
                   ...);

      /* u2_cr_mug():
      **
      **   Compute and/or recall the mug (31-bit hash) of (a).
      */
        c3_w
        u2_cr_mug(u2_noun a);
    
      /* u2_cr_mug_string():
      **
      **   Compute the mug of `a`, LSB first.
      */
        c3_w
        u2_cr_mug_string(const c3_c *a_c);

      /* u2_cr_mug_words():
      **
      **   Compute the mug of `buf`, `len`, LSW first.
      */
        c3_w
        u2_cr_mug_words(const c3_w *buf_w,
                        c3_w        len_w);

      /* u2_cr_mug_cell():
      **
      **   Compute the mug of `[a b]`.
      */
        c3_w
        u2_cr_mug_cell(u2_noun a,
                       u2_noun b);

      /* u2_cr_mug_trel():
      **
      **   Compute the mug of `[a b c]`.
      */
        c3_w
        u2_cr_mug_trel(u2_noun a,
                       u2_noun b,
                       u2_noun c);

      /* u2_cr_mug_qual():
      **
      **   Compute the mug of `[a b c d]`.
      */
        c3_w
        u2_cr_mug_qual(u2_noun a,
                       u2_noun b,
                       u2_noun c,
                       u2_noun d);

      /* u2_cr_mug_both():
      **
      **   Join two mugs.
      */
        c3_w
        u2_cr_mug_both(c3_w a_w,
                       c3_w b_w);


      /* u2_cr_fing():
      **
      **   Yes iff (a) and (b) are the same copy of the same noun.
      **   (Ie, by pointer equality - u2_cr_sing with false negatives.)
      */
        u2_flag
        u2_cr_fing(u2_noun a,
                   u2_noun b);

      /* u2_cr_fing_c():
      **
      **   Yes iff (b) is the same copy of the same noun as the C string [a].
      */
        u2_flag
        u2_cr_fing_c(const c3_c* a_c,
                     u2_noun     b);

      /* u2_cr_fing_cell():
      **
      **   Yes iff `[p q]` and `b` are the same copy of the same noun.
      */
        u2_flag
        u2_cr_fing_cell(u2_noun p,
                        u2_noun q,
                        u2_noun b);

      /* u2_cr_fing_mixt():
      **
      **   Yes iff `[p q]` and `b` are the same copy of the same noun.
      */
        u2_flag
        u2_cr_fing_mixt(const c3_c* p_c,
                        u2_noun     q,
                        u2_noun     b);

      /* u2_cr_fing_trel():
      **
      **   Yes iff `[p q r]` and `b` are the same copy of the same noun.
      */
        u2_flag
        u2_cr_fing_trel(u2_noun p,
                        u2_noun q,
                        u2_noun r,
                        u2_noun b);

      /* u2_cr_fing_qual():
      **
      **   Yes iff `[p q r s]` and `b` are the same copy of the same noun.
      */
        u2_flag
        u2_cr_fing_qual(u2_noun p,
                        u2_noun q,
                        u2_noun r,
                        u2_noun s,
                        u2_noun b);

      /* u2_cr_sing():
      **
      **   Yes iff (a) and (b) are the same noun.
      */
        u2_flag
        u2_cr_sing(u2_noun a,
                   u2_noun b);

      /* u2_cr_sing_c():
      **
      **   Yes iff (b) is the same noun as the C string [a].
      */
        u2_flag
        u2_cr_sing_c(const c3_c* a_c,
                     u2_noun     b);

      /* u2_cr_sing_cell():
      **
      **   Yes iff `[p q]` and `b` are the same noun.
      */
        u2_flag
        u2_cr_sing_cell(u2_noun p,
                        u2_noun q,
                        u2_noun b);

      /* u2_cr_sing_mixt():
      **
      **   Yes iff `[p q]` and `b` are the same noun.
      */
        u2_flag
        u2_cr_sing_mixt(const c3_c* p_c,
                        u2_noun     q,
                        u2_noun     b);

      /* u2_cr_sing_trel():
      **
      **   Yes iff `[p q r]` and `b` are the same noun.
      */
        u2_flag
        u2_cr_sing_trel(u2_noun p,
                        u2_noun q,
                        u2_noun r,
                        u2_noun b);

      /* u2_cr_sing_qual():
      **
      **   Yes iff `[p q r s]` and `b` are the same noun.
      */
        u2_flag
        u2_cr_sing_qual(u2_noun p,
                        u2_noun q,
                        u2_noun r,
                        u2_noun s,
                        u2_noun b);

      /* u2_cr_nord():
      **
      **   Return 0, 1 or 2 if `a` is below, equal to, or above `b`.
      */
        u2_atom
        u2_cr_nord(u2_noun a,
                   u2_noun b);

      /* u2_cr_mold():
      **
      **   Divide `a` as a mold `[b.[p q] c]`.
      */
        u2_flag
        u2_cr_mold(u2_noun  a,
                   u2_noun* b,
                   u2_noun* c);

      /* u2_cr_cell():
      **
      **   Divide `a` as a cell `[b c]`.
      */
        u2_flag
        u2_cr_cell(u2_noun  a,
                   u2_noun* b,
                   u2_noun* c);

      /* u2_cr_trel():
      **
      **   Divide `a` as a trel `[b c]`.
      */
        u2_flag
        u2_cr_trel(u2_noun  a,
                   u2_noun* b,
                   u2_noun* c,
                   u2_noun* d);

      /* u2_cr_qual():
      **
      **   Divide (a) as a qual (b c d e).
      */
        u2_flag
        u2_cr_qual(u2_noun  a,
                   u2_noun* b,
                   u2_noun* c,
                   u2_noun* d,
                   u2_noun* e);

      /* u2_cr_p():
      **
      **   & [0] if [a] is of the form [b *c].
      */
        u2_flag
        u2_cr_p(u2_noun  a,
                u2_noun  b,
                u2_noun* c);

      /* u2_cr_pq():
      **
      **   & [0] if [a] is of the form [b *c d].
      */
        u2_flag
        u2_cr_pq(u2_noun  a,
                 u2_noun  b,
                 u2_noun* c,
                 u2_noun* d);

      /* u2_cr_pqr():
      **
      **   & [0] if [a] is of the form [b *c *d *e].
      */
        u2_flag
        u2_cr_pqr(u2_noun  a,
                  u2_noun  b,
                  u2_noun* c,
                  u2_noun* d,
                  u2_noun* e);

      /* u2_cr_pqrs():
      **
      **   & [0] if [a] is of the form [b *c *d *e *f].
      */
        u2_flag
        u2_cr_pqrs(u2_noun  a,
                   u2_noun  b,
                   u2_noun* c,
                   u2_noun* d,
                   u2_noun* e,
                   u2_noun* f);

      /* u2_cr_met(): 
      **
      **   Return the size of (b) in bits, rounded up to
      **   (1 << a_y). 
      **
      **   For example, (a_y == 3) returns the size in bytes.
      */
        c3_w
        u2_cr_met(c3_y    a_y,
                  u2_atom b);

      /* u2_cr_bit():
      **
      **   Return bit (a_w) of (b).
      */
        c3_b
        u2_cr_bit(c3_w    a_w,
                  u2_atom b);
     
      /* u2_cr_byte():
      **
      **   Return byte (a_w) of (b).
      */
        c3_y
        u2_cr_byte(c3_w    a_w,
                   u2_atom b);
                
      /* u2_cr_bytes():
      **
      **   Copy bytes (a_w) through (a_w + b_w - 1) from (d) to (c).
      */
        void
        u2_cr_bytes(c3_w    a_w,
                    c3_w    b_w,
                    c3_y*   c_y,
                    u2_atom d);

      /* u2_cr_chop():
      **
      **   Into the bloq space of `met`, from position `fum` for a
      **   span of `wid`, to position `tou`, XOR from atom `src`
      **   into ray `dst`.
      */
        void
        u2_cr_chop(c3_g    met_g,
                   c3_w    fum_w,
                   c3_w    wid_w,
                   c3_w    tou_w,
                   u2_ray  dst_r,
                   u2_atom src);

      /* u2_cr_mp():
      **
      **   Copy (b) into (a_mp).
      */
        void
        u2_cr_mp(mpz_t   a_mp,
                 u2_atom b);

      /* u2_cr_word():
      **
      **   Return word (a_w) of (b).
      */
        c3_w
        u2_cr_word(c3_w    a_w,
                   u2_atom b);

      /* u2_cr_words():
      **
      **  Copy words (a_w) through (a_w + b_w - 1) from (d) to (c).
      */
        void
        u2_cr_words(c3_w    a_w,
                    c3_w    b_w,
                    c3_w*   c_w,
                    u2_atom d);


  /** u2_c?: managing noun reference counts.
  **/
#if 1
#     define u2_ct(som) u2_rx(som)
#     define u2_cz(som) u2_rz(som)
#     define u2_co(som) u2_rl_senior(u2_Wire)
#     define u2_cy(som) u2_rl_junior(u2_Wire)
#else
    /* u2_cz(): release noun.  Return `som` for convenience.
    */
      u2_noun
      u2_cz(u2_noun som);

    /* u2_ct(): acquire noun.  Return `som` for convenience.
    */
      u2_noun
      u2_ct(u2_noun som);

#endif
    /* u2_cu(): yes iff `som` is mutable where transferred (refcount 1).
    */
      u2_flag
      u2_cu(u2_noun som);

    /* u2_co(): yes iff `som` is senior (need not be counted)
    */
      u2_flag
      u2_co(u2_noun som);

    /* u2_cy(): yes iff `som` is junior (must not be referenced)
    */
      u2_flag
      u2_cy(u2_noun som);


  /** u2_ci*, u2_cf*: importing and constructing nouns.
  ***
  ***    Unless otherwise noted, u2_ci/f callers *transfer* ownership of
  ***    all argument nouns, and *retain* ownership of argument pointers.
  ***    Callers *produce* a new result which the caller must release.
  **/
    /* u2_ci_bytes():
    **
    **   Construct `a` bytes from `b`, LSB first, as an atom.
    */
      u2_atom
      u2_ci_bytes(c3_w        a_w,
                  const c3_y* b_y);

    /* u2_ci_string():
    **
    **   u2_ci_bytes(strlen(a_c), (c3_y *)a_c);
    */
      u2_atom
      u2_ci_string(const c3_c* a_c);

    /* u2_ci_duck():
    **
    **   Create an atomic string from a list of bytes.
    */
      u2_noun 
      u2_ci_duck(u2_noun a);

    /* u2_ci_decimal():
    **
    **   Parse `a` as a list of decimal digits.
    */
      u2_atom
      u2_ci_decimal(u2_wire wir_r,
                    u2_noun a);

    /* u2_ci_heximal():
    **
    **   On (wir_r), write (lit), a list of digits, as a hexadecimal.
    */
      u2_noun
      u2_ci_heximal(u2_noun a);

    /* u2_ci_list():
    **
    **   Generate a null-terminated list, with `u2_none` as terminator.
    */
      u2_noun
      u2_ci_list(u2_weak one, ...);


  /** u2_cf*: import and export to general unix filesystem.
  ***
  ***   All paths are flat LSB-first strings including extension.
  ***   File modes:
  ***
  ***         c3__atom  LSB-first atom
  ***         c3__file  [length atom] pair
  ***         c3__line  list of list of chars'
  ***
  ***   Directory modes:
  ***
  **/
    /* u2_cf_save_file(): 
    */
      u2_weak
      u2_cf_save(u2_noun pat, 
    

  /** u2_cp*: import and export within logical computer.
  ***
  ***   All paths are pairs [ext road] where road is outside-in term list.
  ***
  ***   Unless otherwise noted, u2_cf callers *transfer* ownership of
  ***   all argument nouns, and *retain* ownership of argument pointers.
  ***   Callers *produce* a new result which the caller must release.
  **/
    /* u2_cf_read_global(
     
  /** u2_cn_*: natural constructors
  **/
    /* u2_cn_inc(): increment an atom.
    */
      u2_atom
      u2_cn_inc(u2_atom a);

    /* u2_cn_dec(): decrement an atom.
    */
      u2_atom
      u2_cn_dec(u2_atom a);

    /* u2_cn_cell(): produce the cell `[a b]`.
    */
      u2_noun
      u2_cn_cell(u2_noun a,
                 u2_noun b);

    /* u2_cn_trel():
    */
      u2_noun
      u2_cn_trel(u2_noun a,
                 u2_noun b,
                 u2_noun c);

  /** u2_cs_*: general-purpose internal hash tables 
  **/


  /** u2_cg_*: garbage collection (exception cleanup only)
  **/
    

  /** u2_cc_*: memoization / caching
  **/
    /* u2_cc_find():
    **
    **   Cache search for function (0 means nock) and sample.
    */
      u2_weak                                      
      u2_cc_find(u2_mote fun_m,
                 u2_noun sam);                     

    /* u2_cc_save():
    **
    **   Cache store for function (0 means nock), sample and product.
    */
      u2_weak                                      
      u2_cc_save(u2_mote fun_m,                    
                 u2_noun sam,                      
                 u2_noun pro);                     

    /* u2_cc_uniq():
    **
    **   Use cache to render `som` unique.
    */
      u2_noun
      u2_cc_uniq(u2_noun som);

    /* u2_cc_find_cell(): as u2_cc_find(), for `sam=[a b]`.
    ** u2_cc_find_trel(): as u2_cc_find(), for `sam=[a b c]`.
    ** u2_cc_find_qual(): as u2_cc_find(), for `sam=[a b d]`.
    */
      u2_weak
      u2_cc_find_cell(u2_mote, u2_noun, u2_noun);

      u2_weak                                            
      u2_cc_find_trel(u2_mote, u2_noun, u2_noun, u2_noun);   

      u2_weak                                      
      u2_cc_find_qual(u2_mote, u2_noun, u2_noun, u2_noun, u2_noun);   

    /* u2_cc_save_cell(): as u2_cc_save(), for `sam=[a b]`.
    ** u2_cc_save_trel(): as u2_cc_save(), for `sam=[a b c]`.
    ** u2_cc_save_qual(): as u2_cc_save(), for `sam=[a b c d]`.
    */
      u2_weak                                      
      u2_cc_save_cell(u2_mote, u2_noun, u2_noun, u2_noun);   

      u2_weak                                      
      u2_cc_save_trel(u2_mote, u2_noun, u2_noun, u2_noun, u2_noun);   

      u2_weak                                      
      u2_cc_save_qual(u2_ray, u2_mote, u2_noun,     
                                       u2_noun,    
                                       u2_noun,    
                                       u2_noun,    
                                       u2_noun);   

  /** u2_cw: exporting, saving or publishing nouns.
  **/

  /** u2_cm: meta, miscellaneous, management and magic.
  **/
    /* u2_cm_boot(): try to boot the system and set one wire (single thread).
    **
    **   Return u2_no on failure.
    */
      u2_flag
      u2_cm_boot(void);

    /* u2_cm_open(): enter new opaque bail context, returning old (or 0).
    **
    **   usage:  
    **        c3_w qop_r = u2_cm_open();
    **  
    **        if ( 0 != u2_cm_trap(wir_r) ) {
    **          u2_cm_done();
    **          [... exception ...]
    **        }
    **        else {
    **          [... code as normal ...]
    **          u2_cm_done();
    **        }
    */
      c3_w
      u2_cm_open();

    /* u2_cm_trap(): trap for exceptions.
    */
#     if 0
        c3_m
        u2_cm_trap();
#     else
#       define u2_cm_trap() \
          ( (c3_l) \
            _setjmp((void *) \
                     u2_at_cord(u2_kite_buf_r(u2_wire_kit_r(u2_Wire)), \
                                c3_wiseof(jmp_buf))) \
          )
#     endif
   
    /* u2_cm_done(): terminate and restore old opaque bail context.
    */
      void
      u2_cm_done(c3_w qop_w);


    /* u2_cm_leap(): descend into a memory region.
    **
    **   Memory allocated in the heap above is senior & frozen.
    */
      void
      u2_cm_leap();

    /* u2_cm_fall(): ascend out of a memory region.
    **
    **   Memory allocated in the heap below is junior & volatile.
    */
      void
      u2_cm_fall();

    /* u2_cm_keep(): copy volatile noun `som` to fresh heap.
    */
      u2_noun
      u2_cm_keep(u2_noun som);

    /* u2_cm_bury(): store fresh or volatile noun `som` to freezer.
    */
      u2_noun
      u2_cm_bury(u2_noun som);

    /* u2_cm_pack(): elide all volatile memory.
    */
      void
      u2_cm_pack();

    /* u2_cm_prof(): begin profiling.
    */
      void
      u2_cm_prof();

    /* u2_cm_frop(): extract, clear and disable profiler.
    */
      u2_noun
      u2_cm_frop();

    /* u2_cm_trac(): extract and clear stack trace.
    */
      u2_noun
      u2_cm_trac();

    /* u2_cm_slab():
    **
    **   Create a blank atomic slab of `len` words.
    */
      u2_ray
      u2_cm_slab(c3_w len_w);

    /* u2_cm_slaq():
    **
    **   Create a blank atomic slab of `len` bloqs of size `met`.
    */
      u2_ray
      u2_cm_slaq(c3_g met_g,
                 c3_w len_w);

    /* u2_cm_malloc():
    **
    **   Allocate `sib_w` *bytes* of raw C storage.
    */
      void*
      u2_cm_malloc(u2_ray ral_r,
                   c3_w   sib_w);

    /* u2_cm_malt():
    **
    **   Initialize slab `sal` as an atom, self-measured.
    */
      u2_atom
      u2_cm_malt(u2_ray sal_r);

    /* u2_cm_mint():
    **
    **   Initialize slab `sal` as an atom, auto-measured.
    */
      u2_atom
      u2_cm_mint(u2_ray  sal_r,
                 c3_w    len_w);

    /* u2_cm_moot():
    **
    **   Initialize slab `sal` as an atom, originally measured.
    */
      u2_atom
      u2_cm_moot(u2_ray  sal_r);

    /* u2_cm_open():
    **
    **   Yes iff [a] more words remain in the pad.
    */
      u2_flag
      u2_cm_open(c3_w a_w);

    /* u2_cm_ralloc():
    **
    **   Allocate `siz_w` words of raw ray storage.
    */
      u2_ray
      u2_cm_ralloc(c3_w siz_w);

    /* u2_cm_rfree():
    **
    **   Free raw ray storage allocated by `u2_cm_ralloc()`.
    */
      void
      u2_cm_rfree(u2_ray nov_r);

  /* u2_ck: kernel and related functions
  */
    /* u2_cka: tier 1 functions
    */
  
