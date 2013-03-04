!:
::          %ames, networking.  This file is in the public domain.
::
=>  |%
    ++  clan                                            ::  flag to rank
      |=  who=flag  ^-  rank
      =+  wid=(met 3 who)
      ?:  (lte wid 1)   %czar
      ?:  =(2 wid)      %king
      ?:  (lte wid 4)   %duke
      ?:  (lte wid 8)   %jack
      ?>  (lte wid 16)  %pawn
    ::
    ++  grip                                            ::  extend will
      |=  [wet=will law=will]
      ^-  will
      ?~  wet
        law
      ?^  t.wet
        ?>((meld i.wet i.t.wet) [i.wet $(wet t.wet)])
      ?~  law
        ?>((pier i.wet) [i.wet ~])
      ?~  q.p.q.i.wet
        ?>((meld i.wet i.law) [i.wet law])
      =+  rul=(sein r.p.q.i.wet)
      |-  ^-  will
      ?:  ?&  =(rul r.p.q.i.law)
              =(p.p.q.i.law u.q.p.q.i.wet)
          ==
        ?>((meld i.wet i.law) [i.wet law])
      ?>(?=(^ t.law) $(law t.law))
    ::
    ++  sein                                            ::  default seigneur
      |=  who=flag  ^-  flag
      =+  mir=(clan who)
      ?-  mir
        %czar  who
        %king  (end 3 1 who)
        %duke  (end 4 1 who)
        %jack  (end 5 1 who)
        %pawn  (end 4 1 who)
      ==
    ::
    ++  meld                                            ::  verify connect
      |=  [new=deed old=deed]
      ^-  &
      ?>  ?&  (melt new old)
              .=  (shaf %meld (sham q.new))
                (need (sure:pu:(hail r.q.old) *code p.new))
          ==
      %&
    ::
    ++  melt                                            ::  proper connect
      |=  [new=deed old=deed]
      ^-  ?
      =+  rac=(clan r.p.q.new)
      ?&  ?~  q.p.q.new
            ?&  =(r.p.q.old r.p.q.new) 
                &(!=(%jack rac) =(p.p.q.old (dec p.p.q.new)))
            ==
          ?&  &(!=(%pawn rac) !=(%czar rac))
              |(=(0 p.p.q.new) =(%jack rac))
              =(r.p.q.old (sein r.p.q.new))
              =(p.p.q.old u.q.p.q.new)
          ==
      ==
    ::
    ++  pare                                            ::  shorten against
      |=  [fou=will law=will]
      ::  ~&  [%pare-fou fou]
      ::  ~&  [%pare-law law]
      ^-  will
      =+  [ouf=(flop fou) wal=(flop law)] 
      %-  flop  
      |-  ^-  will
      ?~  ouf  wal
      ?~  wal  ?>(=(~ ouf) ~)
      ?.  =(i.wal i.ouf)  ouf
      $(wal t.wal, ouf t.ouf)
    ::
    ++  pier                                            ::  initial deed
      |=  wed=deed
      ^-  &
      ?>  =+  rac=(clan r.p.q.wed)
          =+  loy=(hail r.q.wed)
          ?>  =(0 p.p.q.wed)
          ?>  =(fig:ex:loy ?+(rac !! %czar (zeno r.p.q.wed), %pawn r.p.q.wed))
          ?>  =((shaf %self (sham q.wed)) (need (sure:pu:loy *code p.wed)))
          %&
      %&
    ::
    ++  real                                            ::  validate
      |=  [mac=mace law=will]  
      ?>  ?&  |-  ^-  ?
              ?~  mac  &
              ?>  ?&  ?=(^ law) 
                      =(p.p.q.i.law p.i.mac)
                      =(r.q.i.law pub:ex:(wear q.i.mac))
                  ==
              $(mac t.mac, law t.law)
          ==
      %&          
    ::
    ++  rice                                            ::  mace at mark
      |=  [mar=mark mac=mace]
      ^-  (unit mace)
      ?~  mac  ~
      ?:  =(mar p.i.mac)  [~ mac]
      ?:  (gth mar p.i.mac)  ~
      $(mac t.mac)
    ::
    ++  rick                                            ::  will at mark
      |=  [mar=mark lag=flag law=will]
      ^-  (unit will)
      ?~  law  ~
      ?:  =(mar p.p.q.i.law)  [~ law]
      ?:  (gth mar p.p.q.i.law)  ~
      ?:  |(?=(~ q.p.q.i.law) !=(lag r.p.q.i.law))  ~
      $(law t.law)
    ::
    ++  zeno                                            ::  imperial keyprint
      |=  zar=@pD
      ^-  @uvH  ^-  @
      %+  snag  zar
      :~  0w2V.Ukriv.il3Pn.O97RL.WCBiz  0w3b.RFqBh.ZtHLt.xH0uW.nl4r8  ::   0
          0wk.S3gGl.p916u.nGq03.aIfFC   0w3e.ZmmHK.sn8Jk.UbI0q.jBfE~  ::   2
          0w11.NMecf.pgInp.98mpL.IEXxl  0w3M.werni.0PO7m.Xr6o6.sorS5  ::   4
          0ww.eFqOj.~Gd68.cwPXl.5~di2   0w5.UEzYe.f7GeR.Xz4NZ.94t3J   ::   6
          0w3C.vOPG3.dBYPE.WB-JW.pJsut  0w3Z.9SG~g.--p65.ZpYR3.YAPOp  ::   8
          0w1o.oyJ9k.FIgRG.-5DUc.nS2qV  0w1X.rBVYe.eK-Bc.IFT9k.QU70h  ::   10
          0w1n.2RT3k.9uJIw.JJDE7.d~Kr4  0w10.Mvu1S.Twd0R.r5Fgu.zS3P2  ::   12
          0w3O.Y9keb.6KJLZ.3k9rM.1gHfH  0w3n.FmDcG.MLl9-.1R2qr.9CDen  ::   14
          0ws.ivj46.Ka644.zfgyb.i1Jwl   0w1m.KZhaY.~eSMm.m6aUZ.ByLM7  ::   16
          0wD.-jkYG.QYHTh.aKUR0.TgjYn   0wI.lXRB~.Yy0TT.6EYMu.4FE72   ::   18
          0w1o.~RlQ2.cHVpw.a9AqL.v5KvC  0w1C.A4a8V.sGFex.fllup.sRyLn  ::   20
          0wb.IrqZl.GPTc8.xqhHO.3r37l   0w2V.2PTy0.beXoe.elV~F.V1UNp  ::   22
          0wb.xbIcB.SZ7Y3.oeh~K.w2dZN   0w3j.Auhah.XDQSJ.6g~ZN.JNfYD  ::   24
          0wC.LNa1e.mSrRP.xAGYb.ldDcV   0w3h.kmiYW.WU0yJ.fpNhq.MDYfB  ::   26
          0w1L.wvqac.Ej79I.-f2hj.yyiua  0w3S.tipUz.pZEpn.AsOTf.C6kVC  ::   28
          0w1E.s5FLM.qiA80.zIVax.jcuV9  0w3d.dwYLo.QSdkf.4PgIQ.85b62  ::   30
          0w3.v5AQq.r9Q0D.TdUpC.pZnX3   0w21.Rhkns.CxXSM.9vwhi.b69ou  ::   32
          0wd.cN1sl.S6PsD.gcCu7.qItJG   0w3t.RPGNR.mQ8e0.9uiL8.ktckX  ::   34
          0w2h.MJrJz.M2mZQ.qSmo2.o6Kqz  0wU.8sWaG.sxRhN.h6NhF.ZrnfR   ::   36
          0wO.j6rVO.5Nw0J.pCtKx.7Gqjc   0w17.uR4G4.WtINT.tHKlF.cv1sR  ::   38
          0w3D.umDEW.Di9XE.7dj34.RYHP0  0wa.pjSrD.boWNd.WSSTU.N55uA   ::   40
          0w1K.LUMK3.87Kel.sb9w2.axwVA  0w3V.M4cEO.n2-7O.nMUKK.4fE8U  ::   42
          0w2I.K7SX2.EBhEv.I1v9w.fovv9  0wHOKUK.uV7SA.-soQM.Y1O-n     ::   44
          0w1v.cIuC3.yyEcN.iNI2q.wSkxY  0w2s.BDWY7.0I8lb.R97eG.yY9zL  ::   46
          0w1-.aE~uR.C9lnL.MsDYg.80uJC  0wJ.eUvME.BR6mB.fJIlu.5KAv9   ::   48
          0w3c.1u83d.irTLJ.wre0x.sjxAe  0w3p.nG0oH.fDMXg.od3IO.dmsIP  ::   50
          0w3g.H9h3H.94x6x.E6Zye.GqS6x  0w2m.lZJg1.PIJHJ.eAiJ6.jx83v  ::   52
          0wE.kUFKH.Yqo0O.WY6qn.5~JR9   0w2t.XQ8xb.v2VpG.B4yXa.Rpjqw  ::   54
          0w3V.piQ56.iLCrb.ltgoD.ItsXA  0w3I.y56E4.b2XzH.1Brza.K64hV  ::   56
          0wd.Iiw-K.EfcJ-.-X245.boOBr   0w2C.K083C.4dVA8.d-L-I.sXavI  ::   58
          0w2C.D1ul2.c1PKX.I5cL0.n3dxr  0wV.Ng~R9.SKLqw.RMpxP.dblOY   ::   60
          0w2.HlTvo.V0D1L.p9W0j.aFU6k   0w1f.S1~BH.27Zih.7WiEh.pJEON  ::   62
          0w1R.3turY.40u9P.1QMXG.FVJ~e  0w2t.pyk~d.ZNWDs.f7gp-.qahoH  ::   64
          0wd.UASH0.QQ0mT.zFjag.gVv-J   0w34.uu9hS.Nuyp0.9O5GU.IqOPn  ::   66
          0w3G.V1d4~.Zcz2l.WRfRY.Gbqdn  0w2w.Hmqa7.p1ftE.s9mN4.34in8  ::   68
          0wK.CfMeO.vGDN2.L2OUd.DNv60   0wZ.SuM9F.WlyCQ.FwwAh.51TFp   ::   70
          0w2W.sGPo4.beqSQ.XqsQf.ngpFw  0w2j.BxZY4.q5ueN.DYB-W.M4kK5  ::   72
          0wm.7syof.RdI~X.L5DUP.zItuq   0wk.CpyEj.HtQtS.UKg9E.IKoZO   ::   74
          0w2y.EARAL.Pjrps.uAkP5.4NyvD  0wp.CsyQp.QMUm3.X-V1J.p4V4p   ::   76
          0w20.VAE8a.VACSh.IUktB.2DS9S  0w3B.hfjzy.D2ugI.o6nvB.dt6~N  ::   78
          0wb.c-Et2.ENdTt.FyLuO.rXpAF   0w2k.fHAYb.mPp6G.Miboj.aDzEo  ::   80
          0w3z.fhF6D.-4LXN.-P0BA.zDyZ6  0w9.ZZsl8.-aDxl.MWNZQ.n5JDG   ::   82
          0w2g.KbM4g.D4sa1.sbtDS.NUtIe  0wP.JoKfb.h2YhC.oXbtT.rabng   ::   84
          0w35.CHhpO.rszL-.leHOv.cx4WJ  0wy.ENViE.b9RMU.XYJe3.ebjB6   ::   86
          0w1Q.nTf4s.WPehk.UZi6Q.hGCDD  0w3L.eoarl.IzBcW.iHoFk.DdTPs  ::   88
          0w1r.8r6xk.zbByY.HZpKt.TkJSs  0w3.MVsxE.-cBYq.0xiNk.uZoqv   ::   90
          0w1z.C9-kZ.RZHRF.eV1Bt.Ra4al  0wI.y-xHW.bI~ul.RRfRZ.BHRCU   ::   92
          0wT.ZJe~e.xpTw3.WSItm.fm1ot   0we.t4i0L.jy95S.yKr6w.K1Dn4   ::   94
          0w3x.zRFNc.CX9C0.s-3Eh.h3eLp  0w26.6yAPi.bY3ua.jaDs6.1CNTS  ::   96
          0wn.XBNFm.12O3M.55VOX.VBO0I   0w1J.paHT2.IJZqT.e545s.SNWAo  ::   98
          0w3-.k~kTY.t4tHP.PG5RK.Y5X-C  0w3z.w7HU2.lvfLd.2Za49.Kgxht  ::   100
          0w33.DgYKm.i4iL5.4aDjB.sEk3o  0w20.Ll6pC.-mc2A.qehvg.oNeHh  ::   102
          0w3r.0nO~M.hBmIU.Q3XOm.hA2Rj  0wj.WldTu.Bu4rr.Ltu7-.zpJRX   ::   104
          0w3A.35FxJ.DGjY5.G3LHQ.LfJVT  0wv.ya8fC.PxL9-.vvw4m.y1nl9   ::   106
          0w1C.j6o82.Nwvgn.a4iyX.s96A5  0w2f.7Oh0W.qntLx.DJMZ~.GzDu2  ::   108
          0w2-.qx1ZS.mKo4m.NKC1U.6ovnn  0w2w.xmQFS.Z17mh.7jn~D.3tL90  ::   110
          0wa.~IdIm.OLZ8a.pCesI.JRjWh   0w3F.iSBJt.5YTlS.sVD04.5oTsr  ::   112
          0w1O.Umuco.Vd5gL.CiRGE.zSzCC  0w1M.RQl-y.JoZyn.Dt-ah.3yogE  ::   114
          0w3s.63zzz.inepf.VFWBM.Sc7LT  0w3k.zh3Xi.os9gg.VBo6W.XUUUx  ::   116
          0w2k.etCDk.P~CX6.0-Ypj.Ee0Ru  0w2Z.n-HK9.uOlO~.1YFBn.EUm23  ::   118
          0w3e.NGtk~.ShP70.DHWZF.yY8oO  0w3x.jncKF.u2U~6.7C1Xv.z8EOE  ::   120
          0w3Y.szv84.pyB8s.N1uuN.6hy-o  0w2R.7jkGe.cbf1h.Q3wfY.GCzqn  ::   122
          0wz.fGDgR.dMHKH.bgGM8.1F5Ku   0w2m.yvbNA.uj~Wu.zXhF3.qzspX  ::   124
          0w1t.NLG6L.AVQx0.idqAu.92c5Y  0w3j.-zbod.BTNxc.XHnZ6.i~cyL  ::   126
          0wf.TkUIq.M3oEf.V7pzm.oUeac   0wJ.2V7RM.A8mAB.OBPyw.fZkca   ::   128
          0w2o.uL5F3.kYcAL.ywJyr.MBrS6  0w3c.FS1eN.nZCE4.bCHKi.VOWrF  ::   130
          0w20.1pmNL.NUOS-.uvM9I.AC7xS  0w3H.zw20k.wo~9g.ZqENo.4gwia  ::   132
          0w1v.FSEaZ.JJszn.CtXLW.0BOWC  0w23.~C4lg.423lP.bAvqX.YaCat  ::   134
          0w1t.ILS-H.zkh4N.r5cgj.0iObH  0w3R.UykuY.~xkF1.pp7Ul.I~KPN  ::   136
          0w2H.BG1yW.Ho~bf.bxngT.WJyRN  0wd.zLMtU.Qgdhq.4xhFI.BYvSo   ::   138
          0w2D.CCH3~.yU~dF.dOLZ~.i8Yxb  0wG.AcblY.ivT2j.w~SXO.GpbGj   ::   140
          0w3~.Y4wSo.zN3rd.RDM-M.dNYaO  0w2H.z5te6.XIJBr.3CRwR.Dqqbo  ::   142
          0w2p.Fqgvz.-FmKe.ELwI~.rsZTJ  0w2U.6sons.uHcqX.gMaNi.il4kf  ::   144
          0w1D.SfglL.7vzYV.kZu2c.qVIPx  0w3o.IESE6.l66Cr.jMHnD.TJgDi  ::   146
          0w1i.RZjrt.Kb3Dz.7I6Q6.jBFJP  0wA.o0Cfe.7CaMB.Gs2VR.aFjCZ   ::   148
          0w2R.YjhaR.Sgk-2.74Fyb.wA99Y  0w1X.TI8BA.T3Ieb.hqE1c.M1w6u  ::   150
          0wR.-Ky5I.5DuxO.TYfwI.wbSNy   0w36.0SrNB.EE9XH.U~T0E.xaitz  ::   152
          0wW.315-W.vJknR.zUPYm.3-lq4   0w1m.TSem9.FDN5Y.mZt7K.lwcnE  ::   154
          0w2L.yKxX9.HxMoP.WKcgm.Bp7Wo  0w1z.I33gJ.BuwGo.ctZXR.UHGC6  ::   156
          0w2n.S-41-.FbR1Z.2l5Bx.VrQZw  0w7.D2RQ0.EIfuG.rTtnH.JO48c   ::   158
          0w-.7reJB.XblQ9.Uw3jn.FlrdI   0w3A.Kuuqa.F1YS6.ZB-rZ.iy~u2  ::   160
          0wS.ac1h4.nEPk9.eKY0y.m5KrG   0w1U.SR9hP.2ZboY.f1Ok1.ZX-k8  ::   162
          0wS.xdF7L.qeeTC.CGR2-.XqAEe   0w2d.uJ7s5.35XBG.-CymZ.FlEUm  ::   164
          0w2.CTr0J.b7dBt.A691l.7SYjf   0w1z.vVcZg.N1HHx.K6S06.UNvAu  ::   166
          0w1N.zku7K.rCTvt.qGc-9.2yn7o  0w3v.fdfMA.4LSuz.Iho3N.SCThs  ::   168
          0w2B.AyDxf.iFTJL.hoBzC.-bqJW  0w2v.VvLDG.lZSSi.16LC3.E0Quo  ::   170
          0wZ.uHZHu.KADkF.iWll2.czGKn   0wiAW3Q.GlHxG.qeiLC.QKp6H     ::   172
          0w-.UMmQ~.BeOjS.XM7nL.NrE1f   0w21.z1Kzt.OcFHY.QBj6L.Vu92D  ::   174
          0w1v.IwRhA.q81J-.MoCSn.LWM38  0w3A.2dbPP.OB0uf.4gWLs.SS4y7  ::   176
          0w3u.9SGmq.pALil.Ejas4.732GE  0w1.MYJ7V.Gt0kN.4dT9e.H1Dju   ::   178
          0w2O.Uj9-P.4uC5Z.Yyzsh.F4agE  0w1h.65CUK.X7Jy1.JWqGs.7mdrd  ::   180
          0w2-.kWBUe.6KTs2.LMlz1.j43i0  0wc.FHziM.aePml.ieBk5.8eqwJ   ::   182
          0wT.l6eWX.7O5YM.4jVPQ.MxS7q   0w2b.ZTRY4.2hS3d.jIQDz.ohax9  ::   184
          0w2W.BCV~i.J6nRC.GYmYd.PE-3f  0w2M.r~1pF.yxaLG.0X7mY.kbcmZ  ::   186
          0w2H.Jy0dD.5~CGJ.vVl5N.NCqrd  0w2X.mU92M.4KHUY.QsQIm.cZnH0  ::   188
          0w3T.kQ3xd.ZA6mG.fp~5u.Y7SGb  0wP.w3qQ1.Jq7~A.KlqX0.FBN-K   ::   190
          0wL.KZjjX.q004~.moBSf.Tm813   0w28.LmGk-.LIXge.UmRjM.MOSKJ  ::   192
          0w3Y.~TnrK.dMQIE.jcUgQ.jtMlK  0wf.cQJXb.UeQuG.fKnOW.Mvupe   ::   194
          0w32.6z295.XJdLf.LfxB-.AU74n  0w1F.eex0C.AgBjk.OzQRd.Nzdao  ::   196
          0w1c.gYKzt.d3BmF.ws0fc.xKAqB  0w3F.2~y3d.8bmnf.aeJd4.VDON3  ::   198
          0wl.cN7Y6.Bv-T6.mR3gX.WJd6Y   0w1W.YXaDF.NGQui.iJ4NL.e1~aS  ::   200
          0w3d.JGFz~.NZ9~p.IYTg4.aHw-J  0ww.g8MDD.0USjz.-MUWm.Eq5N7   ::   202
          0w2M.VsXXs.IuE7N.j8NAT.lAtDt  0w9.p2bJR.NFhHv.PD-k9.x7cJv   ::   204
          0w1k.zeayz.UvqJZ.2K5sO.DX7lY  0w2V.9rGs-.1ifoK.Jektk.9ib-b  ::   206
          0wW.wtK6L.ubZX1.t3ek~.LVpGp   0w3F.pwdM5.n8QLh.HUIK9.pIFJG  ::   208
          0w3M.VPExl.OdHHu.sC3Qh.3HzX7  0wz.Tu73b.TaxVx.RWhYq.MMlwO   ::   210
          0wc.J6h75.wVCg9.ndTr5.-C0Hr   0w3n.Hib~g.RSETH.7BW0T.5cWBj  ::   212
          0w1O.FnYF0.clcSF.hoMmH.lihCJ  0w1R.wLpDE.7Ku3X.v8B4T.F33Jk  ::   214
          0w1A.u1Xy6.9cJC5.D4WS0.jdfZI  0wR.9r54a.FlL2b.LBvp6.9iTaR   ::   216
          0w2g.tYi3K.f7lTi.FTneM.7gUQp  0wa.JJx2p.4mPll.EVLww.yXRjd   ::   218
          0w1B.JRxYo.eQguP.8m3iV.MeSvO  0w2C.KbwGk.TxQFn.x302i.~CV0r  ::   220
          0w1q.n~9Wx.QD6bR.ZtJSG.vk72y  0wj.3bYhB.X49YD.lSIYp.QUah9   ::   222
          0wD.zFbw2.M1eKo.b~woh.AHW2J   0w22.JsU2i.QEd0L.U1ypz.FKh-e  ::   224
          0wP.yNjBd.9hoR0.LftGu.R3D0B   0w3h.hFb1J.fRqvi.p0Vf0.r39xP  ::   226
          0w3Z.f8ATL.NCgDB.6yR-l.b2do-  0w1g.K9vME.LaoAw.x9C0k.1Ie2X  ::   228
          0w36.DzGry.G1qRx.Z~K05.NgM1j  0w3F.1a~Zh.FKBXa.35Rd0.839r0  ::   230
          0w2C.Kcrd5.7vixd.Tjsws.JzYdW  0wC.XI5BG.HI3Ta.d8roK.dUfKi   ::   232
          0w2c.c16ta.IVqWo.Hf~6p.6AlCG  0wT.yguKp.T0GRt.GPMz6.SXDio   ::   234
          0wn.1Fg-g.j542C.kKwZl.Vs91r   0w2.AfT1v.Q4WBg.8SuCi.w~Czr   ::   236
          0wB.0fRem.N9o9~.rXxsM.gQ0Pe   0w13.6aZYQ.plf47.aW~6z.tEnZr  ::   238
          0w1k.f31i2.8U3CQ.eidrC.e70b6  0w-.D5Jq2.cQ7m1.asl~k.PU6D6   ::   240
          0w20.3GvjZ.6gC6~.rXPfO.HHJUv  0wJ.i2eXe.7ps3d.4MZoT.EVWSu   ::   242
          0w2j.~TQ26.iSUMC.eIetC.q8Qud  0w4.GdF~3.mSosY.~OUIv.ZIWMb   ::   244
          0w2H.15yaC.SRQS3.d4aST.9fHaq  0w1D.vw71j.TuvRV.EZ24I.j5Ozr  ::   246
          0wa.jyzsm.fCIsM.t~fBq.3ETAS   0w1X.-QDve.PeZbP.yiTNj.dRZXc  ::   248
          0w3G.i0gNT.aTiZg.YSElf.~Mu4n  0wP.vP9Q2.TmwJW.wTm7~.optmq   ::   250
          0wR.0WQu-.u8Zcv.ZJgXt.SIWYa   0wm.K7GpT.N5-C~.gca6d.FLwHE   ::   252
          0wE.X8Ijk.07160.u3a7e.rkxlw   0w3L.crn06.cqLpb.c6-N3.FeY6S  ::   254
      ==
    --
