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

struct {
  struct {
    const c3_c* kcuu1_c;      //  key_up 
    const c3_c* kcud1_c;      //  key_down
    const c3_c* kcub1_c;      //  key_back
    const c3_c* kcuf1_c;      //  key_forward
    const c3_c* kbs_c;        //  backspace
  } inn;
  struct {
    const c3_c* el_c;         //  clr_bol clear to beginning of line
    const c3_c* el1_c;        //  clr_eol clear to end of lin
    const c3_c* bel_c;        //  bel sound bell
    const c3_c* cub1_c;       //  parm_left
    const c3_c* cuf1_c;       //  parm_right
    const c3_c* cub_c;        //  parm_left_cursor #num
    const c3_c* cuf_c;        //  parm_right_cursor #num 
  } out;
} Terminfo;

struct {
  struct {
    c3_y* lin_y;    // current line
    c3_w  len_w;    // length of current line
    c3_w  cus_w;    // cursor position
  } out;

  struct {
    c3_y esc_y[4];  // escape code buffer
    c3_w esc_w;     // escape length
  } inn;
} State;

  void 
  u2_term_io_init(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
  }

  void
  u2_term_io_poll(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
  }

  void
  u2_term_io_spin(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
  }

  void
  u2_term_io_stop(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
  }

  void
  u2_term_io_suck(u2_reck*      rec_u,
                  struct ev_io* wax_u)
  {
  }

  void 
  u2_term_io_exit(u2_reck*        rec_u,
                  struct ev_loop* lup_u)
  {
  }

static void
_term_write_str(c3_i fid_i, const c3_c* str_c)
{
  c3_w len_w = strlen(str_c);

  if ( len_w != write(fid_i, str_c, strlen(str_c)) ) {
    c3_assert(!"write");
  }
}

static void
_term_write_strnum(c3_i fid_i, const c3_c* str_c, c3_w num_w)
{
  c3_c buf_c[16];

  sprintf(buf_c, "#%ud", num_w);   //  XX slow
  _term_write_str(fid_i, str_c);
  _term_write_str(fid_i, buf_c);
}

static void
_term_bail_bad(const char* msg)
{
  printf("bail: bad %s\r\n", msg);
  exit(1);
}

static void
_term_exit(c3_i fid_i)
{
  while ( 0 != tcsetattr(fid_i, TCSADRAIN, &Oldattr) ) {
    if ( errno != EINTR ) {
      _term_bail_bad("tcsetattr");
    }
  }
}

static void
_term_exit_bad(c3_i fid_i, const char* msg)
{
  printf("exit: bad %s\r\n", msg);
  _term_exit(fid_i);
  exit(1);
}

static void
_term_exit_good(c3_i fid_i)
{
  printf("exit: good\r\n");
  _term_exit(fid_i);
  exit(0);
}

static void
_term_beep(c3_i fid_i)
{
  putchar(7);
  fflush(stdout);
}

static void
_term_text(c3_i fid_i, c3_y* txt_y)
{
  _term_write_str(fid_i, (c3_c*)txt_y);
  State.out.cus_w += strlen((c3_c*)txt_y);
}

static void
_term_cursor_right(c3_i fid_i)
{
  _term_write_str(fid_i, Terminfo.out.cuf1_c);
}

static void
_term_cursor_left(c3_i fid_i)
{
  _term_write_str(fid_i, Terminfo.out.cub1_c);
}

static void
_term_clear(c3_i fid_i)
{
  _term_write_str(fid_i, "\r");
  _term_write_str(fid_i, Terminfo.out.el1_c);
  State.out.cus_w = 0;
}

static void
_term_set_line(c3_i fid_i, c3_y* lin_y)   // transfer lin_y
{
  _term_clear(fid_i);
  _term_text(fid_i, lin_y);

  free(State.out.lin_y);
  State.out.lin_y = lin_y;
  State.out.len_w = strlen((c3_c*)lin_y);
}

static void
_term_set_cursor(c3_i fid_i, c3_w cur_w)
{
  if ( cur_w < State.out.cus_w ) {
    c3_w dif_w = (State.out.cus_w - cur_w);

    while ( dif_w-- ) {
      _term_write_str(fid_i, Terminfo.out.cub1_c);
    }
  }
  else if ( cur_w > State.out.cus_w ) {
    c3_w dif_w = (cur_w - State.out.cus_w);

    while ( dif_w-- ) {
      _term_write_str(fid_i, Terminfo.out.cuf1_c);
    }
  }
  State.out.cus_w = cur_w;
}

