/* The boot parser for watt.
**
** This file is in the public domain.
*/

/* Pre-bison prologue.
*/
%{
# include "u4/all.h"

  /* Everything is a noun - no yacc type declarations!
  */
#   define YYSTYPE u4_noun

  /* Our fake scanner.
  */
    struct _u4_scanner {
      u4_lane lane;     /* lane for computation */
      u4_noun scan;     /* result - set by parser */

      /* Per-parse state.
      */
      struct {
        u4_log  site;   /* listmark - path from top to part */
        u4_atom tube;   /* part data (ie, source document) */
        u4_tab  bowl;   /* parts - (mark sack). */
      } p;
      
      /* Scanning state.
      */
      struct {
        uint32_t token;    /* initial type token, if any */
        u4_pb    pb;       /* byte position */
        u4_xw    xw_line;  /* current line */
        u4_xw    xw_col;   /* current column */
      } s;
    };
#   define yylane (scanner->lane)

  /* Forward declarations.
  */
    static u4_noun _watt_parse_part(struct _u4_scanner *, u4_noun);
    static u4_noun _watt_locate(u4_lane, const void *, u4_noun);

  /* Construction macros.
  */
#   define _ycell(a, b)         u4_k_cell(yylane, a, b)
#   define _ytrel(a, b, c)      u4_k_trel(yylane, a, b, c)
#   define _yqual(a, b, c, d)   u4_k_qual(yylane, a, b, c, d)
%}

/* Bison directives.
*/
  /* Start tokens for vere and hume respectively.
  */
  %token T_vere
  %token T_hume

  /* With the mighty power of GLR... 
  */
  %glr-parser
 
  /* We laugh at your petty shift-reduce conflicts.
  */
  %expect 854

  %pure-parser
  %locations
  %parse-param {struct _u4_scanner *scanner}
  %lex-param {struct _u4_scanner *scanner}


/* Support routines.
*/
%{
%}

%%

file 
  : g gene g        { scanner->scan = $2; }
  | T_vere g vere g { scanner->scan = $3; }
  | T_hume g hume g { scanner->scan = $3; }
  ;

gene
  : tall
  | wide
  ;

wide
  : wide_core
  ;

wide_core
  : wide_odd
  | wide_norm
  ;

  /** Irregular wide productions.
  **/
    wide_odd
      : rope  
        { $$ = _ytrel(u4_atom_kick, $1, u4_noun_0); }
      | rope '(' nail_wide_star ')'
        { $$ = _ytrel(u4_atom_kick, $1, $3); }
      | '[' g item_wide_some ']'
        { $$ = _ycell(u4_atom_cret, $3); }
      | '(' g wide_some ')'
        { $$ = _ytrel(u4_atom_garc, u4_ch($3), u4_ct($3)); }
      | wide_constant
      ;

    wide_constant
      : tok_delm
        { $$ = _ycell(u4_atom_palt, $1); }
      | '&'               
        { $$ = _ycell(u4_atom_palt, u4_noun_0); }
      | '|' 
        { $$ = _ycell(u4_atom_palt, u4_noun_1); }
      | '0' 'x' tok_chex
        { $$ = _ycell(u4_atom_palt, $3); }
      | tok_loct
        { $$ = _ycell(u4_atom_palt, $1); }
      | '%' tok_mark
        { $$ = _ycell(u4_atom_rock, $2); }
      | '%' tok_delm
        { $$ = _ycell(u4_atom_rock, $2); }
      | '%' '%'
        { $$ = _ycell(u4_atom_rock, u4_noun_0); }
      | '~'
        { $$ = _ycell(u4_atom_rock, u4_noun_0); }
      | '!''!'
        { $$ = _ycell(u4_atom_bail, u4_noun_0); }
      ;
  
  /** Regular wide productions.
  **/
    wide_norm
      : dig_pont wide_norm_pont  /* => */ { $$ = _ycell($1, $2); }
      | dig_clet wide_norm_clet  /* =< */ { $$ = _ycell($1, $2); }
      | dig_trop wide_norm_trop  /* -> */ { $$ = _ycell($1, $2); }
      | dig_prec wide_norm_prec  /* -< */ { $$ = _ycell($1, $2); }
      | dig_link wide_norm_link  /* ~> */ { $$ = _ycell($1, $2); }
      | dig_colb wide_norm_colb  /* ~< */ { $$ = _ycell($1, $2); }

      | dig_quiz wide_norm_quiz  /* ?: */ { $$ = _ycell($1, $2); }
      | dig_feng wide_norm_feng  /* ?> */ { $$ = _ycell($1, $2); }
      | dig_prex wide_norm_prex  /* ?< */ { $$ = _ycell($1, $2); }
      | dig_gril wide_norm_gril  /* ?- */ { $$ = _ycell($1, $2); }
      | dig_stam wide_norm_stam  /* ?+ */ { $$ = _ycell($1, $2); }
      | dig_boce wide_norm_boce  /* ?& */ { $$ = _ycell($1, $2); }
      | dig_dast wide_norm_dast  /* ?| */ { $$ = _ycell($1, $2); }
      | dig_blem wide_norm_blem  /* ?! */ { $$ = _ycell($1, $2); }
      | dig_like wide_norm_like  /* ?= */ { $$ = _ycell($1, $2); }
