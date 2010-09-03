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
        /*  xeno - the old Nock engine.
        */
        u3_x    x;

        /*  zeno - the new Nock engine.
        */
        u3_z    z;

        /*  Watt - the kernel noun.  Initialixed at boot.
        */
        u3_fox  wot;

        /*  True iff the kernel is new.  Forces shell reload.
        */
        c3_b    new_b;

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

        /*  Eqception control.
        */
        struct {
          /*  Jump buffer for all line eqceptions.
          */
          jmp_buf   buf_jmp;
        } q;
      };

  /**   Global variables.
  **/
  struct vere_state ver;

  /**   Internal (temporary) functions.
  **/
    static void
    _vere_dump_in(u3_x x, FILE *fil, u3_fox nun);
    static void
    _vere_dump(u3_x x, FILE *fil, u3_fox nun);
    static u3_fox
    _vere_scan_cell(u3_x x, FILE *fil);
    static u3_fox
    _vere_scan(u3_x x, FILE *fil);

#if 0
/*  _vere_q_does(): push a debugging context.
*/
static void
_vere_q_does(struct vere_state* v,
             const c3_c*        tqt)
{
}

/*  _vere_q_done(): push a debugging context.
*/
static void
_vere_q_done(struct vere_state* v)
{
}
#endif

/*  _vere_q_fail(): return to top.
*/
static u3_fox
_vere_q_fail(struct vere_state* v)
{
  longjmp(v->q.buf_jmp, 1);
  return u3_none;
}

/*  _vere_q_use(): turn fox to rat.
*/
static u3_fox
_vere_q_use(struct vere_state* v,
            u3_rat             rat)
{
  if ( u3_none == rat ) {
    return _vere_q_fail(v);
  }
  else return rat;
}

/*  _vere_nc()::
*/
static u3_fox
_vere_nc(struct vere_state* v,
         u3_fox             hed,
         u3_fox             tal)
{
  return _vere_q_use(v, u3_ln_cell(v->x, hed, tal));
}

/*  _vere_nt()::
*/
static u3_fox
_vere_nt(struct vere_state* v,
         u3_fox             one,
         u3_fox             two,
         u3_fox             tri)
{
  return _vere_nc(v, one, _vere_nc(v, two, tri));
}

/*  _vere_ns()::
*/
static u3_fox
_vere_ns(struct vere_state* v,
         const c3_c*        tqt_c)
{
  return _vere_q_use(v, u3_ln_string(v->x, tqt_c));
}

/*  _vere_h()::
*/
static u3_fox
_vere_h(struct vere_state* v,
        u3_fox             sel)
{
  if ( u3_yes == u3_lr_dust(v->x, sel) ) {
    return u3_h(v->x, sel);
  } else return _vere_q_fail(v);
}

/*  _vere_t()::
*/
static u3_fox
_vere_t(struct vere_state* v,
        u3_fox             sel)
{
  if ( u3_yes == u3_lr_dust(v->x, sel) ) {
    return u3_t(v->x, sel);
  } else return _vere_q_fail(v);
}

/* _vere_file():
**
**  Load the path (pah)  as an atom.
*/
u3_fox
_vere_file(u3_x         x,
           const c3_c*  pah_c)
{
  c3_i        fid_i = open(pah_c, O_RDONLY, 0666);
  struct stat soq_stat;
  c3_w        siz_w;
  uint8_t     *buf;
  u3_fox     dat; 

  if ( (fid_i < 0) || (fstat(fid_i, &soq_stat) < 0) ) {
    perror(pah_c);
    exit(1);
  }

  siz_w = soq_stat.st_size;
  buf = malloc(soq_stat.st_size);

  if ( siz_w != read(fid_i, buf, siz_w) ) {
    perror(pah_c);
    exit(1);
  }
  close(fid_i);

  dat = u3_ln_bytes(x, siz_w, buf);
  free(buf);

  return dat;
}

