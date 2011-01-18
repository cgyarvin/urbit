/* The boot parser for watt.
**
** This file is in the public domain.
*/

/* Pre-bison prologue.
*/
%{
# include "all.h"
#   define  Pit   watt_271

  /* Everything is a noun - no yacc type declarations!
  */
#   define YYSTYPE u2_noun

  /* Our fake scanner.
  */
    struct _u2_scanner {
      u2_ray  wir_r;
      u2_noun scan;     /* result - set by parser */

      /* Per-parse state.
      */
      struct {
        u2_atom tube;   /* part data (ie, source document) */
        u2_book bowl;   /* parts - (mark sack). */
      } p;
      
      /* Scanning state.
      */
      struct {
        uint32_t token;    /* initial type token, if any */
        c3_w    pb;       /* byte position */
        c3_w    xw_line;  /* current line */
        c3_w    xw_col;   /* current column */
      } s;
    };
#   define yqw_r (scanner->wir_r)

  /* Forward declarations.
  */
    static u2_noun _watt_locate(u2_ray, const void *, u2_noun);

  /* Construction macros.
  */
#   define _ycell(a, b)            u2_bc(yqw_r, a, b)
#   define _ytrel(a, b, c)         u2_bt(yqw_r, a, b, c)
#   define _yqual(a, b, c, d)      u2_bq(yqw_r, a, b, c, d)
#   define _yquil(a, b, c, d, e)   u2_bu(yqw_r, a, b, c, d, e)

%}

/* Bison directives.
*/
  /* With the migkty power of GLR... 
  */
  %glr-parser
  %name-prefix="yq"

  /* We laugh at your petty shift-reduce conflicts.
  */
  %expect 59

  %pure-parser
  %locations
  %parse-param {struct _u2_scanner *scanner}
  %lex-param {struct _u2_scanner *scanner}


/* Support routines.
*/
%{
%}

%%

file 
  : g gene g        { scanner->scan = $2; }
  ;

gene
  : tall  { $$ = _watt_locate(yqw_r, &@1, $1); }
  | wide  /* { $$ = _watt_locate(yqw_r, &@1, $1); } */
  ;

wide
  : wide_a
  | wide_rope si_dig wide
    { $$ = _ytrel(c3__bndl, $1, $3); }
  ;

wide_a
  : wide_c
  | tok_term si_bon wide
    { $$ = _ytrel(c3__ktbn, $1, $3); }
  ;

wide_c
  : wide_hard
  | wide_base
  | wide_rope
  | wide_funk
  | wide_cage
  | wide_pick
  | wide_call
  | wide_mtsg
  | wide_norm
  ;

    wide_hard
      : '0' 'x' tok_chex
        { $$ = _ycell(c3__dtsg, $3); }
      | tok_delm
        { $$ = _ycell(c3__dtsg, $1); }
      | si_pam
        { $$ = _ycell(c3__dtsg, _0); }
      | si_bar
        { $$ = _ycell(c3__dtsg, _1); }
      | tok_loct
        { $$ = _ycell(c3__dtsg, $1); }
      | si_mit tok_term
        { $$ = _ycell(c3__dtsg, $2); }
      | si_mit si_mit
        { $$ = _ycell(c3__dtsg, _0); }
      ;
   
    wide_base
      : si_cas
        { $$ = _ycell(c3__tmbn, c3__flag); }
      | si_sar
        { $$ = _ycell(c3__tmbn, c3__blur); }
      | si_ket
        { $$ = _ycell(c3__tmbn, c3__cell); }
      | si_fat
        { $$ = _ycell(c3__tmbn, c3__atom); }
      | si_sig
        { $$ = _ycell(c3__tmbn, c3__null); }
      ;
   
    wide_rope
      : rope            
        { $$ = _ytrel(c3__mtbn, $1, _0); }
      ;
    wide_cage
      : si_nom g bank_wide g si_mon 
        { $$ = _ycell(c3__dgsr, $3); }
      ; 

    wide_pick
      : si_dul g bank_wide g si_lud
        { $$ = _ycell(c3__brcs, $3); } 
      ;

    wide_call
      : si_lep g bank_wide g si_pel
        { $$ = _ycell(c3__mtnp, $3); }
      ;

    wide_mtsg
      : si_sig si_lep rope w gene w bank_wide si_pel
        { $$ = _yqual(c3__mtsg, $3, $5, _ycell(c3__dgsr, $7)); }
 
  /** Wide: funky stuff.
  **/
    wide_funk
      : si_sed g bank_wide g si_des
        { $$ = _ycell(c3__dgsg, $3); }
      | si_sed g si_des
        { $$ = _ycell(c3__dgsg, _0); }
      | rope si_lep rack_wide si_pel
        { $$ = _ytrel(c3__mtbn, $1, $3); }
      | si_zap wide
        { $$ = _ycell(c3__cszp, $2); }
      | si_pam wide
        { $$ = _ycell(c3__tmnp, $2); }
      | si_sar wide
        { $$ = _ycell(c3__mtsr, $2); }
      | si_cab wide
        { $$ = _ycell(c3__tmpd, $2); }
      | si_tic wide si_tic wide
        { $$ = _ytrel(c3__ktnp, $2, $4); }
