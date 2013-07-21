!:
::  behn (4b), shell
::
|=  pit=vase
^-  vane
=>  =~
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::              section 4bA, shell models               ::
::
|%
++  bard                                                ::  new session
  |=  who=seat  ^-  brad
  %*  .  *brad
    hox    (scot %p who)
    cwd    %try
    fog    [0 ~]
    p.hit  1
    p.sur  1
    p.god  1
  ==
++  brad                                                ::  session/dynamic
  $:  fog=(list ,@ud)                                   ::  virtual consoles
      hox=@ta                                           ::  identity text
      cws=path                                          ::  working spur
      cwd=@tas                                          ::  working desk
      war=(map ,@tas coal)                              ::  variables
      sev=(map ,@tas (set ,[p=@ud q=@ud r=wire]))       ::  message servers
      hit=[p=@ud q=(list ,@t)]                          ::  command history
      sur=[p=@ud q=(qeu vase)]                          ::  result history
      god=[p=@ud q=(map ,@ud gyre)]                     ::  process state
  ==                                                    ::
::                                                      ::
++  bran                                                ::  static "state"
  $:  nub=vase                                          ::  
      ^=  vax                                           ::  chestnut vases
    $:  sot=vase                                        ::  'slot'
    ==                                                  ::
      ^=  gen                                           ::
    $:  yom=gene                                        ::  '*(set ,@tas)'
        zim=gene                                        ::  '*(map ,@tas ,*)'
    ==                                                  ::
      ^=  typ                                           ::  chestnut types
    $:  cof=type                                        ::  '*conf'
        gee=type                                        ::  '*gene'
        liz=type                                        ::  '*(list ,@t)'
        pah=type                                        ::  '*path'
        noq=type                                        ::  '*note'
        tak=type                                        ::  '*task'
        vas=type                                        ::  '*vase'
    ==                                                  ::
  ==                                                    ::
::
++  bred                                                ::  make defaults
  =+  nib=pit
  =+  pal=~(play ut p.nib)
  ~+
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
  ==
