!:
::          %bede, the shell.  This file is in the public domain.
::
|%
++  berg                                                ::  repl/shell
  |=  who=lord                                          ::  per identity
  =+  nub=`vase`!>(+>)                                  ::  system + libraries
  =+  :*  ^=  vax                                       ::  chestnut vases
            :*  sot=(slap nub (vice 'slot'))            ::
            ==
          ^=  gen                                       ::  chestnut genes
            :*  yom=(vice '*(set ,@tas)')               ::
                zim=(vice '*(map ,@tas ,*)')            ::
            ==                                          ::
          ^=  typ                                       ::  chestnut types
            =+  pal=~(play ut p.nub)                    ::
            :*  cof=(pal (vice '*conf'))                ::
                gee=(pal (vice '*gene'))                ::
                liz=(pal (vice '*(list ,@)'))           ::
                pah=(pal (vice '*path'))                ::
                noq=(pal (vice '*note'))                ::
                tak=(pal (vice '*task'))                ::
                vas=(pal (vice '*vase'))                ::
            ==                                          ::
          hub=(hoof stub)                               ::  stage extension
      ==                                                ::
  =+  :*  hit=[p=0 q=*(list tape)]                      ::  source history
          sur=[p=0 q=*(qeu vase)]                       ::  result history
          hox=(scot %p who)                             ::  identity string
          cwd=*path                                     ::  working directory
          way=*(map ,@ta vase)                          ::  variables
          pak=*(list ,[p=@ud q=path])                   ::  prompt stack
          lif=*dock                                     ::  processes
          lom=*(map path plea)                          ::  prompt by console
      ==
  |=  [now=@da eny=@ sky=_|+(* *(unit))] 
  =+  wen=(scot %da now)
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
    ++  ipto                                            ::  lights
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
    ++  ipty                                            ::  notices
      %+  knee  *(list ,[p=@tas q=crow])  |.  ~+
      (most ace ;~(plug sym ;~(pfix fas worc)))
    ::
    ++  kral                                            ::  parse lark
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
  ++  doul                                              ::  crow to gene (user)
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
  ++  dive                                              ::  opts to gene (user)
    |=  cux=cone
    ^-  gene
    :-  :+  %cncl
          `gene`[%cnsg `wing`[%gas ~] `gene`[%cnbc %in] `gene`yom.gen]
        [%clsg (turn p.cux |=(a=@ [%dtpt %tas a]))]
    :+  %cncl
      [%cnsg [%gas ~] [%cnbc %by] zim.gen]
    [%clsg (turn q.cux |=([p=@tas q=crow] [[%dtpt %tas p] (doul q)]))]
  ::
  ++  echo                                              ::  echo (user)
    |=  woc=crow
    ^-  tank
    =+  vax=(slap nub (doul woc))
    (dish:ut ~(dole ut p.vax) q.vax) 
  ::
  ++  fane                                              ::  deliver note (user)
    |=  [pux=path nog=note tas=vase]
    ^-  vase
    =+  gym=:(slop [[%atom %da] now] [pah.typ pux] [noq.typ nog])
    (slam tas gym)
  ::
  ++  fapp                                              ::  launch app (user)
    |=  [pax=path cux=cone arg=crow]
    ^-  vase
    =+  deh=(doul [%f pax])
    =+  oun=(slap nub deh)    ::  XX condense
    =+  tib=(slap nub (doul arg))
    =+  yem=:(slop [[%atom %p] who] [[%atom %da] now] [pah.typ pax])
    =+  wuy=(slam oun yem)
    =+  gyd=(slam wuy (slap nub (dive cux)))
    (slam gyd tib)
  ::
  ++  fear                                              ::  feed a bear
    |=  [pux=path fav=card ber=bear]
    ^-  bear
    :_  q.ber
    =+  fug=(~(get by p.ber) pux)
    ?~  fug  p.ber
    ?+    -.u.fug  p.ber
        %up
      (~(del by p.ber) pux)
    ==
  ::
  ++  feat                                              ::  slice weak vase
    |=  [axe=axis vux=*]  ^-  *
    q:(slam sot.vax (slop [[%atom %%] axe] [vas.typ vux]))
  ::
  ++  feck                                              ::  process mockage
    |=  :*  ton=tone 
            fob=_|+((list path) *beef) 
            fut=_|+(* *beef)
        ==
    ^-  beef
    ?-  -.ton
      %0  (fut p.ton)
      %1  (fob ((list path) p.ton))
      %2  [[[%crap p.ton] ~] ~ ~]
    ==
  ::
  ++  feeb                                              ::  vase-bowl to beef
    |=  poc=*
    ^-  [p=(list card) q=(list slip) r=(unit boar)]
    :-  ((hard (list card)) +:(feat 2 poc))
    =+  doy=(feat 3 poc)
    ?~  +.doy  [~ ~]
    :-  ((hard (list slip)) +>-.doy)
    [~ %& ~ ~ (feat 7 doy)]
  ::
  ++  feet                                              ::  process boar
    |=  [hen=tube loz=(map path goal)]
    |=  bof=beef
    ^-  [p=(list move) q=_..^^$]
    =+  lop=(turn p.bof |=(a=card [[~ who] hen a])) 
    ?~  r.bof  [lop ..^^$]
    =+  fey=((feud hen loz) q.bof u.r.bof)
    [(weld lop p.fey) q.fey]
  ::
  ++  feud                                              ::  process slips
    |=  [hen=tube loz=(map path goal)]
    |=  [ask=(list slip) bor=boar]
    ^-  [p=(list move) q=_..^^$]
    =+  kam=(~(gas by *(map path goal)) ask)
    =+  zal=(~(tap by loz) ~)
    =+  hix=p.lif
    =:  p.lif  +(p.lif)
        q.lif  (~(put by q.lif) hix [kam bor])
        ==
    =^  zin  ..^^$
        |-  ^-  [(list move) _..^^^$]
        ?~  ask
          [~ ..^^^$]
        =^  niz  ..^^^$
          $(ask t.ask)
        ?+    -.q.i.ask  [niz ..^^^$]
            %up
          :-  niz
          ?:  (~(has by loz) p.i.ask)  ..^^^$
          ..^^^$(pak [[hix p.i.ask] pak])
        ==
    |-  ^-  [p=(list move) q=_..^^^$]
    ?~  zal
      [zin ..^^^$]
    =^  lus  ..^^^$
      $(zal t.zal)
    ?:  (~(has by kam) p.i.zal)
      [lus ..^^^$] 
    :-  lus
    ?+    -.q.i.zal  ..^^^$
        %up
      ..^^^$(pak (skip pak |=([a=@ud b=path] =(b `path`p.i.zal))))
    ==
  ::
  ++  felp                                              ::  apply lark
    |=  [hen=tube kal=lark]
    ^-  [p=(list move) q=_..^$]
    =+  wan=|=(a=(list path) `beef`[~ ~ ~ %| a kal])
    =+  hak=|=(a=* `beef`[[[%talk ((hard tank) a)] ~] ~ ~])
    ?-  -.kal
      %cd  [~ ..^$(cwd p.kal)]
      %eh  ((feet hen ~) (feck (mung [echo p.kal] sky) wan hak))
      %go  ((feet hen ~) (feck (mung [fapp [p.kal q.kal r.kal]] sky) wan feeb))
      %no  !!
    ==
  ::
  ++  flam                                              ::  line default
    |=  [hen=tube fet=tape]
    ^-  [p=(list move) q=_..^$]
    =>  .(p.hit +(p.hit), q.hit [fet q.hit])
    =+  zif=((full (ifix [gay gay] kral:lo)) [1 1] fet)
    ?~  q.zif
      :_  ..^$
      =+  duf=[p=~(rend co ~ %ud p.p.zif) q=~(rend co ~ %ud q.p.zif)]
      :~  :+  [~ who]  hen 
          [%warn %2 %leaf "<syntax error at [{p.duf} {q.duf}]>"]
      ==
    (felp hen p.u.q.zif)
  ::
  ++  flim                                              ::  line to shell
    |=  [pex=path hen=tube fet=tape]
    ^-  [p=(list move) q=_..^$]
    ?~  pex
      (flam hen fet)
    =+  yex=(slay i.pex)
    ?>  ?=([~ %% %ud @] yex)
    =+  byr=(need (~(get by q.lif) q.p.u.yex))
    =.  q.lif  (~(del by q.lif) q.p.u.yex)
    =+  nob=`note`[%up (rap 3 fet)]
    ?>  ?=(& -.q.byr)
    %-  (feet hen p.byr)
    %^    feck
        (mung [fane [t.pex nob r.q.byr]] sky)
      |=(a=(list path) [~ ~ ~ %& a (~(put to q.q.byr) t.pex nob) r.q.byr])
    feeb
  ::
  ++  leap                                              ::  dispatch event
    |=  [pex=path hen=tube fav=card]
    ^-  [p=(list move) q=_..^$]
    ?+    -.fav  [~ ..^$]
        %line
      =+  fet=(rip 3 p.fav)
      ?~  pak
        (flam hen fet)
      =+  pux=q.i.pak
      =+  byr=(fear pux fav (need (~(get by q.lif) p.i.pak)))
      =>  .(pak t.pak)
      =+  nob=`note`[%up p.fav]
      ?>  ?=(& -.q.byr)
      %-  (feet hen p.byr)
      %^    feck
          (mung [fane [pux nob r.q.byr]] sky)
        |=(a=(list path) [~ ~ ~ %& a (~(put to q.q.byr) pux nob) r.q.byr])
      feeb
    ==
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
  ++  none                                              ::  standard failure
    ^-  (list card)
    [[%warn %2 [%leaf "<invalid command>"]] ~]
  ::
  ++  prot                                              ::  current prompt
    ^-  prod
    ?~  pak 
      [& (rip 3 (cat 3 hox '> '))]
    =+  byr=(need (~(get by q.lif) p.i.pak))
    =+  gol=(need (~(get by p.byr) q.i.pak))
    ?>(?=(%up -.gol) p.gol)
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
