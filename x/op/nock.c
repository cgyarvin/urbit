/* x/op/nock.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_nock(): install a nock agent.
**
**   lid: cap at termination
**   bus: subject
**   sef: formula
*/
static inline void
_xn_forge_nock(u3_x x,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, nock);
  *_xn_forge(x, xos_ray, nock, c.ger_op) = c3__nock;
  *_xn_forge(x, xos_ray, nock, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, nock, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, nock, s.bus) = bus;
  *_xn_forge(x, xos_ray, nock, s.sef) = sef;
  
  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_nock(field) *_xn_anvil(x, bip_ray, nock, field)

  case c3__nock: {
    u3_ray lid_ray = _xn_bip_nock(f.c.lid_ray);
    u3_fox bus     = _xn_bip_nock(f.s.bus);
    u3_fox sef     = _xn_bip_nock(f.s.sef);

    if ( u3_no == u3_lr_dust(x, sef) ) {
      return c3__exit;
    }
    else {
      u3_fox hib = u3_h(x, sef);
      u3_fox fel = u3_t(x, sef);

      if ( u3_yes == u3_lr_dust(x, hib) ) {
        _xn_forge_cons(x, lid_ray);
        _xn_forge_tail(x, x->l.cap_ray, bus, fel);
        _xn_forge_nock(x, x->l.cap_ray, bus, hib);
      }
      else {
        switch ( hib ) {
          default: return c3__exit;

          case u3_nock_frag: {
            u3_fox pob = u3_lr_twig(x, fel, bus);

            if ( u3_none == pob ) {
              return c3__exit;
            }
            else {
              u3_fox vik = u3_ln_ice(x, pob);

              if ( u3_none == vik ) {
                return c3__fail;
              }
              else {
                _xn_complete(x, lid_ray, vik);
              }
            }
            break;
          }

          case u3_nock_bone: {
            u3_fox vik = u3_ln_ice(x, fel);

            if ( u3_none == vik ) {
              return c3__fail;
            }
            else {
              _xn_complete(x, lid_ray, vik);
            }
            break;
          }

          case u3_nock_sail: {
            _xn_start_sail(x, lid_ray, bus, fel); 
            break;
          }
          case u3_nock_dust: {
            _xn_start_root(x, c3__dust, lid_ray, bus, fel); 
            break;
          }
          case u3_nock_vint: {
            _xn_start_root(x, c3__vint, lid_ray, bus, fel); 
            break;
          }
          case u3_nock_sing: {
            _xn_start_root(x, c3__sing, lid_ray, bus, fel); 
            break;
          }
          case u3_nock_trol: {
            if ( u3_no == u3_lr_dust(x, fel) ) {
              return c3__exit;
            } 
            else {
              u3_fox p_fel = u3_h(x, fel);
              u3_fox qr_fel = u3_t(x, fel);

              if ( u3_no == u3_lr_dust(x, qr_fel) ) {
                return c3__exit;
              }
              else {
                u3_fox q_fel = u3_h(x, qr_fel);
                u3_fox r_fel = u3_t(x, qr_fel);

                _xn_start_trol(x, lid_ray, bus, p_fel, q_fel, r_fel);
              }
            }
            break;
          }

          case u3_nock_flac: {
            if ( u3_no == u3_lr_dust(x, fel) ) {
              return c3__exit;
            }
            else {
              _xn_start_flac
                (x, lid_ray, bus, u3_h(x, fel), u3_t(x, fel));
              break;
            }
          }
          case u3_nock_gant: {
            if ( u3_no == u3_lr_dust(x, fel) ) {
              return c3__exit;
            }
            else {
              _xn_start_gant
                (x, lid_ray, bus, u3_h(x, fel), u3_t(x, fel));
              break;
            }
          }
          case u3_nock_hint: {
            if ( u3_no == u3_lr_dust(x, fel) ) {
              return c3__exit;
            }
            else {
              _xn_start_hint
                (x, lid_ray, bus, u3_h(x, fel), u3_t(x, fel));
              break;
            }
          }
          case u3_nock_coat: {
            if ( u3_no == u3_lr_dust(x, fel) ) {
              return c3__exit;
            }
            else {
              u3_fox vik = u3_ln_ice(x, u3_t(x, fel));

              if ( u3_none == vik ) {
                return c3__fail;
              }
              else {
                u3_fox cor = u3_ln_cell(x, bus, vik);
                u3_fox pup = u3_h(x, fel);

                if ( 0 != pup ) {
                  u3_xj_load(x, pup, cor);
                }
                _xn_complete(x, lid_ray, u3_ln_cell(x, bus, vik));
              }
              break;
            }
          }
        }
      }
    }
    break;
  }
#endif  // U3_ZN_OP
