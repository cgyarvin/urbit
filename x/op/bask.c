/* x/op/bask.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_bask(): install a basket sequence.
*/
static inline c3_b
_xn_forge_bask(u3_x    x,
               u3_ray  lid_ray,
               c3_w    num_w,
               c3_w    dem_w)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, bask);
  *_xn_forge(x, xos_ray, bask, c.ger_op) = c3__bask;
  *_xn_forge(x, xos_ray, bask, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, bask, c.lid_ray) = lid_ray;

  {
    c3_w lef_w = x->l.bat_nit - 
                 (u3_ray_b(x->l.hat_ray) + 
                  u3_ray_b(x->l.cap_ray) + 128);

    c3_w wor_w = num_w * (lef_w / dem_w);

    *_xn_forge(x, xos_ray, bask, s.wor_w) = wor_w;
    x->l.cap_ray += wor_w;
  }
  x->n.lab_ray = xos_ray;
  return 1;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_bask(field) *_xn_anvil(x, bip_ray, bask, field)

  case c3__bask: {
    c3_w   wor_w   = _xn_bip_bask(f.s.wor_w);
    u3_ray anv_ray = bip_ray + c3_wiseof(struct u3_xn_forge_bask) + wor_w;
    u3_fox gus     = *u3_at_ray(&x->l, anv_ray);

    _xn_complete(x, _xn_bip_bask(f.c.lid_ray), gus);
    break;
  }

#endif  // U3_ZN_OP
