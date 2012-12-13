!:
::          %bede, the shell.  This file is in the public domain.
::
|%                                                      ::
++  berg                                                ::  repl/shell
  |=  who=flag                                          ::  per identity
  =+  :*  nub=`vase`!>(+>)                              ::  system + libraries
          hub=(hoof stub)                               ::  stage extension
          hit=[p=0 q=*(list tape)]                      ::  source history
          sur=[p=0 q=*(qeu vase)]                       ::  result history
          hox=(cost %p who)                             ::  identity string
          cwd=*path                                     ::  working directory
          way=*(map ,@ta vase)                          ::  variables
          lif=*have                                     ::  processes
          lom=*(map path plea)                          ::  prompt by console
      ==
  |=  [now=@da sky=_|+(* *(unit))] 
  =+  wen=(cost %da now)
  =+  wer=`path`[hox wen %cx (weld cwd [hub ~])]
  =+  rew=(flop wer)
  =+  vez=(vang & wer)
  |%
  ++  lo                                                ::  command parsers
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
    ++  kral
      ;~  pose
        ;~  pfix  col
          ;~  pose
            ;~  pfix  ;~(plug (just 'c') (just 'd') gap)
              (stag %cd htap)
            ==
          ::
            ;~  pfix  ;~(plug (just 'n') (just 'o') gap)
              (stag %no (stag %p (most ace worc)))
            ==
          ::
            %+  stag
              %go
            ;~  plug
              (thap %app)
              ;~(pfix gap (stag %l (most ace worc)))
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
        ;~  plug
          %+  cook
            |=(a=flag ~(rent co ~ %p a))
          ;~(pose ;~(pfix sig fed:ag) (easy who))
        ::
          %+  cook
            |=  a=[p=@ta q=(unit ,[p=@ta q=(unit ,@ta)])]
            ?~  q.a      [~(rent co ~ %da now) %cx %main rol p.a hub ~]
            ?~  q.u.q.a  [~(rent co ~ %da now) %cx p.a rol p.u.q.a hub ~]
                         [u.q.u.q.a %cx p.a rol p.u.q.a hub ~] 
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
  ++  echo                                              ::  echo
    |=  woc=crow
    ^-  tank
    =+  vax=(slap nub (doul woc))
    (dish:ut ~(dole ut p.vax) q.vax) 
  ::
  ++  fapp                                              ::  launch app
    |=  [pax=path arg=crow]
    ^-  vase
    =+  oun=(slap nub (doul [%f pax]))    ::  XX delaminate
    =+  tib=(slap nub (doul arg))
    =+  yem=:(slop [[%atom %p] who] [[%atom %da] now] [(lewd '*path') pax])
    =+  wuy=(slam oun yem)
    =+  gyd=(slam wuy [(lewd '*conf') [~ ~]])
    (slam gyd tib)
  ::
  ++  feat                                              ::  vux is a vase
    |=  [axe=axis vux=*]
    ^-  *                                               ::  also a vase
    q:(slam (lege %slot) (slop [[%atom %%] axe] [(lewd '*vase') vux]))
  ::
  ++  feck
    |=  [ton=tone kal=lark fun=_|+(* [p=*(list card) q=..^$])]
    ^-  [p=(list card) q=_..^$]
    ?-  -.ton
      %0  (fun p.ton)
      %1  =+  yap=((hard (list path)) p.ton)
          :-  ^-  (list card)
              :-  [%warn %2 %leaf "<awaiting as {~(rend co ~ %ud p.lif)}>"]
              %+  turn
                yap
              |=(a=path [%warn %1 (dish:ut [~ %path] a)])
          ..^$(p.lif +(p.lif), q.lif (~(put by q.lif) p.lif [%| yap kal]))
      %2  [[[%crap p.ton] ~] ..^$]
    ==
  ::
  ++  felp                                              ::  apply lark
    |=  kal=lark
    ^-  [p=(list card) q=_..^$]
    ?-    -.kal
        %cd
      [~ ..^$(cwd p.kal)]
    ::
        %eh
      %^    feck 
          (mung [echo p.kal] sky) 
        kal 
      |=  poc=*
      ^-  [p=(list card) q=_..^^$]
      [[[%talk ((hard tank) poc)] ~] ..^^$]
    ::
        %go
      %^    feck 
          (mung [fapp [p.kal q.kal]] sky) 
        kal
      |=  poc=*
      ^-  [p=(list card) q=_..^^$]
      :-  ((hard (list card)) +:(feat 2 poc))
      =+  doy=(feat 3 poc)
      ?~  +.doy
        ..^^$
      %=    ..^^$
          p.lif  +(p.lif)
          q.lif
        %+  ~(put by q.lif)
          p.lif
        ?+  +>-.doy  !!
          &  [%& ((hard (list slip)) +>+<.doy) (feat 31 doy)]
          |  [%| ((hard (list path)) +>+<.doy) ((hard lark) +>+>.doy)]
        ==
      ==
    ::  
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
      %_(..^$ way (~(put by way) p.fav [(lewd '*dram') q.fav]))
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
  ++  lege                                              ::  gene by name
    |=  txt=@t
    ^-  vase
    (slap nub (rash txt wide:vast))
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
