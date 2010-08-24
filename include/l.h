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
    ** adequate for most light-duty programming tasks.  A "nit"
    ** is a 28-bit word pointer in the loom.
    **
    ** A "ray" is a 29-bit word offset onto a beam.  If bit 29
    ** is 0, the ray grows forward from 0 and is "west."  If bit
    ** 29 is 1, the ray grows backward from the end of the loom,
    ** and is "east."
    **
    ** All u3 nouns are represented by the 32-bit word type "rat."
    ** If bit 31 of a rat is 0, it is a "cat" - a direct atom.
    ** Bits 0-30 of a cat are an unsigned 31-bit integer.
    **
    ** A rat can be a special value, u3_none - not a noun.  A
    ** rat which is not u3_none is a "fox."
    **
    ** If bit 31 of a rat is 1, bits 0-28 are a ray which points
    ** to an indirect noun - a "dog."  If bit 30 is 0, the dog is
    ** a "hog" - an indirect cell.  If bit 30 is 1, the noun is a
    ** "pig" - an indirect atom.  (Bit 29 is reserved.)
    **
    ** A loom contains four pointers: "bat," "hat," "cap" and "mat."
    **
    ** "bat," a nit, points to the first word in the east beam.
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
    **
    ** The loom algorithm, while by no means ideal for all functions,
    ** makes a good general-purpose default.  Note especially that if
    ** you are writing a function for which the loom is by no means
    ** ideal, you have an unfragmented block in which to use any other
    ** allocator.  This is most often in practice reference counting,
    ** which always works with acyclic nouns.
    */
 

  /** Data types.
  **/
    /** Bitfields.
    ***
    ***     u3_nit - word offset in loom
    ***       &&&&:28a
    ***         a: offset from loom
    ***
    ***     u3_ray - word offset on beam
    ***       &&&:1a:28b
    ***         a: beam (& = low = west, | = high = east)
    ***         b: offset on beam
    ***
    ***     u3_rat - noun
    ***       ?(cat, dog)
    ***       1a:31b
    ***         a: cat if 0, dog if 1
    ***
    ***     u3_dog - indirect atom or cell
    ***       ?(hog, pig)
    ***       |:29a:1b:1c
    ***         a: ray to data
    ***         b: reserved for extension bit
    ***
    ***     u3_cat - direct atom
    ***       &:31a
    ***         a: unsigned integer
    ***
    ***     u3_hog - indirect cell
    ***       |:29a:1b:&
    ***         a: ray to struct u3_cell
    ***         b: reserved for extension bit
    ***
    ***     u3_pig - indirect atom
    ***       |:29a:1b:|
    ***         a: ray to struct u3_atom
    ***         b: reserved for extension bit
    **/
      typedef c3_w u3_nit;
      typedef c3_w u3_ray;
      typedef c3_w u3_rat;
      typedef c3_w u3_dog;
      typedef c3_w u3_cat;
      typedef c3_w u3_pig;


    /** Structures.
    ***
    ***   u3_loom - the loom
    ***   u3_cell - cell structure (in beam space - do not use)
    ***   u3_atom - atom structure (in beam space - do not use)
    **/
      /* l_core: the loom itself.
      */
        struct u3_loom {
          /* bat: east end of the loom.
          */
          u3_nit bat_nit;

          /* cap, hat, mat: allocation pointers.
          */
          u3_ray cap_ray;
          u3_ray hat_ray;
          u3_ray mat_ray;
          
          /* cop: count of words copied.
          */
          c3_w   cop_w;
        };
        typedef struct u3_loom *u3_l;
        typedef void *u3_lv;

      /* li_atom, li_cell: imaginary structures (in beam space).
      */
        struct u3_atom {
          c3_w mug_w;
          c3_w len_w;
          c3_w buf_w[0];
        };

        struct u3_cell {
          c3_w   mug_w;
          u3_ray hed_ray;
          u3_ray tel_ray;
        };
   

  /** Basic macros.
  **/
    /** Bitfield unpacking.  See above.
    **/
#     define u3_ray_a(ray)     ( (ray) >> 28 )
#     define u3_ray_b(ray)     ( (ray) & ((1 << 28) - 1) )

#     define u3_rat_a(rat)     ( (rat) >> 31 )

