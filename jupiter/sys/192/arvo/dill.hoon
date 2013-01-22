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
    |=  [who=(unit lord) pax=path hen=vein fav=card]
    ^-  [p=(list move) q=_..^$]
    =^  yar  +> 
      ^-  [yard _+>]
      =+  yur=(~(get by wib) hen)
      ?~  yur
        =+  yer=`yard`[& ?~(who ~ [u.who ~]) *blur *(map path hist)]
        [yer +>.$(wib (~(put by wib) hen yer))]
      [u.yur +>.$]
    =.  who  ?~(q.yar ~ [~ i.q.yar])
    ?>  ?=(^ who)                                       ::  no login prompt yet
    =<  =^  mos  yar  leap
        [mos ..^$(wib (~(put by wib) hen yar))]
    |%
    ++  back                                            ::  backspace
      ^-  [p=(list blit) q=bled]
      !!
    ::
    ++  haro                                            ::  horizontal arrow
      |=  ryt=?
      ^-  [p=(list blit) q=bled]
      !!
    ::
    ++  leap                                            ::  dispatch event
      |-  ^-  [p=(list move) q=yard]
      ?+  -.fav  [~ yar]
        %bleb  (lick p.fav)
        %logo  [~ yar(q ?>(?=(^ q.yar) t.q.yar))]
        %logp  [~ yar(q [p.fav q.yar])]
        %text  $(fav [%talk %leaf p.fav])
        %talk  (talk p.fav)
        %warn  (warn p.fav q.fav)
      ==
    ::
    ++  lick
      |=  beb=bleb
      ^-  [p=(list move) q=yard]
      ?~  q.r.yar
        [[`move`[~ hen ~[%blit [%bel ~]]] ~] yar]
      %-  push
      ^-  [p=(list blit) q=bled]
      ?-    -.beb
          %aro
        ?-  p.beb
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
    ++  push                                            ::  apply change
      |=  [byz=(list blit) wum=bled]
      ^-  [p=(list move) q=yard]
      ?~  q.r.yar
        !!
      !!
    ::
    ++  talk
      |=  tac=tank
      ^-  [p=(list move) q=yard]
      !!
    ::
    ++  varo                                            ::  vertical arrow
      |=  dow=?
      ^-  [p=(list blit) q=bled]
      !! 
    ::
    ++  warn
      |=  [veb=? tac=tank] 
      ^-  [p=(list move) q=yard]
      !!
    --
  --
--
