!:
::          %eyre, main loop.   This file is in the public domain.
::
=<  |%
    ++  peek  
      |=  [our=flag now=@da hap=path]
      ^-  (unit)
      ?~  hap  ~
      ((~(beck is now) [~ our]) hap)
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
      $:  rav=vane                                          ::  PKI and net
          dyb=vane                                          ::  shell
          gul=vane                                          ::  http
          yac=vane                                          ::  filesystem
          lyd=vane                                          ::  terminal
          ^=  eyre                                          ::  i/o
        $:  gem=(map flag chum)                             ::  hashed passcodes
            rev=(map hose flag)                             ::  identities
            seh=(list ,[p=host q=flag])                     ::  http owners
        ==
      == 
    --
=+  sys=*game
=.  dyb.sys  bede
=.  lyd.sys  dill
=.  gul.sys  gall
=.  rav.sys  ames
=.  yac.sys  cary
|%
++  is
  |_  now=@da 
  ++  si
    |%  
    ++  arv
      |=  [pex=tire mov=move]
      ^-  [(list move) game]
      =+  sky=(beck p.mov)
      =+  yub=(beat:(rav.sys now (shax now) sky) p.mov pex q.mov r.mov)
      :-  p.yub
      sys(rav q.yub)
    ::
    ++  bed
      |=  [pex=tire mov=move]
      ^-  [(list move) game]
      =+  sky=(beck p.mov)
      =+  yub=(beat:(dyb.sys now (shax now) sky) p.mov pex q.mov r.mov)
      :-  p.yub
      sys(dyb q.yub)
    ::
    ++  car
      |=  [pex=tire mov=move]
      ^-  [(list move) game]
      =+  sky=(beck p.mov)
      =+  yub=(beat:(yac.sys now (shax now) sky) p.mov pex q.mov r.mov)
      :-  p.yub
      sys(yac q.yub)
    ::
    ++  dyl
      |=  [pex=tire mov=move]
      ^-  [(list move) game]
      =+  sky=(beck p.mov)
      =+  yub=(beat:(lyd.sys now (shax now) sky) p.mov pex q.mov r.mov)
      :-  p.yub
      sys(lyd q.yub)
    --
  ::
  ++  beck  
    |=  owr=(unit flag)
    |+  hap=*
    ^-  (unit)
    =>  .(hap ((hard path) hap))
    ?~  owr  ~
    ?.  ?=([@ @ @ *] hap)  ~
    =+  :*  hyr=(slay i.hap) 
            ved=(slay i.t.hap) 
            fal=(slay i.t.t.hap)
            tyl=t.t.t.hap
        ==
    ?.  ?=([~ %% %tas @] hyr)  ~
    ?.  ?=([~ %% %p @] fal)  ~
    =+  his=`@p`q.p.u.fal
    =>  .(owr [~ u=his])                                    ::  XX no!
    =+  [pef=(end 3 1 q.p.u.hyr) rem=(rsh 3 1 q.p.u.hyr)]
    ?+  pef  ~
      %a  (scry:(rav.sys now (shax now) ..$) u.owr rem his u.ved tyl)
      %c  (scry:(yac.sys now (shax now) ..$) u.owr rem his u.ved tyl)
    ==
  ::
  ++  grit                                                  ::  cause privilege
    |=  cul=hose
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