/*
      | dig_malk wide_norm_malk  ** |+ ** { $$ = _ycell($1, $2); }
      | dig_blin wide_norm_blin  ** |* ** { $$ = _ycell($1, $2); }
*/
      | dig_flic wide_norm_flic  /* |: */ { $$ = _ycell($1, $2); }
      | dig_drol wide_norm_drol  /* || */ { $$ = _ycell($1, $2); }
      | dig_lome wide_norm_lome  /* |= */ { $$ = _ycell($1, $2); }
      | dig_flot wide_norm_flot  /* |- */ { $$ = _ycell($1, $2); }

      | dig_cast wide_norm_cast  /* ^+ */ { $$ = _ycell($1, $2); }
      | dig_sure wide_norm_sure  /* ^= */ { $$ = _ycell($1, $2); }
      | dig_rald wide_norm_rald  /* ^* */ { $$ = _ycell($1, $2); }
      | dig_crot wide_norm_crot  /* ^@ */ { $$ = _ycell($1, $2); }

      | dig_kick wide_norm_kick  /* := */ { $$ = _ycell($1, $2); }
      | dig_mang wide_norm_mang  /* :~ */ { $$ = _ycell($1, $2); }
      | dig_garc wide_norm_garc  /* :+ */ { $$ = _ycell($1, $2); }
      | dig_flec wide_norm_flec  /* :- */ { $$ = _ycell($1, $2); }
      | dig_cret wide_norm_cret  /* :* */ { $$ = _ycell($1, $2); }
      | dig_cage wide_norm_cage  /* :. */ { $$ = _ycell($1, $2); }
      | dig_grun wide_norm_grun  /* :% */ { $$ = _ycell($1, $2); }
      | dig_bink wide_norm_bink  /* :^ */ { $$ = _ycell($1, $2); }

      | dig_griv wide_norm_griv  /* && */ { $$ = _ycell($1, $2); }
      | dig_veck wide_norm_veck  /* &: */ { $$ = _ycell($1, $2); }
      | dig_neft wide_norm_neft  /* &^ */ { $$ = _ycell($1, $2); }
      | dig_wamp wide_norm_wamp  /* &= */ { $$ = _ycell($1, $2); }
      | dig_spil wide_norm_spil  /* &~ */ { $$ = _ycell($1, $2); }
      ;

    /** Combinators.
    **/
      wide_norm_pont
        : '{' g tok_mark w wide w wide g '}' { $$ = _ytrel($3, $5, $7); }

      wide_norm_clet
        : '{' g tok_mark w wide w wide g '}' { $$ = _ytrel($1, $3, $5); }

      wide_norm_trop
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_prec
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_link
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_colb 
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }


    /** Branches.
    **/
      wide_norm_quiz
        : '{' g wide w wide w wide g '}' { $$ = _ytrel($1, $3, $5); }

      wide_norm_feng
        : '{' g wide w wide g '}' { $$ = _ycell($1, $3); }

      wide_norm_prex
        : '{' g wide w wide g '}' { $$ = _ycell($1, $3); }

      wide_norm_gril
        : '{' g rope ':' w pike_wide_star '}' { $$ = _ycell($3, $6); }

      wide_norm_stam
        : '{' g wide ':' w pike_wide_star '}' { $$ = _ycell($3, $6); }

      wide_norm_boce
        : '{' g wide_star '}' { $$ = $3; }
      
      wide_norm_dast
        : '{' g wide_star '}' { $$ = $3; }
   
      wide_norm_blem
        : wide
   
      wide_norm_like
        : '{' g rope g wide g '}' { $$ = _ycell($3, $5); }
   

    /** Loading.
    **/
/*
      wide_norm_malk
        : page_star dig_lome { $$ = $1; }
   
      wide_norm_blin
        : wide w page_star dig_lome { $$ = _ycell($1, $3); }
*/
      wide_norm_flic
        : '{' g skel_w w wide g '}'{ $$ = _ycell($3, $5); }

      wide_norm_drol
        : '{' g skel_w w skel_w w wide g '}'{ $$ = _ytrel($3, $5, $7); }

      wide_norm_lome
        : wide

      wide_norm_flot
        : wide
    
    /** Casts.
    **/
      wide_norm_cast
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_sure
        : '{' g wide w wide w wide g '}' { $$ = _ycell($3, $3); }

      wide_norm_rald
        : wide

      wide_norm_crot
        : wide

    /** Funky stuff.
    **/
      wide_norm_kick
        : '{' g wide w nail_wide_star '}' { $$ = _ycell($3, $5); }

      wide_norm_mang
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_garc
        : '{' g wide w wide_some '}' { $$ = _ycell($3, $5); }

      wide_norm_flec
        : wide 

      wide_norm_cret
        : '{' g item_wide_some '}' { $$ = $3; }

      wide_norm_cage
        : '{' g wide_some '}' { $$ = $3; }

      wide_norm_grun
        : '{' g nail_wide_star ':' w wide '}' { $$ = _ycell($3, $6); }

      wide_norm_bink
        : skel_w

    /** Roots.
    **/
      wide_norm_griv
        : '{' g wide w hume '}' { $$ = _ycell($3, $5); }
 
      wide_norm_veck
        : wide

      wide_norm_neft
        : wide

      wide_norm_wamp
        : wide

      wide_norm_spil
        : wide

  ;

