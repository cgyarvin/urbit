/* mill/open.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

#define _open_p(stem) \
  if ( u4_b_p(gen, u4_atom_##stem, &p_gen) ) { \
    u4_loaf _mill_q_##stem(u4_milr, u4_noun); \
    return _mill_q_##stem(m, p_gen); \
  }

#define _open_pq(stem) \
  if ( u4_b_pq(gen, u4_atom_##stem, &p_gen, &q_gen) ) { \
    u4_loaf _mill_q_##stem(u4_milr, u4_noun, u4_noun); \
    return _mill_q_##stem(m, p_gen, q_gen); \
  }

#define _open_pqr(stem) \
  if ( u4_b_pqr(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen) ) {\
    u4_loaf _mill_q_##stem(u4_milr, u4_noun, u4_noun, u4_noun); \
    return _mill_q_##stem(m, p_gen, q_gen, r_gen); \
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
      (m, u4_k_qual(m->lane, u4_atom_slux, p_gen, q_gen, u4_noun_0));
  }
  else {
    _open_pq (ston);  // |*
    _open_p  (quax);  // ?&
    _open_p  (slip);  // :^
    _open_p  (glaz);  // ^@
    _open_p  (slos);  // :$
    _open_pqr(stix);  // ||
    _open_pq (quat);  // ?>
    _open_p  (slem);  // :-
    _open_p  (stem);  // |-
    _open_pq (slid);  // :+
    _open_pq (quid);  // ?+
    _open_pq (plat);  // ->
    _open_pq (slat);
    _open_pq (plet);  // -<
    _open_p  (stop);  // |=
    _open_p  (stid);  // |+
    _open_p  (brip);  // &^
    _open_p  (draz);
    _open_p  (quix);  // ?|
    _open_p  (slux);
    _open_pqr(clat);  // =>
    _open_pq (quet);  // ?<
    _open_p  (dron);
    _open_pq (sloc);  // :~
    _open_p  (glon);  // ^*
    _open_pqr(clet);  // =<
    _open_p  (broc);  // &~
    _open_pq (stol);  // |:
    _open_pq (gret);  // ~<
    _open_p  (quac);  // ?!
    _open_p  (bron);  // &*
    _open_p  (brop);  // &=
    _open_pq (quem);  // ?-
    _open_p  (slet);

    return gen;
  }
}
