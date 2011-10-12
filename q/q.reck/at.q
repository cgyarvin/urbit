::::::::  list              reference item in list
::
  =.  [a=@ b=((list))]
  |=
    ?:  (zip a)
      ?-  b
        ^   i.b
      ==
    ?-  b
      ^   $(a (dec a), b t.b)
    ==
