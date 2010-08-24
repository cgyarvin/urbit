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
            u3_ray mat_ray)
{
  u3_lm_flop(z, mat_ray);
}

/* _zn_complete(): complete a calculation.
**
**   lid: destination of calculation
**   lam: result
*/
static inline void
_zn_complete(u3_z   z,
             u3_ray lid_ray,
             u3_fox lam)
{
  {
    c3_assert(u3_ray_beam(lid_ray) == u3_ray_beam(z->l.cap_ray));
    c3_assert(u3_ray_beam(lid_ray) == u3_ray_beam(z->l.mat_ray));
    c3_assert(lid_ray <= z->l.cap_ray);
    c3_assert(lid_ray >= z->l.mat_ray);
  }

  z->l.cap_ray = lid_ray;

  _zn_push_word(z, lam);
}

/* _zn_forge_cons(): install a cons agent.
**
**   lid: cap at termination
*/
static inline void
_zn_forge_cons(u3_z   z,
               u3_ray lid_ray)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, cons);
  *_zn_forge(z, zos_ray, cons, c.ger_op) = c3__cons;
  *_zn_forge(z, zos_ray, cons, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, cons, c.lid_ray) = lid_ray;

  z->n.lab_ray = zos_ray;
}

/* _zn_forge_cook(): install a cook agent.
**
**   lid: cap at termination
**   lan: subject
**   sef: formula
*/
static inline void
_zn_forge_cook(u3_z z,
               u3_ray lid_ray,
               u3_fox lan,
               u3_fox sef)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, cook);
  *_zn_forge(z, zos_ray, cook, c.ger_op) = c3__cook;
  *_zn_forge(z, zos_ray, cook, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, cook, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, cook, s.lan) = lan;
  *_zn_forge(z, zos_ray, cook, s.sef) = sef;
  
  z->n.lab_ray = zos_ray;
}

/* _zn_forge_drop(): install a drop agent.
**
**   lid: cap at termination
*/
static inline void
_zn_forge_drop(u3_z   z,
               u3_ray lid_ray)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, drop);
  *_zn_forge(z, zos_ray, drop, c.ger_op) = c3__drop;
  *_zn_forge(z, zos_ray, drop, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, drop, c.lid_ray) = lid_ray;

  z->n.lab_ray = zos_ray;
}

/* _zn_forge_fine(): install a fine agent.
**
**   lid: cap at termination
*/
static inline void
_zn_forge_fine(u3_z   z,
               u3_ray lid_ray)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, fine);
  *_zn_forge(z, zos_ray, fine, c.ger_op) = c3__fine;
  *_zn_forge(z, zos_ray, fine, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, fine, c.lid_ray) = lid_ray;

  z->n.lab_ray = zos_ray;
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
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox dep)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, link);
  *_zn_forge(z, zos_ray, link, c.ger_op) = c3__link;
  *_zn_forge(z, zos_ray, link, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, link, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, link, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, link, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, link, s.dep) = dep;

  z->n.lab_ray = zos_ray;
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
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox lan,
               u3_fox dep)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, push);
  *_zn_forge(z, zos_ray, push, c.ger_op) = c3__push;
  *_zn_forge(z, zos_ray, push, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, push, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, push, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, push, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, push, s.lan) = lan;
  *_zn_forge(z, zos_ray, push, s.dep) = dep;

  z->n.lab_ray = zos_ray;
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
              u3_ray          lid_ray,
              u3_ray          mat_ray,
              u3_ray          lip_ray,
              enum u3_zj_code sax_code)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, jet);
  *_zn_forge(z, zos_ray, jet, c.ger_op) = c3__jet;
  *_zn_forge(z, zos_ray, jet, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, jet, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, jet, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, jet, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, jet, s.sax_w) = sax_code;

  z->n.lab_ray = zos_ray;
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
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox pod)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, mate);
  *_zn_forge(z, zos_ray, mate, c.ger_op) = c3__mate;
  *_zn_forge(z, zos_ray, mate, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, mate, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, mate, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, mate, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, mate, s.pod) = pod;
  
  z->n.lab_ray = zos_ray;
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
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox lan,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, pick);
  *_zn_forge(z, zos_ray, pick, c.ger_op) = c3__pick;
  *_zn_forge(z, zos_ray, pick, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, pick, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, pick, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, pick, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, pick, s.lan) = lan;
  *_zn_forge(z, zos_ray, pick, s.feg) = feg;
  *_zn_forge(z, zos_ray, pick, s.paf) = paf;
  
  z->n.lab_ray = zos_ray;
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
               u3_zn_oper ger_op,
               u3_ray     lid_ray,
               u3_ray     mat_ray,
               u3_ray     lip_ray)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, root);
  *_zn_forge(z, zos_ray, root, c.ger_op) = ger_op;
  *_zn_forge(z, zos_ray, root, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, root, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, root, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, root, r.lip_ray) = lip_ray;

  z->n.lab_ray = zos_ray;
}

