/* z/op/push.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _zn_forge_push(): install a push agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: push formula.
*/
static inline void
_zn_forge_push(u3_z   z,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
               u3_fox dep)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, push);
  *_zn_forge(z, zos_ray, push, c.ger_op) = c3__push;
  *_zn_forge(z, zos_ray, push, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, push, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, push, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, push, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, push, s.bus) = bus;
  *_zn_forge(z, zos_ray, push, s.dep) = dep;

  z->n.lab_ray = zos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _zn_bip_push(field) *_zn_anvil(z, bip_ray, push, field)

  case c3__push: {
    u3_ray mat_ray = _zn_bip_push(f.r.mat_ray);
    u3_ray lid_ray = _zn_bip_push(f.c.lid_ray);
    u3_fox dep     = _zn_bip_push(f.s.dep);
    u3_fox bus     = _zn_bip_push(f.s.bus);
    u3_fox gus     = _zn_bip_push(d.gus);
    u3_fox mal;
    
    mal = u3_ln_cell(z, gus, bus);
    _zn_retreat(z, mat_ray);

    _zn_forge_cook(z, lid_ray, mal, dep);

    break;
  }

#endif  // U3_ZN_OP
