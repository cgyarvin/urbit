/* l/shed.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u2_sh_init(): 
**
**   Initialize jet shed.
*/
void
u2_sh_init(u2_ray wir_r)
{
  u2_ray sad_r;

  if ( 0 != (sad_r = u2_wire_sad_r(wir_r)) ) {
    u2_ch_init(u2_shed_cad_r(sad_r));
  }
}

/* _sh_good_sil()::
*/
static u2_flag
_sh_good_sil(u2_noun sil)
{
  // XX: verify seal.
  //
  return u2_yes;
}

/* _sh_good_bud()::
*/
static u2_flag
_sh_good_bud(u2_noun bud)
{
  u2_noun p_bud, q_bud;

  if ( _0 == bud ) {
    return u2_yes;
  }
  else if ( (u2_no == u2_as_cell(bud, &p_bud, &q_bud)) ) {
    return u2_no;
  }
  if ( (u2_nock_bone == p_bud) && (_0 == q_bud) ) {
    return u2_yes;
  }
  if ( (u2_nock_frag == p_bud) && (u2_yes == u2_stud(q_bud)) ) {
    return u2_yes;
  }
  else return u2_no;
}

/* _sh_good_nut()::
*/
static u2_flag
_sh_good_nut(u2_noun nut)
{
  if ( u2_nul == nut ) {
    return u2_yes;
  } else {
    u2_noun i_nut, t_nut;
    u2_noun pi_nut, qi_nut;

    if ( (u2_no == u2_as_cell(nut, &i_nut, &t_nut)) ||
         (u2_no == u2_as_cell(i_nut, &pi_nut, &qi_nut)) ||
         (u2_no == u2_stud(pi_nut)) )
    {
      return u2_no;
    }
    else return u2_yes;
  }
}

/* u2_sh_mine(): substitute active, annotated battery.
*/
u2_weak
u2_sh_mine(u2_ray  wir_r,
           u2_clue clu,
           u2_noun cor)
{
  u2_ray sad_r;
  u2_noun pay, bat;
  u2_noun sil, bud, nut;
  u2_chip xip;

  if ( 0 == (sad_r = u2_wire_sad_r(wir_r)) ) {
    return u2_none;
  }
  else if ( (u2_none == u2_as_cell(cor, &pay, &bat)) || 
            (u2_no == u2_dust(bat)) )
  {
    u2_ho_warn_here();
    return u2_none;
  }
  else if ( u2_none != (xip = u2_ch_find(u2_shed_cad_r(sad_r), bat)) ) {
    u2_noun cyr;

    if ( u2_none == (cyr = u2_rc(wir_r, pay, u2_h(u2_t(xip)))) ) {
      return u2_none;
    }
    else {
      u2_rl_gain(wir_r, pay);

      return cyr;
    }
  }
  else if ( (u2_no == u2_as_trel(clu, &bud, &sil, &nut)) ||
            (u2_no == _sh_good_bud(bud)) ||
            (u2_no == _sh_good_sil(sil)) ||
            (u2_no == _sh_good_nut(nut)) )
  {
    u2_ho_warn_here();

    return u2_none;
  }
  else {
    u2_noun dac, bot, pet, xop, cyr;
    
    dac = bot = pet = xop = cyr = u2_none;
    while ( 1 ) {
      /* disc: dac
      */
      {
        if ( u2_none == (dac = u2_rl_ice(sad_r, u2_t(clu))) ) {
          break;
        }
      }

      /* battery: bot
      */
      {
        if ( u2_no == u2_rl_junior(sad_r, bat) ) {
          /* We need the jet battery to be in the shed, so that we 
          ** have a fast algorithm for distinguishing jet batteries
          ** by ray address.
          */
          bot = u2_rc(sad_r, u2_h(bat), u2_t(bat));
        } 
        else {
          bot = u2_rl_ice(sad_r, bat);
        }
        if ( u2_none == bot ) {
          break;
        }
      }

      /* trunk: pet
      */
      {
        if ( _0 == bud ) {
          pet = u2_nul;
        } 
        else {
          u2_atom p_bud = u2_t(bud);
          u2_noun car   = u2_frag(p_bud, cor);
         
          if ( (u2_none == car) || (u2_no == u2_dust(car)) ) {
            break;
          } else {
            u2_noun but = u2_t(car);
            u2_noun xup, axe;

            if ( u2_none == (xup = u2_ch_find(u2_shed_cad_r(sad_r), but)) ) {
              u2_ho_warn_here();
              break;
            }
            else u2_rl_gain(sad_r, xup);

            if ( u2_none == (axe = u2_rl_ice(sad_r, p_bud)) ) {
              u2_rl_lose(sad_r, xup);
            }

            if ( u2_none == (pet = u2_rc(sad_r, p_bud, xup)) ) {
              u2_rl_lose(sad_r, axe);
              u2_rl_lose(sad_r, xup);
              break;
            }
          }
        }
      }

      /* xop: new chip.
      */
      {
        if ( u2_none == (xop = u2_rt(sad_r, dac, bot, pet)) ) {
          break;
        }
        if ( u2_no == (u2_ch_save(sad_r, u2_shed_cad_r(sad_r), bot, xop)) ) {
          break;
        }
#if 0
        printf("battery: registered: %d.%x\n",
                u2_ray_a(u2_dog_a(bot)),
                u2_ray_b(u2_dog_a(bot)));
#endif

        u2_rl_lose(sad_r, xop);
      }

      /* cyr: new core.
      */
      {
        u2_noun cyr;

        if ( u2_none == (cyr = u2_rc(wir_r, pay, bot)) ) {
          break;
        }
        else {
          u2_rl_gain(wir_r, pay);

          return cyr;
        }
      }
    }
    u2_ho_warn_here();

    if ( dac != u2_none ) u2_rl_lose(sad_r, dac);
    if ( bot != u2_none ) u2_rl_lose(sad_r, bot);
    if ( pet != u2_none ) u2_rl_lose(sad_r, pet);
    if ( xop != u2_none ) u2_rl_lose(sad_r, xop);

    return u2_none;
  }
}

