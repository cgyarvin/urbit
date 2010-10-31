/* f/host.c: driver system.
**
** This file is in the public domain.
*/
#include "all.h"

  /** Global structures.
  **/
    /* Suppress warnings.  Set after the first.
    */
      c3_t JetSuppress;

    /* Hangar stack; top hangar is active.
    */
      u2_ho_hangar *u2_HostHangar;

    /* External drivers.
    */
      extern u2_ho_driver j2_da(watt_274);

    /* Built-in battery drivers.   Null `cos` terminates. 
    */
      static u2_ho_driver *u2_HostDriverBase[] = {
        &j2_da(watt_274), 
        0
      };


  /** Forward declarations.
  **/
    /* _ho_explore(): find driver from chip, caching.
    */
    static u2_ho_driver*
    _ho_explore(u2_ray, u2_noun);

/* _cs_free(): free a cache, freeing.
*/
static void
_cs_free(u2_ho_cash *cas_s)
{
  c3_w i_w;

  for ( i_w = 0; i_w < 16; i_w++ ) {
    if ( u2_none == cas_s->dol_p[i_w].tag ) {
      if ( 0 == cas_s->dol_p[i_w].ptr_v ) {
        _cs_free(cas_s->dol_p[i_w].ptr_v);
        free(cas_s->dol_p[i_w].ptr_v);
      }
    }
  }
}

/* _cs_init(): initialize an empty cache.
*/
static void
_cs_init(u2_ho_cash *cas_s)
{
  c3_w i_w;

  for ( i_w = 0; i_w < 16; i_w++ ) {
    cas_s->dol_p[i_w].tag = u2_none;
    cas_s->dol_p[i_w].ptr_v = 0;
  }
}

/* jx_cash_find(): find a noun in a cache, or return 0.
*/
static void*
_ho_cash_find(u2_ho_cash *cas_s,
              u2_noun    som)
{
  c3_w mug_w = u2_mug(som);
  c3_w off_w = 0;

  while ( 1 ) {
    if ( off_w == 32 ) {
      c3_w i_w;

      for ( i_w = 0; i_w < 16; i_w++ ) {
        u2_ho_pear* per_p = &cas_s->dol_p[i_w];
        u2_noun     tag   = per_p->tag;

        if ( (u2_none != tag) && (u2_yes == u2_sing(som, tag)) ) {
          return per_p->ptr_v;
        }
      }
      return 0;
    }
    else {
      c3_w        fat_w = (mug_w >> off_w) & 15;
      u2_ho_pear* per_p = &cas_s->dol_p[fat_w];
      u2_noun     tag   = per_p->tag;

      if ( u2_none == tag ) {
        cas_s = per_p->ptr_v;

        if ( 0 == cas_s ) {
          return 0;
        } else {
          off_w += 4;
          continue;
        }
      }
      else if ( u2_yes == u2_sing(som, tag) ) {
        return per_p->ptr_v;
      }
      else return 0;
    }
  }
}

/* _cs_save(): as _ho_cash_save(), with mug and offset.
*/
static void
_cs_save(u2_ho_cash* cas_s,
         u2_noun     som,
         void*       ptr_v,
         c3_w        mug_w,
         c3_w        off_w)
{
  while ( 1 ) {
    if ( off_w == 32 ) {
      /* Linear search in a list of 16 total collisions.
      ** Overflow probability: (n/(2^31))^15 ~= 0.
      */
      c3_w i_w;

      for ( i_w = 0; i_w < 16; i_w++ ) {
        u2_ho_pear* per_p = &cas_s->dol_p[i_w];
        u2_noun     tag   = per_p->tag;

        if ( u2_none != tag ) {
          /*
          ** If this assertion fires, you have a duplicate formula 
          ** or battery.  Why?
          */
          c3_assert(u2_no == u2_sing(som, tag));
        }
        else {
          per_p->tag = som;
          per_p->ptr_v = ptr_v;
        }
      }
      return;
    }
    else {
      c3_w        fat_w = (mug_w >> off_w) & 15;
      u2_ho_pear* per_p = &cas_s->dol_p[fat_w];
      u2_noun     tag   = per_p->tag;

      if ( u2_none == tag ) {
        cas_s = per_p->ptr_v;

        if ( 0 == cas_s ) {
          per_p->tag = som;
          per_p->ptr_v = ptr_v;
          return;
        } 
        else {
          off_w += 4;
          continue;
        }
      }
      else {
        void*       qtr_v = per_p->ptr_v;
        u2_ho_cash* cax_s;

        if ( 0 == (cax_s = malloc(sizeof(*cax_s))) ) {
          return;
        }
        _cs_init(cax_s);

        _cs_save(cax_s, tag, qtr_v, u2_mug(tag), 4+off_w);
        _cs_save(cax_s, som, ptr_v, mug_w, 4+off_w);

        per_p->tag = u2_none;
        per_p->ptr_v = cax_s;

        return;
      }
    }
  }
}

