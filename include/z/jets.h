/* include/z/jets.h
**
** This file is in the public domain.
*/
  /** Jet definitions - generic include.
  ***
  ***   A wet jet is a gate jet for which a C function is defined.
  ***   A dry jet is one for which there is none.
  ***
  ***   For both, the declaration is (name source priority).
  **/
    _zj_wet(dec, "dec", 1)
    _zj_wet(eq,  "eq",  1)
    _zj_wet(inc, "inc", 1)
    _zj_wet(pat, "pat", 1)
    _zj_wet(tap, "tap", 1)
    _zj_wet(zip, "zip", 1)

    _zj_wet(add, "add", 2)
    _zj_wet(div, "div", 2)
    _zj_wet(gt,  "gt",  2)
    _zj_wet(gte, "gte", 2)
    _zj_wet(lt,  "lt",  2)
    _zj_wet(lte, "lte", 2)
    _zj_wet(mod, "mod", 2)
    _zj_wet(mul, "mul", 2)
    _zj_wet(sub, "sub", 2)

    _zj_wet(mug,  "mug",  5)
