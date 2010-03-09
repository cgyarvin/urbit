/* mill/fire.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_fire(): fire [tel hum] as (gate arg).
*/
u4_form
_mill_fire(u4_milr m,
           u4_form tel,
           u4_form hum)
{
  u4_lane lane = m->lane;
  u4_form arg  = u4_k_cell(lane, u4_noun_0, u4_noun_3);
  u4_form env  = u4_k_cell(lane, u4_noun_0, u4_noun_9);
  u4_form noc  = u4_k_cell(lane, u4_noun_0, u4_noun_5);

  return _mill_comp
    (m,
     _mill_cons(m, tel, hum),
     u4_k_trel
      (lane, 
       u4_noun_3,
       u4_k_cell(lane, u4_k_cell(lane, arg, env), noc),
       noc));
}
