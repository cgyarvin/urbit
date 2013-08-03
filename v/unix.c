/* v/unix.c
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
#include <curses.h>
#include <termios.h>
#include <term.h>
#include <errno.h>

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

#define u2R  ((u2_reck *) &u2_Host.arv_u)     //  new school

static void _lo_unix(struct ev_loop *lup_u, struct ev_timer* tim_u, c3_i rev_i)
  { u2_lo_call(u2_Host.arv_u, lup_u, tim_u, c3__unix, rev_i); }

static void _lo_sign(struct ev_loop *lup_u, struct ev_signal* sil_u, c3_i rev_i)
  { u2_lo_call(u2_Host.arv_u, lup_u, sil_u, c3__unix, rev_i); }

static void _lo_stat(struct ev_loop *lup_u, struct ev_stat* sat_u, c3_i rev_i)
  { u2_lo_call(u2_Host.arv_u, lup_u, sat_u, c3__unix, rev_i); }

/* _unix_down(): descend path.
*/
static c3_c*
_unix_down(c3_c* pax_c, c3_c* sub_c)
{
  c3_w pax_w = strlen(pax_c);
  c3_c* don_c = malloc(pax_w + strlen(sub_c) + 2);

  strcpy(don_c, pax_c);
  don_c[pax_w] = '/';
  strcpy(don_c + pax_w + 1, sub_c);

  return don_c;
}

/* _unix_opendir(): opendir, asserting.
*/
static DIR*
_unix_opendir(c3_c* pax_c)
{
  DIR* rid_u = opendir(pax_c);

  if ( !rid_u ) {
    uL(fprintf(uH, "%s: %s\n", pax_c, strerror(errno)));
    c3_assert(0);
  }
  return rid_u;
}

/* _unix_mtime(): mtime from path.
*/
static void
_unix_mtime(c3_c* pax_c, mpz_t mod_mp) 
{
  struct stat buf_u;

  if ( 0 != stat(pax_c, &buf_u) ) {
    free(pax_c);
  } else {
    u2_noun mod = c3_stat_mtime(&buf_u);

    u2_cr_mp(mod_mp, mod);
    u2z(mod);
  }
}

/* _unix_file_watch(): create file tracker.
*/
static void
_unix_file_watch(u2_reck* rec_u, 
                 u2_ufil* fil_u, 
                 u2_udir* dir_u, 
                 c3_c*    pax_c,
                 mpz_t    mod_mp)
{
  ev_stat_init(&fil_u->was_u, _lo_stat, pax_c, 1.0);

  fil_u->non = u2_no;
  fil_u->dry = u2_no;
  fil_u->pax_c = pax_c;
  {
    c3_c* dot_c = strrchr(pax_c, '.');
    c3_c* fas_c = strrchr(pax_c, '/');

    fil_u->dot_c = dot_c ? (fas_c ? ((dot_c > fas_c) ? dot_c : 0)
                                  : dot_c)
                         : 0;
  }
  fil_u->par_u = dir_u;
  mpz_init_set(fil_u->mod_mp, mod_mp);
  fil_u->nex_u = 0;
}

/* _unix_dir_watch(): create directory tracker.
*/
static void
_unix_dir_watch(u2_reck* rec_u, u2_udir* dir_u, u2_udir* par_u, c3_c* pax_c)
{
  ev_stat_init(&dir_u->was_u, _lo_stat, pax_c, 1.0);

  dir_u->yes = u2_yes;
  dir_u->dry = u2_no;
  dir_u->pax_c = pax_c;
  dir_u->par_u = par_u;
  dir_u->dis_u = 0;
  dir_u->fil_u = 0;
  dir_u->nex_u = 0;
}

/* _unix_file_free(): free (within) file tracker.
*/
static void
_unix_file_free(u2_reck* rec_u, u2_ufil* fil_u)
{
  free(fil_u->pax_c);
  mpz_clear(fil_u->mod_mp);
}