=>  |%
    ++  bite                                            ::  packet to cake
      |=  pac=rock  ^-  cake
      =+  [mag=(end 5 1 pac) bod=(rsh 5 1 pac)]
      =+  :*  vez=(end 0 3 mag)                         ::  protocol version
              chk=(cut 0 [3 19] mag)                    ::  checksum
              dit=(cut 0 [22 1] mag)                    ::  fragment bit
              wix=(bex +((cut 0 [23 2] mag)))           ::  width of receiver
              vix=(bex +((cut 0 [25 2] mag)))           ::  width of sender
              tay=(cut 0 [27 5] mag)                    ::  message type
          ==
      ?>  =(0 vez)
      ?>  =(chk (end 0 19 (mug bod)))
      :^    [(end 3 wix bod) (cut 3 [wix vix] bod)]
          =(0 dit)
        (snag tay [%none %open %fast %full ~])
      (rsh 3 (add wix vix) bod)
    ::
    ++  spit                                            ::  cake to packet
      |=  kec=cake  ^-  @
      =+  wim=(met 3 p.p.kec)
      =+  dum=(met 3 q.p.kec)
      =+  yax=?:((lte wim 2) 0 ?:((lte wim 4) 1 ?:((lte wim 8) 2 3)))
      =+  qax=?:((lte dum 2) 0 ?:((lte dum 4) 1 ?:((lte dum 8) 2 3)))
      =+  wix=(bex +(yax))
      =+  vix=(bex +(qax))
      =+  bod=:(mix p.p.kec (lsh 3 wix q.p.kec) (lsh 3 (add wix vix) s.kec))
      =+  tay=?-(r.kec %none 0, %open 1, %fast 2, %full 3)
      %+  mix
        %+  can  0
        :~  [3 0]
            [19 (mug bod)]
            [1 q.kec]
            [2 yax]
            [2 qax]
            [5 tay]
        ==
      (lsh 5 1 bod)
    --
