/* include/b.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   u3_b   (bunt)
**
** Description:
**
**   Bunt functions, which are implemented with the old (u4) 
**   system.
*/

  /** Functions.
  **/
    /** Impure.
    **/
      /* u3_b_init(): 
      **
      **   Initialize static bunt services.
      */
        void
        u3_b_init(void);

      /* u3_b_print():
      **
      **   Print [piv], with [c_tid] if nonzero as a caption.
      */
        void
        u3_b_print(u3_lv      lv,
                   const u3_c *c_tid,
                   u3_rat     piv);

      /* u3_b_print_type():
      **
      **   Print [piv] as a type, with [c_tid] if nonzero as a caption.
      */
        void
        u3_b_print_type(u3_lv      lv,
                        const u3_c *c_tid,
                        u3_rat     piv);

    /** Pure.
    **/
      /* u3_b_nock():
      **
      **   Use bunt routines to execute (nock lan sef).
      */
        u3_rat
        u3_b_nock(u3_l   l,
                  u3_fox lan,
                  u3_fox sef);

      /* u3_b_load():
      **
      **   Use bunt routines to load [rop].
      */
        u3_rat 
        u3_b_load(u3_l,
                  u3_fox rop);

      /* u3_b_watt():
      **
      **   Use bunt routines to parse (wek), as watt.
      */
        u3_rat
        u3_b_watt(u3_l   l,
                  u3_fox wek);

      /* u3_b_vere():
      **
      **   Use bunt routines to parse (wek), as vere.
      */
        u3_rat
        u3_b_vere(u3_l   l,
                  u3_fox wek);

      /* u3_b_hume():
      **
      **   Use bunt routines to parse (wek), as hume.
      */
        u3_rat
        u3_b_hume(u3_l   l,
                  u3_fox wek);

      /* u3_b_full():
      **
      **   Use bunt routines to map (type gene) to (type form).
      */
        u3_rat
        u3_b_full(u3_l   l,
                  u3_fox gal,
                  u3_fox vub);

      /* u3_b_bake():
      **
      **   Use bunt routines to map (type gene) to (form).
      */
        u3_rat
        u3_b_bake(u3_l   l,
                  u3_fox gal,
                  u3_fox vub);
