/* x/op/mate.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_mate(): install a mate agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   bus: subject
**   feg: then formula
**   paf: else formula
*/
static inline void
_xn_forge_mate(u3_x x,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox pod)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, mate);
  *_xn_forge(x, xos_ray, mate, c.ger_op) = c3__mate;
  *_xn_forge(x, xos_ray, mate, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, mate, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, mate, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, mate, r.lip_ray) = lip_ray;

  *_xn_forge(x, xos_ray, mate, s.pod) = pod;
  
  x->n.lab_ray = xos_ray;
}

#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_mate(field) *_xn_anvil(x, bip_ray, mate, field)

  case c3__mate: {
    _xn_retreat(x, _xn_bip_mate(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_mate(f.c.lid_ray);
      u3_fox pod     = _xn_bip_mate(f.s.pod);
      u3_fox gus     = _xn_bip_mate(d.gus);

      if ( u3_yes == u3_lr_sing(x, pod, gus) ) {
        _xn_complete(x, lid_ray, pod);
      }
      else {
        printf("mate: jet mismatch\n");

        u3_b_print(&x->l, "hard", pod);
        u3_b_print(&x->l, "soft", gus);

        return c3__fail;
      }
    }
    break;
  }

#endif  // U3_ZN_OP
