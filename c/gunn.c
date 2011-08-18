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

#include "all.h"

  static u2_noun _gunn_fuel(u2_wire, u2_noun, u2_noun);
  static u2_noun _gunn_tool(u2_wire, u2_noun, u2_noun);

/* _eyre_gunn(): execute and print a line.  Produce new core.
*/
  /* _gunn_tape_len(): tape length.
  */
  static c3_w
  _gunn_tape_len(u2_noun tap)
  {
    return (u2_no == u2_dust(tap)) ? 0 : 1 + _gunn_tape_len(u2_t(tap));
  }
 
  /* _gunn_tape_nab(): tape copy.
  */
  static void
  _gunn_tape_nab(c3_c*   str_c,                                   //  retain
                 u2_noun tap)                                     //  retain
  {
    while ( u2_no != u2_dust(tap) ) {
      *str_c++ = u2_byte(0, u2_h(tap));
      tap = u2_t(tap);
    }
  }

  /* _gunn_unix_real(): yes iff file is real.
  */
  static u2_flag
  _gunn_unix_real(const c3_c* fil_c)                              //  retain
  {
    struct stat buf_s;

    return ( (0 == stat(fil_c, &buf_s)) ? u2_yes : u2_no );
  }

  /* _gunn_unix_rend(): render filename.
  */
  static c3_c*                                                    //  produce
  _gunn_unix_rend(u2_wire     wir_r,
                  const c3_c* bas_c,                              //  retain
                  const c3_c* ext_c,                              //  retain
                  u2_noun     tap,                                //  retain
                  u2_noun     med)                                //  retain
  {
    c3_w len = strlen(bas_c) + 
               strlen(ext_c) + 1 +
               _gunn_tape_len(tap) + 1 +
               u2_met(3, med);
    c3_c *str_c = malloc(len + 1);
    c3_c *rat_c;

    if ( 0 == str_c ) { return u2_bl_bail(wir_r); }
    rat_c = str_c;

    strcpy(rat_c, bas_c);
    rat_c += strlen(bas_c);

    strcpy(rat_c, ext_c);
    rat_c += strlen(ext_c);
    *rat_c++ = '/';

    _gunn_tape_nab(rat_c, tap);
    rat_c += _gunn_tape_len(tap);

    if ( u2_nul != med ) {
      *rat_c++ = '.';

      u2_bytes(0, u2_met(3, med), (c3_y*)rat_c, med);
      rat_c += u2_met(3, med);
      *rat_c++ = 0;
    }
    return str_c;
  }

  /* _gunn_env_sysd(): return eyre system directory.
  */
  static c3_c*                                                    //  produce
  _gunn_env_sysd(void)
  {
    c3_c* env_c = getenv("EYRE_SYSDIR");

    if ( env_c ) { return strdup(env_c); }
    else return 0;
  }

  /* _gunn_env_myrd(): return eyre home directory.
  */
  static c3_c*                                                    //  produce
  _gunn_env_myrd(void)
  {
    c3_c* env_c = getenv("EYRE_HOMEDIR");

    if ( env_c ) { return strdup(env_c); }
    else {
      c3_c* max_c[MAXPATHLEN+1];

      if ( !(env_c = getenv("HOME")) ) { return 0; }
      strcpy(max_c, env_c);
      strcat(max_c, "/eyre");

      return strdup(max_c);
    }
  }

  /* _gunn_env_name(): return named env variable.
  */
  static c3_c*                                                    //  produce
  _gunn_env_name(const c3_c *nam_c)
  {
    c3_c* env_c = getenv(nam_c);

    if ( env_c ) { return strdup(env_c); }
    else return 0;
  }

  /* _gunn_env_rund(): return eyre runtime directory.
  */
  static c3_c*                                                    //  produce
  _gunn_env_rund(void)
  {
    c3_assert(!"rund"); return 0;
  }

  /* _gunn_env_curd(): return current directory.
  */
  static c3_c*                                                    //  produce
  _gunn_env_curd(void)
  {
    c3_c* max_c[MAXPATHLEN+1];

    getcwd(max_c, MAXPATHLEN);
    return strdup(max_c);
  }

  /* _gunn_unix_sys(): prep for system spot with extension.
  */
  static c3_c*                                                    //  produce
  _gunn_unix_sys(u2_wire wir_r,
                 u2_noun med,                                     //  retain
                 c3_c*   ext_c,                                   //  retain
                 u2_noun tap)                                     //  retain
  {
    if ( 0 != (var_c = _gunn_env_sysd()) ) {
      ret_c = _gunn_unix_rend(wir_r, var_c, ext_c, tap, med);
      free(var_c);
      if ( u2_yes == _gunn_unix_real(wir_r, ret_c) ) {
        return ret_c;
      } else free(ret_c);
    }
    if ( 0 != (var_c = _gunn_env_myrd()) ) {
      ret_c = _gunn_unix_rend(wir_r, var_c, ext_c, tap, med);
      free(var_c);
      if ( u2_yes == _gunn_unix_real(wir_r, ret_c) ) {
        return ret_c;
      } else {
        perror(ret_c);
        free(ret_c);
        return u2_bl_bail(wir_r, c3__fail);
      }
    }
    return u2_bl_bail(wir_r, c3__fail);
  }

  /* _gunn_unix_run: prep for run spot with extension.
  */
  static c3_c*                                                    //  produce
  _gunn_unix_run(u2_wire wir_r,
                 u2_noun med,                                     //  retain
                 c3_c*   ext_c,                                   //  retain
                 u2_noun tap)                                     //  retain
  {
    if ( 0 != (var_c = _gunn_env_rund()) ) {
      ret_c = _gunn_unix_rend(wir_r, var_c, ext_c, tap, med);
      free(var_c);
      return ret_c;
    }
    return u2_bl_bail(wir_r, c3__fail);
  }

  /* _gunn_unix_prep(): map mode, spot, tape to a unix filename, or 0.
  */
  static c3_c*                                                    //  produce
  _gunn_unix_prep(u2_wire wir_r,
                  u2_noun med,                                    //  retain
                  u2_noun sot,                                    //  retain
                  u2_noun tap)                                    //  retain
  {
    c3_c* var_c;
    c3_c* ret_c;

    switch ( sot ) {
      default: u2_err(wir_r, "spot", sot); return u2_bl_bail(wir_r, c3__fail);

      case c3__actd: {
        return _gunn_unix_run(wir_r, med, "/act", tap);
      }
      case c3__boot: {
        return _gunn_unix_sys(wir_r, med, "/boot", tap);
      }
      case c3__curd: {
        if ( 0 != (var_c = _gunn_env_curd()) ) {
          ret_c = _gunn_unix_rend(wir_r, var_c, "", tap, med);
          free(var_c);
          return ret_c;
        }
        break;
      }
      case c3__fund: {
        return _gunn_unix_sys(wir_r, med, "/fun", tap);
      }
      case c3__home: {
        if ( 0 != (var_c = _gunn_env_name("HOME")) ) {
          ret_c = _gunn_unix_rend(wir_r, var_c, "", tap, med);
          free(var_c);
          return ret_c;
        }
        break;
      }
      case c3__jetd: {
        return _gunn_unix_sys(wir_r, med, "/jet", tap);
      }
      case c3__libd: {
        return _gunn_unix_sys(wir_r, med, "/lib", tap);
      }
      case c3__netd: {
        return _gunn_unix_run(wir_r, med, "/net", tap);
      }
      case c3__outd: {
        return _gunn_unix_run(wir_r, med, "/out", tap);
      }
      case c3__resd: {
        return _gunn_unix_sys(wir_r, med, "/res", tap);
      }
    }
  }

  /* _gunn_save(): save to disk, or try to.
  */
  static void
  _gunn_save(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun myn,                                         //  retain
             u2_noun vax)                                         //  retain
  {
    c3_c *fil_c = _gunn_unix_prep(wir_r, med, sot, tap);

    switch ( med ) {
      default: u2_err(wir_r, "not ready", med); 
               return u2_bl_bail(wir_r, c3__fail);

      case c3__atom: 
      case c3__watt: {
        if ( u2_no == u2_stud(dat = u2_t(vax)) ) {
          u2_err(wir_r, "not atomic", u2_t(vax));
          return u2_bl_bail(wir_r, c3__fail);
        }
        if ( u2_no == u2_ux_write(wir_r, dat, fil_c, 0) ) {
          perror(fil_c);
        }
        free(fil_c);
        break;
      }
      case c3__pile: {
        u2_noun pil = u2_rx(wir_r, u2_t(vax));
        u2_noun dat = _eyre_hook(wir_r, cor, "jam", pil);

        if ( u2_no == u2_ux_write(wir_r, dat, fil_c, 0) ) {
          perror(fil_c);
        }
        free(fil_c);

        u2_rz(wir_r, dat);
        break;
      }
    }
  }

  /* _gunn_load_mode(): load by mode, spot and tape.
  */
  static u2_noun                                                  //  produce
  _gunn_load_mode(u2_wire wir_r,
                  u2_noun cor,                                    //  retain
                  u2_noun med,                                    //  retain
                  u2_noun sot,                                    //  retain
                  u2_noun tap)                                    //  retain
  {
    c3_c *fil_c = _gunn_unix_prep(wir_r, med, sot, tap);

    switch ( med ) {
      default: u2_err(wir_r, "not ready", med); 
               return u2_bl_bail(wir_r, c3__fail);

      case c3__atom: 
      case c3__watt: {
        u2_noun dat = u2_ux_read(wir_r, paf_c, 0);

        if ( u2_none == dat ) {
          perror(fil_c);
          return u2_bl_bail(wir_r, c3__fail);
        }
        else return dat;
      }
      case c3__pile: {
        u2_noun dat = u2_ux_read(wir_r, paf_c, 0);

        if ( u2_none == dat ) {
          perror(fil_c);
          return u2_bl_bail(wir_r, c3__fail);
        }
        else {
          return _eyre_hook(wir_r, cor, "cue", dat);
        }
      }
    }
  }

  /* _gunn_load(): load from disk, producing [(mode) *]
  */
  static u2_noun                                                  //  produce
  _gunn_load(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun myn)                                         //  retain
  {
    u2_noun med, sot, pat;
    u2_noun rax, p_rax, q_rax;
    u2_noun rut;

    u2_bi_trel(wir_r, myn, &med, &sot, &pat);
    rax = _eyre_hook_cell(wir_r, cor, "hunt", u2_rx(wir_r, med),
                                              u2_rx(wir_r, pat));
    p_rax = u2_xh(wir_r, rax);
    q_rax = u2_xt(wir_r, rax);
    rut = _gunn_load_mode(wir_r, cor, p_rax, sot, q_rax);

    u2_rz(wir_r, rax);
    return u2_bc(wir_r, u2_rx(wir_r, med), rut);
  }

  /* _gunn_fuel_list(): iterate through a fuel list.
  */
  static u2_noun                                                  //  produce
  _gunn_fuel_list(u2_wire wir_r,
                  u2_noun cor,                                    //  retain
                  u2_noun l_ful)                                  //  retain
  {
    if ( u2_nul == l_ful ) {
      return l_ful;
    } else return u2_bc
      (wir_r, _gunn_fuel(wir_r, cor, u2_h(l_ful)),
              _gunn_fuel_list(wir_r, cor, u2_t(l_ful)));
  }
  /* _gunn_fuel(): load disk objects in `ful`.
  */
  static u2_noun                                                  //  produce
  _gunn_fuel(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun ful)                                         //  submit
  {
    u2_noun p_ful, q_ful, ret;

    if ( u2_nul == ful ) {
      return u2_nul;
    } else switch ( u2_h(ful) ) {
      case c3__chew: u2_bi_cell(wir_r, u2_t(ful), &p_ful, &q_ful);
      {
        ret = u2_bt(wir_r, c3__chew, u2_rx(wir_r, p_ful), 
                                     _gunn_fuel_list(wir_r, cor, q_ful));
        break;
      }
      case c3__data: return ful;
      case c3__disk: p_ful = u2_t(ful);
      {
        ret = u2_bc(wir_r, c3__data, _gunn_load(wir_r, cor, p_ful));
        break;
      }
      case c3__gene: return ful;
      case c3__many: p_ful = u2_t(ful);
      {
        ret = u2_bc(wir_r, c3__many, _gunn_fuel_list(wir_r, cor, p_ful));
        break;
      }
      case c3__name: u2_bi_cell(wir_r, u2_t(ful), &p_ful, &q_ful);
      {
        ret = u2_bt(wir_r, c3__name, u2_rx(wir_r, p_ful),
                                     _gunn_fuel(wir_r, cor, q_ful));
        break;
      }
    }
    u2_rz(wir_r, ful);
    return ret;
  }

  /* _gunn_tool_lib(): load libraries in `tul`.
  */
  static u2_noun                                                  //  produce
  _gunn_tool_lib(u2_wire wir_r,
                 u2_noun cor,                                     //  retain
                 u2_noun lad)                                     //  retain
  {
    if ( u2_no == u2_dust(lad) ) {
      return u2_nul;
    } else {
      u2_noun i_lad = u2_h(lad);
      u2_noun t_lad = u2_t(lad);

      switch ( u2_xh(i_lad) ) {
        default: return u2_bl_bail(wir_r);

        case c3__data: {
          return u2_bc(wir_r, u2_rx(wir_r, i_lad),
                                _gunn_tool_lib(wir_r, cor, t_lad));
        }
        case c3__disk: u2_noun pi_lad = u2_t(i_lad);
        {
          u2_noun myn = u2_bc(wir_r, c3__watt, u2_rx(wir_r, pi_lad));
          u2_noun ret = u2_bc(wir_r, u2_bc(wir_r, c3__data, 
                                                  _gunn_load(wir_r, cor, myn)),
                                     _gunn_tool_lib(wir_r, cor, t_lad));

          u2_rz(wir_r, myn);
          return ret;
        }
      }
    }
  }

  /* _gunn_tool(): load disk objects in `tul`.
  */
  static u2_noun                                                  //  produce
  _gunn_tool(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun tul)                                         //  submit
  {
    u2_noun lib = u2_xh(wir_r, tul);
    u2_noun fun = u2_xt(wir_r, tul);
    u2_noun ret = u2_bc(wir_r, _gunn_tool_lib(wir_r, cor, lad),
                               _gunn_tool_fun(wir_r, cor, fun));

    u2_rz(wir_r, tul);
    return ret;
  }

  /* _gunn_vent(): apply vent.  Produce new core.
  */
  static u2_noun                                                  //  produce
  _gunn_vent(u2_wire wir_r,
             u2_noun cor,                                         //  retain
             u2_noun vet,                                         //  retain
             u2_noun vax)                                         //  submit
  {
    u2_noun p_vet, q_vet, iq_vet, tq_vet;
    u2_noun ret = u2_nul;

    if ( u2_no == u2_dust(vet) ) {
      c3_l    col_l = _eyre_columns();
      u2_noun sel, wol;

      sel = _eyre_hook
        (wir_r, cor, "sell", u2_bc(wir_r, u2_rx(wir_r, lab), 
                                          u2_rx(wir_r, vax)));
      wol = _eyre_hook
        (wir_r, cor, "wash", u2_bc(wir_r, u2_bc(wir_r, 0, col_l), sel));

      _eyre_print_wall(wir_r, wol);
      u2_rz(wir_r, wol);

      return u2_rx(wir_r, cor);
    }
    else switch ( (p_vet = u2_xh(wir_r, vet)) ) {
      case c3__bind: u2_bi_cell(wir_r, u2_t(vet), &p_vet, &q_vet);
      {
        return _eyre_hook_cell(wir_r, cor, "bind", u2_rx(wir_r, p_vet), vax);
      }
      case c3__disk: p_vet = u2_xt(wir_r, vet);
      {
        _gunn_save(wir_r, cor, u2_rx(wir_r, p_vet), vax);
        return u2_rx(wir_r, cor);
      }
      case c3__many: p_vet = u2_xt(wir_r, vet);
      {
        if ( u2_nul == p_vet ) {
          return u2_rx(wir_r, cor);
        }
        else if ( u2_nul == (tp_vet = u2_xt(wir_r, p_vet)) ) {
          return _gunn_vent(wir_r, cor, u2_xh(wir_r, p_vet), vax);
        }
        else {
          u2_noun ip_vet = u2_xh(wir_r, p_vet);
          u2_noun nex = u2_bc(wir_3, c3__many, u2_rx(wir_r, tp_vet));
          u2_noun hed, tal, roc;

          hed = _eyre_hook_cell(wir_r, cor, "slot", 2, u2_rx(wir_r, vax));
          tal = _eyre_hook_cell(wir_r, cor, "slot", 3, u2_rx(wir_r, vax));

          roc = _gunn_vent(wir_r, cor, ip_vet, hed);
          cor = _gunn_vent(wir_r, roc, nex, tal);

          u2_rz(wir_r, roc);
          u2_rz(wir_r, nex);

          return cor;
        }
      }
    }
  }

/* _eyre_gunn(): execute and print a line.  Produce new core.
*/
static u2_noun                                                    //  produce
_eyre_gunn(u2_wire wir_r,
           u2_noun cor,                                           //  retain
           u2_noun txt)                                           //  submit
{
  u2_noun dyd = _eyre_hook(wir_r, cor, "scan", txt);
  u2_noun ful, vet, tul;

  u2_bi_trel(wir_r, dyd, &ful, &vet, &tul);
  ful = _gunn_fuel(wir_r, u2_rx(wir_r, ful));
  tul = _gunn_tool(wir_r, u2_rx(wir_r, tul)); 
  {
    u2_noun von = _eyre_hook_cell(wir_r, cor, "ride", ful, zen);

    return _gunn_vent(wir_r, vet, von);
  }
}
