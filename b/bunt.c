/* b/bunt.c
**
** This file is in the public domain.
*/
#include "all.h"

#define U4_GLOBALS
#include "u4/all.h"

  /** Static variables.
  **/
    static u4_road _road_woc;

  /** Forward declarations.
  **/
    static u4_noun _bi_read_sack(u4_lane lane, u4_noun bal);

    typedef u4_noun u4_path;
    typedef u4_noun u4_sack;

/* _bi_import(): import a noun from u4 to u3.
*/
static u3_rat
_bi_import(u3_l  l,
           u4_noun fob)
{
  if ( u4_n_atom(fob) ) {
    mpz_t mp_fob;
    
    u4_a_gmp(fob, mp_fob);
    return u3_ln_mp(l, mp_fob);
  }
  else {
    return u3_ln_cell(l, _bi_import(l, u4_ch(fob)), 
                         _bi_import(l, u4_ct(fob)));
  }
}

/* _bi_export(): export a noun from u3 to u4.
*/
static u4_noun
_bi_export(u3_l    l,
           u4_lane lane,
           u3_fox  tam)
{
  if ( u3_yes == u3_lr_pat(l, tam) ) {
    mpz_t mp_tam;

    u3_lr_mp(l, mp_tam, tam);
    return u4_k_atom_gmp(lane, mp_tam);
  }
  else {
    return u4_k_cell(lane, _bi_export(l, lane, u3_h(l, tam)),
                           _bi_export(l, lane, u3_t(l, tam)));
  }
}

/* u3_b_init(): 
**
**   Initialize static bunt services.
*/
void
u3_b_init(void)
{
  _road_woc = u4_r_init_foo(0, u4_cake_sw);
}

/* u3_b_print():
**
**   Print (piv), with (c_tid) if nonzero as a caption.
*/
void
u3_b_print(u3_lv      lv,
           const c3_c *c_tid,
           u3_rat     piv)
{
  u4_lane lane = u4_hat(_road_woc);

  if ( u3_none == piv ) {
    if ( c_tid ) {
      printf("%s: <none>\n", c_tid); 
    } else {
      printf("<none>\n");
    }
  }
  else {
    u4_err(lane, c_tid, _bi_export(lv, lane, piv));
  }
}

/* u3_b_print_type():
**
**   Print [piv] as a type, with [c_tid] if nonzero as a caption.
*/
void
u3_b_print_type(u3_lv      lv,
                const c3_c *c_tid,
                u3_rat     piv)
{
  u4_lane lane = u4_hat(_road_woc);

  if ( u3_none == piv ) {
    if ( c_tid ) {
      printf("%s: <none>\n", c_tid); 
    } else {
      printf("<none>\n");
    }
  }
  else {
    struct _u4_plow plow;

    u4_plow_init(&plow, lane);
    u4_burp(lane, c_tid, _dump_type(&plow, _bi_export(lv, lane, piv)));
  }
}

/* _bi_path_out_dir(): measure (zep), a path, and/or write it to (buf).
*/
static u4_sb
_bi_path_out_dir(u4_cl   *buf,
                 u4_path zep)
{
  if ( u4_n_zero(zep) ) {
    if ( buf ) {
      strcpy(buf, "q/");
    }
    return 2;
  }
  else {
    u4_noun h_zep = u4_ch(zep);
    u4_noun t_zep = u4_ct(zep);
    u4_sb sb_t, sb_h;

    sb_t = _bi_path_out_dir(buf, t_zep);
    sb_h = u4_a_bin(h_zep, 3);

    if ( buf ) {
      u4_sb sb_i;

      strcpy(buf + sb_t, "q.");
      for ( sb_i = 0; sb_i < sb_h; sb_i++ ) {
        buf[sb_t + 2 + sb_i] = u4_a_byte(h_zep, sb_i);
      }
      buf[sb_t + 2 + sb_i] = '/';
    }    
    return sb_t + 2 + sb_h + 1;
  }
}

/* _bi_path_out_file(): measure (zep), a path, and/or write it to (buf).
*/
static u4_sb
_bi_path_out_file(u4_cl   *buf,
                  u4_path zep)
{
  u4_noun h_zep = u4_ch(zep);
  u4_noun t_zep = u4_ct(zep);
  u4_sb sb_t, sb_h;

  sb_t = _bi_path_out_dir(buf, t_zep);
  sb_h = u4_a_bin(h_zep, 3);

  if ( buf ) {
    u4_sb sb_i;

    for ( sb_i = 0; sb_i < sb_h; sb_i++ ) {
      buf[sb_t + sb_i] = u4_a_byte(h_zep, sb_i);
    }
    buf[sb_t + sb_i] = '.';
    buf[sb_t + sb_i + 1] = 'q';
  }
  return sb_t + sb_h + 2;
}