/* _unix_dir_free(): free (within) directory tracker.
*/
static void
_unix_dir_free(u2_reck* rec_u, u2_udir* dir_u)
{
  free(dir_u->pax_c);

  while ( dir_u->dis_u ) {
    u2_udir* nex_u = dir_u->dis_u->nex_u;

    _unix_dir_free(rec_u, dir_u->dis_u);
    free(dir_u->dis_u);
    dir_u->dis_u = nex_u;
  }
  while ( dir_u->fil_u ) {
    u2_ufil* nex_u = dir_u->fil_u->nex_u;

    _unix_file_free(rec_u, dir_u->fil_u);
    free(dir_u->fil_u);
    dir_u->fil_u = nex_u;
  }
}

/* _unix_file_update(): update file, true if plausibly changed.
*/
static u2_bean
_unix_file_update(u2_reck* rec_u, u2_ufil* fil_u, mpz_t mod_mp)
{
  if ( 0 == mpz_cmp(mod_mp, fil_u->mod_mp) ) {
    return u2_no;
  } else {
    mpz_clear(fil_u->mod_mp);
    mpz_init_set(fil_u->mod_mp, mod_mp);

    return u2_yes;
  }
}

/* _unix_dir_update(): update directory, true if changed.
*/
static u2_bean
_unix_dir_update(u2_reck* rec_u, u2_udir* dir_u, DIR* rid_u)
{
  u2_bean cha = u2_no;

  // uL(fprintf(uH, "dir_update ON %s\n", dir_u->pax_c));
  /* use dry bits as markers
  */
  {
    u2_udir* dis_u;
    u2_ufil* fil_u;

    for ( dis_u = dir_u->dis_u; dis_u; dis_u = dis_u->nex_u ) {
      dis_u->dry = u2_yes;
    }
    for ( fil_u = dir_u->fil_u; fil_u; fil_u = fil_u->nex_u ) {
      fil_u->dry = u2_yes;
    }
  }

  /* iterate through directory, opening and updating
  */
  while ( 1 ) {
    struct dirent  ent_u;
    struct dirent* out_u;

    if ( readdir_r(rid_u, &ent_u, &out_u) != 0 ) {
      uL(fprintf(uH, "%s: %s\n", dir_u->pax_c, strerror(errno)));
      c3_assert(0);
    } 
    else if ( !out_u ) {
      break;
    }
    else if ( ('.' == out_u->d_name[0]) ) {    //  XX screws up some paths
      continue;
    }
    else {
      c3_c* pax_c = _unix_down(dir_u->pax_c, out_u->d_name);
      struct stat buf_u;
  
      // uL(fprintf(uH, "  in %s\n", pax_c));
      if ( 0 != stat(pax_c, &buf_u) ) {
        free(pax_c);
        continue;
      } 
      else {
        if ( !S_ISDIR(buf_u.st_mode) ) {
          mpz_t    mod_mp;
          u2_ufil* fil_u;

          {
            u2_noun mod = c3_stat_mtime(&buf_u);

            u2_cr_mp(mod_mp, mod);
            u2z(mod);
          }
          for ( fil_u = dir_u->fil_u; fil_u; fil_u = fil_u->nex_u ) {
            if ( !strcmp(pax_c, fil_u->pax_c) ) {
              fil_u->dry = u2_no;
              cha = u2_or(cha, _unix_file_update(rec_u, fil_u, mod_mp));
              break;
            }
          }
          if ( !fil_u ) {
            fil_u = malloc(sizeof(u2_ufil));
            // uL(fprintf(uH, "found file %s\n", pax_c));
            _unix_file_watch(rec_u, fil_u, dir_u, pax_c, mod_mp);

            fil_u->nex_u = dir_u->fil_u;
            dir_u->fil_u = fil_u;
            cha = u2_yes;
          }
          mpz_clear(mod_mp);
        }
        else {
          DIR* red_u = _unix_opendir(pax_c);
          u2_udir* dis_u;

          for ( dis_u = dir_u->dis_u; dis_u; dis_u = dis_u->nex_u ) {
            if ( !strcmp(pax_c, dis_u->pax_c) ) {
              dis_u->dry = u2_no;
              cha = u2_or(cha, _unix_dir_update(rec_u, dis_u, red_u));
              break;
            }
          }
          if ( !dis_u ) {
            dis_u = malloc(sizeof(u2_udir));
            // uL(fprintf(uH, "found directory %s\n", pax_c));
            _unix_dir_watch(rec_u, dis_u, dir_u, pax_c); 
            _unix_dir_update(rec_u, dis_u, red_u);

            dis_u->nex_u = dir_u->dis_u;
            dir_u->dis_u = dis_u;
            cha = u2_yes;
          }
        }
      }
    }
  }

  /* use dry bits as markers
  */
  {
    u2_udir** dis_u;
    u2_ufil** fil_u;

    for ( dis_u = &(dir_u->dis_u); *dis_u; ) {
      if ( u2_no == (*dis_u)->dry ) {
        (*dis_u)->dry = u2_yes;
        dis_u = &(*dis_u)->nex_u;
      }
      else {
        u2_udir* ded_u = *dis_u;
        u2_udir* nex_u = ded_u->nex_u;

        // uL(fprintf(uH, "removed directory %s\n", ded_u->pax_c));
        _unix_dir_free(rec_u, ded_u);
        free(ded_u);

        *dis_u = nex_u;
        cha = u2_yes;
      }
    }

    for ( fil_u = &(dir_u->fil_u); *fil_u; ) {
      if ( u2_no == (*fil_u)->dry ) {
        fil_u = &(*fil_u)->nex_u;
      }
      else {
        u2_ufil* ded_u = *fil_u;
        u2_ufil* nex_u = ded_u->nex_u;

        // uL(fprintf(uH, "removed file %s\n", ded_u->pax_c));
        _unix_file_free(rec_u, ded_u);
        free(ded_u);

        *fil_u = nex_u;
        cha = u2_yes;
      }
    }
  }
  closedir(rid_u);
  // uL(fprintf(uH, "dir_update OFF %s\n", dir_u->pax_c));
  return cha;
}

