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
  /* With the mighty power of GLR... 
  */
  %glr-parser
  %name-prefix="yq"

  /* We laugh at your petty shift-reduce conflicts.
  */
  %expect 58

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
    { $$ = _ytrel(c3__bndv, $1, $3); }
  ;

wide_a
  : wide_c
  | tok_term si_ben wide
    { $$ = _ytrel(c3__htbn, $1, $3); }
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
      | si_amp
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
      : si_ask
        { $$ = _ycell(c3__lmbn, c3__flag); }
      | si_ras
        { $$ = _ycell(c3__lmbn, c3__blur); }
      | si_hat
        { $$ = _ycell(c3__lmbn, c3__cell); }
      | si_pat
        { $$ = _ycell(c3__lmbn, c3__atom); }
      | si_sig
        { $$ = _ycell(c3__lmbn, c3__null); }
      ;
   
    wide_rope
      : rope            
        { $$ = _ytrel(c3__mtbn, $1, _0); }
      ;
    wide_cage
      : si_nom g bank_wide g si_mon 
        { $$ = _ycell(c3__dgrs, $3); }
      ; 

    wide_pick
      : si_dev g bank_wide g si_ved
        { $$ = _ycell(c3__brsk, $3); } 
      ;

    wide_call
      : si_lep g bank_wide g si_pel
        { $$ = _ycell(c3__mtnb, $3); }
      ;

    wide_mtsg
      : si_sig si_lep rope w gene w bank_wide si_pel
        { $$ = _yqual(c3__mtsg, $3, $5, _ycell(c3__dgrs, $7)); }
 
  /** Wide: funky stuff.
  **/
    wide_funk
      : si_sud g bank_wide g si_dus
        { $$ = _ycell(c3__dgsg, $3); }
      | si_sud g si_dus
        { $$ = _ycell(c3__dgsg, _0); }
      | rope si_lep rack_wide si_pel
        { $$ = _ytrel(c3__mtbn, $1, $3); }
      | si_hop wide
        { $$ = _ycell(c3__skhp, $2); }
      | si_amp wide
        { $$ = _ycell(c3__lmnb, $2); }
      | si_ras wide
        { $$ = _ycell(c3__mtrs, $2); }
      | si_cab wide
        { $$ = _ycell(c3__lmpd, $2); }
      | si_tic wide si_tic wide
        { $$ = _ytrel(c3__htnb, $2, $4); }
