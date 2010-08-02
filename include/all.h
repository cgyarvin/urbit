/* include/all.h
**
** This file is in the public domain.
*/

  /** Internal includes.
  **/
    /** u3_c: the C layer.
    **/
#     include "c/portable.h"
#     include "c/types.h"
#     include "c/defs.h"
#     include "c/motes.h"

#       define u3_assert(x) u3_c_assert(x)
#       define u3_wiseof(x) u3_c_wiseof(x)
#       define u3_stub      u3_c_stub

    /** u3_l: the clam layer.
    **/
#     include "l.h"

      /* Shorthands from u3_g.
      */
        typedef u3_l_ray  u3_ray;
        typedef u3_l_rat  u3_rat;
        typedef u3_l_fox  u3_fox;
        typedef u3_l_atom u3_atom;
        typedef u3_l_flag u3_flag;
        typedef u3_l_mote u3_mote;
        typedef u3_l_list u3_list;

#       define u3_none u3_l_none
#       define u3_yes  u3_l_yes
#       define u3_no   u3_l_no

#       define u3_h(l, a) u3_lr_h(l, a)
#       define u3_t(l, a) u3_lr_t(l, a)

#       define u3_hh(l, a)  u3_h(l, u3_h(l, a))
#       define u3_ht(l, a)  u3_t(l, u3_h(l, a))
#       define u3_th(l, a)  u3_h(l, u3_t(l, a))
#       define u3_tt(l, a)  u3_t(l, u3_t(l, a))

#       define u3_hhh(l, a)  u3_h(l, u3_h(l, u3_h(l, a)))
#       define u3_hht(l, a)  u3_t(l, u3_h(l, u3_h(l, a)))
#       define u3_hth(l, a)  u3_h(l, u3_t(l, u3_h(l, a)))
#       define u3_htt(l, a)  u3_t(l, u3_t(l, u3_h(l, a)))
#       define u3_thh(l, a)  u3_h(l, u3_h(l, u3_t(l, a)))
#       define u3_tht(l, a)  u3_t(l, u3_h(l, u3_t(l, a)))
#       define u3_tth(l, a)  u3_h(l, u3_t(l, u3_t(l, a)))
#       define u3_ttt(l, a)  u3_t(l, u3_t(l, u3_t(l, a)))


    /** u3_b: boot assistance, from u4.  To be deleted.
    **/
#     include "b.h"

    /** u3_z: zeno, the interpreter.
    **/
#     include "z/machine.h"
#     include "z/agent.h"
#     include "z/jato.h"

#     define _zj_dry(nam, mug) 
#     define _zj_wet(nam, mug) \
        u3_fox u3_zx_##nam(u3_z, u3_fox);
#     include "z/jets.h"
#     undef _zj_dry
#     undef _zj_wet
