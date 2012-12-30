/* j/book.c
**
** This file is in the public domain.
*/
#include "all.h"

/** Warning: this file contains old code which does not comply
*** with current coding conventions.
**/

/* _ord_tag_simple():
**
**    Return 1 iff (tag_l tag_r) are in correct simple order.
**
**    Trip if (tag_l tag_r) are equal.
*/
static c3_t
_ord_tag_simple(u2_noun tag_l, u2_noun tag_r)
{
  return (u2_nord(tag_l, tag_r) == _0);
}

/* _ord_hog_prior():
**
**    Return 1 iff (hog_l hog_r) are in correct priority order (meta-mog).
**
**    Trip iff (hog_l hog_r) are equal.
*/
static c3_t
_ord_hog_prior(u2_noun hog_l, u2_noun hog_r)
{
  u2_noun tag_l = u2_h(hog_l);
  u2_noun tag_r = u2_h(hog_r);
  c3_w nib_l = u2_mog(u2_mog(tag_l));
  c3_w nib_r = u2_mog(u2_mog(tag_r));

  if ( nib_l == nib_r ) {
    return _ord_tag_simple(tag_l, tag_r);
  }
  else return (nib_l < nib_r);
}

/* _ord_hog_tree():
**
**    Return 1 iff (hog_l hog_r) are in correct tree order (mog).
**
**    Stop iff (hog_l hog_r) are equal.
*/
static c3_t
_ord_hog_tree(u2_noun hog_l, u2_noun hog_r)
{
  u2_noun tag_l = u2_h(hog_l);
  u2_noun tag_r = u2_h(hog_r);
  c3_w mog_l = u2_mog(tag_l);
  c3_w mog_r = u2_mog(tag_r);

  if ( mog_l == mog_r ) {
    return _ord_tag_simple(tag_l, tag_r);
  }
  else return (mog_l < mog_r);
}

/* u2_fj_book_is():
**
**   Return 1 iff (noun) is a book.
*/
c3_t
u2_fj_book_is(u2_noun book)
{
  if ( (u2_nul == book) ) {
    return 1;
  }
  else {
    u2_noun hog;
    u2_book book_l, book_r;

    u2_as_trel(book, &hog, &book_l, &book_r);
    {
      if ( !(u2_nul == book_l) ) {
        u2_noun hog_l = u2_h(book_l);

        if ( !_ord_hog_tree(hog_l, hog) ) {
          return 0;
        }
        if ( !_ord_hog_prior(hog, hog_l) ) {
          return 0;
        }
      }

      if ( !(u2_nul == book_r) ) {
        u2_noun hog_r = u2_h(book_r);

        if ( !_ord_hog_tree(hog, hog_r) ) {
          return 0;
        }
        if ( !_ord_hog_prior(hog, hog_r) ) {
          return 0;
        }
      }
    }
    return u2_fj_book_is(book_l) && u2_fj_book_is(book_r);
  }
}

/* u2_fj_book_in():
**
**   Return 1 iff (tag_in) is in (book).
*/
c3_t
u2_fj_book_in(u2_noun tag_in,
              u2_book  book)
{
  if ( (u2_nul == book) ) {
    return 0;
  }
  else {
    c3_w mog_in = u2_mog(tag_in);

    while ( 1 ) {
      if ( (u2_nul == book) ) {
        return 0;
      }
      else {
        u2_noun hog;
        u2_noun tag;
        u2_noun dog;
        u2_book book_l, book_r;

        u2_as_trel(book, &hog, &book_l, &book_r);
        u2_as_cell(hog, &tag, &dog);
        {
          c3_w mog = u2_mog(tag);

          if ( mog_in == mog ) {
            if ( u2_yes == u2_sing(tag_in, tag) ) {
              return 1;
            }
            else book = _ord_tag_simple(tag_in, tag) ? book_l : book_r;
          }
          else {
            book = (mog_in < mog) ? book_l : book_r;
          }
        }
      }
    }
  }
}

/* u2_fj_book_get(): 
**
**   Produce the dog in (book) matching (tag_get), or u2_none.
*/
u2_weak
u2_fj_book_get(u2_noun tag_get,
               u2_book  book)
{
  if ( (u2_nul == book) ) {
    return u2_none;
  }
  else {
    c3_w mog_get = u2_mog(tag_get);

    while ( 1 ) {
      if ( (u2_nul == book) ) {
        return u2_none;
      }
      else {
        u2_noun hog;
        u2_noun tag;
        u2_noun dog;
        u2_book book_l, book_r;

        u2_as_trel(book, &hog, &book_l, &book_r);
        u2_as_cell(hog, &tag, &dog);
        {
          c3_w mog = u2_mog(tag);

          if ( mog_get == mog ) {
            if ( u2_yes == u2_sing(tag_get, tag) ) {
              return dog;
            }
            else book = _ord_tag_simple(tag_get, tag) ? book_l : book_r;
          }
          else {
            book = (mog_get < mog) ? book_l : book_r;
          }
        }
      }
    }
  }
}

