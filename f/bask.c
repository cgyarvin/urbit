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
    u2_ch_init(u2_bask_cus_r(bas_r));
    u2_ch_init(u2_bask_sol_r(bas_r));
    u2_ch_init(u2_bask_hag_r(bas_r));
    u2_cs_init(u2_bask_hog_r(bas_r));

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
      return u2_none;
    }
  }
}

/* u2_ba_save():
**
**   Save result of calculation; produce senior result if any.
*/
u2_weak                                                           //  senior
u2_ba_save(u2_ray  wir_r,
           u2_noun bus,                                           //  retain
           u2_noun fol,                                           //  retain
           u2_noun pro)                                           //  retain
{
  u2_ray  bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return u2_none;
  }
  else {
    u2_noun sub = u2_ba_uniq(wir_r, bus);
    u2_noun lof = u2_ba_uniq(wir_r, fol); 
    u2_noun por = u2_ba_uniq(wir_r, pro);

    if ( (u2_none == sub) || (u2_none == lof) || (u2_none == por) ) {
      return u2_none;
    }
    else {
      return u2_ch_save_cell(bas_r, u2_bask_mem_r(bas_r), sub, lof, por);
    }
  }
}

/* u2_ba_find_cus():
**
**   Basket search for custom key.
*/
u2_weak                                                           //  senior
u2_ba_find_cus(u2_ray  wir_r,
               u2_noun key)                                       //  retain
{
  u2_ray bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return u2_none;
  }
  else {
    u2_noun sav = u2_ch_find(u2_bask_cus_r(bas_r), key);

    if ( u2_none != sav ) {
      c3_assert(u2_yes == u2_rl_senior(wir_r, sav));
      return sav;
    } else {
      return u2_none;
    }
  }
}

/* u2_ba_save_cus():
**
**   Basket save by custom key.
*/
u2_weak                                                           //  senior
u2_ba_save_cus(u2_ray  wir_r,
               u2_noun key,                                       //  retain
               u2_noun pro)                                       //  retain
{
  u2_ray  bas_r;

  if ( 0 == (bas_r = u2_wire_bas_r(wir_r)) ) {
    return u2_none;
  }
  else {
    u2_noun yek = u2_ba_uniq(wir_r, key);
    u2_noun por = u2_ba_uniq(wir_r, pro);

    if ( (u2_none == yek) || (u2_none == por) ) {
      return u2_none;
    }
    else {
      return u2_ch_save(bas_r, u2_bask_cus_r(bas_r), yek, por);
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
**   Save unique noun.
*/
u2_noun                                                           //  transfer
u2_ba_sole(u2_ray  wir_r,
           u2_noun som)                                           //  transfer
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

/* u2_ba_uniq():
**
**   Save unique noun; return senior version, if any.
*/
u2_weak                                                           //  senior
u2_ba_uniq(u2_ray  wir_r,
           u2_noun som)                                           //  retain
{
  u2_ray bas_r;

  if ( u2_fly_is_cat(som) || (u2_yes == u2_rl_senior(wir_r, som)) ) {
    return som;
  }
  else if ( (0 == (bas_r = u2_wire_bas_r(wir_r)) ) ) {
    return u2_none;
  }
  else {
    u2_noun cad_r = u2_bask_sol_r(bas_r);
    u2_noun sav;

    if ( u2_none != (sav = u2_ch_find(cad_r, som)) ) {
      return sav;
    }
    else {
      u2_noun one;

      if ( u2_yes == u2_dust(som) ) {
        u2_noun hed = u2_ba_uniq(wir_r, u2_h(som));
        u2_noun tal = u2_ba_uniq(wir_r, u2_t(som));

        if ( (u2_none == hed) || (u2_none == tal) ) {
          return u2_none; 
        }
        else one = u2_rc(bas_r, u2_rx(bas_r, hed), u2_rx(bas_r, tal));
      }
      else one = u2_rx(bas_r, som);

      sav = u2_ch_save(bas_r, cad_r, one, one);

      u2_rl_lose(wir_r, one);
      return sav;
    }
  }
}
