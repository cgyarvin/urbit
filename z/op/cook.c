/* z/op/cook.c
**
** This file is in the public domain.
*/
#   define _zn_bip_cook(field) *_zn_anvil(z, ray_bip, cook, field)

    /* c3__cook: compute nock.
    */
      case c3__cook: {
        /* lid: destination cap.
        */
        u3_ray ray_lid = _zn_bip_cook(f.c.ray_lid);
        u3_fox lan     = _zn_bip_cook(f.s.lan);
        u3_fox sef     = _zn_bip_cook(f.s.sef);

        if ( u3_no == u3_lr_dust(z, sef) ) {
          return c3__exit;
        }
        else {
          u3_fox hib = u3_h(z, sef);
          u3_fox fus = u3_t(z, sef);

          if ( u3_yes == u3_lr_dust(z, hib) ) {
            _zn_forge_cons(z, ray_lid);
            _zn_forge_tail(z, z->l.ray_cap, lan, fus);
            _zn_forge_cook(z, z->l.ray_cap, lan, hib);
          }
          else {
            switch ( hib ) {
              default: return c3__exit;

              case 0: {
                u3_fox pob = u3_lr_twig(z, fus, lan);

                if ( u3_none == pob ) {
                  return c3__exit;
                }
                else {
                  u3_fox vik = u3_ln_ice(z, pob);

                  if ( u3_none == vik ) {
                    return c3__fail;
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
                  return c3__fail;
                }
                else {
                  _zn_complete(z, ray_lid, vik);
                }
                break;
              }

              case 2: _zn_start_goto(z, ray_lid, lan, fus); break;

              case 3: _zn_start_root(z, c3__tap, ray_lid, lan, fus); break;
              case 4: _zn_start_root(z, c3__inc, ray_lid, lan, fus); break;
              case 5: _zn_start_root(z, c3__eq,  ray_lid, lan, fus); break;

              case 6: {
                if ( u3_no == u3_lr_dust(z, fus) ) {
                  return c3__exit;
                } 
                else {
                  u3_fox p_fus = u3_h(z, fus);
                  u3_fox qr_fus = u3_t(z, fus);

                  if ( u3_no == u3_lr_dust(z, qr_fus) ) {
                    return c3__exit;
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
                if ( u3_no == u3_lr_dust(z, fus) ) {
                  return c3__exit;
                }
                else {
                  _zn_start_link(z, ray_lid, lan, u3_h(z, fus), u3_t(z, fus));
                  break;
                }
              }
              case 8: {
                if ( u3_no == u3_lr_dust(z, fus) ) {
                  return c3__exit;
                }
                else {
                  _zn_start_push(z, ray_lid, lan, u3_h(z, fus), u3_t(z, fus));
                  break;
                }
              }
              case 11: {
                if ( u3_no == u3_lr_dust(z, fus) ) {
                  return c3__exit;
                }
                else {
                  _zn_forge_cook(z, z->l.ray_cap, lan, u3_t(z, fus));
                }
              }
              case 12: {
                if ( u3_no == u3_lr_dust(z, fus) ) {
                  return c3__exit;
                }
                else {
                  u3_fox vik = u3_ln_ice(z, u3_t(z, fus));

                  if ( u3_none == vik ) {
                    return c3__fail;
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
