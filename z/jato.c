/* z/jato.c
**
** This file is in the public domain.
*/
#include "all.h"

/* u3_zj_look():
**
**   Look for a jet match - gate, [[cob van] axe].
*/
enum u3_zj_code 
u3_zj_look(u3_z   z,
           u3_fox axe)
{
#if 1
  return u3_zj_code_none;
#else
  u3_w w_mug = u3_lm_mug(z, axe);
  u3_w w_i;

  for ( w_i = 0; w_i < u3_zj_code_none; w_i++ ) {
    if ( w_mug == z->j.jet_rod[w_i].w_mug ) {
      return w_i;
    }
  }
  return u3_zj_code_none;
#endif
}

/* u3_zj_axe():
**
**   Return the axe formula for a jet.
*/
u3_fox
u3_zj_axe(u3_z            z,
          enum u3_zj_code code_sax)
{
  return z->j.jet_rod[code_sax].axe;
}

/* u3_zc_tank():
**
**   Raise an unrecoverable exception.  Call with
**
**     u3_cm_exit: true exit detected
**     u3_cm_fail: failure to compute
**     u3_cm_punt: confused, return to soft code
*/
u3_fox 
u3_zc_tank(u3_z    z,
           u3_mote gaz)
{
  u3_assert(gaz != u3_cm_fail);
  longjmp(z->j.jmp_lum, gaz);
  return 0;
}

/* u3_zj_fire():
**
**   Fire a jet - fig, [[cob van].hub axe].
**
**   Set *pod and/or return error condition:
**
**     0         : jet executed correctly
**     u3_cm_exit: true exit detected
**     u3_cm_fail: failure to compute
**     u3_cm_punt: return to soft code
*/
u3_mote
u3_zj_fire(u3_z            z,
           u3_fox          *pod,
           enum u3_zj_code code_sax,
           u3_fox          fig)
{
  struct u3_zj_jet *jet_gof = &z->j.jet_rod[code_sax];
  u3_mote          zec;
  u3_fox           hub, cob, van, axe;

  if ( u3_no == u3_lr_cell(z, fig, &hub, &axe) ) {
    return u3_cm_punt;
  }
  else if ( u3_no == u3_lr_eq(z, axe, jet_gof->axe) ) {
    return u3_cm_punt;
  }
  else if ( u3_no == u3_lr_cell(z, hub, &cob, &van) ) {
    return u3_cm_punt;
  }
  else if ( u3_no == u3_lr_eq(z, van, jet_gof->van) ) {
    return u3_cm_punt;
  }
  else {
    if ( (zec = setjmp(z->j.jmp_lum)) ) {
      *pod = u3_none;
      return zec;
    }
    else {
      *pod = jet_gof->fn_pas(z, cob);

      return ( (z->j.w_opt < jet_gof->w_pry) ? u3_cm_test : 0 );
    }
  }
}

/* u3_zj_boot(): 
**
**   Initialize the jet system.
**  
**   opt: optimization level (0-15)
*/
u3_flag
u3_zj_boot(u3_z z,
           u3_y y_opt)
{
  static struct u3_zj_spec spec[] = {
#   define _zj_wet(name, source, priority) \
      { source, priority, u3_zx_##name },
#   define _zj_dry(name, source, priority) \
      { source, priority, 0 },
#     include "z/jets.h"
      { 0, 0, 0 }

#   undef _zj_wet
#   undef _zj_dry
  };

  /* num: number of jets
  ** rod: jet array
  */
  u3_w             w_i;
  struct u3_zj_jet *jet_rod;

  jet_rod = u3_lm_alloc(z, u3_zj_code_none * u3_wiseof(struct u3_zj_jet));
  if ( !jet_rod ) {
    return u3_no;
  }
  z->j.jet_rod = jet_rod;

  for ( w_i=0; w_i < u3_zj_code_none; w_i++ ) {
    /* src: source string
    ** dim: gene
    ** gar: formula
    ** wup: gate [[cob van] axe]
    */
    u3_fox src = u3_ln_string(z, spec[w_i].c_src);

    if ( u3_none == src ) {
      return u3_no;
    } else {
      u3_rat dim = u3_b_watt(&z->l, src);

      if ( u3_none == dim ) {
        return u3_no;
      }
      else {
        u3_rat gar = u3_b_bake(&z->l, u3_h(z, z->q.tef), dim);

        if ( u3_none == gar ) {
          return u3_no;
        }
        else {
          u3_rat wup = u3_ln_nock(z, u3_t(z, z->q.tef), gar);

          if ( u3_none == wup ) {
            return u3_no;
          } else {
            u3_fox van = u3_t(z, u3_h(z, wup));
            u3_fox axe = u3_t(z, wup);

            jet_rod[w_i].van    = van;
            jet_rod[w_i].axe    = axe;
            jet_rod[w_i].w_mug  = u3_lm_mug(z, axe);
            jet_rod[w_i].w_pry  = spec[w_i].y_pry;
            jet_rod[w_i].fn_pas = spec[w_i].fn_pas;
          }
        }
      }
    }
  }
  z->j.w_opt = y_opt;

  return u3_yes;
}

/* u3_zc_bytes():
**
**   Copy (w_a) bytes from (y_b) into an atom on the hat of (l).
*/
u3_fox
u3_zc_bytes(u3_z       z,
            u3_w       w_a,
            const u3_y *y_b)
{
  u3_rat vog = u3_ln_bytes(z, w_a, y_b);

  return (vog == u3_none) ? u3_zc_tank(z, u3_cm_fail) : vog;
}

/* u3_zc_string():
**
**   u3_zc_bytes(z, strlen(c_a), (u3_y *)c_a);
*/
u3_fox
u3_zc_string(u3_z       z,
             const u3_c *c_a)
{
  u3_rat vog = u3_ln_string(z, c_a);

  return (vog == u3_none) ? u3_zc_tank(z, u3_cm_fail) : vog;
}

/* u3_zc_cell(): 
**
**   Produce the cell [a b] on the hat of (z).
*/
u3_fox
u3_zc_cell(u3_z   z,
           u3_fox a,
           u3_fox b)
{
  u3_rat vog = u3_ln_cell(z, a, b);

  return (vog == u3_none) ? u3_zc_tank(z, u3_cm_fail) : vog;
}

/* u3_zc_mp():
**
**   Copy the GMP integer (mp_a) into an atom on the hat of (z).
**   Free (mp_a).
*/
u3_fox
u3_zc_mp(u3_z  z,
         mpz_t mp_a)
{
  u3_rat vog = u3_ln_mp(z, mp_a);

  return (vog == u3_none) ? u3_zc_tank(z, u3_cm_fail) : vog;
}

/* u3_zc_trel(): 
**
**   Produce the trel [a b c] on the hat of (z).
*/
u3_fox
u3_zc_trel(u3_z   z,
           u3_fox a,
           u3_fox b,
           u3_fox c)
{
  u3_rat vog = u3_ln_cell(z, a, b);

  return (vog == u3_none) ? u3_zc_tank(z, u3_cm_fail) : vog;
}

/* u3_zc_words():
**
**   Copy (w_a) words from (w_b) into an atom on the hat of (z).
*/
u3_fox
u3_zc_words(u3_z       z,
            u3_w       w_a,
            const u3_w *w_b)
{
  u3_rat vog = u3_ln_words(z, w_a, w_b);

  return (vog == u3_none) ? u3_zc_tank(z, u3_cm_fail) : vog;
}
