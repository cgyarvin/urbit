/* v/reck.c
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

/* _sync_path(): cary path from raw path.
*/
static u2_noun
_sync_path(u2_reck* rec_u, u2_flag rey, c3_c how_c, u2_noun hap)
{
  u2_noun baz, bok, ven, lim;
  u2_noun cay;

  if ( u2_yes == rey ) {
    u2_cx_qual(hap, &baz, &bok, &ven, &lim);
    u2k(baz); u2k(bok); u2k(ven); u2k(lim);
  } else {
    u2_cx_trel(hap, &baz, &bok, &lim);
    u2k(baz); u2k(bok); u2k(lim);
    ven = u2k(rec_u->wen);
  }

  cay = u2nq(c3__cary, baz, bok, u2nt(ven, how_c, lim));
  u2z(hap);
  return cay;
}

/* _sync_peek_meta(): (unit meta) for cary-path.
*/
static u2_noun
_sync_peek_meta(u2_reck* rec_u, u2_flag rey, u2_noun hac)
{
  u2_noun pah = _sync_path(rec_u, rey, 'm', hac);

  return u2_reck_peek(rec_u, pah);
}

/* _sync_peek_data(): (unit @) for cary-path.
*/
static u2_noun
_sync_peek_data(u2_reck* rec_u, u2_flag rey, u2_noun hac)
{
  return u2_reck_peek(rec_u, _sync_path(rec_u, rey, 'd', hac));
}

/* _sync_unix(): unix path as by dir/file.ext or dir/subdir protocol.
*/
static c3_c*
_sync_unix(u2_flag dir, u2_flag rey, u2_noun hac)
{
  u2_noun baz, bok, rev, lim;
  c3_w len_w;
  c3_c *pas_c;

  //  normalize
  {
    u2_noun nor;

    if ( u2_no == rey ) {
      u2_cx_trel(hac, &baz, &bok, &lim);
      nor = u2nq(u2k(baz), u2k(bok), 'e', u2k(lim));
    } else {
      u2_cx_qual(hac, &baz, &bok, &rev, &lim);
      nor = u2nq(u2k(baz), u2k(bok), 'r', u2nc(u2k(rev), u2k(lim)));
    }
    u2z(hac);
    hac = nor;
  }

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

/* _sync_file(): from path to C file.ext style path.
*/
static c3_c*
_sync_file(u2_flag rey, u2_noun hac)
{
  return _sync_unix(u2_no, rey, hac);
}

/* _sync_dire(): from path to C directory style path.
*/
static c3_c*
_sync_dire(u2_flag rey, u2_noun hac)
{
  return _sync_unix(u2_yes, rey, hac);
}

/* _sync_flat(): load unix file (or crash) from cary path.
*/
static u2_noun
_sync_flat(u2_flag rey, u2_noun hac)
{
  c3_c*   pas_c = _sync_file(rey, hac);
  u2_noun pad   = u2_sync_load(pas_c);

  free(pas_c);
  return pad;
}

/* _sync_make(): make sure directory is there.
*/
static void
_sync_make(u2_flag rey, u2_noun hac)
{
  c3_c* pas_c = _sync_file(rey, hac);

  mkdir(pas_c, 0777);
  free(pas_c);
}

/* _sync_push(): save unix file (or crash) from cary path, setting time.
*/
static void
_sync_push(u2_flag rey, u2_noun hac, u2_atom tim, u2_noun pad)
{
  c3_c* pas_c = _sync_file(rey, hac);

  u2_sync_save(pas_c, tim, pad);
  free(pas_c);
}

/* _sync_lose(): delete unix file.
*/
static void
_sync_lose(u2_flag rey, u2_noun hac)
{
  c3_c* pas_c = _sync_file(rey, hac);

  unlink(pas_c);
  free(pas_c);
}

/* _sync_give_m(): _sync_give() in map.
*/
static u2_noun _sync_give(u2_reck*, u2_noun, u2_noun, u2_noun);

static u2_noun
_sync_give_m(u2_reck* rec_u, u2_noun rah, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(rah);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    det = _sync_give_m(rec_u, u2k(rah), u2k(l_map), det);
    det = _sync_give_m(rec_u, u2k(rah), u2k(r_map), det);
    det = _sync_give(rec_u, u2nc(u2k(pn_map), rah), u2k(qn_map), det);

    u2z(map);
    return det;
  }
}

