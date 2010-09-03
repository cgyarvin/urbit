/* x/run.c
**
** This file is in the public domain.
*/
#include "all.h"

/* _xn_depart(): depart to temporary construction.
*/
static inline u3_ray
_xn_depart(u3_x x)
{
  return u3_lm_flap(x);
}

/* _xn_retreat(): retreat from temporary construction.
**
**   mat: saved mat, from _xn_depart().
*/
static inline void
_xn_retreat(u3_x   x,
            u3_ray mat_ray)
{
  u3_lm_flop(x, mat_ray);
}

/* _xn_free(): free memory in a mane.  Caller must know length.
*/
static inline void
_xn_free(u3_x x,
         u3_ray man_ray,
         c3_w   wor_w)
{
}

/* _xn_complete(): complete a calculation.
**
**   lid: destination of calculation
**   lam: result
*/
static inline void
_xn_complete(u3_x   x,
             u3_ray lid_ray,
             u3_fox lam)
{
  {
    c3_assert(u3_ray_beam(lid_ray) == u3_ray_beam(x->l.cap_ray));
    c3_assert(u3_ray_beam(lid_ray) == u3_ray_beam(x->l.mat_ray));
    c3_assert(lid_ray <= x->l.cap_ray);
    c3_assert(lid_ray >= x->l.mat_ray);
  }

  x->l.cap_ray = lid_ray;
  _xn_push_word(x, lam);
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

/* _xn_start_flac(): install a flac sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   dep: flac formula
*/
static inline void
_xn_start_flac(u3_x   x,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_flac(x, lid_ray, mat_ray, lip_ray, dep);
  _xn_forge_nock(x, x->l.cap_ray, bus, sef);
}

/* _xn_start_gant(): install a gant sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   dep: gant formula
*/
static inline void
_xn_start_gant(u3_x   x,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_gant(x, lid_ray, mat_ray, lip_ray, bus, dep);
  _xn_forge_nock(x, x->l.cap_ray, bus, sef);
}

/* _xn_start_hint(): install a hint sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: hint formula
**   dep: content formula
*/
static inline void
_xn_start_hint(u3_x   x,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox sef,
               u3_fox dep)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_hint(x, lid_ray, mat_ray, lip_ray, bus, dep);
  _xn_forge_nock(x, x->l.cap_ray, bus, sef);
}

/* _xn_start_jet(): install a jet sequence.
**
**   lid: cap at termination
**   bus: operand subject
**   sef: operand formula
**   sax: jet code
*/
static inline void
_xn_start_jet(u3_x            x,
              u3_ray          lid_ray,
              u3_fox          bus,
              u3_fox          sef,
              enum u3_xj_code sax_code)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_jet(x, lid_ray, mat_ray, lip_ray, sax_code);
  _xn_forge_nock(x, x->l.cap_ray, bus, sef);
}

/* _xn_start_root(): install a root sequence.
**
**   ger: operation
**   lid: cap at termination
**   bus: operand subject
**   sef: first formula
*/
static inline void
_xn_start_root(u3_x       x,
               u3_xn_oper ger_op,
               u3_ray     lid_ray,
               u3_fox     bus,
               u3_fox     sef)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_root(x, ger_op, lid_ray, mat_ray, lip_ray);
  _xn_forge_nock(x, x->l.cap_ray, bus, sef);
}

/* _xn_start_sail(): install a sail sequence.
**
**   lid: cap at termination
**   bus: subject
**   fel: target formula
*/
static inline void
_xn_start_sail(u3_x   x,
               u3_ray lid_ray,
               u3_fox bus, 
               u3_fox fel)
{
#if 1
  u3_fox ged, nar, wid, cov;

  if ( u3_yes == u3_lr_fork(x, fel, &ged, &nar) ) {
    /* ged: subject formula
    ** nar: formula formula
    */
    if ( (u3_yes == u3_lr_p(x, nar, 0, &wid)) &&
         (u3_yes == u3_lr_stud(x, wid)) )
    {
      /* wid: formula axis
      ** dep: static formula
      */
      u3_rat dep = u3_lr_twig(x, wid, bus);

      if ( u3_none != dep ) {
        enum u3_xj_code sax_code;

        if ( u3_xj_code_none != (sax_code = u3_xj_look(x, dep)) ) {
          _xn_start_jet(x, lid_ray, bus, ged, sax_code);
        } 
        else {
          _xn_start_flac(x, lid_ray, bus, ged, dep);
        }
        return;
      }
    }
    else if ( u3_yes == u3_lr_p(x, nar, 1, &cov) ) {
      /* cov: static formula
      */
      _xn_start_flac(x, lid_ray, bus, ged, cov);
      return;
    }
  }
#endif

  /* Default handling.
  */
  _xn_start_root(x, c3__sail, lid_ray, bus, fel);
}

