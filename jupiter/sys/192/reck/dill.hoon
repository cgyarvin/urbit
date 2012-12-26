!:
::          %dill, http server.  This file is in the public domain.
::
|%
++  lidl                                                ::  http server
  =+  :*  tuh=(map tube logo)                           ::  http sessions
          tyv=(map logo cred)                           ::  credentials
      ==
  |_  [now=@da eny=@]
  ++  gump                                              ::  cook htreq
    |=  [sec=? pol=tube req=httq]
    ^-  hate
    :^    `purl`!!
        `cred`[`logo`@ ~]
      `brow`[~2000.1.1 %unknown]
    ^-  moth
    :-  `meth`%get
    ^-  math
    :+  `(unit mime)`~
      `(list ,[p=@t q=@t])`~
    `(map ,@t ,@t)`~
  ::
  ++  hesh                                                  ::  cook htreq
    |=  [sec=? pol=tube req=httq]
    ^-  [p=(list move) q=_+>]
    ~&  [%hesh sec pol]
    ~&  [%hesh-req-med med.req]
    ~&  [%hesh-req-url url.req]
    ~&  [%hesh-req-hed hed.req]
    ~&  [%hesh-req-bod bod.req]
    !!
  ::
  ++  leap
    |=  mov=move
    ^-  [p=(list move) q=_+>]
    ?+    -.r.mov  [~ +>]
        %resp  !!
        %this  (hesh & q.mov p.r.mov)
        %thin  (hesh | q.mov p.r.mov)
    ==
  --
--