tall
  : tall_norm { $$ = _watt_locate(yylane, &@1, $1); }
  /* | tall_leaf */
  ;

  /** Normal tall genes.
  **/
    tall_norm
      : dig_pont w tall_norm_pont  /* => */ { $$ = _ycell($1, $3); }
      | dig_clet w tall_norm_clet  /* =< */ { $$ = _ycell($1, $3); }
      | dig_trop w tall_norm_trop  /* -> */ { $$ = _ycell($1, $3); }
      | dig_prec w tall_norm_prec  /* -< */ { $$ = _ycell($1, $3); }
      | dig_link w tall_norm_link  /* ~> */ { $$ = _ycell($1, $3); }
      | dig_colb w tall_norm_colb  /* ~< */ { $$ = _ycell($1, $3); }

      | dig_quiz w tall_norm_quiz  /* ?: */ { $$ = _ycell($1, $3); }
      | dig_feng w tall_norm_feng  /* ?> */ { $$ = _ycell($1, $3); }
      | dig_prex w tall_norm_prex  /* ?< */ { $$ = _ycell($1, $3); }
      | dig_gril w tall_norm_gril  /* ?- */ { $$ = _ycell($1, $3); }
      | dig_stam w tall_norm_stam  /* ?+ */ { $$ = _ycell($1, $3); }
      | dig_boce w tall_norm_boce  /* ?& */ { $$ = _ycell($1, $3); }
      | dig_dast w tall_norm_dast  /* ?| */ { $$ = _ycell($1, $3); }
      | dig_blem w tall_norm_blem  /* ?! */ { $$ = _ycell($1, $3); }
      | dig_like w tall_norm_like  /* ?= */ { $$ = _ycell($1, $3); }
    
      | dig_malk w tall_norm_malk  /* |+ */ { $$ = _ycell($1, $3); }
      | dig_blin w tall_norm_blin  /* |* */ { $$ = _ycell($1, $3); }
      | dig_flic w tall_norm_flic  /* |: */ { $$ = _ycell($1, $3); }
      | dig_drol w tall_norm_drol  /* || */ { $$ = _ycell($1, $3); }
      | dig_lome w tall_norm_lome  /* |= */ { $$ = _ycell($1, $3); }
      | dig_flot w tall_norm_flot  /* |- */ { $$ = _ycell($1, $3); }

      | dig_cast w tall_norm_cast  /* ^+ */ { $$ = _ycell($1, $3); }
      | dig_sure w tall_norm_sure  /* ^= */ { $$ = _ycell($1, $3); }
      | dig_rald w tall_norm_rald  /* ^- */ { $$ = _ycell($1, $3); }
      | dig_crot w tall_norm_crot  /* ^- */ { $$ = _ycell($1, $3); }

      | dig_kick w tall_norm_kick  /* := */ { $$ = _ycell($1, $3); }
      | dig_mang w tall_norm_mang  /* :~ */ { $$ = _ycell($1, $3); }
      | dig_garc w tall_norm_garc  /* :+ */ { $$ = _ycell($1, $3); }
      | dig_flec w tall_norm_flec  /* :- */ { $$ = _ycell($1, $3); }
      | dig_cret w tall_norm_cret  /* :* */ { $$ = _ycell($1, $3); }
      | dig_cage w tall_norm_cage  /* :. */ { $$ = _ycell($1, $3); }
      | dig_grun w tall_norm_grun  /* :% */ { $$ = _ycell($1, $3); }
      | dig_bink w tall_norm_bink  /* :^ */ { $$ = _ycell($1, $3); }
   
      | dig_griv w tall_norm_griv  /* && */ { $$ = _ycell($1, $3); }
      | dig_veck w tall_norm_veck  /* &: */ { $$ = _ycell($1, $3); }
      | dig_neft w tall_norm_neft  /* &^ */ { $$ = _ycell($1, $3); }
      | dig_wamp w tall_norm_wamp  /* &= */ { $$ = _ycell($1, $3); }
      | dig_spil w tall_norm_spil  /* &~ */ { $$ = _ycell($1, $3); }

      | dig_dbug w tall_norm_dbug  /* !? */ { $$ = _ycell($1, $3); }
      ;

    /** Combinators.
    **/
      tall_norm_pont
        /*  =>    [%pont han=mark dur=gene leb=gene]
        **
        **    pont: use [leb] under [[han=dur] +]
        */
        : tok_mark w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_clet
        /*  =<    [%clet han=mark dur=gene leb=gene]
        **
        **    clet: use [dur] under [[han=leb] +]
        */
        : tok_mark w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_trop
        /*  ->    [%trop hig=gene muc=gene]
        **
        **    trop: use [muc] under [hig +]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_prec
        /*  -<    [%prec hig=gene muc=gene]
        **
        **    prec: use [hig] under [muc +]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_link
        /*  ~>    [%link del=gene zim=gene]
        **
        **    link: use [zim] under [del]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_colb 
        /*  ~<    [%colb del=gene zim=gene] 
        **
        **    colb: use [del] under [zim]
        */
        : gene w gene { $$ = _ycell($1, $3); }


    /** Branches and conditions.
    **/
      tall_norm_quiz
        /*  ?:    [%quiz tes=gene bif=gene hob=gene]
        **
        **    quiz: if [tes], then [bif], else [hob]
        */
        : gene w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_feng
        /*  ?>    [%feng tes=gene bif=gene]
        **
        **    feng: if [tes], then [bif], else fail
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_prex
        /* ?<     [%prex tes=gene hob=gene]
        **
        **    prex: if [tes], then fail, else [hob]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_gril
        /* ?-     [%gril mox=rope bem=list+pike]
        **
        **    gril: examine [mox], internally
        */
        : rope w pike_tall_star dig_lome { $$ = _ycell($1, $3); }

      tall_norm_stam
        /* ?+     [%stam feg=gene bem=list+pike]
        **
        **    stam: examine [feg], externally
        */
        : gene w pike_tall_star dig_lome { $$ = _ycell($1, $3); }

      tall_norm_boce
        /* ?&     [%boce das=list+gene]
        **
        **    boce: yes iff all of [das] are yes
        */
        : tall_star dig_lome { $$ = $1; }
      
      tall_norm_dast
        /* ?|     [%dast das=list+gene]
        **
        **    dast: yes iff all of [das] are yes
        */
        : tall_star dig_lome { $$ = $1; }

      tall_norm_blem
        /* ?!     [%blem gix=gene]
        **
        **    blem: not
        */
        : gene

      tall_norm_like
        /* ?=     [%like rid=rope bul=gene]
        **
        **    like: yes iff [rid] is like [bul]
        */
        : rope w gene { $$ = _ycell($1, $3); }


    /** Loading.
    **/
      tall_norm_malk
        /* |+     [%malk pir=list+[mark gene]]
        **
        **    malk: pure load
        */
        : page_star dig_lome { $$ = $1; }
   
      tall_norm_blin
        /* |*     [%blin bov=gene pir=list+gene]
        **
        **    blin: load and apply
        */
        : gene w page_star dig_lome { $$ = _ycell($1, $3); }

      tall_norm_flic
        /* |:     [%flic tep=skel von=gene]
        **
        **    flic: lamb construction
        */
        : skel_t_item_some dig_lome w gene 
          { $$ = _ycell(_ycell(u4_atom_peft, $1), $4); }

      tall_norm_drol
        /* ||     [%drol nix=skel tep=skel von=gene]
        **
        **    drol: lamb with cast
        */
        : skel_t w skel_t_item_some dig_lome w gene
          { $$ = _ytrel($1, _ycell(u4_atom_peft, $3), $6); }

      tall_norm_lome
        /* |=     [%lome cug=gene]
        **
        **    lome: cold trap
        */
        : gene

      tall_norm_flot
        /* |-     [%flot cug=gene]
        **
        **    flot: hot trap
        */
        : gene
   

    /** Casts.
    **/
      tall_norm_cast
        /* ^+     [%cast fes=gene rum=gene]
        **
        **    cast: cast [rum] to [fes], geometrically
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_sure
        /* ^=     [%sure fes=gene gav=gene vep=gene]
        **
        **    sure: [vep], since [gav] matches [fes]
        */
        : gene w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_rald
        /* ^*     [%rald rum=gene]
        **
        **    rald: cast [rum] to blur
        */
        : gene 
      
      tall_norm_crot
        /* ^@     [%crot rum=gene]
        **
        **    crot: cast [rum] to atom
        */
        : gene

    /** Funky stuff.
    **/
      tall_norm_kick
        /* :=     [%kick ved=rope suc=list+[rope gene]]
        **
        **    kick: use [ved] with changes from [suc]
        */
        : gene w nail_tall_star dig_lome 
          { $$ = _ycell($1, $3); }

      tall_norm_mang
        /* :~     [%mang buz=gene pum=list+gene]
        **
        **    mang: call [buz] with tuple argument [pum]
        */
        : gene w tall
          { $$ = _ycell($1, $3); }

      tall_norm_garc
        /* :+     [%garc buz=gene pum=list+gene]
        **
        **    garc: call [buz] with tuple argument [pum]
        */
        : gene w tall_some dig_lome 
          { $$ = _ycell($1, $3); }

      tall_norm_flec
        /* :-     [%flec buz=gene]
        **
        **    flec: call [buz] with default argument
        */
        : gene 

      tall_norm_cret
        /* +=     [%cret caw=list+item]
        **
        **    cret: classic tuple
        */
        : item_tall_some dig_lome   
          { $$ = $1; }

      tall_norm_cage
        : tall_some dig_lome
          { $$ = $1; }

      tall_norm_grun
        /* :%     [%grun veq=list+[rope gene] har=gene]
        **
        **    grun: execute with changes
        */
        : nail_tall_star dig_lome w gene  
          { $$ = _ycell($1, $4); }

      tall_norm_bink
        /* :^     [%bink mef=skel]
        **
        **    bink: skeleton lamb
        */
        : skel_t
        
    /** Roots.
    **/
      tall_norm_griv
        /* &&     [%veck dil=gene zep=noun]
        **
        **    veck: raw goto
        */
        : gene w hume
          { $$ = _ycell($1, $3); }

      tall_norm_veck
        /* &:     [%veck dil=gene]
        **
        **    veck: raw goto
        */
        : gene

      tall_norm_neft
        /* &^     [%neft dil=gene]
        **
        **    neft: increment
        */
        : gene

      tall_norm_wamp
        /* &=     [%wamp dil=gene]
        **
        **    wamp: equality test
        */
        : gene

      tall_norm_spil
        /* &~     [%spil dil=gene]
        **
        **    spil: cell test
        */
        : gene

    /** Special and debugging.
    **/
      tall_norm_dbug
        /* !!     [%dbug lyq=gene]
        **
        **    dbug: cell test
        */
        : gene


