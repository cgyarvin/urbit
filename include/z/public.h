/* include/z/public.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   uz   (uz external)
**
** Description:
**
**   External C library interface.
*/
  /** Text integers.
  **/
#     define uz_s1(a)          ( (a) )
#     define uz_s2(a, b)       ( ((b) << 8) | uz_s1(a) )
#     define uz_s3(a, b, c)    ( ((c) << 16) | uz_s2(a, b) )
#     define uz_s4(a, b, c, d) ( ((d) << 24) | uz_s3(a, b, c) )

#     define uz_s5(a, b, c, d, e) \
        ( ((uint64_t)uz_s1(e) << 32ULL) | uz_s4(a, b, c, d) )
#     define uz_s6(a, b, c, d, e, f) \
        ( ((uint64_t)uz_s2(e, f) << 32ULL) | uz_s4(a, b, c, d) )
#     define uz_s7(a, b, c, d, e, f, g) \
        ( ((uint64_t)uz_s3(e, f, g) << 32ULL) | uz_s4(a, b, c, d) )
#     define uz_s8(a, b, c, d, e, f, g, h) \
        ( ((uint64_t)uz_s4(e, f, g, h) << 32ULL) | uz_s4(a, b, c, d) )


  /** Performance statistics.
  **/
    struct uz_bench {
      uint8_t  heb;   /* heb: 1 iff benchmarking is on */
      uint64_t pex;   /* pex: interpreter steps */
      uint32_t gup;   /* gup: words of memory used */
      uint32_t piq;   /* piq: jet invocations */
      uint32_t vel;   /* vel: words of memory copied */
    };


  /** Data types.
  **/
    /* uz_noun: 
    **
    **  A 32-bit noun.  May be the sentinel value uz_none.
    **
    **  Any 31-bit unsigned integer is guaranteed to equal its own noun.
    */
      typedef uint32_t uz_noun;
#     define uz_none 0x80000000

    /* uz_machine: 
    **
    **  The zeno machine, with state.
    */
      typedef struct {
        /* Core zeno machine - to be unified.  Once this is done,
        ** mac->zen becomes just mac.
        */
          void              *zen;

        /* Jump buffer for exceptions.
        */
          jmp_buf           env;

        /* Benchmark data.
        */
          struct uz_bench   ben;

        /* Live (type subject) pair.
        */
          uz_noun           har;
      } *uz_machine;

    /* An opaque 32-bit watermark.  Used in memory management.
    */
      typedef uint32_t uz_shoe;
 

  /** Functions.
  **/
    /** Initiation and lifecycle.
    ***
    ***   uz_l functions may not be called within jets!
    **/
      /* uz_l_boot():
      **
      **   Create a zeno machine, mallocing (1 << siz) 32-bit words.
      **   Set state to the boot kernel.
      **
      **   Return 0 if malloc fails.
      */
        uz_machine
        uz_l_boot(uint8_t siz);

      /* uz_l_free():
      **
      **   Free a zeno machine.
      */
        void
        uz_l_free(uz_machine mac);

      /* uz_l_except():
      **
      **   Set an exception target.  Called with uz_s4('t','a','n','k')
      **   or uz_s4('e','x','i','t').  (env) must be live while engine runs!
      */
        void
        uz_l_except(uz_machine mac,
                    jmp_buf    env);

    /** Exceptions.
    **/
      /* uz_x_exit(): 
      **
      **   Report formal failure (undefined computation).
      */
        uz_noun
        uz_x_exit(uz_machine mac);

      /* uz_x_tank():
      **
      **   Report informal failure (uncalculated computation).
      */
        uz_noun
        uz_x_tank(uz_machine mac);
      
      /* uz_x_trip():
      **
      **   Report informal failure (internal error).
      */
        uz_noun
        uz_x_trip(uz_machine mac);

      /* uz_x_stub():
      **
      **   Return informal failure (unimplemented stub).
      */
        uz_noun
        uz_x_stub(uz_machine mac);

    /** Noun construction.
    **/
      /* uz_k_nock():
      **
      **   Execute nock directly.
      **
      **    sub: subject
      **    fol: formula
      */
        uz_noun
        uz_k_nock(uz_machine mac,
                  uz_noun    sub,
                  uz_noun    fol);

      /* uz_k_cell(), uz_k_trel(), uz_k_qual(), uz_k_quil():
      **
      **   Create a tuple.
      */
        uz_noun
        uz_k_cell(uz_machine mac,
                  uz_noun    a,
                  uz_noun    b);
        uz_noun
        uz_k_trel(uz_machine mac,
                  uz_noun    a,
                  uz_noun    b,
                  uz_noun    c);
        uz_noun
        uz_k_qual(uz_machine mac,
                  uz_noun    a,
                  uz_noun    b,
                  uz_noun    c,
                  uz_noun    d);
        uz_noun
        uz_k_quil(uz_machine mac,
                  uz_noun    a,
                  uz_noun    b,
                  uz_noun    c,
                  uz_noun    d,
                  uz_noun    e);

      /* uz_k_string():
      **
      **   Create a string atom.
      */
        uz_noun
        uz_k_string(uz_machine mac,
                    const char *str);
     
      /* uz_words():
      **
      **   Create a word atom, LSW first.
      */
        uz_noun
        uz_k_words(uz_machine mac,
                   uint32_t   len,
                   uint32_t   *mem);

      /* uz_k_bytes():
      **
      **   Create a byte atom, LSB first.
      */
        uz_noun
        uz_k_bytes(uz_machine mac,
                   uint32_t   len,
                   uint8_t    *mem);

      /* uz_k_file():
      **
      **  Load the Unix file [unx] as an atom.
      */
        uz_noun
        uz_k_file(uz_machine mac,
                  uz_noun    unx);


    /** Reading nouns.
    ***
    *** All read functions assert() if used inappropriately.
    **/
      /** Generic reading.
      **/
        /* uz_n_tap():
        **
        **   True (1) iff [a] is a cell.
        */
          uint8_t
          uz_n_tap(uz_machine mac,
                   uz_noun    a);

        /* uz_n_eq():
        **
        **   True (1) iff [a] and [b] are the same noun.
        */
          uint8_t
          uz_n_eq(uz_machine mac,
                  uz_noun    a,
                  uz_noun    b);

        /* uz_n_mug():
        **
        **   Return the 31-bit cached insecure hash of [a].
        */
          uint32_t
          uz_n_mug(uz_machine mac,
                   uz_noun    a);


      /** Reading cells.
      **/
        /* uz_c_head, uz_c_tail(): 
        **
        **  Extract head and tail.
        */
          uz_noun
          uz_c_head(uz_machine mac,
                    uz_noun    a);
          uz_noun
          uz_c_tail(uz_machine mac,
                    uz_noun    a);

