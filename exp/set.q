::::::::  set             set toolkit
::
  |+
    ::::::::  put         add item to set
    ::
    - put 
      =.  [a=* b=((tree))]
      |=
        =:  [n=* l=((tree)) r=((tree))]
        ?-  b
          ~   [a ~ ~]
        ::
          [n=* l=* r=*]
            =.  c=(ordr a n.b)
            ?-  c
              %0
                =.  d=$(b l.b)
                =.  e=(ordr n.b n.d)
                b
            ::
              %1  b
            ::
              %2  b
            ==
        ==
  ==
