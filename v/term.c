/* v/term.c
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
#include <sys/socket.h>
#include <netinet/in.h>
#include <ev.h>
#include <errno.h>
#include <curses.h>
#include <termios.h>
#include <term.h>

#include "all.h"
#include "v/vere.h"

struct termios Oldattr;
struct termios Newattr;

static void _lo_term(struct ev_loop *lup_u, struct ev_io* wax_u, c3_i rev_i)
  { u2_lo_call(&u2_Host.rec_u[0], lup_u, wax_u, c3__term, rev_i); }

void 
u2_term_io_init(u2_reck* rec_u)
{
  u2_utty* uty_u = malloc(sizeof(u2_utty));
  c3_i     fid_i = 1;                         //  stdin/stdout

  //  Initialize event processing.
  //
  {
    ev_io_init(&uty_u->wax_u, _lo_term, fid_i, 0);
  }

  //  Configure horrible stateful terminfo api.
  //
  {
    if ( 0 != setupterm(0, 2, 0) ) {
      c3_assert(!"init-setupterm");
    }
  }

  //  Load terminfo strings.
  //
  {
    c3_w len_w;

#   define _utfo(way, nam) \
    { \
      uty_u->ufo_u.way.nam##_y = (const c3_y *) tigetstr(#nam); \
      c3_assert(uty_u->ufo_u.way.nam##_y); \
    }

    uty_u->ufo_u.inn.max_w = 0;

    _utfo(inn, kcuu1);
    _utfo(inn, kcud1);
    _utfo(inn, kcub1);
    _utfo(inn, kcuf1);

    _utfo(out, el);
    _utfo(out, el1);
    _utfo(out, bel);
    _utfo(out, cub1);
    _utfo(out, cuf1);
    _utfo(out, cub);
    _utfo(out, cuf);

    //  Terminfo chronically reports the wrong sequence for arrow
    //  keys on xterms.  Drastic fix for ridiculous unacceptable bug.
    //  Yes, we could fix this with smkx/rmkx, but this is retarded as well.
    {
      uty_u->ufo_u.inn.kcuu1_y = (const c3_y*)"\033[A";
      uty_u->ufo_u.inn.kcud1_y = (const c3_y*)"\033[B";
      uty_u->ufo_u.inn.kcuf1_y = (const c3_y*)"\033[C";
      uty_u->ufo_u.inn.kcub1_y = (const c3_y*)"\033[D";
    }

    uty_u->ufo_u.inn.max_w = 0;
    if ( (len_w = strlen((c3_c*)uty_u->ufo_u.inn.kcuu1_y)) > 
          uty_u->ufo_u.inn.max_w ) 
    {
      uty_u->ufo_u.inn.max_w = len_w;
    }
    if ( (len_w = strlen((c3_c*)uty_u->ufo_u.inn.kcud1_y)) > 
          uty_u->ufo_u.inn.max_w ) 
    {
      uty_u->ufo_u.inn.max_w = len_w;
    }
    if ( (len_w = strlen((c3_c*)uty_u->ufo_u.inn.kcub1_y)) > 
          uty_u->ufo_u.inn.max_w ) 
    {
      uty_u->ufo_u.inn.max_w = len_w;
    }
    if ( (len_w = strlen((c3_c*)uty_u->ufo_u.inn.kcuf1_y)) > 
          uty_u->ufo_u.inn.max_w ) 
    {
      uty_u->ufo_u.inn.max_w = len_w;
    }
  }

  //  Load old terminal state to restore.
  //
  {
    if ( 0 != tcgetattr(fid_i, &uty_u->bak_u) ) {
      c3_assert(!"init-tcgetattr");
    }
    if ( -1 == fcntl(fid_i, F_GETFL, &uty_u->cug_i) ) {
      c3_assert(!"init-fcntl");
    }
    uty_u->nob_i = uty_u->cug_i | O_NONBLOCK;   // O_NDELAY on older unix
  }

  //  Construct raw termios configuration.
  //
  {
    uty_u->raw_u = uty_u->bak_u;

    uty_u->raw_u.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN);
    uty_u->raw_u.c_iflag &= ~(ICRNL | INPCK | ISTRIP);
    uty_u->raw_u.c_cflag &= ~(CSIZE | PARENB);
    uty_u->raw_u.c_cflag |= CS8;
    uty_u->raw_u.c_oflag &= ~(OPOST);
    uty_u->raw_u.c_cc[VMIN] = 0;
    uty_u->raw_u.c_cc[VTIME] = 0;
  } 

  //  Initialize mirror and accumulator state.
  //
  {
    uty_u->tat_u.mir.lin_y = (c3_y*)strdup("");
    uty_u->tat_u.mir.len_w = 0;
    uty_u->tat_u.mir.cus_w = 0;

    uty_u->tat_u.acc.len_w = 0;
  }

  //  This is terminal 1, with an empty queue, linked in host.
  //
  {
    uty_u->tid_l = 1;
    uty_u->pax = u2nq(c3__gold, c3__term, '1', u2_nul); 
    uty_u->out_u = 0;
    uty_u->tou_u = 0;

    uty_u->nex_u = u2_Host.uty_u;
    u2_Host.uty_u = uty_u;
  }

  //  Tell the terminal how big it is.
  //
  {
    struct winsize siz_u;

    if ( 0 == ioctl(uty_u->wax_u.fd, TIOCGWINSZ, &siz_u) ) {
      u2_reck_plan
        (rec_u, u2k(uty_u->pax), 
                u2nt(c3__blew, siz_u.ws_col, siz_u.ws_row));
    }
  }

  //  Start raw input.
  //
  {
    if ( 0 != tcsetattr(uty_u->wax_u.fd, TCSADRAIN, &uty_u->raw_u) ) {
      c3_assert(!"spin-tcsetattr");
    }
    if ( -1 == fcntl(uty_u->wax_u.fd, F_SETFL, uty_u->nob_i) ) {
      c3_assert(!"spin-fcntl");
    }
  }
}

/* u2_term_io_exit(): clean up terminal.
*/
void 
u2_term_io_exit(u2_reck* rec_u)
{
  u2_utty* uty_u;

  for ( uty_u = u2_Host.uty_u; uty_u; uty_u = uty_u->nex_u ) {
    if ( 0 != tcsetattr(uty_u->wax_u.fd, TCSADRAIN, &uty_u->bak_u) ) {
      c3_assert(!"exit-tcsetattr");
    }
    if ( -1 == fcntl(uty_u->wax_u.fd, F_SETFL, uty_u->cug_i) ) {
      c3_assert(!"exit-fcntl");
    }
  }
}

