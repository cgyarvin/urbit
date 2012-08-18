/* v/sync.c
**
**  This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <dirent.h>
#include <stdint.h>
#include <ev.h>

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

  /*  ::  |%  
  **  ::  ++  node
  **  ::    $%  [& p=time]                           ::  file/mtime
  **  ::        [| p=(map span node)]                ::  directory
  **  ::    ==
  **  ::  --
  */

/* u2_sync_load(): load file or bail.
*/
u2_noun
u2_sync_load(c3_c* pas_c)
{
  struct stat buf_b;
  c3_i        fid_i = open(pas_c, O_RDONLY, 0644);
  c3_w        fln_w, red_w;
  c3_y*       pad_y;

  if ( (fid_i < 0) || (fstat(fid_i, &buf_b) < 0) ) {
    perror(pas_c);
    return u2_cm_bail(c3__fail);
  }
  fln_w = buf_b.st_size;
  pad_y = malloc(buf_b.st_size);

  red_w = read(fid_i, pad_y, fln_w);
  close(fid_i);

  if ( fln_w != red_w ) {
    free(pad_y);
    return u2_cm_bail(c3__fail);
  }
  else {
    u2_noun pad = u2_ci_bytes(fln_w, (c3_y *)pad_y); 
    free(pad_y);

    return pad;
  }
}

