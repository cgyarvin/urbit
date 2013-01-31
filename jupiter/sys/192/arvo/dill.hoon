!:
::          %dill, terminal handling.  This file is in the public domain.
::
|%                                                      
++  dill                                                ::  terminal handling
  =|  wib=(map vein yard)                               ::  state by terminal
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  current invocation
  |%                                                    ::  poke/peek pattern
  ++  peek
    |=  pax=path
    ^-  (unit)
    !!
  ::
  ++  poke                                              ::  process move
    |=  [whu=(unit flag) pax=path hen=vein fav=card]
    ^-  [p=(list move) q=_..^$]
    ::  =>  ^+(. ?:(?=([%bleb %txt *] fav) . ~&([%dill-poke fav hen] .)))
    =^  yar  +> 
      ^-  [yard _+>]
      =+  yur=(~(get by wib) hen)
      ?~  yur
        =+  ^=  yer  ^-  yard
            :*  &
                ?~(whu ~ [u.whu ~])
                `blur`[80 ~]
                *(map ,[p=flag q=path] hist)
            ==
        [yer +>.$(wib (~(put by wib) hen yer))]
      [u.yur +>.$]
    =.  whu  ?~(q.yar ~ [~ i.q.yar])
    =|  mos=(list move)
    =<  yerk:leap
    |%
    ++  beep  (curb [[%bel ~] ~])                       ::  send beep
    ++  curb                                            ::  send blits
      |=  wab=(list blit)
      ^+  +>
      ?~  wab  +>
      +>(mos [[~ hen [%blit (flop wab)]] mos])
    ::
    ++  edit                                            ::  change the bed
      |=  bed=bead
      ^+  +>
      =.  q.r.yar  [~ bed]
      %-  curb
      :~  [%hop (add pol.bed bus.bed)]
          [%lin (weld `(list ,@)`pot.bed but.bed)]
      ==
    ::
    ++  fume                                            ::  print tank, prefix
      |=  [pef=@tD tac=tank]
      ^+  +>
      =+  wol=(~(win re tac) 2 p.r.yar)
      %-  furl
      %+  turn  wol
      |=  a=tape  ^-  tape
      ?>  ?=([@ @ *] a)
      [pef ' ' t.t.a]
    ::
    ++  furl                                            ::  print wall
      |=  wol=(list tape)
      ^+  +>
      =.  +>
        %-  curb
        %-  flop
        |-  ^-  (list blit)
        ?~  wol  ~
        [[%lin (tuba i.wol)] [%mor ~] $(wol t.wol)]
      ?~  q.r.yar  +>
      (edit(q.r.yar ~) u.q.r.yar)
    ::
    ++  gore                                            ::  move in history
      |=  hup=@ud
      ^+  +>
      =+  ^=  but  ^-  (list ,@c)
          =+  byt=(~(get by hym.u.q.r.yar) hup)
          ?^  byt  u.byt
          (tuba (rip 3 (snag hup q.hyt.u.q.r.yar)))
      =+  bul=(lent but)
      %-  edit
      %=  u.q.r.yar
        hiz  hup
        hym  %+  ~(put by hym.u.q.r.yar)
               hiz.u.q.r.yar
             but.u.q.r.yar
        bus  bul
        bul  (lent but)
        but  but
      ==
    :: 
    ++  leap                                            ::  terminal event
      |-  ^+  +
      ?+    -.fav  !!
          %bleb                                         ::  terminal input
        ?:  ?|  ?=(~ whu)
                ?=(~ q.r.yar)
            ==
          beep
        ?-    -.p.fav
            %aro                                        ::  arrow
          ?-    p.p.fav
              %d                                        ::  down
            ?:  =(0 hiz.u.q.r.yar)
              beep
            (gore (dec hiz.u.q.r.yar))
          ::
              %l                                        ::  left
            ?:  =(0 bus.u.q.r.yar)
              beep
            (edit u.q.r.yar(bus (dec bus.u.q.r.yar)))
          ::
              %r                                        ::  right
            ?:  =(bul.u.q.r.yar bus.u.q.r.yar)
              beep
            (edit u.q.r.yar(bus +(bus.u.q.r.yar)))
          ::
              %u
            =+  hup=+(hiz.u.q.r.yar)
            ?:  =(hup p.hyt.u.q.r.yar)
              beep
            (gore hup)
          ==
        ::
            %bac                                        ::  backspace
          ^+  +.$
          ?:  =(0 bus.u.q.r.yar)
            (curb `(list blit)`[[%bel ~] ~])
          %-  edit
          %=    u.q.r.yar
              bus  (dec bus.u.q.r.yar)
              bul  (dec bul.u.q.r.yar)
              but  
            %+  weld 
              (scag (dec bus.u.q.r.yar) but.u.q.r.yar)
            (slag bus.u.q.r.yar but.u.q.r.yar)
          ==
        ::
            %ctl  beep                                  ::  control
        ::
            %del  beep                                  ::  delete
        ::
            %met  beep                                  ::  meta
        ::
            %ret                                        ::  return
          =+  jab=(rap 3 (tufa but.u.q.r.yar))
          ?:  =(%% jab)
            %=    +.$
                q.r.yar  ~
                mos
              :*  [~ hen [%bbye ~]]
                  [~ hen [%blit [%mor ~] ~]]
                  mos
              ==
            ==
          %=    +.$
              q.r.yar  ~
              s.yar
            %+  ~(put by s.yar)
              [u.whu hux.u.q.r.yar]
            [p.hyt.u.q.r.yar [jab +.q.hyt.u.q.r.yar]]
          ::
              mos
            :*  [~ hen [%bbye ~]]
                [whu [[%bede ~] hen] [%line jab]]
                [~ hen [%blit [[%mor ~] ~]]]
                mos
            ==
          ==
        ::
            %txt                                        ::  text keys
          =+  let=(lent p.p.fav)
          %-  edit
          %=    u.q.r.yar
              bus  (add let bus.u.q.r.yar)
              bul  (add let bul.u.q.r.yar)
              but  
            ;:  weld
              (scag bus.u.q.r.yar but.u.q.r.yar)
              p.p.fav
              (slag bus.u.q.r.yar but.u.q.r.yar)
            ==
          ==
        ==
      ::
          %blew   +.$(p.r.yar p.p.fav)                  ::  window size
          %helo                                         ::  trigger prompt
        ?^  q.r.yar
          (edit(q.r.yar ~) u.q.r.yar)
        ?>  ?=(^ whu)
        %-  edit
        =|  bed=bead
        =+  pot="> "                                    ::  XX temporary
        =+  hux=//
        =+  ^=  hyt  ^-  hist
            =+  hyt=(~(get by s.yar) [u.whu hux])
            ?~(hyt *hist u.hyt)
        %=    bed
            buy  %lark
            hux  hux
            hiz  0
            hyt  [+(p.hyt) [%% q.hyt]]
            pot  pot
            pol  2
        ==
      ::
          %logo                                         ::  logout
        =.  mos  :_(mos [~ hen [%bbye ~]])
        ?~  q.yar  +.$
        %=  $
          fav    =+  mas=~(rend co ~ %p u.whu)
                 [%warn "bye, {mas}"]
          q.yar  t.q.yar
        ==
      ::
          %logp                                         ::  trusted login
        ?>  =(%gold (adit hen))
        %=  $
          fav    =+  mas=~(rend co ~ %p p.fav)
                 [%warn "hi, {mas}"]
          q.yar  [p.fav q.yar]
          mos    :_(mos [~ hen [%bbye ~]])
        ==
      ::
          %logn                                         ::  login by passcode
        %=  $
          fav   =+  mas=~(rend co ~ %p p.fav)
                [%warn "welcome, {mas}"]
          q.yar  [p.fav q.yar]                          ::  XX unvalidated!
          mos    :_(mos [~ hen [%bbye ~]])
        ==
      ::
          %note  ?.(p.yar +.$ (fume p.fav q.fav))       ::  debug message
          %text  $(fav [%talk %leaf p.fav])             ::  simple message
          %talk  (furl (~(win re p.fav) 0 p.r.yar))     ::  program output
          %warn  (fume '~' [%leaf p.fav])               ::  system message
      ==
    ::
    ++  yerk                                            ::  complete core
      ^-  [p=(list move) q=_..^$]
      ::  ~&  [%yerk-moves mos]
      [(flop mos) ..^$(wib (~(put by wib) hen yar))]
    --
  --
--
