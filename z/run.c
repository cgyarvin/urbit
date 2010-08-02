/* z/run.c
**
** This file is in the public domain.
*/
#include "all.h"

/* _zn_depart(): depart to temporary construction.
*/
static inline u3_ray
_zn_depart(u3_z z)
{
  return u3_lm_flap(z);
}

/* _zn_retreat(): retreat from temporary construction.
**
**   mat: saved mat, from _zn_depart().
*/
static inline void
_zn_retreat(u3_z   z,
            u3_ray ray_mat)
{
  u3_lm_flop(z, ray_mat);
}

/* _zn_complete(): complete a calculation.
**
**   lid: destination of calculation
**   lam: result
*/
static inline void
_zn_complete(u3_z   z,
             u3_ray ray_lid,
             u3_fox lam)
{
  {
    c3_assert(u3_li_ray_beam(ray_lid) == u3_li_ray_beam(z->l.ray_cap));
    c3_assert(u3_li_ray_beam(ray_lid) == u3_li_ray_beam(z->l.ray_mat));
    c3_assert(ray_lid <= z->l.ray_cap);
    c3_assert(ray_lid >= z->l.ray_mat);
  }

  z->l.ray_cap = ray_lid;

  _zn_push_word(z, lam);
}

/* _zn_forge_cons(): install a cons agent.
**
**   lid: cap at termination
*/
static inline void
_zn_forge_cons(u3_z   z,
               u3_ray ray_lid)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, cons);
  *_zn_forge(z, ray_zos, cons, c.oper_ger) = u3_cm_cons;
  *_zn_forge(z, ray_zos, cons, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, cons, c.ray_lid) = ray_lid;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_cook(): install a cook agent.
**
**   lid: cap at termination
**   lan: subject
**   sef: formula
*/
static inline void
_zn_forge_cook(u3_z z,
               u3_ray ray_lid,
               u3_fox lan,
               u3_fox sef)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, cook);
  *_zn_forge(z, ray_zos, cook, c.oper_ger) = u3_cm_cook;
  *_zn_forge(z, ray_zos, cook, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, cook, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, cook, s.lan) = lan;
  *_zn_forge(z, ray_zos, cook, s.sef) = sef;
  
  z->n.ray_lab = ray_zos;
}

/* _zn_forge_drop(): install a drop agent.
**
**   lid: cap at termination
*/
static inline void
_zn_forge_drop(u3_z   z,
               u3_ray ray_lid)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, drop);
  *_zn_forge(z, ray_zos, drop, c.oper_ger) = u3_cm_drop;
  *_zn_forge(z, ray_zos, drop, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, drop, c.ray_lid) = ray_lid;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_fine(): install a fine agent.
**
**   lid: cap at termination
*/
static inline void
_zn_forge_fine(u3_z   z,
               u3_ray ray_lid)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, fine);
  *_zn_forge(z, ray_zos, fine, c.oper_ger) = u3_cm_fine;
  *_zn_forge(z, ray_zos, fine, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, fine, c.ray_lid) = ray_lid;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_link(): install a link agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: link formula.
*/
static inline void
_zn_forge_link(u3_z   z,
               u3_ray ray_lid,
               u3_ray ray_mat,
               u3_ray ray_lip,
               u3_fox dep)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, link);
  *_zn_forge(z, ray_zos, link, c.oper_ger) = u3_cm_link;
  *_zn_forge(z, ray_zos, link, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, link, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, link, r.ray_mat) = ray_mat;
  *_zn_forge(z, ray_zos, link, r.ray_lip) = ray_lip;

  *_zn_forge(z, ray_zos, link, s.dep) = dep;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_push(): install a push agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: push formula.
