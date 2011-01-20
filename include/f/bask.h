/* include/bask.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* u2_bask_code: custom plow baskets, temporary only.
    */
      typedef enum {
        u2_bask_plow_vus,
        u2_bask_plow_tyc,
        u2_bask_plow_gam,
        u2_bask_plow_hos,
        u2_bask_plow_zor,
        u2_bask_plow_niq,
        u2_bask_plow_fac,
        u2_bask_plow_vom,
        u2_bask_plow_pon,
        u2_bask_plow_fin,
        u2_bask_plow_huf,

        u2_bask_plow_end
      } u2_bask_code;

    /* u2_loom_bask: a memory basket, for caching nock results
    */
      typedef struct {
        u2_loom_rail o;

        /* par_r: parent basket: ray to u2_loom_bask
        */
        u2_ray par_r;

        /* mem: chad: memoize hash from subject/formula to product
        */
        u2_loom_chad mem_c;

        /* sol: chad: hash of singleton values.
        */
        u2_loom_chad sol_c;

        /* hag: chad: hash from battery to jet chip.
        */
        u2_loom_chad hag_c;

        /* vig: custom chads for plow.
        */
        u2_loom_chad vig_c[u2_bask_plow_end];
      } u2_loom_bask;

#       define u2_bask_par_r(bas_r)  *u2_at(bas_r, u2_loom_bask, par_r)
#       define u2_bask_mem_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, mem_c)
#       define u2_bask_sol_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, sol_c)
#       define u2_bask_hag_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, hag_c)

#       define u2_bask_vig_r(bas_r, i_w) \
          ( u2_aftr(bas_r, u2_loom_bask, vig_c) + \
            ((i_w) * c3_wiseof(u2_loom_chad)) )

  /** Functions.
  **/
    /* u2_ba_init(): 
    **
    **   Initialize wire basket, with parent if any.
    */
      void
      u2_ba_init(u2_ray wir_r,
                 u2_ray par_r);
 
    /* u2_ba_find():
    **
    **   Memory search for `.*(bus fol)` in `bas`.
    */
      u2_weak                                                     //  senior
      u2_ba_find(u2_ray  wir_r,
                 u2_noun bus,                                     //  retain
                 u2_noun fol);                                    //  retain

    /* u2_ba_save():
    **
    **   Save result of calculation.
    */
      u2_noun                                                     //  transfer
      u2_ba_save(u2_ray  wir_r,
                 u2_noun bus,                                     //  retain
                 u2_noun fol,                                     //  retain
                 u2_noun pro);                                    //  transfer

    /* u2_ba_find_plow():
    **
    **   Memory search for `key` in `poc_o`.
    */
      u2_weak                                                     //  senior
      u2_ba_find_plow(u2_ray       wir_r,
                      u2_bask_code poc_o,
                      u2_noun      key);                          //  retain

    /* u2_ba_save_plow():
    **
    **   Save custom plow.
    */
      u2_noun                                                     //  transfer
      u2_ba_save_plow(u2_ray       wir_r,
                      u2_bask_code poc_o,
                      u2_noun      key,                           //  retain
                      u2_noun      val);                          //  transfer

    /* u2_ba_sole():
    **
    **   Save unique noun.
    */
      u2_noun                                                     //  transfer
      u2_ba_sole(u2_ray  wir_r,
                 u2_noun som);                                    //  transfer

    /* u2_ba_sole_cell():
    **
    **   Construct and save cell.
    */
      u2_noun                                                     //  transfer
      u2_ba_sole_cell(u2_ray  wir_r,
                      u2_noun hed,                                //  transfer
                      u2_noun tal);                               //  transfer

    /* u2_ba_sole_trel():
    **
    **   Construct and save trel.  Consumes arguments, transmits result.
    */
      u2_noun                                                     //  transfer
      u2_ba_sole_trel(u2_ray  wir_r,
                      u2_noun one,                                //  transfer
                      u2_noun two,                                //  transfer
                      u2_noun tri);                               //  transfer

    /* u2_ba_sole_qual():
    **
    **   Construct and save quadruple.  Consumes arguments, transmits result.
    */
      u2_noun                                                     //  transfer
      u2_ba_sole_qual(u2_ray  wir_r,
                      u2_noun one,                                //  transfer
                      u2_noun two,                                //  transfer
                      u2_noun tri,                                //  transfer
                      u2_noun fer);                               //  transfer

    /* u2_ba_sole_tupl():
    **
    **   Construct and save n-tuple.  Consumes arguments, transmits result.
    **   Terminator is u2_none.
    */
      u2_noun                                                     //  transfer
      u2_ba_sole_tupl(u2_ray  wir_r,
                      ...);                                       //  transfer
