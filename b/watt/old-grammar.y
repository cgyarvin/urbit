/* The boot parser for quol.
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
        u4_log  site;   /* list(term) - path from top to part */
        u4_atom tube;   /* part data (ie, source document) */
        u4_tab  bowl;   /* parts - (term sack). */
      } p;
      
      /* Scanning state.
      */
      struct {
        u4_t    t_alph;   /* parse an alph command - hack */
        u4_pb   pb;       /* byte position */
        u4_xw   xw_line;  /* current line */
        u4_xw   xw_col;   /* current column */
      } s;
    };
#   define yylane (scanner->lane)

  /* Forward declarations.
  */
    static u4_noun _quol_parse_part(struct _u4_scanner *, u4_noun);
    static u4_noun _quol_locate(u4_lane, const void *, u4_noun);

  /* Construction macros.
  */
#   define _ycell(a, b)       u4_k_cell(yylane, a, b)
#   define _ytrel(a, b)       u4_k_trel(yylane, a, 
%}

/* Bison directives.
*/
  /* With the mighty power of GLR... 
  */
  %glr-parser
 
  /* We laugh at your petty shift-reduce conflicts.
  */
  %expect 19

  %pure-parser
  %locations
  %parse-param {struct _u4_scanner *scanner}
  %lex-param {struct _u4_scanner *scanner}

/* Special control tokens.
*/
  %token T_alph

/* Support routines.
*/
%{
%}

%%

gene
  : 
module
  : g expression g
    { scanner->scan = _quol_locate(yylane, &@2, $2); }
  | g expansion g
    { scanner->scan = $2; }
  | T_alph g alph_line g
    { scanner->scan = $3; }
  ;

statement
  : expression
  | expansion { $$ = _quol_locate(yylane, &@1, $1); }
  ;

