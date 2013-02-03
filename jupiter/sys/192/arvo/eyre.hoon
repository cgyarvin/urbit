!:
::          %eyre, main loop.   This file is in the public domain.
::
=<  |%
    ++  peek  
      |=  [now=@da hap=path]
      ^-  (unit)
      ?~  hap  ~
      (~(buck is now) hap)
    ::
    ++  poke  
      |=  [now=@da ovo=*]
      ?:  !=(ovo (ovum ovo))
        ~&  [%bad-egg ovo]
        !!
      =>  .(ovo ((hard ovum) ovo))
      ::  ~&  [%ovum ovo]
      ^-  [p=(list ovum) q=_+>]
      =^  zef  sys
        (~(howl is now) ~ [[%eyre ~] p.ovo ~] q.ovo)
      [zef +>.$]
    --
=>  |%
    ++  game
      $:  rav=_*alga                                        ::  PKI and net
          deb=(map flag _*berg)                             ::  shell
          yac=_clay                                         ::  filesystem
          lyd=vane                                          ::  terminal
          ^=  eyre                                          ::  i/o
        $:  gem=(map flag chum)                             ::  hashed passcodes
            liv=(map flag (list vein))                      ::  live consoles
            rev=(map vein flag)                             ::  identities
            seh=(list ,[p=host q=flag])                     ::  http owners
        ==
      == 
    --