=>  |%
    ::::
    ++  go                                              ::    go
      |_  ton=town                                      ::  ames protocol
      ::::
      ++  as                                            ::    as:go
        |_  [our=flag saf=safe]                         ::  per server
        ::::
        ++  lax                                         ::    lax:as:go
          |_  [her=flag nob=door]                       ::  per client
          ::::
          ++  cley                                      ::    cley:lax:as:go
            ^-  [p=mark q=gcos r=acro]                  ::  client crypto
            ?~  lew.wod.nob  !!
            :+  p.p.q.i.lew.wod.nob 
              q.q.i.lew.wod.nob 
            (hail r.q.i.lew.wod.nob)
          ::
          ++  griz                                      ::    griz:lax:as:go
            |=  now=@da                                 ::  generate key for
            ^-  [p=code q=_+>]
            =+  key=(shas %enty (mix now any.ton))
            :-  key
            %=  +>.$
              any.ton      (shax (mix now any.ton))
              heg.caq.nob  (~(put by heg.caq.nob) (shaf %hand key) key)
            ==
          ::
          ++  kuch                                      ::    kuch:lax:as:go
            |=  had=hand                                ::  hear key tag
            ^-  (unit ,[p=code q=_+>])
            =+  wey=(~(get by heg.caq.nob) had)
            ?^  wey
              =+  key=(shas %anex u.wey)
              :+  ~  key
              %=    ..kuch
                  yed.caq.nob  [~ had u.wey]
                  heg.caq.nob  (~(del by heg.caq.nob) had)
                  qim.caq.nob  (~(put by qim.caq.nob) had key)
              ==
            =+  dyv=(~(get by qim.caq.nob) had)
            ?~  dyv  ~
            [~ u.dyv ..kuch]
          ::
          ++  trox                                      ::    trox:lax:as:go
            |=  [now=@da]                               ::  expire by date
            ^+  +>
            +>    ::  XX
          ::
          ++  wasc                                      ::    wasc:lax:as:go
            |=  key=code                                ::  hear foreign code
            ^+  +>
            =+  had=(shaf %hand key)
            %_    ..wasc
                yed.caq.nob  [~ had key]
                qim.caq.nob  (~(put by qim.caq.nob) had key)
            ==
          ::
          ++  zuul                                      ::    zuul:lax:as:go
            |=  [now=@da ham=meal]                      ::  encode message
            ^-  [p=(list rock) q=_+>]
            =+  ^=  lun  ^-  (unit lane)
                ?.  &(?=(^ loc.saf) !=(loc.saf lun.fer.nob))
                  ~
                loc.saf
            =<  weft
            |%
            ++  wasp                                    ::  null security
              ^-([p=skin q=@] [%none (jam lun ham)])
            ::
            ++  weft                                    ::  fragment message
              ^-  [p=(list rock) q=_+>.$]
              =^  gim  ..weft  wisp
              :_  +>.$
              ^-  (list rock)
              =+  wit=(met 13 q.gim)
              ?<  =(0 wit)
              ?:  =(1 wit)
                [(spit [her our] & p.gim q.gim) ~]
              =+  ruv=(rip 13 q.gim) 
              ?>  ?=(^ ruv)
              =+  may=(spit [her our] | p.gim (jam wit i.ruv))
              =+  dam=(shaf %flap may)
              =+  inx=1
              :-  may
              |-  ^-  (list rock)
              ?~  t.ruv  ~
              =+  ^=  vie
                  %^    spit
                      [her our]
                    &
                  wasp(lun ~, ham [%carp inx dam i.t.ruv])
              :-  vie
              $(t.ruv t.t.ruv, inx +(inx))
            ::
            ++  wisp                                    ::  generate message
              ^-  [[p=skin q=@] q=_..wisp]
              ?:  =(%carp -.ham)
                [wasp ..wisp]
              ?:  &(=(law.saf lew.fer.nob) ?=(^ yed.caq.nob))
                :_  ..wisp
                :-  %fast
                %^  cat  7
                  p.u.yed.caq.nob 
                (en:r:cley q.u.yed.caq.nob (jam lun ham))
              ?:  =(%back -.ham)
                [wasp ..wisp]
              =^  tuy  +>.$
                ?:(=(~ lew.wod.nob) [*code +>.$] (griz now))
              :_  ..wisp
              =+  yig=sen
              =+  ^=  gom
                  %^    jam
                      p.yig
                    (pare lew.fer.nob law.saf)
                  (sign:se:q.yig tuy (jam lun ham))
              ?:  =(~ lew.wod.nob)
                [%open gom]
              :-  %full
              =+  cay=cley
              (jam p.cay (seal:pu:r.cay tuy gom))
            --                                          ::  --
          --                                            ::  --lax:as:go
        ::::
        ++  fix  |=(lyn=lane %_(+> loc.saf [~ lyn]))    ::  set server route
        ++  gub                                         ::  flag/key by code
          |=  had=hand
          ^-  [p=[p=flag q=code] q=_+>]
          =+  pys=`[p=flag q=@da]`(need (~(get by seh.saf) had))
          =+  gry=`_lax`(myx p.pys)
          =+  kuh=(need (kuch:gry had))
          [[p.pys p.kuh] (nux q.kuh)]
        ::
        ++  hey                                         ::  general routing
          |=  her=flag
          ^-  lane
          =+  tin=(way her)
          ?^  tin
            u.tin
          =+  rex=(yo her)
          ?-  -.rex
            &  =+  nit=loc.saf.p.rex
               ?~(nit [%if 0 .0.0.0.0] u.nit)
            |  p.rex
          ==
        ::
        ++  myx                                         ::  door by flag
          |=  her=flag
          ^+  lax
          =+  fod=(~(get by hoc.saf) her)
          ~(. lax [her ?~(fod *door u.fod)])
        ::
        ++  nux                                         ::  install door
          |=  new=_lax
          ^+  +>
          +>(hoc.saf (~(put by hoc.saf) her.new nob.new))
        ::
        ++  pyl                                         ::  route to
          |=  [her=flag lyn=lane]
          ~&  [%lane her lyn]
          ^+  +>
          (nux %*(. (myx her) lun.wod.nob [~ lyn]))
        ::
        ++  pyr                                         ::  mirror route
          |=  [her=flag lyn=lane]
          ^+  +>
          (nux %*(. (myx her) lun.fer.nob [~ lyn]))
        ::
        ++  ren                                         ::  renew crypto
          |=  [biz=@ud sed=@]
          ^+  ..ren
          ..ren   ::  XX  not needed rite now
        ::
        ++  sen                                         ::  current crypto
          ^-  [p=mark q=acro]
          ?~(val.saf !! i.val.saf)
        ::
        ++  sev                                         ::  crypto by mark
          |=  mar=mark
          ^-  [p=? q=acro]
          ?~  val.saf  !!
          ?:  =(mar p.i.val.saf)
            [& q.i.val.saf]
          ?>  (lth mar p.i.val.saf)
          :-  |
          |-  ^-  acro
          ?:  =(mar p.i.t.val.saf) 
            q.i.t.val.saf 
          $(t.val.saf t.t.val.saf)
        ::
        ++  sex                                         ::  export secrets
          |-  ^-  mace
          ?~  val.saf  ~
          :-  [p.i.val.saf sec:ex:q.i.val.saf] 
          $(val.saf t.val.saf)
        ::
        ++  tim                                         ::  expire by date
          |=  [now=@da]
          ^+  ..tim
          ..tim
        ::
        ++  tyc                                         ::  install symcode
          |=  [her=flag key=code]
          ^+  +>
          (nux (wasc:(myx her) key))
        ::
        ++  wag                                         ::  install will
          |=  [her=flag law=will]
          ^-  [p=[p=mark q=acro] q=_+>]
          =+  hiz=(grip law (yew her))
          =+  lyr=%*(. (myx her) lew.wod.nob hiz)
          =+  cay=cley:lyr
          ~&  [%will her p.cay]
          [[p.cay r.cay] (nux lyr)]
        ::
        ++  way                                         ::  internal routing
          |=  her=flag
          ^-  (unit lane)
          lun.wod.nob:(myx her)
        ::
        ++  yew                                         ::  best will for
          |=  her=flag
          ^-  will
          =+  gel=(~(get by hoc.saf) her)
          ?^  gel
            lew.wod.u.gel
          ?:((lth her 256) ~ $(her (sein her)))
        --
      ::::                                              ::  (as)
      ++  ha                                            ::  adopt new license
        |=  [our=flag mac=mace wil=will] 
        ^-  town
        ?>  !=(~ mac) 
        ?>  ?=(^ wil) 
        ?>  =(our r.p.q.i.wil) 
        ?>  =(wil (grip wil ~))
        ?>  (real mac wil)
        %_    ton
            urb
          %+  ~(put by urb.ton)
            our
          [~ (turn mac |=([p=mark q=ring] [p (wear q)])) wil ~ ~]
        ==
      ::
      ++  su                                            ::  install safe
        |=  new=_as
        ^-  town
        ton(urb (~(put by urb.ton) our.new saf.new))
      ::
      ++  ti                                            ::  expire by time
        |=  [now=@da]
        ^-  town
        !!
      ::
      ++  us                                            ::  produce safe
        |=  our=flag
        ^-  (unit ,_as)
        =+  goh=(~(get by urb.ton) our)
        ?~  goh  ~
        [~ ~(. as [our u.goh])]
      ::
      ++  yo                                            ::  receive routing
        |=  his=flag
        ^-  $%([& p=_as] [| p=lane])
        =+  gun=(~(us go ton) his)
        ?^  gun
          [%& u.gun]
        =+  kid=his
        :-  %|
        |-  ^-  lane
        =+  seg=(sein kid)
        =+  dub=(~(us go ton) seg)
        ?^  dub
          (need (way:u.dub kid))
        ?:  (lte (met 3 kid) 1)
          [%if 0 (mix .0.0.1.0 kid)]
        $(kid seg)
      --                                                ::  --as
    --                                                  ::  --go
