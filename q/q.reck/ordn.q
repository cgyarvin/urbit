::::::::  ordn            noun total order (0=in, 1=out, 2=equal)
::
  =.  [a=* b=*]
  |=
    =:  @
    ?-  a
      [@] 
        ?-  b
          [@]
            ?:  (eq a b)
              2
            (lt a b)
        ::
          [p=* q=*]   0
        ==
    ::
      [p=* q=*]
        ?-  b
          [@]   1
        ::
          [p=* q=*]
            =.  [c=$(a p.a, b p.b)] 
            ?-  c
              %0   0
              %1   1
              %2   $(a q.a, b q.b)
            ==
        ==
    ==