void
u2_term_io_poll(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_utty* uty_u;

  for ( uty_u = u2_Host.uty_u; uty_u; uty_u = uty_u->nex_u ) {
    c3_i ver_i = 0;

    ver_i |= EV_READ;   //  no constraint on reading right now
    if ( uty_u->out_u ) {
      ver_i |= EV_WRITE;
    }
    ev_io_set(&uty_u->wax_u, uty_u->wax_u.fd, ver_i);
  }
}

void
u2_term_io_spin(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_utty* uty_u;

  for ( uty_u = u2_Host.uty_u; uty_u; uty_u = uty_u->nex_u ) {
    ev_io_start(lup_u, &uty_u->wax_u);
  }
}

void
u2_term_io_stop(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_utty* uty_u;

  for ( uty_u = u2_Host.uty_u; uty_u; uty_u = uty_u->nex_u ) {
    ev_io_stop(lup_u, &uty_u->wax_u);
  }
}

/* _term_it_clip(): remove sent bytes from buffer.
**
** XX unify with ubuf in http.c
*/
static void
_term_it_clip(u2_ubuf* buf_u, c3_i siz_i)
{
  if ( siz_i ) {
    c3_assert(siz_i < buf_u->len_w);
    {
      c3_w res_w = (buf_u->len_w - siz_i);

      memmove(buf_u->hun_y, (buf_u->hun_y + siz_i), res_w);
      buf_u->len_w = res_w;
    }
  }
}

/* _term_it_buf(): create a data buffer.
*/
static u2_ubuf*
_term_it_buf(c3_w len_w, const c3_y* hun_y)
{
  u2_ubuf* buf_u = malloc(len_w + sizeof(*buf_u));

  buf_u->len_w = len_w;
  memcpy(buf_u->hun_y, hun_y, len_w);
  
  buf_u->nex_u = 0;
  return buf_u;
}

