!:
::          %gall, http.  This file is in the public domain.
::
|%                                                      
++  gall                                                ::  http system
  =|  $:  seh=(list ,[p=host q=flag])                   ::  http servers
      ==
  |=  [now=@da eny=@ sky=||(* (unit))]                  ::  activate
  |%                                                    ::
  ++  peek  |=(path `(unit)`~)                          ::  enquire
  ++  poke                                              ::  apply
    |=  [whu=(unit flag) pax=path hen=vein fav=card]
    ^-  [p=(list move) q=_..^$]
    ?+    -.fav  !!
        %bind                                           ::  register server
      ?>  =(%gold (adit hen))
      =+  ^=  nom  ^-  tape
          ?-  -.q.fav
            &  ~(ram re (dish:ut [~ %path] p.q.fav))
            |  ~(rend co ~ %if p.q.fav)
          ==
      =+  giy=~(rend co ~ %p p.fav)
      :-  [[~ hen [%warn "http: serving {nom} as {giy}"]] ~]
      %=    ..^$
          seh
        :-  [q.fav p.fav]
        (skip seh |=([a=host b=flag] (hone q.fav a)))
      ==
    ::
        ?(%thin %this)                                  ::  process request
      :_  ..^$
      :_  ~
      =+  heq=(thin =(%this -.fav) p.fav)
      =+  ^=  whu  |-  ^-  (unit ,@p)
          ?~  seh  ~
          ?:  (hone r.p.p.heq p.i.seh) 
            [~ q.i.seh] 
          $(seh t.seh)
      ?~  whu
        [~ hen [%thou 404 ~ ~]]
      [whu [[%bede ~] hen] [%thee heq]]
    ==
  --
--
