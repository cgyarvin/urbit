/* f/trac.c
**
** This file is in the public domain.
*/
#include "all.h"
#include <sys/time.h>
#include <signal.h>

  /**  Jet dependencies.  Minimize these.
  **/
#   define Pt4Y   k_230__a__b__c__d

    u2_noun
    j2_mcc(Pt4Y, by, has)(u2_wire, u2_noun a, u2_noun b);

    u2_noun
    j2_mcc(Pt4Y, by, put)(u2_wire, u2_noun a, u2_noun b, u2_noun c);

#   define _tx_has  j2_mcc(Pt4Y, by, has)
#   define _tx_put  j2_mcc(Pt4Y, by, put)


  /** Static sampling data structures, for signal handling use.
  **/
#   define U2_TRAC_SAMPLE_MAX 10000
    
    u2_loom_knot  _tx_knots[U2_TRAC_SAMPLE_MAX];
    u2_loom_knot* _tx_top_k;
    u2_ray        _tx_rac_r;
    c3_w          _tx_knot_cur;
    c3_t          _tx_on;

    static u2_loom_knot*
    _tx_knot_new(void)
    {
      if ( _tx_knot_cur == U2_TRAC_SAMPLE_MAX ) {
        return 0;
      } else {
        u2_loom_knot *new_k = &_tx_knots[_tx_knot_cur];

        _tx_knot_cur++;
        return new_k;
      }
    }

    static u2_loom_knot*
    _tx_sample_in(u2_noun don)
    {
      if ( u2_nul == don ) {
        _tx_top_k->fin_w += 1;
        return _tx_top_k;
      }
      else {
        u2_noun       hed   = u2_h(don);
        c3_c          hed_c[32];
        u2_loom_knot* par_k = _tx_sample_in(u2_t(don));
        u2_loom_knot* dis_k;

        if ( (0 == par_k) && (u2_no == u2_stud(hed)) ) {
          return 0;
        }
        u2_bytes(0, 32, (c3_y *)hed_c, hed);
        hed_c[31] = 0;

        for ( dis_k = par_k->fam_k; dis_k; dis_k = dis_k->nex_k ) {
          //  linear search, should be fine in normal cases
          //
          if ( !strcmp(hed_c, dis_k->lic_c) ) {
            dis_k->fin_w += 1;
            return dis_k;
          }
        }
        if ( 0 == (dis_k = _tx_knot_new()) ) {
          return 0;
        } else {
          strcpy(dis_k->lic_c, hed_c);
          dis_k->fin_w = 1;
          dis_k->fam_k = 0;
          dis_k->nex_k = par_k->fam_k;
          par_k->fam_k = dis_k;

          return dis_k;
        }
      }
    }
    static void
    _tx_sample(c3_i x)
    {
      c3_assert(_tx_on == 1);
      _tx_sample_in(u2_trac_at(_tx_rac_r, duz.don));
    }

/* u2_tx_samp_on(): turn profile sampling on, clear count.
*/
static void
_tx_samp_on(u2_ray rac_r)
{
  c3_assert(_tx_on == 0);
  c3_assert(_tx_knot_cur == 0);
  
  _tx_on = 1;
  _tx_rac_r = rac_r;
  {
    struct itimerval itm_v;
    struct sigaction sig_s;

    sig_s.__sigaction_u.__sa_handler = _tx_sample;
    sig_s.sa_mask = 0;
    sig_s.sa_flags = 0;

    sigaction(SIGVTALRM, &sig_s, 0);

    itm_v.it_interval.tv_sec = 0;
    itm_v.it_interval.tv_usec = 10;
    itm_v.it_value = itm_v.it_interval;

    setitimer(ITIMER_VIRTUAL, &itm_v, 0);
  }
}

/* _tx_samp_off(): turn profile sampling off.
*/
static void
_tx_samp_off(u2_ray rac_r)
{
  c3_assert(_tx_on == 1);
  struct sigaction sig_s;
  struct itimerval itm_v;

  itm_v.it_interval.tv_sec = 0;
  itm_v.it_interval.tv_usec = 0;
  itm_v.it_value = itm_v.it_interval;

  setitimer(ITIMER_VIRTUAL, &itm_v, 0);

  sig_s.__sigaction_u.__sa_handler = SIG_DFL;
  sig_s.sa_mask = 0;
  sig_s.sa_flags = 0;

  sigaction(SIGVTALRM, &sig_s, 0);
}

