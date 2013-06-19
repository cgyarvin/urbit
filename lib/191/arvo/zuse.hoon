!:
::  zuse (3), standard library (tang)
::
|%
  ::::::::::::::::::::::::::::::::::::::::::::::::::::::  ::
::::              chapter 3b, Arvo libraries            ::::
::  ::::::::::::::::::::::::::::::::::::::::::::::::::::::
::                section 3bA, lite number theory       ::
::
++  egcd                                                ::  schneier's egcd
  |=  [a=@ b=@]
  =+  si
  =+  [c=(sun a) d=(sun b)]
  =+  [u=[c=(sun 1) d=--0] v=[c=--0 d=(sun 1)]]
  |-  ^-  [d=@ u=@ v=@]
  ?:  =(--0 c) 
    [(abs d) d.u d.v]
  ::  ?>  ?&  =(c (sum (pro (sun a) c.u) (pro (sun b) c.v)))
  ::          =(d (sum (pro (sun a) d.u) (pro (sun b) d.v)))
  ::      == 
  =+  q=(fra d c) 
  %=  $
    c  (dif d (pro q c))
    d  c
    u  [(dif d.u (pro q c.u)) c.u]
    v  [(dif d.v (pro q c.v)) c.v]
  ==
::
++  pram                                                ::  rabin-miller
  |=  a=@  ^-  ?
  ?:  ?|  =(0 (end 0 1 a))
          =(1 a)
          =+  b=1
          |-  ^-  ?
          ?:  =(512 b)
            |
          ?|(=+(c=+((mul 2 b)) &(!=(a c) =(a (mul c (div a c))))) $(b +(b)))
      ==
    |
  =+  ^=  b
      =+  [s=(dec a) t=0]
      |-  ^-  [s=@ t=@]
      ?:  =(0 (end 0 1 s))
        $(s (rsh 0 1 s), t +(t))
      [s t]
  ?>  =((mul s.b (bex t.b)) (dec a))
  =+  c=0
  |-  ^-  ?
  ?:  =(c 64)
    &
  =+  d=(~(raw og (add c a)) (met 0 a))
  =+  e=(~(exp fo a) s.b d)
  ?&  ?|  =(1 e)
          =+  f=0
          |-  ^-  ?
          ?:  =(e (dec a))
            &
          ?:  =(f (dec t.b))
            |
          $(e (~(pro fo a) e e), f +(f))
      ==
      $(c +(c))
  ==
::
++  ramp                                                ::  make r-m prime
  |=  [a=@ b=(list ,@) c=@]  ^-  @ux                    ::  [bits snags seed]
  =>  .(c (shas %ramp c))
  =+  d=@
  |-
  ?:  =((mul 100 a) d)
    ~|(%ar-ramp !!)
  =+  e=(~(raw og c) a)
  ?:  &(|-(?~(b & &(!=(1 (mod e i.b)) $(b +.b)))) (pram e))
    e
  $(c +(c), d (shax d))
::
++  fo                                                  ::  modulo prime
  |_  a=@
  ++  dif
    |=  [b=@ c=@]
    (sit (sub (add a b) c))
  ::
  ++  exp
    |=  [b=@ c=@]
    ?:  =(0 b)
      1
    =+  d=$(b (rsh 0 1 b))
    =+  e=(pro d d)
    ?:(=(0 (end 0 1 b)) e (pro c e))
  ::
  ++  fra
    |=  [b=@ c=@]
    (pro b (inv c))
  ::
  ++  inv
    |=  b=@
    =+  c=(dul:si u:(egcd b a) a)
    c
  ::
  ++  pro
    |=  [b=@ c=@]
    (sit (mul b c))
  ::
  ++  sit
    |=  b=@
    (mod b a)
  ::
  ++  sum
    |=  [b=@ c=@]
    (sit (add b c))
  --
