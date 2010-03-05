/* include/z/jato.h
**
** This file is in the public domain.
*/
  /** Data structures.
  **/
    /* zj_spec: 
    **
    **   A spec specification.  Used at load time and not again.
    */
      struct u3_zj_spec {
        /* src: watt source for gate (eg, "add").
        ** pry: priority group, 0-16.
        ** pas: jet function, or 0.
        */
        const u3_c_c *c_src;
        u3_c_y       y_pry;
        u3_fox       (*fn_pas)(u3_z, u3_fox);
      };


  /** Functions.
  **/
    /** Upcalls from zeno.
    **/
      /* u3_zj_boot(): 
      **
      **   Initialize the jet system.
      **
      **   opt: optimization level (0-15)
      */
        u3_flag
        u3_zj_boot(u3_z z,
                   u3_y y_opt);

      /* u3_zj_look():
      **
      **   Look for a jet match - gate, [[cob van] axe].
      */
        enum u3_zj_code 
        u3_zj_look(u3_z   z,
                   u3_fox axe);

      /* u3_zj_axe():
      **
      **   Return the axe formula for a jet.
      */
        u3_fox
        u3_zj_axe(u3_z            z,
                  enum u3_zj_code code_sax);

      /* u3_zj_fire():
      **
      **   Fire a jet - fig, [[cob van].hub axe].
      **
      **   Set *pod and/or return error condition:
      **
      **     0         : jet executed correctly
      **     u3_cm_exit: true exit detected
      **     u3_cm_fail: failure to compute
      **     u3_cm_punt: return to soft code
      */
        u3_mote
        u3_zj_fire(u3_z            z,
                   u3_fox          *pod,
                   enum u3_zj_code code_sax,
                   u3_fox          fig);


    /** C environment for jet programmers.  Ideally pleasurable.
    ***
    *** Jet programmers may use lr functions, but not lm or ln.
    **/
      /** Administrative and miscellaneous.
      **/
        /* u3_zc_malloc():
        **
        **   Drop-in malloc() replacement.  Never returns 0.  Always
        **   allocates on the hat.
        */
          void *
          u3_zc_malloc(u3_z z,
                       u3_w w_led);

        /* u3_zc_depart():
        **
        **   Depart, moving allocation to the can, saving the mat.
        */
          u3_ray
          u3_zc_depart(u3_z z);

        /* u3_zc_retreat():
        **
        **   Retreat, restoring the mat.
        */
          void
          u3_zc_retreat(u3_z   z,
                        u3_ray ray_mat);
        
        /* u3_zc_zap():
        **
        **   Zap the can.
        */
          void
          u3_zc_zap(u3_z z);

        /* u3_zc_save():
        **
        **   Save a noun to the hat.
        */
          u3_fox
          u3_zc_save(u3_z   z,
                     u3_fox zab);

        /* u3_zc_tank():
        **
        **   Raise an unrecoverable exception.  Call with
        **
        **     u3_cm_exit: true exit detected
        **     u3_cm_fail: failure to compute
        **     u3_cm_punt: confused, return to soft code
        */
          u3_fox 
          u3_zc_tank(u3_z    z,
                     u3_mote gaz);


      /** Jet and interpreter activation.
      **/
        /* u3_zc_fire():
        **
        **   Cross-fire a jet.
        */
          u3_fox
          u3_zc_fire(u3_z            z,
                     enum u3_zj_code code_sax,
                     u3_fox          cob);

        /* u3_zc_nock():
        **
        **   Run the interpreter inside itself.
        */
          u3_fox
          u3_zc_nock(u3_z   z,
                     u3_fox lan,
                     u3_fox sef);

      /** Internal map facility.
      **/
        /* u3_zc_map_add():
        **
        **   Add (key toy) to (map).  For a new map, pass 0.
        */
          struct u3_zc_map *
          u3_zc_map_add(u3_z             z,
                        struct u3_zc_map *map,
                        u3_fox           key,
                        u3_fox           toy);

        /* u3_zc_map_find():
        **
        **   Return the toy for (key), or u3_none if there is none such.
        */
          u3_rat
          u3_zc_map_find(u3_z             z,
                         struct u3_zc_map *map,
                         u3_fox           key);


      /** Noun construction.
      **/
        /* u3_zc_bytes():
        **
        **   Copy (w_a) bytes from (y_b) into an atom on the hat of (l).
        */
          u3_fox
          u3_zc_bytes(u3_z       z,
                      u3_w       w_a,
                      const u3_y *y_b);

        /* u3_zc_string():
        **
        **   u3_zc_bytes(z, strlen(c_a), (u3_y *)c_a);
        */
          u3_fox
          u3_zc_string(u3_z       z,
                       const u3_c *c_a);

        /* u3_zc_cell(): 
        **
        **   Produce the cell [a b] on the hat of (z).
        */
          u3_fox
          u3_zc_cell(u3_z   z,
                     u3_fox a,
                     u3_fox b);

        /* u3_zc_mp():
        **
        **   Copy the GMP integer (mp_a) into an atom on the hat of (z).
        */
          u3_fox
          u3_zc_mp(u3_z  z,
                   mpz_t mp_a);

        /* u3_zc_trel(): 
        **
        **   Produce the trel [a b c] on the hat of (z).
        */
          u3_fox
          u3_zc_trel(u3_z   z,
                     u3_fox a,
                     u3_fox b,
                     u3_fox c);

        /* u3_zc_words():
        **
        **   Copy (w_a) words from (w_b) into an atom on the hat of (z).
        */
          u3_fox
          u3_zc_words(u3_z       z,
                      u3_w       w_a,
                      const u3_w *w_b);
