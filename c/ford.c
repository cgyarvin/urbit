/* c/ford.c
**
** This file is in the public domain.
*/
#include <sys/stat.h>
#include <fcntl.h>

#define U2_GLOBAL
#define C3_GLOBAL
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

        /*  kol - kernel formula.
        */
        u2_noun kol;

        /*  pit - the innermost core.
        */
        u2_noun pit;

        /*  ryd - a read gate.
        */
        u2_noun ryd;
      };


  /**   Public functions.
  **/
    /* ford_boot(): create the ford engine.
    */
      struct ford_state*
      ford_boot(const c3_c* src_c);

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
    
void
_ford_print_superdecimal_w(c3_w w)
{
  if ( w < 65536 ) {
    printf("%d", w);
  } else {
    printf("%d+%d", (w >> 16), (w & 65535));
  }
}

void
_ford_print_superdecimal_d(c3_d d)
{
  if ( d > 0x100000000ULL ) {
    _ford_print_superdecimal_w((c3_w)(d >> 32ULL));
    printf(":");
    _ford_print_superdecimal_w((c3_w)(d & 0xffffffffULL));
  }
  else { 
    _ford_print_superdecimal_w((c3_w) d);
  }
}

void
_ford_report(u2_ray wir_r)
{
  c3_d sap_d, cop_d, jax_d, use_d;
  c3_w wax_w, moc_w, hix_w, ums_w;
  c3_ws sew_ws, bax_ws;

  if ( u2_no == u2_bx_post(wir_r, &sap_d, 
                                  &cop_d, 
                                  &jax_d, 
                                  &use_d, 
                                  &wax_w, 
                                  &moc_w, 
                                  &hix_w,
                                  &sew_ws,
                                  &bax_ws,
                                  &ums_w) )
  {
    return;
  } else {
    printf("<");
    _ford_print_superdecimal_d(sap_d);
    printf(" jogs");
    if ( cop_d ) {
      printf(", ");
      _ford_print_superdecimal_d(cop_d);
      printf(" dups");
    }
    if ( jax_d ) {
      printf(", ");
      _ford_print_superdecimal_d(jax_d);
      printf(" shot");
    }
    if ( use_d ) {
      printf(", ");
      _ford_print_superdecimal_d(use_d);
      printf(" pings");
    }
    printf("; ");
    _ford_print_superdecimal_w(moc_w);
    printf(" hit, ");
    _ford_print_superdecimal_w(wax_w);
    printf(" deep");

    if ( hix_w ) {
      printf(", ");
      _ford_print_superdecimal_w(hix_w);
      printf(" held");
    }
    
    if ( sew_ws ) {
      printf(", ");
      if ( sew_ws < 0 ) {
        printf("-");
        _ford_print_superdecimal_w((c3_w) -(sew_ws));
      } else {
        _ford_print_superdecimal_w((c3_w) sew_ws);
      }
      printf(" sewn");
    }
    if ( bax_ws ) {
      printf(", ");
      if ( bax_ws < 0 ) {
        printf("-");
        _ford_print_superdecimal_w((c3_w) -(bax_ws));
      } else {
        _ford_print_superdecimal_w((c3_w) bax_ws);
      }
      printf(" kept");
    }
    printf("; ");
    _ford_print_superdecimal_w(ums_w);
    printf(" ms>\n");
  }
}

/* _ford_save_warm(): save engine as noun.
*/
static void
_ford_save_warm(struct ford_state* fod_f,
                const c3_c*        src_c)
{
  u2_wire wir_r = fod_f->wir_r;
  u2_noun fat = u2_bn_cell(wir_r, fod_f->pyt, fod_f->kol);

  u2_ux_write_deep(wir_r, fat, src_c, "noun");
}

/* _ford_gates(): add various convenience gates.
*/
static void 
_ford_gates(struct ford_state* fod_f)
{
#if 1
  u2_wire wir_r = fod_f->wir_r;

  fod_f->ryd = u2_bn_hook
    (wir_r, u2_bn_hook(wir_r, fod_f->pit, "plow"), "read");
#else
  fod_f->ryd = u2_none;
#endif
}

/* _ford_load_warm(): load engine from warm image.
*/
static void
_ford_load_warm(struct ford_state* fod_f,
                const c3_c*        src_c) 
{
  u2_wire wir_r = fod_f->wir_r;
  u2_noun fat = u2_ux_read_deep(wir_r, src_c, "noun");

  if ( u2_none == fat ) {
    u2_bl_bail(wir_r);
  } 
  else {
    fod_f->pyt = u2_ba_sole(wir_r, u2_h(fat));
    fod_f->kol = u2_ba_sole(wir_r, u2_t(fat));
    fod_f->pit = u2_bn_nock(wir_r, _0, fod_f->kol);
  }
}

