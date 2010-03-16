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
  %expect 969

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

form_w
  : form_w_core
  | form_w_core ':' form_w      { $$ = _ytrel(u4_atom_grip, $1, $3); }
  ;

  form_w_core
    : form_w_base
    | form_w_crib   { $$ = _ycell(u4_atom_crib, $1); }
    | form_rock     { $$ = _ycell(u4_atom_rock, $1); }
    | form_w_gate   { $$ = _ycell(u4_atom_gate, $1); }
    | form_w_pick   { $$ = _ycell(u4_atom_pick, $1); }
    | form_w_dish   { $$ = _ycell(u4_atom_dish, $1); }
    ;

    form_w_base
      : '@'   { $$ = u4_atom_atom; }
      | '*'   { $$ = u4_atom_blur; }
      | '?'   { $$ = u4_atom_flag; }
      ;

    form_w_crib
      : '[' g form_w_crib_items g ']' { $$ = $3; }
      ;

      form_w_crib_item
        : form_w                  { $$ = _ycell(u4_noun_0, $1); }
        | tok_mark g '=' g form_w { $$ = _ycell($1, $5); }
        ;

      form_w_crib_items
        : form_w_crib_item                 { $$ = _ycell($1, u4_noun_0); }
        | form_w_crib_item w form_w_crib_items { $$ = _ycell($1, $3); }
        ;

    form_w_gate
      : wide_deep
      | wide_norm
      ;

    form_w_dish
      : '~' wide
      ;

    form_w_pick
      : '{' g form_ws '}'      { $$ = $3; }
      ;

      form_ws
        : form_w g       { $$ = _ycell($1, u4_noun_0); }
        | form_w w form_ws { $$ = _ycell($1, $3); }
        ;

    form_rock
      : '~'               { $$ = u4_noun_0; }
      | '&'               { $$ = u4_noun_0; }
      | '|'               { $$ = u4_noun_1; }
      | tok_delm          { $$ = $1; }
      | '0' 'x' tok_chex  { $$ = $3; }
      | tok_loct          { $$ = $1; }
      | '%' tok_mark      { $$ = $2; }
      ;


form_t
  : form_w
  | dig_crib w form_t_crib    { $$ = _ycell($1, $3); }
  | dig_gate w form_t_gate    { $$ = _ycell($1, $3); }
  | dig_pick w form_t_pick    { $$ = _ycell($1, $3); }
  | dig_grip w form_t_grip    { $$ = _ycell($1, $3); }
  | dig_dish w form_t_dish    { $$ = _ycell($1, $3); }
  ;

    form_t_crib
      : form_t_crib_items dig_stop { $$ = $1; }
      ;

      form_t_crib_item
        : form_t                  { $$ = _ycell(u4_noun_0, $1); }
        | tok_mark g '=' g form_t { $$ = _ycell($1, $5); }
        ;

      form_t_crib_items
        : form_t_crib_item w                   { $$ = _ycell($1, u4_noun_0); }
        | form_t_crib_item w form_t_crib_items { $$ = _ycell($1, $3); }
        ;

    form_t_gate
      :  gene
      ;

    form_t_dish
      :  gene
      ;

    form_t_pick
      : form_ts dig_stop { $$ = $1; }
      ;

      form_ts
        : form_t w         { $$ = _ycell($1, u4_noun_0); }
        | form_t w form_ts { $$ = _ycell($1, $3); }
        ;

    form_t_grip
      : form_t w form_t { $$ = _ycell($1, $3); }

