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

#define   FileZ   "watt/270"
#define   FileA   "watt/269"
#define   FileB   "watt/268"

  /**   Interpreter data structures.
  **/
    /*  ++  shoe  <[p=*type q=*noun]>
    */
    typedef u2_noun hi_shoz;                  //  type is PitZ type
    typedef u2_noun hi_shoa;                  //  type is PitA type

    /* struct hill_state
    */
      struct hill_state {
        /*  wir - the execution wire.
        */
        u2_ray wir_r;

        /*  soa - shoe A, type/core for PitA, File A by jet boot Z
        */
        hi_shoz soa;

        /*  sob - shoe B, type/core for PitB, File B by mint A
        */
        hi_shoa sob;
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


/* _hill_fill_1(): fill one argument in shoe; type assumed
*/
static u2_noun                                                    //  produce
_hill_fill_1(u2_wire wir_r,
             u2_noun sho,                                         //  retain
             u2_noun a)                                           //  retain
{
  return u2_bc
    (wir_r, u2_rx(wir_r, u2_h(sho)),
            u2_bn_molt(wir_r, u2_t(sho), u2_cv_sam, a, 0));  
}

/* _hill_fill_2(): fill two arguments in shoe; type assumed
*/
static u2_noun                                                    //  produce
_hill_fill_2(u2_wire wir_r,
             u2_noun sho,                                         //  retain
             u2_noun a,                                           //  retain
             u2_noun b)                                           //  retain
{
  return u2_bc
    (wir_r, u2_rx(wir_r, u2_h(sho)),
            u2_bn_molt(wir_r, u2_t(sho), u2_cv_sam_2, a, 
                                         u2_cv_sam_3, b,
                                         0));  
}

#if 0
/* _hill_fill_3(): fill three arguments in shoe; type assumed
*/
static u2_noun                                                    //  produce
_hill_fill_3(u2_wire wir_r,
             u2_noun sho,                                         //  retain
             u2_noun a,                                           //  retain
             u2_noun b,                                           //  retain
             u2_noun c)                                           //  retain
{
  return u2_bc
    (wir_r, u2_rx(wir_r, u2_h(sho)),
            u2_bn_molt(wir_r, u2_t(sho), u2_cv_sam_2, a, 
                                         u2_cv_sam_6, b,
                                         u2_cv_sam_7, c,
                                         0));  
}
#endif

/* _hill_print_wall(): print a wall of txt.
*/
static void
_hill_print_wall(u2_wire     wir_r,                               
                 const c3_c* cap_c,                               //  retain
                 u2_noun     wal)                                 //  retain
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

/* _hill_wake(): boot pit, from `[type form]` to `[type noun]`.
*/
static u2_noun                                                    //  produce
_hill_wake(u2_wire wir_r,
           u2_noun gam)                                           //  retain
{
  return u2_bc
    (wir_r, u2_rx(wir_r, u2_h(gam)),
            u2_nk_nock(wir_r, _0, u2_t(gam)));
}

/* _hill_z_mint_gen(): mint `gen` to `[type form]` with PitZ jets.
*/
static u2_noun                                                    //  produce
_hill_z_mint_gen(u2_wire wir_r,
                 u2_noun sut,                                     //  retain
                 u2_noun gol,                                     //  retain
                 u2_noun gen)                                     //  retain
{
  u2_noun gam;
  u2_noun van = u2_bc
    (wir_r, u2_bc(wir_r, 
                  c3__blur,
                  u2_bc(wir_r, u2_bt(wir_r, _0, _0, _0),
                               u2_bc(wir_r, _0, 42))),
            87);

  gam = j2_mcy(PitZ, ut, mint)(wir_r, van, sut, gol, gen);
  u2_rz(wir_r, van);

  return gam;
}

/* _hill_z_mint_txt(): mint `txt` to `[type form]` with PitZ jets.
*/
static u2_noun                                                    //  produce
_hill_z_mint_txt(u2_wire wir_r,
                 u2_noun sut,                                     //  retain
                 u2_noun gol,                                     //  retain
                 u2_atom txt)                                     //  retain
{
  u2_noun gen;

  if ( u2_none == (gen = j2_mbc(PitZ, ream)(wir_r, txt)) ) {
    fprintf(stderr, "{%s: parser failed}\n", FileZ);
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun ret = _hill_z_mint_gen(wir_r, sut, gol, gen);

    u2_rz(wir_r, gen);
    return ret;
  }
}

/* _hill_z_make_gen(): execute gene against shoe.
*/
static hi_shoz                                                    //  produce
_hill_z_make_gen(u2_wire wir_r,
                 hi_shoz sho,                                     //  retain
                 u2_noun gen)                                     //  retain
{
  u2_noun gam = _hill_z_mint_gen(wir_r, u2_h(sho), c3__noun, gen);
  u2_noun pro = u2_nk_nock(wir_r, u2_rx(wir_r, u2_t(sho)), u2_t(gam));
  u2_noun ret = u2_bc(wir_r, u2_rx(wir_r, u2_h(gam)), pro);

  u2_rz(wir_r, gam);
  return ret;
}

/* _hill_z_make_txt(): execute string against shoe.
*/
static hi_shoz                                                    //  produce
_hill_z_make_txt(u2_wire wir_r,
                 hi_shoz sho,                                     //  retain
                 u2_atom txt)                                     //  retain
{
  u2_noun gen, ret;

  if ( u2_none == (gen = j2_mbc(PitZ, ream)(wir_r, txt)) ) {
    fprintf(stderr, "{%s: parser failed}\n", FileZ);
    return u2_bl_bail(wir_r);
  }
  ret = _hill_z_make_gen(wir_r, sho, gen);

  u2_rz(wir_r, gen);
  return ret;
}

/* _hill_z_make_txt_c(): execute string against shoe, producing shoe.
*/
static u2_noun                                                    //  produce
_hill_z_make_txt_c(u2_wire     wir_r,
                   u2_noun     sho,                               //  retain
                   const c3_c* txt_c)                             //  retain
{
  u2_noun txt = u2_bn_string(wir_r, txt_c);
  u2_noun ret = _hill_z_make_txt(wir_r, sho, txt);

  u2_rz(wir_r, txt);
  return ret;
}

/* _hill_z_hang(): instantiate and fill a flat core.
*/
static u2_noun                                                    //  produce
_hill_z_hang(u2_wire     wir_r,
             u2_noun     pit,                                     //  retain
             const c3_c* txt_c,                                   //  retain
             u2_noun     sam)                                     //  retain
{
  u2_noun cor = _hill_z_make_txt_c(wir_r, pit, txt_c);
  u2_noun ret = _hill_fill_1(wir_r, cor, sam);

  u2_rz(wir_r, cor);
  return ret;
}

#if 0
/* _hill_z_call_1(): invoke 1-argument function on core shoe; type assumed
*/
static u2_noun                                                    //  produce
_hill_z_call_1(u2_wire     wir_r,
               hi_shoz     pit,                                   //  retain
               const c3_c* txt_c,                                 //  retain
               u2_noun     a)                                     //  retain
{
  u2_noun cor = _hill_z_make_txt_c(wir_r, pit, txt_c);
  u2_noun lod = _hill_fill_1(wir_r, cor, a);
  u2_noun ret = _hill_z_make_txt_c(wir_r, lod, "$");

  u2_rz(wir_r, cor);
  u2_rz(wir_r, lod);

  return ret;
}
#endif

/* _hill_z_call_2(): invoke 1-argument function on core shoe; type assumed
*/
static u2_noun                                                    //  produce
_hill_z_call_2(u2_wire     wir_r,
               hi_shoz     pit,                                   //  retain 
               const c3_c* txt_c,                                 //  retain
               u2_noun     a,                                     //  retain
               u2_noun     b)                                     //  retain
{
  u2_noun cor = _hill_z_make_txt_c(wir_r, pit, txt_c);
  u2_noun lod = _hill_fill_2(wir_r, cor, a, b);
  u2_noun ret = _hill_z_make_txt_c(wir_r, lod, "$");

  u2_rz(wir_r, cor);
  u2_rz(wir_r, lod);

  return ret;
}

/* _hill_z_boot(): generate kernel A (with Z jets).
*/
static u2_noun                                                    //  produce
_hill_z_boot(u2_wire     wir_r,
             const c3_c* fil_c)                                   //  retain
{
  u2_noun txt = u2_ux_read(wir_r, fil_c, "watt");

  if ( u2_none == txt ) {
    fprintf(stderr, "{not found: %s.watt}\n", fil_c);
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun gam = _hill_z_mint_txt(wir_r, c3__noun, c3__noun, txt); 
    u2_noun soh = _hill_wake(wir_r, gam);

    u2_rz(wir_r, txt);
    u2_rz(wir_r, gam);
    
    return soh;
  }
}

/* _hill_a_mint_gen(): mint `txt` as `[type form]` with PitA shoe.
*/
static u2_noun                                                    //  produce
_hill_a_mint_gen(u2_wire wir_r,
                 hi_shoz soa,                                     //  retain
                 u2_noun sut,                                     //  retain
                 u2_noun gol,                                     //  retain
                 u2_atom gen)                                     //  retain
{
  u2_noun cor = _hill_z_hang(wir_r, soa, "ut", sut);
  u2_noun dog = _hill_z_call_2(wir_r, cor, "mint", gol, gen);
  u2_noun pro = u2_rx(wir_r, u2_t(dog));

  u2_rz(wir_r, cor);
  u2_rz(wir_r, dog);

  return pro;
}

/* _hill_a_mint_txt(): mint `txt` as `[type form]` with PitA shoe.
*/
static u2_noun                                                    //  produce
_hill_a_mint_txt(u2_wire wir_r,
                 hi_shoz soa,                                     //  retain
                 u2_noun sut,                                     //  retain
                 u2_noun gol,                                     //  retain
                 u2_atom txt)                                     //  retain
{
  u2_noun gen;

  if ( u2_none == (gen = j2_mbc(PitA, ream)(wir_r, txt)) ) {
    fprintf(stderr, "{%s: parse failed}\n", FileA);
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun ret = _hill_a_mint_gen(wir_r, soa, sut, gol, gen);

    u2_rz(wir_r, gen);
    return ret;
  }
}

/* _hill_a_make_gen(): execute gene against core.
*/
static hi_shoa                                                    //  produce
_hill_a_make_gen(u2_wire wir_r,
                 hi_shoz soa,                                     //  retain
                 hi_shoa cor,                                     //  retain
                 u2_noun gen)                                     //  retain
{
  u2_noun gam = _hill_a_mint_gen(wir_r, soa, u2_h(cor), c3__noun, gen);
  u2_noun pro = u2_nk_nock(wir_r, u2_rx(wir_r, u2_t(cor)), u2_t(gam));
  u2_noun ret = u2_bc(wir_r, u2_rx(wir_r, u2_h(gam)), pro);

  u2_rz(wir_r, gam);
  return ret;
}

/* _hill_a_make_txt(): execute string against core.
*/
static hi_shoa                                                    //  produce
_hill_a_make_txt(u2_wire wir_r,
                 hi_shoz soa,                                     //  retain
                 hi_shoa cor,                                     //  retain
                 u2_atom txt)                                     //  retain
{
  u2_noun gen, ret;

  if ( u2_none == (gen = j2_mbc(PitZ, ream)(wir_r, txt)) ) {
    fprintf(stderr, "{%s: parser failed}\n", FileZ);
    return u2_bl_bail(wir_r);
  }
  ret = _hill_a_make_gen(wir_r, soa, cor, gen);

  u2_rz(wir_r, gen);
  return ret;
}

/* _hill_a_make_txt_c(): execute string against shoe, producing shoe.
*/
static hi_shoa                                                    //  produce
_hill_a_make_txt_c(u2_wire     wir_r,
                   hi_shoz     soa,                               //  retain
                   hi_shoa     cor,                               //  retain
                   const c3_c* txt_c)                             //  retain
{
  u2_noun txt = u2_bn_string(wir_r, txt_c);
  u2_noun ret = _hill_a_make_txt(wir_r, soa, cor, txt);

  u2_rz(wir_r, txt);
  return ret;
}

/* _hill_a_hang(): instantiate and fill a flat core.
*/
static hi_shoa                                                    //  produce
_hill_a_hang(u2_wire     wir_r,
             hi_shoz     soa,                                     //  retain
             hi_shoa     pit,                                     //  retain
             const c3_c* txt_c,                                   //  retain
             u2_noun     sam)                                     //  retain
{
  u2_noun cor = _hill_a_make_txt_c(wir_r, soa, pit, txt_c);
  u2_noun ret = _hill_fill_1(wir_r, cor, sam);

  u2_rz(wir_r, cor);
  return ret;
}

#if 0
/* _hill_a_call_1(): invoke 1-argument function on core shoe; type assumed
*/
static hi_shoa                                                    //  produce
_hill_a_call_1(u2_wire     wir_r,
               hi_shoz     soa,                                   //  retain
               hi_shoa     pit,                                   //  retain
               const c3_c* txt_c,                                 //  retain
               u2_noun     a)                                     //  retain
{
  u2_noun cor = _hill_a_make_txt_c(wir_r, soa, pit, txt_c);
  u2_noun lod = _hill_fill_1(wir_r, cor, a);
  u2_noun ret = _hill_a_make_txt_c(wir_r, soa, lod, "$");

  u2_rz(wir_r, cor);
  u2_rz(wir_r, lod);

  return ret;
}
#endif

/* _hill_a_call_2(): invoke 1-argument function on core shoe; type assumed
*/
static hi_shoa                                                    //  produce
_hill_a_call_2(u2_wire     wir_r,
               hi_shoz     soa,                                   //  retain
               hi_shoa     pit,                                   //  retain 
               const c3_c* txt_c,                                 //  retain
               u2_noun     a,                                     //  retain
               u2_noun     b)                                     //  retain
{
  u2_noun cor = _hill_a_make_txt_c(wir_r, soa, pit, txt_c);
  u2_noun lod = _hill_fill_2(wir_r, cor, a, b);
  u2_noun ret = _hill_a_make_txt_c(wir_r, soa, lod, "$");

  u2_rz(wir_r, cor);
  u2_rz(wir_r, lod);

  return ret;
}

/* _hill_a_ugly(): dump type with shoe A.
*/
static void
_hill_a_ugly(u2_wire     wir_r,
             hi_shoz     soa,                                     //  retain
             const c3_c* cap_c,                                   //  retain
             u2_noun     typ)                                     //  retain
{
#if 0
  u2_noun nut = _hill_z_make_txt_c(wir_r, soa, "ut");
  u2_noun fut = _hill_fill(wir_r, nut, typ);
  u2_noun fun = _hill_z_make_txt_c(wir_r, fut, "dump");
  u2_noun sam = u2_bc(wir_r, u2_rx(wir_r, gol), u2_rx(wir_r, gen));
  u2_noun dog = _hill_z_post(wir_r, fun, sam);  
  u2_noun pro = u2_rx(wir_r, u2_t(dog));
#else
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
#endif
}

#if 0
/* _hill_a_nice(): pretty-print with shoe A.  Still very crude.
*/
_hill_a_nice(u2_wire     wir_r,
             hi_shoz     soa,                                     //  retain
             const c3_c* cap_c,                                   //  retain
             hi_shob     som)                                     //  retain
{
  u2_noun typ = u2_h(som);
  u2_noun val = u2_t(som);
  {
    _hill_a_ugly(wir_r, soa, cap_c, typ);
    u2_err(wir_r, 
  }
}
#endif

/* _hill_a_boot(): generate kernel B (with kernel A).
*/
static u2_noun                                                    //  produce
_hill_a_boot(u2_wire     wir_r,
             hi_shoz     soa,                                     //  retain
             const c3_c* fil_c)                                   //  retain
{
  u2_noun txt = u2_ux_read(wir_r, fil_c, "watt");

  if ( u2_none == txt ) {
    fprintf(stderr, "{not found: %s.watt}\n", fil_c);
    return u2_bl_bail(wir_r);
  }
  else {
    u2_noun gam = _hill_a_mint_txt(wir_r, soa, c3__noun, c3__noun, txt); 
    u2_noun soh = _hill_wake(wir_r, gam);

    u2_rz(wir_r, txt);
    u2_rz(wir_r, gam);
    
    return soh;
  }
}

/* _hill_a_fire(): execute and print expression over pit B (with shoe A).
*/
static void                                                       //  produce
_hill_a_fire(u2_wire     wir_r,
             u2_noun     soa,                                     //  retain
             u2_noun     sob,                                     //  retain
             const c3_c* exp_c)                                   //  retain
{
  u2_noun txt, gam, som;

  txt = u2_bn_string(wir_r, exp_c);
  gam = _hill_a_mint_txt(wir_r, soa, u2_h(sob), c3__noun, txt);

  _hill_a_ugly(wir_r, soa, 0, u2_h(gam));
  som = u2_nk_nock(wir_r, u2_rx(wir_r, u2_t(sob)), u2_t(gam));

  if ( u2_none == som ) {
    fprintf(stderr, "{none}\n");
  }
  else {
    u2_err(wir_r, 0, som);
  }
  u2_rz(wir_r, txt);
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

          soa = _hill_z_boot(wir_r, FileA);
        }
      }
      fprintf(stderr, "{hard boot: %s, with %s jets}\n", FileA, FileZ);

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

          sob = _hill_a_boot(wir_r, soa, FileB);
        }
      }
      fprintf(stderr, "{soft boot: %s, with %s}\n", FileB, FileA);

      u2_bx_spot(wir_r, u2_nul);
      u2_bx_show(wir_r);

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
  hi_shoa soa   = hil_h->soa;
  hi_shoz sob   = hil_h->sob;

  u2_bx_boot(wir_r);
  u2_bx_spot(wir_r, u2_nul);

  _hill_a_fire(wir_r, soa, sob, lin_c);

  LoomStop = 0;
  u2_bx_show(wir_r);
}
