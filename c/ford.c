/* c/ford.c
**
** This file is in the public domain.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include "all.h"

  struct ford_gate {
    /*  cor: core
    */
    u3_fox cor;

    /*  typ: type
    */
    u3_fox typ;
  };

  struct ford_state {
    /*  Z - the Nock engine.
    */
    u3_z  z;

    /*  Watt.  Initialized at boot.
    */
    struct {
      /*  wot:  kernel formula ("file C").
      */
      u3_fox  wot;

      /*  wad:  kernel core.
      */
      u3_fox  wad;

      /*  wyp:  kernel type.
      */
      u3_fox  wyp;
    } w;

    /*  Gates.  Subject for all gates is kernel.
    */
    struct {
      /*  Toy: decrement.
      */
      struct ford_gate duc;

      /*  Watt miller.
      */
      struct ford_gate myl;

      /* Command-line decoder.
      */
      struct ford_gate lun;
    } g;

    /*  Structures.
    */
    struct {
      /*  Rolling state.
      */
      u3_fox gut;

      /*  Type of rolling state.
      */
      u3_fox lec;
    } s;

  };
  struct ford_state ver;

  /* Watt code.
  */

  /** Dumb scanning and dumping.
  **/
    static void
    _ford_dump_in(u3_z z, FILE *fil, u3_fox nun);
    static void
    _ford_dump(u3_z z, FILE *fil, u3_fox nun);
    static u3_fox
    _ford_scan_cell(u3_z z, FILE *fil);
    static u3_fox
    _ford_scan(u3_z z, FILE *fil);

/* _ford_file():
**
**  Load the path (pah)  as an atom.
*/
u3_fox
_ford_file(u3_z       z,
           const char *pah)
{
  int         fid = open(pah, O_RDONLY, 0666);
  struct stat sta;
  uint32_t    siz;
  uint8_t     *buf;
  u3_fox     dat; 

  if ( (fid < 0) || (fstat(fid, &sta) < 0) ) {
    perror(pah);
    exit(1);
  }

  siz = sta.st_size;
  buf = malloc(sta.st_size);

  if ( siz != read(fid, buf, siz) ) {
    perror(pah);
    exit(1);
  }
  close(fid);

  dat = u3_ln_bytes(z, siz, buf);
  free(buf);

  return dat;
}

/* Return true iff (atom) is an ASCII string of (3) or more bytes,
** using no characters besides a-z and -.
*/
static uint8_t
_ford_term(u3_z z,
           u3_fox    tat,
           uint32_t   qb)
{
  uint32_t sb = u3_lr_bin(z, 3, tat);

  if ( sb >= qb) {
    uint8_t *xb = alloca(sb);
    uint32_t i;

    u3_lr_bytes(z, 0, sb, xb, tat);

    for ( i=0; i < sb; i++ ) {
      if ( ((xb[i] < 'a') || (xb[i] > 'z')) && (xb[i] != '-') ) {
        return 0;
      }
    }
    return 1;
  }
  else return 0;
}

/* _ford_dump_in(): dump in cell.
*/
static void
_ford_dump_in(u3_z z,
              FILE       *fil,
              u3_fox    nun)
{
  if ( u3_no == u3_lr_dust(z, nun) ) {
    _ford_dump(z, fil, nun);
  }
  else {
    _ford_dump(z, fil, u3_h(z, nun));
    fprintf(fil, " ");
    _ford_dump_in(z, fil, u3_t(z, nun));
  }
}

/* ford_dump(): dump noun to file.
*/
void
_ford_dump(u3_z z,
           FILE       *fil,
           u3_fox    nun)
{
  if ( u3_no == u3_lr_dust(z, nun) ) {
    mpz_t amp;

    if ( _ford_term(z, nun, 2) ) {
      uint32_t sb = u3_lr_bin(z, 3, nun);
      uint8_t *xb = alloca(sb + 1);

      u3_lr_bytes(z, 0, sb, xb, nun);
      xb[sb] = 0;
      fprintf(fil, "%%%s", xb);
    }
    else {
      u3_lr_mp(z, amp, nun);
      gmp_fprintf(fil, "%Zd", amp);
      mpz_clear(amp);
    }
  }
  else {
    fputc('[', fil);
    _ford_dump(z, fil, u3_h(z, nun));
    fprintf(fil, " ");
    _ford_dump_in(z, fil, u3_t(z, nun));
    fputc(']', fil);
  }
}

