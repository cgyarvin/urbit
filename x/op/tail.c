/* x/op/tail.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_tail(): install a tail agent.
**
**   lid: cap at termination
**   bus: subject
**   fel: formula
*/
static inline void
_xn_forge_tail(u3_x   x,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox fel)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, tail);
  *_xn_forge(x, xos_ray, tail, c.ger_op) = c3__tail;
  *_xn_forge(x, xos_ray, tail, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, tail, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, tail, s.bus) = bus;
  *_xn_forge(x, xos_ray, tail, s.fel) = fel;
  
  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_tail(field) *_xn_anvil(x, bip_ray, tail, field)

  case c3__tail: {
    u3_fox gus = _xn_bip_tail(d.gus);
    u3_fox bus = _xn_bip_tail(f.s.bus);
    u3_fox fel = _xn_bip_tail(f.s.fel);

    /* Tricky: we push [gus] above the agent below,
    ** presumably a cons.
    */
    _xn_complete(x, _xn_bip_tail(f.c.lid_ray), gus);
    _xn_forge_nock(x, x->l.cap_ray, bus, fel);

    break;
  }

#endif  // U3_ZN_OP
