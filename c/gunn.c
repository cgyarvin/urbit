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
  /* _well_fill(): load disk objects in `wol`.
  */
  static u2_noun                                                  //  produce
  _well_fill(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun wol)                                         //  submit
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

  /* _sink_wash_sell(): sell with optional label.
  */
  static void
  _sink_wash_sell(u2_wire wir_r,
                  u2_atom lab,                                    //  retain
                  u2_noun vax)                                    //  retain
  {
    c3_l    col_l = _eyre_columns();
    u2_noun sam;
    u2_noun sel, wol;

    sam = u2_bc(wir_r, u2_rx(wir_r, lab), u2_rx(wir_r, vax)); 
    sel = _eyre_hook(wir_r, cor, "sell", sam);
    sam = u2_bc(wir_r, u2_bc(wir_r, 0, col_l), sel);
    wol = _eyre_hook(wir_r, cor, "wash", sel);

    _eyre_print_wall(wir_r, wol);
    u2_rz(wir_r, wol);
  }

  /* _
  /* _sink_wash(): apply sink.  Produce new core.
  */
  static u2_noun                                                  //  produce
  _sink_wash(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun vax,                                         //  retain
             u2_noun sic)                                         //  retain
  {
    if ( u2_nul == sic ) {
      _sink_wash_sell(wir_r, u2_nul, vax);
    }
    else switch ( u2_xh(wir_r, sic) ) {
    }
  }

      u2_noun tac = _eyre_hook(wir_r, cor, "sell", u2_rx(wir_r, vax));
      u2_noun wal = 
        _eyre_hook_cell(wir_r, cor, "wash", u2_bc(wir_r, 0, _eyre_columns), 
                                  t
  }

/* _eyre_gunn(): execute and print a line.  Produce new core.
*/
static u2_noun                                                    //  produce
_eyre_gunn(u2_wire wir_r,
           u2_noun cor,                                           //  retain
           u2_noun txt)                                           //  retain
{
  u2_noun con = _eyre_columns();
  u2_noun dyd = _eyre_hook(wir_r, cor, "scan", txt);
  u2_noun wol, sic, tul;

  u2_bi_trel(wir_r, dyd, &wol, &sic, &tul);
  wol = _well_fill(wir_r, wol);
  tul = _tool_fill(wir_r, tul); 
  {
    u2_noun gun = _eyre_hook(wir_r, cor, "pour", wol);
    u2_noun zen = _eyre_hook(wir_r, cor, "sing", tul);
    u2_noun von = _eyre_hook_cell(wir_r, cor, "fire", gun, zen);

    _gunn_sink(wir_r, sic, von);
  }

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
