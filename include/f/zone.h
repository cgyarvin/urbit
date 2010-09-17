/* include/zone.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /** Structures - in loom space.
    **/
      /* The zone itself.
      */
        typedef struct _u2_loom_zone {
          u2_ray cap_r;   // top of transient region
          u2_ray hat_r;   // top of new durable region
          u2_ray mat_r;   // bottom of transient region
          u2_ray rut_r;   // bottom of new durable region
          c3_m   hip_m;   // memory model in durable; c3__warm, c3__cold
          c3_w   cop_w;   // benchmark - total copies in this zone
        } u2_loom_zone;

#         define  u2_zone_cap(zon)  *u2_at(zon, u2_loom_zone, cap_r)
#         define  u2_zone_hat(zon)  *u2_at(zon, u2_loom_zone, hat_r)
#         define  u2_zone_mat(zon)  *u2_at(zon, u2_loom_zone, mat_r)
#         define  u2_zone_rut(zon)  *u2_at(zon, u2_loom_zone, rut_r)
#         define  u2_zone_hip(zon)  *u2_at(zon, u2_loom_zone, hip_m)
#         define  u2_zone_cop(zon)  *u2_at(zon, u2_loom_zone, cop_w)

      /* A pot in the zone.  Stored on the mat.
      */
        typedef struct _u2_loom_zone_pot {
          u2_ray mat_r;   // senior mat
          u2_ray rut_r;   // senior rut
          c3_m   hip_m;   // senior memory model
        } u2_loom_zone_pot;

#         define u2_zone_pot_mat(pot) *u2_at(pot, u2_loom_zone_pot, mat_r)
#         define u2_zone_pot_rut(pot) *u2_at(pot, u2_loom_zone_pot, rut_r)
#         define u2_zone_pot_hip(pot) *u2_at(pot, u2_loom_zone_pot, hip_m)

      /* A liquid allocator.  Inherits the pot.
      */
        typedef struct _u2_loom_zone_warm {
          u2_loom_zone_pot p;
          
          /* Single free list for now.
          */
          u3_ray fre_r;
        } u2_loom_zone_warm;
#         define u2_zone_warm_fre(warm) *u2_at(warm, u2_loom_zone_warm, fre_r)

      /* A noun box, for liquid hats.  Behind pointer, addressed fwd.
      **
      ** The box size is also stored at the end of the box in classic
      ** malloc style.  Hence a box is:
      **
      **    ---
      **    siz_w
      **    use_w
      **      user data
      **    siz_w
      **    ---
      **
      ** Do not adjust this structure.
      */
        typedef struct _u2_loom_zone_box {
          c3_w   siz_w;     // size of this box
          c3_w   use_w;     // reference count; free if 0
        } u2_loom_zone_box;

#         define u2_zone_box_siz(box) *u2_at(box, u2_loom_zone_box, siz_w)
#         define u2_zone_box_use(box) *u2_at(box, u2_loom_zone_box, use_w)

      /* A free node.  Addressed from the box.
      */
        typedef struct _u2_loom_zone_hut {
          u2_loom_zone_box b;
          u2_ray pre_r;   // next on free list
          u2_ray nex_r;   // next on free list
        } u2_loom_zone_hut;

