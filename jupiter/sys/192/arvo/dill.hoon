!:
::          %dill, terminal handling.  This file is in the public domain.
::
|%                                                      
++  dill                                                ::  revision control
  =+  wib=*(map vein yard)                              ::  state by terminal
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  current invocation
  |%                                                    ::  poke/peek pattern
  ++  peek
    |=  pax=path
    ^-  (unit)
    !!
  ::
  ++  poke                                              ::  process move
    |=  [whu=(unit lord) pax=path hen=vein fav=card]
    ~&  [%dill-poke fav]
    ^-  [p=(list move) q=_..^$]
    =^  yar  +> 
      ^-  [yard _+>]
      =+  yur=(~(get by wib) hen)
      ?~  yur
        =+  ^=  yer  ^-  yard
            :*  &
                ?~(whu ~ [u.whu ~])
                *blur
                *(map path hist)
            ==
        [yer +>.$(wib (~(put by wib) hen yer))]
      [u.yur +>.$]
    =.  whu  ?~(q.yar ~ [~ i.q.yar])
    =|  mos=(list move) 
    =<  yerk:leap
    |%
    ++  back                                            ::  edit backspace
      ^+  +>
      !!
    ::
    ++  curb                                            ::  send blits
      |=  wab=(list blit)
      +>(mos [[~ hen [%blit wab]] mos])
    ::
    ++  edit                                            ::  apply edit
      |=  nud=bled
      !!  
    ::
    ++  furl                                            ::  stop editing
      ^+  .
      !!
    :: 
    ++  grit                                            ::  source privilege
      |-  ^-  ?(%gold %iron %lead)
      ?~  hen
        %lead
      ?~  t.hen
        ?:  ?=([%gold *] i.hen)  %gold
        ?:  ?=([%iron *] i.hen)  %iron
        %lead
      $(hen t.hen)
    ::
    ++  haro                                            ::  horizontal arrow
      |=  ryt=?
      ^+  +>
      !!
    ::
    ++  leap                                            ::  dispatch event
      |-  ^+  +
      ?+    -.fav  +
          %bleb
        ?~  q.yar
          (curb [[%bel ~] ~])
        ?-    -.p.fav
            %aro
          ?-  p.p.fav
            %d  (varo &)
            %l  (haro |)
            %r  (haro &)
            %u  (varo |)
          ==
        ::
            %bac  !!
        ::
            %ctl  !!
        ::
            %del  !!
        ::
            %ret  !!
        ::
            %txt  !!
        ::
            %win  !!
        ==
      ::
          %logo  +(yar yar(q ?~(q.yar !! t.q.yar)))
          %logp  +(yar yar(q ?>(=(%gold grit) [p.fav q.yar])))
          %logn  +(yar yar(q [p.fav q.yar]))            ::  XX fake
          %text  $(fav [%talk %leaf p.fav])
          %talk  (talk p.fav)
          %warn  (warn p.fav q.fav)
      ==
    ::
    ++  prim
      ^-  bled
      !!
    ::
    ++  talk                                            ::  show output
      |=  tac=tank
      ^+  +>
      !!
    ::
    ++  varo                                            ::  v-arrow edit
      |=  dow=?
      ^+  +>  
      !! 
    ::
    ++  warn                                            ::  show diagnostic
      |=  [veb=? tac=tank] 
      ^+  +>
      !!
    ::
    ++  yerk                                            ::  complete core
      ^-  [p=(list move) q=_..^$]
      [mos ..^$(wib (~(put by wib) hen yar))]
    --
  --
--