/** Parts.
**/
  /** Gene and wide lists.
  **/
    tall_some
      : gene w           { $$ = _ycell($1, u4_noun_0); }
      | gene w tall_some { $$ = _ycell($1, $3); }
      ;

    tall_star
      :                  { $$ = u4_noun_0; }
      | gene w tall_star { $$ = _ycell($1, $3); }
      ;

    wide_some
      : wide g           { $$ = _ycell($1, u4_noun_0); }
      | wide w wide_some { $$ = _ycell($1, $3); }
      ;

    wide_star
      :                  { $$ = u4_noun_0; }
      | wide w wide_star { $$ = _ycell($1, $2); }
      ;

  /** Page: mark-gene pair.
  **/
    page
      : '-' w tok_mark w gene { $$ = _ycell($3, $5); }
      ;

    page_some
      : page w            { $$ = _ycell($1, u4_noun_0); }
      | page w page_some  { $$ = _ycell($1, $3); }
      ;
    
    page_star
      : { $$ = u4_noun_0; }
      | page_some
      ;

  /** Item: mark-gene pair.
  **/
    item_tall
      : tok_mark g '=' g gene  { $$ = _ycell($1, $5); }
      | gene                   { $$ = _ycell(u4_noun_0, $1); }
      ;
    item_wide
      : tok_mark g '=' g wide { $$ = _ycell($1, $5); }
      | wide                  { $$ = _ycell(u4_noun_0, $1); }
      ;
    item_tall_some
      : item_tall w                { $$ = _ycell($1, u4_noun_0); }
      | item_tall w item_tall_some { $$ = _ycell($1, $3); }
      ;
