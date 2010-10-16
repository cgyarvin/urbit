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
  

/** External operators (temporary):
**/
  /** Books.
  **/
    /* u2_fj_book_in():
    **
    **   Return 1 iff (tag) is in (tab).
    */
      u4_t
      u2_fj_book_in(u4_noun tag,
                u4_tab  tab);

    /* u2_fj_book_get(): 
    **
    **   Produce the dog in (tab) matching (tag), or bull.
    */
      u4_nopt
      u2_fj_book_get(u4_noun tag,
                 u4_tab  tab);

    /* u2_fj_book_add():
    **
    **   Produce a new tab which adds (tag dog) to (tab).
    **   Replace old dog, if any.
    */
      _(u4_tab, tab_pro)
      u2_fj_book_add(u4_lane lane,
                 u4_noun tag,
                 u4_noun dog,
                 u4_tab  tab_sub);

    /* u2_fj_book_add_list():
    **
    **   Produce a new tab which adds all (tag dog) cells in
    **   (log) to (tab).  Replace old dog, if any.
    */
      _(u4_tab, tab_pro)
      u2_fj_book_add_list(u4_lane lane,
                     u4_log  log,
                     u4_tab  tab_sub);

/** Forward declarations.
**/

/****   _dump: pretty-printing.
****/
      /** Global variables.
      **/
        u4_pool how;

        static u4_prep
        _dump_main(u2_ray  wir_r, u4_pool gil, u4_pool nip, u4_type typ);

  /* seal:dump (fake)
  */
    static u4_pool
    _dump_seal_main(u2_ray  wir_r,
                    u4_pool gil,
                    u4_type typ)
    {
      
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
        return u2_fj_pool_cat(wir_r, _dump_seal_main(wir_r, gil, p_typ),
                               _dump_seal_main(wir_r, gil, q_typ));
      }

      // [%core p=type q=*]
      //
      else if ( u4_b_pq(typ, u4_atom_core, &p_typ, &q_typ) ) {
        return _dump_seal_main(wir_r, gil, p_typ);
      }

      // [%cube p=noun]
      // 
      else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
        return u4_nul;
      }

      // [%face p=mark q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_face, &p_typ, &q_typ) ) {
        return _dump_seal_main(wir_r, gil, q_typ);
      }

      // [%fork p=type q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_fork, &p_typ, &q_typ) ) {
        return u2_fj_pool_cat(wir_r, _dump_seal_main(wir_r, gil, p_typ),
                                _dump_seal_main(wir_r, gil, q_typ));
      }

      // [%fuse p=type q=type]
      //
      else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
        return u2_fj_pool_cat(wir_r, _dump_seal_main(wir_r, gil, p_typ),
                                _dump_seal_main(wir_r, gil, q_typ));
      }

      // [%hold p=type q=gene]
      //
      else if ( u4_b_pq(typ, u4_atom_hold, &p_typ, &q_typ) ) {
        if ( u2_fj_pool_in(typ, gil) ) {
          return u4_k_trel(wir_r, typ, u4_nul, u4_nul);
        } 
        else {
          return _dump_seal_main
            (wir_r, u2_fj_pool_add(wir_r, typ, gil),
                _rose_repo(wir_r, p_typ, q_typ));
        }
      }
      else {
        if ( !u4_n_atom(typ) && !u4_n_atom(u4_ch(typ)) ) {
          printf("hm!\n");
        }
        else u4_err(wir_r, "odd type", typ);


        return u4_trip;
      }
    }

  /* _dump_seal(): produce set of holds sealing [typ].
  */
  u4_pool
  _dump_seal(u2_ray  wir_r,
             u4_type typ)
  {
    return _dump_seal_main(wir_r, u4_nul, typ);
  }

  /* _dump_cell()::
  */
  static u4_noun
  _dump_cell(u2_ray  wir_r,
             u4_pool gil,
             u4_pool nip,
             u4_noun p_typ,
             u4_noun q_typ)
  {
    
    u4_noun pq_typ, qq_typ;

    if ( u4_b_pq(q_typ, u4_atom_cell, &pq_typ, &qq_typ) ) {
      return u4_k_cell
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
              _dump_cell(wir_r, gil, nip, pq_typ, qq_typ));
    }
    else {
      return u4_k_trel
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
               _dump_main(wir_r, gil, nip, q_typ),
               u4_nul);
    }
  }

  /* _dump_core(): dump a core.
  */
  static u4_prep
  _dump_core(u2_ray  wir_r,
             u4_pool gil,
             u4_pool nip,
             u4_type myt,
             u4_atom kic,
             u4_spec dab)
  {
    
    u4_prep gum;
    u4_prep zib;
    u4_prep bor;

    zib = _dump_main(wir_r, gil, nip, myt);
    bor = u4_k_atom_cat
      (wir_r, (u4_n_eq(u4_atom_soft, kic) ? u4_cod_in('-') : u4_cod_in('+')),
             u4_k_atom_cat
               (wir_r, u4_prep_decimal(wir_r, _gull_size(wir_r, dab)),
                      u4_k_atom_cat
                        (wir_r, u4_cod_in('.'),
                               u4_prep_hexinal
                                  (wir_r, u4_cod_in(u4_n_nub(dab) & 0xffff)))));

    gum = u4_prep_close
      (wir_r, '<', '>', u4_k_list(wir_r, zib, bor, 0));

    return gum;
  }

  /* _dump_fork(): dump fork as list.
  */
  static u4_noun
  _dump_fork(u2_ray  wir_r,
             u4_pool gil,
             u4_pool nip,
             u4_type p_typ,
             u4_type q_typ)
  {
    
    u4_noun pq_typ, qq_typ;

    if ( u4_b_pq(q_typ, u4_atom_fork, &pq_typ, &qq_typ) ) {
      return u4_kc
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
              _dump_fork(wir_r, gil, nip, pq_typ, qq_typ));
    }
    else {
      return u4_kt
        (wir_r, _dump_main(wir_r, gil, nip, p_typ),
              _dump_main(wir_r, gil, nip, q_typ),
              u4_nul);
    }
  }
   
  /* _dump_main(): dump with gil and nip.
  */
  static u4_prep
  _dump_main(u2_ray  wir_r,
             u4_pool gil,
             u4_pool nip,
             u4_type typ)
  {
    
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
        (wir_r, '[', ']', 
                _dump_cell(wir_r, gil, nip, p_typ, q_typ));
    }
    else if ( u4_b_pqrs(typ, u4_atom_core, &p_typ, &q_typ, &r_typ, &s_typ) ) {
      return _dump_core(wir_r, gil, nip, p_typ, q_typ, s_typ);
    }
    else if ( u4_b_p(typ, u4_atom_cube, &p_typ) ) {
      if ( (u2_nul == p_typ) ) {
        return u4_cod_in('~');
      }
      else if ( u4_n_atom(p_typ) ) {
        return u4_k_atom_cat
          (wir_r, u4_cod_in('%'), u4_prep_textual(wir_r, p_typ));
      }
      else {
        return u4_k_list
          (wir_r,
           u4_atom_nail,
           u4_cod_in('%'),
           u4_pump_prep(wir_r, p_typ),
           0);
      }
    }
    else if ( u4_b_pq(typ, u4_atom_face, &p_typ, &q_typ) ) {
      return u4_k_list
        (wir_r, u4_atom_nail, 
               u4_prep_textual(wir_r, p_typ),
               u4_cod_in(':'),
               _dump_main(wir_r, gil, nip, q_typ),
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
            (wir_r, '{', '}', _dump_fork(wir_r, gil, nip, p_typ, q_typ));
      }
    }
    else if ( u4_b_pq(typ, u4_atom_fuse, &p_typ, &q_typ) ) {
      return u4_prep_close
        (wir_r, '(', ')', 
               u4_k_list(wir_r,
                         _dump_main(wir_r, gil, nip, p_typ),
                         _dump_main(wir_r, gil, nip, q_typ),
                         0));
    }
    else if ( u4_b_pq(typ, u4_atom_hold, &p_typ, &q_typ) ) {
      if ( u2_fj_pool_in(typ, gil) ) {
        u4_noun fez = u4_k_atom_cat
            (wir_r, u4_cod_in('$'), 
                   u4_prep_decimal(wir_r, u2_fj_pool_at(wir_r, typ, u4_axis_1, gil)));

        if ( u2_fj_pool_in(typ, nip) || u2_fj_pool_in(typ, how) ) {
          return fez;
        }
        else {
          how = u2_fj_pool_add(wir_r, typ, how);
          { 
            u4_prep hod = 
              _dump_main(wir_r, gil, 
                            u2_fj_pool_add(wir_r, typ, nip),
                            _rose_repo(wir_r, p_typ, q_typ));

            
            return u4_k_list
              (wir_r, u4_atom_nail, 
                     fez,
                     u4_cod_in('='),
                     hod,
                     0);
          }
        }
      }
      else {
        return _dump_main(wir_r, gil, nip, _rose_repo(wir_r, p_typ, q_typ));
      }
    }
    else {
      return u4_trip;
    }
  }

  /* _durb_in()::
  */
  static u4_noun
  _durb_in(u2_ray  wir_r,
           u4_rail bar)
  {
    if ( (u2_nul == bar) ) {
      return u4_nul;
    } else {
      return u4_k_cell(p->wir_r, _dump_type(wir_r, u4_ch(bar)), 
                               _durb_in(wir_r, u4_ct(bar)));
    }
  }

  /* _dump_durb(): prepare rail for printing.
  */
  u4_prep
  _dump_durb(u2_ray  wir_r,
             u4_rail bar)
  {
    if ( (u2_nul == bar) ) {
      return u4_cod_in('~');
    }
    else {
      return u4_prep_close
        (p->wir_r, '(', ')', _durb_in(wir_r, bar));
    }
  }

  /* _dump_type(): prepare type for printing.
  */
  u4_prep
  _dump_type(u2_ray  wir_r,
             u4_type typ)
  {
    u4_pool gil = _dump_seal(wir_r, typ);
    u4_prep par;

    // Lamentable.
    //
    how = u4_nul;
    par = _dump_main(wir_r, gil, u4_nul, typ);
    how = u4_nul;

    return par;
  }

  /* _dump_size()::
  */
  u4_atom
  _dump_size(u2_ray wir_r, u4_noun box)
  {
    if ( u4_n_atom(box) ) {
      return u4_math_1;
    }
    else {
      return u4_op_add
        (wir_r, _dump_size(wir_r, u4_ch(box)), 
              _dump_size(wir_r, u4_ct(box)));
    }
  }
/****   _lily: formula assembly.
****/
  /* cons:lily
  */
  u4_tool
  _lily_cons(u2_ray  wir_r,
             u4_tool vur,
             u4_tool sed)
  {
    
    u4_noun p_vur, p_sed;

    if ( u4_b_p(vur, u4_nock_bone, &p_vur) && 
         u4_b_p(sed, u4_nock_bone, &p_sed) ) {
      return u4_kt(wir_r, u4_nock_bone, p_vur, p_sed);
    }
    else if ( u4_b_p(vur, u4_nock_frag, &p_vur) && 
              u4_b_p(sed, u4_nock_frag, &p_sed) &&
              !u4_n_eq(u4_axis_1, p_vur) &&
              !u4_n_eq(p_vur, p_sed) &&
              (u2_nul == u4_op_ord(p_vur, p_sed)) )
    {
      u4_atom fub = u4_op_div(wir_r, u4_math_2, p_vur);
      u4_atom nof = u4_op_div(wir_r, u4_math_2, p_sed);

      if ( u4_n_eq(fub, nof) ) {
        return u4_kc(wir_r, u4_nock_frag, fub);
      }
    }
    return u4_kc(wir_r, vur, sed);
  }

  /* comb:lily
  */
  u4_tool
  _lily_comb(u2_ray  wir_r,
             u4_tool mal,
             u4_tool buz)
  {
    
    u4_noun p_mal, q_mal, p_buz, q_buz, pp_buz, pq_buz;

    if ( u4_b_p(mal, u4_nock_frag, &p_mal) ) {
      if ( u4_b_p(buz, u4_nock_frag, &p_buz) ) {
        if ( (u2_nul == p_buz) ) {
          return buz;
        }
        return u4_kc(wir_r, u4_nock_frag, u4_op_peg(wir_r, p_mal, p_buz));
      }
      else if ( u4_b_pq(buz, u4_nock_sail, &p_buz, &q_buz) &&
                u4_b_p(p_buz, u4_nock_frag, &pp_buz) &&
                u4_b_p(q_buz, u4_nock_frag, &pq_buz) )
      {
        return u4_kt
          (wir_r, u4_nock_sail, 
                 u4_kc(wir_r, u4_nock_frag, u4_op_peg(wir_r, p_mal, pp_buz)),
                 u4_kc(wir_r, u4_nock_frag, u4_op_peg(wir_r, p_mal, pq_buz)));
      }
    }
    else if ( u4_b_fork(mal, &p_mal, &q_mal) ) {
      if ( !u4_n_atom(q_mal) && 
           u4_n_eq(u4_noun_0, u4_ch(q_mal)) &&
           u4_n_eq(u4_noun_1, u4_ct(q_mal)) )
      {
        return u4_kt(wir_r, u4_nock_gant, p_mal, buz);
      }
    }
    else if ( u4_b_p(buz, u4_nock_frag, &p_buz) ) {
      if ( u4_n_eq(u4_axis_1, p_buz) ) {
        return mal;
      }
    }
    // return u4_kq(wir_r, u4_nock_sail, mal, u4_nock_bone, buz);
    return u4_kt(wir_r, u4_nock_flac, mal, buz);
  }

  /* flan:lily
  */
  u4_tool
  _lily_flan(u2_ray  wir_r,
             u4_tool zeg,
             u4_tool dac)
  {
    

    if ( u4_n_eq(u4_nock_bone, u4_ch(zeg)) ) {
      if ( (u2_nul == u4_ct(zeg)) ) {
        return dac;
      }
      else return zeg;
    }
    else {
      if ( u4_n_eq(u4_nock_bone, u4_ch(dac)) ) {
        if ( (u2_nul == u4_ct(dac)) ) {
          return zeg;
        }
        else return dac;
      }
      else {
        return u4_kq
          (wir_r, u4_nock_trol, zeg, dac, u4_kc(wir_r, u4_nock_bone, u4_no));
      }
    }
  }

  /* flor:lily
  */
  u4_tool
  _lily_flor(u2_ray  wir_r,
             u4_tool bos,
             u4_tool nif)
  {
    

    if ( u4_n_eq(u4_nock_bone, u4_ch(bos)) ) {
      if ( (u2_nul == u4_ct(bos)) ) {
        return bos;
      }
      else return nif;
    }
    else {
      if ( u4_n_eq(u4_nock_bone, u4_ch(nif)) ) {
        if ( (u2_nul == u4_ct(nif)) ) {
          return nif;
        }
        else return bos;
      }
      else {
        return u4_kq
          (wir_r, u4_nock_trol, bos, u4_kc(wir_r, u4_nock_bone, u4_yes), nif);
      }
    }
  }

  /* _lily_flop(): invert boolean.
  */
  u4_tool
  _lily_flop(u2_ray  wir_r,
             u4_tool zet)
  {
    

    if ( u4_n_eq(u4_nock_bone, u4_ch(zet)) ) {
      if ( u4_n_eq(u4_yes, u4_ct(zet)) ) {
        return u4_kc(wir_r, u4_nock_bone, u4_no);
      }
      else {
        u4_assert(u4_n_eq(u4_no, u4_ct(zet)));

        return u4_kc(wir_r, u4_nock_bone, u4_yes);
      }
    }
    else {
      return u4_kq
        (wir_r, u4_nock_trol, 
               zet, 
               u4_kc(wir_r, u4_nock_bone, u4_no), 
               u4_kc(wir_r, u4_nock_bone, u4_yes));
    }
  }

  /* hike:lily:plow
  */
    static u4_axis 
    _lily_hike_axis_l(u2_ray  wir_r, 
                      u4_axis axis)
    {
      return u4_op_add(wir_r, axis, axis);
    }
    u4_axis 
    _lily_hike_axis_r(u2_ray  wir_r, 
                      u4_axis axis)
    {
      return u4_op_inc(wir_r, _lily_hike_axis_l(wir_r, axis));
    }

    /* _lily_hike_belt_root(): convert (vix) to a log of root tools.
    */
    static u4_log
    _lily_hike_belt_root(u2_ray  wir_r,
                         u4_list vix)
    {
      if ( (u2_nul == vix) ) {
        return u4_nul;
      }
      else {
        u4_axis axis     = u4_ch(u4_ch(vix));
        u4_tool tool     = u4_ct(u4_ch(vix));
        u4_list log_tool = _lily_hike_belt_root(wir_r, u4_ct(vix));

        if ( u4_n_eq(u4_axis_1, axis) ) {
          return u4_kc(wir_r, tool, log_tool);
        }
        else return log_tool;
      }
    }

    /* _lily_hike_belt_l(): factor (vix) left.
    */
    static u4_log
    _lily_hike_belt_l(u2_ray  wir_r,
                u4_list vix)
    {
      if ( (u2_nul == vix) ) {
        return u4_nul;
      }
      else {
        u4_axis axis       = u4_ch(u4_ch(vix));
        u4_tool tool       = u4_ct(u4_ch(vix));
        u4_list belt_l = _lily_hike_belt_l(wir_r, u4_ct(vix));
        {
          if ( u4_n_eq(u4_axis_2, u4_op_tip(axis)) ) {
            u4_axis axis_tap = u4_op_tap(wir_r, axis);

            return u4_kc(wir_r, u4_kc(wir_r, axis_tap, tool), belt_l);
          }
          else return belt_l;
        }
      }
    }

    /* _lily_hike_belt_r(): factor (vix) right.
    */
    static u4_log
    _lily_hike_belt_r(u2_ray  wir_r,
                      u4_list vix)
    {
      if ( (u2_nul == vix) ) {
        return u4_nul;
      }
      else {
        u4_axis axis       = u4_ch(u4_ch(vix));
        u4_tool tool       = u4_ct(u4_ch(vix));
        u4_list belt_r = _lily_hike_belt_r(wir_r, u4_ct(vix));
        {
          if ( u4_n_eq(u4_axis_3, u4_op_tip(axis)) ) {
            u4_axis axis_tap = u4_op_tap(wir_r, axis);

            return u4_kc(wir_r, u4_kc(wir_r, axis_tap, tool), belt_r);
          }
          else return belt_r;
        }
      }
    }
  u4_tool
  _lily_hike(u2_ray  wir_r,
             u4_axis axe,
             u4_list vix)  /* (axis tool) */
  {
    

    if ( (u2_nul == vix) ) {
      return u4_kc(wir_r, u4_nock_frag, axe);
    }
    else {
      u4_list log_tool    = _lily_hike_belt_root(wir_r, vix);
      u4_list belt_l  = _lily_hike_belt_l(wir_r, vix);
      u4_list belt_r  = _lily_hike_belt_r(wir_r, vix);

      if ( !(u2_nul == log_tool) ) {
        return u4_ch(log_tool);
      }
      else {
        u4_tool tool_l, tool_r;
        
        tool_l = _lily_hike(wir_r, _lily_hike_axis_l(wir_r, axe), belt_l);
        tool_r = _lily_hike(wir_r, _lily_hike_axis_r(wir_r, axe), belt_r);

        return _lily_cons(wir_r, tool_l, tool_r);
      }
    }
  }