/* _ford_load_cold(): load engine from cold source.
*/
static void
_ford_load_cold(struct ford_state* fod_f,
                const c3_c*        src_c)
{
  u2_wire wir_r = fod_f->wir_r;
  u2_noun src   = u2_ux_read(wir_r, src_c, "watt");

  if ( u2_none == src ) {
    u2_bl_bail(wir_r);
  }
  else {
    u2_noun gen, mil, pyt, kol, pit;

    gen = u2_fj_watt(wir_r, src);
    gen = u2_ba_sole(wir_r, gen);
    mil = u2_fj_plow_mill(wir_r, u2_bc(wir_r, c3__cube, _0), gen);
    pyt = u2_bi_h(wir_r, mil);
    kol = u2_bi_t(wir_r, mil);
    {
      // XX: bad dag interaction in old plow code
      //
      u2_rl_gain(wir_r, kol);
    }
    kol = u2_ba_sole(wir_r, kol);
    pit = u2_bn_nock(wir_r, _0, kol);

    fod_f->kol = kol;
    fod_f->pyt = pyt;
    fod_f->pit = pit;

    _ford_save_warm(fod_f, src_c);
  }
}

/* ford_boot(): create the ford engine.
*/
struct ford_state*
ford_boot(const c3_c* src_c)
{
  struct ford_state* fod_f = malloc(sizeof(struct ford_state));
  u2_ray wir_r;

  u2_boot();
  wir_r = u2_wr_init(c3__warm, u2_ray_of(0, 0), u2_ray_of(1, 0));
  fod_f->wir_r = wir_r;

  {
    u2_ray jub_r = u2_bl_open(wir_r);

    fprintf(stderr, "boot: %s\n", src_c);
    if ( u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, jub_r);
      fprintf(stderr, "boot failed\n");

      free(fod_f);
      return 0;
    }
    else {
      u2_bx_boot(wir_r);

      if ( u2_yes == u2_ux_fresh(src_c, "watt", "noun") ) {
        _ford_load_warm(fod_f, src_c);
      } else {
        _ford_load_cold(fod_f, src_c);
      }
      _ford_gates(fod_f);

      u2_bl_done(wir_r, jub_r);
      _ford_report(wir_r);

      return fod_f;
    }
  }
}

/* ford_test(): attempt ford recursion.
*/
void
ford_test(struct ford_state* fod_f,
          const char*        src_c)
{
  u2_wire wir_r = fod_f->wir_r;
  u2_weak src = u2_ux_read(wir_r, src_c, "watt");

  if ( (0 == fod_f) || (u2_none == src) ) {
    perror(src_c);
    return;
  }
  else {
    u2_ray jub_r = u2_bl_open(wir_r);

    fprintf(stderr, "test: %s\n", src_c);
    if ( u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, jub_r);

      fprintf(stderr, "test failed\n");
    }
    else {
      u2_noun vor;

      printf("about to read...\n");
      vor = u2_bn_mung(wir_r, fod_f->ryd, src);
      u2_err(wir_r, "read", vor);

      u2_bl_done(wir_r, jub_r);
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
 
  u2_bx_boot(wir_r);
  u2_rl_leap(wir_r, c3__warm);
  {
    u2_ray jub_r = u2_bl_open(wir_r);

    if ( u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, jub_r);
    }
    else {
      if ( !arg_c && !strcmp(cmd_c, "test") ) {
        ford_test(fod_f, "watt/273");
      }
      else {
#if 0
        u2_noun cmd = u2_bn_string(wir_r, cmd_c);
        u2_noun cor = u2_bn_mung(wir_r, fod_f->ryd, cmd);

        u2_burp(wir_r, 0, u2_fj_prep_noun(wir_r, cor));

        if ( arg_c ) {
          u2_noun arg = u2_bn_string(wir_r, arg_c);
          u2_noun sam = u2_bn_mung(wir_r, fod_f->ryd, arg);

          u2_burp(wir_r, 0, u2_fj_prep_noun(wir_r, sam));
        }
#else
        u2_noun gat, sam, pro;

        /* Construct gate from command.
        */
        gat = _ford_from(fod_f, cmd_c);

        /* Construct sample from argument.
        */
        sam = _ford_from(fod_f, arg_c);

        /* Construct product.
        */
        pro = u2_nk_mung(wir_r, gat, sam);

        /* Print, if applicable.
        */
        {
          if ( u2_none != pro ) {
            u2_prep pap = u2_fj_prep_noun(wir_r, pro);

            u2_burp(wir_r, 0, pap);
          }
        }
      }
#endif
    }
  }
  u2_rl_fall(wir_r);
  u2_rail_cap_r(wir_r) = cap_r;

  _ford_report(wir_r);
}

/* ford_done(): terminate and free all.
*/
void
ford_done(struct ford_state* fod_f)
{
}