/* _ho_cash_save(): save a noun in a cache.
*/
static void
_ho_cash_save(u2_ho_cash *cas_s,
              u2_noun    som,
              void*      ptr_v)
{
  _cs_save(cas_s, som, ptr_v, u2_mug(som), 0);
}

/* _ho_mop_decimal(): measure/print decimal number.
*/
static c3_w
_ho_mop_decimal(c3_c *buf_c, u2_noun num)
{
  if ( u2_no == u2_stud(num) ) {
    return 0;
  } else {
    if ( 0 == num ) {
      if ( buf_c ) *buf_c = '0';
      return 1;
    } else {
      mpz_t num_mp;
      c3_w  len_w;

      mpz_init(num_mp);
      u2_mp(num_mp, num);
      len_w = mpz_sizeinbase(num_mp, 10);

      if ( buf_c ) {
        gmp_sprintf(buf_c, "%Zu", num_mp);
      }
      mpz_clear(num_mp);
      return len_w;
    }
  }
}

/* _ho_mop_term(): measure/print term.
*/
static c3_w
_ho_mop_term(c3_c *buf_c, u2_noun tam)
{
  if ( u2_no == u2_stud(tam) ) {
    return 0;
  }
  else {
    c3_w len_w = u2_met(3, tam);

    if ( buf_c ) {
      u2_bytes(0, len_w, (c3_y *)buf_c, tam);
      {
        c3_w i_w;

        for ( i_w = 0; i_w < len_w; i_w++ ) {
          if ( !((buf_c[i_w] >= 'a') && (buf_c[i_w] <= 'z')) ) {
            buf_c[i_w] = '_';
          }
        }
      }
    }
    return len_w;
  }
}

/* _ho_mop_version(): measure/print version.
*/
static c3_w
_ho_mop_version(c3_c *buf_c, u2_noun ver)
{
  if ( u2_no == u2_dust(ver) ) {
    return _ho_mop_decimal(buf_c, ver);
  }
  else {
    c3_w len_w = _ho_mop_decimal(buf_c, u2_h(ver));

    if ( buf_c ) buf_c += len_w;
    len_w++;
    if ( buf_c ) *buf_c++ = 'x';

    return (len_w + _ho_mop_decimal(buf_c, u2_t(ver)));
  }
}

/* _ho_mop_seal(): measure/print identity declaration.
*/
static c3_w
_ho_mop_seal(c3_c *buf_c, u2_noun mek)
{
  u2_noun std, ven, pro, ver, kel;
  c3_w    len_w, lan_w, lon_w, lin_w;

  if ( u2_yes == u2_as_qual(mek, &ven, &pro, &ver, &kel) ) {
    len_w = _ho_mop_term(buf_c, ven);
    if ( buf_c ) buf_c += len_w;
    len_w++;
    if ( buf_c ) *buf_c++ = '_';

    lan_w = _ho_mop_term(buf_c, pro);
    if ( buf_c ) buf_c += lan_w;
    lan_w++;
    if ( buf_c ) *buf_c++ = '_';

    lon_w = _ho_mop_version(buf_c, ver);
    if ( buf_c ) buf_c += lon_w;
    lon_w++;
    if ( buf_c ) *buf_c++ = '_';

    lin_w = _ho_mop_decimal(buf_c, kel);
    if ( buf_c ) buf_c += lin_w;

    return (len_w + lan_w + lon_w + lin_w);
  }
  else if ( u2_yes == u2_as_trel(mek, &ven, &pro, &kel) ) {
    len_w = _ho_mop_term(buf_c, ven);
    if ( buf_c ) buf_c += len_w;
    len_w++;
    if ( buf_c ) *buf_c++ = '_';

    lan_w = _ho_mop_term(buf_c, pro);
    if ( buf_c ) buf_c += lan_w;
    lan_w++;
    if ( buf_c ) *buf_c++ = '_';

    lon_w = _ho_mop_decimal(buf_c, kel);
    if ( buf_c ) buf_c += lon_w;
    lon_w++;
    if ( buf_c ) *buf_c++ = '_';

    return (len_w + lan_w + lon_w);
  }
  else if ( u2_yes == u2_as_cell(mek, &std, &kel) ) {
    len_w = _ho_mop_term(buf_c, std);
    if ( buf_c ) buf_c += len_w;
    len_w++;
    if ( buf_c ) *buf_c++ = '_';

    lan_w = _ho_mop_decimal(buf_c, kel);
    if ( buf_c ) buf_c += lan_w;

    return (len_w + lan_w);
  }
  else {
    len_w = _ho_mop_term(buf_c, mek);
    
    return len_w;
  }
}

