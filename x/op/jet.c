/* x/op/jet.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_jet(): install a jet agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   sax: jet code
*/
static inline void
_xn_forge_jet(u3_x            x,
              u3_ray          lid_ray,
              u3_ray          mat_ray,
              u3_ray          lip_ray,
              enum u3_xj_code sax_code)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, jet);
  *_xn_forge(x, xos_ray, jet, c.ger_op) = c3__jet;
  *_xn_forge(x, xos_ray, jet, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, jet, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, jet, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, jet, r.lip_ray) = lip_ray;

  *_xn_forge(x, xos_ray, jet, s.sax_w) = sax_code;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_jet(field) *_xn_anvil(x, bip_ray, jet, field)

  case c3__jet: {
    _xn_retreat(x, _xn_bip_jet(f.r.mat_ray));
    {
      /* sax: jet code
      ** gus: computed gate
      ** xec: result code
      ** pod: result
      */
      u3_ray  lid_ray = _xn_bip_jet(f.c.lid_ray);
      u3_fox  sax     = _xn_bip_jet(f.s.sax_w);
      u3_fox  gus     = _xn_bip_jet(d.gus);
      u3_mote xec;
      u3_fox  pod;

      if ( u3_yes == u3_lr_dust(x, gus) ) {
        xec = u3_xj_fire(x, &pod, sax, gus);
      } 
      else xec = c3__punt;

      switch ( xec ) {
        case 0: 
          _xn_complete(x, lid_ray, pod);
          break;

        case c3__fail:
        case c3__exit:
          return xec;

        case c3__punt: {
          u3_fox bat = u3_xj_bat(x, sax);

          _xn_forge_nock(x, lid_ray, gus, bat);
          break;
        }
        case c3__test: {
          u3_fox bat = u3_xj_bat(x, sax);

          _xn_start_mate(x, lid_ray, pod, gus, bat);
          break;
        }
        default: c3_assert(!"unknown error");
      }
    }
    break;
  }

#endif  // U3_ZN_OP
