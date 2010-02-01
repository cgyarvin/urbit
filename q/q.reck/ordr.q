::::::::  ordr            mug total order (0=in, 1=out, 2=equal)
::
  =.  [a=* b=*]
  |=
    =.  [c=(mug a) d=(mug b)]
    ?:  (eq c d)
      (ordn c d)
    (lt c d)
