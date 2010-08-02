/* include/l.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   u3_l   (loom)
**   u3_li  (loom internal)
**   u3_ln  (loom generate)
**   u3_lr  (loom read)
**   u3_lm  (loom management)
**
** Description:
**
**   The loom system, a linear noun allocator.
**
**   A "noun" is either an "atom" (an unsigned integer of any size),
**   or a "cell" (an ordered pair of any two nouns).
*/

  /** Remarks:
  **/
    /* A "loom" is a linear allocator without fragmentation.
    **
    ** You may know the typical Unix process layout, in which heap
    ** grows upward from low memory, and stack grows downward
    ** from high memory.  The general advantage of this layout
    ** is zero fragmentation: heap and stack can grow as far 
    ** toward each other as possible, until they meet.
    ** 
    ** This design is independent of the actual structures that grow
    ** from both ends of a linear address space.  We might just as
    ** well have two heaps growing toward each other, or two stacks.
    **
    ** The loom allocator is the latter - two stacks, growing toward 
    ** each other.  A stack is actually a more powerful structure 
    ** than a heap; if you have a stack and you want a heap, you can
    ** always push one on top of the stack.  If you have a heap
    ** and you want a (contiguous) stack, you are SOL.
    **
    ** We call these flat stacks "beams."  A loom is two symmetric
    ** beams, one growing up from the bottom of memory, the other
    ** growing down from the top. The obvious constraint is that
    ** the beams must never cross.  The unused area between them
    ** may be of any length and at any position.
    **
    ** (Again, a loom imposes no external fragmentation - it can use
    ** its complete allocated segment.  Of course, loom programmers
    ** can still leak internally within the beams.)
    **
    ** All loom addresses are word (32-bit) addresses.  The loom
    ** pointer format can address 2^28 words, or 1GB, which is 
    ** adequate for most light-duty programming tasks.  A "dot"
    ** is a 28-bit word offset in the loom.
    **
    ** A "ray" is a 29-bit word offset onto a beam.  If bit 29
    ** is 0, the ray grows forward from 0 and is "west."  If bit
    ** 29 is 1, the ray grows backward from the end of the loom,
    ** and is "east."
    **
    ** All u3 nouns are represented by the 32-bit word type "rat."
    ** If bit 31 of a rat is 0, it is a "cat" - a direct atom.
    ** Bits 0-30 are an unsigned 31-bit integer.
    **
    ** If bit 31 of a rat is 1, bits 0-28 are a ray which points
    ** to an indirect noun.  If bit 30 is 0, the indirect noun is
    ** a "dog" - an indirect cell.  If bit 30 is 1, the noun is a
    ** "pig" - an indirect atom.  (Bit 29 is reserved.)
    **
    ** A loom contains four pointers: "bat," "hat," "cap" and "mat."
    **
    ** "bat," a dot, points to the first word in the east beam.
    **
    ** "hat" and "cap", rays, are the tops of two opposing stack
    ** allocators, rays on opposite beams.  Either the hat is east
    ** and the cap is west, or vice versa.
    **
    ** "mat" is a ray on the same beam as the cap, at or below it.
    ** 
    ** The loom is thus divided, like Gaul, into three parts:
    **
    ** west                                                  east
    ** ----------------------------------------------------------
    ** ||...............>          <*******<....................|
    ** ||->... box .....>    pad   <* can *<...... box .......<-|
    ** ||...............>          <*******<....................|
    ** ----------------------------------------------------------
    ** |                |          |       |                    | 
    ** 0               hat        cap     mat                  bat
    **
    ** The "pad" is unused memory.  The "box" is stable memory.
    ** The "can" is temporary memory.
    **
    ** What does all this mean?  Hat, cap and mat are the pointers
    ** in a three-pointer noun allocation system, the "box allocator."
    **
    ** The box allocator imposes a seniority restriction on all
    ** pointers.  A reference stored in the can may point into
    ** the box, but a reference stored in the box cannot point
    ** into the can.
    **
    ** Therefore, the can may be entirely destroyed without any
    ** corruption of the box.  In general, the can is used for
    ** temporary allocation.  Temporary structures are constructed
    ** on the can, then either copied into the box or discarded.
    ** 
    ** In the boxer system, the burden of distinguishing between
    ** data that is to be kept, and that which is to be thrown
    ** away, is pushed up to the programmer.  And while not all 
    ** programmers are equal to all burdens, failure in this one
    ** can at worst result in atrocious performance.
    **
    ** Simply put: temporary structures cannot point to
    ** stable ones.  Thus, we can clear the can without
    ** invalidating any pointers in the box.  And thus, any
    ** calculation can discard all its temporary results,
    ** thus obviating classical garbage collection.
    **
    ** Sadly, the calculations that produce temporary data have
    ** a nasty tendency to require temporary storage of their own.
    ** We do not want this to accumulate recursively - we would
    ** like to recycle all temporary memory as soon as it is no
    ** longer needed.
    **
    ** The boxer system performs this by reversing the stacks:
    **
    **                 old        old     old
    ** 0               hat        cap     mat                  bat
    ** |                |          |       |                    | 
    ** ----------------------------------------------------------
    ** ||...............>???>   <!!*******......................|
    ** ||->.............>???>   <!!*******....................<-|
    ** ||...............>???>   <!!*******......................|
    ** ----------------------------------------------------------
    ** |                |   |   |                               | 
    ** 0               mat cap hat                             bat
    **                 tmp tmp tmp
    **
    ** Stable storage is "."; old first-order temporary storage
    ** is '*'; new first-order is "!"; second-order is "?".
    **
    ** This transition (which must save the old mat) is a "flap."
    ** After the reverse transition, a "flop," we see:
    **
    **                 old        old     old
    ** 0               hat        cap     mat                  bat
    ** |                |          |       |                    | 
    ** ----------------------------------------------------------
    ** ||...............>       <!!********<....................|
    ** ||->.............>       <!!********<..................<-|
    ** ||...............>       <!!********<....................|
    ** ----------------------------------------------------------
    ** |                |       |          |                    | 
    ** 0               hat     cap        mat                  bat
    **                 new     new        new
    **
    ** Of course, if you build a temporary structure on the can and
    ** want to save it to the box, copying has to happen.  Note that
    ** this facility can be used as a stop-and-copy GC.
    */
 

  /** Data types.
  **/
    /** Bitfields.
    ***
    ***     u3_l_dot - word offset in loom
    ***       &&&&:28a
    ***         a: offset from loom
    ***
    ***     u3_l_ray - word offset on beam
    ***       &&&:1a:28b
    ***         a: beam (& = low = west, | = high = east)
    ***         b: offset on beam
    ***
    ***     u3_l_rat - noun
    ***       ?(cat, hog)
    ***       1a:31b
    ***         a: cat if 0, hog if 1
    ***
    ***     u3_l_hog - indirect atom or cell
    ***       ?(dog, pig)
    ***       |:29a:1b:1c
    ***         a: ray to data
    ***         b: reserved for extension bit
    ***
    ***     u3_l_cat - direct atom
    ***       &:31a
    ***         a: unsigned integer
    ***
    ***     u3_l_dog - indirect cell
    ***       |:29a:1b:&
    ***         a: ray to struct u3_li_cell
    ***         b: reserved for extension bit
    ***
    ***     u3_l_pig - indirect atom
    ***       |:29a:1b:|
    ***         a: ray to struct u3_li_atom
    ***         b: reserved for extension bit
    **/
      typedef c3_w u3_l_dot;
      typedef c3_w u3_l_ray;
      typedef c3_w u3_l_rat;
      typedef c3_w u3_l_hog;
      typedef c3_w u3_l_cat;
      typedef c3_w u3_l_pig;


    /** Structures.
    ***
    ***   u3_l_core - the loom
    ***   u3_li_cell - cell structure (in beam space - do not use)
    ***   u3_li_atom - atom structure (in beam space - do not use)
    **/
      /* l_core: the loom itself.
      */
        struct u3_l_core {
          /* bat: east end of the loom.
          */
          u3_l_dot dot_bat;

          /* cap, hat, mat: allocation pointers.
          */
          u3_l_ray ray_cap;
          u3_l_ray ray_hat;
          u3_l_ray ray_mat;
          
          /* cop: count of words copied.
          */
          c3_w     w_cop;
        };
        typedef struct u3_l_core *u3_l;
        typedef void *u3_lv;

      /* li_atom, li_cell: imaginary structures (in beam space).
      */
        struct u3_li_atom {
          c3_w w_mug;
          c3_w w_len;
          c3_w w_buf[0];
        };

        struct u3_li_cell {
          c3_w     w_mug;
          u3_l_ray ray_hed;
          u3_l_ray ray_tel;
        };
   

  /** Bas-macros.
  **/
    /** Bitfield unpacking.  See above.
    **/