/* _term_it_queue_buf(): queue buffer, transferring pointer.
*/
static void
_term_it_queue_buf(u2_utty* uty_u,
                   u2_ubuf* buf_u)
{
  if ( !uty_u->tou_u ) {
    uty_u->out_u = uty_u->tou_u = buf_u;
  }
  else {
    uty_u->tou_u->nex_u = buf_u;
    uty_u->tou_u = buf_u;
  }
}

/* _term_it_queue_bytes(): queue bytes, retaining pointer.
*/
static void
_term_it_queue_bytes(u2_utty*    uty_u,
                     c3_w        len_w,
                     const c3_y* hun_y)
{
  _term_it_queue_buf(uty_u, _term_it_buf(len_w, hun_y));
}

/* _term_it_queue_txt(): queue null-terminated string, retaining pointer.
*/
static void
_term_it_queue_txt(u2_utty*    uty_u,
                   const c3_y* hun_y)
{
  _term_it_queue_bytes(uty_u, strlen((const c3_c*)hun_y), hun_y);
}

/* _term_it_queue_str(): queue null-terminated string, retaining pointer.
*/
static void
_term_it_queue_str(u2_utty*    uty_u,
                   const c3_c* str_c)
{
  _term_it_queue_txt(uty_u, (const c3_y*) str_c);
}

/* _term_it_queue_strnum(): queue string with terminal parameter, retaining.
*/
static void
_term_it_queue_strnum(u2_utty* uty_u, const c3_c* str_c, c3_w num_w)
{
  c3_c buf_c[16];

  sprintf(buf_c, "#%ud", num_w);   //  XX slow
  _term_it_queue_str(uty_u, str_c);
  _term_it_queue_str(uty_u, buf_c);
}

/* _term_it_show_text(): show ordinary text, retaining.
*/
static void
_term_it_show_text(u2_utty* uty_u, c3_y* txt_y)
{
  _term_it_queue_str(uty_u, (c3_c*)txt_y);
  uty_u->tat_u.mir.cus_w += strlen((c3_c*)txt_y);
}

/* _term_it_show_clear(): clear to the beginning of the current line.
*/
static void
_term_it_show_clear(u2_utty* uty_u)
{
  _term_it_queue_str(uty_u, "\r");
  _term_it_queue_txt(uty_u, uty_u->ufo_u.out.el_y);
  uty_u->tat_u.mir.cus_w = 0;
}

/* _term_it_show_cursor(): set current line, transferring pointer.
*/
static void
_term_it_show_cursor(u2_utty* uty_u, c3_w cur_w)
{
  if ( cur_w < uty_u->tat_u.mir.cus_w ) {
    c3_w dif_w = (uty_u->tat_u.mir.cus_w - cur_w);

    while ( dif_w-- ) {
      _term_it_queue_txt(uty_u, uty_u->ufo_u.out.cub1_y);
    }
  }
  else if ( cur_w > uty_u->tat_u.mir.cus_w ) {
    c3_w dif_w = (cur_w - uty_u->tat_u.mir.cus_w);

    while ( dif_w-- ) {
      _term_it_queue_txt(uty_u, uty_u->ufo_u.out.cuf1_y);
    }
  }
  uty_u->tat_u.mir.cus_w = cur_w;
}

/* _term_it_show_line(): set current line, transferring pointer.
*/
static void
_term_it_show_line(u2_utty* uty_u, c3_y* lin_y)
{
  _term_it_show_clear(uty_u);
  _term_it_show_text(uty_u, lin_y);

  free(uty_u->tat_u.mir.lin_y);
  uty_u->tat_u.mir.lin_y = lin_y;
  uty_u->tat_u.mir.len_w = strlen((c3_c*)lin_y);
}

/* _term_it_show_more(): new current line.
*/
static void
_term_it_show_more(u2_utty* uty_u)
{
  _term_it_queue_str(uty_u, "\r\n");
  uty_u->tat_u.mir.cus_w = 0;
}

