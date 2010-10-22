/* fj/plow.c
**
** This file is in the public domain.
*/
#include "all.h"

/** Data structures.
**/
  /* Adaptation macros.
  */
    #define u2_brut(wir_r, cat, typ) \
      u2_burp(wir_r, cat, _dump_type(wir_r, typ))


  /* u2_loom_plow: central plow structure.
  */
    typedef struct {
      /* Set [*type *gene] in repo.
      */
      u2_pool fan;

      /* Set [*type] in verify.
      */
      u2_pool ver;

      /* Debug depth.
      */
      u2_atom bug;

      /* Trap - *(list &[p=*text q=*spot])
      */
      u2_noun meb;

      /* Book to memoize nest.
      */
      u2_book vus;

      /* Book to memoize null.
      */
      u2_book tyc;

      /* Book to memoize orth.
      */
      u2_book gam;

      /* Book to memoize show.
      */
      u2_book hos;

      /* Book to memoize play.
      */
      u2_book zor;

      /* Book to memoize make.
      */
      u2_book niq;

      /* Book to memoize safe.
      */
      u2_book fac;

      /* Book to memoize fine.
      */
      u2_book vom;

      /* Book to memoize open.
      */
      u2_book pon;

      /* Book to memoize find.
      */
      u2_book fin;

      /* Book to memoize half.
      */
      u2_book huf;
    } u2_loom_plow;

#     define   u2_plow_(wir_r, pat)  \
        *u2_at(u2_wire_plo_r(wir_r), u2_loom_plow, pat)
  

/** Forward declarations.
**/
  static void      _plow_trap(u2_ray wir_r, const char *msg);
  static u2_noun   _plow_fail(u2_ray wir_r, const char *msg);
  static u2_rope   _plow_rake(u2_ray wir_r, u2_gene gen);
  static u2_gene   _plow_open(u2_ray wir_r, u2_gene gen);

  /** *:dump
  **/
#if 0
    static u2_prep
    _dump_durb(u2_ray  wir_r,
               u2_rail bar);
#endif
    static u2_prep
    _dump_type(u2_ray  wir_r,
               u2_type typ);
    static u2_atom
    _dump_size(u2_ray  wir_r,
               u2_noun box);

  /** *:gull
  **/
    static u2_atom
    _gull_size(u2_ray  wir_r,
               u2_book dab);
    static u2_unit
    _gull_look(u2_ray  wir_r,
               u2_spec dab,
               u2_term cog);
    static u2_spec
    _gull_fill(u2_ray  wir_r,
               u2_spec dab,
               u2_menu sem);
  /** *:iris
  **/
    static u2_type
    _iris_burn(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe,
               u2_tack tac);
    static u2_flag
    _iris_cull(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe);
    static u2_plan
    _iris_find(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe,
               u2_term cog);
    static u2_tool
    _iris_fish(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe);
    static u2_type
    _iris_half(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe,
               u2_axis had);
    static u2_flag
    _iris_nest(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe,
               u2_type bon);
    static u2_type
    _iris_peek(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe,
               u2_axis bow);
    static void
    _iris_slip(u2_ray  wir_r,
               u2_type *sub,
               u2_rail *bar,
               u2_axis *axe,
               u2_axis had);
    static u2_type
    _iris_snap(u2_ray  wir_r,
               u2_type sub,
               u2_rail bar,
               u2_axis axe,
               u2_type bon);
  /** *:lark
  **/
    static u2_tack
    _lark_cram(u2_ray  wir_r,
               u2_type sub,
               u2_tack tac,
               u2_tack les);
    static u2_tack
    _lark_feed(u2_ray  wir_r,
               u2_type sub,
               u2_tack tac,
               u2_list mut);
    static u2_tack
    _lark_nuke(u2_ray  wir_r,
               u2_type sub,
               u2_tack tac,
               u2_rope rop,
               u2_type feg);
  /** *:lily
  **/
    static u2_tool
    _lily_cons(u2_ray  wir_r,
               u2_tool vor,
               u2_tool sed);
    static u2_tool
    _lily_comb(u2_ray  wir_r,
               u2_tool mal,
               u2_tool buz);
    static u2_tool
    _lily_flan(u2_ray  wir_r,
               u2_tool zeg,
               u2_tool dac);
    static u2_tool
    _lily_flor(u2_ray  wir_r,
               u2_tool bos,
               u2_tool nif);
    static u2_tool
    _lily_flop(u2_ray  wir_r,
              u2_tool zet);
    static u2_tool
    _lily_hike(u2_ray  wir_r,
               u2_axis axe,
               u2_list vix);
  /** *:open
  **/
    /* open:plow
    */
    static u2_gene
    _plow_open(u2_ray  wir_r,
               u2_gene gen);
  /** *:rose
  **/
    static u2_type
    _rose_edit(u2_ray  wir_r,
               u2_type sub,
               u2_list mut);
    static u2_type
    _rose_gain(u2_ray  wir_r,
               u2_type sub,
               u2_gene gen);
    static u2_type
    _rose_both(u2_ray  wir_r,
               u2_type sub,
               u2_type hoc);
    static u2_type
    _rose_eith(u2_ray  wir_r,
               u2_type sub,
               u2_type hoc);
    static u2_tool
    _rose_make(u2_ray  wir_r,
               u2_type sub,
               u2_gene gen);
    static u2_flag
    _rose_null(u2_ray  wir_r,
               u2_type sub);
    static u2_flag
    _rose_orth(u2_ray  wir_r,
               u2_type sub,
               u2_type ref);
    static u2_type
    _rose_play(u2_ray  wir_r,
               u2_type sub,
               u2_gene gen);
    static u2_type
    _rose_repo(u2_ray  wir_r,
               u2_type sub,
               u2_gene gen);
    static u2_plan
    _rose_seek(u2_ray  wir_r,
               u2_type sub,
               u2_gene gen);
    static u2_flag
    _rose_show(u2_ray  wir_r,
               u2_type sub,
               u2_gene gen);

/****   _lily: formula assembly.
****/
  /* cons:lily
  */
  static u2_tool
  _lily_cons(u2_ray  wir_r,
             u2_tool vur,
             u2_tool sed)
  {
    
    u2_noun p_vur, p_sed;

    if ( u2_yes == u2_as_p(vur, u2_nock_bone, &p_vur) && 
         u2_yes == u2_as_p(sed, u2_nock_bone, &p_sed) ) {
      return u2_bt(wir_r, u2_nock_bone, p_vur, p_sed);
    }
    else if ( u2_yes == u2_as_p(vur, u2_nock_frag, &p_vur) && 
              u2_yes == u2_as_p(sed, u2_nock_frag, &p_sed) &&
              !(u2_yes == u2_sing(_1, p_vur)) &&
              !(u2_yes == u2_sing(p_vur, p_sed)) &&
              (_0 == u2_nord(p_vur, p_sed)) )
    {
      u2_atom fub = u2_fj_op_div(wir_r, _2, p_vur);
      u2_atom nof = u2_fj_op_div(wir_r, _2, p_sed);

      if ( u2_yes == u2_sing(fub, nof) ) {
        return u2_bc(wir_r, u2_nock_frag, fub);
      }
    }
    return u2_bc(wir_r, vur, sed);
  }

  /* comb:lily
  */
  static u2_tool
  _lily_comb(u2_ray  wir_r,
             u2_tool mal,
             u2_tool buz)
  {
    
    u2_noun p_mal, q_mal, p_buz, q_buz, pp_buz, pq_buz;

    if ( u2_yes == u2_as_p(mal, u2_nock_frag, &p_mal) ) {
      if ( u2_yes == u2_as_p(buz, u2_nock_frag, &p_buz) ) {
        if ( (u2_nul == p_buz) ) {
          return buz;
        }
        return u2_bc(wir_r, u2_nock_frag, u2_fj_op_peg(wir_r, p_mal, p_buz));
      }
      else if ( u2_yes == u2_as_pq(buz, u2_nock_sail, &p_buz, &q_buz) &&
                u2_yes == u2_as_p(p_buz, u2_nock_frag, &pp_buz) &&
                u2_yes == u2_as_p(q_buz, u2_nock_frag, &pq_buz) )
      {
        return u2_bt
          (wir_r, u2_nock_sail, 
                 u2_bc(wir_r, u2_nock_frag, u2_fj_op_peg(wir_r, p_mal, pp_buz)),
                 u2_bc(wir_r, u2_nock_frag, u2_fj_op_peg(wir_r, p_mal, pq_buz)));
      }
    }
    else if ( u2_yes == u2_as_bush(mal, &p_mal, &q_mal) ) {
      if ( u2_yes == u2_dust(q_mal) && 
           u2_yes == u2_sing(_0, u2_h(q_mal)) &&
           u2_yes == u2_sing(_1, u2_t(q_mal)) )
      {
        return u2_bt(wir_r, u2_nock_gant, p_mal, buz);
      }
    }
    else if ( u2_yes == u2_as_p(buz, u2_nock_frag, &p_buz) ) {
      if ( u2_yes == u2_sing(_1, p_buz) ) {
        return mal;
      }
    }
    // return u2_bq(wir_r, u2_nock_sail, mal, u2_nock_bone, buz);
    return u2_bt(wir_r, u2_nock_flac, mal, buz);
  }

  /* flan:lily
  */
  static u2_tool
  _lily_flan(u2_ray  wir_r,
             u2_tool zeg,
             u2_tool dac)
  {
    

    if ( u2_yes == u2_sing(u2_nock_bone, u2_h(zeg)) ) {
      if ( (u2_nul == u2_t(zeg)) ) {
        return dac;
      }
      else return zeg;
    }
    else {
      if ( u2_yes == u2_sing(u2_nock_bone, u2_h(dac)) ) {
        if ( (u2_nul == u2_t(dac)) ) {
          return zeg;
        }
        else return dac;
      }
      else {
        return u2_bq
          (wir_r, u2_nock_trol, zeg, dac, u2_bc(wir_r, u2_nock_bone, u2_no));
      }
    }
  }

  /* flor:lily
  */
  static u2_tool
  _lily_flor(u2_ray  wir_r,
             u2_tool bos,
             u2_tool nif)
  {
    

    if ( u2_yes == u2_sing(u2_nock_bone, u2_h(bos)) ) {
      if ( (u2_nul == u2_t(bos)) ) {
        return bos;
      }
      else return nif;
    }
    else {
      if ( u2_yes == u2_sing(u2_nock_bone, u2_h(nif)) ) {
        if ( (u2_nul == u2_t(nif)) ) {
          return nif;
        }
        else return bos;
      }
      else {
        return u2_bq
          (wir_r, u2_nock_trol, bos, u2_bc(wir_r, u2_nock_bone, u2_yes), nif);
      }
    }
  }

  /* _lily_flop(): invert boolean.
  */
  static u2_tool
  _lily_flop(u2_ray  wir_r,
             u2_tool zet)
  {
    

    if ( u2_yes == u2_sing(u2_nock_bone, u2_h(zet)) ) {
      if ( (u2_yes == u2_t(zet)) ) {
        return u2_bc(wir_r, u2_nock_bone, u2_no);
      }
      else {
        c3_assert((u2_no == u2_t(zet)));

        return u2_bc(wir_r, u2_nock_bone, u2_yes);
      }
    }
    else {
      return u2_bq
        (wir_r, u2_nock_trol, 
               zet, 
               u2_bc(wir_r, u2_nock_bone, u2_no), 
               u2_bc(wir_r, u2_nock_bone, u2_yes));
    }
  }

  /* hike:lily:plow
  */
    static u2_axis 
    _lily_hike_axis_l(u2_ray  wir_r, 
                      u2_axis axis)
    {
      return u2_fj_op_add(wir_r, axis, axis);
    }
    static u2_axis 
    _lily_hike_axis_r(u2_ray  wir_r, 
                      u2_axis axis)
    {
      return u2_fj_op_inc(wir_r, _lily_hike_axis_l(wir_r, axis));
    }

    /* _lily_hike_belt_root(): convert (vix) to a list of root tools.
    */
    static u2_list
    _lily_hike_belt_root(u2_ray  wir_r,
                         u2_list vix)
    {
      if ( (u2_nul == vix) ) {
        return u2_nul;
      }
      else {
        u2_axis axis     = u2_h(u2_h(vix));
        u2_tool tool     = u2_t(u2_h(vix));
        u2_list list_tool = _lily_hike_belt_root(wir_r, u2_t(vix));

        if ( u2_yes == u2_sing(_1, axis) ) {
          return u2_bc(wir_r, tool, list_tool);
        }
        else return list_tool;
      }
    }

    /* _lily_hike_belt_l(): factor (vix) left.
    */
    static u2_list
    _lily_hike_belt_l(u2_ray  wir_r,
                      u2_list vix)
    {
      if ( (u2_nul == vix) ) {
        return u2_nul;
      }
      else {
        u2_axis axis       = u2_h(u2_h(vix));
        u2_tool tool       = u2_t(u2_h(vix));
        u2_list belt_l = _lily_hike_belt_l(wir_r, u2_t(vix));

        {
          if ( (_1 != axis) && u2_yes == u2_sing(_2, u2_fj_op_tip(axis)) ) {
            u2_axis axis_tap = u2_fj_op_tap(wir_r, axis);

            return u2_bc(wir_r, u2_bc(wir_r, axis_tap, tool), belt_l);
          }
          else return belt_l;
        }
      }
    }

    /* _lily_hike_belt_r(): factor (vix) right.
    */
    static u2_list
    _lily_hike_belt_r(u2_ray  wir_r,
                      u2_list vix)
    {
      if ( (u2_nul == vix) ) {
        return u2_nul;
      }
      else {
        u2_axis axis       = u2_h(u2_h(vix));
        u2_tool tool       = u2_t(u2_h(vix));
        u2_list belt_r = _lily_hike_belt_r(wir_r, u2_t(vix));

        {
          if ( (_1 != axis) && u2_yes == u2_sing(_3, u2_fj_op_tip(axis)) ) {
            u2_axis axis_tap = u2_fj_op_tap(wir_r, axis);

            return u2_bc(wir_r, u2_bc(wir_r, axis_tap, tool), belt_r);
          }
          else return belt_r;
        }
      }
    }
  static u2_tool
  _lily_hike(u2_ray  wir_r,
             u2_axis axe,
             u2_list vix)  /* (axis tool) */
  {
    if ( (u2_nul == vix) ) {
      return u2_bc(wir_r, u2_nock_frag, axe);
    }
    else {
      u2_list list_tool    = _lily_hike_belt_root(wir_r, vix);
      u2_list belt_l  = _lily_hike_belt_l(wir_r, vix);
      u2_list belt_r  = _lily_hike_belt_r(wir_r, vix);

      if ( !(u2_nul == list_tool) ) {
        return u2_h(list_tool);
      }
      else {
        u2_tool tool_l, tool_r;
        
        tool_l = _lily_hike(wir_r, _lily_hike_axis_l(wir_r, axe), belt_l);
        tool_r = _lily_hike(wir_r, _lily_hike_axis_r(wir_r, axe), belt_r);

        return _lily_cons(wir_r, tool_l, tool_r);
      }
    }
  }