wide
  : wide_deep
  | wide_cage
  | wide_hard
  | wide_fast
  | wide_norm
  ;

    wide_deep
      : rope  
        { $$ = _ytrel(u4_atom_kick, $1, u4_noun_0); }
      | rope '(' nail_wide_star ')'
        { $$ = _ytrel(u4_atom_kick, $1, $3); }
      | '(' g wide_some ')'
        { $$ = _ytrel(u4_atom_garc, u4_ch($3), u4_ct($3)); }
      ;

    wide_fast
      : '!' wide
        { $$ = _ycell(u4_atom_blem, $2); }
      | '@' 
        { $$ = _ycell(u4_atom_bink, u4_atom_atom); }
      | '*'
        { $$ = _ycell(u4_atom_bink, u4_atom_blur); }
      | '?'
        { $$ = _ycell(u4_atom_bink, u4_atom_flag); }
      | ':' form_w_crib
        { $$ = _ytrel(u4_atom_bink, u4_atom_crib, $2); }
      | '~' form_w '.' wide
        { $$ = _ytrel(u4_atom_lorb, $2, $4); }
      ;

    wide_cage
      : '[' g item_wide_some ']'
        { $$ = _ycell(u4_atom_cret, $3); }
      ;

    wide_hard
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
      : ':' tok_nock '.' wide { $$ = _ytrel(u4_atom_nock, $2, $4); }

      | dig_pont wide_norm_pont  /* => */ { $$ = _ycell($1, $2); }
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
      | dig_dant wide_norm_dant  /* ?| */ { $$ = _ycell($1, $2); }
      | dig_blem wide_norm_blem  /* ?! */ { $$ = _ycell($1, $2); }
      | dig_like wide_norm_like  /* ?= */ { $$ = _ycell($1, $2); }

      | dig_malk wide_norm_malk  /* |+ */ { $$ = _ycell($1, $2); }
      | dig_blin wide_norm_blin  /* |* */ { $$ = _ycell($1, $2); }
      | dig_flic wide_norm_flic  /* |: */ { $$ = _ycell($1, $2); }
      | dig_drol wide_norm_drol  /* || */ { $$ = _ycell($1, $2); }
      | dig_lome wide_norm_lome  /* |= */ { $$ = _ycell($1, $2); }
      | dig_flot wide_norm_flot  /* |- */ { $$ = _ycell($1, $2); }
      | dig_bink wide_norm_bink  /* |~ */ { $$ = _ycell($1, $2); }

      | dig_cast wide_norm_cast  /* ^- */ { $$ = _ycell($1, $2); }
      | dig_lorb wide_norm_lorb  /* ^: */ { $$ = _ycell($1, $2); }
      | dig_sure wide_norm_sure  /* ^= */ { $$ = _ycell($1, $2); }

      | dig_kick wide_norm_kick  /* := */ { $$ = _ycell($1, $2); }
      | dig_mang wide_norm_mang  /* :~ */ { $$ = _ycell($1, $2); }
      | dig_garc wide_norm_garc  /* :+ */ { $$ = _ycell($1, $2); }
      | dig_flec wide_norm_flec  /* :- */ { $$ = _ycell($1, $2); }
      | dig_grun wide_norm_grun  /* :% */ { $$ = _ycell($1, $2); }

      | dig_cret wide_norm_cret  /* ++ */ { $$ = _ycell($1, $2); }
      | dig_cage wide_norm_cage  /* +- */ { $$ = _ycell($1, $2); }
      | dig_name wide_norm_name  /* += */ { $$ = _ycell($1, $2); }
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
      
      wide_norm_dant
        : '{' g wide_star '}' { $$ = $3; }
   
      wide_norm_blem
        : wide
   
      wide_norm_like
        : '{' g rope g wide g '}' { $$ = _ycell($3, $5); }
   

    /** Loading.
    **/
      wide_norm_malk
        : page_star dig_stop { $$ = $1; }
   
      wide_norm_blin
        : wide w page_star dig_stop { $$ = _ycell($1, $3); }

      wide_norm_flic
        : '{' g form_w_crib_items w wide g '}'        
            { $$ = _ycell(_ycell(u4_atom_crib, $3), $5); }

      wide_norm_drol
        : '{' g form_w w form_w_crib_items w wide g '}' 
          { $$ = _ytrel($3, _ycell(u4_atom_crib, $5), $7); }

      wide_norm_lome
        : wide

      wide_norm_flot
        : wide
    
    /** Casts.
    **/
      wide_norm_cast
        : '{' g wide w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_lorb
        : '{' g form_w w wide g '}' { $$ = _ycell($3, $5); }

      wide_norm_sure
        : '{' g wide w wide w wide g '}' { $$ = _ycell($3, $3); }

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

      wide_norm_name
        : '{' g tok_mark w wide g '}' { $$ = _ycell($3, $5); }
      
      wide_norm_grun
        : '{' g nail_wide_star ':' w wide '}' { $$ = _ycell($3, $6); }

      wide_norm_bink
        : form_w

  ;

