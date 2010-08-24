/* z/op/push.c
**
** This file is in the public domain.
*/
#   define _zn_bip_push(field) *_zn_anvil(z, bip_ray, push, field)

    /* c3__push: push to a static formula.
    */
      case c3__push: {
        u3_ray mat_ray = _zn_bip_push(f.r.mat_ray);
        u3_ray lid_ray = _zn_bip_push(f.c.lid_ray);
        u3_fox dep     = _zn_bip_push(f.s.dep);
        u3_fox lan     = _zn_bip_push(f.s.lan);
        u3_fox gus     = _zn_bip_push(d.gus);
        u3_fox mal;
        
        mal = u3_ln_cell(z, gus, lan);
        _zn_retreat(z, mat_ray);

        _zn_forge_cook(z, lid_ray, mal, dep);

        break;
      }
