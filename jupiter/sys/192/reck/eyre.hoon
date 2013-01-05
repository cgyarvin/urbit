!:
::          %eyre, main loop.   This file is in the public domain.
::
=<  |%
    ++  peek  
      |=  [now=@da hap=path]
      ^-  (unit)
      ?~  hap  ~
      =+  fod=(slay i.hap)
      ?:  ?=([%% ~ %p @] fod)
        (~(beck is now) q.p.u.fod t.hap)
      ?.  ?=([%% ~ %tas @] fod)  ~
      (~(dear is now) q.p.u.fod t.hap)
    ::
    ++  poke  
      |=  [now=@da ovo=*]
      =>  .(ovo ((hard ovum) ovo))
      ::  ~&  [%ovum ovo]
      ^-  [p=(list ovum) q=_+>]
      =^  zef  sys
        (~(howl is now) ~ [[%eyre ~] p.ovo ~] q.ovo)
      [zef +>.$]
    --
=>  |%
    ++  game
      $:  ^=  arvo                                          ::  network and PKI
        $:  gel=_*alga
        ==
          ^=  bede                                          ::  shell
        $:  maw=(map lord _*berg)
        ==
          ^=  cary                                          ::  filesystem
        $:  duw=_clay
        ==
          ^=  eyre                                          ::  i/o
        $:  gem=(map lord chum)                             ::  hashed passcodes
            liv=(map lord (list vein))                      ::  live consoles
            rev=(map vein lord)                             ::  identities
            seh=(list ,[p=host q=lord])                     ::  http owners
        ==
      == 
    --