/****   _open: macro expansion.
****/
#define _open_p(stem) \
  if ( u2_yes == u2_as_p(gen, c3__##stem, &p_gen) ) { \
    return _open_in_##stem(wir_r, p_gen); \
  }

#define _open_pq(stem) \
  if ( u2_yes == u2_as_pq(gen, c3__##stem, &p_gen, &q_gen) ) { \
    return _open_in_##stem(wir_r, p_gen, q_gen); \
  }

#define _open_pqr(stem) \
  if ( u2_yes == u2_as_pqr(gen, c3__##stem, &p_gen, &q_gen, &r_gen) ) {\
    return _open_in_##stem(wir_r, p_gen, q_gen, r_gen); \
  }

#define _open_pqrs(stem) \
  if ( u2_yes == u2_as_pqrs(gen, c3__##stem, &p_gen, &q_gen, &r_gen, &s_gen) ) {\
    return _open_in_##stem(wir_r, p_gen, q_gen, r_gen, s_gen); \
  }

#define _open_do_p(stem)  \
  static u2_gene _open_in_##stem \
    (u2_ray  wir_r, u2_noun p_gen)

#define _open_do_pq(stem)  \
  static u2_gene _open_in_##stem \
    (u2_ray  wir_r, u2_noun p_gen, u2_noun q_gen)

#define _open_do_pqr(stem)  \
  static u2_gene _open_in_##stem \
    (u2_ray  wir_r, u2_noun p_gen, u2_noun q_gen, u2_noun r_gen)

#define _open_do_pqrs(stem)  \
  static u2_gene _open_in_##stem \
    (u2_ray  wir_r, u2_noun p_gen, u2_noun q_gen, u2_noun r_gen, u2_noun s_gen)

  /* mast:open:plow
  */
    static u2_gene
    _open_mast(u2_ray, u2_gene);

    static u2_gene 
    _open_mast_fix(u2_ray  wir_r,
                   u2_gene gen,
                   u2_axis axe)
    {
      
      u2_noun p_gen, q_gen;

      if ( u2_yes == u2_as_pq(gen, c3__cast, &p_gen, &q_gen) ) {
        return _open_mast_fix(wir_r, p_gen, axe);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__twix, &p_gen, &q_gen) ) {
        return u2_bt
          (wir_r, 
           c3__twix,
           _open_mast_fix(wir_r, p_gen, u2_fj_op_peg(wir_r, axe, _2)),
           _open_mast_fix(wir_r, q_gen, u2_fj_op_peg(wir_r, axe, _3)));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__velt, &p_gen, &q_gen) ) {
        u2_tool ryx = u2_bc(wir_r, c3__frag, axe);

        return u2_bt
          (wir_r, 
           c3__flac,
           u2_bt(wir_r, 
                 c3__mack, 
                 u2_blip,
                 u2_bo
                  (wir_r,
                   u2_bc
                    (wir_r, 
                     ryx,
                     u2_bq
                      (wir_r, 
                       c3__fung, _open_mast(wir_r, q_gen), ryx, u2_nul)))),
           _open_mast_fix(wir_r, p_gen, axe));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__bran, &p_gen, &q_gen) ) {
        return u2_bt
          (wir_r, c3__bran, p_gen, _open_mast_fix(wir_r, q_gen, axe));
      }
      else if ( u2_yes == u2_as_p(gen, c3__teck, &p_gen) ) {
        return u2_bq
          (wir_r, c3__fung,
                p_gen,
                u2_bc(wir_r, c3__frag, axe),
                u2_nul);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__pock, &p_gen, &q_gen) ) {
        return _open_mast_fix(wir_r, q_gen, axe);
      } 
      else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
        return u2_bt(wir_r, c3__zemp, p_gen, _open_mast_fix(wir_r, q_gen, axe));
      }
      else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
        return u2_bc(wir_r, c3__zush, _open_mast_fix(wir_r, p_gen, axe));
      }
      else {
        u2_gene bog = _plow_open(wir_r, gen);

        if ( !(u2_yes == u2_sing(gen, bog)) ) {
          return _open_mast_fix(wir_r, bog, axe);
        }
        else {
          u2_tool ryx = u2_bc(wir_r, c3__frag, axe);

          return u2_bt
            (wir_r,
             c3__gram, 
             u2_bt(wir_r, c3__plin, gen, ryx), 
             ryx);
        }
      }
    }
  static u2_gene
  _open_mast(u2_ray  wir_r,
             u2_gene gen)
  {
    
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_as_pq(gen, c3__cast, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r,
         c3__gant,
         u2_bt(wir_r, c3__wost, c3__mave, q_gen),
         u2_bt(wir_r, c3__lome, u2_nul, _open_mast_fix(wir_r, p_gen, _4)));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__pock, &p_gen, &q_gen) ) {
      return _open_mast(wir_r, q_gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__teck, &p_gen) ) {
      return p_gen;
    }
    else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
      return u2_bt(wir_r, c3__zemp, p_gen, _open_mast(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
      return u2_bc(wir_r, c3__zush, _open_mast(wir_r, p_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__velt, &p_gen, &q_gen) ) {
      u2_tool ryx = u2_bc(wir_r, c3__frag, _4);

      return u2_bt
        (wir_r,
         c3__gant,
         u2_bt(wir_r, c3__wost, c3__mave, q_gen),
         u2_bt
          (wir_r,
           c3__lome,
           u2_nul,
           u2_bt
            (wir_r, 
             c3__flac,
              u2_bt
                (wir_r,
                 c3__mack,
                 u2_blip,
                 u2_bo
                  (wir_r,
                   u2_bc
                    (wir_r, 
                     ryx,
                     u2_bq
                      (wir_r, c3__fung, _open_mast(wir_r, q_gen), ryx, u2_nul)))),
             _open_mast_fix(wir_r, p_gen, _4))));
    }
    else {
      u2_gene bog = _plow_open(wir_r, gen);

      if ( !(u2_yes == u2_sing(gen, bog)) ) {
        return _open_mast(wir_r, bog);
      }
      else {
        return u2_bt
          (wir_r,
           c3__gant,
           u2_bt(wir_r, c3__wost, c3__mave, gen),
           u2_bt(wir_r, c3__lome, u2_nul, _open_mast_fix(wir_r, gen, _4)));
      }
    }
  }

  /* fist:open:plow
  */
    static u2_gene
    _open_fist(u2_ray, u2_gene);

    static u2_list
    _open_fist_a(u2_ray  wir_r,
                 u2_bank ban)
    {
      

      if ( (u2_nul == ban) ) {
        return u2_nul;
      }
      else {
        return u2_bc
          (wir_r, _open_fist(wir_r, u2_h(ban)), _open_fist_a(wir_r, u2_t(ban)));
      }
    }
  static u2_gene
  _open_fist(u2_ray  wir_r,
             u2_gene gen)
  {
    
    u2_noun p_gen, q_gen;

    if ( u2_yes == u2_as_p(gen, c3__bean, &p_gen) ) {
      return gen;
    }
    else if ( u2_yes == u2_as_pq(gen, c3__cast, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__cast, p_gen, _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__twix, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__twix, _open_fist(wir_r, p_gen), _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__velt, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__velt, _open_fist(wir_r, p_gen), _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__zemp, p_gen, _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
      return u2_bc
        (wir_r, c3__zush, _open_fist(wir_r, p_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__fist, &p_gen) ) {
      return _open_fist(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__bran, &p_gen, &q_gen) ) {
      return u2_bt
        (wir_r, c3__bran, p_gen, _open_fist(wir_r, q_gen));
    }
    else if ( u2_yes == u2_as_p(gen, c3__teck, &p_gen) ) {
      u2_noun pp_gen;

      if ( u2_yes == u2_as_p(p_gen, c3__rond, &pp_gen) ) {
        return u2_bt(wir_r, c3__teck, c3__rond, _open_fist_a(wir_r, pp_gen));
      }
      else {
        return u2_bc(wir_r, c3__bean, c3__blur);
      }
    }
    else if ( u2_yes == u2_as_pq(gen, c3__pock, &p_gen, &q_gen) ) {
      return _open_fist(wir_r, p_gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__bone, &p_gen) ) {
      return gen;
    }
    else {
      u2_gene bog = _plow_open(wir_r, gen);

      if ( !(u2_yes == u2_sing(gen, bog)) ) {
        return _open_fist(wir_r, bog);
      }
      else {
        return u2_bc(wir_r, c3__bean, c3__blur);
      }
    }
  }

  _open_do_p(bean)
  {
    

    if ( u2_yes == u2_sing(c3__atom, p_gen) ) {
      return u2_bt
        (wir_r, c3__cast, 
              u2_bt(wir_r, c3__vint, c3__bone, _0),
              u2_bc(wir_r, c3__bone, _0));
    }
    else if ( u2_yes == u2_sing(c3__blur, p_gen) ) {
      u2_noun dud = u2_bc(wir_r, c3__bone, u2_nul);

      return u2_bt
        (wir_r, c3__cast, 
              u2_bt(wir_r, c3__sail, dud, dud),
              dud);
    }
    else if ( u2_yes == u2_sing(c3__cell, p_gen) ) {
      return u2_bt
        (wir_r, c3__twix,
              u2_bc(wir_r, c3__bean, c3__blur),
              u2_bc(wir_r, c3__bean, c3__blur));
    }
    else if ( u2_yes == u2_sing(c3__flag, p_gen) ) {
      return u2_bt
        (wir_r, c3__cast,
              u2_bt(wir_r, c3__dust, c3__bone, _0),
              u2_bc(wir_r, c3__bone, u2_yes));
    }
    else if ( u2_yes == u2_sing(c3__null, p_gen) ) {
        return u2_bc(wir_r, c3__bone, u2_nul);
    }
    else return u2_bl_bail(wir_r);
  }

  _open_do_pq(lonk)
  {
    
    u2_noun beg = u2_bc(wir_r, c3__frag, _4);

    if ( (u2_nul == q_gen) ) {
      return _plow_fail(wir_r, "lonk");
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);

      if ( (u2_nul == tq_gen) ) {
        return iq_gen;
      }
      else {
        return u2_bt
          (wir_r,
           c3__gant,
           _open_in_lonk(wir_r, p_gen, tq_gen),
           u2_bt
            (wir_r,
             c3__gant,
             u2_bt(wir_r, c3__flac,
                        u2_bc(wir_r, c3__frag, _3),
                        iq_gen),
             u2_bt
              (wir_r, 
               c3__gant,
               u2_bc(wir_r, c3__frag, _8), 
               u2_bt
                (wir_r,
                 c3__sunt,
                 u2_nul,
                 u2_bq
                  (wir_r,
                   c3__bung,
                   u2_bt(wir_r,
                         c3__flac,
                         u2_bc(wir_r, c3__frag, (23)),
                         p_gen),
                   u2_bq
                    (wir_r,
                     c3__fung,
                     u2_bc(wir_r, c3__frag, _10),
                     beg,
                     u2_nul),
                  u2_bt
                    (wir_r,
                     c3__mack,
                     u2_bc(wir_r, 
                           u2_bc(wir_r, c3__frag, (22)), 
                           u2_nul),
                     u2_bc
                      (wir_r,
                       u2_bc(wir_r, beg, beg),
                       u2_nul)))))));
      }
    }
  }

    u2_noun
    _gath_a(u2_ray  wir_r,
            u2_noun r_gen)
    {
      if ( (u2_nul == r_gen) ) {
        return u2_nul;
      } 
      else {
        u2_noun ir_gen = u2_h(r_gen);
        u2_noun tr_gen = u2_t(r_gen);
        u2_noun pir_gen = u2_h(ir_gen);
        u2_noun qir_gen = u2_t(ir_gen);

        return u2_bc
          (wir_r, u2_bc(wir_r, pir_gen, 
                           u2_bt(wir_r, c3__flac, 
                                      u2_bc(wir_r, c3__frag, _3),
                                      qir_gen)),
               _gath_a(wir_r, tr_gen));
      }
    }
  _open_do_pqr(gath)
  {
    

    return u2_bt
      (wir_r, c3__gant,
            q_gen,
            u2_bt
              (wir_r,
               c3__mack,
               u2_bc(wir_r, u2_bc(wir_r, c3__frag, _2), p_gen),
               _gath_a(wir_r, r_gen)));
  }
  _open_do_p(prex)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__zike, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      if ( (u2_nul == tp_gen) ) {
        return ip_gen;
      } else {
        return u2_bt
          (wir_r, c3__twix, ip_gen, _open_in_prex(wir_r, tp_gen));
      }
    }
  }
 
  _open_do_pq(fung)
  {
    

    if ( (u2_nul == q_gen) ) {
      return u2_bt
        (wir_r, c3__flac, 
              p_gen,
              u2_bc(wir_r, c3__pane, u2_blip));
    } else {
      return u2_bq(wir_r, c3__mung, p_gen, c3__prex, q_gen);
    }
  }

  _open_do_pqr(hang)
  {
    return u2_bq
      (wir_r, c3__gath,
            p_gen,
            q_gen,
            u2_bo(wir_r,
                  u2_bc(wir_r,
                        u2_bc(wir_r, c3__frag, _4),
                        r_gen)));
  }

  _open_do_pq(mung)
  {
    

    return u2_bq
      (wir_r, c3__gath,
            u2_bc(wir_r, u2_blip, u2_nul),
            p_gen,
            u2_bo(wir_r,
                  u2_bc(wir_r,
                        u2_bc(wir_r, c3__frag, _4),
                        q_gen)));
  }

  _open_do_pq(velt)
  {
    

    return u2_bt
      (wir_r, c3__gant,
            q_gen,
            u2_bt
              (wir_r, c3__grel,
                    u2_bc(wir_r, c3__frag, _2),
                    u2_bo(wir_r,
                          u2_bc(wir_r,
                                u2_bt(wir_r, c3__flac,
                                           u2_bc(wir_r, c3__frag, _3),
                                           q_gen),
                                u2_bc(wir_r, c3__frag, _2)))));
  }

  _open_do_p(mast)
  {
    return _open_mast(wir_r, p_gen);
  }

  _open_do_p(wost)
  {
    return p_gen;
  }

  _open_do_p(zush)
  {
    return p_gen;
  }

  _open_do_pq(marg)
  {
    

    return u2_bq
      (wir_r, c3__trol,
            p_gen,
            u2_bc(wir_r, c3__zike, u2_nul),
            q_gen);
  }

  _open_do_p(vern)
  {
    

    return u2_bq
      (wir_r, c3__trol,
            p_gen,
            u2_bc(wir_r, c3__bone, u2_no),
            u2_bc(wir_r, c3__bone, u2_yes));
  }

  _open_do_p(slax)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__bone, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bt(wir_r, c3__twix, ip_gen, _open_in_slax(wir_r, tp_gen));
    }
  }

  _open_do_p(frag)
  {
    

    return u2_bt
      (wir_r, c3__mack, 
            u2_bc(wir_r, u2_bc(wir_r, c3__frag, p_gen), u2_nul),
            u2_nul);
  }

  _open_do_p(fist)
  {
    return _open_fist(wir_r, p_gen);
  }

  _open_do_pq(lome)
  {
    

    return u2_bt
      (wir_r, c3__pank,
            p_gen,
            u2_bo(wir_r, u2_bc(wir_r, u2_blip, q_gen)));
  }

  _open_do_pq(gnum)
  {
    

    return u2_bt
      (wir_r, c3__fung, q_gen, u2_bc(wir_r, p_gen, u2_nul));
  }

  _open_do_pqr(bung)
  {
    

    return u2_bc
      (wir_r, c3__fung, 
            u2_bq(wir_r, p_gen, q_gen, r_gen, u2_nul));
  }

  _open_do_pq(claf)
  {
    

    return u2_bt(wir_r, c3__flac, q_gen, p_gen);
  }

  _open_do_pqr(lort)
  {
    

    return u2_bq(wir_r, c3__trol, p_gen, r_gen, q_gen);
  }

  _open_do_pq(vamp)
  {
    

    return u2_bt
      (wir_r, c3__flac,
            u2_bt(wir_r, c3__lome, p_gen, q_gen),
            u2_bc(wir_r, c3__pane, u2_blip));
  }

  _open_do_p(zole)
  {
    

    return u2_bc(wir_r, c3__bone, p_gen);
  }

  _open_do_pq(moze)
  {
    

    if ( (u2_nul == q_gen) ) {
      return u2_bc(wir_r, c3__zike, u2_nul);
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);

#if 0
      if ( !(u2_nul == u2_plow_(wir_r, bug)) ) {
        u2_err(wir_r, "moze: iq_gen", iq_gen);
        u2_err(wir_r, "moze: fist", _open_fist(wir_r, iq_gen));
        u2_err(wir_r, "moze: mast", _open_mast(wir_r, iq_gen));
        printf("\n");
      }
#endif
      return u2_bq
        (wir_r,
         c3__trol,
         u2_bt(wir_r, c3__plin, _open_fist(wir_r, iq_gen), p_gen),
         u2_bq(wir_r, c3__fung, _open_mast(wir_r, iq_gen), p_gen, u2_nul),
         _open_in_moze(wir_r, p_gen, tq_gen));
    }
  }

  _open_do_p(rond)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__zike, u2_nul);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);

      return u2_bt
        (wir_r,
         c3__gant,
         u2_bc(wir_r, c3__mave, ip_gen),
         u2_bt(wir_r, c3__lome,
                    u2_nul,
                    u2_bt(wir_r, c3__moze, 
                               u2_bc(wir_r, c3__frag, _4),
                               p_gen)));
    }
  }

  _open_do_pq(frit)
  {
    

    return u2_bt
      (wir_r, c3__gant,
            p_gen,
            u2_bt
              (wir_r,
               c3__mack,
               u2_bo(wir_r, u2_bc(wir_r, c3__frag, _2)),
               u2_bo(wir_r,
                     u2_bc(wir_r,
                           u2_bc(wir_r, c3__frag, _4),
                           u2_bt(wir_r, c3__flac, 
                                      u2_bc(wir_r, c3__frag, _3),
                                      q_gen)))));
  }

  _open_do_p(pane)
  {
    

    return u2_bt
      (wir_r, c3__mack, 
            u2_bc(wir_r, u2_bc(wir_r, c3__pane, p_gen), u2_nul),
            u2_nul);
  }

  _open_do_pq(tang)
  {
    

    return u2_bt
      (wir_r, c3__gant, q_gen, p_gen);
  }

  _open_do_p(teck)
  {
    

    return u2_bc
      (wir_r, c3__wost,
            u2_bt(wir_r, c3__flac,
                       p_gen,
                       u2_bt(wir_r, c3__mack, 
                                  u2_bo(wir_r, u2_bc(wir_r, c3__pane, u2_blip)),
                                  u2_nul)));
  }

  _open_do_pq(gant)
  {
    

    return u2_bt
      (wir_r, c3__flac,
            u2_bt(wir_r, c3__twix, 
                       p_gen, 
                       u2_bc(wir_r, c3__frag, _1)),
            q_gen);
  }

  _open_do_pqrs(quax)
  {
    

    return u2_bt
      (wir_r, c3__twix,
            p_gen,
            u2_bt
              (wir_r, c3__twix,
                    q_gen,
                    u2_bt(wir_r, c3__twix, r_gen, s_gen)));
  }

  _open_do_p(chan)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__bone, u2_yes);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bq
        (wir_r, c3__trol,
              ip_gen,
              _open_in_chan(wir_r, tp_gen),
              u2_bc(wir_r, c3__bone, u2_no));
    }
  }

  _open_do_pq(grel)
  {
    

    if ( (u2_nul == q_gen) ) {
      return u2_bc(wir_r, c3__zike, u2_nul);
    }
    else {
      u2_noun iq_gen = u2_h(q_gen);
      u2_noun tq_gen = u2_t(q_gen);
      u2_noun piq_gen = u2_h(iq_gen);
      u2_noun qiq_gen = u2_t(iq_gen);

      return u2_bq
        (wir_r, 
         c3__trol,
         u2_bt(wir_r, c3__plin, _open_fist(wir_r, piq_gen), p_gen),
         u2_bt
          (wir_r, c3__flac,
                u2_bt(wir_r,
                      c3__stil,
                      piq_gen,
                      p_gen),
                qiq_gen),
         _open_in_grel(wir_r, p_gen, tq_gen));
    }
  }

  _open_do_pq(sunt)
  {
    

    return u2_bq
      (wir_r, c3__tash, 
            p_gen,
            u2_bc(wir_r, u2_blip, q_gen),
            u2_nul);
  }

  _open_do_pq(pock)
  {
    
    u2_noun rax = u2_bc(wir_r, c3__frag, _2);

    return u2_bt
      (wir_r,
       c3__gant,
       q_gen, 
       u2_bt
        (wir_r,
         c3__claf,
         rax,
         u2_bt(wir_r,
               c3__stil,
               u2_bt(wir_r, 
                     c3__flac, 
                     u2_bc(wir_r, c3__frag, _3), 
                     p_gen),
               rax)));
  }

  _open_do_p(dorn)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u2_bc(wir_r, c3__bone, u2_no);
    }
    else {
      u2_noun ip_gen = u2_h(p_gen);
      u2_noun tp_gen = u2_t(p_gen);

      return u2_bq
        (wir_r, c3__trol,
              ip_gen,
              u2_bc(wir_r, c3__bone, u2_yes),
              _open_in_dorn(wir_r, tp_gen));
    }
  }

  _open_do_pq(zemp)
  {
    return q_gen;
  }

  _open_do_pqr(fent)
  {
    

    return u2_bt
      (wir_r,
       c3__grel,
       p_gen,
       u2_bt
        (wir_r,
         u2_bc(wir_r, u2_bc(wir_r, c3__bone, u2_nul), q_gen),
         u2_bc(wir_r, u2_bc(wir_r, c3__bean, c3__cell), r_gen),
         u2_nul));
  }

  _open_do_pq(gram)
  {
    
    
    return u2_bq
      (wir_r, c3__trol, p_gen, q_gen, u2_bc(wir_r, c3__zike, u2_nul));
  }

  _open_do_pqr(trex)
  {
    

    return u2_bt
      (wir_r, c3__twix,
            p_gen,
            u2_bt(wir_r, c3__twix, q_gen, r_gen));
  }

  _open_do_pqrs(tung)
  {
    

    return u2_bq
      (wir_r, c3__fung, 
            p_gen, 
            q_gen,
            u2_bt(wir_r, r_gen, s_gen, u2_nul));
  }

  _open_do_p(mave)
  {
    

    return u2_bt
      (wir_r, c3__cast, 
            u2_bc(wir_r, c3__bean, c3__blur),
            p_gen);
  }

  _open_do_pq(yell)
  {
    

    return u2_bt(wir_r, c3__fung, p_gen, q_gen);
  }

  /* open:plow
  */
    u2_gene
    _plow_open_main(u2_ray  wir_r,
                    u2_gene gen)
    {
      u2_noun p_gen, q_gen, r_gen, s_gen;

      if ( u2_yes == u2_as_bush(gen, &p_gen, &q_gen) ) {
        u2_err(wir_r, "gen", gen);
        return _plow_fail(wir_r, "bad code");
      }
      else {
        _open_p   (mast);
        _open_p   (wost);
        _open_p   (zush);
        _open_pq  (marg);
        _open_p   (vern);
        _open_p   (frag);
        _open_pqr (hang);
        _open_p   (fist);
        _open_pq  (lome);
        _open_pq  (gnum);
        _open_pqr (bung);
        _open_pq  (claf);
        _open_pqr (lort);
        _open_pq  (vamp);
        _open_p   (zole);
        _open_p   (pane);
        _open_pq  (tang);
        _open_p   (teck);
        _open_pq  (gant);
        _open_pqrs(quax);
        _open_pq  (sunt);
        _open_pq  (zemp);
        _open_pq  (gram);
        _open_pqr (trex);
        _open_pqrs(tung);
        _open_p   (mave);

        _open_p   (bean);
        _open_pq  (lonk);
        _open_pqr (gath);
        _open_p   (prex);
        _open_pq  (fung);
        _open_pq  (mung);
        _open_pq  (velt);
        _open_p   (slax);
        _open_pq  (moze);
        _open_p   (rond);
        _open_pq  (frit);
        _open_p   (chan);
        _open_pq  (grel);
        _open_pq  (pock);
        _open_p   (dorn);
        _open_pqr (fent);
        _open_pq  (yell);

        return gen;
      }
    }
  static u2_gene
  _plow_open(u2_ray  wir_r,
             u2_gene gen)
  {
    u2_weak zax = u2_fj_book_get(gen, u2_plow_(wir_r, pon));

    if ( u2_none != zax ) {
      return zax;
    }
    else {
      zax = _plow_open_main(wir_r, gen);

#if 0
      if ( !(u2_nul == u2_plow_(wir_r, bug)) && u2_yes == u2_as_p(gen, c3__teck, 0) ) {
        u2_err(wir_r, "open: gen", gen);
        u2_err(wir_r, "open: zax", zax);
        printf("\n");
      }
#endif
      u2_plow_(wir_r, pon) = u2_fj_book_add(wir_r, gen, zax, u2_plow_(wir_r, pon));
      return zax;
    }
  }

