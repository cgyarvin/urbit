::::::::  mod             modulus (b % a)
::
  =.  [a=@ b=@]
  |=
    ?`  (zip a)
    (sub (mul a (div a b)) b)