static void
_term_byte_regular(c3_i fid_i, c3_y byt_y)
{
  c3_w  len_w = State.out.len_w;
  c3_w  cus_w = State.out.cus_w;
  c3_y* lin_y = State.out.lin_y;
  c3_y* nuw_y = malloc(len_w + 2);

  if ( cus_w > 0 ) {
    memcpy(nuw_y, lin_y, State.out.cus_w);
  }
  nuw_y[cus_w] = byt_y;
  if ( cus_w < len_w ) {
    memcpy(nuw_y + cus_w + 1, lin_y + cus_w, (len_w - cus_w));
  }
  nuw_y[len_w + 1] = 0;

  _term_set_line(fid_i, nuw_y);
  _term_set_cursor(fid_i, cus_w + 1);

  //  printf("regular byte %x\r\n", byt_y);
  //  fflush(stdout);
}

static void
_term_arrow_left(c3_i fid_i)
{
  if ( 0 == State.out.cus_w ) {
    _term_write_str(fid_i, Terminfo.out.bel_c);
  } else {
    _term_set_cursor(fid_i, State.out.cus_w - 1);
  }
}

static void
_term_arrow_right(c3_i fid_i)
{
  if ( (State.out.len_w - 1) == State.out.cus_w ) {
    _term_write_str(fid_i, Terminfo.out.bel_c);
  } else {
    _term_set_cursor(fid_i, State.out.cus_w + 1);
  }
}

static void
_term_byte(c3_i fid_i, c3_y byt_y)
{
  switch ( State.inn.esc_w ) {
    case 0: {
      if ( 0x1b != byt_y ) {
        _term_byte_regular(fid_i, byt_y);
      } else {
        State.inn.esc_w = 1;
        State.inn.esc_y[0] = 0x1b;
      }
      break;
    }
    case 1: {
      if ( 0x5b != byt_y ) {
        _term_beep(fid_i);
        State.inn.esc_w = 0;
      }
      else {
        State.inn.esc_w = 2;
        State.inn.esc_y[1] = 0x5b;
      }
      break;
    }
    case 2: {
      switch ( byt_y ) {
        default: _term_beep(fid_i); break;
        case 0x43: _term_arrow_right(fid_i); break; 
        case 0x44: _term_arrow_left(fid_i); break; 
      }
      State.inn.esc_w = 0;
      break;
    }
  }
}

static void
_term_init(c3_i fid_i)
{
  if ( OK != setupterm(0, 2, 0) ) {
    _term_bail_bad("init-setupterm");
  }
  if ( 0 != tcgetattr(fid_i, &Oldattr)) {
    _term_bail_bad("init-tcgetattr");
  }
  Newattr = Oldattr;

  Newattr.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN);
  Newattr.c_iflag &= ~(ICRNL | INPCK | ISTRIP);
  Newattr.c_cflag &= ~(CSIZE | PARENB);
  Newattr.c_cflag |= CS8;
  Newattr.c_oflag &= ~(OPOST);
  Newattr.c_cc[VMIN] = 1;   //  0
  Newattr.c_cc[VTIME] = 0;

  if ( 0 != tcsetattr(fid_i, TCSADRAIN, &Newattr) ) {
    _term_bail_bad("init-tcsetattr");
  }

  State.out.lin_y = (c3_y*)strdup("");
  State.out.len_w = 0;
  State.out.cus_w = 0;

  State.inn.esc_w = 0;

  Terminfo.inn.kcuu1_c = tigetstr("kcuu1");
  Terminfo.inn.kcud1_c = tigetstr("kcud1");
  Terminfo.inn.kcub1_c = tigetstr("kcub1");
  Terminfo.inn.kcuf1_c = tigetstr("kcuf1");

  Terminfo.out.el_c = tigetstr("el");
  Terminfo.out.el1_c = tigetstr("el1");
  Terminfo.out.bel_c = tigetstr("bel");
  Terminfo.out.cub1_c = tigetstr("cub1");
  Terminfo.out.cuf1_c = tigetstr("cuf1");
  Terminfo.out.cub_c = tigetstr("cub");
  Terminfo.out.cuf_c = tigetstr("cuf");

  c3_assert(Terminfo.inn.kcuu1_c);
  c3_assert(Terminfo.inn.kcud1_c);
  c3_assert(Terminfo.inn.kcub1_c);
  c3_assert(Terminfo.inn.kcuf1_c);

  c3_assert(Terminfo.out.el_c);
  c3_assert(Terminfo.out.el1_c);
  c3_assert(Terminfo.out.bel_c);
  c3_assert(Terminfo.out.cub1_c);
  c3_assert(Terminfo.out.cuf1_c);
  c3_assert(Terminfo.out.cub_c);
  c3_assert(Terminfo.out.cuf_c);
}

void 
TermTest(void)
{
#if 1
  {
    _term_init(2);
    
    while ( 1 ) {
      int siz;
      c3_y c_y = 0;

      siz = read(1, &c_y, 1);
      if ( siz == 0 ) {
        _term_exit_good(2);
      }
      else if ( siz == -1 ) {
        perror("read");
        _term_exit_bad(2, "read");
      }
      else {
        if ( 'Z' == c_y ) {
          break;
        }
        else _term_byte(2, c_y);
      }
    }
  }
  _term_exit_good(2);
#endif
}
