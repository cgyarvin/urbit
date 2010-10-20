/* c/ford.c
**
** This file is in the public domain.
*/
#include <sys/stat.h>
#include <fcntl.h>

#define U2_GLOBAL
#include "all.h"

  /**   Interpreter data structures.
  **/
    /* struct ford_state: ford application state.
    */
      struct ford_state {
        /*  wir - the execution wire.
        */
        u2_ray wir_r;

        /*  pyt - type of pit.
        */
        u2_noun pyt;

        /*  pit - the innermost core.
        */
        u2_noun pit;
      };


  /**   Public functions.
  **/
    /* ford_boot(): create the ford engine.
    */
      struct ford_state*
      ford_boot(c3_w        siz_w,
                const c3_c* src_c);

    /* ford_line(): execute a ford command.
    */
      void
      ford_line(struct ford_state* fod_f,
                const c3_c*        cmd_c,
                const c3_c*        arg_c);

    /* ford_done(): terminate and free all.
    */
      void
      ford_done(struct ford_state* fod_f);
    

/* ford_boot(): create the ford engine.
*/
struct ford_state*
ford_boot(c3_w        siz_w, 
           const c3_c* src_c)
{
  u2_ray wir_r;

  u2_boot(siz_w);
  wir_r = u2_wr_init(c3__cold, u2_ray_of(0, 0), u2_ray_of(1, 0));

  {
    struct ford_state*  fod_f = malloc(sizeof(struct ford_state));
    u2_weak             src   = u2_ux_read(wir_r, src_c, "watt");

    if ( (0 == fod_f) || (u2_none == src) ) {
      perror(src_c);
      return 0;
    }
    else {
      u2_ray jub_r = u2_bl_open(wir_r);

      fprintf(stderr, "boot: %s\n", src_c);
      if ( u2_bl_set(jub_r) ) {
        u2_bl_done(wir_r, jub_r);
        fprintf(stderr, "boot failed\n");
        return 0;
      }
      else {
        u2_noun gen, mil, pyt, pit;

        gen = u2_fj_watt(wir_r, src);
        mil = u2_fj_plow_mill(wir_r, u2_bc(wir_r, c3__cube, _0), gen);
        pyt = u2_bi_h(wir_r, mil);
        pit = u2_bn_nock(wir_r, _0, u2_t(mil));

        u2_bl_done(wir_r, jub_r);

        fod_f->wir_r = wir_r;
        fod_f->pyt = pyt;
        fod_f->pit = pit;
        return fod_f;
      }
    }
  }
}

/* _ford_from(): expression in pit space.
*/
static u2_noun
_ford_from(struct ford_state* fod_f,
           const c3_c*        exp_c)
{
  u2_ray  wir_r = fod_f->wir_r;
  u2_noun exp, gen, fol, val;

  exp = u2_bn_string(wir_r, exp_c);
  gen = u2_fj_watt(wir_r, exp);
  fol = u2_fj_plow_make(wir_r, fod_f->pyt, gen);
  val = u2_bn_nock(wir_r, fod_f->pit, fol);

  return val;
}

/* ford_line(): execute a ford line, as command and argument.
*/
void
ford_line(struct ford_state* fod_f,
          const c3_c*        cmd_c,
          const c3_c*        arg_c)
{
  u2_ray  wir_r = fod_f->wir_r;
  u2_ray  cap_r = u2_rail_cap_r(wir_r);
  
  u2_rl_leap(wir_r, c3__cold);
  {
    u2_ray jub_r = u2_bl_open(wir_r);

    if ( u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, jub_r);
    }
    else {
      u2_noun gat, sam, pro;

      /* Construct gate from command.
      */
      gat = _ford_from(fod_f, cmd_c);

      /* Construct sample from argument.
      */
      sam = _ford_from(fod_f, arg_c);

      /* Construct product.
      */
      pro = u2_wr_nock_mung(wir_r, gat, sam);

      /* Print, if applicable.
      */
      {
        if ( u2_none != pro ) {
          u2_prep pap = u2_fj_prep_noun(wir_r, pro);

          u2_burp(wir_r, 0, pap);
        }
      }
    }
  }
  u2_rl_fall(wir_r);
  u2_rail_cap_r(wir_r) = cap_r;
}

/* ford_done(): terminate and free all.
*/
void
ford_done(struct ford_state* fod_f)
{
}
