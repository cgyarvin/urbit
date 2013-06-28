!:
::  /=main=/toy/begin/hoon
::
=>  ^^/===/pony
|=  [who=seat est=time eny=@uw was=path]
|=  *
|=  [our=seat tix=@p ~]
^-  bowl
=+  bos=(sein our)
%+  pomp  ""
%+  pomp  "            If I did not build for myself"
%+  pomp  "            for whom should I build?"
%+  pomp  ""
%+  pomp  "                  -- Bunting, _Chomei at Toyama_"
%+  pomp  ""
%+  pomp  "registering {<our>} under {<bos>}"
%+  (polo %pass "entropy: " ~)
  (boss 256 (more gon qit))
|=  tey=@
=.  tey  (shax tey)
%+  pomp  "entropy check: {<`@p`(mug tey)>}"
%+  (polo %text "first name: " ~)
  (boss 256 (more gon qit))
|=  fin=@
%+  (polo %text "last name: " ~)
  (boss 256 (more gon qit))
|=  sur=@
%+  (polo %text "year of birth: " ~)
  dim:ag
|=  yar=@
=+  wum=`whom`[yar %us-ca [fin ~ ~ sur]]
=+  loy=(brew 2.048 tey)
=+  gec=(gcos [(clan our) %lord wum])
=+  msg=`[@p @pG gcos pass]`[our tix gec pub:ex:loy]
^-  bowl
:-  ~
:-  ~
:-  ^-  (list slip)
    :~  [~ [%yo bos %ta msg]]
    ==
|=  [now=@da pax=path nut=note]
?>  ?=(%yo -.nut)
:_  ~
^-  (list gift)
:-  [%la %leaf ?:(=(%good q.nut) "received ok" "crashed")]
~