#     define u3_dog_a(dog)     ( ((dog) &~ (1 << 31)) >> 2 )
#     define u3_dog_b(dog)     ( 1 & ((dog) >> 1) )
#     define u3_dog_c(dog)     ( 1 & (dog) )

#     define u3_hog_a(hog)     u3_dog_a(hog)
#     define u3_hog_b(hog)     u3_dog_b(hog)
#     define u3_pig_a(pig)     u3_dog_a(pig)
#     define u3_pig_b(pig)     u3_dog_b(pig)

#     define u3_rat_is_cat(rat) ( !u3_rat_a(rat) )
#     define u3_rat_is_dog(rat) ( u3_rat_a(rat) )

#     define u3_dog_is_hog(dog) ( !u3_dog_c(dog) )
#     define u3_dog_is_pig(dog) ( u3_dog_c(dog) )

#     define u3_rat_is_atom(a) \
        (u3_rat_is_cat(a) || u3_dog_is_pig(a))
       

    /** Bitfield packing.  See above.
    **/
#     define u3_ray_of(a, b)   ( ((a) << 28) | (b) )

#     define u3_dog_of(a, b, c) \
        ( (1 << 31) | ((a) << 2) | ((b) << 1) | (c) )

#     define u3_hog_of(a, b)   u3_dog_of(a, b, 0)
#     define u3_pig_of(a, b)   u3_dog_of(a, b, 1)


    /** Cage reference and geometry.
    **/
#     define u3_ray_nit(l, ray) \
        ( u3_ray_a(ray) ? ((l)->bat_nit - u3_ray_b(ray)) : (ray) )

#     define u3_at_nit(l, nit)   ( ((c3_w *) (l)) + (nit) )
#     define u3_at_ray(l, ray)    u3_at_nit(l, u3_ray_nit(l, ray))

#     define u3_ray_beam(ray)   u3_ray_a(ray)
#     define u3_ray_point(ray)  u3_ray_b(ray)

#     define u3_dog_ray(dog)    u3_dog_a(dog)

#     define u3_dog_beam(dog)   u3_ray_beam(u3_dog_ray(dog))

#     define u3_overflow(l, a) \
        ( ( (a) + \
            u3_ray_b((l)->hat_ray) + \
            u3_ray_b((l)->cap_ray) \
          ) >= \
          (l)->bat_nit \
        )

    /*** Noun structure access.
    ***/
#     define u3_at_dog_mug(l, a)   u3_at_ray(l, u3_dog_a(a))

#     define u3_at_hog_hed(l, a)   u3_at_ray(l, (1 + u3_hog_a(a)))
#     define u3_at_hog_tel(l, a)   u3_at_ray(l, (2 + u3_hog_a(a)))

#     define u3_at_pig_len(l, a)   u3_at_ray(l, (1 + u3_pig_a(a)))
#     define u3_at_pig_buf(l, a, b) \
        u3_at_ray(l, (2 + (b) + u3_pig_a(a)))


  /** Constants and macros.
  **/
    /* u3_none:
    **
    **   An exceptional value, comparable to NaN for floats.
    */
#     define u3_none u3_dog_of(u3_ray_of(0, 0), 0, 0)

    /* Distinguished numbers - don't laugh.
    */
#     define _0   0
#     define _1   1
#     define _2   2
#     define _3   3
#     define _4   4
#     define _5   5
#     define _6   6
#     define _7   7
#     define _8   8
#     define _9   9
#     define _10  10
#     define _11  11
#     define _12  12
#     define _13  13
#     define _14  14
#     define _15  15

    /* Nock operators.
    */
#     define u3_nock_frag  0
#     define u3_nock_bone  1
#     define u3_nock_sail  2
#     define u3_nock_dust  3
#     define u3_nock_vint  4
#     define u3_nock_sing  5
#     define u3_nock_trol  6
#     define u3_nock_flac  7
#     define u3_nock_gant  8
#     define u3_nock_gath  9
#     define u3_nock_germ  10
#     define u3_nock_hint  11
#     define u3_nock_coat  12

    /* u3_yes, u3_no, u3_nul;
    **
    **   Our Martian booleans and list terminator.
    */
#     define u3_yes 0
#     define u3_no  1
#     define u3_nul 0

    /* Tools for Martian booleans.
    */
