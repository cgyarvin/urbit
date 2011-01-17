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
#if 0
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
      u2_bx_spot(wir_r, u2_nul);
      u2_bx_show(wir_r);

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

/* ford_test2(): another test for recursion.
*/
void
ford_test2(struct ford_state* fod_f,
           const char*        src_c)
{
  u2_wire wir_r = fod_f->wir_r;
  u2_noun src   = u2_ux_read(wir_r, src_c, "watt");

  if ( u2_none == src ) {
    u2_bl_bail(wir_r);
  }
  else {
    u2_noun gen, mil;

    gen = u2_fj_watt(wir_r, src);
    gen = u2_ba_sole(wir_r, gen);
    mil = u2_fj_plow_mill(wir_r, u2_bc(wir_r, c3__cube, _0), gen);

    printf("test2: plowed.\n");
  }
}

u2_weak
j2_mbc(watt_271, ream)(u2_wire wir_r, 
                       u2_weak txt);

void
j2_mcy(watt_271, ut, dupt)(u2_wire     wir_r,
                             u2_noun     van,
                             const c3_c* cap_c,
                             u2_noun     typ);

/* _ford_mo_mill(): mill from C source and pit.
*/
u2_noun
_ford_mo_mill(struct ford_state* fod_f,
              u2_
/* ford_test3(): accurate use of a true kernel.
*/
void
ford_test3(struct ford_state* fod_f,
           const char*        src_c,
           const char*        arg_c)
{
  u2_wire wir_r = fod_f->wir_r;
  u2_noun src   = u2_ux_read(wir_r, src_c, "watt");

  if ( u2_none == src ) {
    printf("test3: %s: no file\n", src_c);
    u2_bl_bail(wir_r);
  }
  else {
    u2_noun gen = j2_mbc(watt_271, ream)(wir_r, src);

    if ( u2_none == gen ) {
      printf("test3: %s: no gene\n", src_c);
      return;
    }
    else {
      u2_noun van = u2_bn_hook(wir_r, fod_f->pit, "ut");
      u2_noun mel = u2_bn_hook(wir_r, van, "mill");
      u2_noun lof;
   
      if ( (u2_none == mel) || (u2_none == van) ) {
        printf("test3: no mill or ut\n");
        return;
      }
      lof = u2_nk_mung(wir_r, mel, gen);
      if ( u2_none == lof ) {
        printf("test3: no lof\n");
      }
      else {
        printf("::::  ::::  ::::  ::::\n");
        u2_bx_spot(wir_r, u2_nul); 
#if 0
        u2_err(wir_r, "type", u2_h(lof));
        u2_err(wir_r, "tool", u2_t(lof));
#else
        if ( arg_c ) {
          u2_noun src = u2_rl_string(wir_r, arg_c);
          u2_noun gen = j2_mbc(watt_271, ream)(wir_r, src);
          u2_noun vad = u2_bn_hook(wir_r, fod_f->pit, "vade");
          u2_noun van = u2_bn_hook(wir_r, fod_f->pit, "ut");
          u2_noun hup = u2_nk_mung(wir_r, vad, u2_rc(wir_r, u2_h(lof), gen));
          u2_noun pug = u2_nk_nock(wir_r, _0, u2_t(lof));

          if ( (u2_none != hup) && (u2_none != pug) ) {
            u2_weak muf = u2_nk_nock(wir_r, pug, u2_t(hup));

            j2_mcy(watt_271, ut, dupt)(wir_r, van, 0, u2_h(hup));
            if ( muf != u2_none ) {
              u2_err(wir_r, 0, muf);
            }
            u2_bx_spot(wir_r, u2_nul);
          }
        }
#endif
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

  LoomStop = 0;
  u2_bx_boot(wir_r);
  u2_rl_leap(wir_r, c3__warm);
  {
    u2_ray jub_r = u2_bl_open(wir_r);

    if ( u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, jub_r);
    }
    else {
      if ( !strcmp(cmd_c, "test") ) {
        // ford_test(fod_f, "watt/t1-273");
        ford_test3(fod_f, "watt/270", arg_c);
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
            u2_bx_spot(wir_r, u2_nul);
          }
        }
      }
#endif
    }
  }
  u2_rl_fall(wir_r);
  u2_rail_cap_r(wir_r) = cap_r;

  u2_bx_show(wir_r);
}

/* ford_done(): terminate and free all.
*/
void
ford_done(struct ford_state* fod_f)
{
}
