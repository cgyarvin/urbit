/* include/v/vere.h
**
** This file is in the public domain.
*/
  /** Quasi-tunable parameters.
  **/
    /* First kernel this executable can boot.
    */
#     define FirstKernel   224
#     define DefaultKernel 224

  /** Data types.
  **/
    /* u2_steg: kernel stage.
    */
      typedef struct {
        c3_m    mod_m;                      //  stage mode, or 0 for none
        u2_noun ken;                        //  stable kernel, or 0 for none
        u2_noun ras;                        //  transition kernel, or 0
        u2_noun tip;                        //  broken sub-kernel, or 0
        u2_noun tul;                        //  toolkit map - [term vase]
        struct {
          u2_noun seed;                     //  kernel vase
          u2_noun what;                     //  platform vase
          u2_noun ream;                     //  text to gene 
          u2_noun slam;                     //  nock vase call - [vase vase]
          u2_noun slap;                     //  nock vase pipe - [vase gene]
          u2_noun slop;                     //  nock vase pair - [vase vase]
        } toy;
        struct {
          u2_noun old;                      //  legacy app
        } dev;
      } u2_steg;

    /* u2_host: entire host.
    */
      typedef struct {
        u2_wire wir_r;                      //  noun system, 1 per thread
        c3_c*   fel_c;                      //  readline filename
        u2_noun pet;                        //  petname of self, atomic
        u2_noun pat;                        //  unix path to self, atomic
        u2_noun opt;                        //  unix arguments as map
        u2_steg ver_e[257];                 //  stages improving downward
        c3_w    kno_w;                      //  current executing stage
      } u2_host;                            //  host == computer == process

  /** Global variables.
  **/
    c3_global  u2_host  u2_Host;
    c3_global  u2_wire  u2_Wire;
    c3_global  c3_c*    u2_Local;
    c3_global  c3_c*    u2_System;
    c3_global  u2_flag  u2_Quiet;
    c3_global  u2_flag  u2_Debug;

#   define u2_ve_at() ( &u2_Host.ver_e[u2_Host.kno_w] )


  /** Functions.
  **/
    /**  Filesystem.
    **/
      /* u2_ve_file(): load internal file as atom from local or system.
      */
        u2_weak
        u2_ve_file(c3_c* ext_c, u2_noun tah);

      /* u2_ve_date(): date internal file.
      */
        c3_d
        u2_ve_date(c3_c* ext_c, u2_noun tah);

      /* u2_ve_save(): save internal file as atom.
      */
        void
        u2_ve_save(c3_c* ext_c, u2_noun tah, u2_noun dat);


    /**  Execution system.
    **/
      /* u2_ve_tag: simple string from stage number.
      */
        u2_noun
        u2_ve_tag(c3_w a_w);

      /* u2_ve_bone(): direct execution from kernel, using ":!%".
      */
        u2_noun
        u2_ve_bone(c3_c *bon_c);

      /* u2_ve_seed(): return kernel seed.
      */
        u2_noun
        u2_ve_seed();

      /* u2_ve_slap(): use slap gate. 
      */
        u2_noun
        u2_ve_slap(u2_noun vax, u2_noun gen);

      /* u2_ve_slam(): use slam gate. 
      */
        u2_noun
        u2_ve_slam(u2_noun gat, u2_noun sam);

      /* u2_ve_slop(): use slop gate. 
      */
        u2_noun
        u2_ve_slop(u2_noun hed, u2_noun tal);

      /* u2_ve_ream(): use ream gate.
      */
        u2_noun
        u2_ve_ream(u2_noun txt);

      /* u2_ve_slac(): slap with C string
      */
        u2_noun
        u2_ve_slac(u2_noun vax, const c3_c* sam_c);

      /* u2_ve_use(): use specified tool.
      */
        u2_noun 
        u2_ve_use(const c3_c* wit_c);

      /* u2_ve_hard(): use standard tool gate without type check.
      */
        u2_noun
        u2_ve_hard(const c3_c* wit_c, c3_c* fun_c, u2_noun arg);

      /* u2_ve_soft(): use standard tool gate against vase.
      */
        u2_noun
        u2_ve_soft(const c3_c* wit_c, c3_c* fun_c, u2_noun vos);

      /* u2_ve_meat(): return noun of vase.
      */
        u2_noun 
        u2_ve_meat(u2_noun vos);


    /**  Boot logic.
    **/
      /* u2_ve_grab(): garbage-collect the world, plus roots.
      */
        void
        u2_ve_grab(u2_noun som, ...);

      /* u2_ve_gunn(): produce a gunn, of any vintage.
      */
        u2_noun
        u2_ve_gunn();

      /* u2_ve_init(): boot the kernel at `kno`.
      */
        void
        u2_ve_init(c3_w kno_w);


    /**  Console and command line.  
    **/
      /* u2_ve_dump_columns(): return screen column width from OS.
      */
        c3_l
        u2_ve_dump_columns(void);

      /* u2_ve_dump_tape(): print a tape of text.
      */
        void
        u2_ve_dump_tape(u2_noun tep);

      /* u2_ve_dump_wall(): print a wall of text.
      */
        void
        u2_ve_dump_wall(u2_noun wol);

      /* u2_ve_sway(): print trace stack.
      */
        void
        u2_ve_sway(c3_l tab_l, u2_noun tax);

      /* u2_ve_wine(): analyze and express error result.
      */
        void
        u2_ve_wine(u2_noun how);

      /* u2_ve_line(): execute a command line, fully protected.
      */
        void
        u2_ve_line(c3_c* lin_c);
