/* z/op/tail.c
**
** This file is in the public domain.
*/
#   define _zn_bip_tail(field) *_zn_anvil(z, ray_bip, tail, field)

    /* c3__tail: tail of a cons.
    */
      case c3__tail: {
        u3_fox gus = _zn_bip_tail(d.gus);
        u3_fox lan = _zn_bip_tail(f.s.lan);
        u3_fox fus = _zn_bip_tail(f.s.fus);

        /* Tricky: we push [gus] above the agent below,
        ** presumably a cons.
        */
        _zn_complete(z, _zn_bip_tail(f.c.ray_lid), gus);
        _zn_forge_cook(z, z->l.ray_cap, lan, fus);

        break;
      }
