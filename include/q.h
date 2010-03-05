/* include/q.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   u3_q   (quat)
**
** Description:
**
**   The quat engine.  Nested in a nock, and nestable itself.
**
**   Quat provides source-level programming.  All services are
**   currently supplied by boot.
*/
  /** Data types.
  **/
    /* A source package.
    */
      typedef u3_fox u3_q_src;

    /* A mold.
    */
      typedef u3_fox u3_q_mold;

    /* A pair (mold grit), grit in mold.
    */
      typedef u3_fox u3_q_shoe;

    /* A source path.
    */
      typedef u3_fox u3_path;

    /* A quat status:
    **
    **    u3_n_stat
    **    [%lose [%path %spot] %message]   :: local error
    **    [%carp [%path %spot] %message]   :: global error
    */
      typedef u3_fox u3_q_stat;

    /* The quat engine.
    */
      struct u3_q_core {
        /* The nested nock core.
        */
        struct u3_n_core n;
        
        /* The boot shoe.
        */
        u3_q_shoe tef;
      };
      typedef struct u3_q_core *u3_q;


  /** Functions.
  **/
    /** External.
    **/
      /* u3_q_new():
      **
      **   Create a quat engine, mallocing (1 << y_a) words of memory.
      **   Return 0 if malloc fails.
      **
      **   The engine can be freed with free() - there is no destructor.
      */
        u3_q
        u3_q_new(u3_y y_a);