/*
    item_tall_star
      :                            { $$ = u4_noun_0; }
      | item_tall w item_tall_star { $$ = _ycell($1, $3); }
      ;
*/
    item_wide_some
      : item_wide g                { $$ = _ycell($1, u4_noun_0); }
      | item_wide w item_wide_some { $$ = _ycell($1, $3); }
      ;
/*
    item_wide_star
      :                            { $$ = u4_noun_0; }
      | item_wide w item_wide_star { $$ = _ycell($1, $2); }
      ;
*/

  /** Rope: reference path.
  **/
    rope
      : dope                  { $$ = u4_log_flip(yylane, $1); }
      ;

    dope
      : dope_hook             { $$ = _ycell($1, u4_noun_0); }
      | dope_hook '.' g dope  { $$ = _ycell($1, $4); }
      ;

      dope_hook
        : '+' tok_delm       { $$ = _ycell(u4_atom_frag, $2); }
        | '+' dope_hook_larb { $$ = _ycell(u4_atom_frag, $2); }
        | dope_tick tok_mark     
          { $$ = u4_n_zero($1) ? $2 : _ytrel(u4_atom_lect, $1, $2); }
        | dope_buck
          { $$ = u4_n_zero($1) 
             ? u4_noun_0 : _ytrel(u4_atom_lect, $1, u4_noun_0);
          }
        ;

        dope_buck
          : '$'           { $$ = u4_noun_0; }
          | '$' dope_buck { $$ = u4_op_inc(yylane, $2); }
          ;

        dope_hook_larb
          :                    { $$ = u4_noun_1; }
          | '<' dope_hook_larb { $$ = u4_op_peg(yylane, u4_noun_2, $2); }
          | '>' dope_hook_larb { $$ = u4_op_peg(yylane, u4_noun_3, $2); }
          ;

        dope_tick
          :               { $$ = u4_noun_0; }
          | '`' dope_tick { $$ = u4_op_inc(yylane, $2); }
          ;


  /** Nail: rope-gene pair.
  **/
    nail_wide
      : rope w wide { $$ = _ycell($1, $3); }
      ;

    nail_wide_some
      : nail_wide g                     { $$ = _ycell($1, u4_noun_0); }
      | nail_wide ',' g nail_wide_some  { $$ = _ycell($1, $4); }
      ;

    nail_wide_star
      : { $$ = u4_noun_0; }
      | nail_wide_some
      ;

    nail_tall
      : rope w tall { $$ = _ycell($1, $3); }
      ;

    nail_tall_some
      : nail_tall w                 { $$ = _ycell($1, u4_noun_0); }
      | nail_tall w nail_tall_some  { $$ = _ycell($1, $3); }
      ;

    nail_tall_star
      : { $$ = u4_noun_0; }
      | nail_tall_some
      ;


    /* 
       skel_w: wide 
       skel_t: tall
    */

  /** skel: fabrication prototype.
  **/
    skel_w
      : skel_w_core
      | skel_w_core '+' skel_w     { $$ = _ytrel(u4_atom_gorm, $1, $3); }
      | skel_w_core '|' skel_w     { $$ = _ytrel(u4_atom_drib, $1, $3); }
      ;

      skel_w_core
        : rope                       { $$ = _ycell(u4_atom_chob, $1); }
        | '^' skel_w                 { $$ = _ycell(u4_atom_dept, $2); }
        | '*'                        { $$ = _ycell(u4_atom_felk, u4_noun_0); }
        | '{' g wide g '}'           { $$ = _ycell(u4_atom_flit, $3); }
        | '@'                        { $$ = _ycell(u4_atom_galb, u4_noun_0); }
        | skel_w_stat                { $$ = _ycell(u4_atom_grop, $1); }
        | '[' g skel_w_item_some ']' { $$ = _ycell(u4_atom_peft, $3); }
        | '^' skel_w ':' skel_w      { $$ = _ytrel(u4_atom_shud, $2, $4); }
        | '(' g skel_w_some ')'      { $$ = _ycell(u4_atom_warx, $3); }
        ;

      skel_w_stat
        : '~'               { $$ = u4_noun_0; }
        | '&'               { $$ = u4_noun_0; }
        | '|'               { $$ = u4_noun_1; }
        | tok_delm
        | '0' 'x' tok_chex  { $$ = $3; }
        | tok_loct          
        | '%' tok_mark      { $$ = $2; }
        ;
 
      skel_w_item
        : skel_w                  { $$ = _ycell(u4_noun_0, $1); }
        | tok_mark g '=' g skel_w { $$ = _ycell($1, $5); }
        ;

      skel_w_item_some
        : skel_w_item g                  { $$ = _ycell($1, u4_noun_0); }
        | skel_w_item w skel_w_item_some { $$ = _ycell($1, $3); }
        ;

      skel_w_some
        : skel_w g             { $$ = _ycell($1, u4_noun_0); }
        | skel_w w skel_w_some { $$ = _ycell($1, $3); }
        ;
  
  /* skel_t: skel, tall.
  */
     skel_t
       : skel_w
       | dig_dept w skel_t                     { $$ = _ycell($1, $3); }
       | dig_flit w tall                       { $$ = _ycell($1, $3); }
       | dig_gorm w skel_t w skel_t            { $$ = _ytrel($1, $3, $5); }
       | dig_peft w skel_t_item_some dig_lome  { $$ = _ycell($1, $3); }
       | dig_drib w skel_t w skel_t            { $$ = _ytrel($1, $3, $5); }
       | dig_shud w skel_t w skel_t            { $$ = _ytrel($1, $3, $5); }
       | dig_warx w skel_t_some dig_lome       { $$ = _ycell($1, $3); }
       ;

      skel_t_item
        : skel_t                  { $$ = _ycell(u4_noun_0, $1); }
        | tok_mark g '=' g skel_t { $$ = _ycell($1, $5); }
        ;

      skel_t_item_some
        : skel_t_item w                  { $$ = _ycell($1, u4_noun_0); }
        | skel_t_item w skel_t_item_some { $$ = _ycell($1, $3); }
        ;

      skel_t_some
        : skel_t w              { $$ = _ycell($1, u4_noun_0); }
        | skel_t w skel_t_some  { $$ = _ycell($1, $3); }
        ;

  /** Pike: pattern reaction.
  **/
    pike_tall
      : '-' w skel_t w gene  { $$ = _ytrel(u4_atom_lask, $3, $5); }
      | '+' w skel_t         { $$ = _ycell(u4_atom_plic, $3); }
      | '*' w skel_t w gene  { $$ = _ytrel(u4_atom_semp, $3, $5); }
      | '%' w skel_t         { $$ = _ycell(u4_atom_fing, $3); }
      ;

    pike_wide
      : '-' w skel_w w wide      { $$ = _ytrel(u4_atom_lask, $3, $5); }
      | '+' w wide               { $$ = _ycell(u4_atom_plic, $3); }
      | '*' w skel_w w wide      { $$ = _ytrel(u4_atom_semp, $3, $5); }
      | '%' w wide               { $$ = _ycell(u4_atom_fing, $3); } 
      ;

    pike_tall_some
      : pike_tall w                 { $$ = _ycell($1, u4_noun_0); }
      | pike_tall w pike_tall_some  { $$ = _ycell($1, $3); }
      ;

    pike_tall_star
      : { $$ = u4_noun_0; }
      | pike_tall_some
      ;

    pike_wide_some
      : pike_wide g                     { $$ = _ycell($1, u4_noun_0); }
      | pike_wide ',' g pike_wide_some  { $$ = _ycell($1, $4); }
      ;

    pike_wide_star
      : { $$ = u4_noun_0; }
      | pike_wide_some
      ;

