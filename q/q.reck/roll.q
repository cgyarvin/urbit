::::::::  roll            fold list from front to back
::
  =.  [a=* b=((list)) c=~([a=* b=*] b)]
  |=
    =:  a
    ?-  b
      ~   a
      ^   $(a (c i.b a), b t.b)
    ==
