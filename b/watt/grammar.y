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
  %expect 855

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
        { $$ = _ytrel(u4_atom_slop, $1, u4_noun_0); }
      | rope '(' nail_wide_star ')'
        { $$ = _ytrel(u4_atom_slop, $1, $3); }
      | '[' g item_wide_some ']'
        { $$ = _ycell(u4_atom_slon, $3); }
      | '(' g wide_some ')'
        { $$ = _ytrel(u4_atom_slid, u4_ch($3), u4_ct($3)); }
      | wide_constant
      ;

    wide_constant
      : tok_delm
        { $$ = _ycell(u4_atom_draz, $1); }
      | '&'               
        { $$ = _ycell(u4_atom_draz, u4_noun_0); }
      | '|' 
        { $$ = _ycell(u4_atom_draz, u4_noun_1); }
      | '0' 'x' tok_chex
        { $$ = _ycell(u4_atom_draz, $3); }
      | tok_loct
        { $$ = _ycell(u4_atom_draz, $1); }
      | '%' tok_mark
        { $$ = _ycell(u4_atom_drop, $2); }
      | '%' tok_delm
        { $$ = _ycell(u4_atom_drop, $2); }
      | '%' '%'
        { $$ = _ycell(u4_atom_drop, u4_noun_0); }
      | '~'
        { $$ = _ycell(u4_atom_drop, u4_noun_0); }
      | '!''!'
        { $$ = _ycell(u4_atom_plac, u4_noun_0); }
      ;
  
  /** Regular wide productions.
  **/
    wide_norm
      : dig_clat wide_norm_clat  /* => */ { $$ = _ycell($1, $2); }
      | dig_clet wide_norm_clet  /* =< */ { $$ = _ycell($1, $2); }
      | dig_plat wide_norm_plat  /* -> */ { $$ = _ycell($1, $2); }
      | dig_plet wide_norm_plet  /* -< */ { $$ = _ycell($1, $2); }
      | dig_grat wide_norm_grat  /* ~> */ { $$ = _ycell($1, $2); }
      | dig_gret wide_norm_gret  /* ~< */ { $$ = _ycell($1, $2); }

      | dig_quol wide_norm_quol  /* ?: */ { $$ = _ycell($1, $2); }
      | dig_quat wide_norm_quat  /* ?> */ { $$ = _ycell($1, $2); }
      | dig_quet wide_norm_quet  /* ?< */ { $$ = _ycell($1, $2); }
      | dig_quem wide_norm_quem  /* ?- */ { $$ = _ycell($1, $2); }
      | dig_quid wide_norm_quid  /* ?+ */ { $$ = _ycell($1, $2); }
      | dig_quax wide_norm_quax  /* ?& */ { $$ = _ycell($1, $2); }
      | dig_quix wide_norm_quix  /* ?| */ { $$ = _ycell($1, $2); }
      | dig_quac wide_norm_quac  /* ?! */ { $$ = _ycell($1, $2); }
      | dig_quop wide_norm_quop  /* ?= */ { $$ = _ycell($1, $2); }
