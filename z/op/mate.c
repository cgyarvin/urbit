/* z/op/mate.c
**
** This file is in the public domain.
*/
#   define _zn_bip_mate(field) *_zn_anvil(z, bip_ray, mate, field)

    /* c3__mate: mate to a static formula.
    */
      case c3__mate: {
        _zn_retreat(z, _zn_bip_mate(f.r.mat_ray));
        {
          u3_ray lid_ray = _zn_bip_mate(f.c.lid_ray);
          u3_fox pod     = _zn_bip_mate(f.s.pod);
          u3_fox gus     = _zn_bip_mate(d.gus);

          if ( u3_yes == u3_lr_sing(z, pod, gus) ) {
            _zn_complete(z, lid_ray, pod);
          }
          else {
            printf("mate: jet mismatch\n");

            u3_b_print(&z->l, "hard", pod);
            u3_b_print(&z->l, "soft", gus);

            return c3__fail;
          }
        }
        break;
      }
