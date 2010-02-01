/* cake/look.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* u4_n_atom():
**
**   Return 1 if (noun) is an atom.
*/
u4_t
u4_n_atom(u4_noun noun)
{
  if ( u4_noun_is_cod(noun) ) {
    return 1;
  }
  else {
    u4_pin pin = noun;
    
    return u4_pin_is_atom(pin);
  }
}

/* u4_n_cell():
**
**   Return 1 if (noun) is a cell.
*/
u4_t
u4_n_cell(u4_noun noun)
{
  if ( u4_noun_is_cod(noun) ) {
    return 0;
  }
  else {
    u4_pin pin = noun;
    
    return u4_pin_is_cell(pin);
  }
}

/* u4_n_trel():
** u4_n_qual():
** u4_n_quil():
**
**   Return 1 if (noun) is a trel, qual or quil.
*/
u4_t u4_n_trel(u4_noun noun) 
  { return u4_n_cell(noun) && u4_n_cell(u4_ct(noun)); }

u4_t u4_n_qual(u4_noun noun)
  { return u4_n_cell(noun) && u4_n_trel(u4_ct(noun)); }

u4_t u4_n_quil(u4_noun noun)
  { return u4_n_cell(noun) && u4_n_qual(u4_ct(noun)); }

/* u4_n_size():
**
**   Return number of subnouns in (a).
*/
u4_xw
u4_n_size(u4_noun a)
{
  if ( u4_n_atom(a) ) {
    return 1;
  }
  else return (u4_n_size(u4_ch(a)) + u4_n_size(u4_ct(a)));
}

/* u4_n_eq():
**
**   Return 1 if (a) and (b) are the same noun.
*/
u4_t
u4_n_eq(u4_noun a,
        u4_noun b)
{
  if ( a == b ) {
    return 1;
  }
  else {
    u4_t t_atom_a = u4_n_atom(a);
    u4_t t_atom_b = u4_n_atom(b);

    if ( t_atom_a != t_atom_b ) {
      return 0;
    }
    else {
      u4_t t_atom = t_atom_a;

      if ( !t_atom ) {
        return u4_n_eq(u4_c_head(a), u4_c_head(b)) && 
               u4_n_eq(u4_c_tail(a), u4_c_tail(b));
      }
      else {
        if ( u4_noun_is_cod(a) || u4_noun_is_cod(b) ) {
          return 0;
        }
        else {
          u4_pin pin_a = a;
          u4_pin pin_b = b;

          if ( u4_pin_is_fort(pin_a) || u4_pin_is_fort(pin_b) ) {
            return u4_stub;
          } 
          else {
            u4_sw sw_a = u4_open_atom_sw(pin_a);
            u4_sw sw_b = u4_open_atom_sw(pin_b);

            if ( sw_a != sw_b ) {
              return 0;
            }
            else {
              u4_sw sw = sw_a;
              u4_pw pw;

              for ( pw = 0; pw < sw; pw++ ) {
                if ( u4_open_atom_xw(pin_a, pw) != 
                     u4_open_atom_xw(pin_b, pw) )
                {
                  return 0;
                }
              }
              return 1;
            }
          }
        }
      }
    }
  }
}
              
/* u4_n_eq_c():
**
**   Return 1 if (noun) equals the C string (cl).
*/
u4_t
u4_n_eq_c(u4_noun noun,
          u4_cl   *cl)
{
  if ( u4_n_cell(noun) ) {
    return 0;
  } 
  else {
    u4_sb sb;

    if ( u4_a_bin(noun, 3) != (sb = strlen(cl)) ) {
      return 0;
    }
    else {
      u4_cl *cl_noun = alloca(sb + 1);

      u4_a_bytes(noun, (u4_xb *)cl_noun, 0, sb + 1);
      return !strcmp(cl, cl_noun);
    }
  }
}

/* u4_c_head():
**
**   Return the head of (cell).
*/
u4_noun
u4_c_head(u4_cell cell)
{
  if ( u4_bull == cell ) {
    u4_bug("head: bull", cell);
    return u4_trip;
  }
  else if ( u4_noun_is_cod(cell) ) {
    u4_bug("head: flat", cell);
    return u4_trip;
  }
  else {
    u4_pin pin_cell = cell;

    if ( u4_pin_is_atom(pin_cell) ) {
      u4_bug("head: flat", cell);
      return u4_trip;
    }
    else if ( u4_pin_is_fort(pin_cell) ) {
      return u4_stub;
    }
    else {
      return u4_open_cell_head(pin_cell);
    }
  }
}