expansion
  : '?' ':' w statement w statement w statement 
    { $$ = u4_k_qual(yylane, u4_atom_if, $4, $6, $8); }
  | '?' '.' w statement w statement w statement
    { $$ = u4_k_qual(yylane, u4_atom_un, $4, $6, $8); }
  | '?' ',' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_so, $4, $6); }
  | '?' '`' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_no, $4, $6); }

  | '?' '-' w statement blades '=' '='
    { $$ = u4_k_trel(yylane, u4_atom_fan, $4, $5); }
  | '?' '+' w statement blades '=' '='
    { $$ = u4_k_trel(yylane, u4_atom_fit, $4, $5); }
  | '?' '=' w statement states '=' '='
    { $$ = u4_k_trel(yylane, u4_atom_fix, $4, $5); }

  | '?' '&' states '=' '='
    { $$ = u4_k_cell(yylane, u4_atom_all, $3); }
  | '?' '|' states '=' '='
    { $$ = u4_k_cell(yylane, u4_atom_any, $3); }
  | '?' '!' w statement
    { $$ = u4_k_cell(yylane, u4_atom_not, $4); }
  | '?' '~' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_like, $4, $6); }

  | '|' '!' w path w statement maps '=' '='
    { $$ = u4_k_qual(yylane, u4_atom_boot, $4, $6, $7); }
  | '|' '+' maps '=' '='
    { $$ = u4_k_cell(yylane, u4_atom_book, $3); }
  | '|' '-' w statement
    { $$ = u4_k_cell(yylane, u4_atom_loop, $4); }
  | '|' '=' w statement
    { $$ = u4_k_cell(yylane, u4_atom_bolt, $4); }
  | '|' '%' w statement w statement
    { $$ = u4_k_qual(yylane, u4_atom_plug, $4, u4_noun_0, $6); }
  | '|' '*' w statement maps statement
    { $$ = u4_k_qual(yylane, u4_atom_gear, $4, $5, $6); }

  | '=' '+' w path w statement w statement
    { $$ = u4_k_qual(yylane, u4_atom_push, $4, $6, $8); }
  | '=' '-' w path w statement w statement
    { $$ = u4_k_qual(yylane, u4_atom_pull, $4, $6, $8); }
  | '=' '|' spairs statement
    { $$ = u4_k_trel(yylane, u4_atom_post, $3, $4); }
  | '=' '.' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_pose, $4, $6); }
  | '=' ':' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_cast, $4, $6); }
  | '=' '?' w statement w statement w statement
    { $$ = u4_k_qual(yylane, u4_atom_sure, $4, $6, $8); }

  | '%' '+' w statement states '=' '='
    { $$ = u4_k_trel(yylane, u4_atom_punt, $4, u4_log_tupl(yylane, $5)); }

  | '%' '-' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_punt, $4, $6); }

  | '%' '=' w statement w statement
    { $$ = u4_k_trel(yylane, u4_atom_link, $4, $6); }
  | '%' '~' w statement w statement  
    { $$ = u4_k_trel(yylane, u4_atom_nilk, $4, $6); }
  | '%' '*' w statement w statement  
    { $$ = u4_k_trel(yylane, u4_atom_cook, $4, $6); }

  | '~' '-' w statement w statement
    { $$ = u4_k_cell(yylane, $4, $6); }
  | '~' '=' w statement w statement w statement
    { $$ = u4_k_trel(yylane, $4, $6, $8); }
  | '~' '+' w statement w statement w statement w statement
    { $$ = u4_k_qual(yylane, $4, $6, $8, $10); }
  | '~' '|' states '=' '='
    { $$ = u4_k_cell(yylane, u4_atom_tupl, $3); }

  | '^' '!' w statement
    { $$ = u4_k_cell(yylane, u4_atom_dbug, $4); }
  ;

  maps
    : w 
      { $$ = u4_noun_0; }
    | w '-' w path w statement maps
      { $$ = u4_k_cell(yylane, u4_k_cell(yylane, $4, $6), $7); }
    ;

  states
    : w 
      { $$ = u4_noun_0; }
    | w statement states 
      { $$ = u4_k_cell(yylane, $2, $3); }
    ;

  spairs
    : w 
      { $$ = u4_noun_0; }
    | w '-' w statement w statement spairs
      { $$ = u4_k_cell(yylane, u4_k_cell(yylane, $4, $6), $7); }
    ;
  
  blades 
    : w 
      { $$ = u4_noun_0; }
    | w blade blades
      { $$ = u4_k_cell(yylane, $2, $3); }
    ;

    blade
      : cases guard statement
        { $$ = u4_k_cell(yylane, u4_k_cell(yylane, $1, $2), $3); }
      ;

    cases
      : expression
        { $$ = u4_k_cell(yylane, $1, u4_noun_0); }
      | expression ',' w cases
        { $$ = u4_k_cell(yylane, $1, $4); }
      ;

    guard
      : w 
        { $$ = u4_k_cell(yylane, u4_atom_rock, u4_noun_0); }
      | w ';' expression w 
        { $$ = $3; }
      ;

expression
  : component
  | combination
  | binding
  | connection
  | inversion
  | primitive
  ;

  combination
    : component '.' expression
      { $$ = u4_k_trel(yylane, u4_atom_nilk, $1, $3); }
    | component '^' mutation '.' expression
      { $$ = u4_k_qual(yylane, u4_atom_comb, $1, $3, $5); }
    | component '^' mutation
      { $$ = u4_k_trel(yylane, u4_atom_bend, $3, $1); }
    | port mutation
      { 
        $$ = u4_k_trel
              (yylane, u4_atom_bend, 
                       $2, 
                       u4_k_trel(yylane, u4_atom_look, u4_noun_0, $1));
      }
    | '`' step port mutation
      {
        $$ = u4_k_trel
              (yylane, u4_atom_bend, 
                       $4, 
                       u4_k_trel(yylane, u4_atom_look, $2, $3));
      }
    ;

    mutation 
      : '(' g expairs g ')'
        { $$ = $3; }
      ;
     
      expairs 
        : expair
          { $$ = u4_k_cell(yylane, $1, u4_noun_0); }
        | expair ',' w expairs
          { $$ = u4_k_cell(yylane, $1, $4); }
        ;

        expair
          : expression w expression
            { $$ = u4_k_cell(yylane, $1, $3); }
          ;

  binding
    : path '=' expression
      { $$ = u4_k_trel(yylane, u4_atom_coat, $1, $3); }
    | path '*'
      { $$ = u4_k_trel
          (yylane, u4_atom_coat, 
                   $1, 
                   u4_k_trel(yylane, u4_atom_roll, u4_noun_3, u4_noun_0));
      }

  connection
    : component '/' expression
      { $$ = u4_k_cell(yylane, $1, $3); }
    ;

  inversion
    : '!' expression
      { $$ = u4_k_cell(yylane, u4_atom_not, $2); }
    ;

  primitive
    : '&' root '.' expression
      { $$ = u4_k_trel(yylane, u4_atom_raw, $2, $4); }

      root 
        : '3' { $$ = u4_noun_3; }
        | '4' { $$ = u4_noun_4; }
        | '5' { $$ = u4_noun_5; }
        | '6' { $$ = u4_noun_6; }
        ;