#         define uz_ch(mac, a) uz_c_head(mac, a)
#         define uz_ct(mac, a) uz_c_tail(mac, a)

        /* uz_c_cell():
        **
        **   True (1) iff [a] is a cell [*b *c].
        */
          uint8_t
          uz_c_cell(uz_machine mac,
                    uz_noun    a,
                    uz_noun    *b,
                    uz_noun    *c);

        /* uz_c_trel():
        **
        **   True (1) iff [a] is a triple [*b *c *d].
        */
          uint8_t
          uz_c_trel(uz_machine mac,
                    uz_noun    a,
                    uz_noun    *b,
                    uz_noun    *c,
                    uz_noun    *d);

        /* uz_c_qual():
        **
        **   True (1) iff [a] is a quadruple [*b *c *d *e].
        */
          uint8_t
          uz_c_qual(uz_machine mac,
                    uz_noun    a,
                    uz_noun    *b,
                    uz_noun    *c,
                    uz_noun    *d,
                    uz_noun    *e);

        /* uz_c_quil():
        **
        **   True (1) iff [a] is a quintuple [*b *c *d *e *f].
        */
          uint8_t
          uz_c_quil(uz_machine mac,
                    uz_noun    a,
                    uz_noun    *b,
                    uz_noun    *c,
                    uz_noun    *d,
                    uz_noun    *e,
                    uz_noun    *f);

        /* uz_c_p():
        **
        **   True (1) iff [a] is of the form [b *c].
        */
          uint8_t
          uz_c_p(uz_machine mac,
                 uz_noun    a,
                 uz_noun    b,
                 uz_noun    *c);

        /* uz_c_pq():
        **
        **   True (1) iff [a] is of the form [b *c *d].
        */
          uint8_t
          uz_c_pq(uz_machine mac,
                  uz_noun    a,
                  uz_noun    b,
                  uz_noun    *c,
                  uz_noun    *d);

        /* uz_c_pqr():
        **
        **   True (1) iff [a] is of the form [b *c *d *e].
        */
          uint8_t
          uz_c_pqr(uz_machine mac,
                   uz_noun    a,
                   uz_noun    b,
                   uz_noun    *c,
                   uz_noun    *d,
                   uz_noun    *e);


      /** Reading atoms.
      **/
        /* uz_a_bin(): 
        **
        **   Return the size of [b] in bits, rounded up to
        **   (1 << a). 
        **
        **   For example, (a == 3) returns the size in bytes.
        */
          uint32_t
          uz_a_bin(uz_machine mac,
                   uint8_t    a,
                   uz_noun    b);

        /* uz_a_bit():
        **
        **   Return bit (w_a) of [b].
        */
          uint8_t
          uz_a_bit(uz_machine mac,
                   uint32_t   a,
                   uz_noun    b);
         
        /* uz_a_byte():
        **
        **   Return byte (w_a) of [b].
        */
          uint8_t
          uz_a_byte(uz_machine mac,
                    uint32_t   a,
                    uz_noun    b);
                    
        /* uz_a_bytes():
        **
        **  Copy bytes (w_a) through (w_a + w_b - 1) from (d) to (c).
        */
          void
          uz_a_bytes(uz_machine mac,
                     uint32_t   a,
                     uint32_t   b,
                     uint8_t    *c,
                     uz_noun    d);

        /* uz_a_eq_c():
        **
        **   Yes iff [b] is the same noun as the C string c_a.
        */
          uint8_t
          uz_a_eq_c(uz_machine  mac,
                    uint8_t     *a,
                    uz_noun     b);