/** Command-line language.
**/
  vere 
    : '>' g tok_unix w vere_construct
      { $$ = _ytrel(u4_atom_grik, $3, $5); }
    | '=' g tok_mark w vere_construct
      { $$ = _ytrel(u4_atom_corm, $3, $5); }
    | vere_construct
      { $$ = _ycell(u4_atom_palq, $1); }
    ;


    vere_construct
      : vere_source
        { $$ = _ycell($1, u4_noun_0); }
      | vere_source w vere_transform
        { $$ = _ycell($1, $3); }
      ;

      vere_transform
        : vere_filter
          { $$ = _ycell($1, u4_noun_0); }
        | vere_filter w vere_transform
          { $$ = _ycell($1, $3); }
        ;

      vere_filter
        : '@' tok_unix
          { $$ = _ycell(u4_atom_gamp, $2); }
        | '_' tok_unix
          { $$ = _ycell(u4_atom_lame, $2); }
        | '#' tok_unix
          { $$ = _ycell(u4_atom_zork, $2); }
        | '$' hume
          { $$ = _ycell(u4_atom_blan, $2); }
        | vere_exp
          { $$ = _ycell(u4_atom_zect, $1); }
        ;

      vere_source
        : '[' g vere_item_some ']'
          { $$ = _ycell(u4_atom_malg, $3); }
        | '@' tok_unix
          { $$ = _ycell(u4_atom_drun, $2); }
        | wide_constant
          { $$ = _ycell(u4_atom_narv, $1); }
        | '{' g vere_exp g '}'
          { $$ = _ycell(u4_atom_trib, $3); }
        ;

        vere_item_some
          : vere_item g                { $$ = _ycell($1, u4_noun_0); }
          | vere_item w vere_item_some { $$ = _ycell($1, $3); }
          ;

        vere_item
          : tok_mark g '=' g vere_source { $$ = _ycell($1, $5); }
          | vere_source                  { $$ = _ycell(u4_noun_0, $1); }
          ;
      ;

    vere_exp
      : wide
      ;


/** Constant language.
**/
  hume
    : hume_atom
    | '[' g hume_some ']'   { $$ = $3; }
    ;

    hume_atom
      : tok_delm            { $$ = $1; }
      | '0' 'x' tok_chex    { $$ = $3; }
      | tok_loct            { $$ = $1; }
      | '%' tok_mark        { $$ = $2; }
      | '%' '%'             { $$ = u4_noun_0; }
      | '~'                 { $$ = u4_noun_0; }
      ;

    hume_some
      : hume g              { $$ = $1; }
      | hume w hume_some    { $$ = _ycell($1, $3); } 
      ;


