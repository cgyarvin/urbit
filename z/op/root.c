/* z/op/cons.c
**
** This file is in the public domain.
*/
#   define _zn_bip_root(field) *_zn_anvil(z, ray_bip, root, field)

    /* c3__eq: equal
    */
      case c3__eq: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);

          if ( u3_no == u3_lr_dust(z, gus) ) {
            return c3__exit;
          } else {
            u3_fox fal = u3_lr_sing(z, u3_h(z, gus), u3_t(z, gus));

            _zn_complete(z, ray_lid, fal);
          }
        }
        break;
      }

    /* c3__goto: goto.
    */
      case c3__goto: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);

          if ( u3_no == u3_lr_dust(z, gus) ) {
            return c3__exit;
          } else {
            /* lan: subject
            ** sef: formula
            */
            u3_fox lan = u3_h(z, gus);
            u3_fox sef = u3_t(z, gus);

            _zn_forge_cook(z, ray_lid, lan, sef);
          }
        }
        break;
      }

    /* c3__inc: increment
    */
      case c3__inc: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);

          if ( u3_no == u3_lr_stud(z, gus) ) {
            return c3__exit;
          } else {
            mpz_t  mp_gus;
            u3_fox fal;
           
            u3_lr_mp(z, mp_gus, gus);
            mpz_add_ui(mp_gus, mp_gus, 1);
            fal = u3_ln_mp(z, mp_gus);

            _zn_complete(z, ray_lid, fal);
          }
        }
        break;
      }

    /* c3__tap: probe
    */
      case c3__tap: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);
          u3_fox fal     = u3_lr_dust(z, gus);

          _zn_complete(z, ray_lid, fal);
        }
        break;
      }
