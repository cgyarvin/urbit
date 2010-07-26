/* watt/crow.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* trap:crow
*/
void
_crow_trap(u4_crow p,
           const char *msg)
{
  u4_lane lan = p->lan;

  u4_atom hal  = u4_k_atom_c(lan, msg);

  p->meb = u4_k_cell(lan, u4_k_cell(lan, hal, u4_nul), p->meb);
}

/* trac:crow
*/

/* fail:crow
*/
u4_noun
_crow_fail(u4_crow p,
           const char *msg)
{
  _crow_trap(p, msg);
  {
    while ( !u4_n_zero(p->meb) ) {
      u4_noun i_meb = u4_ch(p->meb);
      u4_noun hal = u4_ch(i_meb);
      u4_noun jup = u4_ct(i_meb);

      if ( !u4_n_zero(hal) ) {
        u4_sb sb_hal = u4_a_bin(hal, 3);
        u4_cl *cl_hal = alloca(sb_hal + 1);

        u4_a_bytes(hal, (u4_xb *)cl_hal, 0, sb_hal + 1);
        printf("msg: %s\n", cl_hal);
      }

      if ( !u4_n_zero(jup) ) {
        u4_atom pp_jup = u4_ch(u4_ch(jup));
        u4_atom qp_jup = u4_ct(u4_ch(jup));
        u4_atom pq_jup = u4_ch(u4_ct(jup));
        u4_atom qq_jup = u4_ct(u4_ct(jup));
        {
          u4_xw xw_flin = u4_a_wtrip(pp_jup);
          u4_xw xw_fcol = u4_a_wtrip(qp_jup);
          u4_xw xw_llin = u4_a_wtrip(pq_jup);
          u4_xw xw_lcol = u4_a_wtrip(qq_jup);

          printf("spot: %d:%d - %d:%d\n", 
                 xw_flin, xw_fcol, xw_llin, xw_lcol);
        }
      }
      p->meb = u4_ct(p->meb);
    }
  }
  // return u4_exit;
  return u4_trip;
}

/* rake:crow 
*/
u4_rope
_crow_rake(u4_crow p,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_gene p_gen, q_gen;

  if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
    if ( !u4_n_zero(q_gen) ) {
      return _crow_fail(p, "rope");
    }
    else return p_gen;
  }
  else if ( u4_b_p(gen, u4_atom_frag, &p_gen) ) {
    return u4_kl(lan, gen);
  }
  else if ( u4_b_p(gen, u4_atom_pane, &p_gen) ) {
    return u4_kl(lan, gen);
  }
  else {
    u4_err(lan, "rake", gen);
    return _crow_fail(p, "rope");
  }
}

/* init:crow (fake)
*/
void
u4_crow_init(u4_crow p,
             u4_lane lan)
{
  p->lan = lan;
  p->prf = 0;
  p->prg = 0;
  p->prh = 0;
  p->pri = 0;

  p->fan = u4_nul;
  p->ver = u4_nul;
  p->bug = u4_nul;
  p->meb = u4_nul;
  p->vus = u4_nul;
  p->tyc = u4_nul;
  p->gam = u4_nul;
  p->hos = u4_nul;
  p->zor = u4_nul;
  p->niq = u4_nul;
  p->fac = u4_nul;
  p->vom = u4_nul;
  p->pon = u4_nul;
  p->fin = u4_nul;
  p->huf = u4_nul;
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

  printf(":"); fflush(stdout);
  {
    u4_flag boz;
    u4_type typ;
    u4_tool tol;

    tol = _rose_make(&crow, sub, gen);
    printf(":"); fflush(stdout);

#if 1
    boz = _rose_show(&crow, sub, gen);
    if ( !u4_so(boz) ) {
      printf("type error\n");
      return u4_exit;
    }
    printf(":"); fflush(stdout);
#endif

    typ = _rose_play(&crow, sub, gen);
    printf(":\n");

    // u4_err(lan, "size", _dump_size(lan, tol));

    // printf("prf: %d\n", crow.prf);
    // printf("prg: %d\n", crow.prg);
    // printf("prh: %d\n", crow.prh);
    // printf("pri: %d\n", crow.pri);

    return u4_kc(lan, typ, tol);
  }
}
