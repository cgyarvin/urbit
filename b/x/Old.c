/* mill/make.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

  /** Forward declarations.
  **/
    static u4_loaf
    _mill_make_main(u4_milr, u4_gene, u4_type);


/* _make_book(): bake a book.
*/
static u4_form
_make_book(u4_milr m, u4_noun p_gen, u4_type tip)
{
  u4_lane lane = m->lane;

  if ( u4_n_cell(u4_ch(p_gen)) ) {
    return u4_k_cell(lane, _make_book(m, u4_ch(p_gen), tip),
                           _make_book(m, u4_ct(p_gen), tip));
  }
  else {
    return _mill_bake(m, u4_ct(p_gen), tip);
  }
}

/* _mill_make_sard(): mill a sard.
*/
static void
_mill_make_sard(u4_milr m,
                u4_noun p_gen,
                u4_type tip,
                u4_type *gor,
                u4_form *fal)
{
  u4_lane lane    = m->lane;
  u4_noun ip_gen  = u4_ch(p_gen);
  u4_noun pip_gen = u4_ch(ip_gen);
  u4_noun qip_gen = u4_ct(ip_gen);
  u4_noun tp_gen  = u4_ct(p_gen);
  u4_loaf fod     = _mill_make(m, qip_gen, tip);

  if ( u4_n_zero(tp_gen) ) {
    *gor = u4_k_trel
      (lane, u4_atom_sard, 
             u4_k_cell(lane, pip_gen, u4_ch(fod)),
             u4_noun_0);

    *fal = u4_ct(fod);
  } 
  else {
    _mill_make_sard(m, tp_gen, tip, gor, fal);

    *gor = u4_k_trel
      (lane, u4_atom_sard,
             u4_k_cell(lane, pip_gen, u4_ch(fod)),
             u4_ct(*gor));
    
    *fal = _mill_cons(m, u4_ct(fod), *fal);
  }
}

/* _mill_make_main(): internal of _mill_make().
*/
u4_loaf
_mill_make_main(u4_milr m,
                u4_gene gen,
                u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_fork(gen, &p_gen, &q_gen) ) {
    return u4_trip;
  }

  
    /* ^+     [%perd fes=(gene) rum=(gene)]
    **
    **    perd: perd [rum] to [fes], geometrically
    */
  else if ( u4_b_pq(gen, u4_atom_perd, &p_gen, &q_gen) ) {
    u4_form fal = _mill_bake(m, p_gen, tip);
    u4_type gan = _mill_play(m, q_gen, tip);

    // XX: safe

    return u4_k_cell(lane, gan, fal);
  }

    /* ^-     [%halc fes=(gene) rum=(gene)]
    **
    **    halc: perd [rum] to [fes], genetically
    */
  else if ( u4_b_pq(gen, u4_atom_halc, &p_gen, &q_gen) ) {
    return _mill_fail(m, "not supported");
  }

    /*        [%dbug pux=gene]
    **
    **    dbug: enable internal debugging
    */
  else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
  }

    /*        [%pret wis=sand]
    **
    **    pret: precise constant
    */
  else if ( u4_b_p(gen, u4_atom_pret, &p_gen) ) {
    return u4_k_cell(lane, u4_atom_cube, p_gen);
  }

    /*        [%gult fiz=(3 4 5 6 7 8) dil=gene]
    **
    **    gult: raw nock
    */
  else if ( u4_b_pq(gen, u4_atom_gult, &p_gen, &q_gen) ) {
    return _mill_x_gult(m, p_gen, q_gen);
  }

    /* ^=     [%tarn mox=rope sif=gene vep=gene]
    **
    **    tarn: use [vep], since [mox] matches [sif]
    */
  else if ( u4_b_pqr(gen, u4_atom_tarn, &p_gen, &q_gen, &r_gen) ) {
    // XX: safe
    //
    return _mill_make(m, r_gen, tip);
  }

    /*  ?:    [%stol tes=gene bif=gene hob=gene]
    **
    **    stol: if [tes], then [bif], else [hob]
    */
  else if ( u4_b_pqr(gen, u4_atom_stol, &p_gen, &q_gen, &r_gen) ) {
    u4_loaf ruf = _mill_forb(m, p_gen, tip);
    u4_loaf hig = _mill_make(m, u4_ch(ruf), q_gen);
    u4_loaf goz = _mill_make(m, tip, r_gen);
    u4_form fal = u4_ct(ruf);

    if ( u4_n_eq(u4_noun_1, u4_ch(fal)) ) {
      if ( u4_n_eq(u4_noun_0, u4_ct(fal)) ) {
        return hig;
      } else {
        return goz;
      }
    }
    else {
      return u4_k_cell
        (lane, 
         u4_k_qual(m->lane, u4_noun_2, fal, u4_ct(hig), u4_ct(goz)),
         _mill_eith(m, u4_ch(hig), u4_ch(goz)));
    }
  }

    /* :*     [%sard caw=list+item]
    **
    **    sard: classic tuple
    */
  else if ( u4_b_p(gen, u4_atom_sard, &p_gen) ) {
    u4_type gor;
    u4_form fal;

    _mill_make_sard(m, p_gen, tip, &gor, &fal);
    return u4_k_cell(lane, gor, fal);
  }

    /* |+     [%malk pir=list+gene]
    **
    **    malk: pure load
    */
  else if ( u4_b_p(gen, u4_atom_malk, &p_gen) ) {
    u4_type gan = u4_k_trel(lane, u4_atom_cone, tip, p_gen);
    u4_form fal = _make_book(m, tip, p_gen);

    return u4_k_cell(lane, gan, fal);
  }

    /*        [%spot xed=[at=[p=nat q=nat] to=[p=nat q=nat]] lyq=gene]
    **
    **    spot: mark position in file
    */
  else if ( u4_b_pq(gen, u4_atom_spot, &p_gen, &q_gen) ) {
    u4_noun laq = m->zud;
    u4_loaf fod;

    m->zud = p_gen;
    fod = _mill_make(m, q_gen, tip);
    m->zud = laq;

    return fod;
  }


  else return _mill_make(m, _mill_open(m, gen), tip);
}

/* _mill_make(): type inference, top level.
*/
u4_type 
_mill_make(u4_milr m,
           u4_gene gen,
           u4_type tip)
{
  u4_lane lane = m->lane;
  u4_noun fid  = u4_k_cell(lane, gen, tip);
  u4_nopt raz  = u4_tab_get(fid, m->niq);

  if ( raz ) {
    return raz;
  }
  else {
    raz = _mill_make_main(m, gen, tip);

    m->niq = u4_tab_add(lane, fid, raz, m->niq);
    return raz;
  }
}
