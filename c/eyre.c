/* c/eyre.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <setjmp.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <gmp.h>
#include <stdint.h>

#define U2_GLOBAL
#define C3_GLOBAL
#include "all.h"

#define EyreFirstKernel 242     //  counts down; max 264; > 259 needs nock7
u2_flag EyreSmoke;

  /**  Global kernel - used only for trace printing.
  **/
    u2_noun Ken   = u2_nul;
    c3_w    Kno_w = EyreFirstKernel;
  
    /* External drivers.
    */
      extern u2_ho_driver j2_da(k_241);
      extern u2_ho_driver j2_da(k_242);
//      extern u2_ho_driver j2_da(k_243);
//      extern u2_ho_driver j2_da(k_244);
//      extern u2_ho_driver j2_da(k_245);
//      extern u2_ho_driver j2_da(k_246);
//      extern u2_ho_driver j2_da(k_247);
//      extern u2_ho_driver j2_da(k_248);
//      extern u2_ho_driver j2_da(k_249);
//      extern u2_ho_driver j2_da(k_250);
//      extern u2_ho_driver j2_da(k_251);
//      extern u2_ho_driver j2_da(k_252);
//      extern u2_ho_driver j2_da(k_253);
//      extern u2_ho_driver j2_da(k_254);
//      extern u2_ho_driver j2_da(k_255);
//      extern u2_ho_driver j2_da(k_256);
//      extern u2_ho_driver j2_da(k_257);
//      extern u2_ho_driver j2_da(k_258);
//      extern u2_ho_driver j2_da(k_259);
//      extern u2_ho_driver j2_da(k_260);
//      extern u2_ho_driver j2_da(k_261);
//      extern u2_ho_driver j2_da(k_262);
//      extern u2_ho_driver j2_da(watt_263);
//      extern u2_ho_driver j2_da(watt_264);

    /* Built-in battery drivers.   Null `cos` terminates. 
    */
      u2_ho_driver *HostDriverBase[] = {
        &j2_da(k_241),
        &j2_da(k_242),
//        &j2_da(k_243),
//        &j2_da(k_244),
//         &j2_da(k_245),
//        &j2_da(k_246),
//        &j2_da(k_247),
//        &j2_da(k_248),
//        &j2_da(k_249),
//        &j2_da(k_250),
//        &j2_da(k_251),
//        &j2_da(k_252),
//        &j2_da(k_253),
//        &j2_da(k_254),
//        &j2_da(k_255),
//        &j2_da(k_256),
//        &j2_da(k_257),
//        &j2_da(k_258),
//        &j2_da(k_259),
//        &j2_da(k_260),
//        &j2_da(k_261),
//        &j2_da(k_262),
//        &j2_da(watt_263), 
//        &j2_da(watt_264), 
        0
      };

  /**  Jet dependencies.  Minimize these.
  **/
#   define Pt5Y   k_242__a__b__c__d__e

    u2_noun
    j2_mby(Pt5Y, cue)(u2_wire, u2_noun a);

    u2_noun
    j2_mby(Pt5Y, jam)(u2_wire, u2_noun a);

#   define _eyre_cue  j2_mby(Pt5Y, cue)
#   define _eyre_jam  j2_mby(Pt5Y, jam)

  /**  Forward declarations.
  **/
    static void
    _eyre_print_trac(u2_wire, u2_noun, u2_noun);

/* _eyre_trac(): print trace, if any; produce nul.
*/
static u2_noun                                                    //  direct
_eyre_trac(u2_wire wir_r)
{
  u2_ray kit_r = u2_bl_open(wir_r);

  if ( u2_bl_set(wir_r) ) {
    u2_bl_done(wir_r, kit_r);
    fprintf(stderr, "  {trace failed!}\n");
    return u2_bl_bail(wir_r, c3__fail);
  }
  else {
    u2_noun tax;

    tax = u2_rx(wir_r, u2_wire_tax(wir_r));
    u2_wire_tax(wir_r) = u2_nul;

    if ( u2_nul == tax ) {
      fprintf(stderr, "{no trace}\n");
    } else {
      fprintf(stderr, "{trace}\n");
      if ( u2_nul == Ken ) {
        fprintf(stderr, "{trace: no kernel}\n");
      }
      else {
        _eyre_print_trac(wir_r, Ken, tax);
      }
      u2_rz(wir_r, tax);
    }
    u2_bl_done(wir_r, kit_r);
  }
  u2_bl_bail(wir_r, c3__fail);
  return u2_nul;
}

