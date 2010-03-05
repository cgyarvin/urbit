::::::::  weld            bloq concatenate 
::
  ::                      a: bloq (0 = bits, 3 = bytes, 5 = words)
  ::                       
  =.  [a=@ b=*]
  |=
    =:  @
    ?,  (lt a 16)
    ?-  b
      @           b
      [p=* q=*]   =.  [c=$(b p.b) d=$(b q.b)]
                    (add c (lsh a (bin a c) d))
    ==
