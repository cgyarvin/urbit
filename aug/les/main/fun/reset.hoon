!:
::  /=main=/fun/remix/hoon
::
|=  [who=seat est=time eny=@uw was=path]
|=  *
|=  arg=*
=+  ^=  lok  ^-  case
    ?:  =(~ arg)  [%da est]
    ?>  =(~ +.arg)
    ((hard case) -.arg)
=+  cav=(scot (dime lok))
=+  top=`path`[(scot %p who) %arvo cav ~]
=+  pax=`path`(weld top `path`[%hoon ~])
~&  %remix-start
=+  gen=(reck pax)
~&  %remix-parsed
=+  ken=q:(~(mint ut %noun) %noun gen)
=+  all=.*(0 ken)
~&  %remix-compiled
:_  ~
:-  [%xx %volt all]
^-  (list gift)
=+  ^=  vay  ^-  (list ,[p=@tas q=@tas])
    :~  [%% %zuse]
        [%a %ames]
        [%b %behn]
        [%c %clay]
        [%d %dill]
        [%e %eyre]
    ==
%+  turn  vay
|=  [a=@tas b=@tas]
=+  pax=(weld top `path`[%vane b ~])
=+  txt=((hard ,@) .^(%cx (weld pax `path`[%hoon ~])))
`gift`[%xx %veer a pax txt]
