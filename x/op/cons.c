/* x/op/cons.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_cons(): install a cons agent.
**
**   lid: cap at termination
*/
static inline void
_xn_forge_cons(u3_x   x,
               u3_ray lid_ray)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, cons);
  *_xn_forge(x, xos_ray, cons, c.ger_op) = c3__cons;
  *_xn_forge(x, xos_ray, cons, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, cons, c.lid_ray) = lid_ray;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_cons(field) *_xn_anvil(x, bip_ray, cons, field)

  case c3__cons: {
    u3_fox pux = _xn_bip_cons(d.pux);
    u3_fox nol = _xn_bip_cons(d.nol);
    u3_fox mal;
   
    /* We know this will succeed because we prereserve in the 
    ** main loop.
    */
    mal = u3_ln_cell(x, pux, nol);

    _xn_complete(x, _xn_bip_cons(f.c.lid_ray), mal);
    break;
  }

#endif  // U3_ZN_OP