++  brat  ,[[who=seat bran] brad]                       ::  don't ask why
++  brim  (list ,[p=seat q=brad])                       ::  session
--                                                      ::
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::              section 4bB, session engine             ::
::
|%
++  be                                                  ::  repl/shell
  |=  brat                                              ::  core state
  |=  [now=@da eny=@ sky=_|+(* *(unit))] 
  =+  wen=(scot %da now)
  =+  wer=`path`[hox cwd wen cws]
  =+  rew=(flop wer)
  =+  vez=(vang | wer)
  |%
  ++  fest                                              ::    fest:be
    |=  [gyp=@ud hen=duct]                              ::  find a task
    (fi gyp hen (need (~(get by q.god) gyp)))
  ::
  ++  fist                                              ::    fist:be
    |=  hen=duct                                        ::  new task
    =+  [gyp=p.god gyr=*gyre]
    =:  p.god  +(p.god)
        q.god  (~(put by q.god) p.god *gyre)
      ==
    (fi gyp hen gyr)
  :: 
  ++  heat                                              ::    heat:be
    |=  [hen=duct het=hate]                             ::  dispatch http req
    ^-  [p=(list move) q=brat]
    =+  sud=(lout p.het)
    ?~  sud
      :_  +<.^^$
      :~  :+  [~ %iron who]
            hen
          :-  %that
          :-  %raw
          [404 ~ [~ (tact "http error 404")]]
      ==
    =<  abet
    =<  lash
    =<  abet
    %+  glib:(past:(fest p.u.sud hen) q.u.sud)
      r.u.sud 
    [%ht s.u.sud q.het r.het]
  ::
  ++  lead                                              ::    lead:be
    |=  [tea=wire hen=duct]                             ::  route note
    ^-  [p=wire q=_ra:*fi]
    ?>  ?=([@ @ *] tea)
    =+  [ped=(slay i.tea) wad=(slay i.t.tea)]
    ?>  &(?=([~ %% %ud @] ped) ?=([~ %% %ud @] wad))
    [t.t.tea (past:(fest q.p.u.ped hen) q.p.u.wad)]
  ::
  ++  lean                                              ::    lean:be
    |=  [tea=wire hen=duct fav=card]                    ::  deliver card
    ^+  *fi
    =+  lay=(lead tea hen)
    ?>  ?=([%ma *] p.lay)
    abet:(glob:q.lay t.p.lay fav)
  ::
  ++  leap                                              ::    leap:be
    |=  [tea=wire hen=duct fav=card]                    ::  handle event
    ^-  [p=(list move) q=brat]
    ?:  ?=([%crud *] fav)
      [[[[~ %iron who] [/d hen] [%flog fav]] ~] +<.^^$]
    ?+  -.fav  
             [[[[~ %iron who] hen fav] ~] +<.^^$]
      %hail  [[[[~ %iron who] hen [%helo prot]] ~] +<.^^$]
      %line  =+  gyp=?>(?=(^ fog) i.fog)
             =<  abet
             ?:  =(0 gyp)
               lash:(gill:(fist hen) p.fav)
             lash:(como:(fest gyp hen) p.fav)
      %ling  ?>  ?=(^ fog)
             =>  .(fog (weld t.fog `(list ,@ud)`[i.fog ~]))
             [[[[~ %iron who] hen [%helo prot]] ~] +<.^^$]
      %noop  [~ +<.^^$]
      %thee  (heat hen p.fav)
      %went  abet:lash:(lean tea hen fav)
      %writ  abet:lash:(loam tea hen +.fav)
      %wart  (lion hen +.fav)
    ==
  ::
  ++  loam                                              ::    loam:be
    |=  [tea=wire hen=duct rot=riot]                    ::  handle response
    ^+  *fi
    =+(a=(lead tea hen) abet:(gall:q.a p.a rot))
  ::
  ++  lion                                              ::    lion:be
    |=  [hen=duct him=@p cha=@ta num=@ud val=(unit ,*)] ::  handle message
    ^-  [(list move) brat]
    =+  yes=(~(get by sev) cha)
    ?~  yes  [~ +<.^^$]
    =+  sey=(~(tap by u.yes) *(list ,[p=@ud q=@ud r=wire]))
    |-  ^-  [(list move) brat]
    ?~  sey  [~ +<.^^^$]
    =^  von  +<.^^^$
      =<  abet
      =<  lash
      =<  abet
      =<  abet
      %-  pong:(ox:(past:(fest p.i.sey hen) q.i.sey) r.i.sey)
      [%wart him cha num val]
    =^  vun  +<.^^^$  $(sey t.sey)
    [(weld von vun) +<.^^^$]
  ::
  ++  loot                                              ::    loot:be
    |=  [uri=purl rut=rout]                             ::  match route
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
  ++  lout                                              ::    lout:be
    |=  uri=purl                                        ::  match http req
    ^-  (unit ,[p=@ud q=@ud r=path s=scab])
    =+  dog=`(list ,[p=@ud q=gyre])`(~(tap by q.god) ~)
    |-  ^-  (unit ,[p=@ud q=@ud r=path s=scab])
    ?~  dog  ~
    =+  pig=`(list ,[p=@ud q=beak])`(~(tap by q.wip.q.i.dog) ~)
    |-  ^-  (unit ,[p=@ud q=@ud r=path s=scab])
    ?~  pig  ^$(dog t.dog)
    =+  ask=`(list slip)`(~(tap by q.q.i.pig) ~)
    |-  ^-  (unit ,[p=@ud q=@ud r=path s=scab])
    ?~  ask  ^$(pig t.pig)
    ?.  ?=([%ht *] q.i.ask)
      $(ask t.ask)
    |-  ^-  (unit ,[p=@ud q=@ud r=path s=scab])
    ?~  p.q.i.ask  ^$(ask t.ask)
    =+  sem=(loot uri i.p.q.i.ask)
    ?~  sem  
      $(p.q.i.ask t.p.q.i.ask)
    [~ p.i.dog p.i.pig p.i.ask `scab`[`oryx`r.i.p.q.i.ask r.uri u.sem]]
  ::
  ++  lube                                              ::    lube:be
    ^-  vase                                            ::  build subject
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
      nub
    ==
  ::
  ++  prot                                              ::    prot:be
    ^-  prod                                            ::  get prompt
    ?>  ?=(^ fog)
    ?.  =(0 i.fog)
      perd:(fest i.fog ~)
    text/:(weld (trip (rap 3 [hox '/' cwd ~])) "=" ?~(cws "" (spud cws)) "> ")
  ::
  ++  fi                                                ::    fi:be
    |=  [gyp=@ud hen=duct gyr=gyre]                     ::  process task
    =|  duv=(list ,[p=duct q=card])
    |%
    ++  abet                                            ::    abet:fi:be
      ^-  [(list move) brat]                            ::  resolve
      =+  ^=  fod  ^+  [p=fog q=q.god]
          ?~  q.wip.gyr
            :-  (skip fog |=(a=@ud =(a gyp))) 
            (~(del by q.god) gyp)
          :-  ?:((lien fog |=(a=@ud =(a gyp))) fog [gyp fog])
          q=(~(put by q.god) gyp gyr)
      =+  sam==(fog p.fod)
      =:  fog    p.fod
          q.god  q.fod
        ==
      :_  +<.^^$
      %+  turn 
        (flop `_duv`?:(sam duv [[~ [%helo prot]] duv]))
      |=([p=duct q=card] [[~ %iron who] (weld p hen) q])
    ::
    ++  bitt  |=(lap=path [(scot %ud gyp) lap])         ::    bitt:fi:be
    ++  como                                            ::    como:fi:be
      |=  lin=@t                                        ::  command
      ^+  +>
      =+  ryg=~(top to paq.gyr)
      ?~  ryg  
        ~&  %como-no
        +>.$
      abet:abet:(pong:(ox:(past p.u.ryg) q.u.ryg) [%line lin])
    ::
    ++  gill                                            ::    gill:fi:be
      |=  lin=@t                                        ::  input line
      ^+  +>
      =+  zif=((full (ifix [gay gay] lark:lo)) [1 1] (trip lin))
      ?~  q.zif 
        =+  duf=[p=~(rend co ~ %ud p.p.zif) q=~(rend co ~ %ud q.p.zif)]
        (warn "<syntax error at [{p.duf} {q.duf}]>")
      %-  limp
      ^-  (list lath)
      =+  kar=`lark`p.u.q.zif
      ?+  kar  !!
        [%go *]  +.kar
      ==
    ::                                                  ::    hoop:fi:be
    ++  hoop                                            ::  delete prompt
      |=  [lap=wire pid=@ud]                            ::  XX ugly
      ^+  +>
      %=    +>
          paq.gyr
        %-  ~(gas to *(qeu gyro))  
        %+  skip
          (~(tap to paq.gyr) *(list gyro))
        |=(a=gyro &(=(pid p.a) =(lap q.a)))
      ==
    ::
    ++  hoot                                            ::    hoot:fi:be
      |=  [lap=wire pid=@ud pod=prod]                   ::  install prompt
      ^+  +>
      %_(+> paq.gyr (~(put to paq.gyr) [pid lap pod]))
    ::
    ++  lash                                            ::    lash:fi:be
      ^.  .                                             ::  execute task
      =+  pew=(sort (turn (~(tap by q.wip.gyr) ~) |=([p=@ud *] p)) lth)
      |-  ^+  ..lash
      ?~  pew  ..lash
      $(pew t.pew, ..lash abet:grip:(past i.pew))
    ::
    ++  limp                                            ::    limp:fi:be 
      |=  kaw=(list lath)                               ::  start pipeline
      ^+  +>
      ?~  kaw  +>
      $(kaw t.kaw, +>.$ (pant i.kaw ?:(=(~ t.kaw) ~ [~ +(p.wip.gyr)])))
    ::
    ++  pant                                            ::    pant:fi:be 
      |=  [lat=lath nex=(unit ,@ud)]                    ::  start process
      %=  +>
        p.wip.gyr  +(p.wip.gyr)
        q.wip.gyr  (~(put by q.wip.gyr) p.wip.gyr [nex ~ [~ ~ ~ %| ~ lat]])
      ==
    ::
    ++  past                                            ::    past:fi:be
      |=  pid=@ud                                       ::  select process
      ^+  ra
      =+  bek=(need (~(get by q.wip.gyr) pid))
      ~(. ra pid p.bek q.bek r.bek)
    ::
    ++  perd                                            ::    perd:fi:be
      ^-  prod                                          ::  produce prompt
      =+  top=~(top to paq.gyr)
      ?~(top [%none "[waiting...]"] r.u.top)
    ::
    ++  warn                                            ::    warn:fi:be
      |=  txt=tape                                      ::  send warning
      ^+  +>
      +>(duv :_(duv [~ [%warn txt]]))
    ::
    ++  ra                                              ::    ra:fi:be
      |_  $:  pid=@ud                                   ::  process id
              nex=(unit ,@ud)                           ::  next in pipeline
              loz=(map wire goal)                       ::  waiting for
              orb=boor                                  ::  image
          ==
      ::
      ++  abet                                          ::  resolve
        ^+  ..ra
        ?:  &(?=(& -.s.orb) |(=(~ p.s.orb) =(~ loz)))
          =>  (gird ~)
          =.  ..ra  ?~(nex ..ra abet:(glob:(past u.nex) ~ [%pipe ~]))
          ..ra(q.wip.gyr (~(del by q.wip.gyr) pid))
        ..ra(q.wip.gyr (~(put by q.wip.gyr) pid nex loz orb))
      ::
      ++  bist  |=(lap=path (bitt (scot %ud pid) lap))  ::  form path
      ++  bust                                          ::  slice coal
        |=  [axe=axis vux=coal]
        ^-  coal
        =<  q
        %+  slam  sot.vax
        (slop [[%atom %%] axe] [vas.typ vux])
      ::
      ++  fret                                          ::  process coal
        |=  poc=coal
        ^-  beef
        :-  ((hard (list gilt)) +:(bust 2 poc))
        =+  doy=(bust 3 poc)
        ?~  +.doy  [~ %& ~]
        :-  ((hard (list slip)) +>-.doy)
        [%& ~ (bust 7 doy)]
      ::
      ++  gall                                          ::  deliver result
        |=  [lap=wire rot=riot]
        ^+  +>
        ?.  ?=([%au * *] lap)
          ?>  ?=([%ma *] lap)
          (glob t.lap [%writ rot])
        =+  dup=(slay i.t.lap)
        ?>  ?=([~ %% %ud @] dup)
        =+  kit=(need (~(get by p.orb) q.p.u.dup))
        ?~  rot
          %_(+>.$ ..ra (warn (spud (meat kit))), s.orb [%& ~])
        =+  tyk=`kite`[p.p.u.rot q.p.u.rot r.kit r.p.u.rot q.u.rot]
        ?>  =(kit tyk)
        +>.$(p.orb (~(del by p.orb) q.p.u.dup))
      ::
      ++  gird                                          ::  change slips
        |=  ask=(list slip)
        ^+  +>
        =+  zal=(~(tap by loz) ~)
        =+  zim=(~(gas by *(map path goal)) ask)        ::  XX clumsy
        =.  +>.$
          |-  ^+  +>.^$
          ?~  zal  +>.^$
          %=  $
            zal    t.zal
            +>.^$  ?:((~(has by zim) p.i.zal) +>.^$ abet:pang:(ox p.i.zal))
          ==
        |-  ^+  +>.^$
        ?~  ask  +>.^$
        $(ask t.ask, +>.^$ abet:(pane:(ox p.i.ask) q.i.ask))
      ::
      ++  glib                                          ::  pending note
        |=  [lap=wire nob=nose]
        ^+  +>
        %_(+> r.orb (~(put to r.orb) [lap nob]))
      ::
      ++  glob                                          ::  extern
        |=  [lap=wire fav=card]
        ^+  +>
        %_(+> q.orb (~(put to q.orb) [lap fav]))
      ::
      ++  glum                                          ::  blocked process
        |=  [gez=(list path) hog=boar]
        =|  [inx=@ud err=(list path) bez=(map ,@ud kite)]
        |-  ^+  +>.^$
        ?~  gez  
          ?:  =(~ err)
            +>.^$(orb [bez ~ ~ hog])
          |-  ^+  +>.^^$
          ?~  err  +>.^^$(orb [~ ~ ~ %& ~])
          $(err t.err, ..ra (warn (spud i.err)))
        =+  myt=(tame i.gez)
        ?~  myt
          $(gez t.gez, err [i.gez err]) 
        %=  $
          gez    t.gez
          inx    +(inx)
          bez    (~(put by bez) inx u.myt)
          +>.^$  (gulp (bist %au (scot %ud inx) ~) u.myt)
        ==
      ::
      ++  grab                                          ::  chase simple path
        |=  lam=lamp  ^-  gene
        ?-  -.lam
          0  =+  ven=(fall q.lam wen)
             =+  pax=[hox %main ven p.lam %hoon ~]
             =+  tes=(sky [%cx hox %main ven %fun p.lam %hoon ~])
             (grad [hox ?^(tes %main cwd) ven %fun p.lam ~])
          1  (grad [hox p.lam (fall q.lam wen) %fun r.lam])
          2  (grad [(scot %p p.lam) q.lam (fall r.lam wen) %fun s.lam])
          3  p.lam
        ==
      ::
      ++  grad                                          ::  path to gene
        |=  pax=path  ^-  gene
        [%clsg (turn pax |=(a=@ta [%dtpt %ta a]))]
      ::
      ++  gram                                          ::  add action
        |=  [hom=duct fav=card] 
        %_(+> duv [[hom fav] duv])
      ::
      ++  gran                                          ::  add actions
        |=  vid=(list ,[p=duct q=card])
        ^+  +>
        ?~(vid +> $(vid t.vid, +> (gram i.vid)))
      ::
      ++  grin                                          ::  process result
        |=  [ton=toon hog=boar]
        ^+  +>
        ?-  -.ton
          %0  (haul (fret p.ton))
          %1  (glum ((list path) p.ton) hog)
          %2  (gram(orb [~ ~ ~ %& ~]) ~ [%crud p.ton])
        ==
      ::
      ++  grip                                          ::  step to completion
        |-  ^+  +
        =+(a=grit ?:(=(+.$ a) +.$ $(+.$ a)))
      ::
      ++  grit                                          ::  work step
        |-  ^+  +
        ?^  p.orb  +
        ?-    -.s.orb
            |
          ?~  p.s.orb
            $(p.s.orb [~ `coal`(need (mang [food:zu war lube] sky)) ~])
          ?~  q.u.p.s.orb
            ?>  ?=(& -.q.s.orb)                         ::  XX naked gene
            =+  pen=`gene`(grab q.q.s.orb)
            =+  ton=(mong [slap p.u.p.s.orb pen] sky)
            ?-  -.ton
              %0  $(q.u.p.s.orb [~ ((hard path) +.p.ton) ~])
              %1  (glum ((list path) p.ton) s.orb)
              %2  (gram(orb [~ ~ ~ %& ~]) ~ [%crud p.ton])
            ==
          ?>  ?=(& -.q.s.orb)
          %-  grin  :_  s.orb
          %-  mong  :_  sky
          [fapp:zu `coal`p.u.p.s.orb `path`p.u.q.u.p.s.orb *cone s.q.s.orb]
        ::
            &
          ?~  p.s.orb  +
          ?:  =(~ r.orb)
            ?:  =(~ q.orb)  +
            =^  pud  q.orb  ~(get to q.orb)
            abet:(pong:(ox p.p.pud) q.p.pud)
          =^  pud  r.orb  ~(get to r.orb)
          (grin (mong [fane:zu [p.p.pud q.p.pud u.p.s.orb]] sky) s.orb)
        ==
      ::  
      ++  gull                                          ::  request control
        |=  [tea=wire him=seat ryf=riff]
        (gram ~[/c [%b tea]] [%warp him ryf])
      ::
      ++  gulf                                          ::  stop request
        |=  [tea=wire kit=kite]
        (gull tea r.kit [s.kit ~])
      ::
      ++  gulp                                          ::  start request
        |=  [tea=wire kit=kite]
        %^  gull  tea
          r.kit
        ^-  riff
        [s.kit ~ %& p.kit q.kit t.kit]
      ::
      ++  gump                                          ::  message server
        |=  [ton=? cha=@tas gyp=@ud pid=@ud lap=wire]
        ^+  +>
        =+  ^=  yes  ^-  (set ,[p=@ud q=@ud r=wire])
            =+  yes=(~(get by sev) cha)
            ?~(yes ~ u.yes)
        %_    +>.$
            sev
          %+  ~(put by sev)  cha
          ?:  ton
            (~(put in yes) gyp pid lap)
          (~(del in yes) gyp pid lap)
        ==
      ::
      ++  gyro                                          ::  print vase
        |=  [toy=typo val=*]  ^-  card
        =+  caf=((hard calf) (need (mang [felt:zu toy] sky)))
        ?:  =([~ [%atom %t]] caf)
          [%tell ((hard ,@t) val) ~]
        ?:  =([~ %wall] caf)
          [%tell ((hard (list ,@t)) val)]
        [%talk (dish:ut caf val)]
      ::
      ++  haft                                          ::  process gift
        |=  guf=gilt
        ^+  +>
        ?-    -.guf
            %%
          ?~  nex
            (gram ~ (gyro +<.guf +>.guf))
          +>.$(..ra abet:(glob:(past u.nex) ~ [%pipe ~ +<.guf +>.guf ~]))
        ::
            %mu
          =+  tey=((hard (list)) +>.guf)
          ?~  nex  
            (gran (turn tey |=(a=* [~ (gyro +<.guf a)])))
          +>.$(..ra abet:(glob:(past u.nex) ~ [%pipe ~ +<.guf tey]))
        ::
            %va
          =+  tey=((hard ,[p=@tas q=(unit)]) +>.guf)
          %=  +>.$
            war  ?~(q.tey (~(del by war) p.tey) (~(put by war) p.tey u.q.tey))
          ==
        ::
            *
          =+  gud=((hard gift) guf)
          |-  ^+  +>.^$
          ?-  -.gud
            %%   !!
            %cs  +>.^$(cws p.gud)
            %cd  +>.^$(cwd p.gud)
            %de  (gram ~ %note '#' q.gud)
            %ha  (gram ~ %crud [p.gud ~])
            %ho  (gram ~ %crud p.gud)
            %la  (gram ~ %talk p.gud)
            %lo  (gran (turn p.gud |=(a=tank [~ %talk a])))
            %mu  !!
            %mx  |-  ^+  +>.^^$
                 ?~  p.gud  +>.^^$
                 $(p.gud t.p.gud, +>.^^$ ^$(gud i.p.gud))
            %ok  (gram [/c ~] %into who p.gud q.gud)
            %te  (gram ~ %tell p.gud)
            %th  (gram ~ %that p.gud)
            %va  !!
            %xx  (gram ~ p.gud)
            %xy  (gram [p.gud /b ~] q.gud)
          == 
        ==
      ::
      ++  hale                                          ::  process gifts
        |=  guz=(list gilt)
        ^+  +>
        ?~(guz +> $(guz t.guz, +> (haft i.guz)))
      ::
      ++  haul                                          ::  process success
        |=  bof=beef
        ^+  +>
        =.  s.orb  r.bof
        =.  +>  (hale p.bof)
        (gird q.bof)
      ::
      ++  loss                                          ::  stop goal
        |=  [lap=wire gal=goal]
        ^+  +>
        ?-  -.gal
          %%   +>
          %eg  (gulf (bist %ma lap) p.gal)
          %es  (gull (bist %ma lap) p.gal q.gal ~)
          %ht  (gram [/e [%b (bist [%ma lap])] ~] [%bund who ~])
          %oy  (gump | p.gal gyp pid lap)
          %up  +>(..ra (hoop lap pid))
          %wa  !!
          %yo  +>
        ==
      ::
      ++  moor                                          ::  start goal
        |=  [lap=wire gal=goal]
        ^+  +>
        ?-    -.gal
          %%   +>
          %eg  (gulp (bist %ma lap) p.gal)
          %es  (gull (bist %ma lap) p.gal q.gal [~ r.gal])
          %ht  (gram [/e [%b (bist [%ma lap])] ~] [%bund who p.gal])
          %oy  (gump & p.gal [gyp pid lap])
          %up  +>(..ra (hoot lap pid p.gal))
          %wa  !!
          %yo  (gram [/a [%b (bist [%ma lap])] ~] [%want +.gal])
        ==
      ::
      ++  ox                                            ::  per delivery
        |=  lap=wire                                    ::  per request
        =+  gul=(~(get by loz) lap)
        =+  lug=gul
        |%
        ++  abet                                        ::  resolve
          ^+  +>.$
          ?~  lug
            ?~  gul  +>.$
            (loss(loz (~(del by loz) lap)) lap u.gul)
          ?~  gul
            (moor(loz (~(put by loz) lap u.lug)) lap u.lug)
          ?:  =(u.lug u.gul)  +>.$
          =.  +>.$  (loss(loz (~(del by loz) lap)) lap u.gul)
          (moor(loz (~(put by loz) lap u.lug)) lap u.lug)
        ::
        ++  pane  |=(gal=goal %_(. lug [~ gal]))        ::  set goal
        ++  pang  %_(. lug ~)                           ::  delete goal
        ++  pong                                        ::  accept note
          |=  fav=card
          ^+  +>
          ?>  ?=(^ lug)
          ?-    -.u.lug
              ~
            ?>  ?=(%pipe -.fav)
            +>.$(+>.$ (glib lap [%% p.fav]))
          ::
              %eg
            ?>  ?=(%writ -.fav)
            +>.$(lug ~, +>.$ (glib lap [%eg +.fav]))
          ::
              %es
            ?>  ?=(%writ -.fav)
            +>.$(+>.$ (glib lap [%eg +.fav]))
          ::
              %ht  !!
              %up
            ?>  ?=(%line -.fav)
            +>.$(+>.$ (glib lap [%up +.fav]))
          ::
              %oy 
            ?>  ?=(%wart -.fav)
            +>.$(+>.$ (glib lap [%oy +.fav]))
          ::
              %wa  !!
              %yo 
            ?>  ?=(%went -.fav)
            +>.$(lug ~, +>.$ (glib lap [%yo +.fav]))
          ==
        --
      --
    --
  ::
  ++  lo                                                ::  command parsers
    |%
    ++  cone                                            ::  parse conf
      %+  cook  |=(a=^cone a)
      ;~  pose
        (stag %0 (stag %cltr (ifix [sel ser] (most ace wide:vez))))
        (stag %1 (stag %cnts (stag `wing`[[~ 1] ~] loon:vez)))
        (stag %2 (ifix [kel ker] wide:vez))
        (easy [%0 [%% 1]])
      ==
    ::
    ++  lark                                            ::  parse lark
      %+  cook  |=(a=^lark a)
      ;~  pose
        (stag %go (cook |=(a=(list ^lath) (flop a)) (most gap lath)))
        ;~  pfix  tis
          ;~  pose
            (stag %so ;~(plug sym ;~(pfix ace wide:vez)))
            ;~  pfix  tis
              (stag %no sym)
            ==
          ==
        ==
        %+  cook
          |=  a=(list gene)
          =+  wag=(turn a |=(b=gene [%hxgr b ~]))
          [%go [[%& %0 [%0 %echo ~] [%0 [%bcts %null]] [%clsg wag]] ~]]
        (most ace wide:vez)
      ==
    ::
    ++  lamb  
      %+  cook  |=(a=(unit ,@ta) a)
      ;~  pose 
        ;~(pfix lus (stag ~ (cook |=(a=coin ~(rent co a)) nuck:so)))
        (easy ~)
      ==
    ::
    ++  lamp
      %+  cook  |=(a=^lamp a)
      ;~  pose
        (stag %3 rood:vez)
        (stag %1 ;~(plug sym lamb ;~(pfix fas (most fas sym))))
        (stag %0 ;~(plug sym lamb))
        %+  stag
          %2
        ;~  plug
          ;~(pfix sig fed:ag)
          ;~(pfix fas sym)
          lamb
          ;~(pfix fas (most fas sym))
        ==
      ==
    :: 
    ++  lath
      %+  cook  |=(a=^lath a)
      ;~  pose       
        ;~  pfix  col
          %+  stag  %&
          ;~  plug
            ;~(pose ;~(pfix zap ;~(pose (cold %2 zap) (easy %1))) (easy %0))
            lamp
            cone
            (stag %clsg (star ;~(pfix ace wide:vez)))
          ==
        ==
        ::  (stag %| wide:vez)
      ==
    --
  ::
  ++  zu                                                ::  user level
    |%
    ++  fane                                            ::  deliver note 
      |=  [pux=path nog=nose tas=vase]
      ^-  vase
      %+  slam  tas
      ;:  slop
        [[%atom %da] now] 
        [pah.typ pux] 
        [noq.typ nog]
      ==
    ::
    ++  fapp                                            ::  launch app
      |=  [yun=vase pax=path con=cone arg=gene]
      ^-  vase
      %+  slam
        %+  slam
          %+  slam
            (slap nub (fend pax))
          ;:  slop 
            [[%atom %p] who] 
            [[%atom %da] now] 
            [[%atom %%] (shax :(mix eny now (shax p.god)))]
            [pah.typ pax]
          ==
        `vase`[[%atom %n] ~]                            ::  XX configure
      (slap yun arg)
    ::
    ++  felt                                            ::  type to calf
      |=  typ=type  ^-  calf
      ~(dole ut typ)
    ::
    ++  fend
      |=  pax=path
      ^-  gene
      %+  scan  (trip ((hard ,@) .^(%cx (weld pax /hoon))))
      (full (ifix [gay gay] tall:vez(wer pax)))
    ::
    ++  food
      |=  [war=(map ,@ta vase) vax=vase]
      ^-  vase
      ?~  war
        vax
      %-  slop
      :_  vax
      |-  ^-  vase
      ?+  war  !!     ::  XX some inference weirdness here?
        [* ~ ~]  [[%face p.n.war p.q.n.war] q.q.n.war]
        [* ~ ^]  (slop $(r.war ~) $(war r.war))
        [* ^ ~]  (slop $(l.war ~) $(war l.war))
        [* ^ ^]  :(slop $(r.war ~, l.war ~) $(war l.war) $(war r.war))
      ==
    ::
    ++  form                                            ::  compose
      |=  [vax=vase cus=gens hut=path sur=path]
      ^-  vase
      =+  ^=  cup  ^-  (list gene)
          =.  hut  (weld hut `path`[%con ~])
          %-  flop
          |-  ^-  (list gene)
          =+  ape=((hard apex) .^(%cy hut))
          ?.  (~(has by q.ape) %hoon)  ~
          :-  (fend hut)
          ?~  sur  ~
          ?.  (~(has by r.ape) i.sur)  ~
          $(sur t.sur, hut (weld hut `path`[i.sur ~]))
      |-  ^-  vase
      ?~  cup
        ?~(cus vax $(cus t.cus, vax (slap vax i.cus)))
      ?~  cus 
        $(cup t.cup, vax (slap vax i.cup))
      $(cup t.cup, cus t.cus, vax (slap (slap vax i.cup) i.cus))
    --
  --
