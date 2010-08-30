/* z/op/link.c
**
** This file is in the public domain.
*/

#ifdef  U3_ZN_FORGE
/* _zn_forge_link(): install a link agent.
**
**   lid: cap at termination
**   mat: saved mat for departure
**   lip: cap at departure
**   dep: link formula.
*/
static inline void
_zn_forge_link(u3_z   z,
               u3_ray lid_ray,
               u3_ray mat_ray,
               u3_ray lip_ray,
               u3_fox dep)
{
  u3_ray zos_ray;

  zos_ray = _zn_push_forge(z, link);
  *_zn_forge(z, zos_ray, link, c.ger_op) = c3__link;
  *_zn_forge(z, zos_ray, link, c.poq_ray) = z->n.lab_ray;
  *_zn_forge(z, zos_ray, link, c.lid_ray) = lid_ray;

  *_zn_forge(z, zos_ray, link, r.mat_ray) = mat_ray;
  *_zn_forge(z, zos_ray, link, r.lip_ray) = lip_ray;

  *_zn_forge(z, zos_ray, link, s.dep) = dep;

  z->n.lab_ray = zos_ray;
}
#endif  // U3_ZN_FORGE

#ifdef  U3_ZN_OP
# define _zn_bip_link(field) *_zn_anvil(z, bip_ray, link, field)

  case c3__link: {
    _zn_retreat(z, _zn_bip_link(f.r.mat_ray));
    {
      u3_ray lid_ray = _zn_bip_link(f.c.lid_ray);
      u3_ray lip_ray = _zn_bip_link(f.r.lip_ray);
      u3_fox dep     = _zn_bip_link(f.s.dep);
      u3_fox gus     = _zn_bip_link(d.gus);
#if 1
      if ( (lid_ray != lip_ray) && (lip_ray != z->l.cap_ray) ) {
        /* Tail optimization.
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
        ** whether it can be discarded *before* this link completion.
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
        ** Without tail optimization, we cannot loop without leaking.
        **
        ** Note that both detecting and applying this optimization has
        ** a cost of the same order as the size of A.  Moreover, if we
        ** fail to apply the optimization, we consume this same order of
        ** memory.  Consistency minimizes performance surprises.
        */
        if ( u3_yes == u3_lm_clear(z, gus, lid_ray, lip_ray) ) {
          /* Clear to tamp.
          */
          gus = u3_lm_tamp(z, gus, lid_ray, lip_ray);
        } 
        else {
          /* Not clear to tamp.
          ** 
          ** So that further attempts to tamp in this chain can work,
          ** the cook agent that completes the link must not tamp to
          ** [lid], but rather to the current cap.  Thus, to avoid
          ** leaking, we must install a drop agent to free.
          **
          ** Otherwise, the interpreter will detect a tail violation
          ** on every call, as it tries to tamp this entire region.
          ** It will thus fail to tamp, and leak, when it should be
          ** tamping on every call but the first.
          */
          _zn_forge_drop(z, lid_ray);
          lid_ray = z->l.cap_ray;
        }
      }
#endif
      _zn_forge_cook(z, lid_ray, gus, dep);
    }
    break;
  }

#endif  // U3_ZN_OP