#     define u3_so(x)      (u3_yes == (x))
#     define u3_say(x)     ( (x) ? u3_yes : u3_no )
#     define u3_and(x, y)  ( (u3_so(x) && u3_so(y)) ? u3_yes : u3_no )
#     define u3_or(x, y)   ( (u3_so(x) || u3_so(y)) ? u3_yes : u3_no )

#     define u3_nc(l, p, q)        u3_ln_cell(l, p, q)
#     define u3_nt(l, p, q, r)     u3_ln_trel(l, p, q, r)
#     define u3_nq(l, p, q, r, s)  u3_ln_qual(l, p, q, r, s)
#     define u3_nu(l, n)           u3_ln_cell(l, u3_nul, n)
#     define u3_nl(l, n)           u3_ln_cell(l, n, u3_nul)


  /** Typedefs.
  ***
  *** Noun typedefs may reflect usage, structure, or both.  Any noun
  *** typedef is a fox - that is, it may not be (u3_none).
  **/
    /* u3_fox:
    **
    **   A rat which is not u3_none.
    */
      typedef u3_rat u3_fox;

    /* u3_atom:
    **
    **   A fox which is an atom.
    */
      typedef u3_fox u3_atom;

    /* u3_cell:
    **
    **   A fox which is a cell.
    */
      typedef u3_fox u3_cell;

    /* u3_flag:
    **
    **   A Martian boolean (0 = yes, 1 = no).
    */
      typedef u3_fox u3_flag;

    /* u3_mote:
    **
    **   An ASCII string of 2-4 characters.
    */
      typedef u3_fox u3_mote;

    /* u3_list:
    **
    **   A zero-terminated, tailward list.
    */
      typedef u3_fox u3_list;


  /** Functions and hautes-macros.
  **/
    /** Lifecycle, management, and miscellaneous.
    **/
      /* u3_lm_new():
      **
      **   Create a loom, mallocing (1 << a_y) words of memory.  Return
      **   0 if malloc fails.
      **
      **   A loom can be freed with free() - there is no destructor.
      */
        u3_l
        u3_lm_new(c3_y a_y);

      /* u3_lm_alloc():
      **
      **   Allocate (a_w) words of C storage on the hat.
      */
        void *
        u3_lm_alloc(u3_lv lv,
                    c3_w  a_w);

      /* u3_lm_flap():
      **
      **   Reverse the beams forward, returning the old mat.
      */
        u3_ray
        u3_lm_flap(u3_lv lv);

      /* u3_lm_flop():
      **
      **   Reverse the beams backward, restoring the old mat.
      */
        void
        u3_lm_flop(u3_lv  lv,
                   u3_ray mat_ray);

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
        u3_lm_mug(u3_lv  lv,
                  u3_fox a);

      /* u3_lm_order():
      **
      **   Produce u3_yes iff (a) is below (b) in mug order.
      **
      **   Assumes a and b are not equal.
      */
        u3_flag
        u3_lm_order(u3_lv  lv,
                    u3_fox a,
                    u3_fox b);

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
                    c3_w* maz_w,
                    c3_w* buc_w);

      /* u3_lm_open():
      **
      **   Yes iff [a] more words remain in the pad of [l].
      */
#if 0
        u3_flag
        u3_lm_open(u3_lv lv,
                   c3_w  a_w);
#else
#       define u3_lm_open(lv, a_w) \
          (u3_overflow((u3_l)(void *)(lv), a_w) ? u3_no : u3_yes)
