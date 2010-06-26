/* watt/crow.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* fail:crow
*/
u4_noun
_crow_fail(u4_crow p,
           const char *msg)
{
  printf("%s\n", msg);
  return u4_exit;
}

/* rake:crow 
*/
u4_rope
_crow_rake(u4_crow p,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_gene p_gen, q_gen;

  if ( u4_b_pq(gen, u4_atom_take, &p_gen, &q_gen) ) {
    if ( !u4_n_zero(q_gen) ) {
      return _crow_fail(p, "rope");
    }
    else return p_gen;
  }
  else if ( u4_b_p(gen, u4_atom_frag, &p_gen) ) {
    return u4_kl(lan, gen);
  }
  else if ( u4_b_p(gen, u4_atom_port, &p_gen) ) {
    return u4_kl(lan, gen);
  }
  else return _crow_fail(p, "rope");
}

/* init:crow (fake)
*/
void
u4_crow_init(u4_crow p,
             u4_lane lan)
{
  p->lan = lan;
  p->prf = 0;

  p->fan = u4_noun_0;
  p->ver = u4_noun_0;
  p->bug = u4_noun_0;
  p->zud = u4_noun_0;
  p->nix = u4_noun_0;
  p->meb = u4_noun_0;
}

/* full:crow (fake)
*/
u4_loaf
u4_crow_full(u4_lane lan,
             u4_type sub,
             u4_gene gen)
{
  struct _u4_crow crow;

  u4_crow_init(&crow, lan);

  printf(":");
  fflush(stdout);
  printf("ready\n");
  return u4_exit;
  {
    u4_flag boz;
    u4_type typ;
    u4_tool tol;

    boz = _rose_show(&crow, sub, gen);
    if ( !u4_so(boz) ) {
      printf("type error\n");
      return u4_exit;
    }
    else {
      printf(":");

      typ = _rose_play(&crow, sub, gen);
      printf(":");
      tol = _rose_make(&crow, sub, gen);

      printf(":\n");
      // printf("prf: %d\n", p->prf);
      //
      return u4_kc(lan, typ, tol);
    }
  }
}
