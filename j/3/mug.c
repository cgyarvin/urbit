/* j/3/mug.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "hpit.h"

/* functions
*/
  u2_noun
  j2_mb(Pit, mug)(u2_wire wir_r, u2_noun cor)
  {
    u2_noun sam;

    sam = u2_bi_frag(wir_r, 4, cor);
    {
      return u2_mug(sam);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mbj(Pit, mug)[] = { 
    { ".3", j2_mb(Pit, mug), u2_yes, u2_none, u2_none },
    { }
  };
