!:
::  /=main=/bin/begin/hoon
::
=>  .(-< `who=@p`-<)
=>  .(+ =>(+ ^/===/pony))
|=  [est=time *]
|=  [mig=@p ~]
=+  bos=(sein mig)
?>  !=(bos mig)
^-  bowl
%+  pomp  ""
%+  pomp  "            If I did not build for myself"
%+  pomp  "            for whom should I build?"
%+  pomp  ""
%+  pomp  "                  -- Bunting, _Chomei at Toyama_"
%+  pomp  ""
=<  main
|%
++  main
  ^-  bowl
  %+  (polo ~ %text "ticket: ~" ~)
    fed:ag
  |=  [* tic=@p]
  %+  (polo ~ %pass "entropy: " ~)
    (boss 256 (more gon qit))
  |=  [* tey=@]
  =.  tey  (shax tey)
  %+  pomp  "entropy check: {<`@p`(mug tey)>}"
  =+  ran=(clan mig)
  ?.  |(=(%duke ran) =(%jack ran))
    %+  (polo ~ %text "name: " ~)
      (boss 256 (more gon qit))
    |=  [now=@da nam=@]
    (moss now tic tey (gcos [ran nam]))
  %+  (polo ~ %text "first name: " ~)
    (boss 256 (more gon qit))
  |=  [* fin=@]
  %+  (polo ~ %text "last name: " ~)
    (boss 256 (more gon qit))
  |=  [* sur=@]
  %+  (polo ~ %text "birth year: " ~)
    dim:ag
  |=  [now=@ yar=@]
  (moss now tic tey (gcos [ran %lord [yar /us/94.114 [fin ~ ~ sur]]]))
::
++  moss
  |=  [now=@da tic=@p tey=@ gec=gcos]
  ^-  bowl
  =+  bur=(shax :(mix (jam gec) tey))
  %+  (posh now)  ~[la/leaf/"generating 2048-bit RSA key..."]
  |=  now=@da
  =+  loy=(brew 2.048 bur)
  %-  (post bos [%ta %to] [mig tic gec pub:ex:loy])
  |=  [now=@da rup=(unit ,*)]
  :_  ~
  ?~  rup  ~[la/leaf/"request rejected"]
  =+  mac=`mace`[[0 sec:ex:loy] ~]
  =+  wil=((hard will) u.rup)
  :~  [%la %leaf "request approved"]
      [%xy /a `card`[%cash mig mac wil]]
  ==
--
