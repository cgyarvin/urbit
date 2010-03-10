/* include/mill/mill.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* Some kinds of nouns.
    */
      typedef u4_noun u4_lump;  //  *
      typedef u4_noun u4_gene;  //  see _mill_gene()
      typedef u4_atom u4_axis;  //  @
      typedef u4_atom u4_term;  //  @ 
      typedef u4_atom u4_mark;  //  @ 
      typedef u4_atom u4_bead;  //  @ 
      typedef u4_atom u4_tick;  //  @
      typedef u4_noun u4_herb;  //  [type gene]
      typedef u4_noun u4_pike;  //  see _mill_gene_pike()
      typedef u4_noun u4_spec;  //  lambda spec
      typedef u4_noun u4_bone;  //  pattern boneeton
      typedef u4_noun u4_bolo;  //  {list pike}
      typedef u4_noun u4_plox;  //  {list glep}
      typedef u4_noun u4_glep;  //  [tape type]
      typedef u4_noun u4_curb;  //  [axis term]
      typedef u4_noun u4_loaf;  //  [type form]
      typedef u4_noun u4_wire;  //  [type form]
      typedef u4_noun u4_rail;  //  {list type}
      typedef u4_noun u4_knot;  //  |(  (term) 
                                //      [%zarb @] 
                                //      [%lect (tick) (term)]
                                //   )
      typedef u4_noun u4_bait;  //  |(  (%zarb @)
                                //      [%lect @ (tick) (term)]
                                //  )
      typedef u4_noun u4_lure;  //  {list bait}
      typedef u4_noun u4_rope;  //  {list knot}
      typedef u4_noun u4_nail;  //  [rope gene] 
      typedef u4_noun u4_tack;  //  |([%axis axis] [%term term])
      typedef u4_noun u4_weld;  //  [axis form]
      typedef u4_noun u4_bolt;  //  {list nail}
      typedef u4_noun u4_tape;  //  {list tack}
      typedef u4_noun u4_belt;  //  {list weld}
      typedef u4_noun u4_carb;  //  [axis gene]
      typedef u4_noun u4_hair;  //  [term type]
      typedef u4_noun u4_cope;  //  {list hair}
      typedef u4_noun u4_form;  //  [formula]
      typedef u4_noun u4_clip;  //  {bush gene}

      typedef u4_noun u4_type;

    /* The main mill structure.
    */
      typedef struct _u4_mill {
        /* For all internal allocation.
        */
        u4_lane lane;

        /* Set (type gene) currently in replay (aka repo).
        */
        u4_bag fan;

        /* Debug depth.
        */
        u4_atom rux;

        /* Site (source package being compiled, in top-level safe)
        */
        u4_noun zud;

        /* Spot (position in source).
        */
        u4_noun nix;

        /* 0 iff we are producing type.
        */
        u4_atom ply;

        /* 0 iff we are producing formula.
        */
        u4_atom bak;

        /* Trap - ((list {[p=(text) q=(site) r=(spot)]}))
        */
        u4_noun meb;

        /* Tab to memoize _mill_bake().
        */
        u4_tab niq;

        /* Tab to memoize _mill_play().
        */
        u4_tab zor;

        /* Tab (type flag) to memoize _mill_null().
        */
        u4_tab dam;

        /* Tab ((type type) flag) to memoize _mill_cong().
        */
        u4_tab vus;
      } 
        *u4_milr;


  /** Functions.
  **/
    /** Public interfaces.
    **/
      /* u4_mill(): 
      **
      **   Convert (type gene) to (type form).
      */
        u4_wire
        u4_mill(u4_lane lane,
                u4_type nes,
                u4_gene zyl);

      /* u4_mill_init(): 
      **
      **   Initialize (m) with (lane).
      */
        void
        u4_mill_init(u4_milr m,
                     u4_lane lane);


    /** Private functions.
    **/
      /* _mill_and(): make and.
      */
        u4_form
        _mill_and(u4_milr m,
                  u4_form zeg,
                  u4_form dac);

      /* _mill_or(): make or.
      */
        u4_form
        _mill_or(u4_milr m,
                 u4_form bos,
                 u4_form nif);

      /* _mill_bake(): mill and discard type.
      */
        u4_form
        _mill_bake(u4_milr m, 
                   u4_type tip,
                   u4_gene gen);

      /* _mill_both(): fuse pair.
      */
        u4_form
        _mill_both(u4_milr m,
                   u4_type nem,
                   u4_type dif);

      /* _mill_comp(): compose a pipe.
      */
        u4_form
        _mill_comp(u4_milr m,
                   u4_form mal,
                   u4_form buz);

      /* _mill_cong(): true if every tip is a gan.
      */
        u4_t
        _mill_cong(u4_milr m,
                   u4_type gan,
                   u4_type tip);

      /* _mill_cons(): construct cell.
      */
        u4_form
        _mill_cons(u4_milr m,
                   u4_form vor,
                   u4_form sed);

      /* _mill_cook(): cook a gene, producing formula and type.
      */
        u4_type
        _mill_cook(u4_milr m, 
                   u4_gene gen,
                   u4_type tip);

      /* _mill_cull(): prune for computation.
      */
        u4_t
        _mill_cull(u4_milr m,
                   u4_rail bar,
                   u4_type tip);

      /* _mill_dump(): prepare type for printing.
      */
        u4_prep
        _mill_dump(u4_milr m,
                   u4_type tip);

      /* _mill_durb(): prepare rail for printing.
      */
        u4_prep
        _mill_durb(u4_milr m,
                   u4_rail bar);

      /* _mill_edit(): edit a type to reflect a list of writes.
      */
        u4_type
        _mill_edit(u4_milr m,
                   u4_plox zel,
                   u4_rail bar,
                   u4_type gom);

      /* _mill_eith(): fork pair.
      */
        u4_type
        _mill_eith(u4_milr m,
                   u4_type lef,
                   u4_type gap);

      /* _mill_fail(): failage.
      */
        u4_noun
        _mill_fail(u4_milr m,
                   const u4_cl *cl_msg);

      /* _mill_find(): look by name.
      */
        u4_wire
        _mill_find(u4_milr m,
                   u4_term cox,
                   u4_rail bar,
                   u4_type tip);

      /* _mill_fire(): fire [tel hum] as (gate arg).
      */
        u4_form
        _mill_fire(u4_milr m,
                   u4_form tel,
                   u4_form hum);

      /* _mill_fish(): test form.
      */
        u4_form
        _mill_fish(u4_milr m,
                   u4_axis axe,
                   u4_type tip);

      /* _mill_gate(): gate from bone.
      */
        u4_gene
        _mill_gate(u4_milr m,
                   u4_bone kel);

      /* _mill_grip(): generate match gene. 
      */
        u4_gene
        _mill_grip(u4_milr m,
                   u4_bone kel);

      /* _mill_hike(): mutate formula.
      */
        u4_form
        _mill_hike(u4_milr m,
                   u4_axis axe,
                   u4_belt vix);

      /* _mill_hunt(): rope to tape.
      */
        u4_tape
        _mill_hunt(u4_milr m,
                   u4_rope dap,
                   u4_type fim,
                   u4_axis *axe,
                   u4_type *buv);

      /* _mill_hunt(): analyze branch test.
      */
        u4_noun
        _mill_test(u4_milr m,
                   u4_type tip,
                   u4_gene gen);

      /* _mill_look(): read on a rope.
      */
        u4_wire
        _mill_look(u4_milr m,
                   u4_rope fes,
                   u4_type tip);

      /* _mill_lump(): generate direct bone.
      */
        u4_gene
        _mill_lump(u4_milr m,
                   u4_bone kel);

      /* _mill_make(): type inference, top level.
      */
        u4_wire
        _mill_make(u4_milr m,
                   u4_gene gen,
                   u4_type tip);

      /* _mill_nest(): test geometric congruence.
      **
      **    [gan] is geometrically congruent with [tip] iff 
      **    every noun in [gan] is also in [tip].
      */
        u4_t
        _mill_nest(u4_milr m,
                   u4_type gan,
                   u4_type tip);

      /* _mill_not(): invert boolean.
      */
        u4_type
        _mill_not(u4_milr m,
                  u4_form zet);

      /* _mill_null(): true if type is empty.
      */
        u4_t
        _mill_null(u4_milr m,
                   u4_type tip);

      /* _mill_orth(): orthogonality.
      */
        u4_t
        _mill_orth(u4_milr m,
                   u4_type tip,
                   u4_type gan);

      /* _mill_open(): open macro gene.
      */
        u4_gene
        _mill_open(u4_milr m,
                   u4_noun nim);

      /* _mill_peek(): cut a railed type.
      */
        u4_type
        _mill_peek(u4_milr m,
                   u4_axis axe,
                   u4_rail bar,
                   u4_type tip);

      /* _mill_pike: open pike.  *tes is the test, *bif is yes.
      */
        void
        _mill_pike(u4_milr m,
                   u4_rope mox, 
                   u4_pike pik,
                   u4_gene *tes,
                   u4_gene *bif);

      /* _mill_play(): mill and discard formula.
      */
        u4_type
        _mill_play(u4_milr m, 
                   u4_type tip,
                   u4_gene gen);

      /* _mill_reap(): expand type.
      */
        u4_type
        _mill_reap(u4_milr m,
                   u4_type tip);

      /* _mill_repo(): replay post.
      */
        u4_type
        _mill_repo(u4_milr m,
                   u4_type tip,
                   u4_gene gen);

      /* _mill_salt(): modify a change target.
      **
      **    suc: changes:  bolt
      **    pex: subject:  type
      **    fuz: target:   type
      **    ped: fragment: axis
      */
        u4_loaf
        _mill_salt(u4_milr m,
                   u4_bolt suc,
                   u4_type pex,
                   u4_type fuz,
                   u4_axis ped);

      /* _mill_seal(): produce set of holds sealing [typ].
      */
        u4_bag
        _mill_seal(u4_milr m,
                   u4_type typ);

      /* _mill_slip(): hack entire bar.
      */
        u4_type
        _mill_slip(u4_milr m,
                   u4_axis axe,
                   u4_rail bar);

      /* _mill_snap(): adjust [ger] for assignment into [lom].
      */
        u4_type
        _mill_snap(u4_milr m,
                   u4_type lom,
                   u4_type ger);

      /* _mill_trap(): save trap.
      */
        void
        _mill_trap(u4_milr m,
                   const u4_cl *cl_msg);
