/* include/c/types.h
**
** This file is in the public domain.
*/
  /** Integer typedefs.
  **/
    /* Canonical integers.
    */
      typedef uint64_t c3_d;
      typedef int64_t c3_ds;
      typedef uint32_t c3_w;
      typedef int32_t c3_ws;
      typedef uint16_t c3_s;
      typedef int16_t c3_ss;
      typedef uint8_t c3_y;
      typedef int8_t c3_ys;
      typedef uint8_t c3_b;   // bit

    /* Deprecated integers.  Uncomment if used.
    */
      typedef char c3_c;      // does not match int8_t or uint8_t
      typedef int  c3_i;      // int - really bad 
      // typedef u3_w c3_p;   // pointer-length int - uncomment if needed 