::
++  fu                                                  ::  modulo (mul p q)
  |=  a=[p=@ q=@]
  =+  b=?:(=([0 0] a) 0 (~(inv fo p.a) (~(sit fo p.a) q.a)))
  |%
  ++  dif
    |=  [c=[@ @] d=[@ @]]
    [(~(dif fo p.a) -.c -.d) (~(dif fo q.a) +.c +.d)]
  ::
  ++  exp
    |=  [c=@ d=[@ @]]
    :-  (~(exp fo p.a) (mod c (dec p.a)) -.d) 
    (~(exp fo q.a) (mod c (dec q.a)) +.d)
  ::
  ++  out                                               ::  garner's formula
    |=  c=[@ @]
    %+  add
      +.c
    (mul q.a (~(pro fo p.a) b (~(dif fo p.a) -.c (~(sit fo p.a) +.c))))
  ::
  ++  pro
    |=  [c=[@ @] d=[@ @]]
    [(~(pro fo p.a) -.c -.d) (~(pro fo q.a) +.c +.d)]
  ::
  ++  sum
    |=  [c=[@ @] d=[@ @]]
    [(~(sum fo p.a) -.c -.d) (~(sum fo q.a) +.c +.d)]
  ::
  ++  sit
    |=  c=@
    [(mod c p.a) (mod c q.a)]
  --
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::                section 3bB, cryptosuites             ::
::
++  crya                                                ::  cryptosuite A (RSA)
  ^-  acro
  =+  [mos=@ pon=*(unit ,[p=@ q=@ r=[p=@ q=@] s=_*fu])]
  =>  |%
      ++  dap                                           ::  OEAP decode
        |=  [wid=@ xar=@ dog=@]  ^-  [p=@ q=@]
        =+  pav=(sub wid xar)
        =+  qoy=(cut 0 [xar pav] dog)
        =+  dez=(mix (end 0 xar dog) (shaw %pad-b xar qoy))
        [dez (mix qoy (shaw %pad-a pav dez))]
      ::
      ++  pad                                           ::  OEAP encode
        |=  [wid=@ rax=[p=@ q=@] meg=@]  ^-  @
        =+  pav=(sub wid p.rax)
        ?>  (gte pav (met 0 meg))
        ^-  @
        =+  qoy=(mix meg (shaw %pad-a pav q.rax))
        =+  dez=(mix q.rax (shaw %pad-b p.rax qoy))
        (can 0 [p.rax dez] [pav qoy] ~)
      ::
      ++  pull  |=(a=@ (~(exp fo mos) 3 a))
      ++  push  |=(a=@ (~(exp fo mos) 5 a))
      ++  pump
        |=  a=@  ^-  @
        ?~  pon  !!
        (out.s.u.pon (exp.s.u.pon p.r.u.pon (sit.s.u.pon a)))
      ::
      ++  punt
        |=  a=@  ^-  @
        ?~  pon  !!
        (out.s.u.pon (exp.s.u.pon q.r.u.pon (sit.s.u.pon a)))
      --
  |%
  ++  de  
    |+  [key=@ cep=@]  ^-  (unit ,@)
    =+  toh=(met 8 cep)
    ?:  (lth toh 2)
      ~
    =+  adj=(dec toh)
    =+  [hax=(end 8 1 cep) bod=(rsh 8 1 cep)]
    =+  msg=(mix (~(raw og (mix hax key)) (mul 256 adj)) bod)
    ?.  =(hax (shax (mix key (shax (mix adj msg)))))
      ~
    [~ msg]
  ::
  ++  dy  |+([a=@ b=@] (need (de a b)))
  ++  en
    |+  [key=@ msg=@]  ^-  @ux
    =+  len=(met 8 msg)
    =+  adj=?:(=(0 len) 1 len)
    =+  hax=(shax (mix key (shax (mix adj msg))))
    (rap 8 hax (mix msg (~(raw og (mix hax key)) (mul 256 adj))) ~)
  ::
  ++  es  |+(a=@ (shas %anex a))
  ++  ex  ^?
    |%  ++  fig  ^-  @uvH  (shaf %afig mos)
        ++  pac  ^-  @uvG  (end 6 1 (shaf %acod sec))
        ++  pub  ^-  pass  (cat 3 'a' mos)
        ++  sec  ^-  ring  ?~(pon !! (cat 3 'A' (jam p.u.pon q.u.pon)))
    --
  ::
  ++  mx  (dec (met 0 mos))
  ++  nu  
    =>  |%
        ++  elcm
          |=  [a=@ b=@]
          (div (mul a b) d:(egcd a b))
        ::
        ++  eldm
          |=  [a=@ b=@ c=@]
          (~(inv fo (elcm (dec b) (dec c))) a)
        ::
        ++  ersa
          |=  [a=@ b=@]
          [a b [(eldm 3 a b) (eldm 5 a b)] (fu a b)]
        --
    ^?
    |%  ++  com
          |=  a=@
          ^+  ^?(..nu)
          ..nu(mos a, pon ~)
        ::
        ++  pit
          |=  [a=@ b=@]
          =+  c=(rsh 0 1 a)
          =+  [d=(ramp c [3 5 ~] b) e=(ramp c [3 5 ~] +(b))]
          ^+  ^?(..nu)
          ..nu(mos (mul d e), pon [~ (ersa d e)])
        ::
        ++  nol
          |=  a=@ 
          ^+  ^?(..nu)
          =+  b=((hard ,[p=@ q=@]) (cue a))
          ..nu(mos (mul p.b q.b), pon [~ (ersa p.b q.b)])
    --
  ++  pu  ^?
    |%  ++  seal
          |=  [a=@ b=@]
          ^-  @
          =+  det=(lte (add 256 (met 0 b)) mx)
          =+  lip=?:(det b 0)
          =-  (add ?:(p.mav 0 1) (lsh 0 1 q.mav))
          ^=  mav  ^-  [p=? q=@]
          :-  det
          =+  dog=(pad mx [256 a] lip)
          =+  hog=(push dog)
          =+  ben=(en a b)
          ?:(det hog (jam hog ben))
        ::
        ++  sure
          |=  [a=@ b=@]
          ^-  (unit ,@)
          =+  [det==(0 (end 0 1 b)) bod=(rsh 0 1 b)]
          =+  gox=?:(det [p=bod q=0] ((hard ,[p=@ q=@]) (cue bod)))
          =+  dog=(pull p.gox)
          =+  pig=(dap mx 128 dog)
          =+  log=?:(det q.pig q.gox)
          ?.(=(p.pig (shaf (mix %agis a) log)) ~ [~ log])
    --
  ++  se  ^?
    |%  ++  sign
          |=  [a=@ b=@]  ^-  @
          =-  (add ?:(p.mav 0 1) (lsh 0 1 q.mav))
          ^=  mav  ^-  [p=? q=@]
          =+  det=(lte (add 128 (met 0 b)) mx)
          :-  det
          =+  hec=(shaf (mix %agis a) b)
          =+  dog=(pad mx [128 hec] ?:(det b 0))
          =+  hog=(pump dog)
          ?:(det hog (jam hog b))
        ::
        ++  tear
          |=  a=@
          ^-  (unit ,[p=@ q=@])
          =+  [det==(0 (end 0 1 a)) bod=(rsh 0 1 a)]
          =+  gox=?:(det [p=bod q=0] ((hard ,[p=@ q=@]) (cue bod)))
          =+  dog=(punt p.gox)
          =+  pig=(dap mx 256 dog)
          ?:  det 
            [~ p.pig q.pig]
          =+  cow=(de p.pig q.gox)
          ?~(cow ~ [~ p.pig u.cow])
    --
  --