/* u2_sync_save(): save file or bail.
*/
void
u2_sync_save(c3_c* pas_c, u2_noun tim, u2_atom pad)
{
  c3_i  fid_i = open(pas_c, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  c3_w  fln_w, rit_w;
  c3_y* pad_y;

  if ( fid_i < 0 ) {
    perror(pas_c);
    u2_cm_bail(c3__fail);
  }

  fln_w = u2_met(3, pad);
  pad_y = malloc(fln_w);
  u2_cr_bytes(0, fln_w, pad_y, pad);
  u2z(pad);

  rit_w = write(fid_i, pad_y, fln_w);
  close(fid_i);
  free(pad_y);

  if ( rit_w != fln_w ) {
    perror(pas_c);
    u2_cm_bail(c3__fail);
  }

  {
    struct timeval tim_tv[2];

    u2_time_out_tv(&tim_tv[0], u2k(tim));
    u2_time_out_tv(&tim_tv[1], tim);
 
    utimes(pas_c, tim_tv);
  }
}

/* _walk_in(): inner loop of _walk().
*/
static u2_noun
_walk_in(const c3_c* dir_c, c3_w len_w)
{
  DIR*    dir_d = opendir(dir_c);
  u2_noun map = u2_nul;

  if ( !dir_d ) {
    return u2_nul;
  }
  else while ( 1 ) {
    struct dirent  ent_n;
    struct dirent* out_n;

    if ( readdir_r(dir_d, &ent_n, &out_n) != 0 ) {
      perror(dir_c);
      break;
    } 
    else if ( !out_n ) {
      break;
    }
    else if ( !strcmp(out_n->d_name, ".") || !strcmp(out_n->d_name, "..") ) {
      continue;
    }
    else {
      c3_c* fil_c = out_n->d_name;
      c3_w  lef_w = len_w + 1 + strlen(fil_c);
      c3_c* pat_c = malloc(lef_w + 1);
      c3_c* dot_c;
   
      strcpy(pat_c, dir_c);
      pat_c[len_w] = '/';
      strcpy(pat_c + len_w + 1, fil_c);

      if ( (dot_c = strrchr(fil_c, '.')) ) {
        /*  all files must have extensions
        */
        c3_c*       nam_c = strdup(fil_c);
        c3_c*       ext_c = strdup(dot_c + 1);
        struct stat buf_b;

        nam_c[dot_c - fil_c] = 0;

        if ( 0 == stat(pat_c, &buf_b) ) {
          u2_noun tim = u2_time_in_ts(&buf_b.st_mtimespec);
          u2_noun nam = u2_ci_string(nam_c);
          u2_noun ext = u2_ci_string(ext_c);
          u2_noun get = u2_ckd_by_get(u2k(map), u2k(nam));

          if ( u2_none == get ) { get = u2_nul; }
         
          get = u2_ckd_by_put(get, ext, u2nc(u2_yes, tim));
          map = u2_ckd_by_put(map, nam, u2nc(u2_no, get));
        }
        free(nam_c);
        free(ext_c);
      }
      else {
        /*  all nonfiles are directories
        */
        u2_noun dir = _walk_in(pat_c, lef_w);

        if ( u2_nul != dir ) {
          map = u2_ckd_by_put(map, u2_ci_string(fil_c), u2nc(u2_no, dir));
        }
      }
      free(pat_c);
    }
  }
  return map;
}

/* _walk(): traverse `dir_c` to produce a node.
*/
static u2_noun
_walk(const c3_c* dir_c)
{
  return u2nc(u2_no, _walk_in(dir_c, strlen(dir_c)));
}

/* _sync_peek_meta(): (unit meta) for cary-path.
*/
static u2_noun
_sync_peek_meta(u2_reck* rec_u, u2_noun pos, u2_noun bok, u2_noun ram)
{
  u2_noun mar = u2_ckb_flop(ram);

  return u2_reck_peek
    (rec_u, u2nq(c3__cary, pos, bok, u2nt(u2k(rec_u->wen), 'm', mar)));
}

/* _sync_unix(): unix path as by dir/file.ext or dir/subdir protocol.
*/
static c3_c*
_sync_unix(u2_flag dir, u2_noun hac)
{
  c3_w len_w;
  c3_c *pas_c;

  //  measure
  //
  len_w = strlen(u2_Local) + 4;
  {
    u2_noun wiz = hac;

    while ( u2_nul != wiz ) {
      len_w += (1 + u2_cr_met(3, u2h(wiz)));
      wiz = u2t(wiz);
    }
  }

  //  cut
  //
  pas_c = malloc(len_w + 1);
  strcpy(pas_c, u2_Local);
  strcat(pas_c, "/car");
  {
    u2_noun wiz   = hac;
    c3_c*   waq_c = (pas_c + strlen(pas_c));

    while ( u2_nul != wiz ) {
      c3_w tis_w = u2_cr_met(3, u2h(wiz));

      if ( (u2_no == dir) && (u2_nul == u2t(wiz)) ) {
        *waq_c++ = '.';
      } else *waq_c++ = '/';

      u2_cr_bytes(0, tis_w, (c3_y*)waq_c, u2h(wiz));
      waq_c += tis_w;

      wiz = u2t(wiz);
    }
    *waq_c = 0;
  }
  u2z(hac);
  return pas_c;
}

/* _sync_norm_e(): construct editing path as noun.
*/
static u2_noun
_sync_norm_e(u2_noun pos, u2_noun bok, u2_noun ram)
{
  return u2nq(pos, bok, 'e', u2_ckb_flop(ram));
}

/* _sync_unix_data(): editing data from path.
*/
static u2_noun
_sync_unix_data(u2_noun pos, u2_noun bok, u2_noun ram)
{
  u2_noun hac   = _sync_norm_e(pos, bok, ram);
  c3_c*   pax_c = _sync_unix(u2_no, hac);
  u2_noun dat   = u2_sync_load(pax_c);

  free(pax_c);
  return dat;
}

static u2_noun
_sync_give(u2_reck*, u2_noun, u2_noun, u2_noun, u2_noun, u2_noun);

static u2_noun
_sync_give_m(u2_reck* rec_u, 
             u2_noun pos, 
             u2_noun bok, 
             u2_noun ram, 
             u2_noun map,
             u2_noun muv)
{
  if ( u2_nul == map ) {
    u2z(pos); u2z(bok); u2z(ram);
    return muv;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    muv = _sync_give_m(rec_u, u2k(pos), u2k(bok), u2k(ram), u2k(l_map), muv);
    muv = _sync_give_m(rec_u, u2k(pos), u2k(bok), u2k(ram), u2k(r_map), muv);
    muv = _sync_give(rec_u, pos, bok, u2nc(u2k(pn_map), ram), u2k(qn_map), muv);

    u2z(map);
    return muv;
  }
}

/* _sync_give(): pure checkin (memory data does not exist).
*/
static u2_noun
_sync_give(u2_reck* rec_u, 
           u2_noun pos, 
           u2_noun bok, 
           u2_noun ram, 
           u2_noun nod,
           u2_noun muv)
{
  if ( u2_yes == u2h(nod) ) {
    u2_noun pad = _sync_unix_data(pos, bok, u2k(ram));

    muv = u2nc(u2nt(c3_s2('g','v'), u2_ckb_flop(ram), pad), muv);
  } 
  else {
    muv = _sync_give_m(rec_u, pos, bok, ram, u2k(u2t(nod)), muv);
  }
  u2z(nod);
  return muv;
}

/* _sync_edit(): sync in editable directory.
*/
static u2_noun
_sync_edit(u2_reck* rec_u, 
           u2_noun  pos,              //  post
           u2_noun  bok,              //  book
           u2_noun  ram,              //  reverse path in book
           u2_noun  nod,              //  stat node from _walk_in()
           u2_noun  muv)              //  change list
{
  u2_noun mey = _sync_peek_meta(rec_u, u2k(pos), u2k(bok), u2k(ram));
  u2_noun end;

  if ( u2_nul == mey ) {
    return _sync_give(rec_u, pos, bok, ram, nod, muv);
  } else {
    u2_noun yem = u2k(u2t(mey));

    u2z(mey); mey = yem;
  }

  //  dir/file must match, please don't fsck this up for now
  {
    if ( u2h(nod) != u2h(mey) ) {
      //  XX  proper error reporting
      printf("yo, sync mismatch\n");
      goto done;
    }
    else end = u2h(nod);
  }

  if ( u2_yes == end ) {
    if ( u2_yes == u2_sing(u2t(nod), u2t(mey)) ) {
      goto done;
    }
    else if ( u2_yes == u2_cka_lte(u2k(u2t(mey)), u2k(u2t(nod))) ) {
      u2_noun pad = _sync_unix_data(u2k(pos), u2k(bok), u2k(ram));

      u2_err(u2_Wire, "mey", u2t(mey));
      u2_err(u2_Wire, "nod", u2t(nod));

      muv = u2nc(u2nt(c3_s2('g','v'), u2_ckb_flop(u2k(ram)), pad), muv);
    }
    else {
      printf("yo, reverse update\n");

      u2_err(u2_Wire, "mey time", u2t(mey));
      u2_err(u2_Wire, "nod time", u2t(nod));

      goto done;
    }
  }
  else {
    u2_noun n, yip, wam;

    //  we are only interested in the span list & map
    {
      u2_noun sil = u2k(u2t(u2t(mey)));
      u2_noun dun = u2k(u2t(nod));

      u2z(mey); u2z(nod);
      mey = sil;
      nod = dun;
    }

    //  we also be wanting a map - and a unix list
    // 
    yip = u2_ckd_in_tap(u2k(nod), u2_nul);
    wam = u2_ckd_in_gas(u2_nul, u2k(mey));

    //  yip == (list ,[span node]) of unix files
    //  nod == map of unix files
    //  wam == set of cary files
    //  mey == (list span) of cary files

    printf("iterating at %s\n", 
          _sync_unix(u2_yes, _sync_norm_e(u2k(pos), u2k(bok), u2k(ram))));
    u2_err(u2_Wire, "mey", mey);

    //  iterate by unix files
    //
    for ( n=yip; u2_nul != n; n=u2t(n) ) {
      u2_noun i = u2h(n);   //  [span node]

      if ( u2_no == u2_ckd_in_has(u2k(wam), u2k(u2h(i))) ) {
        muv = _sync_give
          (rec_u, u2k(pos), 
                  u2k(bok),
                  u2nc(u2k(u2h(i)), u2k(ram)), 
                  u2k(u2t(i)),
                  muv);
      } else {
        muv = _sync_edit
          (rec_u, u2k(pos), 
                  u2k(bok),
                  u2nc(u2k(u2h(i)), u2k(ram)), 
                  u2k(u2t(i)),
                  muv);
      }
    }

    //  iterate by cary files - should not be needed (but is).
    //
#if 0
    for ( n=mey; u2_nul != n; n=u2t(n) ) {
      u2_noun i = u2h(n);

      if ( u2_no == u2_ckd_in_has(u2k(nod), u2k(i)) ) {
        printf("%s is missing!\n", 
              _sync_dire(u2_no, u2_ckb_flop(u2nc(u2k(i), u2k(rah)))));

        _sync_take(rec_u, u2_no, u2nc(u2k(i), u2k(rah)));
      }
    }
#endif
    u2z(yip);
    u2z(wam);
  }

done:
  u2z(pos); u2z(bok); u2z(ram); u2z(nod); u2z(mey);
  return muv;
}

/* _sync_edit_m():
*/
static u2_noun
_sync_edit_m(u2_reck* rec_u, u2_noun pos, u2_noun bok, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(pos); u2z(bok);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;
    u2_noun muv;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    if ( ('e' != pn_map) ) {
      u2z(map); u2z(pos); u2z(bok);

      return det;
    }
    det = _sync_edit_m(rec_u, u2k(pos), u2k(bok), u2k(l_map), det);
    det = _sync_edit_m(rec_u, u2k(pos), u2k(bok), u2k(r_map), det);
  
    muv = _sync_edit(rec_u, u2k(pos), u2k(bok), u2_nul, u2k(qn_map), u2_nul);
    u2z(map);

    if ( u2_nul == muv ) {
      u2z(pos); u2z(bok);
    } 
    else {
      det = u2nc
        (u2nt(c3_s2('p', 'i'),
              u2nt(pos, bok, u2_nul),
              muv),
         det);
    }
    return det;
  }
}

