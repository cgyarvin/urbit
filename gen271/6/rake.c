/* j/6/rake.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../Pit.h"

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, rake)(u2_wire wir_r, 
                    u2_noun gen)                                  //  retain
  {
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_stud(gen) ) {
      return u2_bc(wir_r, u2_rx(wir_r, gen), u2_nul);
    }
    else switch ( u2_h(gen) ) {
      default: printf("rake error\n"); return u2_bl_bail(wir_r);

      case u2_nul:  return u2_bc(wir_r, u2_rx(wir_r, gen), u2_nul);

      case c3__mtbn: {
        if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          if ( u2_nul != q_gen ) {
            return u2_bl_bail(wir_r);
          }
          else {
            return u2_rx(wir_r, p_gen);
          }
        }
      }
      case c3__ktdl: {
        if ( u2_no == u2_as_cell(u2_t(gen), &p_gen, &q_gen) ) {
          return u2_bl_bail(wir_r);
        }
        else return j2_mby(Pit, rake)(wir_r, q_gen);
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, rake)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun gen;

    if ( u2_none == (gen = u2_frag(4, cor)) ) {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, rake)(wir_r, gen);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, rake)[] = {
    { ".3", c3__hevy, j2_mb(Pit, rake), SafeTier6, u2_none, u2_none },
    { }
  };