*/
static inline void
_zn_forge_push(u3_z   z,
               u3_ray ray_lid,
               u3_ray ray_mat,
               u3_ray ray_lip,
               u3_fox lan,
               u3_fox dep)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, push);
  *_zn_forge(z, ray_zos, push, c.oper_ger) = u3_cm_push;
  *_zn_forge(z, ray_zos, push, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, push, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, push, r.ray_mat) = ray_mat;
  *_zn_forge(z, ray_zos, push, r.ray_lip) = ray_lip;

  *_zn_forge(z, ray_zos, push, s.lan) = lan;
  *_zn_forge(z, ray_zos, push, s.dep) = dep;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_jet(): install a jet agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   sax: jet code
*/
static inline void
_zn_forge_jet(u3_z            z,
              u3_ray          ray_lid,
              u3_ray          ray_mat,
              u3_ray          ray_lip,
              enum u3_zj_code code_sax)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, jet);
  *_zn_forge(z, ray_zos, jet, c.oper_ger) = u3_cm_jet;
  *_zn_forge(z, ray_zos, jet, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, jet, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, jet, r.ray_mat) = ray_mat;
  *_zn_forge(z, ray_zos, jet, r.ray_lip) = ray_lip;

  *_zn_forge(z, ray_zos, jet, s.w_sax) = code_sax;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_mate(): install a mate agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   lan: subject
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_forge_mate(u3_z z,
               u3_ray ray_lid,
               u3_ray ray_mat,
               u3_ray ray_lip,
               u3_fox pod)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, mate);
  *_zn_forge(z, ray_zos, mate, c.oper_ger) = u3_cm_mate;
  *_zn_forge(z, ray_zos, mate, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, mate, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, mate, r.ray_mat) = ray_mat;
  *_zn_forge(z, ray_zos, mate, r.ray_lip) = ray_lip;

  *_zn_forge(z, ray_zos, mate, s.pod) = pod;
  
  z->n.ray_lab = ray_zos;
}

/* _zn_forge_pick(): install a pick agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   lan: subject
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_forge_pick(u3_z z,
               u3_ray ray_lid,
               u3_ray ray_mat,
               u3_ray ray_lip,
               u3_fox lan,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, pick);
  *_zn_forge(z, ray_zos, pick, c.oper_ger) = u3_cm_pick;
  *_zn_forge(z, ray_zos, pick, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, pick, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, pick, r.ray_mat) = ray_mat;
  *_zn_forge(z, ray_zos, pick, r.ray_lip) = ray_lip;

  *_zn_forge(z, ray_zos, pick, s.lan) = lan;
  *_zn_forge(z, ray_zos, pick, s.feg) = feg;
  *_zn_forge(z, ray_zos, pick, s.paf) = paf;
  
  z->n.ray_lab = ray_zos;
}

/* _zn_forge_root(): install a root agent.
**
**   ger: operation.
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
*/
static inline void
_zn_forge_root(u3_z       z,
               u3_zn_oper oper_ger,
               u3_ray     ray_lid,
               u3_ray     ray_mat,
               u3_ray     ray_lip)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, root);
  *_zn_forge(z, ray_zos, root, c.oper_ger) = oper_ger;
  *_zn_forge(z, ray_zos, root, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, root, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, root, r.ray_mat) = ray_mat;
  *_zn_forge(z, ray_zos, root, r.ray_lip) = ray_lip;

  z->n.ray_lab = ray_zos;
}

/* _zn_forge_tail(): install a tail agent.
**
**   lid: cap at termination
**   lan: subject
**   fus: formula
*/
static inline void
_zn_forge_tail(u3_z z,
               u3_ray ray_lid,
               u3_fox lan,
               u3_fox fus)
{
  u3_ray ray_zos;

  ray_zos = _zn_push_forge(z, tail);
  *_zn_forge(z, ray_zos, tail, c.oper_ger) = u3_cm_tail;
  *_zn_forge(z, ray_zos, tail, c.ray_poq) = z->n.ray_lab;
  *_zn_forge(z, ray_zos, tail, c.ray_lid) = ray_lid;

  *_zn_forge(z, ray_zos, tail, s.lan) = lan;
  *_zn_forge(z, ray_zos, tail, s.fus) = fus;
  
  z->n.ray_lab = ray_zos;
}

