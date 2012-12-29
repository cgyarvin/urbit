!:
::          %dill, http server.  This file is in the public domain.
::
|%
++  lidl                                                ::  http server
  =+  :*  tuh=(map tube logo)                           ::  http sessions
          tyv=(map logo cred)                           ::  credentials
      ==
  |_  [now=@da eny=@]
  ++  epur                                              ::  url/header parser
    |%
    ++  apat  ;~(pfix fas (more fas smeg))              ::  2396 abs_path
    ++  auri
      ;~  pfix  ;~(plug scem col fas fas)
        ;~(plug thor apat yque)
      == 
    ++  bite                                            ::  cookies (ours)
      (most sem ;~(plug nuck:so ;~(pfix sem nuck:so))) 
    ++  dlab                                            ::  2396 domainlabel
      %+  sear
        |=  a=@ta
        ?.(=('-' (rsh 3 a (dec (met 3 a)))) [~ u=a] ~)
      %+  cook  cass
      ;~(plug aln (star alp))
    ::
    ++  fque  (cook crip (plus pold))                   ::  normal query field
    ++  pcar  ;~(pose pure pesc psub col pat)           ::  2396 path char
    ++  pesc  ;~(pfix cen mes)                          ::  2396 escaped
    ++  pold  (cold ' ' (just '+'))                     ::  old space code
    ++  pque  ;~(pose pcar fas wut)                     ::  3986 query char
    ++  pquo  ;~(pose pure pesc pold)                   ::  normal query char
    ++  pure  ;~(pose aln hep dot cab sig)              ::  2396 unreserved
    ++  psub  ;~  pose                                  ::  3986 sub-delims
                zap  buc  pam  soq  pel  per 
                tar  lus  com  sem  tis
              ==
    ++  scem                                            ::  2396 scheme
      %+  cook  cass
      ;~(plug alf (star ;~(pose aln lus hep dot)))
    ::
    ++  smeg  (cook crip (plus pcar))                   ::  2396 segment
    ++  thor                                            ::  2396 host/port
      %+  cook  |*(a=[* *] [+.a -.a])
      ;~  plug
        thos
        ;~(pose (stag ~ ;~(pfix col dim:ag)) (easy ~))
      ==
    ++  thos                                            ::  2396 host, no local
      ;~  plug
        ;~  pose
          %+  stag  %&
          %+  sear                                      ::  LL parser weak here
            |=  a=(list ,@t)
            =+  b=(flop a)
            ?>  ?=(^ b)
            =+  c=(end 3 1 i.b)
            ?.(&((gte c 'a') (lte c 'z')) ~ [~ u=b])
          (most dot dlab)
        ::
          %+  stag  %|
          =+  tod=(ape:ag ted:ab) 
          %+  bass  256
          ;~(plug tod (stun [3 3] ;~(pfix dot tod)))
        ==
      ==
    ++  yque                                            ::  query ending
      ;~  pose
        ;~(pfix wut yquy)
        (easy ~)
      ==
    ++  yquy                                            ::  query
      %+  cook
        |=  a=(list ,[p=@t q=@t])
        (~(gas by *(map ,@t ,@t)) a)
      ;~  pose                                          ::  proper query
        %+  more
          ;~(pose pam sem)
        ;~(plug fque ;~(pfix wut fque))
      ::
        %+  cook                                        ::  improper query
          |=(a=tape [[%% (crip a)] ~])
        (star pque)
      ==
    ++  zest                                            ::  2616 request-uri
      ;~  pose
        (stag %& auri)
        (stag %| ;~(plug apat yque))
      ==
    --
  ++  ergo                                              ::  eat headers
    |=  hed=(list ,[p=@t q=@t])
    =+  mah=*math
    |-  ^-  math
    ?~  hed  mah
    =+  cus=(cass (rip 3 p.i.hed))
    =+  zeb=(~(get by mah) cus)
    $(hed t.hed, mah (~(put by mah) cus ?~(zeb [q.i.hed ~] [q.i.hed u.zeb])))
  ::
  ++  gump
    |=  [sec=? req=httq]
    ^-  hate
    =+  ryp=`quri`(rash q.req zest:epur)
    =+  mah=(ergo r.req)
    =+  ^=  pul  ^-  purl
        ?-  -.ryp
          &  p.ryp
          |  =+  hot=(~(get by mah) %host)
             ?>  ?=([~ @ ~] hot)
             [(rash i.u.hot thor:epur) p.ryp q.ryp]
        ==
    [pul *cred *brow [p.req mah ~]]
  ::
  ++  hesh                                              ::  test htreq
    |=  [sec=? pol=tube req=httq]
    ^-  [p=(list move) q=_+>]
    =+  gup=(gump sec req)
    ~&  [%hesh-gump-gup gup]
    !!
  ::
  ++  leap
    |=  mov=move
    ^-  [p=(list move) q=_+>]
    ?+    -.r.mov  [~ +>]
        %this  (hesh & q.mov p.r.mov)
        %thin  (hesh | q.mov p.r.mov)
    ==
  --
--