/** Pseudoscanner - part of the parser that would normally be in lex.
**/
  /** Miscellaneous tokens.
  **/
    tok_unix
      : tok_unix_in { $$ = u4_k_atom_log(yylane, $1); }
      ;

      tok_unix_in
        : tok_unix_c              { $$ = _ycell($1, u4_noun_0); }
        | tok_unix_c tok_unix_in  { $$ = _ycell($1, $2); }
        ;

      tok_unix_c
        : ca | cd | cm 
        ;

    tok_mark
      : tok_mark_pre
      | tok_mark_pre tok_mark_load
        { $$ = u4_k_atom_log(yylane, _ycell($1, $2)); }
      ;
        tok_mark_pre
          : ca

        tok_mark_load
          : ca { $$ = _ycell($1, u4_noun_0); }
                 | cd { $$ = _ycell($1, u4_noun_0); }
                 | ca tok_mark_load  { $$ = _ycell($1, $2); }
                 | cd tok_mark_load  { $$ = _ycell($1, $2); }
                 | '-' tok_mark_load { $$ = _ycell($1, $2); }
                 ;

    tok_chex 
      : '0' 
        { $$ = u4_noun_0; }
      | tok_chex_pre tok_chex_load
        { $$ = u4_k_atom_heximal(yylane, _ycell($1, $2)); }
      ;
        tok_chex_pre
          : cn | ch
          ;

        tok_chex_load
          : { $$ = u4_noun_0; }
                    | cd gap tok_chex_load { $$ = _ycell($1, $3); }
                    | ch gap tok_chex_load { $$ = _ycell($1, $3); }
                    ;


    tok_delm
      : '0' { $$ = u4_noun_0; }
      | tok_delm_pre tok_delm_load
        { $$ = u4_k_atom_decimal(yylane, _ycell($1, $2)); }
      ;
        tok_delm_pre: cn;
        tok_delm_load: { $$ = u4_noun_0; }
                    | cd tok_delm_load { $$ = _ycell($1, $2); }
                    ;

    tok_loct
      : '\'' loct_mid '\''
        { $$ = u4_k_atom_log(yylane, $2); }
      ;
        loct_mid: { $$ = u4_noun_0; }
                 | cq loct_mid { $$ = _ycell($1, $2); }
                 ;


  /** Digraphs.
  **/
    dig_pont: '=' '>' { $$ = u4_atom_pont; }
    dig_clet: '`' '<' { $$ = u4_atom_clet; }
    dig_trop: '-' '>' { $$ = u4_atom_trop; }
    dig_prec: '-' '<' { $$ = u4_atom_prec; }
    dig_link: '~' '>' { $$ = u4_atom_link; }
    dig_colb: '~' '<' { $$ = u4_atom_colb; }

    dig_quiz: '?' ':' { $$ = u4_atom_quiz; } 
    dig_feng: '?' '>' { $$ = u4_atom_feng; }
    dig_prex: '?' '<' { $$ = u4_atom_prex; }
    dig_gril: '?' '-' { $$ = u4_atom_gril; }
    dig_stam: '?' '+' { $$ = u4_atom_stam; }
    dig_boce: '?' '&' { $$ = u4_atom_boce; }
    dig_dast: '?' '|' { $$ = u4_atom_dast; }
    dig_blem: '?' '!' { $$ = u4_atom_blem; }
    dig_like: '?' '=' { $$ = u4_atom_like; }

    dig_malk: '|' '+' { $$ = u4_atom_malk; }
    dig_blin: '|' '*' { $$ = u4_atom_blin; }
    dig_flic: '|' ':' { $$ = u4_atom_flic; }
    dig_drol: '|' '|' { $$ = u4_atom_drol; }
    dig_lome: '|' '=' { $$ = u4_atom_lome; }
    dig_flot: '|' '-' { $$ = u4_atom_flot; }

    dig_cast: '^' '-' { $$ = u4_atom_cast; }
    dig_sure: '^' '=' { $$ = u4_atom_sure; }
    dig_rald: '^' '*' { $$ = u4_atom_rald; }
    dig_crot: '^' '@' { $$ = u4_atom_crot; }

    dig_kick: ':' '=' { $$ = u4_atom_kick; } 
    dig_mang: ':' '~' { $$ = u4_atom_mang; }
    dig_garc: ':' '+' { $$ = u4_atom_garc; }
    dig_flec: ':' '-' { $$ = u4_atom_flec; }
    dig_grun: ':' '%' { $$ = u4_atom_grun; }

    dig_cret: '+' '+' { $$ = u4_atom_cret; }
    dig_cage: '+' '-' { $$ = u4_atom_cage; }
    /* dig_name: '+' '=' { $$ = u4_atom_name; } */
    dig_bink: '+' ':' { $$ = u4_atom_bink; }

    dig_dbug: '!' '?' { $$ = u4_atom_dbug; }
/*
    dig_terg: '`' '+' { $$ = u4_atom_terg; }
    dig_hosc: '`' '-' { $$ = u4_atom_hosc; }
    dig_gald: '`' '*' { $$ = u4_atom_gald; }
    dig_blig: '`' '|' { $$ = u4_atom_blig; }
    dig_jarm: '`' '`' { $$ = u4_atom_jarm; }
*/
    dig_griv: '&' '&' { $$ = u4_atom_griv; }
    dig_veck: '&' ':' { $$ = u4_atom_veck; }
    dig_neft: '&' '^' { $$ = u4_atom_neft; }
    dig_wamp: '&' '=' { $$ = u4_atom_wamp; }
    dig_spil: '&' '~' { $$ = u4_atom_spil; }

    dig_dept: '%' '>' { $$ = u4_atom_dept; }
    dig_flit: '%' '=' { $$ = u4_atom_flit; }
    dig_gorm: '%' '+' { $$ = u4_atom_gorm; }
    dig_peft: '%' '*' { $$ = u4_atom_peft; }
    dig_drib: '%' '|' { $$ = u4_atom_drib; }
    dig_shud: '%' '<' { $$ = u4_atom_shud; }
    dig_warx: '%' '?' { $$ = u4_atom_warx; }

    dig_lome: '=' '=' { $$ = u4_atom_lome; }


  /** Whitespace.
  **/
    gap
      : '\\' g '/'  { $$ = u4_noun_0; }
      |             { $$ = u4_noun_0; }
      ;

    g:            { $$ = u4_noun_0; }
     | cw g       { $$ = u4_noun_0; }
     | comment g  { $$ = u4_noun_0; }
     ;

    w: cw         { $$ = u4_noun_0; }
     | comment    { $$ = u4_noun_0; }
     | cw w       { $$ = u4_noun_0; }
     | comment w  { $$ = u4_noun_0; }
     ;

    comment: ':' ':' comment_body '\n' { $$ = u4_noun_0; }
           ;
      comment_body
        : 
        | cl comment_body
        ;

  /** Characters and character classes.
  **/
    ca
      : 'a'|'b'|'c'|'d'|'e'|'f'|'g'|'h'|'i'|'j'|'k'|'l'|'m'
      | 'n'|'o'|'p'|'q'|'r'|'s'|'t'|'u'|'v'|'w'|'x'|'y'|'z'
      | 'A'|'B'|'C'|'D'|'E'|'F'|'G'|'H'|'I'|'J'|'K'|'L'|'M'
      | 'N'|'O'|'P'|'Q'|'R'|'S'|'T'|'U'|'V'|'W'|'X'|'Y'|'Z'
      ;

    ch: 'a'|'b'|'c'|'d'|'e'|'f';
    cd: '0'|cn;
    cn: '1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9';

    cp: cm|'\''|'\\';

    cm
      : '~'|'`'|'!'|'@'|'#'|'$'|'%'|'^'|'&'|'*'|'('|')' 
      | '{'|'['|'}'|']'|'|'|':'|';'|'"'|'<'|'>' 
      | ','|'.'|'?'|'/'|'_'|'-'|'+'|'='
      ;

    cw: ' ' | '\n';
    cl: ca | cd | cp | ' ';
    cq: ca | cd | cm | ' ' 
      | '\\' '\\' { $$ = $2; }
      | '\\' '\'' { $$ = $2; }
      ;

