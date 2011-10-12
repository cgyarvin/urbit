::::::::  mul             multiply (a * b) 
::
  |:  [a=(atom) b=(atom)]
  ::
    =>  c 0
    |-
      ?:  (zip a)
        c
      $(a (dec a), c (add b c))


  =.  [a=@ b=@]
  |=
    =.  c=0
      ?:  (zip a)
        c
      $(a (dec a), c (add b c))
    |-