tall
  : tall_norm { $$ = _watt_locate(yylane, &@1, $1); }
  ;

  /** Normal tall genes.
  **/
    tall_norm
      : ':' tok_nock w gene { $$ = _ytrel(u4_atom_nock, $2, $4); }

      | dig_pont w tall_norm_pont  /* => */ { $$ = _ycell($1, $3); }
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
      | dig_dant w tall_norm_dant  /* ?| */ { $$ = _ycell($1, $3); }
      | dig_blem w tall_norm_blem  /* ?! */ { $$ = _ycell($1, $3); }
      | dig_like w tall_norm_like  /* ?= */ { $$ = _ycell($1, $3); }
    
      | dig_malk w tall_norm_malk  /* |+ */ { $$ = _ycell($1, $3); }
      | dig_blin w tall_norm_blin  /* |* */ { $$ = _ycell($1, $3); }
      | dig_flic w tall_norm_flic  /* |: */ { $$ = _ycell($1, $3); }
      | dig_drol w tall_norm_drol  /* || */ { $$ = _ycell($1, $3); }
      | dig_lome w tall_norm_lome  /* |= */ { $$ = _ycell($1, $3); }
      | dig_flot w tall_norm_flot  /* |- */ { $$ = _ycell($1, $3); }
      | dig_bink w tall_norm_bink  /* |~ */ { $$ = _ycell($1, $3); }

      | dig_cast w tall_norm_cast  /* ^- */ { $$ = _ycell($1, $3); }
      | dig_lorb w tall_norm_lorb  /* ^: */ { $$ = _ycell($1, $3); }
      | dig_sure w tall_norm_sure  /* ^= */ { $$ = _ycell($1, $3); }

      | dig_kick w tall_norm_kick  /* := */ { $$ = _ycell($1, $3); }
      | dig_mang w tall_norm_mang  /* :~ */ { $$ = _ycell($1, $3); }
      | dig_garc w tall_norm_garc  /* :+ */ { $$ = _ycell($1, $3); }
      | dig_flec w tall_norm_flec  /* :- */ { $$ = _ycell($1, $3); }
      | dig_grun w tall_norm_grun  /* :% */ { $$ = _ycell($1, $3); }

      | dig_cret w tall_norm_cret  /* ++ */ { $$ = _ycell($1, $3); }
      | dig_cage w tall_norm_cage  /* +- */ { $$ = _ycell($1, $3); }
      | dig_name w tall_norm_name  /* += */ { $$ = _ycell($1, $3); }
   
      | dig_dbug w tall_norm_dbug  /* !? */ { $$ = _ycell($1, $3); }
      ;

    /** Combinators.
    **/
      tall_norm_pont
        : tok_mark w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_clet
        : tok_mark w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_trop
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_prec
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_link
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_colb 
        : gene w gene { $$ = _ycell($1, $3); }


    /** Branches and conditions.
    **/
      tall_norm_quiz
        : gene w gene w gene { $$ = _ytrel($1, $3, $5); }

      tall_norm_feng
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_prex
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_gril
        : rope w pike_tall_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_stam
        : gene w pike_tall_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_boce
        : tall_star dig_stop { $$ = $1; }
      
      tall_norm_dant
        : tall_star dig_stop { $$ = $1; }

      tall_norm_blem
        : gene

      tall_norm_like
        : rope w gene { $$ = _ycell($1, $3); }


    /** Loading.
    **/
      tall_norm_malk
        : page_star dig_stop { $$ = $1; }
   
      tall_norm_blin
        : gene w page_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_flic
        : form_t_crib_items dig_stop w gene 
          { $$ = _ycell(_ycell(u4_atom_crib, $1), $4); }

      tall_norm_drol
        : form_t w form_t_crib_items dig_stop w gene
          { $$ = _ytrel($1, _ycell(u4_atom_crib, $3), $6); }

      tall_norm_lome
        : gene

      tall_norm_flot
        : gene
   
      tall_norm_bink
        : form_t
        

    /** Casts.
    **/
      tall_norm_cast
        : gene w gene { $$ = _ycell($1, $3); }

      tall_norm_lorb
        : form_t w gene { $$ = _ycell($1, $3); }

      tall_norm_sure
        : gene w gene w gene { $$ = _ytrel($1, $3, $5); }

    /** Call and use.
    **/
      tall_norm_kick
        : gene w nail_tall_star dig_stop { $$ = _ycell($1, $3); }

      tall_norm_mang
        : gene w tall { $$ = _ycell($1, $3); }

      tall_norm_garc
        : gene w tall_some dig_stop { $$ = _ycell($1, $3); }

      tall_norm_flec
        : gene 

      tall_norm_grun
        : nail_tall_star dig_stop w gene  { $$ = _ycell($1, $4); }

      tall_norm_cret
        : item_tall_some dig_stop   
          { $$ = $1; }

      tall_norm_cage
        : tall_some dig_stop
          { $$ = $1; }

      tall_norm_name
        : tok_mark w gene 
          { $$ = _ycell($1, $3); }
      
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
      : rope w gene { $$ = _ycell($1, $3); }
      ;

    nail_tall_some
      : nail_tall w                 { $$ = _ycell($1, u4_noun_0); }
      | nail_tall w nail_tall_some  { $$ = _ycell($1, $3); }
      ;

    nail_tall_star
      : { $$ = u4_noun_0; }
      | nail_tall_some
      ;


  
  /** Pike: pattern reaction.
  **/
    pike_tall
      : '-' w form_t w gene  { $$ = _ytrel(u4_atom_lask, $3, $5); }
      | '+' w form_t         { $$ = _ycell(u4_atom_plic, $3); }
      | ':' w form_t w gene  { $$ = _ytrel(u4_atom_semp, $3, $5); }
      | '=' w form_t         { $$ = _ycell(u4_atom_fing, $3); }
      | '*' w gene           { $$ = _ycell(u4_atom_homp, $2); }
      ;

    pike_wide
      : '-' w form_w w wide  { $$ = _ytrel(u4_atom_lask, $3, $5); }
      | '+' w wide           { $$ = _ycell(u4_atom_plic, $3); }
      | ':' w form_w w wide  { $$ = _ytrel(u4_atom_semp, $3, $5); }
      | '=' w wide           { $$ = _ycell(u4_atom_fing, $3); } 
      | '*' w wide           { $$ = _ycell(u4_atom_homp, $2); }
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
        | wide_hard
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


    tok_nock
      : '3' { $$ = u4_noun_3; }
      | '4' { $$ = u4_noun_4; }
      | '5' { $$ = u4_noun_5; }
      | '6' { $$ = u4_noun_6; }
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
    dig_dant: '?' '|' { $$ = u4_atom_dant; }
    dig_blem: '?' '!' { $$ = u4_atom_blem; }
    dig_like: '?' '=' { $$ = u4_atom_like; }

    dig_malk: '|' '+' { $$ = u4_atom_malk; }
    dig_blin: '|' '*' { $$ = u4_atom_blin; }
    dig_flic: '|' ':' { $$ = u4_atom_flic; }
    dig_drol: '|' '|' { $$ = u4_atom_drol; }
    dig_lome: '|' '=' { $$ = u4_atom_lome; }
    dig_flot: '|' '-' { $$ = u4_atom_flot; }
    dig_bink: '|' '~' { $$ = u4_atom_bink; }

    dig_cast: '^' '-' { $$ = u4_atom_cast; }
    dig_lorb: '^' ':' { $$ = u4_atom_lorb; }
    dig_sure: '^' '=' { $$ = u4_atom_sure; }

    dig_kick: ':' '=' { $$ = u4_atom_kick; } 
    dig_mang: ':' '~' { $$ = u4_atom_mang; }
    dig_garc: ':' '+' { $$ = u4_atom_garc; }
    dig_flec: ':' '-' { $$ = u4_atom_flec; }
    dig_grun: ':' '%' { $$ = u4_atom_grun; }

    dig_cret: '+' '+' { $$ = u4_atom_cret; }
    dig_cage: '+' '-' { $$ = u4_atom_cage; }
    dig_name: '+' '=' { $$ = u4_atom_name; }

    dig_dbug: '!' '#' { $$ = u4_atom_dbug; }

    dig_crib: '*' '+' { $$ = u4_atom_crib; }
    dig_grip: '*' '|' { $$ = u4_atom_grip; }
    dig_pick: '*' '*' { $$ = u4_atom_pick; }
    dig_gate: '*' ':' { $$ = u4_atom_gate; }
    dig_dish: '*' '~' { $$ = u4_atom_dish; }

    dig_stop: '=' '=' { $$ = u4_atom_lome; }


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

/* Annotate (gene) with spot.
*/
static u4_noun
_watt_locate(u4_lane lane,
             const void *vlocp,
             u4_noun gene)
{
  const YYLTYPE *llocp = vlocp;   /* bufalo estupido */

#if 0
  return gene;
#else
  return u4_k_trel
    (lane, 
     u4_atom_spot, 
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

    // return scanner.scan;
    return u4_k_trel(lane, u4_atom_home, pif, scanner.scan);
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