#     define u3_li_ray_a(ray)     ( (ray) >> 28 )
#     define u3_li_ray_b(ray)     ( (ray) & ((1 << 28) - 1) )

#     define u3_li_rat_a(rat)     ( (rat) >> 31 )

#     define u3_li_hog_a(hog)     ( ((hog) &~ (1 << 31)) >> 2 )
#     define u3_li_hog_b(hog)     ( 1 & ((hog) >> 1) )
#     define u3_li_hog_c(hog)     ( 1 & (hog) )

#     define u3_li_dog_a(dog)     u3_li_hog_a(dog)
#     define u3_li_dog_b(dog)     u3_li_hog_b(dog)
#     define u3_li_pig_a(pig)     u3_li_hog_a(pig)
#     define u3_li_pig_b(pig)     u3_li_hog_b(pig)

#     define u3_li_rat_is_cat(rat) ( !u3_li_rat_a(rat) )
#     define u3_li_rat_is_hog(rat) ( u3_li_rat_a(rat) )

#     define u3_li_hog_is_dog(hog) ( !u3_li_hog_c(hog) )
#     define u3_li_hog_is_pig(hog) ( u3_li_hog_c(hog) )

#     define u3_li_rat_is_atom(a) \
        (u3_li_rat_is_cat(a) || u3_li_hog_is_pig(a))
       

    /** Bitfield packing.  See above.
    **/