/****   _open: macro expansion.
****/
#define _open_p(stem) \
  if ( u4_b_p(gen, u4_atom_##stem, &p_gen) ) { \
    return _open_in_##stem(wir_r, p_gen); \
  }

#define _open_pq(stem) \
  if ( u4_b_pq(gen, u4_atom_##stem, &p_gen, &q_gen) ) { \
    return _open_in_##stem(wir_r, p_gen, q_gen); \
  }

#define _open_pqr(stem) \
  if ( u4_b_pqr(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen) ) {\
    return _open_in_##stem(wir_r, p_gen, q_gen, r_gen); \
  }

#define _open_pqrs(stem) \
  if ( u4_b_pqrs(gen, u4_atom_##stem, &p_gen, &q_gen, &r_gen, &s_gen) ) {\
    return _open_in_##stem(wir_r, p_gen, q_gen, r_gen, s_gen); \
  }

#define _open_do_p(stem)  \
  static u4_gene _open_in_##stem \
    (u2_ray  wir_r, u4_noun p_gen)

#define _open_do_pq(stem)  \
  static u4_gene _open_in_##stem \
    (u2_ray  wir_r, u4_noun p_gen, u4_noun q_gen)

#define _open_do_pqr(stem)  \
  static u4_gene _open_in_##stem \
    (u2_ray  wir_r, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen)

#define _open_do_pqrs(stem)  \
  static u4_gene _open_in_##stem \
    (u2_ray  wir_r, u4_noun p_gen, u4_noun q_gen, u4_noun r_gen, u4_noun s_gen)

  /* mast:open:plow
  */
    static u4_gene
    _open_mast(u4_plow, u4_gene);

    static u4_gene 
    _open_mast_fix(u2_ray  wir_r,
                   u4_gene gen,
                   u4_axis axe)
    {
      
      u4_noun p_gen, q_gen;

      if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return _open_mast_fix(wir_r, p_gen, axe);
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return u4_kt
          (wir_r, 
           u4_atom_twix,
           _open_mast_fix(wir_r, p_gen, u4_op_peg(wir_r, axe, u4_axis_2)),
           _open_mast_fix(wir_r, q_gen, u4_op_peg(wir_r, axe, u4_axis_3)));
      }
      else if ( u4_b_pq(gen, u4_atom_velt, &p_gen, &q_gen) ) {
        u4_tool ryx = u4_kc(wir_r, u4_atom_frag, axe);

        return u4_kt
          (wir_r, 
           u4_atom_flac,
           u4_kt(wir_r, 
                 u4_atom_mack, 
                 u4_blip,
                 u4_kl
                  (wir_r,
                   u4_kc
                    (wir_r, 
                     ryx,
                     u4_kq
                      (wir_r, u4_atom_fung, _open_mast(wir_r, q_gen), ryx, u4_nul)))),
           _open_mast_fix(wir_r, p_gen, axe));
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return u4_kt
          (wir_r, u4_atom_bran, p_gen, _open_mast_fix(wir_r, q_gen, axe));
      }
      else if ( u4_b_p(gen, u4_atom_teck, &p_gen) ) {
        return u4_kq
          (wir_r, u4_atom_fung,
                p_gen,
                u4_kc(wir_r, u4_atom_frag, axe),
                u4_nul);
      }
      else if ( u4_b_pq(gen, u4_atom_pock, &p_gen, &q_gen) ) {
        return _open_mast_fix(wir_r, q_gen, axe);
      } 
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        return u4_kt(wir_r, u4_atom_zemp, p_gen, _open_mast_fix(wir_r, q_gen, axe));
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        return u4_kc(wir_r, u4_atom_zush, _open_mast_fix(wir_r, p_gen, axe));
      }
      else {
        u4_gene bog = _plow_open(wir_r, gen);

        if ( !u4_n_eq(gen, bog) ) {
          return _open_mast_fix(wir_r, bog, axe);
        }
        else {
          u4_tool ryx = u4_kc(wir_r, u4_atom_frag, axe);

          return u4_kt
            (wir_r,
             u4_atom_gram, 
             u4_kt(wir_r, u4_atom_plin, gen, ryx), 
             ryx);
        }
      }
    }
  static u4_gene
  _open_mast(u2_ray  wir_r,
             u4_gene gen)
  {
    
    u4_noun p_gen, q_gen;

    if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return u4_kt
        (wir_r,
         u4_atom_gant,
         u4_kt(wir_r, u4_atom_wost, u4_atom_mave, q_gen),
         u4_kt(wir_r, u4_atom_lome, u4_nul, _open_mast_fix(wir_r, p_gen, u4_axis_4)));
    }
    else if ( u4_b_pq(gen, u4_atom_pock, &p_gen, &q_gen) ) {
      return _open_mast(wir_r, q_gen);
    }
    else if ( u4_b_p(gen, u4_atom_teck, &p_gen) ) {
      return p_gen;
    }
    else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
      return u4_kt(wir_r, u4_atom_zemp, p_gen, _open_mast(wir_r, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
      return u4_kc(wir_r, u4_atom_zush, _open_mast(wir_r, p_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_velt, &p_gen, &q_gen) ) {
      u4_tool ryx = u4_kc(wir_r, u4_atom_frag, u4_axis_4);

      return u4_kt
        (wir_r,
         u4_atom_gant,
         u4_kt(wir_r, u4_atom_wost, u4_atom_mave, q_gen),
         u4_kt
          (wir_r,
           u4_atom_lome,
           u4_nul,
           u4_kt
            (wir_r, 
             u4_atom_flac,
              u4_kt
                (wir_r,
                 u4_atom_mack,
                 u4_blip,
                 u4_kl
                  (wir_r,
                   u4_kc
                    (wir_r, 
                     ryx,
                     u4_kq
                      (wir_r, u4_atom_fung, _open_mast(wir_r, q_gen), ryx, u4_nul)))),
             _open_mast_fix(wir_r, p_gen, u4_axis_4))));
    }
    else {
      u4_gene bog = _plow_open(wir_r, gen);

      if ( !u4_n_eq(gen, bog) ) {
        return _open_mast(wir_r, bog);
      }
      else {
        return u4_kt
          (wir_r,
           u4_atom_gant,
           u4_kt(wir_r, u4_atom_wost, u4_atom_mave, gen),
           u4_kt(wir_r, u4_atom_lome, u4_nul, _open_mast_fix(wir_r, gen, u4_axis_4)));
      }
    }
  }

  /* fist:open:plow
  */
    static u4_gene
    _open_fist(u4_plow, u4_gene);

    static u4_list
    _open_fist_a(u2_ray  wir_r,
                 u4_bank ban)
    {
      

      if ( (u2_nul == ban) ) {
        return u4_nul;
      }
      else {
        return u4_kc
          (wir_r, _open_fist(wir_r, u4_ch(ban)), _open_fist_a(wir_r, u4_ct(ban)));
      }
    }
  static u4_gene
  _open_fist(u2_ray  wir_r,
             u4_gene gen)
  {
    
    u4_noun p_gen, q_gen;

    if ( u4_b_p(gen, u4_atom_bean, &p_gen) ) {
      return gen;
    }
    else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return u4_kt
        (wir_r, u4_atom_cast, p_gen, _open_fist(wir_r, q_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
      return u4_kt
        (wir_r, u4_atom_twix, _open_fist(wir_r, p_gen), _open_fist(wir_r, q_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_velt, &p_gen, &q_gen) ) {
      return u4_kt
        (wir_r, u4_atom_velt, _open_fist(wir_r, p_gen), _open_fist(wir_r, q_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
      return u4_kt
        (wir_r, u4_atom_zemp, p_gen, _open_fist(wir_r, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
      return u4_kc
        (wir_r, u4_atom_zush, _open_fist(wir_r, p_gen));
    }
    else if ( u4_b_p(gen, u4_atom_fist, &p_gen) ) {
      return _open_fist(wir_r, p_gen);
    }
    else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
      return u4_kt
        (wir_r, u4_atom_bran, p_gen, _open_fist(wir_r, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_teck, &p_gen) ) {
      u4_noun pp_gen;

      if ( u4_b_p(p_gen, u4_atom_rond, &pp_gen) ) {
        return u4_kt(wir_r, u4_atom_teck, u4_atom_rond, _open_fist_a(wir_r, pp_gen));
      }
      else {
        return u4_kc(wir_r, u4_atom_bean, u4_atom_blur);
      }
    }
    else if ( u4_b_pq(gen, u4_atom_pock, &p_gen, &q_gen) ) {
      return _open_fist(wir_r, p_gen);
    }
    else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
      return gen;
    }
    else {
      u4_gene bog = _plow_open(wir_r, gen);

      if ( !u4_n_eq(gen, bog) ) {
        return _open_fist(wir_r, bog);
      }
      else {
        return u4_kc(wir_r, u4_atom_bean, u4_atom_blur);
      }
    }
  }

  _open_do_p(bean)
  {
    

    if ( u4_n_eq(u4_atom_atom, p_gen) ) {
      return u4_kt
        (wir_r, u4_atom_cast, 
              u4_kt(wir_r, u4_atom_vint, u4_atom_bone, u4_math_0),
              u4_kc(wir_r, u4_atom_bone, u4_math_0));
    }
    else if ( u4_n_eq(u4_atom_blur, p_gen) ) {
      u4_noun dud = u4_kc(wir_r, u4_atom_bone, u4_nul);

      return u4_kt
        (wir_r, u4_atom_cast, 
              u4_kt(wir_r, u4_atom_sail, dud, dud),
              dud);
    }
    else if ( u4_n_eq(u4_atom_cell, p_gen) ) {
      return u4_kt
        (wir_r, u4_atom_twix,
              u4_kc(wir_r, u4_atom_bean, u4_atom_blur),
              u4_kc(wir_r, u4_atom_bean, u4_atom_blur));
    }
    else if ( u4_n_eq(u4_atom_flag, p_gen) ) {
      return u4_kt
        (wir_r, u4_atom_cast,
              u4_kt(wir_r, u4_atom_dust, u4_atom_bone, u4_math_0),
              u4_kc(wir_r, u4_atom_bone, u4_yes));
    }
    else if ( u4_n_eq(u4_atom_null, p_gen) ) {
        return u4_kc(wir_r, u4_atom_bone, u4_nul);
    }
    else return u4_trip;
  }

  _open_do_pq(lonk)
  {
    
    u4_noun beg = u4_kc(wir_r, u4_atom_frag, u4_axis_4);

    if ( (u2_nul == q_gen) ) {
      return _plow_fail(wir_r, "lonk");
    }
    else {
      u4_noun iq_gen = u4_ch(q_gen);
      u4_noun tq_gen = u4_ct(q_gen);

      if ( (u2_nul == tq_gen) ) {
        return iq_gen;
      }
      else {
        return u4_kt
          (wir_r,
           u4_atom_gant,
           _open_in_lonk(wir_r, p_gen, tq_gen),
           u4_kt
            (wir_r,
             u4_atom_gant,
             u4_kt(wir_r, u4_atom_flac,
                        u4_kc(wir_r, u4_atom_frag, u4_axis_3),
                        iq_gen),
             u4_kt
              (wir_r, 
               u4_atom_gant,
               u4_kc(wir_r, u4_atom_frag, u4_axis_8), 
               u4_kt
                (wir_r,
                 u4_atom_sunt,
                 u4_nul,
                 u4_kq
                  (wir_r,
                   u4_atom_bung,
                   u4_kt(wir_r,
                         u4_atom_flac,
                         u4_kc(wir_r, u4_atom_frag, u4_cod_in(23)),
                         p_gen),
                   u4_kq
                    (wir_r,
                     u4_atom_fung,
                     u4_kc(wir_r, u4_atom_frag, u4_axis_10),
                     beg,
                     u4_nul),
                  u4_kt
                    (wir_r,
                     u4_atom_mack,
                     u4_kc(wir_r, 
                           u4_kc(wir_r, u4_atom_frag, u4_cod_in(22)), 
                           u4_nul),
                     u4_kc
                      (wir_r,
                       u4_kc(wir_r, beg, beg),
                       u4_nul)))))));
      }
    }
  }

    static u4_noun
    _gath_a(u2_ray  wir_r,
            u4_noun r_gen)
    {
      if ( (u2_nul == r_gen) ) {
        return u4_nul;
      } 
      else {
        u4_noun ir_gen = u4_ch(r_gen);
        u4_noun tr_gen = u4_ct(r_gen);
        u4_noun pir_gen = u4_ch(ir_gen);
        u4_noun qir_gen = u4_ct(ir_gen);

        return u4_kc
          (wir_r, u4_kc(wir_r, pir_gen, 
                           u4_kt(wir_r, u4_atom_flac, 
                                      u4_kc(wir_r, u4_atom_frag, u4_axis_3),
                                      qir_gen)),
               _gath_a(wir_r, tr_gen));
      }
    }
  _open_do_pqr(gath)
  {
    

    return u4_kt
      (wir_r, u4_atom_gant,
            q_gen,
            u4_kt
              (wir_r,
               u4_atom_mack,
               u4_kc(wir_r, u4_kc(wir_r, u4_atom_frag, u4_axis_2), p_gen),
               _gath_a(wir_r, r_gen)));
  }
  _open_do_p(prex)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u4_kc(wir_r, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      if ( (u2_nul == tp_gen) ) {
        return ip_gen;
      } else {
        return u4_kt
          (wir_r, u4_atom_twix, ip_gen, _open_in_prex(wir_r, tp_gen));
      }
    }
  }
 
  _open_do_pq(fung)
  {
    

    if ( (u2_nul == q_gen) ) {
      return u4_kt
        (wir_r, u4_atom_flac, 
              p_gen,
              u4_kc(wir_r, u4_atom_pane, u4_blip));
    } else {
      return u4_kq(wir_r, u4_atom_mung, p_gen, u4_atom_prex, q_gen);
    }
  }

  _open_do_pqr(hang)
  {
    

    return u4_kq
      (wir_r, u4_atom_gath,
            p_gen,
            q_gen,
            u4_kl(wir_r,
                  u4_kc(wir_r,
                        u4_kc(wir_r, u4_atom_frag, u4_axis_4),
                        r_gen)));
  }

  _open_do_pq(mung)
  {
    

    return u4_kq
      (wir_r, u4_atom_gath,
            u4_kc(wir_r, u4_blip, u4_nul),
            p_gen,
            u4_kl(wir_r,
                  u4_kc(wir_r,
                        u4_kc(wir_r, u4_atom_frag, u4_axis_4),
                        q_gen)));
  }

  _open_do_pq(velt)
  {
    

    return u4_kt
      (wir_r, u4_atom_gant,
            q_gen,
            u4_kt
              (wir_r, u4_atom_grel,
                    u4_kc(wir_r, u4_atom_frag, u4_axis_2),
                    u4_kl(wir_r,
                          u4_kc(wir_r,
                                u4_kt(wir_r, u4_atom_flac,
                                           u4_kc(wir_r, u4_atom_frag, u4_axis_3),
                                           q_gen),
                                u4_kc(wir_r, u4_atom_frag, u4_axis_2)))));
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
    

    return u4_kq
      (wir_r, u4_atom_trol,
            p_gen,
            u4_kc(wir_r, u4_atom_zike, u4_nul),
            q_gen);
  }

  _open_do_p(vern)
  {
    

    return u4_kq
      (wir_r, u4_atom_trol,
            p_gen,
            u4_kc(wir_r, u4_atom_bone, u4_no),
            u4_kc(wir_r, u4_atom_bone, u4_yes));
  }

  _open_do_p(slax)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u4_kc(wir_r, u4_atom_bone, u4_nul);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      return u4_kt(wir_r, u4_atom_twix, ip_gen, _open_in_slax(wir_r, tp_gen));
    }
  }

  _open_do_p(frag)
  {
    

    return u4_kt
      (wir_r, u4_atom_mack, 
            u4_kc(wir_r, u4_kc(wir_r, u4_atom_frag, p_gen), u4_nul),
            u4_nul);
  }

  _open_do_p(fist)
  {
    return _open_fist(wir_r, p_gen);
  }

  _open_do_pq(lome)
  {
    

    return u4_kt
      (wir_r, u4_atom_pank,
            p_gen,
            u4_kl(wir_r, u4_kc(wir_r, u4_blip, q_gen)));
  }

  _open_do_pq(gnum)
  {
    

    return u4_kt
      (wir_r, u4_atom_fung, q_gen, u4_kc(wir_r, p_gen, u4_nul));
  }

  _open_do_pqr(bung)
  {
    

    return u4_kc
      (wir_r, u4_atom_fung, 
            u4_kq(wir_r, p_gen, q_gen, r_gen, u4_nul));
  }

  _open_do_pq(claf)
  {
    

    return u4_kt(wir_r, u4_atom_flac, q_gen, p_gen);
  }

  _open_do_pqr(lort)
  {
    

    return u4_kq(wir_r, u4_atom_trol, p_gen, r_gen, q_gen);
  }

  _open_do_pq(vamp)
  {
    

    return u4_kt
      (wir_r, u4_atom_flac,
            u4_kt(wir_r, u4_atom_lome, p_gen, q_gen),
            u4_kc(wir_r, u4_atom_pane, u4_blip));
  }

  _open_do_p(zole)
  {
    

    return u4_kc(wir_r, u4_atom_bone, p_gen);
  }

  _open_do_pq(moze)
  {
    

    if ( (u2_nul == q_gen) ) {
      return u4_kc(wir_r, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun iq_gen = u4_ch(q_gen);
      u4_noun tq_gen = u4_ct(q_gen);

#if 0
      if ( !(u2_nul == p->bug) ) {
        u4_err(wir_r, "moze: iq_gen", iq_gen);
        u4_err(wir_r, "moze: fist", _open_fist(wir_r, iq_gen));
        u4_err(wir_r, "moze: mast", _open_mast(wir_r, iq_gen));
        printf("\n");
      }
#endif
      return u4_kq
        (wir_r,
         u4_atom_trol,
         u4_kt(wir_r, u4_atom_plin, _open_fist(wir_r, iq_gen), p_gen),
         u4_kq(wir_r, u4_atom_fung, _open_mast(wir_r, iq_gen), p_gen, u4_nul),
         _open_in_moze(wir_r, p_gen, tq_gen));
    }
  }

  _open_do_p(rond)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u4_kc(wir_r, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);

      return u4_kt
        (wir_r,
         u4_atom_gant,
         u4_kc(wir_r, u4_atom_mave, ip_gen),
         u4_kt(wir_r, u4_atom_lome,
                    u4_nul,
                    u4_kt(wir_r, u4_atom_moze, 
                               u4_kc(wir_r, u4_atom_frag, u4_axis_4),
                               p_gen)));
    }
  }

  _open_do_pq(frit)
  {
    

    return u4_kt
      (wir_r, u4_atom_gant,
            p_gen,
            u4_kt
              (wir_r,
               u4_atom_mack,
               u4_kl(wir_r, u4_kc(wir_r, u4_atom_frag, u4_axis_2)),
               u4_kl(wir_r,
                     u4_kc(wir_r,
                           u4_kc(wir_r, u4_atom_frag, u4_axis_4),
                           u4_kt(wir_r, u4_atom_flac, 
                                      u4_kc(wir_r, u4_atom_frag, u4_axis_3),
                                      q_gen)))));
  }

  _open_do_p(pane)
  {
    

    return u4_kt
      (wir_r, u4_atom_mack, 
            u4_kc(wir_r, u4_kc(wir_r, u4_atom_pane, p_gen), u4_nul),
            u4_nul);
  }

  _open_do_pq(tang)
  {
    

    return u4_kt
      (wir_r, u4_atom_gant, q_gen, p_gen);
  }

  _open_do_p(teck)
  {
    

    return u4_kc
      (wir_r, u4_atom_wost,
            u4_kt(wir_r, u4_atom_flac,
                       p_gen,
                       u4_kt(wir_r, u4_atom_mack, 
                                  u4_kl(wir_r, u4_kc(wir_r, u4_atom_pane, u4_blip)),
                                  u4_nul)));
  }

  _open_do_pq(gant)
  {
    

    return u4_kt
      (wir_r, u4_atom_flac,
            u4_kt(wir_r, u4_atom_twix, 
                       p_gen, 
                       u4_kc(wir_r, u4_atom_frag, u4_axis_1)),
            q_gen);
  }

  _open_do_pqrs(quax)
  {
    

    return u4_kt
      (wir_r, u4_atom_twix,
            p_gen,
            u4_kt
              (wir_r, u4_atom_twix,
                    q_gen,
                    u4_kt(wir_r, u4_atom_twix, r_gen, s_gen)));
  }

  _open_do_p(chan)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u4_kc(wir_r, u4_atom_bone, u4_yes);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      return u4_kq
        (wir_r, u4_atom_trol,
              ip_gen,
              _open_in_chan(wir_r, tp_gen),
              u4_kc(wir_r, u4_atom_bone, u4_no));
    }
  }

  _open_do_pq(grel)
  {
    

    if ( (u2_nul == q_gen) ) {
      return u4_kc(wir_r, u4_atom_zike, u4_nul);
    }
    else {
      u4_noun iq_gen = u4_ch(q_gen);
      u4_noun tq_gen = u4_ct(q_gen);
      u4_noun piq_gen = u4_ch(iq_gen);
      u4_noun qiq_gen = u4_ct(iq_gen);

      return u4_kq
        (wir_r, 
         u4_atom_trol,
         u4_kt(wir_r, u4_atom_plin, _open_fist(wir_r, piq_gen), p_gen),
         u4_kt
          (wir_r, u4_atom_flac,
                u4_kt(wir_r,
                      u4_atom_stil,
                      piq_gen,
                      p_gen),
                qiq_gen),
         _open_in_grel(wir_r, p_gen, tq_gen));
    }
  }

  _open_do_pq(sunt)
  {
    

    return u4_kq
      (wir_r, u4_atom_tash, 
            p_gen,
            u4_kc(wir_r, u4_blip, q_gen),
            u4_nul);
  }

  _open_do_pq(pock)
  {
    
    u4_noun rax = u4_kc(wir_r, u4_atom_frag, u4_axis_2);

    return u4_kt
      (wir_r,
       u4_atom_gant,
       q_gen, 
       u4_kt
        (wir_r,
         u4_atom_claf,
         rax,
         u4_kt(wir_r,
               u4_atom_stil,
               u4_kt(wir_r, 
                     u4_atom_flac, 
                     u4_kc(wir_r, u4_atom_frag, u4_axis_3), 
                     p_gen),
               rax)));
  }

  _open_do_p(dorn)
  {
    

    if ( (u2_nul == p_gen) ) {
      return u4_kc(wir_r, u4_atom_bone, u4_no);
    }
    else {
      u4_noun ip_gen = u4_ch(p_gen);
      u4_noun tp_gen = u4_ct(p_gen);

      return u4_kq
        (wir_r, u4_atom_trol,
              ip_gen,
              u4_kc(wir_r, u4_atom_bone, u4_yes),
              _open_in_dorn(wir_r, tp_gen));
    }
  }

  _open_do_pq(zemp)
  {
    return q_gen;
  }

  _open_do_pqr(fent)
  {
    

    return u4_kt
      (wir_r,
       u4_atom_grel,
       p_gen,
       u4_kt
        (wir_r,
         u4_kc(wir_r, u4_kc(wir_r, u4_atom_bone, u4_nul), q_gen),
         u4_kc(wir_r, u4_kc(wir_r, u4_atom_bean, u4_atom_cell), r_gen),
         u4_nul));
  }

  _open_do_pq(gram)
  {
    
    
    return u4_kq
      (wir_r, u4_atom_trol, p_gen, q_gen, u4_kc(wir_r, u4_atom_zike, u4_nul));
  }

  _open_do_pqr(trex)
  {
    

    return u4_kt
      (wir_r, u4_atom_twix,
            p_gen,
            u4_kt(wir_r, u4_atom_twix, q_gen, r_gen));
  }

  _open_do_pqrs(tung)
  {
    

    return u4_kq
      (wir_r, u4_atom_fung, 
            p_gen, 
            q_gen,
            u4_kt(wir_r, r_gen, s_gen, u4_nul));
  }

  _open_do_p(mave)
  {
    

    return u4_kt
      (wir_r, u4_atom_cast, 
            u4_kc(wir_r, u4_atom_bean, u4_atom_blur),
            p_gen);
  }

  _open_do_pq(yell)
  {
    

    return u4_kt(wir_r, u4_atom_fung, p_gen, q_gen);
  }

  /* open:plow
  */
    static u4_gene
    _plow_open_main(u2_ray  wir_r,
                    u4_gene gen)
    {
      u4_noun p_gen, q_gen, r_gen, s_gen;

      if ( u4_b_fork(gen, &p_gen, &q_gen) ) {
        u4_err(p->wir_r, "gen", gen);
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
  u4_gene
  _plow_open(u2_ray  wir_r,
             u4_gene gen)
  {
    u4_nopt zax = u2_fj_book_get(gen, p->pon);

    if ( u4_bull != zax ) {
      return zax;
    }
    else {
      zax = _plow_open_main(wir_r, gen);

#if 0
      if ( !(u2_nul == p->bug) && u4_b_p(gen, u4_atom_teck, 0) ) {
        u4_err(p->wir_r, "open: gen", gen);
        u4_err(p->wir_r, "open: zax", zax);
        printf("\n");
      }
#endif
      p->pon = u2_fj_book_add(p->wir_r, gen, zax, p->pon);
      return zax;
    }
  }

/****   _gull: battery symbol table.
****/
  /* size:gull:plow
  */
  u4_atom
  _gull_size(u2_ray  wir_r,
             u4_book dab)
  {
    if ( (u2_nul == dab) ) {
      return u4_noun_0;
    } else {
      u4_noun n_dab, l_dab, r_dab;

      u4_c_trel(dab, &n_dab, &l_dab, &r_dab);

      return u4_op_inc(wir_r, u4_op_add(wir_r, _gull_size(wir_r, l_dab),
                                           _gull_size(wir_r, r_dab)));
    }
  }

  /* fill:gull:plow
  */
  u4_spec
  _gull_fill(u2_ray  wir_r,
             u4_book dab,
             u4_menu sem)
  {
    return u2_fj_book_add_list(wir_r, sem, dab);
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
    _gull_look_a(u2_ray  wir_r,
                 u4_spec dab,
                 u4_term cog,
                 u4_axis axe)
    {
      

      if ( (u2_nul == dab) ) {
        return u4_nul;
      }
      else {
        u4_noun n_dab, l_dab, r_dab, pn_dab, qn_dab;

        u4_c_trel(dab, &n_dab, &l_dab, &r_dab);
        pn_dab = u4_ch(n_dab);
        qn_dab = u4_ct(n_dab);

        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(wir_r, u4_nul, axe, qn_dab);
          }
          else return u4_nul;
        }
        else if ( (u2_nul == l_dab) ) {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(wir_r, u4_nul, u4_op_peg(wir_r, axe, u4_noun_2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return u4_nul;
          }
          else {
            return _gull_look_a(wir_r, r_dab, cog, u4_op_peg(wir_r, axe, u4_noun_3));
          }
        }
        else if ( (u2_nul == r_dab) ) {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(wir_r, u4_nul, u4_op_peg(wir_r, axe, u4_noun_2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return _gull_look_a(wir_r, l_dab, cog, u4_op_peg(wir_r, axe, u4_noun_3));
          }
          else {
            return u4_nul;
          }
        }
        else {
          if ( u4_n_eq(cog, pn_dab) ) {
            return u4_kt(wir_r, u4_nul, u4_op_peg(wir_r, axe, u4_noun_2), qn_dab);
          }
          else if ( _ord_tag_tree(cog, pn_dab) ) {
            return _gull_look_a(wir_r, l_dab, cog, u4_op_peg(wir_r, axe, u4_noun_6));
          }
          else {
            return _gull_look_a(wir_r, r_dab, cog, u4_op_peg(wir_r, axe, u4_noun_7));
          }
        }
      }
    }
  u4_unit
  _gull_look(u2_ray  wir_r,
             u4_spec dab,
             u4_term cog)
  {
    return _gull_look_a(wir_r, dab, cog, u4_axis_1);
  }


/****   _iris: type system core.
****/
  /* burn:iris:rose:plow
  */
    static u4_type
    _iris_burn_sint(u4_plow, u4_type, u4_rail, u4_axis, u4_tack);

    static u4_type
    _iris_burn_dext(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_tack tac)
    {
      
      u4_noun p_tac, q_tac;
      u4_noun p_sut, q_sut, qrs_sut;

      if ( (u2_nul == tac) ) {
        return sut;
      }
      else if ( u4_b_p(tac, u4_atom_leaf, &p_tac) ) {
        return _iris_snap(wir_r, sut, bar, axe, p_tac);
      }
      else if ( u4_b_pq(tac, u4_atom_bran, &p_tac, &q_tac) ) {
        if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
          if ( u4_n_eq(p_sut, p_tac) ) {
            return u4_kt
              (wir_r, 
               u4_atom_face, 
               p_tac, 
               _iris_burn_dext(wir_r, q_sut, bar, axe, q_tac));
          }
          else {
            return u4_kt
              (wir_r,
               u4_atom_face,
               p_tac,
               _iris_burn_dext(wir_r, sut, bar, axe, q_tac));
          }
        }
        else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) )
        {
          return _iris_burn_sint(wir_r, sut, bar, axe, tac);
        }
        else {
          return u4_kt
            (wir_r,
             u4_atom_face,
             p_tac,
             _iris_burn_dext(wir_r, sut, bar, axe, q_tac));
        }
      }
      else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
        if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
          u4_noun l_sut, l_bar, l_axe;
          u4_noun r_sut, r_bar, r_axe;

          l_sut = sut; l_bar = bar; l_axe = axe;
          _iris_slip(wir_r, &l_sut, &l_bar, &l_axe, u4_axis_2);

          r_sut = sut; r_bar = bar; r_axe = axe;
          _iris_slip(wir_r, &r_sut, &r_bar, &r_axe, u4_axis_3);

          return u4_kt
            (wir_r,
             u4_atom_cell,
             _iris_burn_dext(wir_r, l_sut, l_bar, l_axe, p_tac),
             _iris_burn_dext(wir_r, r_sut, r_bar, r_axe, q_tac));
        }
        else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &qrs_sut) ) {
          u4_noun l_sut, l_bar, l_axe;
          u4_type ham;

          l_sut = sut; l_bar = bar; l_axe = axe;
          _iris_slip(wir_r, &l_sut, &l_bar, &l_axe, u4_axis_2);

          ham = _iris_burn_dext(wir_r, l_sut, l_bar, l_axe, p_tac);

          if ( (u2_nul == q_tac) ) {
            return u4_k_trel
              (wir_r, u4_atom_core, ham, qrs_sut);
          } else {
            return u4_k_trel
              (wir_r, u4_atom_cell, ham, u4_atom_blur);
          }
        }
        else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ||
                  u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) )
        {
          return _iris_burn_sint(wir_r, sut, bar, axe, tac);
        }
        else {
          u4_noun poq = u4_kt
            (wir_r,
             u4_atom_cell,
             _iris_half(wir_r, sut, bar, axe, u4_axis_2),
             _iris_half(wir_r, sut, bar, axe, u4_axis_3));

          return _iris_burn_dext(wir_r, poq, bar, axe, tac);
        }
      }
      else return u4_trip;
    }
    static u4_unit
    _iris_burn_swim(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_tack tac)
    {
      
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit yop = _iris_burn_swim(wir_r, p_sut, bar, axe, tac);
        u4_unit paf = _iris_burn_swim(wir_r, q_sut, bar, axe, tac);

        if ( (u2_nul == yop) ) {
          return paf;
        } else if ( (u2_nul == paf) ) {
          return yop;
        }
        else {
          return u4_kc
            (wir_r,
             u4_nul,
             _rose_eith(wir_r, u4_ct(yop), u4_ct(paf)));
        }
      }
      else {
        if ( u4_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u4_nul;
        }
        else {
          return u4_kc
            (wir_r, u4_nul, _iris_burn_dext(wir_r, sut, bar, axe, tac));
        }
      }
    }
    static u4_type
    _iris_burn_sint(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_tack tac)
    {
      
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return u4_kt
          (wir_r, 
           u4_atom_face,
           p_sut,
           _iris_burn_dext(wir_r, q_sut, bar, axe, tac));
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_ct(_iris_burn_swim(wir_r, sut, bar, axe, tac));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _rose_both
          (wir_r, 
           _iris_burn_dext(wir_r, q_sut, u4_kc(wir_r, p_sut, bar), axe, tac),
           _iris_burn_dext(wir_r, p_sut, bar, axe, tac));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        return _iris_burn_dext
          (wir_r, _rose_repo(wir_r, p_sut, q_sut), bar, axe, tac); 
      }
      else return u4_trip;
    }
  u4_type
  _iris_burn(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_tack tac)
  {
    return _iris_burn_dext(wir_r, sut, bar, axe, tac);
  }

  /* cull:iris:rose:plow
  */
    static u4_flag
    _iris_cull_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_rail bar,
                 u4_axis axe)
    {
      if ( (u2_nul == bar) ) {
        return u4_no;
      }
      else if ( u4_so(_rose_orth(wir_r, sut, u4_ch(bar))) ) {
        return u4_yes;
      }
      else return _iris_cull_a(wir_r, sut, u4_ct(bar), axe);
    }
  u4_flag
  _iris_cull(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe)
  {
    if ( u4_so(_rose_null(wir_r, sut)) ) {
      return u4_yes;
    }
    else {
      return _iris_cull_a(wir_r, sut, bar, axe);
    }
  }

  /* find:iris:rose:plow
  */
    static u4_unit _iris_find_main
      (u4_plow, u4_type, u4_rail, u4_axis, u4_pool, u4_term);

    static u4_unit
    _iris_find_half(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_term cog,
                    u4_axis cap)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, cap);

      return _iris_find_main(wir_r, sut, bar, axe, gil, cog);
    }
    static u4_unit
    _iris_find_swim(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_term cog)
    {
      
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit yop = _iris_find_swim(wir_r, p_sut, bar, axe, gil, cog);
        u4_unit paf = _iris_find_swim(wir_r, q_sut, bar, axe, gil, cog);

        if ( (u2_nul == yop) ) {
          return paf;
        }
        else if ( (u2_nul == paf) ) {
          return yop;
        }
        else {
          u4_unit lep = u4_ct(yop);
          u4_unit gam = u4_ct(paf);
          
          if ( (u2_nul == lep) ) {
            if ( (u2_nul == gam) ) {
              return u4_nul;
            }
            else {
              u4_burp(wir_r, "cog", u4_prep_textual(wir_r, cog));
              return _plow_fail(wir_r, "fork conflict a");
            }
          }
          else if ( (u2_nul == gam) ) {
            return _plow_fail(wir_r, "fork conflict b");
          }
          else {
            u4_plan u_lep = u4_ct(lep);
            u4_plan u_gam = u4_ct(gam);

            if ( u4_n_eq(u4_ch(u_lep), u4_ch(u_gam)) &&
                 u4_n_eq(u4_ch(u4_ct(u_lep)), u4_ch(u4_ct(u_gam))) )
            {
              return u4_kt
                (wir_r,
                 u4_nul,
                 u4_nul,
                 u4_kt
                  (wir_r, 
                   u4_ch(u_lep),
                   u4_ch(u4_ct(u_lep)),
                   _rose_eith(wir_r, u4_ct(u4_ct(u_lep)), u4_ct(u4_ct(u_gam)))));
            }
            else {
              u4_burp(wir_r, "cog", u4_prep_textual(wir_r, cog));
              return _plow_fail(wir_r, "fork conflict c");
            }
          }
        }
      }
      else {
        if ( u4_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u4_nul;
        }
        else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) &&
                  u2_fj_pool_in(u4_kc(wir_r, bar, sut), gil) )
        {
          return u4_nul;
        }
        else {
          return u4_kc
            (wir_r, u4_nul, _iris_find_main(wir_r, sut, bar, axe, gil, cog));
        }
      }
    }
    static u4_unit
    _iris_find_main_a(u2_ray  wir_r,
                      u4_type sut,
                      u4_rail bar,
                      u4_axis axe,
                      u4_pool gil,
                      u4_term cog)
    {
      
      u4_noun p_sut, q_sut, r_sut, s_sut;

      if ( u4_n_eq(u4_atom_atom, sut) ||
           u4_n_eq(u4_atom_blur, sut) ||
           u4_n_eq(u4_atom_blot, sut) ||
           u4_b_p(sut, u4_atom_cube, &p_sut) )
      {
        return u4_nul;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        u4_unit taf = _iris_find_half(wir_r, sut, bar, axe, gil, cog, u4_axis_2);
        u4_unit bov = _iris_find_half(wir_r, sut, bar, axe, gil, cog, u4_axis_3);

        if ( (u2_nul == taf) ) {
          return bov;
        }
        else if ( (u2_nul == bov) ) {
          return taf;
        }
        else {
#if 0
          u4_burp(wir_r, "cog", u4_prep_textual(wir_r, cog));
          return _plow_fail(wir_r, "cell conflict");
#else
          return taf;
#endif
        }
      }
      else if ( u4_b_pqrs(sut, u4_atom_core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
        u4_spec dab = s_sut;
        u4_unit zem;

        zem = _gull_look(wir_r, dab, cog);
        if ( (u2_nul == zem) ) {
          return _iris_find_half(wir_r, sut, bar, axe, gil, cog, u4_axis_2);
        }
        else return 
          u4_kc
            (wir_r, 
             u4_nul, 
             u4_kt
              (wir_r, 
               axe, 
               u4_kq
                (wir_r, 
                 u4_nul, 
                 u4_op_peg(wir_r, u4_axis_3, u4_ch(u4_ct(zem))),
                 sut,
                 u4_ct(u4_ct(zem))),
               sut));
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        if ( u4_n_eq(cog, p_sut) ) {
          return u4_kq
            (wir_r, u4_nul, axe, u4_nul, q_sut);
        }
        else return u4_nul;
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit foz = _iris_find_swim(wir_r, sut, bar, axe, gil, cog);

        if ( (u2_nul == foz) ) {
          return u4_nul; 
        }
        return u4_ct(foz);
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        u4_unit hax = _iris_find_main
          (wir_r, p_sut, bar, axe, gil, cog);
        u4_unit yor = _iris_find_main
          (wir_r, q_sut, u4_kc(wir_r, p_sut, bar), axe, gil, cog);

        if ( (u2_nul == yor) ) {
          if ( (u2_nul == hax) ) {
            return u4_nul;
          }
          else {
            u4_noun u_hax = u4_ct(hax);
            u4_noun pu_hax = u4_ch(u_hax);
            u4_noun qu_hax = u4_ch(u4_ct(u_hax));
            u4_noun ru_hax = u4_ct(u4_ct(u_hax));

            return u4_kc
              (wir_r, 
               u4_nul,
               u4_kt
                (wir_r,
                 pu_hax,
                 qu_hax,
                 _rose_both
                  (wir_r,
                   _iris_peek
                    (wir_r, q_sut, u4_kc(wir_r, p_sut, bar), axe, pu_hax),
                   ru_hax)));
          }
        }
        else {
          u4_noun u_yor = u4_ct(yor);
          u4_noun pu_yor = u4_ch(u_yor);
          u4_noun qu_yor = u4_ch(u4_ct(u_yor));
          u4_noun ru_yor = u4_ct(u4_ct(u_yor));

          if ( (u2_nul == hax) ) {
            return u4_kc
              (wir_r, 
               u4_nul,
               u4_kt
                (wir_r,
                 pu_yor,
                 qu_yor,
                 _rose_both
                  (wir_r,
                   ru_yor,
                   _iris_peek(wir_r, p_sut, bar, axe, pu_yor))));
          }
          else {
            u4_noun u_hax = u4_ct(hax);
            u4_noun pu_hax = u4_ch(u_hax);
            u4_noun qu_hax = u4_ch(u4_ct(u_hax));
            u4_noun ru_hax = u4_ct(u4_ct(u_hax));

            if ( !(u4_n_eq(pu_hax, pu_yor) && u4_n_eq(qu_hax, qu_yor)) ) {
              ru_hax = _iris_peek(wir_r, p_sut, bar, axe, pu_yor);
            }
            return u4_kc
              (wir_r, 
               u4_nul,
               u4_kt
                (wir_r,
                 pu_yor,
                 qu_yor,
                 _rose_both(wir_r, ru_yor, ru_hax)));
          }
        }
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun dit = u4_kc(wir_r, bar, sut);

        if ( u2_fj_pool_in(dit, gil) ) {
          return u4_nul;
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
        return u4_trip;
      }
    }
    static u4_unit
    _iris_find_main(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_term cog)
    {
      
      u4_noun mum  = u4_k_quil(wir_r, sut, bar, axe, gil, cog);
      u4_nopt zod  = u2_fj_book_get(mum, p->fin);

      if ( zod != u4_bull ) {
        return zod;
      }
      else {
        u4_unit gur = _iris_find_main_a
          (wir_r, sut, bar, axe, gil, cog);

        p->fin = u2_fj_book_add(wir_r, mum, gur, p->fin);
        return gur;
      }
    }
  u4_plan
  _iris_find(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_term cog)
  {
    u4_unit fyg = _iris_find_main(wir_r, sut, bar, axe, u4_nul, cog);

    if ( (u2_nul == fyg) ) {
      u4_burp(p->wir_r, "name", u4_prep_textual(p->wir_r, cog));
      u4_burp(p->wir_r, "sut", _dump_type(wir_r, sut));
      return _plow_fail(wir_r, "not found");
    }
    return u4_ct(fyg);
  }

  /* fish:iris:rose:plow
  */
    static u4_tool
    _iris_fish_main(u4_plow, u4_type, u4_rail, u4_axis, u4_pool);

    static u4_tool
    _iris_fish_slip(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool vit,
                    u4_axis had)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, had);
      return _iris_fish_main(wir_r, sut, bar, axe, vit);
    }
    static u4_unit
    _iris_fish_swim(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool vit)
    {
      
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit doz = _iris_fish_swim(wir_r, p_sut, bar, axe, vit);
        u4_unit ryg = _iris_fish_swim(wir_r, q_sut, bar, axe, vit);
      
        if ( (u2_nul == doz) ) return ryg;
        else if ( (u2_nul == ryg) ) return doz;
        else return u4_kc
          (wir_r, u4_nul, 
                _lily_flor(wir_r, u4_ct(doz), u4_ct(ryg)));
      }
      else {
        if ( u4_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u4_nul;
        }
        else {
          return u4_kc
            (wir_r, u4_nul, _iris_fish_main(wir_r, sut, bar, axe, vit));
        }
      }
    }
    static u4_tool
    _iris_fish_main(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool vit)
    {
      
      u4_noun p_sut, q_sut;

      if ( u4_n_eq(u4_atom_atom, sut) ) {
        return _lily_flop
          (wir_r, u4_kt(wir_r, u4_nock_dust, u4_nock_frag, axe));
      }
      else if ( u4_n_eq(u4_atom_blur, sut) ) {
        return u4_kc(wir_r, u4_nock_bone, u4_yes);
      }
      else if ( u4_n_eq(u4_atom_blot, sut) ) {
        return u4_kc(wir_r, u4_nock_bone, u4_no);
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        return u4_kc(wir_r, u4_nock_frag, u4_noun_0);
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        return u4_kt
          (wir_r, u4_nock_sing, 
                u4_kc(wir_r, u4_nock_bone, p_sut),
                u4_kc(wir_r, u4_nock_frag, axe));
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        return _lily_flan
          (wir_r,
           u4_kt(wir_r, u4_nock_dust, u4_nock_frag, axe),
           _lily_flan
            (wir_r, _iris_fish_slip(wir_r, sut, bar, axe, vit, u4_axis_2),
                _iris_fish_slip(wir_r, sut, bar, axe, vit, u4_axis_3)));
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _iris_fish_main(wir_r, q_sut, bar, axe, vit);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_ct(_iris_fish_swim(wir_r, sut, bar, axe, vit));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _lily_flan
          (wir_r, 
           _iris_fish_main(wir_r, p_sut, bar, axe, vit),
           _iris_fish_main(wir_r, q_sut, u4_kc(wir_r, p_sut, bar), axe, vit));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun duq = u4_kc(wir_r, sut, bar);

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
        return u4_trip;
      }
    }
  u4_tool
  _iris_fish(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe)
  {
    return _iris_fish_main(wir_r, sut, bar, axe, u4_nul);
  }

  /* half:iris:rose:plow
  */
    static u4_unit
    _iris_half_swim(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_axis had)
    {
      
      u4_noun p_sut, q_sut;

      if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit doz = _iris_half_swim(wir_r, p_sut, bar, axe, had);
        u4_unit ryg = _iris_half_swim(wir_r, q_sut, bar, axe, had);

        if ( (u2_nul == doz) ) return ryg;
        else if ( (u2_nul == ryg) ) return doz;
        else return u4_kc
          (wir_r, u4_nul, _rose_eith(wir_r, u4_ct(doz), u4_ct(ryg)));
      }
      else {
        if ( u4_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u4_nul;
        }
        else {
          return u4_kc
            (wir_r, u4_nul, _iris_half(wir_r, sut, bar, axe, had));
        }
      }
    }
    u4_type
    _iris_half_main(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_axis had)
    {
      
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
          return u4_kc(wir_r, u4_atom_cube, u4_ch(p_sut));
        } else return u4_kc(wir_r, u4_atom_cube, u4_ct(p_sut));
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _iris_half(wir_r, q_sut, bar, axe, had);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        u4_unit pez = _iris_half_swim(wir_r, sut, bar, axe, had);

        if ( (u2_nul == pez) ) {
          return u4_atom_blot;
        }
        return u4_ct(pez);
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _rose_both
          (wir_r, 
           _iris_half(wir_r, q_sut, u4_kc(wir_r, p_sut, bar), axe, had),
           _iris_half(wir_r, p_sut, bar, axe, had));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        return _iris_half(wir_r, _rose_repo(wir_r, p_sut, q_sut), bar, axe, had);
      }
      else return u4_trip;
    }

  u4_type
  _iris_half(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_axis had)
  {
    
    u4_noun mum = u4_kt(wir_r, sut, bar, had);  /* axe is not used */
    u4_nopt zod = u2_fj_book_get(mum, p->huf);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_type gur = _iris_half_main(wir_r, sut, bar, axe, had);

      p->huf = u2_fj_book_add(wir_r, mum, gur, p->huf);
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
    _iris_nest_dext_slip(u2_ray  wir_r,
                         u4_type sut,
                         u4_rail bar,
                         u4_axis axe,
                         u4_pool gil,
                         u4_type bon,
                         u4_rail nef,
                         u4_axis ful,
                         u4_axis had)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, had);
      _iris_slip(wir_r, &bon, &nef, &ful, had);

      return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
    }
    static u4_flag
    _iris_nest_dext_swim(u2_ray  wir_r,
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
          (_iris_nest_dext_swim(wir_r, p_sut, bar, axe, gil, bon, nef, ful),
           _iris_nest_dext_swim(wir_r, q_sut, bar, axe, gil, bon, nef, ful));
      }
      else {
        if ( u4_so(_iris_cull(wir_r, sut, bar, axe)) ) {
          return u4_no;
        }
        else return _iris_nest_dext
          (wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
    }

    static u4_flag
    _iris_nest_dext_main(u2_ray  wir_r,
                         u4_type sut,
                         u4_rail bar,
                         u4_axis axe,
                         u4_pool gil,
                         u4_type bon,
                         u4_rail nef,
                         u4_axis ful)
    {
      
      u4_noun p_sut, q_sut, qrs_sut;
      u4_noun p_bon, q_bon, qrs_bon;

      if ( u4_n_eq(sut, u4_atom_atom) ) {
        if ( u4_n_eq(bon, u4_atom_atom) ) {
          return u4_yes;
        }
        else if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
          return u4_say(u4_n_atom(p_bon));
        }
        else return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_n_eq(sut, u4_atom_blur) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &qrs_sut) ) {
        if ( u4_b_pq(bon, u4_atom_core, &p_bon, &qrs_bon) ) {
          return u4_and
            (u4_say(u4_n_eq(qrs_sut, qrs_bon)),
             _iris_nest_dext_slip
                (wir_r, sut, bar, axe, gil, bon, nef, ful, u4_axis_2));
        }
        else return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
          return u4_and
            (_iris_nest_dext_slip
                (wir_r, sut, bar, axe, gil, bon, nef, ful, u4_axis_2),
             _iris_nest_dext_slip
                (wir_r, sut, bar, axe, gil, bon, nef, ful, u4_axis_3));
        }
        else {
          return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
          return u4_n_eq(p_sut, p_bon) ? u4_yes : u4_no;
        }
        else return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _iris_nest_dext(wir_r, q_sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        if ( u4_n_atom(bon) ||
             u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ||
             u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ||
             u4_b_p(bon, u4_atom_cube, &p_bon) ) 
        {
          return _iris_nest_dext_swim
            (wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
        else {
          return _iris_nest_sint(wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        u4_rail buz = u4_kc(wir_r, p_sut, bar);

        return u4_and
          (_iris_nest_dext(wir_r, p_sut, bar, axe, gil, bon, nef, ful),
           _iris_nest_dext(wir_r, q_sut, buz, axe, gil, bon, nef, ful));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun duq = u4_kq(wir_r, sut, bar, bon, nef);

        if ( u2_fj_pool_in(duq, gil) ) {
          return u4_yes;
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
        return u4_trip;
      }
    }
    static u4_flag
    _iris_nest_dext(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_type bon,
                    u4_rail nef,
                    u4_axis ful)
    {
      
    
      if ( u4_n_eq(sut, bon) ) {
        return u4_yes;
      }
      else {
        u4_noun mum = u4_kq(wir_r, bar, sut, nef, bon);
        u4_nopt zod = u2_fj_book_get(mum, p->vus);

        if ( zod != u4_bull ) {
          return zod;
        }
        else {
          u4_flag gur = _iris_nest_dext_main
            (wir_r, sut, bar, axe, gil, bon, nef, ful);

          p->vus = u2_fj_book_add(wir_r, mum, gur, p->vus);
          return gur;
        }
      }
    }
    static u4_flag
    _iris_nest_sint_swim(u2_ray  wir_r,
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
          (_iris_nest_sint_swim(wir_r, sut, bar, axe, gil, p_bon, nef, ful),
           _iris_nest_sint_swim(wir_r, sut, bar, axe, gil, q_bon, nef, ful));
      }
      else {
        if ( u4_so(_iris_cull(wir_r, bon, nef, ful)) ) {
          return u4_yes;
        }
        else return _iris_nest_dext
          (wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
    }
    static u4_flag
    _iris_nest_sint(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_pool gil,
                    u4_type bon,
                    u4_rail nef,
                    u4_axis ful)
    {
      
      u4_noun p_bon, q_bon;

      if ( u4_n_eq(bon, u4_atom_atom) || u4_n_eq(bon, u4_atom_blur) ) {
        return u4_no;
      }
      else if ( u4_b_pq(bon, u4_atom_cell, &p_bon, &q_bon) ) {
        return u4_no;
      }
      else if ( u4_b_pq(bon, u4_atom_core, &p_bon, &q_bon) ) {
        bon = u4_kt(wir_r, u4_atom_cell, p_bon, u4_atom_blur);

        return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_p(bon, u4_atom_cube, &p_bon) ) {
        if ( u4_n_atom(p_bon) ) {
          return u4_no;
        }
        else {
          bon = u4_kt
            (wir_r, u4_atom_cell,
                  u4_kc(wir_r, u4_atom_cube, u4_ch(p_bon)),
                  u4_kc(wir_r, u4_atom_cube, u4_ct(p_bon)));

          return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
        }
      }
      else if ( u4_b_pq(bon, u4_atom_face, &p_bon, &q_bon) ) {
        return _iris_nest_dext(wir_r, sut, bar, axe, gil, q_bon, nef, ful);
      }
      else if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
        return _iris_nest_sint_swim(wir_r, sut, bar, axe, gil, bon, nef, ful);
      }
      else if ( u4_b_pq(bon, u4_atom_fuse, &p_bon, &q_bon) ) {
        u4_rail gok = u4_kc(wir_r, p_bon, nef);

        return u4_or
          (_iris_nest_dext(wir_r, sut, bar, axe, gil, p_bon, nef, ful),
           _iris_nest_dext(wir_r, sut, bar, axe, gil, q_bon, gok, ful));
      }
      else if ( u4_b_pq(bon, u4_atom_hold, &p_bon, &q_bon) ) {
        u4_noun duq = u4_kq(wir_r, sut, bar, bon, nef);

        if ( u2_fj_pool_in(duq, gil) ) {
          return u4_yes;
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
      else return u4_trip;
    }
  u4_flag
  _iris_nest(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_type bon)
  {
    if ( u4_so(_rose_null(wir_r, bon)) ) {
      return u4_yes;
    }
    else if ( u4_so(_rose_null(wir_r, sut)) ) {
      return u4_no;
    }
    else {
      u4_pool gil = u4_nul;
      u4_rail nef = u4_nul;
      u4_axis ful = u4_axis_1;

      return _iris_nest_dext(wir_r, sut, bar, axe, gil, bon, nef, ful);
    }
  }

  /* peek:iris:rose:plow
  */
  u4_type
  _iris_peek(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_axis bow)
  {
    

    if ( u4_n_eq(u4_axis_1, bow) ) {
      return sut;
    } 
    else {
      _iris_slip(wir_r, &sut, &bar, &axe, u4_op_tip(bow));

      return _iris_peek(wir_r, sut, bar, axe, u4_op_tap(wir_r, bow));
    }
  }

  /* slip:iris:rose:plow
  */
    static u4_rail
    _iris_slip_a(u2_ray  wir_r,
                 u4_rail bar,
                 u4_axis had)
    {
      if ( (u2_nul == bar) ) {
        return u4_nul;
      }
      else {
        return u4_kc
          (p->wir_r, _iris_half(wir_r, u4_ch(bar), u4_nul, u4_axis_1, had),
                   _iris_slip_a(wir_r, u4_ct(bar), had));
      } 
    }
  void
  _iris_slip(u2_ray  wir_r,
             u4_type *sut,
             u4_rail *bar,
             u4_axis *axe,
             u4_axis had)
  {
    *sut = _iris_half(wir_r, *sut, *bar, *axe, had);
    *bar = _iris_slip_a(wir_r, *bar,  had);
    *axe = u4_op_peg(p->wir_r, *axe, had);
  }

  /* snap:iris:rose:plow
  */
    static u4_type
    _iris_snap_dext(u4_plow, u4_type, u4_rail, u4_axis, u4_type);
    static u4_type
    _iris_snap_sint(u4_plow, u4_type, u4_rail, u4_axis, u4_type);

    static u4_type
    _iris_snap_slip(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon,
                    u4_axis had)
    {
      _iris_slip(wir_r, &sut, &bar, &axe, had);
      return _iris_snap(wir_r, sut, bar, axe, bon);
    }
    static u4_flag
    _iris_snap_cull(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon)
    {
      return u4_or
        (_iris_cull(wir_r, sut, bar, axe),
         _rose_orth(wir_r, sut, bon));
    }
    static u4_type
    _iris_snap_dext(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon)
    {
      
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
            (wir_r,
             u4_atom_cell,
             _iris_snap_slip(wir_r, sut, bar, axe, p_bon, u4_axis_2),
             _iris_snap_slip(wir_r, sut, bar, axe, q_bon, u4_noun_3));
        }
        else {
          return _iris_snap_sint(wir_r, sut, bar, axe, bon);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        if ( u4_b_pq(bon, u4_atom_face, &p_bon, &q_bon) ) {
          return u4_kt
            (wir_r, u4_atom_face,
                  p_sut,
                  _iris_snap_dext(wir_r, q_sut, bar, axe, q_bon));
        }
        else {
          return u4_kt
            (wir_r, u4_atom_face,
                  p_sut,
                  _iris_snap_dext(wir_r, q_sut, bar, axe, bon));
        }
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        if ( u4_so(_iris_snap_cull(wir_r, p_sut, bar, axe, bon)) ) {
          if ( u4_so(_iris_snap_cull(wir_r, q_sut, bar, axe, bon)) ) {
            return bon;
          }
          else return _iris_snap_dext(wir_r, q_sut, bar, axe, bon);
        }
        else {
          if ( u4_so(_iris_snap_cull(wir_r, q_sut, bar, axe, bon)) ) {
            return _iris_snap_dext(wir_r, p_sut, bar, axe, bon);
          }
          else return bon;
        }
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _iris_snap_dext
          (wir_r, q_sut, u4_kc(wir_r, p_sut, bar), axe, bon);
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        return _iris_snap_dext
          (wir_r, _rose_repo(wir_r, p_sut, q_sut), bar, axe, bon);
      }
      else return u4_trip;
    }
    static u4_type
    _iris_snap_sint(u2_ray  wir_r,
                    u4_type sut,
                    u4_rail bar,
                    u4_axis axe,
                    u4_type bon)
    {
      u4_noun p_bon, q_bon;

      if ( u4_b_pq(bon, u4_atom_fork, &p_bon, &q_bon) ) {
        return _rose_eith
          (wir_r, 
           _iris_snap_dext(wir_r, sut, bar, axe, p_bon), 
           _iris_snap_dext(wir_r, sut, bar, axe, q_bon));
      }
      else if ( u4_b_pq(bon, u4_atom_fuse, &p_bon, &q_bon) ) {
        return _rose_both
          (wir_r,
           _iris_snap_dext(wir_r, sut, bar, axe, q_bon),
           _iris_snap_dext(wir_r, sut, bar, axe, p_bon));
      }
      else return bon;
    }
  u4_type
  _iris_snap(u2_ray  wir_r,
             u4_type sut,
             u4_rail bar,
             u4_axis axe,
             u4_type bon)
  {
    u4_type sap;

    sap = _iris_snap_dext(wir_r, sut, bar, axe, bon);

    return sap;
  }


/****   _lark: mutation.
****/
  /* nuke:lark:rose:plow
  */
    static u4_tack
    _lark_nuke_port(u2_ray  wir_r,
                    u4_type sut,
                    u4_tack tac,
                    u4_rope rop,
                    u4_type feg,
                    u4_term gos,
                    u4_axis wam,
                    u4_unit yus,
                    u4_type gur)
    {
      

      if ( u4_n_eq(u4_axis_1, wam) ) {
        if ( (u2_nul == yus) ) {
          return u4_k_trel
            (wir_r, u4_atom_bran,
                  gos,
                  _lark_nuke(wir_r, gur, tac, rop, feg));
        } else {
          return _lark_nuke(wir_r, gur, tac, rop, feg);
        }
      }
      else {
        u4_axis tip = u4_op_tip(wam);
        u4_axis tap = u4_op_tap(wir_r, wam);

        if ( u4_n_eq(u4_axis_2, tip) ) {
          return u4_k_trel
            (wir_r, 
             u4_atom_pair,
             _lark_nuke_port(wir_r, sut, tac, rop, feg, gos, tap, yus, gur),
             u4_nul);
        }
        else {
          return u4_k_trel
            (wir_r, 
             u4_atom_pair,
             u4_nul,
             _lark_nuke_port(wir_r, sut, tac, rop, feg, gos, tap, yus, gur));
        }
      }
    }

    static u4_tack
    _lark_nuke_frag(u2_ray  wir_r,
                    u4_type sut,
                    u4_tack tac,
                    u4_rope rop,
                    u4_type feg,
                    u4_axis wam,
                    u4_type gur)
    {
      

      if ( u4_n_eq(u4_axis_1, wam) ) {
        return _lark_nuke(wir_r, gur, tac, rop, feg);
      }
      else {
        u4_axis tip = u4_op_tip(wam);
        u4_axis tap = u4_op_tap(wir_r, wam);

        if ( u4_n_eq(u4_axis_2, tip) ) {
          return u4_k_trel
            (wir_r, 
             u4_atom_pair,
             _lark_nuke_frag(wir_r, sut, tac, rop, feg, tap, gur),
             u4_nul);
        }
        else {
          return u4_k_trel
            (wir_r, 
             u4_atom_pair,
             u4_nul,
             _lark_nuke_frag(wir_r, sut, tac, rop, feg, tap, gur));
        }
      }
    }
  u4_tack
  _lark_nuke(u2_ray  wir_r,
             u4_type sut,
             u4_tack tac,
             u4_rope rop,
             u4_type feg)
  {
    

    if ( (u2_nul == rop) ) {
      return u4_k_cell(wir_r, u4_atom_leaf, feg);
    }
    else {
      u4_cord i_rop = u4_ch(rop);
      u4_rope t_rop = u4_ct(rop);
      u4_noun pi_rop;

      if ( u4_n_atom(i_rop) ) {
        return _lark_nuke
          (wir_r, sut, 
              tac, 
              u4_k_cell(wir_r, u4_k_cell(wir_r, u4_atom_pane, rop), t_rop),
              feg);
      }
      else if ( u4_b_p(i_rop, u4_atom_pane, &pi_rop) ) {
        u4_plan lar = _iris_find(wir_r, sut, u4_nul, u4_axis_1, pi_rop);
        u4_axis p_lar = u4_ch(lar);
        u4_unit q_lar = u4_ch(u4_ct(lar));
        u4_type r_lar = u4_ct(u4_ct(lar));

        return _lark_nuke_port
          (wir_r, sut, tac, t_rop, feg, pi_rop, p_lar, q_lar, r_lar);
      }
      else if ( u4_b_p(i_rop, u4_atom_frag, &pi_rop) ) {
        u4_type gur = _iris_peek(wir_r, sut, u4_nul, u4_axis_1, pi_rop);

        return _lark_nuke_frag(wir_r, sut, tac, t_rop, feg, pi_rop, gur); 
      }
      else return u4_trip;
    }
  }

  /* cram:lark:rose:plow
  */
  u4_tack
  _lark_cram(u2_ray  wir_r,
             u4_type sut,
             u4_tack tac,
             u4_tack les)
  {
    
    u4_noun p_tac, q_tac, p_les, q_les;

    if ( (u2_nul == tac) ) {
      return les;
    }
    else if ( (u2_nul == les) ) {
      return tac;
    }
    else if ( u4_b_pq(tac, u4_atom_bran, &p_tac, &q_tac) ) {
      if ( !u4_b_pq(les, u4_atom_bran, &p_les, &q_les) ||
           !u4_n_eq(p_tac, p_les) )
      {
        return _plow_fail(wir_r, "cram crash");
      }
      else return u4_k_trel
        (wir_r, u4_atom_bran,
              p_tac,
              _lark_cram(wir_r, sut, q_tac, q_les));
    }
    else if ( u4_b_pq(tac, u4_atom_pair, &p_tac, &q_tac) ) {
      if ( !u4_b_pq(les, u4_atom_pair, &p_les, &q_les) ) {
        return _plow_fail(wir_r, "cram crash");
      }
      else return u4_k_trel
        (wir_r, u4_atom_pair,
              _lark_cram(wir_r, sut, p_tac, p_les),
              _lark_cram(wir_r, sut, q_tac, q_les));
    }
    else return _plow_fail(wir_r, "cram crash");
  }

  /* feed:lark:rose:plow
  */
  u4_tack
  _lark_feed(u2_ray  wir_r,
             u4_type sut,
             u4_tack tac,
             u4_list mut)
  {
    if ( (u2_nul == mut) ) {
      return tac;
    }
    else {
      u4_noun i_mut  = u4_ch(mut);
      u4_list t_mut  = u4_ct(mut);
      u4_gene pi_mut = u4_ch(i_mut);
      u4_type qi_mut = u4_ct(i_mut);
      u4_rope rop    = _plow_rake(wir_r, pi_mut);
      u4_tack bur    = _lark_nuke(wir_r, sut, tac, rop, qi_mut);
      u4_tack tey    = _lark_cram(wir_r, sut, tac, bur);

#if 0
      { 
        u4_err(p->wir_r, "tac", tac);
        u4_err(p->wir_r, "bur", bur);
        u4_err(p->wir_r, "tey", tey);
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
  u4_type
  _rose_both(u2_ray  wir_r,
             u4_type sut,
             u4_type hoc)
  {
    

#if 1
    if ( u4_n_eq(u4_atom_blur, sut) ) {
      return hoc;
    }
    else if ( u4_n_eq(u4_atom_blur, hoc) ) {
      return sut;
    }
    else {
      return u4_kt(wir_r, u4_atom_fuse, hoc, sut);
    }
#else 
    if ( u4_so(_iris_nest(wir_r, hoc, u4_nul, u4_axis_1, sut)) ) {
      /* every sut is a hoc */
      return sut;
    }
    else {
      /* not every sut is a hoc */
      if ( u4_so(_iris_nest(wir_r, sut, u4_nul, u4_axis_1, hoc)) ) {
        /* every hoc is a sut */
        return hoc;
      }
      else {
        /* not every sut is a hoc, not every hoc is a sut */
        return u4_kt(wir_r, u4_atom_fuse, hoc, sut);
      }
    }
#endif
  }

  /* eith:rose:plow
  */
  u4_type
  _rose_eith(u2_ray  wir_r,
             u4_type sut,
             u4_type hoc)
  {
    

    if ( u4_n_eq(sut, hoc) ) {
      return sut;
    }
    else if ( u4_n_eq(u4_atom_blot, hoc) ) {
      return sut;
    }
    else if ( u4_n_eq(u4_atom_blot, sut) ) {
      return hoc;
    }
    else return u4_kt(wir_r, u4_atom_fork, sut, hoc);
  }

  /* etch:rose:plow
  */
  u4_type
  _rose_etch(u2_ray  wir_r,
             u4_type sut)
  {
    u4_noun p_sut, q_sut;

    if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
      return q_sut;
    }
    else return _plow_fail(wir_r, "bad etch");
  }

  /* edit:rose:plow
  */
  u4_type
  _rose_edit(u2_ray  wir_r,
             u4_type sut,
             u4_list mut)
  {
    u4_tack tac = _lark_feed(wir_r, sut, u4_nul, mut);
    u4_type fuz = _iris_burn(wir_r, sut, u4_nul, u4_axis_1, tac);

    return fuz;
  }

  /* gain:rose:plow
  */
    static u4_rack
    _rose_gain_hunt(u4_plow, u4_type, u4_gene);

    static u4_rack
    _rose_gain_hunt_a(u2_ray  wir_r,
                      u4_type sut,
                      u4_bank vof)
    {
      if ( (u2_nul == vof) ) {
        return u4_nul;
      }
      else return u4_log_cat(p->wir_r, _rose_gain_hunt(wir_r, sut, u4_ch(vof)),
                                     _rose_gain_hunt_a(wir_r, sut, u4_ct(vof)));
    }
    static u4_plot
    _rose_gain_hunt(u2_ray  wir_r,
                    u4_type sut,
                    u4_gene gen)
    {
      
      u4_noun p_gen, q_gen;

      if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        return u4_k_cell
          (wir_r, 
           u4_k_cell(wir_r, q_gen, _rose_play(wir_r, sut, p_gen)),
           u4_nul);
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        return _rose_gain_hunt(wir_r, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_zush, &p_gen, &q_gen) ) {
        return _rose_gain_hunt(wir_r, sut, q_gen);
      }
      else if ( u4_b_p(gen, u4_atom_chan, &p_gen) ) {
        return _rose_gain_hunt_a(wir_r, sut, p_gen);
      }
      else return u4_nul;
    }
    static u4_type
    _rose_gain_gild(u2_ray  wir_r,
                    u4_type sut,
                    u4_plot mut)
    {
      u4_tack tac = _lark_feed(wir_r, sut, u4_nul, mut);
      u4_type hoc = _iris_burn(wir_r, u4_atom_blur, u4_nul, u4_axis_1, tac);

      return _rose_both(wir_r, sut, hoc);
    }
  u4_type
  _rose_gain(u2_ray  wir_r,
             u4_type sut,
             u4_gene gen)
  {
    u4_plot zet = _rose_gain_hunt(wir_r, sut, gen);

    return _rose_gain_gild(wir_r, sut, zet);
  }

  /* make:rose:plow
  */
    u4_list
    _rose_make_boil_a(u2_ray  wir_r,
                      u4_type sut,
                      u4_list rem)
    {
      

      if ( (u2_nul == rem) ) {
        return u4_nul;
      }
      else {
        u4_noun i_rem  = u4_ch(rem);
        u4_noun t_rem  = u4_ct(rem);
        u4_gene pi_rem = u4_ch(i_rem);
        u4_tool qi_rem = u4_ct(i_rem);
        u4_plan giz    = _rose_seek(wir_r, sut, _plow_rake(wir_r, pi_rem));
        u4_axis p_giz  = u4_ch(giz);

        return u4_k_cell(wir_r, u4_k_cell(wir_r, p_giz, qi_rem),
                              _rose_make_boil_a(wir_r, sut, t_rem));
      }
    }
    u4_tool
    _rose_make_boil(u2_ray  wir_r,
                    u4_type sut,
                    u4_axis axe,
                    u4_list rem)
    {
      return _lily_hike(wir_r, axe, _rose_make_boil_a(wir_r, sut, rem));
    }
    u4_noun
    _rose_make_bake(u2_ray  wir_r,
                    u4_type sut,
                    u4_book dab)
    {
      

      if ( (u2_nul == dab) ) {
        return u4_noun_0;
      }
      else {
        u4_noun n_dab, l_dab, r_dab, qn_dab;

        u4_c_trel(dab, &n_dab, &l_dab, &r_dab);
        qn_dab = u4_ct(n_dab);
        
        if ( (u2_nul == l_dab) && (u2_nul == r_dab) ) {
          return _rose_make(wir_r, sut, qn_dab);
        }
        else if ( (u2_nul == l_dab) ) {
          return u4_kc
            (wir_r, _rose_make(wir_r, sut, qn_dab),
                  _rose_make_bake(wir_r, sut, r_dab));
        }
        else if ( (u2_nul == r_dab) ) {
          return u4_kc
            (wir_r, _rose_make(wir_r, sut, qn_dab),
                  _rose_make_bake(wir_r, sut, l_dab));
        }
        else {
          return u4_kt
            (wir_r, _rose_make(wir_r, sut, qn_dab),
                  _rose_make_bake(wir_r, sut, l_dab),
                  _rose_make_bake(wir_r, sut, r_dab));
        }
      }
    }
    u4_noun
    _rose_make_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_rack dus)
    {
      

      if ( (u2_nul == dus) ) {
        return u4_nul;
      }
      else {
        u4_noun i_dus = u4_ch(dus);
        u4_noun t_dus = u4_ct(dus);
        u4_gene pi_dus = u4_ch(i_dus);
        u4_gene qi_dus = u4_ct(i_dus);
        u4_tool pog    = _rose_make(wir_r, sut, qi_dus);

        return u4_k_cell
          (wir_r,
           u4_k_cell(wir_r, pi_dus, pog),
           _rose_make_a(wir_r, sut, t_dus));
      }
    }
    u4_noun
    _rose_make_prop(u2_ray  wir_r,
                    u4_type sut,
                    u4_prop pup)
    {
      
      
      if ( (u2_nul == pup) ) {
        return pup;
      } else {
        u4_plan lar = _rose_seek(wir_r, sut, u4_ch(pup));

        return u4_kc(wir_r, u4_ch(lar), u4_ct(pup));
      }
    }

    static u4_tool
    _rose_make_main(u2_ray  wir_r,
                    u4_type sut,
                    u4_gene gen)
    {
      
      u4_noun p_gen, q_gen, r_gen;

      if ( u4_b_p(gen, u4_atom_zike, &p_gen) ) {
        return u4_k_cell(wir_r, u4_nock_frag, u4_axis_0);
      }
      else if ( u4_b_p(gen, u4_atom_zoot, &p_gen) ) {
        return u4_tank;
      }
      else if ( u4_b_p(gen, u4_atom_vint, &p_gen) ) {
        return u4_k_cell(wir_r, u4_nock_vint, _rose_make(wir_r, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return _rose_make(wir_r, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return _lily_cons
          (wir_r, _rose_make(wir_r, sut, p_gen), _rose_make(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_wost, &p_gen) ) {
        return _rose_make(wir_r, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        u4_tool guz;
        u4_atom bug;

        bug = p->bug;
        p->bug = u4_op_inc(wir_r, p->bug);

        guz = _rose_make(wir_r, sut, p_gen);
        
        p->bug = bug;
        return guz;
      }
      else if ( u4_b_p(gen, u4_atom_dust, &p_gen) ) {
        return u4_k_cell(wir_r, u4_nock_dust, _rose_make(wir_r, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_germ, &p_gen, &q_gen) ) {
        return u4_kt(wir_r, 
                     u4_atom_germ,
                     _rose_make(wir_r, sut, p_gen),
                     _rose_make(wir_r, sut, q_gen));
      } 
      else if ( u4_b_pq(gen, u4_atom_hint, &p_gen, &q_gen) ) {
        return u4_kt(wir_r, 
                     u4_nock_hint,
                     _rose_make(wir_r, sut, p_gen),
                     _rose_make(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_grit, &p_gen) ) {
        return _rose_make(wir_r, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_tash, &p_gen, &q_gen) ) {
        u4_book sec = _gull_fill(wir_r, u4_nul, q_gen);
        u4_noun heq = _rose_make_prop(wir_r, sut, p_gen);
        u4_noun baf = _rose_make_bake(wir_r, _rose_play(wir_r, sut, gen), sec);

#if 1
        return u4_kt
          (wir_r, u4_nock_coat, heq, baf);
#else
        return u4_kc
          (wir_r,
           u4_kc(wir_r, u4_nock_frag, u4_axis_1), 
           u4_kc(wir_r, u4_nock_bone, baf));
#endif
      }
      else if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(wir_r, sut, _plow_rake(wir_r, q_gen));
        u4_axis p_lar = u4_ch(lar);

        if ( !(u2_nul == u4_ch(u4_ct(lar))) ) {
          return _plow_fail(wir_r, "bad like");
        }
        else {
          return _iris_fish(wir_r, _rose_play(wir_r, sut, p_gen), u4_nul, p_lar);
        }
      }
      else if ( u4_b_pq(gen, u4_atom_flac, &p_gen, &q_gen) ) {
        return _lily_comb
          (wir_r,
           _rose_make(wir_r, sut, p_gen),
           _rose_make(wir_r, _rose_play(wir_r, sut, p_gen), q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_pank, &p_gen, &q_gen) ) {
        u4_book sec = _gull_fill(wir_r, u4_nul, q_gen);
        u4_noun heq = _rose_make_prop(wir_r, sut, p_gen);
        u4_noun baf = _rose_make_bake(wir_r, _rose_play(wir_r, sut, gen), sec);

#if 1
        return u4_kt
          (wir_r, u4_nock_coat, heq, baf);
#else
        return u4_kc
          (wir_r,
           u4_kc(wir_r, u4_nock_frag, u4_axis_1), 
           u4_kc(wir_r, u4_nock_bone, baf));
#endif
      }
      else if ( u4_b_p(gen, u4_atom_zalt, &p_gen) ) {
        u4_type yoz = _rose_play(wir_r, sut, p_gen);
   
        return u4_kc(wir_r, u4_nock_bone, yoz);
      }
      else if ( u4_b_p(gen, u4_atom_zond, &p_gen) ) {
        u4_type yoz = _rose_make(wir_r, sut, p_gen);
   
        return u4_kc(wir_r, u4_nock_bone, yoz);
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return _rose_make(wir_r, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_sail, &p_gen, &q_gen) ) {
        return u4_k_trel(wir_r, u4_nock_sail,
                              _rose_make(wir_r, sut, p_gen),
                              _rose_make(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
        return u4_k_cell(wir_r, u4_nock_bone, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        u4_noun qip;

        p->meb = u4_kc(wir_r, u4_kc(wir_r, u4_nul, p_gen), p->meb);
        qip = _rose_make(wir_r, sut, q_gen);
        p->meb = u4_ct(p->meb);

        return qip;
      }
      else if ( u4_b_pq(gen, u4_atom_stil, &p_gen, &q_gen) ) {
        return u4_kc(wir_r, u4_nock_frag, u4_axis_1);
      }
      else if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(wir_r, sut, p_gen);
        u4_noun rem = _rose_make_a(wir_r, sut, q_gen);
        u4_axis p_lar = u4_ch(lar);
        u4_noun q_lar = u4_ch(u4_ct(lar));
        u4_type r_lar = u4_ct(u4_ct(lar));

#if 0
        if ( !(u2_nul == q_gen) ) {
          u4_err(wir_r, "make: take", gen);
          u4_err(wir_r, "make: q", q_lar);
        }
#endif
        if ( (u2_nul == q_lar) ) {
          return _rose_make_boil(wir_r, r_lar, p_lar, rem);
        }
        else {
          u4_door uq_lar  = u4_ct(q_lar);
          u4_axis puq_lar = u4_ch(uq_lar);
          u4_type quq_lar = u4_ch(u4_ct(uq_lar));
          u4_tool ruz = _rose_make_boil(wir_r, quq_lar, p_lar, rem);
          u4_tool gak;

          gak = u4_k_trel
            (wir_r,
             u4_nock_sail,
             ruz,
             u4_k_cell(wir_r, u4_nock_frag, u4_op_peg(wir_r, p_lar, puq_lar)));

          return gak;
        }
      }
      else if ( u4_b_pqr(gen, u4_atom_trol, &p_gen, &q_gen, &r_gen) ) {
        return u4_k_qual
          (wir_r,
           u4_nock_trol,
           _rose_make(wir_r, sut, p_gen),
           _rose_make(wir_r, _rose_gain(wir_r, sut, p_gen), q_gen),
           _rose_make(wir_r, sut, r_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_sing, &p_gen, &q_gen) ) {
        return u4_k_trel
          (wir_r,
           u4_nock_sing,
           _rose_make(wir_r, sut, p_gen),
           _rose_make(wir_r, sut, q_gen));
      }
      else {
        u4_noun fog = _plow_open(wir_r, gen);

        if ( u4_n_eq(fog, gen) ) {
          u4_err(wir_r, "dup: gen", gen);
          return u4_trip;
        }
        return _rose_make(wir_r, sut, _plow_open(wir_r, gen)); 
      }
    }
  u4_tool
  _rose_make(u2_ray  wir_r,
             u4_type sut,
             u4_gene gen)
  {
    
    u4_noun mum = u4_kc(wir_r, sut, gen);
    u4_nopt zod = u2_fj_book_get(mum, p->niq);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_tool gur = _rose_make_main(wir_r, sut, gen);

      p->niq = u2_fj_book_add(wir_r, mum, gur, p->niq);
      return gur;
    }
  }

  /* null:rose:plow
  */
    static u4_flag
    _rose_null_a(u2_ray  wir_r, u4_type sut, u4_pool hem);

    static u4_flag
    _rose_null_b(u2_ray  wir_r,
                 u4_type sut,
                 u4_pool hem)
    {
      
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
        return u4_or(_rose_null_a(wir_r, p_sut, hem), _rose_null_a(wir_r, q_sut, hem));
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        return _rose_null_a(wir_r, p_sut, hem);
      }
      else if ( u4_b_p(sut, u4_atom_cube, &p_sut) ) {
        return u4_no;
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _rose_null_a(wir_r, q_sut, hem);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_and(_rose_null_a(wir_r, p_sut, hem), _rose_null_a(wir_r, q_sut, hem));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return _rose_orth(wir_r, p_sut, q_sut);
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        if ( u2_fj_pool_in(sut, hem) ) {
          return u4_yes;
        } else {
          return _rose_null_a
            (wir_r, _rose_repo(wir_r, p_sut, q_sut), u2_fj_pool_add(wir_r, sut, hem));
        }
      } 
      else return u4_trip;
    }
    static u4_flag
    _rose_null_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_pool hem)
    {
      
      u4_noun mum = u4_kc(wir_r, sut, hem);
      u4_nopt zod = u2_fj_book_get(mum, p->tyc);

      if ( zod != u4_bull ) {
        return zod;
      }
      else {
        u4_flag gur = _rose_null_b(wir_r, sut, hem);

        p->tyc = u2_fj_book_add(wir_r, mum, gur, p->tyc);
        return gur;
      }
    }
  u4_flag
  _rose_null(u2_ray  wir_r,
             u4_type sut)
  {
    return _rose_null_a(wir_r, sut, u4_nul);
  }

  /* orth:rose:plow
  */
    static u4_flag
    _rose_orth_a(u2_ray  wir_r, u4_type sut, u4_type ref, u4_pool bol);

    static u4_flag
    _rose_orth_b(u2_ray  wir_r,
                 u4_type sut,
                 u4_type ref,
                 u4_pool bol)
    {
      
      u4_noun p_sut, q_sut;
      u4_noun p_ref, q_ref;

      if ( u4_n_eq(sut, u4_atom_atom) ) {
        if ( u4_n_eq(ref, u4_atom_atom) ) {
          return u4_no;
        }
        else if ( u4_b_pq(ref, u4_atom_cell, &p_sut, &q_sut) ) {
          return u4_yes;
        }
        else return _rose_orth_a(wir_r, ref, sut, bol);
      }
      else if ( u4_n_eq(sut, u4_atom_blot) ) {
        return u4_yes;
      }
      else if ( u4_n_eq(sut, u4_atom_blur) ) {
        return u4_no;
      }
      else if ( u4_b_pq(sut, u4_atom_cell, &p_sut, &q_sut) ) {
        if ( u4_b_pq(ref, u4_atom_cell, &p_ref, &q_ref) ) {
          return u4_or(_rose_orth_a(wir_r, p_sut, p_ref, bol),
                       _rose_orth_a(wir_r, q_sut, q_ref, bol));
        }
        else {
          return _rose_orth_a(wir_r, ref, sut, bol);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_core, &p_sut, &q_sut) ) {
        return _rose_orth_a
          (wir_r, u4_k_trel(wir_r, u4_atom_cell, p_sut, u4_atom_blur), ref, bol);
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
            u4_type hed = u4_k_cell(wir_r, u4_atom_cube, u4_ch(p_sut));
            u4_type tal = u4_k_cell(wir_r, u4_atom_cube, u4_ct(p_sut));

            return u4_or(_rose_orth_a(wir_r, hed, p_ref, bol),
                         _rose_orth_a(wir_r, tal, q_ref, bol));
          }
        }
        else {
          return _rose_orth_a(wir_r, ref, sut, bol);
        }
      }
      else if ( u4_b_pq(sut, u4_atom_face, &p_sut, &q_sut) ) {
        return _rose_orth_a(wir_r, q_sut, ref, bol);
      }
      else if ( u4_b_pq(sut, u4_atom_fork, &p_sut, &q_sut) ) {
        return u4_and(_rose_orth_a(wir_r, p_sut, ref, bol),
                      _rose_orth_a(wir_r, q_sut, ref, bol));
      }
      else if ( u4_b_pq(sut, u4_atom_fuse, &p_sut, &q_sut) ) {
        return u4_or(_rose_orth_a(wir_r, p_sut, ref, bol),
                     _rose_orth_a(wir_r, q_sut, ref, bol));
      }
      else if ( u4_b_pq(sut, u4_atom_hold, &p_sut, &q_sut) ) {
        u4_noun gob = u4_k_cell(wir_r, sut, ref);

        if ( u2_fj_pool_in(gob, bol) ) {
          return u4_yes;
        } else {
          return _rose_orth_a
            (wir_r, _rose_repo(wir_r, p_sut, q_sut), ref, u2_fj_pool_add(wir_r, gob, bol));
        }
      } 
      else {
        u4_err(wir_r, "sut", sut);

        return u4_trip;
      }
    }
    static u4_flag
    _rose_orth_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_type ref,
                 u4_pool bol)
    {
      
      u4_noun mum = u4_kt(wir_r, sut, ref, bol);
      u4_nopt zod = u2_fj_book_get(mum, p->gam);

      if ( zod != u4_bull ) {
        return zod;
      }
      else {
        u4_flag gur = _rose_orth_b(wir_r, sut, ref, bol);

        p->gam = u2_fj_book_add(wir_r, mum, gur, p->gam);
        return gur;
      }
    }
  u4_flag
  _rose_orth(u2_ray  wir_r,
             u4_type sut,
             u4_type ref)
  {
    return _rose_orth_a(wir_r, sut, ref, u4_nul);
  }

  /* play:rose:plow
  */
    static u4_plot
    _rose_play_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_rack dus)
    {
      

      if ( (u2_nul == dus) ) {
        return u4_nul;
      }
      else {
        u4_noun i_dus = u4_ch(dus);
        u4_noun t_dus = u4_ct(dus);
        u4_gene pi_dus = u4_ch(i_dus);
        u4_gene qi_dus = u4_ct(i_dus);
        u4_type feg    = _rose_play(wir_r, sut, qi_dus);

        return u4_k_cell
          (wir_r,
           u4_k_cell(wir_r, pi_dus, feg),
           _rose_play_a(wir_r, sut, t_dus));
      }
    }
    static u4_type
    _rose_play_main(u2_ray  wir_r,
                    u4_type sut,
                    u4_gene gen)
    {
      
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
        return _rose_play(wir_r, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return u4_k_trel
          (wir_r, u4_atom_cell,
                _rose_play(wir_r, sut, p_gen),
                _rose_play(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_wost, &p_gen) ) {
        return _rose_play(wir_r, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        u4_type soq;
        u4_atom bug;

        bug = p->bug;
        p->bug = u4_op_inc(wir_r, p->bug);

        soq = _rose_play(wir_r, sut, p_gen);
       
        u4_brut(wir_r, "soq", soq);

        p->bug = bug;
        return soq;
      }
      else if ( u4_b_p(gen, u4_atom_dust, &p_gen) ) {
        return u4_k_trel
          (wir_r,
           u4_atom_fork,
           u4_k_cell(wir_r, u4_atom_cube, u4_yes),
           u4_k_cell(wir_r, u4_atom_cube, u4_no));
      }
      else if ( u4_b_pq(gen, u4_atom_germ, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, sut, q_gen);
      } 
      else if ( u4_b_pq(gen, u4_atom_hint, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, sut, q_gen);
      }
      else if ( u4_b_p(gen, u4_atom_grit, &p_gen) ) {
        return _rose_etch(wir_r, _rose_play(wir_r, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_tash, &p_gen, &q_gen) ) {
        return u4_k_quil
          (wir_r, u4_atom_core, 
                sut, 
                u4_atom_soft,
                sut,
                _gull_fill(wir_r, u4_nul, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        return u4_k_trel
          (wir_r,
           u4_atom_fork,
           u4_k_cell(wir_r, u4_atom_cube, u4_yes),
           u4_k_cell(wir_r, u4_atom_cube, u4_no));
      }
      else if ( u4_b_pq(gen, u4_atom_flac, &p_gen, &q_gen) ) {
        return _rose_play(wir_r, _rose_play(wir_r, sut, p_gen), q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_pank, &p_gen, &q_gen) ) {
        return u4_k_quil
          (wir_r, u4_atom_core, 
                sut, 
                u4_atom_hard,
                sut,
                _gull_fill(wir_r, u4_nul, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_zalt, &p_gen) ) {
        return u4_k_cell(wir_r, u4_atom_cube, _rose_play(wir_r, sut, p_gen));
      }
      else if ( u4_b_p(gen, u4_atom_zond, &p_gen) ) {
        return u4_k_cell(wir_r, u4_atom_cube, _rose_make(wir_r, sut, p_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return u4_k_trel(wir_r, u4_atom_face, p_gen, _rose_play(wir_r, sut, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_sail, &p_gen, &q_gen) ) {
        return u4_atom_blur;
      }
      else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
        return u4_k_cell(wir_r, u4_atom_cube, p_gen); 
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        u4_noun qip;

        p->meb = u4_kc(wir_r, u4_kc(wir_r, u4_nul, p_gen), p->meb);
        qip = _rose_play(wir_r, sut, q_gen);
        p->meb = u4_ct(p->meb);

        return qip;
      }
      else if ( u4_b_pq(gen, u4_atom_stil, &p_gen, &q_gen) ) {
        return sut;
      }
      else if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(wir_r, sut, p_gen);
        u4_noun huz = _rose_play_a(wir_r, sut, q_gen);
        u4_noun q_lar = u4_ch(u4_ct(lar));
        u4_type r_lar = u4_ct(u4_ct(lar));

        if ( (u2_nul == q_lar) ) {
          return _rose_edit(wir_r, r_lar, huz);
        }
        else {
          u4_door uq_lar  = u4_ct(q_lar);
          u4_type quq_lar = u4_ch(u4_ct(uq_lar));
          u4_gene ruq_lar = u4_ct(u4_ct(uq_lar));
          u4_gene old     = gen;
          u4_noun p_sut, q_sut, r_sut, s_sut;

          sut = _rose_edit(wir_r, quq_lar, huz);
          gen = ruq_lar;

          if ( u4_b_pqrs(sut, u4_atom_core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
            if ( u4_n_eq(u4_atom_hard, q_sut) ) {
              sut = u4_k_quil(wir_r, u4_atom_core, r_sut, q_sut, r_sut, s_sut);
              if ( !(u2_nul == p->bug) ) {
                u4_err(wir_r, "hard: gen", old);
                u4_brut(wir_r, "hard: sut", sut);
                u4_brut(wir_r, "hard: mack", u4_kt(wir_r, u4_atom_hold, sut, gen));
                printf("\n");
              }
            } 
            else if ( u4_n_eq(u4_atom_soft, q_sut) ) {
              sut = sut;
              if ( !(u2_nul == p->bug) ) {
                u4_err(wir_r, "soft: gen", old);
                u4_brut(wir_r, "soft: sut", sut);
                u4_brut(wir_r, "soft: mack", u4_kt(wir_r, u4_atom_hold, sut, gen));
                printf("\n");
              }
            }
            else return u4_trip;
          }
          else return u4_trip;

          return u4_k_trel(wir_r, u4_atom_hold, sut, gen);
        }
      }
      else if ( u4_b_pqr(gen, u4_atom_trol, &p_gen, &q_gen, &r_gen) ) {
        return _rose_eith
          (wir_r,
           _rose_play(wir_r, _rose_gain(wir_r, sut, p_gen), q_gen),
           _rose_play(wir_r, sut, r_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_sing, &p_gen, &q_gen) ) {
        return u4_k_trel
          (wir_r,
           u4_atom_fork,
           u4_k_cell(wir_r, u4_atom_cube, u4_yes),
           u4_k_cell(wir_r, u4_atom_cube, u4_no));
      }
      else {
        return _rose_play(wir_r, sut, _plow_open(wir_r, gen)); 
      }
    }
  u4_type
  _rose_play(u2_ray  wir_r,
             u4_type sut,
             u4_gene gen)
  {
    
    u4_noun mum = u4_kc(wir_r, sut, gen);
    u4_nopt zod = u2_fj_book_get(mum, p->zor);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_type gur = _rose_play_main(wir_r, sut, gen);

      p->zor = u2_fj_book_add(wir_r, mum, gur, p->zor);
      return gur;
    }
  }

  /* repo:rose:plow
  */
  u4_type
  _rose_repo(u2_ray  wir_r,
             u4_type sut,
             u4_gene gen)
  {
    
    u4_noun vax = u4_k_cell(wir_r, sut, gen);

    if ( u2_fj_pool_in(vax, p->fan) ) {
      return _plow_fail(wir_r, "inference recursion");
    }
    else {
      u4_noun fan;
      u4_type gex;

      fan = p->fan;
      p->fan = u2_fj_pool_add(wir_r, vax, p->fan);

      gex = _rose_play(wir_r, sut, gen);
      p->fan = fan;
      return gex;
    }
  }

  /* seek:rose:plow
  */
    static u4_plan
    _rose_seek_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_rope rop,
                 u4_axis axe,
                 u4_unit act)
    {
      

      if ( (u2_nul == rop) ) {
        return u4_k_trel(wir_r, axe, act, sut);
      }
      else {
        u4_noun i_rop = u4_ch(rop);
        u4_noun t_rop = u4_ct(rop);
        u4_noun pi_rop;

        if ( u4_n_atom(i_rop) ) {
          return _rose_seek_a
            (wir_r, sut, 
                u4_k_cell(wir_r, u4_k_cell(wir_r, u4_atom_pane, i_rop), t_rop),
                axe,
                act);
        }
        else if ( u4_b_p(i_rop, u4_atom_frag, &pi_rop) ) {
          return _rose_seek_a
            (wir_r, _iris_peek(wir_r, sut, u4_nul, u4_axis_1, pi_rop), 
                t_rop,
                u4_op_peg(wir_r, axe, pi_rop),
                u4_nul);
        }
        else if ( u4_b_p(i_rop, u4_atom_pane, &pi_rop) ) {
          u4_plan sap = _iris_find(wir_r, sut, u4_nul, u4_axis_1, pi_rop);
          u4_axis p_sap = u4_ch(sap);
          u4_unit q_sap = u4_ch(u4_ct(sap));
          u4_type r_sap = u4_ct(u4_ct(sap));
#if 0
          if ( (u2_nul == pi_rop) ) {
            u4_err(wir_r, "blip: p", p_sap);
            u4_err(wir_r, "blip: q", q_sap);
            u4_err(wir_r, "blip: r", r_sap);
          }
#endif
          return _rose_seek_a
            (wir_r, r_sap, t_rop, u4_op_peg(wir_r, axe, p_sap), q_sap);
        }
        else return u4_trip;
      }
    }
  u4_plan
  _rose_seek(u2_ray  wir_r,
             u4_type sut,
             u4_rope rop)
  {
    return _rose_seek_a(wir_r, sut, rop, u4_axis_1, u4_nul);
  }

  /* show:rose:plow
  */
    u4_flag
    _rose_show_nest(u2_ray  wir_r,
                    u4_type sut,
                    u4_type bon)
    {
      if ( !u4_so(_iris_nest(wir_r, sut, u4_nul, u4_axis_1, bon)) ) {
        u4_brut(wir_r, "sut", sut);
        u4_brut(wir_r, "bon", bon);
        return _plow_fail(wir_r, "nest: show");
      }
      else {
        return u4_yes;
      }
    }
    static u4_plot
    _rose_show_a(u2_ray  wir_r,
                 u4_type sut,
                 u4_rack dus)
    {
      

      if ( (u2_nul == dus) ) {
        return u4_nul;
      }
      else {
        u4_noun i_dus = u4_ch(dus);
        u4_noun t_dus = u4_ct(dus);
        u4_gene pi_dus = u4_ch(i_dus);
        u4_gene qi_dus = u4_ct(i_dus);

        if ( !u4_so(_rose_show(wir_r, sut, qi_dus)) ) {
          return _plow_fail(wir_r, "show: take");
        }
        else {
          u4_type feg    = _rose_play(wir_r, sut, qi_dus);

          return u4_k_cell
            (wir_r,
             u4_k_cell(wir_r, pi_dus, feg),
             _rose_play_a(wir_r, sut, t_dus));
        }
      }
    }
    u4_flag
    _rose_show_main(u2_ray  wir_r,
                    u4_type sut,
                    u4_gene gen)
    {
      
      u4_noun p_gen, q_gen, r_gen;

      if ( u4_b_p(gen, u4_atom_zike, &p_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_p(gen, u4_atom_zoot, &p_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_p(gen, u4_atom_vint, &p_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show_nest
                          (wir_r, u4_atom_atom, _rose_play(wir_r, sut, p_gen)));
      }
      else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
        return u4_and
          (_rose_show(wir_r, sut, p_gen),
           u4_and
            (_rose_show(wir_r, sut, q_gen),
             _rose_show_nest(wir_r, _rose_play(wir_r, sut, p_gen),
                                _rose_play(wir_r, sut, q_gen))));
      }
      else if ( u4_b_pq(gen, u4_atom_twix, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen), _rose_show(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_wost, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
        u4_flag zic;
        u4_atom bug;

        bug = p->bug;
        p->bug = u4_op_inc(wir_r, p->bug);

        zic = _rose_show(wir_r, sut, p_gen);
        
        p->bug = bug;
        return zic;
      }
      else if ( u4_b_p(gen, u4_atom_dust, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_germ, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_hint, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_grit, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_tash, &p_gen, &q_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(gen, u4_atom_plin, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen), 
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_flac, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, _rose_play(wir_r, sut, p_gen), q_gen));
      }
      else if ( u4_b_pq(gen, u4_atom_pank, &p_gen, &q_gen) ) {
        sut = _rose_play(wir_r, sut, gen);

        while ( !(u2_nul == q_gen) ) {
          u4_noun iq_gen = u4_ch(q_gen);
          u4_noun tq_gen = u4_ct(q_gen);
          u4_noun qiq_gen = u4_ct(iq_gen);

          if ( !u4_so(_rose_show(wir_r, sut, qiq_gen)) ) {
            return _plow_fail(wir_r, "menu fail");
          }
          q_gen = tq_gen;
        }
        return u4_yes;
      }
      else if ( u4_b_p(gen, u4_atom_zalt, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u4_b_p(gen, u4_atom_zond, &p_gen) ) {
        return _rose_show(wir_r, sut, p_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_bran, &p_gen, &q_gen) ) {
        return _rose_show(wir_r, sut, q_gen);
      }
      else if ( u4_b_pq(gen, u4_atom_sail, &p_gen, &q_gen) ) {
        return u4_and(_rose_show(wir_r, sut, p_gen),
                      _rose_show(wir_r, sut, q_gen));
      }
      else if ( u4_b_p(gen, u4_atom_bone, &p_gen) ) {
        return u4_yes;
      }
      else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
        u4_noun qip;

        p->meb = u4_kc(wir_r, u4_kc(wir_r, u4_nul, p_gen), p->meb);
        qip = _rose_show(wir_r, sut, q_gen);
        p->meb = u4_ct(p->meb);

        return qip;
      }
      else if ( u4_b_pq(gen, u4_atom_stil, &p_gen, &q_gen) ) {
        return u4_and
          (_rose_show(wir_r, sut, p_gen),
           u4_and
            (_rose_show(wir_r, sut, q_gen),
             _rose_show_nest
              (wir_r, _rose_play(wir_r, sut, p_gen), _rose_play(wir_r, sut, q_gen))));
      }
      else if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
        u4_plan lar = _rose_seek(wir_r, sut, p_gen);
        u4_noun huz = _rose_show_a(wir_r, sut, q_gen);
        u4_noun q_lar = u4_ch(u4_ct(lar));

        if ( (u2_nul == q_lar) ) {
          return u4_yes;
        }
        else {
          u4_door uq_lar  = u4_ct(q_lar);
          u4_type quq_lar = u4_ch(u4_ct(uq_lar));
          u4_gene ruq_lar = u4_ct(u4_ct(uq_lar));
          u4_noun p_sut, q_sut, r_sut, s_sut;

          sut = _rose_edit(wir_r, quq_lar, huz);
          gen = ruq_lar;

          if ( u4_b_pqrs(sut, u4_atom_core, &p_sut, &q_sut, &r_sut, &s_sut) ) {
            if ( u4_n_eq(u4_atom_hard, q_sut) ) {
              return _rose_show_nest(wir_r, r_sut, p_sut);
            }
            else if ( u4_n_eq(u4_atom_soft, q_sut) ) {
              u4_noun fuy = u4_k_cell(wir_r, sut, gen);

              if ( u2_fj_pool_in(fuy, p->ver) ) {
                return u4_yes;
              } else {
                u4_type  gim = u4_k_quil
                    (wir_r, u4_atom_core, r_sut, q_sut, r_sut, s_sut);
                u4_pool   rev = p->ver;
                u4_flag  goh;

                p->ver = u2_fj_pool_add(wir_r, fuy, p->ver);
                goh = u4_and
                  (_rose_show(wir_r, sut, gen),
                   u4_say(u4_n_eq(_rose_make(wir_r, sut, gen), 
                                  _rose_make(wir_r, gim, gen))));

                p->ver = rev;
                if ( !u4_so(goh) ) {
                  u4_err(wir_r, "gen", gen);
                  u4_err(wir_r, "mka", _rose_make(wir_r, sut, gen));
                  u4_err(wir_r, "mkb", _rose_make(wir_r, gim, gen));
                  return _plow_fail(wir_r, "soft mack");
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
          (_rose_show(wir_r, sut, p_gen),
           u4_and
           (_rose_show(wir_r, _rose_gain(wir_r, sut, p_gen), q_gen),
            _rose_show(wir_r, sut, r_gen)));
      }
      else if ( u4_b_pq(gen, u4_atom_sing, &p_gen, &q_gen) ) {
        return u4_and
          (_rose_show(wir_r, sut, p_gen),
           _rose_show(wir_r, sut, q_gen));
      }
      else {
        u4_gene vul = _plow_open(wir_r, gen);

        if ( u4_n_eq(vul, gen) ) {
          u4_err(wir_r, "gen", gen);
          u4_err(wir_r, "vul", vul);
          return u4_trip;
        }

        return _rose_show(wir_r, sut, vul);
      }
    }
  u4_flag
  _rose_show(u2_ray  wir_r,
             u4_type sut,
             u4_gene gen)
  {
#if 0
    return u4_yes;
#else
    
    u4_noun mum = u4_kc(wir_r, sut, gen);
    u4_nopt zod = u2_fj_book_get(mum, p->hos);

    if ( zod != u4_bull ) {
      return zod;
    }
    else {
      u4_flag gur = _rose_show_main(wir_r, sut, gen);

      p->hos = u2_fj_book_add(wir_r, mum, gur, p->hos);
      return gur;
    }
#endif
  }


/****   _plow: top-level functions.
****/
  void
  _plow_trap(u2_ray  wir_r,
             const char *msg)
  {
    

    u4_atom hal  = u4_k_atom_c(wir_r, msg);

    p->meb = u4_k_cell(wir_r, u4_k_cell(wir_r, hal, u4_nul), p->meb);
  }

  u4_noun
  _plow_fail(u2_ray  wir_r,
             const char *msg)
  {
    _plow_trap(wir_r, msg);
    {
      while ( !(u2_nul == p->meb) ) {
        u4_noun i_meb = u4_ch(p->meb);
        u4_noun hal = u4_ch(i_meb);
        u4_noun jup = u4_ct(i_meb);

        if ( !(u2_nul == hal) ) {
          u4_sb sb_hal = u4_a_bin(hal, 3);
          u4_cl *cl_hal = alloca(sb_hal + 1);

          u4_a_bytes(hal, (u4_xb *)cl_hal, 0, sb_hal + 1);
          printf("msg: %s\n", cl_hal);
        }

        if ( !(u2_nul == jup) ) {
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
  _plow_rake(u2_ray  wir_r,
             u4_gene gen)
  {
    
    u4_gene p_gen, q_gen;

    if ( u4_b_pq(gen, u4_atom_mack, &p_gen, &q_gen) ) {
      if ( !(u2_nul == q_gen) ) {
        return _plow_fail(wir_r, "rope");
      }
      else return p_gen;
    }
    else if ( u4_b_p(gen, u4_atom_frag, &p_gen) ) {
      return u4_kl(wir_r, gen);
    }
    else if ( u4_b_p(gen, u4_atom_pane, &p_gen) ) {
      return u4_kl(wir_r, gen);
    }
    else if ( u4_b_pq(gen, u4_atom_zemp, &p_gen, &q_gen) ) {
      return _plow_rake(wir_r, q_gen);
    }
    else if ( u4_b_p(gen, u4_atom_zush, &p_gen) ) {
      return _plow_rake(wir_r, p_gen);
    }
    else {
      u4_err(wir_r, "rake", gen);
      return _plow_fail(wir_r, "rope");
    }
  }

  /* init:plow (fake)
  */
  void
  u4_plow_init(u2_ray  wir_r,
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
  u4_plow_make(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return _rose_make(wir_r, sut, gen);
  }

  /* play:plow (fake)
  */
  u4_noun
  u4_plow_play(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return _rose_play(wir_r, sut, gen);
  }

  /* show:plow (fake)
  */
  u4_noun
  u4_plow_show(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return _rose_show(wir_r, sut, gen);
  }

  /* pass:plow (fake)
  */
  u4_noun
  u4_plow_pass(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    if ( !u4_so(_rose_show(wir_r, sut, gen)) ) {
      return u4_exit;
    }
    else return _rose_make(wir_r, sut, gen);
  }

  /* shop:plow (fake)
  */
  u4_noun
  u4_plow_shop(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    if ( !u4_so(_rose_show(wir_r, sut, gen)) ) {
      return u4_exit;
    }
    else return _rose_play(wir_r, sut, gen);
  }

  /* wish:plow (fake)
  */
  u4_noun
  u4_plow_wish(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    return 
      u4_kc(wir_r, _rose_play(wir_r, sut, gen),
                 _rose_make(wir_r, sut, gen));
  }

  /* shop:plow (fake)
  */
  u4_noun
  u4_plow_mill(u2_ray  wir_r,
               u4_type sut,
               u4_gene gen)
  {
    u4_plow p = PlowInit(lan);

    if ( !u4_so(_rose_show(wir_r, sut, gen)) ) {
      return u4_exit;
    }
    else return 
      u4_kc(wir_r, _rose_play(wir_r, sut, gen),
                 _rose_make(wir_r, sut, gen));
  }

