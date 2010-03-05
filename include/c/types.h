/* include/c/types.h
**
** This file is in the public domain.
*/
  /** Integer typedefs.
  **/
    /* Canonical integers.
    */
      typedef uint64_t u3_c_d;
      typedef int64_t u3_c_ds;
      typedef uint32_t u3_c_w;
      typedef int32_t u3_c_ws;
      typedef uint16_t u3_c_s;
      typedef int16_t u3_c_ss;
      typedef uint8_t u3_c_y;
      typedef int8_t u3_c_ys;
      typedef uint8_t u3_c_b;   // bit

    /* Deprecated integers.  Uncomment if used.
    */
      typedef char u3_c_c;      // does not match int8_t or uint8_t
      typedef int  u3_c_i;      // int - really bad 
      // typedef u3_w u3_c_p;   // pointer-length int - uncomment if needed 
