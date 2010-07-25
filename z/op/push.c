/* z/op/push.c
**
** This file is in the public domain.
*/
#   define _zn_bip_push(field) *_zn_anvil(z, ray_bip, push, field)

    /* u3_cm_push: push to a static formula.
    */
      case u3_cm_push: {
        u3_ray ray_mat = _zn_bip_push(f.r.ray_mat);
        u3_ray ray_lid = _zn_bip_push(f.c.ray_lid);
        u3_fox dep     = _zn_bip_push(f.s.dep);
        u3_fox lan     = _zn_bip_push(f.s.lan);
        u3_fox gus     = _zn_bip_push(d.gus);
        u3_fox mal;
        
        mal = u3_ln_cell(z, gus, lan);
        _zn_retreat(z, ray_mat);

        _zn_forge_cook(z, ray_lid, mal, dep);

        break;
      }
