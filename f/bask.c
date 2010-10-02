/* l/bask.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u2_ba_init(): 
**
**   Initialize basket from rail partition, with parent if any.
*/
u2_ray
u2_ba_init(u2_ray bas_r, 
           u2_ray par_r)
{
  u2_bask_par_r(bas_r) = par_r;
  u2_ch_init(u2_bask_cad_r(bas_r));

  return bas_r;
}
 
/* u2_ba_find():
**
**   Basket search for `.*(bus fol)` in `bas`.
*/
u2_weak
u2_ba_find(u2_ray  bas_r,
           u2_noun bus,
           u2_noun fol)
{
  u2_noun pro;

  if ( u2_none != (pro = u2_ch_find_cell(u2_bask_cad_r(bas_r), bus, fol)) ) {
    return pro;
  } 
  else {
    if ( 0 != (bas_r = u2_bask_par_r(bas_r)) ) {
      return u2_ba_find(bas_r, bus, fol);
    } 
    else return u2_none;
  }
}

/* u2_ba_save():
*/
void
u2_ba_save(u2_ray  bas_r,
           u2_noun bus,
           u2_noun fol,
           u2_noun pro)
{
  u2_ch_save_cell(bas_r, u2_bask_cad_r(bas_r), bus, fol, pro);
}
