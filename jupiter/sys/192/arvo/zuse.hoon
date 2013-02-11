!:
::          %zuse, main loop.   This file is in the public domain.
::
=<  =+  ^=  duc                                         ::  nock entrance
        |=  cud=*  ^-  *
        ?:  =(0 cud)
          ..peek
        ?>(?=(@ cud) (make cud))
    ^-  *
    [8 [1 duc] [9 2 [[0 4] [[0 3] [0 11]]]]]
=<  |%
    ++  peek                                            ::  external inspect
      |=  *
      ^-  (unit)
      =>  .(+< ((hard ,[our=@p now=@da hap=path]) +<))
      ?~  hap  ~
      ((~(beck is now) [~ our]) hap)
    ::
    ++  poke                                            ::  external apply
      |=  *
      ^-  [p=(list ovum) q=_+>]
      =>  .(+< ((hard ,[now=@da ovo=ovum]) +<))
      =^  zef  fan
        (~(hurl is now) ovo)
      [zef +>.$]
    ::
    ++  wish                                            ::  external compute
      |=  *
      ^-  *
      =>  .(+< ((hard ,[txt=@]) +<))
      =+  gen=(ream txt)
      q:(slap `vase`!>(+>) (ream txt))
    --
=|  eny=@
=+  ^=  fan  ^-  (list ,[p=@tas q=vane])
    :~  a/ames
        b/bede
        c/cary
        d/dill
        e/eyre
    ==
|%
++  is                                                  ::  operate in time
  |_  now=@da 
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
    =>  .(owr [~ u=his])                                ::  XX no!
    =+  dis=(end 3 1 q.p.u.hyr)
    =+  rem=(rsh 3 1 q.p.u.hyr)
    |-  ^-  (unit)
    ?~  fan  ~
    ?.  =(dis p.i.fan)  $(fan t.fan)
    %-  scry:(q.i.fan now (shax now) ..^$)
    [u.owr rem his u.ved tyl]
  ::
  ++  goad                                              ::  route event
    |=  fav=card                                        ::  accept, event
    ^-  (unit ,@tas)                                    ::  produce, route
    ?+  -.fav                                           ::  on event kind
      ~&([%goad-fav -.fav] !!)                          ::  XX temporary
      %bbye  ~                                          ::  reset prompt
      %bind  [~ %e]                                     ::  publish http
      %belt  [~ %d]                                     ::  terminal input
      %blew  [~ %d]                                     ::  terminal config
      %blit  ~                                          ::  terminal output
      %boot  [~ %d]                                     ::  terminal boot
      %crap  ~                                          ::  error trace
      %edit  [~ %c]                                     ::  edit filesystem
      %exit  ~                                          ::  abstract exit
      %fail  ~                                          ::  report failure
      %helo  [~ %d]                                     ::  trigger prompt
      %init  ~                                          ::  install master
      %kill  [~ %b]                                     ::  kill a process
      %line  [~ %b]                                     ::  command line
      %logn  [~ %d]                                     ::  login
      %make  [~ %d]                                     ::  wild invite
      %note  [~ %d]                                     ::  debug message
      %nuke  [~ %b]                                     ::  kill all processes
      %talk  [~ %d]                                     ::  show on console
      %text  [~ %d]                                     ::  talk leaf
      %that  [~ %e]                                     ::  htresponse, cooked
      %thee  [~ %e]                                     ::  htrequest, cooked
      %thin  [~ %e]                                     ::  htrequest, insecure
      %this  [~ %e]                                     ::  htrequest, secure
      %thou  ~                                          ::  htresponse, raw
      %warn  [~ %d]                                     ::  system message
    ==
  ::
  ++  hurl                                              ::  start loop
    |=  ovo=ovum
    ^-  [p=(list ovum) q=(list ,[p=@tas q=vane])]
    %-  kick
    [[~ [[(need (goad q.ovo)) ~] p.ovo ~] q.ovo] ~]
  ::
  ++  kick                                              ::  complete loop
    |=  mor=(list move)
    =|  ova=(list ovum)
    |-  ^-  [p=(list ovum) q=(list ,[p=@tas q=vane])]
    ?~  mor
      [(flop ova) fan]
    ?>  ?=(^ q.i.mor)
    ?~  t.q.i.mor
      =+  gyd=(goad r.i.mor)
      ?>  ?=(^ i.q.i.mor)
      %=  $
        ova  [[i.q.i.mor r.i.mor] ova]
        mor  ?~  gyd
               t.mor
             :_(t.mor [p.i.mor [[u.gyd ~] [i.i.q.i.mor ~] ~] r.i.mor])
      == 
    ?>  ?=(^ i.q.i.mor)
    =-  $(mor (weld p.nyx t.mor), fan q.nyx)
    ^=  nyx
    |-  ^-  [p=(list move) q=_fan]
    ?~  fan  [~ ~]
    ?.  =(i.i.q.i.mor p.i.fan)
      =+  tuh=$(fan t.fan)
      [p.tuh [i.fan q.tuh]]
    =+  ^=  yub
        %-  beat:(q.i.fan now (shax now) (beck p.i.mor))
        [p.i.mor t.i.q.i.mor t.q.i.mor r.i.mor]
    [p.yub [[p.i.fan q.yub] t.fan]]
  --
--
