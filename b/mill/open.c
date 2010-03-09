/* mill/open.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

#define _open_p(flot) \
  if ( u4_b_p(gen, u4_atom_##flot, &p_gen) ) { \
    u4_loaf _mill_q_##flot(u4_milr, u4_noun); \
    return _mill_q_##flot(m, p_gen); \
  }

#define _open_pq(flot) \
  if ( u4_b_pq(gen, u4_atom_##flot, &p_gen, &q_gen) ) { \
    u4_loaf _mill_q_##flot(u4_milr, u4_noun, u4_noun); \
    return _mill_q_##flot(m, p_gen, q_gen); \
  }

#define _open_pqr(flot) \
  if ( u4_b_pqr(gen, u4_atom_##flot, &p_gen, &q_gen, &r_gen) ) {\
    u4_loaf _mill_q_##flot(u4_milr, u4_noun, u4_noun, u4_noun); \
    return _mill_q_##flot(m, p_gen, q_gen, r_gen); \
  }


/* _mill_open(): type inference, top level.
*/
u4_type 
_mill_open(u4_milr m,
           u4_gene gen)
{
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_fork(gen, &p_gen, &q_gen) ) {
    return _mill_open
      (m, u4_k_qual(m->lane, u4_atom_cage, p_gen, q_gen, u4_noun_0));
  }
  else {
    _open_pq (blin);  // |*
    _open_p  (boce);  // ?&
    _open_p  (bink);  // :^
    _open_p  (crot);  // ^@
    _open_pqr(drol);  // ||
    _open_pq (feng);  // ?>
    _open_p  (flec);  // :-
    _open_p  (flot);  // |-
    _open_pq (garc);  // :+
    _open_pq (stam);  // ?+
    _open_pq (trop);  // ->
    _open_pq (lect);
    _open_pq (prec);  // -<
    _open_p  (lome);  // |=
    _open_p  (malk);  // |+
    _open_p  (palt);
    _open_p  (dant);  // ?|
    _open_pqr(pont);  // =>
    _open_pq (prex);  // ?<
    _open_pq (grun);  // :%
    _open_p  (crad);
    _open_p  (cret);  // :*
    _open_p  (rald);  // ^*
    _open_pqr(clet);  // =<
    _open_pq (flic);  // |:
    _open_pq (colb);  // ~<
    _open_p  (blem);  // ?!
    _open_pq (gril);  // ?-
    _open_p  (frag);

    return gen;
  }
}
