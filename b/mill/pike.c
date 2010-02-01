/* mill/pike.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_pike: open pike.  *tes is the forb, *bif is yes.
*/
void
_mill_pike(u4_milr m,
           u4_rope mox, 
           u4_pike pik,
           u4_gene *tes,
           u4_gene *bif)
{
  u4_lane lane = m->lane;
  u4_skel bic;
  u4_gene luf;

  if ( u4_b_pq(pik, u4_atom_lask, &bic, &luf) ) {
    u4_gene mip = _mill_mate(m, bic);
    u4_gene bul = _mill_stub(m, bic);
    u4_gene nek = u4_k_trel(lane, u4_atom_gant, mox, u4_noun_0);

    *tes = u4_k_trel(lane, u4_atom_forb, mox, mip);
    *bif = u4_k_qual(lane, u4_atom_tarn, bul, nek, luf);
  }
  else if ( u4_b_p(pik, u4_atom_plic, &bic) ) {
    u4_gene luf = u4_k_trel(lane, u4_atom_gant, mox, u4_noun_0);
    u4_gene mip = _mill_mate(m, bic);
    u4_gene bul = _mill_stub(m, bic);

    *tes = u4_k_trel(lane, u4_atom_forb, mox, mip);
    *bif = u4_k_qual(lane, u4_atom_tarn, bul, luf, luf);
  }
  else if ( u4_b_pq(pik, u4_atom_semp, &bic, &luf) ) {
    u4_gene mip = _mill_mate(m, bic);
    u4_gene hem = _mill_fiat(m, bic);

    *tes = u4_k_trel(lane, u4_atom_forb, mox, mip);
    *bif = u4_k_trel
        (lane,
         u4_atom_grun,
         u4_k_cell(lane, u4_k_cell(lane, mox, hem), u4_noun_0),
         luf);
  }
  else if ( u4_b_p(pik, u4_atom_drol, &bic) ) {
    u4_gene mip = _mill_mate(m, bic);
    u4_gene hem = _mill_fiat(m, bic);

    *tes = u4_k_trel(lane, u4_atom_forb, mox, mip);
    *bif = hem;
  }
  else u4_trip;
}