/* _ho_mop_chip(): measure/print control string, from chip.
*/
static c3_w
_ho_mop_chip(c3_c *buf_c, u2_noun xip)
{
  u2_disc dac = u2_h(xip);
  u2_noun pit = u2_t(u2_t(xip));

  if ( u2_nul == pit ) {
    return _ho_mop_seal(buf_c, u2_h(dac));
  }
  else {
    c3_w len_w = _ho_mop_chip(buf_c, u2_t(pit));

    if ( buf_c ) {
      buf_c += len_w;
      *buf_c++ = '_';
      *buf_c++ = '_';
    }
    return (len_w + 2 + _ho_mop_seal(buf_c, u2_h(dac)));
  }
}

/* _ho_cstring(): return malloced control string for `xip`.
*/
static c3_c*
_ho_cstring(u2_noun xip)
{
  c3_w len_w = _ho_mop_chip(0, xip);
  c3_c *cos_c;

  if ( !(cos_c = malloc(len_w + 1)) ) abort();

  _ho_mop_chip(cos_c, xip);
  cos_c[len_w] = 0;

  return cos_c;
}

/* u2_ho_boot(): 
**
**   Boot driver system.  Note that all chips and
**   tools are considered permanent between reboots.
*/
static void
_ho_boot(u2_ho_hangar *hag)
{
  _cs_init(&hag->jac_s);
  _cs_init(&hag->bad_s);
}

/* _ho_down(): 
**
**   Release all resources in `hag`.
*/
static void
_ho_down(u2_ho_hangar *hag)
{
  _cs_free(&hag->jac_s);
  _cs_free(&hag->bad_s);
}

/* u2_ho_push(): 
**
**   Push a driver hangar (corresponding to a jet shed).
*/
void
u2_ho_push(void)
{
  u2_ho_hangar *hag = malloc(sizeof(u2_ho_hangar));

  _ho_boot(hag);
  hag->nex_h = u2_HostHangar;
  u2_HostHangar = hag;
}

/* u2_ho_popp():
**
**  Pop a hangar.
*/
void
u2_ho_popp(void)
{
  u2_ho_hangar *hag = u2_HostHangar;
  u2_ho_hangar *nex_h = hag->nex_h;

  _ho_down(hag);
  free(hag);
  u2_HostHangar = nex_h;
}

/* u2_ho_klar():
**
**   Clear and release all hangars.
*/
void
u2_ho_klar(void)
{
  while ( u2_HostHangar ) {
    u2_ho_popp();
  }
}

/* u2_ho_warn(): report a warning, file and line.
*/
void
u2_ho_warn(const c3_c* fil_c,
           c3_w        lyn_w)
{
  if ( !JetSuppress ) {
    fprintf(stderr, "ho: warn: %s:%u\n", fil_c, lyn_w);
    JetSuppress = 1;
  }
}

/* u2_ho_dive():
**
**   Report compatibility failure in `xip`. 
*/
void
u2_ho_dive(u2_ray  wir_r,
           u2_noun xip)
{
  c3_c *cos_c = _ho_cstring(xip);

  fprintf(stderr, "ho: jet dive: %s\n", cos_c);
  free(cos_c);

  c3_assert(0);
}

