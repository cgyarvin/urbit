/* z/op/cons.c
**
** This file is in the public domain.
*/
#   define _zn_bip_root(field) *_zn_anvil(z, ray_bip, root, field)

    /* u3_cm_eq: equal
    */
      case u3_cm_eq: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);

          if ( u3_no == u3_lr_tap(z, gus) ) {
            return u3_cm_exit;
          } else {
            u3_fox fal = u3_lr_eq(z, u3_h(z, gus), u3_t(z, gus));

            _zn_complete(z, ray_lid, fal);
          }
        }
        break;
      }

    /* u3_cm_goto: goto.
    */
      case u3_cm_goto: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);

          if ( u3_no == u3_lr_tap(z, gus) ) {
            return u3_cm_exit;
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

    /* u3_cm_inc: increment
    */
      case u3_cm_inc: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);

          if ( u3_no == u3_lr_pat(l, gus) ) {
            return u3_cm_exit;
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

    /* u3_cm_tap: probe
    */
      case u3_cm_tap: {
        _zn_retreat(z, _zn_bip_root(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_root(f.c.ray_lid);
          u3_fox gus     = _zn_bip_root(d.gus);
          u3_fox fal     = u3_lr_tap(z, gus);

          _zn_complete(z, ray_lid, fal);
        }
        break;
      }
