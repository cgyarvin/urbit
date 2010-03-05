::::::::  turn            transform items in list
::
  =.  [a=((list)) b={*}]
  |=
    ?-  a
      ~   ~
      ^   [i=(b i.a) t=$(a t.a)]
    ==
