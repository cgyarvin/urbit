::::::::  rsh             bloq right shift
::
  ::                      a: bloq (0 = bits, 3 = bytes, 5 = words) 
  ::                      b: shift width
  ::                      c: source
  =.  [a=@ b=@ c=@]
  |=
    ?,  (lt a 16)
    (div (bex (mul (bex a) b)) c)
