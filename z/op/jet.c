/* z/op/jet.c
**
** This file is in the public domain.
*/
#   define _zn_bip_jet(field) *_zn_anvil(z, ray_bip, jet, field)

    /* u3_cm_jet: jet to a static formula.
    */
      case u3_cm_jet: {
        _zn_retreat(z, _zn_bip_jet(f.r.ray_mat));
        {
          /* sax: jet code
          ** gus: computed gate
          ** zec: result code
          ** pod: result
          */
          u3_ray  ray_lid = _zn_bip_jet(f.c.ray_lid);
          u3_fox  sax     = _zn_bip_jet(f.s.w_sax);
          u3_fox  gus     = _zn_bip_jet(d.gus);
          u3_mote zec;
          u3_fox  pod;

          if ( u3_yes == u3_lr_tap(z, gus) ) {
            zec = u3_zj_fire(z, &pod, sax, gus);
          } 
          else zec = u3_cm_punt;

          switch ( zec ) {
            case 0: 
              _zn_complete(z, ray_lid, pod);
              break;

            case u3_cm_fail:
            case u3_cm_exit:
              return zec;
 
            case u3_cm_punt: {
              u3_fox bat = u3_zj_bat(z, sax);

              _zn_forge_cook(z, ray_lid, gus, bat);
              break;
            }
            case u3_cm_test: {
              u3_fox bat = u3_zj_bat(z, sax);

              _zn_start_mate(z, ray_lid, pod, gus, bat);
              break;
            }
            default: u3_assert(!"unknown error");
          }
        }
        break;
      }