++  brew                                                ::  create keypair
  |=  [a=@ b=@]                                         ::  width seed
  ^-  acro
  (pit:nu:crya a b)
::
++  hail                                                ::  activate public key
  |=  a=pass
  ^-  acro
  =+  [mag=(end 3 1 a) bod=(rsh 3 1 a)]
  ?>  =('a' mag)
  (com:nu:crya bod)
::
++  wear                                                ::  activate secret key
  |=  a=ring
  ^-  acro
  =+  [mag=(end 3 1 a) bod=(rsh 3 1 a)]
  ?>  =('A' mag)
  (nol:nu:crya bod)
::
++  trsa                                                ::  test rsa
  |=  msg=@tas
  ^-  @
  =+  rsa=(brew 1.024 (shax msg))
  =+  key=(shax (shax (shax msg)))
  =+  sax=(seal:pu:rsa key msg)
  =+  tin=(tear:se:rsa sax)
  ?.  &(?=(^ tin) =(key p.u.tin) =(msg q.u.tin))
    ~|(%test-fail-seal !!)
  =+  tef=(sign:se:rsa [0 msg])
  =+  lov=(sure:pu:rsa [0 tef])
  ?.  &(?=(^ lov) =(msg u.lov))
    ~|(%test-fail-sign !!)
  msg
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::                section 3bC, JSON and XML             ::
::
++  moon                                                ::  mime type to text
  |=  myn=mime
  %+  rap
    3
  |-  ^-  tape
  ?~  myn  ~
  ?~  t.myn  (trip i.myn)
  (weld (trip i.myn) ['/' $(myn t.myn)])