/* _tx_samples_in(): sample list.
*/
static u2_weak
_tx_samples_in(u2_wire wir_r, u2_loom_knot *fam_k)
{
  if ( 0 == fam_k ) {
    return u2_nul;
  } else {
    return u2_rc
      (wir_r, u2_rt(wir_r, u2_rl_string(wir_r, fam_k->lic_c),
                           u2_rl_words(wir_r, 1, &fam_k->fin_w),
                           _tx_samples_in(wir_r, fam_k->fam_k)),
              _tx_samples_in(wir_r, fam_k->nex_k));
  }
}

/* _tx_samples(): dump samples.
*/
static u2_weak                                                    //  produce
_tx_samples(u2_wire wir_r)
{
  u2_loom_knot *not_k = _tx_top_k;

  return u2_rc(wir_r, u2_rl_words(wir_r, 1, &not_k->fin_w),
                         _tx_samples_in(wir_r, not_k->fam_k));
}

/* _tx_d(): noun from c3_d.
*/
static u2_weak
_tx_d(u2_wire wir_r, c3_d dat_d)
{
  c3_w dat_w[2];

  dat_w[0] = (dat_d & 0xffffffff);
  dat_w[1] = (dat_d >> 32ULL);

  return u2_rl_words(wir_r, 2, dat_w);
}

