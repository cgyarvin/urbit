/* include/dash.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* u2_chop: identification in objective battery declaration.
    **
    **  |?
    **    lef=*term
    **    [std=*term kel=@]
    **    [ven=*term pro=*term kel=@]
    **    [ven=*term pro=*term ver=@ kel=@]
    **  ==
    */
      typedef u2_noun u2_chop;

    /* u2_clue: programmer's declaration hint
    **
    **  [bud=*tool sil=*chop nut=*(list &[p=*term q=*tool])]
    */
      typedef u2_noun u2_clue;

    /* u2_chip: complete battery record (XX: list should be map)
    **
    **  :*  dac=[sil=*chop nut=*(list <[p=*term q=*tool]>)]
    **      bat=*
    **      pet=<~ [axe=*axis led=*chip]>
    **  --
    */
      typedef u2_noun u2_chip;

  /** Functions.
  **/
    /* u2_ds_init(): 
    **
    **   Initialize dash, with parent if any.
    */
      void
      u2_ds_init(u2_wire wir_r);
 
    /* u2_ds_find(): find chip by core, or none.  Includes validate.
    */
      u2_weak                                                     //  senior
      u2_ds_find(u2_wire wir_r,
                 u2_noun cor);                                    //  retain

    /* u2_ds_mine(): 
    **
    **   Register and/or replace core.
    */
      u2_noun                                                     //  transfer
      u2_ds_mine(u2_wire wir_r,
                 u2_noun clu,                                     //  retain
                 u2_noun cor);                                    //  transfer

    /* u2_ds_cook():
    **
    **   Produce hook formula from chip, or u2_none.
    */
      u2_weak                                                     //  senior
      u2_ds_cook(u2_wire     wir_r,
                 u2_noun     xip,                                 //  retain
                 const c3_c* tam_c);                              //  retain

    /* u2_ds_look():
    **
    **   Produce hook formula from core, or u2_none.
    */
      u2_weak                                                     //  senior
      u2_ds_look(u2_wire     wir_r,
                 u2_noun     cor,                                 //  retain
                 const c3_c* tam_c);                              //  retain