/* u4_c_tail():
**
**   Return the tail of (cell).
*/
u4_noun
u4_c_tail(u4_cell cell)
{
  if ( u4_bull == cell ) {
    u4_bug("tail: bull", cell);
    return u4_trip;
  }
  else if ( u4_noun_is_cod(cell) ) {
    u4_bug("tail: flat", cell);
    return u4_trip;
  }
  else {
    u4_pin pin_cell = cell;

    if ( u4_pin_is_atom(pin_cell) ) {
      u4_bug("tail: flat", cell);
      return u4_trip;
    }
    else if ( u4_pin_is_fort(pin_cell) ) {
      return u4_stub;
    }
    else {
      return u4_open_cell_tail(pin_cell);
    }
  }
}

/* u4_c_head_exit():
**
**   Return the head of (noun), or exit if (noun) is flat.
*/
u4_noun
u4_c_head_exit(u4_noun noun)
{
  if ( u4_n_atom(noun) ) {
    return u4_exit;
  }
  else return u4_ch(noun);
}

/* u4_c_tail_exit():
**
**   Return the tail of (noun), or exit if (noun) is flat.
*/
u4_noun
u4_c_tail_exit(u4_noun noun)
{
  if ( u4_n_atom(noun) ) {
    return u4_exit;
  }
  else return u4_ct(noun);
}

/* u4_c_cell(): 
** u4_c_trel():
** u4_c_qual():
** u4_c_quil():
**
**   Unpack (cell, trel, qual, quil).
*/
u4_t 
u4_c_cell(u4_noun cell, 
          u4_noun *a, 
          u4_noun *b)
{ 
  if ( !u4_n_cell(cell) ) {
    return 0;
  }

  *a = u4_ch(cell); 
  *b = u4_ct(cell);
  return 1;
}

u4_t 
u4_c_trel(u4_noun trel, 
          u4_noun *a, 
          u4_noun *b, 
          u4_noun *c)
{ 
  if ( !u4_n_cell(trel) ) {
    return 0;
  }
  *a = u4_ch(trel); 

  return u4_c_cell(u4_ct(trel), b, c); 
}

u4_t 
u4_c_qual(u4_noun qual, 
          u4_noun *a, 
          u4_noun *b, 
          u4_noun *c, 
          u4_noun *d)
{
  if ( !u4_n_cell(qual) ) {
    return 0;
  }
  *a = u4_ch(qual); 

  return u4_c_trel(u4_ct(qual), b, c, d);
}

u4_t 
u4_c_quil(u4_noun quil, 
          u4_noun *a, 
          u4_noun *b, 
          u4_noun *c, 
          u4_noun *d, 
          u4_noun *e)
{ 
  if ( !u4_n_cell(quil) ) {
    return 0;
  }
  *a = u4_ch(quil); 

  return u4_c_qual(u4_ct(quil), b, c, d, e);
}

/* u4_c_log():
**
**   Unpack a log of length (xw), ignoring the tail.
*/
void
u4_c_log(u4_log  log,
         u4_xw   xw,
         u4_noun *nouns)
{
  u4_xw i;

  for ( i=0; i < xw; i++ ) {
    nouns[i] = u4_ch(log);
    log = u4_ct(log);
  }
}

/* u4_c_tuple():
**
**   Unpack a tuple of (xw) nouns.
*/
void
u4_c_tuple(u4_noun tuple,
           u4_xw   xw,
           u4_noun *nouns)
{
  u4_assert(xw);
  {
    u4_xw i;

    for ( i=0; i < (xw - 1); i++ ) {
      nouns[i] = u4_ch(tuple);
      tuple = u4_ct(tuple);
    }
    nouns[i] = tuple;
  }
}

/* _nub_xw(): equivalent to _nub_pin_atom(), for (xw).
*/
static u4_nub
_nub_xw(u4_xw xw)
{
  u4_xw xw_seed = 0x18d0a625;

  if ( !xw ) {
    return xw_seed;
  }
  else {
    while ( 1 ) {
      u4_xw xw_hash = xw_seed;

      xw_hash ^= xw;
      xw_hash = u4_sbox_mix(xw_hash);
      xw_hash &= 0x7fffffff;

      if ( xw_hash ) {
        return xw_hash;
      }
      else xw_seed++;
    }
  }
} 

