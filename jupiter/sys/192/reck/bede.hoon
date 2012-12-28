!:
::          %bede, the shell.  This file is in the public domain.
::
|%
++  berg                                                ::  repl/shell
  |=  who=lord                                          ::  per identity
  =+  nub=`vase`!>(+>)                                  ::  system + libraries
  =+  :*  ^=  vax                                       ::  chestnut vases
            :*  sot=(slap nub (vice 'slot'))            ::
            ==                                          ::
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
  ++  do                                                ::  userspace code
    |%
    ++  dive                                            ::  opts to gene
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
    ++  doul                                            ::  crow to gene
      |=  woc=crow
      ^-  gene
      ?-    -.woc
          %c
        [%cnhp $(woc p.woc) $(woc [%p q.woc]) ~]
      ::
          %f
        %+  scan  (trip ((hard ,@) .^(p.woc)))
        (full (ifix [gay gay] tall:vez))
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
    ++  echo                                            ::  echo argument
      |=  [yun=vase woc=crow]
      ^-  tank
      =+  vax=(slap yun (doul woc))
      (dish:ut ~(dole ut p.vax) q.vax) 
    ::
    ++  fane                                            ::  deliver note 
      |=  [pux=path nog=note tas=vase]
      ^-  vase
      %+  slam  tas
      ;:  slop
        [[%atom %da] now] 
        [pah.typ pux] 
        [noq.typ nog]
      ==
    ::
    ++  fapp                                            ::  launch app
      |=  [yun=vase pax=path cux=cone arg=crow]
      ^-  vase
      %+  slam
        %+  slam
          %+  slam
            (slap nub (doul [%f pax]))
          ;:  slop 
            [[%atom %p] who] 
            [[%atom %da] now] 
            [pah.typ pax]
          ==
        (slap yun (dive cux))
      (slap yun (doul arg))
    --
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
  ++  ma                                                ::  process context
    |_  [hen=tube loz=(map path goal)]
    ++  fear                                            ::  update query state
      |=  [pux=path fav=card]
      ^-  _+>
      =+  fug=(~(get by loz) pux)
      ?~  fug  +>.$
      ?+    -.u.fug  +>.$
          %up
        +>.$(loz (~(del by loz) pux))
      ==
    ::
    ++  feat                                            ::  slice weak vase
      |=  [axe=axis vux=*]  ^-  *
      =<  q
      %+  slam  sot.vax
      (slop [[%atom %%] axe] [vas.typ vux])
    ::
    ++  feck                                            ::  process mockage
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
    ++  feeb                                            ::  soft bowl to beef
      |=  poc=*
      ^-  [p=(list card) q=(list slip) r=(unit boar)]
      :-  ((hard (list card)) +:(feat 2 poc))
      =+  doy=(feat 3 poc)
      ?~  +.doy  [~ ~]
      :-  ((hard (list slip)) +>-.doy)
      [~ %& ~ ~ (feat 7 doy)]
    ::
    ++  feet                                            ::  apply result
      |=  bof=beef
      ^-  [p=(list move) q=_..^$]
      =+  lop=(turn p.bof |=(a=card [[~ who] hen a])) 
      ?~  r.bof  [lop ..^$]
      =+  fey=(feud q.bof u.r.bof)
      [(weld lop p.fey) q.fey]
    ::
    ++  felp                                            ::  apply command
      |=  kal=lark
      ^-  [p=(list move) q=_..^$]
      =+  wan=|=(a=(list path) [~ ~ ~ %| a kal])
      =+  hak=|=(a=* [[[%talk ((hard tank) a)] ~] ~ ~])
      ?-  -.kal
        %cd  [~ ..^$(cwd p.kal)]
        %eh  (feet (feck (mung [echo:do lube +.kal] sky) wan hak))
        %go  (feet (feck (mung [fapp:do lube +.kal] sky) wan feeb))
        %no  !!
      ==
    ::
    ++  feud                                            ::  process slips
      |=  [ask=(list slip) bor=boar]
      ^-  [p=(list move) q=_..^$]
      =+  kam=(~(gas by *(map path goal)) ask)
      =+  zal=(~(tap by loz) ~)
      =+  hix=p.lif
      =:  p.lif  +(p.lif)
          q.lif  (~(put by q.lif) hix [kam bor])
          ==
      =^  zin  ..^$
          |-  ^-  [(list move) _..^^$]
          ?~  ask
            [~ ..^^$]
          =^  niz  ..^^$
            $(ask t.ask)
          ?+    -.q.i.ask  [niz ..^^$]
              %up
            :-  niz
            ?:  (~(has by loz) p.i.ask)  ..^^$
            ..^^$(pak [[hix p.i.ask] pak])
          ==
      |-  ^-  [p=(list move) q=_..^^$]
      ?~  zal
        [zin ..^^$]
      =^  lus  ..^^$
        $(zal t.zal)
      ?:  (~(has by kam) p.i.zal)
        [lus ..^^$] 
      :-  lus
      ?+    -.q.i.zal  ..^^$
          %up
        ..^^$(pak (skip pak |=([a=@ud b=path] =(b `path`p.i.zal))))
      ==
    ::
    ++  flam                                            ::  deliver line
      |=  fet=tape
      ^-  [p=(list move) q=_..^$]
      =>  .(p.hit +(p.hit), q.hit [fet q.hit])
      =+  zif=((full (ifix [gay gay] kral:lo)) [1 1] fet)
      ?~  q.zif
        :_  ..^$
        =+  duf=[p=~(rend co ~ %ud p.p.zif) q=~(rend co ~ %ud q.p.zif)]
        :~  :+  [~ who]  hen 
            [%warn %2 %leaf "<syntax error at [{p.duf} {q.duf}]>"]
        ==
      (felp p.u.q.zif)
    ::
    ++  fone                                            ::  deliver note
      |=  [pux=path nob=note bor=boar]
      ^-  [p=(list move) q=_..^$]
      ?>  ?=(& -.bor)
      %-  feet
      %^    feck
          (mung [fane:do [pux nob r.bor]] sky)
        |=  a=(list path) 
        [~ ~ ~ %& a (~(put to q.bor) pux nob) r.bor]
      feeb
    --
  ::
  ++  leap                                              ::  dispatch event
    |=  [pex=path hen=tube fav=card]
    ^-  [p=(list move) q=_..^$]
    ?+    -.fav  [~ ..^$]
        %line
      =+  fet=(rip 3 p.fav)
      ?~  pak
        (~(flam ma [hen ~]) fet)
      =+  [nix=p.i.pak pux=q.i.pak]
      =>  .(pak t.pak)
      =+  byr=(need (~(get by q.lif) nix))
      =+  pey=(~(fear ma [hen p.byr]) pux fav)
      (fone:pey pux [%up p.fav] q.byr)
    ==
  ::
  ++  lube                                              ::  define subject
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
