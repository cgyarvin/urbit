/* include/unix.h
**
** This file is in the public domain.
*/
  /** Functions.
  **/
    /* u2_ux_read(): read a filesystem path/extension into an atom.
    */
      u2_weak
      u2_ux_read(u2_ray      ral_r,
                 const c3_c* paf_c,
                 const c3_c* ext_c);

    /* u2_ux_rite(): write a filesystem path/extension as an atom.
    */
      void
      u2_ux_rite(u2_ray      ral_r,
                 const c3_c* paf_c,
                 const c3_c* ext_c);