/* _eyre_nock(): control and trace wrapper for interpreter.
*/
static u2_noun                                                    //  produce
_eyre_nock(u2_wire wir_r,
           u2_flag rac,                                           //  direct
           u2_noun bus,                                           //  submit
           u2_noun fol)                                           //  retain
{
  u2_noun pro;

  pro = u2_nk_nock(wir_r, bus, fol);

  if ( u2_none != pro ) {
    return pro;
  }
  else if ( u2_yes == rac ) {
    return _eyre_trac(wir_r);
  }
  else return u2_bl_bail(wir_r, c3__fail);
}

/* _eyre_mong(): mong with trace.
*/
static u2_noun                                                    //  produce
_eyre_mong(u2_wire wir_r,
           u2_flag rac,                                           //  direct
           u2_noun gat,                                           //  retain
           u2_noun sam)                                           //  submit
{
  u2_noun pro;

  pro = u2_nk_mong(wir_r, gat, sam);

  if ( u2_none != pro ) {
    return pro;
  }
  else if ( u2_yes == rac ) {
    return _eyre_trac(wir_r);
  }
  else return u2_bl_bail(wir_r, c3__fail);
}

/* _eyre_hook(): hook with unitary sample.
*/
static u2_noun                                                    //  produce
_eyre_hook(u2_wire     wir_r,
           u2_noun     cor,                                       //  retain
           const c3_c* hoc_c,                                     //  retain
           u2_noun     sam)                                       //  submit
{
  u2_noun gat = u2_bn_hook(wir_r, cor, hoc_c);
  u2_noun pro;

  pro = _eyre_mong(wir_r, u2_yes, gat, sam);
  u2_rz(wir_r, gat);
  return pro;
}

/* _eyre_hook_cell(): hook with cell sample.
*/
static u2_noun                                                    //  produce
_eyre_hook_cell(u2_wire     wir_r,
                u2_noun     cor,                                  //  retain
                const c3_c* hoc_c,                                //  retain
                u2_noun     sam_2,                                //  submit
                u2_noun     sam_3)                                //  submit
{
  u2_noun gat = u2_bn_hook(wir_r, cor, hoc_c);
  u2_noun pro;

  pro = _eyre_mong(wir_r, u2_yes, gat, u2_bn_cell(wir_r, sam_2, sam_3));
  u2_rz(wir_r, gat);
  return pro;
}

/* _eyre_hook_trel(): hook with trel sample.
*/
static u2_noun                                                    //  produce
_eyre_hook_trel(u2_wire     wir_r,
                u2_noun     cor,                                  //  retain
                const c3_c* hoc_c,                                //  retain
                u2_noun     sam_2,                                //  submit
                u2_noun     sam_6,                                //  submit
                u2_noun     sam_7)                                //  submit
{
  u2_noun gat = u2_bn_hook(wir_r, cor, hoc_c);
  u2_noun pro;

  pro = _eyre_mong
    (wir_r, u2_yes, gat, u2_bn_trel(wir_r, sam_2, sam_6, sam_7));
  u2_rz(wir_r, gat);
  return pro;
}

/* _eyre_hook_qual(): hook with quadruple sample.
*/
static u2_noun                                                    //  produce
_eyre_hook_qual(u2_wire     wir_r,
                u2_noun     cor,                                  //  retain
                const c3_c* hoc_c,                                //  retain
                u2_noun     sam_2,                                //  submit
                u2_noun     sam_6,                                //  submit
                u2_noun     sam_14,                               //  submit
                u2_noun     sam_15)                               //  submit
{
  u2_noun gat = u2_bn_hook(wir_r, cor, hoc_c);
  u2_noun pro;

  pro = _eyre_mong
    (wir_r, u2_yes, gat, u2_bn_qual(wir_r, sam_2, sam_6, sam_14, sam_15));
  u2_rz(wir_r, gat);
  return pro;
}

/* _eyre_path_lid(): 
*/
static c3_c*                                                      //  produce
_eyre_path_lid(c3_c* lid_c)                                       //  retain
{
  c3_c* pot_c = malloc(FILENAME_MAX + 1);

  snprintf(pot_c, FILENAME_MAX, "watt/%s", lid_c);
  return pot_c;
}


