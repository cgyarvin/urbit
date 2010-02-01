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

  _open_pq (blin);  // |*
  _open_pq (boce);  // ?&
  _open_p  (brip);  // :^
  _open_p  (crot);  // ^@
  _open_p  (delc);  // :$
  _open_pq (feng);  // ?>
  _open_p  (flec);  // :-
  _open_p  (flot);  // |-
  _open_p  (frez);  // &~
  _open_pq (garc);  // :+
  _open_pq (glax);  // ?+
  _open_pq (glem);  // ->
  _open_pq (lect);
  _open_pq (lisc);  // -<
  _open_p  (malk);  // |+
  _open_p  (neft);  // &^
  _open_p  (palt);
  _open_p  (peld);  // ?|
  _open_pqr(pont);  // =>
  _open_pq (prex);  // ?<
  _open_p  (pril);
  _open_pq (pung);  // :~
  _open_p  (rald);  // ^*
  _open_pqr(rulf);  // =<
  _open_pq (serd);  // |:
  _open_p  (spal);  // &~
  _open_pq (stiv);  // ~<
  _open_p  (trup);  // ?!
  _open_p  (veck);  // &*
  _open_p  (wamp);  // &=
  _open_pq (zact);  // ?-
  _open_p  (zarb);

  u4_bug("open: stem", u4_ch(gen));
  return u4_trip;
}