#         define u2_zone_hut_siz(hut) *u2_at(hut, u2_loom_zone_hut, b.siz_w)
#         define u2_zone_hut_use(hut) *u2_at(hut, u2_loom_zone_hut, b.use_w)
#         define u2_zone_hut_pre(hut) *u2_at(hut, u2_loom_zone_hut, pre_r)
#         define u2_zone_hut_nex(hut) *u2_at(hut, u2_loom_zone_hut, nex_r)

    /** Functions.
    **/
      /** Management.
      **/
        /* u2_zn_boot():
        **
        **   Create an empty zone in an empty loom, with memory model `hip`.
        **   See u2_zn_leap() for storage policies.
        */
          u2_ray
          u2_zn_boot(c3_m hip_m);

        /* u2_zn_ralloc():
        **
        **   Allocate `siz_w` words of raw ray storage.
        */
          u2_ray
          u2_zn_ralloc(u2_ray zon_r,
                       c3_w   siz_w);

        /* u2_zn_rfree():
        **
        **   Free raw ray storage allocated by `u2_zn_ralloc()`.
        */
          void
          u2_zn_rfree(u2_ray zon_r,
                      u2_ray nov_r);

        /* u2_zn_leap():
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
          u2_zn_leap(u2_ray zon_r,
                     c3_m   hip_m);

        /* u2_zn_fall():
        **
        **   Reverse the beams backward, restoring the old frame.
        */
          void
          u2_zn_fall(u2_ray zon_r);

        /* u2_zn_flog():
        **
        **   Release the can, setting cap to mat.
        */
          void
          u2_zn_flog(u2_ray zon_r);

        /* u2_zn_gain():
        **
        **   Gain a reference to `som`.
        */
          void
          u2_zn_gain(u2_ray  zon_r,
                     u2_noun som);

        /* u2_zn_lose():
        **
        **   Lose a reference to `som`.  Free it if refcount == 0.
        */
          void
          u2_zn_lose(u2_ray  zon_r,
                     u2_noun som);

        /* u2_zn_open():
        **
        **   Yes iff [a] more words remain in the pad.
        */
          u2_flag
          u2_zn_open(u2_ray zon_r,
                     c3_w   a_w);

        /* u2_zn_clear():
        **
        **   Yes iff [lef] does not point to any word >= [net]
        **   and < [bat].
        */
          u2_flag
          u2_zn_clear(u2_noun lef,
                      u2_ray  net_r,
                      u2_ray  bat_r);

        /* u2_zn_senior():
        **
        **   Yes iff `dus` is senior in `zon` - ie, does not
        **   require reference counting.
        */
          u2_flag
          u2_zn_senior(u2_ray  zon_r,
                       u2_noun dus);

        /* u2_zn_tamp():
        **
        **   Tamp, eliding the segment from `net` up to `bat`,
        **   preserving the root `lef`.
        **
        **   Assumes u2_zn_clear() with the same arguments.
        */
          u2_noun
          u2_zn_tamp(u2_ray  zon_r,
                     u2_noun lef,
                     u2_ray  net_r,
                     u2_ray  bat_r);

        /* u2_zn_water():
        **
        **   Return east and west watermarks, respectively.
        */
          void
          u2_zn_water(u2_ray zon_r,
                      c3_w*  maz_w,
                      c3_w*  buc_w);

      /** Generation.
      **/
        /* u2_zn_bytes():
        **
        **   Copy [a] bytes from [b].
        */
          u2_weak
          u2_zn_bytes(u2_ray      zon_r,
                      c3_w        a_w,
                      const c3_y* b_y);

        /* u2_zn_string():
        **
        **   u2_zn_bytes(zon_r, strlen(a_c), (c3_y *)a_c);
        */
          u2_weak
          u2_zn_string(u2_ray      zon_r,
                       const c3_c* a_c);

        /* u2_zn_cell(): 
        **
        **   Produce the cell [a b].
        */
          u2_weak
          u2_zn_cell(u2_ray  zon_r,
                     u2_noun a,
                     u2_noun b);
#         define u2_zc(zon_r, a, b) u2_zn_cell(zon_r, a, b)

        /* u2_zn_ice():
        **
        **   Produce `a`, not referencing the can.  Copy or gain reference.
        */
          u2_weak
          u2_zn_ice(u2_ray  zon_r,
                    u2_noun a);

        /* u2_zn_mp():
        **
        **   Copy the GMP integer [a] into an atom.
        */
          u2_weak
          u2_zn_mp(u2_ray zon_r,
                   mpz_t  a_mp);

        /* u2_zn_nock():
        **
        **    Execute (nock lan sef) with a trivial interpreter.
        */
          u2_weak
          u2_zn_nock(u2_ray  zon_r,
                     u2_noun lan,
                     u2_noun sef);

        /* u2_zn_qual(): 
        **
        **   Produce the quadruple [a b c d].
        */
          u2_weak
          u2_zn_qual(u2_ray  zon_r,
                     u2_noun a,
                     u2_noun b,
                     u2_noun c,
                     u2_noun d);
#         define u2_zq(zon_r, a, b, c, d) u2_zn_trel(zon_r, a, b, c, d)

        /* u2_zn_trel(): 
        **
        **   Produce the triple [a b c].
        */
          u2_weak
          u2_zn_trel(u2_ray  zon_r,
                     u2_noun a,
                     u2_noun b,
                     u2_noun c);
#         define u2_zt(zon_r, a, b, c) u2_zn_trel(zon_r, a, b, c)

        /* u2_zn_words():
        **
        **   Copy [a] words from [b] into an atom.
        */
          u2_weak
          u2_zn_words(u2_ray      zon_r,
                      c3_w        a_w,
                      const c3_w* b_w);