/*
      | si_sol fath
        { $$ = $2; }
*/
      ;

  /** Hints.
  **/
    hint
      : tok_term
      | tok_term '.' wide { $$ = _ycell($1, $3); }
      ;

    hont
      : tok_term
      | tok_term '.' wide   { $$ = _ycell($1, $3); }
      | tok_term '.' w gene { $$ = _ycell($1, $4); }
      ;
/*
    path 
      : thin
      | thin si_sol path    { $$ = _ytrel(c3__dgnp, $1, $3); }
      ;

    thin
      : term        { $$ = _ycell(c3__dtsg, $1); }
      | wide_hard
      | wide_cage
      | wide_pick
      | wide_call
      ;
*/

  /** Wide: normals.
  **/
    wide_norm: di_casdig body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_casdot body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_casdul body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_caslud body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_caspam body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_casbar body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_cassig body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_caszap body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_casbon body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_casnep body_h_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_cassar body_i_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_bonped body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bonnep body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bonlud body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bondul body_b_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_barnep body_o_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barbon body_o_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bardul body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barsar body_e_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barmit body_e_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bardig body_o_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barcas body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barsig body_i_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barlud body_b_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_digsar body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_digsig body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dignep body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_digped body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_digket body_f_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_dotbon body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dotket body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dotcas body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dotsar body_b_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_ketlud body_r_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketdul body_r_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketnep body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketbec body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketped body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketdig body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketbon body_g_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketmit body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_ketsar body_a_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_zapdax body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_zapven body_l_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_zapmit body_l_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_zapdig body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_zapbon body_a_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_lamnep body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_lamped body_a_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_mitbon body_j_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitsar body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitnep body_k_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitbar body_p_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitdot body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitdig body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitped body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitket body_f_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitsig body_q_wide    { $$ = _ycell($1, $2); }

  /** Wide - bodies.
  **/
    body_a_wide: si_lep g wide g si_pel
      { $$ = $3; }
    body_b_wide: si_lep g wide w wide g si_pel
      { $$ = _ycell($3, $5); }
    body_c_wide: si_lep g wide w wide w wide g si_pel
      { $$ = _ytrel($3, $5, $7); }
    body_d_wide: si_lep g bank_wide g si_pel
      { $$ = $3; }
    body_e_wide: si_lep g menu_wide si_pel
      { $$ = $3; }
    body_f_wide: si_lep g wide w wide w wide w wide g si_pel
      { $$ = _yqual($3, $5, $7, $9); }
    body_g_wide: si_lep g term w wide g si_pel
      { $$ = _ycell($3, $5); }
    body_h_wide: si_lep g wide w rack_wide si_pel
      { $$ = _ycell($3, $5); }
    body_i_wide: si_lep g wide w bank_wide g si_pel
      { $$ = _ycell($3, $5); }
    body_j_wide: si_lep g rope w rack_wide si_pel
      { $$ = _ycell($3, $5); }
    body_k_wide: si_lep g wide w wide g si_pel
      { $$ = _ytrel($3, $5, u2_nul); }
    body_l_wide:
      { $$ = u2_nul; }
    body_o_wide: si_lep g wide g si_pel
      { $$ = $3; }
    body_p_wide: si_lep g rope w wide w rack_wide si_pel
      { $$ = _ytrel($3, $5, $7); }
    body_q_wide: si_lep g rope w wide w wide si_pel
      { $$ = _ytrel($3, $5, $7); }
    body_r_wide: si_lep g hint w wide g si_pel
      { $$ = _ycell($3, $5); }


    bank_wide
      : wide             { $$ = _ycell($1, _0); }
      | wide w bank_wide { $$ = _ycell($1, $3); }
      ;

    pair_wide
      : wide w wide      { $$ = _ycell($1, $3); }
      ;

    dish_wide
      : term w wide      { $$ = _ycell($1, $3); }
      ;

    rack_wide
      : g                             { $$ = _0; }
      | pair_wide g                   { $$ = _ycell($1, _0); }
      | pair_wide ',' g rack_wide     { $$ = _ycell($1, $4); }
      ;

    menu_wide
      : dish_wide g                   { $$ = _ycell($1, _0); }
      | dish_wide ',' g menu_wide     { $$ = _ycell($1, $4); }
      ;
