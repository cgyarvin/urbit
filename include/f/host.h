/* include/host.h
**
** This file is in the public domain.
*/
  /** Functions.
  **/
    /* u2_ho_push(): 
    **
    **   Push a driver hangar (corresponding to a jet shed).
    */
      void
      u2_ho_push(void);

    /* u2_ho_popp(): 
    **
    **   Pop a driver hangar.
    */
      void
      u2_ho_popp(void);

    /* u2_ho_klar():
    **
    **   Clear and release all hangars.
    */
      void
      u2_ho_klar(void);

    /* u2_ho_warn(): 
    **
    **   Report a warning at file and line.  This is assumed
    **   to have no semantic effect and negligible cost.
    */
      void
      u2_ho_warn(const c3_c* fil_c,
                c3_w        lyn_w);

#     define u2_ho_warn_here() u2_ho_warn(__FILE__, __LINE__)

    /* u2_ho_dive():
    **
    **   Report compatibility failure in `xip`. 
    */
      void
      u2_ho_dive(u2_ray  wir_r,
                 u2_noun xip);

    /* u2_ho_fire(): 
    **
    **   Attempt host nock driver on `xip`, `cor`, `fol`.
    **   For any failure to compute, return `u2_none`.
    **
    **   If `*saf` is u2_no, result is unsafe and needs testing.
    */
      u2_weak
      u2_ho_fire(u2_ray   wir_r,
                 u2_chip  xip,
                 u2_noun  cor,
                 u2_noun  fol,
                 u2_flag* saf);

    /* u2_ho_kick():
    **
    **   As `u2_ho_fire()`, but by axis instead of formula.
    */
      u2_weak
      u2_ho_kick(u2_ray   wir_r,
                 u2_chip  xip,
                 u2_noun  cor,
                 u2_atom  axe,
                 u2_flag* saf);