/* _zn_forge_tail(): install a tail agent.
**
**   lid: cap at termination
**   lan: subject
**   fus: formula
*/
static inline void
_zn_forge_tail(u3_z z,
               u3_ray lid_ray,
               u3_fox lan,
               u3_fox fus)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, tail);
  *_zn_forge(z, zos_ray, tail, c.ger_op) = c3__tail;
  *_zn_forge(z, zos_ray, tail, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, tail, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, tail, s.lan) = lan;
  *_zn_forge(z, zos_ray, tail, s.fus) = fus;
  
  z->n.lab_ray = zos_ray;
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
               u3_ray lid_ray,
               u3_fox lan,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_link(z, lid_ray, mat_ray, lip_ray, dep);
  _zn_forge_cook(z, z->l.cap_ray, lan, sef);
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
               u3_ray lid_ray,
               u3_fox lan,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_push(z, lid_ray, mat_ray, lip_ray, lan, dep);
  _zn_forge_cook(z, z->l.cap_ray, lan, sef);
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
              u3_ray          lid_ray,
              u3_fox          lan,
              u3_fox          sef,
              enum u3_zj_code sax_code)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_jet(z, lid_ray, mat_ray, lip_ray, sax_code);
  _zn_forge_cook(z, z->l.cap_ray, lan, sef);
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
               u3_zn_oper ger_op,
               u3_ray     lid_ray,
               u3_fox     lan,
               u3_fox     sef)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_root(z, ger_op, lid_ray, mat_ray, lip_ray);
  _zn_forge_cook(z, z->l.cap_ray, lan, sef);
}

/* _zn_start_goto(): install a goto sequence.
**
**   lid: cap at termination
**   lan: subject
**   fus: target formula
*/
static inline void
_zn_start_goto(u3_z   z,
               u3_ray lid_ray,
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
         (u3_yes == u3_lr_stud(z, wid)) )
    {
      /* wid: formula axis
      ** dep: static formula
      */
      u3_rat dep = u3_lr_twig(z, wid, lan);

      if ( u3_none != dep ) {
        enum u3_zj_code sax_code;

        if ( u3_zj_code_none != (sax_code = u3_zj_look(z, dep)) ) {
          _zn_start_jet(z, lid_ray, lan, ged, sax_code);
        } 
        else {
          _zn_start_link(z, lid_ray, lan, ged, dep);
        }
        return;
      }
    }
    else if ( u3_yes == u3_lr_p(z, nar, 1, &cov) ) {
      /* cov: static formula
      */
      _zn_start_link(z, lid_ray, lan, ged, cov);
      return;
    }
  }
#endif

  /* Default handling.
  */
  _zn_start_root(z, c3__goto, lid_ray, lan, fus);
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
               u3_ray lid_ray,
               u3_fox pod,
               u3_fox lan, 
               u3_fox sef)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_mate(z, lid_ray, mat_ray, lip_ray, pod);
  _zn_forge_cook(z, z->l.cap_ray, lan, sef);
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
               u3_ray lid_ray,
               u3_fox lan,
               u3_fox cor,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_pick(z, lid_ray, mat_ray, lip_ray, lan, feg, paf);
  _zn_forge_cook(z, z->l.cap_ray, lan, cor);
}

/* uz_z_mung():
**
**   As uz_z_run(), but [b] is gate and [c] is sample.
*/
u3_fox
u3_z_mung(u3_z              z,
          u3_fox            *a,
          u3_fox            b,
          u3_fox            c,
          struct u3_z_bench *d)
{
  u3_fox gat = b;
  u3_fox sam = c;

  if ( u3_no == u3_lr_dust(z, gat) ) {
    return c3__exit;
  } else {
    u3_fox ham = u3_h(z, gat);
    u3_fox bat = u3_t(z, gat);

    if ( u3_no == u3_lr_dust(z, ham) ) {
      return c3__exit;
    } else {
      // XX: memory behavior not quite perfect.
      //
      u3_fox con = u3_t(z, ham);
      u3_fox sub = u3_ln_cell(z, u3_ln_cell(z, sam, con), bat);
      u3_fox fol = bat;
      
      return u3_z_run(z, a, sub, fol, d);
    }
  }
}

/* u3_z_run():
**
**   Execute (nock b c) and set *a to the result.  If this succeeds,
**   return 0.  Otherwise, return c3__exit or c3__fail.
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
    d->ruy_d = 0;
    u3_lm_water(z, &d->vil_w, &d->tew_w);
    d->maz_w = d->vil_w;
    d->buc_w = d->tew_w;
  }

  /* Install initial instruction - or fire direct jet.
  */
  {
    enum u3_zj_code sax_code;

    if ( u3_zj_code_none != (sax_code = u3_zj_look(z, c)) ) {
      u3_mote bem = u3_zj_fire(z, a, sax_code, b);
      
      if ( bem != c3__punt ) {
        return bem;
      }
    } 
  }
  *a = u3_none;
  _zn_forge_fine(z, z->l.cap_ray);
  _zn_forge_cook(z, z->l.cap_ray, b, c);

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
        c3_w maz_w, buc_w;

        u3_lm_water(z, &maz_w, &buc_w);
        printf("not open: maz %d, buc %d\n", maz_w, buc_w);
        return c3__fail;
      }

      /* Update benchmark statistics.
      */
      if ( d ) {
        c3_w nox_w, zur_w;

        u3_lm_water(z, &nox_w, &zur_w);
        d->maz_w = c3_max(d->maz_w, nox_w);
        d->buc_w = c3_max(d->buc_w, zur_w);

        d->ruy_d++;
      }
    }

    /* Body - main body of the loop.
    */
    {
      /* bip: agent.
      ** ger: operator.
      */
      u3_ray     bip_ray = z->n.lab_ray;
      u3_ray     poq_ray;
      u3_zn_oper ger_op;

      /* Unload opcode and following agent.
      */
        ger_op = *_zn_anvil(z, bip_ray, any, f.c.ger_op);
        poq_ray = *_zn_anvil(z, bip_ray, any, f.c.poq_ray);

      /* Remove this agent from the agenda.
      ** Pop it off the cap.
      */
        z->n.lab_ray = poq_ray;
        z->l.cap_ray = bip_ray;

      /* Load and execute the operation.
      */
        switch ( ger_op ) {
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
