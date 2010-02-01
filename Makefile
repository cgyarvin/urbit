# A simple makefile.
#

# Pick one of:
#   linux
#   osx
#
#OS=linux
OS=osx

# Pick one of:
#   little
#   big
#
ENDIAN=little

# Binary directory - not in quotes.
#
BIN=run

RM=rm -f
CC=gcc
CLD=gcc -bind_at_load -L/sw/lib
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU3_OS_$(OS) -DU3_OS_ENDIAN_$(ENDIAN)\
	-DU4_ENDIAN_$(ENDIAN) -DU4_OS_$(OS)
CFLAGS=-g -I/sw/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
CWFLAGS=-Wall

.y.o:
	 $(YACC) $<
	 $(CC) -c $(CFLAGS) -o $@ $(GENERATED)/y.tab.c
	 $(RM) $(GENERATED)/y.tab.c

.c.o:
	 $(CC) -c $(CWFLAGS) $(CFLAGS) -o $@ $<

U4_CAKE_OFILES=\
       b/cake/bail.o \
       b/cake/road.o \
       b/cake/look.o \
       b/cake/make.o

U4_DISK_OFILES=\
       b/disk/disk.o

U4_MILL_OFILES=\
       b/mill/and.o \
       b/mill/bake.o \
       b/mill/both.o \
       b/mill/comp.o \
       b/mill/cons.o \
       b/mill/cull.o \
       b/mill/dump.o \
       b/mill/eith.o \
       b/mill/fail.o \
       b/mill/fiat.o \
       b/mill/find.o \
       b/mill/fish.o \
       b/mill/hike.o \
       b/mill/look.o \
       b/mill/make.o \
       b/mill/mate.o \
       b/mill/mill.o \
       b/mill/nest.o \
       b/mill/not.o  \
       b/mill/null.o \
       b/mill/open.o \
       b/mill/or.o   \
       b/mill/orth.o \
       b/mill/peek.o \
       b/mill/pike.o \
       b/mill/play.o \
       b/mill/poke.o \
       b/mill/reap.o \
       b/mill/repo.o \
       b/mill/slip.o \
       b/mill/snap.o \
       b/mill/stub.o \
       b/mill/test.o \
       b/mill/trap.o \
       b/mill/turn.o \
       b/mill/weld.o

U4_MX_OFILES=\
       b/x/clep.o \
       b/x/dbug.o \
       b/x/forb.o \
       b/x/gant.o \
       b/x/gult.o \
       b/x/griv.o \
       b/x/halc.o \
       b/x/perd.o \
       b/x/poos.o \
       b/x/pret.o \
       b/x/sard.o \
       b/x/slon.o \
       b/x/spot.o \
       b/x/stol.o \
       b/x/tarn.o

U4_MQ_OFILES=\
       b/q/blin.o \
       b/q/boce.o \
       b/q/brip.o \
       b/q/crot.o \
       b/q/delc.o \
       b/q/feng.o \
       b/q/flec.o \
       b/q/flot.o \
       b/q/frez.o \
       b/q/garc.o \
       b/q/glax.o \
       b/q/glem.o \
       b/q/lect.o \
       b/q/lisc.o \
       b/q/lome.o \
       b/q/malk.o \
       b/q/neft.o \
       b/q/palt.o \
       b/q/peld.o \
       b/q/plom.o \
       b/q/pont.o \
       b/q/prex.o \
       b/q/pril.o \
       b/q/pung.o \
       b/q/rald.o \
       b/q/rulf.o \
       b/q/serd.o \
       b/q/spal.o \
       b/q/stiv.o \
       b/q/trup.o \
       b/q/veck.o \
       b/q/wamp.o \
       b/q/zact.o \
       b/q/zarb.o

U4_FAKE_OP_OFILES=\
       b/fake/op/add.o \
       b/fake/op/con.o \
       b/fake/op/cut.o \
       b/fake/op/cutb.o \
       b/fake/op/dec.o \
       b/fake/op/dis.o \
       b/fake/op/div.o \
       b/fake/op/end.o \
       b/fake/op/endb.o \
       b/fake/op/get.o \
       b/fake/op/inc.o \
       b/fake/op/log.o \
       b/fake/op/lsh.o \
       b/fake/op/lshb.o \
       b/fake/op/mix.o \
       b/fake/op/mod.o \
       b/fake/op/mul.o \
       b/fake/op/ord.o \
       b/fake/op/pan.o \
       b/fake/op/peg.o \
       b/fake/op/put.o \
       b/fake/op/sub.o \
       b/fake/op/tap.o \
       b/fake/op/tip.o \
       b/fake/op/rsh.o \
       b/fake/op/rshb.o 

U4_FAKE_ALG_OFILES=\
       b/fake/bag.o \
       b/fake/log.o \
       b/fake/tab.o \
       b/fake/ugly.o

U4_FAKE_PUMP_OFILES=\
       b/fake/pump/bug.o \
       b/fake/pump/err.o \
       b/fake/pump/prep.o \
       b/fake/pump/dump.o

U4_FAKE_OFILES=$(U4_FAKE_OP_OFILES) \
	       $(U4_FAKE_ALG_OFILES) \
	       $(U4_FAKE_PUMP_OFILES)

U4_NOCK_OFILES=\
       b/nock/pure.o

U4_WATT_OFILES=\
       b/watt/grammar.o \

U4_OFILES= \
       $(U4_CAKE_OFILES) \
       $(U4_DISK_OFILES) \
       $(U4_FAKE_OFILES) \
       $(U4_LIB_OFILES) \
       $(U4_NOCK_OFILES) \
       $(U4_MILL_OFILES) \
       $(U4_MX_OFILES) \
       $(U4_MQ_OFILES) \
       $(U4_WATT_OFILES)

C_OFILES=\
       c/main.o \
       c/vere.o

L_OFILES=\
       l/manage.o \
       l/new.o \
       l/read.o

Z_OFILES=\
       z/jato.o \
       z/public.o \
       z/run.o \
       z/zeno.o 

J_OFILES=\
       j/dec.o \
       j/eq.o  \
       j/inc.o \
       j/pat.o \
       j/tap.o \
       j/zip.o \
       \
       j/add.o \
       j/div.o \
       j/gt.o  \
       j/gte.o \
       j/lt.o  \
       j/lte.o \
       j/mod.o \
       j/mul.o \
       j/sub.o \
       \
       j/mug.o

B_OFILES=\
       b/bunt.o

OFILES= \
       $(L_OFILES) \
       $(C_OFILES) \
       $(B_OFILES) \
       $(Z_OFILES) \
       $(J_OFILES) \
       $(U4_OFILES)

$(BIN)/vere: $(OFILES)
	$(CLD) -o $(BIN)/vere $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/vere