::
++  pojo                                                ::  print json
  |=  val=jval
  ^-  tape
  ?~  val  "null"
  ?-    -.val
      %a
    ;:  weld
      "["
      =|  rez=tape
      |-  ^+  rez
      ?~  p.val  rez
      $(p.val t.p.val, rez :(weld rez ^$(val i.p.val) ?~(t.p.val ~ ",")))
      "]"
    ==
 ::
      %b  ?:(p.val "true" "false")
      %n  (trip p.val)
      %s  :(weld "\"" (trip p.val) "\"")
      %o
    ;:  weld
      "\{"
      =+  viz=(~(tap by p.val) ~)
      =|  rez=tape
      |-  ^+  rez
      ?~  viz  rez
      %=    $
          viz  t.viz
          rez
        :(weld rez "\"" (trip p.i.viz) "\":" ^$(val q.i.viz) ?~(t.viz ~ ","))
      ==
      "}"
    ==
  ==
::
++  tact                                                ::  tape to octstream
  |=  tep=tape  ^-  octs
  =+  buf=(rap 3 tep)
  [(met 3 buf) buf]
::
++  txml                                                ::  string to xml
  |=  tep=tape  ^-  manx
  [[%% [%% tep] ~] ~]
::
++  xmla                                                ::  attributes to tape
  |=  [tat=mart rez=tape]
  ^-  tape
  ?~  tat  rez
  =+  ryq=$(tat t.tat)
  :(weld (xmln n.i.tat) "=\"" (xmle v.i.tat '"' ?~(t.tat ryq [' ' ryq])))
::
++  xmle                                                ::  escape for xml
  |=  [tex=tape rez=tape]
  =+  xet=`tape`(flop tex)
  |-  ^-  tape
  ?~  xet  rez
  %=    $
    xet  t.xet
    rez  ?-  i.xet
           34  ['&' 'q' 'u' 'o' 't' ';' rez]
           38  ['&' 'a' 'm' 'p' ';' rez]
           39  ['&' 'a' 'p' 'o' 's' ';' rez]
           60  ['&' 'l' 't' ';' rez]
           62  ['&' 'g' 't' ';' rez]
           *   [i.xet rez]
         ==
  ==
::
++  xmln                                                ::  name to tape
  |=  man=mane  ^-  tape
  ?@  man  (trip man) 
  (weld (trip -.man) [':' (trip +.man)])
::
++  xmll                                                ::  nodes to tape
  |=  [lix=(list manx) rez=tape]
  =+  xil=(flop lix)
  |-  ^-  tape
  ?~  xil  rez
  $(xil t.xil, rez (xmlt i.xil rez))
