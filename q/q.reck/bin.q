::::::::  bin             size in bloqs 
::
  ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
  ::                      b: source
  =.  [a=@ b=@]
  |=
    ?,  (lt a 16)
    =.  c=0
    |-
      ?:  (zip b)
        c
      $(b (rsh a 1 b), c (inc c))
