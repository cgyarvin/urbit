/* j/6/hike.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* internal tools
*/
  static u2_axis 
  _lily_hike_axis_l(u2_ray  wir_r, 
                    u2_axis axis)
  {
    return u2_fj_op_add(wir_r, axis, axis);
  }
  static u2_axis 
  _lily_hike_axis_r(u2_ray  wir_r, 
                    u2_axis axis)
  {
    return u2_fj_op_inc(wir_r, _lily_hike_axis_l(wir_r, axis));
  }

  /* _lily_hike_belt_root(): convert (pac) to a list of root tools.
  */
  static u2_list
  _lily_hike_belt_root(u2_ray  wir_r,
                       u2_list pac)
  {
    if ( (u2_nul == pac) ) {
      return u2_nul;
    }
    else {
      u2_axis axis     = u2_h(u2_h(pac));
      u2_tool tool     = u2_t(u2_h(pac));
      u2_list list_tool = _lily_hike_belt_root(wir_r, u2_t(pac));

      if ( u2_yes == u2_sing(_1, axis) ) {
        return u2_bc(wir_r, tool, list_tool);
      }
      else return list_tool;
    }
  }

  /* _lily_hike_belt_l(): factor (pac) left.
  */
  static u2_list
  _lily_hike_belt_l(u2_ray  wir_r,
                    u2_list pac)
  {
    if ( (u2_nul == pac) ) {
      return u2_nul;
    }
    else {
      u2_axis axis       = u2_h(u2_h(pac));
      u2_tool tool       = u2_t(u2_h(pac));
      u2_list belt_l = _lily_hike_belt_l(wir_r, u2_t(pac));

      {
        if ( (_1 != axis) && u2_yes == u2_sing(_2, u2_fj_op_tip(axis)) ) {
          u2_axis axis_tap = u2_fj_op_tap(wir_r, axis);

          return u2_bc(wir_r, u2_bc(wir_r, axis_tap, tool), belt_l);
        }
        else return belt_l;
      }
    }
  }

  /* _lily_hike_belt_r(): factor (pac) right.
  */
  static u2_list
  _lily_hike_belt_r(u2_ray  wir_r,
                    u2_list pac)
  {
    if ( (u2_nul == pac) ) {
      return u2_nul;
    }
    else {
      u2_axis axis       = u2_h(u2_h(pac));
      u2_tool tool       = u2_t(u2_h(pac));
      u2_list belt_r = _lily_hike_belt_r(wir_r, u2_t(pac));

      {
        if ( (_1 != axis) && u2_yes == u2_sing(_3, u2_fj_op_tip(axis)) ) {
          u2_axis axis_tap = u2_fj_op_tap(wir_r, axis);

          return u2_bc(wir_r, u2_bc(wir_r, axis_tap, tool), belt_r);
        }
        else return belt_r;
      }
    }
  }

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mby(Pit, hike)(u2_wire wir_r, 
                    u2_noun axe,                                  //  retain
                    u2_noun pac)                                  //  retain
  {
    if ( (u2_nul == pac) ) {
      return u2_bc(wir_r, u2_nock_frag, axe);
    }
    else {
      u2_list list_tool    = _lily_hike_belt_root(wir_r, pac);
      u2_list belt_l  = _lily_hike_belt_l(wir_r, pac);
      u2_list belt_r  = _lily_hike_belt_r(wir_r, pac);

      if ( !(u2_nul == list_tool) ) {
        return u2_h(list_tool);
      }
      else {
        u2_tool tool_l, tool_r;
        
        tool_l = j2_mby(Pit, hike)
          (wir_r, _lily_hike_axis_l(wir_r, axe), belt_l);

        tool_r = j2_mby(Pit, hike)
          (wir_r, _lily_hike_axis_r(wir_r, axe), belt_r);

        return j2_mby(Pit, cons)(wir_r, tool_l, tool_r);
      }
    }
  }
  u2_noun                                                         //  transfer
  j2_mb(Pit, hike)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun axe, pac;

    if ( (u2_no == u2_mean(cor, 8, &axe, 9, &pac, 0)) ||
         (u2_no == u2_stud(axe)) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mby(Pit, hike)(wir_r, axe, pac);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, hike)[] = {
    { ".3", c3__hevy, j2_mb(Pit, hike), u2_no, u2_none, u2_none },
    { }
  };
