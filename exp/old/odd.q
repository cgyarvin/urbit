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
      =?  a @
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


:::: Tier 2: simple arithmetic.
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


:::: Tier 3: heavy arithmetic and general noun wrangling.
::::
:::: seek: soft seek, with optional return
::::
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

  ::::::::  burn            modify binary
  ::
  :: - burn [a [b c d] e]
    ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
    ::                      b: position of patch
    ::                      c: length of patch
    ::                      d: value of patch
    ::                      e: source
    ::
      
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

  ::::::::  mix
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


:::: Tier 4: lists and cups
::::
:::: list - list definition

  ::::::::  list            define or normalize list
  ::
  - list
    =.  a={*}
    |=
      =.  b=*
      |=
        ?-  b
          ~           ~
          [i=* t=*]   [i=(a i.b) t=$(b t.b)]
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

  ::::::::  glum
  ::
  - glum
    =.  a=((list))
    |=
      =.  [b=~([b=*] b)]
      |=
        ?-  a
          ~ ~
          ^ [i=(b i.a) t=$(a t.a)]
        ==

:::: Testing junk.
::::
::::

  ::::::::  culm
  ::
  - culm
    =.  a=((list {@}))
    |=
      =.  b=0
      |-
        ?-  a
          ~   b
          ^   $(b (add b i.a), a t.a)
        ==

  ::::::::  cram
  ::
  - cram
    =.  a=((list ~([b=@ c=@] [b c])))
    |=
      (mull a ~([b=@ c=@] (inc b)))
==