/* _sync_book(): sync `nod` as a project change to `pos`, `bok`.
*/
static u2_noun
_sync_book(u2_reck* rec_u, u2_noun pos, u2_noun bok, u2_noun nod, u2_noun det)
{
  if ( u2_yes == u2h(nod) ) {
    //  XX  user error
    u2z(nod); u2z(bok); u2z(pos);
    return det;
  }
  else {
    det = _sync_edit_m(rec_u, pos, bok, u2k(u2t(nod)), det);
    u2z(nod);

    return det;
  }
}

/* _sync_book_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_book_m(u2_reck* rec_u, u2_noun pos, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(pos);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    det = _sync_book_m(rec_u, u2k(pos), u2k(l_map), det);
    det = _sync_book_m(rec_u, u2k(pos), u2k(r_map), det);
    det = _sync_book(rec_u, pos, u2k(pn_map), u2k(qn_map), det);

    u2z(map);
    return det;
  }
}

/* _sync_post(): sync `nod` as a base change.
*/
static u2_noun
_sync_post(u2_reck* rec_u, u2_noun pos, u2_noun nod, u2_noun det)
{
  if ( (u2_nul == nod) || (u2_yes == u2h(nod)) ) {
    u2z(pos);
    u2z(nod);
    return det;
  }
  else {
    det = _sync_book_m(rec_u, pos, u2k(u2t(nod)), det);
    u2z(nod);
    return det;
  }
}

