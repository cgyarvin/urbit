/* include/m.h
**
** This file is in the public domain.
**
** Prefixes:
**
**   u3_m   (marp)
**
** Description:
**
**   The marp engine.  Nested in a nock, and nestable itself.
*/
  /** Data types.
  **/
    /* The marp engine.
    */
      struct u3_m_core {
        /* The nested zeno engine.
        */
        struct u3_z_core z;

        /* The current shoe.
        */
        u3_q_shoe dut;
      };
      typedef struct u3_m_core *u3_m;


  /** Functions.
  **/
    /** External.
    **/
      /* u3_m_new():
      **
      **   Create a marp engine, mallocing (1 << y_a) words of memory.
      **   Return 0 if malloc fails.  Free with free().
      **
      **   Rely only on jets of priority <= (y_b), testing all others.
      **   y_b is 0 for full nock, 15 for full speed.
      */
        u3_m
        u3_m_new(u3_y y_a,
                 u3_y y_b);

      /* u3_m_do():
      **
      **   Execute a marp command.
      **
      **   Caller transfers ownership of (c_cob), receives ownership
      **   of result.  (Ie, u3_m_cmd() frees (c_cob), and its result
      **   must be freed.)
      */
        u3_c *
        u3_m_do(u3_m m,
                u3_c *c_cob);