/* unix_load_safe(): load file or 0.
*/
static u2_noun
_unix_load_safe(c3_c* pax_c)
{
  struct stat buf_u;
  c3_i        fid_i = open(pax_c, O_RDONLY, 0644);
  c3_w        fln_w, red_w;
  c3_y*       pad_y;

  if ( (fid_i < 0) || (fstat(fid_i, &buf_u) < 0) ) {
    // uL(fprintf(uH, "%s: %s\n", pax_c, strerror(errno)));
    return 0;
  }
  fln_w = buf_u.st_size;
  pad_y = malloc(buf_u.st_size);

  red_w = read(fid_i, pad_y, fln_w);
  close(fid_i);

  if ( fln_w != red_w ) {
    free(pad_y);
    return 0;
  }
  else {
    u2_noun pad = u2_ci_bytes(fln_w, (c3_y *)pad_y); 
    free(pad_y);

    return pad;
  }
}

/* _unix_file_load(): load a file.
*/
static u2_noun
_unix_file_load(u2_reck* rec_u, u2_ufil* fil_u)
{
  u2_noun raw = _unix_load_safe(fil_u->pax_c);

  if ( (0 == raw) || ('^' != fil_u->dot_c[1]) ) {
    return raw;
  }
  else return u2_cke_cue(raw);
}

/* _unix_dir_name(): directory name.
*/
static u2_noun
_unix_dir_name(u2_reck* rec_u, u2_udir* dir_u)
{
  c3_w pel_w = strlen(dir_u->par_u->pax_c);
  c3_c* pax_c = dir_u->pax_c + pel_w + 1;
  c3_c* fas_c = strchr(pax_c, '/');

  return fas_c ? u2_ci_bytes((fas_c - pax_c), (c3_y*) pax_c)
               : u2_ci_string(pax_c);
}


/* _unix_file_name(): file name/extension.
*/
static u2_noun 
_unix_file_name(u2_reck* rec_u, u2_ufil* fil_u)
{
  c3_w pel_w = strlen(fil_u->par_u->pax_c);
  c3_c* pax_c = fil_u->pax_c + pel_w + 1;

  if ( !fil_u->dot_c ) {
    return u2_ci_string(pax_c);
  } 
  else {
    c3_c* ext_c = fil_u->dot_c + 1;

    ext_c = (*ext_c == '^') ? (ext_c + 1) : ext_c;
    return u2nc(u2_ci_bytes((fil_u->dot_c - pax_c), (c3_y*)pax_c),
                u2_ci_string(ext_c));
  }
}

