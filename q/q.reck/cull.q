::::::::  cull            select items in list
::
  =.  [a=((list)) b=~([a=*] &4.a)]
  |=
    ?-  a
      ~   ~
      ^   ?:  (b i.a)
            [i.a $(a t.a)]
          $(a t.a)
    ==
