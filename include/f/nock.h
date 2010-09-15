/* include/wire.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /** Structures - in loom space.
    **/
      /* Development control.
      */
        typedef struct _u2_loom_devl {
          /* Maximum depth of C stack, in call records.
          */
          c3_w  stk_w;

          /* West base.
          */
          u2_ray wab_r;

          /* East base.
          */
          u2_ray eab_r;

          /* West watermark.
          */
          u2_ray wst_r;

          /* East watermark.
          */
          u2_ray est_r;
        } u2_loom_devl;

      /* The wire - nock thread.
      */
        typedef struct _u2_loom_wire {
          u2_loom_zone o;

          u2_loom_devl d;
#if 0
          /* Kernel; u2_loom_watt; kernel and tools.
          */
          u2_ray ken_r;

          /* Basket; u2_loom_bask; memoization.
          */
          u2_ray bas_r;

          /* Motor; u2_loom_motr; registration and acceleration.
          */
          u2_ray mot_r;

          /* Devil; u2_loom_devl; benchmarking and debugging.
          */
          u2_ray dev_r;
#endif
        } u2_loom_wire;

#         define  u2_wire_cap(wir)  *u2_at(wir, u2_loom_wire, o.cap_r)
#         define  u2_wire_hat(wir)  *u2_at(wir, u2_loom_wire, o.hat_r)
#         define  u2_wire_mat(wir)  *u2_at(wir, u2_loom_wire, o.mat_r)
#         define  u2_wire_rut(wir)  *u2_at(wir, u2_loom_wire, o.rut_r)
#         define  u2_wire_hip(wir)  *u2_at(wir, u2_loom_wire, o.hip_m)
#         define  u2_wire_cop(wir)  *u2_at(wir, u2_loom_wire, o.cop_w)

#         define  u2_wire_ken_r(wir)  *u2_at(wir, u2_loom_wire, k)
#         define  u2_wire_bas_r(wir)  *u2_at(wir, u2_loom_wire, b)
#         define  u2_wire_mot_r(wir)  *u2_at(wir, u2_loom_wire, m)
#         define  u2_wire_dev_r(wir)  *u2_at(wir, u2_loom_wire, d)

    /** Functions.
    **/
      /** Administration.
      **/
        /* u2_wr_boot():
        **
        **  Create an empty zone in an empty loom, with memory model `hip`.
        **  See u2_zn_leap() for storage policies.
        */
          u2_ray
          u2_wr_boot(c3_m hip_m);

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
                       c3_w*  stk_w,
                       c3_w*  wst_w,
                       c3_w*  est_w);

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

        /* u2_wr_nock_here():
        **
        **    As `u2_wr_nock_flee()`, but without cap reduction.
        */
          u2_weak
          u2_wr_nock_here(u2_ray  wir_r,
                          c3_w    stk_w,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_flee():
        **
        **    Execute (nock bus fol) in the `flee` memory style.
        **
        **    After using `bus`, reduce `cap` to `net`.
        */
          u2_weak
          u2_wr_nock_flee(u2_ray  wir_r,
                          c3_w    stk_w, 
                          u2_ray  net_r,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_keep(wir, bus, fol):
        */
          u2_weak
          u2_wr_nock_keep(u2_ray  wir_r,
                          c3_w    stk_w,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_lame():
        **
        **    Execute `(nock bus fol)` with a simple reference interpreter.
        */
          u2_weak
          u2_wr_nock_lame(u2_ray  wir_r,
                          c3_w    stk_w,
                          u2_noun bus,
                          u2_noun fol);

        /* u2_wr_nock_toss():
        **
        **    Execute `(nock bus fol)`, losing `bus`, holding `fol`.
        */
          u2_weak
          u2_wr_nock_toss(u2_ray  wir_r,
                          c3_w    stk_w,
                          u2_noun bus,
                          u2_noun fol);
