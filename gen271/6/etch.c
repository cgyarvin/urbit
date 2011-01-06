            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
      }
      case c3__face: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        } else { 
          return u2_bt
            (wir_r, c3__face, u2_bx(wir_r, p_sut), u2_bx(wir_r, giv));
        }
      }
      case c3__fork: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return j2_mby(Pit, eith)
            (wir_r, _etch_term(wir_r, van, p_sut, p_wer, giv),
                    _etch_term(wir_r, van, q_sut, p_wer, giv));
        }
      } 
      case c3__hold: {
        if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
          u2_noun pro = _etch_term(wir_r, van, fop, p_wer, giv);

          u2_rl_lose(wir_r, fop);
          return pro;
        }
      }
    }
  }

  static u2_noun
  _etch_frag(u2_wire wir_r,
             u2_noun van,
             u2_noun sut,
             u2_atom pi_per,
             u2_noun t_per,
             u2_noun gan)
  {
    u2_noun p_sut, q_sut, r_sut;

    if ( _1 == pi_per ) {
      return _etch_per(wir_r, van, sut, t_per, gan);
    }
    else {
      if ( u2_yes == u2_stud(sut) ) switch( sut ) {
        default: return u2_bl_bail(wir_r);

        case c3__blur: {
          u2_noun fop = u2_bt(wir_r, c3__cell, c3__blur, c3__blur);
          u2_noun pro = _etch_frag(wir_r, van, fop, pi_per, t_per, gan);

          u2_rl_lose(wir_r, fop);
          return pro;
        }
      } else switch( u2_h(sut) ) {
        default: return u2_bl_bail(wir_r);

        case c3__cell: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun tip = j2_mbc(Pit, cap)(wir_r, pi_per);
            u2_noun tap = j2_mbc(Pit, mas)(wir_r, pi_per);
            u2_noun pro;

            if ( _2 == tip ) {
              pro = u2_bt
                (wir_r, c3__cell, 
                       _etch_frag(wir_r, van, p_sut, tap, t_per, gan), 
                       u2_bx(wir_r, q_sut));
            }
            else {
              pro = u2_bt
                (wir_r, c3__cell, 
                        u2_bx(wir_r, p_sut),
                       _etch_frag(wir_r, van, q_sut, tap, t_per, gan));
            }
            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
        case c3__core: {
          if ( u2_no == u2_as_qual(sut, 0, &p_sut, &q_sut, &r_sut) ) {
            return u2_bl_bail(wir_r);
          } else {
            u2_noun tip = j2_mbc(Pit, cap)(wir_r, pi_per);
            u2_noun tap = j2_mbc(Pit, mas)(wir_r, pi_per);
            u2_noun pro;

            if ( _2 != tip ) {
              return u2_bl_bail(wir_r);
            } else {
              u2_noun gac = _etch_frag(wir_r, van, p_sut, tap, t_per, gan);
              u2_noun huq;

              if ( u2_yes == u2_stud(q_sut) ) switch ( q_sut ) {
                default: return u2_bl_bail(wir_r);

                case c3__blue: {
                  huq = u2_bc(wir_r, c3__gray, u2_bx(wir_r, p_sut));
                  break;
                }
                case c3__pink: {
                  huq = u2_bc(wir_r, c3__teal, u2_bx(wir_r, p_sut));
                  break;
                }
              }
              else huq = u2_bx(wir_r, q_sut);

              pro = u2_bq(wir_r, c3__core, gac, huq, u2_bx(wir_r, r_sut));
            }
            u2_rl_lose(wir_r, tap);
            return pro;
          }
        }
        case c3__cube: {
          p_sut = u2_t(sut);

          if ( u2_no == u2_dust(p_sut) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun fop = u2_bt(wir_r, c3__cell, 
                                       u2_bc(wir_r, c3__cube, u2_h(p_sut)),
                                       u2_bc(wir_r, c3__cube, u2_t(p_sut)));
            u2_noun pro = _etch_frag(wir_r, van, fop, pi_per, t_per, gan);

            u2_rl_lose(wir_r, fop);
            return pro;
          }
        }
        case c3__face: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          } else { 
            return u2_bt
              (wir_r, c3__face,
                      u2_bx(wir_r, p_sut), 
                      _etch_frag(wir_r, van, q_sut, pi_per, t_per, gan));
          }
        }
        case c3__fork: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            return j2_mby(Pit, eith)
              (wir_r, _etch_frag(wir_r, van, p_sut, pi_per, t_per, gan),
                      _etch_frag(wir_r, van, q_sut, pi_per, t_per, gan));
          }
        } 
        case c3__hold: {
          if ( (u2_no == u2_as_trel(sut, 0, &p_sut, &q_sut)) ) {
            return u2_bl_bail(wir_r);
          }
          else {
            u2_noun fop = j2_mcy(Pit, vane, play)(wir_r, van, p_sut, q_sut);
            u2_noun pro = _etch_frag(wir_r, van, fop, pi_per, t_per, gan);

            u2_rl_lose(wir_r, fop);
            return pro;
          }
        }
      }
    }
  }

  static u2_noun                                                  //  transfer
  _etch_per(u2_wire wir_r, 
            u2_noun van,                                          //  retain
            u2_noun sut,                                          //  retain
            u2_noun per,                                          //  retain
            u2_noun gan)                                          //  retain
  {
    if ( u2_nul == per ) {
      return u2_bx(wir_r, gan);
    }
    else {
      u2_noun i_per = u2_h(per);
      u2_noun t_per = u2_t(per);

      if ( u2_yes == u2_stud(i_per) ) {
        u2_noun wer = j2_mcy(Pit, vane, find)(wir_r, van, sut, i_per);
        u2_noun p_wer, r_wer;

        u2_as_trel(wer, &p_wer, 0, &r_wer);
        {
          u2_noun giv = _etch_per(wir_r, van, r_wer, t_per, gan);
          u2_noun pro;

          pro = _etch_term(wir_r, van, sut, p_wer, giv);

          u2_rl_lose(wir_r, giv);
          return pro;
        }
      }
      else {
        u2_noun pi_per = u2_t(i_per);

        if ( (u2_nul != u2_h(i_per)) || (u2_no == u2_stud(pi_per)) ) {
          return u2_bl_bail(wir_r);
        }
        else {
          return _etch_frag(wir_r, van, sut, pi_per, t_per, gan);
        }
      }
    }
  }

/* functions
*/
  u2_noun                                                         //  transfer
  j2_mcy(Pit, vane, etch)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun rep,                            //  retain
                          u2_noun gan)                            //  retain
  {
    u2_noun per = j2_mbc(Pit, flop)(wir_r, rep);
    u2_noun pro = _etch_per(wir_r, van, sut, per, gan);

    u2_rl_lose(wir_r, per);
    return pro;
  }

  u2_noun                                                         //  transfer
  j2_mc(Pit, vane, etch)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, rep, gan, van;

    if ( (u2_no == u2_mean(cor, 8, &rep, 9, &gan, 5, &van, 0)) ||
         (u2_none == (sut = u2_frag(4, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcy(Pit, vane, etch)(wir_r, van, sut, rep, gan);
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, vane, etch)[] = {
    { ".3", c3__hevy, j2_mc(Pit, vane, etch), u2_no, u2_none, u2_none },
    { }
  };
