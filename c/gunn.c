/* c/eyre.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <setjmp.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <gmp.h>
#include <stdint.h>

#include "all.h"

/* _eyre_gunn(): execute and print a line.  Produce new core.
*/
  /* _fuel_fill(): load disk objects in `ful`.
  */
  static u2_noun                                                  //  produce
  _fuel_fill(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun ful)                                         //  submit
  {
  }

  /* _tool_fill(): load disk objects in `tul`.
  */
  static u2_noun                                                  //  produce
  _tool_fill(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun tul)                                         //  submit
  {
  }

  /* _vent_wash_sell(): sell with optional label.
  */
  static void
  _vent_wash_sell(u2_wire wir_r,
                  u2_atom lab,                                    //  retain
                  u2_noun vax)                                    //  retain
  {
    c3_l    col_l = _eyre_columns();
    u2_noun sam;
    u2_noun sel, ful;

    sam = u2_bc(wir_r, u2_rx(wir_r, lab), u2_rx(wir_r, vax)); 
    sel = _eyre_hook(wir_r, cor, "sell", sam);
    sam = u2_bc(wir_r, u2_bc(wir_r, 0, col_l), sel);
    ful = _eyre_hook(wir_r, cor, "wash", sel);

    _eyre_print_wall(wir_r, ful);
    u2_rz(wir_r, ful);
  }

  /* _gunn_vent(): apply vent.  Produce new core.
  */
  static u2_noun                                                  //  produce
  _gunn_vent(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun vet,                                         //  retain
             u2_noun vax)                                         //  submit
  {
    u2_noun ret = u2_nul;

    if ( u2_nul == vet ) {
      _vent_wash_sell(wir_r, u2_nul, vax);
      return u2_rx(wir_r, cor);
    }
    else switch ( u2_xh(wir_r, vet) ) {
      case c3__bind:
      case c3__disk:
      case c3__many: 
        if ( 
        u2_noun hed = _eyre_hook_cell(wir_r, cor, "slot", 2, u2_rx(wir_r, vax));
        u2_noun tal = _eyre_hook_cell(wir_r, cor, "slot", 3, u2_rx(wir_r, vax));

    }
      default:
        u2_err(wir_r, 
        c3_asser
    }

    u2_rz(wir_r, vax);
  }

/* _eyre_gunn(): execute and print a line.  Produce new core.
*/
static u2_noun                                                    //  produce
_eyre_gunn(u2_wire wir_r,
           u2_noun cor,                                           //  retain
           u2_noun txt)                                           //  submit
{
  u2_noun dyd = _eyre_hook(wir_r, cor, "scan", txt);
  u2_noun ful, vet, tul;

  u2_bi_trel(wir_r, dyd, &ful, &vet, &tul);
  ful = _gunn_fuel(wir_r, u2_rx(wir_r, ful));
  tul = _gunn_tool(wir_r, u2_rx(wir_r, tul)); 
  {
    u2_noun von = _eyre_hook_cell(wir_r, cor, "ride", ful, zen);

    return _gunn_vent(wir_r, vet, von);
  }
}

  u2_rz(wir_r, 

  u2_ray kit_r = u2_bl_open(wir_r);

  if ( u2_bl_set(wir_r) ) {
    u2_bl_done(wir_r, kit_r);
    fprintf(stderr, "{stop}\n");
  } else {
    u2_noun spar = u2_bn_hook(wir_r, cor, "spar");
    u2_noun gall = u2_bn_hook(wir_r, cor, "gall");
    u2_noun gat = u2_bn_hook(wir_r, cor, "line");
    u2_noun pro;

    u2_bx_boot(wir_r);
    pro = _eyre_mong(wir_r, gat, u2_rx(wir_r, txt));
    u2_bx_sell(wir_r);

#if 1
    _eyre_gnaw(wir_r, ken, 2, u2_h(pro));
    _eyre_gnaw(wir_r, ken, 0, u2_t(pro));
#else
    _eyre_gnaw(wir_r, ken, 0, pro);
#endif

    u2_bl_done(wir_r, kit_r);
  }
}
