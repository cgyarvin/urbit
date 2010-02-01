:: smoke-test kernel
::

|+
:::: Tier 1: trivial arithmetic.
::::
::::  dec   [a=@]           decrement
::::  eq    [a=* b=*]       test equality
::::  inc   [a=@]           increment
::::  pat   [a=*]           test for atom 
::::  tap   [a=*]           test for cell
::::  zip   [a=@]           test atom for zero
::
  - dec   #dec
  - eq    #eq
  - inc   #inc
  - pat   #pat
  - tap   #tap
  - zip   #zip


:::: Tier 2: light arithmetic.
::::
::::  add   [a=@ b=@]       add (a + b)
::::  div   [a=@ b=@]       divide (b / a) 
::::  mod   [a=@ b=@]       modulus (b % a)
::::  gt    [a=@ b=@]       greater than (a > b)
::::  gte   [a=@ b=@]       greater than or equal (a >= b)
::::  lt    [a=@ b=@]       less than (a < b)
::::  lte   [a=@ b=@]       less than or equal (a <= b)
::::  mul   [a=@ b=@]       multiply (a * b)
::::  sub   [a=@ b=@]       subtract (b - a)
::
  - add   #add
  - div   #div
  - mod   #mod
  - gt    #gt
  - gte   #gte
  - lt    #lt
  - lte   #lte
  - mul   #mul
  - sub   #sub


:::: Tier 3: recursive geometry.
::::
::::  list  [a={*}]         linked list of
::::  pod   [a={*}]         optional item of
::::  tree  [a={*}]         binary tree of
::::
::
  - list  #list
  - pod   #pod
  - tree  #tree


:::: Tier 4: traversal and iteration.
::::
::::  at    [a=@ b=((list))]                  reference item in list
::::  burp  [a=((list))]                      dump tree to list
::::  cat   [a=((list)) b=((list))]           concatenate lists
::::  cull  [a=((list)) b=~(* &)]             select items in list
::::  pull  [a=* b=((list) c=([a=* b=*] b)]   fold list, back to front
::::  roll  [a=* b=((list) c=([a=* b=*] b)]   fold list, front to back
::::  spin  [a=* b=~(* &) c=~(* *)]           iterate over state
::::  take  [a=((list))]                      require one item
::::  tupl  [a=((list))]                      convert list to tuple
::::  turn  [a=((list)) b={*}]                transform items in list
::::
::
  - at    #at
  - burp  #burp
  - cat   #cat
  - cull  #cull
  - pull  #pull
  - roll  #roll
  - spin  #spin
  - take  #take
  - tupl  #tupl
  - turn  #turn


:::: Tier 5: heavy arithmetic and miscellaneous noun carpentry.
:::: 
::::  bex  [a=@]                      exponent of 2
::::  bin  [a=@ b=@]                  size in bloqs
::::  burn [a=@ [b=@ c=@ d=@] e=@]    bloq modify
::::  con  [a=@ b=@]                  bit conjoin - lunary and (binary or) 
::::  cut  [a=@ [b=@ c=@] d=@]        bloq sample
::::  dis  [a=@ b=@]                  bit disjoin - lunary or (binary and) 
::::  end  [a=@ b=@ c=@]              bloq low end
::::  lsh  [a=@ b=@ c=@]              bloq left shift
::::  mix  [a=@ b=@]                  bit combine - lunary xor (binary xor) 
::::  mug  [a=*]                      short hash
::::  ordn [a=* b=*]                  noun total order (0=in, 1=out, 2=equal)
:::   ordr [a=* b=*]                  mug total order (0=in, 1=out, 2=equal)
::::  rsh  [a=@ b=@ c=@]              bloq right shift
::::  weld [a=@ b=*]                  bloq concatenate
::
  - bex   #bex
  - bin   #bin
  - burn  #burn
  - con   #con
  - cut   #cut
  - dis   #dis
  - end   #end
  - lsh   #lsh
  - mix   #mix
  - mug   #mug
  - ordn  #ordn
  - ordr  #ordr
  - rsh   #rsh
  - weld  #weld

:::: Tier 6: associative arrays.
::::
::
  - set   #set
  - map   #map

:::: Tier 7: parsing.
::::
::
  - spar  #spar

:::: Fun experimental code.
::
  - naf
    =.  [a=*]
    |=
      (cat [3 4 ~] ((list) a))

  - gum
    =.  [a=*]
    |=
      =.  b=((list {[p=@ q=@]}) a)
      =.  c=(fill.map b ~)
      =.  d=(get.map 3 c)
      =.  e=(take d)
      (add 7 e)
==