/*
      | si_sol path
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
      | thin si_sol path    { $$ = _ytrel(c3__dgnb, $1, $3); }
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
    wide_norm: di_askdig body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askdot body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askdev body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askved body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askamp body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askbar body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_asksig body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askhop body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askben body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_asknub body_h_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_askras body_i_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_benpod body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bennub body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_benved body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bendev body_b_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_barnub body_o_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barben body_o_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barras body_e_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barmit body_e_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_bardig body_o_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barask body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_barsig body_i_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_digras body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_digsig body_d_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dignub body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_digpod body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dighat body_f_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_dotben body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dothat body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dotask body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_dotras body_b_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_hatved body_r_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatdev body_r_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatnub body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatbuc body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatpod body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatdig body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatben body_g_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatmit body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatras body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hatpat body_a_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_hopdax body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hopven body_l_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hopmit body_l_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hopdig body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_hopben body_a_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_lomnub body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_lompod body_a_wide    { $$ = _ycell($1, $2); }

    wide_norm: di_mitben body_j_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitras body_a_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitnub body_k_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitbar body_p_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitdot body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitdig body_b_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mitpod body_c_wide    { $$ = _ycell($1, $2); }
    wide_norm: di_mithat body_f_wide    { $$ = _ycell($1, $2); }
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
    tall_norm: di_askdig w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askdot w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askdev w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askved w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askamp w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askbar w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_asksig w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askhop w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askben w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_asknub w body_h_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_askras w body_i_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_benpod w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bennub w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_benved w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bendev w body_b_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_barnub w body_o_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barben w body_o_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_bardig w body_o_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barras w body_e_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barmit w body_e_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barask w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_barsig w body_i_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_digras w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_digsig w body_d_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dignub w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_digpod w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dighat w body_f_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_dotben w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dothat w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dotask w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_dotras w body_b_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_hatved w body_r_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatdev w body_r_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatnub w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatbuc w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatpod w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatdig w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatben w body_g_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatmit w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatras w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hatpat w body_a_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_hopdax w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hopdig w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_hopben w body_a_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_lomnub w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_lompod w body_a_tall    { $$ = _ycell($1, $3); }

    tall_norm: di_mitben w body_j_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitras w body_a_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitnub w body_k_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitbar w body_p_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitdot w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitdig w body_b_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mitpod w body_c_tall    { $$ = _ycell($1, $3); }
    tall_norm: di_mithat w body_f_tall    { $$ = _ycell($1, $3); }
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
      : tall_star e                     { $$ = $1; }
      ;
      tall_star
        :                               { $$ = _0; }
        | gene w tall_star              { $$ = _ycell($1, $3); }
        ;

    rack_tall
      : tall_tall_star e                { $$ = $1; }
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
      | bucs                    { $$ = $1; }
      | bucs si_dot g rope      { $$ = u2_fj_list_cat(yqw_r, $1, $4); }
      ;

      bucs
        : si_buc                { $$ = _ycell(_0, _0); }
        | si_buc bucs           
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
          : si_nub              { $$ = _2; }
          | si_pod              { $$ = _3; }
          | si_nub axis_galu    { $$ = u2_fj_op_peg(yqw_r, _2, $2); }
          | si_pod axis_galu    { $$ = u2_fj_op_peg(yqw_r, _3, $2); }
          ;
        axis_galu
          : si_dev              { $$ = _2; }
          | si_ved              { $$ = _3; }
          | si_dev axis_beto    { $$ = u2_fj_op_peg(yqw_r, _2, $2); }
          | si_ved axis_beto    { $$ = u2_fj_op_peg(yqw_r, _3, $2); }
          ;

  /** Digraphs (with stem)
  **/
    di_askdig: si_ask si_dig  { $$ = c3__skdg; }
    di_askdot: si_ask si_dot  { $$ = c3__skdt; }
    di_askved: si_ask si_ved  { $$ = c3__skvd; }
    di_askdev: si_ask si_dev  { $$ = c3__skdv; }
    di_askamp: si_ask si_amp  { $$ = c3__skmp; }
    di_askbar: si_ask si_bar  { $$ = c3__skbr; }
    di_asksig: si_ask si_sig  { $$ = c3__sksg; }
    di_askhop: si_ask si_hop  { $$ = c3__skhp; }
    di_askben: si_ask si_ben  { $$ = c3__skbn; }
    di_asknub: si_ask si_nub  { $$ = c3__sknb; }
    di_askras: si_ask si_ras  { $$ = c3__skrs; }

    di_barnub: si_bar si_nub  { $$ = c3__brnb; }
    di_barben: si_bar si_ben  { $$ = c3__brbn; }
    di_barras: si_bar si_ras  { $$ = c3__brrs; }
    di_barmit: si_bar si_mit  { $$ = c3__brmt; }
    di_bardig: si_bar si_dig  { $$ = c3__brdg; }
    di_barask: si_bar si_ask  { $$ = c3__brsk; }
    di_barsig: si_bar si_sig  { $$ = c3__brsg; }

    di_bendev: si_ben si_dev  { $$ = c3__bndv; }
    di_benved: si_ben si_ved  { $$ = c3__bnvd; }
    di_benpod: si_ben si_pod  { $$ = c3__bnpd; }
    di_bennub: si_ben si_nub  { $$ = c3__bnnb; }
 
    di_digras: si_dig si_ras  { $$ = c3__dgrs; }
    di_digsig: si_dig si_sig  { $$ = c3__dgsg; }
    di_dignub: si_dig si_nub  { $$ = c3__dgnb; }
    di_digpod: si_dig si_pod  { $$ = c3__dgpd; }
    di_dighat: si_dig si_hat  { $$ = c3__dght; }

    di_dotben: si_dot si_ben  { $$ = c3__dtbn; }
    di_dothat: si_dot si_hat  { $$ = c3__dtht; }
    di_dotask: si_dot si_ask  { $$ = c3__dtsk; }
    di_dotras: si_dot si_ras  { $$ = c3__dtrs; }
    
    di_hatved: si_hat si_ved  { $$ = c3__htvd; }
    di_hatdev: si_hat si_dev  { $$ = c3__htdv; }
    di_hatnub: si_hat si_nub  { $$ = c3__htnb; }
    di_hatbuc: si_hat si_buc  { $$ = c3__htbc; }
    di_hatdig: si_hat si_dig  { $$ = c3__htpd; }
    di_hatpod: si_hat si_pod  { $$ = c3__htdg; }
    di_hatben: si_hat si_ben  { $$ = c3__htbn; }
    di_hatmit: si_hat si_mit  { $$ = c3__htmt; }
    di_hatras: si_hat si_ras  { $$ = c3__htrs; }
    di_hatpat: si_hat si_pat  { $$ = c3__htpt; }

    di_hopdax: si_hop si_dax  { $$ = c3__hpdx; }
    di_hopmit: si_hop si_mit  { $$ = c3__hpmt; }
    di_hopven: si_hop si_hop  { $$ = c3__hphp; }
    di_hopdig: si_hop si_dig  { $$ = c3__hpdg; }
    di_hopben: si_hop si_ben  { $$ = c3__hpbn; }
    
    di_lomnub: si_lom si_nub  { $$ = c3__lmnb; }
    di_lompod: si_lom si_pod  { $$ = c3__lmpd; }
    
    di_mitben: si_mit si_ben  { $$ = c3__mtbn; }
    di_mitras: si_mit si_ras  { $$ = c3__mtrs; }
    di_mitbar: si_mit si_bar  { $$ = c3__mtbr; }
    di_mitsig: si_mit si_sig  { $$ = c3__mtsg; }
    di_mitnub: si_mit si_nub  { $$ = c3__mtnb; }
    di_mitdig: si_mit si_dig  { $$ = c3__mtdg; }
    di_mitdot: si_mit si_dot  { $$ = c3__mtdt; }
    di_mitpod: si_mit si_pod  { $$ = c3__mtpd; }
    di_mithat: si_mit si_hat  { $$ = c3__mtht; }

  /* Signs.
  */
    si_amp: '&'
    si_ask: '?'
    si_bar: '|'
    si_ben: '='
    si_buc: '$'
    si_bot: '\''
    si_cab: '_'
    /* si_com: ',' */
    si_dax: '#'
    si_dig: ':'
    si_dev: '<'
    si_dot: '.'
    si_dus: '}'
    si_hat: '^'
    si_hop: '!'
    si_lom: ';'
    si_lep: '('
    si_mit: '%'
    si_mon: ']'
    si_nom: '['
    si_nub: '-'
    si_pat: '@'
    si_pel: ')'
    si_pod: '+'
    si_ras: '*'
    si_sac: '\\'
    si_sol: '/'
    si_sud: '{'
    si_sig: '~'
    si_tic: '`'
    /* si_toq: '"' */
    si_ved: '>'

  /** Basic tokens.
  **/
    term
      : tok_term
      | si_buc    { $$ = _0; }
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

#if 1
  return gene;
#else
  return u2_bt
    (wir_r, 
     c3__htvd,
     u2_bq
      (wir_r,
       c3__spot,
       c3__dtsg, 
       u2_nul,
       u2_bc
        (wir_r, 
         u2_bc
          (wir_r, 
           (llocp->first_line), 
           (llocp->first_column)),
         u2_bc
          (wir_r,
           (llocp->last_line), 
           (llocp->last_column)))),
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
