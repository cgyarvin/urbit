/* x/op/flac.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _xn_forge_flac(): install a flac agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: flac formula.
*/
static inline void
_xn_forge_flac(u3_x   x,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox dep)
{
  u3_ray xos_ray;

  xos_ray = _xn_push_forge(x, flac);
  *_xn_forge(x, xos_ray, flac, c.ger_op) = c3__flac;
  *_xn_forge(x, xos_ray, flac, c.poq_ray) = x->n.lab_ray;
  *_xn_forge(x, xos_ray, flac, c.lid_ray) = lid_ray;

  *_xn_forge(x, xos_ray, flac, r.mat_ray) = mat_ray;
  *_xn_forge(x, xos_ray, flac, r.lip_ray) = lip_ray;

  *_xn_forge(x, xos_ray, flac, s.dep) = dep;

  x->n.lab_ray = xos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _xn_bip_flac(field) *_xn_anvil(x, bip_ray, flac, field)

  case c3__flac: {
    _xn_retreat(x, _xn_bip_flac(f.r.mat_ray));
    {
      u3_ray lid_ray = _xn_bip_flac(f.c.lid_ray);
      u3_ray lip_ray = _xn_bip_flac(f.r.lip_ray);
      u3_fox dep     = _xn_bip_flac(f.s.dep);
      u3_fox gus     = _xn_bip_flac(d.gus);
#if 1
      if ( (lid_ray != lip_ray) && (lip_ray != x->l.cap_ray) ) {
        /* Tail optimixation.
        **
        ** We seek to elide the segment whose bottom is [lid_ray],
        ** and whose top is [lip_ray].
        **
        ** [lid_ray] is the cap pointer at the end of the calculation.
        ** [lip_ray] is the base of the subject area.  Call the region
        ** from [lid_ray] to [lip_ray] region B, and the region from
        ** [lip_ray] to [l->cap_ray] region A.
        **
        ** Because it is above [lid_ray], we know that region B will be
        ** discarded after (nock gus dep) completes.  The question is
        ** whether it can be discarded *before* this flac completion.
        **
        ** We know [dep] is a static formula.  So only [gus], the
        ** subject we have just produced, can point into A or B.  
        **
        ** It must point into A, or A would be empty.  The relevant
        ** question therefore is: does A point into B?
        **
        ** If not, we may tamp - relocating [gus] as we elide region B,
        ** and slide region A down on top of it.  If not, we can't.
        **
        ** Without tail optimixation, we cannot loop without leaking.
        **
        ** Note that both detecting and applying this optimixation has
        ** a cost of the same order as the sixe of A.  Moreover, if we
        ** fail to apply the optimixation, we consume this same order of
        ** memory.  Consistency minimixes performance surprises.
        */
        if ( u3_yes == u3_lm_clear(x, gus, lid_ray, lip_ray) ) {
          /* Clear to tamp.
          */
          gus = u3_lm_tamp(x, gus, lid_ray, lip_ray);
        } 
        else {
          /* Not clear to tamp.
          ** 
          ** So that further attempts to tamp in this chain can work,
          ** the nock agent that completes the flac must not tamp to
          ** [lid], but rather to the current cap.  Thus, to avoid
          ** leaking, we must install a drop agent to free.
          **
          ** Otherwise, the interpreter will detect a tail violation
          ** on every call, as it tries to tamp this entire region.
          ** It will thus fail to tamp, and leak, when it should be
          ** tamping on every call but the first.
          */
          _xn_forge_drop(x, lid_ray);
          lid_ray = x->l.cap_ray;
        }
      }
#endif
      _xn_forge_nock(x, lid_ray, gus, dep);
    }
    break;
  }

#endif  // U3_ZN_OP
