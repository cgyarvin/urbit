/* c/hill.c
**
** This file is in the public domain.
*/
#include <sys/stat.h>
#include <fcntl.h>

#define U2_GLOBAL
#define C3_GLOBAL
#include "all.h"

#define   PitZ  watt_270
#define   PitA  watt_269
#define   PitB  watt_268

#define   FileA   "watt/269"
#define   FileB   "watt/270"

  /**   Interpreter data structures.
  **/
    /*  ++  shoe  <[p=*type q=*core]>
    */
    typedef u2_noun hi_shoe;

    /* struct hill_state
    */
      struct hill_state {
        /*  wir - the execution wire.
        */
        u2_ray wir_r;

        /*  soa - shoe A, type/core for PitA, File A by jet boot Z
        */
        hi_shoe soa;

        /*  sob - shoe B, type/core for PitB, File B by mint A
        */
        hi_shoe sob;
      };

  /**   Direct-jet hacks.  All but PitZ should be removed.
  **/
    /* Minting - for jet boot.
    */
      u2_noun                                                     //  transfer
      j2_mcy(PitZ, ut, mint)(u2_wire wir_r,
                             u2_noun van,                         //  retain
                             u2_noun sut,                         //  retain
                             u2_noun gol,                         //  retain
                             u2_noun gen);                        //  retain
      
    /* Parsing - a hack.
    */
      u2_weak                                                     //  transfer
      j2_mbc(PitZ, ream)(u2_wire wir_r, 
                         u2_noun txt);                            //  transfer
      u2_weak                                                     //  transfer
      j2_mbc(PitA, ream)(u2_wire wir_r, 
                         u2_noun txt);                            //  transfer

    /* Type printing - hack squared.
    */
      void
      j2_mcy(PitA, ut, dupt)(u2_wire     wir_r,
                             u2_noun     van,                     //  retain
                             const c3_c* cap_c,                   //  retain
                             u2_noun     typ);                    //  retain


/* _hill_van(): artificial ut core for jet booting (fits 270).
*/
static u2_noun                                                    //  produce
_hill_van(u2_wire wir_r)
{
  u2_noun cor = u2_bc(wir_r, _0, 42);    //  42 == not nock
  u2_noun fan = _0;
  u2_noun rib = _0;
  u2_noun vet = _0;
  u2_noun sut = c3__blur;

  return u2_bc
    (wir_r, u2_bc(wir_r, 
                  sut,
                  u2_bc(wir_r, u2_bt(wir_r, fan, rib, vet),
                               cor)),
            87);                                //  87 == not nock
}

/* _hill_mint_z(): mint `txt` as `[type core]` with PitZ jets.
*/
static u2_noun                                                    //  produce
_hill_mint_z(u2_wire wir_r,
             u2_noun sut,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_atom txt)                                         //  retain
{
  u2_noun gen;

  if ( u2_none == (gen = j2_mbc(PitZ, ream)(wir_r, txt)) ) {
    fprintf(stderr, "{bz: parse failed}\n");
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun van = _hill_van(wir_r);
    u2_noun gam;

    gam = j2_mcy(PitZ, ut, mint)(wir_r, van, sut, gol, gen);
    u2_rz(wir_r, van);

    return gam;
  }
}

