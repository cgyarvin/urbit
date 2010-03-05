::::::::  lte             less than or equal (a <= b)
::
  =.  [a=@ b=@]
  |=
    ?|
      (eq a b)
      (lt a b)
    ==