/* _eyre_path_ken():
*/
static c3_c*                                                      //  produce 
_eyre_path_ken(c3_w kno_w)
{
  c3_c* pot_c = malloc(FILENAME_MAX + 1);

  snprintf(pot_c, FILENAME_MAX, "watt/%d", kno_w);
  return pot_c;
}

/* _eyre_ken_nuw():
**
**   u2_yes iff `ken` needs to be recompiled.
*/
static u2_flag
_eyre_ken_nuw(c3_w kno_w)
{
  c3_c*   pot_c = _eyre_path_ken(kno_w);
  u2_flag esh;

  esh = u2_ux_fresh(pot_c, "watt", "noun");
  free(pot_c);
  return u2_not(esh);
}

/* _eyre_ken_load_hard():
**
**   Load `ken` from the saved kernel binary.
*/
static u2_noun                                                    //  produce
_eyre_ken_load_hard(u2_wire wir_r,
                    c3_w    kno_w)
{
  c3_c* pot_c = _eyre_path_ken(kno_w);
  u2_noun paq, cun, ken;

  // u2_bx_boot(wir_r);
  paq = u2_ux_read(wir_r, pot_c, "noun");
  cun = _eyre_cue(wir_r, paq);
  printf("hard boot: %s: %x\n", pot_c, u2_mug(cun));
  // u2_bx_show(wir_r);

  u2_rz(wir_r, paq);
  free(pot_c);

  ken = u2_rl_take(u2_wire_bas_r(wir_r), cun);
  u2_rz(wir_r, cun);

  Ken = ken;
  Kno_w = kno_w;
  return ken;
}

/* _eyre_ken_load_soft():
**
**   Load `ken` from source, using previous `las`; save the binary.
*/
static u2_noun                                                    //  produce
_eyre_ken_load_soft(u2_wire wir_r,
                    u2_noun las,                                  //  retain
                    c3_w    kno_w)
{
  u2_noun cun, ken;

  if ( u2_no == u2_rl_leap(wir_r, c3__rock) ) {
    c3_assert(0);
  }
  u2_bx_boot(wir_r);
  {
    u2_ray  kit_r = u2_bl_open(wir_r);

    if ( u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, kit_r);
      u2_rl_fall(wir_r);
      fprintf(stderr, "{no boot, %d}\n", kno_w);
      exit(1);
    }
    else {
      c3_c* pot_c = _eyre_path_ken(kno_w);
      u2_noun src = u2_ux_read(wir_r, pot_c, "watt");

      cun = _eyre_nock(wir_r, u2_yes, src, las);

      u2_bl_done(wir_r, kit_r);

      u2_bx_spot(wir_r, u2_nul);
      u2_bx_show(wir_r);
      printf("{soft boot: %s: %x}\n", pot_c, u2_mug(cun));
      free(pot_c);
    }
  }
  ken = u2_rl_take(u2_wire_bas_r(wir_r), cun);
  u2_rl_fall(wir_r);

  {
    c3_c* pot_c = _eyre_path_ken(kno_w);
    u2_noun paq;

    paq = _eyre_jam(wir_r, ken);
    u2_ux_write(wir_r, paq, pot_c, "noun");
    printf("  {%d bits}\n", u2_met(0, paq));

#if 0
    {
      u2_noun foo;

      u2_bx_boot(wir_r);
      foo = _eyre_cue(wir_r, paq);
      u2_bx_show(wir_r);
      u2_rz(wir_r, foo);
    }
#endif 
    u2_rz(wir_r, paq);
    free(pot_c);
  }
  Ken = ken;
  Kno_w = kno_w;

  return ken;
}

/* _eyre_ken(): load kernel by number.
*/
static u2_noun                                                    //  produce
_eyre_ken(u2_wire wir_r,
          c3_w    kno_w)
{
  c3_w    nec_w = EyreFirstKernel;
  u2_noun ken = u2_nul;
  u2_flag nuw = u2_no;

  while ( 1 ) {
    if ( u2_no == nuw ) {
      if ( u2_yes == _eyre_ken_nuw(nec_w) ) {
        nuw = u2_yes;

        if ( EyreFirstKernel == nec_w ) {
          fprintf(stderr, "eyre: %d is not fresh\n", EyreFirstKernel);
          exit(1);
        }
        else {
          u2_noun las = _eyre_ken_load_hard(wir_r, (nec_w + 1));
           
          ken = _eyre_ken_load_soft(wir_r, las, nec_w);
          u2_rz(wir_r, las);
        }
      }
    }
    else {
      u2_noun las = u2_rx(wir_r, ken);

      ken = _eyre_ken_load_soft(wir_r, las, nec_w);
      u2_rz(wir_r, las);
    }

    if ( nec_w == kno_w ) {
      if ( u2_no == nuw ) {
        return _eyre_ken_load_hard(wir_r, kno_w);
      }
      else return ken;
    } else {
      nec_w--;
    }
  }
}

