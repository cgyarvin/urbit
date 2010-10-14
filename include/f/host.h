/* include/host.h
**
** This file is in the public domain.
*/
  /** Types.
  **/
    /* u2_ho_jet: a C function, per formula.
    */
      typedef struct {
        /* Function control string - defines formula in battery.
        **
        **    ".@" | "hook"
        */
        const c3_c* fcs_c;

        /* chip: battery identifier.
        */
        u2_chip xip;

        /* Tool: Nock formula.
        */
        u2_tool fol;
 
        /* Stable iff true; test iff false.
        */
        c3_t ace_t;

        /* C function, on core `[[sam con] bat]`.
        */
        u2_weak (*fun_f)(u2_ray wir_r, u2_noun cor);
      } u2_ho_jet;

    /* u2_ho_driver: battery driver.
    */
      typedef struct {
        /* Control string - computed from seals.
        */
        const c3_c* cos_c;
      
        /* chip: battery identifier, from shed.
        */
        u2_chip xip;

        /* Mug: short hash of chip, or 0.  Must match if set.
        */
        c3_w mug_w;

        /* Function/formula jets.  Null `dar` terminates.
        */
        u2_ho_jet fan_j[1];
      } u2_ho_driver;

    /* u2_ho_pear: mug-to-pointer binding.
    */
      typedef struct {
        u2_noun tag;
        void*   ptr_v;
      } u2_ho_pear;

    /* u2_ho_cash: mug-to-pointer cache.  Semantics match sham.
    */
      typedef struct {
        u2_ho_pear dol_p[16];
      } u2_ho_cash;

    /* u2_ho_hangar: driver system.
    */
      typedef struct _u2_ho_hangar {
        /* Cache from formula to jet.
        */
        u2_ho_cash jac_s;

        /* Cache from chip to driver.
        */
        u2_ho_cash bad_s;

        /* Next hangar in stack.
        */
        struct _u2_ho_hangar *nex_h;
      } u2_ho_hangar;

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

