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

/* _console_init(): 
**
**   Initialize the readline console.  Return the history filename.
*/
static char *
_console_init(void)
{
  /* gib: home directory
  ** fel: history pathname
  */
  const char *c_gib = getenv("HOME");
  char       *history_name;
  int     fd;

  if ( !c_gib ) {
    fprintf(stderr, "no home directory\n");
    exit(1);
  }
  history_name = malloc(strlen(c_gib) + 13);
  strcpy(history_name, c_gib);
  strcat(history_name, "/.u3_history");

  if ( (fd = open(history_name, O_CREAT | O_RDWR, 0666)) < 0 ) {
    perror(history_name);
    exit(1);
  }
  close(fd);

  using_history();
  read_history(history_name);

  return history_name;
}

/* _console_line():
**
**   Read a line from the console, saving to history file (fel).
**
**   Returns 0 iff the console has exited.  Otherwise, caller must 
**   free the line.
*/
static char *
_console_line(const char *history_name)
{
  while ( 1 ) {
    char *vid_c;

    if ( !(vid_c = readline(": ")) ) {
      printf("\n");
      return 0;
    }
    if ( !*vid_c ) {
      free(vid_c);
      continue;
    }

    add_history(vid_c);
    if ( append_history(1, history_name) ) {
      perror("console");
      exit(1);
    }
    return vid_c;
  }
}

extern void *vere_boot(uint32_t size);
extern void  vere_line(void *vere, char *line);
extern void  vere_line2(void *vere, char *line);

int
main(int  argc,
     char **argv)
{
  char *history_name = _console_init();
  void *ver;

  if ( !(ver = vere_boot(26)) ) {
    fprintf(stderr, "vere: boot failed\n");
    return 1;
  }
  while ( 1 ) {
    char *line = _console_line(history_name);

    if ( !line ) {
      break;
    }
    else {
      vere_line(ver, line);
      // vere_line2(ver, line);
    }
  }
  return 0;
}