/* _nub_pin_atom(): compute the nub of (pin), an open atom.
*/
static u4_nub
_nub_pin_atom(u4_pin_open_atom pin)
{
  u4_sw sw      = u4_open_atom_sw(pin);
  u4_xw xw_seed = 0x18d0a625;

  while ( 1 ) {
    u4_xw xw_hash = xw_seed;
    u4_pw pw;

    for ( pw=0; pw < sw; pw++ ) {
      u4_xw xw_pw = u4_open_atom_xw(pin, pw);

      xw_hash ^= xw_pw;
      xw_hash = u4_sbox_mix(xw_hash);
    }
    xw_hash &= 0x7fffffff;

    if ( xw_hash ) {
      return xw_hash;
    }
    else xw_seed++;
  }
}

/* _nub_pin_cell(): compute the nub of (pin), an open cell.
*/
static u4_nub
_nub_pin_cell(u4_pin_open_cell pin)
{
  u4_noun head = u4_open_cell_head(pin);
  u4_noun tail = u4_open_cell_tail(pin);
  {
    u4_nub nub_head = u4_n_nub(head);
    u4_nub nub_tail = u4_n_nub(tail);
    u4_xw  xw_both  = ((~nub_head) ^ (nub_tail >> 24) ^ (nub_tail << 8));
 
    return _nub_xw(xw_both);
  }
}

/* u4_n_nub():
**
**  Return the nub [31-bit nonzero insecure hash] of (noun).
*/
u4_nub
u4_n_nub(u4_noun noun)
{
  u4_assert(noun != u4_bull);

  if ( u4_noun_is_cod(noun) ) {
    return _nub_xw(u4_cod_out(noun));
  }
  else {
    u4_pin pin = noun;

    if ( u4_pin_is_fort(pin) ) {
      return u4_stub;
    }
    else {
      u4_nub nub;

      if ( (nub = u4_open_nub(pin)) ) {
        return nub;
      }
      else {
        if ( u4_pin_is_atom(pin) ) {
          nub = _nub_pin_atom(pin);
        }
        else nub = _nub_pin_cell(pin);

        u4_open_nub(pin) = nub;
        return nub;
      }
    }
  }
}

/* u4_n_nib():
**
**   Return the nub of the nub of (noun).
*/
u4_nub
u4_n_nib(u4_noun noun)
{
  u4_xw xw_nub = u4_n_nub(noun);

  return u4_n_nub(u4_cod_in(xw_nub));
}

/* u4_n_true():
**
**   Return 1 if (noun) is 0, 0 if (noun) is 1.  Otherwise, trip.
*/
u4_t
u4_n_true(u4_noun noun)
{
  if ( u4_n_eq(u4_noun_0, noun) ) {
    return 1;
  }
  else if ( u4_n_eq(u4_noun_1, noun) ) {
    return 0;
  }
  else return u4_trip;
}

/* u4_n_snip_():
**
**   Return nock(b (0 a)), or u4_bull if there is no such.
*/
u4_noun
u4_n_snip_(u4_atom a,
           u4_noun b)
{
  u4_st st = (u4_a_bin(a, 0) - 1);
  u4_pt i;
  mpz_t mp_a;

  u4_a_gmp(a, mp_a);

  for ( i=0; i < st; i++ ) {
    u4_st st_at = (st - (i + 1));

    if ( u4_n_atom(b) ) {
      mpz_clear(mp_a);

      return u4_bull;
    }
    else {
      if ( (mpz_tstbit(mp_a, st_at) == 0) ) {
        b = u4_ch(b);
      } else {
        b = u4_ct(b);
      }
    }
  }
  mpz_clear(mp_a);
  return b;
}

