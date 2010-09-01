/* z/op/pick.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _zn_forge_pick(): install a pick agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   bus: subject
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_forge_pick(u3_z z,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, pick);
  *_zn_forge(z, zos_ray, pick, c.ger_op) = c3__pick;
  *_zn_forge(z, zos_ray, pick, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, pick, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, pick, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, pick, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, pick, s.bus) = bus;
  *_zn_forge(z, zos_ray, pick, s.feg) = feg;
  *_zn_forge(z, zos_ray, pick, s.paf) = paf;
  
  z->n.lab_ray = zos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _zn_bip_pick(field) *_zn_anvil(z, bip_ray, pick, field)

  case c3__pick: {
    _zn_retreat(z, _zn_bip_pick(f.r.mat_ray));
    {
      u3_ray lid_ray = _zn_bip_pick(f.c.lid_ray);
      u3_ray lip_ray = _zn_bip_pick(f.r.lip_ray);
      u3_fox bus     = _zn_bip_pick(f.s.bus);
      u3_fox feg     = _zn_bip_pick(f.s.feg);
      u3_fox paf     = _zn_bip_pick(f.s.paf);
      u3_fox gus     = _zn_bip_pick(d.gus);

      if ( 0 == gus ) {
        c3_assert(lip_ray == z->l.cap_ray);

        _zn_forge_nock(z, lid_ray, bus, feg); 
      }
      else if ( 1 == gus ) {
        c3_assert(lip_ray == z->l.cap_ray);

        _zn_forge_nock(z, lid_ray, bus, paf); 
      }
      else {
        return c3__exit;
      }
    }
    break;
  }

#endif  // U3_ZN_OP
