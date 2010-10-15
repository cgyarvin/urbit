/* fj/plow.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/** Data structures.
**/
  /* Noun types.
  */

  /* Adaptation macros.
  */

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

#     define   u2_plow_(plo_r, pat)  *u2_at(plo_r, u2_loom_plow, pat)
  

/** Forward declarations.
**/

/****   _dump: pretty-printing.
****/
      /** Global variables.
      **/
        u4_pool how;

        static u4_prep
        _dump_main(u4_plow p, u4_pool gil, u4_pool nip, u4_type typ);

  /* seal:dump (fake)
  */
    static u4_pool
    _dump_seal_main(u4_plow p,
                    u4_pool gil,
                    u4_type typ)
    {
      u4_lane lan = p->lan;
      u4_noun p_typ, q_typ;

      // %atom
      // %blur
      //
      if ( u4_n_eq(u4_atom_atom, typ) ||
           u4_n_eq(u4_atom_blur, typ) ||
           u4_n_eq(u4_atom_blot, typ) ) 
      {
        return u4_nul;
      }

      // [%cell p=type q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
        return u4_bag_cat(lan, _dump_seal_main(p, gil, p_typ),
                               _dump_seal_main(p, gil, q_typ));
      }

      // [%core p=type q=*]
      //
      else if ( u4_b_pq(typ, u4_atom_core, &p_typ, &q_typ) ) {
        return _dump_seal_main(p, gil, p_typ);
      }

      // [%cube p=noun]
      // 
      else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
        return u4_nul;
      }

      // [%face p=mark q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_face, &p_typ, &q_typ) ) {
        return _dump_seal_main(p, gil, q_typ);
      }

      // [%fork p=type q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
        return u4_bag_cat(lan, _dump_seal_main(p, gil, p_typ),
                                _dump_seal_main(p, gil, q_typ));
      }

      // [%fuse p=type q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
        return u4_bag_cat(lan, _dump_seal_main(p, gil, p_typ),
                                _dump_seal_main(p, gil, q_typ));
      }

      // [%hold p=type q=gene]
      //
      else if ( u4_b_pq(typ, u4_atom_hold, &p_typ, &q_typ) ) {
        if ( u4_bag_in(typ, gil) ) {
          return u4_k_trel(lan, typ, u4_nul, u4_nul);
        } 
        else {
          return _dump_seal_main
            (p, u4_bag_add(lan, typ, gil),
                _rose_repo(p, p_typ, q_typ));
        }
      }
      else {
        if ( !u4_n_atom(typ) && !u4_n_atom(u4_ch(typ)) ) {
          printf("hm!\n");
        }
        else u4_err(lan, "odd type", typ);


        return u4_trip;
      }
    }

  /* _dump_seal(): produce set of holds sealing [typ].
  */
  u4_pool
  _dump_seal(u4_plow p,
             u4_type typ)
  {
    return _dump_seal_main(p, u4_nul, typ);
  }

  /* _dump_cell()::
  */
  static u4_noun
  _dump_cell(u4_plow p,
             u4_pool gil,
             u4_pool nip,
             u4_noun p_typ,
             u4_noun q_typ)
  {
    u4_lane lan = p->lan;
    u4_noun pq_typ, qq_typ;

    if ( u4_b_pq(q_typ, u4_atom_cell, &pq_typ, &qq_typ) ) {
      return u4_k_cell
        (lan, _dump_main(p, gil, nip, p_typ),
              _dump_cell(p, gil, nip, pq_typ, qq_typ));
    }
    else {
      return u4_k_trel
        (lan, _dump_main(p, gil, nip, p_typ),
               _dump_main(p, gil, nip, q_typ),
               u4_nul);
    }
  }

  /* _dump_core(): dump a core.
  */
  static u4_prep
  _dump_core(u4_plow p,
             u4_pool gil,
             u4_pool nip,
             u4_type myt,
             u4_atom kic,
             u4_spec dab)
  {
    u4_lane lan = p->lan;
    u4_prep gum;
    u4_prep zib;
    u4_prep bor;

    zib = _dump_main(p, gil, nip, myt);
    bor = u4_k_atom_cat
      (lan, (u4_n_eq(u4_atom_soft, kic) ? u4_cod_in('-') : u4_cod_in('+')),
             u4_k_atom_cat
               (lan, u4_prep_decimal(lan, _gull_size(p, dab)),
                      u4_k_atom_cat
                        (lan, u4_cod_in('.'),
                               u4_prep_hexinal
                                  (lan, u4_cod_in(u4_n_nub(dab) & 0xffff)))));

    gum = u4_prep_close
      (lan, '<', '>', u4_k_list(lan, zib, bor, 0));

    return gum;
  }

  /* _dump_fork(): dump fork as list.
  */
  static u4_noun
  _dump_fork(u4_plow p,
             u4_pool gil,
             u4_pool nip,
             u4_type p_typ,
             u4_type q_typ)
  {
    u4_lane lan = p->lan;
    u4_noun pq_typ, qq_typ;

    if ( u4_b_pq(q_typ, u4_atom_fork, &pq_typ, &qq_typ) ) {
      return u4_kc
        (lan, _dump_main(p, gil, nip, p_typ),
              _dump_fork(p, gil, nip, pq_typ, qq_typ));
    }
    else {
      return u4_kt
        (lan, _dump_main(p, gil, nip, p_typ),
              _dump_main(p, gil, nip, q_typ),
              u4_nul);
    }
  }
   
  /* _dump_main(): dump with gil and nip.
  */
  static u4_prep
  _dump_main(u4_plow p,
             u4_pool gil,
             u4_pool nip,
             u4_type typ)
  {
    u4_lane lan = p->lan;
    u4_noun p_typ, q_typ, r_typ, s_typ;

    if ( u4_n_atom(typ) ) {
      if ( u4_n_eq(u4_atom_atom, typ) ) {
        return u4_cod_in('@');
      }
      else if ( u4_n_eq(u4_atom_blot, typ) ) {
        return u4_cod_in('#');
      }
      else if ( u4_n_eq(u4_atom_blur, typ) ) {
        return u4_cod_in('*');
      }
      else return u4_trip;
    }
    else if ( u4_b_pq(typ, u4_atom_cell, &p_typ, &q_typ) ) {
      return u4_prep_close
        (lan, '[', ']', 
                _dump_cell(p, gil, nip, p_typ, q_typ));
    }
    else if ( u4_b_pqrs(typ, u4_atom_core, &p_typ, &q_typ, &r_typ, &s_typ) ) {
      return _dump_core(p, gil, nip, p_typ, q_typ, s_typ);
    }
    else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
      if ( u4_n_zero(p_typ) ) {
        return u4_cod_in('~');
      }
      else if ( u4_n_atom(p_typ) ) {
        return u4_k_atom_cat
          (lan, u4_cod_in('%'), u4_prep_textual(lan, p_typ));
      }
      else {
        return u4_k_list
          (lan,
           u4_atom_nail,
           u4_cod_in('%'),
           u4_pump_prep(lan, p_typ),
           0);
      }
    }
    else if ( u4_b_pq(typ, u4_atom_face, &p_typ, &q_typ) ) {
      return u4_k_list
        (lan, u4_atom_nail, 
               u4_prep_textual(lan, p_typ),
               u4_cod_in(':'),
               _dump_main(p, gil, nip, q_typ),
               0);
    }
    else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
      u4_noun pip_typ, piq_typ;

      if ( u4_b_p(p_typ, u4_atom_cube, &pip_typ) &&
           u4_b_p(q_typ, u4_atom_cube, &piq_typ) &&
           u4_n_eq(u4_yes, pip_typ) &&
           u4_n_eq(u4_no, piq_typ) )
      {
        return u4_cod_in('?');
      }
      else {
        return
          u4_prep_close
            (lan, '{', '}', _dump_fork(p, gil, nip, p_typ, q_typ));
      }
    }
    else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
      return u4_prep_close
        (lan, '(', ')', 
               u4_k_list(lan,
                         _dump_main(p, gil, nip, p_typ),
                         _dump_main(p, gil, nip, q_typ),
                         0));
    }
    else if ( u4_b_pq(typ, u4_atom_hold, &p_typ, &q_typ) ) {
      if ( u4_bag_in(typ, gil) ) {
        u4_noun fez = u4_k_atom_cat
            (lan, u4_cod_in('$'), 
                   u4_prep_decimal(lan, u4_bag_at(lan, typ, u4_axis_1, gil)));

        if ( u4_bag_in(typ, nip) || u4_bag_in(typ, how) ) {
          return fez;
        }
        else {
          how = u4_bag_add(lan, typ, how);
          { 
            u4_prep hod = 
              _dump_main(p, gil, 
                            u4_bag_add(lan, typ, nip),
                            _rose_repo(p, p_typ, q_typ));

            
            return u4_k_list
              (lan, u4_atom_nail, 
                     fez,
                     u4_cod_in('='),
                     hod,
                     0);
          }
        }
      }
      else {
        return _dump_main(p, gil, nip, _rose_repo(p, p_typ, q_typ));
      }
    }
    else {
      return u4_trip;
    }
  }

  /* _durb_in()::
  */
  static u4_noun
  _durb_in(u4_plow p,
           u4_rail bar)
  {
    if ( u4_n_zero(bar) ) {
      return u4_nul;
    } else {
      return u4_k_cell(p->lan, _dump_type(p, u4_ch(bar)), 
                               _durb_in(p, u4_ct(bar)));
    }
  }

  /* _dump_durb(): prepare rail for printing.
  */
  u4_prep
  _dump_durb(u4_plow p,
             u4_rail bar)
  {
    if ( u4_n_zero(bar) ) {
      return u4_cod_in('~');
    }
    else {
      return u4_prep_close
        (p->lan, '(', ')', _durb_in(p, bar));
    }
  }

  /* _dump_type(): prepare type for printing.
  */
  u4_prep
  _dump_type(u4_plow p,
             u4_type typ)
  {
    u4_pool gil = _dump_seal(p, typ);
    u4_prep par;

    // Lamentable.
    //
    how = u4_nul;
    par = _dump_main(p, gil, u4_nul, typ);
    how = u4_nul;

    return par;
  }

  /* _dump_size()::
  */
  u4_atom
  _dump_size(u4_lane lan, u4_noun box)
  {
    if ( u4_n_atom(box) ) {
      return u4_math_1;
    }
    else {
      return u4_op_add
        (lan, _dump_size(lan, u4_ch(box)), 
              _dump_size(lan, u4_ct(box)));
    }
  }
/****   _lily: formula assembly.
****/
  /* cons:lily
  */
  u4_tool
  _lily_cons(u4_plow p,
             u4_tool vur,
             u4_tool sed)
  {
    u4_lane lan = p->lan;
    u4_noun p_vur, p_sed;

    if ( u4_b_p(vur, u4_nock_bone, &p_vur) && 
         u4_b_p(sed, u4_nock_bone, &p_sed) ) {
      return u4_kt(lan, u4_nock_bone, p_vur, p_sed);
    }
    else if ( u4_b_p(vur, u4_nock_frag, &p_vur) && 
              u4_b_p(sed, u4_nock_frag, &p_sed) &&
              !u4_n_eq(u4_axis_1, p_vur) &&
              !u4_n_eq(p_vur, p_sed) &&
              u4_n_zero(u4_op_ord(p_vur, p_sed)) )
    {
      u4_atom fub = u4_op_div(lan, u4_math_2, p_vur);
      u4_atom nof = u4_op_div(lan, u4_math_2, p_sed);

      if ( u4_n_eq(fub, nof) ) {
        return u4_kc(lan, u4_nock_frag, fub);
      }
    }
    return u4_kc(lan, vur, sed);
  }

  /* comb:lily
  */
  u4_tool
  _lily_comb(u4_plow p,
             u4_tool mal,
             u4_tool buz)
  {
    u4_lane lan = p->lan;
    u4_noun p_mal, q_mal, p_buz, q_buz, pp_buz, pq_buz;

    if ( u4_b_p(mal, u4_nock_frag, &p_mal) ) {
      if ( u4_b_p(buz, u4_nock_frag, &p_buz) ) {
        if ( u4_n_zero(p_buz) ) {
          return buz;
        }
        return u4_kc(lan, u4_nock_frag, u4_op_peg(lan, p_mal, p_buz));
      }
      else if ( u4_b_pq(buz, u4_nock_sail, &p_buz, &q_buz) &&
                u4_b_p(p_buz, u4_nock_frag, &pp_buz) &&
                u4_b_p(q_buz, u4_nock_frag, &pq_buz) )
      {
        return u4_kt
          (lan, u4_nock_sail, 
                 u4_kc(lan, u4_nock_frag, u4_op_peg(lan, p_mal, pp_buz)),
                 u4_kc(lan, u4_nock_frag, u4_op_peg(lan, p_mal, pq_buz)));
      }
    }
    else if ( u4_b_fork(mal, &p_mal, &q_mal) ) {
      if ( !u4_n_atom(q_mal) && 
           u4_n_eq(u4_noun_0, u4_ch(q_mal)) &&
           u4_n_eq(u4_noun_1, u4_ct(q_mal)) )
      {
        return u4_kt(lan, u4_nock_gant, p_mal, buz);
      }
    }
    else if ( u4_b_p(buz, u4_nock_frag, &p_buz) ) {
      if ( u4_n_eq(u4_axis_1, p_buz) ) {
        return mal;
      }
    }
    // return u4_kq(lan, u4_nock_sail, mal, u4_nock_bone, buz);
    return u4_kt(lan, u4_nock_flac, mal, buz);
  }

  /* flan:lily
  */
  u4_tool
  _lily_flan(u4_plow p,
             u4_tool zeg,
             u4_tool dac)
  {
    u4_lane lan = p->lan;

    if ( u4_n_eq(u4_nock_bone, u4_ch(zeg)) ) {
      if ( u4_n_zero(u4_ct(zeg)) ) {
        return dac;
      }
      else return zeg;
    }
    else {
      if ( u4_n_eq(u4_nock_bone, u4_ch(dac)) ) {
        if ( u4_n_zero(u4_ct(dac)) ) {
          return zeg;
        }
        else return dac;
      }
      else {
        return u4_kq
          (lan, u4_nock_trol, zeg, dac, u4_kc(lan, u4_nock_bone, u4_no));
      }
    }
  }

  /* flor:lily
  */
  u4_tool
  _lily_flor(u4_plow p,
             u4_tool bos,
             u4_tool nif)
  {
    u4_lane lan = p->lan;

    if ( u4_n_eq(u4_nock_bone, u4_ch(bos)) ) {
      if ( u4_n_zero(u4_ct(bos)) ) {
        return bos;
      }
      else return nif;
    }
    else {
      if ( u4_n_eq(u4_nock_bone, u4_ch(nif)) ) {
        if ( u4_n_zero(u4_ct(nif)) ) {
          return nif;
        }
        else return bos;
      }
      else {
        return u4_kq
          (lan, u4_nock_trol, bos, u4_kc(lan, u4_nock_bone, u4_yes), nif);
      }
    }
  }

  /* _lily_flop(): invert boolean.
  */
  u4_tool
  _lily_flop(u4_plow p,
             u4_tool zet)
  {
    u4_lane lan = p->lan;

    if ( u4_n_eq(u4_nock_bone, u4_ch(zet)) ) {
      if ( u4_n_eq(u4_yes, u4_ct(zet)) ) {
        return u4_kc(lan, u4_nock_bone, u4_no);
      }
      else {
        u4_assert(u4_n_eq(u4_no, u4_ct(zet)));

        return u4_kc(lan, u4_nock_bone, u4_yes);
      }
    }
    else {
      return u4_kq
        (lan, u4_nock_trol, 
               zet, 
               u4_kc(lan, u4_nock_bone, u4_no), 
               u4_kc(lan, u4_nock_bone, u4_yes));
    }
  }

  /* hike:lily:plow
  */
    static u4_axis 
    _lily_hike_axis_l(u4_lane lan, 
                      u4_axis axis)
    {
      return u4_op_add(lan, axis, axis);
    }
    u4_axis 
    _lily_hike_axis_r(u4_lane lan, 
                      u4_axis axis)
    {
      return u4_op_inc(lan, _lily_hike_axis_l(lan, axis));
    }

    /* _lily_hike_belt_root(): convert (vix) to a log of root tools.
    */
    static u4_log
    _lily_hike_belt_root(u4_lane lan,
                         u4_list vix)
    {
      if ( u4_n_zero(vix) ) {
        return u4_nul;
      }
      else {
        u4_axis axis     = u4_ch(u4_ch(vix));
        u4_tool tool     = u4_ct(u4_ch(vix));
        u4_list log_tool = _lily_hike_belt_root(lan, u4_ct(vix));

        if ( u4_n_eq(u4_axis_1, axis) ) {
          return u4_kc(lan, tool, log_tool);
        }
        else return log_tool;
      }
    }

    /* _lily_hike_belt_l(): factor (vix) left.
    */
    static u4_log
    _lily_hike_belt_l(u4_lane lan,
                u4_list vix)
    {
      if ( u4_n_zero(vix) ) {
        return u4_nul;
      }
      else {
        u4_axis axis       = u4_ch(u4_ch(vix));
        u4_tool tool       = u4_ct(u4_ch(vix));
        u4_list belt_l = _lily_hike_belt_l(lan, u4_ct(vix));
        {
          if ( u4_n_eq(u4_axis_2, u4_op_tip(axis)) ) {
            u4_axis axis_tap = u4_op_tap(lan, axis);

            return u4_kc(lan, u4_kc(lan, axis_tap, tool), belt_l);
          }
          else return belt_l;
        }
      }
    }

    /* _lily_hike_belt_r(): factor (vix) right.
    */
    static u4_log
    _lily_hike_belt_r(u4_lane lan,
                      u4_list vix)
    {
      if ( u4_n_zero(vix) ) {
        return u4_nul;
      }
      else {
        u4_axis axis       = u4_ch(u4_ch(vix));
        u4_tool tool       = u4_ct(u4_ch(vix));
        u4_list belt_r = _lily_hike_belt_r(lan, u4_ct(vix));
        {
          if ( u4_n_eq(u4_axis_3, u4_op_tip(axis)) ) {
            u4_axis axis_tap = u4_op_tap(lan, axis);

            return u4_kc(lan, u4_kc(lan, axis_tap, tool), belt_r);
          }
          else return belt_r;
        }
      }
    }
  u4_tool
  _lily_hike(u4_plow p,
             u4_axis axe,
             u4_list vix)  /* (axis tool) */
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(vix) ) {
      return u4_kc(lan, u4_nock_frag, axe);
    }
    else {
      u4_list log_tool    = _lily_hike_belt_root(lan, vix);
      u4_list belt_l  = _lily_hike_belt_l(lan, vix);
      u4_list belt_r  = _lily_hike_belt_r(lan, vix);

      if ( !u4_n_zero(log_tool) ) {
        return u4_ch(log_tool);
      }
      else {
        u4_tool tool_l, tool_r;
        
        tool_l = _lily_hike(p, _lily_hike_axis_l(lan, axe), belt_l);
        tool_r = _lily_hike(p, _lily_hike_axis_r(lan, axe), belt_r);

        return _lily_cons(p, tool_l, tool_r);
      }
    }
  }