::
++  xmlt                                                ::  node to tape
  |=  [mex=manx rez=tape]
  ^-  tape
  ?:  ?=([%% [[%% *] ~]] t.mex)
    (xmle v.i.a.t.mex rez)
  =+  man=`mane`?@(t.mex t.mex -.t.mex)
  =+  tam=(xmln man)
  =+  end=:(weld "</" tam ">" rez)
  =+  bod=['>' (xmll c.mex :(weld "</" tam ">" rez))]
  =+  att=`mart`?@(t.mex ~ a.t.mex)
  :-  '<'
  %+  weld  tam
  ?~(att bod [' ' (xmla att bod)])
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::                section 3bC, JSON and XML             ::
::
++  deft                                                ::  import url path
  |=  rax=(list ,@t)
  |-  ^-  pork
  ?~  rax
    [~ ~]
  ?~  t.rax
    =+  den=(trip i.rax)
    =+  ^=  vex
      %-  %-  full
          ;~(plug sym ;~(pose (stag ~ ;~(pfix dot sym)) (easy ~)))
      [[1 1] (trip i.rax)]
    ?~  q.vex
      [~ [~(rent co %% %t i.rax) ~]]
    [+.p.u.q.vex [-.p.u.q.vex ~]]
  =+  pok=$(rax t.rax)
  :-  p.pok
  :_  q.pok
  ?:(((sane %tas) i.rax) i.rax ~(rent co %% %t i.rax))
::
++  epur                                                ::  url/header parser
  |%
  ++  apat  (cook deft ;~(pfix fas (more fas smeg)))    ::  2396 abs_path
  ++  auri
    ;~  plug
      ;~  plug
        %+  sear
          |=  a=@t 
          ^-  (unit ,?)
          ?+(a ~ %http [~ %|], %https [~ %&])
        ;~(sfix scem ;~(plug col fas fas))
        thor
      ==
      ;~(plug apat yque)
    == 
  ++  bite                                              ::  cookies (ours)
    (most sem ;~(plug nuck:so ;~(pfix sem nuck:so))) 
  ++  dlab                                              ::  2396 domainlabel
    %+  sear
      |=  a=@ta
      ?.(=('-' (rsh 3 a (dec (met 3 a)))) [~ u=a] ~)
    %+  cook  cass
    ;~(plug aln (star alp))
  ::
  ++  fque  (cook crip (plus pquo))                     ::  normal query field
  ++  pcar  ;~(pose pure pesc psub col pat)             ::  2396 path char
  ++  pesc  ;~(pfix cen mes)                            ::  2396 escaped
  ++  pold  (cold ' ' (just '+'))                       ::  old space code
  ++  pque  ;~(pose pcar fas wut)                       ::  3986 query char
  ++  pquo  ;~(pose pure pesc pold)                     ::  normal query char
  ++  pure  ;~(pose aln hep dot cab sig)                ::  2396 unreserved
  ++  psub  ;~  pose                                    ::  3986 sub-delims
              zap  buc  pam  soq  pel  per 
              tar  lus  com  sem  tis
            ==
  ++  scem                                              ::  2396 scheme
    %+  cook  cass
    ;~(plug alf (star ;~(pose aln lus hep dot)))
  ::
  ++  smeg  (cook crip (plus pcar))                     ::  2396 segment
  ++  thor                                              ::  2396 host/port
    %+  cook  |*(a=[* *] [+.a -.a])
    ;~  plug
      thos
      ;~(pose (stag ~ ;~(pfix col dim:ag)) (easy ~))
    ==
  ++  thos                                              ::  2396 host, no local
    ;~  plug
      ;~  pose
        %+  stag  %&
        %+  sear                                        ::  LL parser weak here
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
  ++  yque                                              ::  query ending
    ;~  pose
      ;~(pfix wut yquy)
      (easy ~)
    ==
  ++  yquy                                              ::  query
    %+  cook
      |=  a=(list ,[p=@t q=@t])
      (~(gas by *(map ,@t ,@t)) a)
    ;~  pose                                            ::  proper query
      %+  more
        ;~(pose pam sem)
      ;~(plug fque ;~(pfix tis fque))
    ::
      %+  cook                                          ::  funky query
        |=(a=tape [[%% (crip a)] ~])
      (star pque)
    ==
  ++  zest                                              ::  2616 request-uri
    ;~  pose
      (stag %& (cook |=(a=purl a) auri))
      (stag %| ;~(plug apat yque))
    ==
  --
