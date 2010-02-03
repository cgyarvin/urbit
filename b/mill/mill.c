/* mill/mill.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* u4_mill(): 
**
**   Convert [gene type] to [type form].
*/
u4_loaf
u4_mill(u4_lane lane,
        u4_lump nes,
        u4_lump zyl)
{
  struct _u4_mill milr;

  milr.lane = lane;
  milr.fan = u4_noun_0;
  milr.rux = u4_noun_0;
  milr.zud = u4_noun_0;
  milr.nix = u4_noun_0;

  milr.meb = u4_noun_0;
  milr.dam = u4_noun_0;
  milr.niq = u4_noun_0;
  milr.vus = u4_noun_0;

  // nes = _mill_gene(&milr, nes);
  // zyl = _mill_type(&milr, zyl);

  {
    u4_loaf lof = _mill_make(&milr, nes, zyl);
    u4_type typ = u4_ch(lof);
    u4_form fol = u4_ct(lof);

    // return u4_k_cell(lane, typ, fol);
    // 
    return u4_k_cell(lane, _mill_reap(&milr, typ), fol);
  }
}
