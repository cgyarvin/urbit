/* c/comd.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <setjmp.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "all.h"

/* c3_comd_init(): 
**
**   Initialize the readline console.  Return the history filename.
*/
c3_c*                                                             //  produce
c3_comd_init(void)
{
  /* gib: home directory
  ** fel: history pathname
  */
  const c3_c* gib_c = getenv("HOME");
  c3_c*       fel_c;
  c3_i        fd;

  if ( !gib_c ) {
    fprintf(stderr, "no home directory\n");
    exit(1);
  }
  fel_c = malloc(strlen(gib_c) + 13);
  strcpy(fel_c, gib_c);
  strcat(fel_c, "/.u3_history");

  if ( (fd = open(fel_c, O_CREAT | O_RDWR, 0666)) < 0 ) {
    perror(fel_c);
    exit(1);
  }
  close(fd);

  using_history();
  read_history(fel_c);

  return fel_c;
}

/* c3_comd_line():
**
**   Read a line from the console, saving to history file (fel).
**
**   Returns 0 iff the console has exited.  Otherwise, caller must 
**   free the line.
*/
c3_c*                                                             //  produce
c3_comd_line(const c3_c *fel_c)                                   //  retain
{
  while ( 1 ) {
    c3_c *vid_c;

    if ( !(vid_c = readline(": ")) ) {
      printf("\n");
      return 0;
    }
    if ( !*vid_c ) {
      free(vid_c);
      continue;
    }

    add_history(vid_c);
    if ( write_history(fel_c) ) {
      perror("console");
      exit(1);
    }
    return vid_c;
  }
}
