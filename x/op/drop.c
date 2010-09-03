/* x/op/drop.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_drop(): install a drop agent.
**
**   lid: cap at termination
*/
static inline void
_xn_forge_drop(u3_x   x,
               u3_ray lid_ray)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, drop);
  *_xn_forge(x, xos_ray, drop, c.ger_op) = c3__drop;
  *_xn_forge(x, xos_ray, drop, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, drop, c.lid_ray) = lid_ray;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_drop(field) *_xn_anvil(x, bip_ray, drop, field)

  case c3__drop: {
    u3_fox gus = _xn_bip_drop(d.gus);

    _xn_complete(x, _xn_bip_drop(f.c.lid_ray), gus);
    break;
  }

#endif  // U3_ZN_OP