=>  |%                                                  ::  congestion control
    ++  baby                                            ::  new flow
      ^-  flow
      [`@dr`(bex 60) 4 0]
    ::
    ++  echo                                            ::  measured rtt
      |=  [rtt=@ foy=flow]  ^-  flow
      foy(rtt (div (add rtt (mul 2 rtt.foy)) 3))
    ::
    ++  fast                                            ::  got good ack
      |=  foy=flow  ^-  flow
      foy(wid +(wid.foy))
    ::
    ++  slow                                            ::  throttle back
      |=  foy=flow  ^-  flow
      foy(wid ?:(=(1 wid.foy) 1 (div wid.foy 2)))
    --
=>  |%                                                  ::  selective ack
    ++  suck
      |=  [num=@ud ski=snow]
      ~&  [%suck num ski]
      ^-  [p=(list ,@ud) q=snow]
      ?>  (lte num q.ski)
      ?:  =(num p.ski)
        =>  .(p.ski +(p.ski))
        |-  ?:  =(q.ski p.ski)
              [~ ski]
            ?.  (~(has in r.ski) p.ski)
              [~ ski]
            $(p.ski +(p.ski), r.ski (~(del in r.ski) p.ski))
      ?>  (gth num p.ski)
      =>  .(r.ski (~(put in r.ski) num), num (dec num))
      =+  wop=*(list ,@ud)
      |-  ?:  =(num p.ski)
            [(flop wop) ski]
          $(num (dec num), wop [num wop])
    ::
    ++  toss  |=(ski=snow ^-(snow ski(q +(q.ski))))
    --
