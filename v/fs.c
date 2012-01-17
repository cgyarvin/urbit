/* v/fs.c
**
** This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <stdint.h>

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"

/* u2_ve_file(): load internal file as atom from local or system.
*/
u2_weak
u2_ve_file(c3_c* ext_c, u2_noun tah)
{
  u2_noun pas;
  u2_weak dat;

  c3_assert(u2_Local);
  pas = u2_cf_path(u2_Local, ext_c, u2_ct(tah));
  dat = u2_cf_flat_load(c3__atom, pas);

  if ( (u2_none != dat) || !u2_System ) {
    u2_cz(tah);

    return dat;
  } else {
    return u2_cf_flat_load(c3__atom, u2_cf_path(u2_System, ext_c, tah));
  }
}

/* u2_ve_date(): date internal file.
*/
c3_d
u2_ve_date(c3_c* ext_c, u2_noun tah)
{
  u2_noun pas;
  u2_weak dat;

  pas = u2_cf_path(u2_Local, ext_c, u2_ct(tah));
  dat = u2_cf_flat_date(pas);

  if ( (0 != dat) || !u2_System ) {
    u2_cz(tah);

    return dat;
  } else {
    return u2_cf_flat_date(u2_cf_path(u2_System, ext_c, tah));
  }
}

/* u2_ve_save(): save internal file as atom.
*/
void
u2_ve_save(c3_c* ext_c, u2_noun tah, u2_noun dat)
{
  u2_cf_flat_save(c3__atom, u2_cf_path(u2_Local, ext_c, tah), dat);
}


