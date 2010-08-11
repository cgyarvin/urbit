/* c/vere.c
**
** This file is in the public domain.
*/
#include <sys/stat.h>
#include <fcntl.h>
#include "all.h"

  /**   Central data structures.
  **/
    /*  struct vere_gate: a typed gate.
    */
      struct vere_gate {
        /*  cor: core
        */
        u3_fox cor;

        /*  typ: type
        */
        u3_fox typ;
      };

    /*  struct vere_state: vere application state.
    */
      struct vere_state {
        /*  Z - the Nock engine.
        */
        u3_z    z;

        /*  Watt - the raw kernel.  Initialized at boot.
        */
        u3_fox  wot;

        /*  Kernel soul - [p=*type q=*].
        */
        struct {
          u3_fox  p;
          u3_fox  q;
        } kul;

        /*  Gates and other cores.
        */
        struct {
          /*  "read:plow:!%"
          */
          u3_fox  rad;

          /*  =>  !% 
          **  =+  [p=*type:plow q=*gene:plow] 
          **  |=
          **  (%~(mill rose:plow sut p) q)
          */
          u3_fox  mel;
        } g;

        /*  New main app - vere.
        */
        struct {
          /*  App core as soul.
          */
          u3_fox  sod;

          /*  Gate formulas (on sod).
          */
          struct {
            /*  par: parse line to [knob sink well]
            */
            u3_fox  par;

            /*  fab: compute well to soul
            */
            u3_fox  fab;

            /*  hom: sink and soul to core and merds
            */
            u3_fox  hom;
          } g;
        } m;

        /*  Exception control.
        */
        struct {
          /*  Jump buffer for all line exceptions.
          */
          jmp_buf   buf_jmp;
        } x;
      };

  /**   Global variables.
  **/
  struct vere_state ver;

  /**   Internal (temporary) functions.
  **/
    static void
    _vere_dump_in(u3_z z, FILE *fil, u3_fox nun);
    static void
    _vere_dump(u3_z z, FILE *fil, u3_fox nun);
    static u3_fox
    _vere_scan_cell(u3_z z, FILE *fil);
    static u3_fox
    _vere_scan(u3_z z, FILE *fil);

#if 0
/*  _vere_x_does(): push a debugging context.
*/
static void
_vere_x_does(struct vere_state*   v,
             const c3_c*          txt)
{
}

/*  _vere_x_done(): push a debugging context.
*/
static void
_vere_x_done(struct vere_state*   v)
{
}
#endif

/*  _vere_x_fail(): return to top.
*/
static u3_fox
_vere_x_fail(struct vere_state*   v)
{
  longjmp(v->x.buf_jmp, 1);
  return u3_none;
}

/*  _vere_x_use(): turn fox to rat.
*/
static u3_fox
_vere_x_use(struct vere_state*    v,
            u3_rat                rat)
{
  if ( u3_none == rat ) {
    return _vere_x_fail(v);
  }
  else return rat;
}

/*  _vere_nc()::
*/
static u3_fox
_vere_nc(struct vere_state*   v,
         u3_fox               hed,
         u3_fox               tal)
{
  return _vere_x_use(v, u3_ln_cell(v->z, hed, tal));
}

/*  _vere_ns()::
*/
static u3_fox
_vere_ns(struct vere_state*   v,
         const c3_c*          txt_c)
{
  return _vere_x_use(v, u3_ln_string(v->z, txt_c));
}

/*  _vere_h()::
*/
static u3_fox
_vere_h(struct vere_state*  v,
        u3_fox              sel)
{
  if ( u3_yes == u3_lr_dust(v->z, sel) ) {
    return u3_h(v->z, sel);
  } else return _vere_x_fail(v);
}

/*  _vere_t()::
*/
static u3_fox
_vere_t(struct vere_state*  v,
        u3_fox              sel)
{
  if ( u3_yes == u3_lr_dust(v->z, sel) ) {
    return u3_t(v->z, sel);
  } else return _vere_x_fail(v);
}

/* _vere_file():
**
**  Load the path (pah)  as an atom.
*/
u3_fox
_vere_file(u3_z         z,
           const c3_c*  c_pah)
{
  c3_i        i_fid = open(c_pah, O_RDONLY, 0666);
  struct stat sta;
  uint32_t    siz;
  uint8_t     *buf;
  u3_fox     dat; 

  if ( (i_fid < 0) || (fstat(i_fid, &sta) < 0) ) {
    perror(c_pah);
    exit(1);
  }

  siz = sta.st_size;
  buf = malloc(sta.st_size);

  if ( siz != read(i_fid, buf, siz) ) {
    perror(c_pah);
    exit(1);
  }
  close(i_fid);

  dat = u3_ln_bytes(z, siz, buf);
  free(buf);

  return dat;
}