/* u4_a_bin(): 
**
**   Return the size of (atom) in bits, rounded up to
**   (1 << gt). 
**
**   For example, (gt = 3) returns the size in bytes.
*/
u4_st
u4_a_bin(u4_atom atom,
         u4_gt   gt)
{
  u4_sw sw_atom;
  u4_xw xw_last;
  u4_sw sw_rest;

  if ( u4_noun_is_cod(atom) ) {
    xw_last = u4_cod_out(atom);
    sw_rest = 0;
    sw_atom = xw_last ? 1 : 0;
  } 
  else {
    u4_pin pin_atom = atom;

    if ( u4_pin_is_cell(pin_atom) ) {
      return u4_trip;
    }
    else if ( u4_pin_is_fort(pin_atom) ) {
      return u4_stub;
    } 
    else {
      sw_atom = u4_open_atom_sw(pin_atom);
      xw_last = u4_open_atom_xw(pin_atom, (sw_atom - 1));
      sw_rest = (sw_atom - 1);
    }
  }
 
  switch ( gt ) {
    case 0:
    case 1:
    case 2: {
      u4_st st_rest = (sw_rest << 5);
      u4_st st_last = u4_word_bits(xw_last);
      u4_st st = (st_rest + st_last);

      return u4_bblock(st, gt);
    }
    case 3: {
      u4_sb sb_rest = (sw_rest << 2);
      u4_sb sb_last = u4_word_bytes(xw_last);
      u4_sb sb = (sb_rest + sb_last);

      return sb;
    }
    case 4: {
      u4_sh sh_rest = (sw_rest << 1);
      u4_sh sh_last = u4_word_halves(xw_last);
      u4_sh sh = (sh_rest + sh_last);

      return sh;
    }
    default: {
      return u4_bblock(sw_atom, (gt - 5));
    }
  }
}

/* u4_a_bit():
**
**   Return bit (pt) of (atom).
*/
u4_t
u4_a_bit(u4_atom atom,
         u4_pt   pt)
{
  if ( u4_noun_is_cod(atom) ) {
    if ( pt >= 31 ) {
      return 0;
    }
    else return (1 & (u4_cod_out(atom) >> pt));
  }
  else {
    u4_pin pin_atom = atom;

    if ( u4_pin_is_cell(pin_atom) ) {
      return u4_trip;
    }
    else if ( u4_pin_is_fort(pin_atom) ) {
      return u4_stub;
    } 
    else {
      u4_pw pw = (pt >> 5);
      u4_hw hw = (pt & 31);
      {
        u4_sw sw_atom = u4_open_atom_sw(pin_atom);

        if ( pw >= sw_atom ) {
          return 0;
        }
        else return (1 & (u4_open_atom_xw(pin_atom, pw) >> hw));
      }
    }
  }
}

/* u4_a_byte():
**
**   Return byte (pb) of (atom).
*/
u4_xb
u4_a_byte(u4_atom atom,
          u4_pb   pb)
{
  u4_pw  pw = (pb >> 2);
  u4_hbw hbw = (pb & 3);
  {
    u4_xw xw = u4_a_word(atom, pw);
    u4_xb xb = (255 & (xw >> (8 * hbw)));

    return xb;
  }
}

/* u4_a_word():
**
**   Return word (pw) of (atom).
*/
u4_xw
u4_a_word(u4_atom atom,
          u4_pw   pw)
{
  if ( u4_noun_is_cod(atom) ) {
    if ( pw != 0 ) {
      return 0;
    }
    else return u4_cod_out(atom);
  }
  else {
    u4_pin pin_atom = atom;

    if ( u4_pin_is_cell(pin_atom) ) {
      return u4_trip;
    } 
    else if ( u4_pin_is_fort(pin_atom) ) {
      return u4_stub;
    } 
    else {
      u4_sw sw_atom = u4_open_atom_sw(pin_atom);

      if ( pw >= sw_atom ) {
        return 0;
      }
      else return u4_open_atom_xw(pin_atom, pw);
    }
  }
}

