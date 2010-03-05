/* include/c/defs.h
**
** This file is in the public domain.
*/
  /** Random useful C macros.
  **/
    /* Assert.  Good to capture.
    */
#     define u3_c_assert(x)   assert(x)

    /* Stub.
    */
#     define u3_c_stub       (assert(!"stub"), 0)

    /* Size in words.
    */
#     define u3_c_wiseof(x)  (((sizeof (x)) + 3) >> 2)

    /* Min and max.
    */
#     define u3_c_max(x, y) ( ((x) > (y)) ? (x) : (y) )
#     define u3_c_min(x, y) ( ((x) < (y)) ? (x) : (y) )


    /* Short integers.
    */
#     define u3_c_s1(a)          ( (a) )
#     define u3_c_s2(a, b)       ( ((b) << 8) | u3_c_s1(a) )
#     define u3_c_s3(a, b, c)    ( ((c) << 16) | u3_c_s2(a, b) )
#     define u3_c_s4(a, b, c, d) ( ((d) << 24) | u3_c_s3(a, b, c) )

#     define u3_c_s5(a, b, c, d, e) \
        ( ((uint64_t)u3_c_s1(e) << 32ULL) | u3_c_s4(a, b, c, d) )
#     define u3_c_s6(a, b, c, d, e, f) \
        ( ((uint64_t)u3_c_s2(e, f) << 32ULL) | u3_c_s4(a, b, c, d) )
#     define u3_c_s7(a, b, c, d, e, f, g) \
        ( ((uint64_t)u3_c_s3(e, f, g) << 32ULL) | u3_c_s4(a, b, c, d) )
#     define u3_c_s8(a, b, c, d, e, f, g, h) \
        ( ((uint64_t)u3_c_s4(e, f, g, h) << 32ULL) | u3_c_s4(a, b, c, d) )

