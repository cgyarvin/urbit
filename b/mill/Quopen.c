/* mill/open.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* _open_all(): (%all p)
*/
static u4_noun
_open_all(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(p_gen) ) {
    return u4_k_cell(lane, u4_atom_pret, u4_noun_0);
  } 
  else if ( u4_n_zero(u4_ct(p_gen)) ) {
    return u4_ch(p_gen);
  }
  else {
    return u4_k_trel
        (lane, u4_atom_and, u4_ch(p_gen), _open_all(m, u4_ct(p_gen)));
  }
}

/* _open_any(): (%any p)
*/
static u4_noun
_open_any(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(p_gen) ) {
    return u4_k_cell(lane, u4_atom_pret, u4_noun_1);
  } 
  else if ( u4_n_zero(u4_ct(p_gen)) ) {
    return u4_ch(p_gen);
  }
  else {
    return u4_k_trel
        (lane, u4_atom_or, u4_ch(p_gen), _open_any(m, u4_ct(p_gen)));
  }
}

/* _open_bolt(): (%bolt p)
*/
static u4_noun
_open_bolt(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_load, u4_noun_0, p_gen);
}

/* _open_goat(): (%goat p)
*/
static u4_noun
_open_goat(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, 
     u4_atom_lamb,
     u4_k_trel(lane, u4_atom_roll, u4_noun_3, u4_noun_0),
     u4_k_trel
     (lane, 
       u4_atom_fix,
       u4_k_cell(lane, u4_atom_limb, u4_noun_4),
       p_gen));
}

/* _open_loop(): (%loop p)
*/
static u4_noun
_open_loop(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, u4_atom_slon, 
           u4_k_trel(lane, u4_atom_load, u4_noun_0, p_gen),
           u4_k_trel(lane, u4_atom_look, u4_noun_0, u4_noun_0));
}

/* _open_not(): (%not p)
*/
static u4_noun
_open_not(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_if,
           p_gen,
           u4_k_cell(lane, u4_atom_pret, u4_noun_1),
           u4_k_cell(lane, u4_atom_pret, u4_noun_0));
}

/* _open_pop(): (%pop p)
*/
static u4_noun
_open_pop(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, u4_atom_slon,
           p_gen,
           u4_k_trel(lane, u4_atom_look, u4_noun_0, u4_noun_0));
}

/* _open_tupl(): (%tupl p)
*/
static u4_noun
_open_tupl(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(p_gen) ) {
    return u4_exit;
  }
  else {
    if ( u4_n_zero(u4_ct(p_gen)) ) {
      return u4_ch(p_gen);
    }
    else return u4_k_cell(lane, u4_ch(p_gen), _open_tupl(m, u4_ct(p_gen)));
  }
}

/* _open_and(): (%and p q)
*/
static u4_noun
_open_and(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_if, 
           p_gen,
           q_gen,
           u4_k_cell(lane, u4_atom_pret, u4_noun_1));
}

#if 0
/* _open_coat(): (%coat p q)
*/
static u4_noun
_open_coat(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, u4_atom_wrap,
           u4_k_cell
            (lane, 
             u4_k_trel(lane, p_gen, u4_atom_limb, u4_noun_1),
             u4_noun_0),
           q_gen);
}
#endif

/* _open_book(): (%book p)
*/
static u4_noun
_open_book(u4_milr m, u4_noun p_gen)
{
  u4_lane lane = m->lane;

  return u4_k_cell(lane, u4_atom_load, u4_log_tupl(lane, p_gen));
}

/* _open_nilk(): (%nilk p q)
*/
static u4_noun
_open_nilk(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel(lane, u4_atom_slon, q_gen, p_gen);
}

/* _open_no(): (%no p q)
*/
static u4_noun
_open_no(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_if, p_gen, u4_k_cell(lane, u4_atom_limb, u4_noun_0), q_gen);
}

/* _open_so(): (%so p q)
*/
static u4_noun
_open_so(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_if, p_gen, q_gen, u4_k_cell(lane, u4_atom_limb, u4_noun_0));
}

/* _open_or(): (%or p q)
*/
static u4_noun
_open_or(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane, u4_atom_if, 
           p_gen,
           u4_k_cell(lane, u4_atom_pret, u4_noun_0),
           q_gen);
}