/* u4_a_words():
**
**   Copy words from (atom) into (xw), starting at (pw)
**   and continuing for (sw).
**
**   (xw) must be of length (sw).
*/
void
u4_a_words(u4_atom atom,
           u4_xw   *xw,
           u4_pw   pw,
           u4_sw   sw)
{
  if ( !sw ) {
    if ( u4_n_cell(atom) ) {
      u4_trip;
    }
  }
  else {
    u4_i i;

    if ( u4_noun_is_cod(atom) ) {
      u4_xw xw_atom = u4_cod_out(atom);

      if ( pw == 0 ) {
        *xw = xw_atom;
        xw++;
        sw--;
      }

      for ( i=0; i < sw; i++ ) {
        xw[i] = 0;
      }
    }
    else {
      u4_pin pin_atom = atom;

      if ( u4_pin_is_cell(pin_atom) ) {
        u4_trip;
      }
      else if ( u4_pin_is_fort(pin_atom) ) {
        u4_stub;
      } 
      else {
        u4_sw sw_atom = u4_open_atom_sw(pin_atom);
        
        if ( pw >= sw_atom ) {
          for ( i=0; i < sw; i++ ) {
            xw[i] = 0;
          }
        }
        else {
          if ( (pw + sw) <= sw_atom ) {
            for ( i=0; i < sw; i++ ) {
              xw[i] = u4_open_atom_xw(pin_atom, (pw + i));
            }
          }
          else {
            u4_sw sw_out = (pw + sw) - sw_atom;
            u4_sw sw_in  = (sw - sw_out);

            for ( i=0; i < sw_in; i++ ) {
              xw[i] = u4_open_atom_xw(pin_atom, (pw + i));
            }
            for ( i=0; i < sw_out; i++ ) {
              xw[sw_in + i] = 0;
            }
          }
        }
      }
    }
  }
}

/* u4_a_bytes(): 
**
**   Copy bytes from (atom) into (xb), starting at (pb)
**   and continuing for (sb).
**
**   (xb) must be of length (sb).
*/
void
u4_a_bytes(u4_atom atom,
           u4_xb   *xb,
           u4_pb   pb,
           u4_sb   sb)
{
  if ( !sb ) {
    if ( u4_n_cell(atom) ) {
      u4_trip;
    }
  }
  else {
    u4_i i;

    if ( u4_noun_is_cod(atom) ) {
      u4_xw xw_atom = u4_cod_out(atom);

      for ( i=0; i < sb; i++ ) {
        if ( (pb + i) >= 4 ) {
          xb[i] = 0;
        }
        else {
          xb[i] = 255 & (xw_atom >> (8 * (pb + i)));
        }
      }
    }
    else {
      u4_pin pin_atom = atom;

      if ( u4_pin_is_cell(pin_atom) ) {
        u4_trip;
      }
      else if ( u4_pin_is_fort(pin_atom) ) {
        u4_stub;
      } 
      else {
        u4_sw sw_atom = u4_open_atom_sw(pin_atom);

        /* Efficiency: hand-coding may help.
        */
        for ( i=0; i < sb; i++ ) {
          u4_pw  pw_atom  = ((pb + i) >> 2);
          u4_hbw hbw_atom = ((pb + i) & 3);

          if ( pw_atom >= sw_atom ) {
            xb[i] = 0;
          }
          else {
            u4_xw xw_atom = u4_open_atom_xw(pin_atom, pw_atom);
            u4_xb xb_atom = (255 & (xw_atom >> (8 * hbw_atom)));

            xb[i] = xb_atom;
          }
        }
      }
    }
  }
}

/* u4_a_bits(): 
**
**   Xor bits from (atom) into (xw), starting at (hw) in
**   (xw[0]), reading from (pt) for (st).
**
**   (xw) must be of length (u4_bblock(hw + st, 5)).
*/
void
u4_a_bits(u4_atom atom,
          u4_xw   *xw,
          u4_hw   hw,
          u4_pt   pt,
          u4_st   st)
{
  u4_stub;
}

/* u4_a_gmp():
**
**   Copy (atom) into (mp).
**
**   The caller must free (mp) with mpz_clear, or equivalent.
*/
void
u4_a_gmp(u4_atom atom,
         mpz_t   mp)
{
  if ( u4_noun_is_cod(atom) ) {
    u4_xw xw_atom = u4_cod_out(atom);

    mpz_init_set_ui(mp, xw_atom);
  }
  else {
    u4_pin pin_atom = atom;

    if ( u4_pin_is_cell(pin_atom) ) {
      u4_trip;
    }
    else if ( u4_pin_is_fort(pin_atom) ) {
      u4_stub;
    } 
    else {
      u4_sw sw_atom = u4_open_atom_sw(pin_atom);

      if ( sw_atom >> 27 ) {
        u4_trip;
      }
      else {
        u4_st st_atom = (sw_atom << 5);

        /* Efficiency: horrible.  Import directly from cake.
        */
        mpz_init2(mp, st_atom);
        {
          u4_xw *xw = alloca(sw_atom << 2);
          u4_pw pw;

          for ( pw=0; pw < sw_atom; pw++ ) {
            xw[pw] = u4_open_atom_xw(pin_atom, pw);
          }
          mpz_import(mp, sw_atom, -1, 4, 0, 0, xw);
        }
      }
    }
  }
}