#endif

      /* u3_lm_clear():
      **
      **   Yes iff [lef] does not point to any word >= [lid]
      **   and < [nut].
      */
        u3_flag
        u3_lm_clear(u3_lv  lv,
                    u3_fox lef,
                    u3_ray lid_ray,
                    u3_ray nut_ray);

      /* u3_lm_tamp():
      **
      **   Tamp, eliding the segment from [lid_ray] up to [nut_ray],
      **   preserving the root [lef].
      **
      **   Assumes u3_lm_clear() with the same arguments.
      */
        u3_fox
        u3_lm_tamp(u3_lv  lv,
                   u3_fox lef,
                   u3_ray lid_ray,
                   u3_ray nut_ray);

      /* u3_lm_water():
      **
      **   Return east and west watermarks, respectively.
      */
        void
        u3_lm_water(u3_lv lv,
                    c3_w* maz_w,
                    c3_w* buc_w);

    /** Generation.
    ***
    *** All generators return u3_none if out of memory.
    **/
      /* u3_ln_bytes():
      **
      **   Copy [a_w] bytes from [b_y].
      */
        u3_rat
        u3_ln_bytes(u3_lv       lv,
                    c3_w        a_w,
                    const c3_y* b_y);

      /* u3_ln_string():
      **
      **   u3_ln_bytes(l, strlen(a_c), (c3_y *)a_c);
      */
        u3_rat
        u3_ln_string(u3_lv       lv,
                     const c3_c* a_c);

      /* u3_ln_cell(): 
      **
      **   Produce the cell [a b].
      */
        u3_rat
        u3_ln_cell(u3_lv  lv,
                   u3_fox a,
                   u3_fox b);

      /* u3_ln_ice():
      **
      **   Produce [a], not referencing the cap.
      */
        u3_rat
        u3_ln_ice(u3_lv  lv,
                  u3_fox a);

      /* u3_ln_mp():
      **
      **   Copy the GMP integer (a_mp) into an atom on the hat of (l).
      */
        u3_rat
        u3_ln_mp(u3_lv lv,
                 mpz_t a_mp);

      /* u3_ln_nock():
      **
      **    Execute (nock lan sef) with a trivial interpreter.
      */
        u3_rat
        u3_ln_nock(u3_lv  lv,
                   u3_fox lan,
                   u3_fox sef);

      /* u3_ln_trel(): 
      **
      **   Produce the trel [a b c] on the hat of [l], or u3_none if
      **   this would overflow the loom.
      */
        u3_rat
        u3_ln_trel(u3_lv  lv,
                   u3_fox a,
                   u3_fox b,
                   u3_fox c);

      /* u3_ln_weld():
      **
      **   Weld (b) into a single atom, gluing on (1 << a_y) lines.
      **   Eg, a_y = 3 to concatenate bytes, 0 for bits, 5 for words.
      */
        u3_rat
        u3_ln_weld(u3_lv  lv,
                   c3_y   a_y,
                   u3_fox b);
        
      /* u3_ln_words():
      **
      **   Copy (a_w) words from (b_w) into an atom on the hat of (l).
      */
        u3_rat
        u3_ln_words(u3_lv       lv,
                    c3_w        a_w,
                    const c3_w* b_w);
      

    /** Reading.
    **/
      /* u3_lr_bin(): 
      **
      **   Return the size of (b) in bits, rounded up to
      **   (1 << a_y). 
      **
      **   For example, (a_y == 3) returns the size in bytes.
      */
        c3_w
        u3_lr_bin(u3_lv   lv,
                  c3_y    a_y,
                  u3_atom b);

      /* u3_lr_bit():
      **
      **   Return bit (a_w) of (b).
      */
        c3_b
        u3_lr_bit(u3_lv   lv,
                  c3_w    a_w,
                  u3_atom b);
       
      /* u3_lr_byte():
      **
      **   Return byte (a_w) of (b).
      */
        c3_y
        u3_lr_byte(u3_lv   lv,
                   c3_w    a_w,
                   u3_atom b);
                  
      /* u3_lr_bytes():
      **
      **  Copy bytes (a_w) through (a_w + b_w - 1) from (d) to (c).
      */
        void
        u3_lr_bytes(u3_lv   lv,
                    c3_w    a_w,
                    c3_w    b_w,
                    c3_y*   c_y,
                    u3_atom d);

      /* u3_lr_cell():
      **
      **   Factor (a) as a cell (b c).
      */
        u3_flag
        u3_lr_cell(u3_lv   lv,
                   u3_fox  a,
                   u3_rat* b,
                   u3_rat* c);

      /* u3_lr_sing():
      **
      **   Yes iff (a) and (b) are the same noun.
      */
        u3_flag
        u3_lr_sing(u3_lv  lv,
                   u3_fox a,
                   u3_fox b);

      /* u3_lr_sing_c():
      **
      **   Yes iff (b) is the same noun as the C string a_c.
      */
        u3_flag
        u3_lr_sing_c(u3_lv  lv,
                     c3_c*  a_c,
                     u3_fox b);

      /* u3_lr_fork():
      **
      **   Factor [a] as a fork [b.[p q] c].
      */
        u3_flag
        u3_lr_fork(u3_lv   lv,
                   u3_fox  a,
                   u3_rat* b,
                   u3_rat* c);

      /* u3_lr_ord():
      **
      **   0 if a < b, 1 if a == b, 2 if a > b
      */
        u3_atom
        u3_lr_ord(u3_lv  lv,
                  u3_fox a,
                  u3_fox b);

      /* u3_lr_p():
      **
      **   & [0] if [a] is of the form [b *c].
      */
        u3_flag
        u3_lr_p(u3_lv   lv,
                u3_fox  a,
                u3_fox  b,
                u3_fox* c);

      /* u3_lr_pq():
      **
      **   & [0] if [a] is of the form [b *c d].
      */
        u3_flag
        u3_lr_pq(u3_lv   lv,
                 u3_fox  a,
                 u3_fox  b,
                 u3_fox* c,
                 u3_fox* d);

      /* u3_lr_pqr():
      **
      **   & [0] if [a] is of the form [b *c *d *e].
      */
        u3_flag
        u3_lr_pqr(u3_lv   lv,
                  u3_fox  a,
                  u3_fox  b,
                  u3_fox* c,
                  u3_fox* d,
                  u3_fox* e);

      /* u3_lr_stud():
      **
      **   Yes iff (a) is an atom.
      */
