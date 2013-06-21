!:
::  dill (4d), terminal handling
::
  |=  pit=vase
  ^-  vane                                              ::  kernel instrument
  =|  $:  dub=(map duct (list seat))                    ::  rights by duct
          wyg=(map seat yard)                           ::  interface by seat
      ==                                                ::
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  current invocation
  ^?                                                    ::  opaque core
  |%                                                    ::  poke/peek pattern
  ++  beat                                              ::  process move
    |=  [whu=(unit seat) tea=wire hen=duct fav=card]
    ^-  [p=(list move) q=vane]
    =+  gid=(~(get by dub) hen)
    ?~  gid                                             ::  truly new duct
      ?+    -.fav
        ~&([%dill-lost whu tea hen fav] [~ ..^$])
      ::
          %boot                                         ::  log in with creds
        [[[whu [[%a ~] [%d tea] hen] p.fav] ~] ..^$]
      ::
          %flog                                         ::  log to terminal
        :_  ..^$
        %-  turn
        :_  |=(a=duct [whu [/d a] p.fav])
        ^-  (list duct)
        =+  mel=(adit hen)
        =+  gum=`(list ,[p=duct q=(list seat)])`(~(tap by dub) ~)
        |-  ^-  (list duct) 
        ?~  gum  ~
        %-  weld
        :_  $(gum t.gum)
        ?.  ?~(whu =(%gold mel) (lien q.i.gum |=(a=seat =(a u.whu))))
          ~
        [p.i.gum ~]
      ::
          %init                                         ::  attach terminal
        :-  :~  [whu hen [%init p.fav]]
                [[~ p.fav] [/b hen] [%noop ~]]
            ==
        %=    ..^$
            dub
          (~(put by dub) hen [p.fav ~])
        ::
            wyg
          ?:  (~(has by wyg) p.fav)  
            wyg
          (~(put by wyg) p.fav [& [p.fav ~] *blur ~])
        ==
      ==
    ?~  u.gid
      ~&  [%dill-none hen]
      [~ ..^$]
    =>  .(gid `(list seat)`u.gid)
    =.  whu  [~ i.gid]
    =+  yar=`yard`(need (~(get by wyg) i.gid))
    =|  mos=(list move)
    =+  wip=|
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
          :-  %lin
          %+  weld  pot.bed
          ?-  buy.bed
            %none  but.bed
            %text  but.bed
            %pass  `(list ,@)`(runt [(lent but.bed) '*'] ~)
          ==
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
    ++  kill                                            ::  add to kill ring
      |=  txt=(list ,@c)
      ^+  +>
      =>  ?.  =(16 p.r.r.yar)  .
          .(p.r.r.yar 15, r.r.r.yar (scag 15 r.r.r.yar))
      %=  +>
        p.r.r.yar  +(p.r.r.yar)
        q.r.r.yar  0
        r.r.r.yar  [txt r.r.r.yar]
      ==
    :: 
    ++  leap                                            ::  terminal event
      |-  ^+  +
      ?+    -.fav
        +(mos :_(mos [whu hen fav]))
      ::
          %belt                                         ::  terminal input
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
            %ctl                                        ::  control
          ?+  p.p.fav
            beep
            %a  (edit u.q.r.yar(bus 0))
            %b  $(fav [%belt %aro %l])
            %d  ?:  ?&  =(0 bul.u.q.r.yar)
                        =(0 bus.u.q.r.yar)
                    ==
                  $(fav [%logo ~])
                $(fav [%belt %del ~])
            %e  (edit u.q.r.yar(bus bul.u.q.r.yar))
            %f  $(fav [%belt %aro %r])
            %k  ?:  =(bul.u.q.r.yar bus.u.q.r.yar)
                  beep
                =>  .(+.$ (kill (slag bus.u.q.r.yar but.u.q.r.yar)))
                %-  edit
                %=  u.q.r.yar
                  bul  bus.u.q.r.yar
                  but  (scag bus.u.q.r.yar but.u.q.r.yar)
                ==
            %l  +.$(mos :_(mos [~ hen %blit [[%clr ~] ~]])) 
            %n  $(fav [%belt %aro %d])
            %p  $(fav [%belt %aro %u])
            %u  ?:  =(0 bus.u.q.r.yar)
                  beep
                =>  .(+.$ (kill (scag bus.u.q.r.yar but.u.q.r.yar)))
                %-  edit
                %=  u.q.r.yar
                  bus  0
                  bul  (sub bul.u.q.r.yar bus.u.q.r.yar)
                  but  (slag bus.u.q.r.yar but.u.q.r.yar)
                ==
            %x  +.$(mos :_(mos [whu [/b /d hen] [%ling ~]]))
            %y  ?:  =(0 p.r.r.yar)
                  beep
                $(fav [%belt %txt (snag q.r.r.yar r.r.r.yar)])
          ==
        ::
            %del                                        ::  delete
          ?:  =(bul.u.q.r.yar bus.u.q.r.yar)
            beep
          %-  edit
          %=    u.q.r.yar
              bul  (dec bul.u.q.r.yar)
              but  
            %+  weld 
              (scag bus.u.q.r.yar but.u.q.r.yar)
            (slag +(bus.u.q.r.yar) but.u.q.r.yar)
          ==
        ::
            %met                                        ::  meta
          ?+    p.p.fav
              beep
              %y  
            ?:  =(0 p.r.r.yar)
              beep
            =+  dol=(snag q.r.r.yar r.r.r.yar)
            =+  leo=(lent dol)
            ?.  (gte bus.u.q.r.yar leo)
              beep
            =+  pey=(sub bus.u.q.r.yar leo)
            ?.  =(dol (swag [pey leo] but.u.q.r.yar))
              beep
            =.  q.r.r.yar  ?:(=(p.r.r.yar +(q.r.r.yar)) 0 +(q.r.r.yar))
            =+  ney=(snag q.r.r.yar r.r.r.yar)
            =+  lye=(lent ney)
            %-  edit
            %=  u.q.r.yar
              bus  (sub (add bus.u.q.r.yar lye) leo)
              bul  (sub (add bul.u.q.r.yar lye) leo)
              but  %+  weld
                     (scag pey but.u.q.r.yar)
                   %+  weld
                     `(list ,@c)`ney                    ::  XX weird fuse-loop
                   (slag bus.u.q.r.yar but.u.q.r.yar)
            ==
          ==
        ::
            %ret                                        ::  return
          =+  jab=(rap 3 (tufa but.u.q.r.yar))
          ?:  =(%% jab)
            %=    +.$
                q.r.yar  ~
                mos
              :*  [~ [/d hen] [%helo ~]]
                  [~ hen [%bbye ~]]
                  [~ hen [%blit [%mor ~] ~]]
                  mos
              ==
            ==
          %=    +.$
              q.r.yar  ~
              s.yar
            ?:  =(%pass buy.u.q.r.yar)
              s.yar 
            %+  ~(put by s.yar)
              [u.whu hux.u.q.r.yar]
            [p.hyt.u.q.r.yar [jab +.q.hyt.u.q.r.yar]]
          ::
              mos
            :*  [~ [/d hen] [%helo ~]]
                [~ hen [%bbye ~]]
                [whu [/b /d hen] [%line jab]]
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
          %boot
        %=    +.$
            mos
          :_(mos [whu [[%a ~] [%d tea] hen] p.fav])
        ==
      ::
          %crud                                         ::  error trace
        |-  ^+  +.^$
        ?~  p.fav  +.^$
       (fume:$(p.fav t.p.fav) '!' i.p.fav)
      ::
          %hail
        ?>  ?=(^ whu)
        %=    +.$ 
            mos
          :~  [whu [/d hen] [%warn "welcome, {~(rend co [~ %p u.whu])}!"]]
              [whu [/d hen] [%helo ~]]
          ==
        ==
      ::
          %helo                                         ::  trigger prompt
        ?:  &(?=(^ q.r.yar) !=(~ but.u.q.r.yar)) +.$
        ?>  ?=(^ whu)
        =+  pom=(sky [%b (scot p/u.whu) %p (scot da/now) ~])
        =+  poy=?~(pom `prod`[%text "# "] (prod u.pom))
        %-  edit
        =|  bed=bead
        =+  hux=/
        =+  ^=  hyt  ^-  hist
            =+  hyt=(~(get by s.yar) [u.whu hux])
            ?~(hyt *hist u.hyt)
        %=    bed
            buy  p.poy
            hux  hux
            hiz  0
            hyt  [+(p.hyt) [%% q.hyt]]
            pot  q.poy
            pol  (lent q.poy)
        ==
      ::
          %init                                         ::  attach to seat
        %=    +.$
            gid  [p.fav gid]
            mos    :*  [whu hen [%init p.fav]]
                       [[~ p.fav] [/b hen] [%noop ~]]
                       mos
                   ==
        ==
      ::
          %logo                                         ::  logout
        %=    +.$
            gid  (skip gid |=(a=seat =(u.whu a)))
            mos  
          :*  [whu hen [%bbye ~]]
              [whu hen [%warn "bye, {(scow %p u.whu)}"]]
              mos
          ==
        ==
      ::
          %note  ?.(p.yar +.$ (fume p.fav q.fav))       ::  debug message
          %save                                         ::  write a file
        %=  +.$
          mos  :_(mos [whu hen `card`[%blit [%sav p.fav q.fav] ~]])
        ==
      ::
          %tell  (furl (turn p.fav |=(a=@t (trip a))))  ::  wall of text
          %text  $(fav [%talk %leaf p.fav])             ::  simple message
          %talk  (furl (~(win re p.fav) 0 p.r.yar))     ::  program output
          %warn  (fume '~' [%leaf p.fav])               ::  system message
          %wipe  +.$(wip &)                             ::  delete old
      ==
    ::
    ++  yerk                                            ::  complete core
      ^-  [p=(list move) q=_..^$]
      :-  (flop mos)
      %_  ..^$
        dub  ?.(wip (~(put by dub) hen gid) (~(del by dub) hen))
        wyg  (~(put by wyg) u.whu yar)
      ==
    --
  ::
  ++  come  |=(old=vase (load old))
  ++  doze
    |=  [now=@da hen=duct]
    ^-  (unit ,@da)
    ~
  ::
  ++  flee  stay
  ++  load
    |=  new=vase
    ^-  vane
    ?.  (~(nest ut -:!>([dub wyg])) & p.new)
      ~|(%load-nest-dill !!)
    %_  ..^$
      dub  ((map duct (list seat)) -.q.new)
      wyg  ((map seat yard) +.q.new)
    ==
  ::
  ++  raze  
    ^-  vane
    ..$(dub ~, wyg ~)
  ::
  ++  scry
    |=  [our=seat ren=@tas his=seat syd=disc lot=coin tyl=path]
    ^-  (unit)
    ~
  ::
  ++  stay  `vase`!>([dub wyg])
  --
