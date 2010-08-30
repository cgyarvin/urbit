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

/* _zn_free(): free memory in a mane.  Caller must know length.
*/
static inline void
_zn_free(u3_z z,
         u3_ray man_ray,
         c3_w   wor_w)
{
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
**   bus: subject
**   sef: formula
*/
static inline void
_zn_forge_cook(u3_z z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, cook);
  *_zn_forge(z, zos_ray, cook, c.ger_op) = c3__cook;
  *_zn_forge(z, zos_ray, cook, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, cook, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, cook, s.bus) = bus;
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
               u3_fox bus,
               u3_fox dep)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, push);
  *_zn_forge(z, zos_ray, push, c.ger_op) = c3__push;
  *_zn_forge(z, zos_ray, push, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, push, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, push, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, push, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, push, s.bus) = bus;
  *_zn_forge(z, zos_ray, push, s.dep) = dep;

  z->n.lab_ray = zos_ray;
}

/* _zn_forge_hint(): install a hint agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: content formula.
*/
static inline void
_zn_forge_hint(u3_z   z,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
               u3_fox dep)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, hint);
  *_zn_forge(z, zos_ray, hint, c.ger_op) = c3__hint;
  *_zn_forge(z, zos_ray, hint, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, hint, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, hint, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, hint, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, hint, s.bus) = bus;
  *_zn_forge(z, zos_ray, hint, s.dep) = dep;

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
**   bus: subject
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
**   bus: subject
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_forge_pick(u3_z z,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox bus,
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

  *_zn_forge(z, zos_ray, pick, s.bus) = bus;
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
**   bus: subject
**   fel: formula
*/
static inline void
_zn_forge_tail(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox fel)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, tail);
  *_zn_forge(z, zos_ray, tail, c.ger_op) = c3__tail;
  *_zn_forge(z, zos_ray, tail, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, tail, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, tail, s.bus) = bus;
  *_zn_forge(z, zos_ray, tail, s.fel) = fel;
  
  z->n.lab_ray = zos_ray;
}

/* _zn_forge_bask(): install a basket sequence.
*/
static inline c3_b
_zn_forge_bask(u3_z    z,
               u3_ray  lid_ray,
               c3_w    num_w,
               c3_w    dem_w)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, bask);
  *_zn_forge(z, zos_ray, bask, c.ger_op) = c3__bask;
  *_zn_forge(z, zos_ray, bask, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, bask, c.lid_ray) = lid_ray;

  {
    c3_w lef_w = z->l.bat_nit - 
                 (u3_ray_b(z->l.hat_ray) + 
                  u3_ray_b(z->l.cap_ray) + 128);

    c3_w wor_w = num_w * (lef_w / dem_w);

    *_zn_forge(z, zos_ray, bask, s.wor_w) = wor_w;
    z->l.cap_ray += wor_w;
  }
  z->n.lab_ray = zos_ray;
  return 1;
}

