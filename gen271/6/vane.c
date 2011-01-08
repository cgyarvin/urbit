/* j/6/vane.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* debugging hacks
*/
  static void
  _dump_wall(u2_wire     wir_r,
             const c3_c* cap_c,
             u2_noun     wal)
  {
    if ( cap_c ) printf("%s:\n", cap_c);

    while ( u2_nul != wal ) {
      u2_noun h_wal = u2_h(wal);

      while ( u2_nul != h_wal ) {
        c3_assert(u2_h(h_wal) < 128);

        putchar(u2_h(h_wal));
        h_wal = u2_t(h_wal);
      }
      putchar(10);
      wal = u2_t(wal);
    }
  }
  void
  j2_mcy(Pit, vane, dupt)(u2_wire     wir_r,
                          u2_noun     van,
                          const c3_c* cap_c,
                          u2_noun     typ)
  {
    u2_noun vin;
    u2_noun pup, cul, col, fly, wal;

    vin = u2_bn_molt(wir_r, van, 4, typ, 0);
    pup = u2_bn_hook(wir_r, vin, "dump");
    cul = u2_bn_hook(wir_r, van, "club");
    col = u2_bn_molt(wir_r, cul, 4, pup, 0); 

    fly = u2_bn_hook(wir_r, col, "fly");

    wal = u2_bn_mung(wir_r, fly, 75);

    _dump_wall(wir_r, cap_c, wal);

    u2_rl_lose(wir_r, vin);
    u2_rl_lose(wir_r, pup);
    u2_rl_lose(wir_r, cul);
    u2_rl_lose(wir_r, col);
    u2_rl_lose(wir_r, fly);
    u2_rl_lose(wir_r, wal);
  }
  static void
  _type_in(u2_wire wir_r, 
           u2_noun typ)
  {
    u2_noun p_typ, q_typ, r_typ;

    if ( u2_no == u2_dust(typ) ) switch ( typ ) {
      default: goto fail;

      case c3__atom: break;
      case c3__blot: break;
      case c3__blur: break;
    } 
    else switch ( u2_h(typ) ) {
      default: fail: u2_err(wir_r, "bum type", typ); u2_bl_bail(wir_r); break;

      case c3__cell: {
        if ( u2_no == u2_as_cell(u2_t(typ), &p_typ, &q_typ) ) {
          goto fail;
        } else {
          _type_in(wir_r, p_typ);
          _type_in(wir_r, q_typ);
          break;
        }
      }
      case c3__core: {
        if ( u2_no == u2_as_trel(u2_t(typ), &p_typ, &q_typ, &r_typ) ) {
          goto fail;
        } else {
          _type_in(wir_r, p_typ);

          if ( u2_yes == u2_dust(q_typ) ) {
            _type_in(wir_r, u2_t(q_typ));
          }
          break;
        }
      }
      case c3__cube: { 
        p_typ = u2_t(typ);
        {
          break;
        }
      case c3__face: {
        if ( u2_no == u2_as_cell(u2_t(typ), &p_typ, &q_typ) ) {
          goto fail;
        } else {
          if ( u2_no == u2_stud(p_typ) ) {
            goto fail;
          }
          _type_in(wir_r, q_typ);
          break;
        }
      }
      case c3__fork: {
        if ( u2_no == u2_as_cell(u2_t(typ), &p_typ, &q_typ) ) {
          goto fail;
        } else {
          _type_in(wir_r, p_typ);
          _type_in(wir_r, q_typ);
          break;
        }
      }
      case c3__hold:
        if ( u2_no == u2_as_cell(u2_t(typ), &p_typ, &q_typ) ) {
          goto fail;
        } else {
          _type_in(wir_r, p_typ);
          break;
        }
      }
    } 
  }
  void
  j2_mby(Pit, type)(u2_wire  wir_r,
                    u2_noun  typ)
  {
    u2_rl_ok(wir_r, typ);
    _type_in(wir_r, typ);
  }

/* declarations
*/
  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, clay)(u2_wire wir_r, 
                         u2_noun cor);                            //  retain

  extern u2_ho_jet j2_mcj(Pit, vane, bake)[];
  extern u2_ho_jet j2_mcj(Pit, vane, fair)[];
  extern u2_ho_jet j2_mcj(Pit, vane, firm)[];
  extern u2_ho_jet j2_mcj(Pit, vane, find)[];
  extern u2_ho_jet j2_mcj(Pit, vane, fish)[];
  extern u2_ho_jet j2_mcj(Pit, vane, gain)[];
  extern u2_ho_jet j2_mcj(Pit, vane, make)[];
  extern u2_ho_jet j2_mcj(Pit, vane, mill)[];
  extern u2_ho_jet j2_mcj(Pit, vane, nest)[];
  extern u2_ho_jet j2_mcj(Pit, vane, peek)[];
  extern u2_ho_jet j2_mcj(Pit, vane, play)[];
  extern u2_ho_jet j2_mcj(Pit, vane, reap)[];
  extern u2_ho_jet j2_mcj(Pit, vane, seek)[];
  extern u2_ho_jet j2_mcj(Pit, vane, snap)[];
  extern u2_ho_jet j2_mcj(Pit, vane, tuck)[];

/* structures
*/
  u2_ho_driver 
  j2_mbd(Pit, vane)[] = {
    { j2_sc(Pit, vane, bake), j2_mcj(Pit, vane, bake), 0, 0, u2_none },
    { j2_sc(Pit, vane, find), j2_mcj(Pit, vane, find), 0, 0, u2_none },
    { j2_sc(Pit, vane, fair), j2_mcj(Pit, vane, fair), 0, 0, u2_none },
    { j2_sc(Pit, vane, firm), j2_mcj(Pit, vane, firm), 0, 0, u2_none },
    { j2_sc(Pit, vane, fish), j2_mcj(Pit, vane, fish), 0, 0, u2_none },
    { j2_sc(Pit, vane, gain), j2_mcj(Pit, vane, gain), 0, 0, u2_none },
    { j2_sc(Pit, vane, nest), j2_mcj(Pit, vane, nest), 0, 0, u2_none },
    { j2_sc(Pit, vane, make), j2_mcj(Pit, vane, make), 0, 0, u2_none },
    { j2_sc(Pit, vane, mill), j2_mcj(Pit, vane, mill), 0, 0, u2_none },
    { j2_sc(Pit, vane, peek), j2_mcj(Pit, vane, peek), 0, 0, u2_none },
    { j2_sc(Pit, vane, play), j2_mcj(Pit, vane, play), 0, 0, u2_none },
    { j2_sc(Pit, vane, reap), j2_mcj(Pit, vane, reap), 0, 0, u2_none },
    { j2_sc(Pit, vane, seek), j2_mcj(Pit, vane, seek), 0, 0, u2_none },
    { j2_sc(Pit, vane, snap), j2_mcj(Pit, vane, snap), 0, 0, u2_none },
    { j2_sc(Pit, vane, tuck), j2_mcj(Pit, vane, tuck), 0, 0, u2_none },
    { }
  };

  u2_ho_jet 
  j2_mbj(Pit, vane)[] = {
    // { "clay", c3__hevy, j2_mc(Pit, vane, clay), u2_no, u2_none, u2_none },
    { }
  };

  u2_ho_driver
  j2_db(Pit, vane) = 
    { j2_sb(Pit, vane), j2_mbj(Pit, vane), j2_mbd(Pit, vane), 0, u2_none };