/* _unix_dir_arch(): resolve directory to old style arch.
*/
static u2_noun
_unix_dir_arch(u2_reck* rec_u, u2_udir* dir_u)
{
  u2_udir* dis_u;
  u2_ufil* fil_u;
  u2_noun pam = u2_nul;

  for ( dis_u = dir_u->dis_u; dis_u; dis_u = dis_u->nex_u ) {
    u2_noun pre = _unix_dir_name(rec_u, dis_u);
    u2_noun arc = _unix_dir_arch(rec_u, dis_u);

    // uL(fprintf(uH, "dir %s\n", u2_cr_string(pre)));
    pam = u2_ckd_by_put(pam, pre, arc);
  }

  for ( fil_u = dir_u->fil_u; fil_u; fil_u = fil_u->nex_u ) {
    u2_noun wib = _unix_file_name(rec_u, fil_u);
    u2_noun baw = _unix_file_load(rec_u, fil_u);
    u2_noun has = u2_cn_mung(u2k(rec_u->toy.sham), u2k(baw));
    u2_noun fil = u2nt(u2_yes, has, baw);

    if ( u2_no == u2du(wib) ) {
      // uL(fprintf(uH, "file %s\n", u2_cr_string(wib)));
      pam = u2_ckd_by_put(pam, wib, fil);
    }
    else {
      u2_weak ole = u2_ckd_by_get(u2k(pam), u2k(u2h(wib)));
      u2_noun arc, rac;

      // uL(fprintf(uH, "file %s.%s\n", u2_cr_string(u2h(wib)),
      //                               u2_cr_string(u2t(wib))));

      if ( u2_none == ole ) {
        arc = u2nc(u2_no, u2_nul);
      } 
      else if ( u2_yes == u2h(ole) ) {
        u2z(ole);
        arc = u2nc(u2_no, u2_nul);
      }
      else arc = ole;

      rac = u2nc(u2_no, u2_ckd_by_put(u2k(u2t(arc)), u2k(u2t(wib)), fil));
      pam = u2_ckd_by_put(pam, u2k(u2h(wib)), rac);

      u2z(wib); u2z(arc);
    }
  }
  return u2nc(u2_no, pam);
}

/* _unix_desk_peek(): peek for arch.
*/
static u2_noun
_unix_desk_peek(u2_reck* rec_u, u2_noun hox, u2_noun syd)
{
  u2_noun cay;

  cay = u2_reck_prick
    (rec_u, u2k(rec_u->our),
            u2nc(c3_s2('c','z'),
                 u2nq(hox, 
                      syd,
                      u2k(rec_u->wen),
                      u2_nul)));

  if ( u2_nul == cay ) {
    return u2nc(u2_no, u2_nul);
  } else {
    u2_noun arc = u2k(u2t(cay));

    u2z(cay); return arc;
  }
}

/* _unix_desk_sync(): sync desk.
*/
static void
_unix_desk_sync(u2_reck* rec_u, 
                u2_noun  who,
                u2_noun  hox, 
                u2_noun  syd, 
                u2_udir* dir_u)
{
  u2_noun xun, bur, dul, fav, pax;

  xun = _unix_dir_arch(rec_u, dir_u);
  bur = _unix_desk_peek(rec_u, hox, syd);
  dul = u2_cn_mung(u2k(rec_u->toy.cyst), u2nc(xun, bur));
  pax = u2nq(c3__gold, c3__sync, u2k(rec_u->sen), u2_nul);
  fav = u2nq(c3__into, who, syd, u2nc(u2_yes, dul));

  u2_reck_plan(rec_u, pax, fav);
}