/* _ford_scan_cell(): scan cell or tuple.
*/
static u3_fox
_ford_scan_cell(u3_z z, 
                FILE       *fil)
{
  u3_fox hed = _ford_scan(z, fil);
  int     c   = fgetc(fil);

  if ( c == ' ' ) {
    u3_fox tal = _ford_scan_cell(z, fil);

    return u3_ln_cell(z, hed, tal);
  }
  else { 
    assert(c == ']');
    return hed;
  }
}

/* _ford_scan(): scan noun from file.
*/
static u3_fox
_ford_scan(u3_z z,
           FILE       *fil)
{
  int c = fgetc(fil);

  if ( c == '[' ) {
    return _ford_scan_cell(z, fil);
  } 
  else if ( c == '%' )  {
    char buf[1025];

    fscanf(fil, "%1024[a-z-]", buf);
    return u3_ln_string(z, buf);
  }
#if 0
    mpz_t amp;

    mpz_init(amp);
    while ( 1 ) {
      c=fgetc(fil);

      if ( (c == '-') || ((c >= 'a') && (c <= 'z')) ) {
        mpz_mul_ui(amp, amp, 256);
        mpz_add_ui(amp, amp, c);
      }
      else {
        ungetc(c, fil);

        return uz_k_mp(z, amp);
      }
    }
#endif
  else {
    mpz_t amp;

    ungetc(c, fil);
    mpz_init(amp);
    gmp_fscanf(fil, "%Zd", amp);
    return u3_ln_mp(z, amp);
  }
}

/* _ford_watt:
**
**   Compile source text to watt gene.
**
**    src: source text, as atom
*/
u3_fox
_ford_watt(u3_z    z,
           u3_fox  src)
{
  u3_rat rat = u3_b_watt(&z->l, src);

  if ( u3_l_none == rat ) {
    fprintf(stderr, "boot parse failed\n");
    exit(1);
  }
  return rat;
}

/* _ford_init:
**
**   Compile source text to watt gene.
**
**    src: source text, as atom
*/
u3_fox
_ford_init(u3_z    z,
           u3_fox  gen)
{
  u3_rat rat = u3_b_make(&z->l, c3__blur, gen);

  if ( u3_l_none == rat ) {
    fprintf(stderr, "boot make failed\n");
    exit(1);
  }
  return rat;
}

u3_fox
_ford_kernel(u3_z z,
             const char *pod,
             const char *pax)
{
  FILE *fil;
  u3_fox ker;

  if ( !(fil = fopen(pax, "r")) ) {
    u3_fox src, gen, ker;

    printf("[rebuilding kernel]\n");

    src = _ford_file(z, pod);
    gen = _ford_watt(z, src);
    ker = _ford_init(z, gen);

    if ( !(fil = fopen(pax, "w")) ) {
      perror(pax);
      exit(1);
    }
    _ford_dump(z, fil, ker);
     printf("[saved: %s]\n", pax);
    fclose(fil);

#if 0
    {
      u3_fox hec;

      printf("[loading: %s]\n", pax);
      if ( !(fil = fopen(pax, "r")) ) {
        perror(pax);
        exit(1);
      }
      hec = _ford_scan(z, fil);
      fclose(fil);

      if ( u3_yes == u3_lr_eq(z, hec, ker) ) {
        printf("[match]\n");
      } else printf("no match!\n");
    }
#endif
    return ker;
  }
  else {
    printf("[loading: %s]\n", pax);

    ker = _ford_scan(z, fil);
    fclose(fil);
    return ker;
  }
}

/*  _ford_watt_boot():  boot make, typeless
*/
static u3_fox
_ford_watt_boot(struct ford_state *ver,
                const c3_c        *src)
{
}

/*  _ford_watt_pass():  pass (make and show)
*/
static u3_fox
_ford_watt_pass(struct ford_state *ver,
                u3_fox            sut,
                const c3_c        *src)
{
}

/*  _ford_watt_make():  mill (play, make, show)
*/
static u3_fox
_ford_watt_mill(struct ford_state *ver,
                u3_fox            sut,
                const c3_c        *src)
{
}

void *
ford_boot(int siz)
{
  struct ford_state *state = malloc(sizeof(struct ford_state));

  u3_b_init();

  /*  Load the kernel itself.  XX: add jets.
  */
  {
    state->z = u3_z_new(siz);
    state->w.wot = _ford_kernel(state->z, "watt/watt.watt", "watt/298.nock");
  }

  /*  Load the kernel core, which we'll actually use.
  */

  exit(0);
}

extern void 
ford_line(void *ford, char *line)
{
  exit(1);
}

