/* include/devl.h
**
** This file is in the public domain.
*/
    /* u2_loom_devl: development control.
    */
      typedef struct _u2_loom_devl {
        /* Maximum depth of C stack, in call records.
        */
        c3_w  stk_w;

        /* West base.
        */
        u2_ray wab_r;

        /* East base.
        */
        u2_ray eab_r;

        /* West watermark.
        */
        u2_ray wst_r;

        /* East watermark.
        */
        u2_ray est_r;
      } u2_loom_devl;