#     define u3_li_ray_of(a, b)   ( ((a) << 28) | (b) )

#     define u3_li_hog_of(a, b, c) \
        ( (1 << 31) | ((a) << 2) | ((b) << 1) | (c) )

#     define u3_li_dog_of(a, b)   u3_li_hog_of(a, b, 0)
#     define u3_li_pig_of(a, b)   u3_li_hog_of(a, b, 1)


    /** Cage reference and geometry.
    **/
#     define u3_li_ray_dot(l, ray) \
        ( u3_li_ray_a(ray) ? ((l)->dot_bat - u3_li_ray_b(ray)) : (ray) )

#     define u3_li_at_dot(l, dot)   ( ((c3_w *) (l)) + (dot) )
#     define u3_l_at_ray(l, ray)    u3_li_at_dot(l, u3_li_ray_dot(l, ray))

#     define u3_li_ray_beam(ray)   u3_li_ray_a(ray)
#     define u3_li_ray_point(ray)  u3_li_ray_b(ray)

#     define u3_li_hog_ray(hog)    u3_li_hog_a(hog)
#     define u3_li_hog_fort(hog)   u3_li_hog_b(hog)
#     define u3_li_hog_dust(hog)    u3_li_hog_c(hog)

#     define u3_li_hog_beam(hog)   u3_li_ray_beam(u3_li_hog_ray(hog))

#     define u3_li_overflow(l, a) \
        ( ( (a) + \
            u3_li_ray_b((l)->ray_hat) + \
            u3_li_ray_b((l)->ray_cap) \
          ) >= \
          (l)->dot_bat \
        )

    /*** Noun structure access.
    ***/
#     define u3_li_at_hog_mug(l, a)   u3_l_at_ray(l, u3_li_hog_a(a))

#     define u3_li_at_dog_hed(l, a)   u3_l_at_ray(l, (1 + u3_li_dog_a(a)))
#     define u3_li_at_dog_tel(l, a)   u3_l_at_ray(l, (2 + u3_li_dog_a(a)))

#     define u3_li_at_pig_len(l, a)   u3_l_at_ray(l, (1 + u3_li_pig_a(a)))
#     define u3_li_at_pig_buf(l, a, b) \
        u3_l_at_ray(l, (2 + (b) + u3_li_pig_a(a)))


  /** Constants.
  **/
    /* u3_l_none:
    **
    **   An exceptional value, comparable to NaN for floats.  Should
    **   propagate through all functions.
    */
#     define u3_l_none u3_li_hog_of(u3_li_ray_of(0, 0), 0, 0)

    /* u3_l_yes, u3_l_no:
    **
    **   Our Martian booleans.
    */