=>  |%
    ++  pe                                              ::  packet queue
      |_  tea=shed
      ++  busc                                          ::    busc:pe
        |=  num=@ud                                     ::  find by number
        ^-  (unit bird)
        ?~  q.tea  ~
        ?:  =(num p.n.q.tea)
          [~ q.n.q.tea]
        ?:((gth num p.n.q.tea) $(q.tea l.q.tea) $(q.tea r.q.tea))
      ::
      ++  glan                                          ::    glan:pe
        |=  num=@ud                                     ::  delete by number
        ^+  ..glan
        ?:  =(~ q.tea)  
          ..glan
        ?:  =(num p.n.q.tea)
          %_(..glan q.tea ~(nap to q.tea))
        ?:((gth num p.n.q.tea) $(q.tea l.q.tea) $(q.tea r.q.tea))
      ::
      ++  gost                                          ::    gost:pe
        |=  [now=@da num=@ud gom=soap mup=@ud pac=rock] ::  insert in queue
        ^+  ..gost
        %_    ..gost
            p.tea  now
            q.tea 
          %+  ~(put to q.tea) 
            num 
          `bird`[gom mup & @dr @da pac]
        ==
      ::
      ++  harv                                          ::    harv:pe
        |=  [now=@da rtt=@dr]                           ::  current / roundtrip
        =+  ^=  rub                                     ::  harvest data
            :*  p=&                                     ::  window nice
                q=`@da`(add ~d1 now)                    ::  next active
                r=*(list rock)                          ::  send packets
                s=*(list soap)                          ::  kill msgs
            ==
        =<  [p=rub q=..harv]
        |-  ^+  ..$
        ?~  q.tea  ..$
        =>  =+  sir=$(q.tea l.q.tea)
            ..$(rub rub.sir, l.q.tea q.tea.sir)
        =>  ^+  ..$
            ?:  =(0 tim.q.n.q.tea)
              =+  ryt=(div (mul 3 rtt) 2)
              =+  den=(add ryt now)
              %_  ..$
                q.rub          den
                r.rub          [pac.q.n.q.tea r.rub]
                tim.q.n.q.tea  ryt
                ded.q.n.q.tea  den
              ==
            ?.  (lth ded.q.n.q.tea now)
              ..$
            ?:  (gth tim.q.n.q.tea ~m1)
              ..$(s.rub [gom.q.n.q.tea s.rub])
            =+  ryt=(mul 2 tim.q.n.q.tea)
            =+  den=(add ryt now)
            %_  ..$
              p.rub          |
              q.rub          den
              r.rub          [pac.q.n.q.tea r.rub]
              tim.q.n.q.tea  ryt
              ded.q.n.q.tea  den
            == 
        =+  ryz=$(q.tea r.q.tea)
        ..$(rub rub.ryz, r.q.tea q.tea.ryz)
      ::
      ++  namp                                          ::    namp:pe
        |=  [now=@da num=@ud]                           ::  timeout/resend
        %_    ..namp
            p.tea  now
            q.tea
          |-  ^+  q.tea
          ?:  =(~ q.tea)
            q.tea
          =>  %_(. l.q.tea $(q.tea l.q.tea), r.q.tea $(q.tea r.q.tea))
          ?.  =(num p.n.q.tea)
            q.tea
          q.tea(ded.q.n now)
        ==
      ::
      ++  rast                                          ::    rast:pe
        |=  gom=soap                                    ::  delete by msg id
        %_    ..rast
            q.tea
          |-  ^+  q.tea
          ?:  =(~ q.tea)
            q.tea
          =>  %_(. l.q.tea $(q.tea l.q.tea), r.q.tea $(q.tea r.q.tea))
          ?:  =(gom gom.q.n.q.tea)
            ~(nap to q.tea)
          q.tea
        ==
      --
    --
