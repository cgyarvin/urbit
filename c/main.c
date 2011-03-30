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

#if 1

extern void *hill_boot(void);
extern void  hill_line(void *hill, const char *line);
extern void  hill_lose(void *hill);

int
main(int  argc,
     char **argv)
{
  char *history_name = _console_init();
  void *hill;

  if ( !(hill = hill_boot()) ) {
    return 1;
  }
  while ( 1 ) {
    char *line = _console_line(history_name);

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
  char *history_name = _console_init();
  void *fod;

  if ( !(fod = zuse_boot("watt/271")) ) {
    fprintf(stderr, "zuse: boot failed\n");
    return 1;
  }
  // zuse_test(fod, "watt/t1-273");

  while ( 1 ) {
    char *line = _console_line(history_name);

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
