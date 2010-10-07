/* include/bask.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
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
      } u2_loom_bask;

#       define u2_bask_par_r(bas_r)  *u2_at(bas_r, u2_loom_bask, par_r)
#       define u2_bask_mem_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, mem_c)
#       define u2_bask_sol_r(bas_r)  u2_aftr(bas_r, u2_loom_bask, sol_c)


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
      u2_weak
      u2_ba_find(u2_ray  wir_r,
                 u2_noun bus,
                 u2_noun fol);

    /* u2_ba_save():
    */
      void
      u2_ba_save(u2_ray  wir_r,
                 u2_noun bus,
                 u2_noun fol,
                 u2_noun pro);

    /* u2_ba_sole():
    **
    **   Save unique noun.
    */
      u2_weak
      u2_ba_sole(u2_ray  wir_r,
                 u2_noun som);
