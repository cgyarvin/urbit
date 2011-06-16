/* c/main.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <setjmp.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <gmp.h>
#include <stdint.h>

#include "all.h"

#if 1

extern void *hill_boot(void);
extern void  hill_line(void *hill, const char *line);
extern void  hill_lose(void *hill);

int
main(int  argc,
     char **argv)
{
  char *history_name = c3_comd_init();
  void *hill;

  if ( !(hill = hill_boot()) ) {
    return 1;
  }
  while ( 1 ) {
    char *line = c3_comd_line(history_name);

    if ( !line ) {
      break;
    }
    else {
      hill_line(hill, line);
    }
  }
  hill_lose(hill);
  return 0;
}

#else

  /* zuse_boot(): create the zuse engine.
  */
    struct zuse_state*
    zuse_boot(const char* src_c);

  /* zuse_line(): execute a zuse command.
  */
    void
    zuse_line(struct zuse_state* fod_f,
              const char*        cmd_c,
              const char*        arg_c);

  /* zuse_test(): initiate zuse recursion.
  */
    void
    zuse_test(struct zuse_state* fod_f,
              const char*        src_c);

  /* zuse_done(): terminate and free all 
  */
    void
    zuse_done(struct zuse_state* fod_f);
    
int
main(int  argc,
     char **argv)
{
  char *history_name = c3_comd_init();
  void *fod;

  if ( !(fod = zuse_boot("watt/271")) ) {
    fprintf(stderr, "zuse: boot failed\n");
    return 1;
  }
  // zuse_test(fod, "watt/t1-273");

  while ( 1 ) {
    char *line = c3_comd_line(history_name);

    if ( !line ) {
      break;
    }
    else {
      char *cmd = line;
      char *arg = strchr(line, ' ');

      if ( 0 != arg ) {
        *arg++ = 0; 
      }
      zuse_line(fod, cmd, arg);
      free(line);
    }
  }
  zuse_done(fod);
  return 0;
}

#endif