/* _eyre_app(): load application core.
*/
static u2_noun                                                    //  produce
_eyre_app(u2_wire wir_r, 
          u2_noun ken,                                            //  retain
          c3_c*   lid_c)                                          //  retain
{
  u2_ray kit_r = u2_bl_open(wir_r);

  if ( u2_bl_set(wir_r) ) {
    u2_bl_done(wir_r, kit_r);
    fprintf(stderr, "{app: exit}\n");
    exit(1);
    return 0;
  } else {
    c3_c*   pot_c = _eyre_path_lid(lid_c);
    u2_noun src   = u2_ux_read(wir_r, pot_c, "watt");
    u2_noun noc, cor;

    printf("app: loading: %s\n", pot_c);

    noc = _eyre_nock(wir_r, u2_yes, src, ken);
    cor = _eyre_nock(wir_r, u2_yes, 0, noc);

    u2_rz(wir_r, noc);
    printf("app: %s\n", pot_c);
    free(pot_c);

    u2_bl_done(wir_r, kit_r);
    return cor;
  }
}

/* _eyre_call_1(): call a text function, with argument `a`.
*/
static u2_noun                                                    //  produce
_eyre_call_1(u2_wire     wir_r,
             u2_flag     rac,                                     //  direct
             u2_noun     ken,                                     //  retain
             const c3_c* src_c,                                   //  retain
             u2_noun     a)                                       //  retain
{
  u2_noun src = u2_bn_string(wir_r, src_c);
  u2_noun noc = _eyre_nock(wir_r, rac, src, ken);
  u2_noun cor = _eyre_nock(wir_r, rac, 0, noc);
  u2_noun pro = _eyre_mong(wir_r, rac, cor, u2_rx(wir_r, a));

  u2_rz(wir_r, cor);
  u2_rz(wir_r, noc);
  u2_rz(wir_r, src);

  return pro;
}

/* _eyre_call_2(): call a text function, with argument `[a b]`.
*/
static u2_noun                                                    //  produce
_eyre_call_2(u2_wire     wir_r,
             u2_flag     rac,                                     //  direct
             u2_noun     ken,                                     //  retain
             const c3_c* src_c,                                   //  retain
             u2_noun     a,                                       //  retain
             u2_noun     b)                                       //  retain
{
  u2_noun src = u2_bn_string(wir_r, src_c);
  u2_noun noc = _eyre_nock(wir_r, rac, src, ken);
  u2_noun cor = _eyre_nock(wir_r, rac, 0, noc);
  u2_noun pro = _eyre_mong(wir_r, rac, cor, u2_bc(wir_r, u2_rx(wir_r, a),
                                                         u2_rx(wir_r, b)));

  u2_rz(wir_r, cor);
  u2_rz(wir_r, noc);

  return pro;
}

/* _eyre_call_3(): call a text function, with argument `[a b c]`.
*/
static u2_noun                                                    //  produce
_eyre_call_3(u2_wire     wir_r,
             u2_flag     rac,                                     //  direct
             u2_noun     ken,                                     //  retain
             const c3_c* src_c,                                   //  retain
             u2_noun     a,                                       //  retain
             u2_noun     b,                                       //  retain
             u2_noun     c)                                       //  retain
{
  u2_noun src = u2_bn_string(wir_r, src_c);
  u2_noun noc = _eyre_nock(wir_r, rac, src, ken);
  u2_noun cor = _eyre_nock(wir_r, rac, 0, noc);
  u2_noun pro = _eyre_mong(wir_r, rac, cor, u2_bt(wir_r, u2_rx(wir_r, a),
                                                         u2_rx(wir_r, b),
                                                         u2_rx(wir_r, c)));

  u2_rz(wir_r, cor);
  u2_rz(wir_r, noc);

  return pro;
}