/****   _gull: battery symbol table.
****/
  /* size:gull:plow
  */
  static u2_atom
  _gull_size(u2_ray  wir_r,
             u2_book dab)
  {
    if ( (u2_nul == dab) ) {
      return _0;
    } else {
      u2_noun n_dab, l_dab, r_dab;

      u2_as_trel(dab, &n_dab, &l_dab, &r_dab);

      return u2_fj_op_inc(wir_r, u2_fj_op_add(wir_r, _gull_size(wir_r, l_dab),
                                           _gull_size(wir_r, r_dab)));
    }
  }

  /* fill:gull:plow
  */
  static u2_spec
  _gull_fill(u2_ray  wir_r,
             u2_book dab,
             u2_menu sem)
  {
    return u2_fj_book_add_list(wir_r, sem, dab);
  }

  /* _ord_tag_simple():
  **
  **    Return 1 iff (tag_l tag_r) are in correct simple order.
  **
  **    Trip if (tag_l tag_r) are equal.
  */
  c3_t
  _ord_tag_simple(u2_noun tag_l, u2_noun tag_r)
  {
    return (_0 == u2_nord(tag_l, tag_r));
  }

  /* _ord_tag_tree():
  **
  **    Return 1 iff (hog_l hog_r) are in correct tree order (mug).
  **
  **    Stop iff (hog_l hog_r) are equal.
  */
  c3_t
  _ord_tag_tree(u2_noun tag_l, u2_noun tag_r)
  {
    c3_w mug_l = u2_mug(tag_l);
    c3_w mug_r = u2_mug(tag_r);

    if ( mug_l == mug_r ) {
      return _ord_tag_simple(tag_l, tag_r);
    }
    else return (mug_l < mug_r);
  }

  /* look:gull:plow
  */
    u2_unit
    _gull_look_a(u2_ray  wir_r,
                 u2_spec dab,
                 u2_term cog,
                 u2_axis axe)
    {
      

      if ( (u2_nul == dab) ) {
        return u2_nul;
      }
      else {
        u2_noun n_dab, l_dab, r_dab, pn_dab, qn_dab;

        u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
        pn_dab = u2_h(n_dab);
        qn_dab = u2_t(n_dab);

        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          if ( u2_yes == u2_sing(cog, pn_dab) ) {
            return u2_bt(wir_r, u2_nul, axe, qn_dab);
          }
          else return u2_nul;
        }
        else if ( (u2_nul == l_dab) ) {
          if ( u2_yes == u2_sing(cog, pn_dab) ) {
            return u2_bt(wir_r, u2_nul, u2_fj_op_peg(wir_r, axe, _2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return u2_nul;
          }
          else {
            return _gull_look_a(wir_r, r_dab, cog, u2_fj_op_peg(wir_r, axe, _3));
          }
        }
        else if ( (u2_nul == r_dab) ) {
          if ( u2_yes == u2_sing(cog, pn_dab) ) {
            return u2_bt(wir_r, u2_nul, u2_fj_op_peg(wir_r, axe, _2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return _gull_look_a(wir_r, l_dab, cog, u2_fj_op_peg(wir_r, axe, _3));
          }
          else {
            return u2_nul;
          }
        }
        else {
          if ( u2_yes == u2_sing(cog, pn_dab) ) {
            return u2_bt(wir_r, u2_nul, u2_fj_op_peg(wir_r, axe, _2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return _gull_look_a(wir_r, l_dab, cog, u2_fj_op_peg(wir_r, axe, _6));
          }
          else {
            return _gull_look_a(wir_r, r_dab, cog, u2_fj_op_peg(wir_r, axe, _7));
          }
        }
      }
    }
  static u2_unit
  _gull_look(u2_ray  wir_r,
             u2_spec dab,
             u2_term cog)
  {
    return _gull_look_a(wir_r, dab, cog, _1);
  }


/****   _iris: type system core.
****/
    /** Forward declarations.
    **/
      
  /* burn:iris:rose:plow
  */
    u2_type
    _iris_burn_sint(u2_ray, u2_type, u2_rail, u2_axis, u2_tack);

    u2_type
    _iris_burn_dext(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_tack tac)
    {
      
      u2_noun p_tac, q_tac;
      u2_noun p_sut, q_sut, qrs_sut;

      if ( (u2_nul == tac) ) {
        return sut;
      }
      else if ( u2_yes == u2_as_p(tac, c3__leaf, &p_tac) ) {
        return _iris_snap(wir_r, sut, bar, axe, p_tac);
      }
      else if ( u2_yes == u2_as_pq(tac, c3__bran, &p_tac, &q_tac) ) {
        if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
          if ( u2_yes == u2_sing(p_sut, p_tac) ) {
            return u2_bt
              (wir_r, 
               c3__face, 
               p_tac, 
               _iris_burn_dext(wir_r, q_sut, bar, axe, q_tac));
          }
          else {
            return u2_bt
              (wir_r,
               c3__face,
               p_tac,
               _iris_burn_dext(wir_r, sut, bar, axe, q_tac));
          }
        }
        else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ||
                  u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ||
                  u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) )
        {
          return _iris_burn_sint(wir_r, sut, bar, axe, tac);
        }
        else {
          return u2_bt
            (wir_r,
             c3__face,
             p_tac,
             _iris_burn_dext(wir_r, sut, bar, axe, q_tac));
        }
      }
      else if ( u2_yes == u2_as_pq(tac, c3__pair, &p_tac, &q_tac) ) {
        if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
          u2_noun l_sut, l_bar, l_axe;
          u2_noun r_sut, r_bar, r_axe;

          l_sut = sut; l_bar = bar; l_axe = axe;
          _iris_slip(wir_r, &l_sut, &l_bar, &l_axe, _2);

          r_sut = sut; r_bar = bar; r_axe = axe;
          _iris_slip(wir_r, &r_sut, &r_bar, &r_axe, _3);

          return u2_bt
            (wir_r,
             c3__cell,
             _iris_burn_dext(wir_r, l_sut, l_bar, l_axe, p_tac),
             _iris_burn_dext(wir_r, r_sut, r_bar, r_axe, q_tac));
        }
        else if ( u2_yes == u2_as_pq(sut, c3__core, &p_sut, &qrs_sut) ) {
          u2_noun l_sut, l_bar, l_axe;
          u2_type ham;

          l_sut = sut; l_bar = bar; l_axe = axe;
          _iris_slip(wir_r, &l_sut, &l_bar, &l_axe, _2);

          ham = _iris_burn_dext(wir_r, l_sut, l_bar, l_axe, p_tac);

          if ( (u2_nul == q_tac) ) {
            return u2_bt
              (wir_r, c3__core, ham, qrs_sut);
          } else {
            return u2_bt
              (wir_r, c3__cell, ham, c3__blur);
          }
        }
        else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ||
                  u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ||
                  u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ||
                  u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) )
        {
          return _iris_burn_sint(wir_r, sut, bar, axe, tac);
        }
        else {
          u2_noun poq = u2_bt
            (wir_r,
             c3__cell,
             _iris_half(wir_r, sut, bar, axe, _2),
             _iris_half(wir_r, sut, bar, axe, _3));

          return _iris_burn_dext(wir_r, poq, bar, axe, tac);
        }
      }
      else return u2_bl_bail(wir_r);
    }
    u2_unit
    _iris_burn_swim(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_tack tac)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        u2_unit yop = _iris_burn_swim(wir_r, p_sut, bar, axe, tac);
        u2_unit paf = _iris_burn_swim(wir_r, q_sut, bar, axe, tac);

        if ( (u2_nul == yop) ) {
          return paf;
        } else if ( (u2_nul == paf) ) {
          return yop;
        }
        else {
          return u2_bc
            (wir_r,
             u2_nul,
             _rose_eith(wir_r, u2_t(yop), u2_t(paf)));
        }
      }
      else {
        if ( u2_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u2_nul;
        }
        else {
          return u2_bc
            (wir_r, u2_nul, _iris_burn_dext(wir_r, sut, bar, axe, tac));
        }
      }
    }
    u2_type
    _iris_burn_sint(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_tack tac)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        return u2_bt
          (wir_r, 
           c3__face,
           p_sut,
           _iris_burn_dext(wir_r, q_sut, bar, axe, tac));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        return u2_t(_iris_burn_swim(wir_r, sut, bar, axe, tac));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        return _rose_both
          (wir_r, 
           _iris_burn_dext(wir_r, q_sut, u2_bc(wir_r, p_sut, bar), axe, tac),
           _iris_burn_dext(wir_r, p_sut, bar, axe, tac));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        return _iris_burn_dext
          (wir_r, _rose_repo(wir_r, p_sut, q_sut), bar, axe, tac); 
      }
      else return u2_bl_bail(wir_r);
    }
  static u2_type
  _iris_burn(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe,
             u2_tack tac)
  {
    return _iris_burn_dext(wir_r, sut, bar, axe, tac);
  }

  /* cull:iris:rose:plow
  */
    u2_flag
    _iris_cull_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_rail bar,
                 u2_axis axe)
    {
      if ( (u2_nul == bar) ) {
        return u2_no;
      }
      else if ( u2_so(_rose_orth(wir_r, sut, u2_h(bar))) ) {
        return u2_yes;
      }
      else return _iris_cull_a(wir_r, sut, u2_t(bar), axe);
    }
  static u2_flag
  _iris_cull(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe)
  {
    if ( u2_so(_rose_null(wir_r, sut)) ) {
      return u2_yes;
    }
    else {
      return _iris_cull_a(wir_r, sut, bar, axe);
    }
  }

  /* find:iris:rose:plow
  */
    u2_unit _iris_find_main
      (u2_ray, u2_type, u2_rail, u2_axis, u2_pool, u2_term);

    u2_unit
    _iris_find_half(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool gil,
                    u2_term cog,
                    u2_axis cap)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, cap);

      return _iris_find_main(wir_r, sut, bar, axe, gil, cog);
    }
    u2_unit
    _iris_find_swim(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool gil,
                    u2_term cog)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        u2_unit yop = _iris_find_swim(wir_r, p_sut, bar, axe, gil, cog);
        u2_unit paf = _iris_find_swim(wir_r, q_sut, bar, axe, gil, cog);

        if ( (u2_nul == yop) ) {
          return paf;
        }
        else if ( (u2_nul == paf) ) {
          return yop;
        }
        else {
          u2_unit lep = u2_t(yop);
          u2_unit gam = u2_t(paf);
          
          if ( (u2_nul == lep) ) {
            if ( (u2_nul == gam) ) {
              return u2_nul;
            }
            else {
              u2_burp(wir_r, "cog", u2_fj_prep_textual(wir_r, cog));
              return _plow_fail(wir_r, "fork conflict a");
            }
          }
          else if ( (u2_nul == gam) ) {
            return _plow_fail(wir_r, "fork conflict b");
          }
          else {
            u2_plan u_lep = u2_t(lep);
            u2_plan u_gam = u2_t(gam);

            if ( u2_yes == u2_sing(u2_h(u_lep), u2_h(u_gam)) &&
                 u2_yes == u2_sing(u2_h(u2_t(u_lep)), u2_h(u2_t(u_gam))) )
            {
              return u2_bt
                (wir_r,
                 u2_nul,
                 u2_nul,
                 u2_bt
                  (wir_r, 
                   u2_h(u_lep),
                   u2_h(u2_t(u_lep)),
                   _rose_eith(wir_r, u2_t(u2_t(u_lep)), u2_t(u2_t(u_gam)))));
            }
            else {
              u2_burp(wir_r, "cog", u2_fj_prep_textual(wir_r, cog));
              return _plow_fail(wir_r, "fork conflict c");
            }
          }
        }
      }
      else {
        if ( u2_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u2_nul;
        }
        else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) &&
                  u2_fj_pool_in(u2_bc(wir_r, bar, sut), gil) )
        {
          return u2_nul;
        }
        else {
          return u2_bc
            (wir_r, u2_nul, _iris_find_main(wir_r, sut, bar, axe, gil, cog));
        }
      }
    }
    u2_unit
    _iris_find_main_a(u2_ray  wir_r,
                      u2_type sut,
                      u2_rail bar,
                      u2_axis axe,
                      u2_pool gil,
                      u2_term cog)
    {
      
      u2_noun p_sut, q_sut, r_sut, s_sut;

      if ( u2_yes == u2_sing(c3__atom, sut) ||
           u2_yes == u2_sing(c3__blur, sut) ||
           u2_yes == u2_sing(c3__blot, sut) ||
           u2_yes == u2_as_p(sut, c3__cube, &p_sut) )
      {
        return u2_nul;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        u2_unit taf = _iris_find_half(wir_r, sut, bar, axe, gil, cog, _2);
        u2_unit bov = _iris_find_half(wir_r, sut, bar, axe, gil, cog, _3);

        if ( (u2_nul == taf) ) {
          return bov;
        }
        else if ( (u2_nul == bov) ) {
          return taf;
        }
        else {
#if 0
          u2_burp(wir_r, "cog", u2_fj_prep_textual(wir_r, cog));
          return _plow_fail(wir_r, "cell conflict");
#else
          return taf;
#endif
        }
      }
      else if ( u2_yes == u2_as_pqrs(sut, c3__core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
        u2_spec dab = s_sut;
        u2_unit zem;

        zem = _gull_look(wir_r, dab, cog);
        if ( (u2_nul == zem) ) {
          return _iris_find_half(wir_r, sut, bar, axe, gil, cog, _2);
        }
        else return 
          u2_bc
            (wir_r, 
             u2_nul, 
             u2_bt
              (wir_r, 
               axe, 
               u2_bq
                (wir_r, 
                 u2_nul, 
                 u2_fj_op_peg(wir_r, _3, u2_h(u2_t(zem))),
                 sut,
                 u2_t(u2_t(zem))),
               sut));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_sing(cog, p_sut) ) {
          return u2_bq
            (wir_r, u2_nul, axe, u2_nul, q_sut);
        }
        else return u2_nul;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        u2_unit foz = _iris_find_swim(wir_r, sut, bar, axe, gil, cog);

        if ( (u2_nul == foz) ) {
          return u2_nul; 
        }
        return u2_t(foz);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        u2_unit hax = _iris_find_main
          (wir_r, p_sut, bar, axe, gil, cog);
        u2_unit yor = _iris_find_main
          (wir_r, q_sut, u2_bc(wir_r, p_sut, bar), axe, gil, cog);

        if ( (u2_nul == yor) ) {
          if ( (u2_nul == hax) ) {
            return u2_nul;
          }
          else {
            u2_noun u_hax = u2_t(hax);
            u2_noun pu_hax = u2_h(u_hax);
            u2_noun qu_hax = u2_h(u2_t(u_hax));
            u2_noun ru_hax = u2_t(u2_t(u_hax));

            return u2_bc
              (wir_r, 
               u2_nul,
               u2_bt
                (wir_r,
                 pu_hax,
                 qu_hax,
                 _rose_both
                  (wir_r,
                   _iris_peek
                    (wir_r, q_sut, u2_bc(wir_r, p_sut, bar), axe, pu_hax),
                   ru_hax)));
          }
        }
        else {
          u2_noun u_yor = u2_t(yor);
          u2_noun pu_yor = u2_h(u_yor);
          u2_noun qu_yor = u2_h(u2_t(u_yor));
          u2_noun ru_yor = u2_t(u2_t(u_yor));

          if ( (u2_nul == hax) ) {
            return u2_bc
              (wir_r, 
               u2_nul,
               u2_bt
                (wir_r,
                 pu_yor,
                 qu_yor,
                 _rose_both
                  (wir_r,
                   ru_yor,
                   _iris_peek(wir_r, p_sut, bar, axe, pu_yor))));
          }
          else {
            u2_noun u_hax = u2_t(hax);
            u2_noun pu_hax = u2_h(u_hax);
            u2_noun qu_hax = u2_h(u2_t(u_hax));
            u2_noun ru_hax = u2_t(u2_t(u_hax));

            if ( !(u2_yes == u2_sing(pu_hax, pu_yor) && u2_yes == u2_sing(qu_hax, qu_yor)) ) {
              ru_hax = _iris_peek(wir_r, p_sut, bar, axe, pu_yor);
            }
            return u2_bc
              (wir_r, 
               u2_nul,
               u2_bt
                (wir_r,
                 pu_yor,
                 qu_yor,
                 _rose_both(wir_r, ru_yor, ru_hax)));
          }
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        u2_noun dit = u2_bc(wir_r, bar, sut);

        if ( u2_fj_pool_in(dit, gil) ) {
          return u2_nul;
        } 
        else {
          return _iris_find_main
            (wir_r,
             _rose_repo(wir_r, p_sut, q_sut), 
             bar,
             axe,
             u2_fj_pool_add(wir_r, dit, gil), 
             cog);
        }
      }
      else {
        return u2_bl_bail(wir_r);
      }
    }
    u2_unit
    _iris_find_main(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool gil,
                    u2_term cog)
    {
      
      u2_noun mum  = u2_bu(wir_r, sut, bar, axe, gil, cog);
      u2_weak zod  = u2_fj_book_get(mum, u2_plow_(wir_r, fin));

      if ( zod != u2_none ) {
        return zod;
      }
      else {
        u2_unit gur = _iris_find_main_a
          (wir_r, sut, bar, axe, gil, cog);

        u2_plow_(wir_r, fin) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, fin));
        return gur;
      }
    }
  static u2_plan
  _iris_find(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe,
             u2_term cog)
  {
    u2_unit fyg = _iris_find_main(wir_r, sut, bar, axe, u2_nul, cog);

    if ( (u2_nul == fyg) ) {
      u2_burp(wir_r, "name", u2_fj_prep_textual(wir_r, cog));
      u2_burp(wir_r, "sut", _dump_type(wir_r, sut));
      return _plow_fail(wir_r, "not found");
    }
    return u2_t(fyg);
  }

  /* fish:iris:rose:plow
  */
    u2_tool
    _iris_fish_main(u2_ray, u2_type, u2_rail, u2_axis, u2_pool);

    u2_tool
    _iris_fish_slip(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool vit,
                    u2_axis had)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, had);
      return _iris_fish_main(wir_r, sut, bar, axe, vit);
    }
    u2_unit
    _iris_fish_swim(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool vit)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        u2_unit doz = _iris_fish_swim(wir_r, p_sut, bar, axe, vit);
        u2_unit ryg = _iris_fish_swim(wir_r, q_sut, bar, axe, vit);
      
        if ( (u2_nul == doz) ) return ryg;
        else if ( (u2_nul == ryg) ) return doz;
        else return u2_bc
          (wir_r, u2_nul, 
                _lily_flor(wir_r, u2_t(doz), u2_t(ryg)));
      }
      else {
        if ( u2_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u2_nul;
        }
        else {
          return u2_bc
            (wir_r, u2_nul, _iris_fish_main(wir_r, sut, bar, axe, vit));
        }
      }
    }
    u2_tool
    _iris_fish_main(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool vit)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_sing(c3__atom, sut) ) {
        return _lily_flop
          (wir_r, u2_bt(wir_r, u2_nock_dust, u2_nock_frag, axe));
      }
      else if ( u2_yes == u2_sing(c3__blur, sut) ) {
        return u2_bc(wir_r, u2_nock_bone, u2_yes);
      }
      else if ( u2_yes == u2_sing(c3__blot, sut) ) {
        return u2_bc(wir_r, u2_nock_bone, u2_no);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__core, &p_sut, &q_sut) ) {
        return u2_bc(wir_r, u2_nock_frag, _0);
      }
      else if ( u2_yes == u2_as_p(sut, c3__cube, &p_sut) ) {
        return u2_bt
          (wir_r, u2_nock_sing, 
                u2_bc(wir_r, u2_nock_bone, p_sut),
                u2_bc(wir_r, u2_nock_frag, axe));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        return _lily_flan
          (wir_r,
           u2_bt(wir_r, u2_nock_dust, u2_nock_frag, axe),
           _lily_flan
            (wir_r, _iris_fish_slip(wir_r, sut, bar, axe, vit, _2),
                _iris_fish_slip(wir_r, sut, bar, axe, vit, _3)));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        return _iris_fish_main(wir_r, q_sut, bar, axe, vit);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        return u2_t(_iris_fish_swim(wir_r, sut, bar, axe, vit));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        return _lily_flan
          (wir_r, 
           _iris_fish_main(wir_r, p_sut, bar, axe, vit),
           _iris_fish_main(wir_r, q_sut, u2_bc(wir_r, p_sut, bar), axe, vit));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        u2_noun duq = u2_bc(wir_r, sut, bar);

        if ( u2_fj_pool_in(duq, vit) ) {
          return _plow_fail(wir_r, "fish recursion");
        } 
        else {
          return _iris_fish_main
            (wir_r, _rose_repo(wir_r, p_sut, q_sut),
                bar,
                axe,
                u2_fj_pool_add(wir_r, duq, vit));
        }
      }
      else {
        return u2_bl_bail(wir_r);
      }
    }
  static u2_tool
  _iris_fish(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe)
  {
    return _iris_fish_main(wir_r, sut, bar, axe, u2_nul);
  }

  /* half:iris:rose:plow
  */
    static u2_unit
    _iris_half_swim(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_axis had)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        u2_unit doz = _iris_half_swim(wir_r, p_sut, bar, axe, had);
        u2_unit ryg = _iris_half_swim(wir_r, q_sut, bar, axe, had);

        if ( (u2_nul == doz) ) return ryg;
        else if ( (u2_nul == ryg) ) return doz;
        else return u2_bc
          (wir_r, u2_nul, _rose_eith(wir_r, u2_t(doz), u2_t(ryg)));
      }
      else {
        if ( u2_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u2_nul;
        }
        else {
          return u2_bc
            (wir_r, u2_nul, _iris_half(wir_r, sut, bar, axe, had));
        }
      }
    }
    static u2_type
    _iris_half_main(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_axis had)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_sing(c3__atom, sut) ) {
        return c3__blot;
      }
      else if ( u2_yes == u2_sing(c3__blot, sut) ) {
        return c3__blot;
      }
      else if ( u2_yes == u2_sing(c3__blur, sut) ) {
        return c3__blur;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_sing(_2, had) ) {
          return p_sut;
        } else return q_sut;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__core, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_sing(_2, had) ) {
          return p_sut;
        } else return c3__blur;
      }
      else if ( u2_yes == u2_as_p(sut, c3__cube, &p_sut) )  {
        if ( u2_yes == u2_stud(p_sut) ) {
          return c3__blot;
        }
        else if ( u2_yes == u2_sing(_2, had) ) {
          return u2_bc(wir_r, c3__cube, u2_h(p_sut));
        } else return u2_bc(wir_r, c3__cube, u2_t(p_sut));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        return _iris_half(wir_r, q_sut, bar, axe, had);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        u2_unit pez = _iris_half_swim(wir_r, sut, bar, axe, had);

        if ( (u2_nul == pez) ) {
          return c3__blot;
        }
        return u2_t(pez);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        return _rose_both
          (wir_r, 
           _iris_half(wir_r, q_sut, u2_bc(wir_r, p_sut, bar), axe, had),
           _iris_half(wir_r, p_sut, bar, axe, had));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        return _iris_half(wir_r, _rose_repo(wir_r, p_sut, q_sut), bar, axe, had);
      }
      else return u2_bl_bail(wir_r);
    }

  static u2_type
  _iris_half(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe,
             u2_axis had)
  {
    
    u2_noun mum = u2_bt(wir_r, sut, bar, had);  /* axe is not used */
    u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, huf));

    if ( zod != u2_none ) {
      return zod;
    }
    else {
      u2_type gur = _iris_half_main(wir_r, sut, bar, axe, had);

      u2_plow_(wir_r, huf) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, huf));
      return gur;
    }
  }

  /* nest:iris:rose:plow
  */
    u2_flag
    _iris_nest_sint
      (u2_ray, u2_type, u2_rail, u2_axis, u2_pool, u2_type, u2_rail, u2_axis); 
    u2_flag
    _iris_nest_dext
      (u2_ray, u2_type, u2_rail, u2_axis, u2_pool, u2_type, u2_rail, u2_axis); 

    u2_flag
    _iris_nest_dext_slip(u2_ray  wir_r,
                         u2_type sut,
                         u2_rail bar,
                         u2_axis axe,
                         u2_pool gil,
                         u2_type bon,
                         u2_rail nef,
                         u2_axis ful,
                         u2_axis had)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, had);
      _iris_slip(wir_r, &bon, &nef, &ful, had);

      return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
    }
    u2_flag
    _iris_nest_dext_swim(u2_ray  wir_r,
                         u2_type sut,
                         u2_rail bar,
                         u2_axis axe,
                         u2_pool gil,
                         u2_type bon,
                         u2_rail nef,
                         u2_axis ful)
    {
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        return u2_or
          (_iris_nest_dext_swim(wir_r, p_sut, bar, axe, gil, bon, nef, ful),
           _iris_nest_dext_swim(wir_r, q_sut, bar, axe, gil, bon, nef, ful));
      }
      else {
        if ( u2_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u2_no;
        }
        else return _iris_nest_dext
          (wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
    }

    u2_flag
    _iris_nest_dext_main(u2_ray  wir_r,
                         u2_type sut,
                         u2_rail bar,
                         u2_axis axe,
                         u2_pool gil,
                         u2_type bon,
                         u2_rail nef,
                         u2_axis ful)
    {
      
      u2_noun p_sut, q_sut, qrs_sut;
      u2_noun p_bon, q_bon, qrs_bon;

      if ( u2_yes == u2_sing(sut, c3__atom) ) {
        if ( u2_yes == u2_sing(bon, c3__atom) ) {
          return u2_yes;
        }
        else if ( u2_yes == u2_as_p(bon, c3__cube, &p_bon) ) {
          return u2_stud(p_bon);
        }
        else return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u2_yes == u2_sing(sut, c3__blur) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__core, &p_sut, &qrs_sut) ) {
        if ( u2_yes == u2_as_pq(bon, c3__core, &p_bon, &qrs_bon) ) {
          return u2_and
            (u2_sing(qrs_sut, qrs_bon),
             _iris_nest_dext_slip
                (wir_r, sut, bar, axe, gil, bon, nef, ful, _2));
        }
        else return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_as_pq(bon, c3__cell, &p_bon, &q_bon) ) {
          return u2_and
            (_iris_nest_dext_slip
                (wir_r, sut, bar, axe, gil, bon, nef, ful, _2),
             _iris_nest_dext_slip
                (wir_r, sut, bar, axe, gil, bon, nef, ful, _3));
        }
        else {
          return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u2_yes == u2_as_p(sut, c3__cube, &p_sut) ) {
        if ( u2_yes == u2_as_p(bon, c3__cube, &p_bon) ) {
          return u2_sing(p_sut, p_bon);
        }
        else return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        return _iris_nest_dext(wir_r, q_sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_stud(bon) ||
             u2_yes == u2_as_pq(bon, c3__cell, &p_bon, &q_bon) ||
             u2_yes == u2_as_pq(bon, c3__core, &p_bon, &q_bon) ||
             u2_yes == u2_as_p(bon, c3__cube, &p_bon) ) 
        {
          return _iris_nest_dext_swim
            (wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
        else {
          return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        u2_rail buz = u2_bc(wir_r, p_sut, bar);

        return u2_and
          (_iris_nest_dext(wir_r, p_sut, bar, axe, gil, bon, nef, ful),
           _iris_nest_dext(wir_r, q_sut, buz, axe, gil, bon, nef, ful));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        u2_noun duq = u2_bq(wir_r, sut, bar, bon, nef);

        if ( u2_fj_pool_in(duq, gil) ) {
          return u2_yes;
        } else {
          return _iris_nest_dext
            (wir_r, _rose_repo(wir_r, p_sut, q_sut),
                bar,
                axe,
                u2_fj_pool_add(wir_r, duq, gil),
                bon, 
                nef, 
                ful);
        }
      }
      else {
        return u2_bl_bail(wir_r);
      }
    }
    u2_flag
    _iris_nest_dext(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool gil,
                    u2_type bon,
                    u2_rail nef,
                    u2_axis ful)
    {
      
    
      if ( u2_yes == u2_sing(sut, bon) ) {
        return u2_yes;
      }
      else {
        u2_noun mum = u2_bq(wir_r, bar, sut, nef, bon);
        u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, vus));

        if ( zod != u2_none ) {
          return zod;
        }
        else {
          u2_flag gur = _iris_nest_dext_main
            (wir_r, sut, bar, axe, gil, bon, nef, ful);

          u2_plow_(wir_r, vus) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, vus));
          return gur;
        }
      }
    }
    u2_flag
    _iris_nest_sint_swim(u2_ray  wir_r,
                         u2_type sut,
                         u2_rail bar,
                         u2_axis axe,
                         u2_pool gil,
                         u2_type bon,
                         u2_rail nef,
                         u2_axis ful)
    {
      u2_noun p_bon, q_bon;

      if ( u2_yes == u2_as_pq(bon, c3__fork, &p_bon, &q_bon) ) {
        return u2_and
          (_iris_nest_sint_swim(wir_r, sut, bar, axe, gil, p_bon, nef, ful),
           _iris_nest_sint_swim(wir_r, sut, bar, axe, gil, q_bon, nef, ful));
      }
      else {
        if ( u2_so(_iris_cull(wir_r, bon, nef, ful)) ) {
          return u2_yes;
        }
        else return _iris_nest_dext
          (wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
    }
    u2_flag
    _iris_nest_sint(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_pool gil,
                    u2_type bon,
                    u2_rail nef,
                    u2_axis ful)
    {
      
      u2_noun p_bon, q_bon;

      if ( u2_yes == u2_sing(bon, c3__atom) || u2_yes == u2_sing(bon, c3__blur) ) {
        return u2_no;
      }
      else if ( u2_yes == u2_as_pq(bon, c3__cell, &p_bon, &q_bon) ) {
        return u2_no;
      }
      else if ( u2_yes == u2_as_pq(bon, c3__core, &p_bon, &q_bon) ) {
        bon = u2_bt(wir_r, c3__cell, p_bon, c3__blur);

        return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u2_yes == u2_as_p(bon, c3__cube, &p_bon) ) {
        if ( u2_yes == u2_stud(p_bon) ) {
          return u2_no;
        }
        else {
          bon = u2_bt
            (wir_r, c3__cell,
                  u2_bc(wir_r, c3__cube, u2_h(p_bon)),
                  u2_bc(wir_r, c3__cube, u2_t(p_bon)));

          return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u2_yes == u2_as_pq(bon, c3__face, &p_bon, &q_bon) ) {
        return _iris_nest_dext(wir_r, sut, bar, axe, gil, q_bon, nef, ful);
      }
      else if ( u2_yes == u2_as_pq(bon, c3__fork, &p_bon, &q_bon) ) {
        return _iris_nest_sint_swim(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u2_yes == u2_as_pq(bon, c3__fuse, &p_bon, &q_bon) ) {
        u2_rail gok = u2_bc(wir_r, p_bon, nef);

        return u2_or
          (_iris_nest_dext(wir_r, sut, bar, axe, gil, p_bon, nef, ful),
           _iris_nest_dext(wir_r, sut, bar, axe, gil, q_bon, gok, ful));
      }
      else if ( u2_yes == u2_as_pq(bon, c3__hold, &p_bon, &q_bon) ) {
        u2_noun duq = u2_bq(wir_r, sut, bar, bon, nef);

        if ( u2_fj_pool_in(duq, gil) ) {
          return u2_yes;
        } else {
          return _iris_nest_dext
            (wir_r, sut,
                bar,
                axe,
                u2_fj_pool_add(wir_r, duq, gil),
                _rose_repo(wir_r, p_bon, q_bon),
                nef, 
                ful);
        }
      }
      else return u2_bl_bail(wir_r);
    }
  static u2_flag
  _iris_nest(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe,
             u2_type bon)
  {
    if ( u2_so(_rose_null(wir_r, bon)) ) {
      return u2_yes;
    }
    else if ( u2_so(_rose_null(wir_r, sut)) ) {
      return u2_no;
    }
    else {
      u2_pool gil = u2_nul;
      u2_rail nef = u2_nul;
      u2_axis ful = _1;

      return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
    }
  }

  /* peek:iris:rose:plow
  */
  static u2_type
  _iris_peek(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe,
             u2_axis bow)
  {
    

    if ( u2_yes == u2_sing(_1, bow) ) {
      return sut;
    } 
    else {
      _iris_slip(wir_r, &sut, &bar, &axe, u2_fj_op_tip(bow));

      return _iris_peek(wir_r, sut, bar, axe, u2_fj_op_tap(wir_r, bow));
    }
  }

  /* slip:iris:rose:plow
  */
    u2_rail
    _iris_slip_a(u2_ray  wir_r,
                 u2_rail bar,
                 u2_axis had)
    {
      if ( (u2_nul == bar) ) {
        return u2_nul;
      }
      else {
        return u2_bc
          (wir_r, _iris_half(wir_r, u2_h(bar), u2_nul, _1, had),
                   _iris_slip_a(wir_r, u2_t(bar), had));
      } 
    }
  void
  _iris_slip(u2_ray  wir_r,
             u2_type *sut,
             u2_rail *bar,
             u2_axis *axe,
             u2_axis had)
  {
    *sut = _iris_half(wir_r, *sut, *bar, *axe, had);
    *bar = _iris_slip_a(wir_r, *bar,  had);
    *axe = u2_fj_op_peg(wir_r, *axe, had);
  }

  /* snap:iris:rose:plow
  */
    u2_type
    _iris_snap_dext(u2_ray, u2_type, u2_rail, u2_axis, u2_type);
    u2_type
    _iris_snap_sint(u2_ray, u2_type, u2_rail, u2_axis, u2_type);

    u2_type
    _iris_snap_slip(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_type bon,
                    u2_axis had)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, had);
      return _iris_snap(wir_r, sut, bar, axe, bon);
    }
    u2_flag
    _iris_snap_cull(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_type bon)
    {
      return u2_or
        (_iris_cull(wir_r, sut, bar, axe),
         _rose_orth(wir_r, sut, bon));
    }
    u2_type
    _iris_snap_dext(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_type bon)
    {
      
      u2_noun p_sut, q_sut;
      u2_noun p_bon, q_bon;

      if ( u2_yes == u2_sing(sut, c3__atom) ||
           u2_yes == u2_sing(sut, c3__blot) ||
           u2_yes == u2_sing(sut, c3__blur) ||
           u2_yes == u2_as_p(sut, c3__cube, &p_sut) ||
           u2_yes == u2_as_pq(sut, c3__core, &p_sut, &q_sut) )
      {
        return bon;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_as_pq(bon, c3__cell, &p_bon, &q_bon) ) {
          return u2_bt
            (wir_r,
             c3__cell,
             _iris_snap_slip(wir_r, sut, bar, axe, p_bon, _2),
             _iris_snap_slip(wir_r, sut, bar, axe, q_bon, _3));
        }
        else {
          return _iris_snap_sint(wir_r, sut, bar, axe, bon);
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_as_pq(bon, c3__face, &p_bon, &q_bon) ) {
          return u2_bt
            (wir_r, c3__face,
                  p_sut,
                  _iris_snap_dext(wir_r, q_sut, bar, axe, q_bon));
        }
        else {
          return u2_bt
            (wir_r, c3__face,
                  p_sut,
                  _iris_snap_dext(wir_r, q_sut, bar, axe, bon));
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        if ( u2_so(_iris_snap_cull(wir_r, p_sut, bar, axe, bon)) ) {
          if ( u2_so(_iris_snap_cull(wir_r, q_sut, bar, axe, bon)) ) {
            return bon;
          }
          else return _iris_snap_dext(wir_r, q_sut, bar, axe, bon);
        }
        else {
          if ( u2_so(_iris_snap_cull(wir_r, q_sut, bar, axe, bon)) ) {
            return _iris_snap_dext(wir_r, p_sut, bar, axe, bon);
          }
          else return bon;
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        return _iris_snap_dext
          (wir_r, q_sut, u2_bc(wir_r, p_sut, bar), axe, bon);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        return _iris_snap_dext
          (wir_r, _rose_repo(wir_r, p_sut, q_sut), bar, axe, bon);
      }
      else return u2_bl_bail(wir_r);
    }
    u2_type
    _iris_snap_sint(u2_ray  wir_r,
                    u2_type sut,
                    u2_rail bar,
                    u2_axis axe,
                    u2_type bon)
    {
      u2_noun p_bon, q_bon;

      if ( u2_yes == u2_as_pq(bon, c3__fork, &p_bon, &q_bon) ) {
        return _rose_eith
          (wir_r, 
           _iris_snap_dext(wir_r, sut, bar, axe, p_bon), 
           _iris_snap_dext(wir_r, sut, bar, axe, q_bon));
      }
      else if ( u2_yes == u2_as_pq(bon, c3__fuse, &p_bon, &q_bon) ) {
        return _rose_both
          (wir_r,
           _iris_snap_dext(wir_r, sut, bar, axe, q_bon),
           _iris_snap_dext(wir_r, sut, bar, axe, p_bon));
      }
      else return bon;
    }
  static u2_type
  _iris_snap(u2_ray  wir_r,
             u2_type sut,
             u2_rail bar,
             u2_axis axe,
             u2_type bon)
  {
    u2_type sap;

    sap = _iris_snap_dext(wir_r, sut, bar, axe, bon);

    return sap;
  }


/****   _lark: mutation.
****/
  /* nuke:lark:rose:plow
  */
    u2_tack
    _lark_nuke_port(u2_ray  wir_r,
                    u2_type sut,
                    u2_tack tac,
                    u2_rope rop,
                    u2_type feg,
                    u2_term gos,
                    u2_axis wam,
                    u2_unit yus,
                    u2_type gur)
    {
      

      if ( u2_yes == u2_sing(_1, wam) ) {
        if ( (u2_nul == yus) ) {
          return u2_bt
            (wir_r, c3__bran,
                  gos,
                  _lark_nuke(wir_r, gur, tac, rop, feg));
        } else {
          return _lark_nuke(wir_r, gur, tac, rop, feg);
        }
      }
      else {
        u2_axis tip = u2_fj_op_tip(wam);
        u2_axis tap = u2_fj_op_tap(wir_r, wam);

        if ( u2_yes == u2_sing(_2, tip) ) {
          return u2_bt
            (wir_r, 
             c3__pair,
             _lark_nuke_port(wir_r, sut, tac, rop, feg, gos, tap, yus, gur),
             u2_nul);
        }
        else {
          return u2_bt
            (wir_r, 
             c3__pair,
             u2_nul,
             _lark_nuke_port(wir_r, sut, tac, rop, feg, gos, tap, yus, gur));
        }
      }
    }

    u2_tack
    _lark_nuke_frag(u2_ray  wir_r,
                    u2_type sut,
                    u2_tack tac,
                    u2_rope rop,
                    u2_type feg,
                    u2_axis wam,
                    u2_type gur)
    {
      

      if ( u2_yes == u2_sing(_1, wam) ) {
        return _lark_nuke(wir_r, gur, tac, rop, feg);
      }
      else {
        u2_axis tip = u2_fj_op_tip(wam);
        u2_axis tap = u2_fj_op_tap(wir_r, wam);

        if ( u2_yes == u2_sing(_2, tip) ) {
          return u2_bt
            (wir_r, 
             c3__pair,
             _lark_nuke_frag(wir_r, sut, tac, rop, feg, tap, gur),
             u2_nul);
        }
        else {
          return u2_bt
            (wir_r, 
             c3__pair,
             u2_nul,
             _lark_nuke_frag(wir_r, sut, tac, rop, feg, tap, gur));
        }
      }
    }
  static u2_tack
  _lark_nuke(u2_ray  wir_r,
             u2_type sut,
             u2_tack tac,
             u2_rope rop,
             u2_type feg)
  {
    

    if ( (u2_nul == rop) ) {
      return u2_bc(wir_r, c3__leaf, feg);
    }
    else {
      u2_cord i_rop = u2_h(rop);
      u2_rope t_rop = u2_t(rop);
      u2_noun pi_rop;

      if ( u2_yes == u2_stud(i_rop) ) {
        return _lark_nuke
          (wir_r, sut, 
              tac, 
              u2_bc(wir_r, u2_bc(wir_r, c3__pane, rop), t_rop),
              feg);
      }
      else if ( u2_yes == u2_as_p(i_rop, c3__pane, &pi_rop) ) {
        u2_plan lar = _iris_find(wir_r, sut, u2_nul, _1, pi_rop);
        u2_axis p_lar = u2_h(lar);
        u2_unit q_lar = u2_h(u2_t(lar));
        u2_type r_lar = u2_t(u2_t(lar));

        return _lark_nuke_port
          (wir_r, sut, tac, t_rop, feg, pi_rop, p_lar, q_lar, r_lar);
      }
      else if ( u2_yes == u2_as_p(i_rop, c3__frag, &pi_rop) ) {
        u2_type gur = _iris_peek(wir_r, sut, u2_nul, _1, pi_rop);

        return _lark_nuke_frag(wir_r, sut, tac, t_rop, feg, pi_rop, gur); 
      }
      else return u2_bl_bail(wir_r);
    }
  }

  /* cram:lark:rose:plow
  */
  static u2_tack
  _lark_cram(u2_ray  wir_r,
             u2_type sut,
             u2_tack tac,
             u2_tack les)
  {
    
    u2_noun p_tac, q_tac, p_les, q_les;

    if ( (u2_nul == tac) ) {
      return les;
    }
    else if ( (u2_nul == les) ) {
      return tac;
    }
    else if ( u2_yes == u2_as_pq(tac, c3__bran, &p_tac, &q_tac) ) {
      if ( !(u2_yes == u2_as_pq(les, c3__bran, &p_les, &q_les)) ||
           !(u2_yes == u2_sing(p_tac, p_les)) )
      {
        return _plow_fail(wir_r, "cram crash");
      }
      else return u2_bt
        (wir_r, c3__bran,
              p_tac,
              _lark_cram(wir_r, sut, q_tac, q_les));
    }
    else if ( u2_yes == u2_as_pq(tac, c3__pair, &p_tac, &q_tac) ) {
      if ( !(u2_yes == u2_as_pq(les, c3__pair, &p_les, &q_les)) ) {
        return _plow_fail(wir_r, "cram crash");
      }
      else return u2_bt
        (wir_r, c3__pair,
              _lark_cram(wir_r, sut, p_tac, p_les),
              _lark_cram(wir_r, sut, q_tac, q_les));
    }
    else return _plow_fail(wir_r, "cram crash");
  }

  /* feed:lark:rose:plow
  */
  static u2_tack
  _lark_feed(u2_ray  wir_r,
             u2_type sut,
             u2_tack tac,
             u2_list mut)
  {
    if ( (u2_nul == mut) ) {
      return tac;
    }
    else {
      u2_noun i_mut  = u2_h(mut);
      u2_list t_mut  = u2_t(mut);
      u2_gene pi_mut = u2_h(i_mut);
      u2_type qi_mut = u2_t(i_mut);
      u2_rope rop    = _plow_rake(wir_r, pi_mut);
      u2_tack bur    = _lark_nuke(wir_r, sut, tac, rop, qi_mut);
      u2_tack tey    = _lark_cram(wir_r, sut, tac, bur);

#if 0
      { 
        u2_err(wir_r, "tac", tac);
        u2_err(wir_r, "bur", bur);
        u2_err(wir_r, "tey", tey);
        printf("\n");
      }
#endif
      return _lark_feed(wir_r, sut, tey, t_mut);
    }
  }

/****   _rose: high-level functions.
****/
  /* both:rose:plow
  */
  static u2_type
  _rose_both(u2_ray  wir_r,
             u2_type sut,
             u2_type hoc)
  {
    

#if 1
    if ( u2_yes == u2_sing(c3__blur, sut) ) {
      return hoc;
    }
    else if ( u2_yes == u2_sing(c3__blur, hoc) ) {
      return sut;
    }
    else {
      return u2_bt(wir_r, c3__fuse, hoc, sut);
    }
#else 
    if ( u2_so(_iris_nest(wir_r, hoc, u2_nul, _1, sut)) ) {
      /* every sut is a hoc */
      return sut;
    }
    else {
      /* not every sut is a hoc */
      if ( u2_so(_iris_nest(wir_r, sut, u2_nul, _1, hoc)) ) {
        /* every hoc is a sut */
        return hoc;
      }
      else {
        /* not every sut is a hoc, not every hoc is a sut */
        return u2_bt(wir_r, c3__fuse, hoc, sut);
      }
    }
#endif
  }

  /* eith:rose:plow
  */
  static u2_type
  _rose_eith(u2_ray  wir_r,
             u2_type sut,
             u2_type hoc)
  {
    

    if ( u2_yes == u2_sing(sut, hoc) ) {
      return sut;
    }
    else if ( u2_yes == u2_sing(c3__blot, hoc) ) {
      return sut;
    }
    else if ( u2_yes == u2_sing(c3__blot, sut) ) {
      return hoc;
    }
    else return u2_bt(wir_r, c3__fork, sut, hoc);
  }

  /* etch:rose:plow
  */
  static u2_type
  _rose_etch(u2_ray  wir_r,
             u2_type sut)
  {
    u2_noun p_sut, q_sut;

    if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
      return q_sut;
    }
    else return _plow_fail(wir_r, "bad etch");
  }

  /* edit:rose:plow
  */
  static u2_type
  _rose_edit(u2_ray  wir_r,
             u2_type sut,
             u2_list mut)
  {
    u2_tack tac = _lark_feed(wir_r, sut, u2_nul, mut);
    u2_type fuz = _iris_burn(wir_r, sut, u2_nul, _1, tac);

    return fuz;
  }

  /* gain:rose:plow
  */
    u2_rack
    _rose_gain_hunt(u2_ray, u2_type, u2_gene);

    u2_rack
    _rose_gain_hunt_a(u2_ray  wir_r,
                      u2_type sut,
                      u2_bank vof)
    {
      if ( (u2_nul == vof) ) {
        return u2_nul;
      }
      else return u2_fj_list_cat(wir_r, _rose_gain_hunt(wir_r, sut, u2_h(vof)),
                                    _rose_gain_hunt_a(wir_r, sut, u2_t(vof)));
    }
    u2_plot
    _rose_gain_hunt(u2_ray  wir_r,
                    u2_type sut,
                    u2_gene gen)
    {
      
      u2_noun p_gen, q_gen;

      if ( u2_yes == u2_as_pq(gen, c3__plin, &p_gen, &q_gen) ) {
        return u2_bc
          (wir_r, 
           u2_bc(wir_r, q_gen, _rose_play(wir_r, sut, p_gen)),
           u2_nul);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
        return _rose_gain_hunt(wir_r, sut, q_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__zush, &p_gen, &q_gen) ) {
        return _rose_gain_hunt(wir_r, sut, q_gen);
      }
      else if ( u2_yes == u2_as_p(gen, c3__chan, &p_gen) ) {
        return _rose_gain_hunt_a(wir_r, sut, p_gen);
      }
      else return u2_nul;
    }
    u2_type
    _rose_gain_gild(u2_ray  wir_r,
                    u2_type sut,
                    u2_plot mut)
    {
      u2_tack tac = _lark_feed(wir_r, sut, u2_nul, mut);
      u2_type hoc = _iris_burn(wir_r, c3__blur, u2_nul, _1, tac);

      return _rose_both(wir_r, sut, hoc);
    }
  static u2_type
  _rose_gain(u2_ray  wir_r,
             u2_type sut,
             u2_gene gen)
  {
    u2_plot zet = _rose_gain_hunt(wir_r, sut, gen);

    return _rose_gain_gild(wir_r, sut, zet);
  }

  /* make:rose:plow
  */
    static u2_list
    _rose_make_boil_a(u2_ray  wir_r,
                      u2_type sut,
                      u2_list rem)
    {
      

      if ( (u2_nul == rem) ) {
        return u2_nul;
      }
      else {
        u2_noun i_rem  = u2_h(rem);
        u2_noun t_rem  = u2_t(rem);
        u2_gene pi_rem = u2_h(i_rem);
        u2_tool qi_rem = u2_t(i_rem);
        u2_plan giz    = _rose_seek(wir_r, sut, _plow_rake(wir_r, pi_rem));
        u2_axis p_giz  = u2_h(giz);

        return u2_bc(wir_r, u2_bc(wir_r, p_giz, qi_rem),
                              _rose_make_boil_a(wir_r, sut, t_rem));
      }
    }
    static u2_tool
    _rose_make_boil(u2_ray  wir_r,
                    u2_type sut,
                    u2_axis axe,
                    u2_list rem)
    {
      return _lily_hike(wir_r, axe, _rose_make_boil_a(wir_r, sut, rem));
    }
    static u2_noun
    _rose_make_bake(u2_ray  wir_r,
                    u2_type sut,
                    u2_book dab)
    {
      if ( (u2_nul == dab) ) {
        return _0;
      }
      else {
        u2_noun n_dab, l_dab, r_dab, qn_dab;

        u2_as_trel(dab, &n_dab, &l_dab, &r_dab);
        qn_dab = u2_t(n_dab);
        
        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          return _rose_make(wir_r, sut, qn_dab);
        }
        else if ( (u2_nul == l_dab) ) {
          return u2_bc
            (wir_r, _rose_make(wir_r, sut, qn_dab),
                  _rose_make_bake(wir_r, sut, r_dab));
        }
        else if ( (u2_nul == r_dab) ) {
          return u2_bc
            (wir_r, _rose_make(wir_r, sut, qn_dab),
                  _rose_make_bake(wir_r, sut, l_dab));
        }
        else {
          return u2_bt
            (wir_r, _rose_make(wir_r, sut, qn_dab),
                  _rose_make_bake(wir_r, sut, l_dab),
                  _rose_make_bake(wir_r, sut, r_dab));
        }
      }
    }
    static u2_noun
    _rose_make_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_rack dus)
    {
      if ( (u2_nul == dus) ) {
        return u2_nul;
      }
      else {
        u2_noun i_dus = u2_h(dus);
        u2_noun t_dus = u2_t(dus);
        u2_gene pi_dus = u2_h(i_dus);
        u2_gene qi_dus = u2_t(i_dus);
        u2_tool pog    = _rose_make(wir_r, sut, qi_dus);

        return u2_bc
          (wir_r,
           u2_bc(wir_r, pi_dus, pog),
           _rose_make_a(wir_r, sut, t_dus));
      }
    }
    static u2_noun
    _rose_make_prop(u2_ray  wir_r,
                    u2_type sut,
                    u2_prop pup)
    {
      
      
      if ( (u2_nul == pup) ) {
        return pup;
      } else {
        u2_plan lar = _rose_seek(wir_r, sut, u2_h(pup));

        return u2_bc(wir_r, u2_h(lar), u2_t(pup));
      }
    }

    u2_tool
    _rose_make_main(u2_ray  wir_r,
                    u2_type sut,
                    u2_gene gen)
    {
      
      u2_noun p_gen, q_gen, r_gen;

      if ( u2_yes == u2_as_p(gen, c3__zike, &p_gen) ) {
        return u2_bc(wir_r, u2_nock_frag, _0);
      }
      else if ( u2_yes == u2_as_p(gen, c3__zoot, &p_gen) ) {
        return u2_bl_bail(wir_r);
      }
      else if ( u2_yes == u2_as_p(gen, c3__vint, &p_gen) ) {
        return u2_bc(wir_r, u2_nock_vint, _rose_make(wir_r, sut, p_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__cast, &p_gen, &q_gen) ) {
        return _rose_make(wir_r, sut, q_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__twix, &p_gen, &q_gen) ) {
        return _lily_cons
          (wir_r, _rose_make(wir_r, sut, p_gen), _rose_make(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__wost, &p_gen) ) {
        return _rose_make(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
        u2_tool guz;
        u2_atom bug;

        bug = u2_plow_(wir_r, bug);
        u2_plow_(wir_r, bug) = u2_fj_op_inc(wir_r, u2_plow_(wir_r, bug));

        guz = _rose_make(wir_r, sut, p_gen);
        
        u2_plow_(wir_r, bug) = bug;
        return guz;
      }
      else if ( u2_yes == u2_as_p(gen, c3__dust, &p_gen) ) {
        return u2_bc(wir_r, u2_nock_dust, _rose_make(wir_r, sut, p_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__germ, &p_gen, &q_gen) ) {
        return u2_bt(wir_r, 
                     c3__germ,
                     _rose_make(wir_r, sut, p_gen),
                     _rose_make(wir_r, sut, q_gen));
      } 
      else if ( u2_yes == u2_as_pq(gen, c3__hint, &p_gen, &q_gen) ) {
        return u2_bt(wir_r, 
                     u2_nock_hint,
                     _rose_make(wir_r, sut, p_gen),
                     _rose_make(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__grit, &p_gen) ) {
        return _rose_make(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__tash, &p_gen, &q_gen) ) {
        u2_book sec = _gull_fill(wir_r, u2_nul, q_gen);
        u2_noun heq = _rose_make_prop(wir_r, sut, p_gen);
        u2_noun baf = _rose_make_bake(wir_r, _rose_play(wir_r, sut, gen), sec);

#if 1
        return u2_bt
          (wir_r, u2_nock_coat, heq, baf);
#else
        return u2_bc
          (wir_r,
           u2_bc(wir_r, u2_nock_frag, _1), 
           u2_bc(wir_r, u2_nock_bone, baf));
#endif
      }
      else if ( u2_yes == u2_as_pq(gen, c3__plin, &p_gen, &q_gen) ) {
        u2_plan lar = _rose_seek(wir_r, sut, _plow_rake(wir_r, q_gen));
        u2_axis p_lar = u2_h(lar);

        if ( !(u2_nul == u2_h(u2_t(lar))) ) {
          return _plow_fail(wir_r, "bad like");
        }
        else {
          return _iris_fish(wir_r, _rose_play(wir_r, sut, p_gen), u2_nul, p_lar);
        }
      }
      else if ( u2_yes == u2_as_pq(gen, c3__flac, &p_gen, &q_gen) ) {
        return _lily_comb
          (wir_r,
           _rose_make(wir_r, sut, p_gen),
           _rose_make(wir_r, _rose_play(wir_r, sut, p_gen), q_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__pank, &p_gen, &q_gen) ) {
        u2_book sec = _gull_fill(wir_r, u2_nul, q_gen);
        u2_noun heq = _rose_make_prop(wir_r, sut, p_gen);
        u2_noun baf = _rose_make_bake(wir_r, _rose_play(wir_r, sut, gen), sec);

#if 1
        return u2_bt
          (wir_r, u2_nock_coat, heq, baf);
#else
        return u2_bc
          (wir_r,
           u2_bc(wir_r, u2_nock_frag, _1), 
           u2_bc(wir_r, u2_nock_bone, baf));
#endif
      }
      else if ( u2_yes == u2_as_p(gen, c3__zalt, &p_gen) ) {
        u2_type yoz = _rose_play(wir_r, sut, p_gen);
   
        return u2_bc(wir_r, u2_nock_bone, yoz);
      }
      else if ( u2_yes == u2_as_p(gen, c3__zond, &p_gen) ) {
        u2_type yoz = _rose_make(wir_r, sut, p_gen);
   
        return u2_bc(wir_r, u2_nock_bone, yoz);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__bran, &p_gen, &q_gen) ) {
        return _rose_make(wir_r, sut, q_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__sail, &p_gen, &q_gen) ) {
        return u2_bt(wir_r, u2_nock_sail,
                              _rose_make(wir_r, sut, p_gen),
                              _rose_make(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__bone, &p_gen) ) {
        return u2_bc(wir_r, u2_nock_bone, p_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
        u2_noun qip;

        u2_plow_(wir_r, meb) = u2_bc(wir_r, u2_bc(wir_r, u2_nul, p_gen), u2_plow_(wir_r, meb));
        qip = _rose_make(wir_r, sut, q_gen);
        u2_plow_(wir_r, meb) = u2_t(u2_plow_(wir_r, meb));

        return qip;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__stil, &p_gen, &q_gen) ) {
        return u2_bc(wir_r, u2_nock_frag, _1);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__mack, &p_gen, &q_gen) ) {
        u2_plan lar = _rose_seek(wir_r, sut, p_gen);
        u2_noun rem = _rose_make_a(wir_r, sut, q_gen);
        u2_axis p_lar = u2_h(lar);
        u2_noun q_lar = u2_h(u2_t(lar));
        u2_type r_lar = u2_t(u2_t(lar));

#if 0
        if ( !(u2_nul == q_gen) ) {
          u2_err(wir_r, "make: take", gen);
          u2_err(wir_r, "make: q", q_lar);
        }
#endif
        if ( (u2_nul == q_lar) ) {
          return _rose_make_boil(wir_r, r_lar, p_lar, rem);
        }
        else {
          u2_door uq_lar  = u2_t(q_lar);
          u2_axis puq_lar = u2_h(uq_lar);
          u2_type quq_lar = u2_h(u2_t(uq_lar));
          u2_tool ruz = _rose_make_boil(wir_r, quq_lar, p_lar, rem);
          u2_tool gak;

          gak = u2_bt
            (wir_r,
             u2_nock_sail,
             ruz,
             u2_bc(wir_r, u2_nock_frag, u2_fj_op_peg(wir_r, p_lar, puq_lar)));

          return gak;
        }
      }
      else if ( u2_yes == u2_as_pqr(gen, c3__trol, &p_gen, &q_gen, &r_gen) ) {
        return u2_bq
          (wir_r,
           u2_nock_trol,
           _rose_make(wir_r, sut, p_gen),
           _rose_make(wir_r, _rose_gain(wir_r, sut, p_gen), q_gen),
           _rose_make(wir_r, sut, r_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__sing, &p_gen, &q_gen) ) {
        return u2_bt
          (wir_r,
           u2_nock_sing,
           _rose_make(wir_r, sut, p_gen),
           _rose_make(wir_r, sut, q_gen));
      }
      else {
        u2_noun fog = _plow_open(wir_r, gen);

        if ( u2_yes == u2_sing(fog, gen) ) {
          u2_err(wir_r, "dup: gen", gen);
          return u2_bl_bail(wir_r);
        }
        return _rose_make(wir_r, sut, _plow_open(wir_r, gen)); 
      }
    }
  static u2_tool
  _rose_make(u2_ray  wir_r,
             u2_type sut,
             u2_gene gen)
  {
    
    u2_noun mum = u2_bc(wir_r, sut, gen);
    u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, niq));

    if ( zod != u2_none ) {
      return zod;
    }
    else {
      u2_tool gur = _rose_make_main(wir_r, sut, gen);

      u2_plow_(wir_r, niq) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, niq));
      return gur;
    }
  }

  /* null:rose:plow
  */
    u2_flag
    _rose_null_a(u2_ray  wir_r, u2_type sut, u2_pool hem);

    u2_flag
    _rose_null_b(u2_ray  wir_r,
                 u2_type sut,
                 u2_pool hem)
    {
      
      u2_noun p_sut, q_sut;

      if ( u2_yes == u2_sing(sut, c3__atom) ) {
        return u2_no;
      }
      else if ( u2_yes == u2_sing(sut, c3__blur) ) {
        return u2_no;
      }
      else if ( u2_yes == u2_sing(sut, c3__blot) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        return u2_or(_rose_null_a(wir_r, p_sut, hem), _rose_null_a(wir_r, q_sut, hem));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__core, &p_sut, &q_sut) ) {
        return _rose_null_a(wir_r, p_sut, hem);
      }
      else if ( u2_yes == u2_as_p(sut, c3__cube, &p_sut) ) {
        return u2_no;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        return _rose_null_a(wir_r, q_sut, hem);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        return u2_and(_rose_null_a(wir_r, p_sut, hem), _rose_null_a(wir_r, q_sut, hem));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        return _rose_orth(wir_r, p_sut, q_sut);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        if ( u2_fj_pool_in(sut, hem) ) {
          return u2_yes;
        } else {
          return _rose_null_a
            (wir_r, _rose_repo(wir_r, p_sut, q_sut), u2_fj_pool_add(wir_r, sut, hem));
        }
      } 
      else return u2_bl_bail(wir_r);
    }
    u2_flag
    _rose_null_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_pool hem)
    {
      
      u2_noun mum = u2_bc(wir_r, sut, hem);
      u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, tyc));

      if ( zod != u2_none ) {
        return zod;
      }
      else {
        u2_flag gur = _rose_null_b(wir_r, sut, hem);

        u2_plow_(wir_r, tyc) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, tyc));
        return gur;
      }
    }
  static u2_flag
  _rose_null(u2_ray  wir_r,
             u2_type sut)
  {
    return _rose_null_a(wir_r, sut, u2_nul);
  }

  /* orth:rose:plow
  */
    u2_flag
    _rose_orth_a(u2_ray  wir_r, u2_type sut, u2_type ref, u2_pool bol);

    u2_flag
    _rose_orth_b(u2_ray  wir_r,
                 u2_type sut,
                 u2_type ref,
                 u2_pool bol)
    {
      
      u2_noun p_sut, q_sut;
      u2_noun p_ref, q_ref;

      if ( u2_yes == u2_sing(sut, c3__atom) ) {
        if ( u2_yes == u2_sing(ref, c3__atom) ) {
          return u2_no;
        }
        else if ( u2_yes == u2_as_pq(ref, c3__cell, &p_sut, &q_sut) ) {
          return u2_yes;
        }
        else return _rose_orth_a(wir_r, ref, sut, bol);
      }
      else if ( u2_yes == u2_sing(sut, c3__blot) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_sing(sut, c3__blur) ) {
        return u2_no;
      }
      else if ( u2_yes == u2_as_pq(sut, c3__cell, &p_sut, &q_sut) ) {
        if ( u2_yes == u2_as_pq(ref, c3__cell, &p_ref, &q_ref) ) {
          return u2_or(_rose_orth_a(wir_r, p_sut, p_ref, bol),
                       _rose_orth_a(wir_r, q_sut, q_ref, bol));
        }
        else {
          return _rose_orth_a(wir_r, ref, sut, bol);
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__core, &p_sut, &q_sut) ) {
        return _rose_orth_a
          (wir_r, u2_bt(wir_r, c3__cell, p_sut, c3__blur), ref, bol);
      }
      else if ( u2_yes == u2_as_p(sut, c3__cube, &p_sut) ) {
        if ( u2_yes == u2_sing(c3__atom, ref) ) {
          return u2_yes == u2_stud(p_sut) ? u2_no : u2_yes;
        }
        else if ( u2_yes == u2_as_p(ref, c3__cube, &p_ref) ) {
          return u2_not(u2_sing(p_sut, p_ref));
        }
        else if ( u2_yes == u2_as_pq(ref, c3__cell, &p_ref, &q_ref) ) {
          if ( u2_yes == u2_stud(p_sut) ) {
            return u2_yes;
          } else {
            u2_type hed = u2_bc(wir_r, c3__cube, u2_h(p_sut));
            u2_type tal = u2_bc(wir_r, c3__cube, u2_t(p_sut));

            return u2_or(_rose_orth_a(wir_r, hed, p_ref, bol),
                         _rose_orth_a(wir_r, tal, q_ref, bol));
          }
        }
        else {
          return _rose_orth_a(wir_r, ref, sut, bol);
        }
      }
      else if ( u2_yes == u2_as_pq(sut, c3__face, &p_sut, &q_sut) ) {
        return _rose_orth_a(wir_r, q_sut, ref, bol);
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fork, &p_sut, &q_sut) ) {
        return u2_and(_rose_orth_a(wir_r, p_sut, ref, bol),
                      _rose_orth_a(wir_r, q_sut, ref, bol));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__fuse, &p_sut, &q_sut) ) {
        return u2_or(_rose_orth_a(wir_r, p_sut, ref, bol),
                     _rose_orth_a(wir_r, q_sut, ref, bol));
      }
      else if ( u2_yes == u2_as_pq(sut, c3__hold, &p_sut, &q_sut) ) {
        u2_noun gob = u2_bc(wir_r, sut, ref);

        if ( u2_fj_pool_in(gob, bol) ) {
          return u2_yes;
        } else {
          return _rose_orth_a
            (wir_r, _rose_repo(wir_r, p_sut, q_sut), ref, u2_fj_pool_add(wir_r, gob, bol));
        }
      } 
      else {
        u2_err(wir_r, "sut", sut);

        return u2_bl_bail(wir_r);
      }
    }
    u2_flag
    _rose_orth_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_type ref,
                 u2_pool bol)
    {
      
      u2_noun mum = u2_bt(wir_r, sut, ref, bol);
      u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, gam));

      if ( zod != u2_none ) {
        return zod;
      }
      else {
        u2_flag gur = _rose_orth_b(wir_r, sut, ref, bol);

        u2_plow_(wir_r, gam) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, gam));
        return gur;
      }
    }
  static u2_flag
  _rose_orth(u2_ray  wir_r,
             u2_type sut,
             u2_type ref)
  {
    return _rose_orth_a(wir_r, sut, ref, u2_nul);
  }

  /* play:rose:plow
  */
    u2_plot
    _rose_play_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_rack dus)
    {
      

      if ( (u2_nul == dus) ) {
        return u2_nul;
      }
      else {
        u2_noun i_dus = u2_h(dus);
        u2_noun t_dus = u2_t(dus);
        u2_gene pi_dus = u2_h(i_dus);
        u2_gene qi_dus = u2_t(i_dus);
        u2_type feg    = _rose_play(wir_r, sut, qi_dus);

        return u2_bc
          (wir_r,
           u2_bc(wir_r, pi_dus, feg),
           _rose_play_a(wir_r, sut, t_dus));
      }
    }
    u2_type
    _rose_play_main(u2_ray  wir_r,
                    u2_type sut,
                    u2_gene gen)
    {
      
      u2_noun p_gen, q_gen, r_gen;

      if ( u2_yes == u2_as_p(gen, c3__zike, &p_gen) ) {
        return c3__blot;
      }
      else if ( u2_yes == u2_as_p(gen, c3__zoot, &p_gen) ) {
        return u2_bl_bail(wir_r);
      }
      else if ( u2_yes == u2_as_p(gen, c3__vint, &p_gen) ) {
        return c3__atom;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__cast, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__twix, &p_gen, &q_gen) ) {
        return u2_bt
          (wir_r, c3__cell,
                _rose_play(wir_r, sut, p_gen),
                _rose_play(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__wost, &p_gen) ) {
        return _rose_play(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
        u2_type soq;
        u2_atom bug;

        bug = u2_plow_(wir_r, bug);
        u2_plow_(wir_r, bug) = u2_fj_op_inc(wir_r, u2_plow_(wir_r, bug));

        soq = _rose_play(wir_r, sut, p_gen);
       
        u2_brut(wir_r, "soq", soq);

        u2_plow_(wir_r, bug) = bug;
        return soq;
      }
      else if ( u2_yes == u2_as_p(gen, c3__dust, &p_gen) ) {
        return u2_bt
          (wir_r,
           c3__fork,
           u2_bc(wir_r, c3__cube, u2_yes),
           u2_bc(wir_r, c3__cube, u2_no));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__germ, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, sut, q_gen);
      } 
      else if ( u2_yes == u2_as_pq(gen, c3__hint, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, sut, q_gen);
      }
      else if ( u2_yes == u2_as_p(gen, c3__grit, &p_gen) ) {
        return _rose_etch(wir_r, _rose_play(wir_r, sut, p_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__tash, &p_gen, &q_gen) ) {
        return u2_bu
          (wir_r, c3__core, 
                sut, 
                c3__soft,
                sut,
                _gull_fill(wir_r, u2_nul, q_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__plin, &p_gen, &q_gen) ) {
        return u2_bt
          (wir_r,
           c3__fork,
           u2_bc(wir_r, c3__cube, u2_yes),
           u2_bc(wir_r, c3__cube, u2_no));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__flac, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, _rose_play(wir_r, sut, p_gen), q_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__pank, &p_gen, &q_gen) ) {
        return u2_bu
          (wir_r, c3__core, 
                sut, 
                c3__hard,
                sut,
                _gull_fill(wir_r, u2_nul, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__zalt, &p_gen) ) {
        return u2_bc(wir_r, c3__cube, _rose_play(wir_r, sut, p_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__zond, &p_gen) ) {
        return u2_bc(wir_r, c3__cube, _rose_make(wir_r, sut, p_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__bran, &p_gen, &q_gen) ) {
        return u2_bt(wir_r, c3__face, p_gen, _rose_play(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__sail, &p_gen, &q_gen) ) {
        return c3__blur;
      }
      else if ( u2_yes == u2_as_p(gen, c3__bone, &p_gen) ) {
        return u2_bc(wir_r, c3__cube, p_gen); 
      }
      else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
        u2_noun qip;

        u2_plow_(wir_r, meb) = u2_bc(wir_r, u2_bc(wir_r, u2_nul, p_gen), u2_plow_(wir_r, meb));
        qip = _rose_play(wir_r, sut, q_gen);
        u2_plow_(wir_r, meb) = u2_t(u2_plow_(wir_r, meb));

        return qip;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__stil, &p_gen, &q_gen) ) {
        return sut;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__mack, &p_gen, &q_gen) ) {
        u2_plan lar = _rose_seek(wir_r, sut, p_gen);
        u2_noun huz = _rose_play_a(wir_r, sut, q_gen);
        u2_noun q_lar = u2_h(u2_t(lar));
        u2_type r_lar = u2_t(u2_t(lar));

        if ( (u2_nul == q_lar) ) {
          return _rose_edit(wir_r, r_lar, huz);
        }
        else {
          u2_door uq_lar  = u2_t(q_lar);
          u2_type quq_lar = u2_h(u2_t(uq_lar));
          u2_gene ruq_lar = u2_t(u2_t(uq_lar));
          u2_gene old     = gen;
          u2_noun p_sut, q_sut, r_sut, s_sut;

          sut = _rose_edit(wir_r, quq_lar, huz);
          gen = ruq_lar;

          if ( u2_yes == u2_as_pqrs(sut, c3__core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
            if ( u2_yes == u2_sing(c3__hard, q_sut) ) {
              sut = u2_bu(wir_r, c3__core, r_sut, q_sut, r_sut, s_sut);
              if ( !(u2_nul == u2_plow_(wir_r, bug)) ) {
                u2_err(wir_r, "hard: gen", old);
                u2_brut(wir_r, "hard: sut", sut);
                u2_brut(wir_r, "hard: mack", u2_bt(wir_r, c3__hold, sut, gen));
                printf("\n");
              }
            } 
            else if ( u2_yes == u2_sing(c3__soft, q_sut) ) {
              sut = sut;
              if ( !(u2_nul == u2_plow_(wir_r, bug)) ) {
                u2_err(wir_r, "soft: gen", old);
                u2_brut(wir_r, "soft: sut", sut);
                u2_brut(wir_r, "soft: mack", u2_bt(wir_r, c3__hold, sut, gen));
                printf("\n");
              }
            }
            else return u2_bl_bail(wir_r);
          }
          else return u2_bl_bail(wir_r);

          return u2_bt(wir_r, c3__hold, sut, gen);
        }
      }
      else if ( u2_yes == u2_as_pqr(gen, c3__trol, &p_gen, &q_gen, &r_gen) ) {
        return _rose_eith
          (wir_r,
           _rose_play(wir_r, _rose_gain(wir_r, sut, p_gen), q_gen),
           _rose_play(wir_r, sut, r_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__sing, &p_gen, &q_gen) ) {
        return u2_bt
          (wir_r,
           c3__fork,
           u2_bc(wir_r, c3__cube, u2_yes),
           u2_bc(wir_r, c3__cube, u2_no));
      }
      else {
        return _rose_play(wir_r, sut, _plow_open(wir_r, gen)); 
      }
    }
  static u2_type
  _rose_play(u2_ray  wir_r,
             u2_type sut,
             u2_gene gen)
  {
    
    u2_noun mum = u2_bc(wir_r, sut, gen);
    u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, zor));

    if ( zod != u2_none ) {
      return zod;
    }
    else {
      u2_type gur = _rose_play_main(wir_r, sut, gen);

      u2_plow_(wir_r, zor) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, zor));
      return gur;
    }
  }

  /* repo:rose:plow
  */
  static u2_type
  _rose_repo(u2_ray  wir_r,
             u2_type sut,
             u2_gene gen)
  {
    
    u2_noun vax = u2_bc(wir_r, sut, gen);

    if ( u2_fj_pool_in(vax, u2_plow_(wir_r, fan)) ) {
      return _plow_fail(wir_r, "inference recursion");
    }
    else {
      u2_noun fan;
      u2_type gex;

      fan = u2_plow_(wir_r, fan);
      u2_plow_(wir_r, fan) = u2_fj_pool_add(wir_r, vax, u2_plow_(wir_r, fan));

      gex = _rose_play(wir_r, sut, gen);
      u2_plow_(wir_r, fan) = fan;
      return gex;
    }
  }

  /* seek:rose:plow
  */
    u2_plan
    _rose_seek_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_rope rop,
                 u2_axis axe,
                 u2_unit act)
    {
      

      if ( (u2_nul == rop) ) {
        return u2_bt(wir_r, axe, act, sut);
      }
      else {
        u2_noun i_rop = u2_h(rop);
        u2_noun t_rop = u2_t(rop);
        u2_noun pi_rop;

        if ( u2_yes == u2_stud(i_rop) ) {
          return _rose_seek_a
            (wir_r, sut, 
                u2_bc(wir_r, u2_bc(wir_r, c3__pane, i_rop), t_rop),
                axe,
                act);
        }
        else if ( u2_yes == u2_as_p(i_rop, c3__frag, &pi_rop) ) {
          return _rose_seek_a
            (wir_r, _iris_peek(wir_r, sut, u2_nul, _1, pi_rop), 
                t_rop,
                u2_fj_op_peg(wir_r, axe, pi_rop),
                u2_nul);
        }
        else if ( u2_yes == u2_as_p(i_rop, c3__pane, &pi_rop) ) {
          u2_plan sap = _iris_find(wir_r, sut, u2_nul, _1, pi_rop);
          u2_axis p_sap = u2_h(sap);
          u2_unit q_sap = u2_h(u2_t(sap));
          u2_type r_sap = u2_t(u2_t(sap));
#if 0
          if ( (u2_nul == pi_rop) ) {
            u2_err(wir_r, "blip: p", p_sap);
            u2_err(wir_r, "blip: q", q_sap);
            u2_err(wir_r, "blip: r", r_sap);
          }
#endif
          return _rose_seek_a
            (wir_r, r_sap, t_rop, u2_fj_op_peg(wir_r, axe, p_sap), q_sap);
        }
        else return u2_bl_bail(wir_r);
      }
    }
  static u2_plan
  _rose_seek(u2_ray  wir_r,
             u2_type sut,
             u2_rope rop)
  {
    return _rose_seek_a(wir_r, sut, rop, _1, u2_nul);
  }

  /* show:rose:plow
  */
    static u2_flag
    _rose_show_nest(u2_ray  wir_r,
                    u2_type sut,
                    u2_type bon)
    {
      if ( !u2_so(_iris_nest(wir_r, sut, u2_nul, _1, bon)) ) {
        u2_brut(wir_r, "sut", sut);
        u2_brut(wir_r, "bon", bon);
        return _plow_fail(wir_r, "nest: show");
      }
      else {
        return u2_yes;
      }
    }
    static u2_plot
    _rose_show_a(u2_ray  wir_r,
                 u2_type sut,
                 u2_rack dus)
    {
      

      if ( (u2_nul == dus) ) {
        return u2_nul;
      }
      else {
        u2_noun i_dus = u2_h(dus);
        u2_noun t_dus = u2_t(dus);
        u2_gene pi_dus = u2_h(i_dus);
        u2_gene qi_dus = u2_t(i_dus);

        if ( !u2_so(_rose_show(wir_r, sut, qi_dus)) ) {
          return _plow_fail(wir_r, "show: take");
        }
        else {
          u2_type feg    = _rose_play(wir_r, sut, qi_dus);

          return u2_bc
            (wir_r,
             u2_bc(wir_r, pi_dus, feg),
             _rose_play_a(wir_r, sut, t_dus));
        }
      }
    }
    static u2_flag
    _rose_show_main(u2_ray  wir_r,
                    u2_type sut,
                    u2_gene gen)
    {
      
      u2_noun p_gen, q_gen, r_gen;

      if ( u2_yes == u2_as_p(gen, c3__zike, &p_gen) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_as_p(gen, c3__zoot, &p_gen) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_as_p(gen, c3__vint, &p_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show_nest
                          (wir_r, c3__atom, _rose_play(wir_r, sut, p_gen)));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__cast, &p_gen, &q_gen) ) {
        return u2_and
          (_rose_show(wir_r, sut, p_gen),
           u2_and
            (_rose_show(wir_r, sut, q_gen),
             _rose_show_nest(wir_r, _rose_play(wir_r, sut, p_gen),
                                _rose_play(wir_r, sut, q_gen))));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__twix, &p_gen, &q_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen), _rose_show(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__wost, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
        u2_flag zic;
        u2_atom bug;

        bug = u2_plow_(wir_r, bug);
        u2_plow_(wir_r, bug) = u2_fj_op_inc(wir_r, u2_plow_(wir_r, bug));

        zic = _rose_show(wir_r, sut, p_gen);
        
        u2_plow_(wir_r, bug) = bug;
        return zic;
      }
      else if ( u2_yes == u2_as_p(gen, c3__dust, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__germ, &p_gen, &q_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__hint, &p_gen, &q_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__grit, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__tash, &p_gen, &q_gen) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__plin, &p_gen, &q_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen), 
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__flac, &p_gen, &q_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, _rose_play(wir_r, sut, p_gen), q_gen));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__pank, &p_gen, &q_gen) ) {
        sut = _rose_play(wir_r, sut, gen);

        while ( !(u2_nul == q_gen) ) {
          u2_noun iq_gen = u2_h(q_gen);
          u2_noun tq_gen = u2_t(q_gen);
          u2_noun qiq_gen = u2_t(iq_gen);

          if ( !u2_so(_rose_show(wir_r, sut, qiq_gen)) ) {
            return _plow_fail(wir_r, "menu fail");
          }
          q_gen = tq_gen;
        }
        return u2_yes;
      }
      else if ( u2_yes == u2_as_p(gen, c3__zalt, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_p(gen, c3__zond, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__bran, &p_gen, &q_gen) ) {
        return _rose_show(wir_r, sut, q_gen);
      }
      else if ( u2_yes == u2_as_pq(gen, c3__sail, &p_gen, &q_gen) ) {
        return u2_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u2_yes == u2_as_p(gen, c3__bone, &p_gen) ) {
        return u2_yes;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
        u2_noun qip;

        u2_plow_(wir_r, meb) = u2_bc(wir_r, u2_bc(wir_r, u2_nul, p_gen), u2_plow_(wir_r, meb));
        qip = _rose_show(wir_r, sut, q_gen);
        u2_plow_(wir_r, meb) = u2_t(u2_plow_(wir_r, meb));

        return qip;
      }
      else if ( u2_yes == u2_as_pq(gen, c3__stil, &p_gen, &q_gen) ) {
        return u2_and
          (_rose_show(wir_r, sut, p_gen),
           u2_and
            (_rose_show(wir_r, sut, q_gen),
             _rose_show_nest
              (wir_r, _rose_play(wir_r, sut, p_gen), _rose_play(wir_r, sut, q_gen))));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__mack, &p_gen, &q_gen) ) {
        u2_plan lar = _rose_seek(wir_r, sut, p_gen);
        u2_noun huz = _rose_show_a(wir_r, sut, q_gen);
        u2_noun q_lar = u2_h(u2_t(lar));

        if ( (u2_nul == q_lar) ) {
          return u2_yes;
        }
        else {
          u2_door uq_lar  = u2_t(q_lar);
          u2_type quq_lar = u2_h(u2_t(uq_lar));
          u2_gene ruq_lar = u2_t(u2_t(uq_lar));
          u2_noun p_sut, q_sut, r_sut, s_sut;

          sut = _rose_edit(wir_r, quq_lar, huz);
          gen = ruq_lar;

          if ( u2_yes == u2_as_pqrs(sut, c3__core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
            if ( u2_yes == u2_sing(c3__hard, q_sut) ) {
              return _rose_show_nest(wir_r, r_sut, p_sut);
            }
            else if ( u2_yes == u2_sing(c3__soft, q_sut) ) {
              u2_noun fuy = u2_bc(wir_r, sut, gen);

              if ( u2_fj_pool_in(fuy, u2_plow_(wir_r, ver)) ) {
                return u2_yes;
              } else {
                u2_type  gim = u2_bu
                    (wir_r, c3__core, r_sut, q_sut, r_sut, s_sut);
                u2_pool   rev = u2_plow_(wir_r, ver);
                u2_flag  goh;

                u2_plow_(wir_r, ver) = u2_fj_pool_add(wir_r, fuy, u2_plow_(wir_r, ver));
                goh = u2_and
                  (_rose_show(wir_r, sut, gen),
                   u2_sing(_rose_make(wir_r, sut, gen), 
                           _rose_make(wir_r, gim, gen)));

                u2_plow_(wir_r, ver) = rev;
                if ( !u2_so(goh) ) {
                  u2_err(wir_r, "gen", gen);
                  u2_err(wir_r, "mka", _rose_make(wir_r, sut, gen));
                  u2_err(wir_r, "mkb", _rose_make(wir_r, gim, gen));
                  return _plow_fail(wir_r, "soft mack");
                }
                return goh;
              }
            } 
            else return u2_bl_bail(wir_r);
          }
          else return u2_bl_bail(wir_r);
        }
      }
      else if ( u2_yes == u2_as_pqr(gen, c3__trol, &p_gen, &q_gen, &r_gen) ) {
        return u2_and
          (_rose_show(wir_r, sut, p_gen),
           u2_and
           (_rose_show(wir_r, _rose_gain(wir_r, sut, p_gen), q_gen),
            _rose_show(wir_r, sut, r_gen)));
      }
      else if ( u2_yes == u2_as_pq(gen, c3__sing, &p_gen, &q_gen) ) {
        return u2_and
          (_rose_show(wir_r, sut, p_gen),
           _rose_show(wir_r, sut, q_gen));
      }
      else {
        u2_gene vul = _plow_open(wir_r, gen);

        if ( u2_yes == u2_sing(vul, gen) ) {
          u2_err(wir_r, "gen", gen);
          u2_err(wir_r, "vul", vul);
          return u2_bl_bail(wir_r);
        }

        return _rose_show(wir_r, sut, vul);
      }
    }
  static u2_flag
  _rose_show(u2_ray  wir_r,
             u2_type sut,
             u2_gene gen)
  {
#if 0
    return u2_yes;
#else
    
    u2_noun mum = u2_bc(wir_r, sut, gen);
    u2_weak zod = u2_fj_book_get(mum, u2_plow_(wir_r, hos));

    if ( zod != u2_none ) {
      return zod;
    }
    else {
      u2_flag gur = _rose_show_main(wir_r, sut, gen);

      u2_plow_(wir_r, hos) = u2_fj_book_add(wir_r, mum, gur, u2_plow_(wir_r, hos));
      return gur;
    }
#endif
  }

