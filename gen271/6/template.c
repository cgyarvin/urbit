/* j/6/temp.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"
#include "vane.h"

/* functions
*/
  /* forward
  */
  /*
  */

  u2_weak                                                         //  transfer
  j2_mcc(Pit, vane, temp)(u2_wire wir_r, 
                          u2_weak sut,                            //  retain
                          u2_weak bon)                            //  retain
  {
    if ( (u2_none == sut) || (u2_none == bon) ) {
      return u2_none;
    }
    else {
      switch ( sut ) {
        default: return u2_bl_bail(wir_r);

        case c3__atom: {
        }
        case c3__blot: {
        }
        case c3__blur: {
        }
      }
    }
    else {
      u2_noun p_sut, q_sut, r_sut, p_bon, q_bon, r_bon;

      switch ( u2_h(sut) ) {
        default: return u2_bl_bail(wir_r);

        case c3__cell: {
          if ( (u2_yes == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          }
          else return u2_bl_bail(wir_r);
        }
        case c3__core: {
          if ( (u2_yes == 
                u2_mean(sut, 6, &p_sut, 14, &q_sut, 15, &r_sut, 0)) ) 
          {
          }
          else return u2_bl_bail(wir_r);
        }
        case c3__cube: {
        }
        case c3__face: {
          if ( (u2_yes == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          }
          else return u2_bl_bail(wir_r);
        }
        case c3__fork: {
          if ( (u2_yes == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          }
          else return u2_bl_bail(wir_r);
        } 
        case c3__hold: {
          if ( (u2_yes == u2_mean(sut, 6, &p_sut, 7, &q_sut, 0)) ) {
          }
          else return u2_bl_bail(wir_r);
        }
      }
      return _temp_dext(wir_r, u2_nul, sut, bon);
    }
  }
  u2_weak                                                         //  transfer
  j2_mc(Pit, vane, temp)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, bon;

    if ( u2_no == u2_mean(cor, 20, &sut, 9, &bon, 0) ) {
      return u2_none;
    } else {
      return j2_mcc(Pit, temp, vane)(wir_r, sut, bon);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, temp)[] = {
    { ".3", j2_mc(Pit, vane, temp), u2_no, u2_none, u2_none },
    { }
  };
