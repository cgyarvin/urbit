/* include/bail.h
**
** This file is in the public domain.
*/
  /** Functions.
  **/
    /** Fail-only programming.
    ***
    *** Functions parallel equivalent u2_zn functions, but longjmp to pass
    *** on type mismatch, memory failure, etc.  When there is no u2_bl_
    *** function, the u2_zn function is identical and should be used.
    *** See include/zone.h for the u2_zn api.
    **/
      /* Fail-only cell dissection.  Use u2_h or u2_t if sure of cell.
      */
        u2_noun
        u2_bl_h(u2_ray, u2_noun);
      
        u2_noun
        u2_bl_t(u2_ray, u2_noun);
     
      /* u2_bl_bail():
      **
      **   Bail out without prejudice.
      */
        u2_noun
        u2_bl_bail(u2_ray);

      /* Noun allocation.
      */
#         define u2_bc(bel_r, a, b) \
            u2_bl_cell(bel_r, a, b)
#         define u2_bt(bel_r, a, b, c) \
            u2_bc(bel_r, a, u2_bc(bel_r, b, c))
#         define u2_bq(bel_r, a, b, c, d) \
            u2_bc(bel_r, a, u2_bt(bel_r, b, c, d))

        u2_noun
        u2_bl_bytes(u2_ray, c3_w, const c3_y*);

        u2_noun
        u2_bl_cell(u2_ray, u2_noun, u2_noun);

        u2_noun
        u2_bl_ice(u2_ray, u2_noun);

        u2_noun
        u2_bl_mp(u2_ray, mpz_t);

        u2_noun
        u2_bl_mung(u2_ray, u2_noun, u2_noun);

        u2_noun
        u2_bl_nock(u2_ray, u2_noun, u2_noun);

        u2_noun
        u2_bl_string(u2_ray, const c3_c*);

        u2_noun
        u2_bl_words(u2_ray, c3_w, const c3_w*);

      /* Memory allocation and management.  
      */
        u2_ray
        u2_bl_ralloc(u2_ray, c3_w);

        void*
        u2_bl_malloc(u2_ray, c3_w);

        void
        u2_bl_leap(u2_ray, c3_m);