/* _sync_give(): pure checkin (memory data does not exist).
*/
static u2_noun
_sync_give(u2_reck* rec_u, u2_noun rah, u2_noun nod, u2_noun det)
{
  if ( u2_yes == u2h(nod) ) {
    u2_noun hac = u2_ckb_flop(rah);
    u2_noun pad = _sync_flat(u2_no, u2k(hac));

    det = u2nc(u2nc(c3_s2('p','i'),
                    u2nt(hac, c3_s2('g', 'v'), pad)),
               det);
    u2z(nod);
    return det;
  }
  else {
    u2_noun map = u2k(u2t(nod));

    det = _sync_give_m(rec_u, rah, map, det);
    u2z(nod);
    return det;
  }
}

/* _sync_take(): pure checkout (fs data does not exist).
*/
static void
_sync_take(u2_reck* rec_u, u2_noun rey, u2_noun rah)
{
  u2_noun hac = u2_ckb_flop(rah);
  u2_noun mey = _sync_peek_meta(rec_u, u2_no, u2k(hac));

  if ( u2_nul == mey ) {
    u2_cm_bail(c3__fail);
  } else {
    u2_noun yem = u2k(u2t(mey));

    u2z(mey); mey = yem;
  }

  if ( u2_yes == u2h(mey) ) {
    u2_noun tim = u2k(u2t(mey));
    u2_noun pad   = _sync_peek_data(rec_u, rey, u2k(hac));

    _sync_push(rey, hac, tim, pad);
  } 
  else {
    u2_noun hac = u2_ckb_flop(u2k(rah));
    u2_noun n;

    _sync_make(rey, hac);

    for ( n=u2t(mey); u2_nul != n; n=u2t(n) ) {
      u2_noun i = u2h(n);   //  span

      _sync_take(rec_u, rey, u2nc(u2k(i), u2k(rah)));
    }
    u2z(rah);
  }
}

/* _sync_live(): sync in editable directory.
*/
static u2_noun
_sync_live(u2_reck* rec_u, u2_noun rah, u2_noun nod, u2_noun det)
{
  u2_noun hac = u2_ckb_flop(u2k(rah));
  u2_noun mey = _sync_peek_meta(rec_u, u2_no, u2k(hac));
  u2_flag end;

  //  simpler path for pure checkin
  {
    if ( u2_nul == mey ) {
      u2z(hac);
      return _sync_give(rec_u, rah, nod, det);
    }
    else {
      u2_noun yem = u2k(u2t(mey));

      u2z(mey); mey = yem;
    }
  }

  //  dir/file must match, please don't fsck this up for now
  {
    if ( u2h(nod) != u2h(mey) ) {
      //  XX  error
      printf("yo, sync mismatch\n");
      u2z(rah); u2z(hac); u2z(mey);
      return det;
    }
    else end = u2h(nod);
  }

  if ( u2_yes == end ) {
    c3_d nod_d = u2_cr_chub(0, u2t(nod));
    c3_d mey_d = u2_cr_chub(0, u2t(mey));
    
    if ( nod_d == mey_d ) {                             //  already in sync
      u2z(hac);
    }
    else if ( nod_d > mey_d ) {                         //  unix file is newer
      u2_noun pad = _sync_flat(u2_no, u2k(hac));

      det = u2nc(u2nc(c3_s2('p','o'),
                      u2nt(hac, c3_s2('g', 'v'), pad)),
                 det);
    }
    else {                                              //   cary is newer
      u2_noun pad = _sync_peek_data(rec_u, u2_no, u2k(hac));
        
      if ( u2_nul == pad ) {
        printf("%s missing & obsolete!\n", _sync_file(u2_no, u2k(hac))); 
      } else {
        printf("%s is obsolete!\n", _sync_file(u2_no, u2k(hac)));

        _sync_push(u2_no, u2k(hac), mey_d, u2k(u2t(pad)));
        u2z(pad);
      }
      u2z(hac);
    }
  }
  else {
    u2_noun n, yip, wam;

    //  we are only interested in the span list & map
    {
      u2_noun sil = u2k(u2t(u2t(mey)));
      u2_noun dun = u2k(u2t(nod));

      u2z(mey); u2k(nod);
      mey = sil;
      nod = dun;
    }

    //  we also be wanting a map - and a unix list
    // 
    yip = u2_ckd_in_tap(u2k(u2t(nod)), u2_nul);
    wam = u2_ckd_in_gas(u2k(mey), u2_nul);

    //  yip == (list ,[span node]) of unix files
    //  nod == map of unix files
    //  wam == set of cary files
    //  mey == (list span) of cary files

    //  iterate by unix files
    //
    for ( n=yip; u2_nul != n; n=u2t(n) ) {
      u2_noun i = u2h(n);   //  [span node]

      if ( u2_no == u2_ckd_in_has(u2k(wam), u2k(u2h(i))) ) {
        det = _sync_give
          (rec_u, u2nc(u2k(u2h(i)), u2k(rah)), u2k(u2t(i)), det);
      } else {
        det = _sync_live
          (rec_u, u2nc(u2k(u2h(i)), u2k(rah)), u2k(u2t(i)), det);
      }
    }

    //  iterate by cary files - should not be needed (but is).
    //
    for ( n=mey; u2_nul != n; n=u2t(n) ) {
      u2_noun i = u2h(n);

      if ( u2_no == u2_ckd_in_has(u2k(nod), u2k(i)) ) {
        printf("%s is missing!\n", 
              _sync_dire(u2_no, u2_ckb_flop(u2nc(u2k(i), u2k(rah)))));

        _sync_take(rec_u, u2_no, u2nc(u2k(i), u2k(rah)));
      }
    }
    u2z(yip);
    u2z(wam);
  }
  u2z(rah); u2z(hac); u2z(mey);
  return det;
}