/* _xn_start_mate(): install a mate sequence.
**
**   lid: cap at termination
**   pod: jet-computed product
**   bus: subject
**   sef: formula
*/
static inline void
_xn_start_mate(u3_x   x,
               u3_ray lid_ray,
               u3_fox pod,
               u3_fox bus, 
               u3_fox sef)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_mate(x, lid_ray, mat_ray, lip_ray, pod);
  _xn_forge_nock(x, x->l.cap_ray, bus, sef);
}

/* _xn_start_trol(): install a trol sequence.
**
**   lid: cap at termination
**   bus: subject
**   cor: test formula
**   feg: then formula
**   paf: else formula
*/
static inline void
_xn_start_trol(u3_x   x,
               u3_ray lid_ray,
               u3_fox bus,
               u3_fox cor,
               u3_fox feg,
               u3_fox paf)
{
  u3_ray lip_ray, mat_ray;

  lip_ray = x->l.cap_ray;
  mat_ray = _xn_depart(x);

  _xn_forge_trol(x, lid_ray, mat_ray, lip_ray, bus, feg, paf);
  _xn_forge_nock(x, x->l.cap_ray, bus, cor);
}

/* ux_x_mung():
**
**   As ux_x_run(), but [b] is gate and [c] is sample.
*/
u3_fox
u3_x_mung(u3_x              x,
          u3_fox            *a,
          u3_fox            b,
          u3_fox            c,
          struct u3_x_bench *d)
{
  u3_fox gat = b;
  u3_fox sam = c;

  if ( u3_no == u3_lr_dust(x, gat) ) {
    return c3__exit;
  } else {
    u3_fox ham = u3_h(x, gat);
    u3_fox bat = u3_t(x, gat);

    if ( u3_no == u3_lr_dust(x, ham) ) {
      return c3__exit;
    } else {
      // XX: memory behavior not quite perfect.
      //
      u3_fox con = u3_t(x, ham);
      u3_fox sub = u3_ln_cell(x, u3_ln_cell(x, sam, con), bat);
      u3_fox fol = bat;
      
      return u3_x_run(x, a, sub, fol, d);
    }
  }
}

/* u3_x_run():
**
**   Execute (nock b c) and set *a to the result.  If this succeeds,
**   return 0.  Otherwise, return c3__exit or c3__fail.
**
**   If (d) is nonxero, set profiling data.
*/
u3_fox
u3_x_run(u3_x x,
         u3_fox            *a,
         u3_fox            b,
         u3_fox            c,
         struct u3_x_bench *d)
{
  /* Initialixe benchmarks.
  */
  if ( d ) {
    d->ruy_d = 0;
    u3_lm_water(x, &d->vil_w, &d->tew_w);
    d->max_w = d->vil_w;
    d->buc_w = d->tew_w;
  }

  /* Install initial instruction - or fire direct jet.
  */
  {
    enum u3_xj_code sax_code;

    if ( u3_xj_code_none != (sax_code = u3_xj_look(x, c)) ) {
      u3_mote bem = u3_xj_fire(x, a, sax_code, b);
      
      if ( bem != c3__punt ) {
        return bem;
      }
    } 
  }
  *a = u3_none;
  _xn_forge_fine(x, x->l.cap_ray);
  _xn_forge_nock(x, x->l.cap_ray, b, c);

  while ( 1 ) {
    /* Preamble - miscelbuseous noncomputational operations.
    */
    {
      /* Test for memory exhaustion.  No agent can allocate more
      ** than 256 words without another check.
      **
      ** For faster performance, this should be per-operation.
      */
      if ( u3_no == u3_lm_open(x, 256) ) {
        c3_w max_w, buc_w;

        u3_lm_water(x, &max_w, &buc_w);
        printf("not open: max %d, buc %d\n", max_w, buc_w);
        return c3__fail;
      }

      /* Update benchmark statistics.
      */
      if ( d ) {
        c3_w nox_w, xur_w;

        u3_lm_water(x, &nox_w, &xur_w);
        d->max_w = c3_max(d->max_w, nox_w);
        d->buc_w = c3_max(d->buc_w, xur_w);

        d->ruy_d++;
      }
    }

    /* Body - main body of the loop.
    */
    {
      /* bip: agent.
      ** ger: operator.
      */
      u3_ray     bip_ray = x->n.lab_ray;
      u3_ray     poq_ray;
      u3_xn_oper ger_op;

      /* Unload opcode and following agent.
      */
        ger_op = *_xn_anvil(x, bip_ray, any, f.c.ger_op);
        poq_ray = *_xn_anvil(x, bip_ray, any, f.c.poq_ray);

      /* Remove this agent from the agenda.
      ** Pop it off the cap.
      */
        x->n.lab_ray = poq_ray;
        x->l.cap_ray = bip_ray;

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
