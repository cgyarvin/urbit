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

        /* mem: chad: hash from subject/formula to product
        */
        u2_loom_chad mem_c;

        /* sol: chad: hash of singleton values.
        */
        u2_loom_chad sol_c;

        /* vig: custom chads for plow.
        */
        u2_loom_chad vig_c[u2_bask_plow_end];
      } u2_loom_bask;

#       define u2_bask_par_r(bas_r)  *u2_at(bas_r, u2_loom_bask, par_r)
#       define u2_bask_mem_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, mem_c)
#       define u2_bask_sol_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, sol_c)

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
    **   Memory search for `.*(bus fol)` in `bas`.  Result is senior.
    */
      u2_weak
      u2_ba_find(u2_ray  wir_r,
                 u2_noun bus,
                 u2_noun fol);

    /* u2_ba_save():
    **
    **   Save result of calculation; consumes `pro`, transmits result.
    */
      u2_noun
      u2_ba_save(u2_ray  wir_r,
                 u2_noun bus,
                 u2_noun fol,
                 u2_noun pro);

    /* u2_ba_find_plow():
    **
    **   Memory search for `key` in `poc_o`.  Result is senior.
    */
      u2_weak
      u2_ba_find_plow(u2_ray       wir_r,
                      u2_bask_code poc_o,
                      u2_noun      key);

    /* u2_ba_save_plow():
    **
    **   Save custom plow; copies `key`; consumes `pro`, transmits result.
    */
      u2_noun
      u2_ba_save_plow(u2_ray       wir_r,
                      u2_bask_code poc_o,
                      u2_noun      key,
                      u2_noun      val);

    /* u2_ba_sole():
    **
    **   Save unique noun.  Consumes `som`, transmits result.
    */
      u2_noun
      u2_ba_sole(u2_ray  wir_r,
                 u2_noun som);

    /* u2_ba_sole_cell():
    **
    **   Construct and save cell.  Consumes arguments, transmits result.
    */
      u2_noun
      u2_ba_sole_cell(u2_ray  wir_r,
                      u2_noun hed,
                      u2_noun tal);

    /* u2_ba_sole_trel():
    **
    **   Construct and save trel.  Consumes arguments, transmits result.
    */
      u2_noun
      u2_ba_sole_trel(u2_ray  wir_r,
                      u2_noun one,
                      u2_noun two,
                      u2_noun tri);

    /* u2_ba_sole_qual():
    **
    **   Construct and save quadruple.  Consumes arguments, transmits result.
    */
      u2_noun
      u2_ba_sole_qual(u2_ray  wir_r,
                      u2_noun one,
                      u2_noun two,
                      u2_noun tri,
                      u2_noun fer);

    /* u2_ba_sole_tupl():
    **
    **   Construct and save n-tuple.  Consumes arguments, transmits result.
    **   Terminator is u2_none.
    */
      u2_noun
      u2_ba_sole_tupl(u2_ray  wir_r,
                      ...);
