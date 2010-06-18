/* include/watt/pitt.h
**
** This file is in the public domain.
*/
  /** Container types by current nomenclature.
  **/
    typedef u4_log  u4_list;
    typedef u4_bag  u4_pool;
    typedef u4_tab  u4_book;

  /** Noun types.  See kernel for definition.
  **/
    typedef u4_noun u4_bank;
    typedef u4_noun u4_cord;
    typedef u4_noun u4_door;
    typedef u4_noun u4_gene;
    typedef u4_noun u4_home;
    typedef u4_noun u4_init;
    typedef u4_noun u4_menu;
    typedef u4_noun u4_plan;
    typedef u4_noun u4_plot;
    typedef u4_noun u4_rack;
    typedef u4_noun u4_rail;
    typedef u4_noun u4_rope;
    typedef u4_noun u4_seed;
    typedef u4_noun u4_spec;
    typedef u4_noun u4_spot;
    typedef u4_noun u4_type;
    typedef u4_noun u4_tool;

  /** Yes and no.
  **/
    #define u4_yes        u4_noun_0
    #define u4_no         u4_noun_1

    #define u4_so(x)      u4_n_zero(x)
    #define u4_say(x)     ( (x) ? u4_noun_0 : u4_noun_1 )
    #define u4_and(x, y)  ( (u4_so(x) && u4_so(y)) ? u4_yes : u4_no )
    #define u4_or(x, y)   ( (u4_so(x) || u4_so(y)) ? u4_no : u4_yes )

    /* The main pitt structure.
    */
      typedef struct _u4_pitt {
        /* For all internal allocation.
        */
        u4_lane lane;

        /* Internal counter for perf testing.
        */
        uint32_t prf;

        /* Set [*type *gene] in repo.
        */
        u4_bag fan;

        /* Set [*type] in verify.
        */
        u4_bag ver;

        /* Debug depth.
        */
        u4_atom bug;

        /* Home (source file).
        */
        u4_noun zud;

        /* Spot (position in source).
        */
        u4_spot nix;

        /* Trap - ((list {[p=*text q=*site r=*spot]}))
        */
        u4_noun meb;
      } 
        *u4_pitt;
