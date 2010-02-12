/* c/vere.c
**
** This file is in the public domain.
*/
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include "z/public.h"

  /** Forward declarations.
  **/
    static uz_noun
    _vere_source(uz_machine, uz_noun);

/* _vere_print(): print a clam [type noun]
*/
static void
_vere_print(uz_machine mac,
            const char *cap,
            uz_noun    fig)
{
  uz_f_print_type(mac, cap, uz_ch(mac, fig));
  uz_f_print(mac, cap, uz_ct(mac, fig));
}

/* _vere_source_crib(): load a crib source.
*/
static uz_noun
_vere_source_crib(uz_machine mac,
                  uz_noun    lar)
{
  uz_noun i_lar  = uz_ch(mac, lar);
  uz_noun t_lar  = uz_ct(mac, lar);
  uz_noun pi_lar = uz_ch(mac, i_lar);
  uz_noun qi_lar = uz_ct(mac, i_lar);
  uz_noun fig    = _vere_source(mac, qi_lar);
  uz_noun p_fig  = uz_ch(mac, fig);
  uz_noun q_fig  = uz_ct(mac, fig);

  if ( uz_n_eq(mac, 0, uz_ct(mac, lar)) ) {
    return uz_k_cell
      (mac, uz_k_trel(mac, uz_s4('c','r','i','b'), 
                           uz_k_cell(mac, pi_lar, p_fig), 
                           0),
            q_fig);
  }
  else {
    uz_noun pem   = _vere_source_crib(mac, t_lar);
    uz_noun p_pem = uz_ch(mac, pem);
    uz_noun q_pem = uz_ct(mac, pem);

    return uz_k_cell
      (mac, uz_k_trel(mac, uz_s4('c','r','i','b'), 
                           uz_k_cell(mac, pi_lar, p_fig),
                           uz_ct(mac, p_pem)),
            uz_k_cell(mac, q_fig, q_pem));
  }
}

/* _vere_source_file(): load a file source.
*/
static uz_noun
_vere_source_file(uz_machine mac,
                  uz_noun    unx)
{
  return uz_k_file(mac, unx);
}

/* _vere_source_atom(): load an atom source.
*/
static uz_noun
_vere_source_atom(uz_machine mac,
                  uz_noun    viq)
{
  uz_noun p_viq;

  if ( uz_c_p(mac, viq, uz_s4('p','a','l','t'), &p_viq) ) {
    return uz_k_cell(mac, uz_s4('a','t','o','m'), p_viq);
  }
  else if ( uz_c_p(mac, viq, uz_s4('p','r','e','t'), &p_viq) ) {
    return uz_k_cell
      (mac, uz_k_cell(mac, uz_s4('c','u','b','e'), p_viq), p_viq);
  }
  else return uz_x_tank(mac);
}

/* _vere_source_exp(): load an expression source.
*/
static uz_noun
_vere_source_exp(uz_machine mac,
                 uz_noun    gen)
{
  return uz_g_express(mac, gen);
}

/* _vere_source(): load a source.
*/
static uz_noun
_vere_source(uz_machine mac,
             uz_noun    dim)
{
  uz_noun p_dim;

  if ( uz_c_p(mac, dim, uz_s4('m','a','l','g'), &p_dim) ) {
    return _vere_source_crib(mac, p_dim);
  }
  else if ( uz_c_p(mac, dim, uz_s4('d','r','u','n'), &p_dim) ) {
    return _vere_source_file(mac, p_dim);
  }
  else if ( uz_c_p(mac, dim, uz_s4('n','a','r','v'), &p_dim) ) {
    return _vere_source_atom(mac, p_dim);
  }
  else if ( uz_c_p(mac, dim, uz_s4('t','r','i','b'), &p_dim) ) {
    return _vere_source_exp(mac, p_dim);
  }
  else return uz_x_tank(mac);
}

/* _vere_filter_watt_lame(): apply a lame filter.
*/
static uz_noun
_vere_filter_watt_lame(uz_machine mac,
                       uz_noun    fig,
                       uz_noun    gar)
{
  uz_noun src = uz_k_file(mac, gar);
  uz_noun gen = uz_t_watt(mac, src);

  return uz_g_lame(mac, fig, gen);
}

/* _vere_filter_watt_program(): apply a program filter.
*/
static uz_noun
_vere_filter_watt_program(uz_machine mac,
                          uz_noun    fig,
                          uz_noun    fev)
{
  uz_noun src = uz_k_file(mac, fev);
  uz_noun gen = uz_t_watt(mac, src);

  return uz_g_compute(mac, fig, gen);
}

