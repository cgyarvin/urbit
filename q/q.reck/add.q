::::::::  add             add (a + b)
::
  =.  [a=@ b=@]
  |=
    ?:  (zip a)
      b
    $(a (dec a), b (inc b))
