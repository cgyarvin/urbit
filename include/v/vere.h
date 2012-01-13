/* include/v/vere.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* u2_steg: kernel stage.
    */
      typedef struct {
        c3_m    mod_m;                      //  stage mode, or 0 for none
        u2_noun ken;                        //  stable kernel, or 0 for none
        u2_noun ras;                        //  transition kernel, or 0
        u2_noun tip;                        //  broken sub-kernel, or 0
        u2_noun tax;                        //  error trace, if any
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
