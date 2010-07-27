/* z/op/cook.c
**
** This file is in the public domain.
*/
#   define _zn_bip_cook(field) *_zn_anvil(z, ray_bip, cook, field)

    /* u3_cm_cook: compute nock.
    */
      case u3_cm_cook: {
        /* lid: destination cap.
        */
        u3_ray ray_lid = _zn_bip_cook(f.c.ray_lid);
        u3_fox lan     = _zn_bip_cook(f.s.lan);
        u3_fox sef     = _zn_bip_cook(f.s.sef);

        if ( u3_no == u3_lr_tap(z, sef) ) {
          return u3_cm_exit;
        }
        else {
          u3_fox hib = u3_h(z, sef);
          u3_fox fus = u3_t(z, sef);

          if ( u3_yes == u3_lr_tap(g, hib) ) {
            _zn_forge_cons(z, ray_lid);
            _zn_forge_tail(z, z->l.ray_cap, lan, fus);
            _zn_forge_cook(z, z->l.ray_cap, lan, hib);
          }
          else {
            switch ( hib ) {
              default: return u3_cm_exit;

              case 0: {
                u3_fox pob = u3_lr_twig(z, fus, lan);

                if ( u3_none == pob ) {
                  return u3_cm_exit;
                }
                else {
                  u3_fox vik = u3_ln_ice(z, pob);

                  if ( u3_none == vik ) {
                    return u3_cm_fail;
                  }
                  else {
                    _zn_complete(z, ray_lid, vik);
                  }
                }
                break;
              }

              case 1: {
                u3_fox vik = u3_ln_ice(z, fus);

                if ( u3_none == vik ) {
                  return u3_cm_fail;
                }
                else {
                  _zn_complete(z, ray_lid, vik);
                }
                break;
              }

              case 2: _zn_start_goto(z, ray_lid, lan, fus); break;

              case 3: _zn_start_root(z, u3_cm_tap, ray_lid, lan, fus); break;
              case 4: _zn_start_root(z, u3_cm_inc, ray_lid, lan, fus); break;
              case 5: _zn_start_root(z, u3_cm_eq,  ray_lid, lan, fus); break;

              case 6: {
                if ( u3_no == u3_lr_tap(z, fus) ) {
                  return u3_cm_exit;
                } 
                else {
                  u3_fox p_fus = u3_h(z, fus);
                  u3_fox qr_fus = u3_t(z, fus);

                  if ( u3_no == u3_lr_tap(z, qr_fus) ) {
                    return u3_cm_exit;
                  }
                  else {
                    u3_fox q_fus = u3_h(z, qr_fus);
                    u3_fox r_fus = u3_t(z, qr_fus);

                    _zn_start_pick(z, ray_lid, lan, p_fus, q_fus, r_fus);
                  }
                }
                break;
              }

              case 7: {
                if ( u3_no == u3_lr_tap(z, fus) ) {
                  return u3_cm_exit;
                }
                else {
                  _zn_start_link(z, ray_lid, lan, u3_h(z, fus), u3_t(z, fus));
                  break;
                }
              }
              case 8: {
                if ( u3_no == u3_lr_tap(z, fus) ) {
                  return u3_cm_exit;
                }
                else {
                  _zn_start_push(z, ray_lid, lan, u3_h(z, fus), u3_t(z, fus));
                  break;
                }
              }
              case 11: {
                if ( u3_no == u3_lr_tap(z, fus) ) {
                  return u3_cm_exit;
                }
                else {
                  _zn_forge_cook(z, z->l.ray_cap, lan, u3_t(z, fus));
                }
              }
              case 12: {
                if ( u3_no == u3_lr_tap(z, fus) ) {
                  return u3_cm_exit;
                }
                else {
                  u3_fox vik = u3_ln_ice(z, u3_t(z, fus));

                  if ( u3_none == vik ) {
                    return u3_cm_fail;
                  }
                  else {
                    u3_fox cor = u3_ln_cell(z, lan, vik);
                    u3_fox pup = u3_h(z, fus);

                    if ( 0 != pup ) {
                      u3_zj_load(z, pup, cor);
                    }
                    _zn_complete(z, ray_lid, u3_ln_cell(z, lan, vik));
                  }
                  break;
                }
              }
            }
          }
        }
        break;
      }