#if 0
        /* uz_a_mp():
        **
        **   Copy [b] into (a).
        */
          void
          uz_a_mp(uz_machine mac,
                  mpz_t      a,
                  uz_noun    b);
#endif
        /* uz_a_word():
        **
        **   Return word (w_a) of [b].
        */
          uint32_t
          uz_a_word(uz_machine mac,
                    uint32_t   a,
                    uz_noun    b);

        /* uz_a_words():
        **
        **  Copy words (w_a) through (w_a + w_b - 1) from (d) to (c).
        */
          void
          uz_a_words(uz_machine mac,
                     uint32_t   a,
                     uint32_t   b,
                     uint32_t   *c,
                     uz_noun    d);
        
        /* uz_a_file():
        **
        **  Copy [dat] into the Unix file [unx].
        */
          void
          uz_a_file(uz_machine mac,
                    uz_noun    unx,
                    uz_noun    dat);


    /** Typed computation.
    ***
    ***   Functions labeled _g_ generate a clam - [type noun].
    ***   Functions labeled _r_ replace the subject with the clam.
    ***   Functions labeled _p_ post the clam on the subject.
    **/
      /* uz_g_lame():
      **
      **   Compute in a lame way that might work today.  Delete.
      */
        uz_noun
        uz_g_lame(uz_machine mac,
                  uz_noun    fig,
                  uz_noun    gen);
        
      /* uz_g_compute(), uz_r_compute(), uz_p_compute():
      **
      **   Compute a function of an external argument.
      **
      **    gen: gene (producing function)
      **    han: name
      **    fig: clam
      */
        uz_noun
        uz_g_compute(uz_machine mac, 
                     uz_noun    gen,
                     uz_noun    fig);
        void
        uz_r_compute(uz_machine mac, 
                     uz_noun    gen,
                     uz_noun    fig);
        void
        uz_p_compute(uz_machine mac, 
                     uz_noun    han,
                     uz_noun    gen,
                     uz_noun    fig);
 
      /* uz_g_express(), uz_r_express(), uz_p_express():
      **
      **   Express a gene against the subject.
      **
      **    gen: gene
      **    han: name
      */
        uz_noun
        uz_g_express(uz_machine mac,
                     uz_noun    gen);
        uz_noun
        uz_r_express(uz_machine mac,
                     uz_noun    gen);
        uz_noun
        uz_p_express(uz_machine mac,
                     uz_noun    gen);

      /* uz_p_constant():
      **
      **   Post a typed constant.
      **
      **    han: name
      **    fig: clam
      */
        void
        uz_p_constant(uz_machine mac,
                      uz_noun    han,
                      uz_noun    fig);


    /** Built-in functions, typically kernel implemented.
    **/
      /* uz_t_mill(): 
      **
      **   Compile [type gene] to [type form].
      */
        uz_noun
        uz_t_mill(uz_machine mac,
                  uz_noun    tip,
                  uz_noun    gen);

      /* uz_t_make(): 
      **
      **   Compile [type gene] to [form].
      */
        uz_noun
        uz_t_make(uz_machine mac,
                  uz_noun    tip,
                  uz_noun    gen);

      /* uz_t_watt():
      **
      **   Compile source text to watt gene.
      **
      **    src: source text, as atom
      */
        uz_noun
        uz_t_watt(uz_machine mac,
                  uz_noun    src);
                
      /* uz_t_vere():
      **
      **   Compile source text to vere command.
      **
      **    src: source text, as atom
      */
        uz_noun
        uz_t_vere(uz_machine mac,
                  uz_noun    src);

      /* uz_t_hume():
      **
      **   Compile source text to untyped noun.
      **
      **    src: source text, as atom
      */
        uz_noun
        uz_t_hume(uz_machine mac,
                  uz_noun    src);


    /** Memory management - for advanced users only.
    **/
      /* uz_m_depart():
      **
      **   Depart, returning a shoe.
      */
        uz_shoe
        uz_m_depart(uz_machine mac);

      /* uz_m_retreat():
      **
      **   Retreat to saved shoe.
      */
        void
        uz_m_retreat(uz_machine mac,
                     uz_shoe    sho);

      /* uz_m_zap():
      **
      **   Discard all departed storage.
      */
        void
        uz_m_zap(uz_machine mac);


    /** Side effects.
    **/
      /* uz_f_print():
      **
      **   Print [noun], with [caption] if nonzero as a caption.
      */
        void
        uz_f_print(uz_machine mac,
                   const char *cap,
                   uz_noun    non);