|%
++  am                                                  ::    am
  |_  [now=@da fox=fort]                                ::  protocol engine
  ::::
  ++  ad                                                ::    ad:am
    |=  [our=flag her=flag]                             ::  outbound dispatch
    =|  bin=(list boon)
    =+  weg=(need (~(get by zac.fox) our))
    =+  ^=  bah  ^- bath
        =+  bah=(~(get by wab.weg) her)               
        ?^(bah u.bah %*(. *bath foy baby))            
    |%
    ++  cool                                            ::    cool:ad:am
      |-  ^+  ..cool                                    ::  refill window
      ?.  &(?=(^ maz.bah) (gth wid.foy.bah yed.foy.bah))
        ..cool
      $(..cool pock)
    ::
    ++  corn                                            ::    corn:ad:am
      ^-  [p=(list boon) q=fort]                        ::  resolve ad:am
      :-  bin
      %=    fox
          zac  
        %+  ~(put by zac.fox)
          our
        %=   weg
          wen  (min p.sea.bah wen.weg)
          wab  (~(put by wab.weg) her bah)
        == 
      ==
    ::
    ++  kill                                            ::    kill:ad:am
      |=  gom=soap                                      ::  kill message
      ^+  ..kill
      %_    ..kill
          bin      [[%coke %weak gom] bin]
          sea.bah  tea:(~(rast pe sea.bah) gom)
      ==
    ::
    ++  pock                                            ::    pock:ad:am
      |-  ^+  ..pock                                    ::  queue a packet
      ?:  =(~ maz.bah)
        ..pock
      =+  zem=~(get to maz.bah)
      =>  ^+(. .(maz.bah q.zem))
      =+  dyp=`putt`(need (~(get by par.bah) p.zem))
      ?>  ?=(^ wyv.dyp)
      ~&  [%pock `@p`(mug (shaf %flap i.wyv.dyp))]
      %_    ..pock
          yed.foy.bah  +(yed.foy.bah)
          ski.bah      (toss ski.bah)
          maz.bah      
        ?~(t.wyv.dyp maz.bah (~(put to maz.bah) p.zem))
      ::
          air.bah      
        (~(put by air.bah) (shaf %flap i.wyv.dyp) q.ski.bah)
      ::
          par.bah 
        %+  ~(put by par.bah)
          p.zem
        dyp(wyv t.wyv.dyp, ski (toss ski.dyp))
      ::
          sea.bah      
        tea:(~(gost pe sea.bah) now q.ski.bah p.zem q.ski.dyp i.wyv.dyp)
      ==
    ::
    ++  tuck                                            ::    tuck:ad:am
      |=  [kay=cape fap=flap cot=@dr]                   ::  ack by hash
      ^+  ..tuck
      =>  %_(. ..tuck (tusk kay (need (~(get by air.bah) fap)) cot))
      ?.  =(%good kay)
        ..tuck
      ..tuck(air.bah (~(del by air.bah) fap))
    ::
    ++  tusk                                            ::    tusk:ad:am
      |=  [kay=cape num=@ud cot=@dr]                    ::  ack by sequence
      ^+  ..tusk
      ?-    kay
          %dead  
        %_  ..tusk
          sea.bah  tea:(~(namp pe sea.bah) now num)
          foy.bah  (slow foy.bah)
        ==
      ::
          %good
        ~&  [%tusk-ski-bah ski.bah]
        =+  suz=(suck num ski.bah)
        ~&  [%tusk-ski-suz suz] 
        =>  %_    .
                sea.bah
              |-  ^+  sea.bah
              ?~  p.suz  sea.bah
              %=    $
                  p.suz    t.p.suz
                  sea.bah  tea:(~(namp pe sea.bah) now i.p.suz)
              ==
            ==
        =+  rob=(need (~(busc pe sea.bah) num))
        =+  dyp=`putt`(need (~(get by par.bah) gom.rob))
        =>  %_(. ski.dyp q:(suck mup.rob ski.dyp))
        =+  fin=&(=(~ wyv.dyp) =(p.ski.dyp q.ski.dyp)) 
        %_    ..tusk
            bin      ?.(fin bin [[%coke %good gom.rob] bin])
            ski.bah  q.suz
            sea.bah  tea:(~(glan pe sea.bah) num)
            par.bah  (~(put by par.bah) gom.rob dyp)
            foy.bah
          ?^  p.suz
            (slow foy.bah)
          ?.  org.rob
            foy.bah
          (echo (sub (sub now (sub ded.rob tim.rob)) cot) foy.bah)
        ==
      ::
          %weak 
        =+  gom=gom:(need (~(busc pe sea.bah) num))
        =>  %_(. bin [[%coke %weak gom] bin])
        (kill gom)
      ==
    --
  ++  lo                                                ::    lo:am
    |=  $:  gus=_as:go                                  ::  inbound dispatch
            her=flag                                    ::  claimed sender
            ryn=lane                                    ::  receive lane
            aut=?                                       ::  authenticated
            dam=flap                                    ::  ack identity
        ==
    =+  weg==+(weg=(~(get by zac.fox) our.gus) ?~(weg *oven u.weg))
    =+  bin=*(list boon)
    |%                                                  
    ++  blow                                            ::    blow:lo:am
      |=  [dit=? sin=skin msg=@]                        ::
      ^+  ..blow
      (?:(dit chew wait) & sin msg)
    ::
    ++  chew                                            ::    chew:lo:am
      |=  [dak=? sin=skin msg=@]                        ::
      ^+  +>
      =+  ^=  leq
          |=  key=code  ^-  _..chew
          =+  ^=  mex
              %.  (cue msg)
              (hard ,[p=mark q=will r=@])
          =+  wug=(wag:gus her q.mex)
          ?>  =(p.mex p.p.wug)
          %+  chow(aut &)  dak
          ((hard tray) (cue (need (sure:pu:q.p.wug key r.mex))))
      ?-    sin
          %none  (chow dak ((hard tray) (cue msg)))
          %fast
        =+  [mag=`hand`(end 7 1 msg) bod=(rsh 7 1 msg)]
        =+  yoq=(gub:gus mag)
        =>  %_(. gus q.yoq)
        ?>  =(her p.p.yoq)
        %+  chow(aut &)  dak
        ((hard tray) (cue (dy:q:sen:gus q.p.yoq msg)))
    ::
          %full
        =+  mex=((hard ,[p=mark q=@]) (cue msg))
        =+  gey=(sev:gus p.mex)
        =+  mes=(need (tear:se:q.gey q.mex))
        =+  qel=(leq p.mes)
        =>  %_(. +>.$ qel)
        %_(+>.$ gus ?.(p.gey gus (tyc:gus her p.mes)))
    ::
          %open  (leq *code)
      ==
    ::
    ++  chow                                            ::    chow:lo:am 
      |=  [dak=? fey=tray]                              ::  interpret tray
      =.  gus 
          ?.  &(aut ?=(^ p.fey))  gus 
          ?>  ?&  |(=(0 p.u.p.fey) =(p.ryn p.u.p.fey))
                  =(q.ryn q.u.p.fey)
              ==
          (pyl:gus her ryn)
      (dine dak q.fey)
    ::
    ++  cock                                            ::    cock:lo:am
      ^+  .                                             ::  acknowledgment
      =+  diz=(myx:gus her)
      ~&  [%cock `@p`(mug dam)]
      =^  rox  diz  (zuul:diz now [%back %good dam ~s0])
      %_  ..cock
        bin  (weld (turn p.rox |=(pac=rock [%ouzo ryn pac])) bin)
        gus  (nux:gus diz)
      ==
    ::
    ++  dine                                            ::    dine:lo:am
      |=  [dak=? fud=meal]                              ::  interpret meal
      ^+  +>
      =.  +>  ?.(&(dak !=(%back -.fud)) +> cock)
      ?-    -.fud
          %back
        =+  boz=corn:(tuck:(ad [our.gus her]) p.fud q.fud r.fud)
        %_  ..dine
          bin  (weld p.boz bin)
          weg  (need (~(get by zac.q.boz) our.gus))     ::  XX slow
        ==
      ::
          %bond
        ?>  aut
        (emit [%milk [our.gus her] now q.fud])
      ::
          %buck
        =>  %_(. ..dine (emit [%beer her pac:ex:q:sen:gus]))
        %_(..dine ton.fox (~(ha go ton.fox) her p.fud q.fud))
      ::
          %carp
        =+  neb=`[p=@da q=bait]`(need (~(get by nys.weg) q.fud))
        ?>  (lth p.fud p.r.q.neb)
        =+  doy=`(unit ,@)`(~(get by q.r.q.neb) p.fud)
        ?^  doy
          ..dine
        =>  ^+  .   %=  .
              q.r.q.neb  (~(put by q.r.q.neb) p.fud r.fud)
              q.q.neb    +(q.q.neb)
            ==
        ?:  =(q.q.neb p.r.q.neb)
          (gaff p.q.neb r.q.neb)
        ..dine(nys.weg (~(put by nys.weg) q.fud neb))
      ::
          %ping  
        ~&  [%ping aut her]
        ..dine
      ==
    ::
    ++  emit                                            ::    emit:lo:am
      |=  bun=boon                                      ::  emit a boon
      ^+  ..emit
      ..emit(bin [bun bin])
    ::
    ++  gaff                                            ::    gaff:lo:am 
      |=  [sin=skin duv=dove]                           ::  assemble fragments
      ^+  ..gaff
      %^  chew  |
        sin
      =+  [nix=0 rax=*(list ,@)]
      |-  ^-  @
      ?:  =(p.duv nix)
        (can 13 (turn (flop rax) |=(a=@ [1 a])))
      $(nix +(nix), rax [(need (~(get by q.duv) nix)) rax])
    ::
    ++  grok                                            ::    grok:lo:am
      ^-  [p=(list boon) q=fort]                        ::  resolve lo:am
      :-  bin
      %=  fox
        ton  (~(su go ton.fox) gus)
        zac  (~(put by zac.fox) our.gus weg)
      ==
    ::
    ++  wait                                            ::    wait:lo:am
      |=  [dak=? sin=skin msg=@]                        ::  receive indirect
      ^+  ..wait
      =+  pay=((hard ,[p=@ud q=@]) (cue msg))
      =.  nys.weg  (~(put by nys.weg) dam [(add now ~d1) sin 0 p.pay ~])
      (dine dak [%carp 0 dam q.pay])
    --                                                  ::  --lo:am
  ::
  ++  come                                              ::    come:am
    |=  [ges=@t wid=@ bur=@]                            ::  instantiate pawn
    ^-  [p=[p=flag q=@uvG] q=fort]
    =+  loy=(brew wid bur)
    =+  rig=sec:ex:loy
    =+  our=`@p`fig:ex:loy
    =+  syp=`step`[`bran`[0 ~ our now] [%pawn ges] pub:ex:loy]
    :-  [our pac:ex:loy]
    %_    fox
        ton
      %^    ~(ha go ton.fox)
          our
        `mace`[[0 rig] ~]
      `will`[[(sign:se:loy @ (shaf %self (sham syp))) syp] ~]
    ==
  ::
  ++  gnaw                                              ::    gnaw:am
    |=  [ryn=lane pac=rock]                             ::  process packet
    ^-  [p=(list boon) q=fort]
    ~&  [%hear ryn `@p`(mug (shaf %flap pac))]
    =+  kec=(bite pac)
    =+  how=(~(yo go ton.fox) p.p.kec)
    ?-  -.how
      &  =<  grok
         %-  =<  blow
            (lo p.how q.p.kec ryn | (shaf %flap pac))
         [q.kec r.kec s.kec]
      |  [[[%ouzo p.how pac] ~] fox]
    ==
  ::
  ++  hast                                              ::    hast:am
    |=  [soq=sock bah=bath]                             ::  roll per socket
    ^-  [p=(list (list ,[p=@da q=boon])) q=bath]
    =+  lyn=`lane`(hey:(need (~(us go ton.fox) p.soq)) q.soq)
    =+  peq=(~(harv pe sea.bah) now rtt.foy.bah)
    :-  =+  [fux=now mey=*(list ,[p=@da q=boon])]
        :~  =+  mey=*(list ,[p=@da q=boon])
            |-  ^-  (list ,[p=@da q=boon])
            ?~  r.p.peq  mey
            %=    $
                r.p.peq  t.r.p.peq
                fux      (add 0x1.0000.0000 fux) 
                mey      [[fux %ouzo lyn i.r.p.peq] mey]
            ==
        ::
            |-  ^-  (list ,[p=@da q=boon])
            ?~  s.p.peq  mey
            %=    $
                s.p.peq  t.s.p.peq
                fux      (add 0x1.0000.0000 fux) 
                mey      [[fux %coke %dead i.s.p.peq] mey]
            ==
        ==
    bah(foy ?~(r.p.peq foy.bah (slow foy.bah)), sea tea:q.peq)
  ::
  ++  have                                              ::    have:am 
    |=  [our=flag buq=buck]                             ::  acquire license
    ^-  [p=(list boon) q=fort]
    =:  ton.fox  (~(ha go ton.fox) our buq)
        zac.fox  (~(put by zac.fox) our *oven)
      ==
    [[[%beer our pac:ex:q:sen:(need (~(us go ton.fox) our))] ~] fox]
  ::
  ++  haze                                              ::    haze:am
    |=  [our=flag pov=oven]                             ::  roll per oven
    ^-  [p=(list (list ,[p=@da q=boon])) q=oven]
    =+  vaq=`(list ,[p=flag q=bath])`(~(tap by wab.pov) ~)
    =+  tol=*(list (list ,[p=@da q=boon]))
    |-  ^+  [tol pov]
    ?~  vaq
      [tol pov]
    =+  puk=(hast [our p.i.vaq] q.i.vaq)
    %=  $
      vaq      t.vaq
      tol      (weld p.puk tol)
      wab.pov  (~(put by wab.pov) p.i.vaq q.puk)
      wen.pov  ?:((lth p.sea.q.puk wen.pov) p.sea.q.puk wen.pov)
    ==
  ::
  ++  hark                                              ::    hark:am
    ^-  [p=(list boon) q=fort]                          ::  roll per fort
    =+  yus=`(list ,[p=flag q=oven])`(~(tap by zac.fox) ~)
    =+  tol=*(list (list ,[p=@da q=boon]))
    |-  ^-  [p=(list boon) q=fort]
    ?~  yus
      :-  %+  turn
            %+  sort
              |-  ^-  (list ,[p=@da q=boon])
              ?~(tol ~ (weld i.tol $(tol t.tol)))
            |=  [a=[p=@da q=boon] b=[p=@da q=boon]]
            ?.(=(p.a p.b) (lth p.a p.b) (lth (mug q.a) (mug q.b)))
          |=([p=@da q=boon] q)
      fox
    =+  qet=(haze i.yus)
    %=  $
      yus      t.yus
      tol      (weld p.qet tol)
      zac.fox  (~(put by zac.fox) p.i.yus q.qet)
      wen.fox  ?:((lth wen.q.qet wen.fox) wen.q.qet wen.fox)
    ==
  ::
  ++  home                                              ::    home:am
    |=  [our=flag lyn=lane]                             ::  update ip address
    ^-  fort
    =+  gus=(need (~(us go ton.fox) our))
    fox(ton (~(su go ton.fox) (fix:gus lyn)))
  ::
  ++  wash                                              ::    wash:am
    |=  [soq=sock sup=soap ham=meal]                    ::  dispatch and send
    ^-  [p=(list boon) q=fort]
    =+  sug=`_as:go`(need (~(us go ton.fox) p.soq))
    =.  fox  (wish soq sup ham)
    =^  bin  fox  corn:cool:(ad p.soq q.soq)
    =^  byn  fox  hark
    [(weld p.bin p.byn) fox]
  ::
  ++  wish                                              ::    wish:am
    |=  [soq=sock sup=soap ham=meal]                    ::  dispatch message
    ^-  fort
    =+  sug=`_as:go`(need (~(us go ton.fox) p.soq))
    =+  yem=`oven`(need (~(get by zac.fox) p.soq))
    =+  diz=`_lax:as:go`(myx:sug q.soq)
    =^  wyv  diz  (zuul:diz now ham)
    =+  ^=  bah  ^-  bath
        =+  bah=(~(get by wab.yem) q.soq)
        ?^(bah u.bah %*(. *bath foy baby)) 
    =:  p.sea.bah  now
        par.bah    (~(put by par.bah) sup [*snow wyv])
        maz.bah    (~(put to maz.bah) sup)
      ==
    %_    fox
        ton  (~(su go ton.fox) (nux:sug diz))
        zac  
      %+  ~(put by zac.fox)  p.soq
      %_  yem
        wab  (~(put by wab.yem) q.soq bah)
        wen  ?:((lth p.sea.bah wen.yem) p.sea.bah wen.yem)
      ==
    ==
  --                                                    ::  --am