/* _vere_filter_watt_exp():
*/
static uz_noun
_vere_filter_watt_exp(uz_machine mac,
                      uz_noun    fig,
                      uz_noun    gen)
{
  return uz_g_compute(mac, fig, gen);
}

/* _vere_filter_nock_exp():
*/
static uz_noun
_vere_filter_nock_exp(uz_machine mac,
                      uz_noun    fig,
                      uz_noun    fol)
{
  return uz_k_cell
    (mac, uz_s4('b','l','u','r'), uz_k_nock(mac, uz_ct(mac, fig), fol));
}

/* _vere_filter_nock_program(): apply a program filter.
*/
static uz_noun
_vere_filter_nock_program(uz_machine mac,
                          uz_noun    fig,
                          uz_noun    nar)
{
  uz_noun src = uz_k_file(mac, nar);
  uz_noun fol = uz_t_hume(mac, src);

  return _vere_filter_nock_exp(mac, fig, fol);
}

/* _vere_filter(): apply a transformation filter.
**
**    fig: [tip nun] - source
**    kal: filter    - transformation filter
*/
static uz_noun
_vere_filter(uz_machine mac,
             uz_noun    fig,
             uz_noun    kal)
{
  uz_noun p_kal;

  if ( uz_c_p(mac, kal, uz_s4('z','e','c','t'), &p_kal) ) {
    return _vere_filter_watt_exp(mac, fig, p_kal);
  }
  else if ( uz_c_p(mac, kal, uz_s4('g','a','m','p'), &p_kal) ) {
    return _vere_filter_watt_program(mac, fig, p_kal);
  }
  else if ( uz_c_p(mac, kal, uz_s4('l','a','m','e'), &p_kal) ) {
    return _vere_filter_watt_lame(mac, fig, p_kal);
  }
  else if ( uz_c_p(mac, kal, uz_s4('b','l','a','n'), &p_kal) ) {
    return _vere_filter_nock_exp(mac, fig, p_kal);
  }
  else if ( uz_c_p(mac, kal, uz_s4('z','o','r','k'), &p_kal) ) {
    return _vere_filter_nock_program(mac, fig, p_kal);
  }
  else return uz_x_tank(mac);
}

/* _vere_transform(): transform a source.
**
**    fig: [tip nun] - source
**    gar: *filter   - transformation pipeline, first to last
*/
static uz_noun
_vere_transform(uz_machine mac,
                uz_noun    fig,
                uz_noun    gar)
{
  if ( uz_n_eq(mac, 0, gar) ) {
    return fig;
  }
  else {
    return _vere_transform
      (mac, _vere_filter(mac, fig, uz_ch(mac, gar)), uz_ct(mac, gar));
  }
}

/* _vere_construct(): process construction.  Produces [tip nun].
*/
static uz_noun
_vere_construct(uz_machine mac,
                uz_noun    pel)
{
  return _vere_transform
    (mac, _vere_source(mac, uz_ch(mac, pel)), uz_ct(mac, pel));
}

/* _vere_command(): process command.
*/
static void
_vere_command(uz_machine mac,
              uz_noun    fex)
{
  uz_noun p_fex, q_fex;

  if ( uz_c_pq(mac, fex, uz_s4('g','r','i','k'), &p_fex, &q_fex) ) {
    printf(">: not supported\n");
  }
  else if ( uz_c_pq(mac, fex, uz_s4('c','o','r','m'), &p_fex, &q_fex) ) {
    printf("=: not supported\n");
  }
  else if ( uz_c_p(mac, fex, uz_s4('p','a','l','q'), &p_fex) ) {
    uz_shoe sho = uz_m_depart(mac);
    {
      uz_noun lon = _vere_construct(mac, p_fex);

      _vere_print(mac, 0, lon);
    }
    uz_m_retreat(mac, sho);
    uz_m_zap(mac);
  }
  else {
    printf("vere: strange command\n");
  }
}

/* vere_line(): process command line.
*/
void 
vere_line(uz_machine mac, 
          uz_noun lug)
{
  jmp_buf env;
  uz_noun wef;

  if ( (wef = setjmp(env)) ) {
    uint8_t str[5];

    str[4] = 0;
    uz_a_bytes(mac, 0, 4, str, wef);
    printf("[%s]\n", str);
  }
  else {
    uz_l_except(mac, env);
    {
      uz_noun fex = uz_t_vere(mac, lug);

      _vere_command(mac, fex);
    }
  }
}
