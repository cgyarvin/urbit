/* z/jato.c
**
** This file is in the public domain.
*/
#include "all.h"

  /** Global data structures.
  **/
    static struct u3_zj_def _zj_defs[] = {
#     define _zj_wet(nam, mug, maj, min, kel) \
        { #nam, mug, maj, min, kel, 0, u3_zx_
    };
    static struct u3_zj_def *_zj_list;
 
/* u3_zj_load():
**
**   Load jet by prop and battery.
*/
void
u3_zj_load(u3_z   z,
           u3_fox pup,
           u3_fox bat)
{
  enum u3_zj_code sax = u3_zj_look(z, bat);
  u3_fox par, nam, maj, min, kel, pri;

  if ( (sax == u3_zj_code_none) && 
       (u3_yes == u3_lr_hext(z, pup, &par, &nam, &maj, &min, &kel, &pri) ) )
  {
#if 0
    u3_b_print(z, "par", par);
    u3_b_print(z, "nam", nam);
    u3_b_print(z, "maj", maj);
    u3_b_print(z, "min", min);
    u3_b_print(z, "kel", kel);
    u3_b_print(z, "pri", pri);
#endif
  }
}

/* u3_zj_look():
**
**   Look for a jet match - gate, [[sam con] bat].
*/
enum u3_zj_code 
u3_zj_look(u3_z   z,
           u3_fox bat)
{
#if 1
  return u3_zj_code_none;
#else
  u3_w w_mug = u3_lm_mug(z, bat);
  u3_w w_i;

  for ( w_i = 0; w_i < u3_zj_code_none; w_i++ ) {
    if ( w_mug == z->j.jet_rod[w_i].w_mug ) {
      return w_i;
    }
  }
  return u3_zj_code_none;
#endif
}

/* u3_zj_bat():
**
**   Return the bat formula for a jet.
*/
u3_fox
u3_zj_bat(u3_z            z,
          enum u3_zj_code code_sax)
{
  return _zj_defs[code_sax].bat;
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
**   Fire a jet - core, [[sam con] bat].
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
           u3_fox          cor)
{
  struct u3_zj_def *gof = &_zj_defs[code_sax];
  u3_mote          zec;
  u3_fox           ham, sam, con, bat;

  if ( u3_no == u3_lr_cell(z, cor, &ham, &bat) ) {
    return u3_cm_punt;
  }
  else if ( u3_no == u3_lr_eq(z, bat, gof->bat) ) {
    return u3_cm_punt;
  }
  else if ( u3_no == u3_lr_cell(z, ham, &sam, &con) ) {
    return u3_cm_punt;
  }
  else if ( u3_no == u3_lr_eq(z, con, gof->con) ) {
    return u3_cm_punt;
  }
  else {
    if ( (zec = setjmp(z->j.jmp_lum)) ) {
      *pod = u3_none;
      return zec;
    }
    else {
      *pod = gof->pas(z, cor);

      // return ( (z->j.w_opt < jet_gof->w_pry) ? u3_cm_test : 0 );
      return 0;
    }
  }
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
