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
#include "z/public.h"

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
    char *c_vid;

    if ( !(c_vid = readline(": ")) ) {
      printf("\n");
      return 0;
    }
    if ( !*c_vid ) {
      free(c_vid);
      continue;
    }

    add_history(c_vid);
    if ( append_history(1, history_name) ) {
      perror("console");
      exit(1);
    }
    return c_vid;
  }
}

#if 0
extern void mord_boot(uz_machine);
extern void mord_line(uz_machine, uz_noun);

/* main()::
*/
int
main(int  argc,
     char **argv)
{
  char *history_name = _console_init();
  uz_machine mac;

  if ( !(mac = uz_l_boot(24)) ) {
    fprintf(stderr, "zeno: boot failed\n");
    return 1;
  }
  mord_boot(mac);

  while ( 1 ) {
    char *line = _console_line(history_name);

    if ( !line || !strcmp("q", line) || !strcmp("quit", line) ) {
      break;
    }
    else {
      uz_noun lug = uz_k_string(mac, line);

      mord_line(mac, lug);
    }
  }
  return 0;
}
#else

extern void *vere_boot(int size);
extern void  vere_line(void *vere, char *line);

int
main(int  argc,
     char **argv)
{
  char *history_name = _console_init();
  void *ver;

  if ( !(ver = vere_boot(24)) ) {
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
    }
  }
  return 0;
}
#endif
