/* include/rail.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /** Ray types.
    **/
      /* u2_rail: an allocation control frame.
      */
        typedef u2_ray u2_rail;

      /* u2_wire: an execution context, inheriting rail
      */
        typedef u2_ray u2_wire;

    /** Structures - in loom space.
    **/
      /* Base rail.
      */
        typedef struct _u2_loom_rail {
          u2_ray cap_r;   // top of transient region
          u2_ray hat_r;   // top of new durable region
          u2_ray mat_r;   // bottom of transient region
          u2_ray rut_r;   // bottom of new durable region
          c3_m   hip_m;   // memory model in durable; c3__warm, c3__cold

          /* Devil; u2_loom_devl; benchmarking and debugging.
          */
          u2_ray dev_r;
        } u2_loom_rail;

#         define  u2_rail_cap_r(ral_r)  *u2_at(ral_r, u2_loom_rail, cap_r)
#         define  u2_rail_hat_r(ral_r)  *u2_at(ral_r, u2_loom_rail, hat_r)
#         define  u2_rail_mat_r(ral_r)  *u2_at(ral_r, u2_loom_rail, mat_r)
#         define  u2_rail_rut_r(ral_r)  *u2_at(ral_r, u2_loom_rail, rut_r)
#         define  u2_rail_hip_m(ral_r)  *u2_at(ral_r, u2_loom_rail, hip_m)

      /* Pork - base of frame.
      */
        typedef struct {
          u2_ray mut_r;   // parent mat
          u2_ray rit_r;   // parent rut
          c3_m   hap_m;   // parent hip
        } u2_loom_pork;
#         define u2_pork_mut_r(pik_r)  *u2_at(pik_r, u2_loom_pork, mut_r)
#         define u2_pork_rit_r(pik_r)  *u2_at(pik_r, u2_loom_pork, rit_r)
#         define u2_pork_hap_m(pik_r)  *u2_at(pik_r, u2_loom_pork, hap_m)

      /* Floe - a solid rail allocator.  Implied by `hip_m == c3__cold`.
      */
        typedef struct {
        } u2_loom_floe;

      /* Soup - a liquid rail allocator.
      */
        typedef struct {
          u2_ray fre_r;   // single, doubly-linked free list
        } u2_loom_soup;
#         define u2_soup_fre_r(sop_r)  *u2_at(sop_r, u2_loom_soup, fre_r)

      /* A noun box, for liquid hats.  Behind pointer, addressed fwd.
      **
      ** The box size is also stored at the end of the box in classic
      ** bad ass malloc style.  Hence a box is:
      **
      **    ---
      **    siz_w
      **    use_w
      **      user data
      **    siz_w
      **    ---
      **
      ** Do not attempt to adjust this structure!
      */
        typedef struct _u2_loom_rail_box {
          c3_w   siz_w;     // size of this box
          c3_w   use_w;     // reference count; free if 0
        } u2_loom_rail_box;

#         define u2_rail_box_siz(box) *u2_at(box, u2_loom_rail_box, siz_w)
#         define u2_rail_box_use(box) *u2_at(box, u2_loom_rail_box, use_w)

      /* A free node.  Addressed from the box.
      */
        typedef struct _u2_loom_rail_hut {
          u2_loom_rail_box b;
          u2_ray pre_r;   // next on free list
          u2_ray nex_r;   // next on free list
        } u2_loom_rail_hut;