#     define u3_l_yes 0
#     define u3_l_no  1


  /** Typedefs.
  ***
  *** Noun typedefs may reflect usage, structure, or both.  Any noun
  *** typedef is a fox - that is, it may not be (u3_l_none).
  **/
    /* u3_l_fox:
    **
    **   A rat which is not u3_l_none.
    */
      typedef u3_l_rat u3_l_fox;

    /* u3_l_atom:
    **
    **   A fox which is an atom.
    */
      typedef u3_l_fox u3_l_atom;

    /* u3_l_cell:
    **
    **   A fox which is a cell.
    */
      typedef u3_l_fox u3_l_cell;

    /* u3_l_flag:
    **
    **   A Martian boolean (0 = yes, 1 = no).
    */
      typedef u3_l_fox u3_l_flag;

    /* u3_l_mote:
    **
    **   An ASCII string of 2-4 characters.
    */
      typedef u3_l_fox u3_l_mote;

    /* u3_l_list:
    **
    **   A zero-terminated, tailward list.
    */
      typedef u3_l_fox u3_l_list;


  /** Functions and hautes-macros.
  **/
    /** Lifecycle, management, and miscellaneous.
    **/
      /* u3_lm_new():
      **
      **   Create a loom, mallocing (1 << y_a) words of memory.  Return
      **   0 if malloc fails.
      **
      **   A loom can be freed with free() - there is no destructor.
      */
        u3_l
        u3_lm_new(c3_y y_a);

      /* u3_lm_alloc():
      **
      **   Allocate (w_a) words of C storage on the hat.
      */
        void *
        u3_lm_alloc(u3_lv lv,
                    c3_w  w_a);

      /* u3_lm_flap():
      **
      **   Reverse the beams forward, returning the old mat.
      */
        u3_l_ray
        u3_lm_flap(u3_lv lv);

      /* u3_lm_flop():
      **
      **   Reverse the beams backward, restoring the old mat.
      */
        void
        u3_lm_flop(u3_lv    lv,
                   u3_l_ray ray_mat);

      /* u3_lm_flog():
      **
      **   Release the can.
      */
        void
        u3_lm_flog(u3_lv lv);

      /* u3_lm_mug():
      **
      **   Compute and/or recall the mug (short hash) of (a).
      */
        c3_w
        u3_lm_mug(u3_lv    lv,
                  u3_l_fox a);

      /* u3_lm_order():
      **
      **   Produce u3_yes iff (a) is below (b) in mug order.
      **
      **   Assumes a and b are not equal.
      */
        u3_l_flag
        u3_lm_order(u3_lv   lv,
                    u3_l_fox a,
                    u3_l_fox b);

      /* u3_lm_nuke():
      **
      **   Zero all data between cap and hat.  For debugging.
      */
        void
        u3_lm_nuke(u3_lv lv);

      /* u3_lm_water():
      **
      **   Return west and east watermarks, respectively.
      */
        void
        u3_lm_water(u3_lv lv,
                    c3_w  *w_maz,
                    c3_w  *w_buc);

      /* u3_lm_open():
      **
      **   Yes iff [a] more words remain in the pad of [l].
      */
#if 0
        u3_flag
        u3_lm_open(u3_lv lv,
                   c3_w  w_a);
#else
#       define u3_lm_open(lv, w_a) \
          (u3_li_overflow((u3_l)(void *)(lv), w_a) ? u3_l_no : u3_l_yes)
