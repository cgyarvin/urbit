/* include/n.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   u3_n   (nolt)
**   u3_ni  (nolt internal)
**
** Description:
**
**   The nolt engine.  Nested in a cage, and nestable itself.
*/
  /** Data types.
  **/
    /** Noun types.
    **/
      /* A nolt formula.
      */
        typedef u3_fox u3_n_form;

      /* A nolt subject - ie, arbitrary noun.
      */
        typedef u3_fox u3_n_grit;

      /* A nolt result:
      **
      **      0       :: computing is not complete
      **      [0 c]   :: (eq c (nolt a b))
      **
      **      %lame   :: agenda is empty
      **      %exit   :: computation does not complete
      **      %fail   :: computation exceeded resources
      */
        typedef u3_fox u3_n_stat;


    /** C structures.
    **/
      /* The nolt engine.
      */
        struct u3_n_core {
          /* The nested cage.
          */
          struct u3_l_core l;

          /* The agenda.
          */
          u3_l_ray ray_lab;
        };
        typedef struct u3_n_core *u3_n;


  /** Functions.
  **/
    /** External.
    **/
      /* u3_n_new():
      **
      **   Create a nolt engine, mallocing (1 << y_a) words of memory.
      **   Return 0 if malloc fails.
      **
      **   The engine can be freed with free() - there is no destructor.
      */
        u3_n
        u3_n_new(u3_y y_a);

      /* u3_n_fire():
      **
      **   In (n), initiate the calculation (nolt a b).
      */
        void
        u3_n_fire(u3_n      n,
                  u3_n_grit a,
                  u3_n_form b);
 
      /* u3_n_spin():
      **
      **   As u3_n_step(), until complete.
      */
        u3_n_stat
        u3_n_spin(u3_n n);

      /* u3_n_step():
      **
      **   Step the engine, returning a nolt result.
      */ 
        u3_n_stat
        u3_n_step(u3_n n);

      /* u3_n_nock():
      **
      **   Simple nock, returning u3_none for failure.
      */
        u3_rat
        u3_n_nock(u3_n   n,
                  u3_fox lan,
                  u3_fox sef);


  /** Internal.
  **/