#         define u2_rail_hut_siz(hut) *u2_at(hut, u2_loom_rail_hut, b.siz_w)
#         define u2_rail_hut_use(hut) *u2_at(hut, u2_loom_rail_hut, b.use_w)
#         define u2_rail_hut_pre(hut) *u2_at(hut, u2_loom_rail_hut, pre_r)
#         define u2_rail_hut_nex(hut) *u2_at(hut, u2_loom_rail_hut, nex_r)

    /** Functions.
    **/
      /** Management.
      **/
        /* u2_rl_boot():
        **
        **   Create an empty rail in an empty loom, with memory model `hip`.
        **   See u2_rl_leap() for storage policies.
        */
          u2_ray
          u2_rl_boot(c3_m hip_m);

        /* u2_rl_valid():
        **
        **   Validate rail for memory bugs.
        */
          void
          u2_rl_valid(u2_ray ral_r);

        /* u2_rl_init():
        **
        **   Install an empty rail within `hat_r` and `mat_r` in the loom,
        **   with memory model `hip`.
        **
        **   Returns ray to rail, which always equalls the passed `mat_r`.
        */
          u2_ray
          u2_rl_init(c3_m   hip_m,
                     u2_ray hat_r,
                     u2_ray mat_r);

        /* u2_rl_ralloc():
        **
        **   Allocate `siz_w` words of raw ray storage.
        */
          u2_ray
          u2_rl_ralloc(u2_ray ral_r,
                       c3_w   siz_w);

        /* u2_rl_rfree():
        **
        **   Free raw ray storage allocated by `u2_rl_ralloc()`.
        */
          void
          u2_rl_rfree(u2_ray ral_r,
                      u2_ray nov_r);

        /* u2_rl_malloc():
        **
        **   Allocate `sib_w` *bytes* of raw C storage.
        */
          void*
          u2_rl_malloc(u2_ray ral_r,
                       c3_w   sib_w);

        /* u2_rl_free():
        **
        **   Free storage allocated by u2_rl_malloc().
        */
          void
          u2_rl_free(u2_ray ral_r,
                     void*  lag_v);

        /* u2_rl_leap():
        **
        **   Reverse the beams forward, with memory model `hip`.
        **   Memory models at present:
        **
        **    c3__cold    solid, no boxes or reference counts
        **    c3__warm    liquid, boxes, reference-counted heap
        **
        **   Returns u2_yes on success.
        */
          u2_flag
          u2_rl_leap(u2_ray ral_r,
                     c3_m   hip_m);

        /* u2_rl_leap_part():
        **
        **   Reverse and split rail, inserting partition of size `num/dem`
        **   plus `tip`. 
        **
        **   Returns partition rail, `aux_r`.
        */
          u2_ray
          u2_rl_leap_part(u2_ray ral_r,
                          c3_m   hop_m,
                          c3_w   num_w,
                          c3_w   dem_w,
                          c3_w   tip_w);
        /* u2_rl_fall():
        **
        **   Reverse the beams backward, restoring the old frame.
        */
          void
          u2_rl_fall(u2_ray ral_r);

        /* u2_rl_fall_part():
        **
        **   Fall on `ral`, also releasing the partition `aux`.
        */
          void
          u2_rl_fall_part(u2_ray ral_r,
                          u2_ray aux_r);

        /* u2_rl_flog():
        **
        **   Release the can, setting cap to mat.
        */
          void
          u2_rl_flog(u2_ray ral_r);

        /* u2_rl_gain():
        **
        **   Gain a reference to `som`.
        */
          void
          u2_rl_gain(u2_ray  ral_r,
                     u2_noun som);

        /* u2_rl_lose():
        **
        **   Lose a reference to `som`.  Free it if refcount == 0.
        */
          void
          u2_rl_lose(u2_ray  ral_r,
                     u2_noun som);

        /* u2_rl_open():
        **
        **   Yes iff [a] more words remain in the pad.
        */
          u2_flag
          u2_rl_open(u2_ray ral_r,
                     c3_w   a_w);

        /* u2_rl_clear():
        **
        **   Yes iff [lef] does not point to any word >= [net]
        **   and < [bat].
        */
          u2_flag
          u2_rl_clear(u2_noun lef,
                      u2_ray  net_r,
                      u2_ray  bat_r);

        /* u2_rl_junior():
        **
        **   Yes iff `dus` is junior in `ral` - ie, must be copied
        **   to be referenced on the hat.
        */
          u2_flag
          u2_rl_junior(u2_ray  ral_r,
                       u2_noun dus);

        /* u2_rl_senior():
        **
        **   Yes iff `dus` is senior in `ral` - ie, does not
        **   require reference counting.
        */
          u2_flag
          u2_rl_senior(u2_ray  ral_r,
                       u2_noun dus);

        /* u2_rl_tamp():
        **
        **   Tamp, eliding the segment from `net` up to `bat`,
        **   preserving the root `lef`.
        **
        **   Assumes u2_rl_clear() with the same arguments.
        */
          u2_noun
          u2_rl_tamp(u2_ray  ral_r,
                     u2_noun lef,
                     u2_ray  net_r,
                     u2_ray  bat_r);

        /* u2_rl_water():
        **
        **   Return east and west watermarks, respectively.
        */
          void
          u2_rl_water(u2_ray ral_r,
                      c3_w*  maz_w,
                      c3_w*  buc_w);

      /** Generation.
      **/
        /* u2_rl_bytes():
        **
        **   Copy [a] bytes from [b].
        */
          u2_weak
          u2_rl_bytes(u2_ray      ral_r,
                      c3_w        a_w,
                      const c3_y* b_y);

        /* u2_rl_string():
        **
        **   u2_rl_bytes(ral_r, strlen(a_c), (c3_y *)a_c);
        */
          u2_weak
          u2_rl_string(u2_ray      ral_r,
                       const c3_c* a_c);

        /* u2_rl_cell(): 
        **
        **   Produce the cell [a b].
        */
          u2_weak
          u2_rl_cell(u2_ray  ral_r,
                     u2_noun a,
                     u2_noun b);
#         define u2_rc(ral_r, a, b) u2_rl_cell(ral_r, a, b)

        /* u2_rl_ice():
        **
        **   Produce `a`, not referencing the can.  Copy or gain reference.
        */
          u2_weak
          u2_rl_ice(u2_ray  ral_r,
                    u2_noun a);

        /* u2_rl_mp():
        **
        **   Copy the GMP integer [a] into an atom.
        */
          u2_weak
          u2_rl_mp(u2_ray ral_r,
                   mpz_t  a_mp);

        /* u2_rl_qual(): 
        **
        **   Produce the quadruple [a b c d].
        */
          u2_weak
          u2_rl_qual(u2_ray  ral_r,
                     u2_noun a,
                     u2_noun b,
                     u2_noun c,
                     u2_noun d);
#         define u2_rq(ral_r, a, b, c, d) u2_rl_qual(ral_r, a, b, c, d)

        /* u2_rl_trel(): 
        **
        **   Produce the triple [a b c].
        */
          u2_weak
          u2_rl_trel(u2_ray  ral_r,
                     u2_noun a,
                     u2_noun b,
                     u2_noun c);
#         define u2_rt(ral_r, a, b, c) u2_rl_trel(ral_r, a, b, c)

        /* u2_rl_words():
        **
        **   Copy [a] words from [b] into an atom.
        */
          u2_weak
          u2_rl_words(u2_ray      ral_r,
                      c3_w        a_w,
                      const c3_w* b_w);

