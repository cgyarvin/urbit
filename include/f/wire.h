/* include/wire.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /** Ray types.
    **/
      typedef u2_ray u2_wire;

    /** Structures - in loom space.
    **/
      /* u2_loom_wire: the whole thread.
      */
        typedef struct _u2_loom_wire {
          u2_loom_rail o;

          /* Kernel; u2_loom_watt; kernel and tools.
          */
          u2_ray wat_r;

          /* Basket; u2_loom_bask; memoization.
          */
          u2_ray bas_r;

          /* Jet shed or hangar; u2_loom_shed; registration and acceleration.
          */
          u2_ray sad_r;

          /* Ray to machine exception buffer (C jmp_buf); used in jets.
          */
          u2_ray jub_r;

          /* Plow; special support for bootstrap code; temporary.
          */
          u2_ray plo_r;

          /* Ray to performance log.
          */
          u2_ray bex_r;
        } u2_loom_wire;

#         define  u2_wire_wat_r(wir_r)  *u2_at(wir_r, u2_loom_wire, wat_r)
#         define  u2_wire_bas_r(wir_r)  *u2_at(wir_r, u2_loom_wire, bas_r)
#         define  u2_wire_sad_r(wir_r)  *u2_at(wir_r, u2_loom_wire, sad_r)
#         define  u2_wire_jub_r(wir_r)  *u2_at(wir_r, u2_loom_wire, jub_r)
#         define  u2_wire_plo_r(wir_r)  *u2_at(wir_r, u2_loom_wire, plo_r)
#         define  u2_wire_bex_r(wir_r)  *u2_at(wir_r, u2_loom_wire, bex_r)

    /** Functions.
    **/
      /** Administration.
      **/
        /* u2_wr_init():
        **
        **   Install an empty wire within `hat_r` and `mat_r` in the loom,
        **   with memory model `hip`.
        **
        **   Returns ray to wire, which always equalls the passed `mat_r`.
        */
          u2_ray
          u2_wr_init(c3_m   hip_m,
                     u2_ray hat_r,
                     u2_ray mat_r);

        /* u2_wr_ice(): u2_rl_ice(), with u2_bx_copy().
        */
          u2_weak
          u2_wr_ice(u2_ray  wir_r,
                    u2_noun fiz);
#if 0
        /* u2_wr_bench():
        **
        **  Save benchmarks with stack depth.
        */
          void
          u2_wr_bench(u2_ray wir_r,
                      c3_w   stk_w);

        /* u2_wr_report():
        **
        **  Return handy reporting information.
        */
          void
          u2_wr_report(u2_ray wir_r,
                       c3_w*  cop_w,
                       c3_w*  stk_w,
                       c3_w*  wst_w,
                       c3_w*  est_w);
#endif

      /** Nock.
      **/
        /* u2_wr_nock_main(wir, bus, fol):
        **
        **  wir:  wire
        **  bus:  subject
        **  fol:  formula
        **
        **    Execute `(nock bus fol)`, allocating on `hat`.
        **
        **    If computation fails for any reason, return `u2_none`.
        **    Failure must leave the loom undamaged.
        */
          u2_weak
          u2_wr_nock_main(u2_ray  wir_r,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_mung(): call with gate and sample.
        */
          u2_weak
          u2_wr_nock_mung(u2_ray  wir_r,
                          u2_noun gat,
                          u2_noun sam);

        /* u2_wr_nock_here():
        **
        **   As `u2_wr_nock_flee()`, but without cap reduction.
        */
          u2_weak
          u2_wr_nock_here(u2_ray  wir_r,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_flee():
        **
        **   Execute (nock bus fol) in the `flee` memory style.
        **
        **   After using `bus`, reduce `cap` to `net`.
        */
          u2_weak
          u2_wr_nock_flee(u2_ray  wir_r,
                          u2_ray  net_r,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_hint():
        */
          u2_weak
          u2_wr_nock_hint(u2_ray  wir_r,
                          u2_noun zep,
                          u2_noun hod,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_jet():
        **
        **   Jet-propel `(nock bus fol)`, or return u2_none.
        */
          u2_weak
          u2_wr_nock_jet(u2_ray  wir_r,
                         u2_noun bus,
                         u2_noun fol);

        /* u2_wr_hint():
        **
        **   Hint directly in a modern style.  Returns `u2_none` if hint
        **   processing fails.
        */
          u2_weak
          u2_wr_hint(u2_ray  wir_r,
                     u2_noun zep,
                     u2_noun hod,
                     u2_noun bus,
                     u2_noun fol);

        /* u2_wr_nock_keep(wir, bus, fol):
        */
          u2_weak
          u2_wr_nock_keep(u2_ray  wir_r,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_lame():
        **
        **    Execute `(nock bus fol)` with a simple reference interpreter.
        */
          u2_weak
          u2_wr_nock_lame(u2_ray  wir_r,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_toss():
        **
        **    Execute `(nock bus fol)`, losing `bus`, holding `fol`.
        */
          u2_weak
          u2_wr_nock_toss(u2_ray  wir_r,
                          u2_noun bus,
                          u2_noun fol);