/* _term_io_bleb(): send bleb.
*/
static void
_term_io_bleb(u2_reck* rec_u,
              u2_utty* uty_u,
              u2_noun  blb)
{
  u2_reck_plan(rec_u, u2k(uty_u->pax), u2nc(c3__bleb, blb));
}

/* _term_io_suck_char(): process a single character.
*/
static void
_term_io_suck_char(u2_reck* rec_u,
                   u2_utty* uty_u,
                   c3_y     cay_y)
{
  if ( 0 == uty_u->tat_u.acc.len_w ) {
    if ( (cay_y >= 32) && (cay_y < 127) ) {
      _term_io_bleb(rec_u, uty_u, u2nt(c3__txt, cay_y, u2_nul));
    }
    else if ( 13 == cay_y ) {
      _term_io_bleb(rec_u, uty_u, u2nc(c3__ret, u2_nul));
    }
    else if ( 27 == cay_y ) {
      uty_u->tat_u.acc.len_w = 1;
      uty_u->tat_u.acc.syp_y[0] = 27;
    }
    else if ( 127 == cay_y ) {
      _term_io_bleb(rec_u, uty_u, u2nc(c3__bac, u2_nul));
    }
    else {
      if ( cay_y <= 26 ) {
        _term_io_bleb(rec_u, uty_u, u2nt(c3__ctl, cay_y, u2_nul));
      } else {
        _term_it_queue_txt(uty_u, uty_u->ufo_u.out.bel_y);
      }
    }
  }
  else {
    u2_utfo* ufo_u = &uty_u->ufo_u;
    u2_utat* tat_u = &uty_u->tat_u;

    tat_u->acc.syp_y[tat_u->acc.len_w] = cay_y;
    tat_u->acc.syp_y[tat_u->acc.len_w + 1] = 0;
    tat_u->acc.len_w += 1;

    //  Very stupid parsing!  Computers very fast these days...
    //
    if ( !strcmp((c3_c*)ufo_u->inn.kcuu1_y, (c3_c*)tat_u->acc.syp_y) ) {
      tat_u->acc.len_w = 0;
      _term_io_bleb(rec_u, uty_u, u2nc(c3__aro, 'u'));
    }
    else if ( !strcmp((c3_c*)ufo_u->inn.kcud1_y, (c3_c*)tat_u->acc.syp_y) ) {
      tat_u->acc.len_w = 0;
      _term_io_bleb(rec_u, uty_u, u2nc(c3__aro, 'd'));
    }
    else if ( !strcmp((c3_c*)ufo_u->inn.kcub1_y, (c3_c*)tat_u->acc.syp_y) ) {
      tat_u->acc.len_w = 0;
      _term_io_bleb(rec_u, uty_u, u2nc(c3__aro, 'l'));
    }
    else if ( !strcmp((c3_c*)ufo_u->inn.kcuf1_y, (c3_c*)tat_u->acc.syp_y) ) {
      tat_u->acc.len_w = 0;
      _term_io_bleb(rec_u, uty_u, u2nc(c3__aro, 'r'));
    }
    else {
      if ( ufo_u->inn.max_w == tat_u->acc.len_w ) {
        tat_u->acc.len_w = 0;
        _term_it_queue_txt(uty_u, uty_u->ufo_u.out.bel_y);
      }
    }
  }
}

/* u2_term_io_suck(): read terminal bytes.
*/
void
u2_term_io_suck(u2_reck*      rec_u,
                struct ev_io* wax_u)
{
  u2_utty* uty_u = (u2_utty*)(void*)wax_u;

  {
    while ( 1 ) {
      c3_y buf_y[4096];
      c3_i siz_i, i;

      if ( (siz_i = read(uty_u->wax_u.fd, buf_y, 4096)) < 0) {
        if ( EAGAIN == errno ) {
          break;
        } else {
          c3_assert(!"term: read");
        }
      }
      for ( i=0; i < siz_i; i++ ) {
        _term_io_suck_char(rec_u, uty_u, buf_y[i]);
      }
      if ( 4096 != siz_i ) {
        break;
      }
    }
  }
}

/* u2_term_io_fuck(): write terminal bytes.
*/
void
u2_term_io_fuck(u2_reck*      rec_u,
                struct ev_io* wax_u)
{
  u2_utty* uty_u = (u2_utty*)(void*)wax_u;

