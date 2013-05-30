!:
::  born (4b), shell
::
  |=  pit=vase
  ^-  vane
  =>  =~
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  ::              section 4bA, shell models             ::
  ::
  |%
  ++  brad                                              ::  session/dynamic
    $:  who=seat                                        ::  identity
        hit=[p=@ud q=(list ,@t)]                        ::  command history
        sur=[p=@ud q=(qeu vase)]                        ::  result history
        fog=[p=@ud q=(list ,@ud) r=(map ,@ud gyre)]     ::  console activities
        hox=@ta                                         ::  identity text
        cwc=path                                        ::  working cord
        cwd=@tas                                        ::  working disc
        way=(map ,@tas vase)                            ::  variables
        lif=dock                                        ::  process table
    ==                                                  ::
  ::                                                    ::
  ++  bran                                              ::  static "state"
    $:  nub=vase                                        ::  
        ^=  vax                                         ::  chestnut vases
      $:  sot=vase                                      ::  'slot'
      ==                                                ::
        ^=  gen                                         ::
      $:  yom=gene                                      ::  '*(set ,@tas)'
          zim=gene                                      ::  '*(map ,@tas ,*)'
      ==                                                ::
        ^=  typ                                         ::  chestnut types
      $:  cof=type                                      ::  '*conf'
          gee=type                                      ::  '*gene'
          liz=type                                      ::  '*(list ,@t)'
          pah=type                                      ::  '*path'
          noq=type                                      ::  '*note'
          tak=type                                      ::  '*task'
          vas=type                                      ::  '*vase'
      ==                                                ::
        hub=@ta                                         ::  (hoof stub)
    ==                                                  ::
  --                                                    ::
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  ::              section 4bB, session engine           ::
  ::
  |%
  ++  bard                                              ::  new session
    |=  who=seat
    %+  barn  who
    %*  .  *brad
      who    who
      p.fog  1
      p.lif  1
      q.fog  [0 ~]
      hox    (scot %p who)
      cwd    %try
    ==
  ::
  ++  barn
    |=  [who=seat bad=brad]
    =+  nib=pit
    =+  pal=~(play ut p.nib)
    %-  berg
    :_  bad
    %*  .  *bran
      nub      nib
      sot.vax  (slap nib (vice 'slot'))
      yom.gen  (vice '*(set ,@tas)')
      zim.gen  (vice '*(map ,@tas ,*)')
      cof.typ  (pal (vice '*conf'))
      gee.typ  (pal (vice '*gene'))
      liz.typ  (pal (vice '*(list ,@t)'))
      pah.typ  (pal (vice '*path'))
      noq.typ  (pal (vice '*note'))
      tak.typ  (pal (vice '*task'))
      vas.typ  (pal (vice '*vase'))
      hub      (hoof stub)
    ==
  ::
  ++  berg                                              ::  repl/shell
    |=  [bran brad]
    |=  [now=@da eny=@ sky=_|+(* *(unit))] 
    =+  wen=(scot %da now)
    =+  wer=`path`[hox cwd wen (weld cwc [hub ~])]
    =+  rew=(flop wer)
    =+  vez=(vang | wer)
    |%
    ++  do                                              ::  userspace code
      |%
      ++  dive                                          ::  opts to gene
        |=  cux=cone
        ^-  gene
        :-  :+  %cncl
              [%cnsg [%gas ~] [%cnbc %in] yom.gen]
            [%clsg (turn p.cux |=(a=@ [%dtpt %tas a]))]
        :+  %cncl
          [%cnsg [%gas ~] [%cnbc %by] zim.gen]
        :-  %clsg
        %+  turn  q.cux
        |=([p=@tas q=crow] [[%dtpt %tas p] (doul q)])
      ::
      ++  doul                                          ::  crow to gene
        |=  woc=crow
        ^-  gene
        ?-    -.woc
            %c
          [%cnhp $(woc p.woc) $(woc [%p q.woc]) ~]
        ::
            %f
          %+  scan  (trip ((hard ,@) .^(%cx p.woc)))
          (full (ifix [gay gay] tall:vez(wer p.woc)))
        ::
            %g
          |-  ^-  gene
          ?~  p.woc
            q.woc
          [%tsgr ^$(woc [%f i.p.woc]) $(p.woc t.p.woc)]
        ::
            %l
          |-  ^-  gene
          ?~  p.woc
            [%bcts %null]
          [^$(woc i.p.woc) $(p.woc t.p.woc)]
        ::
            %p
          |-  ^-  gene
          ?~  p.woc  !!
          ?~  t.p.woc
            ^$(woc i.p.woc)
          [^$(woc i.p.woc) $(p.woc t.p.woc)]
        ==
      ::
      ++  echo                                          ::  echo argument
        |=  [yun=vase woc=crow]
        ^-  tank
        =+  vax=(slap yun (doul woc))
        (dish:ut ~(dole ut p.vax) q.vax) 
      ::
      ++  ecto                                          ::  type only
        |=  [yun=vase woc=crow]
        ^-  tank
        (dial:ut ~(dole ut (~(play ut p.yun) (doul woc))))
      ::
      ++  fane                                          ::  deliver note 
        |=  [pux=path nog=note tas=vase]
        ^-  vase
        %+  slam  tas
        ;:  slop
          [[%atom %da] now] 
          [pah.typ pux] 
          [noq.typ nog]
        ==
      ::
      ++  fapp                                          ::  launch app
        |=  [yun=vase pax=path cux=cone arg=crow]
        ^-  vase
        %+  slam
          %+  slam
            %+  slam
              (slap nub (doul [%f pax]))
            ;:  slop 
              [[%atom %p] who] 
              [[%atom %da] now] 
              [[%atom %%] (shax :(mix eny now (shax p.lif)))]
              [pah.typ pax]
            ==
          (slap yun (dive cux))
        (slap yun (doul arg))
      --
    ++  lo                                              ::  command parsers
      |%
      ++  htap 
        ;~  pfix  fas
          %+  cook
            |=  [a=reef b=path]
            =+  pot=(flop (scag q.a rew))
            =+  gaw=(slag q.a rew)
            =+  pre=?:(p.p.a (scag q.p.a (flop gaw)) (flop (slag q.p.a gaw)))
            (weld pre ?~(pot b (weld b pot)))
          ;~  plug
            ;~  plug
              ;~  pose
                (cold [%| 0] lus)
                (cook |=(a=(list) [%| (lent a)]) (plus tis))
                (cook |=(a=(list) [%& (lent a)]) (star tar))
              ==
              (cook |=(a=(list) (lent a)) (star buc))
            ==
            ;~(sfix (more (cook |=(a=coin ~(rent co a)) nuck:so) fas) fas)
          ==
        ==
      ::
      ++  ipto                                          ::  lights
        %+  knee  *(list ,@tas)  |.  ~+
        %+  cook
          |=  a=(list (list ,@tas))  ^-  (list ,@tas)
          ?~(a ~ (weld i.a $(a t.a)))
        %+  most
          ;~(plug com ace)
        ;~  pose
          (cook |=(a=@ [a ~]) sym)
          (cook |=(a=@ (rip 3 a)) ;~(pfix lus sym))
        ==
      ::
      ++  ipty                                          ::  notices
        %+  knee  *(list ,[p=@tas q=crow])  |.  ~+
        (most ace ;~(plug sym ;~(pfix fas worc)))
      ::
      ++  kral                                          ::  parse lark
        ;~  pose
          ;~  pfix  col
            ;~  pose
              ;~  pfix  ;~(plug (just 'c') (just 'd') gap)
                (stag %cd sym)
              ==
            ::
              ;~  pfix  ;~(plug (just 'c') (just 'c') gap)
                (stag %cc worc)
              ==
            ::
              ;~  pfix  ;~(plug (just 't') (just 'o') gap)
                (stag %to (stag %p (most ace worc)))
              ==
            ::
              ;~  pfix  ;~(plug (jest 'do') gap)
                (stag %do (stag %l (most ace worc)))
              ==
            ::
              ;~  pfix  ;~(plug (just 'k') (just 'l') gap)
                (stag %kl (cook |=(a=dime ?>(?=(%ud p.a) q.a)) bisk:so))
              ==
            ::
              ;~  pfix  ;~(plug (jest 'so') gap)
                %+  stag  %so
                ;~  plug  
                  sym
                  ;~(pfix gap (stag %p (most ace worc)))
                ==
              ==
            ::
              (cold [%nk ~] ;~(plug (just 'n') (just 'k')))
              (cold [%ps ~] ;~(plug (just 'p') (just 's')))
            ::
              %+  stag
                %go
              ;~  plug
                (thap %app)
                ;~  pose 
                  %+  ifix  [kel ker]
                  ;~  pose
                    ;~  plug
                      ipto
                      ;~(pose ;~(pfix ;~(plug sem ace) ipty) (easy ~))
                    ==
                    (stag ~ ipty)
                  ==
                  (easy [~ ~])
                ==
                (stag %l (star ;~(pfix ace worc)))
              ==
            ==
          ==
        ::
          (stag %eh (stag %p (most ace worc)))
        ==
      ::
      ++  thap
        |=  rol=@ta
        ;~  pose
          htap
          %+  cook                                      ::  XX bletcherous
            |=  a=path  ^-  path
            ?>  ?=([@ @ @ *] a)
            [i.a i.t.t.a i.t.a t.t.t.a]
          ;~  plug
            %+  cook
              |=(a=seat ~(rent co ~ %p a))
            ;~(pose ;~(pfix sig fed:ag) (easy who))
          ::
            %+  cook
              |=  a=[p=@ta q=(unit ,[p=@ta q=(unit ,@ta)])]
              ?~  q.a      [~(rent co ~ %da now) %main rol p.a hub ~]
              ?~  q.u.q.a  [~(rent co ~ %da now) p.a rol p.u.q.a hub ~]
                           [u.q.u.q.a p.a rol p.u.q.a hub ~] 
            ;~  plug
              sym
              ;~  pose
                %+  stag  ~
                ;~  plug
                  ;~(pfix fas sym)
                  ;~(pose (stag ~ ;~(pfix fas sym)) (easy ~))
                ==
                (easy ~)
              ==
            ==
          ==
        ==
      ::
      ++  worc
        %+  knee  *crow  |.  ~+
        ;~  pose
          ;~  pfix  buc
            %+  cook
              |=  [a=path b=(list crow)]
              `crow`[%c [%f a] b]
            ;~  plug
              (thap %fit)
              (ifix [pel per] (most ace worc))
            ==
          ==
          (stag %g (stag ~ wide:vez))
        ==
      --
    ::
    ++  fi
      |=  [gyp=@ud hen=duct]
      =+  ^=  gyr  ^-  gyre
          ?:  =(0 gyp)  *gyre
          =+  gyr=(~(get by r.fog) gyp)
          ?~(gyr *gyre u.gyr)
      =|  duz=(list move)
      |%
      ++  arse
        ^+  [*(list move) ..^$]
        :-  (flop duz)
        =+  yep=(skim pie.gyr |=(a=@ud (~(has by q.lif) a)))
        ?:  =(0 gyp)
          ?~  yep  ..^$
          %=    ..^$
              p.fog  +(p.fog)
              q.fog  [p.fog q.fog]
              r.fog  (~(put by r.fog) p.fog [yep pak.gyr])
          ==
        ?~  yep  ..^$(r.fog (~(del by r.fog) gyp))
        ..^$(r.fog (~(put by r.fog) gyp [yep pak.gyr]))
      ::
      ++  gull
        |=  fet=tape
        ^+  +>
        ?:(=(0 gyp) (maul fet) (mayo fet))
      ::
      ++  maul
        |=  fet=tape
        ^+  +>
        =^  zud  ..^^$
          =<  nave
          ^+  *ra
          =+  pid=p.lif
          =.  p.lif  +(p.lif) 
          (mete:(ra pid hen ~ ~) fet)
        +>.$(duz (weld (flop zud) duz))
      ::
      ++  mayo
        |=  fet=tape
        ^+  +>
        ?>  ?=(^ pak.gyr)
        =^  zud  ..^^$
          =<  nave
          ^+  *ra
          =+  byr=(need (~(get by q.lif) p.i.pak.gyr))
          =+  fuc=(rap 3 fet)
          %.  [q.i.pak.gyr [%up fuc]]
          =<  jerk
          %.  [q.i.pak.gyr [%line fuc]]
          =<  coax
          (ra p.i.pak.gyr hen p.byr [~ q.byr])
        %=  +>.$
          pak.gyr  t.pak.gyr
          duz      (weld (flop zud) duz)
        ==
      ::
      ++  perd
        ^-  prod
        ?:  =(0 gyp)
          :-  %text
          ;:  weld
            (trip (rap 3 [hox '/' cwd ~])) 
            "="
            ?~(cwc "" ~(ram re (dish:ut [~ %path] cwc)))
            "> "
          ==
        ?~  pak.gyr  [%none "[waiting for input]"]
        r.i.pak.gyr
      --
    ::
    ++  ra                                              ::  process context
      |=  $:  pid=tick                                  ::  process identity
              hen=duct                                  ::  current duct
              loz=(map path goal)                       ::  request state
              bor=(unit boar)                           ::  execution state
          ==                                            ::
      =|  duz=(list move)                               ::  pending operations
      |%                                                ::
      ++  bust                                          ::  slice coal
        |=  [axe=axis vux=coal]
        ^-  coal
        =<  q
        %+  slam  sot.vax
        (slop [[%atom %%] axe] [vas.typ vux])
      ::
      ++  coax                                          ::  update request
        |=  [pux=path fav=card]
        ^+  +>
        =+  fug=(~(get by loz) pux)
        ?~  fug  +>.$
        ?+    -.u.fug  +>.$
            %eg
          ?>  =(%writ -.fav)
          +>.$(loz (~(del by loz) pux))
        ::
            %up
          ?>  =(%line -.fav)
          +>.$(loz (~(del by loz) pux))
        ::
            %yo
          ?>  =(%went -.fav)
          +>.$(loz (~(del by loz) pux))
        ==
      ::
      ++  dost                                          ::  virtualize
        |=  :*  ton=toon
                fob=_|+((list path) *beef)
                fut=_|+(coal *beef)
            ==
        ^-  beef
        ?-  -.ton
          %0  (fut p.ton)
          %1  (fob ((list path) p.ton))
          %2  [[[%ho p.ton] ~] ~ ~]
        ==
      ::
      ++  emit                                          ::  return a card
        |=  fav=card
        +>(duz [[[~ who] hen fav] duz])
      ::
      ++  emir                                          ::  return cards
        |=  veq=(list card)
        +>(duz (weld (turn veq |=(a=card [[~ who] hen a])) duz))
      ::
      ++  enow                                          ::  advance a card
        |=  [nxt=wire ret=wire fav=card]
        +>(duz [[[~ who] [nxt [%b ret] hen] fav] duz])
      ::
      ++  envy                                          ::  redirect a card
        |=  [dst=wire fav=card]
        +>(duz [[[~ who] [dst hen] fav] duz])
      ::
      ++  ergo                                          ::  lark blocked
        |=  kal=lark
        |=  gez=(list path)
        ::  ~&  [%ergo-gez gez]
        ^-  beef
        :+  ~
          %+  turn  gez
          |=  hap=path
          ^-  slip
          =+(myt=(tame hap) [hap ?~(myt [%er hap] [%eg u.myt])])
        [~ %| (~(gas in *(set path)) gez) kal]
      ::
      ++  fret                                          ::  process coal
        |=  poc=coal
        ^-  beef
        :-  ((hard (list gift)) +:(bust 2 poc))
        =+  doy=(bust 3 poc)
        ?~  +.doy  [~ ~]
        :-  ((hard (list slip)) +>-.doy)
        [~ %& ~ ~ (bust 7 doy)]
      ::
      ++  gaff                                          ::  kill the process 
        ^+  .
        =+  ask=(~(tap by loz) *(list slip))
        |-  ^+  ..gaff
        ?~  ask
          ..gaff(loz ~)
        $(ask t.ask, ..gaff (geld i.ask))
      ::
      ++  geld                                          ::  abandon a slip
        |=  sip=slip
        +>
      ::
      ++  germ                                          ::  add a slip
        |=  sip=slip
        ::  ~&  [%germ sip]
        ^+  +>
        ?+    -.q.sip  +>
            %eg
          %^  enow  /c
            [(scot %ud pid) p.sip] 
          :+  %warp
            r.q.sip
          ^-  riff
          :-  s.q.sip
          :*  ~
              p.q.sip 
              ?-  -.q.q.sip 
                %da   [%da p.q.q.sip ~ p.q.q.sip]
                %tas  [%tas p.q.q.sip]
                %ud   [%ud p.q.q.sip]
              ==
              t.q.sip
          ==
        ::
            %er  (jibe p.q.sip ~)
            %yo  
          (enow /a [(scot %ud pid) p.sip] [%want p.q.sip q.q.sip r.q.sip])
        ==
      ::
      ++  gird                                          ::  process slips
        |=  ask=(list slip)
        ^+  +>
        =.  +>.$
          |-  ^+  +>.^$
          ?~  ask  +>.^$
          =+  tuq=(~(get by loz) p.i.ask)
          ?~  tuq  
            (germ i.ask)
          ?:  =(u.tuq q.i.ask) 
            +>.^$
          (goad i.ask)
        =+  zal=(~(tap by loz) ~)
        =.  loz  (~(gas by *(map path goal)) ask)
        |-  ^+  +>.^$
        ?~  zal  +>.^$
        ?:  (~(has by loz) p.i.zal)  +>.^$
        (geld i.zal)
      ::
      ++  goad                                          ::  modify a slip
        |=  sip=slip                                      
        ^+  +>
        ?+  -.q.sip  
               +>
          %ht  (germ sip)
          %up  !!   ::  this should actually work
        ==
      ::
      ++  haft                                          ::  gift to move(s)
        |=  gud=gift
        ^-  (list move)
        ?-    -.gud
          %de  [[[~ who] hen [%note '#' q.gud]] ~]
          %em  [[[~ who] hen [%talk (sell p.gud)]] ~]
          %en  |-  ^-  (list move)
               ?~(p.gud ~ (weld ^$(gud [%em i.p.gud]) $(p.gud t.p.gud)))
          %ha  [[[~ who] hen [%crud [p.gud ~]]] ~]
          %ho  [[[~ who] hen [%crud p.gud]] ~]
          %la  [[[~ who] hen [%talk p.gud]] ~]
          %lo  (turn p.gud |=(a=tank [[~ who] hen [%talk a]]))
          %ok  [[[~ who] [/c hen] [%edit p.gud q.gud r.gud]] ~]
          %te  [[[~ who] hen [%tell p.gud]] ~]
          %th  [[[~ who] hen [%that p.gud]] ~]
        == 
      ::
      ++  haul                                          ::  apply a result
        |=  bof=beef
        ^+  +>
        =.  duz
          |-  ^+  duz
          ?~  p.bof  duz
          (weld (haft i.p.bof) $(p.bof t.p.bof))
        ?~  r.bof
          gaff
        =.  bor  r.bof
        (gird q.bof)
      ::
      ++  hock                                          ::  set a variable
        |=  [nam=@tas woc=crow]
        ^+  +>
        =^  hus  +>.$  (husk %noun woc)
        ?~  hus  +>.$
        =.  way  (~(put by way) nam u.hus)
        (emit %note '.' %leaf (trip nam))
      ::
      ++  honk                                          ::  short circuit crow
        |=  [typ=type woc=crow]
        ^-  [p=type q=toon]
        =+  yun=lube
        =+  heq=(~(mint ut p.yun) %noun (doul:do woc))
        [p.heq (mock [q.yun q.heq] sky)]
      ::
      ++  huck                                          ::  direct effect
        |=  woc=crow
        ^+  +>
        =+  ton=q:(honk `type`-:!>(*(list card)) woc)
        ?-  -.ton
          %0  (emir ((hard (list card)) p.ton))
          %1  (emit %crud (turn p.ton |=(a=* [%leaf (spud (path a))])))
          %2  (emit %crud p.ton)
        ==
      ::
      ++  husk                                          ::  try to short
        |=  [typ=type woc=crow]
        ^-  [(unit vase) _+>]
        =+  hon=(honk typ woc) 
        ?-  -.q.hon
          %0  [[~ p.hon p.q.hon] +>.$]
          %1  [~ (emit %crud (turn p.q.hon |=(a=* [%leaf (spud (path a))])))]
          %2  [~ (emit %crud p.q.hon)]
        ==
      ::
      ++  hype                                          ::  change cord
        |=  woc=crow
        ^+  +>
        =^  hus  +>.$  (husk `type`-:!>(*path) woc)
        ?~  hus  +>.$
        +>.$(cwc ((hard path) q.u.hus))
      ::
      ++  jerk                                          ::  deliver note
        |=  [pux=path nob=note]
        ^+  +>
        ?>  ?=(^ bor)
        ?>  ?=(& -.u.bor)
        ?>  ?=(~ p.u.bor)                               ::  XX actually block
        %-  haul
        %^    dost
            (mong [fane:do [pux nob r.u.bor]] sky)
          |=  gez=(list path)
          ^-  beef
          !!                                            ::  XX do this right
        fret
      ::
      ++  jibe                                          ::  handle response
        |=  [pux=path fib=(unit)]
        ^+  +>
        ?~  fib
          gaff:(emit %text "! {~(ram re (dish:ut [~ %path] pux))}")
        ?>  ?=(^ bor)
        =.  p.u.bor  (~(del in p.u.bor) pux)
        ?^  p.u.bor  +>.$
        ?-    -.u.bor
            &  !!                                       ::  XX do this right
            |
          (loft q.u.bor)
        ==
      ::
      ++  loft                                          ::  execute command
        |=  kal=lark
        ^+  +>
        =+  hak=|=(a=* [[[%la ((hard tank) a)] ~] ~ ~])
        ?-    -.kal
            %cc  (hype p.kal)
            %cd  +>.$(cwd p.kal)
            %do  (huck p.kal)
            %eh  (haul (dost (mong [echo:do lube +.kal] sky) (ergo kal) hak))
            %go  (haul (dost (mong [fapp:do lube +.kal] sky) (ergo kal) fret))
            %kl  (envy /b [%kill p.kal])
            %nk  (envy /b [%nuke ~])
            %ps  (emir view)
            %so  (hock p.kal q.kal)
            %to  (haul (dost (mong [ecto:do lube +.kal] sky) (ergo kal) hak))
        ==
      ::
      ++  mete                                          ::  deliver line
        |=  fet=tape
        ^+  +>
        =>  .(p.hit +(p.hit), q.hit [(rap 3 fet) q.hit])
        =+  zif=((full (ifix [gay gay] kral:lo)) [1 1] fet)
        ?^  q.zif 
          (loft p.u.q.zif)
        =+  duf=[p=~(rend co ~ %ud p.p.zif) q=~(rend co ~ %ud q.p.zif)]
        %=    +>.$
            duz
          :_  duz
          :+  [~ who]  hen 
          [%warn "<syntax error at [{p.duf} {q.duf}]>"]
        ==
      ::
      ++  nave                                          ::  resolve
        ^-  [(list move) _..^$]
        =+  tid=~(rend co ~ %ud pid)
        ?:  =(~ loz)
          =.  p.lif  ?:(=(pid (dec p.lif)) (dec p.lif) p.lif)
          ?.  (~(has by q.lif) pid)
            [duz ..^$]
  ::      =.  ..nave  (envy /d %flog %text (weld "/ %" tid))
          [duz ..^$(q.lif (~(del by q.lif) pid))]
        ?>  ?=(^ bor)
  ::    =>  %=    .
  ::            ..nave
  ::          %+  envy
  ::            /d
  ::          [%flog %text (weld ?:((~(has by q.lif) pid) "= %" "^ %") tid)]
  ::        ==
        [duz ..^$(q.lif (~(put by q.lif) pid [loz u.bor]))]
      ::
      --
    ::
    ++  leap                                            ::  dispatch event
      |=  [pex=path hen=duct fav=card]
      ^-  [p=(list move) q=_..^$]
      =<  ?+  -.fav  [[[[~ who] hen fav] ~] ..^$]
            %writ  (gain p.fav)
            %kill  (kill p.fav)
            %noop  [~ ..^$]
            %nuke  nuke
            %line  =+  top=?>(?=(^ q.fog) i.q.fog) 
                   arse:(gull:(fi top hen) (trip p.fav))
            %thee  (heat p.fav)
            %went  (glom p.fav q.fav r.fav)
           ==
      |%
      ++  gain                                          ::  namespace response
        |=  fib=(unit) 
        ^-  [p=(list move) q=_..^^$]
        ?>  ?=(^ pex)
        ::  ~&  [%gain-pex pex ?=(^ fib)]
        =+  ped=(slay i.pex)
        ?>  ?=([~ %% %ud @] ped)
        =+  bur=(~(get by q.lif) q.p.u.ped)
        ?~  bur  [~ ..^^$]
        =<  nave
        ^+  *ra
        %.  [t.pex fib]
        =<  jibe
        %.  [t.pex fav]
        =<  coax
        (ra q.p.u.ped hen p.u.bur [~ q.u.bur])
      ::
      ++  glom                                          ::  dispatch response
        |=  [her=seat cap=cape sop=soap]
        ^-  [p=(list move) q=_..^^$]
        ?>  ?=(^ pex)
        =+  ped=(slay i.pex)
        ?>  ?=([~ %% %ud @] ped)
        =+  byr=(need (~(get by q.lif) q.p.u.ped))
        =<  nave
        ^+  *ra
        %.  [t.pex [%yo her cap sop]]
        =<  jerk
        %.  [t.pex fav]
        =<  coax
        (ra q.p.u.ped hen p.byr [~ q.byr])
      :: 
      ++  heat                                          ::  dispatch http req
        |=  het=hate
        ^-  [p=(list move) q=_..^^$]
        =+  sud=(lout p.het)
        ?~  sud
          :_  ..^^$
          :~  :+  [~ who]
                hen
              :-  %that
              :-  %raw
              [404 ~ [~ (tact "http error 404")]]
          ==
        =+  byr=(need (~(get by q.lif) p.u.sud))
        =<  nave
        %.  [q.u.sud [%ht r.u.sud q.het r.het]]
        =<  jerk
        (ra p.u.sud hen p.byr [~ q.byr])
      ::
      ++  kill                                          ::  kill a process
        |=  pid=tick
        ^-  [p=(list move) q=_..^^$]
        =+  byr=(need (~(get by q.lif) pid))
        =<  nave
        =<  gaff
        (ra pid hen p.byr [~ q.byr])
      ::
      ++  nuke                                          ::  kill all processes
        =+  fen=(~(tap by q.lif) ~)
        |-  ^-  [(list move) _..^^$]
        ?~  fen
          [~ ..^^$]
        =^  mor  ..^^$  $(fen t.fen)
        =+  les=(kill p.i.fen)
        [(weld p.les mor) q.les]
      --
    ::
    ++  loot                                            ::  match route
      |=  [uri=purl rut=rout]
      ^-  (unit scud)
      ?.  |-  ^-  ?
          ?~  p.rut  |
          =(i.p.rut `host`r.p.uri)
        ~
      =+  tac=*path
      |-  ^-  (unit scud)
      ?~  q.rut
        :-  ~
        :-  :(weld (flop q.q.uri) tac s.rut)
        `scar`[p.uri (flop tac) p.q.uri s.rut]
      ?:  |(?=(~ q.q.uri) !=(i.q.rut i.q.q.uri))
        ~
      $(q.rut t.q.rut, q.q.uri t.q.q.uri, tac [i.q.rut tac])
    ::
    ++  lout                                            ::  request to process
      |=  uri=purl                                      ::  XX map iterator
      ^-  (unit ,[p=tick q=path r=scab])
      =+  fen=`(list ,[p=tick q=bear])`(~(tap by q.lif) ~)
      |-  ^-  (unit ,[p=tick q=path r=scab])
      ?~  fen  ~
      =+  ask=`(list slip)`(~(tap by p.q.i.fen) ~)
      |-  ^-  (unit ,[p=tick q=path r=scab])
      ?~  ask  ^$(fen t.fen)
      ?.  ?=([%ht *] q.i.ask)
        $(ask t.ask)
      |-  ^-  (unit ,[p=tick q=path r=scab])
      ?~  p.q.i.ask  ^$(ask t.ask)
      =+  sem=(loot uri i.p.q.i.ask)
      ?~  sem  
        $(p.q.i.ask t.p.q.i.ask)
      [~ p.i.fen p.i.ask `scab`[`oryx`r.i.p.q.i.ask r.uri u.sem]]
    ::
    ++  lube                                            ::  define subject
      ^-  vase
      ;:  slop
        ;:  slop
          %+  slop
            [[%atom %da] now]
          [[%atom %ta] ~(rent co [~ %da now])]
        ::
          %+  slop
            [[%atom %p] who]
          [[%atom %ta] ~(rent co [~ %p who])]
        ::
          [liz.typ q.hit]
        ==
      ::
        =+  voy=(~(tap to q.sur) ~)
        |-  ^-  vase
        ?~(voy [[%atom %n] ~] (slop i.voy $(voy t.voy)))
      ::
        ?~  way
          nub
        %-  slop
        :_  nub
        |-  ^-  vase
        ?+  way  !!     ::  XX some inference weirdness here?
          [* ~ ~]  [[%face p.n.way p.q.n.way] q.q.n.way]
          [* ~ ^]  (slop $(r.way ~) $(way r.way))
          [* ^ ~]  (slop $(l.way ~) $(way l.way))
          [* ^ ^]  :(slop $(r.way ~, l.way ~) $(way l.way) $(way r.way))
        ==
      ==
    ::
    ++  prot                                            ::  current prompt
      ^-  prod
      perd:(fi ?>(?=(^ q.fog) i.q.fog) ~)
    ::
    ++  suet                                            ::  add to results
      |=  vax=vase
      %_    ..^$
          sur
        ?:  =(16 p.sur)
          [16 (~(put to q:~(get to q.sur)) vax)]
        [+(p.sur) (~(put to q.sur) vax)]
      ==
    ::
    ++  view                                            ::  render processes
      =+  fen=(~(tap by q.lif) ~)
      |-  ^-  (list card)
      ?~  fen  ~
      :_  $(fen t.fen)
      =+  cyv=[p.i.fen (~(tap by p.q.i.fen) ~)]
      [%talk >cyv<]
    --
  --
  . ==
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::::
  ::              section 4bC, shell vane               ::
  ::
  =|  $:  deb=(map seat _*berg)                         ::  state by terminal
      ==                                                ::
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  current invocation
  ^?                                                    ::  opaque core
  |%                                                    ::  poke/peek pattern
  ++  beat                                              ::  process move
    |=  [whu=(unit seat) tea=wire hen=duct fav=card]
    ^-  [p=(list move) q=vane]
    ?.  ?=(^ whu)
      ~&  [%beat-none fav]
      !!
    =+  ^=  beg  ^+  *berg
        =+  beg=(~(get by deb) u.whu)
        ?^(beg u.beg (bard u.whu))
    =+  yub=(leap:(beg now eny sky) tea hen fav)
    :-  p.yub
    ..^$(deb (~(put by deb) u.whu q.yub))
  ::
  ++  come  |=(old=vase (load old))
  ++  doze
    |=  [now=@da hen=duct]
    ^-  (unit ,@da)
    ~
  ::
  ++  flee  stay
  ++  load
    |=  new=vase
    ~&  %bede-load
    ^-  vane
    ?.  (~(nest ut -:!>(*(list ,[p=seat q=brad]))) & p.new)
      ~|(%load-nest-bede !!)
    %=    ..^$
        deb
      ^-  (map seat _*berg)
      %-  ~(gas by *(map seat _*berg))
      %+  turn
        ((hard (list ,[p=seat q=brad])) q.new)
      |=([p=seat q=brad] [p (barn p q)])
    ==
  ::
  ++  raze  
    ^-  vane
    ..$(deb ~)
  ::
  ++  scry
    |=  [our=seat ren=@tas his=seat syd=disc lot=coin tyl=path]
    ^-  (unit)
    ?.  =(our his)  ~
    ?.  &(=(%p syd) =([%% %da now] lot)) ~
    =+  beg=(~(get by deb) our)
    ?~  beg  ~
    [~ prot:(u.beg now eny |=(* *(unit)))]
  ::
  ++  stay
    ^-  vase
    ~&  %bede-stay
    !>  |-  ^-  (list ,[p=seat q=brad])
        %+  turn
          (~(tap by deb) ~)
        |=  [p=seat q=_*berg]
        ^-([p=seat q=brad] [p +>+<+.q])
    ==
  --
