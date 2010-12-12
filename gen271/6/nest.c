/* j/6/nest.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  /* forward
  */
    static u2_flag
    _nest_sint(u2_wire, u2_noun, u2_noun, u2_noun);
  /*
  */

  static u2_flag
  _nest_dext(u2_wire wir_r,
             u2_noun gil,
             u2_noun sut,
             u2_noun bon)
  {
    u2_noun p_sut, q_sut, r_sut, p_bon, q_bon, r_bon;

    if ( (u2_yes == u2_sing(sut, bon)) ) {
      return u2_yes;
    }
     
    if ( (u2_no == u2_dust(sut)) ) switch ( sut ) {
      default: return u2_bl_bail(wir_r);

      case c3__atom: {
        if ( c3__atom == bon ) {
          return u2_yes;
        } else if ( (u2_yes == u2_dust(bon)) && (c3__cube == u2_h(bon)) ) {
          return u2_stud(u2_t(bon));
        }
        else return _nest_sint(wir_r, gil, sut, bon);
      }
      case c3__blot: {
        return _nest_sint(wir_r, gil, sut, bon);
      }
      case c3__blur: {
        return u2_yes;
      }
    }
    else switch ( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( (u2_no == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          return u2_bl_bail(wir_r);
        } else {
          if ( u2_yes == u2_as_pq(bon, c3__cell, &p_bon, &q_bon) ) {
            return u2_and(_nest_dext(wir_r, gil, p_sut, p_bon),
                          _nest_dext(wir_r, gil, q_sut, q_bon));
          }
          else return _nest_sint(wir_r, gil, sut, bon);
        }
      }
      case c3__core: {
        if ( u2_no == u2_mean(sut, 6, &p_sut, 14, &q_sut, 15, &r_sut, 0) ) {
          return u2_bl_bail(wir_r);
        } else {
          if ( (u2_yes == u2_as_pqr(bon, c3__core, &p_bon, &q_bon, &r_bon)) ) {
            return u2_and
              (u2_sing(q_sut, q_bon),
               u2_and
                (u2_sing(r_sut, r_bon),
                 u2_and
                  (_nest_dext(wir_r, gil, p_sut, p_bon),
                   _nest_dext(wir_r, gil, q_sut, q_bon))));
          }
          else return _nest_sint(wir_r, gil, sut, bon);
        }
      }
      case c3__cube: {
        p_sut = u2_t(sut);
        {
          if ( u2_yes == u2_as_p(bon, c3__cube, &p_bon) ) {
            return u2_sing(p_sut, p_bon);
          }
          else return _nest_sint(wir_r, gil, sut, bon);
        }
      }
      case c3__face: {
        if ( (u2_no == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return _nest_dext(wir_r, gil, q_sut, bon);
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          if ( u2_yes == u2_dust(bon) ) switch ( bon ) {
            default: return _nest_sint(wir_r, gil, sut, bon);

            case c3__atom:
            case c3__blur:
              break;
          }
          else switch ( u2_h(bon) ) {
            default: return _nest_sint(wir_r, gil, sut, bon);
            
            case c3__cell: 
            case c3__cube:
            case c3__core:
              break;
          }
          return u2_or(_nest_dext(wir_r, gil, p_sut, bon),
                       _nest_dext(wir_r, gil, q_sut, bon));
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun hud = u2_bc(wir_r, sut, bon);

          if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, gil, hud)) ) {
            u2_rl_lose(wir_r, hud);

            return u2_yes;
          } else {
            u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, gil, hud);
            u2_type fop = j2_mcc(Pit, vane, play)(wir_r, p_sut, q_sut);
            u2_flag hiv = _nest_dext(wir_r, zoc, fop, bon);

            u2_rl_lose(wir_r, hud);
            u2_rl_lose(wir_r, fop);
            u2_rl_lose(wir_r, zoc);

            return hiv;
          }
        }
      }
    }
  }
  static u2_flag
  _nest_sint(u2_wire wir_r,
             u2_noun gil,
             u2_noun sut,
             u2_noun bon)
  {
    u2_noun p_bon, q_bon, r_bon;

    if ( (u2_no == u2_dust(bon)) ) {
      switch ( bon ) {
        default: return u2_bl_bail(wir_r);

        case c3__atom: return u2_no;
        case c3__blot: return u2_yes;
        case c3__blur: return u2_no;
      }
    }
    else {
      switch ( u2_h(bon) ) {
        default: return u2_bl_bail(wir_r);

        case c3__cell: {
          return u2_no;
        }
        case c3__core: {
          if ( (u2_yes == 
                u2_mean(bon, 6, &p_bon, 14, &q_bon, 15, &r_bon, 0)) ) 
          {
            u2_noun fug = u2_bt(wir_r, c3__cell, p_bon, c3__blur);
            u2_flag hiv = _nest_dext(wir_r, gil, sut, fug);
            
            u2_rl_lose(wir_r, fug);
            return hiv;
          }
          else return u2_bl_bail(wir_r);
        }
        case c3__cube: {
          p_bon = u2_t(bon);

          if ( u2_no == u2_dust(p_bon) ) {
            return u2_no;
          } else {
            u2_noun fug = u2_bt(wir_r, c3__cell, 
                                       u2_bc(wir_r, c3__cube, u2_h(p_bon)),
                                       u2_bc(wir_r, c3__cube, u2_t(p_bon)));
            u2_flag hiv = _nest_dext(wir_r, gil, sut, fug);
 
            u2_rl_lose(wir_r, fug);
            return hiv;
          }
        }
        case c3__face: {
          if ( (u2_yes == u2_mean(bon, 6, &p_bon, 7, &q_bon, 0)) ) {
            return _nest_dext(wir_r, gil, sut, q_bon);
          }
          else return u2_bl_bail(wir_r);
        }
        case c3__fork: {
          if ( (u2_yes == u2_mean(bon, 6, &p_bon, 7, &q_bon, 0)) ) {
            return u2_and(_nest_dext(wir_r, gil, sut, p_bon),
                          _nest_dext(wir_r, gil, sut, q_bon));
          }
          else return u2_bl_bail(wir_r);
        } 
        case c3__hold: {
          if ( (u2_yes == u2_mean(bon, 6, &p_bon, 7, &q_bon, 0)) ) {
            u2_noun hud = u2_bc(wir_r, sut, bon);

            if ( (u2_yes == j2_mcc(Pit, in, has)(wir_r, gil, hud)) ) {
              u2_rl_lose(wir_r, hud);

              return u2_yes;
            } else {
              u2_noun zoc = j2_mcc(Pit, in, put)(wir_r, gil, hud);
              u2_type gam = j2_mcc(Pit, vane, play)(wir_r, p_bon, q_bon);
              u2_flag hiv = _nest_dext(wir_r, zoc, sut, gam);

              u2_rl_lose(wir_r, hud);
              u2_rl_lose(wir_r, gam);
              u2_rl_lose(wir_r, zoc);

              return hiv;
            }
          }
          else return u2_bl_bail(wir_r);
        }
      }
    }
  }
  
  u2_weak                                                         //  transfer
  j2_mcc(Pit, vane, nest)(u2_wire wir_r, 
                          u2_noun sut,                            //  retain
                          u2_noun bon)                            //  retain
  {
    return _nest_dext(wir_r, u2_nul, sut, bon);
  }
  u2_weak                                                         //  transfer
  j2_mc(Pit, vane, nest)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, bon;

    if ( u2_no == u2_mean(cor, 20, &sut, 9, &bon, 0) ) {
      return u2_none;
    } else {
      return j2_mcc(Pit, vane, nest)(wir_r, sut, bon);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, nest)[] = {
    { ".3", j2_mc(Pit, vane, nest), u2_no, u2_none, u2_none },
    { }
  };