::
++  ames                                                ::  terminal handling
  ^-  vane                                              ::  
  =|  $:  fox=fort                                      ::  kernel state
      ==                                                ::
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  current invocation
  ^?                                                    ::  opaque core
  =<
    |%                                                  ::  poke/peek pattern
    ++  beat                                            ::  process move
      |=  [whu=(unit flag) tea=tire hen=hose fav=card]
      ^-  [p=(list move) q=vane]
      =^  duy  ..knap
        (knap whu hen fav)
      [duy ..^$]
    ::
    ++  doze
      |=  hen=hose
      ^-  (unit ,[p=@da q=move])
      ~
    ::
    ++  scry
      |=  [our=flag ren=@tas his=flag lot=coin tyl=path]
      ^-  (unit)
      ?.  =(0 ren)  ~
      ?+    lot  ~
          [%% %ud @]
        (perm our his q.p.lot tyl)
      ::
          [%% %da @]
        ?.  =(now q.p.lot)  ~
        (temp our his tyl)
      ==
    --
  |%
  ++  clop
    |=  [whu=(unit flag) now=@da hen=hose bon=boon]
    ^-  [(list move) _+>]
    ?-    -.bon
        %beer
      :-  :~  [[~ p.bon] [/c/ hen] [%keep p.bon]]
              [[~ p.bon] hen [%init p.bon]]
          ==
      +>
    ::
        %coke  ~&([%coke p.bon q.bon] !!)
        %mead  !!
        %milk  !!
        %ouzo  ~&  [%send `@p`(mug (shaf %flap q.bon))]
               [[[whu hen [%send p.bon q.bon]] ~] +>.$]
        %wine  !!
    ==
  ::
  ++  knap
    |=  [whu=(unit flag) hen=hose fav=card]
    ^-  [(list move) _+>]
    ?:  ?=([%crud *] fav)
      [[[whu [/d/ hen] [%flog fav]] ~] +>]
    =+  ^=  fuy  ^-  [p=(list boon) q=fort]
        ?+    -.fav  
          [~ fox]
        ::
            %cash
          (~(have am [now fox]) p.fav q.fav)
        ::
            %home
          =.  fox  (~(home am [now fox]) p.fav q.fav)
          =+  dad=(sein p.fav)
          ?:  =(dad p.fav)  [~ fox]
          %^    ~(wash am [now fox])
              [p.fav dad]
            [%home p.fav hen]
          [%ping ~]
        ::
            %hear
          (~(gnaw am [now fox]) p.fav q.fav)
        ::
            %junk
          [~ fox(any.ton (shax (mix any.ton.fox p.fav)))]
        ::
            %make
          =+  vun=(~(come am [now fox]) p.fav (bex q.fav) r.fav)
          [[[%beer p.vun] ~] q.vun]
        ==
    =>  %_(. fox q.fuy)
    =|  out=(list move)
    |-  ^-  [p=(list move) q=_+>.^$]
    ?~  p.fuy
      [(flop out) +>.^$]
    =^  toe  +>.^$
      (clop whu now hen i.p.fuy)
    $(p.fuy t.p.fuy, out (weld (flop toe) out))
  ::
  ++  perm
    |=  [our=flag his=flag mar=@ud tyl=path]
    ^-  (unit)
    ?~  tyl  ~
    =+  gys=(~(us go ton.fox) our)
    ?~  gys  ~
    ?.  =(our his)
      ?:  ?=([%will ~] tyl)
        =+  fod=(~(get by hoc.saf.u.gys) his)
        ?~  fod  ~
        (rick mar his lew.wod.u.fod)
      ~
    ?:  ?=([%buck ~] tyl)
      =+  muc=(rice mar sex:u.gys)
      =+  luw=(rick mar our law.saf.u.gys)
      ?.  &(?=(^ muc) ?=(^ luw))  ~
      [~ `buck`[u.muc u.luw]]
    ?:  ?=([%will ~] tyl)
      (rick mar our law.saf.u.gys)
    ~
  ::
  ++  rand
    |=  [lem=@ ent=*]
    ^-  [p=@uvI q=_+>]
    =+  yan=(mix (sham ent) any.ton.fox)
    [(~(raw og yan) lem) +>.$(any.ton.fox (shax yan))]
  ::
  ++  temp
    |=  [our=flag his=flag tyl=path]
    ::  ~&  [%temp our his tyl]
    ^-  (unit)
    ?.  ?=([%mark ~] tyl)
      =+  muc=$(tyl [%mark ~])
      ?~  muc  ~
      (perm our his (,@ud u.muc) tyl)
    =+  gys=(~(us go ton.fox) our)
    ?~  gys  ~
    ?.  =(our his)
      =+  fod=(~(get by hoc.saf.u.gys) his)
      ?~  lew.wod.u.fod  ~
      [~ `@ud`p.p.q.i.lew.wod.u.fod]
    ?~  val.saf.u.gys  ~
    [~ `@ud`p.i.val.saf.u.gys]
  --
--
