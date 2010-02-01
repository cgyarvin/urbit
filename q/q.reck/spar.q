::::::::  spar            parser
::
  |+
    ::::::::  case        grammar production
    ::
    - case
      =.  [a=*]
      |=
        ?-  a
          [@]                   a
          [%byte p=@ q=@]       a
          [%all p=*]            [%all p=((list case) p.a)]
          [%one p=*]            [%one p=((list case) p.a)]
        ==

    ::::::::  rule        grammar rule
    ::
    - rule
      =.  [a=*]
      |=
        ?-  a
          [p=@ q=*]   [p=p.a q=(case q.a)]
        ==

    ::::::::  gram        grammar
    ::
    - gram
      =.  [a=*]
      |=
        ((list rule) a)

    ::::::::  read        parse
    ::
    - read
      =.  [duf=@ bil=(case) tuv=(gram)]
      |=
        =.  zot=(fill.map tuv ~)
        =.  ver=0
        =-  nod
          ?-  nod
            ^
              ?,  (eq p.nod (bin 3 duf))
              q.nod
          ==
        |-
          =:  ({~ [p=@ q=*]})
          ?-  bil
            @   
              ?:  (eq 1 (bin 3 bil))
                ?:  (eq bil (cut 3 [1 ver] duf))
                  [p=(inc ver) q=bil]
                ~
              $(bil (take (get.map bil zot)))

            [%byte *]
              =.  fuv=(cut 3 [1 ver] duf)
              ?:  &((gte fuv p.bil) (lte fuv q.bil))
                [p=(inc ver) q=fuv]
              ~

            [%all *]
              =-  vep
                ?-  vep
                  ~          ~
                  [p=@ q=*]  [p=p.vep q=(tupl q.vep)]
                ==
              |-
                =:  (~(a=* [?- a ~ ~ [p=@ q=*] [p=p.a q=((list) q.a)] ==]))
                ?-  p.bil
                  ~   [p=ver q=~]
                  ^
                    =.  ged=`$(bil i.p.bil)
                    ?-  ged
                      ~   ~
                      ^   
                        =.  lop=$(ver p.ged, bil [%all t.p.bil])
                        ?-  lop
                          ~   ~
                          ^   [p=p.lop q=[q.ged q.lop]]
                        ==
                    ==
                ==
          ==
  ==

