/* l/bask.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u2_ba_init(): 
**
**   Initialize wire basket, with parent if any.
*/
void
u2_ba_init(u2_ray wir_r, 
           u2_ray par_r)
{
  u2_ray  bas_r;

  if ( 0 != (bas_r = u2_wire_bas_r(wir_r)) ) {
    u2_bask_par_r(bas_r) = par_r;
    u2_ch_init(u2_bask_mem_r(bas_r));
    u2_ch_init(u2_bask_sol_r(bas_r));
  }
}
 
/* u2_ba_find():
**
**   Basket search for `.*(bus fol)` in `bas`.
*/
u2_weak
u2_ba_find(u2_ray  wir_r,
           u2_noun bus,
           u2_noun fol)
{
  u2_ray bas_r;
  u2_noun pro;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return u2_none;
  }
  if ( u2_none != (pro = u2_ch_find_cell(u2_bask_mem_r(bas_r), bus, fol)) ) {
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
**
**   Record computation in memoization basket.
*/
void
u2_ba_save(u2_ray  wir_r,
           u2_noun bus,
           u2_noun fol,
           u2_noun pro)
{
  u2_ray bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return;
  }
  fol = u2_rl_ice(bas_r, fol);

  u2_ch_save_cell(bas_r, u2_bask_mem_r(bas_r), bus, fol, pro);
}

/* u2_ba_sole():
**
**   Save unique noun.
*/
u2_weak
u2_ba_sole(u2_ray  wir_r,
           u2_noun som)
{
  u2_ray  bas_r;
  u2_weak haz = u2_none;

  if ( 0 != (bas_r = u2_wire_bas_r(wir_r)) ) {
    if ( u2_none == (haz = u2_ch_find(u2_bask_sol_r(bas_r), som)) ) {
      if ( u2_none != (haz = u2_rl_ice(bas_r, som)) ) {
        u2_ch_save(bas_r, u2_bask_sol_r(bas_r), haz, haz);
      }
    }
  }
  return (haz == u2_none) ? som : haz;
}
