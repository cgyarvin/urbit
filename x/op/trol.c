/* x/op/trol.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_trol(): install a trol agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   bus: subject
**   feg: then formula
**   paf: else formula
*/
static inline void
_xn_forge_trol(u3_x x,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, trol);
  *_xn_forge(x, xos_ray, trol, c.ger_op) = c3__trol;
  *_xn_forge(x, xos_ray, trol, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, trol, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, trol, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, trol, r.lip_ray) = lip_ray;

  *_xn_forge(x, xos_ray, trol, s.bus) = bus;
  *_xn_forge(x, xos_ray, trol, s.feg) = feg;
  *_xn_forge(x, xos_ray, trol, s.paf) = paf;
  
  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_trol(field) *_xn_anvil(x, bip_ray, trol, field)

  case c3__trol: {
    _xn_retreat(x, _xn_bip_trol(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_trol(f.c.lid_ray);
      u3_ray lip_ray = _xn_bip_trol(f.r.lip_ray);
      u3_fox bus     = _xn_bip_trol(f.s.bus);
      u3_fox feg     = _xn_bip_trol(f.s.feg);
      u3_fox paf     = _xn_bip_trol(f.s.paf);
      u3_fox gus     = _xn_bip_trol(d.gus);

      if ( 0 == gus ) {
        c3_assert(lip_ray == x->l.cap_ray);

        _xn_forge_nock(x, lid_ray, bus, feg); 
      }
      else if ( 1 == gus ) {
        c3_assert(lip_ray == x->l.cap_ray);

        _xn_forge_nock(x, lid_ray, bus, paf); 
      }
      else {
        return c3__exit;
      }
    }
    break;
  }

#endif  // U3_ZN_OP