tall
  : tall_norm

  /** Tall - normals.
  **/
    tall_norm: di_casdig w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_casdot w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_casdul w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_caslud w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_caspam w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_casbar w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_cassig w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_caszap w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_casbon w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_casnep w body_h_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_cassar w body_i_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_bonped w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bonnep w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bonlud w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bondul w body_b_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_barnep w body_o_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barbon w body_o_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bardul w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barlud w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bardig w body_o_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barsar w body_e_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barmit w body_e_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barcas w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barsig w body_i_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_digsar w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_digsig w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dignep w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_digped w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_digket w body_f_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_dotbon w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dotket w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dotcas w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dotsar w body_b_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_ketlud w body_r_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketdul w body_r_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketnep w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketbec w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketped w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketdig w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketbon w body_g_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketmit w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_ketsar w body_a_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_zapdax w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_zapdig w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_zapbon w body_a_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_lamnep w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_lamped w body_a_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_mitbon w body_j_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitsar w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitnep w body_k_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitbar w body_p_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitdot w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitdig w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitped w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitket w body_f_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitsig w body_q_tall    { $$ = _ycell($1, $3); }

  /** Tall - bodies.
  **/
    body_a_tall: gene                       { $$ = $1; }
    body_b_tall: gene w gene                { $$ = _ycell($1, $3); }
    body_c_tall: gene w gene w gene         { $$ = _ytrel($1, $3, $5); }
    body_d_tall: bank_tall                  { $$ = $1; }
    body_e_tall: menu_tall                  { $$ = $1; }
    body_f_tall: gene w gene w gene w gene  { $$ = _yqual($1, $3, $5, $7); }
    body_g_tall: term w gene                { $$ = _ycell($1, $3); }
    body_h_tall: gene w rack_tall           { $$ = _ycell($1, $3); }
    body_i_tall: gene w bank_tall           { $$ = _ycell($1, $3); }
    body_j_tall: rope w rack_tall           { $$ = _ycell($1, $3); }
    body_k_tall: gene w gene                { $$ = _ytrel($1, $3, u2_nul); }
    body_o_tall: gene                       { $$ = $1; }
    body_p_tall: rope w gene w rack_tall    { $$ = _ytrel($1, $3, $5); }
    body_q_tall: rope w gene w gene         { $$ = _ytrel($1, $3, $5); }
    body_r_tall: hont w gene                { $$ = _ycell($1, $3); }

  /** Tall - body parts.
  **/
    bank_tall
      : tall_star f                     { $$ = $1; }
      ;
      tall_star
        :                               { $$ = _0; }
        | gene w tall_star              { $$ = _ycell($1, $3); }
        ;

    rack_tall
      : tall_tall_star f                { $$ = $1; }
      ;
      tall_tall_star
        :                               { $$ = _0; }
        | gene w gene w tall_tall_star  { $$ = _ycell(_ycell($1, $3), $5); }
        ;

    menu_tall
      : term_tall_star e                { $$ = $1; }
      ;
      term_tall_star
        :                               { $$ = _0; }
        | term w gene w term_tall_star  { $$ = _ycell(_ycell($1, $3), $5); }
        ;
  

  /** Rope: reference path.
  **/
    rope
      : cord                    { $$ = _ycell($1, _0); }
      | cord si_dot g rope      { $$ = _ycell($1, $4); }
      | becs                    { $$ = $1; }
      | becs si_dot g rope      { $$ = u2_fj_list_cat(yqw_r, $1, $4); }
      ;

      becs
        : si_bec                { $$ = _ycell(_0, _0); }
        | si_bec becs           
          { $$ = _ytrel(_0, 
                        _ycell(_0, _2),
                        $2); }
        ;
      cord
        : axis                  { $$ = _ycell(_0, $1); }
        | tok_term              { $$ = $1; }
        ;

      axis
        : si_dot                { $$ = _1; }
        | si_dot tok_delm       { $$ = $2; }
        | axis_beto             { $$ = $1; }
        ;
        axis_beto
          : si_nep              { $$ = _2; }
          | si_ped              { $$ = _3; }
          | si_nep axis_galu    { $$ = u2_fj_op_peg(yqw_r, _2, $2); }
          | si_ped axis_galu    { $$ = u2_fj_op_peg(yqw_r, _3, $2); }
          ;
        axis_galu
          : si_dul              { $$ = _2; }
          | si_lud              { $$ = _3; }
          | si_dul axis_beto    { $$ = u2_fj_op_peg(yqw_r, _2, $2); }
          | si_lud axis_beto    { $$ = u2_fj_op_peg(yqw_r, _3, $2); }
          ;

  /** Digraphs (with stem)
  **/
    di_casdig: si_cas si_dig  { $$ = c3__csdg; }
    di_casdot: si_cas si_dot  { $$ = c3__csdt; }
    di_caslud: si_cas si_lud  { $$ = c3__csld; }
    di_casdul: si_cas si_dul  { $$ = c3__csdl; }
    di_caspam: si_cas si_pam  { $$ = c3__cspm; }
    di_casbar: si_cas si_bar  { $$ = c3__csbr; }
    di_cassig: si_cas si_sig  { $$ = c3__cssg; }
    di_caszap: si_cas si_zap  { $$ = c3__cszp; }
    di_casbon: si_cas si_bon  { $$ = c3__csbn; }
    di_casnep: si_cas si_nep  { $$ = c3__csnp; }
    di_cassar: si_cas si_sar  { $$ = c3__cssr; }

    di_barbon: si_bar si_bon  { $$ = c3__brbn; }
    di_bardul: si_bar si_dul  { $$ = c3__brdl; }
    di_bardig: si_bar si_dig  { $$ = c3__brdg; }
    di_barcas: si_bar si_cas  { $$ = c3__brcs; }
    di_barmit: si_bar si_mit  { $$ = c3__brmt; }
    di_barnep: si_bar si_nep  { $$ = c3__brnp; }
    di_barsar: si_bar si_sar  { $$ = c3__brsr; }
    di_barsig: si_bar si_sig  { $$ = c3__brsg; }
    di_barlud: si_bar si_lud  { $$ = c3__brld; }

    di_bondul: si_bon si_dul  { $$ = c3__bndl; }
    di_bonlud: si_bon si_lud  { $$ = c3__bnld; }
    di_bonped: si_bon si_ped  { $$ = c3__bnpd; }
    di_bonnep: si_bon si_nep  { $$ = c3__bnnp; }
 
    di_digsar: si_dig si_sar  { $$ = c3__dgsr; }
    di_digsig: si_dig si_sig  { $$ = c3__dgsg; }
    di_dignep: si_dig si_nep  { $$ = c3__dgnp; }
    di_digped: si_dig si_ped  { $$ = c3__dgpd; }
    di_digket: si_dig si_ket  { $$ = c3__dgkt; }

    di_dotbon: si_dot si_bon  { $$ = c3__dtbn; }
    di_dotket: si_dot si_ket  { $$ = c3__dtkt; }
    di_dotcas: si_dot si_cas  { $$ = c3__dtcs; }
    di_dotsar: si_dot si_sar  { $$ = c3__dtsr; }
    
    di_ketlud: si_ket si_lud  { $$ = c3__ktld; }
    di_ketdul: si_ket si_dul  { $$ = c3__ktdl; }
    di_ketnep: si_ket si_nep  { $$ = c3__ktnp; }
    di_ketbec: si_ket si_bec  { $$ = c3__ktbc; }
    di_ketdig: si_ket si_dig  { $$ = c3__ktpd; }
    di_ketped: si_ket si_ped  { $$ = c3__ktdg; }
    di_ketbon: si_ket si_bon  { $$ = c3__ktbn; }
    di_ketmit: si_ket si_mit  { $$ = c3__ktmt; }
    di_ketsar: si_ket si_sar  { $$ = c3__ktsr; }

    di_zapdax: si_zap si_dax  { $$ = c3__zpdx; }
    di_zapmit: si_zap si_mit  { $$ = c3__zpmt; }
    di_zapven: si_zap si_zap  { $$ = c3__zpzp; }
    di_zapdig: si_zap si_dig  { $$ = c3__zpdg; }
    di_zapbon: si_zap si_bon  { $$ = c3__zpbn; }
    
    di_lamnep: si_lam si_nep  { $$ = c3__tmnp; }
    di_lamped: si_lam si_ped  { $$ = c3__tmpd; }
    
    di_mitbon: si_mit si_bon  { $$ = c3__mtbn; }
    di_mitsar: si_mit si_sar  { $$ = c3__mtsr; }
    di_mitbar: si_mit si_bar  { $$ = c3__mtbr; }
    di_mitsig: si_mit si_sig  { $$ = c3__mtsg; }
    di_mitnep: si_mit si_nep  { $$ = c3__mtnp; }
    di_mitdig: si_mit si_dig  { $$ = c3__mtdg; }
    di_mitdot: si_mit si_dot  { $$ = c3__mtdt; }
    di_mitped: si_mit si_ped  { $$ = c3__mtpd; }
    di_mitket: si_mit si_ket  { $$ = c3__mtkt; }

  /* Signs.
  */
    si_pam: '&'
    si_cas: '?'
    si_bar: '|'
    si_bon: '='
    si_bec: '$'
    si_bot: '\''
    si_cab: '_'
    /* si_cam: ',' */
    si_dax: '#'
    si_dig: ':'
    si_dul: '<'
    si_dot: '.'
    si_des: '}'
    si_ket: '^'
    si_zap: '!'
    si_lam: ';'
    si_lep: '('
    si_mit: '%'
    si_mon: ']'
    si_nom: '['
    si_nep: '-'
    si_fat: '@'
    si_pel: ')'
    si_ped: '+'
    si_sar: '*'
    si_sac: '\\'
    si_sol: '/'
    si_sed: '{'
    si_sig: '~'
    si_tic: '`'
    /* si_toq: '"' */
    si_lud: '>'

  /** Basic tokens.
  **/
    term
      : tok_term
      | si_bec    { $$ = _0; }
      ;

    tok_term
      : tok_term_pre
      | tok_term_pre tok_term_load
        { $$ = u2_bn_tape(yqw_r, _ycell($1, $2)); }
      ;
        tok_term_pre
          : ca

        tok_term_load
          : ca { $$ = _ycell($1, _0); }
                 | cd { $$ = _ycell($1, _0); }
                 | '-' { $$ = _ycell($1, _0); }
                 | ca tok_term_load  { $$ = _ycell($1, $2); }
                 | cd tok_term_load  { $$ = _ycell($1, $2); }
                 | '-' tok_term_load { $$ = _ycell($1, $2); }
                 ;

    tok_chex 
      : '0' 
        { $$ = _0; }
      | tok_chex_pre tok_chex_load
        { $$ = u2_bn_heximal(yqw_r, _ycell($1, $2)); }
      ;
        tok_chex_pre
          : cn | ch
          ;

        tok_chex_load
          : { $$ = _0; }
                    | cd gap tok_chex_load { $$ = _ycell($1, $3); }
                    | ch gap tok_chex_load { $$ = _ycell($1, $3); }
                    ;


    tok_delm
      : '0' { $$ = _0; }
      | tok_delm_pre tok_delm_load
        { $$ = u2_bn_decimal(yqw_r, _ycell($1, $2)); }
      ;
        tok_delm_pre: cn;
        tok_delm_load: { $$ = _0; }
                    | cd tok_delm_load { $$ = _ycell($1, $2); }
                    ;

    tok_loct
      : si_bot loct_mid si_bot
        { $$ = u2_bn_tape(yqw_r, $2); }
      ;
        loct_mid: { $$ = _0; }
                 | cq loct_mid { $$ = _ycell($1, $2); }
                 ;


  /** Whitespace.
  **/
    gap
      : si_sac g si_sol  { $$ = _0; }
      |                  { $$ = _0; }
      ;

    g:            { $$ = _0; }
     | cw g       { $$ = _0; }
     | comment g  { $$ = _0; }
     ;

    w: cw         { $$ = _0; }
     | comment    { $$ = _0; }
     | cw w       { $$ = _0; }
     | comment w  { $$ = _0; }
     ;

    e: '=' '='
        ;

    f: '-' '-'
        ;

    comment: ':' ':' comment_body '\n' { $$ = _0; }
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
static u2_noun
_watt_locate(u2_ray  wir_r,
             const void *vlocp,
             u2_noun gene)
{
  const YYLTYPE *llocp = vlocp;   /* bufalo estupido */

#if 0
  return gene;
#endif
#if 1
  return u2_bt
  (wir_r,
   c3__zpcb,
   u2_bt
    (wir_r, 
     u2_nul,
     u2_bc
      (wir_r, 
       (llocp->first_line), 
       (llocp->first_column)),
     u2_bc
      (wir_r,
       (llocp->last_line), 
       (llocp->last_column))),
    gene);
#endif

#if 0
  return u2_bt
    (wir_r, 
     c3__ktld,
     u2_bq
      (wir_r,
       c3__spot,
       c3__dtsg, 
       u2_nul,
     gene);
#endif
}

/* Initialize (scanner) for (sack).
*/
static void
_scanner_init(struct _u2_scanner *scanner,
              u2_ray  wir_r,
              u2_noun sack)
{
  scanner->wir_r = wir_r;
  scanner->scan = u2_none;

  if ( u2_yes == u2_stud(sack) ) {
    scanner->p.tube = sack;
    scanner->p.bowl = _0;
  }
  else {
    scanner->p.tube = u2_h(sack);
    scanner->p.bowl = u2_t(sack);
  }

  scanner->s.token = 0;
  scanner->s.pb = 0;
  scanner->s.xw_line = 1;
  scanner->s.xw_col = 1;
}


/* functions
*/
  u2_weak                                                         //  transfer
  j2_mbc(Pit, ream)(u2_wire wir_r, 
                    u2_weak txt)                                  //  transfer
  {
    if ( u2_none == txt ) {
      return u2_none;
    }
    else {
      struct _u2_scanner scanner;

      _scanner_init(&scanner, wir_r, txt);

      if ( !yqparse(&scanner) ) {
        c3_assert(scanner.scan);

        return scanner.scan;
      }
      else {
        return u2_bl_bail(wir_r);
      }
    }
  }
  u2_weak                                                         //  transfer
  j2_mb(Pit, ream)(u2_wire wir_r, 
                   u2_noun cor)                                   //  retain
  {
    u2_noun txt;

    if ( u2_none == (txt = u2_frag(4, cor)) ) {
      return u2_none;
    } else {
      return j2_mbc(Pit, ream)(wir_r, txt);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, ream)[] = { 
    { ".3", c3__lite, j2_mb(Pit, ream), u2_yes, u2_none, u2_none },
    { }
  };

/* Trivial scanner.
*/
int 
yqlex(YYSTYPE *lvalp, YYLTYPE *llocp, struct _u2_scanner *scanner)
{
  if ( scanner->s.token ) {
    int token = scanner->s.token;

    scanner->s.token = 0;
    return token;
  }
  else {
    c3_y xb = u2_byte(scanner->s.pb, scanner->p.tube);

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

    *lvalp = xb;
    return xb;
  }
}  

/* Error printer.
*/
int yqerror(YYLTYPE *locp, struct _u2_scanner *scanner, char const *msg)
{
  printf("%s: (%d:%d - %d:%d)\n", 
    msg, locp->first_line, locp->first_column,
         locp->last_line, locp->last_column);
}
