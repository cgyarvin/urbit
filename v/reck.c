/* v/reck.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <stdint.h>
#include <ev.h>

#include "all.h"
#include "v/vere.h"

/* u2_ve_reck_load():
*/

/* u2_ve_reck_invent(): 
*/
void
u2_ve_reck_invent(): create wild reck in current stage.
{
}

/* u2_ve_tool(): load kernel tool.
*/
void
u2_ve_tool(u2_noun nam)
{
  u2_steg* ver_e = u2_ve_at();
  u2_noun  num   = u2_ve_tag(u2_Host.kno_w);
  u2_noun  bon   = u2nc(u2_ci_string(".~"), 
                        u2nq(c3__sys, u2k(num), u2k(nam), u2_nul));
  u2_noun  tah   = u2nt(nam, num, c3__sys);
  u2_weak  src   = u2_ve_file("watt", u2_ct(tah));

  u2_err(u2_Wire, "ve_tool", nam);
  u2_cm_push(u2nc(c3__lose, u2_cf_path(".", "watt", tah)));
  if ( u2_none == src ) {
    u2_cm_bail(c3__fail);
  }
  else {
    u2_noun gen, syd, vos;
  
    if ( u2_Host.kno_w > 210 ) {
      gen = u2_ve_ream(src);
      u2z(bon);
    } else {
      u2_hevn_be(u2_pryr, god) = u2_ve_zeus;
      {
        gen = u2_ve_rain(bon, src);
      }
      u2_hevn_be(u2_pryr, god) = 0;
    }

    if ( u2_Host.kno_w > 209 ) {
      syd = u2_ct(ver_e->toy.what ? ver_e->toy.what : ver_e->toy.seed);
    } else {
      syd = u2_ct(ver_e->toy.seed);
    }
    vos = u2_ve_slap(syd, gen);

    ver_e->tul = u2_ckd_by_put(ver_e->tul, nam, u2_cm_bury(vos));
    // ver_e->tul = u2_ckd_by_put(ver_e->tul, nam, vos);
  }
  u2_cm_drop();
}

