:: smoke-test kernel
::

|+
:::: Tier 1: trivial arithmetic.
::::
::::
  ::::::::  dec             decrement
  ::
  - dec
    =.  a=@
    |= 
      ?`  (zip a)
      =.  b=0
      |-
        ?:  (eq a (inc b))
          b
        $(b (inc b))

  ::::::::  eq              test equality (lunary: 0 = yes, 1 = no)
  ::
  - eq
    =.  [a=* b=*]
    |=
      &6.[a b]

  ::::::::  inc             increment
  ::
  - inc
    =.  a=@
    |=
      &5.a

  ::::::::  pat             test for atom (lunary: 0 = yes, 1 = no)
  ::
  - pat
    =.  a=*
    |=
      !&4.a

  ::::::::  tap             test for cell (lunary: 0 = yes, 1 = no)
  ::
  - tap
    =.  a=*
    |=
      &4.a

  ::::::::  zip             test atom for zero (lunary: 0 = yes, 1 = no)
  ::
  - zip
    =.  a=@
    |=
      &6.[0 a]


:::: Tier 2: light arithmetic.
::::
::::
  ::::::::  add             add
  ::
  - add 
    =.  [a=@ b=@]
    |=
      ?:  (zip a)
        b
      $(a (dec a), b (inc b))

  ::::::::  div             divide (arguments in reverse order)
  ::
  - div
    =.  [a=@ b=@]
    |=
      ?`  (zip a)
      =+  c 0
      |-
        ?:  (gt a b)
          c 
        $(c (inc c), b (sub a b))

  ::::::::  mod             modulus (arguments in reverse order)
  ::
  - mod
    =.  [a=@ b=@]
    |=
      ?`  (zip a)
      (sub (mul a (div a b)) b)

  ::::::::  gt
  ::
  - gt
    =.  [a=@ b=@]
    |=
      !(lte a b)

  ::::::::  gte
  ::
  - gte
    =.  [a=@ b=@]
    |=
      !(lt a b)

  ::::::::  lt
  ::
  - lt
    =.  [a=@ b=@]
    |=
      ?&
        !(eq a b)
        |-
          ?:  (zip a)
            &
          ?:  (zip b)
            |
          $(a (dec a), b (dec b))
      ==

  ::::::::  lte
  ::
  - lte
    =.  [a=@ b=@]
    |=
      ?|
        (eq a b)
        (lt a b)
      ==

  ::::::::  mul
  ::
  - mul
    =.  [a=@ b=@]
    |=
      =.  c=0
      |-
        ?:  (zip a)
          c
        $(a (dec a), c (add b c))

  ::::::::  sub
  ::
  - sub
    =.  [a=@ b=@]
    |=
      ?:  (zip a)
        b
      $(a (dec a), b (dec b))


:::: Tier 3: high arithmetic and general noun wrangling.
:::: 
:::: +
:::: seek: soft seek, with optional return
::::
  ::::::::  bex             exponent of 2
  ::
  - bex
    =.  a=@
    |=
      =.  b=1
      |-
        ?:  (zip a)
          b
        $(b (mul 2 b), a (dec a))

  ::::::::  bin             size in bloqs 
  ::
  - bin
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
    ::                      b: source
    =.  [a=@ b=@]
    |=
      ?,  (lt a 16)
      =.  c=0
      |-
        ?:  (zip b)
          c
        $(b (rsh a 1 b), c (inc c))

  ::::::::  burn            modify bloqs in atom
  ::
  - burn
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
    ::                      b: position of patch
    ::                      c: length of patch
    ::                      d: value of patch
    ::                      e: source
    ::
    =.  [a=@ [b=@ c=@ d=@] e=@]
    |=
      ?,  (lt a 16)
      ?,  (lte (bin a d) c)
      ::
      (add (lsh a (add b c) (rsh a (add b c) e)) (add d (end a b e)))
  
  ::::::::  con             conjoin - lunary and (== binary or)
  ::
  - con
    =. [a=@ b=@]
    |=
      =.  [c=0 d=0]
      |-
        ?:  &((zip a) (zip b))
          d
        $(a (rsh 0 1 a),
          b (rsh 0 1 b),
          c (inc c),
          d (add d (lsh 0 c &((zip (end 0 1 a)) (zip (end 0 1 b))))))

  ::::::::  cut             select atom bloqs 
  ::
  - cut
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words)
    ::                      b: length of cut
    ::                      c: position of cut
    ::                      d: source
    =.  [a=@ [b=@ c=@] d=@]
    |=
      ?,  (lt a 16)
      (end a b (rsh a c d))

  ::::::::  dis             disjoin - lunary or (== binary and)
  ::
  - dis
    =.  [a=@ b=@]
    |=
      =.  [c=0 d=0]
      |-
        ?:  |((zip a) (zip b))
          d
        $(a (rsh 0 1 a),
          b (rsh 0 1 b),
          c (inc c),
          d (add d (lsh 0 c |((zip (end 0 1 a)) (zip (end 0 1 b))))))

  ::::::::  end             extract right end
  ::
  - end
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words)
    ::                      b: length
    ::                      c: source
    =.  [a=@ b=@ c=@]
    |=
      ?,  (lt a 16)
      (mod (bex (mul (bex a) b)) c)

  ::::::::  lsh             left shift
  ::
  - lsh
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
    ::                      b: shift width
    ::                      c: source
    =.  [a=@ b=@ c=@]
    |=
      ?,  (lt a 16)
      (mul (bex (mul (bex a) b)) c)

  ::::::::  mix             combine - lunary xor (== binary xor)
  ::
  - mix
    =.  [a=@ b=@]
    |=
      =.  [c=0 d=0]
      |-
        ?:  &((zip a) (zip b))
          d
        =. [e=(zip (end 0 1 a)) f=(zip (end 0 1 b))]
        $(a (rsh 0 1 a),
          b (rsh 0 1 b),
          c (inc c),
          d (add d (lsh 0 c |(&(e !f) &(!e f)))))

  ::::::::  rsh             right shift
  ::
  - rsh
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
    ::                      b: shift width
    ::                      c: source
    =.  [a=@ b=@ c=@]
    |=
      ?,  (lt a 16)
      (div (bex (mul (bex a) b)) c)

  ::::::::  weld            concatenate atoms 
  ::
  - weld
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words)
    ::                       
    =.  [a=@ b=*]
    |=
      =:  @
      ?,  (lt a 16)
      ?-  b
        @           b
        [p=* q=*]   =.  [c=$(b p.b) d=$(b q.b)]
                      (add c (lsh a (bin a c) d))
      ==


:::: Tier 4: Platonic shapes.
::::
::::
  ::::::::  cup             "maybe" type 
  ::
  - cup
    =.  a={*}
    |=
      =.  b=*
      |=
        ?-  b
          ~           ~
          [i=* ~]     [i=(a i.b) ~]
        ==
 
  ::::::::  list            list definition 
  ::
  - list
    =.  a=~([b=*] b)
    |=
      =.  b=*
      |=
        ?-  b
          ~           ~
          [i=* t=*]   [i=(a i.b) t=$(b t.b)]
        ==

  ::::::::  tree            binary tree
  ::
  - tree
    =.  a={*}
    |=
      =.  b=*
      |=
        ?-  b
          ~               ~
          [n=* l=* r=*]   [n=(a n.b) l=$(b l.b) r=$(b r.b)]
        ==


:::: Tier 5: traversal and iteration.
::::
::::
  ::::::::  at              dereference in list
  ::
  - at
    =.  [a=@ b=((list))]
    |=
      ?:  (zip a)
        ?-  b
          ^   i.b
        ==
      ?-  b
        ^   $(a (dec a), b t.b)
      ==

  ::::::::  cull            select list entries
  ::
  - cull
    =.  [a=((list)) b=~([a=*] &4.a)]
    |=
      ?-  a
        ~   ~
        ^   ?:  (b i.a)
              [i.a $(a t.a)]
            $(a t.a)
      ==

  ::::::::  mull            transform list entries
  ::
  - mull
    =.  [a=((list)) b={*}]
    |=
      ?-  a
        ~   ~
        ^   [i=(b i.a) t=$(a t.a)]
      ==

  ::::::::  need            require first and only element
  ::
  - need
    =.  a=((list))
    |=
      ?-  a
        [i=* ~]   i.a
      ==

  ::::::::  pull            fold list from back to front
  ::
  - pull
    =.  [a=* b=((list)) c=~([a=* b=*] a)]
    |=
      =:  a
      ?-  b
        ~   a
        ^   (c i.b $(b t.b))
      ==
 
  ::::::::  roll            fold list from front to back
  ::
  - roll
    =.  [a=* b=((list)) c=~([a=* b=*] a)]
    |=
      =:  a
      ?-  b
        ~   a
        ^   $(a (c i.b a), b t.b)
      ==

  ::::::::  spin            state iteration
  ::
  - spin
    =.  [a=* b=~([a=*] &4.a) c={*}]
    |=
      ?:  (b a)
        a
      $(a (c a))


:::: Tier 6: associative memory.
::::
  ::::::::  mash            32-bit hash conversion
  ::
  - mash
    =.  [a=@]
    |=
      =+ b
        =:  ((list {@}))
        [ 0xc52598d8 0xba93dc82 0xa9af3d6c 0xfe83511a 0xf40f7a8d 0x6220e335
          0xf8820121 0x99267e88 0xdee5b579 0x7824fff6 0x738f8c1a 0x766ff6e3
          0xb03d8836 0x1994625d 0x33ff3e0a  0x3100eda 0xda4952df 0x62b3fdef
          0xf00f39e2 0xcac0bdd8 0xd156e14b 0x22b9bd93 0xeb9f040e 0x9570fa8c
          0x151f4b17 0x43680ec4 0x362f6816 0x534c205e 0xe2ddee5a 0x87652d85
          0x80722ba6 0xa158b454 0x5022a0c9 0xb3457a9d 0xc3e8c919 0x7990bd4e
          0xf443697e 0xf60ee7be 0xdd68f3d2 0xdcbfabae 0x2ba16060 0x2c171e36
          0x9b9e23e3 0x68cfa466 0x10cb813f 0x40a3d8d3 0xe14077a2 0x12ce5e9f
          0x3fbeae41  0xf4bb67c 0xf5c7ea14 0xae871243 0xaed109cb 0x51c3e98d
          0x5f606c88 0x1e458e1d 0x88fd1802 0xcb7aac91 0x53af8a56 0xbddd8a18
          0x91878c73 0x35e102b2 0xf1923b3d 0xb2078d1a 0xf59ce52b 0xbb396404
          0x2fe5b7f9 0x5eab8ea3 0x65a14a04 0x6dd6f5f8  0x88c5b42 0x71cfffa2
          0xc3ab1b6f 0x6cdd42a0 0xb81a7b1d 0x29079afa 0xde331486 0x18494012
          0x68d8efa2 0x87cb540e 0xc052b642 0x81f4f73a 0x44cc7e55 0x863797ce
          0x8c5c9726 0x8e498a90 0xe808e302 0x48d76271 0xdeb0aa12 0xb7a9e7c5
          0x8f1d0a6e 0x8a1fd9ca 0xd2e1d0d1 0x909cfa5f 0xbe74ea0b 0xdcea1b9d
          0x51a57cdd 0x516c4e92 0xbc275702 0x4341d236 0x6717fac9 0x56a8a013
          0x948c28b1 0xdbaf1fa2 0xcbff3889 0x7fb44be7 0x475d85c4 0x5eba8280
          0x30903ccb  0xc5857a4 0x95b1eb1f 0x5d3dc652 0x1b97c827 0x5e240703
          0x7c67a5f9   0xfcef4e 0xbcb3adac 0x3fce40cc 0x1a9d0bdc 0xa46b9dd7
          0xa2c4566b 0x61f4a52d 0x44844992 0xfaffdd2c 0x14187d04 0x7360006c
          0xa9417956 0xd10fa3a2 0x78eea5cd 0x4743903f 0xc7f42e48 0xac765510
          0xe6ffe2fb 0xe8cc50f0 0xce5e358d 0xdeeed3e8 0xb530da9c 0xa01ebf2b
          0xbced287a 0x1cbee300  0x26378ab 0x3845a9e2 0xb6c15b6a 0xe5d52c8e
          0x62d39736 0x6a523674 0xc70f9e65 0xe777884a 0xcbeb6b4d 0x953d349c
          0xb265b0ee 0xa34f347f 0x3415c213 0xe9f360eb 0x42c7062e 0x566dd093
           0x5af69ed 0xa7589924 0xe0c038ed 0xcf524c9e 0x85a398d2 0x2026a870
          0xfdf0043a 0x28c29abc 0x70378b33 0x111a1094 0x90c6b901 0x712f6c16
          0x4c54fce7  0x617eda8 0x7fe89a8b 0x6c7d01f5  0xfa54e14 0x72fb1b49
          0xd82afef8 0x1055a07d  0xf435845 0x4f112d16 0xe2309c6d 0x9692c387
          0xf5b593c3  0xca1f284 0x36ca1157 0x7255caee 0x88502921 0xbdf1cb83
          0xf54a4761 0x54447357 0xeefbdb16 0x1931155c 0x1b06df20 0xe4c95998
          0xcbf794d3 0x261389c8 0x875f1bb9 0x8b29fd75 0x350d3a0c 0xe95ea3b5
          0x12139f64 0xd3e5b8fa 0x1673f21d 0xab1f9401 0x37eb6480 0x48f0a344
          0xc1c25e3a 0x70186f9e 0x9887957d 0xfd0dbfee 0xb799e1be 0xb13c83a7
           0x3c2efad 0xf3c63a9d 0xffc07dd2 0x7b941d3c 0x9182f20d 0x78a53743
           0xb399347 0xf823b4ad 0x4bbb0e3f 0xb3816aba 0xa47cc7b1 0x5242aa7a
          0x40b92e52 0xcf550453 0x6dea345d 0x5230256a  0x209e49e 0xc81585e2
          0x2d477432 0x5fb51d7c 0x1b45677c 0x180d4405 0x4b72be7f 0x54464f51
          0xfbfbda37 0xb9df9e6c 0x12ad416c 0x5d563751 0x6d4b9ace 0x75d934e1
          0x1804e2a5 0xce77ee18 0x12924b1a  0x3fd4d14 0x353d42ce 0xec5ccb5b
          0xa5cef8c4 0x6f8b93c6 0xb9e06f14 0x76d680b9 0x523a46d8  0x8445cc6
          0xbb412e0c 0x2ae29f22 0xee3c57b8 0x45bd2fb
        ~ ]
      (end 5 1 
        (add 
          (at (cut 3 [1 0] a) b)
          (add 
            (at (cut 3 [1 1] a) b)
            (add 
              (at (cut 3 [1 2] a) b)
              (at (cut 3 [1 3] a) b)
            )
          )
        )
      )

  ::::::::  mug             short (insecure) noun hash
  ::
    =.  a=*
    |=
      =:  @
      ?-  a
        [p=* q=*]
          47
          =.  [b=$(a p.a) c=$(a q.a)]
          =.  d=(mix b (add (end 5 1 (lsh 3 1 c)) (rsh 3 3 c)))
          |-
            =.  e=(dis 0x7fffffff (mash d))
            ?:  (zip e)
              $(d (inc d))
            e
        @
          =.  b=0x18d0a625
          |-
            =.  c=(bin 5 a)
            =.  d=0
            =.  e=b
            |-
              ?:  (eq d c)
                =.  f=(dis 0x7fffffff e)
                ?:  (zip f)
                  $$(b (inc b))
                f
              $(d (inc d), e (mash (mix e (cut 5 [1 d] a))))
      ==

:::: Testing junk.
::::
::::

  ::::::::  cram
  ::
  - cram
    =.  a=((list {[@ @]}))
    |=
      (mull a ~([b=@ c=@] (add b c)))

  ::::::::  deck
  ::
  - deck
    =.  a=@
    |=
      (spin a ~([b=@] (gt b a)) ~([b=@] (inc b)))

  ::::::::  crum
  ::
  - crum
    =.  a=((list {@}))
    |=
      (roll 0 a ~([b=@ c=@] (add b c)))
==

