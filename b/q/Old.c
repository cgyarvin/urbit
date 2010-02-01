/* mill/open.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _open_zact(): [%zact mox=rope bem=list+pike]
*/
static u4_noun
_open_zact(u4_milr m, u4_wire mox, u4_noun bem)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(bem) ) {
    return u4_k_cell(lane, u4_atom_zarb, u4_noun_0);
  }
  else {
    u4_pike i_bem = u4_ch(bem);
    u4_noun t_bem = u4_ct(bem);
    u4_gene tes;
    u4_gene bif;

    _mill_pike(m, mox, i_bem, &tes, &bif);

    return u4_k_qual
      (lane,
       u4_atom_stol, 
       tes, 
       bif,
       _open_zact(m, mox, t_bem));
  }
}

/* _open_glax(): [%glax p/gene q/list+pike]
*/
static u4_noun
_open_glax(u4_milr m, u4_gene feg, u4_noun bem)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, u4_atom_glem,
           feg,
           u4_k_trel(lane, u4_atom_zact, 
                           u4_k_cell(lane, u4_atom_zarb, u4_noun_2),
                           bem));
} 

/* _mill_open(): open macro.
*/
u4_noun
_mill_open(u4_milr m,
           u4_noun gen)
{
  u4_lane lane = m->lane;
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_pq(gen, u4_atom_zact, &p_gen, &q_gen) ) {
    return _open_zact(m, p_gen, q_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_lect, &p_gen) ) {
    return u4_k_trel
      (lane, u4_atom_gant, u4_k_cell(lane, gen, u4_noun_0), u4_noun_0);
  }
  else if ( u4_b_pq(gen, u4_atom_zarb, &p_gen) ) {
    return u4_k_trel
      (lane, u4_atom_gant, u4_k_cell(lane, gen, u4_noun_0), u4_noun_0);
  }
  else if ( u4_b_pq(gen, u4_atom_pril, &p_gen) ) {
    /* constant as blur
    */
  }

  return gen;
}
