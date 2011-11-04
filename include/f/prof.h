/* include/prof.h
**
** This file is in the public domain.
*/
  /** Data structures.
  **/
    /* u2_loom_marx: stack parameter record.
    */
      typedef struct _u2_loom_marx {
        /* Current count.
        */
        c3_w cun_w;

        /* Original count.
        */
        c3_w lif_w;

        /* Maximum count.
        */
        c3_w myx_w;
      } u2_loom_marx;


    /* u2_loom_prof: tracing, profiling, debugging
    */
      typedef struct _u2_loom_prof {
        /* Source position debug stack: 
        **
        **  *(list &[p=* q=[p=* q=*(list [p=[p=@ q=@] q=[p=@ q=@]])]])
        */
        u2_weak zat;  // on shed

        /* Programmer action debug stack:
        **
        **  *(list &*) 
        */
        u2_weak zof;  // on shed

        /* Interpreter steps.
        */
        c3_d  sap_d;

        /* Words copied.
        */
        c3_d  cop_d;

        /* Matching comparisons.
        */
        c3_d  det_d;

        /* Jet activations.
        */
        c3_d  jax_d;

        /* User-defined activations.
        */
        c3_d  use_d;

        /* C stack record.
        */
        u2_loom_marx cas_m;

        /* Main memory usage record.
        */
        u2_loom_marx mey_m;

        /* Basket memory usage record.
        */
        u2_loom_marx bek_m;

        /* Unix time in seconds.
        */
        c3_w sec_w;

        /* Unix time in microseconds.
        */
        c3_w usc_w;
      } u2_loom_prof;

#define   u2_prof_at(bex_r, wof)        *u2_at(bex_r, u2_loom_prof, wof)
#define   u2_prof_be(bex_r, ite, wof)   *u2_be(bex_r, u2_loom_prof, ite, wof)


  /** Functions.
  **/
    /* u2_pf_boot(): reset the performance log.
    */
      void
      u2_pf_boot(u2_ray wir_r);

    /* u2_pf_post(): export and reset the performance log.
    **
    **  zat: source position stack (on shed)
    **  zof: programer action stack (on shed)
    **  sap: number of steps
    **  cop: number of words copied
    **  det: number of identical nouns compared
    **  jax: number of jet activations
    **  use: number of user counts
    **  wax: maximum depth of C stack
    **  viq: words in wire allocated
    **  zor: words in basket allocated
    **  ums: number of milliseconds consumed
    */
      u2_flag
      u2_pf_post(u2_ray   wir_r,
                 u2_noun* zat,
                 u2_noun* zof, 
                 c3_d*    sap_d,
                 c3_d*    cop_d,
                 c3_d*    det_d,
                 c3_d*    jax_d,
                 c3_d*    use_d,
                 c3_w*    wax_w,
                 c3_ws*   viq_ws,
                 c3_ws*   zor_ws,
                 c3_w*    ums_w);

    /* u2_pf_spot(): declare source position.
    */
      void
      u2_pf_spot(u2_ray  wir_r,
                 u2_noun hod);                                    //  transfer

    /* u2_pf_loaf(): print debug wall.
    */
      void
      u2_pf_loaf(u2_ray  wir_r,
                 u2_noun wal);                                    //  retain

    /* u2_pf_bean_ent(), u2_pf_bean_out(): enter and exit execution state.
    */
      void
      u2_pf_bean_ent(u2_ray  wir_r,
                     u2_noun hod);                                //  transfer
      void
      u2_pf_bean_out(u2_ray wir_r);

    /* u2_pf_step(): note interpreter step.
    */
      void
      u2_pf_step(u2_ray wir_r);

    /* u2_pf_copy(): note `cop` copied words.
    */
      void 
      u2_pf_copy(u2_ray wir_r,
                 c3_w   cop_w);

    /* u2_pf_dent(): note 'det' identicals.
    */
      void 
      u2_pf_dent(u2_ray wir_r,
                 c3_w   det_w);

    /* u2_pf_shed(): note `wad` allocated/freed words in hangar.
    */
      void
      u2_pf_shed(u2_ray wir_r,
                 c3_ws  wad_ws); 
  
    /* u2_pf_bask(): note `wad` allocated/freed words in basket.
    */
      void
      u2_pf_bask(u2_ray wir_r,
                 c3_ws  wad_ws);

    /* u2_pf_sink(): go deeper (call) in the C stack.
    */
      void
      u2_pf_sink(u2_ray wir_r);

    /* u2_pf_rise(): go shallower (return) in the C stack.
    */
      void 
      u2_pf_rise(u2_ray wir_r);

    /* u2_pf_used(): report a user count.
    */
      void
      u2_pf_used(u2_ray wir_r);

    /* u2_pf_flew(): report a jet activation.
    */
      void
      u2_pf_flew(u2_ray wir_r);

    /* u2_pf_mark(): update memory watermarks.
    */
      void
      u2_pf_mark(u2_ray wir_r);

    /* u2_pf_show(): print benchmark report and clear structure.
    */
      void
      u2_pf_show(u2_ray wir_r);

    /* u2_pf_warn(): report a warning at file and line.
    */
      void
      u2_pf_warn(u2_ray      wir_r,
                 const c3_c* fil_c,
                 c3_w        lyn_w);
#     define u2_pf_warn_here(wir_r) u2_pf_warn(wir_r, __FILE__, __LINE__)