/* _open_pose(): (%pose p q)
*/
static u4_noun
_open_pose(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return 
    u4_k_trel
     (lane,
      u4_atom_slon,
      u4_k_cell(lane, p_gen, u4_k_cell(lane, u4_atom_limb, u4_noun_1)),
      q_gen);
}

/* _open_clep(): (%clep p q)
*/
static u4_noun
_open_clep(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, 
     u4_atom_slon,
     u4_k_trel
       (lane, 
        u4_atom_bend, 
        p_gen, 
        u4_k_cell(lane, u4_atom_limb, u4_noun_1)),
     q_gen);
}

/* _open_roll(): (%roll p q)
*/
static u4_noun
_open_roll(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_trel
    (lane, 
     u4_atom_perd,
     u4_k_qual(lane, u4_atom_raw, p_gen, u4_atom_pret, u4_noun_0),
     u4_k_cell(lane, u4_atom_pret, q_gen));
}

/* _open_punt(): (%punt p q)
*/
static u4_noun
_open_punt(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane,
     u4_atom_comb,
     u4_k_trel(lane, u4_atom_look, u4_noun_0, u4_noun_0),
     u4_k_cell
      (lane,
       u4_k_cell(lane, u4_k_cell(lane, u4_atom_limb, u4_noun_4), q_gen),
       u4_noun_0),
     p_gen);
}

/* _open_boot(): (%boot p q r)
*/
static u4_noun
_open_boot(u4_milr m, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)
{
  u4_lane lane = m->lane;
  u4_gene bof;

  bof = u4_n_zero(r_gen)
          ? u4_k_cell(lane, u4_atom_pret, u4_noun_0)
          : u4_k_trel
              (lane, u4_atom_slon,
                     u4_k_cell(lane, u4_atom_pret, u4_noun_0),
                     u4_k_cell(lane, u4_atom_load, u4_log_tupl(lane, r_gen)));

  return u4_k_trel
    (lane, u4_atom_slon,
           u4_k_cell
             (lane, u4_k_trel
                      (lane, u4_atom_coat, 
                             p_gen,
                             u4_k_cell(lane, u4_atom_limb, u4_noun_1)),
                    bof),
           q_gen);
}

/* _comb_bends()::
*/
static u4_noun
_comb_bends(u4_lane lane, u4_noun q_gen)
{
  if ( u4_n_zero(q_gen) ) {
    return u4_noun_0;
  }
  else {
    u4_noun iq_gen  = u4_ch(q_gen);
    u4_noun tq_gen  = u4_ct(q_gen);
    u4_noun piq_gen = u4_ch(iq_gen);
    u4_noun qiq_gen = u4_ct(iq_gen);

    return u4_k_cell
      (lane, 
       u4_k_cell
        (lane, 
         piq_gen,
         u4_k_trel
          (lane, 
           u4_atom_slon, 
           u4_k_cell(lane, u4_atom_limb, u4_noun_3),
           qiq_gen)),
      _comb_bends(lane, tq_gen));
  }
}

/* _open_comb(): (%comb p q r)
*/
static u4_noun
_open_comb(u4_milr m, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(q_gen) ) {
    return u4_k_trel(lane, u4_atom_slon, r_gen, p_gen);
  }
  else {
    return u4_k_trel
      (lane, 
       u4_atom_slon,
       u4_k_trel(lane, r_gen, u4_atom_limb, u4_noun_1),
       u4_k_trel
        (lane, 
         u4_atom_bend,
         _comb_bends(lane, q_gen),
         u4_k_trel
           (lane, 
            u4_atom_slon, 
            u4_k_cell(lane, u4_atom_limb, u4_noun_2), 
            p_gen
           )
        )
      );
  }
}

/* _gear_arg()::
*/
static u4_noun
_gear_arg(u4_milr m, u4_noun q_gen)
{
  u4_lane lane    = m->lane;
  u4_noun iq_gen  = u4_ch(q_gen);
  u4_noun tq_gen  = u4_ct(q_gen);
  u4_noun piq_gen = u4_ch(iq_gen);
  u4_noun qiq_gen = u4_ct(iq_gen);
  u4_noun fos     = u4_k_trel(lane, u4_atom_coat, piq_gen, qiq_gen);

  if ( u4_n_zero(tq_gen) ) {
    return fos;
  }
  else {
    return u4_k_cell(lane, fos, _gear_arg(m, tq_gen));
  }
}