/* _sync_post_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_post_m(u2_reck* rec_u, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cx_trel(map, &n_map, &l_map, &r_map);
    u2_cx_cell(n_map, &pn_map, &qn_map);

    det = _sync_post(rec_u, u2k(pn_map), u2k(qn_map), det);
    det = _sync_post_m(rec_u, u2k(l_map), det);
    det = _sync_post_m(rec_u, u2k(r_map), det);

    u2z(map);
    return det;
  }
}

/* u2_sync_reck(): traverse filesystem to commit changes -> lamb
*/
u2_noun
u2_sync_reck(u2_reck* rec_u)
{
  c3_c*   pas_c = malloc(strlen(u2_Local) + 1 + 3 + 1);
  u2_noun nod; 

  strcpy(pas_c, u2_Local);
  strcat(pas_c, "/car");
 
  nod = _walk(pas_c);
  free(pas_c);

  if ( (u2_nul == nod) || (u2_yes == u2h(nod)) ) {
    u2z(nod);
    return u2_nul;
  }
  else {
    u2_noun det = u2_nul;
    u2_noun map = u2t(nod);
    
    det = _sync_post_m(rec_u, u2k(map), det);
    u2z(nod);

    {
      u2_noun dut = det;
      u2_noun lam = u2_nul;

      while ( u2_nul != dut ) {
        lam = u2nc(u2nc(c3__cary, u2k(u2h(dut))), lam);
        dut = u2t(dut);
      }
      u2z(det);

      return u2nc('o', lam);
    }
  }
}
