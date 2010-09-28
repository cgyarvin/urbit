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
    **    [can=*term kel=@]
    **    [ven=*term pro=*term kel=@]
    **    [ven=*term pro=*term ver=[maj=@ min=@] kel=@]
    **  ==
    */
      typedef u2_noun u2_ring;

    /* u2_clue: battery declaration
    **
    **  [rig=*ring fin=*axis]
    */
      typedef u2_noun u2_clue;

    /* u2_cuff: objective battery identification
    **
    **  (list ring)
    */
      typedef u2_noun u2_cuff;
  
    /* u2_disc: all objective information
    **
    **  [cuf=*cuff hoc=~]
    */
      typedef u2_noun u2_disc;

    /* u2_bird: live battery record
    **
    **  [doc=*disc bat=*]
    */
      typedef u2_noun u2_bird;

    /* u2_loom_shed: jet registration hangar.
    */
      typedef struct {
        /* zon_r: ray to warm allocation zone.
        */
        u2_ray zon_r;

        /* cad_c: hash from battery to bird.
        */
        u2_loom_chad cad_c;

        /* par_r: parent shed.
        */
      } u2_loom_shed;

#define   u2_shed_zon_r(sud_r)  *u2_at(sud_r, u2_loom_shed, zon_r)
#define   u2_shed_cad_r(sud_r)  u2_aftr(sud_r, u2_loom_shed, cad_c)

  /** Functions.
  **/
    /* u2_sh_open(): 
    **
    **   Install a shed partition of size `(num_w / dem_w)` in `wir_r`.
    **   Return the new shed.
    */
      u2_ray
      u2_sh_open(u2_ray wir_r,
                 c3_w   num_w,
                 c3_w   dem_w);

    /* u2_sh_init(): insert a shed at `cap_r` for `siz_w` before `rut_r`.
    */
      u2_ray
      u2_sh_init(u2_ray cap_r,
                 c3_w   siz_w, 
                 u2_ray rut_r);
                 
    /* u2_sh_find(): find disc by core, or none.  Includes validate.
    */
      u2_weak
      u2_sh_find(u2_ray  sad_r,
                 u2_noun pay,
                 u2_noun bat);

    /* u2_sh_core(): substitute active, annotated battery.
    */
      u2_noun
      u2_sh_save(u2_ray  sad_r,
                 u2_noun hod,
                 u2_noun pay,
                 u2_noun bat);

    /* u2_sh_hook(): formula by port name, from core.
    */
      u2_weak
      u2_sh_hoo(u2_ray  sad_r,
                u2_noun cor,
                u2_term tam);
