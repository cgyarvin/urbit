::::::::  burn            bloq modify
::
  ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
  ::                      b: position of patch
  ::                      c: length of patch
  ::                      d: value of patch
  ::                      e: source
  ::
  =.  [a=@ [b=@ c=@ d=@] e=@]
  |=
    ?,  (lt a 16)
    ?,  (lte (bin a d) c)
    ::
    (add 
      (lsh a (add b c) (rsh a (add b c) e)) 
      (add d (end a b e))
    )
