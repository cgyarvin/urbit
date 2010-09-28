/* include/plow.h
**
** This file is in the public domain.
*/
  /** Data types.
  **/
    /* u2_loom_plow: temporary adaptation layer for old plow code.
    */
      typedef struct {
        /* Set [*type *gene] in repo.
        */
        u2_pool fan;

        /* Set [*type] in verify.
        */
        u2_pool ver;

        /* Debug depth.
        */
        u2_atom bug;

        /* Trap - *(list &[p=*text q=*spot])
        */
        u2_noun meb;

        /* Book to memoize nest.
        */
        u2_book vus;

        /* Book to memoize null.
        */
        u2_book tyc;

        /* Book to memoize orth.
        */
        u2_book gam;

        /* Book to memoize show.
        */
        u2_book hos;

        /* Book to memoize play.
        */
        u2_book zor;

        /* Book to memoize make.
        */
        u2_book niq;

        /* Book to memoize safe.
        */
        u2_book fac;

        /* Book to memoize fine.
        */
        u2_book vom;

        /* Book to memoize open.
        */
        u2_book pon;

        /* Book to memoize find.
        */
        u2_book fin;

        /* Book to memoize half.
        */
        u2_book huf;
      } u2_loom_plow;

#define   u2_plow_(plo_r, pat)  *u2_at(plo_r, u2_loom_plow, zon_r)