/* _hill_mint_a(): mint `txt` as `[type core]` with PitA shoe.
*/
static u2_noun                                                    //  produce
_hill_mint_a(u2_wire wir_r,
             u2_noun soa,                                         //  retain
             u2_noun sut,                                         //  retain
             u2_noun gol,                                         //  retain
             u2_atom txt)                                         //  retain
{
  u2_noun gen;

  if ( u2_none == (gen = j2_mbc(PitA, ream)(wir_r, txt)) ) {
    fprintf(stderr, "{ba: parse failed}\n");
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun cor = u2_t(soa); 
    u2_noun fut = u2_sh_look(wir_r, cor, "ut");

    if ( u2_none == fut ) {
      printf("ba: fut failed\n");
      return u2_none;
    } else {
      u2_noun tut = u2_nk_nock(wir_r, u2_rx(wir_r, cor), fut);

      if ( u2_none == tut ) {
        printf("ba: tut failed\n");
        return u2_none;
      }
      else {
        u2_noun van = u2_rl_molt(wir_r, tut, u2_cv_sam, u2_rx(wir_r, sut), 0);

        u2_rl_lose(wir_r, tut);
        if ( u2_none == van ) {
          printf("ba: van failed\n");
          return u2_none;
        }
        else {
          u2_noun gom = u2_sh_look(wir_r, van, "mint"); 

          if ( u2_none == gom ) {
            printf("ba: gom failed\n");
            u2_rl_lose(wir_r, van); return u2_none;
          } else {
            u2_noun mil = u2_nk_nock(wir_r, van, gom);

            if ( u2_none == mil ) {
              printf("ba: mil failed\n");
              return u2_none;
            }
            else {
              u2_noun ruq = u2_rc(wir_r, u2_rx(wir_r, gol), 
                                         u2_rx(wir_r, gen));

              if ( u2_none == ruq ) {
                printf("ba: ruq failed\n");
                return u2_none;
              }
              else return u2_nk_mung(wir_r, mil, ruq);
            }
          }
        }
      }
    }
  }
}

/* _hill_stew(): from [type form] to [type core].
*/
static u2_noun                                                    //  produce
_hill_stew(u2_wire wir_r,
           u2_noun gam)                                           //  retain
{
  return u2_bc
    (wir_r, u2_rx(wir_r, u2_h(gam)),
            u2_nk_nock(wir_r, _0, u2_rx(wir_r, u2_t(gam))));      //  XX !!
}

/* _hill_shoe_z(): generate shoe A (with Z jets).
*/
static u2_noun                                                    //  produce
_hill_shoe_z(u2_wire     wir_r,
             const c3_c* fil_c)                                   //  retain
{
  u2_noun txt = u2_ux_read(wir_r, fil_c, "watt");

  if ( u2_none == txt ) {
    fprintf(stderr, "{not found: %s.watt}\n", fil_c);
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun gam = _hill_mint_z(wir_r, c3__noun, c3__noun, txt); 
    u2_noun soh = _hill_stew(wir_r, gam);

    u2_rz(wir_r, txt);
    u2_rz(wir_r, gam);
    
    return soh;
  }
}

/* _hill_shoe_a(): generate shoe B (with shoe A).
*/
static u2_noun                                                    //  produce
_hill_shoe_a(u2_wire     wir_r,
             u2_noun     soa, 
             const c3_c* fil_c)                                   //  retain
{
  u2_noun txt = u2_ux_read(wir_r, fil_c, "watt");

  if ( u2_none == txt ) {
    fprintf(stderr, "{not found: %s.watt}\n", fil_c);
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun gam = _hill_mint_a(wir_r, soa, c3__noun, c3__noun, txt); 
    u2_noun soh = _hill_stew(wir_r, gam);

    u2_rz(wir_r, txt);
    u2_rz(wir_r, gam);
    
    return soh;
  }
}

/* _hill_dump_a(): dump type with shoe A.
*/
static void
_hill_dump_a(u2_wire     wir_r,
             u2_noun     soa,                                     //  retain
             const c3_c* cap_c,                                   //  retain
             u2_noun     typ)                                     //  retain
{
  u2_noun cor = u2_t(soa);
  u2_noun fut = u2_sh_look(wir_r, cor, "ut");

  if ( u2_none == fut ) {
    printf("dump: fut failed\n");
    u2_bl_bail(wir_r);

  } else {
    u2_noun van = u2_nk_nock(wir_r, u2_rx(wir_r, cor), fut);

    j2_mcy(PitA, ut, dupt)(wir_r, van, cap_c, typ);
    u2_rl_lose(wir_r, van);
  }
}