/* u2_tx_events(): produce event list, including counts.
*/
static u2_noun                                                    //  produce
_tx_events(u2_wire wir_r, 
           u2_noun cot)                                           //  retain
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);
  u2_noun str, val, vez;

  cot = u2_rx(wir_r, cot);

  /* sys-hops
  */
  {
    if ( u2_none == (str = u2_rl_string(wir_r, "sys-hops")) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, u2_trac_be(rac_r, c3_d, sys.hop_d))) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-jets
  */
  {
    if ( u2_none == (str = u2_rl_string(wir_r, "sys-jets")) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, u2_trac_be(rac_r, c3_d, sys.jet_d))) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-tests
  */
  {
    if ( u2_none == (str = u2_rl_string(wir_r, "sys-tests")) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, u2_trac_be(rac_r, c3_d, sys.tes_d))) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-nods
  */
  {
    if ( u2_none == (str = u2_rl_string(wir_r, "sys-nods")) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, u2_trac_be(rac_r, c3_d, sys.nod_d))) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-cstack
  */
  {
    c3_ds cas_ds      = u2_trac_be(rac_r, c3_ds, sys.cas_ds);
    c3_d cas_d        = (cas_ds < 0ULL) ? -(cas_ds) : cas_ds;
    const c3_c* str_c = (cas_ds < 0ULL) ? "sys-kcatsc" : "sys-cstack";

    if ( u2_none == (str = u2_rl_string(wir_r, str_c)) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, cas_d)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-memory
  */
  {
    c3_ds mey_ds      = u2_trac_be(rac_r, c3_ds, sys.mey_ds);
    c3_d mey_d        = (mey_ds < 0ULL) ? -(mey_ds) : mey_ds;
    const c3_c* str_c = (mey_ds < 0ULL) ? "sys-yromem" : "sys-memory";

    if ( u2_none == (str = u2_rl_string(wir_r, str_c)) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, mey_d)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-basket
  */
  {
    c3_ds bek_ds      = u2_trac_be(rac_r, c3_ds, sys.bek_ds);
    c3_d bek_d        = (bek_ds < 0ULL) ? -(bek_ds) : bek_ds;
    const c3_c* str_c = (bek_ds < 0ULL) ? "sys-teksab" : "sys-basket";

    if ( u2_none == (str = u2_rl_string(wir_r, str_c)) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = _tx_d(wir_r, bek_d)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  /* sys-time
  */
  {
    struct timeval tv;
    c3_w sec_w = u2_trac_at(rac_r, sys.sec_w);
    c3_w usc_w = u2_trac_at(rac_r, sys.usc_w);
    c3_w ums_w;
    c3_d old_d, new_d;

    old_d = sec_w;
    old_d *= 1000000ULL;
    old_d += usc_w;

    gettimeofday(&tv, 0);
    new_d = tv.tv_sec;
    new_d *= 1000000ULL;
    new_d += tv.tv_usec;

    ums_w = (c3_w) (((new_d - old_d) + 999ULL) / 1000ULL);

    if ( u2_none == (str = u2_rl_string(wir_r, "sys-hops")) ) {
      u2_rz(wir_r, cot);
      return u2_none;
    }
    if ( u2_none == (val = u2_rl_words(wir_r, 1, &ums_w)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); return u2_none;
    }
    if ( u2_none == (vez = _tx_put(wir_r, cot, str, val)) ) {
      u2_rz(wir_r, cot); u2_rz(wir_r, str); u2_rz(wir_r, val); return u2_none;
    }
    u2_rz(wir_r, cot);
    cot = vez;
  }
  return cot;
}

/* u2_tx_init(): initialize state.
*/
u2_ray
u2_tx_init(u2_wire wir_r)
{
  u2_ray rac_r = u2_rl_ralloc(wir_r, c3_wiseof(u2_loom_trac));

  u2_trac_at(rac_r, cor.deb) = u2_no;
  u2_trac_at(rac_r, cor.pro) = u2_no;

  return rac_r;
}

/* u2_tx_open(): open tracing.
*/
void
u2_tx_open(u2_wire wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_at(rac_r, wer.ryp) = u2_nul;
  u2_trac_at(rac_r, duz.don) = u2_nul;
  u2_trac_at(rac_r, duz.cot) = u2_nul;

  u2_trac_be(rac_r, c3_d, sys.hop_d) = 0;
  u2_trac_be(rac_r, c3_d, sys.jet_d) = 0;
  u2_trac_be(rac_r, c3_d, sys.tes_d) = 0;
  u2_trac_be(rac_r, c3_d, sys.nod_d) = 0;

  u2_trac_be(rac_r, c3_ds, sys.cas_ds) = 0;
  u2_trac_be(rac_r, c3_ds, sys.mey_ds) = 0;
  u2_trac_be(rac_r, c3_ds, sys.bek_ds) = 0;

  {
    struct timeval tv;

    gettimeofday(&tv, 0);
    u2_trac_at(rac_r, sys.sec_w) = tv.tv_sec;
    u2_trac_at(rac_r, sys.usc_w) = tv.tv_usec;
  }

  if ( u2_yes == u2_trac_at(rac_r, cor.pro) ) {
    _tx_samp_on(wir_r);
  }
}

/* u2_tx_done(): produce a profile slab to render.  Free internal state.
*/ 
u2_noun                                                           //  produce
u2_tx_done(u2_wire wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);
  u2_noun p_sab = u2_nul, q_sab = u2_nul, r_sab = u2_nul;

  _tx_samp_off(rac_r);

  if ( u2_yes != u2_trac_at(rac_r, cor.deb) ) {
    p_sab = u2_rx(wir_r, u2_trac_at(rac_r, wer.ryp));
  }
  if ( u2_yes != u2_trac_at(rac_r, cor.pro) ) {
    q_sab = _tx_events(wir_r, u2_trac_at(rac_r, duz.cot));
    r_sab = _tx_samples(wir_r);

    if ( u2_none == q_sab ) q_sab = u2_nul;
    if ( u2_none == r_sab ) r_sab = u2_nul;
  }

  u2_rz(wir_r, u2_trac_at(rac_r, wer.ryp));
  u2_rz(wir_r, u2_trac_at(rac_r, duz.don));
  u2_rz(wir_r, u2_trac_at(rac_r, duz.cot));

  return u2_bt(wir_r, p_sab, q_sab, r_sab);
}

/* u2_tx_do_debug(): set debug flag.  Return old value.
*/
u2_flag 
u2_tx_do_debug(u2_ray wir_r, u2_flag lag)
{
  u2_ray  rac_r = u2_wire_rac_r(wir_r);
  u2_flag old   = u2_trac_at(rac_r, cor.deb);

  u2_trac_at(rac_r, cor.deb) = lag;
  return old;
}


/* u2_tx_in_debug(): get debug flag.
*/
u2_flag 
u2_tx_in_debug(u2_ray wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  return u2_trac_at(rac_r, cor.deb);
}

/* u2_tx_do_profile(): set profile flag.  Return old value.
*/
u2_flag 
u2_tx_do_profile(u2_ray wir_r, u2_flag lag)
{
  u2_ray  rac_r = u2_wire_rac_r(wir_r);
  u2_flag old   = u2_trac_at(rac_r, cor.pro);

  u2_trac_at(rac_r, cor.pro) = lag;
  return old;
}

/* u2_tx_in_profile(): get profile flag.
*/
u2_flag 
u2_tx_in_profile(u2_ray wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  return u2_trac_at(rac_r, cor.pro);
}

/* u2_tx_did_hop(): record nock engine step.
*/
void 
u2_tx_did_hop(u2_wire wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_d, sys.hop_d) += 1;
}

/* u2_tx_did_jet(): record jet invocation.
*/
void u2_tx_did_jet(u2_wire wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_d, sys.jet_d) += 1;
}

