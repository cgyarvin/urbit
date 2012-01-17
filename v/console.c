/* v/console.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <stdint.h>

#include "all.h"
#include "v/vere.h"

    /* Temporary dependency on old gunn.
    */
      /* u2_ve_gunn_line(): apply command line.
      */
        void
        u2_ve_gunn_line(u2_noun cor, u2_noun txt);

/* u2_ve_dump_columns(): return screen column width from OS.
*/
c3_l
u2_ve_dump_columns(void)
{
  c3_s buf_s[4];
  
  ioctl(0, TIOCGWINSZ, &buf_s);

  return buf_s[1] - 1;
}

/* u2_ve_dump_tape(): print a tape of text.
*/
void
u2_ve_dump_tape(u2_noun tep)
{
  while ( u2_nul != tep ) {
    c3_c car_c;

    if ( u2h(tep) >= 127 ) {
      car_c = '?';
    } else car_c = u2h(tep);

    putchar(car_c);
    tep = u2t(tep);
  }
  u2_cz(tep);
}

/* u2_ve_dump_wall(): print a wall of text.
*/
void
u2_ve_dump_wall(u2_noun wol)
{
  while ( u2_nul != wol ) {
    u2_ve_dump_tape(u2_ct(u2h(wol)));
    putchar(10);

    wol = u2t(wol);
  }
  u2_cz(wol);
}

/* u2_ve_sway(): print trace stack.
*/
void
u2_ve_sway(c3_l tab_l, u2_noun tax)
{
  while ( u2_yes == u2_cr_du(tax) ) {
    u2_noun h_tax = u2h(tax);
    u2_noun t_tax = u2t(tax);
    c3_w poq_w = u2_cm_wind();
    u2_noun how;

    if ( 0 != (how = u2_cm_trap()) ) {
      fprintf(stderr, "  !!--!!\n");
    } 
    else {
      c3_l    col_l = u2_ve_dump_columns();
      u2_noun tac;
      u2_noun wol;

      tac = u2_ve_hard("pitt", "swan", u2_ct(h_tax));
      wol = u2_ve_hard("pitt", "wash", u2nc(u2nc(tab_l, col_l), tac));

      u2_ve_dump_wall(wol);
      u2_cm_done(poq_w);
    }
    tax = t_tax;
  }
  u2_cz(tax);
}

/* u2_ve_wine(): analyze and express error result.
*/
void
u2_ve_wine(u2_noun how)
{
  u2_noun p_how, q_how;

  if ( u2_no == u2_cr_du(how) ) {
    switch ( how ) {
      case c3__exit: fprintf(stderr, "<<exit>>:\n"); break;
      case c3__fail: fprintf(stderr, "<<fail>>:\n"); break;
      case c3__intr: fprintf(stderr, "<<intr>>:\n"); break;
      default:       fprintf(stderr, "<<--->>\n"); break;
    }
  } else {
    switch ( u2_h(how) ) {
      case c3__fail: u2_cx_cell(u2_t(how), &p_how, &q_how);
      {
        c3_c* str_c = u2_cr_string(p_how);

        fprintf(stderr, "<<fail (%s)>>:\n", str_c);
        break;
      }
      case c3__need: u2_cx_cell(u2_t(how), &p_how, &q_how);
      {
        fprintf(stderr, "<<need>>:\n");

        u2_err(u2_Wire, "need", p_how);
        break;
      }
      default: {
        fprintf(stderr, "<<--->>\n");
        break;
      }
    }
  }
  u2_cz(how);
}

/* u2_ve_line(): execute a command line, fully protected.
*/
void
u2_ve_line(c3_c* lin_c)
{
  c3_w poq_w;
  u2_noun how;

  u2_cm_trip();
  u2_ve_grab(0);
  poq_w = u2_cm_wind();

  if ( 0 != (how = u2_cm_trap()) ) {
    u2_noun rap = u2_cm_trac();
    u2_cm_done(poq_w);
    //  gc with rap as root

    u2_ve_wine(how);
    u2_ve_sway(2, u2_ckb_flop(rap));
  } 
  else {
    u2_noun cor = u2_ve_gunn();
    u2_noun lin = u2_ci_string(lin_c);

    u2_ve_gunn_line(cor, lin);
    u2_cm_done(poq_w);
  }
  u2_cm_purge();
  if ( u2_yes == u2_Flag_Garbage ) {
    u2_ve_grab(0);
  }
  u2_cm_chin();
}