#endif

      /* u3_lm_clear():
      **
      **   Yes iff [lef] does not point to any word >= [lid]
      **   and < [nut].
      */
        u3_l_flag
        u3_lm_clear(u3_lv    lv,
                    u3_l_fox lef,
                    u3_l_ray ray_lid,
                    u3_l_ray ray_nut);

      /* u3_lm_tamp():
      **
      **   Tamp, eliding the segment from [ray_lid] up to [ray_nut],
      **   preserving the root [lef].
      **
      **   Assumes u3_lm_clear() with the same arguments.
      */
        u3_l_fox
        u3_lm_tamp(u3_lv    lv,
                   u3_l_fox lef,
                   u3_l_ray ray_lid,
                   u3_l_ray ray_nut);

      /* u3_lm_water():
      **
      **   Return east and west watermarks, respectively.
      */
        void
        u3_lm_water(u3_lv lv,
                    c3_w  *w_maz,
                    c3_w  *w_buc);

    /** Generation.
    ***
    *** All generators return u3_l_none if out of memory.
    **/
      /* u3_ln_bytes():
      **
      **   Copy (w_a) bytes from (y_b) into an atom on the hat of (l).
      */
        u3_l_rat
        u3_ln_bytes(u3_lv      lv,
                    c3_w       w_a,
                    const c3_y *y_b);

      /* u3_ln_string():
      **
      **   u3_ln_bytes(l, strlen(c_a), (c3_y *)c_a);
      */
        u3_l_rat
        u3_ln_string(u3_lv      lv,
                     const c3_c *c_a);

      /* u3_ln_cell(): 
      **
      **   Produce the cell (a b) on the hat of (l), or u3_l_none if
      **   this would overflow the loom.
      */
        u3_l_rat
        u3_ln_cell(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_fox b);

      /* u3_ln_ice():
      **
      **   Produce a noun equivalent to (a), which does not reference
      **   any data on the can of (l).
      */
        u3_l_rat
        u3_ln_ice(u3_lv    lv,
                  u3_l_fox a);

      /* u3_ln_mp():
      **
      **   Copy the GMP integer (mp_a) into an atom on the hat of (l).
      */
        u3_l_rat
        u3_ln_mp(u3_lv lv,
                 mpz_t mp_a);

      /* u3_ln_nock():
      **
      **    Execute (nock lan sef) with a trivial interpreter.
      */
        u3_l_rat
        u3_ln_nock(u3_lv    lv,
                   u3_l_fox lan,
                   u3_l_fox sef);

      /* u3_ln_trel(): 
      **
      **   Produce the trel [a b c] on the hat of [l], or u3_l_none if
      **   this would overflow the loom.
      */
        u3_l_rat
        u3_ln_trel(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_fox b,
                   u3_l_fox c);

      /* u3_ln_weld():
      **
      **   Weld (b) into a single atom, gluing on (1 << y_a) lines.
      **   Eg, y_a = 3 to concatenate bytes, 0 for bits, 5 for words.
      */
        u3_l_rat
        u3_ln_weld(u3_lv    lv,
                   c3_y     y_a,
                   u3_l_fox b);
        
      /* u3_ln_words():
      **
      **   Copy (w_a) words from (w_b) into an atom on the hat of (l).
      */
        u3_l_rat
        u3_ln_words(u3_lv      lv,
                    c3_w       w_a,
                    const c3_w *w_b);
      

    /** Reading.
    **/
      /* u3_lr_bin(): 
      **
      **   Return the size of (b) in bits, rounded up to
      **   (1 << y_a). 
      **
      **   For example, (y_a == 3) returns the size in bytes.
      */
        c3_w
        u3_lr_bin(u3_lv     lv,
                  c3_y      y_a,
                  u3_l_atom b);

      /* u3_lr_bit():
      **
      **   Return bit (w_a) of (b).
      */
        c3_b
        u3_lr_bit(u3_lv     lv,
                  c3_w      w_a,
                  u3_l_atom b);
       
      /* u3_lr_byte():
      **
      **   Return byte (w_a) of (b).
      */
        c3_y
        u3_lr_byte(u3_lv     lv,
                   c3_w      w_a,
                   u3_l_atom b);
                  
      /* u3_lr_bytes():
      **
      **  Copy bytes (w_a) through (w_a + w_b - 1) from (d) to (c).
      */
        void
        u3_lr_bytes(u3_lv     lv,
                    c3_w      w_a,
                    c3_w      w_b,
                    c3_y      *y_c,
                    u3_l_atom d);

      /* u3_lr_cell():
      **
      **   Factor (a) as a cell (b c).
      */
        u3_l_flag
        u3_lr_cell(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_rat *b,
                   u3_l_rat *c);

      /* u3_lr_sing():
      **
      **   Yes iff (a) and (b) are the same noun.
      */
        u3_l_flag
        u3_lr_sing(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_fox b);

      /* u3_lr_sing_c():
      **
      **   Yes iff (b) is the same noun as the C string c_a.
      */
        u3_l_flag
        u3_lr_sing_c(u3_lv    lv,
                     c3_c     *c_a,
                     u3_l_fox b);

      /* u3_lr_fork():
      **
      **   Factor (a) as a fork [b.[p q] c].
      */
        u3_l_flag
        u3_lr_fork(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_rat *b,
                   u3_l_rat *c);

      /* u3_lr_ord():
      **
      **   0 if a < b, 1 if a == b, 2 if a > b
      */
        u3_l_atom
        u3_lr_ord(u3_lv    lv,
                  u3_l_fox a,
                  u3_l_fox b);

      /* u3_lr_p():
      **
      **   & [0] if [a] is of the form [b *c].
      */
        u3_l_flag
        u3_lr_p(u3_lv lv,
                u3_l_fox a,
                u3_l_fox b,
                u3_l_fox *c);

      /* u3_lr_pq():
      **
      **   & [0] if [a] is of the form [b *c d].
      */
        u3_l_flag
        u3_lr_pq(u3_lv lv,
                 u3_l_fox a,
                 u3_l_fox b,
                 u3_l_fox *c,
                 u3_l_fox *d);

      /* u3_lr_pqr():
      **
      **   & [0] if [a] is of the form [b *c *d *e].
      */
        u3_l_flag
        u3_lr_pqr(u3_lv lv,
                  u3_l_fox a,
                  u3_l_fox b,
                  u3_l_fox *c,
                  u3_l_fox *d,
                  u3_l_fox *e);

      /* u3_lr_stud():
      **
      **   Yes iff (a) is an atom.
      */