/* _book_fix_l(): fix a book whose left side has been rebuilt.
*/
static u2_book
_book_fix_l(u2_ray  wir_r,
           u2_noun  hog,
           u2_book  book_l,
           u2_book  book_r)
{
  u2_noun hog_l;
  u2_book book_ll, book_lr;

  u2_as_trel(book_l, &hog_l, &book_ll, &book_lr);
  {
    if ( _ord_hog_prior(hog, hog_l) ) {
      return u2_bt(wir_r, hog, book_l, book_r);
    }
    else {
      /* Rotate to the right.
      */
      return u2_bt(wir_r, hog_l, book_ll, 
                                    u2_bt(wir_r, hog, book_lr, book_r));
    }
  }
}

/* _book_fix_r(): fix a book whose right side has been rebuilt.
*/
static u2_book
_book_fix_r(u2_ray  wir_r,
           u2_noun  hog,
           u2_book  book_l,
           u2_book  book_r)
{
  u2_noun hog_r;
  u2_book book_rl, book_rr;

  u2_as_trel(book_r, &hog_r, &book_rl, &book_rr);
  {
    if ( _ord_hog_prior(hog, hog_r) ) {
      return u2_bt(wir_r, hog, book_l, book_r);
    }
    else {
      /* Rotate to the left.
      */
      return u2_bt(wir_r, hog_r, u2_bt(wir_r, hog, book_l, book_rl), 
                                    book_rr);
    }
  }
}

/* _book_add_mog(): as u2_fj_book_add(), with mog of tag.
*/
static u2_book
_book_add_mog(u2_ray  wir_r,
              u2_noun tag_add,
              u2_noun dog_add,
              c3_w    mog_add,
              u2_book book)
{
  if ( (u2_nul == book) ) {
    return u2_bt(wir_r, u2_bc(wir_r, tag_add, dog_add), u2_nul, u2_nul);
  }
  else {
    u2_noun hog;
    u2_noun tag;
    u2_noun dog;
    u2_book book_l, book_r;

    u2_as_trel(book, &hog, &book_l, &book_r);
    u2_as_cell(hog, &tag, &dog);
    {
      c3_w mog = u2_mog(tag);

      if ( mog_add == mog ) {
        if ( u2_yes == u2_sing(tag_add, tag) ) {
          if ( u2_yes == u2_sing(dog_add, dog) ) {
            return book;
          }
          else {
            return u2_bt(wir_r, u2_bc(wir_r, tag_add, dog_add),
                                   book_l,
                                   book_r);
          }
        }
        else {
          if ( _ord_tag_simple(tag_add, tag) ) {
            goto left;
          } else goto right;
        }
      }
      else {
        if ( mog_add < mog ) {
          left: {
            u2_book book_l_add = _book_add_mog
              (wir_r, tag_add, dog_add, mog_add, book_l);

            if ( book_l_add == book_l ) {
              return book;
            }
            else return _book_fix_l(wir_r, hog, book_l_add, book_r);
          }
        } else {
          right: {
            u2_book book_r_add = _book_add_mog
              (wir_r, tag_add, dog_add, mog_add, book_r);

            if ( book_r_add == book_r ) {
              return book;
            }
            else return _book_fix_r(wir_r, hog, book_l, book_r_add);
          }
        }
      }
    }
  }
}

/* u2_fj_book_add():
**
**   Produce a new book which adds (tag_add dog_add) to (book).
**   Replace old dog, if any.
*/
u2_book
u2_fj_book_add(u2_ray  wir_r,
               u2_noun tag_add,
               u2_noun dog_add,
               u2_book book)
{
  return _book_add_mog(wir_r, tag_add, dog_add, u2_mog(tag_add), book);
}

/* u2_fj_book_add_list():
**
**   Produce a new book which adds all (tag dog) cells in
**   (list) to (book).  Replace old dog, if any.
*/
u2_book
u2_fj_book_add_list(u2_ray  wir_r,
                    u2_list  list,
                    u2_book  book)
{
  while ( !(u2_nul == list) ) {
    u2_noun i_list = u2_h(list);

    book = u2_fj_book_add(wir_r, u2_h(i_list), u2_t(i_list), book);
    list = u2_t(list);
  }
  return book;
}

/* u2_fj_book_list():
**
**   Convert (book) to a pseudo-randomly sorted list of (tag dog) 
**   cells, prepending to (list).
*/
u2_list
u2_fj_book_list(u2_ray  wir_r,
                u2_list list,
                u2_book book)
{
  if ( (u2_nul == book) ) {
    return list;
  }
  else {
    u2_noun hog;
    u2_book book_l, book_r;

    u2_as_trel(book, &hog, &book_l, &book_r);
    {
      list = u2_fj_book_list(wir_r, list, book_l);
      list = u2_bc(wir_r, hog, list);
      list = u2_fj_book_list(wir_r, list, book_r);
    }
    return list;
  }
}
