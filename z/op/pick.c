/* z/op/pick.c
**
** This file is in the public domain.
*/
#   define _zn_bip_pick(field) *_zn_anvil(z, ray_bip, pick, field)

    /* u3_cm_pick: pick to a static formula.
    */
      case u3_cm_pick: {
        _zn_retreat(z, _zn_bip_pick(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_pick(f.c.ray_lid);
          u3_ray ray_lip = _zn_bip_pick(f.r.ray_lip);
          u3_fox lan     = _zn_bip_pick(f.s.lan);
          u3_fox feg     = _zn_bip_pick(f.s.feg);
          u3_fox paf     = _zn_bip_pick(f.s.paf);
          u3_fox gus     = _zn_bip_pick(d.gus);

          if ( 0 == gus ) {
            u3_assert(ray_lip == z->l.ray_cap);

            _zn_forge_cook(z, ray_lid, lan, feg); 
          }
          else if ( 1 == gus ) {
            u3_assert(ray_lip == z->l.ray_cap);

            _zn_forge_cook(z, ray_lid, lan, paf); 
          }
          else {
            return u3_cm_exit;
          }
        }
        break;
      }
