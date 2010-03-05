/* z/op/fine.c
**
** This file is in the public domain.
*/
    /* u3_cm_fine: finish computation.
    */
#     define _zn_bip_fine(field) *_zn_anvil(z, ray_bip, fine, field)

      case u3_cm_fine: {
        u3_fox gus = _zn_bip_fine(d.gus);

        *a = gus;
        if ( d ) {
          d->w_cop = z->l.w_cop;
        }
        return 0;
      }