component
  : punt
  | all
  | any
  | lamb
  | goat
  | pick
  | look
  | seek
  | cell
  | rock
  | part
  ;

  part
    : '#' term
      { $$ = _quol_parse_part(scanner, $2); }

  all
    : '&' '(' g expression punt_tail
      { $$ = u4_k_trel(yylane, u4_atom_all, $4, $5); }
    ;

  any
    : '|' '(' g expression punt_tail
      { $$ = u4_k_trel(yylane, u4_atom_any, $4, $5); }
    ;

  lamb
    : '~' '(' g expression w expression g ')'
      { $$ = u4_k_trel(yylane, u4_atom_lamb, $4, $6); }
    ;
 
  goat
    : '{' g expression goat_tail
      { $$ = u4_k_trel(yylane, u4_atom_goat, $3, $4); }
    ;
    goat_tail
      : g '}' { $$ = u4_noun_0; }
      | w expression goat_tail { $$ = u4_k_cell(yylane, $2, $3); }
      ;
    ;

  pick
    : '?' '(' g expression pick_tail
      { $$ = u4_k_trel(yylane, u4_atom_fix, $4, $5); }
    ;
    pick_tail
      : g ')' { $$ = u4_noun_0; }
      | w expression pick_tail { $$ = u4_k_cell(yylane, $2, $3); }
      ;
    ;
  look
    : port { $$ = u4_k_trel(yylane, u4_atom_look, u4_noun_0, $1); }
    | '`' step port { $$ = u4_k_trel(yylane, u4_atom_look, $2, $3); }
    ;

    port
      : path
      | '$' { $$ = u4_noun_0; }
      ;

    step 
      : { $$ = u4_noun_1; }
      | '`' step { $$ = u4_op_inc(yylane, $2); }
      ;

  seek
    : '+' decimal
      { $$ = u4_k_cell(yylane, u4_atom_limb, $2); }
    ;

  punt
    : '(' g expression punt_tail
      { if ( u4_n_zero($4) )
          $$ = u4_k_cell(yylane, u4_atom_pop, $3);
        else
          $$ = u4_k_trel
            (yylane, u4_atom_punt, $3, u4_log_tupl(yylane, $4));
      }
    ;
    punt_tail
      : g ')' { $$ = u4_noun_0; }
      | w expression punt_tail { $$ = u4_k_cell(yylane, $2, $3); }
      ;

  cell
    : '[' g expansion g ']'
      { $$ = _quol_locate(yylane, &@3, $3); }
    | '[' g expression cell_tail
      { $$ = u4_n_zero($4) 
          ? $3 : u4_k_cell(yylane, $3, u4_log_tupl(yylane, $4)); 
      }
    ;
    cell_tail
      : g ']' { $$ = u4_noun_0; }
      | w expression cell_tail { $$ = u4_k_cell(yylane, $2, $3); }
      ;

  rock
    : '%' path
      { $$ = u4_k_cell(yylane, u4_atom_rock, $2); }
    | '%' quote
      { $$ = u4_k_cell(yylane, u4_atom_rock, $2); }
    | '%' decimal
      { $$ = u4_k_cell(yylane, u4_atom_rock, $2); }
    | '%' '0' 'x' heximal
      { $$ = u4_k_cell(yylane, u4_atom_rock, $4); }
    | '%' '&'
      { $$ = u4_k_cell(yylane, u4_atom_rock, u4_noun_0); }
    | '%' '|'
      { $$ = u4_k_cell(yylane, u4_atom_rock, u4_noun_1); }
    | '~'
      { $$ = u4_k_cell(yylane, u4_atom_rock, u4_noun_0); }
    | '^'
      { 
        u4_noun hax = u4_k_trel(yylane, u4_atom_roll, u4_noun_3, u4_noun_0);
        $$ = u4_k_cell(yylane, hax, hax);
      } 
    | '@'
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_5, u4_noun_0); }
    | quote
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_5, $1); }
    | decimal
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_5, $1); }
    | '0' 'x' heximal
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_5, $3); }
    | '&'
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_4, u4_noun_0); }
    | '?'
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_4, u4_noun_0); }
    | '|'
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_4, u4_noun_1); }
    | '*'
      { $$ = u4_k_trel(yylane, u4_atom_roll, u4_noun_3, u4_noun_0); }
    | '!' '!'
      { $$ = u4_k_cell(yylane, u4_atom_limb, u4_noun_0); }
    ;

