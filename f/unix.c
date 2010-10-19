/* l/unix.c
**
** This file is in the public domain.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include "all.h"

/* u2_ux_read(): read a filesystem path/extension into an atom.
*/
u2_weak
u2_ux_read(u2_ray      ral_r,
           const c3_c* paf_c,
           const c3_c* ext_c)
{
  c3_w len_w = strlen(paf_c) + 1 + strlen(ext_c);
  c3_c *nam_c = alloca(len_w + 1);

  sprintf(nam_c, "%s.%s", paf_c, ext_c);
  {
    c3_i        fid_i;
    struct stat sat_s;
    c3_w        fln_w;
    c3_c        *fil_c;
    u2_atom     fil;

    fid_i = open(nam_c, O_RDONLY, 0666);
    if ( (fid_i < 0) || (fstat(fid_i, &sat_s) < 0) ) {
      return u2_none;
    }

    fln_w = sat_s.st_size;
    fil_c = malloc(sat_s.st_size);

    if ( fln_w != read(fid_i, fil_c, fln_w) ) {
      return u2_none;
    }
    close(fid_i);

    fil = u2_rl_bytes(ral_r, fln_w, (c3_y *)fil_c); 
    free(fil_c);

    return fil;
  }
}
