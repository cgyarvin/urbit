/* include/c/portable.h
**
** This file is in the public domain.
*/
  /** Must be compiled on gcc with C99 support.
  **/
#    ifndef __GNUC__
#      error "port me"
#    endif
#    define _GNU_SOURCE


  /** System include files.
  ***
  *** Do not put include files that are only used in the
  *** porting layer here.  Include them directly in the
  *** C file.
  **/
#   if defined(U2_OS_linux)
#     include <stdlib.h>
#     include <string.h>
#     include <stdarg.h>
#     include <unistd.h>
#     include <stdint.h>
#     include <assert.h>
#     include <byteswap.h> 
#     include <setjmp.h>
#     include <stdio.h>
#     include <signal.h>
#     include <sys/time.h>
#     include <sys/resource.h>
#     include <sys/mman.h>

#   elif defined(U2_OS_osx)
#     include <stdlib.h>
#     include <string.h>
#     include <stdarg.h>
#     include <unistd.h>
#     include <stdint.h>
#     include <assert.h>
#     include <setjmp.h>
#     include <signal.h>
#     include <machine/endian.h> 
#     include <machine/byte_order.h> 
#     include <stdio.h>
#     include <sys/time.h>
#     include <sys/resource.h>
#     include <sys/mman.h>

#   endif

  /** Address space layout.
  **/
#   if defined(U2_OS_linux)
#     define U2_OS_LoomBase 0x4000000

#   elif defined(U2_OS_osx)
#     define U2_OS_LoomBase 0x4000000
#     define U2_OS_LoomBits 29            //  ie, 2^29 words == 
#   endif

  /** Global variable control.
  ***
  *** To instantiate globals, #define c3_global as extern.
  **/
#   ifndef c3_global
#     define c3_global
#   endif


  /** External, OS-independent library dependencies.
  **/
    /* The GMP (GNU arbitrary-precision arithmetic) library.
    ** (Tested with version 4.0.1.)
    */
#      include <gmp.h>


  /** Private C "extensions."
  ***
  *** Except for these and main(), any function, macro, or structure
  *** names must be prefixed either by u3_/U2_ (for public names),
  *** or _ (for static and other file-local names).
  **/
    /* Endianness.
    */
#     define c3_endian_little     0
#     define c3_endian_big        1

#     ifdef U2_OS_ENDIAN_little
#       define c3_endian c3_endian_little
#     elif defined(U2_OS_ENDIAN_big)
#       define c3_endian c3_endian_big
#     else
#       error "port: U2_OS_ENDIAN"
#     endif

    /* Byte swapping.
    */
#      if defined(U2_OS_linux)
#        define c3_bswap_16(x)  bswap_16(x)
#        define c3_bswap_32(x)  bswap_32(x)
#        define c3_bswap_64(x)  bswap_64(x)

#      elif defined(U2_OS_osx)
#        define c3_bswap_16(x)  NXSwapShort(x)
#        define c3_bswap_32(x)  NXSwapInt(x)
#        define c3_bswap_64(x)  NXSwapLongLong(x)
#      endif
