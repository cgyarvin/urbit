/* x/op/hint.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_hint(): install a hint agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: content formula.
*/
static inline void
_xn_forge_hint(u3_x   x,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
               u3_fox dep)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, hint);
  *_xn_forge(x, xos_ray, hint, c.ger_op) = c3__hint;
  *_xn_forge(x, xos_ray, hint, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, hint, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, hint, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, hint, r.lip_ray) = lip_ray;

  *_xn_forge(x, xos_ray, hint, s.bus) = bus;
  *_xn_forge(x, xos_ray, hint, s.dep) = dep;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_hint(field) *_xn_anvil(x, bip_ray, hint, field)

  case c3__hint: {
    _xn_retreat(x, _xn_bip_hint(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_hint(f.c.lid_ray);
      u3_fox bus     = _xn_bip_hint(f.s.bus);
      u3_fox dep     = _xn_bip_hint(f.s.dep);
      u3_fox gus     = _xn_bip_hint(d.gus);

      if ( u3_no == u3_lr_dust(x, gus) ) {
        _xn_forge_nock(x, lid_ray, bus, dep);
      }
      else { 
        u3_fox p_gus, q_gus;

        if ( (u3_yes == u3_lr_pq(x, gus, c3__bask, &p_gus, &q_gus)) &&
             u3_rat_is_cat(p_gus) &&
             u3_rat_is_cat(q_gus) &&
             (q_gus > 0) &&
             (p_gus > 0) &&
             (p_gus < q_gus) )
        {
          if ( _xn_forge_bask(x, lid_ray, p_gus, q_gus) ) {
            _xn_forge_nock(x, x->l.cap_ray, bus, dep);
          } else {
            _xn_forge_nock(x, lid_ray, bus, dep);
          }
        }
        else if ( u3_yes == u3_lr_p(x, gus, c3__blog, &p_gus) ) {
          u3_b_print(x, "log", u3_t(x, gus));
        }
        else {
          _xn_forge_nock(x, lid_ray, bus, dep);
        }
      }
    }
    break;
  }

#endif  // U3_ZN_OP