/* _sync_form_m():
*/
static u2_noun
_sync_form_m(u2_reck* rec_u, u2_noun baz, u2_noun bok, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(baz); u2z(bok);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;
    u2_noun rah;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    if ( ('e' != pn_map) ) {
      u2z(map); u2z(baz); u2z(bok);

      return det;               //  XX version checkout not yet supported
    }
   
    rah = u2nt(bok, baz, u2_nul);

    det = _sync_form_m(rec_u, u2k(baz), u2k(bok), u2k(l_map), det);
    det = _sync_form_m(rec_u, u2k(baz), u2k(bok), u2k(r_map), det);
    det = _sync_live(rec_u, rah, u2k(qn_map), det);

    u2z(map);
    return det;
  }
}

/* _sync_book(): sync `nod` as a project change to `baz`, `bok`.
*/
static u2_noun
_sync_book(u2_reck* rec_u, u2_noun baz, u2_noun bok, u2_noun nod, u2_noun det)
{
  if ( u2_yes == u2h(nod) ) {
    //  XX  user error
    u2z(nod); u2z(bok); u2z(baz);
    return det;
  }
  else {
    det = _sync_form_m(rec_u, baz, bok, u2k(u2t(nod)), det);
    u2z(nod);

    return det;
  }
}

/* _sync_book_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_book_m(u2_reck* rec_u, u2_noun baz, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    u2z(baz);
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cr_trel(map, &n_map, &l_map, &r_map);
    u2_cr_cell(n_map, &pn_map, &qn_map);

    det = _sync_book_m(rec_u, u2k(baz), u2k(l_map), det);
    det = _sync_book_m(rec_u, u2k(baz), u2k(r_map), det);
    det = _sync_book(rec_u, baz, u2k(pn_map), u2k(qn_map), det);

    u2z(map);
    return det;
  }
}

/* _sync_base(): sync `nod` as a base change.
*/
static u2_noun
_sync_base(u2_reck* rec_u, u2_noun baz, u2_noun nod, u2_noun det)
{
  if ( (u2_nul == nod) || (u2_yes == u2h(nod)) ) {
    u2z(baz);
    u2z(nod);
    return det;
  }
  else {
    det = _sync_book_m(rec_u, baz, u2k(u2t(nod)), det);
    u2z(nod);
    return det;
  }
}

/* _sync_base_m(): sync `map` to a change list `det`.
*/
static u2_noun
_sync_base_m(u2_reck* rec_u, u2_noun map, u2_noun det)
{
  if ( u2_nul == map ) {
    return det;
  }
  else {
    u2_noun n_map, pn_map, qn_map, l_map, r_map;

    u2_cx_trel(map, &n_map, &l_map, &r_map);
    u2_cx_cell(n_map, &pn_map, &qn_map);

    det = _sync_base(rec_u, u2k(pn_map), u2k(qn_map), det);
    det = _sync_base_m(rec_u, u2k(l_map), det);
    det = _sync_base_m(rec_u, u2k(r_map), det);

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
    
    det = _sync_base_m(rec_u, u2k(map), det);
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
