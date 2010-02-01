/* cake/bail.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include "u4/all.h"

/* u4_bail_out():
**
**   Bail out with (code).
*/
u4_int
u4_bail_out(enum u4_bail_code code)
{
  if ( code == u4_bail_trip ) {
    printf("trip!\n");
    abort();
  }
  else if ( code == u4_bail_stub ) {
    printf("stub!\n");
    abort();
  }
  else longjmp(U4_Bail.jmpbuf, code);

  return 0;
}