/* _bi_read_sack_bowl(): read the directory side of (bal).
*/
static u4_noun
_bi_read_sack_bowl(u4_lane lane,
                   u4_path bal)
{
  u4_sb   sb_bal   = _bi_path_out_dir(0, bal);
  u4_cl   *cl_path = alloca(sb_bal + 1);
  u4_tab  bowl     = u4_noun_0;
  u4_noun dir;     // [*[name ext] text]

  _bi_path_out_dir(cl_path, bal);
  cl_path[sb_bal] = 0;

  // printf("bowl: reading %s\n", cl_path);

  for ( dir = u4_disk_read_dir(lane, cl_path); 
        !u4_n_zero(dir);
        dir = u4_ct(dir) )
  {
    u4_noun fus = u4_ch(dir);

    if ( u4_n_eq(u4_cod_in('q'), u4_ct(fus) ) ) {
      u4_path fal = u4_k_cell(lane, u4_ch(fus), bal);
      u4_sack zet; 

      zet = _bi_read_sack(lane, fal);
      bowl = u4_tab_add(lane, u4_ch(fus), zet, bowl);
    }
  }
  return bowl;
}

/* _bi_read_sack_tube(): read (bal), a path, as watt source.
*/
static u4_noun
_bi_read_sack_tube(u4_lane lane,
                   u4_path bal)
{
  u4_sb  sb_bal  = _bi_path_out_file(0, bal);
  u4_cl *cl_path = alloca(sb_bal + 1);

  _bi_path_out_file(cl_path, bal);
  cl_path[sb_bal] = 0;

  // printf("load: %s\n", cl_path);

  return u4_disk_read_file(lane, cl_path);
}

/* _bi_read_sack(): read (bal), as watt source.
*/
static u4_noun
_bi_read_sack(u4_lane lane,
              u4_path bal)
{
  u4_noun tube = _bi_read_sack_tube(lane, bal);
  u4_noun bowl = _bi_read_sack_bowl(lane, bal);

  if ( u4_n_zero(bowl) ) {
    return tube;
  }
  else return u4_k_cell(lane, tube, bowl);
}

/* u3_b_load():
**
**   Use bunt routines to load [rop].
*/
u3_rat 
u3_b_load(u3_l l,
          u3_fox rop)
{
  u4_lane lane = u4_hat(_road_woc);
  u4_path bal = u4_k_cell(lane, _bi_export(l, lane, rop), u4_noun_0);
  u4_noun sac = _bi_read_sack(lane, bal);

  return _bi_import(l, sac);
}

/* u3_b_nock():
**
**   Use bunt routines to execute (nock lan sef).
*/
u3_rat
u3_b_nock(u3_l   l,
          u3_fox lan,
          u3_fox sef)
{
  u4_lane           lane = u4_hat(_road_woc);
  enum u4_bail_code bail_code;

  if ( (bail_code = u4_bail_in) ) {
    switch ( bail_code ) {
      default: printf("[weird!]\n"); return u3_none;

      case u4_bail_exit: printf("[nock exit]\n"); return u3_none;
      case u4_bail_tank: printf("[nock tank]\n"); return u3_none;
      case u4_bail_trip: printf("[nock trip]\n"); return u3_none;
      case u4_bail_stub: printf("[nock stub]\n"); return u3_none;
    }
  } 
  else {
    u4_noun n_lan = _bi_export(l, lane, lan);
    u4_noun n_sef = _bi_export(l, lane, sef);
    u4_noun n_yut = u4_nock_pure(lane, n_lan, n_sef);

    return _bi_import(l, n_yut);
  }
}

/* u3_b_watt():
**
**   Use bunt routines to parse (wek).
*/
u3_rat
u3_b_watt(u3_l   l,
          u3_fox wek)
{
  u4_lane           lane = u4_hat(_road_woc);
  enum u4_bail_code bail_code;

  if ( (bail_code = u4_bail_in) ) {
    switch ( bail_code ) {
      default: printf("[weird!]\n"); return u3_none;

      case u4_bail_exit: printf("[watt exit]\n"); return u3_none;
      case u4_bail_tank: printf("[watt tank]\n"); return u3_none;
      case u4_bail_trip: printf("[watt trip]\n"); return u3_none;
      case u4_bail_stub: printf("[watt stub]\n"); return u3_none;
    }
  } 
  else {
    u4_noun n_wek = _bi_export(l, lane, wek);
    u4_noun n_ruq = u4_watt_parse(lane, u4_noun_0, n_wek);

    return _bi_import(l, n_ruq);
  }
}