++  ecco                                                ::  eat headers
  |=  hed=(list ,[p=@t q=@t])
  =+  mah=*math
  |-  ^-  math
  ?~  hed  mah
  =+  cus=(cass (rip 3 p.i.hed))
  =+  zeb=(~(get by mah) cus)
  $(hed t.hed, mah (~(put by mah) cus ?~(zeb [q.i.hed ~] [q.i.hed u.zeb])))
::
++  hone                                                ::  host match
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
++  thin                                                ::  parse headers
  |=  [sec=? req=httq]
  ^-  hate
  ::  ~&  [%thin-quri (trip q.req)]
  =+  ryp=`quri`(rash q.req zest:epur)
  =+  mah=(ecco r.req)
  =+  ^=  pul  ^-  purl
      ?-  -.ryp
        &  ?>(=(sec p.p.p.ryp) p.ryp)
        |  =+  hot=(~(get by mah) %host)
           ?>  ?=([~ @ ~] hot)
           [[sec (rash i.u.hot thor:epur)] p.ryp q.ryp]
      ==
  [pul *cred [p.req mah s.req]]
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::                section 3bD, tree sync                ::
::
++  cyst
  |=  [bus=arch arc=arch]
  ^-  ukay
  uke:(dist:ka:(ci arc) bus)
::
++  ci
  |=  arc=arch
  =|  uke=ukay
  |%
  ++  ka
    =|  ram=hapt
    |%
    ++  dare  ..ka                                      ::  retract
    ++  dark  arc
    ++  darn  `[p=ukay q=arch]`[(flop uke) arc]
    ++  dash                                            ::  ascend
      |=  [lol=@ta rac=arch]
      ^+  +>
      ?>  &(?=(^ ram) =(lol i.ram))
      %=    +>
          ram  t.ram
          arc
        :-  %|
        ?>  ?=(| -.rac)
        ?:  =(arc [| ~])
          ?.  (~(has by p.rac) lol)  p.rac
          (~(del by p.rac) lol)
        (~(put by p.rac) lol arc)
      ==
    ::
    ++  deaf                                            ::  add ukaz
      |=  zuk=ukan
      ^+  +>
      +>(uke [[(flop ram) zuk] uke])
    ::
    ++  dent                                            ::  descend
      |=  lol=@ta
      ^+  +>
      =+  you=?:(?=(& -.arc) ~ (~(get by p.arc) lol))
      +>.$(ram [lol ram], arc ?~(you [%| ~] u.you))
    ::
    ++  deny                                            ::  descend recursively
      |=  way=path
      ^+  +>
      ?~(way +> $(way t.way, +> (dent i.way)))
    ::
    ++  dest                                            ::  write over
      |=  val=*
      ^+  +>
      ?-   -.arc
        |  (deaf:dirk %ins (sham val) `@uvI`0 val)
        &  (deaf %ins (sham val) p.arc val)
      ==
    ::
    ++  dist                                            ::  modify to
      |=  bus=arch
      ^+  +>
      ?-    -.bus
          &  ?:(&(?=(& -.arc) =(p.bus p.arc)) +> (dest q.bus))
          |
        =.  +>  ?.(?=(& -.arc) +> %*(. dirk arc [%| ~]))
        ?>  ?=(| -.arc)
        =+  [yeg=(~(tap by p.arc) ~) gey=(~(tap by p.bus) ~)]
        =>  .(arc `arch`arc)
        =.  +>.$
          |-  ^+  +>.^$
          ?~  yeg  +>.^$
          ?:  (~(has by p.bus) p.i.yeg)  $(yeg t.yeg)
          $(yeg t.yeg, uke uke:dirk(arc q.i.yeg, ram [p.i.yeg ram]))
        =.  +>.$
          |-  ^+  +>.^$
          ?~  gey  +>.^$
          $(gey t.gey, uke uke:^$(bus q.i.gey, +> (dent p.i.gey)))
        +>.$
      ==
    ::
    ++  dirk                                            ::  rm -r
      |-  ^+  +
      ?-    -.arc
          &  (deaf %del p.arc)
          |
        =+  dyr=(~(tap by p.arc) ~)
        =>  .(arc `arch`arc)
        |-  ^+  +.^$
        ?~  dyr  +.^$
        =.  +.^$  dirk:(dent p.i.dyr)
        $(dyr t.dyr)
      ==
    ::
    ++  dorf                                            ::  write under
      |=  [way=path bus=arch]
      ^+  +>
      ?~  way  (dist bus)
      =.  +>  ?.(?=(& -.arc) +> %*(. dirk arc [%| ~]))
      $(way t.way, +> (dent i.way))
    ::
    ++  drum                                            ::  apply and reverse
      |=  kuz=ukaz
      ^+  +>
      ?~  p.kuz 
        ?-    -.q.kuz
            %del
          ?>  ?=(& -.arc)
          =>  .(+>.$ (deaf %ins p.arc `@uvI`0 q.arc))
          +>.$(arc [%| ~])
        ::
            %ins
          =.  +>
            ?-    -.arc
                |
              ?>  &(=([| ~] arc) =(0 q.q.kuz))
              (deaf %del p.q.kuz)
            ::
                &
              ?>  =(p.arc q.q.kuz)
              (deaf %ins p.arc p.q.kuz q.arc)
            ==
          +>(arc [%& p.q.kuz r.q.kuz])
        ::
            %mut
          !!
        ==
      ?>  ?=(| -.arc)
      (dash:$(p.kuz t.p.kuz, +> (dent i.p.kuz)) i.p.kuz arc)
    ::
    ++  durn                                            ::  apply and reverse
      |=  kuy=ukay
      ^+  +>
      ?~  kuy  +>
      ::  ~&  [%drum-kuz i.kuy]
      $(kuy t.kuy, +> (drum i.kuy))
    -- 
  ++  zunk                                              ::  extract
    ^-  [p=ukay q=arch]
    [(flop uke) arc]
  --
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::                section 3bE, names etc                ::
::
++  gnow
  |=  gos=gcos  ^-  @t
  ?-    -.gos
      ?(%czar %king %pawn)  p.gos
      ?(%duke %jack) 
    ?+    -.p.gos  p.p.p.gos
        %anon  %%
        %punk  p.p.gos
        ?(%lord %lady)  
      =+  nam=`name`r.p.p.gos
      %+  rap  3
      :~  p.nam
          ?~(q.nam 0 (cat 3 ' ' u.q.nam))
          ?~(r.nam 0 (rap 3 ' (' u.r.nam ')' ~))
          ' '
          s.nam
      ==
    ==
  ==