/* Return true iff (atom) is an ASCII string of (3) or more bytes,
** using no characters besides a-x and -.
*/
static uint8_t
_vere_term(u3_x x,
           u3_fox    tat,
           uint32_t   qb)
{
  uint32_t sb = u3_lr_bin(x, 3, tat);

  if ( sb >= qb) {
    uint8_t *qb = alloca(sb);
    uint32_t i;

    u3_lr_bytes(x, 0, sb, qb, tat);

    for ( i=0; i < sb; i++ ) {
      if ( ((qb[i] < 'a') || (qb[i] > 'x')) && (qb[i] != '-') ) {
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
_vere_dump_in(u3_x x,
              FILE       *fil,
              u3_fox    nun)
{
  if ( u3_no == u3_lr_dust(x, nun) ) {
    _vere_dump(x, fil, nun);
  }
  else {
    _vere_dump(x, fil, u3_h(x, nun));
    fprintf(fil, " ");
    _vere_dump_in(x, fil, u3_t(x, nun));
  }
}

/* vere_dump(): dump noun to file.
*/
void
_vere_dump(u3_x x,
           FILE       *fil,
           u3_fox    nun)
{
  if ( u3_no == u3_lr_dust(x, nun) ) {
    mpz_t amp;

    if ( _vere_term(x, nun, 2) ) {
      uint32_t sb = u3_lr_bin(x, 3, nun);
      uint8_t *qb = alloca(sb + 1);

      u3_lr_bytes(x, 0, sb, qb, nun);
      qb[sb] = 0;
      fprintf(fil, "%%%s", qb);
    }
    else {
      u3_lr_mp(x, amp, nun);
      gmp_fprintf(fil, "%Zd", amp);
      mpz_clear(amp);
    }
  }
  else {
    fputc('[', fil);
    _vere_dump(x, fil, u3_h(x, nun));
    fprintf(fil, " ");
    _vere_dump_in(x, fil, u3_t(x, nun));
    fputc(']', fil);
  }
}

/* _vere_scan_cell(): scan cell or tuple.
*/
static u3_fox
_vere_scan_cell(u3_x x, 
                FILE       *fil)
{
  u3_fox hed = _vere_scan(x, fil);
  int     c   = fgetc(fil);

  if ( c == ' ' ) {
    u3_fox tal = _vere_scan_cell(x, fil);

    return u3_ln_cell(x, hed, tal);
  }
  else { 
    assert(c == ']');
    return hed;
  }
}

/* _vere_scan(): scan noun from file.
*/
static u3_fox
_vere_scan(u3_x x,
           FILE       *fil)
{
  int c = fgetc(fil);

  if ( c == '[' ) {
    return _vere_scan_cell(x, fil);
  } 
  else if ( c == '%' )  {
    char buf[1025];

    fscanf(fil, "%1024[a-z-]", buf);
    return u3_ln_string(x, buf);
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

        return ux_k_mp(x, amp);
      }
    }
#endif
  else {
    mpz_t amp;

    ungetc(c, fil);
    mpz_init(amp);
    gmp_fscanf(fil, "%Zd", amp);
    return u3_ln_mp(x, amp);
  }
}

/* _vere_init_read():
**
**   Compile source text to watt gene.
**
**    src: source text, as atom
*/
u3_fox
_vere_init_read(u3_x    x,
                u3_fox  src)
{
  u3_rat rat = u3_b_read(&x->l, src);

  if ( u3_none == rat ) {
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
_vere_init_make(u3_x    x,
                u3_fox  gen)
{
  u3_mote how;
  u3_rat  rat = u3_b_pass(&x->l, c3__blur, gen, &how);

  if ( u3_none == rat ) {
    fprintf(stderr, "boot make failed\n");
    exit(1);
  }
  return rat;
}

/*  _vere_kernel(): load the kernel.
*/
void
_vere_kernel(struct vere_state*   v,
             const c3_c*          pod_c,
             const c3_c*          paq_c)
{
  struct stat pod_stat, paq_stat;

  if ( stat(pod_c, &pod_stat) < 0 ) {
    perror(pod_c);
    exit(1);
  }
  else {
    if ( (stat(paq_c, &paq_stat) < 0) ||
         (pod_stat.st_mtimespec.tv_sec > paq_stat.st_mtimespec.tv_sec) ||
         ((pod_stat.st_mtimespec.tv_sec == (pod_stat.st_mtimespec.tv_sec)) &&
          (pod_stat.st_mtimespec.tv_nsec > paq_stat.st_mtimespec.tv_nsec)) )
    {
      FILE *fil;
      u3_fox src, gen, ker;

      printf("[vere: building kernel: %s]\n", pod_c);

      src = _vere_file(v->x, pod_c);
      gen = _vere_init_read(v->x, src);
      ker = _vere_init_make(v->x, gen);

      if ( !(fil = fopen(paq_c, "w")) ) {
        perror(paq_c);
        exit(1);
      }
      _vere_dump(v->x, fil, ker);
       printf("[saved kernel: %s]\n", paq_c);
      fclose(fil);

      v->wot = ker;
      v->new_b = 1;
    }
    else {
      FILE *fil;
      u3_fox ker;

      if ( !(fil = fopen(paq_c, "r")) ) {
        perror(paq_c);
        exit(1);
      }
      ker = _vere_scan(v->x, fil);
      printf("[vere: loaded kernel: %s]\n", paq_c);

      fclose(fil);
      v->wot = ker;
      v->new_b = 0;
    }
  }
}

/*  _vere_nock()::
*/
static u3_fox
_vere_nock(struct vere_state* v,
           u3_fox             bus,
           u3_fox             fol,
           c3_b               mar_b)
{
  /*  bus:  subject
  **  fol:  formula
  **  res:  result
  **  pro:  product
  */
  u3_fox res, pro;
  struct u3_x_bench naq;

  res = u3_x_run(v->x, &pro, bus, fol, mar_b ? &naq : 0);
  if ( 0 == res ) {
    if ( mar_b ) {
      fprintf(stderr, " <%lld steps, %d words>\n",
              naq.ruy_d,
              (naq.max_w - naq.vil_w) + (naq.buc_w - naq.tew_w));
    }
    return pro;
  }
  else {
    c3_c c_buf[5];

    u3_lr_bytes(v->x, 0, 5, (c3_y *)c_buf, res);
    fprintf(stderr, "[%s]\n", c_buf);
 
    return _vere_q_fail(v);
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
  struct u3_x_bench naq;

  res = u3_x_mung(v->x, &pro, gat, sam, mar_b ? &naq : 0);
  if ( 0 == res ) {
    if ( mar_b ) {
      fprintf(stderr, " <%lld steps, %d words>\n",
              naq.ruy_d,
              (naq.max_w - naq.vil_w) + (naq.buc_w - naq.tew_w));
    }
    return pro;
  }
  else {
    c3_c c_buf[5];

    u3_lr_bytes(v->x, 0, 5, (c3_y *)c_buf, res);
    fprintf(stderr, "[%s]\n", c_buf);
    
    return _vere_q_fail(v);
  }
}

/*  _vere_munz()::
*/
static u3_fox
_vere_munz(struct vere_state*   v,
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
              naq.ruy_d,
              (naq.maz_w - naq.vil_w) + (naq.buc_w - naq.tew_w));
    }
    return pro;
  }
  else {
    c3_c c_buf[5];

    u3_lr_bytes(v->z, 0, 5, (c3_y *)c_buf, res);
    fprintf(stderr, "[%s]\n", c_buf);
    
    return _vere_q_fail(v);
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

/*  _vere_shell():  load the shell.
*/
u3_fox
_vere_shell(struct vere_state*  v,
            const c3_c*         pod_c,
            const c3_c*         paq_c)
{
  struct stat pod_stat, paq_stat;

  if ( stat(pod_c, &pod_stat) < 0 ) {
    perror(pod_c);
    exit(1);
  }
  else {
    u3_fox ver;
    FILE *fil;

    if ( v->new_b ||
         (stat(paq_c, &paq_stat) < 0) ||
         (pod_stat.st_mtimespec.tv_sec > paq_stat.st_mtimespec.tv_sec) ||
         ((pod_stat.st_mtimespec.tv_sec == (pod_stat.st_mtimespec.tv_sec)) &&
          (pod_stat.st_mtimespec.tv_nsec > paq_stat.st_mtimespec.tv_nsec)) )
    {
      printf("[vere: building shell: %s]\n", pod_c);
      ver = _vere_fire(v, _vere_file(v->x, pod_c));

      if ( !(fil = fopen(paq_c, "w")) ) {
        perror(paq_c);
      }
      else {
        _vere_dump(v->x, fil, ver);
         printf("[saved shell: %s]\n", paq_c);
        fclose(fil);
      }
      return ver;
    }
    else {
      fil = fopen(paq_c, "r");
      ver = _vere_scan(v->x, fil);

      printf("[vere: loaded shell: %s]\n", paq_c);

      return ver;
    }
  }
}

void *
vere_boot(c3_w siz_w)
{
  struct vere_state *v = malloc(sizeof(struct vere_state));

  u3_b_init();

  if ( setjmp(v->q.buf_jmp) ) {
    fprintf(stderr, "boot: fail\n");
    exit(1);
  }

  /*  Load the kernel itself.  XX: jets from the outside.
  **
  **  XX: this whole sequence is wrong.  It is made complicated
  **  by the fact that the fake compiler can't jet !%, and punts 
  **  in a way that is eqponentially slow!
  */
  {
    v->x = u3_x_new(siz_w);
    v->z = u3_z_new(siz_w);
    _vere_kernel(v, "watt/296.watt", "watt/296.nock");
  }

  /*  Create the kernel soul.
  */
  {
    u3_fox kul = _vere_load_c(v, "seed:plow:!%");

    v->kul.p = _vere_h(v, kul);
    v->kul.q = _vere_t(v, kul);
  }

  /*  Basic metacircular gates: read and mill.
  **
  **  XX: note that the mel load is perceptibly slow due to the
  **  aforementioned problems with |%.
  */
  {
    v->g.rad = _vere_load_c(v, "read:plow:!%");

    v->g.mel = _vere_load_c(v, 
      "=>(!% =+([p=*type:plow q=*gene:plow] |=((~(mill rose:plow p) q))))"
    );
  }

#if 1
  /*  Load vere, the new shell.
  */
  {
    v->m.sod = _vere_shell(v, "watt/vere.watt", "watt/vere.nock");

    v->m.g.par = _vere_make(v, _vere_h(v, v->m.sod), _vere_ns(v, "spar"));
    v->m.g.fab = _vere_make(v, _vere_h(v, v->m.sod), _vere_ns(v, "glem"));
    v->m.g.hom = _vere_make(v, _vere_h(v, v->m.sod), _vere_ns(v, "blor"));
  }
#endif
  return v;
}

void
_vere_spit(struct vere_state*   v,
           u3_fox               pox)
{
  if ( 0 != pox ) {
    u3_fox i_pox = _vere_h(v, pox);
    u3_fox t_pox = _vere_t(v, pox);

    switch ( _vere_h(v, i_pox) ) {
      case c3__crud: {
        u3_fox rol = _vere_t(v, i_pox);
        u3_fox typ = _vere_h(v, rol);
        u3_fox pro = _vere_t(v, rol);

        u3_b_print_type(v->x, 0, typ);
        u3_b_print(v->x, 0, pro);

        break;
      }
      default: _vere_q_fail(v);
    }
    _vere_spit(v, t_pox);
  }
}

/*  _vere_path_out_a(): measure and/or cat a path with form.
*/
static c3_w
_vere_path_out_a(struct vere_state*   v,
                 c3_c*                pah_c,
                 u3_fox               fom,
                 u3_fox               pih)
{
  u3_fox  bis = _vere_h(v, pih);
  c3_w    len = u3_lr_bin(v->x, 3, bis);

  if ( pah_c ) {
    u3_lr_bytes(v->x, 0, len, (c3_y *)pah_c, bis);
    pah_c += len;
  }
  if ( 0 == _vere_t(v, pih) ) {
    c3_w  fen = u3_lr_bin(v->x, 3, fom);
    
    if ( pah_c ) {
      *pah_c++ = '.';
      u3_lr_bytes(v->x, 0, fen + 1, (c3_y *)pah_c, fom);
    }
    return (1 + fen + len);
  }
  else {
    if ( pah_c ) {
      *pah_c++ = '/';
    }
    return (1 + len + _vere_path_out_a(v, pah_c, fom, _vere_t(v, pih)));
  }
}

/*  _vere_path_out(): measure and/or cat a path with form.
*/
static c3_w
_vere_path_out(struct vere_state* v,
               c3_c*              pah_c,
               u3_fox             fom,
               u3_fox             pah)
{
  const c3_c* rut;
  c3_w        len_w = 0;

  switch ( _vere_h(v, pah) ) {
    case c3__root:  rut = "/"; break;
    case c3__curd:  rut = ""; break;
    case c3__kern:  rut = "watt/"; break;
    case c3__ulib:  rut = "watt/lib/"; break;
    case c3__ubin:  rut = "watt/bin/"; break;
    default:        return _vere_q_fail(v);
  }
  len_w = strlen(rut);

  if ( pah_c ) {
    strcpy(pah_c, rut);
    pah_c += len_w;
  }
  return len_w + _vere_path_out_a(v, pah_c, fom, _vere_t(v, pah));
}

/*  _vere_path(): load by uniq path with format.
*/
static u3_fox
_vere_path_load(struct vere_state*  v,
                u3_fox              fom,
                u3_fox              pah)
{
  c3_w    pol_w = _vere_path_out(v, 0, fom, pah);
  c3_c*   pah_c = alloca(pol_w + 1);

  _vere_path_out(v, pah_c, fom, pah);
  {
    switch ( fom ) {
      case c3__watt: {
        u3_fox des = _vere_file(v->x, pah_c);
        return _vere_mung(v, v->g.rad, des, 0);
      }
      case c3__nock: 
      case c3__noun: {
        FILE *fil = fopen(pah_c, "r");

        return _vere_scan(v->x, fil);
      }
      default:
      case c3__atom: {
        return _vere_file(v->x, pah_c);
      }
    }
  }
}  

/*  _vere_well_a(): well tule.
*/
  static u3_fox 
  _vere_well(struct vere_state*, u3_fox);

static u3_fox
_vere_well_a(struct vere_state*   v,
             u3_fox               p_wol)
{
  if ( 0 == p_wol ) {
    return p_wol;
  } else {
    return _vere_nc(v, _vere_well(v, _vere_h(v, p_wol)),
                       _vere_well_a(v, _vere_t(v, p_wol)));
  }
}

/*  _vere_well_wood(): convert %wood.
*/
static u3_fox
_vere_well_wood(struct vere_state* v,
                u3_fox             p_wol)
{
  if ( 0 == p_wol ) {
    return 0;
  } else {
    u3_fox ip_wol = _vere_h(v, p_wol);
    u3_fox tp_wol = _vere_t(v, p_wol);
    u3_fox pip_wol = _vere_h(v, ip_wol);
    u3_fox qip_wol = _vere_t(v, ip_wol);

    switch ( pip_wol ) {
      case c3__sys: {
        return _vere_nc
          (v, _vere_nc(v, c3__gen, _vere_path_load(v, c3__watt, qip_wol)),
              _vere_well_wood(v, tp_wol));
      }
      case c3__gen: {
        return _vere_nc
          (v, ip_wol, _vere_well_wood(v, tp_wol));
      }
      default: {
        return _vere_q_fail(v);
      }
    }
  }
}

/*  _vere_well(): adjust well with input.
*/
static u3_fox
_vere_well(struct vere_state*   v,
           u3_fox               wol)
{
  u3_fox p_wol, q_wol;

  if ( u3_yes == u3_lr_pq(v->x, wol, c3__data, &p_wol, &q_wol) ) {
    u3_fox dat = _vere_path_load(v, p_wol, q_wol);

    return _vere_nc(v, c3__bone, dat);
  }
  else if ( u3_yes == u3_lr_pq(v->x, wol, c3__kick, &p_wol, &q_wol) ) {
    return _vere_nt
      (v, c3__kick, _vere_well(v, p_wol), _vere_well(v, q_wol));
  }
  else if ( u3_yes == u3_lr_pq(v->x, wol, c3__sell, &p_wol, &q_wol) ) {
    return _vere_nt
      (v, c3__sell, _vere_well(v, p_wol), _vere_well(v, q_wol));
  }
  else if ( u3_yes == u3_lr_p(v->x, wol, c3__tule, &p_wol) ) {
    return _vere_nc
      (v, c3__tule, _vere_well_a(v, p_wol));
  }
  else if ( u3_yes == u3_lr_p(v->x, wol, c3__wood, &p_wol) ) {
    return _vere_nc(v, c3__wood, _vere_well_wood(v, p_wol));
  }
  else return wol;
}

void 
vere_line(void *vere, const c3_c *line)
{
  struct vere_state*  v=vere;
  const c3_c*         lin_c=line;

  if ( setjmp(v->q.buf_jmp) ) {
    fprintf(stderr, "line: fail\n");
  }
  else {
#if 0
    /*  lin:  line, input
    **  feq:  gene, parsed line
    **  rol:  soul, generated line
    */
    u3_fox lin = _vere_ns(v, lin_c);
    u3_fox feq = _vere_mung(v, v->a.g.par, lin, 0);
    {
      // u3_b_print(v->x, "feq", feq);

      u3_fox rol = _vere_mung(v, v->a.g.tog, feq, 0);
      u3_fox typ = _vere_h(v, rol);
      u3_fox pro = _vere_t(v, rol);

      u3_b_print_type(v->x, 0, typ);
      u3_b_print(v->x, 0, pro);
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

      // u3_b_print(v->x, "syn", syn);
      // u3_b_print(v->x, "wola", wol);
      // 
      wol = _vere_well(v, wol);
      // u3_b_print(v->x, "wolb", wol);
      {
        u3_fox mal = _vere_mung(v, fab, wol, 0);
        u3_fox tif = _vere_mung(v, hom, _vere_nc(v, syn, mal), 0);

        v->m.sod = _vere_nc(v, _vere_h(v, v->m.sod), _vere_h(v, tif));
        _vere_spit(v, _vere_t(v, tif));
      }
    }
#endif
  }
}

static u3_fox
_vere_xz(struct vere_state* v,
         u3_fox             fox)
{
  if ( u3_yes == u3_lr_dust(v->x, fox) ) {
    return u3_ln_cell
      (v->z, 
       _vere_xz(v, u3_lr_h(v->x, fox)), 
       _vere_xz(v, u3_lr_t(v->x, fox)));
  }
  else {
    mpz_t gur_mp;

    u3_lr_mp(v->x, gur_mp, fox);
    return u3_ln_mp(v->z, gur_mp);
  }
}

void 
vere_line2(void* vere, const c3_c* lin_c)
{
  struct vere_state*  v=vere;

  if ( setjmp(v->q.buf_jmp) ) {
    fprintf(stderr, "line: fail\n");
  }
  else {
    const c3_c* spc_c = strchr(lin_c, ' ');
    const c3_c* arg_c = (spc_c + 1);
    c3_c*       pro_c = alloca((spc_c - lin_c) + 1);
    c3_c        pah_c[1024];

    strncpy(pro_c, lin_c, (spc_c - lin_c));
    pro_c[spc_c - lin_c] = 0;
    sprintf(pah_c, "watt/tst/%s.watt", pro_c);

    /* Load and run program.
    */
    {
      u3_fox gat = _vere_file(v->x, pah_c);
      u3_fox arg = u3_ln_string(v->x, arg_c);
      u3_fox fel = _vere_nock(v, 0, _vere_kick(v, gat), 0);
      u3_fox gux = _vere_nock(v, 0, _vere_kick(v, arg), 0);
      u3_fox bim;

      fel = _vere_xz(v, fel);
      gux = _vere_xz(v, gux);

      bim = _vere_munz(v, fel, gux, 1);
      u3_b_print(v->z, 0, bim);
    }
  }
}
