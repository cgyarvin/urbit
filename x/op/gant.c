/* x/op/gant.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_gant(): install a gant agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: gant formula.
*/
static inline void
_xn_forge_gant(u3_x   x,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
               u3_fox dep)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, gant);
  *_xn_forge(x, xos_ray, gant, c.ger_op) = c3__gant;
  *_xn_forge(x, xos_ray, gant, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, gant, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, gant, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, gant, r.lip_ray) = lip_ray;

  *_xn_forge(x, xos_ray, gant, s.bus) = bus;
  *_xn_forge(x, xos_ray, gant, s.dep) = dep;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_gant(field) *_xn_anvil(x, bip_ray, gant, field)

  case c3__gant: {
    u3_ray mat_ray = _xn_bip_gant(f.r.mat_ray);
    u3_ray lid_ray = _xn_bip_gant(f.c.lid_ray);
    u3_fox dep     = _xn_bip_gant(f.s.dep);
    u3_fox bus     = _xn_bip_gant(f.s.bus);
    u3_fox gus     = _xn_bip_gant(d.gus);
    u3_fox mal;
    
    mal = u3_ln_cell(x, gus, bus);
    _xn_retreat(x, mat_ray);

    _xn_forge_nock(x, lid_ray, mal, dep);

    break;
  }

#endif  // U3_ZN_OP
