/* include/shed.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* u2_ring: layer in objective battery identification
    **
    **  |?
    **    lef=*term
    **    [std=*term kel=@]
    **    [ven=*term pro=*term kel=@]
    **    [ven=*term pro=*term ver=[maj=@ min=@] kel=@]
    **  ==
    */
      typedef u2_noun u2_ring;

    /* u2_clue: battery declaration
    **
    **  [rig=*ring bud=*tool nut=*(list &[*term *tool]) tup=<~ *type>]
    */
      typedef u2_noun u2_clue;

    /* u2_disc: list of clue - complete battery identification
    */
      typedef u2_noun u2_disc;

    /* u2_lead: live battery record
    **
    **  [dus=*disc pay=* bat=*]
    */
      typedef u2_noun u2_lead;

    /* u2_loom_shed: jet registration hangar.
    */
      typedef struct {
        u2_loom_rail o;

        /* par_r: parent shed.
        */
        u2_ray par_r;

        /* cad_c: hash from battery to lead.
        */
        u2_loom_chad cad_c;
      } u2_loom_shed;

#       define u2_shed_par_r(sad_r)  *u2_at(sad_r, u2_loom_shed, par_r)
#       define u2_shed_cad_r(sad_r)  u2_aftr(sad_r, u2_loom_shed, cad_c)

  /** Functions.
  **/
    /* u2_sh_init(): 
    **
    **   Initialize shed from rail partition, with parent if any.
    */
      u2_ray
      u2_sh_init(u2_ray sad_r,
                 u2_ray par_r);
 
    /* u2_sh_find(): find lead by core, or none.  Includes validate.
    */
      u2_weak
      u2_sh_find(u2_ray  wir_r,
                 u2_noun cor);

    /* u2_sh_mine(): 
    **
    **   Produce replacement core with shed battery, or return u2_none.
    */
      u2_weak
      u2_sh_mine(u2_ray  wir_r,
                 u2_noun hod,
                 u2_noun cor);