#if 0
        u3_flag
        u3_lr_stud(u3_lv    lv,
                   u3_fox a)
#else 
#       define u3_lr_stud(lv, a) \
          (u3_rat_is_atom(a) ? u3_yes : u3_no)
#endif

      /* u3_lr_h():
      **
      **   Return the head of (a).
      */
        u3_rat
        u3_lr_h(u3_lv  lv, 
                u3_fox a);

      /* u3_lr_mp():
      **
      **   Copy (b) into (a_mp).
      */
        void
        u3_lr_mp(u3_lv   lv,
                 mpz_t   a_mp,
                 u3_atom b);

      /* u3_lr_qual():
      **
      **   Factor (a) as a qual (b c d e).
      */
        u3_flag
        u3_lr_qual(u3_lv   lv,
                   u3_fox  a,
                   u3_rat* b,
                   u3_rat* c,
                   u3_rat* d,
                   u3_rat* e);

      /* u3_lr_quil():
      **
      **   Factor (a) as a quil (b c d e f).
      */
        u3_flag
        u3_lr_quil(u3_lv   lv,
                   u3_fox  a,
                   u3_rat* b,
                   u3_rat* c,
                   u3_rat* d,
                   u3_rat* e,
                   u3_rat* f);

      /* u3_lr_hext():
      **
      **   Factor (a) as a hext (b c d e f g)
      */
        u3_flag
        u3_lr_hext(u3_lv   lv,
                   u3_fox  a,
                   u3_rat* b,
                   u3_rat* c,
                   u3_rat* d,
                   u3_rat* e,
                   u3_rat* f,
                   u3_rat* g);


      /* u3_lr_t():
      **
      **   Return the tail of (a).
      */
        u3_rat
        u3_lr_t(u3_lv    lv, 
                u3_fox a);

      /* u3_lr_dust():
      **
      **   Yes iff (a) is a cell.
      */
#if 0
        u3_flag
        u3_lr_dust(u3_lv    lv,
                   u3_fox a)
#else 
#       define u3_lr_dust(lv, a) \
          (u3_rat_is_atom(a) ? u3_no : u3_yes)
#endif

      /* u3_lr_trel():
      **
      **   Factor (a) as a trel (b c d).
      */
        u3_flag
        u3_lr_trel(u3_lv    lv,
                   u3_fox a,
                   u3_rat *b,
                   u3_rat *c,
                   u3_rat *d);

      /* u3_lr_twig():
      **
      **   Return twig (a) of (b).
      */
        u3_rat
        u3_lr_twig(u3_lv     lv,
                   u3_atom a,
                   u3_fox  b);

      /* u3_lr_word():
      **
      **   Return word (a_w) of (b).
      */
        c3_w
        u3_lr_word(u3_lv     lv,
                   c3_w      a_w,
                   u3_atom b);

      /* u3_lr_words():
      **
      **  Copy words (a_w) through (a_w + b_w - 1) from (d) to (c).
      */
        void
        u3_lr_words(u3_lv   lv,
                    c3_w    a_w,
                    c3_w    b_w,
                    c3_w*   c_w,
                    u3_atom d);