/* u4_a_wbail():
**
**   Produce (atom) as a 32-bit word, or bail with (code).
*/
u4_xw
u4_a_wbail(u4_atom           atom,
           enum u4_bail_code bail_code)
{
  if ( u4_n_cell(atom) ) {
    return u4_bail_out(bail_code);
  }
  else if ( u4_noun_is_cod(atom) ) {
    return u4_cod_out(atom);
  }
  else {
    u4_pin pin_atom = atom;

    if ( u4_pin_is_cell(pin_atom) ) {
      return u4_trip;
    }
    else if ( u4_pin_is_fort(pin_atom) ) {
      return u4_stub;
    } 
    else {
      u4_sw sw_atom = u4_open_atom_sw(pin_atom);

      if ( sw_atom == 1 ) {
        return u4_open_atom_xw(pin_atom, 0);
      }
      else return u4_bail_out(bail_code);
    }
  }
  return u4_stub;
}


/* u4_b_fork(): 
**
**   True iff, in (noun), (*p) and (*q) are a bush fork.
*/
u4_t
u4_b_fork(u4_noun noun,
          u4_noun *p,
          u4_noun *q)
{
  if ( u4_n_cell(noun) && u4_n_cell(u4_ch(noun)) ) {
    *p = u4_ch(noun);
    *q = u4_ct(noun);
    return 1;
  }
  return 0;
}

/* u4_b_p():
**
**   True iff (noun) is of the form (stem *p).
*/
u4_t 
u4_b_p(u4_noun noun,
       u4_atom stem,
       u4_noun *p)
{
  if ( u4_n_cell(noun) && u4_n_eq(u4_ch(noun), stem) ) {
    if (p) *p = u4_ct(noun);
    return 1;
  }
  return 0;
}

/* u4_b_pq():
**
**   True iff (noun) is of the form (stem *p *q).
*/
u4_t 
u4_b_pq(u4_noun noun,
        u4_atom stem,
        u4_noun *p,
        u4_noun *q)
{
  if ( u4_n_cell(noun) && u4_n_eq(u4_ch(noun), stem) ) {
    u4_noun noun_3 = u4_ct(noun);

    if ( u4_n_cell(noun_3) ) {
      if (p) *p = u4_ch(noun_3);
      if (q) *q = u4_ct(noun_3);
      return 1;
    }
  }
  return 0;
}

/* u4_b_pqr():
**
**   True iff (noun) is of the form (stem *p *q *r).
*/
u4_t 
u4_b_pqr(u4_noun noun,
         u4_atom stem,
         u4_noun *p,
         u4_noun *q,
         u4_noun *r)
{
  if ( u4_n_cell(noun) && u4_n_eq(u4_ch(noun), stem) ) {
    u4_noun noun_3 = u4_ct(noun);

    if ( u4_n_cell(noun_3) ) {
      u4_noun noun_7 = u4_ct(noun_3);

      if ( u4_n_cell(noun_7) ) {
        if (p) *p = u4_ch(noun_3);
        if (q) *q = u4_ch(noun_7);
        if (r) *r = u4_ct(noun_7);
        return 1;
      }
    }
  }
  return 0;
}

/* u4_b_pqrs():
**
**   True iff (noun) is of the form (stem *p *q *r *s).
*/
u4_t 
u4_b_pqrs(u4_noun noun,
          u4_atom stem,
          u4_noun *p,
          u4_noun *q,
          u4_noun *r, 
          u4_noun *s)
{
  if ( u4_n_cell(noun) && u4_n_eq(u4_ch(noun), stem) ) {
    u4_noun noun_3 = u4_ct(noun);

    if ( u4_n_cell(noun_3) ) {
      u4_noun noun_7 = u4_ct(noun_3);

      if ( u4_n_cell(noun_7) ) {
        u4_noun noun_15 = u4_ct(noun_7);

        if ( u4_n_cell(noun_15) ) {
          if (p) *p = u4_ch(noun_3);
          if (q) *q = u4_ch(noun_7);
          if (r) *r = u4_ch(noun_15);
          if (s) *s = u4_ct(noun_15);
          return 1;
        }
      }
    }
  }
  return 0;
}