/* _ho_execute(): execute jet.
*/
static u2_weak
_ho_execute(u2_ray      wir_r,
            u2_ho_jet*  jet_j,
            u2_noun     cor)
{
  u2_ray cap_r = u2_rail_cap_r(wir_r);
  u2_ray jub_r;

  if ( 0 == jet_j->fun_f ) {
    return u2_none;
  }
  else if ( u2_no == u2_rl_leap(wir_r, c3__warm) ) {
    return u2_none;
  }
  else if ( 0 == (jub_r = u2_bl_open(wir_r)) ) {
    u2_rl_fall(wir_r);
    return u2_none;
  }
  else {
    if ( 1 == u2_bl_set(wir_r) ) {
      u2_bl_done(wir_r, jub_r);
      u2_rl_fall(wir_r);

      u2_rail_cap_r(wir_r) = cap_r;
      return u2_none;
    } else {
      u2_noun pro = jet_j->fun_f(wir_r, cor);

      u2_bl_done(wir_r, jub_r);
      u2_rl_fall(wir_r);

      c3_assert(u2_none != pro);
      pro = u2_rl_ice(wir_r, pro);
      u2_rail_cap_r(wir_r) = cap_r;
      return pro;
    }
  }
}

/* _ho_extract(): extract jet formula from battery.
*/
static u2_weak
_ho_extract(u2_noun    xip,
            const c3_c *fcs_c)
{
  u2_noun bat = u2_h(u2_t(xip));

  if ( *fcs_c == '.' ) {
    c3_w axe_w = 0;

    sscanf(fcs_c+1, "%u", &axe_w);
    c3_assert(!(0x80000000 & axe_w));     // that's a deep tree, dude

    axe_w = u2_fj_op_tap(0, axe_w);
    return u2_frag(axe_w, bat);
  }
  else {
    u2_noun nut = u2_t(u2_h(xip));

    while ( _0 != nut ) {
      u2_noun i_nut = u2_h(nut);

      if ( (u2_yes == u2_sing_c(fcs_c, u2_h(i_nut))) ) {
        u2_noun fal = u2_t(i_nut);

        /* `fal` must match `[2 [0 1] [0 x]]`
        */
        if ( (u2_yes == u2_dust(fal)) &&
             (u2_nock_sail == u2_h(fal)) &&
             (u2_yes == u2_dust(u2_t(fal))) )
        {
          u2_noun ht_fal = u2_h(u2_t(fal));
          u2_noun tt_fal = u2_t(u2_t(fal));

          if ( (_0 == u2_h(ht_fal)) && 
               (_1 == u2_t(ht_fal)) &&
               (_0 == u2_h(tt_fal)) &&
               (u2_yes == u2_stud(u2_t(tt_fal))) )
          {
            u2_atom axe = u2_t(tt_fal);

            if ( !u2_fly_is_cat(axe) ) {
              u2_ho_warn_here();
            }
            axe = u2_fj_op_tap(0, axe);

            return u2_frag(axe, bat);
          }
        }
        return u2_none;
      }
    }
    return u2_none;
  }
}

/* _ho_drive(): install driver.
*/
static void
_ho_drive(u2_ho_driver* dry_d)
{
  u2_ho_jet*    jet_j;
  c3_w          i_w;

  if ( dry_d->fan_j ) {
    for ( i_w = 0; (jet_j = &dry_d->fan_j[i_w])->fcs_c; i_w++ ) {
      jet_j->xip = dry_d->xip;

      jet_j->fol = _ho_extract(dry_d->xip, jet_j->fcs_c);
      if ( u2_none != jet_j->fol ) {
        _ho_cash_save(&u2_HostHangar->jac_s, jet_j->fol, jet_j);
      }
    }
  }
}

/* _ho_explore_static(): find driver from built-in list, or return 0.
*/
static u2_ho_driver*
_ho_explore_static(u2_ray  wir_r,
                   u2_noun xip,
                   c3_c*   cos_c)
{
  c3_w  i_w;

  for ( i_w=0; u2_HostDriverBase[i_w]; i_w++ ) {
    u2_ho_driver *dry_d = u2_HostDriverBase[i_w];

    if ( (u2_none == dry_d->xip) && !strcmp(cos_c, dry_d->cos_c) ) {
      dry_d->xip = xip;
      free(cos_c);

      _ho_cash_save(&u2_HostHangar->bad_s, xip, dry_d);
      return dry_d;
    }
  }
  return 0;
}