/* _unix_ship_update(): update top level ship.
*/
static void
_unix_ship_update(u2_reck* rec_u, u2_uhot* hot_u)
{
  u2_udir* dir_u = &(hot_u->dir_u);
  DIR*     rid_u = _unix_opendir(dir_u->pax_c);

  if ( u2_yes == _unix_dir_update(rec_u, dir_u, rid_u) ) {
    u2_udir* dis_u;
    u2_noun  who, hox;

    {
      mpz_t who_mp;

      mpz_init_set(who_mp, hot_u->who_mp);
      who = u2_ci_mp(who_mp);
      hox = u2_cn_mung(u2k(rec_u->toy.scot), u2nc('p', u2k(who)));
    }

    for ( dis_u = dir_u->dis_u; dis_u; dis_u = dis_u->nex_u ) { 
      u2_noun syd = _unix_dir_name(rec_u, dis_u); 

      // uL(fprintf(uH, "sync %s %s\n", u2_cr_string(hox), u2_cr_string(syd))); 
      _unix_desk_sync(rec_u, u2k(who), u2k(hox), syd, dis_u);
    }
    u2z(hox);
    u2z(who);
  }
}
 
/* _unix_hot_gain(): gain ship.
*/
static struct _u2_uhot*
_unix_hot_gain(u2_reck* rec_u, u2_noun who)
{
  u2_noun hox = u2_cn_mung(u2k(rec_u->toy.scot), u2nc('p', who));
  c3_c*   hox_c = u2_cr_string(hox);
  c3_c*   pax_c = _unix_down(u2_Host.ops_u.hom_c, hox_c + 1);
  DIR*    rid_u = opendir(pax_c);

  if ( !rid_u ) return 0;
  else closedir(rid_u);

  sprintf(pax_c, "%s/%s", u2_Host.ops_u.hom_c, hox_c + 1);
  free(hox_c);
  u2z(hox);

  {
    u2_uhot* hot_u = malloc(sizeof(u2_uhot));

    _unix_dir_watch(rec_u, &hot_u->dir_u, 0, pax_c);

    u2_cr_mp(hot_u->who_mp, who);
    hot_u->nex_u = 0;

    return hot_u;
  }
}

/* _unix_hot_lose(): release within a host directory.
*/
static void
_unix_hot_lose(u2_reck* rec_u, u2_uhot* hot_u)
{
  _unix_dir_free(rec_u, &(hot_u->dir_u));
}

/* u2_unix_ef_edit(): apply edits pushed out by clay.
*/
void
u2_unix_ef_edit(u2_reck* rec_u, u2_noun who, u2_noun syd, u2_noun nor)
{
}

/* u2_unix_ef_look(): update the root.
*/
void
u2_unix_ef_look(u2_reck* rec_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;
  u2_noun  who;
  u2_uhot* hot_u; 

  //  find owners without directories
  {
    for ( who = rec_u->own; u2_nul != who; who = u2t(who) ) {
      mpz_t who_mp;

      u2_cr_mp(who_mp, u2h(who));
      for ( hot_u = unx_u->hot_u; 
            hot_u && (0 != mpz_cmp(who_mp, hot_u->who_mp));
            hot_u = hot_u->nex_u );

      if ( 0 == hot_u ) {
        hot_u = _unix_hot_gain(rec_u, u2k(u2h(who)));

        if ( hot_u ) {
          // uL(fprintf(uH, "sync: gain %s\n", hot_u->dir_u.pax_c));

          hot_u->nex_u = unx_u->hot_u;
          unx_u->hot_u = hot_u;
        }
      }
    }
  }

  //  find directories without owners
  {
    u2_uhot** het_u = &(unx_u->hot_u);

    while ( 0 != (hot_u=*het_u) ) {
      for ( who = rec_u->own; u2_nul != who; who = u2t(who) ) {
        mpz_t who_mp;

        u2_cr_mp(who_mp, u2h(who));
        if ( 0 == mpz_cmp(who_mp, hot_u->who_mp) ) {
          break;
        }
        mpz_clear(who_mp);
      }

      if ( u2_nul == who ) {
        *het_u = hot_u->nex_u;
       
        // uL(fprintf(uH, "sync: lose %s\n", hot_u->dir_u.pax_c));
        _unix_hot_lose(rec_u, hot_u);

        free(hot_u);
        continue;
      }
      else {
        het_u = &(hot_u->nex_u);
      }
    }
  }

  //  update all ships
  {
    u2_uhot* hot_u;

    for ( hot_u = unx_u->hot_u; hot_u; hot_u = hot_u->nex_u ) {
      _unix_ship_update(rec_u, hot_u);
    }
  }
}

