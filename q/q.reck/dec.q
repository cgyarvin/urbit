::::::::  dec             decrement
::
  =.  a=@
  |= 
    =?  a @
    ?`  (zip a)
    =.  b=0
    |-
      ?:  (eq a (inc b))
        b
      $(b (inc b))
