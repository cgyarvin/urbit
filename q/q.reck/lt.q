::::::::  lt              less than (a < b)
::
  =.  [a=@ b=@]
  |=
    ?&
      !(eq a b)
      |-
        ?:  (zip a)
          &
        ?:  (zip b)
          |
        $(a (dec a), b (dec b))
    ==