/* u3_b_vere():
**
**   Use bunt routines to parse (wek).
*/
u3_rat
u3_b_vere(u3_l   l,
          u3_fox wek)
{
  u4_lane           lane = u4_hat(_road_woc);
  enum u4_bail_code bail_code;

  if ( (bail_code = u4_bail_in) ) {
    switch ( bail_code ) {
      default: printf("[weird!]\n"); return u3_none;

      case u4_bail_exit: printf("[vere exit]\n"); return u3_none;
      case u4_bail_tank: printf("[vere tank]\n"); return u3_none;
      case u4_bail_trip: printf("[vere trip]\n"); return u3_none;
      case u4_bail_stub: printf("[vere stub]\n"); return u3_none;
    }
  } 
  else {
    u4_noun n_wek = _bi_export(l, lane, wek);
    u4_noun n_ruq = u4_vere_parse(lane, n_wek);

    return _bi_import(l, n_ruq);
  }
}

/* u3_b_hume():
**
**   Use bunt routines to parse (wek).
*/
u3_rat
u3_b_hume(u3_l   l,
          u3_fox wek)
{
  u4_lane           lane = u4_hat(_road_woc);
  enum u4_bail_code bail_code;

  if ( (bail_code = u4_bail_in) ) {
    switch ( bail_code ) {
      default: printf("[weird!]\n"); return u3_none;

      case u4_bail_exit: printf("[hume exit]\n"); return u3_none;
      case u4_bail_tank: printf("[hume tank]\n"); return u3_none;
      case u4_bail_trip: printf("[hume trip]\n"); return u3_none;
      case u4_bail_stub: printf("[hume stub]\n"); return u3_none;
    }
  } 
  else {
    u4_noun n_wek = _bi_export(l, lane, wek);
    u4_noun n_ruq = u4_hume_parse(lane, n_wek);

    return _bi_import(l, n_ruq);
  }
}

/* u3_b_full():
**
**   Use bunt routines to map (type gene) to (type form).
**
**   gal: type
**   vub: gene
*/
u3_rat
u3_b_full(u3_l   l,
          u3_fox gal,
          u3_fox vub)
{
  u4_lane           lane = u4_hat(_road_woc);
  enum u4_bail_code bail_code;

  if ( (bail_code = u4_bail_in) ) {
    switch ( bail_code ) {
      default: printf("[weird!]\n"); return u3_none;

      case u4_bail_exit: printf("[full exit]\n"); return u3_none;
      case u4_bail_tank: printf("[full tank]\n"); return u3_none;
      case u4_bail_trip: printf("[full trip]\n"); return u3_none;
      case u4_bail_stub: printf("[full stub]\n"); return u3_none;
    }
  } 
  else {
    // Note: arguments reversed...
    //
    u4_noun n_zyl = _bi_export(l, lane, gal);
    u4_noun n_nes = _bi_export(l, lane, vub);
    u4_noun n_fut = u4_plow_full(lane, n_zyl, n_nes);

    return _bi_import(l, n_fut);
  }
}

/* u3_b_make():
**
**   Use bunt routines to map (mold gene) to (form).
*/
u3_rat
u3_b_make(u3_l   l,
          u3_fox gal,
          u3_fox vub)
{
  u4_lane           lane = u4_hat(_road_woc);
  enum u4_bail_code bail_code;

  if ( (bail_code = u4_bail_in) ) {
    switch ( bail_code ) {
      default: printf("[weird!]\n"); return u3_none;

      case u4_bail_exit: printf("[exit]\n"); return u3_none;
      case u4_bail_tank: printf("[tank]\n"); return u3_none;
      case u4_bail_trip: printf("[trip]\n"); return u3_none;
      case u4_bail_stub: printf("[stub]\n"); return u3_none;
    }
  } 
  else {
    u4_noun n_zyl = _bi_export(l, lane, gal);
    u4_noun n_nes = _bi_export(l, lane, vub);
    u4_noun n_fut = u4_plow_full(lane, n_zyl, n_nes);

    return _bi_import(l, u4_ct(n_fut));
  }
}
