/* include/host.h
**
** This file is in the public domain.
*/
  /** Functions.
  **/
    /* u2_ho_boot(): 
    **
    **   Boot driver system.  Note that all birds and
    **   tools are considered permanent between reboots.
    */
      void
      u2_ho_boot();

    /* u2_ho_reset(): 
    **
    **   Reboot driver system.  Note that all birds and
    **   tools are considered permanent between reboots.
    */
      void
      u2_ho_reset();

    /* u2_ho_warn(): 
    **
    **   Report a warning at file and line.  This is assumed
    **   to have no semantic effect and negligible cost.
    */
      void
      u2_ho_warn(const c3_c* fil_c,
                c3_w        lyn_w);

#     define u2_ho_warn_here() u2_ho_warn(__FILE__, __LINE__)

    /* u2_ho_fire(): 
    **
    **   Drive in OID to formula.  Core prevalidated.
    **
    **   If *ver_t is 1, caller must check result.
    */
      u2_weak
      u2_ho_fire(u2_ray  wir_r,
                 u2_noun oid,
                 u2_noun cor,
                 u2_noun fol,
                 c3_t*   ver_t);

    /* u2_ho_dive():
    **
    **   Report compatibility failure in `dac`.  May not return.
    */
      void
      u2_ho_dive(u2_ray  wir_r,
                 u2_noun dac);
