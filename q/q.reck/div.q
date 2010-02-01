::::::::  div             divide (b / a)
::
  =.  [a=@ b=@]
  |=
    ?`  (zip a)
    =+  c 0
    |-
      ?:  (gt a b)
        c 
      $(c (inc c), b (sub a b))
