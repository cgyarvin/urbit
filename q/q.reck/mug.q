::::::::  mug             short hash
::
  %~
    =.  [a=*]
    |=
      =:  @
      ?-  a
        [p=* q=*]
          =.  [b=$(a p.a) c=$(a q.a)]
          =.  d=(mix b (add (end 5 1 (lsh 3 1 c)) (rsh 3 3 c)))
          |-
            =.  e=(dis 0x7fffffff (mash d))
            ?:  (zip e)
              $(d (inc d))
            e
        @
          =.  b=0x18d0a625
          |-
            =.  c=(bin 5 a)
            =.  d=0
            =.  e=b
            |-
              ?:  (eq d c)
                =.  f=(dis 0x7fffffff e)
                ?:  (zip f)
                  `$(b (inc b))
                f
              $(d (inc d), e (mash (mix e (cut 5 [1 d] a))))
      ==
  |+
    ::::::::  mash      32-bit sbox
    ::
    - mash
      =.  [a=@]
      |=
        =+  b
          0x45bd2fb7\ /eec357b8\ /2ae29f22\ /bb412e03\ /08445336\ /52ca46d8\
           /76d680b9\ /b9e06f14\ /6f8b9c36\ /a53ef834\ /e3533b5b\ /c5cd423e\
           /0cfd4d14\ /12924b1a\ /3e77ee18\ /1804e2a5\ /75d9c4e1\ /6d4b9a3e\
           /5d56c751\ /12ad4163\ /b9df9e63\ /fbfbdac7\ /54464f51\ /4b72be7f\
           /180d4405\ /1b456773\ /5fb51d73\ /2d4774c2\ /381585e2\ /0209e49e\
           /52c0256a\ /6deac45d\ /3f55045c\ /40b92e52\ /5242aa7a\ /a47337b1\
           /bc816aba\ /4bbb0ecf\ /f82cb4ad\ /0bc99c47\ /78a5c74c\ /9182f20d\
           /7b941dc3\ /ff307dd2\ /fc36ca9d\ /0c32efad\ /b1c38ca7\ /b799e1be\
           /fd0dbfee\ /9887957d\ /70186f9e\ /31325eca\ /48f0ac44\ /c7eb6480\
           /ab1f9401\ /167cf21d\ /dce5b8fa\ /121c9f64\ /e95eacb5\ /c50dca03\
           /8b29fd75\ /875f1bb9\ /261c8938\ /3bf794dc\ /e4395998\ /1b06df20\
           /19c11553\ /eefbdb16\ /54447c57\ /f54a4761\ /bdf13b8c\ /88502921\
           /72553aee\ /c63a1157\ /03a1f284\ /f5b59c3c\ /96923c87\ /e2c0936d\
           /4f112d16\ /0f4c5845\ /1055a07d\ /d82afef8\ /72fb1b49\ /0fa54e14\
           /637d01f5\ /7fe89a8b\ /0617eda8\ /4354f3e7\ /712f6316\ /9036b901\
           /111a1094\ /70c78bcc\ /28329ab3\ /fdf004ca\ /2026a870\ /85ac98d2\
           /3f52439e\ /e030c8ed\ /a7589924\ /05af69ed\ /566dd09c\ /4237062e\
           /e9fc60eb\ /c415321c\ /ac4fc47f\ /b265b0ee\ /95cdc493\ /3beb6b4d\
           /e777884a\ /370f9e65\ /6a52c674\ /62dc97c6\ /e5d5238e\ /b6315b6a\
           /c845a9e2\ /026c78ab\ /13beec00\ /b3ed287a\ /a01ebf2b\ /b5c0da93\
           /deeedce8\ /3e5ec58d\ /e83350f0\ /e6ffe2fb\ /a3765510\ /37f42e48\
           /474c90cf\ /78eea53d\ /d10faca2\ /a9417956\ /7c600063\ /14187d04\
           /faffdd23\ /44844992\ /61f4a52d\ /a234566b\ /a46b9dd7\ /1a9d0bd3\
           /cf3e4033\ /b3bcada3\ /00f3ef4e\ /7367a5f9\ /5e24070c\ /1b973827\
           /5dcd3652\ /95b1eb1f\ /035857a4\ /c090c33b\ /5eba8280\ /475d8534\
           /7fb44be7\ /3bffc889\ /dbaf1fa2\ /948328b1\ /56a8a01c\ /6717fa39\
           /4c41d2c6\ /b3275702\ /51634e92\ /51a573dd\ /d3ea1b9d\ /be74ea0b\
           /9093fa5f\ /d2e1d0d1\ /8a1fd93a\ /8f1d0a6e\ /b7a9e735\ /deb0aa12\
           /48d76271\ /e808ec02\ /8e498a90\ /83539726\ /86c7973e\ /44337e55\
           /81f4f7ca\ /3052b642\ /873b540e\ /68d8efa2\ /18494012\ /decc1486\
           /29079afa\ /b81a7b1d\ /63dd42a0\ /3cab1b6f\ /713fffa2\ /08835b42\
           /6dd6f5f8\ /65a14a04\ /5eab8eac\ /2fe5b7f9\ /bbc96404\ /f593e52b\
           /b2078d1a\ /f192cbcd\ /c5e102b2\ /9187837c\ /bddd8a18\ /5caf8a56\
           /3b7aa391\ /88fd1802\ /1e458e1d\ /5f606388\ /513ce98d\ /aed1093b\
           /ae87124c\ /f537ea14\ /0f4bb673\ /cfbeae41\ /123e5e9f\ /e14077a2\
           /40acd8dc\ /103b81cf\ /683fa466\ /9b9e2cec\ /23171ec6\ /2ba16060\
           /d3bfabae\ /dd68fcd2\ /f60ee7be\ /f44c697e\ /7990bd4e\ /3ce83919\
           /bc457a9d\ /5022a039\ /a158b454\ /80722ba6\ /87652d85\ /e2ddee5a\
           /5c43205e\ /c62f6816\ /4c680e34\ /151f4b17\ /9570fa83\ /eb9f040e\
           /22b9bd9c\ /d156e14b\ /3a30bdd8\ /f00fc9e2\ /62bcfdef\ /da4952df\
           /0c100eda\ /ccffce0a\ /1994625d\ /b0cd88c6\ /766ff6ec\ /7c8f831a\
           /7824fff6\ /dee5b579\ /99267e88\ /f8820121\ /6220ecc5\ /f40f7a8d\
           /fe8c511a\ /a9afcd63\ /ba9cd382\ /352598d8
        ::
        (end 5 1 
          (add 
            (cut 5 [1 (cut 3 [1 0] a)] b)
            (add 
              (cut 5 [1 (cut 3 [1 1] a)] b)
              (add 
                (cut 5 [1 (cut 3 [1 2] a)] b)
                (cut 5 [1 (cut 3 [1 3] a)] b)
              )
            )
          )
        )
  ==

