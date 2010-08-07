/* z/op/link.c
**
** This file is in the public domain.
*/
#   define _zn_bip_link(field) *_zn_anvil(z, ray_bip, link, field)

    /* c3__link: link to a static formula.
    */
      case c3__link: {
        _zn_retreat(z, _zn_bip_link(f.r.ray_mat));
        {
          u3_ray ray_lid = _zn_bip_link(f.c.ray_lid);
          u3_ray ray_lip = _zn_bip_link(f.r.ray_lip);
          u3_fox dep     = _zn_bip_link(f.s.dep);
          u3_fox gus     = _zn_bip_link(d.gus);
#if 1
          if ( (ray_lid != ray_lip) && (ray_lip != z->l.ray_cap) ) {
            /* Tail optimization.
            **
            ** We seek to elide the segment whose bottom is [ray_lid],
            ** and whose top is [ray_lip].
            **
            ** [ray_lid] is the cap pointer at the end of the calculation.
            ** [ray_lip] is the base of the subject area.  Call the region
            ** from [ray_lid] to [ray_lip] region B, and the region from
            ** [ray_lip] to [l->ray_cap] region A.
            **
            ** Because it is above [ray_lid], we know that region B will be
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
            ** Without tail optimization, nolt cannot loop without leaking.
            **
            ** Note that both detecting and applying this optimization has
            ** a cost of the same order as the size of A.  Moreover, if we
            ** fail to apply the optimization, we consume this same order of
            ** memory.  Consistency minimizes performance surprises.
            */
            if ( u3_yes == u3_lm_clear(z, gus, ray_lid, ray_lip) ) {
              /* Clear to tamp.
              */
              gus = u3_lm_tamp(z, gus, ray_lid, ray_lip);
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
              _zn_forge_drop(z, ray_lid);
              ray_lid = z->l.ray_cap;
            }
          }
#endif
          _zn_forge_cook(z, ray_lid, gus, dep);
        }
        break;
      }