/* _eyre_columns(): return screen column width from OS.
*/
static c3_l
_eyre_columns(void)
{
  c3_s buf_s[4];
  
  ioctl(0, TIOCGWINSZ, &buf_s);

  return buf_s[1] - 1;
}

/* _eyre_tank_win(): tank to wall.
*/
static u2_noun
_eyre_tank_win(u2_wire wir_r,
               u2_noun ken,                                       //  retain
               c3_l    tab_l,
               u2_noun tec)                                       //  retain
{
  c3_l    edg_l = _eyre_columns();

  return _eyre_call_3
    (wir_r, u2_no,
            ken, 
            "|!([a=@ b=@ c=*tank] (~(win re c) [a b]))", 
            tab_l, edg_l, tec);
}

/* _eyre_bill(): bill to wall.
*/
static u2_noun
_eyre_bill(u2_wire wir_r,
           u2_noun ken,                                           //  retain
           u2_noun bil)                                           //  retain
{
  c3_l    edg_l = _eyre_columns();

  return _eyre_call_2
    (wir_r, u2_no, ken, "|!([a=@ b=*bill] (~(fly to b) a))", edg_l, bil);
}

/* _eyre_print_tape(): print a tape of txt to FIL_f.
*/
static void
_eyre_print_tape(u2_wire     wir_r,                               
                 u2_noun     tep)                                 //  retain
{
  while ( u2_nul != tep ) {
    c3_c car_c;

    if ( u2_h(tep) >= 127 ) {
      car_c = '?';
    } else car_c = u2_h(tep);

    putchar(car_c);
    tep = u2_t(tep);
  }
}

/* _eyre_print_wall(): print a wall of txt.
*/
static void
_eyre_print_wall(u2_wire     wir_r,                               
                 u2_noun     wal)                                 //  retain
{
  while ( u2_nul != wal ) {
    _eyre_print_tape(wir_r, u2_h(wal));
    putchar(10);

    wal = u2_t(wal);
  }
}

/* _eyre_gnaw(): dump a tank to a wall, with tab.
*/
static void
_eyre_gnaw(u2_wire wir_r,
           u2_noun ken,                                           //  retain
           c3_l    tab_l,
           u2_noun tec)                                           //  retain
{
  u2_noun wal;

  wal = _eyre_tank_win(wir_r, ken, tab_l, tec);
  _eyre_print_wall(wir_r, wal);

  u2_rz(wir_r, wal);
}

/* _eyre_dirt(): print an arbitrary noun as a wall.  Works <= 263.
*/
static void
_eyre_dirt(u2_wire wir_r, 
           u2_noun ken,                                           //  retain
           c3_l    tab_l,                                         //  retain
           u2_noun som)                                           //  retain
{
  u2_noun poq = u2_bc(wir_r, 'q', u2_rx(wir_r, som));
  u2_noun tec = _eyre_call_1(wir_r, u2_no, ken, "=>(!% show)", poq);

  _eyre_gnaw(wir_r, ken, tab_l, tec);

  u2_rz(wir_r, tec);
  u2_rz(wir_r, poq);
}
                  
/* _eyre_dump(): dump a bill to a wall.
*/
static void
_eyre_dump(u2_wire wir_r,
           u2_noun ken,                                           //  retain
           u2_noun bil)                                           //  retain
{
  u2_noun wal;

  wal = _eyre_bill(wir_r, ken, bil);
  _eyre_print_wall(wir_r, wal);

  u2_rz(wir_r, wal);
}

/* _eyre_print_spot(): print wrapper for file location, at tab of 2.
*/
static void
_eyre_print_spot(u2_wire wir_r,
                 u2_noun ken,                                     //  retain
                 u2_noun sot)                                     //  retain
{
  u2_noun p_sot, q_sot, r_sot, pq_sot, qq_sot, pr_sot, qr_sot;

  if ( (u2_yes == u2_as_trel(sot, &p_sot, &q_sot, &r_sot)) &&
       (u2_yes == u2_as_cell(q_sot, &pq_sot, &qq_sot)) &&
       (u2_yes == u2_as_cell(r_sot, &pr_sot, &qr_sot)) &&
       (u2_yes == u2_stud(pq_sot)) &&
       (u2_yes == u2_stud(qq_sot)) &&
       (u2_yes == u2_stud(pr_sot)) &&
       (u2_yes == u2_stud(qr_sot)) )
  {
    printf("{%d.%d:%d.%d}\n", pq_sot, qq_sot, pr_sot, qr_sot);
  }
  else {
    printf("  {spot!}\n");
    u2_err(wir_r, "{{invalid}}", sot);
  }
}