/*
      | dig_stid wide_norm_stid  ** |+ ** { $$ = _ycell($1, $2); }
      | dig_ston wide_norm_ston  ** |* ** { $$ = _ycell($1, $2); }
*/
      | dig_stol wide_norm_stol  /* |: */ { $$ = _ycell($1, $2); }
      | dig_stix wide_norm_stix  /* || */ { $$ = _ycell($1, $2); }
      | dig_stop wide_norm_stop  /* |= */ { $$ = _ycell($1, $2); }
      | dig_stem wide_norm_stem  /* |- */ { $$ = _ycell($1, $2); }

      | dig_glid wide_norm_glid  /* ^+ */ { $$ = _ycell($1, $2); }
      | dig_glem wide_norm_glem  /* ^- */ { $$ = _ycell($1, $2); }
      | dig_glop wide_norm_glop  /* ^= */ { $$ = _ycell($1, $2); }
      | dig_glon wide_norm_glon  /* ^* */ { $$ = _ycell($1, $2); }
      | dig_glaz wide_norm_glaz  /* ^@ */ { $$ = _ycell($1, $2); }

      | dig_slop wide_norm_slop  /* := */ { $$ = _ycell($1, $2); }
      | dig_sloc wide_norm_sloc  /* :~ */ { $$ = _ycell($1, $2); }
      | dig_slid wide_norm_slid  /* :+ */ { $$ = _ycell($1, $2); }
      | dig_slem wide_norm_slem  /* :- */ { $$ = _ycell($1, $2); }
      | dig_slon wide_norm_slon  /* :* */ { $$ = _ycell($1, $2); }
      | dig_slux wide_norm_slux  /* :. */ { $$ = _ycell($1, $2); }
      | dig_grun wide_norm_grun  /* :% */ { $$ = _ycell($1, $2); }
      | dig_slos wide_norm_slos  /* :$ */ { $$ = _ycell($1, $2); }
      | dig_slip wide_norm_slip  /* :~ */ { $$ = _ycell($1, $2); }

      | dig_brax wide_norm_brax  /* && */ { $$ = _ycell($1, $2); }
      | dig_bron wide_norm_bron  /* &: */ { $$ = _ycell($1, $2); }
      | dig_brip wide_norm_brip  /* &^ */ { $$ = _ycell($1, $2); }
      | dig_brop wide_norm_brop  /* &= */ { $$ = _ycell($1, $2); }
      | dig_broc wide_norm_broc  /* &~ */ { $$ = _ycell($1, $2); }
      ;

    /** Combinators.
    **/
      wide_norm_clat
        : '{' g tok_mark w wide w wide g '}' { $$ = _ytrel($3, $5, $7); }

      wide_norm_clet
        : '{' g tok_mark w wide w wide g '}' { $$ = _ytrel($1, $3, $5); }

      wide_norm_plat
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_plet
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_grat
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_gret 
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }


    /** Branches.
    **/
      wide_norm_quol
        : '{' g wide w wide w wide g '}' { $$ = _ytrel($1, $3, $5); }

      wide_norm_quat
        : '{' g wide w wide g '}' { $$ = _ycell($1, $3); }

      wide_norm_quet
        : '{' g wide w wide g '}' { $$ = _ycell($1, $3); }

      wide_norm_quem
        : '{' g rope ':' w pike_wide_star '}' { $$ = _ycell($3, $6); }

      wide_norm_quid
        : '{' g wide ':' w pike_wide_star '}' { $$ = _ycell($3, $6); }

      wide_norm_quax
        : '{' g wide_star '}' { $$ = $3; }
      
      wide_norm_quix
        : '{' g wide_star '}' { $$ = $3; }
   
      wide_norm_quac
        : wide
   
      wide_norm_quop
        : '{' g rope g wide g '}' { $$ = _ycell($3, $5); }
   

    /** Loading.
    **/
/*
      wide_norm_stid
        : page_star dig_stop { $$ = $1; }
   
      wide_norm_ston
        : wide w page_star dig_stop { $$ = _ycell($1, $3); }
*/
      wide_norm_stol
        : '{' g skel_w w wide g '}'{ $$ = _ycell($3, $5); }

      wide_norm_stix
        : '{' g skel_w w skel_w w wide g '}'{ $$ = _ytrel($3, $5, $7); }

      wide_norm_stop
        : wide

      wide_norm_stem
        : wide
    
    /** Casts.
    **/
      wide_norm_glid
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_glem
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_glop
        : '{' g wide w wide w wide g '}' { $$ = _ycell($3, $3); }

      wide_norm_glon
        : wide

      wide_norm_glaz
        : wide

    /** Funky stuff.
    **/
      wide_norm_slop
        : '{' g wide w nail_wide_star '}' { $$ = _ycell($3, $5); }

      wide_norm_sloc
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_slid
        : '{' g wide w wide_some '}' { $$ = _ycell($3, $5); }

      wide_norm_slem
        : wide 

      wide_norm_slon
        : '{' g item_wide_some '}' { $$ = $3; }

      wide_norm_slux
        : '{' g wide_some '}' { $$ = $3; }

      wide_norm_grun
        : '{' g nail_wide_star ':' w wide '}' { $$ = _ycell($3, $6); }

      wide_norm_slos
        : skel_w

      wide_norm_slip
        : skel_w

    /** Roots.
    **/
      wide_norm_brax
        : '{' g wide w hume '}' { $$ = _ycell($3, $5); }
 
      wide_norm_bron
        : wide

      wide_norm_brip
        : wide

      wide_norm_brop
        : wide

      wide_norm_broc
        : wide

  ;