=+  sys=*game
=.  gel.arvo.sys  $:alga
=.  duw.cary.sys  clay
|%
++  is
  |_  now=@da 
  ++  si
    |%  
    ++  arv
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      =+  yub=(knap:gel.arvo.sys now r.mov)
      :-  (turn p.yub |=(a=card [p.mov q.mov a]))
      sys(gel.arvo q.yub)
    ::
    ++  bed
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      ?>  ?=(^ p.mov)
      =+  ^=  beg  ^+  *berg
          =+  beg=(~(get by maw.bede.sys) u.p.mov)
          ?^(beg u.beg (berg u.p.mov))
      =+  ^=    yub
          %^    leap:(beg now (shax now) |=(a=* (beck u.p.mov (path a))))
              pex 
            q.mov 
          r.mov
      :-  p.yub
      sys(maw.bede (~(put by maw.bede.sys) u.p.mov q.yub))
    ::
    ++  car
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      ?>  ?=(^ p.mov)
      =+  yub=(drip:duw.cary.sys now u.p.mov r.mov)
      :-  (turn p.yub |=(a=card [p.mov q.mov a]))
      sys(duw.cary q.yub)
    --
  ::
  ++  auth                                                  ::  match password
    |=  [our=lord cof=chum]
    ^-  ?
    =+  fup=(~(get by gem.eyre.sys) our)
    ?^  fup
      =(cof u.fup)
    =+  gys=(~(us go ton.fox.gel.arvo.sys) our)
    ?&(?=(^ gys) =(cof (shak our pac:ex:q:sen:u.gys)))
  ::
  ++  beck                                                  ::  namespace
    |=  [our=lord hap=path]
    ^-  (unit)
    ::  ~&  [%beck our hap]
    ?.  ?=([@ @ @ *] hap)  ~
    =+  :*  fal=(slay i.hap) 
            ved=(slay i.t.hap) 
            hyr=(slay i.t.t.hap)
            tyl=t.t.t.hap
        ==
    ?.  ?=([~ %% %p @] fal)  ~
    ?.  ?=([~ %% %tas @] hyr)  ~
    =+  [pef=(end 3 1 q.p.u.hyr) rem=(rsh 3 1 q.p.u.hyr)]
    ?+    pef  ~
        %a                                                  ::  arvo
      ?.  =(0 rem)  ~
      ?+    ved  ~
          [~ %% %ud @]
        (perm:gel.arvo.sys our q.p.u.fal q.p.u.ved tyl)
      ::
          [~ %% %da @]
        ?.  =(now q.p.u.ved)  ~
        (temp:gel.arvo.sys our q.p.u.fal tyl)
      ==
    ::
        %c                                                  ::  cary
      ?.  ?=(?(%z %y %x %w) rem)  ~
      ?.  ?=([~ %% ?(%ud %da %tas) @] ved)  ~
      (scry:duw.cary.sys rem our u.ved tyl)
    ==
  ::
  ++  dear                                                  ::  global vision
    |=  [mol=@tas hap=path]
    ^-  (unit)
    ?+    mol  ~
        %eyre
      ?+    hap  ~
          [%prod *]  ^-  (unit ,[p=prom q=@tas])
        =+  yup=(~(get by rev.eyre.sys) `vein`[t.hap ~])
        ?~  yup
          [~ & '# ']
        =+  byg=(~(get by maw.bede.sys) u.yup)
        ?~  byg
          [~ & (cat 3 ~(rent co ~ %p u.yup) '> ')]
        =+  pro=prot:(u.byg now (shax now) |=(a=* (beck u.yup (path a))))
        [~ p.pro (rap 3 q.pro)]
      ==
    ==
  ::
  ++  grit                                                  ::  cause privilege
    |=  cul=vein
    ^-  ?(%gold %iron %lead)
    ?~  cul
      %lead
    ?~  t.cul
      ?:  ?=([%gold *] i.cul)  %gold
      ?:  ?=([%iron *] i.cul)  %iron
      %lead
    $(cul t.cul)
  ::
  ++  hone                                                  ::  host match
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
  ++  hope                                                  ::  lord from host
    |=  hom=host
    =+  seh=seh.eyre.sys
    |-  ^-  (unit lord)
    ?~  seh  ~
    ?:((hone hom p.i.seh) [~ q.i.seh] $(seh t.seh))
  ::
  ++  howl                                                  ::  handle event 
    |=  mov=move
    =+  [mor=`(list move)`[mov ~] out=`(list ovum)`~]
    |-  ^-  [p=(list ovum) q=game]
    ?~  mor
      [(flop out) sys]
    =>  %_(. mov i.mor)
    ?>  ?=(^ q.mov)           ::  at least one path
    ?>  ?=(^ i.q.mov)         ::  at least prefix
    =+  pex=t.i.q.mov
    ?+    i.i.q.mov  ~&([%howl-no i.i.q.mov] !!)
        %arvo
      =^  fez  sys
        (arv:si pex [p.mov t.q.mov r.mov])
      $(mor (weld fez t.mor))
    ::
        %bede
      =^  fez  sys
        (bed:si pex [p.mov t.q.mov r.mov])
      $(mor (weld fez t.mor))
    ::
        %cary
      =^  fez  sys
        (car:si pex [p.mov t.q.mov r.mov])
      $(mor (weld fez t.mor))
    ::
        %eyre
      =.  p.mov  ?^(p.mov p.mov (~(get by rev.eyre.sys) t.q.mov))
      =+  red=|=(a=card ^$(mor [[p.mov q.mov a] t.mor]))
      =+  rer=|=(a=@tas ^$(mor [[p.mov [[a ~] q.mov] r.mov] t.mor]))
      =+  giv=|.(^$(mor t.mor, out [[i.t.q.mov r.mov] out]))
      =+  mel=(grit t.q.mov)
      =+  ^=  lov
          |=  a=lord 
          ^$(mor t.mor, rev.eyre.sys (~(put by rev.eyre.sys) t.q.mov a))
      ?-    -.r.mov
          %bbye  !!
          %bind
        ?>  =(%gold mel)
        %=    $
            mor  t.mor
            seh.eyre.sys
          :-  [q.r.mov p.r.mov]
          (skip seh.eyre.sys |=([a=host b=lord] (hone q.r.mov a)))
        ::
            out
          :_  out
          :-  i.t.q.mov
          [%talk %leaf "http: serving {<p.r.mov>} on {<q.r.mov>}"]
        ==
      ::
          %boot  !!
          %cash  (rer %arvo)
          %crap  (giv)
          %dire  (rer %bede)
          %dump  (giv)
          %edit
        %=    $
            mor
          :_  t.mor
          :+  ?^  p.mov  
                ?>(=(u.p.mov p.r.mov) p.mov)
              ?>(=(%gold mel) [~ p.r.mov])
            [[%cary ~] q.mov]
          r.mov
        ==
      ::
          %file  (rer %bede)
          %hear  (rer %arvo)
          %helo  !!
          %init  
        %=  $
          out  [[i.t.q.mov r.mov] out]
          mor  [[p.mov [[%cary ~] q.mov] r.mov] t.mor]
        ==
      ::
          %junk  (rer %arvo)
          %line  (rer %bede)
          %load  (giv) 
          %logn 
        ?>  !=(%lead mel)
        ?>  (auth p.r.mov q.r.mov)
        (lov p.r.mov)
      ::
          %logp
        ?>  =(%gold mel)
        ~&  [%logp p.r.mov]
        (lov p.r.mov)
      ::
          %loot  (giv)
          %love   !!
          %make  (rer %arvo)
          %mine  (rer %bede)
          %pace  !!
          %pour  (giv)
          %pump  !!
          %save  (giv)
          %send  (giv)
          %ship  (rer %cary)
          ?(%thin %this)
        =+  heq=(thin =(%this -.r.mov) p.r.mov)
        =+  whu=(hope q.p.p.heq)
        ?~  whu
          $(mor t.mor, out [[i.t.q.mov [%thou 404 ~ ~]] out])
        $(mor [[whu [[%bede ~] q.mov] [%thee heq]] t.mor])
      ::
          %sync  !!
          %talk  (giv) 
          %text  (red [%talk %leaf p.r.mov])
          %that
        ?+    -.p.r.mov  !!
            %hmx
          %=    $
              mor  t.mor
              out  :-  :-  i.t.q.mov
                       :-  %thou 
                       ^-  httr
                       :+  200 
                         ~[content-type/'text/html']
                       [~ (tact (xmlt p.p.r.mov ~))]
                   out
          ==
        ==
          %thee  (rer %bede)
          %thou  !!
          %tory  !!
          %warn  (giv) 
          %word  !!
      ==
    ==
  --
--