/****   _dump: pretty-printing.
****/
      /** Global variables.
      **/
        u2_pool how;

        static u2_prep
        _dump_main(u2_ray  wir_r, u2_pool gil, u2_pool nip, u2_type typ);

  /* seal:dump (fake)
  */
    u2_pool
    _dump_seal_main(u2_ray  wir_r,
                    u2_pool gil,
                    u2_type typ)
    {
      
      u2_noun p_typ, q_typ;

      // %atom
      // %blur
      //
      if ( u2_yes == u2_sing(c3__atom, typ) ||
           u2_yes == u2_sing(c3__blur, typ) ||
           u2_yes == u2_sing(c3__blot, typ) ) 
      {
        return u2_nul;
      }

      // [%cell p=type q=type]
      //
      else if ( u2_yes == u2_as_pq(typ, c3__cell, &p_typ, &q_typ) ) {
        return u2_fj_pool_cat(wir_r, _dump_seal_main(wir_r, gil, p_typ),
                               _dump_seal_main(wir_r, gil, q_typ));
      }

      // [%core p=type q=*]
      //
      else if ( u2_yes == u2_as_pq(typ, c3__core, &p_typ, &q_typ) ) {
        return _dump_seal_main(wir_r, gil, p_typ);
      }

      // [%cube p=noun]
      // 
      else if ( u2_yes == u2_as_p(typ, c3__cube, &p_typ) ) {
        return u2_nul;
      }

      // [%face p=mark q=type]
      //
      else if ( u2_yes == u2_as_pq(typ, c3__face, &p_typ, &q_typ) ) {
        return _dump_seal_main(wir_r, gil, q_typ);
      }

      // [%fork p=type q=type]
      //
      else if ( u2_yes == u2_as_pq(typ, c3__fork, &p_typ, &q_typ) ) {
        return u2_fj_pool_cat(wir_r, _dump_seal_main(wir_r, gil, p_typ),
                                _dump_seal_main(wir_r, gil, q_typ));
      }

      // [%fuse p=type q=type]
      //
      else if ( u2_yes == u2_as_pq(typ, c3__fuse, &p_typ, &q_typ) ) {
        return u2_fj_pool_cat(wir_r, _dump_seal_main(wir_r, gil, p_typ),
                                _dump_seal_main(wir_r, gil, q_typ));
      }

      // [%hold p=type q=gene]
      //
      else if ( u2_yes == u2_as_pq(typ, c3__hold, &p_typ, &q_typ) ) {
        if ( u2_fj_pool_in(typ, gil) ) {
          return u2_bt(wir_r, typ, u2_nul, u2_nul);
        } 
        else {
          return _dump_seal_main
            (wir_r, u2_fj_pool_add(wir_r, typ, gil),
                _rose_repo(wir_r, p_typ, q_typ));
        }
      }
      else {
        if ( u2_yes == u2_dust(typ) && u2_yes == u2_dust(u2_h(typ)) ) {
          printf("hm!\n");
        }
        else u2_err(wir_r, "odd type", typ);


        return u2_bl_bail(wir_r);
      }
    }

  /* _dump_seal(): produce set of holds sealing [typ].
  */
  static u2_pool
  _dump_seal(u2_ray  wir_r,
             u2_type typ)
  {
    return _dump_seal_main(wir_r, u2_nul, typ);
  }

  /* _dump_cell()::
  */
  static u2_noun
  _dump_cell(u2_ray  wir_r,
             u2_pool gil,
             u2_pool nip,
             u2_noun p_typ,
             u2_noun q_typ)
  {
    
    u2_noun pq_typ, qq_typ;

    if ( u2_yes == u2_as_pq(q_typ, c3__cell, &pq_typ, &qq_typ) ) {
      return u2_bc
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
              _dump_cell(wir_r, gil, nip, pq_typ, qq_typ));
    }
    else {
      return u2_bt
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
               _dump_main(wir_r, gil, nip, q_typ),
               u2_nul);
    }
  }

  /* _dump_core(): dump a core.
  */
  static u2_prep
  _dump_core(u2_ray  wir_r,
             u2_pool gil,
             u2_pool nip,
             u2_type myt,
             u2_atom kic,
             u2_spec dab)
  {
    
    u2_prep gum;
    u2_prep zib;
    u2_prep bor;

    zib = _dump_main(wir_r, gil, nip, myt);
    bor = u2_fj_op_glu
      (wir_r, (u2_yes == u2_sing(c3__soft, kic) ? ('-') : ('+')),
             u2_fj_op_glu
               (wir_r, u2_fj_prep_decimal(wir_r, _gull_size(wir_r, dab)),
                      u2_fj_op_glu
                        (wir_r, ('.'),
                               u2_fj_prep_hexinal
                                  (wir_r, (u2_mug(dab) & 0xffff)))));

    gum = u2_fj_prep_close
      (wir_r, '<', '>', u2_bn_list(wir_r, zib, bor, u2_none));

    return gum;
  }

  /* _dump_fork(): dump fork as list.
  */
  static u2_noun
  _dump_fork(u2_ray  wir_r,
             u2_pool gil,
             u2_pool nip,
             u2_type p_typ,
             u2_type q_typ)
  {
    
    u2_noun pq_typ, qq_typ;

    if ( u2_yes == u2_as_pq(q_typ, c3__fork, &pq_typ, &qq_typ) ) {
      return u2_bc
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
              _dump_fork(wir_r, gil, nip, pq_typ, qq_typ));
    }
    else {
      return u2_bt
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
              _dump_main(wir_r, gil, nip, q_typ),
              u2_nul);
    }
  }
   
  /* _dump_main(): dump with gil and nip.
  */
  static u2_prep
  _dump_main(u2_ray  wir_r,
             u2_pool gil,
             u2_pool nip,
             u2_type typ)
  {
    
    u2_noun p_typ, q_typ, r_typ, s_typ;

    if ( u2_yes == u2_stud(typ) ) {
      if ( u2_yes == u2_sing(c3__atom, typ) ) {
        return ('@');
      }
      else if ( u2_yes == u2_sing(c3__blot, typ) ) {
        return ('#');
      }
      else if ( u2_yes == u2_sing(c3__blur, typ) ) {
        return ('*');
      }
      else return u2_bl_bail(wir_r);
    }
    else if ( u2_yes == u2_as_pq(typ, c3__cell, &p_typ, &q_typ) ) {
      return u2_fj_prep_close
        (wir_r, '[', ']', 
                _dump_cell(wir_r, gil, nip, p_typ, q_typ));
    }
    else if ( u2_yes == u2_as_pqrs(typ, c3__core, &p_typ, &q_typ, &r_typ, &s_typ) ) {
      return _dump_core(wir_r, gil, nip, p_typ, q_typ, s_typ);
    }
    else if ( u2_yes == u2_as_p(typ, c3__cube, &p_typ) ) {
      if ( (u2_nul == p_typ) ) {
        return ('~');
      }
      else if ( u2_yes == u2_stud(p_typ) ) {
        return u2_fj_op_glu
          (wir_r, ('%'), u2_fj_prep_textual(wir_r, p_typ));
      }
      else {
        return u2_bn_list
          (wir_r,
           c3__nail,
           ('%'),
           u2_fj_prep_noun(wir_r, p_typ),
           u2_none);
      }
    }
    else if ( u2_yes == u2_as_pq(typ, c3__face, &p_typ, &q_typ) ) {
      return u2_bn_list
        (wir_r, c3__nail, 
               u2_fj_prep_textual(wir_r, p_typ),
               (':'),
               _dump_main(wir_r, gil, nip, q_typ),
               u2_none);
    }
    else if ( u2_yes == u2_as_pq(typ, c3__fork, &p_typ, &q_typ) ) {
      u2_noun pip_typ, piq_typ;

      if ( u2_yes == u2_as_p(p_typ, c3__cube, &pip_typ) &&
           u2_yes == u2_as_p(q_typ, c3__cube, &piq_typ) &&
           (u2_yes == pip_typ) &&
           (u2_no == piq_typ) )
      {
        return ('?');
      }
      else {
        return
          u2_fj_prep_close
            (wir_r, '{', '}', _dump_fork(wir_r, gil, nip, p_typ, q_typ));
      }
    }
    else if ( u2_yes == u2_as_pq(typ, c3__fuse, &p_typ, &q_typ) ) {
      return u2_fj_prep_close
        (wir_r, '(', ')', 
               u2_bn_list(wir_r,
                         _dump_main(wir_r, gil, nip, p_typ),
                         _dump_main(wir_r, gil, nip, q_typ),
                         u2_none));
    }
    else if ( u2_yes == u2_as_pq(typ, c3__hold, &p_typ, &q_typ) ) {
      if ( u2_fj_pool_in(typ, gil) ) {
        u2_noun fez = u2_fj_op_glu
            (wir_r, ('$'), 
                   u2_fj_prep_decimal(wir_r, u2_fj_pool_at(wir_r, typ, _1, gil)));

        if ( u2_fj_pool_in(typ, nip) || u2_fj_pool_in(typ, how) ) {
          return fez;
        }
        else {
          how = u2_fj_pool_add(wir_r, typ, how);
          { 
            u2_prep hod = 
              _dump_main(wir_r, gil, 
                            u2_fj_pool_add(wir_r, typ, nip),
                            _rose_repo(wir_r, p_typ, q_typ));

            
            return u2_bn_list
              (wir_r, c3__nail, 
                     fez,
                     ('='),
                     hod,
                     u2_none);
          }
        }
      }
      else {
        return _dump_main(wir_r, gil, nip, _rose_repo(wir_r, p_typ, q_typ));
      }
    }
    else {
      return u2_bl_bail(wir_r);
    }
  }

  /* _durb_in()::
  */
  static u2_noun
  _durb_in(u2_ray  wir_r,
           u2_rail bar)
  {
    if ( (u2_nul == bar) ) {
      return u2_nul;
    } else {
      return u2_bc(wir_r, _dump_type(wir_r, u2_h(bar)), 
                               _durb_in(wir_r, u2_t(bar)));
    }
  }
