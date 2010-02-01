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
  
  ::::::::  con             conjoin - lunary or (== binary and)
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

  ::::::::  cut
  ::
  - cut
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

  ::::::::  stig            stig definition 
  ::
  - stig
    =.  a=~([b=*] b)
    |=
      =.  b=*
      |=
        a

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

