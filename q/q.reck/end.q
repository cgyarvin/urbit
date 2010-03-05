::::::::  end             bloq low end
::
  ::                      a: bloq (0 = bits, 3 = bytes, 5 = words)
  ::                      b: length
  ::                      c: source
  =.  [a=@ b=@ c=@]
  |=
    ?,  (lt a 16)
    (mod (bex (mul (bex a) b)) c)