#if 0
  /* _dump_durb(): prepare rail for printing.
  */
  static u2_prep
  _dump_durb(u2_ray  wir_r,
             u2_rail bar)
  {
    if ( (u2_nul == bar) ) {
      return ('~');
    }
    else {
      return u2_fj_prep_close
        (wir_r, '(', ')', _durb_in(wir_r, bar));
    }
  }
#endif

  /* _dump_type(): prepare type for printing.
  */
  static u2_prep
  _dump_type(u2_ray  wir_r,
             u2_type typ)
  {
    u2_pool gil = _dump_seal(wir_r, typ);
    u2_prep par;

    // Lamentable.
    //
    how = u2_nul;
    par = _dump_main(wir_r, gil, u2_nul, typ);
    how = u2_nul;

    return par;
  }

  /* _dump_size()::
  */
  static u2_atom
  _dump_size(u2_ray wir_r, u2_noun box)
  {
    if ( u2_yes == u2_stud(box) ) {
      return _1;
    }
    else {
      return u2_fj_op_add
        (wir_r, _dump_size(wir_r, u2_h(box)), 
              _dump_size(wir_r, u2_t(box)));
    }
  }

/****   _plow: top-level functions.
****/
  static void
  _plow_trap(u2_ray  wir_r,
             const char *msg)
  {
    u2_atom hal  = u2_bn_string(wir_r, msg);

    u2_plow_(wir_r, meb) = 
      u2_bc(wir_r, u2_bc(wir_r, hal, u2_nul), u2_plow_(wir_r, meb));
  }

  static u2_noun
  _plow_fail(u2_ray  wir_r,
             const char *msg)
  {
    _plow_trap(wir_r, msg);
    {
      while ( !(u2_nul == u2_plow_(wir_r, meb)) ) {
        u2_noun i_meb = u2_h(u2_plow_(wir_r, meb));
        u2_noun hal = u2_h(i_meb);
        u2_noun jup = u2_t(i_meb);

        if ( !(u2_nul == hal) ) {
          c3_w sb_hal = u2_met(3, hal);
          c3_c *cl_hal = alloca(sb_hal + 1);

          u2_bytes(0, sb_hal + 1, (c3_y *)cl_hal, hal);
          printf("msg: %s\n", cl_hal);
        }

        if ( !(u2_nul == jup) ) {
          u2_atom pp_jup = u2_h(u2_h(jup));
          u2_atom qp_jup = u2_t(u2_h(jup));
          u2_atom pq_jup = u2_h(u2_t(jup));
          u2_atom qq_jup = u2_t(u2_t(jup));
          {
            c3_w xw_flin = (pp_jup);
            c3_w xw_fcol = (qp_jup);
            c3_w xw_llin = (pq_jup);
            c3_w xw_lcol = (qq_jup);

            printf("spot: %d:%d - %d:%d\n", 
                   xw_flin, xw_fcol, xw_llin, xw_lcol);
          }
        }
        u2_plow_(wir_r, meb) = u2_t(u2_plow_(wir_r, meb));
      }
    }
    return u2_bl_bail(wir_r);
    // return u2_bl_bail(wir_r);
  }

  /* rake:plow 
  */
  static u2_rope
  _plow_rake(u2_ray  wir_r,
             u2_gene gen)
  {
    
    u2_gene p_gen, q_gen;

    if ( u2_yes == u2_as_pq(gen, c3__mack, &p_gen, &q_gen) ) {
      if ( !(u2_nul == q_gen) ) {
        return _plow_fail(wir_r, "rope");
      }
      else return p_gen;
    }
    else if ( u2_yes == u2_as_p(gen, c3__frag, &p_gen) ) {
      return u2_bo(wir_r, gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__pane, &p_gen) ) {
      return u2_bo(wir_r, gen);
    }
    else if ( u2_yes == u2_as_pq(gen, c3__zemp, &p_gen, &q_gen) ) {
      return _plow_rake(wir_r, q_gen);
    }
    else if ( u2_yes == u2_as_p(gen, c3__zush, &p_gen) ) {
      return _plow_rake(wir_r, p_gen);
    }
    else {
      u2_err(wir_r, "rake", gen);
      return _plow_fail(wir_r, "rope");
    }
  }

  /* init:plow (fake)
  */
  void
  _plow_init(u2_ray wir_r)
  {
    c3_assert(_0 == u2_wire_plo_r(wir_r));
    u2_wire_plo_r(wir_r) = u2_rl_ralloc(wir_r, c3_wiseof(u2_loom_plow));

    u2_plow_(wir_r, fan) = u2_nul;
    u2_plow_(wir_r, ver) = u2_nul;
    u2_plow_(wir_r, bug) = u2_nul;
    u2_plow_(wir_r, meb) = u2_nul;
    u2_plow_(wir_r, vus) = u2_nul;
    u2_plow_(wir_r, tyc) = u2_nul;
    u2_plow_(wir_r, gam) = u2_nul;
    u2_plow_(wir_r, hos) = u2_nul;
    u2_plow_(wir_r, zor) = u2_nul;
    u2_plow_(wir_r, niq) = u2_nul;
    u2_plow_(wir_r, fac) = u2_nul;
    u2_plow_(wir_r, vom) = u2_nul;
    u2_plow_(wir_r, pon) = u2_nul;
    u2_plow_(wir_r, fin) = u2_nul;
    u2_plow_(wir_r, huf) = u2_nul;
  }

  void
  _plow_exit(u2_ray wir_r)
  {
    u2_rl_rfree(wir_r, u2_wire_plo_r(wir_r));
    u2_wire_plo_r(wir_r) = _0;
  }

  /* u2_fj_plow_make():
  **
  **   Not verifying type correctness, compile to formula.
  */
  u2_noun
  u2_fj_plow_make(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    pro = _rose_make(wir_r, sut, gen);
    _plow_exit(wir_r);

    return pro;
  }

  /* u2_fj_plow_play():
  **
  **   Not verifying type correctness, infer product type.
  */
  u2_noun
  u2_fj_plow_play(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    pro = _rose_make(wir_r, sut, gen);
    _plow_exit(wir_r);

    return pro;
  }

  /* u2_fj_plow_show():
  **
  **   Verify type correctness.
  */
  u2_noun
  u2_fj_plow_show(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    pro = _rose_show(wir_r, sut, gen);
    _plow_exit(wir_r);

    return pro;
  }

  /* u2_fj_plow_pass():
  **
  **   Verifying type correctness, compile to formula.
  */
  u2_noun
  u2_fj_plow_pass(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    {

      if ( !u2_so(_rose_show(wir_r, sut, gen)) ) {
        _plow_exit(wir_r);
        return u2_bl_bail(wir_r);
      }
      else pro = _rose_make(wir_r, sut, gen);
    }
    _plow_exit(wir_r);
    return pro;
  }

  /* u2_fj_plow_shop():
  **
  **   Verifying type correctness, infer product type.
  */
  u2_noun
  u2_fj_plow_shop(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    {

      if ( !u2_so(_rose_show(wir_r, sut, gen)) ) {
        _plow_exit(wir_r);
        return u2_bl_bail(wir_r);
      }
      else pro = _rose_play(wir_r, sut, gen);
    }
    _plow_exit(wir_r);
    return pro;
  }

  /* u2_fj_plow_wish():
  **
  **   Not verifying type correctness, compile and infer.
  */
  u2_noun
  u2_fj_plow_wish(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    pro = u2_bc(wir_r, _rose_play(wir_r, sut, gen), 
                       _rose_make(wir_r, sut, gen));
    _plow_exit(wir_r);

    return pro;
  }

  /* u2_fj_plow_mill():
  **
  **   Verifying type correctness, compile and infer.
  */
  u2_noun
  u2_fj_plow_mill(u2_ray  wir_r,
                  u2_type sut,
                  u2_gene gen)
  {
    u2_noun pro;

    _plow_init(wir_r);
    {

      if ( !u2_so(_rose_show(wir_r, sut, gen)) ) {
        _plow_exit(wir_r);
        return u2_bl_bail(wir_r);
      }
      else {
        pro = 
          u2_bc(wir_r, _rose_play(wir_r, sut, gen),
                       _rose_make(wir_r, sut, gen));
      }
    }
    _plow_exit(wir_r);
    return pro;
  }