=+  sys=*game
=.  lyd.sys  dill
=.  rav.sys  $:alga
=.  yac.sys  clay
|%
++  is
  |_  now=@da 
  ++  si
    |%  
    ++  arv
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      =+  yub=(knap:rav.sys now r.mov)
      :-  (turn p.yub |=(a=card [p.mov q.mov a]))
      sys(rav q.yub)
    ::
    ++  bed
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      ?>  ?=(^ p.mov)
      =+  ^=  beg  ^+  *berg
          =+  beg=(~(get by deb.sys) u.p.mov)
          ?^(beg u.beg (berg u.p.mov))
      =+  ^=    yub
          %^    leap:(beg now (shax now) |=(a=* (buck (path a))))
              pex 
            q.mov 
          r.mov
      :-  p.yub
      sys(deb (~(put by deb.sys) u.p.mov q.yub))
    ::
    ++  car
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      ?>  ?=(^ p.mov)
      =+  yub=(drip:yac.sys now u.p.mov r.mov)
      :-  (turn p.yub |=(a=card [p.mov q.mov a]))
      sys(yac q.yub)
    ::
    ++  dyl
      |=  [pex=path mov=move]
      ^-  [(list move) game]
      =+  yub=(poke:(lyd.sys now (shax now) |=(a=* !!)) p.mov pex q.mov r.mov)
      :-  p.yub
      sys(lyd q.yub)
    --
  ::
  ++  buck
    |=  hap=path
    ^-  (unit)
    ?.  ?=([@ @ @ *] hap)  ~
    =+  :*  hyr=(slay i.hap) 
            ved=(slay i.t.hap) 
            fal=(slay i.t.t.hap)
            tyl=t.t.t.hap
        ==
    ?.  ?=([~ %% %tas @] hyr)  ~
    ?.  ?=([~ %% %p @] fal)  ~
    =+  our=`@p`q.p.u.fal
    =+  [pef=(end 3 1 q.p.u.hyr) rem=(rsh 3 1 q.p.u.hyr)]
    ?+    pef  ~
        %a                                                  ::  ames
      ?.  =(0 rem)  ~
      ?+    ved  ~
          [~ %% %ud @]
        (perm:rav.sys our q.p.u.fal q.p.u.ved tyl)
      ::
          [~ %% %da @]
        ?.  =(now q.p.u.ved)  ~
        (temp:rav.sys our q.p.u.fal tyl)
      ==
    ::
        %c                                                  ::  cary
      ?.  ?=(?(%z %y %x %w) rem)  ~
      ?.  ?=([~ %% ?(%ud %da %tas) @] ved)  ~
      (scry:yac.sys rem our u.ved tyl)
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
  ++  hope                                                  ::  flag from host
    |=  hom=host
    =+  seh=seh.eyre.sys
    |-  ^-  (unit flag)
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
        %ames
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
        %dill
      =^  fez  sys
        (dyl:si pex [p.mov t.q.mov r.mov])
      $(mor (weld fez t.mor))
    ::
        %eyre
      =.  p.mov  ?^(p.mov p.mov (~(get by rev.eyre.sys) t.q.mov))
      =+  red=|=(a=card ^$(mor [[p.mov q.mov a] t.mor]))
      =+  rer=|=(a=@tas ^$(mor [[p.mov [[a ~] q.mov] r.mov] t.mor]))
      =+  giv=|.(^$(mor t.mor, out [[i.t.q.mov r.mov] out]))
      =+  mel=(grit t.q.mov)
      =+  ^=  lov
          |=  a=flag 
          ^$(mor t.mor, rev.eyre.sys (~(put by rev.eyre.sys) t.q.mov a))
      ?-    -.r.mov
          %bbye  (giv)
          %bind
        ?>  =(%gold mel)
        %=    $
            mor  t.mor
            seh.eyre.sys
          :-  [q.r.mov p.r.mov]
          (skip seh.eyre.sys |=([a=host b=flag] (hone q.r.mov a)))
        ::
            out
          :_  out
          :-  i.t.q.mov
          [%talk %leaf "http: serving {<p.r.mov>} on {<q.r.mov>}"]
        ==
      ::
          %bleb  (rer %dill)
          %blit  (giv)
          %blew  (rer %dill) 
          %boot  !!
          %cash  (rer %ames)
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
          %exit  (giv)
          %file  (rer %bede)
          %hear  (rer %ames)
          %helo  (rer %dill)
          %init  
        %=  $
          out  [[i.t.q.mov r.mov] out]
          mor  [[[~ p.r.mov] [[%cary ~] q.mov] r.mov] t.mor]
        ==
      ::
          %junk  (rer %ames)
          %kill  (rer %bede)
          %line  (rer %bede)
          %load  (giv) 
          %logn  (rer %dill)
          %logo  (rer %dill)
          %logp  (rer %dill)
          %loot  (giv)
          %love  !!
          %make  (rer %ames)
          %mine  (rer %bede)
          %note
        ?:  =(t.q.mov [/gold/sync/ ~])
          $(mor [[p.mov [[%eyre ~] /gold/term/1/ ~] r.mov] t.mor])
        (rer %dill)
      ::
          %nuke  (rer %bede)
          %pace  !!
          %pour  (giv)
          %pump  !!
          %save  (giv)
          %send  (giv)
          %ship  (rer %cary)
          ?(%thin %this)
        =+  heq=(thin =(%this -.r.mov) p.r.mov)
        =+  whu=(hope r.p.p.heq)
        ?~  whu
          $(mor t.mor, out [[i.t.q.mov [%thou 404 ~ ~]] out])
        $(mor [[whu [[%bede ~] q.mov] [%thee heq]] t.mor])
      ::
          %sync  !!
          %talk  (rer %dill) 
          %tell  !!
          %text  (red [%talk %leaf p.r.mov])
          %that
        ?-    -.p.r.mov 
            %mid
          %=    $
              mor  t.mor
              out  :-  :-  i.t.q.mov
                       :-  %thou 
                       ^-  httr
                       :+  200 
                         ~[content-type/(moon p.p.r.mov)]
                       [~ q.p.r.mov]
                   out
          ==
        ::
            %ham
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
        ::
            %raw
          %=    $
              mor  t.mor
              out  :-  :-  i.t.q.mov
                       [%thou p.p.r.mov]
                   out
          ==
        ==
      ::
          %thee  (rer %bede)
          %thou  !!
          %tory  !!
          %warn  (rer %dill)
          %word  !!
      ==
    ==
  --
--