/* _sh_good(): verify payload integrity in core.
*/
static u2_flag
_sh_good(u2_noun cor,
         u2_noun xip)
{
  while ( 1 ) {
    u2_noun bat = u2_h(u2_t(xip));
    u2_noun pet = u2_t(u2_t(xip));

    if ( u2_no == u2_sing(bat, u2_t(cor)) ) {
      u2_ho_warn_here();
      return u2_no;
    }
    else {
      if ( _0 == pet ) {
        return u2_yes;
      } else {
        u2_atom axe = u2_h(pet);
        u2_noun nub = u2_frag(axe, cor);

        if ( u2_none == nub ) {
          return u2_no;
        } else {
          cor = nub;
          xip = u2_t(pet);
          continue;
        }
      }
    }
  }
}

/* u2_sh_find(): find chip by core.
*/
u2_weak
u2_sh_find(u2_ray  wir_r,
           u2_noun cor)
{
  u2_ray sad_r;

  if ( 0 == (sad_r = u2_wire_sad_r(wir_r)) ) {
    return u2_none;
  }
  if ( u2_no == u2_dust(cor) ) {
    return u2_none;
  } else {
    u2_noun bat = u2_t(cor);

    if ( !u2_fly_is_dog(bat) ) {
      return u2_none;
    } else {
      u2_ray bat_r = u2_dog_a(bat);
      u2_ray rut_r = u2_rail_rut_r(sad_r);
      u2_ray hat_r = u2_rail_hat_r(sad_r);

      if ( (bat_r < rut_r) || (bat_r >= hat_r) ) {
        return u2_none;
      } else {
        u2_chip xip = u2_ch_find(u2_shed_cad_r(sad_r), bat);

        if ( u2_none == xip ) {
#if 0
          printf("bat_r %d.%x; hat_r %d.%x; rut_r %d.%x\n",
                  u2_ray_a(bat_r), u2_ray_b(bat_r),
                  u2_ray_a(hat_r), u2_ray_b(hat_r),
                  u2_ray_a(rut_r), u2_ray_b(rut_r));
#endif
          u2_ho_warn_here();
          return u2_none;
        } else {
          if ( u2_yes == _sh_good(cor, xip) ) {
            return xip;
          }
          else {
            u2_ho_warn_here();

            return u2_none;
          }
        }
      }
    }
  }
}