/****   _open: macro expansion.
****/
#define _open_p(stem) \
  if ( u4_b_p(gen, u4_atom_##stem, &p_gen) ) { \
    return _open_in_##stem(p, p_gen); \
  }

#define _open_pq(stem) \
  if ( u4_b_pq(gen, u4_atom_##stem, &p_gen, &q_gen) ) { \
    return _open_in_##stem(p, p_gen, q_gen); \
  }

#define _open_pqr(stem) \
  if ( u4_b_pqr(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen) ) {\
    return _open_in_##stem(p, p_gen, q_gen, r_gen); \
  }

#define _open_pqrs(stem) \
  if ( u4_b_pqrs(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen, &s_gen) ) {\
    return _open_in_##stem(p, p_gen, q_gen, r_gen, s_gen); \
  }

#define _open_do_p(stem)  \
  static u4_gene _open_in_##stem \
    (u4_plow p, u4_noun p_gen)

#define _open_do_pq(stem)  \
  static u4_gene _open_in_##stem \
    (u4_plow p, u4_noun p_gen, u4_noun q_gen)

#define _open_do_pqr(stem)  \
  static u4_gene _open_in_##stem \
    (u4_plow p, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)

#define _open_do_pqrs(stem)  \
  static u4_gene _open_in_##stem \
    (u4_plow p, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen, u4_noun s_gen)

  /* mast:open:plow
  */
    static u4_gene
    _open_mast(u4_plow, u4_gene);

    static u4_gene 
    _open_mast_fix(u4_plow p,
                   u4_gene gen,
                   u4_axis axe)
    {
      u4_lane lan = p->lan;
      u4_noun p_gen, q_gen;

      if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return _open_mast_fix(p, p_gen, axe);
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return u4_kt
          (lan, 
           u4_atom_twix,
           _open_mast_fix(p, p_gen, u4_op_peg(lan, axe, u4_axis_2)),
           _open_mast_fix(p, q_gen, u4_op_peg(lan, axe, u4_axis_3)));
      }
      else if ( u4_b_pq(gen, u4_atom_velt, &p_gen, &q_gen) ) {
        u4_tool ryx = u4_kc(lan, u4_atom_frag, axe);

        return u4_kt
          (lan, 
           u4_atom_flac,
           u4_kt(lan, 
                 u4_atom_mack, 
                 u4_blip,
                 u4_kl
                  (lan,
                   u4_kc
                    (lan, 
                     ryx,
                     u4_kq
                      (lan, u4_atom_fung, _open_mast(p, q_gen), ryx, u4_nul)))),
           _open_mast_fix(p, p_gen, axe));
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return u4_kt
          (lan, u4_atom_bran, p_gen, _open_mast_fix(p, q_gen, axe));
      }
      else if ( u4_b_p(gen, u4_atom_teck, &p_gen) ) {
        return u4_kq
          (lan, u4_atom_fung,
                p_gen,
                u4_kc(lan, u4_atom_frag, axe),
                u4_nul);
      }
      else if ( u4_b_pq(gen, u4_atom_pock, &p_gen, &q_gen) ) {
        return _open_mast_fix(p, q_gen, axe);
      } 
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        return u4_kt(lan, u4_atom_zemp, p_gen, _open_mast_fix(p, q_gen, axe));
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        return u4_kc(lan, u4_atom_zush, _open_mast_fix(p, p_gen, axe));
      }
      else {
        u4_gene bog = _plow_open(p, gen);

        if ( !u4_n_eq(gen, bog) ) {
          return _open_mast_fix(p, bog, axe);
        }
        else {
          u4_tool ryx = u4_kc(lan, u4_atom_frag, axe);

          return u4_kt
            (lan,
             u4_atom_gram, 
             u4_kt(lan, u4_atom_plin, gen, ryx), 
             ryx);
        }
      }
    }
  static u4_gene
  _open_mast(u4_plow p,
             u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun p_gen, q_gen;

    if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return u4_kt
        (lan,
         u4_atom_gant,
         u4_kt(lan, u4_atom_wost, u4_atom_mave, q_gen),
         u4_kt(lan, u4_atom_lome, u4_nul, _open_mast_fix(p, p_gen, u4_axis_4)));
    }
    else if ( u4_b_pq(gen, u4_atom_pock, &p_gen, &q_gen) ) {
      return _open_mast(p, q_gen);
    }
    else if ( u4_b_p(gen, u4_atom_teck, &p_gen) ) {
      return p_gen;
    }
    else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
      return u4_kt(lan, u4_atom_zemp, p_gen, _open_mast(p, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
      return u4_kc(lan, u4_atom_zush, _open_mast(p, p_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_velt, &p_gen, &q_gen) ) {
      u4_tool ryx = u4_kc(lan, u4_atom_frag, u4_axis_4);

      return u4_kt
        (lan,
         u4_atom_gant,
         u4_kt(lan, u4_atom_wost, u4_atom_mave, q_gen),
         u4_kt
          (lan,
           u4_atom_lome,
           u4_nul,
           u4_kt
            (lan, 
             u4_atom_flac,
              u4_kt
                (lan,
                 u4_atom_mack,
                 u4_blip,
                 u4_kl
                  (lan,
                   u4_kc
                    (lan, 
                     ryx,
                     u4_kq
                      (lan, u4_atom_fung, _open_mast(p, q_gen), ryx, u4_nul)))),
             _open_mast_fix(p, p_gen, u4_axis_4))));
    }
    else {
      u4_gene bog = _plow_open(p, gen);

      if ( !u4_n_eq(gen, bog) ) {
        return _open_mast(p, bog);
      }
      else {
        return u4_kt
          (lan,
           u4_atom_gant,
           u4_kt(lan, u4_atom_wost, u4_atom_mave, gen),
           u4_kt(lan, u4_atom_lome, u4_nul, _open_mast_fix(p, gen, u4_axis_4)));
      }
    }
  }

  /* fist:open:plow
  */
    static u4_gene
    _open_fist(u4_plow, u4_gene);

    static u4_list
    _open_fist_a(u4_plow p,
                 u4_bank ban)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(ban) ) {
        return u4_nul;
      }
      else {
        return u4_kc
          (lan, _open_fist(p, u4_ch(ban)), _open_fist_a(p, u4_ct(ban)));
      }
    }
  static u4_gene
  _open_fist(u4_plow p,
             u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun p_gen, q_gen;

    if ( u4_b_p(gen, u4_atom_bean, &p_gen) ) {
      return gen;
    }
    else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, u4_atom_cast, p_gen, _open_fist(p, q_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, u4_atom_twix, _open_fist(p, p_gen), _open_fist(p, q_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_velt, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, u4_atom_velt, _open_fist(p, p_gen), _open_fist(p, q_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, u4_atom_zemp, p_gen, _open_fist(p, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
      return u4_kc
        (lan, u4_atom_zush, _open_fist(p, p_gen));
    }
    else if ( u4_b_p(gen, u4_atom_fist, &p_gen) ) {
      return _open_fist(p, p_gen);
    }
    else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
      return u4_kt
        (lan, u4_atom_bran, p_gen, _open_fist(p, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_teck, &p_gen) ) {
      u4_noun pp_gen;

      if ( u4_b_p(p_gen, u4_atom_rond, &pp_gen) ) {
        return u4_kt(lan, u4_atom_teck, u4_atom_rond, _open_fist_a(p, pp_gen));
      }
      else {
        return u4_kc(lan, u4_atom_bean, u4_atom_blur);
      }
    }
    else if ( u4_b_pq(gen, u4_atom_pock, &p_gen, &q_gen) ) {
      return _open_fist(p, p_gen);
    }
    else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
      return gen;
    }
    else {
      u4_gene bog = _plow_open(p, gen);

      if ( !u4_n_eq(gen, bog) ) {
        return _open_fist(p, bog);
      }
      else {
        return u4_kc(lan, u4_atom_bean, u4_atom_blur);
      }
    }
  }

  _open_do_p(bean)
  {
    u4_lane lan = p->lan;

    if ( u4_n_eq(u4_atom_atom, p_gen) ) {
      return u4_kt
        (lan, u4_atom_cast, 
              u4_kt(lan, u4_atom_vint, u4_atom_bone, u4_math_0),
              u4_kc(lan, u4_atom_bone, u4_math_0));
    }
    else if ( u4_n_eq(u4_atom_blur, p_gen) ) {
      u4_noun dud = u4_kc(lan, u4_atom_bone, u4_nul);

      return u4_kt
        (lan, u4_atom_cast, 
              u4_kt(lan, u4_atom_sail, dud, dud),
              dud);
    }
    else if ( u4_n_eq(u4_atom_cell, p_gen) ) {
      return u4_kt
        (lan, u4_atom_twix,
              u4_kc(lan, u4_atom_bean, u4_atom_blur),
              u4_kc(lan, u4_atom_bean, u4_atom_blur));
    }
    else if ( u4_n_eq(u4_atom_flag, p_gen) ) {
      return u4_kt
        (lan, u4_atom_cast,
              u4_kt(lan, u4_atom_dust, u4_atom_bone, u4_math_0),
              u4_kc(lan, u4_atom_bone, u4_yes));
    }
    else if ( u4_n_eq(u4_atom_null, p_gen) ) {
        return u4_kc(lan, u4_atom_bone, u4_nul);
    }
    else return u4_trip;
  }

  _open_do_pq(lonk)
  {
    u4_lane lan = p->lan;
    u4_noun beg = u4_kc(lan, u4_atom_frag, u4_axis_4);

    if ( u4_n_zero(q_gen) ) {
      return _plow_fail(p, "lonk");
    }
    else {
      u4_noun iq_gen = u4_ch(q_gen);
      u4_noun tq_gen = u4_ct(q_gen);

      if ( u4_n_zero(tq_gen) ) {
        return iq_gen;
      }
      else {
        return u4_kt
          (lan,
           u4_atom_gant,
           _open_in_lonk(p, p_gen, tq_gen),
           u4_kt
            (lan,
             u4_atom_gant,
             u4_kt(lan, u4_atom_flac,
                        u4_kc(lan, u4_atom_frag, u4_axis_3),
                        iq_gen),
             u4_kt
              (lan, 
               u4_atom_gant,
               u4_kc(lan, u4_atom_frag, u4_axis_8), 
               u4_kt
                (lan,
                 u4_atom_sunt,
                 u4_nul,
                 u4_kq
                  (lan,
                   u4_atom_bung,
                   u4_kt(lan,
                         u4_atom_flac,
                         u4_kc(lan, u4_atom_frag, u4_cod_in(23)),
                         p_gen),
                   u4_kq
                    (lan,
                     u4_atom_fung,
                     u4_kc(lan, u4_atom_frag, u4_axis_10),
                     beg,
                     u4_nul),
                  u4_kt
                    (lan,
                     u4_atom_mack,
                     u4_kc(lan, 
                           u4_kc(lan, u4_atom_frag, u4_cod_in(22)), 
                           u4_nul),
                     u4_kc
                      (lan,
                       u4_kc(lan, beg, beg),
                       u4_nul)))))));
      }
    }
  }

    static u4_noun
    _gath_a(u4_lane lan,
            u4_noun r_gen)
    {
      if ( u4_n_zero(r_gen) ) {
        return u4_nul;
      } 
      else {
        u4_noun ir_gen = u4_ch(r_gen);
        u4_noun tr_gen = u4_ct(r_gen);
        u4_noun pir_gen = u4_ch(ir_gen);
        u4_noun qir_gen = u4_ct(ir_gen);

        return u4_kc
          (lan, u4_kc(lan, pir_gen, 
                           u4_kt(lan, u4_atom_flac, 
                                      u4_kc(lan, u4_atom_frag, u4_axis_3),
                                      qir_gen)),
               _gath_a(lan, tr_gen));
      }
    }
  _open_do_pqr(gath)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_gant,
            q_gen,
            u4_kt
              (lan,
               u4_atom_mack,
               u4_kc(lan, u4_kc(lan, u4_atom_frag, u4_axis_2), p_gen),
               _gath_a(lan, r_gen)));
  }
  _open_do_p(prex)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(p_gen) ) {
      return u4_kc(lan, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      if ( u4_n_zero(tp_gen) ) {
        return ip_gen;
      } else {
        return u4_kt
          (lan, u4_atom_twix, ip_gen, _open_in_prex(p, tp_gen));
      }
    }
  }
 
  _open_do_pq(fung)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(q_gen) ) {
      return u4_kt
        (lan, u4_atom_flac, 
              p_gen,
              u4_kc(lan, u4_atom_pane, u4_blip));
    } else {
      return u4_kq(lan, u4_atom_mung, p_gen, u4_atom_prex, q_gen);
    }
  }

  _open_do_pqr(hang)
  {
    u4_lane lan = p->lan;

    return u4_kq
      (lan, u4_atom_gath,
            p_gen,
            q_gen,
            u4_kl(lan,
                  u4_kc(lan,
                        u4_kc(lan, u4_atom_frag, u4_axis_4),
                        r_gen)));
  }

  _open_do_pq(mung)
  {
    u4_lane lan = p->lan;

    return u4_kq
      (lan, u4_atom_gath,
            u4_kc(lan, u4_blip, u4_nul),
            p_gen,
            u4_kl(lan,
                  u4_kc(lan,
                        u4_kc(lan, u4_atom_frag, u4_axis_4),
                        q_gen)));
  }

  _open_do_pq(velt)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_gant,
            q_gen,
            u4_kt
              (lan, u4_atom_grel,
                    u4_kc(lan, u4_atom_frag, u4_axis_2),
                    u4_kl(lan,
                          u4_kc(lan,
                                u4_kt(lan, u4_atom_flac,
                                           u4_kc(lan, u4_atom_frag, u4_axis_3),
                                           q_gen),
                                u4_kc(lan, u4_atom_frag, u4_axis_2)))));
  }

  _open_do_p(mast)
  {
    return _open_mast(p, p_gen);
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
    u4_lane lan = p->lan;

    return u4_kq
      (lan, u4_atom_trol,
            p_gen,
            u4_kc(lan, u4_atom_zike, u4_nul),
            q_gen);
  }

  _open_do_p(vern)
  {
    u4_lane lan = p->lan;

    return u4_kq
      (lan, u4_atom_trol,
            p_gen,
            u4_kc(lan, u4_atom_bone, u4_no),
            u4_kc(lan, u4_atom_bone, u4_yes));
  }

  _open_do_p(slax)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(p_gen) ) {
      return u4_kc(lan, u4_atom_bone, u4_nul);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      return u4_kt(lan, u4_atom_twix, ip_gen, _open_in_slax(p, tp_gen));
    }
  }

  _open_do_p(frag)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_mack, 
            u4_kc(lan, u4_kc(lan, u4_atom_frag, p_gen), u4_nul),
            u4_nul);
  }

  _open_do_p(fist)
  {
    return _open_fist(p, p_gen);
  }

  _open_do_pq(lome)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_pank,
            p_gen,
            u4_kl(lan, u4_kc(lan, u4_blip, q_gen)));
  }

  _open_do_pq(gnum)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_fung, q_gen, u4_kc(lan, p_gen, u4_nul));
  }

  _open_do_pqr(bung)
  {
    u4_lane lan = p->lan;

    return u4_kc
      (lan, u4_atom_fung, 
            u4_kq(lan, p_gen, q_gen, r_gen, u4_nul));
  }

  _open_do_pq(claf)
  {
    u4_lane lan = p->lan;

    return u4_kt(lan, u4_atom_flac, q_gen, p_gen);
  }

  _open_do_pqr(lort)
  {
    u4_lane lan = p->lan;

    return u4_kq(lan, u4_atom_trol, p_gen, r_gen, q_gen);
  }

  _open_do_pq(vamp)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_flac,
            u4_kt(lan, u4_atom_lome, p_gen, q_gen),
            u4_kc(lan, u4_atom_pane, u4_blip));
  }

  _open_do_p(zole)
  {
    u4_lane lan = p->lan;

    return u4_kc(lan, u4_atom_bone, p_gen);
  }

  _open_do_pq(moze)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(q_gen) ) {
      return u4_kc(lan, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun iq_gen = u4_ch(q_gen);
      u4_noun tq_gen = u4_ct(q_gen);

#if 0
      if ( !u4_n_zero(p->bug) ) {
        u4_err(lan, "moze: iq_gen", iq_gen);
        u4_err(lan, "moze: fist", _open_fist(p, iq_gen));
        u4_err(lan, "moze: mast", _open_mast(p, iq_gen));
        printf("\n");
      }
#endif
      return u4_kq
        (lan,
         u4_atom_trol,
         u4_kt(lan, u4_atom_plin, _open_fist(p, iq_gen), p_gen),
         u4_kq(lan, u4_atom_fung, _open_mast(p, iq_gen), p_gen, u4_nul),
         _open_in_moze(p, p_gen, tq_gen));
    }
  }

  _open_do_p(rond)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(p_gen) ) {
      return u4_kc(lan, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);

      return u4_kt
        (lan,
         u4_atom_gant,
         u4_kc(lan, u4_atom_mave, ip_gen),
         u4_kt(lan, u4_atom_lome,
                    u4_nul,
                    u4_kt(lan, u4_atom_moze, 
                               u4_kc(lan, u4_atom_frag, u4_axis_4),
                               p_gen)));
    }
  }

  _open_do_pq(frit)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_gant,
            p_gen,
            u4_kt
              (lan,
               u4_atom_mack,
               u4_kl(lan, u4_kc(lan, u4_atom_frag, u4_axis_2)),
               u4_kl(lan,
                     u4_kc(lan,
                           u4_kc(lan, u4_atom_frag, u4_axis_4),
                           u4_kt(lan, u4_atom_flac, 
                                      u4_kc(lan, u4_atom_frag, u4_axis_3),
                                      q_gen)))));
  }

  _open_do_p(pane)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_mack, 
            u4_kc(lan, u4_kc(lan, u4_atom_pane, p_gen), u4_nul),
            u4_nul);
  }

  _open_do_pq(tang)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_gant, q_gen, p_gen);
  }

  _open_do_p(teck)
  {
    u4_lane lan = p->lan;

    return u4_kc
      (lan, u4_atom_wost,
            u4_kt(lan, u4_atom_flac,
                       p_gen,
                       u4_kt(lan, u4_atom_mack, 
                                  u4_kl(lan, u4_kc(lan, u4_atom_pane, u4_blip)),
                                  u4_nul)));
  }

  _open_do_pq(gant)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_flac,
            u4_kt(lan, u4_atom_twix, 
                       p_gen, 
                       u4_kc(lan, u4_atom_frag, u4_axis_1)),
            q_gen);
  }

  _open_do_pqrs(quax)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_twix,
            p_gen,
            u4_kt
              (lan, u4_atom_twix,
                    q_gen,
                    u4_kt(lan, u4_atom_twix, r_gen, s_gen)));
  }

  _open_do_p(chan)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(p_gen) ) {
      return u4_kc(lan, u4_atom_bone, u4_yes);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      return u4_kq
        (lan, u4_atom_trol,
              ip_gen,
              _open_in_chan(p, tp_gen),
              u4_kc(lan, u4_atom_bone, u4_no));
    }
  }

  _open_do_pq(grel)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(q_gen) ) {
      return u4_kc(lan, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun iq_gen = u4_ch(q_gen);
      u4_noun tq_gen = u4_ct(q_gen);
      u4_noun piq_gen = u4_ch(iq_gen);
      u4_noun qiq_gen = u4_ct(iq_gen);

      return u4_kq
        (lan, 
         u4_atom_trol,
         u4_kt(lan, u4_atom_plin, _open_fist(p, piq_gen), p_gen),
         u4_kt
          (lan, u4_atom_flac,
                u4_kt(lan,
                      u4_atom_stil,
                      piq_gen,
                      p_gen),
                qiq_gen),
         _open_in_grel(p, p_gen, tq_gen));
    }
  }

  _open_do_pq(sunt)
  {
    u4_lane lan = p->lan;

    return u4_kq
      (lan, u4_atom_tash, 
            p_gen,
            u4_kc(lan, u4_blip, q_gen),
            u4_nul);
  }

  _open_do_pq(pock)
  {
    u4_lane lan = p->lan;
    u4_noun rax = u4_kc(lan, u4_atom_frag, u4_axis_2);

    return u4_kt
      (lan,
       u4_atom_gant,
       q_gen, 
       u4_kt
        (lan,
         u4_atom_claf,
         rax,
         u4_kt(lan,
               u4_atom_stil,
               u4_kt(lan, 
                     u4_atom_flac, 
                     u4_kc(lan, u4_atom_frag, u4_axis_3), 
                     p_gen),
               rax)));
  }

  _open_do_p(dorn)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(p_gen) ) {
      return u4_kc(lan, u4_atom_bone, u4_no);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      return u4_kq
        (lan, u4_atom_trol,
              ip_gen,
              u4_kc(lan, u4_atom_bone, u4_yes),
              _open_in_dorn(p, tp_gen));
    }
  }

  _open_do_pq(zemp)
  {
    return q_gen;
  }

  _open_do_pqr(fent)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan,
       u4_atom_grel,
       p_gen,
       u4_kt
        (lan,
         u4_kc(lan, u4_kc(lan, u4_atom_bone, u4_nul), q_gen),
         u4_kc(lan, u4_kc(lan, u4_atom_bean, u4_atom_cell), r_gen),
         u4_nul));
  }

  _open_do_pq(gram)
  {
    u4_lane lan = p->lan;
    
    return u4_kq
      (lan, u4_atom_trol, p_gen, q_gen, u4_kc(lan, u4_atom_zike, u4_nul));
  }

  _open_do_pqr(trex)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_twix,
            p_gen,
            u4_kt(lan, u4_atom_twix, q_gen, r_gen));
  }

  _open_do_pqrs(tung)
  {
    u4_lane lan = p->lan;

    return u4_kq
      (lan, u4_atom_fung, 
            p_gen, 
            q_gen,
            u4_kt(lan, r_gen, s_gen, u4_nul));
  }

  _open_do_p(mave)
  {
    u4_lane lan = p->lan;

    return u4_kt
      (lan, u4_atom_cast, 
            u4_kc(lan, u4_atom_bean, u4_atom_blur),
            p_gen);
  }

  _open_do_pq(yell)
  {
    u4_lane lan = p->lan;

    return u4_kt(lan, u4_atom_fung, p_gen, q_gen);
  }

  /* open:plow
  */
    static u4_gene
    _plow_open_main(u4_plow p,
                    u4_gene gen)
    {
      u4_noun p_gen, q_gen, r_gen, s_gen;

      if ( u4_b_fork(gen, &p_gen, &q_gen) ) {
        u4_err(p->lan, "gen", gen);
        return _plow_fail(p, "bad code");
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
  u4_gene
  _plow_open(u4_plow p,
             u4_gene gen)
  {
    u4_nopt zax = u4_tab_get(gen, p->pon);

    if ( u4_bull != zax ) {
      return zax;
    }
    else {
      zax = _plow_open_main(p, gen);

#if 0
      if ( !u4_n_zero(p->bug) && u4_b_p(gen, u4_atom_teck, 0) ) {
        u4_err(p->lan, "open: gen", gen);
        u4_err(p->lan, "open: zax", zax);
        printf("\n");
      }
#endif
      p->pon = u4_tab_add(p->lan, gen, zax, p->pon);
      return zax;
    }
  }

/****   _gull: battery symbol table.
****/
  /* size:gull:plow
  */
  u4_atom
  _gull_size(u4_plow p,
             u4_book dab)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(dab) ) {
      return u4_noun_0;
    } else {
      u4_noun n_dab, l_dab, r_dab;

      u4_c_trel(dab, &n_dab, &l_dab, &r_dab);

      return u4_op_inc(lan, u4_op_add(lan, _gull_size(p, l_dab),
                                           _gull_size(p, r_dab)));
    }
  }

  /* fill:gull:plow
  */
  u4_spec
  _gull_fill(u4_plow p,
             u4_book dab,
             u4_menu sem)
  {
    u4_lane lan = p->lan;

    return u4_tab_add_log(lan, sem, dab);
  }

  /* _ord_tag_simple():
  **
  **    Return 1 iff (tag_l tag_r) are in correct simple order.
  **
  **    Trip if (tag_l tag_r) are equal.
  */
  static u4_t
  _ord_tag_simple(u4_tag tag_l, u4_tag tag_r)
  {
    u4_bit bit;

    if ( u4_bull == (bit = u4_op_ord(tag_l, tag_r)) ) {
      return u4_trip;
    }
    return u4_n_true(bit);
  }

  /* _ord_tag_tree():
  **
  **    Return 1 iff (hog_l hog_r) are in correct tree order (nub).
  **
  **    Stop iff (hog_l hog_r) are equal.
  */
  static u4_t
  _ord_tag_tree(u4_tag tag_l, u4_tag tag_r)
  {
    u4_nub nub_l = u4_n_nub(tag_l);
    u4_nub nub_r = u4_n_nub(tag_r);

    if ( nub_l == nub_r ) {
      return _ord_tag_simple(tag_l, tag_r);
    }
    else return (nub_l < nub_r);
  }

  /* look:gull:plow
  */
    static u4_unit
    _gull_look_a(u4_plow p,
                 u4_spec dab,
                 u4_term cog,
                 u4_axis axe)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(dab) ) {
        return u4_nul;
      }
      else {
        u4_noun n_dab, l_dab, r_dab, pn_dab, qn_dab;

        u4_c_trel(dab, &n_dab, &l_dab, &r_dab);
        pn_dab = u4_ch(n_dab);
        qn_dab = u4_ct(n_dab);

        if ( u4_n_zero(l_dab) && u4_n_zero(r_dab) ) {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(lan, u4_nul, axe, qn_dab);
          }
          else return u4_nul;
        }
        else if ( u4_n_zero(l_dab) ) {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(lan, u4_nul, u4_op_peg(lan, axe, u4_noun_2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return u4_nul;
          }
          else {
            return _gull_look_a(p, r_dab, cog, u4_op_peg(lan, axe, u4_noun_3));
          }
        }
        else if ( u4_n_zero(r_dab) ) {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(lan, u4_nul, u4_op_peg(lan, axe, u4_noun_2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return _gull_look_a(p, l_dab, cog, u4_op_peg(lan, axe, u4_noun_3));
          }
          else {
            return u4_nul;
          }
        }
        else {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(lan, u4_nul, u4_op_peg(lan, axe, u4_noun_2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return _gull_look_a(p, l_dab, cog, u4_op_peg(lan, axe, u4_noun_6));
          }
          else {
            return _gull_look_a(p, r_dab, cog, u4_op_peg(lan, axe, u4_noun_7));
          }
        }
      }
    }
  u4_unit
  _gull_look(u4_plow p,
             u4_spec dab,
             u4_term cog)
  {
    return _gull_look_a(p, dab, cog, u4_axis_1);
  }


/****   _iris: type system core.
****/
  /* burn:iris:rose:plow
  */
    static u4_type
    _iris_burn_sint(u4_plow, u4_type, u4_rail, u4_axis, u4_tack);

    static u4_type
    _iris_burn_dext(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_tack tac)
    {
      u4_lane lan = p->lan;
      u4_noun p_tac, q_tac;
      u4_noun p_sut, q_sut, qrs_sut;

      if ( u4_n_zero(tac) ) {
        return sut;
      }
      else if ( u4_b_p(tac, u4_atom_leaf, &p_tac) ) {
        return _iris_snap(p, sut, bar, axe, p_tac);
      }
      else if ( u4_b_pq(tac, u4_atom_bran, &p_tac, &q_tac) ) {
        if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
          if ( u4_n_eq(p_sut, p_tac) ) {
            return u4_kt
              (lan, 
               u4_atom_face, 
               p_tac, 
               _iris_burn_dext(p, q_sut, bar, axe, q_tac));
          }
          else {
            return u4_kt
              (lan,
               u4_atom_face,
               p_tac,
               _iris_burn_dext(p, sut, bar, axe, q_tac));
          }
        }
        else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) )
        {
          return _iris_burn_sint(p, sut, bar, axe, tac);
        }
        else {
          return u4_kt
            (lan,
             u4_atom_face,
             p_tac,
             _iris_burn_dext(p, sut, bar, axe, q_tac));
        }
      }
      else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
        if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
          u4_noun l_sut, l_bar, l_axe;
          u4_noun r_sut, r_bar, r_axe;

          l_sut = sut; l_bar = bar; l_axe = axe;
          _iris_slip(p, &l_sut, &l_bar, &l_axe, u4_axis_2);

          r_sut = sut; r_bar = bar; r_axe = axe;
          _iris_slip(p, &r_sut, &r_bar, &r_axe, u4_axis_3);

          return u4_kt
            (lan,
             u4_atom_cell,
             _iris_burn_dext(p, l_sut, l_bar, l_axe, p_tac),
             _iris_burn_dext(p, r_sut, r_bar, r_axe, q_tac));
        }
        else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &qrs_sut) ) {
          u4_noun l_sut, l_bar, l_axe;
          u4_type ham;

          l_sut = sut; l_bar = bar; l_axe = axe;
          _iris_slip(p, &l_sut, &l_bar, &l_axe, u4_axis_2);

          ham = _iris_burn_dext(p, l_sut, l_bar, l_axe, p_tac);

          if ( u4_n_zero(q_tac) ) {
            return u4_k_trel
              (lan, u4_atom_core, ham, qrs_sut);
          } else {
            return u4_k_trel
              (lan, u4_atom_cell, ham, u4_atom_blur);
          }
        }
        else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) )
        {
          return _iris_burn_sint(p, sut, bar, axe, tac);
        }
        else {
          u4_noun poq = u4_kt
            (lan,
             u4_atom_cell,
             _iris_half(p, sut, bar, axe, u4_axis_2),
             _iris_half(p, sut, bar, axe, u4_axis_3));

          return _iris_burn_dext(p, poq, bar, axe, tac);
        }
      }
      else return u4_trip;
    }
    static u4_unit
    _iris_burn_swim(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_tack tac)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit yop = _iris_burn_swim(p, p_sut, bar, axe, tac);
        u4_unit paf = _iris_burn_swim(p, q_sut, bar, axe, tac);

        if ( u4_n_zero(yop) ) {
          return paf;
        } else if ( u4_n_zero(paf) ) {
          return yop;
        }
        else {
          return u4_kc
            (lan,
             u4_nul,
             _rose_eith(p, u4_ct(yop), u4_ct(paf)));
        }
      }
      else {
        if ( u4_so(_iris_cull(p, sut, bar, axe)) ) {
          return u4_nul;
        }
        else {
          return u4_kc
            (lan, u4_nul, _iris_burn_dext(p, sut, bar, axe, tac));
        }
      }
    }
    static u4_type
    _iris_burn_sint(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_tack tac)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return u4_kt
          (lan, 
           u4_atom_face,
           p_sut,
           _iris_burn_dext(p, q_sut, bar, axe, tac));
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_ct(_iris_burn_swim(p, sut, bar, axe, tac));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _rose_both
          (p, 
           _iris_burn_dext(p, q_sut, u4_kc(lan, p_sut, bar), axe, tac),
           _iris_burn_dext(p, p_sut, bar, axe, tac));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        return _iris_burn_dext
          (p, _rose_repo(p, p_sut, q_sut), bar, axe, tac); 
      }
      else return u4_trip;
    }
  u4_type
  _iris_burn(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_tack tac)
  {
    return _iris_burn_dext(p, sut, bar, axe, tac);
  }

  /* cull:iris:rose:plow
  */
    static u4_flag
    _iris_cull_a(u4_plow p,
                 u4_type sut,
                 u4_rail bar,
                 u4_axis axe)
    {
      if ( u4_n_zero(bar) ) {
        return u4_no;
      }
      else if ( u4_so(_rose_orth(p, sut, u4_ch(bar))) ) {
        return u4_yes;
      }
      else return _iris_cull_a(p, sut, u4_ct(bar), axe);
    }
  u4_flag
  _iris_cull(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe)
  {
    if ( u4_so(_rose_null(p, sut)) ) {
      return u4_yes;
    }
    else {
      return _iris_cull_a(p, sut, bar, axe);
    }
  }

  /* find:iris:rose:plow
  */
    static u4_unit _iris_find_main
      (u4_plow, u4_type, u4_rail, u4_axis, u4_pool, u4_term);

    static u4_unit
    _iris_find_half(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_term cog,
                    u4_axis cap)
    {
      _iris_slip(p, &sut, &bar, &axe, cap);

      return _iris_find_main(p, sut, bar, axe, gil, cog);
    }
    static u4_unit
    _iris_find_swim(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_term cog)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit yop = _iris_find_swim(p, p_sut, bar, axe, gil, cog);
        u4_unit paf = _iris_find_swim(p, q_sut, bar, axe, gil, cog);

        if ( u4_n_zero(yop) ) {
          return paf;
        }
        else if ( u4_n_zero(paf) ) {
          return yop;
        }
        else {
          u4_unit lep = u4_ct(yop);
          u4_unit gam = u4_ct(paf);
          
          if ( u4_n_zero(lep) ) {
            if ( u4_n_zero(gam) ) {
              return u4_nul;
            }
            else {
              u4_burp(lan, "cog", u4_prep_textual(lan, cog));
              return _plow_fail(p, "fork conflict a");
            }
          }
          else if ( u4_n_zero(gam) ) {
            return _plow_fail(p, "fork conflict b");
          }
          else {
            u4_plan u_lep = u4_ct(lep);
            u4_plan u_gam = u4_ct(gam);

            if ( u4_n_eq(u4_ch(u_lep), u4_ch(u_gam)) &&
                 u4_n_eq(u4_ch(u4_ct(u_lep)), u4_ch(u4_ct(u_gam))) )
            {
              return u4_kt
                (lan,
                 u4_nul,
                 u4_nul,
                 u4_kt
                  (lan, 
                   u4_ch(u_lep),
                   u4_ch(u4_ct(u_lep)),
                   _rose_eith(p, u4_ct(u4_ct(u_lep)), u4_ct(u4_ct(u_gam)))));
            }
            else {
              u4_burp(lan, "cog", u4_prep_textual(lan, cog));
              return _plow_fail(p, "fork conflict c");
            }
          }
        }
      }
      else {
        if ( u4_so(_iris_cull(p, sut, bar, axe)) ) {
          return u4_nul;
        }
        else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) &&
                  u4_bag_in(u4_kc(lan, bar, sut), gil) )
        {
          return u4_nul;
        }
        else {
          return u4_kc
            (lan, u4_nul, _iris_find_main(p, sut, bar, axe, gil, cog));
        }
      }
    }
    static u4_unit
    _iris_find_main_a(u4_plow p,
                      u4_type sut,
                      u4_rail bar,
                      u4_axis axe,
                      u4_pool gil,
                      u4_term cog)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut, r_sut, s_sut;

      if ( u4_n_eq(u4_atom_atom, sut) ||
           u4_n_eq(u4_atom_blur, sut) ||
           u4_n_eq(u4_atom_blot, sut) ||
           u4_b_p(sut, u4_atom_cube, &p_sut) )
      {
        return u4_nul;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        u4_unit taf = _iris_find_half(p, sut, bar, axe, gil, cog, u4_axis_2);
        u4_unit bov = _iris_find_half(p, sut, bar, axe, gil, cog, u4_axis_3);

        if ( u4_n_zero(taf) ) {
          return bov;
        }
        else if ( u4_n_zero(bov) ) {
          return taf;
        }
        else {
#if 0
          u4_burp(lan, "cog", u4_prep_textual(lan, cog));
          return _plow_fail(p, "cell conflict");
#else
          return taf;
#endif
        }
      }
      else if ( u4_b_pqrs(sut, u4_atom_core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
        u4_spec dab = s_sut;
        u4_unit zem;

        zem = _gull_look(p, dab, cog);
        if ( u4_n_zero(zem) ) {
          return _iris_find_half(p, sut, bar, axe, gil, cog, u4_axis_2);
        }
        else return 
          u4_kc
            (lan, 
             u4_nul, 
             u4_kt
              (lan, 
               axe, 
               u4_kq
                (lan, 
                 u4_nul, 
                 u4_op_peg(lan, u4_axis_3, u4_ch(u4_ct(zem))),
                 sut,
                 u4_ct(u4_ct(zem))),
               sut));
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        if ( u4_n_eq(cog, p_sut) ) {
          return u4_kq
            (lan, u4_nul, axe, u4_nul, q_sut);
        }
        else return u4_nul;
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit foz = _iris_find_swim(p, sut, bar, axe, gil, cog);

        if ( u4_n_zero(foz) ) {
          return u4_nul; 
        }
        return u4_ct(foz);
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        u4_unit hax = _iris_find_main
          (p, p_sut, bar, axe, gil, cog);
        u4_unit yor = _iris_find_main
          (p, q_sut, u4_kc(lan, p_sut, bar), axe, gil, cog);

        if ( u4_n_zero(yor) ) {
          if ( u4_n_zero(hax) ) {
            return u4_nul;
          }
          else {
            u4_noun u_hax = u4_ct(hax);
            u4_noun pu_hax = u4_ch(u_hax);
            u4_noun qu_hax = u4_ch(u4_ct(u_hax));
            u4_noun ru_hax = u4_ct(u4_ct(u_hax));

            return u4_kc
              (lan, 
               u4_nul,
               u4_kt
                (lan,
                 pu_hax,
                 qu_hax,
                 _rose_both
                  (p,
                   _iris_peek
                    (p, q_sut, u4_kc(lan, p_sut, bar), axe, pu_hax),
                   ru_hax)));
          }
        }
        else {
          u4_noun u_yor = u4_ct(yor);
          u4_noun pu_yor = u4_ch(u_yor);
          u4_noun qu_yor = u4_ch(u4_ct(u_yor));
          u4_noun ru_yor = u4_ct(u4_ct(u_yor));

          if ( u4_n_zero(hax) ) {
            return u4_kc
              (lan, 
               u4_nul,
               u4_kt
                (lan,
                 pu_yor,
                 qu_yor,
                 _rose_both
                  (p,
                   ru_yor,
                   _iris_peek(p, p_sut, bar, axe, pu_yor))));
          }
          else {
            u4_noun u_hax = u4_ct(hax);
            u4_noun pu_hax = u4_ch(u_hax);
            u4_noun qu_hax = u4_ch(u4_ct(u_hax));
            u4_noun ru_hax = u4_ct(u4_ct(u_hax));

            if ( !(u4_n_eq(pu_hax, pu_yor) && u4_n_eq(qu_hax, qu_yor)) ) {
              ru_hax = _iris_peek(p, p_sut, bar, axe, pu_yor);
            }
            return u4_kc
              (lan, 
               u4_nul,
               u4_kt
                (lan,
                 pu_yor,
                 qu_yor,
                 _rose_both(p, ru_yor, ru_hax)));
          }
        }
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun dit = u4_kc(lan, bar, sut);

        if ( u4_bag_in(dit, gil) ) {
          return u4_nul;
        } 
        else {
          return _iris_find_main
            (p,
             _rose_repo(p, p_sut, q_sut), 
             bar,
             axe,
             u4_bag_add(lan, dit, gil), 
             cog);
        }
      }
      else {
        return u4_trip;
      }
    }
    static u4_unit
    _iris_find_main(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_term cog)
    {
      u4_lane lan = p->lan;
      u4_noun mum  = u4_k_quil(lan, sut, bar, axe, gil, cog);
      u4_nopt zod  = u4_tab_get(mum, p->fin);

      if ( zod != u4_bull ) {
        return zod;
      }
      else {
        u4_unit gur = _iris_find_main_a
          (p, sut, bar, axe, gil, cog);

        p->fin = u4_tab_add(lan, mum, gur, p->fin);
        return gur;
      }
    }
  u4_plan
  _iris_find(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_term cog)
  {
    u4_unit fyg = _iris_find_main(p, sut, bar, axe, u4_nul, cog);

    if ( u4_n_zero(fyg) ) {
      u4_burp(p->lan, "name", u4_prep_textual(p->lan, cog));
      u4_burp(p->lan, "sut", _dump_type(p, sut));
      return _plow_fail(p, "not found");
    }
    return u4_ct(fyg);
  }

  /* fish:iris:rose:plow
  */
    static u4_tool
    _iris_fish_main(u4_plow, u4_type, u4_rail, u4_axis, u4_pool);

    static u4_tool
    _iris_fish_slip(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool vit,
                    u4_axis had)
    {
      _iris_slip(p, &sut, &bar, &axe, had);
      return _iris_fish_main(p, sut, bar, axe, vit);
    }
    static u4_unit
    _iris_fish_swim(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool vit)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit doz = _iris_fish_swim(p, p_sut, bar, axe, vit);
        u4_unit ryg = _iris_fish_swim(p, q_sut, bar, axe, vit);
      
        if ( u4_n_zero(doz) ) return ryg;
        else if ( u4_n_zero(ryg) ) return doz;
        else return u4_kc
          (lan, u4_nul, 
                _lily_flor(p, u4_ct(doz), u4_ct(ryg)));
      }
      else {
        if ( u4_so(_iris_cull(p, sut, bar, axe)) ) {
          return u4_nul;
        }
        else {
          return u4_kc
            (lan, u4_nul, _iris_fish_main(p, sut, bar, axe, vit));
        }
      }
    }
    static u4_tool
    _iris_fish_main(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool vit)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_n_eq(u4_atom_atom, sut) ) {
        return _lily_flop
          (p, u4_kt(lan, u4_nock_dust, u4_nock_frag, axe));
      }
      else if ( u4_n_eq(u4_atom_blur, sut) ) {
        return u4_kc(lan, u4_nock_bone, u4_yes);
      }
      else if ( u4_n_eq(u4_atom_blot, sut) ) {
        return u4_kc(lan, u4_nock_bone, u4_no);
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        return u4_kc(lan, u4_nock_frag, u4_noun_0);
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        return u4_kt
          (lan, u4_nock_sing, 
                u4_kc(lan, u4_nock_bone, p_sut),
                u4_kc(lan, u4_nock_frag, axe));
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        return _lily_flan
          (p,
           u4_kt(lan, u4_nock_dust, u4_nock_frag, axe),
           _lily_flan
            (p, _iris_fish_slip(p, sut, bar, axe, vit, u4_axis_2),
                _iris_fish_slip(p, sut, bar, axe, vit, u4_axis_3)));
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _iris_fish_main(p, q_sut, bar, axe, vit);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_ct(_iris_fish_swim(p, sut, bar, axe, vit));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _lily_flan
          (p, 
           _iris_fish_main(p, p_sut, bar, axe, vit),
           _iris_fish_main(p, q_sut, u4_kc(lan, p_sut, bar), axe, vit));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun duq = u4_kc(lan, sut, bar);

        if ( u4_bag_in(duq, vit) ) {
          return _plow_fail(p, "fish recursion");
        } 
        else {
          return _iris_fish_main
            (p, _rose_repo(p, p_sut, q_sut),
                bar,
                axe,
                u4_bag_add(lan, duq, vit));
        }
      }
      else {
        return u4_trip;
      }
    }
  u4_tool
  _iris_fish(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe)
  {
    return _iris_fish_main(p, sut, bar, axe, u4_nul);
  }

  /* half:iris:rose:plow
  */
    static u4_unit
    _iris_half_swim(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_axis had)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit doz = _iris_half_swim(p, p_sut, bar, axe, had);
        u4_unit ryg = _iris_half_swim(p, q_sut, bar, axe, had);

        if ( u4_n_zero(doz) ) return ryg;
        else if ( u4_n_zero(ryg) ) return doz;
        else return u4_kc
          (lan, u4_nul, _rose_eith(p, u4_ct(doz), u4_ct(ryg)));
      }
      else {
        if ( u4_so(_iris_cull(p, sut, bar, axe)) ) {
          return u4_nul;
        }
        else {
          return u4_kc
            (lan, u4_nul, _iris_half(p, sut, bar, axe, had));
        }
      }
    }
    u4_type
    _iris_half_main(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_axis had)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_n_eq(u4_atom_atom, sut) ) {
        return u4_atom_blot;
      }
      else if ( u4_n_eq(u4_atom_blot, sut) ) {
        return u4_atom_blot;
      }
      else if ( u4_n_eq(u4_atom_blur, sut) ) {
        return u4_atom_blur;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        if ( u4_n_eq(u4_axis_2, had) ) {
          return p_sut;
        } else return q_sut;
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        if ( u4_n_eq(u4_axis_2, had) ) {
          return p_sut;
        } else return u4_atom_blur;
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) )  {
        if ( u4_n_atom(p_sut) ) {
          return u4_atom_blot;
        }
        else if ( u4_n_eq(u4_axis_2, had) ) {
          return u4_kc(lan, u4_atom_cube, u4_ch(p_sut));
        } else return u4_kc(lan, u4_atom_cube, u4_ct(p_sut));
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _iris_half(p, q_sut, bar, axe, had);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit pez = _iris_half_swim(p, sut, bar, axe, had);

        if ( u4_n_zero(pez) ) {
          return u4_atom_blot;
        }
        return u4_ct(pez);
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _rose_both
          (p, 
           _iris_half(p, q_sut, u4_kc(lan, p_sut, bar), axe, had),
           _iris_half(p, p_sut, bar, axe, had));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        return _iris_half(p, _rose_repo(p, p_sut, q_sut), bar, axe, had);
      }
      else return u4_trip;
    }

  u4_type
  _iris_half(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_axis had)
  {
    u4_lane lan = p->lan;
    u4_noun mum = u4_kt(lan, sut, bar, had);  /* axe is not used */
    u4_nopt zod = u4_tab_get(mum, p->huf);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_type gur = _iris_half_main(p, sut, bar, axe, had);

      p->huf = u4_tab_add(lan, mum, gur, p->huf);
      return gur;
    }
  }

  /* nest:iris:rose:plow
  */
    static u4_flag
    _iris_nest_sint
      (u4_plow, u4_type, u4_rail, u4_axis, u4_pool, u4_type, u4_rail, u4_axis); 
    static u4_flag
    _iris_nest_dext
      (u4_plow, u4_type, u4_rail, u4_axis, u4_pool, u4_type, u4_rail, u4_axis); 

    static u4_flag
    _iris_nest_dext_slip(u4_plow p,
                         u4_type sut,
                         u4_rail bar,
                         u4_axis axe,
                         u4_pool gil,
                         u4_type bon,
                         u4_rail nef,
                         u4_axis ful,
                         u4_axis had)
    {
      _iris_slip(p, &sut, &bar, &axe, had);
      _iris_slip(p, &bon, &nef, &ful, had);

      return _iris_nest_dext(p, sut, bar, axe, gil, bon, nef, ful);
    }
    static u4_flag
    _iris_nest_dext_swim(u4_plow p,
                         u4_type sut,
                         u4_rail bar,
                         u4_axis axe,
                         u4_pool gil,
                         u4_type bon,
                         u4_rail nef,
                         u4_axis ful)
    {
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_or
          (_iris_nest_dext_swim(p, p_sut, bar, axe, gil, bon, nef, ful),
           _iris_nest_dext_swim(p, q_sut, bar, axe, gil, bon, nef, ful));
      }
      else {
        if ( u4_so(_iris_cull(p, sut, bar, axe)) ) {
          return u4_no;
        }
        else return _iris_nest_dext
          (p, sut, bar, axe, gil, bon, nef, ful);
      }
    }

    static u4_flag
    _iris_nest_dext_main(u4_plow p,
                         u4_type sut,
                         u4_rail bar,
                         u4_axis axe,
                         u4_pool gil,
                         u4_type bon,
                         u4_rail nef,
                         u4_axis ful)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut, qrs_sut;
      u4_noun p_bon, q_bon, qrs_bon;

      if ( u4_n_eq(sut, u4_atom_atom) ) {
        if ( u4_n_eq(bon, u4_atom_atom) ) {
          return u4_yes;
        }
        else if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
          return u4_say(u4_n_atom(p_bon));
        }
        else return _iris_nest_sint(p, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_n_eq(sut, u4_atom_blur) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &qrs_sut) ) {
        if ( u4_b_pq(bon, u4_atom_core, &p_bon, &qrs_bon) ) {
          return u4_and
            (u4_say(u4_n_eq(qrs_sut, qrs_bon)),
             _iris_nest_dext_slip
                (p, sut, bar, axe, gil, bon, nef, ful, u4_axis_2));
        }
        else return _iris_nest_sint(p, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
          return u4_and
            (_iris_nest_dext_slip
                (p, sut, bar, axe, gil, bon, nef, ful, u4_axis_2),
             _iris_nest_dext_slip
                (p, sut, bar, axe, gil, bon, nef, ful, u4_axis_3));
        }
        else {
          return _iris_nest_sint(p, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
          return u4_n_eq(p_sut, p_bon) ? u4_yes : u4_no;
        }
        else return _iris_nest_sint(p, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _iris_nest_dext(p, q_sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        if ( u4_n_atom(bon) ||
             u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ||
             u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ||
             u4_b_p(bon, u4_atom_cube, &p_bon) ) 
        {
          return _iris_nest_dext_swim
            (p, sut, bar, axe, gil, bon, nef, ful);
        }
        else {
          return _iris_nest_sint(p, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        u4_rail buz = u4_kc(lan, p_sut, bar);

        return u4_and
          (_iris_nest_dext(p, p_sut, bar, axe, gil, bon, nef, ful),
           _iris_nest_dext(p, q_sut, buz, axe, gil, bon, nef, ful));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun duq = u4_kq(lan, sut, bar, bon, nef);

        if ( u4_bag_in(duq, gil) ) {
          return u4_yes;
        } else {
          return _iris_nest_dext
            (p, _rose_repo(p, p_sut, q_sut),
                bar,
                axe,
                u4_bag_add(lan, duq, gil),
                bon, 
                nef, 
                ful);
        }
      }
      else {
        return u4_trip;
      }
    }
    static u4_flag
    _iris_nest_dext(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_type bon,
                    u4_rail nef,
                    u4_axis ful)
    {
      u4_lane lan = p->lan;
    
      if ( u4_n_eq(sut, bon) ) {
        return u4_yes;
      }
      else {
        u4_noun mum = u4_kq(lan, bar, sut, nef, bon);
        u4_nopt zod = u4_tab_get(mum, p->vus);

        if ( zod != u4_bull ) {
          return zod;
        }
        else {
          u4_flag gur = _iris_nest_dext_main
            (p, sut, bar, axe, gil, bon, nef, ful);

          p->vus = u4_tab_add(lan, mum, gur, p->vus);
          return gur;
        }
      }
    }
    static u4_flag
    _iris_nest_sint_swim(u4_plow p,
                         u4_type sut,
                         u4_rail bar,
                         u4_axis axe,
                         u4_pool gil,
                         u4_type bon,
                         u4_rail nef,
                         u4_axis ful)
    {
      u4_noun p_bon, q_bon;

      if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
        return u4_and
          (_iris_nest_sint_swim(p, sut, bar, axe, gil, p_bon, nef, ful),
           _iris_nest_sint_swim(p, sut, bar, axe, gil, q_bon, nef, ful));
      }
      else {
        if ( u4_so(_iris_cull(p, bon, nef, ful)) ) {
          return u4_yes;
        }
        else return _iris_nest_dext
          (p, sut, bar, axe, gil, bon, nef, ful);
      }
    }
    static u4_flag
    _iris_nest_sint(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_type bon,
                    u4_rail nef,
                    u4_axis ful)
    {
      u4_lane lan = p->lan;
      u4_noun p_bon, q_bon;

      if ( u4_n_eq(bon, u4_atom_atom) || u4_n_eq(bon, u4_atom_blur) ) {
        return u4_no;
      }
      else if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
        return u4_no;
      }
      else if ( u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ) {
        bon = u4_kt(lan, u4_atom_cell, p_bon, u4_atom_blur);

        return _iris_nest_dext(p, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
        if ( u4_n_atom(p_bon) ) {
          return u4_no;
        }
        else {
          bon = u4_kt
            (lan, u4_atom_cell,
                  u4_kc(lan, u4_atom_cube, u4_ch(p_bon)),
                  u4_kc(lan, u4_atom_cube, u4_ct(p_bon)));

          return _iris_nest_dext(p, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u4_b_pq(bon, u4_atom_face, &p_bon, &q_bon) ) {
        return _iris_nest_dext(p, sut, bar, axe, gil, q_bon, nef, ful);
      }
      else if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
        return _iris_nest_sint_swim(p, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(bon, u4_atom_fuse, &p_bon, &q_bon) ) {
        u4_rail gok = u4_kc(lan, p_bon, nef);

        return u4_or
          (_iris_nest_dext(p, sut, bar, axe, gil, p_bon, nef, ful),
           _iris_nest_dext(p, sut, bar, axe, gil, q_bon, gok, ful));
      }
      else if ( u4_b_pq(bon, u4_atom_hold, &p_bon, &q_bon) ) {
        u4_noun duq = u4_kq(lan, sut, bar, bon, nef);

        if ( u4_bag_in(duq, gil) ) {
          return u4_yes;
        } else {
          return _iris_nest_dext
            (p, sut,
                bar,
                axe,
                u4_bag_add(lan, duq, gil),
                _rose_repo(p, p_bon, q_bon),
                nef, 
                ful);
        }
      }
      else return u4_trip;
    }
  u4_flag
  _iris_nest(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_type bon)
  {
    if ( u4_so(_rose_null(p, bon)) ) {
      return u4_yes;
    }
    else if ( u4_so(_rose_null(p, sut)) ) {
      return u4_no;
    }
    else {
      u4_pool gil = u4_nul;
      u4_rail nef = u4_nul;
      u4_axis ful = u4_axis_1;

      return _iris_nest_dext(p, sut, bar, axe, gil, bon, nef, ful);
    }
  }

  /* peek:iris:rose:plow
  */
  u4_type
  _iris_peek(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_axis bow)
  {
    u4_lane lan = p->lan;

    if ( u4_n_eq(u4_axis_1, bow) ) {
      return sut;
    } 
    else {
      _iris_slip(p, &sut, &bar, &axe, u4_op_tip(bow));

      return _iris_peek(p, sut, bar, axe, u4_op_tap(lan, bow));
    }
  }

  /* slip:iris:rose:plow
  */
    static u4_rail
    _iris_slip_a(u4_plow p,
                 u4_rail bar,
                 u4_axis had)
    {
      if ( u4_n_zero(bar) ) {
        return u4_nul;
      }
      else {
        return u4_kc
          (p->lan, _iris_half(p, u4_ch(bar), u4_nul, u4_axis_1, had),
                   _iris_slip_a(p, u4_ct(bar), had));
      } 
    }
  void
  _iris_slip(u4_plow p,
             u4_type *sut,
             u4_rail *bar,
             u4_axis *axe,
             u4_axis had)
  {
    *sut = _iris_half(p, *sut, *bar, *axe, had);
    *bar = _iris_slip_a(p, *bar,  had);
    *axe = u4_op_peg(p->lan, *axe, had);
  }

  /* snap:iris:rose:plow
  */
    static u4_type
    _iris_snap_dext(u4_plow, u4_type, u4_rail, u4_axis, u4_type);
    static u4_type
    _iris_snap_sint(u4_plow, u4_type, u4_rail, u4_axis, u4_type);

    static u4_type
    _iris_snap_slip(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon,
                    u4_axis had)
    {
      _iris_slip(p, &sut, &bar, &axe, had);
      return _iris_snap(p, sut, bar, axe, bon);
    }
    static u4_flag
    _iris_snap_cull(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon)
    {
      return u4_or
        (_iris_cull(p, sut, bar, axe),
         _rose_orth(p, sut, bon));
    }
    static u4_type
    _iris_snap_dext(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;
      u4_noun p_bon, q_bon;

      if ( u4_n_eq(sut, u4_atom_atom) ||
           u4_n_eq(sut, u4_atom_blot) ||
           u4_n_eq(sut, u4_atom_blur) ||
           u4_b_p(sut, u4_atom_cube, &p_sut) ||
           u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) )
      {
        return bon;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
          return u4_kt
            (lan,
             u4_atom_cell,
             _iris_snap_slip(p, sut, bar, axe, p_bon, u4_axis_2),
             _iris_snap_slip(p, sut, bar, axe, q_bon, u4_noun_3));
        }
        else {
          return _iris_snap_sint(p, sut, bar, axe, bon);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        if ( u4_b_pq(bon, u4_atom_face, &p_bon, &q_bon) ) {
          return u4_kt
            (lan, u4_atom_face,
                  p_sut,
                  _iris_snap_dext(p, q_sut, bar, axe, q_bon));
        }
        else {
          return u4_kt
            (lan, u4_atom_face,
                  p_sut,
                  _iris_snap_dext(p, q_sut, bar, axe, bon));
        }
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        if ( u4_so(_iris_snap_cull(p, p_sut, bar, axe, bon)) ) {
          if ( u4_so(_iris_snap_cull(p, q_sut, bar, axe, bon)) ) {
            return bon;
          }
          else return _iris_snap_dext(p, q_sut, bar, axe, bon);
        }
        else {
          if ( u4_so(_iris_snap_cull(p, q_sut, bar, axe, bon)) ) {
            return _iris_snap_dext(p, p_sut, bar, axe, bon);
          }
          else return bon;
        }
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _iris_snap_dext
          (p, q_sut, u4_kc(lan, p_sut, bar), axe, bon);
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        return _iris_snap_dext
          (p, _rose_repo(p, p_sut, q_sut), bar, axe, bon);
      }
      else return u4_trip;
    }
    static u4_type
    _iris_snap_sint(u4_plow p,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon)
    {
      u4_noun p_bon, q_bon;

      if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
        return _rose_eith
          (p, 
           _iris_snap_dext(p, sut, bar, axe, p_bon), 
           _iris_snap_dext(p, sut, bar, axe, q_bon));
      }
      else if ( u4_b_pq(bon, u4_atom_fuse, &p_bon, &q_bon) ) {
        return _rose_both
          (p,
           _iris_snap_dext(p, sut, bar, axe, q_bon),
           _iris_snap_dext(p, sut, bar, axe, p_bon));
      }
      else return bon;
    }
  u4_type
  _iris_snap(u4_plow p,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_type bon)
  {
    u4_type sap;

    sap = _iris_snap_dext(p, sut, bar, axe, bon);

    return sap;
  }


/****   _lark: mutation.
****/
  /* nuke:lark:rose:plow
  */
    static u4_tack
    _lark_nuke_port(u4_plow p,
                    u4_type sut,
                    u4_tack tac,
                    u4_rope rop,
                    u4_type feg,
                    u4_term gos,
                    u4_axis wam,
                    u4_unit yus,
                    u4_type gur)
    {
      u4_lane lan = p->lan;

      if ( u4_n_eq(u4_axis_1, wam) ) {
        if ( u4_n_zero(yus) ) {
          return u4_k_trel
            (lan, u4_atom_bran,
                  gos,
                  _lark_nuke(p, gur, tac, rop, feg));
        } else {
          return _lark_nuke(p, gur, tac, rop, feg);
        }
      }
      else {
        u4_axis tip = u4_op_tip(wam);
        u4_axis tap = u4_op_tap(lan, wam);

        if ( u4_n_eq(u4_axis_2, tip) ) {
          return u4_k_trel
            (lan, 
             u4_atom_pair,
             _lark_nuke_port(p, sut, tac, rop, feg, gos, tap, yus, gur),
             u4_nul);
        }
        else {
          return u4_k_trel
            (lan, 
             u4_atom_pair,
             u4_nul,
             _lark_nuke_port(p, sut, tac, rop, feg, gos, tap, yus, gur));
        }
      }
    }

    static u4_tack
    _lark_nuke_frag(u4_plow p,
                    u4_type sut,
                    u4_tack tac,
                    u4_rope rop,
                    u4_type feg,
                    u4_axis wam,
                    u4_type gur)
    {
      u4_lane lan = p->lan;

      if ( u4_n_eq(u4_axis_1, wam) ) {
        return _lark_nuke(p, gur, tac, rop, feg);
      }
      else {
        u4_axis tip = u4_op_tip(wam);
        u4_axis tap = u4_op_tap(lan, wam);

        if ( u4_n_eq(u4_axis_2, tip) ) {
          return u4_k_trel
            (lan, 
             u4_atom_pair,
             _lark_nuke_frag(p, sut, tac, rop, feg, tap, gur),
             u4_nul);
        }
        else {
          return u4_k_trel
            (lan, 
             u4_atom_pair,
             u4_nul,
             _lark_nuke_frag(p, sut, tac, rop, feg, tap, gur));
        }
      }
    }
  u4_tack
  _lark_nuke(u4_plow p,
             u4_type sut,
             u4_tack tac,
             u4_rope rop,
             u4_type feg)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(rop) ) {
      return u4_k_cell(lan, u4_atom_leaf, feg);
    }
    else {
      u4_cord i_rop = u4_ch(rop);
      u4_rope t_rop = u4_ct(rop);
      u4_noun pi_rop;

      if ( u4_n_atom(i_rop) ) {
        return _lark_nuke
          (p, sut, 
              tac, 
              u4_k_cell(lan, u4_k_cell(lan, u4_atom_pane, rop), t_rop),
              feg);
      }
      else if ( u4_b_p(i_rop, u4_atom_pane, &pi_rop) ) {
        u4_plan lar = _iris_find(p, sut, u4_nul, u4_axis_1, pi_rop);
        u4_axis p_lar = u4_ch(lar);
        u4_unit q_lar = u4_ch(u4_ct(lar));
        u4_type r_lar = u4_ct(u4_ct(lar));

        return _lark_nuke_port
          (p, sut, tac, t_rop, feg, pi_rop, p_lar, q_lar, r_lar);
      }
      else if ( u4_b_p(i_rop, u4_atom_frag, &pi_rop) ) {
        u4_type gur = _iris_peek(p, sut, u4_nul, u4_axis_1, pi_rop);

        return _lark_nuke_frag(p, sut, tac, t_rop, feg, pi_rop, gur); 
      }
      else return u4_trip;
    }
  }

  /* cram:lark:rose:plow
  */
  u4_tack
  _lark_cram(u4_plow p,
             u4_type sut,
             u4_tack tac,
             u4_tack les)
  {
    u4_lane lan = p->lan;
    u4_noun p_tac, q_tac, p_les, q_les;

    if ( u4_n_zero(tac) ) {
      return les;
    }
    else if ( u4_n_zero(les) ) {
      return tac;
    }
    else if ( u4_b_pq(tac, u4_atom_bran, &p_tac, &q_tac) ) {
      if ( !u4_b_pq(les, u4_atom_bran, &p_les, &q_les) ||
           !u4_n_eq(p_tac, p_les) )
      {
        return _plow_fail(p, "cram crash");
      }
      else return u4_k_trel
        (lan, u4_atom_bran,
              p_tac,
              _lark_cram(p, sut, q_tac, q_les));
    }
    else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
      if ( !u4_b_pq(les, u4_atom_pair, &p_les, &q_les) ) {
        return _plow_fail(p, "cram crash");
      }
      else return u4_k_trel
        (lan, u4_atom_pair,
              _lark_cram(p, sut, p_tac, p_les),
              _lark_cram(p, sut, q_tac, q_les));
    }
    else return _plow_fail(p, "cram crash");
  }

  /* feed:lark:rose:plow
  */
  u4_tack
  _lark_feed(u4_plow p,
             u4_type sut,
             u4_tack tac,
             u4_list mut)
  {
    if ( u4_n_zero(mut) ) {
      return tac;
    }
    else {
      u4_noun i_mut  = u4_ch(mut);
      u4_list t_mut  = u4_ct(mut);
      u4_gene pi_mut = u4_ch(i_mut);
      u4_type qi_mut = u4_ct(i_mut);
      u4_rope rop    = _plow_rake(p, pi_mut);
      u4_tack bur    = _lark_nuke(p, sut, tac, rop, qi_mut);
      u4_tack tey    = _lark_cram(p, sut, tac, bur);

#if 0
      { 
        u4_err(p->lan, "tac", tac);
        u4_err(p->lan, "bur", bur);
        u4_err(p->lan, "tey", tey);
        printf("\n");
      }
#endif
      return _lark_feed(p, sut, tey, t_mut);
    }
  }