%%

/* Annotate (gene) with home.
*/
static u4_noun
_watt_locate(u4_lane lane,
             const void *vlocp,
             u4_noun gene)
{
  const YYLTYPE *llocp = vlocp;   /* bufalo estupido */

#if 1
  return gene;
#else
  return u4_k_trel
    (lane, 
     u4_atom_home, 
     u4_k_cell
      (lane, 
       u4_k_cell
        (lane, 
         u4_k_atom_xw(lane, llocp->first_line), 
         u4_k_atom_xw(lane, llocp->first_column)),
       u4_k_cell
        (lane,
         u4_k_atom_xw(lane, llocp->last_line), 
         u4_k_atom_xw(lane, llocp->last_column))),
     gene);
#endif
}

/* Initialize (scanner) for (site sack).
*/
static void
_scanner_init(struct _u4_scanner *scanner,
              u4_lane lane,
              u4_noun site,
              u4_noun sack)
{
  scanner->lane = lane;
  scanner->scan = u4_bull;

  scanner->p.site = site;
  if ( u4_n_atom(sack) ) {
    scanner->p.tube = sack;
    scanner->p.bowl = u4_noun_0;
  }
  else {
    scanner->p.tube = u4_ch(sack);
    scanner->p.bowl = u4_ct(sack);
  }

  scanner->s.token = 0;
  scanner->s.pb = 0;
  scanner->s.xw_line = 1;
  scanner->s.xw_col = 1;
}

/* _watt_parse_part():
*/
static u4_noun
_watt_parse_part(struct _u4_scanner *scanner,
                 u4_noun mark)
{
  u4_lane lane = scanner->lane;
  u4_log  site = scanner->p.site;
  u4_tab  bowl = scanner->p.bowl;
  u4_noun sack;

  if ( !u4_tab_in(mark, bowl) ) {
    u4_err(lane, "part", mark);
    return u4_exit;
  }
  sack = u4_tab_get(mark, bowl);
  site = u4_k_cell(lane, mark, site);

  /* Is bison really reentrant?
  */
  return u4_watt_parse(lane, site, sack);
}

/* u4_watt_parse(): 
**
**   At (pif), convert (zar) to a gene.
*/
u4_noun
u4_watt_parse(u4_lane lane,
              u4_site pif,
              u4_sack zar)
{
  struct _u4_scanner scanner;

  _scanner_init(&scanner, lane, pif, zar);

  if ( !yyparse(&scanner) ) {
    u4_assert(scanner.scan);

    return scanner.scan;
    // return u4_k_trel(lane, u4_atom_spot, pif, scanner.scan);
  }
  else {
    return u4_exit;
  }
}

/* u4_vere_parse(): 
**
**   Convert (mez) to a vere command.
*/
u4_noun
u4_vere_parse(u4_lane lane,
              u4_atom mez)
{
  struct _u4_scanner scanner;

  _scanner_init(&scanner, lane, u4_noun_0, mez);
  scanner.s.token = T_vere;

  if ( !yyparse(&scanner) ) {
    u4_assert(scanner.scan);

    return scanner.scan;
  }
  else {
    return u4_exit;
  }
}

/* u4_hume_parse(): 
**
**   Convert (mez) to a data noun.
*/
u4_noun
u4_hume_parse(u4_lane lane,
              u4_atom mez)
{
  struct _u4_scanner scanner;

  _scanner_init(&scanner, lane, u4_noun_0, mez);
  scanner.s.token = T_hume;

  if ( !yyparse(&scanner) ) {
    u4_assert(scanner.scan);

    return scanner.scan;
  }
  else {
    return u4_exit;
  }
}

/* Trivial scanner.
*/
int 
yylex(YYSTYPE *lvalp, YYLTYPE *llocp, struct _u4_scanner *scanner)
{
  if ( scanner->s.token ) {
    int token = scanner->s.token;

    scanner->s.token = 0;
    return token;
  }
  else {
    u4_xb xb = u4_a_byte(scanner->p.tube, scanner->s.pb);

    llocp->first_line = llocp->last_line = scanner->s.xw_line;
    llocp->first_column = llocp->last_column = scanner->s.xw_col;

    scanner->s.pb += 1;
    if ( xb == '\n' ) {
      scanner->s.xw_line += 1;
      scanner->s.xw_col = 1;
    }
    else {
      scanner->s.xw_col += 1;
    }

    *lvalp = u4_cod_in(xb);
    return xb;
  }
}  

/* Error printer.
*/
int yyerror(YYLTYPE *locp, struct _u4_scanner *scanner, char const *msg)
{
  if ( !u4_n_zero(scanner->p.site) ) {
    u4_err(scanner->lane, "yyerror", scanner->p.site);
  }
  printf("%s: (%d:%d - %d:%d)\n", 
    msg, locp->first_line, locp->first_column,
         locp->last_line, locp->last_column);
}

