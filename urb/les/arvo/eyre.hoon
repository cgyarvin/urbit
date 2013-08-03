!:
::  eyre (4e), http servant
::
|=  pit=vase
^-  vane                                                ::  kernel instrument
=>  =~
|%
++  bolo                                                ::  eyre state
    $:  wig=(map duct (list rout))                      ::  server routes
        ged=duct                                        ::  client interface
        giv=[p=@ud q=(map ,@ud duct)]                   ::  incoming requests
        ask=[p=@ud q=(map ,@ud ,[p=duct q=hiss])]       ::  outgoing requests
        kes=(map duct ,@ud)                             ::  outgoing requests
    ==
::
++  deft                                                ::  import url path
  |=  rax=(list ,@t)
  |-  ^-  pork
  ?~  rax
    [~ ~]
  ?~  t.rax
    =+  den=(trip i.rax)
    =+  ^=  vex
      %-  %-  full
          ;~(plug sym ;~(pose (stag ~ ;~(pfix dot sym)) (easy ~)))
      [[1 1] (trip i.rax)]
    ?~  q.vex
      [~ [~(rent co %% %t i.rax) ~]]
    [+.p.u.q.vex [-.p.u.q.vex ~]]
  =+  pok=$(rax t.rax)
  :-  p.pok
  :_  q.pok
  ?:(((sane %tas) i.rax) i.rax ~(rent co %% %t i.rax))
::
++  ecco                                                ::  eat headers
  |=  hed=(list ,[p=@t q=@t])
  =+  mah=*math
  |-  ^-  math
  ?~  hed  mah
  =+  cus=(cass (rip 3 p.i.hed))
  =+  zeb=(~(get by mah) cus)
  $(hed t.hed, mah (~(put by mah) cus ?~(zeb [q.i.hed ~] [q.i.hed u.zeb])))
::
++  epur                                                ::  url/header parser
  |%
  ++  apat  (cook deft ;~(pfix fas (more fas smeg)))    ::  2396 abs_path
  ++  auri
    ;~  plug
      ;~  plug
        %+  sear
          |=  a=@t 
          ^-  (unit ,?)
          ?+(a ~ %http [~ %|], %https [~ %&])
        ;~(sfix scem ;~(plug col fas fas))
        thor
      ==
      ;~(plug apat yque)
    == 
  ++  bite                                              ::  cookies (ours)
    (most sem ;~(plug nuck:so ;~(pfix sem nuck:so))) 
  ++  dlab                                              ::  2396 domainlabel
    %+  sear
      |=  a=@ta
      ?.(=('-' (rsh 3 a (dec (met 3 a)))) [~ u=a] ~)
    %+  cook  cass
    ;~(plug aln (star alp))
  ::
  ++  fque  (cook crip (plus pquo))                     ::  normal query field
  ++  pcar  ;~(pose pure pesc psub col pat)             ::  2396 path char
  ++  pesc  ;~(pfix cen mes)                            ::  2396 escaped
  ++  pold  (cold ' ' (just '+'))                       ::  old space code
  ++  pque  ;~(pose pcar fas wut)                       ::  3986 query char
  ++  pquo  ;~(pose pure pesc pold)                     ::  normal query char
  ++  pure  ;~(pose aln hep dot cab sig)                ::  2396 unreserved
  ++  psub  ;~  pose                                    ::  3986 sub-delims
              zap  buc  pam  soq  pel  per 
              tar  lus  com  sem  tis
            ==
  ++  scem                                              ::  2396 scheme
    %+  cook  cass
    ;~(plug alf (star ;~(pose aln lus hep dot)))
  ::
  ++  smeg  (cook crip (plus pcar))                     ::  2396 segment
  ++  thor                                              ::  2396 host/port
    %+  cook  |*(a=[* *] [+.a -.a])
    ;~  plug
      thos
      ;~(pose (stag ~ ;~(pfix col dim:ag)) (easy ~))
    ==
  ++  thos                                              ::  2396 host, no local
    ;~  plug
      ;~  pose
        %+  stag  %&
        %+  sear                                        ::  LL parser weak here
          |=  a=(list ,@t)
          =+  b=(flop a)
          ?>  ?=(^ b)
          =+  c=(end 3 1 i.b)
          ?.(&((gte c 'a') (lte c 'z')) ~ [~ u=b])
        (most dot dlab)
      ::
        %+  stag  %|
        =+  tod=(ape:ag ted:ab) 
        %+  bass  256
        ;~(plug tod (stun [3 3] ;~(pfix dot tod)))
      ==
    ==
  ++  yque                                              ::  query ending
    ;~  pose
      ;~(pfix wut yquy)
      (easy ~)
    ==
  ++  yquy                                              ::  query
    %+  cook
      |=  a=(list ,[p=@t q=@t])
      (~(gas by *(map ,@t ,@t)) a)
    ;~  pose                                            ::  proper query
      %+  more
        ;~(pose pam sem)
      ;~(plug fque ;~(pfix tis fque))
    ::
      %+  cook                                          ::  funky query
        |=(a=tape [[%% (crip a)] ~])
      (star pque)
    ==
  ++  zest                                              ::  2616 request-uri
    ;~  pose
      (stag %& (cook |=(a=purl a) auri))
      (stag %| ;~(plug apat yque))
    ==
  --
