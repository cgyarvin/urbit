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
 
    /* zj_def:
    **
    **   A jet definition.  Populated by installation.
    */
      struct u3_zj_def {
        /* Name of the jet.
        */
        const u3_c_c *nam;

        /* Version: major, minor, kelvin.
        */
        uint32_t maj, min, kel;

        /* Battery mug.
        */
        u3_fox mug;

        /* Optimization priority.
        */
        uint32_t pri;

        /* Fun, or null.
        */
        u3_fox (*pas)(u3_z, u3_fox);

        /* Parent, or null.
        */
        struct u3_zj_def *par;

        /* Next in search list.  (XX - tree-ify.)
        */
        struct u3_zj_def *nex;
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
      **   Look for a jet match - gate, [[sam con] bat].
      */
        enum u3_zj_code 
        u3_zj_look(u3_z   z,
                   u3_fox bat);

      /* u3_zj_bat():
      **
      **   Return the bat formula for a jet.
      */
        u3_fox
        u3_zj_bat(u3_z            z,
                  enum u3_zj_code code_sax);

      /* u3_zj_fire():
      **
      **   Fire a jet - subject, [[sam con] bat].
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
                   enum u3_zj_code sax,
                   u3_fox          sub);


    /** C environment for jet programmers.  Ideally pleasurable.
    ***
    *** Jet programmers may use lr functions, but not lm or ln.
    *** Replace with appropriate zc.
    **/
      /** Macros.
      **/
#       define u3_zh(z, n)      u3_zc_use(z, u3_lr_h(z, n))
#       define u3_zt(z, n)      u3_zc_use(z, u3_lr_t(z, n))
#       define u3_zf(z, a, n)   u3_zc_use(z, u3_lr_twig(z, a, n))

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

        /* u3_zc_use():
        **
        **   Exit iff (rat) is none.
        */
          u3_fox
          u3_zc_use(u3_z   z,
                    u3_rat rat);

      /** Jet and interpreter activation.
      **/
        /* u3_zc_fire():
        **
        **   Cross-fire a jet.
        */
          u3_fox
          u3_zc_fire(u3_z            z,
                     enum u3_zj_code code_sax,
                     u3_fox          sam);

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