/* _zn_start_link(): install a link sequence.
**
**   lid: cap at termination
**   lan: operand subject
**   sef: operand formula
**   dep: link formula
*/
static inline void
_zn_start_link(u3_z   z,
               u3_ray ray_lid,
               u3_fox lan,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray ray_lip, ray_mat;

  ray_lip = z->l.ray_cap;
  ray_mat = _zn_depart(z);

  _zn_forge_link(z, ray_lid, ray_mat, ray_lip, dep);
  _zn_forge_cook(z, z->l.ray_cap, lan, sef);
}

/* _zn_start_push(): install a push sequence.
**
**   lid: cap at termination
**   lan: operand subject
**   sef: operand formula
**   dep: push formula
*/
static inline void
_zn_start_push(u3_z   z,
               u3_ray ray_lid,
               u3_fox lan,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray ray_lip, ray_mat;

  ray_lip = z->l.ray_cap;
  ray_mat = _zn_depart(z);

  _zn_forge_push(z, ray_lid, ray_mat, ray_lip, lan, dep);
  _zn_forge_cook(z, z->l.ray_cap, lan, sef);
}

/* _zn_start_jet(): install a jet sequence.
**
**   lid: cap at termination
**   lan: operand subject
**   sef: operand formula
**   sax: jet code
*/
static inline void
_zn_start_jet(u3_z            z,
              u3_ray          ray_lid,
              u3_fox          lan,
              u3_fox          sef,
              enum u3_zj_code code_sax)
{
  u3_ray ray_lip, ray_mat;

  ray_lip = z->l.ray_cap;
  ray_mat = _zn_depart(z);

  _zn_forge_jet(z, ray_lid, ray_mat, ray_lip, code_sax);
  _zn_forge_cook(z, z->l.ray_cap, lan, sef);
}

/* _zn_start_root(): install a root sequence.
**
**   ger: operation
**   lid: cap at termination
**   lan: operand subject
**   sef: first formula
*/
static inline void
_zn_start_root(u3_z       z,
               u3_zn_oper oper_ger,
               u3_ray     ray_lid,
               u3_fox     lan,
               u3_fox     sef)
{
  u3_ray ray_lip, ray_mat;

  ray_lip = z->l.ray_cap;
  ray_mat = _zn_depart(z);

  _zn_forge_root(z, oper_ger, ray_lid, ray_mat, ray_lip);
  _zn_forge_cook(z, z->l.ray_cap, lan, sef);
}

/* _zn_start_goto(): install a goto sequence.
**
**   lid: cap at termination
**   lan: subject
**   fus: target formula
*/
static inline void
_zn_start_goto(u3_z   z,
               u3_ray ray_lid,
               u3_fox lan, 
               u3_fox fus)
{
#if 1
  u3_fox ged, nar, wid, cov;

  if ( u3_yes == u3_lr_fork(z, fus, &ged, &nar) ) {
    /* ged: subject formula
    ** nar: formula formula
    */
    if ( (u3_yes == u3_lr_p(z, nar, 0, &wid)) &&
         (u3_yes == u3_lr_pat(z, wid)) )
    {
      /* wid: formula axis
      ** dep: static formula
      */
      u3_rat dep = u3_lr_twig(z, wid, lan);

      if ( u3_none != dep ) {
        enum u3_zj_code code_sax;

        if ( u3_zj_code_none != (code_sax = u3_zj_look(z, dep)) ) {
          _zn_start_jet(z, ray_lid, lan, ged, code_sax);
        } 
        else {
          _zn_start_link(z, ray_lid, lan, ged, dep);
        }
        return;
      }
    }
    else if ( u3_yes == u3_lr_p(z, nar, 1, &cov) ) {
      /* cov: static formula
      */
      _zn_start_link(z, ray_lid, lan, ged, cov);
      return;
    }
  }
#endif

  /* Default handling.
  */
  _zn_start_root(z, u3_cm_goto, ray_lid, lan, fus);
}

