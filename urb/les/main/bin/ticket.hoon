::
::  /=main=/fun/env/hoon
::
|=  [who=seat est=time *]
|=  arg=*
^-  bowl
:_  ~
=+  ^=  fir  ^-  [p=@p q=@ud]
    ?:  ?=([@ ~] arg)
      [-.arg 1]
    ?:  ?=([@ @ ~] arg)
      [-.arg +<.arg]
    ~|(%ticket-arg !!)
|-  ^-  (list gift)
?:  =(0 q.fir)  ~
=+  tic=(,@p .^(%a (scot %p who) %tick (scot %da est) (scot %p p.fir) ~))
:-  [%la %leaf "{<p.fir>}: {<tic>}"]
$(p.fir +(p.fir), q.fir (dec q.fir))