/* u2_unix_io_init(): initialize unix sync.
*/
void 
u2_unix_io_init(u2_reck* rec_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  ev_timer_init(&unx_u->tim_u, _lo_unix, 10000.0, 0.);
  unx_u->alm = u2_no;
  unx_u->sig_u = 0;
  unx_u->hot_u = 0;

  {
    u2_usig* sig_u;

    sig_u = malloc(sizeof(u2_usig));
    ev_signal_init(&sig_u->sil_u, _lo_sign, SIGTERM);

    sig_u->nex_u = unx_u->sig_u;
    unx_u->sig_u = sig_u;
  }
  {
    u2_usig* sig_u;

    sig_u = malloc(sizeof(u2_usig));
    ev_signal_init(&sig_u->sil_u, _lo_sign, SIGWINCH);

    sig_u->nex_u = unx_u->sig_u;
    unx_u->sig_u = sig_u;
  }
}

/* u2_unix_io_exit(): terminate unix I/O.
*/
void 
u2_unix_io_exit(u2_reck* rec_u)
{
}

/* u2_unix_io_spin(): start unix server(s).
*/
void
u2_unix_io_spin(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  if ( u2_yes == unx_u->alm ) {
    ev_timer_start(lup_u, &unx_u->tim_u);
  }

  {
    u2_usig* sig_u;

    for ( sig_u = unx_u->sig_u; sig_u; sig_u = sig_u->nex_u ) {
      ev_signal_start(lup_u, &sig_u->sil_u);
    }
  }
}

/* u2_unix_io_stop(): stop unix servers.
*/
void
u2_unix_io_stop(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  if ( u2_yes == unx_u->alm ) {
    ev_timer_stop(lup_u, &unx_u->tim_u);
  }

  {
    u2_usig* sig_u;

    for ( sig_u = unx_u->sig_u; sig_u; sig_u = sig_u->nex_u ) {
      ev_signal_stop(lup_u, &sig_u->sil_u);
    }
  }
}

/* u2_unix_io_poll(): update unix IO state.
*/
void
u2_unix_io_poll(u2_reck*        rec_u,
                struct ev_loop* lup_u)
{
  u2_unix* unx_u = &u2_Host.unx_u;

  {
    u2_noun wen = u2_reck_keep(rec_u, u2nt(c3__gold, c3__clay, u2_nul));
    
    if ( (u2_nul != wen) && 
         (u2_yes == u2du(wen)) &&
         (u2_yes == u2ud(u2t(wen))) )
    {
      double gap_g = u2_time_gap_double(u2k(rec_u->now), u2k(u2t(wen)));

      unx_u->alm = u2_yes;
      ev_timer_set(&unx_u->tim_u, gap_g, 0.);
    }
    else {
      unx_u->alm = u2_no;
    }
  }
}

/* u2_unix_io_time(): time event on unix channel.
*/
void
u2_unix_io_time(u2_reck*         rec_u,
                struct ev_timer* tim_u)
{
  u2_reck_plan
    (rec_u,
     u2nt(c3__gold, c3__clay, u2_nul),
     u2nc(c3__wake, u2_nul));
}

/* u2_unix_io_stat(): fs event on storage.
*/
void
u2_unix_io_stat(u2_reck*        rec_u,
                struct ev_stat* sat_u)
{
}

/* u2_unix_io_sign(): signal event.
*/
void
u2_unix_io_sign(u2_reck*          rec_u,
                struct ev_signal* sil_u)
{
  switch ( sil_u->signum ) {
    case SIGTERM: u2_Host.liv = u2_no; break;
    case SIGWINCH: u2_term_ef_winch(rec_u); break;
  }
}
