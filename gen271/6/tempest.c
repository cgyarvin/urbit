/* j/6/tempest.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* internals
*/

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, pest)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun zep,                            //  retain
                          u2_noun nux)                            //  retain
  {
    u2_noun p_sut, q_sut, r_sut;

    if ( u2_yes == u2_stud(sut) ) switch( sut ) {
      default: return u2_bl_bail(wir_r);

      case c3__atom: {
      }
      case c3__blot: {
      }
      case c3__blur: {
      }
    } else switch( u2_h(sut) ) {
      default: return u2_bl_bail(wir_r);

      case c3__cell: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else {
        }
      }
      case c3__core: {
        if ( u2_no == u2_as_qual(sut, 0, &p_sut, &q_sut, &r_sut) ) {
          return u2_bl_bail(wir_r);
        } else {
          }
          else return _nest_sint(wir_r, van, sut, bon, gil);
        }
      }
      case c3__cube: {
        p_sut = u2_t(sut);
        {
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
          u2_noun pro;

          pro = j2_mcy(Pit, vane, pest)(wir_r, van, fop, zep, nux); 
          u2_rl_lose(wir_r, fop);

          return pro;
        }
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, pest)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, zep, nux, van;

    if ( (u2_no == u2_mean(cor, 8, &zep, 9, &nux, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, pest)(wir_r, van, sut, zep, nux);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, pest)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, pest), u2_no, u2_none, u2_none },
    { }
  };
