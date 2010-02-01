/* z/op/cons.c
**
** This file is in the public domain.
*/
#   define _zn_bip_cons(field) *_zn_anvil(z, ray_bip, cons, field)

    /* u3_cm_cons: construct a pair.
    */
      case u3_cm_cons: {
        u3_fox pux = _zn_bip_cons(d.pux);
        u3_fox nol = _zn_bip_cons(d.nol);
        u3_fox mal;
       
        /* We know this will succeed because we prereserve in the 
        ** main loop.
        */
        mal = u3_ln_cell(z, pux, nol);

        _zn_complete(z, _zn_bip_cons(f.c.ray_lid), mal);
        break;
      }
