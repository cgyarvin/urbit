/* x/op/fine.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_fine(): install a fine agent.
**
**   lid: cap at termination
*/
static inline void
_xn_forge_fine(u3_x   x,
               u3_ray lid_ray)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, fine);
  *_xn_forge(x, xos_ray, fine, c.ger_op) = c3__fine;
  *_xn_forge(x, xos_ray, fine, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, fine, c.lid_ray) = lid_ray;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_fine(field) *_xn_anvil(x, bip_ray, fine, field)

  case c3__fine: {
    u3_fox gus = _xn_bip_fine(d.gus);

    *a = gus;
    if ( d ) {
      d->cop_w = x->l.cop_w;
    }
    return 0;
  }

#endif  // U3_ZN_OP
