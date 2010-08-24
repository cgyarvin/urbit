/* z/op/jet.c
**
** This file is in the public domain.
*/
#   define _zn_bip_jet(field) *_zn_anvil(z, bip_ray, jet, field)

    /* c3__jet: jet to a static formula.
    */
      case c3__jet: {
        _zn_retreat(z, _zn_bip_jet(f.r.mat_ray));
        {
          /* sax: jet code
          ** gus: computed gate
          ** zec: result code
          ** pod: result
          */
          u3_ray  lid_ray = _zn_bip_jet(f.c.lid_ray);
          u3_fox  sax     = _zn_bip_jet(f.s.sax_w);
          u3_fox  gus     = _zn_bip_jet(d.gus);
          u3_mote zec;
          u3_fox  pod;

          if ( u3_yes == u3_lr_dust(z, gus) ) {
            zec = u3_zj_fire(z, &pod, sax, gus);
          } 
          else zec = c3__punt;

          switch ( zec ) {
            case 0: 
              _zn_complete(z, lid_ray, pod);
              break;

            case c3__fail:
            case c3__exit:
              return zec;
 
            case c3__punt: {
              u3_fox bat = u3_zj_bat(z, sax);

              _zn_forge_cook(z, lid_ray, gus, bat);
              break;
            }
            case c3__test: {
              u3_fox bat = u3_zj_bat(z, sax);

              _zn_start_mate(z, lid_ray, pod, gus, bat);
              break;
            }
            default: c3_assert(!"unknown error");
          }
        }
        break;
      }
