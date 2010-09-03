/* x/op/root.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_root(): install a root agent.
**
**   ger: operation.
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
*/
static inline void
_xn_forge_root(u3_x       x,
               u3_xn_oper ger_op,
               u3_ray     lid_ray,
               u3_ray     mat_ray,
               u3_ray     lip_ray)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, root);
  *_xn_forge(x, xos_ray, root, c.ger_op) = ger_op;
  *_xn_forge(x, xos_ray, root, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, root, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, root, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, root, r.lip_ray) = lip_ray;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_root(field) *_xn_anvil(x, bip_ray, root, field)

  case c3__sing: {
    _xn_retreat(x, _xn_bip_root(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_root(f.c.lid_ray);
      u3_fox gus     = _xn_bip_root(d.gus);

      if ( u3_no == u3_lr_dust(x, gus) ) {
        return c3__exit;
      } else {
        u3_fox fal = u3_lr_sing(x, u3_h(x, gus), u3_t(x, gus));

        _xn_complete(x, lid_ray, fal);
      }
    }
    break;
  }
  case c3__sail: {
    _xn_retreat(x, _xn_bip_root(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_root(f.c.lid_ray);
      u3_fox gus     = _xn_bip_root(d.gus);

      if ( u3_no == u3_lr_dust(x, gus) ) {
        return c3__exit;
      } else {
        /* bus: subject
        ** sef: formula
        */
        u3_fox bus = u3_h(x, gus);
        u3_fox sef = u3_t(x, gus);

        _xn_forge_nock(x, lid_ray, bus, sef);
      }
    }
    break;
  }
  case c3__vint: {
    _xn_retreat(x, _xn_bip_root(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_root(f.c.lid_ray);
      u3_fox gus     = _xn_bip_root(d.gus);

      if ( u3_no == u3_lr_stud(x, gus) ) {
        return c3__exit;
      } else {
        mpz_t  mp_gus;
        u3_fox fal;
       
        u3_lr_mp(x, mp_gus, gus);
        mpz_add_ui(mp_gus, mp_gus, 1);
        fal = u3_ln_mp(x, mp_gus);

        _xn_complete(x, lid_ray, fal);
      }
    }
    break;
  }
  case c3__dust: {
    _xn_retreat(x, _xn_bip_root(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_root(f.c.lid_ray);
      u3_fox gus     = _xn_bip_root(d.gus);
      u3_fox fal     = u3_lr_dust(x, gus);

      _xn_complete(x, lid_ray, fal);
    }
    break;
  }

#endif  // U3_ZN_OP