/* _zn_start_mate(): install a mate sequence.
**
**   lid: cap at termination
**   pod: jet-computed product
**   lan: subject
**   sef: formula
*/
static inline void
_zn_start_mate(u3_z   z,
               u3_ray ray_lid,
               u3_fox pod,
               u3_fox lan, 
               u3_fox sef)
{
  u3_ray ray_lip, ray_mat;

  ray_lip = z->l.ray_cap;
  ray_mat = _zn_depart(z);

  _zn_forge_mate(z, ray_lid, ray_mat, ray_lip, pod);
  _zn_forge_cook(z, z->l.ray_cap, lan, sef);
}

/* _zn_start_pick(): install a pick sequence.
**
**   lid: cap at termination
**   lan: subject
**   cor: test formula
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_start_pick(u3_z   z,
               u3_ray ray_lid,
               u3_fox lan,
               u3_fox cor,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray ray_lip, ray_mat;

  ray_lip = z->l.ray_cap;
  ray_mat = _zn_depart(z);

  _zn_forge_pick(z, ray_lid, ray_mat, ray_lip, lan, feg, paf);
  _zn_forge_cook(z, z->l.ray_cap, lan, cor);
}

/* u3_z_run():
**
**   Execute (nock b c) and set *a to the result.  If this succeeds,
**   return 0.  Otherwise, return u3_cm_exit or u3_cm_fail.
**
**   If (d) is nonzero, set profiling data.
*/
u3_fox
u3_z_run(u3_z z,
         u3_fox            *a,
         u3_fox            b,
         u3_fox            c,
         struct u3_z_bench *d)
{
  /* Initialize benchmarks.
  */
  if ( d ) {
    d->d_ruy = 0;
    u3_lm_water(z, &d->w_vil, &d->w_tew);
    d->w_maz = d->w_vil;
    d->w_buc = d->w_tew;
  }

  /* Install initial instruction.
  */
  *a = u3_none;
  _zn_forge_fine(z, z->l.ray_cap);
  _zn_forge_cook(z, z->l.ray_cap, b, c);

  while ( 1 ) {
    /* Preamble - miscellaneous noncomputational operations.
    */
    {
      /* Test for memory exhaustion.  No agent can allocate more
      ** than 64 words without another check.
      **
      ** For faster performance, this should be per-operation.
      */
      if ( u3_no == u3_lm_open(z, 64) ) {
        c3_w w_maz, w_buc;

        u3_lm_water(z, &w_maz, &w_buc);
        printf("not open: maz %d, buc %d\n", w_maz, w_buc);
        return u3_cm_fail;
      }

      /* Update benchmark statistics.
      */
      if ( d ) {
        c3_w w_nox, w_zur;

        u3_lm_water(z, &w_nox, &w_zur);
        d->w_maz = c3_max(d->w_maz, w_nox);
        d->w_buc = c3_max(d->w_buc, w_zur);

        d->d_ruy++;
      }
    }

    /* Body - main body of the loop.
    */
    {
      /* bip: agent.
      ** ger: operator.
      */
      u3_ray     ray_bip = z->n.ray_lab;
      u3_ray     ray_poq;
      u3_zn_oper oper_ger;

      /* Unload opcode and following agent.
      */
        oper_ger = *_zn_anvil(z, ray_bip, any, f.c.oper_ger);
        ray_poq = *_zn_anvil(z, ray_bip, any, f.c.ray_poq);

      /* Remove this agent from the agenda.
      ** Free its memory from the top of the cap.
      */
        z->n.ray_lab = ray_poq;
        z->l.ray_cap = ray_bip;

      /* Load and execute the operation.
      */
        switch ( oper_ger ) {
          default: c3_assert(0);

#           include "op/cons.c"
#           include "op/cook.c"
#           include "op/drop.c"

#           include "op/fine.c"
#           include "op/jet.c"
#           include "op/link.c"
#           include "op/push.c"
#           include "op/mate.c"

#           include "op/pick.c"
#           include "op/root.c"
#           include "op/tail.c"
        }
    }
  }
}
