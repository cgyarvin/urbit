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
CLD=gcc -g -bind_at_load -L/sw/lib
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU3_OS_$(OS) -DU3_OS_ENDIAN_$(ENDIAN)\
	-DU4_ENDIAN_$(ENDIAN) -DU4_OS_$(OS)
CFLAGS=-g -I/sw/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
CWFLAGS=-Wall

.y.o:
	 mkdir -p $(GENERATED)
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
       b/mill/edit.o \
       b/mill/eith.o \
       b/mill/fail.o \
       b/mill/find.o \
       b/mill/fire.o \
       b/mill/fish.o \
       b/mill/gate.o \
       b/mill/grip.o \
       b/mill/hike.o \
       b/mill/hunt.o \
       b/mill/init.o \
       b/mill/look.o \
       b/mill/lump.o \
       b/mill/make.o \
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
       b/mill/reap.o \
       b/mill/repo.o \
       b/mill/salt.o \
       b/mill/seal.o \
       b/mill/slip.o \
       b/mill/snap.o \
       b/mill/test.o \
       b/mill/trap.o

U4_MX_OFILES=\
       b/x/load.o \
       b/x/dbug.o \
       b/x/drag.o \
       b/x/name.o \
       b/x/like.o \
       b/x/kick.o \
       b/x/nock.o \
       b/x/cast.o \
       b/x/cage.o \
       b/x/home.o \
       b/x/rock.o \
       b/x/link.o \
       b/x/mang.o \
       b/x/spot.o \
       b/x/quiz.o \
       b/x/sure.o \
       b/x/bail.o 

U4_MQ_OFILES=\
       b/q/bink.o \
       b/q/blem.o \
       b/q/blin.o \
       b/q/boce.o \
       b/q/cell.o \
       b/q/colb.o \
       b/q/crad.o \
       b/q/dant.o \
       b/q/drol.o \
       b/q/feng.o \
       b/q/flic.o \
       b/q/flot.o \
       b/q/frag.o \
       b/q/garc.o \
       b/q/gleb.o \
       b/q/grad.o \
       b/q/gril.o \
       b/q/grun.o \
       b/q/lome.o \
       b/q/lorb.o \
       b/q/mang.o \
       b/q/marn.o \
       b/q/palt.o \
       b/q/parq.o \
       b/q/port.o \
       b/q/pont.o \
       b/q/prec.o \
       b/q/prox.o \
       b/q/qual.o \
       b/q/rack.o \
       b/q/rald.o \
       b/q/read.o \
       b/q/rulf.o \
       b/q/stam.o \
       b/q/trel.o \
       b/q/trop.o

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
       b/watt/plow.o \
       b/watt/dump.o \
       b/watt/grammar.o \
       b/watt/gull.o \
       b/watt/iris.o \
       b/watt/lark.o \
       b/watt/lily.o \
       b/watt/open.o \
       b/watt/rose.o

U4_OFILES= \
       $(U4_CAKE_OFILES) \
       $(U4_DISK_OFILES) \
       $(U4_FAKE_OFILES) \
       $(U4_LIB_OFILES) \
       $(U4_NOCK_OFILES) \
       $(U4_WATT_OFILES)

C_OFILES=\
       c/main.o \
       c/ford.o \
       c/mord.o

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
       j/add.o \
       j/bex.o \
       j/dec.o \
       j/div.o \
       j/gth.o \
       j/gte.o \
       j/lth.o \
       j/lte.o \
       j/mod.o \
       j/mul.o \
       j/sub.o \
       \
       j/mug.o \
       \
       j/make.o	\
       j/mill.o \
       j/pass.o	\
       j/play.o	\
       j/read.o \
       j/shop.o	\
       j/show.o	\
       j/wish.o

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
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/vere $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/vere