/* _ho_explore_parent(): find driver from parent, or return 0.
*/
static u2_ho_driver*
_ho_explore_parent(u2_ray  wir_r,
                   u2_noun xip,
                   c3_c*   cos_c)
{
  u2_noun pet = u2_t(u2_t(xip));

  if ( _0 == pet ) {
    return 0;
  } else {
    u2_ho_driver* par_d = _ho_explore(wir_r, u2_t(pet));
    c3_w          i_w;

    c3_assert(par_d);
    if ( par_d->sub_d ) {
      for ( i_w = 0; par_d->sub_d[i_w].cos_c; i_w++ ) {
        if ( (u2_none == par_d->sub_d[i_w].xip) &&
             !strcmp(cos_c, par_d->sub_d[i_w].cos_c) ) 
        {
          u2_ho_driver *dry_d = &par_d->sub_d[i_w];

          dry_d->xip = xip;
          free(cos_c);

          _ho_cash_save(&u2_HostHangar->bad_s, xip, dry_d);
          return dry_d;
        }
      }
    }
    return 0;
  }
}

/* _ho_explore(): find driver from chip, caching.
*/
static u2_ho_driver*
_ho_explore(u2_ray  wir_r,
            u2_noun xip)
{
  u2_ho_driver* dry_d;

  if ( 0 != (dry_d = _ho_cash_find(&u2_HostHangar->bad_s, xip)) ) {
    return dry_d;
  } else {
    c3_c* cos_c = _ho_cstring(xip);

    if ( 0 != (dry_d = _ho_explore_parent(wir_r, xip, cos_c)) ) {
      fprintf(stderr, "battery: child : %s\n", cos_c);
      _ho_drive(dry_d);
      return dry_d;
    }
    else if ( 0 != (dry_d = _ho_explore_static(wir_r, xip, cos_c)) ) {
      fprintf(stderr, "battery: static: %s\n", cos_c);
      _ho_drive(dry_d);
      return dry_d;
    }
    else {
      if ( !(dry_d = malloc(sizeof(u2_ho_driver))) ) {
        abort();
      }

      dry_d->cos_c = cos_c;
      dry_d->xip = xip;
      dry_d->fan_j = 0;

      fprintf(stderr, "battery: dummy : %s\n", cos_c);
      _ho_cash_save(&u2_HostHangar->bad_s, xip, dry_d);
      return dry_d;
    }
  }
}

/* _ho_discover(): find jet from xip and fol, caching.
*/
static u2_ho_jet*
_ho_discover(u2_ray  wir_r,
             u2_noun xip,
             u2_noun fol,
             u2_noun cor)
{
  u2_ho_jet*    jet_j;
  u2_ho_driver* dry_d;

  if ( (0 != (jet_j = _ho_cash_find(&u2_HostHangar->jac_s, fol)) ) ) {
    return jet_j;
  }
  else {
    if ( 0 == (dry_d = _ho_explore(wir_r, xip)) ) {
      return 0;
    }
    else {
      if ( 0 != (jet_j = _ho_cash_find(&u2_HostHangar->jac_s, fol)) ) {
        return jet_j;
      } else {
        if ( !(jet_j = malloc(sizeof(u2_ho_jet))) ) {
          abort();
        }

        jet_j->xip = dry_d->xip;
        jet_j->fol = fol;
        jet_j->fun_f = 0;

        fprintf(stderr, "formula: dummy : %s, %x\n",
            dry_d->cos_c, u2_mug(fol));
        _ho_cash_save(&u2_HostHangar->jac_s, fol, jet_j);
        return jet_j;
      }
    }
  }
}

/* u2_ho_fire(): 
**
**   Attempt host nock driver on `xip`, `cor`, `fol`.
**   For any failure to compute, return `u2_none`.
**
**   If `*saf` is u2_no, result is unsafe and needs testing.
*/
u2_weak
u2_ho_fire(u2_ray   wir_r,
           u2_chip  xip,
           u2_noun  cor,
           u2_noun  fol,
           u2_flag* saf)
{
  u2_ho_jet *jet_j;

  if ( 0 == (jet_j = _ho_discover(wir_r, xip, fol, cor)) ) {
    return u2_none;
  }
  else {
    *saf = jet_j->ace;

    return _ho_execute(wir_r, jet_j, cor);
  }
}
