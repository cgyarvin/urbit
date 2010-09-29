/* include/benx.h
**
** This file is in the public domain.
*/
  /** Data structures.
  **/
    /* u2_loom_benx: the performance log.
    */
      typedef struct _u2_loom_benx {
        /* Interpreter steps.
        */
        c3_d  sap_d;

        /* Words copied.
        */
        c3_d  cop_d;

        /* Jet activations.
        */
        c3_d  jax_d;

        /* User-defined activations.
        */
        c3_d  use_d;

        /* Current depth of C stack.
        */
        c3_w  wac_w;

        /* Maximum depth of C stack.
        */
        c3_w  wax_w;

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
        
        /* Unix time in seconds.
        */
        c3_w sec_w;

        /* Unix time in microseconds.
        */
        c3_w usc_w;
      } u2_loom_benx;

#define   u2_benx_at(bex_r, wof)        *u2_at(bex_r, u2_loom_benx, wof)
#define   u2_benx_be(bex_r, ite, wof)   *u2_be(bex_r, u2_loom_benx, ite, wof)


  /** Functions.
  **/
    /* u2_bx_boot(): reset the performance log.
    */
      void
      u2_bx_boot(u2_ray wir_r);

    /* u2_bx_post(): export and reset the performance log.
    **
    **  sap: number of steps
    **  cop: number of words copied
    **  jax: number of jet activations
    **  use: number of user counts
    **  wax: maximum depth of C stack
    **  moc: number of words touched
    **  hix: number of words acquired
    **  ums: number of milliseconds consumed
    */
      u2_flag
      u2_bx_post(u2_ray wir_r,
                 c3_d   *sap_d,
                 c3_d   *cop_d,
                 c3_d   *jax_d,
                 c3_d   *use_d,
                 c3_w   *wax_w,
                 c3_w   *moc_w,
                 c3_w   *hix_w,
                 c3_w   *ums_w);
 
    /* u2_bx_step(): note interpreter step.
    */
      void
      u2_bx_step(u2_ray wir_r);

    /* u2_bx_copy(): note `cop` copied words.
    */
      void 
      u2_bx_copy(u2_ray wir_r,
                 c3_w   cop_w);
                 
    /* u2_bx_fall(): go deeper (call) in the C stack.
    */
      void
      u2_bx_fall(u2_ray wir_r);

    /* u2_bx_rise(): go shallower (return) in the C stack.
    */
      void 
      u2_bx_rise(u2_ray wir_r);

    /* u2_bx_used(): report a user count.
    */
      void
      u2_bx_used(u2_ray wir_r);

    /* u2_bx_flew(): report a jet activation.
    */
      void
      u2_bx_flew(u2_ray wir_r);

    /* u2_bx_mark(): update memory watermarks.
    */
      void
      u2_bx_mark(u2_ray wir_r);
