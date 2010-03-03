/* mill/weld.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_weld(): modify type to reflect assignment.
**
**   axe: change axis
**   hur: type of change
**   wac: background type
*/
u4_type
_mill_weld(u4_milr m,
           u4_axis axe,
           u4_type hur,
           u4_type wac)
{
  u4_type dox  = _mill_peek(m, axe, u4_noun_0, wac);

  if ( _mill_nest(m, hur, dox) ) {
    if ( _mill_nest(m, dox, hur) ) {
      return wac;
    }
    else return _mill_heal(m, axe, hur, wac);
  }
  else {
    u4_burp(m->lane, "hur", _mill_dump(m, hur));
    u4_burp(m->lane, "dox", _mill_dump(m, dox));

    return _mill_poke(m, axe, hur, u4_noun_0, wac);
  }
}
