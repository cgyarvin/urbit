/* mill/weld.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _is_grip()::
*/
static u4_t
_is_grip(u4_hook sod, 
         u4_tick *tik, 
         u4_term *cox)
{
  if ( u4_n_atom(sod) ) {
    if ( tik ) *tik = u4_noun_0;
    if ( cox ) *cox = sod;
    return 1;
  }
  else if ( u4_b_pq(sod, u4_atom_name, tik, cox) ) {
    return 1;
  }
  else return 0;
}

/* _is_limb()::
*/
static u4_t
_is_limb(u4_hook sod,
         u4_axis *axe)
{
  return u4_b_p(sod, u4_atom_limb, axe);
}

/* _mill_weld(): modify type to reflect assignment.
*/
u4_type
_mill_weld(u4_milr m,
           u4_rope fes,
           u4_type gan,
           u4_type tip)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(fes) ) {
    return gan;
  }
  else {
    u4_hook i_fes = u4_ch(fes);
    u4_rope t_fes = u4_ct(fes);
    u4_tick tik;
    u4_term cox;
    u4_axis axe;

    if ( _is_grip(i_fes, &tik, &cox) ) {
      u4_loaf fod = _mill_find(m, cox, u4_noun_0, tip);
      u4_type voz, pel;

      if ( u4_n_zero(fod) ) {
        return _mill_fail(m, "weld: no grip");
      }
      else if ( !u4_b_p(u4_ct(fod), u4_noun_0, &axe) ) {
        return _mill_fail(m, "weld: read-only");
      }
      voz = u4_ch(fod);
       
      if ( !u4_n_zero(tik) ) {
        t_fes = u4_k_cell
          (lane, u4_k_trel
                  (lane, u4_atom_name, u4_op_dec(lane, tik), cox),
                 t_fes);
      }
      
      pel = _mill_weld(m, t_fes, gan, voz);
      return _mill_turn(m, cox, axe, pel, u4_noun_0, tip);
    }

    else if ( _is_limb(i_fes, &axe) ) {
      u4_type voz = _mill_peek(m, axe, u4_noun_0, tip);
      u4_type pel = _mill_weld(m, t_fes, gan, voz);

      return _mill_poke(m, axe, pel, u4_noun_0, tip);
    }
    else return u4_trip;
  }
}