/* _open_gear(): (%gear p q r)
*/
static u4_noun
_open_gear(u4_milr m, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)
{
  u4_lane lane = m->lane;

  return 
    u4_k_trel
     (lane, 
      u4_atom_slon,
      u4_k_cell
       (lane, 
        _gear_arg(m, q_gen), 
        u4_k_cell(lane, u4_atom_limb, u4_noun_1)),
      u4_k_cell
       (lane,
        u4_atom_bolt,
        u4_k_trel(lane, u4_atom_perd, p_gen, r_gen)));
}

/* _open_pull(): (%pull p q r)
*/
static u4_noun
_open_pull(u4_milr m, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)
{
  u4_lane lane = m->lane;

  return 
    u4_k_trel
     (lane,
      u4_atom_slon,
      u4_k_cell
       (lane, 
        u4_k_trel(lane, u4_atom_coat, p_gen, r_gen),
        u4_k_cell(lane, u4_atom_limb, u4_noun_1)),
      q_gen);
}

/* _open_push(): (%push p q r)
*/
static u4_noun
_open_push(u4_milr m, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)
{
  u4_lane lane = m->lane;

  return 
    u4_k_trel
     (lane,
      u4_atom_slon,
      u4_k_cell
       (lane, 
        u4_k_trel(lane, u4_atom_coat, p_gen, q_gen),
        u4_k_cell(lane, u4_atom_limb, u4_noun_1)),
      r_gen);
}

/* _fan_cases()::
*/
static u4_noun
_fan_cases(u4_milr m, u4_noun ppip_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;
 
  if ( u4_n_zero(ppip_gen) ) {
    return u4_noun_0;
  }
  else {
    u4_noun ippip_gen = u4_ch(ppip_gen);
    u4_noun tppip_gen = u4_ct(ppip_gen);

    return u4_k_cell
      (lane, u4_k_trel(lane, u4_atom_like, q_gen, ippip_gen),
             _fan_cases(m, tppip_gen, q_gen));
  }
}

/* _open_fan(): (%fan p q)
*/
static u4_noun
_open_fan(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(q_gen) ) {
    return u4_k_cell(lane, u4_atom_limb, u4_noun_0);
  }
  else {
    u4_noun iq_gen   = u4_ch(q_gen);      // first
    u4_noun tq_gen   = u4_ct(q_gen);      // rest
    u4_noun piq_gen  = u4_ch(iq_gen);     // forb
    u4_noun qiq_gen  = u4_ct(iq_gen);     // product
    u4_noun ppiq_gen = u4_ch(piq_gen);    // cases
    u4_noun qpiq_gen = u4_ct(piq_gen);    // guard

    return u4_k_qual
     (lane, 
      u4_atom_if,
      u4_k_trel
       (lane, 
        u4_atom_and, 
        u4_k_cell(lane, u4_atom_any, _fan_cases(m, ppiq_gen, p_gen)),
        qpiq_gen),
      qiq_gen,
      _open_fan(m, p_gen, tq_gen));
  }
}

/* _open_fix(): (%fix p q)
*/
static u4_noun
_open_fix(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  if ( u4_n_zero(q_gen) ) {
    return u4_k_cell(lane, u4_atom_limb, u4_noun_0);
  }
  else {
    return u4_k_qual
      (lane, u4_atom_if,
             u4_k_trel(lane, u4_atom_like, p_gen, u4_ch(q_gen)),
             p_gen,
             _open_fix(m, p_gen, u4_ct(q_gen)));
  }
}

/* _fit_list()::
*/
static u4_noun
_fit_list(u4_lane lane, u4_noun q_gen)
{
  if ( u4_n_zero(q_gen) ) {
    return u4_noun_0;
  }
  else {
    u4_noun iq_gen = u4_ch(q_gen);        // first
    u4_noun tq_gen = u4_ct(q_gen);        // rest
    u4_noun piq_gen  = u4_ch(iq_gen);     // forb
    u4_noun ppiq_gen = u4_ch(piq_gen);    // cases

    return u4_log_cat(lane, ppiq_gen, _fit_list(lane, tq_gen));
  }
}