/* _hill_fire_a(): execute and print expression over pit B (with shoe A).
*/
static void                                                       //  produce
_hill_fire_a(u2_wire     wir_r,
             u2_noun     soa,                                     //  retain
             u2_noun     sob,                                     //  retain
             const c3_c* exp_c)                                   //  retain
{
  u2_noun txt, gen, gam, som;

  txt = u2_bn_string(wir_r, exp_c);
  gen = j2_mbc(PitA, ream)(wir_r, txt);
  gam = _hill_mint_a(wir_r, soa, u2_h(sob), c3__noun, gen);

  _hill_dump_a(wir_r, soa, 0, u2_h(gam));
  som = u2_nk_nock(wir_r, u2_rx(wir_r, u2_t(sob)), u2_t(gam));

  if ( u2_none == som ) {
    fprintf(stderr, "{none}\n");
  }
  else {
    u2_err(wir_r, 0, som);
  }
  u2_rz(wir_r, txt);
  u2_rz(wir_r, gen);
  u2_rz(wir_r, gam);
  u2_rz(wir_r, som);
}

/* hill_boot(): create the hill engine.
*/
struct hill_state*                                                //  produce
hill_boot(void)
{
  u2_ray wir_r;

  u2_boot();
  wir_r = u2_wr_init(c3__rock, u2_ray_of(0, 0), u2_ray_of(1, 0));

  fprintf(stderr, "{boot}\n");

  /* Mint the shoes.  Impeccable memory practices.
  */
  {
    u2_noun soa = u2_none;
    u2_noun sob = u2_none;

    do {
      /* Boot shoe A.
      */
      {
        u2_ray  jub_r = u2_bl_open(wir_r);

        if ( u2_bl_set(wir_r) ) {
          u2_bl_done(wir_r, jub_r);
          fprintf(stderr, "{no boot, a}\n");
          break;
        }
        else {
          u2_bl_done(wir_r, jub_r);

          soa = _hill_shoe_z(wir_r, FileA);
        }
      }
      fprintf(stderr, "{boot %s}\n", FileA);

      /* Boot shoe B.
      */
      {
        u2_ray  jub_r = u2_bl_open(wir_r);

        if ( u2_bl_set(wir_r) ) {
          u2_bl_done(wir_r, jub_r);
          fprintf(stderr, "{no boot, b}\n");
          break;
        }
        else {
          u2_bl_done(wir_r, jub_r);

          sob = _hill_shoe_a(wir_r, soa, FileB);
        }
      }
      fprintf(stderr, "{boot %s}\n", FileB);

      /* Create state and return on success.
      */
      {
        struct hill_state* hil_h = malloc(sizeof(struct hill_state));

        hil_h->wir_r = wir_r;
        hil_h->soa = soa;
        hil_h->sob = sob;

        return hil_h;
      } 
    } while (0);

    u2_rz(wir_r, soa);
    u2_rz(wir_r, sob);

    return 0;
  }
}

/* hill_lose(): terminate and free state.
*/
void
hill_lose(struct hill_state* hil_h)                               //  submit
{
  u2_wire wir_r = hil_h->wir_r;

  u2_rz(wir_r, hil_h->soa);
  u2_rz(wir_r, hil_h->sob);
}

/* hill_line(): execute a hill command line.
*/
void
hill_line(struct hill_state* hil_h,
          const c3_c*        lin_c)
{
  u2_wire wir_r = hil_h->wir_r;
  hi_shoe soa   = hil_h->soa;
  hi_shoe sob   = hil_h->sob;

  u2_bx_boot(wir_r);
  u2_bx_spot(wir_r, u2_nul);

  _hill_fire_a(wir_r, soa, sob, lin_c);

  LoomStop = 0;
  u2_bx_show(wir_r);
}
