/* include/sham.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* u2_loom_pear: overloaded name-value pair.
    */
      typedef struct _u2_loom_pear {
        /*  [nam val]:     name-value pair
        **  [u2_none ray]: subtable
        **  [u2_none 0]:   empty
        */
        u2_weak nam;
        u2_weak val;
      } u2_loom_pear;

    /* u2_loom_sham:
    **
    **    16-way mug-powered hashtable.  If wun != u2_none,
    **    table is not allocated.
    */
      typedef struct _u2_loom_sham {
        u2_loom_pear dol_p[16];
      };
      

  /** Functions.
  **/
    /* u2_sh_find():
    **
    **   Find value for `nam` in `ash`, or return `u2_none`.
    */
      u2_weak
      u2_sh_find(u2_ray  ash_r,
                 u2_noun nam);
    
    /* u2_sh_find_cell():
    **
    **   Find value for `[hed tal]` in `ash`, or return `u2_none`.
    */
      u2_weak
      u2_sh_find_cell(u2_ray  ash_r,
                      u2_noun hed,
                      u2_noun tal);

    /* u2_sh_save():
    **
    **   Save `val` under `nam` in `ash`, allocating in `zon`.
    **   Return `u2_no` iff allocation fails.  Asserts on duplicate.
    */
      u2_flag
      u2_sh_save(u2_ray  zon_r,
                 u2_ray  ash_r,
                 u2_noun nam,
                 u2_noun val);

    /* u2_sh_save_cell():
    **
    **   Save `val` under `[hed tal]` in `ash`, allocating in `zon`.
    **   Return `u2_no` iff allocation fails.  Asserts on duplicate.
    */
      u2_flag
      u2_sh_save_cell(u2_ray  zon_r,
                      u2_ray  ash_r,
                      u2_noun hed,
                      u2_noun tal,
                      u2_noun val);
