/* z/op/pick.c
**
** This file is in the public domain.
*/
#   define _zn_bip_pick(field) *_zn_anvil(z, bip_ray, pick, field)

    /* c3__pick: pick to a static formula.
    */
      case c3__pick: {
        _zn_retreat(z, _zn_bip_pick(f.r.mat_ray));
        {
          u3_ray lid_ray = _zn_bip_pick(f.c.lid_ray);
          u3_ray lip_ray = _zn_bip_pick(f.r.lip_ray);
          u3_fox lan     = _zn_bip_pick(f.s.lan);
          u3_fox feg     = _zn_bip_pick(f.s.feg);
          u3_fox paf     = _zn_bip_pick(f.s.paf);
          u3_fox gus     = _zn_bip_pick(d.gus);

          if ( 0 == gus ) {
            c3_assert(lip_ray == z->l.cap_ray);

            _zn_forge_cook(z, lid_ray, lan, feg); 
          }
          else if ( 1 == gus ) {
            c3_assert(lip_ray == z->l.cap_ray);

            _zn_forge_cook(z, lid_ray, lan, paf); 
          }
          else {
            return c3__exit;
          }
        }
        break;
      }