tall
  : tall_norm { $$ = _watt_locate(yylane, &@1, $1); }
  /* | tall_leaf */
  ;

  /** Normal tall genes.
  **/
    tall_norm
      : dig_clat w tall_norm_clat  /* => */ { $$ = _ycell($1, $3); }
      | dig_clet w tall_norm_clet  /* =< */ { $$ = _ycell($1, $3); }
      | dig_plat w tall_norm_plat  /* -> */ { $$ = _ycell($1, $3); }
      | dig_plet w tall_norm_plet  /* -< */ { $$ = _ycell($1, $3); }
      | dig_grat w tall_norm_grat  /* ~> */ { $$ = _ycell($1, $3); }
      | dig_gret w tall_norm_gret  /* ~< */ { $$ = _ycell($1, $3); }

      | dig_quol w tall_norm_quol  /* ?: */ { $$ = _ycell($1, $3); }
      | dig_quat w tall_norm_quat  /* ?> */ { $$ = _ycell($1, $3); }
      | dig_quet w tall_norm_quet  /* ?< */ { $$ = _ycell($1, $3); }
      | dig_quem w tall_norm_quem  /* ?- */ { $$ = _ycell($1, $3); }
      | dig_quid w tall_norm_quid  /* ?+ */ { $$ = _ycell($1, $3); }
      | dig_quax w tall_norm_quax  /* ?& */ { $$ = _ycell($1, $3); }
      | dig_quix w tall_norm_quix  /* ?| */ { $$ = _ycell($1, $3); }
      | dig_quac w tall_norm_quac  /* ?! */ { $$ = _ycell($1, $3); }
      | dig_quop w tall_norm_quop  /* ?= */ { $$ = _ycell($1, $3); }
    
      | dig_stid w tall_norm_stid  /* |+ */ { $$ = _ycell($1, $3); }
      | dig_ston w tall_norm_ston  /* |* */ { $$ = _ycell($1, $3); }
      | dig_stol w tall_norm_stol  /* |: */ { $$ = _ycell($1, $3); }
      | dig_stix w tall_norm_stix  /* || */ { $$ = _ycell($1, $3); }
      | dig_stop w tall_norm_stop  /* |= */ { $$ = _ycell($1, $3); }
      | dig_stem w tall_norm_stem  /* |- */ { $$ = _ycell($1, $3); }

      | dig_glid w tall_norm_glid  /* ^+ */ { $$ = _ycell($1, $3); }
      | dig_glem w tall_norm_glem  /* ^- */ { $$ = _ycell($1, $3); }
      | dig_glop w tall_norm_glop  /* ^= */ { $$ = _ycell($1, $3); }
      | dig_glon w tall_norm_glon  /* ^- */ { $$ = _ycell($1, $3); }
      | dig_glaz w tall_norm_glaz  /* ^- */ { $$ = _ycell($1, $3); }

      | dig_slop w tall_norm_slop  /* := */ { $$ = _ycell($1, $3); }
      | dig_sloc w tall_norm_sloc  /* :~ */ { $$ = _ycell($1, $3); }
      | dig_slid w tall_norm_slid  /* :+ */ { $$ = _ycell($1, $3); }
      | dig_slem w tall_norm_slem  /* :- */ { $$ = _ycell($1, $3); }
      | dig_slon w tall_norm_slon  /* :* */ { $$ = _ycell($1, $3); }
      | dig_slux w tall_norm_slux  /* :. */ { $$ = _ycell($1, $3); }
      | dig_grun w tall_norm_grun  /* :% */ { $$ = _ycell($1, $3); }
      | dig_slos w tall_norm_slos  /* :$ */ { $$ = _ycell($1, $3); }
      | dig_slip w tall_norm_slip  /* :~ */ { $$ = _ycell($1, $3); }
   
      | dig_brax w tall_norm_brax  /* && */ { $$ = _ycell($1, $3); }
      | dig_bron w tall_norm_bron  /* &: */ { $$ = _ycell($1, $3); }
      | dig_brip w tall_norm_brip  /* &^ */ { $$ = _ycell($1, $3); }
      | dig_brop w tall_norm_brop  /* &= */ { $$ = _ycell($1, $3); }
      | dig_broc w tall_norm_broc  /* &~ */ { $$ = _ycell($1, $3); }
      ;

    /** Combinators.
    **/
      tall_norm_clat
        /*  =>    [%clat han=mark dur=gene leb=gene]
        **
        **    clat: use [leb] under [[han=dur] +]
        */
        : tok_mark w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_clet
        /*  =<    [%clet han=mark dur=gene leb=gene]
        **
        **    clet: use [dur] under [[han=leb] +]
        */
        : tok_mark w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_plat
        /*  ->    [%plat hig=gene muc=gene]
        **
        **    plat: use [muc] under [hig +]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_plet
        /*  -<    [%plet hig=gene muc=gene]
        **
        **    plet: use [hig] under [muc +]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_grat
        /*  ~>    [%grat del=gene zim=gene]
        **
        **    grat: use [zim] under [del]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_gret 
        /*  ~<    [%gret del=gene zim=gene] 
        **
        **    gret: use [del] under [zim]
        */
        : gene w gene { $$ = _ycell($1, $3); }


    /** Branches and conditions.
    **/
      tall_norm_quol
        /*  ?:    [%quol tes=gene bif=gene hob=gene]
        **
        **    quol: if [tes], then [bif], else [hob]
        */
        : gene w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_quat
        /*  ?>    [%quat tes=gene bif=gene]
        **
        **    quat: if [tes], then [bif], else fail
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_quet
        /* ?<     [%quet tes=gene hob=gene]
        **
        **    quet: if [tes], then fail, else [hob]
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_quem
        /* ?-     [%quem mox=rope bem=list+pike]
        **
        **    quem: examine [mox], internally
        */
        : rope w pike_tall_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_quid
        /* ?+     [%quid feg=gene bem=list+pike]
        **
        **    quid: examine [feg], externally
        */
        : gene w pike_tall_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_quax
        /* ?&     [%quax das=list+gene]
        **
        **    quax: yes iff all of [das] are yes
        */
        : tall_star dig_stop { $$ = $1; }
      
      tall_norm_quix
        /* ?|     [%quix das=list+gene]
        **
        **    quix: yes iff all of [das] are yes
        */
        : tall_star dig_stop { $$ = $1; }

      tall_norm_quac
        /* ?!     [%quac gix=gene]
        **
        **    quac: not
        */
        : gene

      tall_norm_quop
        /* ?=     [%quop rid=rope bul=gene]
        **
        **    quop: yes iff [rid] is like [bul]
        */
        : rope w gene { $$ = _ycell($1, $3); }


    /** Loading.
    **/
      tall_norm_stid
        /* |+     [%stid pir=list+[mark gene]]
        **
        **    stid: pure load
        */
        : page_star dig_stop { $$ = $1; }
   
      tall_norm_ston
        /* |*     [%ston bov=gene pir=list+gene]
        **
        **    ston: load and apply
        */
        : gene w page_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_stol
        /* |:     [%stol tep=skel von=gene]
        **
        **    stol: lamb construction
        */
        : skel_t_item_some dig_stop w gene 
          { $$ = _ycell(_ycell(u4_atom_peft, $1), $4); }

      tall_norm_stix
        /* ||     [%stix nix=skel tep=skel von=gene]
        **
        **    stix: lamb with cast
        */
        : skel_t w skel_t_item_some dig_stop w gene
          { $$ = _ytrel($1, _ycell(u4_atom_peft, $3), $6); }

      tall_norm_stop
        /* |=     [%stop cug=gene]
        **
        **    stop: cold trap
        */
        : gene

      tall_norm_stem
        /* |-     [%stem cug=gene]
        **
        **    stem: hot trap
        */
        : gene
   

    /** Casts.
    **/
      tall_norm_glid
        /* ^+     [%glid fes=gene rum=gene]
        **
        **    glid: glid [rum] to [fes], geometrically
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_glem
        /* ^-     [%glem fes=gene rum=gene]
        **
        **    glem: glid [rum] to [fes], genetically
        */
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_glop
        /* ^=     [%glop fes=gene gav=gene vep=gene]
        **
        **    glop: [vep], since [gav] matches [fes]
        */
        : gene w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_glon
        /* ^*     [%glon rum=gene]
        **
        **    glon: glid [rum] to blur
        */
        : gene 
      
      tall_norm_glaz
        /* ^@     [%glaz rum=gene]
        **
        **    glaz: glid [rum] to atom
        */
        : gene

    /** Funky stuff.
    **/
      tall_norm_slop
        /* :=     [%slop ved=rope suc=list+[rope gene]]
        **
        **    slop: use [ved] with changes from [suc]
        */
        : gene w nail_tall_star dig_stop 
          { $$ = _ycell($1, $3); }

      tall_norm_sloc
        /* :~     [%sloc buz=gene pum=list+gene]
        **
        **    sloc: call [buz] with tuple argument [pum]
        */
        : gene w tall
          { $$ = _ycell($1, $3); }

      tall_norm_slid
        /* :+     [%slid buz=gene pum=list+gene]
        **
        **    slid: call [buz] with tuple argument [pum]
        */
        : gene w tall_some dig_stop 
          { $$ = _ycell($1, $3); }

      tall_norm_slem
        /* :-     [%slem buz=gene]
        **
        **    slem: call [buz] with default argument
        */
        : gene 

      tall_norm_slon
        /* :*     [%slon caw=list+item]
        **
        **    slon: classic tuple
        */
        : item_tall_some dig_stop   
          { $$ = $1; }

      tall_norm_slux
        : tall_some dig_stop
          { $$ = $1; }

      tall_norm_grun
        /* :%     [%grun veq=list+[rope gene] har=gene]
        **
        **    grun: execute with changes
        */
        : nail_tall_star dig_stop w gene  
          { $$ = _ycell($1, $4); }

      tall_norm_slos
        /* :$     [%slos mef=skel]
        **
        **    slos: skeleton stub
        */
        : skel_t

      tall_norm_slip
        /* :^     [%slip mef=skel]
        **
        **    slip: skeleton lamb
        */
        : skel_t
        
    /** Roots.
    **/
      tall_norm_brax
        /* &&     [%bron dil=gene zep=noun]
        **
        **    bron: raw goto
        */
        : gene w hume
          { $$ = _ycell($1, $3); }

      tall_norm_bron
        /* &:     [%bron dil=gene]
        **
        **    bron: raw goto
        */
        : tall

      tall_norm_brip
        /* &^     [%brip dil=gene]
        **
        **    brip: increment
        */
        : tall

      tall_norm_brop
        /* &=     [%brop dil=gene]
        **
        **    brop: equality test
        */
        : tall

      tall_norm_broc
        /* &~     [%broc dil=gene]
        **
        **    broc: cell test
        */
        : tall


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
        : '+' tok_delm       { $$ = _ycell(u4_atom_slet, $2); }
        | '+' dope_hook_larb { $$ = _ycell(u4_atom_slet, $2); }
        | dope_tick tok_mark     
          { $$ = u4_n_zero($1) ? $2 : _ytrel(u4_atom_slat, $1, $2); }
        | dope_buck
          { $$ = u4_n_zero($1) 
             ? u4_noun_0 : _ytrel(u4_atom_slat, $1, u4_noun_0);
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
        | tok_mark g '=' g skel_w { $$ = _ycell($1, $3); }
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
       | dig_peft w skel_t_item_some dig_stop  { $$ = _ycell($1, $3); }
       | dig_drib w skel_t w skel_t            { $$ = _ytrel($1, $3, $5); }
       | dig_shud w skel_t w skel_t            { $$ = _ytrel($1, $3, $5); }
       | dig_warx w skel_t_some dig_stop       { $$ = _ycell($1, $3); }
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
      : '-' w skel_t w tall  { $$ = _ytrel(u4_atom_lask, $3, $5); }
      | '+' w skel_t         { $$ = _ycell(u4_atom_plic, $3); }
      | '*' w skel_t w tall  { $$ = _ytrel(u4_atom_semp, $3, $5); }
      | '%' w skel_t         { $$ = _ycell(u4_atom_fing, $3); }
      ;

    pike_wide
      : '-' w skel_w w wide      { $$ = _ytrel(u4_atom_lask, $3, $5); }
      | '+' w wide               { $$ = _ycell(u4_atom_plic, $3); }
      | '*' w skel_w w wide      { $$ = _ytrel(u4_atom_semp, $3, $5); }
      | ':' w wide               { $$ = _ycell(u4_atom_fing, $3); } 
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
      | tok_mark_pre tok_mark_stig
        { $$ = u4_k_atom_log(yylane, _ycell($1, $2)); }
      ;
        tok_mark_pre
          : ca

        tok_mark_stig
          : ca { $$ = _ycell($1, u4_noun_0); }
                 | cd { $$ = _ycell($1, u4_noun_0); }
                 | ca tok_mark_stig  { $$ = _ycell($1, $2); }
                 | cd tok_mark_stig  { $$ = _ycell($1, $2); }
                 | '-' tok_mark_stig { $$ = _ycell($1, $2); }
                 ;

    tok_chex 
      : '0' 
        { $$ = u4_noun_0; }
      | tok_chex_pre tok_chex_stig
        { $$ = u4_k_atom_heximal(yylane, _ycell($1, $2)); }
      ;
        tok_chex_pre
          : cn | ch
          ;

        tok_chex_stig
          : { $$ = u4_noun_0; }
                    | cd gap tok_chex_stig { $$ = _ycell($1, $3); }
                    | ch gap tok_chex_stig { $$ = _ycell($1, $3); }
                    ;


    tok_delm
      : '0' { $$ = u4_noun_0; }
      | tok_delm_pre tok_delm_stig
        { $$ = u4_k_atom_decimal(yylane, _ycell($1, $2)); }
      ;
        tok_delm_pre: cn;
        tok_delm_stig: { $$ = u4_noun_0; }
                    | cd tok_delm_stig { $$ = _ycell($1, $2); }
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
    dig_clat: '=' '>' { $$ = u4_atom_clat; }
    dig_clet: '`' '<' { $$ = u4_atom_clet; }
    dig_plat: '-' '>' { $$ = u4_atom_plat; }
    dig_plet: '-' '<' { $$ = u4_atom_plet; }
    dig_grat: '~' '>' { $$ = u4_atom_grat; }
    dig_gret: '~' '<' { $$ = u4_atom_gret; }

    dig_quol: '?' ':' { $$ = u4_atom_quol; } 
    dig_quat: '?' '>' { $$ = u4_atom_quat; }
    dig_quet: '?' '<' { $$ = u4_atom_quet; }
    dig_quem: '?' '-' { $$ = u4_atom_quem; }
    dig_quid: '?' '+' { $$ = u4_atom_quid; }
    dig_quax: '?' '&' { $$ = u4_atom_quax; }
    dig_quix: '?' '|' { $$ = u4_atom_quix; }
    dig_quac: '?' '!' { $$ = u4_atom_quac; }
    dig_quop: '?' '=' { $$ = u4_atom_quop; }

    dig_stid: '|' '+' { $$ = u4_atom_stid; }
    dig_ston: '|' '*' { $$ = u4_atom_ston; }
    dig_stol: '|' ':' { $$ = u4_atom_stol; }
    dig_stix: '|' '|' { $$ = u4_atom_stix; }
    dig_stop: '|' '=' { $$ = u4_atom_stop; }
    dig_stem: '|' '-' { $$ = u4_atom_stem; }

    dig_glid: '^' '+' { $$ = u4_atom_glid; }
    dig_glem: '^' '-' { $$ = u4_atom_glem; }
    dig_glop: '^' '=' { $$ = u4_atom_glop; }
    dig_glon: '^' '*' { $$ = u4_atom_glon; }
    dig_glaz: '^' '@' { $$ = u4_atom_glaz; }

    dig_slop: ':' '=' { $$ = u4_atom_slop; } 
    dig_sloc: ':' '~' { $$ = u4_atom_sloc; }
    dig_slid: ':' '+' { $$ = u4_atom_slid; }
    dig_slem: ':' '-' { $$ = u4_atom_slem; }
    dig_slon: ':' '*' { $$ = u4_atom_slon; }
    dig_slux: ':' '.' { $$ = u4_atom_slux; }
    dig_grun: ':' '%' { $$ = u4_atom_grun; }
    dig_slos: ':' '$' { $$ = u4_atom_slos; }
    dig_slip: ':' '^' { $$ = u4_atom_slip; }
/*
    dig_terg: '`' '+' { $$ = u4_atom_terg; }
    dig_hosc: '`' '-' { $$ = u4_atom_hosc; }
    dig_gald: '`' '*' { $$ = u4_atom_gald; }
    dig_blig: '`' '|' { $$ = u4_atom_blig; }
    dig_jarm: '`' '`' { $$ = u4_atom_jarm; }
*/
    dig_brax: '&' '&' { $$ = u4_atom_brax; }
    dig_bron: '&' ':' { $$ = u4_atom_bron; }
    dig_brip: '&' '^' { $$ = u4_atom_brip; }
    dig_brop: '&' '=' { $$ = u4_atom_brop; }
    dig_broc: '&' '~' { $$ = u4_atom_broc; }

    dig_dept: '%' '>' { $$ = u4_atom_dept; }
    dig_flit: '%' '=' { $$ = u4_atom_flit; }
    dig_gorm: '%' '+' { $$ = u4_atom_gorm; }
    dig_peft: '%' '*' { $$ = u4_atom_peft; }
    dig_drib: '%' '|' { $$ = u4_atom_drib; }
    dig_shud: '%' '<' { $$ = u4_atom_shud; }
    dig_warx: '%' '?' { $$ = u4_atom_warx; }

    dig_stop: '=' '=' { $$ = u4_atom_stop; }


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

/* Annotate (gene) with plol.
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
     u4_atom_plol, 
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
    // return u4_k_trel(lane, u4_atom_plaz, pif, scanner.scan);
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