path
  : term
  | term '_' path { $$ = u4_k_cell(yylane, $1, $3); }
  ;

term
  : term_pre
  | term_pre term_post
    { $$ = u4_k_atom_log(yylane, u4_k_cell (yylane, $1, $2)); }
  ;
    term_pre: ca
    term_post: ca { $$ = u4_k_cell(yylane, $1, u4_noun_0); }
             | cd { $$ = u4_k_cell(yylane, $1, u4_noun_0); }
             | ca term_post  { $$ = u4_k_cell(yylane, $1, $2); }
             | cd term_post  { $$ = u4_k_cell(yylane, $1, $2); }
             | '-' term_post { $$ = u4_k_cell(yylane, $1, $2); }
             ;

heximal 
  : '0' 
    { $$ = u4_noun_0; }
  | heximal_pre heximal_post
    { $$ = u4_k_atom_heximal(yylane, u4_k_cell(yylane, $1, $2)); }
  ;
    heximal_pre: cn | ch;
    heximal_post: { $$ = u4_noun_0; }
                | cd gap heximal_post { $$ = u4_k_cell(yylane, $1, $3); }
                | ch gap heximal_post { $$ = u4_k_cell(yylane, $1, $3); }
                ;


decimal
  : '0' { $$ = u4_noun_0; }
  | decimal_pre decimal_post
    { $$ = u4_k_atom_decimal(yylane, u4_k_cell(yylane, $1, $2)); }
  ;
    decimal_pre: cn;
    decimal_post: { $$ = u4_noun_0; }
                | cd decimal_post { $$ = u4_k_cell(yylane, $1, $2); }
                ;

quote
  : '\'' quote_mid '\''
    { $$ = u4_k_atom_log(yylane, $2); }
  ;
    quote_mid: { $$ = u4_noun_0; }
             | cq quote_mid { $$ = u4_k_cell(yylane, $1, $2); }
             ;

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

ca: 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm'
  | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z'
  | 'A' | 'B' | 'C' | 'D' | 'E' | 'F' | 'G' | 'H' | 'I' | 'J' | 'K' | 'L' | 'M'
  | 'N' | 'O' | 'P' | 'Q' | 'R' | 'S' | 'T' | 'U' | 'V' | 'W' | 'X' | 'Y' | 'Z'
  ;

ch: 'a' | 'b' | 'c' | 'd' | 'e' | 'f';
cd: '0' | cn;
cn: '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9';

cp: cm | '\'' | '\\';

cm: '~' | '`' | '!' | '@' | '#' | '$' | '%' | '^' | '&' | '*' | '(' | ')' 
  | '{' | '[' | '}' | ']' | '|' | ':' | ';' | '"' | '<' | '>' 
  | ',' | '.' | '?' | '/' | '_' | '-' | '+' | '='
  ;

cw: ' ' | '\n';
cl: ca | cd | cp | ' ';
cq: ca | cd | cm | ' ' 
  | '\\' '\\' { $$ = $2; }
  | '\\' '\'' { $$ = $2; }
  ;

/*
hume_command
  : hume_disp hume_pipe hume_src
    { $$ = u4_k_qual(yylane, u4_atom_hume, $1, $2, $3); }
  
    hume_disp
      : { $$ = u4_k_cell(yylane, u4_atom_show, u4_atom_noun); }
      ;

    hume_pipe
      : { $$ = u4_noun_0; }
      ;

    hume_src
      : statement
      ;
*/