#if 0
        u3_l_flag
        u3_lr_stud(u3_lv    lv,
                   u3_l_fox a)
#else 
#       define u3_lr_stud(lv, a) \
          (u3_li_rat_is_atom(a) ? u3_yes : u3_no)
#endif

      /* u3_lr_h():
      **
      **   Return the head of (a).
      */
        u3_l_rat
        u3_lr_h(u3_lv    lv, 
                u3_l_fox a);

      /* u3_lr_mp():
      **
      **   Copy (b) into (mp_a).
      */
        void
        u3_lr_mp(u3_lv     lv,
                 mpz_t     mp_a,
                 u3_l_atom b);

      /* u3_lr_qual():
      **
      **   Factor (a) as a qual (b c d e).
      */
        u3_l_flag
        u3_lr_qual(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_rat *b,
                   u3_l_rat *c,
                   u3_l_rat *d,
                   u3_l_rat *e);

      /* u3_lr_quil():
      **
      **   Factor (a) as a quil (b c d e f).
      */
        u3_l_flag
        u3_lr_quil(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_rat *b,
                   u3_l_rat *c,
                   u3_l_rat *d,
                   u3_l_rat *e,
                   u3_l_rat *f);

      /* u3_lr_hext():
      **
      **   Factor (a) as a hext (b c d e f g)
      */
        u3_l_flag
        u3_lr_hext(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_rat *b,
                   u3_l_rat *c,
                   u3_l_rat *d,
                   u3_l_rat *e,
                   u3_l_rat *f,
                   u3_l_rat *g);


      /* u3_lr_t():
      **
      **   Return the tail of (a).
      */
        u3_l_rat
        u3_lr_t(u3_lv    lv, 
                u3_l_fox a);

      /* u3_lr_dust():
      **
      **   Yes iff (a) is a cell.
      */
#if 0
        u3_flag
        u3_lr_dust(u3_lv    lv,
                   u3_l_fox a)
#else 
#       define u3_lr_dust(lv, a) \
          (u3_li_rat_is_atom(a) ? u3_l_no : u3_l_yes)
#endif

      /* u3_lr_trel():
      **
      **   Factor (a) as a trel (b c d).
      */
        u3_l_flag
        u3_lr_trel(u3_lv    lv,
                   u3_l_fox a,
                   u3_l_rat *b,
                   u3_l_rat *c,
                   u3_l_rat *d);

      /* u3_lr_twig():
      **
      **   Return twig (a) of (b).
      */
        u3_l_rat
        u3_lr_twig(u3_lv     lv,
                   u3_l_atom a,
                   u3_l_fox  b);

      /* u3_lr_word():
      **
      **   Return word (w_a) of (b).
      */
        c3_w
        u3_lr_word(u3_lv     lv,
                   c3_w      w_a,
                   u3_l_atom b);

      /* u3_lr_words():
      **
      **  Copy words (w_a) through (w_a + w_b - 1) from (d) to (c).
      */
        void
        u3_lr_words(u3_lv     lv,
                    c3_w      w_a,
                    c3_w      w_b,
                    c3_w      *w_c,
                    u3_l_atom d);
