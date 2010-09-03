/* x/jato.c
**
** This file is in the public domain.
*/
#include "all.h"

  /** Global data structures.
  **/
    static struct u3_xj_def _xj_defs[] = {
#     define _xj_wet(nam, mug) \
        { #nam, mug, u3_xx_##nam },
#     define _xj_dry(nam, mug) \
        { #nam, mug,  0 },
#include "x/jets.h"
        {}
    };
    static struct u3_xj_def *_xj_list = 0;

/* _xj_add():
**
**   Add (def, cor, pri) to the jet search space.
*/
static void
_xj_add(u3_x     x,
        struct   u3_xj_def *def,
        u3_fox   cor,
        u3_fox   par,
        uint32_t pri)
{
  u3_fox ham = u3_xh(x, cor);
  u3_fox bat = u3_xt(x, cor);

  if ( u3_no == u3_lr_dust(x, ham) ) {
    def->con = 0;
  } else {
    def->con = u3_xt(x, ham);
  }
  if ( 0 == def->mug ) {
    def->mug = u3_lm_mug(x, bat);
    fprintf(stderr, "jet: %s: %x\n", def->nam, def->mug);
  } else {
    if ( def->mug != u3_lm_mug(x, bat) ) {
      fprintf(stderr, "jet: mismatch: %s, %x, %x\n", 
          def->nam, def->mug, u3_lm_mug(x, bat));
      return;
    }
  }
  def->bat = bat;
  def->pri = pri; 

  def->nex = _xj_list;
  _xj_list = def;
}

/* u3_xj_load():
**
**   Load jet by prop and battery.
*/
void
u3_xj_load(u3_x   x,
           u3_fox pup,
           u3_fox cor)
{
  u3_fox            bat = u3_xt(x, cor);
  c3_w              mug = u3_lm_mug(x, bat);
  enum u3_xj_code   sax = u3_xj_look(x, bat);
  struct u3_xj_def  *def;
  u3_fox            par, nam, pri;

  for ( def = _xj_list; def; def = def->nex ) {
    if ( mug == def->mug ) {
      return;
    }
  }

  if ( (sax == u3_xj_code_none) && 
       (u3_yes == u3_lr_trel(x, pup, &par, &nam, &pri) ) )
  {
    uint32_t         i;
    struct u3_xj_def *def;

    for ( i=0; (def = &_xj_defs[i])->nam; i++ ) {
      if ( u3_yes == u3_lr_sing_c(x, (c3_c *)def->nam, nam) ) {
        _xj_add(x, def, cor, par, u3_lr_word(x, 0, pri));
      }
    }
  }
}

/* u3_xj_look():
**
**   Look for a jet match - gate, [[sample context] battery].
*/
enum u3_xj_code 
u3_xj_look(u3_x   x,
           u3_fox bat)
{
#if 0
  return u3_xj_code_none;
#else
  c3_w             mug = u3_lm_mug(x, bat);
  struct u3_xj_def *def;

  for ( def = _xj_list; def; def = def->nex ) {
    if ( mug == def->mug ) {
      return (def->pas ? (def - _xj_defs) : u3_xj_code_none);
    }
  }
  return u3_xj_code_none;
#endif
}

/* u3_xj_bat():
**
**   Return the bat formula for a jet.
*/
u3_fox
u3_xj_bat(u3_x            x,
          enum u3_xj_code code_sax)
{
  return _xj_defs[code_sax].bat;
}

/* u3_xc_tank():
**
**   Raise an unrecoverable exception.  Call with
**
**     c3__exit: true exit detected
**     c3__fail: failure to compute
**     c3__punt: confused, return to soft code
*/
u3_fox 
u3_xc_tank(u3_x    x,
           u3_mote gax)
{
  longjmp(x->j.jmp_lum, gax);
  return 0;
}

/* u3_xc_use():
**
**   Exit iff (rat) is none.
*/
u3_fox
u3_xc_use(u3_x   x,
          u3_rat rat)
{
  if ( rat == u3_none ) {
    return u3_xc_tank(x, c3__exit);
  }
  else return rat;
}

/* u3_xj_fire():
**
**   Fire a jet - core, [[sam con] bat].
**
**   Set *pod and/or return error condition:
**
**     0         : jet executed correctly
**     c3__exit: true exit detected
**     c3__fail: failure to compute
**     c3__punt: return to soft code
*/
u3_mote
u3_xj_fire(u3_x            x,
           u3_fox          *pod,
           enum u3_xj_code code_sax,
           u3_fox          cor)
{
  struct u3_xj_def *gof = &_xj_defs[code_sax];
  u3_mote          xec;

#if 0
  u3_fox           ham, sam, con, bat;
  if ( u3_no == u3_lr_cell(x, cor, &ham, &bat) ) {
    printf("punt 1\n");
    return c3__punt;
  }
  else if ( u3_no == u3_lr_sing(x, bat, gof->bat) ) {
    printf("punt 2\n");
    return c3__punt;
  }
  else if ( u3_no == u3_lr_cell(x, ham, &sam, &con) ) {
    printf("punt 3\n");
    return c3__punt;
  }
  else if ( u3_no == u3_lr_sing(x, con, gof->con) ) {
    printf("punt 4\n");
    return c3__punt;
  }
#endif

  {
    if ( (xec = setjmp(x->j.jmp_lum)) ) {
      *pod = u3_none;
      return xec;
    }
    else {
      *pod = gof->pas(x, cor);

      // return ( (x->j.w_opt < jet_gof->w_pry) ? c3__test : 0 );
      return 0;
    }
  }
}

/* u3_xc_bytes():
**
**   Copy (w_a) bytes from (y_b) into an atom on the hat of (l).
*/
u3_fox
u3_xc_bytes(u3_x       x,
            c3_w       w_a,
            const c3_y *y_b)
{
  u3_rat vog = u3_ln_bytes(x, w_a, y_b);

  return (vog == u3_none) ? u3_xc_tank(x, c3__fail) : vog;
}

/* u3_xc_string():
**
**   u3_xc_bytes(x, strlen(c_a), (u3_y *)c_a);
*/
u3_fox
u3_xc_string(u3_x       x,
             const c3_c *c_a)
{
  u3_rat vog = u3_ln_string(x, c_a);

  return (vog == u3_none) ? u3_xc_tank(x, c3__fail) : vog;
}

/* u3_xc_cell(): 
**
**   Produce the cell [a b] on the hat of (x).
*/
u3_fox
u3_xc_cell(u3_x   x,
           u3_fox a,
           u3_fox b)
{
  u3_rat vog = u3_ln_cell(x, a, b);

  return (vog == u3_none) ? u3_xc_tank(x, c3__fail) : vog;
}

/* u3_xc_mp():
**
**   Copy the GMP integer (mp_a) into an atom on the hat of (x).
**   Free (mp_a).
*/
u3_fox
u3_xc_mp(u3_x  x,
         mpz_t mp_a)
{
  u3_rat vog = u3_ln_mp(x, mp_a);

  return (vog == u3_none) ? u3_xc_tank(x, c3__fail) : vog;
}

/* u3_xc_trel(): 
**
**   Produce the trel [a b c] on the hat of (x).
*/
u3_fox
u3_xc_trel(u3_x   x,
           u3_fox a,
           u3_fox b,
           u3_fox c)
{
  u3_rat vog = u3_ln_cell(x, a, b);

  return (vog == u3_none) ? u3_xc_tank(x, c3__fail) : vog;
}

/* u3_xc_words():
**
**   Copy (w_a) words from (w_b) into an atom on the hat of (x).
*/
u3_fox
u3_xc_words(u3_x       x,
            c3_w       w_a,
            const c3_w *w_b)
{
  u3_rat vog = u3_ln_words(x, w_a, w_b);

  return (vog == u3_none) ? u3_xc_tank(x, c3__fail) : vog;
}
