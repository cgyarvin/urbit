::::::::  tupl            convert list to tuple
::
  =.  [a=((list))]
  |=
    =:  *
    ?-  a
      [i=* t=~]   [=: * i.a]
      ^           [i.a $(a t.a)]
    ==