/* _eyre_print_bean(): print wrapper for flat meaning.
*/
static void
_eyre_print_bean(u2_wire wir_r,
                 u2_noun ken,                                     //  retain
                 u2_noun ben)                                     //  retain
{
  if ( Kno_w == 264 ) {
    _eyre_dump(wir_r, ken, ben);
  }
  else {
    _eyre_dirt(wir_r, ken, 2, ben);
  }
}

/* _eyre_print_mean(): print wrapper for meta-meaning.
*/
static void
_eyre_print_mean(u2_wire wir_r,
                 u2_noun ken,                                     //  retain
                 u2_noun mon)                                     //  retain
{
  if ( u2_yes == u2_dust(mon) ) {
    u2_noun som = u2_nk_nock(wir_r, u2_rx(wir_r, mon), u2_t(mon));

    if ( u2_none != som ) {
      _eyre_gnaw(wir_r, ken, 2, som);
      u2_rz(wir_r, som);
      return;
    }
    else printf("  {meaning failed!}\n");
  }
}

/* _eyre_print_tent(): print wrapper for trace entry.
*/
static void
_eyre_print_tent(u2_wire wir_r,
                 u2_noun ken,
                 u2_noun tax)                                     //  retain
{
  if ( u2_yes == u2_dust(tax) ) switch ( u2_h(tax) ) {
    case c3__spot: _eyre_print_spot(wir_r, ken, u2_t(tax)); return;
    case c3__bean: _eyre_print_bean(wir_r, ken, u2_t(tax)); return;
                   // u2_err(wir_r, "bean", u2_t(tax)); return;
    case c3__mean: _eyre_print_mean(wir_r, ken, u2_t(tax)); return;
  }
  // u2_err(wir_r, "htax", u2_h(tax));
  printf("  {tent!}\n");
}

/* _eyre_print_trac(): print wrapper for trace stack.
*/
static void
_eyre_print_trac(u2_wire wir_r,
                 u2_noun ken,
                 u2_noun tax)                                     //  retain
{
  while ( u2_nul != tax ) {
    _eyre_print_tent(wir_r, ken, u2_h(tax));
    tax = u2_t(tax);
  }
}

/* _eyre_line(): execute and print a line.
*/
static void
_eyre_line(u2_wire wir_r,
           u2_noun ken,                                           //  retain
           u2_noun cor,                                           //  retain
           u2_noun txt)                                           //  retain
{
  u2_ray kit_r = u2_bl_open(wir_r);

  if ( u2_bl_set(wir_r) ) {
    u2_bl_done(wir_r, kit_r);
    fprintf(stderr, "{stop}\n");
  } else {
    u2_noun gat = u2_bn_hook(wir_r, cor, "line");
    u2_noun pro;

    u2_bx_boot(wir_r);
    pro = _eyre_mong(wir_r, u2_yes, gat, u2_rx(wir_r, txt));
    u2_bx_show(wir_r);

#if 1
    _eyre_gnaw(wir_r, ken, 2, u2_h(pro));
    _eyre_gnaw(wir_r, ken, 0, u2_t(pro));
#else
    _eyre_gnaw(wir_r, ken, 0, pro);
#endif

    u2_bl_done(wir_r, kit_r);
  }
}

/* _eyre_line_proto(): parse line with old kernel, execute with new.
*/
static void
_eyre_line_proto(u2_wire wir_r, 
                 u2_noun las,                                     //  retain
                 u2_noun ken,                                     //  retain
                 u2_noun txt)                                     //  retain
{
  u2_ray kit_r = u2_bl_open(wir_r);

  if ( u2_bl_set(wir_r) ) {
    u2_bl_done(wir_r, kit_r);
    fprintf(stderr, "{stop}\n");
  } else {
    u2_noun fol = _eyre_call_1(wir_r, u2_yes, las, "=>(!% make)", txt);
    u2_noun som = _eyre_nock(wir_r, u2_yes, 0, fol);
    u2_noun pro;
   
    u2_bx_boot(wir_r);
    // u2_err(wir_r, "som", som);
    // u2_err(wir_r, "ken", ken);
    pro = _eyre_nock(wir_r, u2_yes, som, ken);
    u2_err(wir_r, "pro", pro);
    u2_bx_show(wir_r);

    // _eyre_dirt(wir_r, las, 0, pro); 
    u2_rz(wir_r, fol);
    u2_rz(wir_r, pro);

    u2_bl_done(wir_r, kit_r);
  }
}

