::::::::  map             associative array
::
  |+
    ::::::::  put         add item to map
    ::
    - put 
      =.  [a=[p=* q=*] b=((tree {[p=* q=*]}))]
      |=
        ?-  b
          ~   [n=a l=~ r=~]
          ^
            =:  [n=n.b l=l.b r=r.b]
            =.  c=(ordr p.a p.n.b)
            ?-  c
              %0
                =.  d=$(b l.b)
                =.  e=(ordr p.n.d p.n.b)
                ?-  e
                  %0  [n.b d r.b]
                  %1  [n.d l.d [n.b r.d r.b]]
                ==
            ::
              %1
                =.  d=$(b r.b)
                =.  e=(ordr p.n.b p.n.d)
                ?-  e
                  %0  [n.b l.b d]
                  %1  [n.d [n.b l.b l.d] r.d]
                ==
            ::
              %2
                ?,  (eq q.a q.n.b)
                b
            ==
        ==

    ::::::::  get         find item in map
    ::
    - get
      =.  [a=* b=((tree {[p=* q=*]}))]
      |=
        ?-  b
          ~   ~
          ^
            :: =:  ((pod {q.n.+2.b}))
            =.  c=(ordr a p.n.b)
            ?-  c
              %0  $(b l.b)
              %1  $(b r.b)
              %2  [i=q.n.b t=~]
            ==
        ==

    ::::::::  fill        add list to map
    ::
    - fill
      =.  [a=((list {[p=* q=*]})) b=((tree {[p=* q=*]}))]
      |=
        ?-  a
          ~   b
          ^   $(a t.a, b (put i.a b))
        ==
  ==

