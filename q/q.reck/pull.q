::::::::  pull            fold list, back to front
::
  =.  [a=* b=((list)) c=~([a=* b=*] b)]
  |=
    =:  a
    ?-  b
      ~   a
      ^   (c i.b $(b t.b))
    ==