/* main()::
*/
c3_i
main(c3_i   argc,
     c3_c** argv)
{
  u2_wire wir_r;
  c3_w    kno_w;
  c3_c*   fel_c;
  c3_c*   lid_c = 0;
  u2_noun ken;
  u2_noun las = 0;
  u2_noun app = 0;

  //  Parse arguments.
  //
  if ( argc == 1 ) {
    EyreSmoke = u2_no;
    kno_w = EyreFirstKernel;
    lid_c = strdup("hume");

    goto proceed;
  }
  if ( (0 == (kno_w = strtol(argv[1], 0, 10))) || (kno_w > EyreFirstKernel) ) {
    goto usage;
  }
  if ( 2 == argc ) {
    EyreSmoke = u2_yes;

    if ( kno_w > (EyreFirstKernel - 1) ) {
      goto usage;
    }
    printf("{smoke test %d}\n", kno_w);
    goto proceed;
  }
  else if ( 3 == argc ) {
    if ( !(lid_c = strdup(argv[2])) ) {
      goto usage;
    }
    EyreSmoke = u2_no;
    goto proceed;
  }

  usage: {
    fprintf(stderr, "usage: eyre $kernel [$shell]\n");
    fprintf(stderr, "  watt/$kernel.watt\n");
    fprintf(stderr, "    (FirstKernel is %d, kernels count down)\n", 
            EyreFirstKernel);
    fprintf(stderr, "  watt/$shell.watt\n");

    exit(1);
  } proceed:

  //  Instantiate system utilities.
  {
    u2_boot();
    wir_r = u2_wr_init(c3__rock, u2_ray_of(0, 0), u2_ray_of(1, 0));
    fel_c = c3_comd_init();
  }

  //  Load the kernel(s) and/or shell.
  //
  {
    if ( u2_yes == EyreSmoke ) {
      las = _eyre_ken(wir_r, (kno_w + 1));
      ken = _eyre_ken_load_soft(wir_r, las, kno_w);

      Ken = las;
      Kno_w = (kno_w + 1);
    }
    else {
      ken = _eyre_ken(wir_r, kno_w);
      app = _eyre_app(wir_r, ken, lid_c);
    }
  }

  //  Do some lines.
  //
  while ( 1 ) {
    c3_c* lin_c = c3_comd_line(fel_c);

    if ( !lin_c ) {
      break;
    }
    else {
      u2_noun lin = u2_bn_string(wir_r, lin_c);

      if ( u2_yes == EyreSmoke ) {
        _eyre_line_proto(wir_r, las, ken, lin);
      } else {
        _eyre_line(wir_r, ken, app, lin);
      }
      free(lin_c);
      u2_rz(wir_r, lin);
    }
  }
  return 0;
}

#if 0
/* _eyre_test2(): advanced test.
*/
static void
_eyre_test2(u2_wire wir_r, 
            u2_noun ken,
            c3_c*   lid_c)
{
  u2_ray kit_r = u2_bl_open(wir_r);

  if ( u2_bl_set(wir_r) ) {
    u2_bl_done(wir_r, kit_r);
    fprintf(stderr, "{exit}\n");
  } else {
    c3_c*   pot_c = _eyre_path_lid(lid_c);
    u2_noun src   = u2_ux_read(wir_r, pot_c, "watt");
    u2_noun noc, cor, bum, goo;

    printf("compiling...\n");
    noc = _eyre_nock(wir_r, src, ken);
    printf("composing...\n");
    cor = _eyre_nock(wir_r, 0, noc);
    printf("ready...\n");

    bum = u2_bn_hook(wir_r, cor, "bump");
    printf("bumped...\n");

    goo = u2_bn_mong(wir_r, bum, 13);
    u2_err(wir_r, "goo", goo);

    u2_bl_done(wir_r, kit_r);
  }
}
#endif