void u2_tx_did_tes(u2_wire wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_d, sys.jet_d) += 1;
}

void u2_tx_did_nod(u2_wire wir_r)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_d, sys.jet_d) += 1;
}

/* u2_tx_did_act(): record user actions.
*/
void 
u2_tx_did_act(u2_wire wir_r, 
              u2_noun did)                                        //  retain
{
  u2_ray  rac_r = u2_wire_rac_r(wir_r);
  u2_noun cot   = u2_trac_at(rac_r, duz.cot);
  u2_noun zot;
  u2_noun gox;

  if ( u2_none == (gox = _tx_has(wir_r, cot, did)) ) {
    zot = _tx_put(wir_r, cot, did, _1);
  } else {
    zot = _tx_put(wir_r, cot, did, u2_rl_vint(wir_r, gox));
  }
  if ( u2_none != zot ) {
    u2_rz(wir_r, cot);
    u2_trac_at(rac_r, duz.cot) = zot;
  }
}

/* u2_tx_add_cas(): record signed change in C stack watermark.
*/
void u2_tx_add_cas(u2_wire wir_r, c3_ws add_ws)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_ds, sys.cas_ds) += add_ws;
}

/* u2_tx_add_mey(): record signed change in memory watermark.
*/
void u2_tx_add_mey(u2_wire wir_r, c3_ws add_ws)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_ds, sys.mey_ds) += add_ws;
}

/* u2_tx_add_bek(): record signed change in memory watermark.
*/
void u2_tx_add_bek(u2_wire wir_r, c3_ws add_ws)
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);

  u2_trac_be(rac_r, c3_ds, sys.bek_ds) += add_ws;
}

/* u2_tx_task_in(): enter a task for profiling purposes.
**
** u2_yes iff the task is not already in the stack.
*/
u2_flag
u2_tx_task_in(u2_wire wir_r, 
              u2_noun tak)                                        //  retain
{
  u2_ray rac_r = u2_wire_rac_r(wir_r);
  u2_noun don = u2_trac_at(rac_r, duz.don);
  u2_noun dim;

  /* Test if we're already doing this.
  */
  {
    dim = don;

    while ( don != u2_nul ) {
      if ( u2_yes == u2_sing(tak, u2_h(don)) ) {
        return u2_no;
      }
      don = u2_t(don);
    }
  }

  dim = u2_rc(wir_r, u2_rx(wir_r, tak), u2_rx(wir_r, don));
  if ( u2_none == dim ) {
    return u2_no;
  }
  else {
    u2_rz(wir_r, don);
    u2_trac_at(rac_r, duz.don) = dim;

    return u2_yes;
  }
}

/* u2_tx_task_out(): leave a task for profiling purposes.
*/
void
u2_tx_task_out(u2_wire wir_r)
{
  u2_ray  rac_r = u2_wire_rac_r(wir_r);
  u2_noun don = u2_trac_at(rac_r, duz.don);

  c3_assert(u2_nul != don);
}

/* u2_tx_log(): log a wall.  Discouraged.
*/
void
u2_tx_log(u2_wire wir_r, 
          u2_noun wal);                                           //  retain

/* u2_tx_warn(): report a warning by internal file and line.
*/
void
u2_tx_warn(u2_ray      wir_r,
           const c3_c* fil_c,
           c3_w        lyn_w)
{
}
