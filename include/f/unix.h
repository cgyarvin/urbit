/* include/unix.h
**
** This file is in the public domain.
*/
  /** Functions.
  **/
    /* u2_ux_read(): read a path/extension into an atom.
    */
      u2_weak
      u2_ux_read(u2_wire     wir_r,
                 const c3_c* paf_c,
                 const c3_c* ext_c);

    /* u2_ux_read_deep(): read a filesystem path as a generic noun.
    */
      u2_weak
      u2_ux_read_deep(u2_wire     wir_r,
                      const c3_c* paf_c,
                      const c3_c* ext_c);

    /* u2_ux_write(): write a path/extension as an atom.
    */
      u2_flag
      u2_ux_write(u2_wire     wir_r,
                  u2_atom     som,
                  const c3_c* paf_c,
                  const c3_c* ext_c);

    /* u2_ux_write_deep(): write a path/extension as a generic noun.
    */
      u2_flag
      u2_ux_write_deep(u2_wire     wir_r,
                       u2_noun     som,
                       const c3_c* paf_c,
                       const c3_c* ext_c);

    /* u2_ux_fresh(): true iff `oxt` is as fresh as `ext`.
    */
      u2_flag
      u2_ux_fresh(const c3_c* paf_c,
                  const c3_c* ext_c,
                  const c3_c* oxt_c);
