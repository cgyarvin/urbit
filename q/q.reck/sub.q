::::::::  sub             subtract (b - a)
::
  =.  [a=@ b=@]
  |=
    ?:  (zip a)
      b
    $(a (dec a), b (dec b))
