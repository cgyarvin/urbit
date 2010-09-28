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

    /* u2_ho_fire(): 
    **
    **   Drive in bird to formula.  Core prevalidated.
    **
    **   If *ver_t is 1, caller must check result.
    */
      u2_weak
      u2_ho_fire(u2_ray  wir_r,
                 u2_noun dac,
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