--
. ==
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::              section 4bC, shell vane                 ::
::
=|  $:  dez=(map duct brim)                             ::  state by seat
    ==                                                  ::
|=  [now=@da eny=@ sky=||(* (unit))]                    ::  current invocation
^?                                                      ::  opaque core
|%                                                      ::  poke/peek pattern
++  beat                                                ::  process move
  |=  [wru=(unit writ) tea=wire hen=duct fav=curd]
  =>  .(fav ((hard card) fav))
  ^-  [p=(list move) q=vane]
  =+  dus=(~(get by dez) hen)
  ?~  dus
    ?+    -.fav  
      ~&  [%beat-none -.fav tea hen]
      ~|([%beat-none -.fav] !!)
    ::
        %init
      ?~  wru  !! 
      :-  [[wru hen fav] ~]
      ..^$(dez (~(put by dez) hen [[q.u.wru (bard q.u.wru)] ~]))
    ::
        ?(%loin %make %sith)
      [[[wru [/a [%b tea] hen] fav] ~] ..^$]
    ==
  ?>  ?=(^ u.dus)
  ?+    -.fav
      ?~  wru
        =+  ade=(adit hen)
        =+  hem=`helm`?-(ade %lead [%lead p.i.u.dus], %iron %iron, %gold %gold)
        [[[[~ hem p.i.u.dus] [[%b tea] hen] fav] ~] ..^$]
      =+  beg=`brat`[[p.i.u.dus bred] q.i.u.dus]
      =+  yub=(leap:((be beg) now eny sky) tea hen fav)
      :-  p.yub
      ..^$(dez (~(put by dez) hen [[p.i.u.dus +.q.yub] t.u.dus]))
  ::
      %init
    ?~  wru  !! 
    $(fav [%hail ~], dez (~(put by dez) hen [[q.u.wru (bard q.u.wru)] u.dus]))
  ::
      %limn
    $(fav [%hail ~], dez (~(put by dez) hen (weld t.u.dus [i.u.dus ~])))
  ==
::
++  come  
  |=  old=vase
  ^-  vane
  ~|(%load-nest-bede !!)
::
++  doze
  |=  [now=@da hen=duct]
  ^-  (unit ,@da)
  ~
::
++  flee  stay
++  load
  |=  new=vase
  ^-  vane
  ?.  (~(nest ut -:!>(dez)) & p.new)
    (come new) 
  ..^$(dez ((map duct brim) q.new))
::
++  raze  
  ^-  vane
  ..$(dez ~)
::
++  scry
  |=  [our=seat ren=@tas his=seat syd=disc lot=coin tyl=path]
  ^-  (unit)
  ~
::
++  stay  `vase`!>(dez)
--
