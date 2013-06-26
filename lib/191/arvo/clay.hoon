!:
::  clay (4c), revision control
::
|=  pit=vase
^-  vane
=>
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  ::              section 4cA, filesystem logic         ::
  ::
  |%
  ::
  ++  un                                                ::  per seat
    |=  [who=@p now=@da ruf=raft]
    =+  ^=  yar  ^-  room
        =+  yar=(~(get by fat.ruf) who)
        ?~(yar *room u.yar)
    =|  yel=(list ,[p=duct q=tape])
    =|  wot=(list ,[p=duct q=tape])
    =|  byn=(list ,[p=duct q=riot]) 
    =|  say=(list ,[p=duct q=seat r=[p=@ud q=riff]])
    |%
    ++  abet
      ^-  [(list move) raft]
      :_  ruf(fat (~(put by fat.ruf) who yar))
      ;:  weld
        %+  turn  (flop yel)
        |=([a=duct b=tape] [[~ who] [/d a] [%flog %warn b]])
      ::
        %+  turn  (flop wot) 
        |=([a=duct b=tape] [[~ who] a [%wort b]])
      ::
        %+  turn  (flop byn) 
        |=([a=duct b=riot] [[~ who] a [%writ b]])
      ::
        %+  turn  (flop say) 
        |=([a=duct b=seat c=*] [[~ who] [/a a] [%want b %re c]])
      ==
    ::
    ++  doze
      =+  saz=(turn (~(tap by dos.yar) ~) |=([a=@tas b=*] a))
      =|  nex=(unit ,@da)
      |-  ^+   nex
      ?~  saz  nex
      $(saz t.saz, nex (hunt nex doze:(di i.saz)))
    ::
    ++  wake
      ^+  .
      =+  saz=(turn (~(tap by dos.yar) ~) |=([a=@tas b=*] a))
      |-  ^+  ..wake
      ?~  saz  ..wake
      $(saz t.saz, ..wake zoot:wake:(di i.saz))
    ::
    ++  de                                              ::  per desk
      |_  [syd=@ta lim=@da qyx=cult dom=dome]
      ++  aeon                                          ::  act count through
        |=  lok=case
        ^-  (unit ,@ud)
        ?-    -.lok
            %da
          ?:  (gth p.lok lim)  ~
          |-  ^-  (unit ,@ud)
          ?~  hit.dom  [~ let.dom]
          ?:  (gth p.lok p.i.hit.dom)  [~ let.dom]
          $(hit.dom t.hit.dom, let.dom (dec let.dom))
        :: 
            %tas  (~(get by lab.dom) p.lok)
            %ud   ?:((gte p.lok let.dom) ~ [~ +(p.lok)])
        ==
      ::
      ++  amor                                          ::  endpoint query
        |=  ren=?(%x %y %z)
        ^-  (unit ,*)
        ?-  ren
          %x  ?.(?=(& -.arc.dom) ~ [~ q.arc.dom])
          %y  :-  ~
              ?-  -.arc.dom
                &  [& p.arc.dom]
                |  [| (turn (~(tap by p.arc.dom) ~) |=([p=@ta *] p))]
              ==
          %z  [~ arc.dom]
        ==
      ::
      ++  argo                                          ::  rewind to aeon
        |=  oan=@ud
        ^+  +>
        ?:  =(let.dom oan)  +>
        ?>  ?=(^ hit.dom)
        %=  $
          let.dom  (dec let.dom)
          hit.dom  t.hit.dom
          arc.dom  ?.  ?=(& -.q.i.hit.dom)  arc.dom
                   arc:(dusk:ka:(cu arc.dom) p.q.i.hit.dom)
          lab.dom  ?.  ?=(| -.q.i.hit.dom)  lab.dom
                   (~(del by lab.dom) p.q.i.hit.dom)
        ==
      ::
      ++  auto                                          ::  read at point
        |=  mun=mood
        ^-  (unit)
        ?:  &(?=(%w p.mun) !?=(%ud -.q.mun))
          ?^(r.mun ~ [~ let.dom])
        ?:  ?=(%w p.mun)
          ?>  ?=(^ hit.dom)  ?^(r.mun ~ [~ i.hit.dom])
        (amor(arc.dom arc:(deny:ka:(cu arc.dom) r.mun)) p.mun)
      ::
      ++  aver                                          ::  domestic read 
        |=  mun=mood
        ^-  (unit (unit ,*))
        =+  nao=(aeon q.mun)
        ?~(nao ~ [~ (avid u.nao mun)])
      ::
      ++  avid                                          ::  seek and read
        |=  [oan=@ud mun=mood]
        ^-  (unit)
        ?:  &(?=(%w p.mun) !?=(%ud -.q.mun))            ::  NB optimization
          ?^(r.mun ~ [~ oan])
        (auto:(argo oan) mun)
      ::
      ++  balk                                          ::  read and send
        |=  [hen=duct oan=@ud mun=mood]
        ^+  +>
        =+  vid=(avid oan mun)
        ?~  vid  (blob hen)  (blab hen mun u.vid)
      ::
      ++  blab                                          ::  ship result
        |=  [hen=duct mun=mood dat=*]
        ^+  +>
        +>(byn [[hen ~ [p.mun q.mun syd] r.mun dat] byn])
      ::
      ++  bleb                                          ::  ship sequence
        |=  [hen=duct ins=@ud hip=(list frog)]
        ^+  +>
        ?~  hip  +>
        %=  $
          hip  t.hip
          ins  +(ins)
          +>   (blab hen [%w [%ud ins] ~] i.hip)
        == 
      ::
      ++  blob                                          ::  ship stop
        |=  hen=duct
        %_(+> byn [[hen ~] byn])
      ::
      ++  doze                                          ::  sleep until
        =+  xiq=(~(tap by qyx) ~)
        =|  nex=(unit ,@da)
        |-  ^+  nex
        ?~  xiq  nex
        =+  ^=  zis  ^+  nex
            ?-    -.q.i.xiq
                &  ?.(?=(%da -.q.p.q.i.xiq) ~ [~ p.q.p.q.i.xiq])
            ::
                |
              =+  mot=`moat`p.q.i.xiq
              %+  hunt
                ?.(&(?=(%da -.p.mot) (lth now p.p.mot)) ~ [~ p.p.mot])
              ?.(&(?=(%da -.q.mot) (lth now p.q.mot)) ~ [~ p.q.mot])
            ==
        $(xiq t.xiq, nex (hunt nex zis))
      ::
      ++  ease                                          ::  unsubscribe
        |=  hen=duct
        ^+  +>
        +>(qyx (~(del by qyx) hen))
      ::
      ++  eave                                          ::  subscribe
        |=  [hen=duct rav=rave]
        ^+  +>
        ?-    -.rav
            &
          =+  ver=(aver p.rav)
          ?~  ver  
            +>.$(qyx (~(put by qyx) hen rav))
          ?~  u.ver
            (blob hen)
          (blab hen p.rav u.u.ver)
        ::
            |
          =+  nab=(aeon p.p.rav)
          ?~  nab
            ?>  =(~ (aeon q.p.rav))
            +>.$(qyx (~(put by qyx) hen rav))
          =+  huy=(aeon q.p.rav)
          ?:  &(?=(^ huy) |((lth u.huy u.nab) &(=(0 u.huy) =(0 u.nab))))
            (blob hen)
          =+  top=?~(huy let.dom u.huy)
          =+  seb=(slag (sub let.dom top) hit.dom)
          =+  wid=(sub top u.nab)
          =+  fud=(flop (scag wid seb))
          =.  +>.$  (bleb hen u.nab fud)
          ?^  huy 
            (blob hen)
          =+  ^=  ptr  ^-  case
              ?:  =(0 u.nab)  [%da @da]
              =+(old=(slag wid seb) ?>(?=(^ old) `case`[%da p.i.old]))
          +>.$(qyx (~(put by qyx) hen `rave`[%| ptr q.p.rav]))
        ==
      ::
      ++  edit                                          ::  apply changes
        |=  [wen=@da lav=nori]
        ^+  +>
        %=  +>.$
          arc.dom  ?.  ?=(& -.lav)  arc.dom 
                   arc:(durn:ka:(cu arc.dom) p.lav)
          let.dom  +(let.dom)
          hit.dom  :_(hit.dom [wen lav])
          lab.dom  ?.  ?=(| -.lav)  lab.dom
                   ?<  (~(has by lab.dom) p.lav)
                   (~(put by lab.dom) p.lav let.dom)
        ==
      ::
      ++  exec                                          ::  change and update
        |=  [wen=@da lav=nori]
        ^+  +>
        wake:(edit wen lav)
      ::
      ++  wake                                          ::  update subscribers
        ^+  .
        =+  xiq=(~(tap by qyx) ~)
        =|  xaq=(list ,[p=duct q=rave])
        |-  ^+  ..wake
        ?~  xiq  ..wake(qyx (~(gas by *cult) xaq))
        ?-    -.q.i.xiq
            &
          =+  nao=(aeon q.p.q.i.xiq)
          ?~  nao  $(xiq t.xiq, xaq [i.xiq xaq])
          $(xiq t.xiq, ..wake (balk p.i.xiq u.nao p.q.i.xiq))
        ::
            |
          =+  mot=`moat`p.q.i.xiq
          =+  nab=(aeon p.mot)
          ?:  |(?=(~ nab) =(let.dom u.nab))
            $(xiq t.xiq, xaq [i.xiq xaq])
          ?>  (gth let.dom u.nab)
          ?>  ?=(^ hit.dom)
          =+  huy=(aeon q.mot)
          ?~  huy
            =+  ptr=[%da p.i.hit.dom]
            =+  fud=(flop (scag (sub let.dom u.nab) `(list frog)`hit.dom))
            %=  $
              xiq     t.xiq
              xaq     [[p.i.xiq [%| ptr q.mot]] xaq]
              ..wake  (bleb p.i.xiq let.dom fud)
            ==
          =+  yad=(slag (sub let.dom u.huy) `(list frog)`hit.dom)
          =+  fud=(flop (scag (sub u.huy u.nab) yad))
          %=  $
            xiq     t.xiq
            ..wake  (blob:(bleb p.i.xiq +(u.nab) fud))
          ==
        ==
      ::
      ++  zoot
        %_(..de dos.yar (~(put by dos.yar) syd qyx dom))
      --
    ::
    ++  di
      |=  syd=@ta
      =+  ^=  saq  ^-  desk
          =+  saq=(~(get by dos.yar) syd)
          ?~(saq [~ [[%| ~] 0 ~ ~]] u.saq)
      ~(. de syd now p.saq q.saq)
    ::
    ++  fa
      |=  him=seat
      =+  ^=  raz
          =+  raz=(~(get by rid.yar) him)
          ?~(raz [p=*rind q=*rink] u.raz)
      |%
      ++  mete                                          ::  foreign request
        |=  [hen=duct ryf=riff]
        ^+  +>
        =+  nux=(~(get by fod.p.raz) hen)
        ?^  nux
          ?>  ?=(~ q.ryf)
          %=  +>.$
            say      [[[[%c (scot %ud u.nux) ~] hen] him [u.nux ryf]] say]
            fod.p.raz  (~(del by fod.p.raz) hen)
            bim.p.raz  (~(del by bim.p.raz) u.nux)
          ==
        ?>  ?=(^ q.ryf)
        =+  inx=nix.p.raz
        %=  +>.$
          say      [[[[%c (scot %ud inx) ~] hen] him [inx ryf]] say]
          nix.p.raz  +(nix.p.raz)
          bim.p.raz  (~(put by bim.p.raz) inx [hen ryf])
          fod.p.raz  (~(put by fod.p.raz) hen inx)
        ==
      ::
      ++  mote                                          ::  send/cancel request
        |=  [hen=duct ryf=riff]
        ^+  +>
        =+  rym=(~(get by mir.q.raz) p.ryf)
        ?~  rym  (mete hen ryf)
        =+  wex=~(. de [p.ryf lim.u.rym qyx.u.rym dom.u.rym])
        =+  wak=?~(q.ryf (ease:wex hen) (eave:wex hen u.q.ryf))
        =:  byn        byn.wak
            qyx.u.rym  qyx.wak
            dom.u.rym  dom.wak
          ==
        +>.$(mir.q.raz (~(put by mir.q.raz) p.ryf u.rym))
      ::
      ++  poll                                          ::  pull result
        |=  [hen=duct syd=disc rot=riot]
        ^+  +>
        =+  rum=(need (~(get by mir.q.raz) syd))
        =+  kas=(need ask.rum)
        =^  wex  rum
          ?~  rot
            :_  rum(ask ~, lim kas)
            ~(. de [syd kas qyx.rum dom.rum])
          ?>  ?=(%w p.p.u.rot)
          ?>  =(syd r.p.u.rot)
          ?>  =(~ q.u.rot)
          ?>  ?=(%ud -.q.p.u.rot)
          ?>  =(let.dom.rum p.q.p.u.rot)
          =+  rog=((hard frog) r.u.rot)
          :_  rum
          (~(exec de [syd lim.rum qyx.rum dom.rum]) rog)
        =+  wak=wake:wex
        =.  byn  byn.wak
        =.  qyx.rum  qyx.wak
        =.  dom.rum  dom.wak
        +>.$(mir.q.raz (~(put by mir.q.raz) syd rum))
      ::
      ++  puke                                          ::  pull failed
        |=  [hen=duct syd=disc msg=tape]
        ^+  +>
        %_  +>
          mir.q.raz  (~(del by mir.q.raz) syd)
          yel        [[hen msg] yel]
        ==
      ::
      ++  pull                                          ::  pull changeset
        |=  [hen=duct syd=disc]
        ^+  +>
        =+  ^=  rum  ^-  rede
            =+  rum=(~(get by mir.q.raz) syd)
            ?^  rum  u.rum  [~2000.1.1 ~ ~ [[%| ~] 0 ~ ~]]
        ?>  ?=(~ ask.rum)
        =>  .(ask.rum [~ now])
        =.  +>.$
          %+  mete
            [[%c (scot %p him) syd ~] hen]
          [syd ~ %| [%da lim.rum] [%da now]]
        +>.$(mir.q.raz (~(put by mir.q.raz) syd rum))
      ::       
      ++  tome                                          ::  accept response
        |=  [inx=@ud rot=riot]
        ^+  +>
        ::  ~&  [%clay-tome inx ?~(rot ~ [p.u.rot q.u.rot])]
        =+  mub=(~(get by bim.p.raz) inx)
        ?~  mub  +>.$
        =+  die=?~(rot & &(?=(^ q.q.u.mub) ?=(& -.u.q.q.u.mub)))
        %=  +>.$
          byn      [[p.u.mub rot] byn]
          bim.p.raz  ?.(die bim.p.raz (~(del by bim.p.raz) inx))
          fod.p.raz  ?.(die fod.p.raz (~(del by fod.p.raz) p.u.mub))
          hac.q.raz  ?~  rot 
                       hac.q.raz 
                     %+  ~(put by hac.q.raz) 
                       [p.p.u.rot q.p.u.rot r.p.u.rot q.u.rot]
                     r.u.rot
        ==
      ::
      ++  tref                                          ::  request rejected
        |=  [hen=duct tea=wire]
        ^+  +>
        ::  ~&  [%clay-tref tea]
        ?.  ?=([@ *] tea)  +>
        =+  xoc=(slay i.tea)
        ?:  ?=([~ %% %p @] xoc)
          ?>  ?=([@ ~] t.tea) 
          (puke hen i.t.tea "system failure")
        ?.  ?=([~ %% %ud @] xoc)  +>.$
        =+  mub=(~(get by bim.p.raz) q.p.u.xoc)
        ?~  mub  +>.$
        %=  +>.$
          byn      [[p.u.mub ~] byn]
          fod.p.raz  (~(del by fod.p.raz) q.p.u.xoc)
        ==
      ::
      ++  vera                                          ::  search
        |=  [syd=@tas ren=care lok=case way=path]
        ^-  (unit)
        =+  rym=(~(get by mir.q.raz) syd)
        ?~  rym
          (~(get by hac.q.raz) ren lok syd way)
        =+  vyr=(~(aver de [syd lim.u.rym qyx.u.rym dom.u.rym]) ren lok way)
        ?~(vyr ~ u.vyr)
      ::
      ++  zoom
        %_(+>.$ rid.yar (~(put by rid.yar) him raz))
      --
    --
  --
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  ::              section 4cA, filesystem vane          ::
  ::                                                    ::
  =|                                                    ::  instrument state
      $:  ruf=raft                                      ::  revision tree
      ==                                                ::
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  activate
  ^?                                                    ::  opaque core
  |%                                                    ::
  ++  beat                                              ::  update
    |=  [whu=(unit seat) tea=wire hen=duct fav=*]
    =>  .(fav ((hard card) fav))
    ^-  [p=(list move) q=vane]
    ?+    -.fav  ~&  [%clay-none fav]
                 !!
        %crud
      [[[whu [/d hen] %flog fav] ~] ..^$]
    ::
        %edit
      =.  whu  
          ?^  whu  whu
          ?.  =(%gold (adit hen))  ~
          [~ p.fav] 
      ?>  =(u.whu p.fav)
      =+  ^=  yaq  ^-  (list move)
          ?.  ?=(& -.r.fav)  ~
          =+  one=~(rend co ~ %p u.whu)
          =+  two=(rip 3 q.fav)
          %+  turn
            p.r.fav
          |=  [pax=path mis=miso]  ^-  move
          =+  qua=~(ram re (dish:ut [~ %path] pax))
          =+  ^=  qui
              ?-(-.mis %del '-', %ins '+', %mut ':')
          [whu [/d hen] %flog %note qui %leaf "{one}/{two}{qua}"]
      =^  mos  ruf  
        abet:zoot:(exec:(di:wake:(un u.whu now ruf) q.fav) now r.fav)
      [(weld yaq mos) ..^$]
    ::
        %keep
      ::  [[%tell %0 %leaf "clay: home for {~(rend co ~ %p u.whu)}"] ~]
      [~ ..^$(fat.ruf (~(put by fat.ruf) u.whu *room))]
    ::
        %pull
      ?>  ?=(^ whu)
      ?>  !=(u.whu p.fav) 
      =^  mos  ruf
        abet:zoom:(pull:(fa:(un u.whu now ruf) p.fav) hen q.fav)
      [mos ..^$]
    ::
        %warp
      ?>  ?=(^ whu)
      =^  mos  ruf
        =<  abet
        =+  une=(un u.whu now ruf)
        ::  ~&  [%warp u.whu p.fav]
        ?.  =(u.whu p.fav)
          zoom:(mote:(fa:une p.fav) hen q.fav)
        =+  wex=(di:une p.q.fav)
        ?~  q.q.fav
          zoot:(ease:wex hen)
        zoot:(eave:wex hen u.q.q.fav)
      [mos ..^$]
    ::
        %wart
      ?>  ?=(%ru q.fav)
      ?~  s.fav  [~ ..^$]
      =^  mos  ruf
        =<  abet
        =<  zoom
        (tome:(fa:(un u.whu now ruf) p.fav) ((hard ,[@ud riot]) u.s.fav))
      [mos ..^$]
    ::
        %went
      ?:  =(%good q.fav)  [~ ..^$]
      =^  mos  ruf
        abet:zoom:(tref:(fa:(un u.whu now ruf) p.fav) hen tea)
      [mos ..^$]
    ::
        %wake
      =+  dal=(turn (~(tap by fat.ruf) ~) |=([a=@p b=room] a))
      =|  mos=(list move)
      |-  ^-  [p=(list move) q=vane]
      ?~  dal  [mos ..^^$(las.ruf now)] 
      =^  som  ruf  abet:wake:(un i.dal now ruf)
      $(dal t.dal, mos (weld som mos))
    ::
        %wort
      ?>  ?=([@ @ ~] tea)
      =+  xoc=(slay i.tea)
      ?>  ?=([~ %% %p @] xoc)
      =^  mos  ruf
        =<  abet
        =<  zoom
        (puke:(fa:(un u.whu now ruf) q.p.u.xoc) hen i.t.tea p.fav)
      [mos ..^$]
    ::
        %writ
      ?>  ?=([@ @ ~] tea)
      =+  xoc=(slay i.tea)
      ?>  ?=([~ %% %p @] xoc)
      =^  mos  ruf
        abet:zoom:(poll:(fa:(un u.whu now ruf) q.p.u.xoc) hen i.t.tea p.fav)
      [mos ..^$]
    ==
  ::
  ++  come  |=(old=vase (load old))
  ++  doze
    |=  [now=@da hen=duct]
    =|  nex=(unit ,@da)
    =+  dal=(turn (~(tap by fat.ruf) ~) |=([a=@p b=room] a))
    |-  ^+  nex
    ?~  dal  nex
    $(dal t.dal, nex (hunt nex doze:(un i.dal now ruf)))
  ::
  ++  flee  stay
  ::
  ++  load
    |=  new=vase
    ^-  vane
    ?.  (~(nest ut -:!>(ruf)) & p.new)
      ~|(%load-nest-clay !!)
    ..^$(ruf (raft q.new))
  ::
  ++  raze
    ^-  vane
    ..$(ruf *raft)
  ::
  ++  scry                                              ::  inspect
    |=  [our=seat ron=@tas his=seat syd=disc lot=coin tyl=path]
    ^-  (unit)
    =+  luk=?.(?=(%% -.lot) ~ ((soft case) p.lot))
    =+  run=((soft care) ron)
    ?~  luk  ~
    ?~  run  ~
    ?.  =(our his)
      (vera:(fa:(un our now ruf) his) syd u.run u.luk tyl)
    =+  vyr=(aver:(di:(un our now ruf) syd) u.run u.luk tyl)
    ?~(vyr ~ u.vyr)
  ::
  ++  stay  `vase`!>(ruf)
  --
