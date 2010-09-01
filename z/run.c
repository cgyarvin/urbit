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


#define U3_ZN_FORGE
# include "op/bask.c"
# include "op/cons.c"
# include "op/nock.c"
# include "op/drop.c"
# include "op/fine.c"
# include "op/hint.c"
# include "op/jet.c"
# include "op/flac.c"
# include "op/mate.c"
# include "op/trol.c"
# include "op/gant.c"
# include "op/root.c"
# include "op/tail.c"
#undef U3_ZN_FORGE

/* _zn_start_flac(): install a flac sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   dep: flac formula
*/
static inline void
_zn_start_flac(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_flac(z, lid_ray, mat_ray, lip_ray, dep);
  _zn_forge_nock(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_gant(): install a gant sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   dep: gant formula
*/
static inline void
_zn_start_gant(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_gant(z, lid_ray, mat_ray, lip_ray, bus, dep);
  _zn_forge_nock(z, z->l.cap_ray, bus, sef);
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
  _zn_forge_nock(z, z->l.cap_ray, bus, sef);
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
  _zn_forge_nock(z, z->l.cap_ray, bus, sef);
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
  _zn_forge_nock(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_sail(): install a sail sequence.
**
**   lid: cap at termination
**   bus: subject
**   fel: target formula
*/
static inline void
_zn_start_sail(u3_z   z,
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
          _zn_start_flac(z, lid_ray, bus, ged, dep);
        }
        return;
      }
    }
    else if ( u3_yes == u3_lr_p(z, nar, 1, &cov) ) {
      /* cov: static formula
      */
      _zn_start_flac(z, lid_ray, bus, ged, cov);
      return;
    }
  }
#endif

  /* Default handling.
  */
  _zn_start_root(z, c3__sail, lid_ray, bus, fel);
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
  _zn_forge_nock(z, z->l.cap_ray, bus, sef);
}

/* _zn_start_trol(): install a trol sequence.
**
**   lid: cap at termination
**   bus: subject
**   cor: test formula
**   feg: then formula
**   paf: else formula
*/
static inline void
_zn_start_trol(u3_z   z,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox cor,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = z->l.cap_ray;
  mat_ray = _zn_depart(z);

  _zn_forge_trol(z, lid_ray, mat_ray, lip_ray, bus, feg, paf);
  _zn_forge_nock(z, z->l.cap_ray, bus, cor);
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
  _zn_forge_nock(z, z->l.cap_ray, b, c);

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

      /* Load and execute the operation.
      */
      switch ( ger_op ) {
        default: c3_assert(0);

#       define U3_ZN_OP
#         include "op/bask.c"
#         include "op/cons.c"
#         include "op/nock.c"
#         include "op/drop.c"
#         include "op/fine.c"
#         include "op/hint.c"
#         include "op/jet.c"
#         include "op/flac.c"
#         include "op/mate.c"
#         include "op/trol.c"
#         include "op/gant.c"
#         include "op/root.c"
#         include "op/tail.c"
#       undef U3_ZN_OP 
      }
    }
  }
}