  {
    while ( uty_u->out_u ) {
      u2_ubuf* out_u = uty_u->out_u;
      c3_i     siz_i;

      if ( (siz_i = write(uty_u->wax_u.fd, 
                          uty_u->out_u->hun_y, 
                          uty_u->out_u->len_w)) < 0 ) {
        if ( EAGAIN == errno ) {
          break;
        } else {
          c3_assert(!"term: write");
        }
      }
      if ( siz_i < out_u->len_w ) {
        _term_it_clip(out_u, siz_i);
        break;
      }
      else {
        uty_u->out_u = uty_u->out_u->nex_u;
        if ( 0 == uty_u->out_u ) {
          c3_assert(out_u == uty_u->tou_u);
          uty_u->tou_u = 0;
        }
        free(out_u);
      }
    }
  }
}

/* _term_ef_blit(): send blit to terminal.
*/
static void
_term_ef_blit(u2_reck* rec_u,
              u2_utty* uty_u,
              u2_noun  blt)
{
  switch ( u2h(blt) ) {
    default: c3_assert(!"term: bad blit"); return;
    case c3__bel: {
      _term_it_queue_txt(uty_u, uty_u->ufo_u.out.bel_y);
    } break;
    case c3__hop: {
      _term_it_show_cursor(uty_u, u2t(blt)); 
    } break;
    case c3__lin: {
      c3_y* lin_y = u2_cr_tape(u2k(u2t(blt)));

      _term_it_show_line(uty_u, lin_y);
    } break;
    case c3__mor: {
      _term_it_show_more(uty_u);
    } break;
  }
  u2z(blt);
  return;
}

/* _term_ef_blits(): send blit list to terminal.
*/
static void
_term_ef_blits(u2_reck* rec_u,
               c3_l     tid_l,
               u2_noun  bls)
{
  u2_utty* uty_u;

  for ( uty_u = u2_Host.uty_u; uty_u; uty_u = uty_u->nex_u ) {
    if ( tid_l == uty_u->tid_l ) {
      u2_noun bis = bls;

      while ( u2_yes == u2du(bis) ) {
        _term_ef_blit(rec_u, uty_u, u2k(u2h(bis)));
        bis = u2t(bis);
      }
      u2z(bls);
      return;
    }
  }
  u2z(bls);
  c3_assert(!"term: bad terminal id");
}

static u2_bean
_term_ud(u2_noun txt, c3_l* tid_l)
{
  if ( u2_no == u2ud(txt) ) {
    return u2_no;
  } else {
    c3_c* tid_c = u2_cr_string(txt);

    u2z(txt);
    return 
        ( (1 == sscanf(tid_c, "%ud", tid_l)) && !(0x80000000 & *tid_l) )
      ? u2_yes
      : u2_no;
  }
}

/* u2_term_ef_blit(): send %blit effect to to terminal.
*/
void
u2_term_ef_blit(u2_reck* rec_u,
                u2_noun  pox,
                u2_noun  blt)
{
  u2_noun p_pox, q_pox, r_pox, s_pox;
  c3_l    tid_l;

  //  Is blit from a terminal?  Perfect.
  //
  if ( (u2_yes == u2_cr_qual(pox, &p_pox, &q_pox, &r_pox, &s_pox)) &&
       ((c3__gold == p_pox) || (c3__iron == p_pox)) &&
       (c3__term == q_pox) &&
       (u2_yes == _term_ud(u2k(r_pox), &tid_l)) &&
       (u2_nul == s_pox) )
  { } 
  else {
    if ( 0 == u2_Host.uty_u ) {
      //  Discard console if no terminal.
      //
      u2z(pox); u2z(blt); return;
    } else {
      u2_utty* uty_u;

      for ( uty_u = u2_Host.uty_u; uty_u; uty_u = uty_u->nex_u ) {
        if ( uty_u->wax_u.fd <= 2 ) {
          tid_l = uty_u->tid_l;
          break;
        }
      }
      if ( !uty_u ) {
        tid_l = u2_Host.uty_u->tid_l;
      }
    }
  }

  return _term_ef_blits(rec_u, tid_l, blt);
} 
