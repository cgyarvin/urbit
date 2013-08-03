/* include/v/arvo.h
**
** This file is in the public domain.
*/
  /**   Data structures.
  **/
    /* u2_cart: ovum carton.
    */
      struct _u2_reck;

      typedef struct _u2_cart {
        u2_noun egg;                      //  ovum itself
        void (*clr_f)                     //  ovum processing failed
            (struct _u2_reck *rec_u,      //  system
             u2_noun,                     //  egg itself
             u2_noun,                     //  failure mode
             u2_noun);                    //  trace if any
        struct _u2_cart* nex_u;           //  next in queue
      } u2_cart;

    /* u2_reck: modern arvo structure.
    */
      typedef struct _u2_reck {
        c3_w    kno_w;                    //  kernel stage
        c3_w    rno_w;                    //  rotor index (always 0)
        c3_w    ent_w;                    //  event counter XX 64

        struct {
          struct _u2_cart* egg_u;         //  exit of ovum queue
          struct _u2_cart* geg_u;         //  entry of ovum queue
        } ova;

        struct {                          //  function gates, use mung
          u2_noun cyst;                   //  compare resource trees
          u2_noun lump;                   //  patch
          u2_noun rain;                   //  parse path, text -> gene
          u2_noun ream;                   //  parse text -> gene
          u2_noun slam;                   //  call ([vase vase] -> vase)
          u2_noun sham;                   //  SHA-256 on noun
          u2_noun shed;                   //  ghetto decrypt
          u2_noun shen;                   //  ghetto encrypt
          u2_noun slap;                   //  layer ([vase gene] -> vase)
          u2_noun slop;                   //  cell ([vase vase] -> vase)
          u2_noun slay;                   //  text to coin
          u2_noun slaw;                   //  text to format
          u2_noun scot;                   //  dime to text
          u2_noun spat;                   //  path to text
          u2_noun stab;                   //  text to path
          u2_noun turf;                   //  utf8 to utf32
          u2_noun tuft;                   //  utf32 to utf8
          u2_noun mook;                   //  trace conversion
          u2_noun hoof;                   //  kno to text 
          u2_noun wash;                   //  tank window printer
        } toy;

        u2_noun now;                      //  current time, as noun
        u2_noun wen;                      //  current time, as text
        u2_noun sev_l;                    //  instance number
        u2_noun sen;                      //  instance string
        u2_noun own;                      //  owner list

        u2_noun our;                      //  main owner
        u2_noun pod;                      //  owner as text
        u2_noun roe;                      //  temporary unsaved events
        u2_noun key;                      //  log key, or 0

        u2_noun ken;                      //  kernel formula (for now)
        //  u2_noun syd;                      //  kernel seed 
        u2_noun roc;                      //  rotor core
      } u2_reck;

  /**   Global variables.
  **/
#define  u2_Arv  ((u2_reck*)u2_at_cord(u2_wire_arv_r(u2_Wire), sizeof(u2_reck)))
