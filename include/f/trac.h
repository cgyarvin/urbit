/* include/trac.h
**
** This file is in the public domain.
*/
  /** Data structures.
  **/
    /* u2_loom_knot: profile node.
    */
      typedef struct _u2_loom_knot {
        /* Task name - 31-byte prefix.
        */
        c3_c lic_c[32];

        /* Number of hits in this task.
        */
        c3_w fin_w;

        /* Subtask list, if any.
        */
        struct _u2_loom_knot *fam_k;
        struct _u2_loom_knot *nex_k;
      } u2_loom_knot;

    /* u2_loom_trac: tracing/profiling control structure.
    */
      typedef struct _u2_loom_trac {
        /* Control.
        */
          struct {
            /* u2_yes iff debugging is on.
            */
            u2_flag deb;

            /* u2_yes iff profiling is on.
            */
            u2_flag pro;
          } cor;

        /* Tracing.
        */
          struct {
            /* Position stack: *(list shoe) 
            */
            u2_noun ryp;
          } wer; 

        /* Profiling.
        */
          struct {
            /* Task stack: *(list term)
            */
            u2_noun don;

            /* Act count: *(map term num)
            */
            u2_noun cot;
          } duz;

        /* Built-in system acts and counters.
        */
          struct {
            /* Nock reductions.
            */
            c3_d hop_d;

            /* Jet activations.
            */
            c3_d jet_d;

            /* Jet tests.
            */
            c3_d tes_d;

            /* Matching comparisons.
            */
            c3_d nod_d;

            /* C stack record.
            */
            c3_ds cas_ds;

            /* Main memory usage record.
            */
            c3_ds mey_ds;

            /* Basket memory usage record.
            */
            c3_ds bek_ds;

            /* Unix time in seconds at analysis instantiation.
            */
            c3_w sec_w;

            /* Unix time in microseconds at analysis instantiation.
            */
            c3_w usc_w;
          } sys;
      } u2_loom_trac;

#define   u2_trac_at(rac_r, wof)        *u2_at(rac_r, u2_loom_trac, wof)
#define   u2_trac_be(rac_r, ite, wof)   *u2_be(rac_r, u2_loom_trac, ite, wof)

  /** Functions.
  **/
    /** Lifecycle.
    **/
      /* u2_tx_init(): initialize state.
      */
        u2_ray
        u2_tx_init(u2_ray wir_r);

      /* u2_tx_done(): produce a profile slab to render.  Close tracing.
      **
      ** type:
      */ 
        u2_noun                                                   //  produce
        u2_tx_done(u2_ray wir_r);

      /* u2_tx_open(): open tracing.
      */
        void
        u2_tx_open(u2_ray wir_r);

      /* u2_tx_do_*(): set debug/profile flag.  Return old value.
      */
        u2_flag u2_tx_do_debug(u2_ray wir_r, u2_flag lag);
        u2_flag u2_tx_do_profile(u2_ray wir_r, u2_flag lag);

      /* u2_tx_in_*(): get debug/profile flag.
      */
        u2_flag u2_tx_in_debug(u2_ray wir_r);
        u2_flag u2_tx_in_profile(u2_ray wir_r);

    /** Actions.
    **/
      /* u2_tx_did_*(): record system actions.
      */
        void u2_tx_did_hop(u2_ray wir_r);
        void u2_tx_did_jet(u2_ray wir_r);
        void u2_tx_did_tes(u2_ray wir_r);
        void u2_tx_did_nod(u2_ray wir_r);

      /* u2_tx_did_act(): record user actions.
      */
        void 
        u2_tx_did_act(u2_ray  wir_r, 
                      u2_noun did);                               //  retain

      /* u2_tx_add_*(): record signed change in watermarks.
      */
        void u2_tx_add_cas(u2_ray wir_r, c3_ws add_ws);
        void u2_tx_add_mey(u2_ray wir_r, c3_ws add_ws);
        void u2_tx_add_cas(u2_ray wir_r, c3_ws add_ws);

    /** Tasks.
    **/
      /* u2_tx_task_in(): enter a task for profiling purposes.
      **
      ** u2_yes iff the task is not already in the stack.
      */
        u2_flag
        u2_tx_task_in(u2_ray  wir_r, 
                      u2_noun tak);                               //  retain

      /* u2_tx_task_out(): leave a task for profiling purposes.
      */
        void
        u2_tx_task_out(u2_ray  wir_r);

    /** Direct logging.
    **/
      /* u2_tx_log(): log a wall.  Discouraged.
      */
        void
        u2_tx_log(u2_ray  wir_r, 
                  u2_noun wal);                                   //  retain

      /* u2_tx_warn(): report a warning by internal file and line.
      */
        void
        u2_tx_warn(u2_ray      wir_r,
                   const c3_c* fil_c,
                   c3_w        lyn_w);
#       define u2_tx_warn_here(wir_r) u2_bx_warn(wir_r, __FILE__, __LINE__)

