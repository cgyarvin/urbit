/* mill/test.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _mill_test(): analyze branch test.
**
** Produce (p.type q.form).  p is the yes type.  q is the test.
*/
u4_loaf
_mill_test(u4_milr m,
           u4_gene gen,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_gen, q_gen;

  if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
    u4_loaf fod = _mill_look(m, p_gen, tip);
    u4_type gan = _mill_play(m, q_gen, tip);
    u4_axis niv;

    if ( !u4_b_p(u4_ct(fod), u4_noun_0, &niv) ) {
      return _mill_fail(m, "test: bad like");
    }
    else {
      if ( _mill_orth(m, gan, u4_ch(fod)) ) {
        return u4_k_trel(lane, u4_atom_blot, u4_noun_1, u4_noun_1);
      }
      else if ( _mill_nest(m, gan, u4_ch(fod)) ) {
        return u4_k_trel(lane, tip, u4_noun_1, u4_noun_0);
      }
      else {
        u4_type hem = _mill_both(m, gan, u4_ch(fod));

        return u4_k_cell
          (lane, _mill_poke(m, p_gen, hem, u4_noun_0, tip),
                 _mill_fish(m, niv, gan));
      }
    }
  }

  else if ( u4_b_pq(gen, u4_atom_and, &p_gen, &q_gen) ) {
    u4_loaf fod = _mill_test(m, p_gen, tip);
    u4_loaf nar = _mill_test(m, q_gen, u4_ch(fod));

    return u4_k_cell(lane, u4_ch(nar), 
                           _mill_and(m, u4_ct(fod), u4_ct(nar)));
  }

  else if ( u4_b_pq(gen, u4_atom_or, &p_gen, &q_gen) ) {
    u4_noun miv = _mill_test(m, p_gen, tip);
    u4_noun pas = _mill_test(m, q_gen, tip);

    return u4_k_cell(lane, _mill_eith(m, u4_ch(miv), u4_ch(pas)),
                           _mill_or(m, u4_ct(miv), u4_ct(pas)));
  }

  else {
    u4_noun vob = _mill_open(m, gen);

    if ( u4_n_eq(vob, gen) ) {
      return u4_k_cell(lane, tip, _mill_bake(m, gen, tip));
    }
    else return _mill_test(m, vob, tip);
  }
}