/****   _rose: high-level functions.
****/
  /* both:rose:plow
  */
  u4_type
  _rose_both(u4_plow p,
             u4_type sut,
             u4_type hoc)
  {
    u4_lane lan = p->lan;

#if 1
    if ( u4_n_eq(u4_atom_blur, sut) ) {
      return hoc;
    }
    else if ( u4_n_eq(u4_atom_blur, hoc) ) {
      return sut;
    }
    else {
      return u4_kt(lan, u4_atom_fuse, hoc, sut);
    }
#else 
    if ( u4_so(_iris_nest(p, hoc, u4_nul, u4_axis_1, sut)) ) {
      /* every sut is a hoc */
      return sut;
    }
    else {
      /* not every sut is a hoc */
      if ( u4_so(_iris_nest(p, sut, u4_nul, u4_axis_1, hoc)) ) {
        /* every hoc is a sut */
        return hoc;
      }
      else {
        /* not every sut is a hoc, not every hoc is a sut */
        return u4_kt(lan, u4_atom_fuse, hoc, sut);
      }
    }
#endif
  }

  /* eith:rose:plow
  */
  u4_type
  _rose_eith(u4_plow p,
             u4_type sut,
             u4_type hoc)
  {
    u4_lane lan = p->lan;

    if ( u4_n_eq(sut, hoc) ) {
      return sut;
    }
    else if ( u4_n_eq(u4_atom_blot, hoc) ) {
      return sut;
    }
    else if ( u4_n_eq(u4_atom_blot, sut) ) {
      return hoc;
    }
    else return u4_kt(lan, u4_atom_fork, sut, hoc);
  }

  /* etch:rose:plow
  */
  u4_type
  _rose_etch(u4_plow p,
             u4_type sut)
  {
    u4_noun p_sut, q_sut;

    if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
      return q_sut;
    }
    else return _plow_fail(p, "bad etch");
  }

  /* edit:rose:plow
  */
  u4_type
  _rose_edit(u4_plow p,
             u4_type sut,
             u4_list mut)
  {
    u4_tack tac = _lark_feed(p, sut, u4_nul, mut);
    u4_type fuz = _iris_burn(p, sut, u4_nul, u4_axis_1, tac);

    return fuz;
  }

  /* gain:rose:plow
  */
    static u4_rack
    _rose_gain_hunt(u4_plow, u4_type, u4_gene);

    static u4_rack
    _rose_gain_hunt_a(u4_plow p,
                      u4_type sut,
                      u4_bank vof)
    {
      if ( u4_n_zero(vof) ) {
        return u4_nul;
      }
      else return u4_log_cat(p->lan, _rose_gain_hunt(p, sut, u4_ch(vof)),
                                     _rose_gain_hunt_a(p, sut, u4_ct(vof)));
    }
    static u4_plot
    _rose_gain_hunt(u4_plow p,
                    u4_type sut,
                    u4_gene gen)
    {
      u4_lane lan = p->lan;
      u4_noun p_gen, q_gen;

      if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        return u4_k_cell
          (lan, 
           u4_k_cell(lan, q_gen, _rose_play(p, sut, p_gen)),
           u4_nul);
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        return _rose_gain_hunt(p, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_zush, &p_gen, &q_gen) ) {
        return _rose_gain_hunt(p, sut, q_gen);
      }
      else if ( u4_b_p(gen, u4_atom_chan, &p_gen) ) {
        return _rose_gain_hunt_a(p, sut, p_gen);
      }
      else return u4_nul;
    }
    static u4_type
    _rose_gain_gild(u4_plow p,
                    u4_type sut,
                    u4_plot mut)
    {
      u4_tack tac = _lark_feed(p, sut, u4_nul, mut);
      u4_type hoc = _iris_burn(p, u4_atom_blur, u4_nul, u4_axis_1, tac);

      return _rose_both(p, sut, hoc);
    }
  u4_type
  _rose_gain(u4_plow p,
             u4_type sut,
             u4_gene gen)
  {
    u4_plot zet = _rose_gain_hunt(p, sut, gen);

    return _rose_gain_gild(p, sut, zet);
  }

  /* make:rose:plow
  */
    u4_list
    _rose_make_boil_a(u4_plow p,
                      u4_type sut,
                      u4_list rem)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(rem) ) {
        return u4_nul;
      }
      else {
        u4_noun i_rem  = u4_ch(rem);
        u4_noun t_rem  = u4_ct(rem);
        u4_gene pi_rem = u4_ch(i_rem);
        u4_tool qi_rem = u4_ct(i_rem);
        u4_plan giz    = _rose_seek(p, sut, _plow_rake(p, pi_rem));
        u4_axis p_giz  = u4_ch(giz);

        return u4_k_cell(lan, u4_k_cell(lan, p_giz, qi_rem),
                              _rose_make_boil_a(p, sut, t_rem));
      }
    }
    u4_tool
    _rose_make_boil(u4_plow p,
                    u4_type sut,
                    u4_axis axe,
                    u4_list rem)
    {
      return _lily_hike(p, axe, _rose_make_boil_a(p, sut, rem));
    }
    u4_noun
    _rose_make_bake(u4_plow p,
                    u4_type sut,
                    u4_book dab)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(dab) ) {
        return u4_noun_0;
      }
      else {
        u4_noun n_dab, l_dab, r_dab, qn_dab;

        u4_c_trel(dab, &n_dab, &l_dab, &r_dab);
        qn_dab = u4_ct(n_dab);
        
        if ( u4_n_zero(l_dab) && u4_n_zero(r_dab) ) {
          return _rose_make(p, sut, qn_dab);
        }
        else if ( u4_n_zero(l_dab) ) {
          return u4_kc
            (lan, _rose_make(p, sut, qn_dab),
                  _rose_make_bake(p, sut, r_dab));
        }
        else if ( u4_n_zero(r_dab) ) {
          return u4_kc
            (lan, _rose_make(p, sut, qn_dab),
                  _rose_make_bake(p, sut, l_dab));
        }
        else {
          return u4_kt
            (lan, _rose_make(p, sut, qn_dab),
                  _rose_make_bake(p, sut, l_dab),
                  _rose_make_bake(p, sut, r_dab));
        }
      }
    }
    u4_noun
    _rose_make_a(u4_plow p,
                 u4_type sut,
                 u4_rack dus)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(dus) ) {
        return u4_nul;
      }
      else {
        u4_noun i_dus = u4_ch(dus);
        u4_noun t_dus = u4_ct(dus);
        u4_gene pi_dus = u4_ch(i_dus);
        u4_gene qi_dus = u4_ct(i_dus);
        u4_tool pog    = _rose_make(p, sut, qi_dus);

        return u4_k_cell
          (lan,
           u4_k_cell(lan, pi_dus, pog),
           _rose_make_a(p, sut, t_dus));
      }
    }
    u4_noun
    _rose_make_prop(u4_plow p,
                    u4_type sut,
                    u4_prop pup)
    {
      u4_lane lan = p->lan;
      
      if ( u4_n_zero(pup) ) {
        return pup;
      } else {
        u4_plan lar = _rose_seek(p, sut, u4_ch(pup));

        return u4_kc(lan, u4_ch(lar), u4_ct(pup));
      }
    }

    static u4_tool
    _rose_make_main(u4_plow p,
                    u4_type sut,
                    u4_gene gen)
    {
      u4_lane lan = p->lan;
      u4_noun p_gen, q_gen, r_gen;

      if ( u4_b_p(gen, u4_atom_zike, &p_gen) ) {
        return u4_k_cell(lan, u4_nock_frag, u4_axis_0);
      }
      else if ( u4_b_p(gen, u4_atom_zoot, &p_gen) ) {
        return u4_tank;
      }
      else if ( u4_b_p(gen, u4_atom_vint, &p_gen) ) {
        return u4_k_cell(lan, u4_nock_vint, _rose_make(p, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return _rose_make(p, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return _lily_cons
          (p, _rose_make(p, sut, p_gen), _rose_make(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_wost, &p_gen) ) {
        return _rose_make(p, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        u4_tool guz;
        u4_atom bug;

        bug = p->bug;
        p->bug = u4_op_inc(lan, p->bug);

        guz = _rose_make(p, sut, p_gen);
        
        p->bug = bug;
        return guz;
      }
      else if ( u4_b_p(gen, u4_atom_dust, &p_gen) ) {
        return u4_k_cell(lan, u4_nock_dust, _rose_make(p, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_germ, &p_gen, &q_gen) ) {
        return u4_kt(lan, 
                     u4_atom_germ,
                     _rose_make(p, sut, p_gen),
                     _rose_make(p, sut, q_gen));
      } 
      else if ( u4_b_pq(gen, u4_atom_hint, &p_gen, &q_gen) ) {
        return u4_kt(lan, 
                     u4_nock_hint,
                     _rose_make(p, sut, p_gen),
                     _rose_make(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_grit, &p_gen) ) {
        return _rose_make(p, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_tash, &p_gen, &q_gen) ) {
        u4_book sec = _gull_fill(p, u4_nul, q_gen);
        u4_noun heq = _rose_make_prop(p, sut, p_gen);
        u4_noun baf = _rose_make_bake(p, _rose_play(p, sut, gen), sec);

#if 1
        return u4_kt
          (lan, u4_nock_coat, heq, baf);
#else
        return u4_kc
          (lan,
           u4_kc(lan, u4_nock_frag, u4_axis_1), 
           u4_kc(lan, u4_nock_bone, baf));
#endif
      }
      else if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(p, sut, _plow_rake(p, q_gen));
        u4_axis p_lar = u4_ch(lar);

        if ( !u4_n_zero(u4_ch(u4_ct(lar))) ) {
          return _plow_fail(p, "bad like");
        }
        else {
          return _iris_fish(p, _rose_play(p, sut, p_gen), u4_nul, p_lar);
        }
      }
      else if ( u4_b_pq(gen, u4_atom_flac, &p_gen, &q_gen) ) {
        return _lily_comb
          (p,
           _rose_make(p, sut, p_gen),
           _rose_make(p, _rose_play(p, sut, p_gen), q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_pank, &p_gen, &q_gen) ) {
        u4_book sec = _gull_fill(p, u4_nul, q_gen);
        u4_noun heq = _rose_make_prop(p, sut, p_gen);
        u4_noun baf = _rose_make_bake(p, _rose_play(p, sut, gen), sec);

#if 1
        return u4_kt
          (lan, u4_nock_coat, heq, baf);
#else
        return u4_kc
          (lan,
           u4_kc(lan, u4_nock_frag, u4_axis_1), 
           u4_kc(lan, u4_nock_bone, baf));
#endif
      }
      else if ( u4_b_p(gen, u4_atom_zalt, &p_gen) ) {
        u4_type yoz = _rose_play(p, sut, p_gen);
   
        return u4_kc(lan, u4_nock_bone, yoz);
      }
      else if ( u4_b_p(gen, u4_atom_zond, &p_gen) ) {
        u4_type yoz = _rose_make(p, sut, p_gen);
   
        return u4_kc(lan, u4_nock_bone, yoz);
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return _rose_make(p, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_sail, &p_gen, &q_gen) ) {
        return u4_k_trel(lan, u4_nock_sail,
                              _rose_make(p, sut, p_gen),
                              _rose_make(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
        return u4_k_cell(lan, u4_nock_bone, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        u4_noun qip;

        p->meb = u4_kc(lan, u4_kc(lan, u4_nul, p_gen), p->meb);
        qip = _rose_make(p, sut, q_gen);
        p->meb = u4_ct(p->meb);

        return qip;
      }
      else if ( u4_b_pq(gen, u4_atom_stil, &p_gen, &q_gen) ) {
        return u4_kc(lan, u4_nock_frag, u4_axis_1);
      }
      else if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(p, sut, p_gen);
        u4_noun rem = _rose_make_a(p, sut, q_gen);
        u4_axis p_lar = u4_ch(lar);
        u4_noun q_lar = u4_ch(u4_ct(lar));
        u4_type r_lar = u4_ct(u4_ct(lar));

#if 0
        if ( !u4_n_zero(q_gen) ) {
          u4_err(lan, "make: take", gen);
          u4_err(lan, "make: q", q_lar);
        }
#endif
        if ( u4_n_zero(q_lar) ) {
          return _rose_make_boil(p, r_lar, p_lar, rem);
        }
        else {
          u4_door uq_lar  = u4_ct(q_lar);
          u4_axis puq_lar = u4_ch(uq_lar);
          u4_type quq_lar = u4_ch(u4_ct(uq_lar));
          u4_tool ruz = _rose_make_boil(p, quq_lar, p_lar, rem);
          u4_tool gak;

          gak = u4_k_trel
            (lan,
             u4_nock_sail,
             ruz,
             u4_k_cell(lan, u4_nock_frag, u4_op_peg(lan, p_lar, puq_lar)));

          return gak;
        }
      }
      else if ( u4_b_pqr(gen, u4_atom_trol, &p_gen, &q_gen, &r_gen) ) {
        return u4_k_qual
          (lan,
           u4_nock_trol,
           _rose_make(p, sut, p_gen),
           _rose_make(p, _rose_gain(p, sut, p_gen), q_gen),
           _rose_make(p, sut, r_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_sing, &p_gen, &q_gen) ) {
        return u4_k_trel
          (lan,
           u4_nock_sing,
           _rose_make(p, sut, p_gen),
           _rose_make(p, sut, q_gen));
      }
      else {
        u4_noun fog = _plow_open(p, gen);

        if ( u4_n_eq(fog, gen) ) {
          u4_err(lan, "dup: gen", gen);
          return u4_trip;
        }
        return _rose_make(p, sut, _plow_open(p, gen)); 
      }
    }
  u4_tool
  _rose_make(u4_plow p,
             u4_type sut,
             u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun mum = u4_kc(lan, sut, gen);
    u4_nopt zod = u4_tab_get(mum, p->niq);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_tool gur = _rose_make_main(p, sut, gen);

      p->niq = u4_tab_add(lan, mum, gur, p->niq);
      return gur;
    }
  }

  /* null:rose:plow
  */
    static u4_flag
    _rose_null_a(u4_plow p, u4_type sut, u4_pool hem);

    static u4_flag
    _rose_null_b(u4_plow p,
                 u4_type sut,
                 u4_pool hem)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;

      if ( u4_n_eq(sut, u4_atom_atom) ) {
        return u4_no;
      }
      else if ( u4_n_eq(sut, u4_atom_blur) ) {
        return u4_no;
      }
      else if ( u4_n_eq(sut, u4_atom_blot) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        return u4_or(_rose_null_a(p, p_sut, hem), _rose_null_a(p, q_sut, hem));
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        return _rose_null_a(p, p_sut, hem);
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        return u4_no;
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _rose_null_a(p, q_sut, hem);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_and(_rose_null_a(p, p_sut, hem), _rose_null_a(p, q_sut, hem));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _rose_orth(p, p_sut, q_sut);
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        if ( u4_bag_in(sut, hem) ) {
          return u4_yes;
        } else {
          return _rose_null_a
            (p, _rose_repo(p, p_sut, q_sut), u4_bag_add(lan, sut, hem));
        }
      } 
      else return u4_trip;
    }
    static u4_flag
    _rose_null_a(u4_plow p,
                 u4_type sut,
                 u4_pool hem)
    {
      u4_lane lan = p->lan;
      u4_noun mum = u4_kc(lan, sut, hem);
      u4_nopt zod = u4_tab_get(mum, p->tyc);

      if ( zod != u4_bull ) {
        return zod;
      }
      else {
        u4_flag gur = _rose_null_b(p, sut, hem);

        p->tyc = u4_tab_add(lan, mum, gur, p->tyc);
        return gur;
      }
    }
  u4_flag
  _rose_null(u4_plow p,
             u4_type sut)
  {
    return _rose_null_a(p, sut, u4_nul);
  }

  /* orth:rose:plow
  */
    static u4_flag
    _rose_orth_a(u4_plow p, u4_type sut, u4_type ref, u4_pool bol);

    static u4_flag
    _rose_orth_b(u4_plow p,
                 u4_type sut,
                 u4_type ref,
                 u4_pool bol)
    {
      u4_lane lan = p->lan;
      u4_noun p_sut, q_sut;
      u4_noun p_ref, q_ref;

      if ( u4_n_eq(sut, u4_atom_atom) ) {
        if ( u4_n_eq(ref, u4_atom_atom) ) {
          return u4_no;
        }
        else if ( u4_b_pq(ref, u4_atom_cell, &p_sut, &q_sut) ) {
          return u4_yes;
        }
        else return _rose_orth_a(p, ref, sut, bol);
      }
      else if ( u4_n_eq(sut, u4_atom_blot) ) {
        return u4_yes;
      }
      else if ( u4_n_eq(sut, u4_atom_blur) ) {
        return u4_no;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        if ( u4_b_pq(ref, u4_atom_cell, &p_ref, &q_ref) ) {
          return u4_or(_rose_orth_a(p, p_sut, p_ref, bol),
                       _rose_orth_a(p, q_sut, q_ref, bol));
        }
        else {
          return _rose_orth_a(p, ref, sut, bol);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        return _rose_orth_a
          (p, u4_k_trel(lan, u4_atom_cell, p_sut, u4_atom_blur), ref, bol);
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        if ( u4_n_eq(u4_atom_atom, ref) ) {
          return u4_n_atom(p_sut) ? u4_no : u4_yes;
        }
        else if ( u4_b_p(ref, u4_atom_cube, &p_ref) ) {
          return u4_say(!u4_n_eq(p_sut, p_ref));
        }
        else if ( u4_b_pq(ref, u4_atom_cell, &p_ref, &q_ref) ) {
          if ( u4_n_atom(p_sut) ) {
            return u4_yes;
          } else {
            u4_type hed = u4_k_cell(lan, u4_atom_cube, u4_ch(p_sut));
            u4_type tal = u4_k_cell(lan, u4_atom_cube, u4_ct(p_sut));

            return u4_or(_rose_orth_a(p, hed, p_ref, bol),
                         _rose_orth_a(p, tal, q_ref, bol));
          }
        }
        else {
          return _rose_orth_a(p, ref, sut, bol);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _rose_orth_a(p, q_sut, ref, bol);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_and(_rose_orth_a(p, p_sut, ref, bol),
                      _rose_orth_a(p, q_sut, ref, bol));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return u4_or(_rose_orth_a(p, p_sut, ref, bol),
                     _rose_orth_a(p, q_sut, ref, bol));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun gob = u4_k_cell(lan, sut, ref);

        if ( u4_bag_in(gob, bol) ) {
          return u4_yes;
        } else {
          return _rose_orth_a
            (p, _rose_repo(p, p_sut, q_sut), ref, u4_bag_add(lan, gob, bol));
        }
      } 
      else {
        u4_err(lan, "sut", sut);

        return u4_trip;
      }
    }
    static u4_flag
    _rose_orth_a(u4_plow p,
                 u4_type sut,
                 u4_type ref,
                 u4_pool bol)
    {
      u4_lane lan = p->lan;
      u4_noun mum = u4_kt(lan, sut, ref, bol);
      u4_nopt zod = u4_tab_get(mum, p->gam);

      if ( zod != u4_bull ) {
        return zod;
      }
      else {
        u4_flag gur = _rose_orth_b(p, sut, ref, bol);

        p->gam = u4_tab_add(lan, mum, gur, p->gam);
        return gur;
      }
    }
  u4_flag
  _rose_orth(u4_plow p,
             u4_type sut,
             u4_type ref)
  {
    return _rose_orth_a(p, sut, ref, u4_nul);
  }

  /* play:rose:plow
  */
    static u4_plot
    _rose_play_a(u4_plow p,
                 u4_type sut,
                 u4_rack dus)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(dus) ) {
        return u4_nul;
      }
      else {
        u4_noun i_dus = u4_ch(dus);
        u4_noun t_dus = u4_ct(dus);
        u4_gene pi_dus = u4_ch(i_dus);
        u4_gene qi_dus = u4_ct(i_dus);
        u4_type feg    = _rose_play(p, sut, qi_dus);

        return u4_k_cell
          (lan,
           u4_k_cell(lan, pi_dus, feg),
           _rose_play_a(p, sut, t_dus));
      }
    }
    static u4_type
    _rose_play_main(u4_plow p,
                    u4_type sut,
                    u4_gene gen)
    {
      u4_lane lan = p->lan;
      u4_noun p_gen, q_gen, r_gen;

      if ( u4_b_p(gen, u4_atom_zike, &p_gen) ) {
        return u4_atom_blot;
      }
      else if ( u4_b_p(gen, u4_atom_zoot, &p_gen) ) {
        return u4_tank;
      }
      else if ( u4_b_p(gen, u4_atom_vint, &p_gen) ) {
        return u4_atom_atom;
      }
      else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return _rose_play(p, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return u4_k_trel
          (lan, u4_atom_cell,
                _rose_play(p, sut, p_gen),
                _rose_play(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_wost, &p_gen) ) {
        return _rose_play(p, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        u4_type soq;
        u4_atom bug;

        bug = p->bug;
        p->bug = u4_op_inc(lan, p->bug);

        soq = _rose_play(p, sut, p_gen);
       
        u4_brut(p, "soq", soq);

        p->bug = bug;
        return soq;
      }
      else if ( u4_b_p(gen, u4_atom_dust, &p_gen) ) {
        return u4_k_trel
          (lan,
           u4_atom_fork,
           u4_k_cell(lan, u4_atom_cube, u4_yes),
           u4_k_cell(lan, u4_atom_cube, u4_no));
      }
      else if ( u4_b_pq(gen, u4_atom_germ, &p_gen, &q_gen) ) {
        return _rose_play(p, sut, q_gen);
      } 
      else if ( u4_b_pq(gen, u4_atom_hint, &p_gen, &q_gen) ) {
        return _rose_play(p, sut, q_gen);
      }
      else if ( u4_b_p(gen, u4_atom_grit, &p_gen) ) {
        return _rose_etch(p, _rose_play(p, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_tash, &p_gen, &q_gen) ) {
        return u4_k_quil
          (lan, u4_atom_core, 
                sut, 
                u4_atom_soft,
                sut,
                _gull_fill(p, u4_nul, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        return u4_k_trel
          (lan,
           u4_atom_fork,
           u4_k_cell(lan, u4_atom_cube, u4_yes),
           u4_k_cell(lan, u4_atom_cube, u4_no));
      }
      else if ( u4_b_pq(gen, u4_atom_flac, &p_gen, &q_gen) ) {
        return _rose_play(p, _rose_play(p, sut, p_gen), q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_pank, &p_gen, &q_gen) ) {
        return u4_k_quil
          (lan, u4_atom_core, 
                sut, 
                u4_atom_hard,
                sut,
                _gull_fill(p, u4_nul, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_zalt, &p_gen) ) {
        return u4_k_cell(lan, u4_atom_cube, _rose_play(p, sut, p_gen));
      }
      else if ( u4_b_p(gen, u4_atom_zond, &p_gen) ) {
        return u4_k_cell(lan, u4_atom_cube, _rose_make(p, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return u4_k_trel(lan, u4_atom_face, p_gen, _rose_play(p, sut, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_sail, &p_gen, &q_gen) ) {
        return u4_atom_blur;
      }
      else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
        return u4_k_cell(lan, u4_atom_cube, p_gen); 
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        u4_noun qip;

        p->meb = u4_kc(lan, u4_kc(lan, u4_nul, p_gen), p->meb);
        qip = _rose_play(p, sut, q_gen);
        p->meb = u4_ct(p->meb);

        return qip;
      }
      else if ( u4_b_pq(gen, u4_atom_stil, &p_gen, &q_gen) ) {
        return sut;
      }
      else if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(p, sut, p_gen);
        u4_noun huz = _rose_play_a(p, sut, q_gen);
        u4_noun q_lar = u4_ch(u4_ct(lar));
        u4_type r_lar = u4_ct(u4_ct(lar));

        if ( u4_n_zero(q_lar) ) {
          return _rose_edit(p, r_lar, huz);
        }
        else {
          u4_door uq_lar  = u4_ct(q_lar);
          u4_type quq_lar = u4_ch(u4_ct(uq_lar));
          u4_gene ruq_lar = u4_ct(u4_ct(uq_lar));
          u4_gene old     = gen;
          u4_noun p_sut, q_sut, r_sut, s_sut;

          sut = _rose_edit(p, quq_lar, huz);
          gen = ruq_lar;

          if ( u4_b_pqrs(sut, u4_atom_core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
            if ( u4_n_eq(u4_atom_hard, q_sut) ) {
              sut = u4_k_quil(lan, u4_atom_core, r_sut, q_sut, r_sut, s_sut);
              if ( !u4_n_zero(p->bug) ) {
                u4_err(lan, "hard: gen", old);
                u4_brut(p, "hard: sut", sut);
                u4_brut(p, "hard: mack", u4_kt(lan, u4_atom_hold, sut, gen));
                printf("\n");
              }
            } 
            else if ( u4_n_eq(u4_atom_soft, q_sut) ) {
              sut = sut;
              if ( !u4_n_zero(p->bug) ) {
                u4_err(lan, "soft: gen", old);
                u4_brut(p, "soft: sut", sut);
                u4_brut(p, "soft: mack", u4_kt(lan, u4_atom_hold, sut, gen));
                printf("\n");
              }
            }
            else return u4_trip;
          }
          else return u4_trip;

          return u4_k_trel(lan, u4_atom_hold, sut, gen);
        }
      }
      else if ( u4_b_pqr(gen, u4_atom_trol, &p_gen, &q_gen, &r_gen) ) {
        return _rose_eith
          (p,
           _rose_play(p, _rose_gain(p, sut, p_gen), q_gen),
           _rose_play(p, sut, r_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_sing, &p_gen, &q_gen) ) {
        return u4_k_trel
          (lan,
           u4_atom_fork,
           u4_k_cell(lan, u4_atom_cube, u4_yes),
           u4_k_cell(lan, u4_atom_cube, u4_no));
      }
      else {
        return _rose_play(p, sut, _plow_open(p, gen)); 
      }
    }
  u4_type
  _rose_play(u4_plow p,
             u4_type sut,
             u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun mum = u4_kc(lan, sut, gen);
    u4_nopt zod = u4_tab_get(mum, p->zor);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_type gur = _rose_play_main(p, sut, gen);

      p->zor = u4_tab_add(lan, mum, gur, p->zor);
      return gur;
    }
  }

  /* repo:rose:plow
  */
  u4_type
  _rose_repo(u4_plow p,
             u4_type sut,
             u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun vax = u4_k_cell(lan, sut, gen);

    if ( u4_bag_in(vax, p->fan) ) {
      return _plow_fail(p, "inference recursion");
    }
    else {
      u4_noun fan;
      u4_type gex;

      fan = p->fan;
      p->fan = u4_bag_add(lan, vax, p->fan);

      gex = _rose_play(p, sut, gen);
      p->fan = fan;
      return gex;
    }
  }

  /* seek:rose:plow
  */
    static u4_plan
    _rose_seek_a(u4_plow p,
                 u4_type sut,
                 u4_rope rop,
                 u4_axis axe,
                 u4_unit act)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(rop) ) {
        return u4_k_trel(lan, axe, act, sut);
      }
      else {
        u4_noun i_rop = u4_ch(rop);
        u4_noun t_rop = u4_ct(rop);
        u4_noun pi_rop;

        if ( u4_n_atom(i_rop) ) {
          return _rose_seek_a
            (p, sut, 
                u4_k_cell(lan, u4_k_cell(lan, u4_atom_pane, i_rop), t_rop),
                axe,
                act);
        }
        else if ( u4_b_p(i_rop, u4_atom_frag, &pi_rop) ) {
          return _rose_seek_a
            (p, _iris_peek(p, sut, u4_nul, u4_axis_1, pi_rop), 
                t_rop,
                u4_op_peg(lan, axe, pi_rop),
                u4_nul);
        }
        else if ( u4_b_p(i_rop, u4_atom_pane, &pi_rop) ) {
          u4_plan sap = _iris_find(p, sut, u4_nul, u4_axis_1, pi_rop);
          u4_axis p_sap = u4_ch(sap);
          u4_unit q_sap = u4_ch(u4_ct(sap));
          u4_type r_sap = u4_ct(u4_ct(sap));
#if 0
          if ( u4_n_zero(pi_rop) ) {
            u4_err(lan, "blip: p", p_sap);
            u4_err(lan, "blip: q", q_sap);
            u4_err(lan, "blip: r", r_sap);
          }
#endif
          return _rose_seek_a
            (p, r_sap, t_rop, u4_op_peg(lan, axe, p_sap), q_sap);
        }
        else return u4_trip;
      }
    }
  u4_plan
  _rose_seek(u4_plow p,
             u4_type sut,
             u4_rope rop)
  {
    return _rose_seek_a(p, sut, rop, u4_axis_1, u4_nul);
  }

  /* show:rose:plow
  */
    u4_flag
    _rose_show_nest(u4_plow p,
                    u4_type sut,
                    u4_type bon)
    {
      if ( !u4_so(_iris_nest(p, sut, u4_nul, u4_axis_1, bon)) ) {
        u4_brut(p, "sut", sut);
        u4_brut(p, "bon", bon);
        return _plow_fail(p, "nest: show");
      }
      else {
        return u4_yes;
      }
    }
    static u4_plot
    _rose_show_a(u4_plow p,
                 u4_type sut,
                 u4_rack dus)
    {
      u4_lane lan = p->lan;

      if ( u4_n_zero(dus) ) {
        return u4_nul;
      }
      else {
        u4_noun i_dus = u4_ch(dus);
        u4_noun t_dus = u4_ct(dus);
        u4_gene pi_dus = u4_ch(i_dus);
        u4_gene qi_dus = u4_ct(i_dus);

        if ( !u4_so(_rose_show(p, sut, qi_dus)) ) {
          return _plow_fail(p, "show: take");
        }
        else {
          u4_type feg    = _rose_play(p, sut, qi_dus);

          return u4_k_cell
            (lan,
             u4_k_cell(lan, pi_dus, feg),
             _rose_play_a(p, sut, t_dus));
        }
      }
    }
    u4_flag
    _rose_show_main(u4_plow p,
                    u4_type sut,
                    u4_gene gen)
    {
      u4_lane lan = p->lan;
      u4_noun p_gen, q_gen, r_gen;

      if ( u4_b_p(gen, u4_atom_zike, &p_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_p(gen, u4_atom_zoot, &p_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_p(gen, u4_atom_vint, &p_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen),
                      _rose_show_nest
                          (p, u4_atom_atom, _rose_play(p, sut, p_gen)));
      }
      else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return u4_and
          (_rose_show(p, sut, p_gen),
           u4_and
            (_rose_show(p, sut, q_gen),
             _rose_show_nest(p, _rose_play(p, sut, p_gen),
                                _rose_play(p, sut, q_gen))));
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen), _rose_show(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_wost, &p_gen) ) {
        return _rose_show(p, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        u4_flag zic;
        u4_atom bug;

        bug = p->bug;
        p->bug = u4_op_inc(lan, p->bug);

        zic = _rose_show(p, sut, p_gen);
        
        p->bug = bug;
        return zic;
      }
      else if ( u4_b_p(gen, u4_atom_dust, &p_gen) ) {
        return _rose_show(p, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_germ, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen),
                      _rose_show(p, sut, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_hint, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen),
                      _rose_show(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_grit, &p_gen) ) {
        return _rose_show(p, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_tash, &p_gen, &q_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen), 
                      _rose_show(p, sut, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_flac, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen),
                      _rose_show(p, _rose_play(p, sut, p_gen), q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_pank, &p_gen, &q_gen) ) {
        sut = _rose_play(p, sut, gen);

        while ( !u4_n_zero(q_gen) ) {
          u4_noun iq_gen = u4_ch(q_gen);
          u4_noun tq_gen = u4_ct(q_gen);
          u4_noun qiq_gen = u4_ct(iq_gen);

          if ( !u4_so(_rose_show(p, sut, qiq_gen)) ) {
            return _plow_fail(p, "menu fail");
          }
          q_gen = tq_gen;
        }
        return u4_yes;
      }
      else if ( u4_b_p(gen, u4_atom_zalt, &p_gen) ) {
        return _rose_show(p, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zond, &p_gen) ) {
        return _rose_show(p, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return _rose_show(p, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_sail, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(p, sut, p_gen),
                      _rose_show(p, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        u4_noun qip;

        p->meb = u4_kc(lan, u4_kc(lan, u4_nul, p_gen), p->meb);
        qip = _rose_show(p, sut, q_gen);
        p->meb = u4_ct(p->meb);

        return qip;
      }
      else if ( u4_b_pq(gen, u4_atom_stil, &p_gen, &q_gen) ) {
        return u4_and
          (_rose_show(p, sut, p_gen),
           u4_and
            (_rose_show(p, sut, q_gen),
             _rose_show_nest
              (p, _rose_play(p, sut, p_gen), _rose_play(p, sut, q_gen))));
      }
      else if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(p, sut, p_gen);
        u4_noun huz = _rose_show_a(p, sut, q_gen);
        u4_noun q_lar = u4_ch(u4_ct(lar));

        if ( u4_n_zero(q_lar) ) {
          return u4_yes;
        }
        else {
          u4_door uq_lar  = u4_ct(q_lar);
          u4_type quq_lar = u4_ch(u4_ct(uq_lar));
          u4_gene ruq_lar = u4_ct(u4_ct(uq_lar));
          u4_noun p_sut, q_sut, r_sut, s_sut;

          sut = _rose_edit(p, quq_lar, huz);
          gen = ruq_lar;

          if ( u4_b_pqrs(sut, u4_atom_core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
            if ( u4_n_eq(u4_atom_hard, q_sut) ) {
              return _rose_show_nest(p, r_sut, p_sut);
            }
            else if ( u4_n_eq(u4_atom_soft, q_sut) ) {
              u4_noun fuy = u4_k_cell(lan, sut, gen);

              if ( u4_bag_in(fuy, p->ver) ) {
                return u4_yes;
              } else {
                u4_type  gim = u4_k_quil
                    (lan, u4_atom_core, r_sut, q_sut, r_sut, s_sut);
                u4_bag   rev = p->ver;
                u4_flag  goh;

                p->ver = u4_bag_add(lan, fuy, p->ver);
                goh = u4_and
                  (_rose_show(p, sut, gen),
                   u4_say(u4_n_eq(_rose_make(p, sut, gen), 
                                  _rose_make(p, gim, gen))));

                p->ver = rev;
                if ( !u4_so(goh) ) {
                  u4_err(lan, "gen", gen);
                  u4_err(lan, "mka", _rose_make(p, sut, gen));
                  u4_err(lan, "mkb", _rose_make(p, gim, gen));
                  return _plow_fail(p, "soft mack");
                }
                return goh;
              }
            } 
            else return u4_trip;
          }
          else return u4_trip;
        }
      }
      else if ( u4_b_pqr(gen, u4_atom_trol, &p_gen, &q_gen, &r_gen) ) {
        return u4_and
          (_rose_show(p, sut, p_gen),
           u4_and
           (_rose_show(p, _rose_gain(p, sut, p_gen), q_gen),
            _rose_show(p, sut, r_gen)));
      }
      else if ( u4_b_pq(gen, u4_atom_sing, &p_gen, &q_gen) ) {
        return u4_and
          (_rose_show(p, sut, p_gen),
           _rose_show(p, sut, q_gen));
      }
      else {
        u4_gene vul = _plow_open(p, gen);

        if ( u4_n_eq(vul, gen) ) {
          u4_err(lan, "gen", gen);
          u4_err(lan, "vul", vul);
          return u4_trip;
        }

        return _rose_show(p, sut, vul);
      }
    }
  u4_flag
  _rose_show(u4_plow p,
             u4_type sut,
             u4_gene gen)
  {
#if 0
    return u4_yes;
#else
    u4_lane lan = p->lan;
    u4_noun mum = u4_kc(lan, sut, gen);
    u4_nopt zod = u4_tab_get(mum, p->hos);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_flag gur = _rose_show_main(p, sut, gen);

      p->hos = u4_tab_add(lan, mum, gur, p->hos);
      return gur;
    }
#endif
  }


/****   _plow: top-level functions.
****/
  void
  _plow_trap(u4_plow p,
             const char *msg)
  {
    u4_lane lan = p->lan;

    u4_atom hal  = u4_k_atom_c(lan, msg);

    p->meb = u4_k_cell(lan, u4_k_cell(lan, hal, u4_nul), p->meb);
  }

  u4_noun
  _plow_fail(u4_plow p,
             const char *msg)
  {
    _plow_trap(p, msg);
    {
      while ( !u4_n_zero(p->meb) ) {
        u4_noun i_meb = u4_ch(p->meb);
        u4_noun hal = u4_ch(i_meb);
        u4_noun jup = u4_ct(i_meb);

        if ( !u4_n_zero(hal) ) {
          u4_sb sb_hal = u4_a_bin(hal, 3);
          u4_cl *cl_hal = alloca(sb_hal + 1);

          u4_a_bytes(hal, (u4_xb *)cl_hal, 0, sb_hal + 1);
          printf("msg: %s\n", cl_hal);
        }

        if ( !u4_n_zero(jup) ) {
          u4_atom pp_jup = u4_ch(u4_ch(jup));
          u4_atom qp_jup = u4_ct(u4_ch(jup));
          u4_atom pq_jup = u4_ch(u4_ct(jup));
          u4_atom qq_jup = u4_ct(u4_ct(jup));
          {
            u4_xw xw_flin = u4_a_wtrip(pp_jup);
            u4_xw xw_fcol = u4_a_wtrip(qp_jup);
            u4_xw xw_llin = u4_a_wtrip(pq_jup);
            u4_xw xw_lcol = u4_a_wtrip(qq_jup);

            printf("spot: %d:%d - %d:%d\n", 
                   xw_flin, xw_fcol, xw_llin, xw_lcol);
          }
        }
        p->meb = u4_ct(p->meb);
      }
    }
    return u4_exit;
    // return u4_trip;
  }

  /* rake:plow 
  */
  u4_rope
  _plow_rake(u4_plow p,
             u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_gene p_gen, q_gen;

    if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
      if ( !u4_n_zero(q_gen) ) {
        return _plow_fail(p, "rope");
      }
      else return p_gen;
    }
    else if ( u4_b_p(gen, u4_atom_frag, &p_gen) ) {
      return u4_kl(lan, gen);
    }
    else if ( u4_b_p(gen, u4_atom_pane, &p_gen) ) {
      return u4_kl(lan, gen);
    }
    else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
      return _plow_rake(p, q_gen);
    }
    else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
      return _plow_rake(p, p_gen);
    }
    else {
      u4_err(lan, "rake", gen);
      return _plow_fail(p, "rope");
    }
  }

  /* init:plow (fake)
  */
  void
  u4_plow_init(u4_plow p,
               u4_lane lan)
  {
    p->lan = lan;
    p->prf = 0;
    p->prg = 0;
    p->prh = 0;
    p->pri = 0;

    p->fan = u4_nul;
    p->ver = u4_nul;
    p->bug = u4_nul;
    p->meb = u4_nul;
    p->vus = u4_nul;
    p->tyc = u4_nul;
    p->gam = u4_nul;
    p->hos = u4_nul;
    p->zor = u4_nul;
    p->niq = u4_nul;
    p->fac = u4_nul;
    p->vom = u4_nul;
    p->pon = u4_nul;
    p->fin = u4_nul;
    p->huf = u4_nul;
  }

  /* make:plow (fake)
  */
  u4_noun
  u4_plow_make(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return _rose_make(p, sut, gen);
  }

  /* play:plow (fake)
  */
  u4_noun
  u4_plow_play(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return _rose_play(p, sut, gen);
  }

  /* show:plow (fake)
  */
  u4_noun
  u4_plow_show(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return _rose_show(p, sut, gen);
  }

  /* pass:plow (fake)
  */
  u4_noun
  u4_plow_pass(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    if ( !u4_so(_rose_show(p, sut, gen)) ) {
      return u4_exit;
    }
    else return _rose_make(p, sut, gen);
  }

  /* shop:plow (fake)
  */
  u4_noun
  u4_plow_shop(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    if ( !u4_so(_rose_show(p, sut, gen)) ) {
      return u4_exit;
    }
    else return _rose_play(p, sut, gen);
  }

  /* wish:plow (fake)
  */
  u4_noun
  u4_plow_wish(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return 
      u4_kc(lan, _rose_play(p, sut, gen),
                 _rose_make(p, sut, gen));
  }

  /* shop:plow (fake)
  */
  u4_noun
  u4_plow_mill(u4_lane lan,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    if ( !u4_so(_rose_show(p, sut, gen)) ) {
      return u4_exit;
    }
    else return 
      u4_kc(lan, _rose_play(p, sut, gen),
                 _rose_make(p, sut, gen));
  }

