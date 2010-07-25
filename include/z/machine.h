/* include/z/machine.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   u3_z   (zeno machine)
**
**   u3_zl  (zeno internal - loom; nouns and memory)
**   u3_zn  (zeno internal - nock; the nock interpreter)
**   u3_zq  (zeno internal - watt; the built-in kernel)
**   u3_zj  (zeno internal - jato; the optimization layer)
**
** Description:
**
**   zeno: top-level internal interfaces.
*/
  /** Data types.
  **/
    struct u3_z_core;

    /* u3_zj_code:
    **
    **   Jet codes.
    */
      enum u3_zj_code {
#       define _zj_wet(name, source, priority) u3_zj_code_##name,
#       define _zj_dry(name, source, priority) u3_zj_code_##name,
#         include "z/jets.h"
#       undef _zj_wet 
#       undef _zj_dry
        u3_zj_code_none
      };

    /* u3_zj_jet: 
    **
    **   Live jet structure.
    */
      struct u3_zj_jet {
        /* rid  : mung / short hash of bat
        ** con  : static argument
        ** bat  : formula
        ** mug  : short hash of formula
        ** pas  : C function to call - argument, sam (dynamic argument)
        ** w_pri: priority
        ** nex  : next in hash-search sequence
        */
        u3_fox           con;
        u3_fox           bat;
        u3_w             w_mug;
        u3_fox           (*fn_pas)(struct u3_z_core *, u3_fox);
        u3_w             w_pry;
        struct u3_zj_jet *jet_nex;
      };

    /* u3_zj_map:
    **
    **   Live map structure.
    */
      struct u3_zj_map {
        /* rid: hash of key
        ** key: ie, name
        ** toy: ie, value
        ** hin: lower-hashed keys
        ** yon: higher-hashed keys
        */
        u3_fox           rid;
        u3_fox           key; 
        u3_fox           toy;
        struct u3_zj_map *map_hin;
        struct u3_zj_map *map_yon;
      };

    /* u3_z_core, z: 
    **
    **   The zeno core.
    **
    **   Zeno is a layered interpreter.  In general, lower layers do
    **   not call higher layers - exceptions are noted.  Lower layers
    **   never have direct access to the data of higher layers, but
    **   higher layers can both read and write lower-layer data.
    **
    **   From low to high, the layers are:
    **    
    **      loom    nouns and memory management
    **      nock    generic nock interpreter
    **      watt    boot nouns
    **      jato    accelerated execution
    **      sith    tracing and debugging infrastructure
    */
      struct u3_z_core {
        /** Layer: loom.
        **/
          struct u3_l_core l;

        /** Layer: nock.
        ***
        ***   The main interpreter loop is at the nock level,
        ***   but calls jato and debug for obvious reasons.
        **/
          struct {
            /* lab: agenda stack
            */
            u3_ray ray_lab;
          } n;

        /** Layer: watt.  Subject.
        **/
          struct {
            /* tef: subject [type noun]
            */
            u3_fox tef;
          } q;

        /** Layer: jato.  Built-in performance assistance.
        **/
          struct {
            /* lum: exception return
            ** rod: jet array
            ** opt: optimization level (0-15)
            */
            jmp_buf          jmp_lum;
            struct u3_zj_jet *jet_rod;
            u3_w             w_opt;
          } j;
    
        /** Layer: sith.  Tracing and debugging.
        **/
      };
      typedef struct u3_z_core *u3_z;


    /* u3_z_bench: performance statistics.
    */
      struct u3_z_bench {
        /* ruy: step count
        ** cop: copy count
        ** vil: west watermark (start)
        ** tew: east watermark (start) 
        ** maz: west watermark (max)
        ** buc: east watermark (max)
        */
        u3_d d_ruy;
        u3_w w_cop;
        u3_w w_vil, w_tew, w_maz, w_buc;
      };


  /** Functions.
  **/
    /* u3_z_new():
    **
    **   Create a zeno core, mallocing (1 << y_a) words of memory.
    **   Return 0 if malloc fails.  Free with free().
    */
      u3_z
      u3_z_new(u3_y y_a);

    /* u3_z_do():
    **
    **   Execute (nock a b), returning u3_none on failure.
    */
      u3_rat
      u3_z_do(u3_z   z,
              u3_fox a,
              u3_fox b);

    /* u3_z_run():
    **
    **   Execute (nock b c) and set *a to the result.  If this succeeds,
    **   return 0.  Otherwise, return u3_cm_exit or u3_cm_fail.
    **
    **   If z_bench is nonzero, set benchmark data.
    */
      u3_fox
      u3_z_run(u3_z z,
               u3_fox            *a,
               u3_fox            b,
               u3_fox            c,
               struct u3_z_bench *d);