alph_line
  : 'n' w term w alph_code
    { $$ = u4_k_trel(yylane, u4_atom_new, $3, $5); }
  | 'm' w term w alph_code
    { $$ = u4_k_trel(yylane, u4_atom_mod, $3, $5); }
  | 's' w path w alph_code
    { $$ = u4_k_trel(yylane, u4_atom_save, $3, $5); }
  | 'f' w term w expression w statement
    { $$ = u4_k_qual(yylane, u4_atom_fun, $3, $5, $7); }
  | 'w' w alph_code
    { $$ = u4_k_cell(yylane, u4_atom_weak, $3); }
  | 'j' w decimal
    { $$ = u4_k_cell(yylane, u4_atom_jet, $3); }
  | g alph_code
    { $$ = u4_k_cell(yylane, u4_atom_weak, $2); }
  ;

  alph_code
    : statement
      { $$ = u4_k_cell(yylane, u4_atom_gene, _quol_locate(yylane, &@1, $1)); }
    | '<' g statement w path g '>'
      { $$ = u4_k_trel(yylane, u4_atom_read, $3, $5); }

    | ';' g path w expression alph_run_tail
      {
        $$ = u4_k_trel
          (yylane, 
           u4_atom_run, 
           $3, 
           u4_n_zero($6) 
             ? $5 : u4_k_cell(yylane, $5, u4_log_tupl(yylane, $6)));
      }
    ;

    alph_run_tail
      : g '}' { $$ = u4_noun_0; }
      | w expression alph_run_tail { $$ = u4_k_cell(yylane, $2, $3); }
      ;

/*
  | alph_line_write
  | alph_line_fun
  | alph_line_boot
  | alph_line_print

  alph_line_print
    : alph_line_print_blur
    | alph_line_print_dec
    | alph_line_print_hex
    | alph_line_print_text
    | alph_line_print_log
    | alph_line_print_cud
    ;

  alph_line_print_blur
    : 'p' 'b' w code
      { $$ = $4; }
    | 'p' w code
      { $$ = $3; }
    ;
*/
  

%%

/* Annotate (gene) with spot.
*/
static u4_noun
_quol_locate(u4_lane lane,
             const void *vlocp,
             u4_noun gene)
{
  const YYLTYPE *llocp = vlocp;   /* bufalo estupido */

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

  scanner->s.t_alph = 0;
  scanner->s.pb = 0;
  scanner->s.xw_line = 1;
  scanner->s.xw_col = 1;
}

/* _quol_parse_part():
*/
static u4_noun
_quol_parse_part(struct _u4_scanner *scanner,
                 u4_noun term)
{
  u4_lane lane = scanner->lane;
  u4_log  site = scanner->p.site;
  u4_tab  bowl = scanner->p.bowl;
  u4_noun sack;

  if ( !u4_tab_in(term, bowl) ) {
    u4_err(lane, "part", term);
    return u4_exit;
  }
  sack = u4_tab_get(term, bowl);
  site = u4_k_cell(lane, term, site);

  /* Is bison really reentrant?
  */
  return u4_quol_parse(lane, site, sack);
}

/* u4_quol_parse(): 
**
**   At (pif), convert (zar) to a gene.
*/
u4_noun
u4_quol_parse(u4_lane lane,
              u4_site pif,
              u4_sack zar)
{
  struct _u4_scanner scanner;

  _scanner_init(&scanner, lane, pif, zar);

  if ( !yyparse(&scanner) ) {
    u4_assert(scanner.scan);

    return u4_k_trel(lane, u4_atom_site, pif, scanner.scan);
  }
  else {
    return u4_exit;
  }
}

/* u4_quol_parse_alph(): 
**
**   Convert (nas), an alph command, to a parsed noun.  A hack.
*/
u4_noun
u4_quol_parse_alph(u4_lane lane,
                   u4_tube nas)
{
  struct _u4_scanner scanner;

  _scanner_init(&scanner, lane, u4_noun_0, nas);
  scanner.s.t_alph = 1;

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
  if ( scanner->s.t_alph ) {
    scanner->s.t_alph = 0;

    *lvalp = u4_noun_0;
    return T_alph;
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

