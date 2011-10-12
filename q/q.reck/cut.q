::::::::  cut             bloq sample
::
  ::                      a: bloq (0 = bits, 3 = bytes, 5 = words)
  ::                      b: length of cut
  ::                      c: position of cut
  ::                      d: source
  =.  [a=@ [b=@ c=@] d=@]
  |=
    ?,  (lt a 16)
    (end a b (rsh a c d))
