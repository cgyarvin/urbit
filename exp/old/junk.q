  ::::::::  cram
  ::
  - cram
    =.  a=((list {[@ @]}))
    |=
      (turn a ~([b=@ c=@] (add b c)))

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


:::: Testing junk.
::::
::::

  ::::::::  garb
  ::
  - garb
    =.  [a=*]
    |=
      =:  ((list) {[* @]})
      =.  b=((list a) {[p=@ q=*]})
      %-  (mull b) 
        =.  [p=@ q=*]
        |=
          [q p]

  ::::::::  flop
  ::
  - flop
    =.  [a=@ b=*]
    |=
      %-  (cull ((list b) {@}))
        =.  [c=*]
        |=
          (eq a c)

  ::::::::  glem
  ::
  - glem
    =.  [a=* b=*]
    |=
      =:  ((list) {[* *] @})
      =+  c ((list a) {@})
      =+  d ((list b) {[* *]})
      ::
      (glue c d)

  ::::::::  sart
  ::

== 
