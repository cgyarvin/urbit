/* include/plow.h
**
** This file is in the public domain.
*/
  /** Functions.
  ***
  *** These escape via jump buffer, which must be set.  Note also that
  *** they leak memory like crazy.
  **/
      u2_noun u2_fj_make(u2_ray wir_r, u2_noun sut, u2_noun gen);
      u2_noun u2_fj_play(u2_ray wir_r, u2_noun sut, u2_noun gen);
      u2_noun u2_fj_show(u2_ray wir_r, u2_noun sut, u2_noun gen);
      u2_noun u2_fj_pass(u2_ray wir_r, u2_noun sut, u2_noun gen);
      u2_noun u2_fj_shop(u2_ray wir_r, u2_noun sut, u2_noun gen);
      u2_noun u2_fj_wish(u2_ray wir_r, u2_noun sut, u2_noun gen);
      u2_noun u2_fj_mill(u2_ray wir_r, u2_noun sut, u2_noun gen);
