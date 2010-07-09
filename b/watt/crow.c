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
  u4_atom nof  = p->nix;
  u4_atom jup  = p->zud;

  p->meb = u4_k_cell(lan, u4_k_trel(lan, hal, nof, jup), p->meb);
}

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
      {
        u4_noun hal = u4_ch(i_meb);
        u4_noun nof = u4_cth(i_meb);
        u4_noun jup = u4_ctt(i_meb);

        if ( u4_n_zero(u4_ct(p->meb)) ) {
          u4_sb sb_hal = u4_a_bin(hal, 3);
          u4_cl *cl_hal = alloca(sb_hal + 1);

          u4_a_bytes(hal, (u4_xb *)cl_hal, 0, sb_hal + 1);
          printf("fail: %s\n", cl_hal);

          if ( !u4_n_zero(nof) ) {
            u4_burp(p->lan, "home", u4_prep_textual(p->lan, nof));
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

              printf("spot: %d:%d - %d:%d\n\n", 
                     xw_flin, xw_fcol, xw_llin, xw_lcol);
            }
          }
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

  p->fan = u4_noun_0;
  p->ver = u4_noun_0;
  p->bug = u4_noun_0;
  p->zud = u4_noun_0;
  p->nix = u4_noun_0;
  p->meb = u4_noun_0;
  p->vus = u4_noun_0;
  p->gam = u4_noun_0;
  p->zor = u4_noun_0;
  p->niq = u4_noun_0;
  p->pon = u4_noun_0;
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
      // u4_err(lan, "tol", tol);

      printf(":\n");
      // printf("prf: %d\n", crow.prf);
      //
      return u4_kc(lan, typ, tol);
    }
  }
}