/* _open_fit(): (%fit p q)
*/
static u4_noun
_open_fit(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual
    (lane,
     u4_atom_safe,
     u4_k_trel(lane, u4_atom_fix, p_gen, _fit_list(lane, q_gen)),
     p_gen,
     u4_k_trel(lane, u4_atom_fan, p_gen, q_gen));
}

/* _open_lamb(): (%lamb p q)
*/
static u4_noun
_open_lamb(u4_milr m, u4_noun p_gen, u4_noun q_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual(lane, u4_atom_pose, p_gen, u4_atom_bolt, q_gen);
}

/* _open_un(): (%un p q r)
*/
static u4_noun
_open_un(u4_milr m, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)
{
  u4_lane lane = m->lane;

  return u4_k_qual(lane, u4_atom_if, p_gen, r_gen, q_gen);
}

/* _mill_open(): open macro.
*/
u4_noun
_mill_open(u4_milr m,
           u4_noun gen)
{
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_p(gen, u4_atom_all, &p_gen) ) {
    return _open_all(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_any, &p_gen) ) {
    return _open_any(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_bolt, &p_gen) ) {
    return _open_bolt(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_book, &p_gen) ) {
    return _open_book(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_goat, &p_gen) ) {
    return _open_goat(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_loop, &p_gen) ) {
    return _open_loop(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_not, &p_gen) ) {
    return _open_not(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_pop, &p_gen) ) {
    return _open_pop(m, p_gen);
  }
  if ( u4_b_p(gen, u4_atom_tupl, &p_gen) ) {
    return _open_tupl(m, p_gen);
  }

  if ( u4_b_pq(gen, u4_atom_and, &p_gen, &q_gen) ) {
    return _open_and(m, p_gen, q_gen);
  }
#if 0
  if ( u4_b_pq(gen, u4_atom_coat, &p_gen, &q_gen) ) {
    return _open_coat(m, p_gen, q_gen);
  }
#endif
  if ( u4_b_pq(gen, u4_atom_fan, &p_gen, &q_gen) ) {
    return _open_fan(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_fix, &p_gen, &q_gen) ) {
    return _open_fix(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_fit, &p_gen, &q_gen) ) {
    return _open_fit(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_lamb, &p_gen, &q_gen) ) {
    return _open_lamb(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_nilk, &p_gen, &q_gen) ) {
    return _open_nilk(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_no, &p_gen, &q_gen) ) {
    return _open_no(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_or, &p_gen, &q_gen) ) {
    return _open_or(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_pose, &p_gen, &q_gen) ) {
    return _open_pose(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_clep, &p_gen, &q_gen) ) {
    return _open_clep(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_punt, &p_gen, &q_gen) ) {
    return _open_punt(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_roll, &p_gen, &q_gen) ) {
    return _open_roll(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_site, &p_gen, &q_gen) ) {
    return q_gen;
  }
  if ( u4_b_pq(gen, u4_atom_so, &p_gen, &q_gen) ) {
    return _open_so(m, p_gen, q_gen);
  }
  if ( u4_b_pq(gen, u4_atom_spot, &p_gen, &q_gen) ) {
    return q_gen;
  }
  
  if ( u4_b_pqr(gen, u4_atom_boot, &p_gen, &q_gen, &r_gen) ) {
    return _open_boot(m, p_gen, q_gen, r_gen);
  }
  if ( u4_b_pqr(gen, u4_atom_comb, &p_gen, &q_gen, &r_gen) ) {
    return _open_comb(m, p_gen, q_gen, r_gen);
  }
  if ( u4_b_pqr(gen, u4_atom_gear, &p_gen, &q_gen, &r_gen) ) {
    return _open_gear(m, p_gen, q_gen, r_gen);
  }
  if ( u4_b_pqr(gen, u4_atom_pull, &p_gen, &q_gen, &r_gen) ) {
    return _open_pull(m, p_gen, q_gen, r_gen);
  }
  if ( u4_b_pqr(gen, u4_atom_push, &p_gen, &q_gen, &r_gen) ) {
    return _open_push(m, p_gen, q_gen, r_gen);
  }
  if ( u4_b_pqr(gen, u4_atom_safe, &p_gen, &q_gen, &r_gen) ) {
    return r_gen;
  }
  if ( u4_b_pqr(gen, u4_atom_un, &p_gen, &q_gen, &r_gen) ) {
    return _open_un(m, p_gen, q_gen, r_gen);
  }

  return gen;
}