/* Return true iff (atom) is an ASCII string of (3) or more bytes,
** using no characters besides a-z and -.
*/
static uint8_t
_vere_term(u3_z z,
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

/* _vere_dump_in(): dump in cell.
*/
static void
_vere_dump_in(u3_z z,
              FILE       *fil,
              u3_fox    nun)
{
  if ( u3_no == u3_lr_dust(z, nun) ) {
    _vere_dump(z, fil, nun);
  }
  else {
    _vere_dump(z, fil, u3_h(z, nun));
    fprintf(fil, " ");
    _vere_dump_in(z, fil, u3_t(z, nun));
  }
}

/* vere_dump(): dump noun to file.
*/
void
_vere_dump(u3_z z,
           FILE       *fil,
           u3_fox    nun)
{
  if ( u3_no == u3_lr_dust(z, nun) ) {
    mpz_t amp;

    if ( _vere_term(z, nun, 2) ) {
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
    _vere_dump(z, fil, u3_h(z, nun));
    fprintf(fil, " ");
    _vere_dump_in(z, fil, u3_t(z, nun));
    fputc(']', fil);
  }
}

/* _vere_scan_cell(): scan cell or tuple.
*/
static u3_fox
_vere_scan_cell(u3_z z, 
                FILE       *fil)
{
  u3_fox hed = _vere_scan(z, fil);
  int     c   = fgetc(fil);

  if ( c == ' ' ) {
    u3_fox tal = _vere_scan_cell(z, fil);

    return u3_ln_cell(z, hed, tal);
  }
  else { 
    assert(c == ']');
    return hed;
  }
}

/* _vere_scan(): scan noun from file.
*/
static u3_fox
_vere_scan(u3_z z,
           FILE       *fil)
{
  int c = fgetc(fil);

  if ( c == '[' ) {
    return _vere_scan_cell(z, fil);
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

/* _vere_init_read():
**
**   Compile source text to watt gene.
**
**    src: source text, as atom
*/
u3_fox
_vere_init_read(u3_z    z,
                u3_fox  src)
{
  u3_rat rat = u3_b_read(&z->l, src);

  if ( u3_l_none == rat ) {
    fprintf(stderr, "boot parse failed\n");
    exit(1);
  }
  return rat;
}

/* _vere_init_make():
**
**   Compile source text to watt gene.
**
**    src: source text, as atom
*/
u3_fox
_vere_init_make(u3_z    z,
                u3_fox  gen)
{
  u3_mote how;
  u3_rat  rat = u3_b_pass(&z->l, c3__blur, gen, &how);

  if ( u3_l_none == rat ) {
    fprintf(stderr, "boot make failed\n");
    exit(1);
  }
  return rat;
}

/*  _vere_kernel(): load the kernel.
*/
u3_fox
_vere_kernel(u3_z         z,
             const c3_c*  c_pod,
             const c3_c*  c_pax)
{
  FILE *fil;
  u3_fox ker;

  if ( !(fil = fopen(c_pax, "r")) ) {
    u3_fox src, gen, ker;

    printf("[vere: building kernel: %s]\n", c_pod);

    src = _vere_file(z, c_pod);
    gen = _vere_init_read(z, src);
    ker = _vere_init_make(z, gen);

    if ( !(fil = fopen(c_pax, "w")) ) {
      perror(c_pax);
      exit(1);
    }
    _vere_dump(z, fil, ker);
     printf("[saved kernel: %s]\n", c_pax);
    fclose(fil);

#if 0
    {
      u3_fox hec;

      printf("[loading: %s]\n", c_pax);
      if ( !(fil = fopen(c_pax, "r")) ) {
        perror(pax);
        exit(1);
      }
      hec = _vere_scan(z, fil);
      fclose(fil);

      if ( u3_yes == u3_lr_eq(z, hec, ker) ) {
        printf("[match]\n");
      } else printf("no match!\n");
    }
#endif
    return ker;
  }
  else {
    ker = _vere_scan(z, fil);
    printf("[vere: loaded kernel: %s]\n", c_pax);

    fclose(fil);
    return ker;
  }
}

/*  _vere_nock()::
*/
static u3_fox
_vere_nock(struct vere_state*   v,
           u3_fox               bus,
           u3_fox               fol,
           c3_b                 mar_b)
{
  /*  bus:  subject
  **  fol:  formula
  **  res:  rekult
  **  pro:  product
  */
  u3_fox res, pro;
  struct u3_z_bench naq;

  res = u3_z_run(v->z, &pro, bus, fol, mar_b ? &naq : 0);
  if ( 0 == res ) {
    if ( mar_b ) {
      fprintf(stderr, " <%lld steps, %d words>\n",
              naq.d_ruy,
              (naq.w_maz - naq.w_vil) + (naq.w_buc - naq.w_tew));
    }
    return pro;
  }
  else {
    c3_c c_buf[5];

    u3_lr_bytes(v->z, 0, 5, (c3_y *)c_buf, res);
    fprintf(stderr, "[%s]\n", c_buf);
 
    return _vere_x_fail(v);
  }
}

/*  _vere_mung()::
*/
static u3_fox
_vere_mung(struct vere_state*   v,
           u3_fox               gat,
           u3_fox               sam,
           c3_b                 mar_b)
{
  u3_fox res, pro;
  struct u3_z_bench naq;

  res = u3_z_mung(v->z, &pro, gat, sam, mar_b ? &naq : 0);
  if ( 0 == res ) {
    if ( mar_b ) {
      fprintf(stderr, " <%lld steps, %d words>\n",
              naq.d_ruy,
              (naq.w_maz - naq.w_vil) + (naq.w_buc - naq.w_tew));
    }
    return pro;
  }
  else {
    c3_c c_buf[5];

    u3_lr_bytes(v->z, 0, 5, (c3_y *)c_buf, res);
    fprintf(stderr, "[%s]\n", c_buf);
    
    return _vere_x_fail(v);
  }
}

/*  _vere_kick():  boot make, typeless; to formula
*/
static u3_fox
_vere_kick(struct vere_state*  v,
           u3_fox              des)
{
  return _vere_nock(v, des, v->wot, 0);
}

/*  _vere_load():  kick and nock; produces gate or core
*/
static u3_fox
_vere_load(struct vere_state*  v,
           u3_fox              des)
{
  return _vere_nock(v, 0, _vere_kick(v, des), 0);
}

/*  _vere_load_c():  load immediate string.
*/
static u3_fox
_vere_load_c(struct vere_state*   v,
             const c3_c*          c_des)
{
  return _vere_load(v, _vere_ns(v, c_des));
}

/*  _vere_mill():  load and mill text, with the kernel miller.
*/
static u3_fox
_vere_mill(struct vere_state*   v,
           u3_fox               sut,
           u3_fox               des)
{
  u3_fox gen = _vere_mung(v, v->g.rad, des, 0);
  u3_fox lof = _vere_mung(v, v->g.mel, _vere_nc(v, sut, gen), 0);

  return lof;
}

/*  _vere_make():  make text, with the kernel miller.
*/
static u3_fox
_vere_make(struct vere_state*   v,
           u3_fox               sut,
           u3_fox               des)
{
  u3_fox gen = _vere_mung(v, v->g.rad, des, 0);
  u3_fox lof = _vere_mung(v, v->g.mel, _vere_nc(v, sut, gen), 0);

  return _vere_t(v, lof);
}

/*  _vere_fire(): fire text to soul, against the kernel soul (kul).
*/
static u3_fox
_vere_fire(struct vere_state*   v,
           u3_fox               des)
{
  u3_fox lof = _vere_mill(v, v->kul.p, des);

  return _vere_nc
    (v, _vere_h(v, lof), 
        _vere_nock(v, v->kul.q, _vere_t(v, lof), 0));
}

#if 0
/*  _vere_gear_c(): gate from soul
*/
static u3_fox
_vere_gear_c(struct vere_state*   v,
             u3_fox               sul,
             c3_c*                des_c)
{
  u3_fox lof = _vere_mill(v, _vere_h(v, sul), _vere_ns(v, des_c));

  return _vere_nock(v, _vere_t(v, sul), _vere_t(v, lof), 0);
}
#endif

#if 0
/* _vere_load_path():   load C path.
*/
static u3_fox
_vere_load_path(struct vere_state*  v,
                const c3_c*         c_pah)
{
  return _vere_load(v, _vere_file(v->z, c_pah));
}
#endif

#if 0
/*  _vere_watt_pass():  pass (make and show)
*/
static u3_fox
_vere_watt_pass(struct vere_state *v,
                u3_fox            sut,
                const c3_c        *src)
{
}

/*  _vere_watt_make():  mill (play, make, show)
*/
static u3_fox
_vere_watt_mill(struct vere_state *v,
                u3_fox            sut,
                const c3_c        *src)
{
}

#endif

/*  _vere_shell():  load the shell.
*/
u3_fox
_vere_shell(struct vere_state*  v,
            const c3_c*         c_pod,
            const c3_c*         c_pax)
{
  return _vere_fire(v, _vere_file(v->z, c_pod));
}

void *
vere_boot(int siz)
{
  struct vere_state *v = malloc(sizeof(struct vere_state));

  u3_b_init();

  if ( setjmp(v->x.buf_jmp) ) {
    fprintf(stderr, "boot: fail\n");
    exit(1);
  }

  /*  Load the kernel itself.  XX: jets from the outside.
  **
  **  XX: this whole sequence is wrong.  It is made complicated
  **  by the fact that the fake compiler can't jet !%, and punts 
  **  in a way that is exponentially slow!
  */
  {
    v->z = u3_z_new(siz);
    v->wot = _vere_kernel(v->z, "watt/watt.watt", "watt/297.nock");
  }

  /*  Create the kernel soul.
  */
  {
    v->kul.p = _vere_load_c(v, "seed:plow:!%");
    v->kul.q = _vere_load_c(v, "!%");
  }

  /*  Basic metacircular gates: read and mill.
  **
  **  XX: note that the mel load is perceptibly slow due to the
  **  aforementioned problems with |%.
  */
  {
    v->g.rad = _vere_load_c(v, "read:plow:!%");

    v->g.mel = _vere_load_c(v, 
      "=>(!% =+([p=*type:plow q=*gene:plow] |=((%~(mill rose:plow sut p) q))))"
    );
  }

#if 1
  /*  Load vere, the new shell.
  */
  printf("[vere: building shell: watt/vere.watt]\n");
  {
    v->m.sod = _vere_shell(v, "watt/vere.watt", "watt/vere.nock");

    v->m.g.par = _vere_make(v, _vere_h(v, v->m.sod), _vere_ns(v, "spar"));
    v->m.g.fab = _vere_make(v, _vere_h(v, v->m.sod), _vere_ns(v, "glem"));
    v->m.g.hom = _vere_make(v, _vere_h(v, v->m.sod), _vere_ns(v, "blor"));
  }
  printf("[vere: loaded shell: watt/vere.watt]\n");
#endif
  return v;
}

void
_vere_spit(struct vere_state*   v,
           u3_fox               poz)
{
  if ( 0 != poz ) {
    u3_fox i_poz = _vere_h(v, poz);
    u3_fox t_poz = _vere_t(v, poz);

    switch ( _vere_h(v, i_poz) ) {
      case c3__turd: {
        u3_fox rol = _vere_t(v, i_poz);
        u3_fox typ = _vere_h(v, rol);
        u3_fox pro = _vere_t(v, rol);

        u3_b_print_type(v->z, 0, typ);
        u3_b_print(v->z, 0, pro);

        break;
      }
      default: _vere_x_fail(v);
    }
    _vere_spit(v, t_poz);
  }
}

void 
vere_line(void *vere, const c3_c *line)
{
  struct vere_state*  v=vere;
  const c3_c*         lin_c=line;

  if ( setjmp(v->x.buf_jmp) ) {
    fprintf(stderr, "line: fail\n");
  }
  else {
#if 0
    /*  lin:  line, input
    **  fex:  gene, parsed line
    **  rol:  soul, generated line
    */
    u3_fox lin = _vere_ns(v, lin_c);
    u3_fox fex = _vere_mung(v, v->a.g.par, lin, 0);
    {
      // u3_b_print(v->z, "fex", fex);

      u3_fox rol = _vere_mung(v, v->a.g.tog, fex, 0);
      u3_fox typ = _vere_h(v, rol);
      u3_fox pro = _vere_t(v, rol);

      u3_b_print_type(v->z, 0, typ);
      u3_b_print(v->z, 0, pro);
    }
#else
    {
      /*  lin:  raw line
      **  par:  gate, parse
      **  fab:  gate, apply well
      **  hom:  gate, apply sink
      **  piq:  parsed line
      **  nob:  knob
      **  syn:  sink
      **  wol:  well
      **  mal:  soul from well
      **  tif:  output and new state 
      */
      u3_fox lin = _vere_ns(v, lin_c);
      u3_fox par = _vere_nock(v, _vere_t(v, v->m.sod), v->m.g.par, 0);
      u3_fox fab = _vere_nock(v, _vere_t(v, v->m.sod), v->m.g.fab, 0);
      u3_fox hom = _vere_nock(v, _vere_t(v, v->m.sod), v->m.g.hom, 0);
      u3_fox piq = _vere_mung(v, par, lin, 0);
      // u3_fox nob = _vere_h(v, piq);
      u3_fox syn = _vere_h(v, _vere_t(v, piq));
      u3_fox wol = _vere_t(v, _vere_t(v, piq));
      u3_fox mal = _vere_mung(v, fab, wol, 0);
      u3_fox tif = _vere_mung(v, hom, _vere_nc(v, syn, mal), 0);

      v->m.sod = _vere_nc(v, _vere_h(v, v->m.sod), _vere_h(v, tif));
      _vere_spit(v, _vere_t(v, tif));
    }
#endif
  }
}
