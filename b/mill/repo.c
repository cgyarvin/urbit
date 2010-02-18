/* mill/repo.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_repo(): replay stig.
*/
u4_type
_mill_repo(u4_milr m,
           u4_type tip,
           u4_gene gen)
{
  u4_lane lane = m->lane;
  u4_noun fad = u4_k_cell(lane, tip, gen);
  u4_noun fan;
  u4_type pol;

  if ( u4_bag_in(fad, m->fan) ) {
    // printf("inference recursion\n");
    // abort();

    return _mill_fail(m, "repo: inference recursion");
  }

  fan = m->fan;
  m->fan = u4_bag_add(lane, fad, m->fan);
  pol = _mill_play(m, gen, tip);
  m->fan = fan;

  return pol;
}
