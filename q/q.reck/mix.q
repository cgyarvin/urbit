::::::::  mix             bit combine - lunary xor (binary xor)
::
  =.  [a=@ b=@]
  |=
    =.  [c=0 d=0]
    |-
      ?:  &((zip a) (zip b))
        d
      $(a (rsh 0 1 a),
        b (rsh 0 1 b),
        c (inc c),
        d (add d (lsh 0 c (eq (end 0 1 a) (end 0 1 b)))))