/* _zn_start_link(): install a link sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   dep: link formula
*/
static inline void
_zn_start_link(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_link(z, lid_ray, mat_ray, lip_ray, dep);
  _zn_forge_cook(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_push(): install a push sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   dep: push formula
*/
static inline void
_zn_start_push(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_push(z, lid_ray, mat_ray, lip_ray, bus, dep);
  _zn_forge_cook(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_hint(): install a hint sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: hint formula
**   dep: content formula
*/
static inline void
_zn_start_hint(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_hint(z, lid_ray, mat_ray, lip_ray, bus, dep);
  _zn_forge_cook(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_jet(): install a jet sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   sax: jet code
*/
static inline void
_zn_start_jet(u3_z            z,
              u3_ray          lid_ray,
              u3_fox          bus,
              u3_fox          sef,
              enum u3_zj_code sax_code)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_jet(z, lid_ray, mat_ray, lip_ray, sax_code);
  _zn_forge_cook(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_root(): install a root sequence.
**
**   ger: operation
**   lid: cap at termination
**   bus: operand subject
**   sef: first formula
*/
static inline void
_zn_start_root(u3_z       z,
               u3_zn_oper ger_op,
               u3_ray     lid_ray,
               u3_fox     bus,
               u3_fox     sef)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_root(z, ger_op, lid_ray, mat_ray, lip_ray);
  _zn_forge_cook(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_goto(): install a goto sequence.
**
**   lid: cap at termination
**   bus: subject
**   fel: target formula
*/
static inline void
_zn_start_goto(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus, 
               u3_fox fel)
{
#if 1
  u3_fox ged, nar, wid, cov;

  if ( u3_yes == u3_lr_fork(z, fel, &ged, &nar) ) {
    /* ged: subject formula
    ** nar: formula formula
    */
    if ( (u3_yes == u3_lr_p(z, nar, 0, &wid)) &&
         (u3_yes == u3_lr_stud(z, wid)) )
    {
      /* wid: formula axis
      ** dep: static formula
      */
      u3_rat dep = u3_lr_twig(z, wid, bus);

      if ( u3_none != dep ) {
        enum u3_zj_code sax_code;

        if ( u3_zj_code_none != (sax_code = u3_zj_look(z, dep)) ) {
          _zn_start_jet(z, lid_ray, bus, ged, sax_code);
        } 
        else {
          _zn_start_link(z, lid_ray, bus, ged, dep);
        }
        return;
      }
    }
    else if ( u3_yes == u3_lr_p(z, nar, 1, &cov) ) {
      /* cov: static formula
      */
      _zn_start_link(z, lid_ray, bus, ged, cov);
      return;
    }
  }
#endif

  /* Default handling.
  */
  _zn_start_root(z, c3__goto, lid_ray, bus, fel);
}

/* _zn_start_mate(): install a mate sequence.
**
**   lid: cap at termination
**   pod: jet-computed product
**   bus: subject
**   sef: formula
*/
static inline void
_zn_start_mate(u3_z   z,
               u3_ray lid_ray,
               u3_fox pod,
               u3_fox bus, 
               u3_fox sef)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_mate(z, lid_ray, mat_ray, lip_ray, pod);
  _zn_forge_cook(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_pick(): install a pick sequence.
**
**   lid: cap at termination
**   bus: subject
**   cor: test formula
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_start_pick(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox cor,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_pick(z, lid_ray, mat_ray, lip_ray, bus, feg, paf);
  _zn_forge_cook(z, z->l.cap_ray, bus, cor);
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
    /* Preamble - miscelbuseous noncomputational operations.
    */
    {
      /* Test for memory exhaustion.  No agent can allocate more
      ** than 256 words without another check.
      **
      ** For faster performance, this should be per-operation.
      */
      if ( u3_no == u3_lm_open(z, 256) ) {
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

#   define _zn_bip_cons(field) *_zn_anvil(z, bip_ray, cons, field)
#   define _zn_bip_bask(field) *_zn_anvil(z, bip_ray, bask, field)
#   define _zn_bip_cook(field) *_zn_anvil(z, bip_ray, cook, field)
#   define _zn_bip_drop(field) *_zn_anvil(z, bip_ray, drop, field)
#   define _zn_bip_fine(field) *_zn_anvil(z, bip_ray, fine, field)
#   define _zn_bip_jet(field)  *_zn_anvil(z, bip_ray, jet, field)
#   define _zn_bip_hint(field) *_zn_anvil(z, bip_ray, hint, field)
#   define _zn_bip_link(field) *_zn_anvil(z, bip_ray, link, field)
#   define _zn_bip_mate(field) *_zn_anvil(z, bip_ray, mate, field)
#   define _zn_bip_pick(field) *_zn_anvil(z, bip_ray, pick, field)
#   define _zn_bip_push(field) *_zn_anvil(z, bip_ray, push, field)
#   define _zn_bip_root(field) *_zn_anvil(z, bip_ray, root, field)
#   define _zn_bip_tail(field) *_zn_anvil(z, bip_ray, tail, field)

      /* Load and execute the operation.
      */
      switch ( ger_op ) {
        default: c3_assert(0);
      /* 
      **  cons
      */
        case c3__cons: {
          u3_fox pux = _zn_bip_cons(d.pux);
          u3_fox nol = _zn_bip_cons(d.nol);
          u3_fox mal;
         
          /* We know this will succeed because we prereserve in the 
          ** main loop.
          */
          mal = u3_ln_cell(z, pux, nol);

          _zn_complete(z, _zn_bip_cons(f.c.lid_ray), mal);
          break;
        }
      /*
      **  cook
      */
        case c3__cook: {
          u3_ray lid_ray = _zn_bip_cook(f.c.lid_ray);
          u3_fox bus     = _zn_bip_cook(f.s.bus);
          u3_fox sef     = _zn_bip_cook(f.s.sef);

          if ( u3_no == u3_lr_dust(z, sef) ) {
            return c3__exit;
          }
          else {
            u3_fox hib = u3_h(z, sef);
            u3_fox fel = u3_t(z, sef);

            if ( u3_yes == u3_lr_dust(z, hib) ) {
              _zn_forge_cons(z, lid_ray);
              _zn_forge_tail(z, z->l.cap_ray, bus, fel);
              _zn_forge_cook(z, z->l.cap_ray, bus, hib);
            }
            else {
              switch ( hib ) {
                default: return c3__exit;

                case u3_nock_frag: {
                  u3_fox pob = u3_lr_twig(z, fel, bus);

                  if ( u3_none == pob ) {
                    return c3__exit;
                  }
                  else {
                    u3_fox vik = u3_ln_ice(z, pob);

                    if ( u3_none == vik ) {
                      return c3__fail;
                    }
                    else {
                      _zn_complete(z, lid_ray, vik);
                    }
                  }
                  break;
                }

                case u3_nock_bone: {
                  u3_fox vik = u3_ln_ice(z, fel);

                  if ( u3_none == vik ) {
                    return c3__fail;
                  }
                  else {
                    _zn_complete(z, lid_ray, vik);
                  }
                  break;
                }

                case u3_nock_sail: {
                  _zn_start_goto(z, lid_ray, bus, fel); 
                  break;
                }
                case u3_nock_dust: {
                  _zn_start_root(z, c3__tap, lid_ray, bus, fel); 
                  break;
                }
                case u3_nock_vint: {
                  _zn_start_root(z, c3__inc, lid_ray, bus, fel); 
                  break;
                }
                case u3_nock_sing: {
                  _zn_start_root(z, c3__eq,  lid_ray, bus, fel); 
                  break;
                }
                case u3_nock_trol: {
                  if ( u3_no == u3_lr_dust(z, fel) ) {
                    return c3__exit;
                  } 
                  else {
                    u3_fox p_fel = u3_h(z, fel);
                    u3_fox qr_fel = u3_t(z, fel);

                    if ( u3_no == u3_lr_dust(z, qr_fel) ) {
                      return c3__exit;
                    }
                    else {
                      u3_fox q_fel = u3_h(z, qr_fel);
                      u3_fox r_fel = u3_t(z, qr_fel);

                      _zn_start_pick(z, lid_ray, bus, p_fel, q_fel, r_fel);
                    }
                  }
                  break;
                }

                case u3_nock_flac: {
                  if ( u3_no == u3_lr_dust(z, fel) ) {
                    return c3__exit;
                  }
                  else {
                    _zn_start_link
                      (z, lid_ray, bus, u3_h(z, fel), u3_t(z, fel));
                    break;
                  }
                }
                case u3_nock_gant: {
                  if ( u3_no == u3_lr_dust(z, fel) ) {
                    return c3__exit;
                  }
                  else {
                    _zn_start_push
                      (z, lid_ray, bus, u3_h(z, fel), u3_t(z, fel));
                    break;
                  }
                }
                case u3_nock_hint: {
                  if ( u3_no == u3_lr_dust(z, fel) ) {
                    return c3__exit;
                  }
                  else {
                    _zn_start_hint
                      (z, lid_ray, bus, u3_h(z, fel), u3_t(z, fel));
                    break;
                  }
                }
                case u3_nock_coat: {
                  if ( u3_no == u3_lr_dust(z, fel) ) {
                    return c3__exit;
                  }
                  else {
                    u3_fox vik = u3_ln_ice(z, u3_t(z, fel));

                    if ( u3_none == vik ) {
                      return c3__fail;
                    }
                    else {
                      u3_fox cor = u3_ln_cell(z, bus, vik);
                      u3_fox pup = u3_h(z, fel);

                      if ( 0 != pup ) {
                        u3_zj_load(z, pup, cor);
                      }
                      _zn_complete(z, lid_ray, u3_ln_cell(z, bus, vik));
                    }
                    break;
                  }
                }
              }
            }
          }
          break;
        }
      /*
      **  drop
      */
        case c3__drop: {
          u3_fox gus = _zn_bip_drop(d.gus);

          _zn_complete(z, _zn_bip_drop(f.c.lid_ray), gus);
          break;
        }
      /*
      **  fine
      */
        case c3__fine: {
          u3_fox gus = _zn_bip_fine(d.gus);

          *a = gus;
          if ( d ) {
            d->cop_w = z->l.cop_w;
          }
          return 0;
        }
      /*
      **  jet
      */
        case c3__jet: {
          _zn_retreat(z, _zn_bip_jet(f.r.mat_ray));
          {
            /* sax: jet code
            ** gus: computed gate
            ** zec: result code
            ** pod: result
            */
            u3_ray  lid_ray = _zn_bip_jet(f.c.lid_ray);
            u3_fox  sax     = _zn_bip_jet(f.s.sax_w);
            u3_fox  gus     = _zn_bip_jet(d.gus);
            u3_mote zec;
            u3_fox  pod;

            if ( u3_yes == u3_lr_dust(z, gus) ) {
              zec = u3_zj_fire(z, &pod, sax, gus);
            } 
            else zec = c3__punt;

            switch ( zec ) {
              case 0: 
                _zn_complete(z, lid_ray, pod);
                break;

              case c3__fail:
              case c3__exit:
                return zec;
   
              case c3__punt: {
                u3_fox bat = u3_zj_bat(z, sax);

                _zn_forge_cook(z, lid_ray, gus, bat);
                break;
              }
              case c3__test: {
                u3_fox bat = u3_zj_bat(z, sax);

                _zn_start_mate(z, lid_ray, pod, gus, bat);
                break;
              }
              default: c3_assert(!"unknown error");
            }
          }
          break;
        }
      /*
      **  bask
      */
        case c3__bask: {
          c3_w   wor_w   = _zn_bip_bask(f.s.wor_w);
          u3_ray anv_ray = bip_ray + c3_wiseof(struct u3_zn_forge_bask) + wor_w;
          u3_fox gus     = *u3_at_ray(&z->l, anv_ray);

          _zn_complete(z, _zn_bip_bask(f.c.lid_ray), gus);
          break;
        }
      /*
      **  hint
      */
        case c3__hint: {
          _zn_retreat(z, _zn_bip_hint(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_hint(f.c.lid_ray);
            u3_fox bus     = _zn_bip_hint(f.s.bus);
            u3_fox dep     = _zn_bip_hint(f.s.dep);
            u3_fox gus     = _zn_bip_hint(d.gus);

            if ( u3_no == u3_lr_dust(z, gus) ) {
              _zn_forge_cook(z, lid_ray, bus, dep);
            }
            else { 
              u3_fox p_gus, q_gus;

              if ( (u3_yes == u3_lr_pq(z, gus, c3__bask, &p_gus, &q_gus)) &&
                   u3_rat_is_cat(p_gus) &&
                   u3_rat_is_cat(q_gus) &&
                   (q_gus > 0) &&
                   (p_gus > 0) &&
                   (p_gus < q_gus) )
              {
                if ( _zn_forge_bask(z, lid_ray, p_gus, q_gus) ) {
                  _zn_forge_cook(z, z->l.cap_ray, bus, dep);
                } else {
                  _zn_forge_cook(z, lid_ray, bus, dep);
                }
              }
              else if ( u3_yes == u3_lr_p(z, gus, c3__blog, &p_gus) ) {
                u3_b_print(z, "log", u3_t(z, gus));
              }
              else {
                _zn_forge_cook(z, lid_ray, bus, dep);
              }
            }
          }
          break;
        }
      /*
      **  link
      */
        case c3__link: {
          _zn_retreat(z, _zn_bip_link(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_link(f.c.lid_ray);
            u3_ray lip_ray = _zn_bip_link(f.r.lip_ray);
            u3_fox dep     = _zn_bip_link(f.s.dep);
            u3_fox gus     = _zn_bip_link(d.gus);
#if 1
            if ( (lid_ray != lip_ray) && (lip_ray != z->l.cap_ray) ) {
              /* Tail optimization.
              **
              ** We seek to elide the segment whose bottom is [lid_ray],
              ** and whose top is [lip_ray].
              **
              ** [lid_ray] is the cap pointer at the end of the calculation.
              ** [lip_ray] is the base of the subject area.  Call the region
              ** from [lid_ray] to [lip_ray] region B, and the region from
              ** [lip_ray] to [l->cap_ray] region A.
              **
              ** Because it is above [lid_ray], we know that region B will be
              ** discarded after (nock gus dep) completes.  The question is
              ** whether it can be discarded *before* this link completion.
              **
              ** We know [dep] is a static formula.  So only [gus], the
              ** subject we have just produced, can point into A or B.  
              **
              ** It must point into A, or A would be empty.  The relevant
              ** question therefore is: does A point into B?
              **
              ** If not, we may tamp - relocating [gus] as we elide region B,
              ** and slide region A down on top of it.  If not, we can't.
              **
              ** Without tail optimization, we cannot loop without leaking.
              **
              ** Note that both detecting and applying this optimization has
              ** a cost of the same order as the size of A.  Moreover, if we
              ** fail to apply the optimization, we consume this same order of
              ** memory.  Consistency minimizes performance surprises.
              */
              if ( u3_yes == u3_lm_clear(z, gus, lid_ray, lip_ray) ) {
                /* Clear to tamp.
                */
                gus = u3_lm_tamp(z, gus, lid_ray, lip_ray);
              } 
              else {
                /* Not clear to tamp.
                ** 
                ** So that further attempts to tamp in this chain can work,
                ** the cook agent that completes the link must not tamp to
                ** [lid], but rather to the current cap.  Thus, to avoid
                ** leaking, we must install a drop agent to free.
                **
                ** Otherwise, the interpreter will detect a tail violation
                ** on every call, as it tries to tamp this entire region.
                ** It will thus fail to tamp, and leak, when it should be
                ** tamping on every call but the first.
                */
                _zn_forge_drop(z, lid_ray);
                lid_ray = z->l.cap_ray;
              }
            }
#endif
            _zn_forge_cook(z, lid_ray, gus, dep);
          }
          break;
        }
      /*
      **  push
      */
        case c3__push: {
          u3_ray mat_ray = _zn_bip_push(f.r.mat_ray);
          u3_ray lid_ray = _zn_bip_push(f.c.lid_ray);
          u3_fox dep     = _zn_bip_push(f.s.dep);
          u3_fox bus     = _zn_bip_push(f.s.bus);
          u3_fox gus     = _zn_bip_push(d.gus);
          u3_fox mal;
          
          mal = u3_ln_cell(z, gus, bus);
          _zn_retreat(z, mat_ray);

          _zn_forge_cook(z, lid_ray, mal, dep);

          break;
        }
      /*
      **  mate
      */
        case c3__mate: {
          _zn_retreat(z, _zn_bip_mate(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_mate(f.c.lid_ray);
            u3_fox pod     = _zn_bip_mate(f.s.pod);
            u3_fox gus     = _zn_bip_mate(d.gus);

            if ( u3_yes == u3_lr_sing(z, pod, gus) ) {
              _zn_complete(z, lid_ray, pod);
            }
            else {
              printf("mate: jet mismatch\n");

              u3_b_print(&z->l, "hard", pod);
              u3_b_print(&z->l, "soft", gus);

              return c3__fail;
            }
          }
          break;
        }
      /*
      **  pick
      */
        case c3__pick: {
          _zn_retreat(z, _zn_bip_pick(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_pick(f.c.lid_ray);
            u3_ray lip_ray = _zn_bip_pick(f.r.lip_ray);
            u3_fox bus     = _zn_bip_pick(f.s.bus);
            u3_fox feg     = _zn_bip_pick(f.s.feg);
            u3_fox paf     = _zn_bip_pick(f.s.paf);
            u3_fox gus     = _zn_bip_pick(d.gus);

            if ( 0 == gus ) {
              c3_assert(lip_ray == z->l.cap_ray);

              _zn_forge_cook(z, lid_ray, bus, feg); 
            }
            else if ( 1 == gus ) {
              c3_assert(lip_ray == z->l.cap_ray);

              _zn_forge_cook(z, lid_ray, bus, paf); 
            }
            else {
              return c3__exit;
            }
          }
          break;
        }
      /*
      **  eq
      */
        case c3__eq: {
          _zn_retreat(z, _zn_bip_root(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_root(f.c.lid_ray);
            u3_fox gus     = _zn_bip_root(d.gus);

            if ( u3_no == u3_lr_dust(z, gus) ) {
              return c3__exit;
            } else {
              u3_fox fal = u3_lr_sing(z, u3_h(z, gus), u3_t(z, gus));

              _zn_complete(z, lid_ray, fal);
            }
          }
          break;
        }
      /*
      **  goto
      */
        case c3__goto: {
          _zn_retreat(z, _zn_bip_root(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_root(f.c.lid_ray);
            u3_fox gus     = _zn_bip_root(d.gus);

            if ( u3_no == u3_lr_dust(z, gus) ) {
              return c3__exit;
            } else {
              /* bus: subject
              ** sef: formula
              */
              u3_fox bus = u3_h(z, gus);
              u3_fox sef = u3_t(z, gus);

              _zn_forge_cook(z, lid_ray, bus, sef);
            }
          }
          break;
        }
      /*
      **  inc
      */
        case c3__inc: {
          _zn_retreat(z, _zn_bip_root(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_root(f.c.lid_ray);
            u3_fox gus     = _zn_bip_root(d.gus);

            if ( u3_no == u3_lr_stud(z, gus) ) {
              return c3__exit;
            } else {
              mpz_t  mp_gus;
              u3_fox fal;
             
              u3_lr_mp(z, mp_gus, gus);
              mpz_add_ui(mp_gus, mp_gus, 1);
              fal = u3_ln_mp(z, mp_gus);

              _zn_complete(z, lid_ray, fal);
            }
          }
          break;
        }
      /*
      **  tap
      */
        case c3__tap: {
          _zn_retreat(z, _zn_bip_root(f.r.mat_ray));
          {
            u3_ray lid_ray = _zn_bip_root(f.c.lid_ray);
            u3_fox gus     = _zn_bip_root(d.gus);
            u3_fox fal     = u3_lr_dust(z, gus);

            _zn_complete(z, lid_ray, fal);
          }
          break;
        }
      /*
      **  tail
      */
        case c3__tail: {
          u3_fox gus = _zn_bip_tail(d.gus);
          u3_fox bus = _zn_bip_tail(f.s.bus);
          u3_fox fel = _zn_bip_tail(f.s.fel);

          /* Tricky: we push [gus] above the agent below,
          ** presumably a cons.
          */
          _zn_complete(z, _zn_bip_tail(f.c.lid_ray), gus);
          _zn_forge_cook(z, z->l.cap_ray, bus, fel);

          break;
        }
        }
    }
  }
}
