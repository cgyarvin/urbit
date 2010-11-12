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
    c3_w i_w;

    u2_bask_par_r(bas_r) = par_r;
    u2_ch_init(u2_bask_mem_r(bas_r));
    u2_ch_init(u2_bask_sol_r(bas_r));

    for ( i_w = 0; i_w < u2_bask_plow_end; i_w++ ) {
      u2_ch_init(u2_bask_vig_r(bas_r, i_w));
    }
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

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return u2_none;
  }
  else {
    u2_noun sav = u2_ch_find_cell(u2_bask_mem_r(bas_r), bus, fol);

    if ( u2_none != sav ) {
      c3_assert(u2_yes == u2_rl_senior(wir_r, sav));
      return sav;
    } else {
      if ( 0 != (bas_r = u2_bask_par_r(bas_r)) ) {
        return u2_ba_find(bas_r, bus, fol);
      } 
      else return u2_none;
    }
  }
}

/* u2_ba_save():
**
**   Save result of calculation; consumes `pro`, transmits result.
*/
u2_noun
u2_ba_save(u2_ray  wir_r,
           u2_noun bus,
           u2_noun fol,
           u2_noun pro)
{
  u2_ray  bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return pro;
  }
  else {
    u2_weak sav = u2_ch_save_cell(bas_r, u2_bask_mem_r(bas_r), bus, fol, pro);

    if ( u2_none == sav ) {
      return pro;
    } else {
      u2_rl_lose(wir_r, pro);

      c3_assert(u2_yes == u2_rl_senior(wir_r, sav));
      return sav;
    }
  }
}

/* u2_ba_find_plow():
**
**   Memory search for `key` in `poc_o`.
*/
u2_weak
u2_ba_find_plow(u2_ray       wir_r,
                u2_bask_code poc_o,
                u2_noun      key)
{
  u2_ray bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return u2_none;
  }
  else {
    u2_weak sav = u2_ch_find(u2_bask_vig_r(bas_r, poc_o), key);

    if ( u2_none != sav ) {
      c3_assert(u2_yes == u2_rl_senior(wir_r, sav));
      return sav;
    }
    else return u2_none;
  }
}

/* u2_ba_save_plow():
**
**   Save custom plow; copies `key`; consumes `pro`, transmits result.
*/
u2_noun
u2_ba_save_plow(u2_ray       wir_r,
                u2_bask_code poc_o,
                u2_noun      key,
                u2_noun      val)
{
  u2_ray bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return val;
  }
  else {
    u2_ray  cad_r = u2_bask_vig_r(bas_r, poc_o);
    u2_weak sav   = u2_ch_save(bas_r, cad_r, key, val);

    if ( u2_none == sav ) {
      return val;
    } else {
      // u2_rl_lose(wir_r, val);

      c3_assert(u2_yes == u2_rl_senior(wir_r, sav));
      return sav;
    }
  }
}

/* u2_ba_sole():
**
**   Save unique noun.  Consumes `som`, transmits result.
*/
u2_noun
u2_ba_sole(u2_ray  wir_r,
           u2_noun som)
{
  u2_ray bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return som;
  }
  else {
    if ( u2_yes == u2_rl_senior(wir_r, som) ) {
      return som;
    } else {
      u2_noun cad_r = u2_bask_sol_r(bas_r);
      u2_noun sav;

      if ( u2_none != (sav = u2_ch_find(cad_r, som)) ) {
        u2_rl_lose(wir_r, som);

        return sav;
      }
      else {
        if ( u2_none != (sav = u2_ch_save(bas_r, cad_r, som, som)) ) {
          u2_rl_lose(wir_r, som);

          return sav;
        }
        else return som;
      }
    }
  }
}

#if 0
/* u2_ba_sole():
**
**   Save unique noun, or at least try to.
*/
u2_noun
u2_ba_sole(u2_ray  wir_r,
           u2_noun som)
{
  u2_ray  bas_r;
  u2_weak haz = u2_none;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return som;
  }
  if 
  if ( u2_none != (haz = u2_ch_find(u2_bask_sol_r(bas_r), som)) ) {
    u2_rl_lose(wir_r, som);
    return haz;
  } 
  else {

    if ( u2_yes == u2_dust(som) ) {
      u2_noun hed = u2_ba_sole(wir_r, u2_h(som));
      u2_noun tal = u2_ba_sole(wir_r, u2_t(som));

      if ( (u2_no == u2_rl_junior(bas_r, hed)) ||
           (u2_no == u2_rl_junior(bas_r, tal)) )
      {
        return som;
      } 
      else {
        haz = u2_rl_cell(bas_r, hed, tal);
        if ( u2_no == haz ) {
          return som;
        } 
        else if ( u2_no == u2_ch_save(bas_r, u2_bask_sol_r(bas_r), haz, haz) ) {
          u2_rl_lose(bas_r, haz);
          return som;
        }
        else {
          u2_rl_lose(bas_r, som);
          return haz;
        }
      }
    }
    else {
      if ( u2_none != (haz = u2_rl_ice(bas_r, som)) ) {
        u2_rl_lose(som);
        return haz;
      } else {
        return som;
      }
    }
  }
}
#endif
