/* include/wire.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /** Structures - in loom space.
    **/
      /* u2_loom_wire: the whole thread.
      */
        typedef struct _u2_loom_wire {
          u2_loom_rail o;

          /* Kernel; u2_loom_watt; kernel and tools.
          */
          u2_ray wat_r;

          /* Basket; u2_loom_bask; senior storage.
          */
          u2_ray bas_r;

          /* Dashboard; u2_loom_dash; jet registration.
          */
          u2_ray des_r;

          /* Ray to machine exception buffer (C jmp_buf); used in jets.
          */
          u2_ray jub_r;

          /* Ray to performance log.
          */
          u2_ray bex_r;

          /* Interpreter trace.
          */
          u2_noun tax;
        } u2_loom_wire;

#         define  u2_wire_wat_r(wir_r)  *u2_at(wir_r, u2_loom_wire, wat_r)
#         define  u2_wire_bas_r(wir_r)  *u2_at(wir_r, u2_loom_wire, bas_r)
#         define  u2_wire_jub_r(wir_r)  *u2_at(wir_r, u2_loom_wire, jub_r)
#         define  u2_wire_bex_r(wir_r)  *u2_at(wir_r, u2_loom_wire, bex_r)

#         define  u2_wire_tax(wir_r)    *u2_at(wir_r, u2_loom_wire, tax)

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