::
++  hone                                                ::  host match
  |=  [fro=host too=host]  ^-  ?
  ?-    -.fro
      |  =(too fro)
      &
    ?&  ?=(& -.too)
        |-  ^-  ?
        ?~  p.too  &
        ?~  p.fro  |
        ?:  !=(i.p.too i.p.fro)  |
        $(p.too t.p.too, p.fro t.p.fro)
    ==
  ==
::
++  loot                                                ::  match route
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
--
. ==
=|  bolo
|=  [now=@da eny=@ sky=||(* (unit))]                    ::  activate
^?                                                      ::  opaque core
|%                                                      ::
++  beat                                                ::  process move
  |=  [wru=(unit writ) tea=wire hen=duct fav=curd]
  =>  .(fav ((hard card) fav))
  ^-  [p=(list move) q=vane]
  ?+    -.fav
    [[[wru hen fav] ~] ..^$]
  ::
      %band                                             ::  set/clear route
    [~ ..^$(wig ?~(q.fav (~(del by wig) hen) (~(put by wig) hen q.fav)))]
  ::
      %born
    [~ ..^$(ged hen)]      ::  XX retry all gets, abort all puts
  ::
      %crud
    [[[wru [/d hen] %flog fav] ~] ..^$]
  ::
      %that                                             ::  response by us
    =+  neh=(need (~(get by q.giv) p.fav))
    :_  ..^$(q.giv (~(del by q.giv) p.fav))
    :_  ~
    :+  ~  hen
    :-  %thou
    ^-  httr
    ?-  -.q.fav
      %mid  [200 ~[content-type/(moon p.q.fav)] [~ q.q.fav]]
      %ham  [200 ~[content-type/'text/html'] [~ (tact (xmlt p.q.fav ~))]]
      %raw  p.q.fav
    ==
  ::
      %them                                             ::  outgoing request
    ?~  p.fav
      =+  sud=(need (~(get by kes) hen))
      :-  [[~ ged [%thus sud ~]] ~]
      ..^$(q.ask (~(del by q.ask) sud), kes (~(del by kes) hen))
    :-  [[~ ged [%thus p.ask p.fav]] ~]
    %=  ..^$
      p.ask  +(p.ask)
      q.ask  (~(put by q.ask) p.ask hen u.p.fav)
      kes    (~(put by kes) hen p.ask)
    ==
  ::
      %they                                             ::  response to us
    =+  kas=(need (~(get by q.ask) p.fav))
    :-  [[~ p.kas [%thou q.fav]] ~]
    ..^$(q.ask (~(del by q.ask) p.kas))
  ::
      %this                                             ::  request to us
    =+  ryp=`quri`(rash q.r.fav zest:epur)
    =+  mah=(ecco r.r.fav)
    =+  ^=  pul  ^-  purl
        ?-  -.ryp
          &  ?>(=(p.fav p.p.p.ryp) p.ryp)
          |  =+  hot=(~(get by mah) %host)
             ?>  ?=([~ @ ~] hot)
             [[p.fav (rash i.u.hot thor:epur)] p.ryp q.ryp]
        ==
    =+  het=`hate`[pul (shaf %this q.fav) [p.r.fav mah s.r.fav]]
    =+  gew=`(list ,[p=duct q=(list rout)])`(~(tap by wig) ~)
    =+  ^=  faw  
        |-  ^-  (list ,[p=duct q=scud])
        ?~  gew  ~
        =+  mor=$(gew t.gew)
        =+  ^=  woy
            |-  ^-  (list scud)
            ?~  q.i.gew  ~
            =+  mor=$(q.i.gew t.q.i.gew)
            =+  lut=(loot pul i.q.i.gew)
            ?~(lut mor [u.lut mor])
        ?~  woy  mor
        ::  ?^  t.woy  [[[~ hen [%thou 500 ~ ~]] ~] ..^^$]
        [[p.i.gew i.woy] mor]
    ?~  faw  [[[~ hen [%thou 404 ~ ~]] ~] ..^$]
    ::  ?^  t.faw  [[[~ hen [%thou 500 ~ ~]] ~] ..^$]
    :-  [[~ p.i.faw [%thee p.giv q.i.faw het]] ~]
    ..^$(p.giv +(p.giv), q.giv (~(put by q.giv) p.giv hen))
  ==
::
++  come  
  |=  old=vase
  ^-  vane
  ~|(%load-nest-eyre !!)
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
  ?.  (~(nest ut -:!>(`bolo`+>-.^$)) & p.new)
    (come new)
  ..^$(+>- (bolo q.new))
::
++  raze  
  ^-  vane
  ..$(+>- *bolo)
::
++  scry
  |=  [our=seat ren=@tas who=seat syd=disc lot=coin tyl=path]
  ^-  (unit)
  ~
::
++  stay  `vase`!>(`bolo`+>-.$)
--
