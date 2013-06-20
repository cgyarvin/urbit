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
    =|  byn=(list ,[p=duct q=riot]) 
    =|  say=(list ,[p=duct q=seat r=[p=@ud q=riff]])
    |%
    ++  de                                              ::  per desk
      |_  [buk=@ta qyx=cult dom=dome]
      ++  aeon                                          ::  mark to era
        |=  lok=case
        ^-  (unit ,@ud)
        ?-    -.lok
            %da
          ?:  (gth p.lok now)  ~
          =+  deq=?:(=(0 let.dom) ~ [~ (dec let.dom)])
          |-  ^+  deq
          ?~  hit.dom  deq
          ?:  (gth p.lok p.i.hit.dom)  deq
          =+  nix=(dec let.dom)
          $(hit.dom t.hit.dom, let.dom nix, deq [~ nix])
        :: 
            %tas  (~(get by lab.dom) p.lok)
            %ud   ?:((gte p.lok let.dom) ~ [~ p.lok])
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
      ++  ammo                                          ::  trace window
        |=  oan=@ud
        =|  bul=(list ,[p=@da q=ukay])
        |-  ^+  [bul +>.^$]
        ?:  =(oan (dec let.dom))  [(flop bul) +>.^$]
        %=  $
          bul      [[p.i.hit.dom r.i.hit.dom] bul]
          let.dom  (dec let.dom)
          hit.dom  t.hit.dom
          arc.dom  arc:(durn:ka:(ci arc.dom) q.i.hit.dom)
        ==
      ::
      ++  argo  |=(oan=@ud +:(ammo oan))                ::  revert to era
      ++  aver                                          ::  domestic read 
        |=  [ren=care lok=case way=path]
        ^-  (unit (unit ,*))
        =+  nao=(aeon lok)
        ::  ~&  [%aver buk lok nao]
        ?~  nao  ~
        :-  ~
        ?:  ?=(%w ren)
          ?.(?=(~ way) ~ [~ u.nao])
        =.  +>.$  (argo u.nao)
        (amor(arc.dom dark:(deny:ka:(ci arc.dom) way)) ren)
      ::
      ++  biff                                          ::  path subset
        |=  [yok=path gib=path]
        ^-  (unit path)
        ?~  yok  [~ gib]
        ?~  gib  ~
        ?.  =(i.yok i.gib)  ~
        $(yok t.yok, gib t.gib)
      ::
      ++  blab                                          ::  ship result
        |=  [hen=duct ren=care lok=case way=path dat=*]
        ^+  +>
        +>(byn [[hen ~ [ren lok buk] way dat] byn])
      ::
      ++  demo                                          ::  ship snapshot
        |=  [hen=duct ren=care lok=case way=path]
        ^+  +>
        %=    +>
            byn
          =<  byn
          ^+  +>
          ?:  ?=(%w ren)
            ?^  way  +>
            (blab hen ren lok ~ let.dom)
          =.  arc.dom  dark:(deny:ka:(ci arc.dom) way)
          ?:  ?=(%z ren)
            (blab hen ren lok way arc.dom)
          =+  yaw=(flop way)
          |-  ^+  +>.^$
          ?-    -.arc.dom
              &  
            (blab hen ren lok (flop yaw) ?:(?=(%y ren) [& p.arc.dom] q.arc.dom))
          ::
              |
            =+  goz=(~(tap by p.arc.dom) ~)
            =>  .(arc.dom `arch`arc.dom)
            =.  +>.^$  
              ?.  ?=(%y ren)  +>.^$
              (blab hen ren lok (flop yaw) [| (turn goz |=([p=@ta *] p))])
            |-  ^+  +>.^^$
            ?~  goz  +>.^^$
            $(goz t.goz, +>.^^$ ^$(yaw [p.i.goz yaw], arc.dom q.i.goz))
          ==
        ==
      ::
      ++  doze
        =+  xiq=(~(tap by qyx) ~)                   ::  XX tap
        =|  nex=(unit ,@da)
        |-  ^+  nex
        ?~  xiq  nex
        ?.  ?=(%da -.q.q.i.xiq)  $(xiq t.xiq)
        %=    $
            xiq  t.xiq
            nex
          %+  hunt  nex
          ?:  (lth now p.q.q.i.xiq)  [~ p.q.q.i.xiq]
          ?~(q.q.q.i.xiq ~ ?>((lth now u.q.q.q.i.xiq) q.q.q.i.xiq))
        ==
      ::
      ++  ease                                          ::  unsubscribe
        |=  hen=duct
        ^+  +>
        +>(qyx (~(del by qyx) hen))
      ::
      ++  eave                                          ::  subscribe
        |=  [hen=duct ren=care myn=morn way=path]
        ^+  +>
        ?-    -.myn
            %da
          =+  nao=(aeon [%da p.myn])
          ?~  nao
            +>.$(qyx (~(put by qyx) hen ren myn way))
          =+  oap=?~(q.myn ~ (aeon %da u.q.myn))
          =+  ^=  nyb  ^+  byn
              =.  +>.$  ?~(oap +>.$ (argo u.oap))
              =^  giz  +>.$  (ammo u.nao)
              =.  +>.$  (demo hen ren [%da p.myn] way)
              =<  byn
              |-  ^+  +>.^$
              ?~  giz  +>.^$
              =.  +>.^$  (ecce q.i.giz hen ren [%da p.i.giz] way)
              $(+>.^$ (edit(now p.i.giz) q.i.giz))
          %=  +>.$
            byn      ?~(oap nyb [[hen ~] nyb])
            qyx  ?^(oap qyx (~(put by qyx) hen ren myn way))
          ==
        ::
            ?(%tas %ud)
          =+  lok=`case`?-(-.myn %tas [%tas p.myn], %ud [%ud p.myn])
          =+  nao=(aeon lok)
          ?~  nao  
            +>.$(qyx (~(put by qyx) hen ren myn way))
          +>.$(byn [[hen ~] byn:(demo:(argo u.nao) hen ren lok way)])
        ==
      ::
      ++  ecce                                          ::  send changes
        |=  [lav=ukay hen=duct ren=care lok=case way=path]
        ^+  +>
        ?-    ren
            %w
          ?^  way  +>
          (blab hen ren lok ~ (dec let.dom))
        ::
            %x
          |-  ^+  +>.^$
          ?~  lav  +>.^$
          ?.  ?=(%ins -.q.i.lav)  $(lav t.lav)
          =+  gim=(biff way p.i.lav)
          ?~  gim  $(lav t.lav)
          $(lav t.lav, +>.^$ (blab hen ren lok p.i.lav r.q.i.lav))
        ::
            %y
          !!
        ::
            %z
          !!
        ==
      ::
      ++  ecco                                          ::  ship release
        |=  lol=@tas
        ^+  +>
        ?<  |(=(0 let.dom) (~(has by lab.dom) lol))
        =.  lab.dom  (~(put by lab.dom) lol (dec let.dom))
        =+  xiq=(~(tap by qyx) ~)                   ::  XX tap
        |-  ^+  +>.^$
        ?~  xiq  +>.^$
        ?.  &(?=(%tas -.q.q.i.xiq) =(lol p.q.q.i.xiq)) $(xiq t.xiq)
        $(xiq t.xiq, +>.^$ (demo p.i.xiq p.q.i.xiq [%tas lol] r.q.i.xiq))
      ::
      ++  edit                                          ::  apply changes
        |=  lav=ukay
        ^+  +>
        ::  ~&  [%edit buk lav]
        =+  wak=darn:(durn:ka:(ci arc.dom) lav)
        %=  +>.$
          arc.dom  q.wak
          let.dom  +(let.dom)
          hit.dom  :_(hit.dom [now p.wak lav])
        ==
      ::
      ++  exec                                          ::  propagate changes
        |=  lav=ukay
        ^+  +>
        =+  xiq=(~(tap by qyx) ~)                   ::  XX tap
        =|  dem=(list ,[p=duct q=care r=case s=path])
        |-  ^+  +>.^$
        ?~  xiq  
          =.  +>.^$  (edit lav)
          |-  ^+  +>.^^$
          ?~  dem  +>.^^$
          =.  +>.^^$  (demo i.dem)
          =.  byn  [[p.i.dem ~] byn]
          $(dem t.dem)
        ?-    -.q.q.i.xiq
            %da
          %=  $
            xiq    t.xiq
            +>.^$  (ecce lav p.i.xiq p.q.i.xiq [%da now] r.q.i.xiq)
          ==
            %tas  $(xiq t.xiq)
            %ud
          ?.  =(let.dom p.q.q.i.xiq)  $(xiq t.xiq)
          %=  $
            xiq  t.xiq
            dem  :_(dem [p.i.xiq p.q.i.xiq [%ud let.dom] r.q.i.xiq])
            qyx  (~(del by qyx) p.i.xiq)
          ==
        ==
      ::
      ++  wake                                          ::  react to time
        ^+  .
        =+  xiq=(~(tap by qyx) ~)                   ::  XX tap
        |-  ^+  ..wake
        ?~  xiq  ..wake
        ?.  ?=(%da -.q.q.i.xiq)  $(xiq t.xiq)
        =.  ..wake
          ?.  &((lth las.ruf p.q.q.i.xiq) (gte now p.q.q.i.xiq))  ..wake
          (demo p.i.xiq p.q.i.xiq [%da now] r.q.i.xiq)
        =.  byn
          ?.  &(?=(^ q.q.q.i.xiq) (gte now u.q.q.q.i.xiq))  byn
          [[p.i.xiq ~] byn]
        $(xiq t.xiq)
      ::
      ++  zoot
        %_(..de dos.yar (~(put by dos.yar) buk qyx dom))
      --
    ::
    ++  di
      |=  buk=@ta
      =+  ^=  saq  ^-  desk
          =+  saq=(~(get by dos.yar) buk)
          ?~(saq [~ [[%| ~] 0 ~ ~]] u.saq)
      ~(. de buk p.saq q.saq)
    ::
    ++  fa
      |=  him=seat
      =+  ^=  raz
          =+  raz=(~(get by rid.yar) him)
          ?~(raz [p=*rind q=*rink] u.raz)
      |%
      ++  mote                                          ::  send/cancel request
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
      ++  tome                                          ::  accept response
        |=  [inx=@ud rot=riot]
        ^+  +>
        ::  ~&  [%clay-tome inx rot]
        =+  mub=(~(get by bim.p.raz) inx)
        ?~  mub  +>.$
        %=  +>.$
          byn      [[p.u.mub rot] byn]
          bim.p.raz  (~(del by bim.p.raz) inx)
          fod.p.raz  (~(del by fod.p.raz) p.u.mub)
          hac.q.raz  ?~  rot 
                     hac.q.raz 
                   %+  ~(put by hac.q.raz) 
                     [p.p.u.rot q.p.u.rot r.p.u.rot q.u.rot]
                   r.u.rot
        ==
      ::
      ++  tref                                          ::  request rejected
        |=  tea=wire
        ^+  +>
        ?.  ?=([@ ~] tea)  +>
        =+  xoc=(slay i.tea)
        ?.  ?=([~ %% %ud @] xoc)  +>.$
        =+  mub=(~(get by bim.p.raz) q.p.u.xoc)
        ?~  mub  +>.$
        %=  +>.$
          byn      [[p.u.mub ~] byn]
          fod.p.raz  (~(del by fod.p.raz) q.p.u.xoc)
        ==
      ::
      ++  vera                                          ::  search
        |=  [buk=@tas ren=care lok=case way=path]
        (~(get by hac.q.raz) ren lok buk way)
      ::
      ++  zoom
        %_(+>.$ rid.yar (~(put by rid.yar) him raz))
      --
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
    ++  zonk
      ^-  [(list move) raft]
      :-  %+  weld
            %+  turn  (flop byn) 
            |=([a=duct b=riot] [[~ who] a [%writ b]])
          %+  turn  (flop say) 
          |=([a=duct b=seat c=*] [[~ who] [/a a] [%want b %re c]])
      ruf(fat (~(put by fat.ruf) who yar))
    --
  --
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  ::              section 4cA, filesystem vane          ::
  ::
  =|                                                    ::  instrument state
      $:  ruf=raft                                      ::  revision tree
      ==                                                ::
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  activate
  ^?                                                    ::  opaque core
  |%                                                    ::
  ++  beat                                              ::  update
    |=  [whu=(unit seat) tea=wire hen=duct fav=card]
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
          =+  one=~(rend co ~ %p u.whu)
          =+  two=(rip 3 q.fav)
          %+  turn
            r.fav
          |=  uke=ukaz  ^-  move
          =+  qua=~(ram re (dish:ut [~ %path] p.uke))
          =+  ^=  qui
              ?-(-.q.uke %del '-', %ins '+', %mut ':')
          [whu [/d hen] %flog %note qui %leaf "{one}/{two}{qua}"]
      =^  mos  ruf  zonk:zoot:(exec:(di:wake:(un u.whu now ruf) q.fav) r.fav)
      [(weld yaq mos) ..^$]
    ::
        %keep
      ::  [[%tell %0 %leaf "clay: home for {~(rend co ~ %p u.whu)}"] ~]
      [~ ..^$(fat.ruf (~(put by fat.ruf) u.whu *room))]
    ::
        %ship
      ?>  ?=(^ whu)
      =^  mos  ruf  zonk:zoot:(ecco:(di:wake:(un u.whu now ruf) p.fav) q.fav)
      [mos ..^$]
    ::
        %warp
      ?>  ?=(^ whu)
      =^  mos  ruf
        =<  zonk
        =+  une=(un u.whu now ruf)
        ::  ~&  [%warp u.whu p.fav]
        ?.  =(u.whu p.fav)
          zoom:(mote:(fa:une p.fav) hen q.fav)
        =+  dic=(di:une p.q.fav)
        ?~  q.q.fav
          zoot:(ease:dic hen)
        zoot:(eave:dic hen u.q.q.fav)
      [mos ..^$]
    ::
        %wart
      ?>  ?=(%ru q.fav)
      ?~  s.fav  [~ ..^$]
      =^  mos  ruf
        =<  zonk
        =<  zoom
        (tome:(fa:(un u.whu now ruf) p.fav) ((hard ,[@ud riot]) u.s.fav))
      [mos ..^$]
    ::
        %went
      ?:  =(%good q.fav)  [~ ..^$]
      =^  mos  ruf
        zonk:zoom:(tref:(fa:(un u.whu now ruf) p.fav) tea)
      [mos ..^$]
    ::
        %wake
      =+  dal=(turn (~(tap by fat.ruf) ~) |=([a=@p b=room] a))
      =|  mos=(list move)
      |-  ^-  [p=(list move) q=vane]
      ?~  dal  [mos ..^^$(las.ruf now)] 
      =^  som  ruf  zonk:wake:(un i.dal now ruf)
      $(dal t.dal, mos (weld som mos))
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
