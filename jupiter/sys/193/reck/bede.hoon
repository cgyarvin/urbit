!:
::          %bede, the shell.  This file is in the public domain.
::
=>  |%                                              ::  command models
    ++  crow                                        ::  shell expression
              $%  [%c p=crow q=(list crow)]         ::  function call
                  [%f p=path]                       ::  file by path
                  [%g p=(list path) q=gene]         ::  gene w/libs
                  [%l p=(list crow)]                ::  list
                  [%p p=(list crow)]                ::  tuple
                  ::  [%m p=(list crow)]            ::  map
                  ::  [%s p=(list crow)]            ::  set
              ==                                    ::
    ++  lark                                        ::  parsed command
              $%  [%cd p=path]                      ::  change directory
                  [%eh p=crow]                      ::  print and record
                  [%go p=path q=(list crow)]        ::  run application
                  [%no p=(list crow)]               ::  show result type
              ==                                    ::
    --                                              ::
|%
++  berg                                                ::  repl/shell
  |=  who=flag                                          ::  per identity
  =+  :*  nub=`vase`!>(+>)                              ::  system + libraries
          hub=(hoof stub)                               ::  stage extension
          hit=[p=0 q=*(list tape)]                      ::  source history
          sur=[p=0 q=*(qeu vase)]                       ::  result history
          haf=[p=0 q=*tape]                             ::  partial input
          hox=(cost %p who)                             ::  identity string
          cwd=*path                                     ::  working directory
          way=*(map ,@ta vase)                          ::  variables
      ==
  |=  [now=@da sky=_|+(* *(unit))] 
  =+  wen=(cost %da now)
  =+  wer=`path`[hox wen %cx (weld cwd [hub ~])]
  =+  rew=(flop wer)
  =+  vez=(vang & wer)
  |%
  ++  lo                                                ::  parsers
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
    ++  itap
      |=  rol=@ta
      ;~  pose
        htap
        ;~  plug
          %+  cook
            |=(a=flag ~(rent co ~ %p a))
          ;~(pose ;~(pfix sig fed:ag) (easy who))
        ::
          ;~  pose      ::  XX slow, backtracks
            %+  cook
              |=(a=@ta [~(rent co ~ %da now) %cx %main rol a hub ~])
            sym
          ::
            %+  cook
              |=([a=@ta b=@ta] [~(rent co ~ %da now) %cx a rol b hub ~])
            ;~(plug sym ;~(pfix fas sym))
          ::
            %+  cook
              |=([a=@ta b=@ta c=@ta] [c %cx a rol b hub ~])
            ;~(plug sym ;~(pfix fas sym) ;~(pfix fas sym))
          ==
        ==
      ==
    ++  kral
      ;~  pose
        ;~  pfix  col
          ;~  pfix  ;~(plug (just 'c') (just 'd') gap)
            (stag %cd htap)
          ==
        ::
          %+  stag
            %go 
          ;~  plug
            (itap %app)
            (most ace worc)
          ==
        ==
      ::
        (stag %eh (stag %p (most ace worc)))
      ==
    ++  worc
      %+  knee  *crow  |.  ~+
      ;~  pose
        ;~  pfix  buc
          %+  cook
            |=  [a=path b=(list crow)]
            `crow`[%c [%f a] b]
          ;~  plug
            (itap %fit)
            (ifix [pel per] (most ace worc))
          ==
        ==
        (stag %g (stag ~ wide:vez))
      ==
    --
  ::
  ++  chaf                                              ::  missing error
    |=  lap=(list)
    ^-  (list card)
    :-  [%warn %2 %leaf "<not found>"]
    %+  turn
      lap
    |=(a=* [%warn %1 (dish:ut [~ %path] (path a))])
  ::
  ++  doul                                              ::  crow to gene
    |=  woc=crow
    ^-  gene
    ?-    -.woc
        %c
      [%cnhp $(woc p.woc) $(woc [%p q.woc]) ~]
    ::
        %f
      =+  txt=((hard ,@) .^(p.woc))
      (scan (trip txt) (full (ifix [gay gay] tall:vez)))
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
  ++  epic
    |=  woc=crow
    ^-  tank
    =+  vax=(slap nub (doul woc))
    (dish:ut ~(dole ut p.vax) q.vax) 
  ::
  ++  felp                                              ::  apply lark
    |=  kal=lark
    ^-  [p=(list card) q=_..^$]
    ?-    -.kal
        %cd
      [~ ..^$(cwd p.kal)]
    ::
        %eh
      =+  ton=(mung [epic p.kal] sky)
      ?-  -.ton
        %0  [[[%talk (tank p.ton)] ~] ..^$]
        %1  [(chaf p.ton) ..^$]
        %2  [[[%crap p.ton] ~] ..^$]
      ==
    ::
        %go
      !!
        %no
      !!
    ==
  ::
  ++  flim                                              ::  apply line
    |=  pet=tape
    ^-  [p=(list card) q=_..^$]
    =>  .(p.hit +(p.hit), q.hit [pet q.hit])
    =+  zif=((full kral:lo) [1 1] pet)
    ?~  q.zif
      :_  ..^$
      =+  duf=[p=~(rend co ~ %ud p.p.zif) q=~(rend co ~ %ud q.p.zif)]
      [[%warn %2 %leaf "<syntax error at [{p.duf} {q.duf}]>"] ~]
    (felp p.u.q.zif)
  ::
  ++  knap                                              ::  apply event
    |=  fav=card
    ^-  [p=(list card) q=_..^$]
    ?+    -.fav  [~ ..^$]
        %dire
      :-  ~
      %_(..^$ way (~(put by way) p.fav [(lewd 'dram') q.fav]))
    ::
        %file
      :-  ~
      %_(..^$ way (~(put by way) p.fav [[%atom %%] q.fav]))
    ::
        %helo
      [[prom ~] ..^$]
    ::
        %line
      (flim (rip 3 p.fav))
    ==
  ::
  ++  lewd                                              ::  type by name
    |=  txt=@t
    ^-  type
    (~(play ut p.nub) (rash txt wide:vast))
  ::
  ++  love                                              ::  ^+ by name
    |=  [txt=@t vax=vase]
    ^-  (unit)
    ?.((~(nest ut (lewd txt)) | p.vax) ~ [~ q.vax])
  ::
  ++  lube                                              ::  make subject
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
        [(lewd '*(list ,@)') q.hit]
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
  ++  none                                              ::  standard failure
    ^-  (list card)
    [[%warn %2 [%leaf "<invalid command>"]] ~]
  ::
  ++  prom                                              ::  normal prompt
    ^-  card
    [%prop & (rap 3 (weld (rip 3 hox) ": "))]
  ::
  ++  stay                                              ::  add to results
    |=  vax=vase
    %_    ..^$
        sur
      ?:  =(16 p.sur)
        [16 (~(put to q:~(get to q.sur)) vax)]
      [+(p.sur) (~(put to q.sur) vax)]
    ==
  --
--
