!:
::          %bede, the shell.  This file is in the public domain.
::
|%                                                      ::
++  berg                                                ::  repl/shell
  |=  who=lord                                          ::  per identity
  =+  :*  nub=`vase`!>(+>)                              ::  system + libraries
          hub=(hoof stub)                               ::  stage extension
          hit=[p=0 q=*(list tape)]                      ::  source history
          sur=[p=0 q=*(qeu vase)]                       ::  result history
          hox=(cost %p who)                             ::  identity string
          cwd=*path                                     ::  working directory
          way=*(map ,@ta vase)                          ::  variables
          lif=*dock                                     ::  processes
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
            |=(a=lord ~(rent co ~ %p a))
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
    =+  oun=(slap nub (doul [%f pax]))    ::  XX condense
    =+  tib=(slap nub (doul arg))
    =+  yem=:(slop [[%atom %p] who] [[%atom %da] now] [(lewd '*path') pax])
    =+  wuy=(slam oun yem)
    =+  gyd=(slam wuy [(lewd '*conf') [~ ~]])
    (slam gyd tib)
  ::
  ++  feat                                              ::  slice weak vase
    |=  [axe=axis vux=*]  ^-  *
    q:(slam (lege %slot) (slop [[%atom %%] axe] [(lewd '*vase') vux]))
  ::
  ++  feck
    |=  [ton=tone kal=lark fun=_|+(* [p=*(list card) q=*(unit boar)])]
    ^-  [p=(list card) q=(unit boar)]
    ?-  -.ton
      %0  (fun p.ton)
      %1  [~ [~ %| ((hard (list path)) p.ton) kal]]
      %2  [[[%crap p.ton] ~] ~]
    ==
  ::
  ++  fedo                                              ::  postprocess slips
    |=  [hen=caul ask=(list slip)]
    ^-  [p=(list slip) q=(list move)]
    =+  [aks=*(list slip) pir=*(list move)]
    |-  ^-  [p=(list slip) q=(list move)]
    ?~  ask  
      [aks pir]
    ?-    -.q.i.ask
        %ez             ::    XX we may already have it - sky?
      %=  $
        ask  t.ask 
        aks  [i.ask aks]
        pir  [[[~ who] hen [%talk %leaf "? {(dart:ut p.i.ask)}"]] pir]
      ==
    ::
        %fu
      !!
    ::
        %la
      !!
    ::
        %up
      %=  $
        ask  t.ask 
        aks  [i.ask aks]
        pir  :_  pir
             :+  [~ who] 
               [[%eyre %bede (cost %ud p.lif) p.i.ask] hen]
             [%prop p.q.i.ask]
      ==
    ::
        %wa
      !!
    ==
  ::
  ++  feer
    |=  bor=boar
    ^-  _..^$
    ..^$(p.lif +(p.lif), q.lif (~(put by q.lif) p.lif bor))
  ::
  ++  feez                                              ::  process boar
    |=  hen=caul 
    |=  [out=(list card) tow=(unit boar)]
    =+  oum=`(list move)`(turn out |=(a=card [[~ who] hen a]))
    ^-  [p=(list move) q=_..^^$]
    ?~  tow
      [oum ..^^$]
    ?-  -.u.tow
      &  =+  fek=(fedo hen p.u.tow)
         [(weld q.fek oum) (feer u.tow(p p.fek))]
      |  =+  fek=(fedo hen (turn p.u.tow |=(a=path [~ [%ez a]])))
         [(weld q.fek oum) (feer u.tow)]
    ==
  ::
  ++  felp                                              ::  apply lark
    |=  [hen=caul kal=lark]
    ^-  [p=(list move) q=_..^$]
    ?-    -.kal
        %cd
      [~ ..^$(cwd p.kal)]
    ::
        %eh
      %-  (feez hen)
      %^    feck 
          (mung [echo p.kal] sky) 
        kal 
      |=  poc=*
      ^-  [p=(list card) q=(unit boar)]
      [[[%talk ((hard tank) poc)] ~] ~]
    ::
        %go
      %-  (feez hen)
      %^    feck 
          (mung [fapp [p.kal q.kal]] sky) 
        kal
      |=  poc=*
      ^-  [p=(list card) q=(unit boar)]
      :-  ((hard (list card)) +:(feat 2 poc))
      =+  doy=(feat 3 poc)
      ?~  +.doy  ~
      :-  ~
      ?+  +>-.doy  !!
        &  [%& ((hard (list slip)) +>+<.doy) (feat 31 doy)]
        |  [%| ((hard (list path)) +>+<.doy) ((hard lark) +>+>.doy)]
      ==
    ::  
        %no
      !!
    ==
  ::
  ++  flam                                              ::  line default
    |=  [hen=caul fet=tape]
    ^-  [p=(list move) q=_..^$]
    =>  .(p.hit +(p.hit), q.hit [fet q.hit])
    =+  zif=((full kral:lo) [1 1] fet)
    ?~  q.zif
      :_  ..^$
      =+  duf=[p=~(rend co ~ %ud p.p.zif) q=~(rend co ~ %ud q.p.zif)]
      :~  :+  [~ who]  hen 
          [%warn %2 %leaf "<syntax error at [{p.duf} {q.duf}]>"]
      ==
    (felp hen p.u.q.zif)
  ::
  ++  flim                                              ::  line to shell
    |=  [pex=path hen=caul fet=tape]
    ^-  [p=(list move) q=_..^$]
    ?~  pex
      (flam hen fet)
    =+  yex=(slay i.pex)
    ?>  ?=([~ %% %ud @] yex)
    =+  bog=`boar`(need (~(get by q.lif) q.p.u.yex))
    !! 
  ::
  ++  leap                                              ::  dispatch bad card
    |=  [pex=path hen=caul fav=card]
    ^-  [p=(list move) q=_..^$]
    ?+    -.fav  [~ ..^$]
        %line
      (flim pex hen (rip 3 p.fav))
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