++  hunt
  |=  [one=(unit ,@da) two=(unit ,@da)]
  ^-  (unit ,@da)
  ?~  one  two
  ?~  two  one
  ?:((lth u.one u.two) one two)
::
++  meat
  |=  kit=kite
  ^-  path
  [(cat 3 'c' p.kit) (scot %p r.kit) s.kit (scot (dime q.kit)) t.kit]
::
++  tame
  |=  hap=path
  ^-  (unit kite)
  ?.  ?=([@ @ @ *] hap)  ~
  =+  :*  hyr=(slay i.hap) 
          fal=(slay i.t.hap)
          dyc=(slay i.t.t.hap)
          ved=(slay i.t.t.t.hap) 
          ::  ved=(slay i.t.hap)
          ::  fal=(slay i.t.t.hap)
          ::  dyc=(slay i.t.t.t.hap)
          tyl=t.t.t.t.hap
      ==
  ?.  ?=([~ %% %tas @] hyr)  ~
  ?.  ?=([~ %% %p @] fal)  ~
  ?.  ?=([~ %% %tas @] dyc)  ~
  ?.  ?=(^ ved)  ~
  =+  his=`@p`q.p.u.fal
  =+  [dis=(end 3 1 q.p.u.hyr) rem=(rsh 3 1 q.p.u.hyr)]
  ?.  ?&(?=(%c dis) ?=(?(%w %x %y %z) rem))  ~
  [~ rem (case p.u.ved) q.p.u.fal q.p.u.dyc tyl]
--
