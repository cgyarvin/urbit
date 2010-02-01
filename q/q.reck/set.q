::::::::  set             set toolkit
::
  |+
    ::::::::  put         add item to set
    ::
    - put 
      =.  [a=* b=((tree))]
      |=
        =:  [n=n.+2.b l=b r=b]        :: ugly - revisit
        ?-  b
          ~   [a ~ ~]
          ^
            =.  c=(ordr a n.b)
            ?-  c
              %0
                =.  d=$(b l.b)
                =.  e=(ordr n.d n.b)
                ?-  e
                  %0  [n.b d r.b]
                  %1  [n.d l.d [n.b r.d r.b]]
                ==
            ::
              %1
                =.  d=$(b r.b)
                =.  e=(ordr n.b n.d)
                ?-  e
                  %0  [n.b l.b d]
                  %1  [n.d [n.b l.b l.d] r.d]
                ==
            ::
              %2  b
            ==
        ==

    ::::::::  has         test item in set
    ::
    - has
      =.  [a=* b=((tree))]
      |=
        ?-  b
          ~   |
          ^
            =.  c=(ordr a n.b)
            ?-  c
              %0  $(b l.b)
              %1  $(b r.b)
              %2  &
            ==
        ==
  ==
