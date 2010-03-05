::::::::  dis             bit disjoin - lunary or (binary and)
::
  =.  [a=@ b=@]
  |=
    =.  [c=0 d=0]
    |-
      ?:  |((zip a) (zip b))
        d
      $(a (rsh 0 1 a),
        b (rsh 0 1 b),
        c (inc c),
        d (add d (lsh 0 c |((zip (end 0 1 a)) (zip (end 0 1 b))))))
