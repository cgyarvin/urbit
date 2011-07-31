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
CLD=gcc -O3 -L/sw/lib
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU2_OS_$(OS) -DU2_OS_ENDIAN_$(ENDIAN)
CFLAGS=-O3 -I/sw/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
CWFLAGS=-Wall

.y.o:
	 mkdir -p $(GENERATED)
	 $(YACC) $<
	 $(CC) -c $(CFLAGS) -o $@ $(GENERATED)/y.tab.c
	 $(RM) $(GENERATED)/y.tab.c

.c.o:
	 $(CC) -c $(CWFLAGS) $(CFLAGS) -o $@ $<

C_OFILES=\
       c/comd.o

F_OFILES=\
       f/rail.o \
       f/loom.o \
       f/wire.o \
       f/chad.o \
       f/cash.o \
       f/host.o \
       f/benx.o \
       f/bail.o \
       f/bask.o \
       f/dash.o \
       f/unix.o \
       f/nock.o

P_OFILES=\
       p/book.o \
       p/list.o \
       p/pool.o \
       p/prep.o \
       p/saur.o

J250_1_OFILES=\
       gen250/1/add.o \
       gen250/1/bex.o \
       gen250/1/dec.o \
       gen250/1/div.o \
       gen250/1/gte.o \
       gen250/1/gth.o \
       gen250/1/lte.o \
       gen250/1/lth.o \
       gen250/1/mod.o \
       gen250/1/mul.o \
       gen250/1/sub.o

J250_2_OFILES=\
       gen250/2/bind.o \
       gen250/2/clap.o \
       gen250/2/drop.o \
       gen250/2/flop.o \
       gen250/2/lent.o \
       gen250/2/levy.o \
       gen250/2/lien.o \
       gen250/2/need.o \
       gen250/2/reel.o \
       gen250/2/roll.o \
       gen250/2/skim.o \
       gen250/2/skip.o \
       gen250/2/slag.o \
       gen250/2/snag.o \
       gen250/2/sort.o \
       gen250/2/turn.o \
       gen250/2/weld.o

J250_3_OFILES=\
       gen250/3/can.o \
       gen250/3/cap.o \
       gen250/3/cat.o \
       gen250/3/con.o \
       gen250/3/cut.o \
       gen250/3/dor.o \
       gen250/3/dis.o \
       gen250/3/end.o \
       gen250/3/gor.o \
       gen250/3/hor.o \
       gen250/3/lsh.o \
       gen250/3/mas.o \
       gen250/3/met.o \
       gen250/3/mix.o \
       gen250/3/mug.o \
       gen250/3/peg.o \
       gen250/3/rap.o \
       gen250/3/rip.o \
       gen250/3/rsh.o \
       gen250/3/vor.o

J250_4_OFILES=\
       gen250/4/in.o \
       gen250/4/by.o \
       gen250/4/in_has.o \
       gen250/4/in_gas.o \
       gen250/4/in_put.o \
       gen250/4/in_tap.o \
       gen250/4/by_gas.o \
       gen250/4/by_get.o \
       gen250/4/by_has.o \
       gen250/4/by_put.o 

J250_5_OFILES=\
       gen250/5/cue.o \
       gen250/5/jam.o \
       gen250/5/mat.o \
       gen250/5/rub.o 

J250_6_OFILES=\
       gen250/6/ap.o \
       gen250/6/cell.o \
       gen250/6/comb.o \
       gen250/6/cons.o \
       gen250/6/core.o \
       gen250/6/cube.o \
       gen250/6/face.o \
       gen250/6/fine.o \
       gen250/6/flan.o \
       gen250/6/flip.o \
       gen250/6/flor.o \
       gen250/6/fork.o \
       gen250/6/hike.o \
       gen250/6/look.o \
       gen250/6/ream.o \
       gen250/6/ut.o

J250_6_OFILES_UT=\
       gen250/6/ut_bake.o \
       gen250/6/ut_burn.o \
       gen250/6/ut_cull.o \
       gen250/6/ut_emit.o \
       gen250/6/ut_find.o \
       gen250/6/ut_fire.o \
       gen250/6/ut_firm.o \
       gen250/6/ut_fish.o \
       gen250/6/ut_fret.o \
       gen250/6/ut_fuse.o \
       gen250/6/ut_gain.o \
       gen250/6/ut_heal.o \
       gen250/6/ut_mint.o \
       gen250/6/ut_orth.o \
       gen250/6/ut_nest.o \
       gen250/6/ut_park.o \
       gen250/6/ut_peek.o \
       gen250/6/ut_play.o \
       gen250/6/ut_repo.o \
       gen250/6/ut_rest.o \
       gen250/6/ut_seek.o \
       gen250/6/ut_snap.o \
       gen250/6/ut_tuck.o

J250_OFILES=\
       $(J250_1_OFILES) \
       $(J250_2_OFILES) \
       $(J250_3_OFILES) \
       $(J250_4_OFILES) \
       $(J250_5_OFILES) \
       $(J250_6_OFILES) \
       $(J250_6_OFILES_UT) \
       gen250/watt.o

J249_1_OFILES=\
       gen249/1/add.o \
       gen249/1/bex.o \
       gen249/1/dec.o \
       gen249/1/div.o \
       gen249/1/gte.o \
       gen249/1/gth.o \
       gen249/1/lte.o \
       gen249/1/lth.o \
       gen249/1/mod.o \
       gen249/1/mul.o \
       gen249/1/sub.o

J249_2_OFILES=\
       gen249/2/bind.o \
       gen249/2/clap.o \
       gen249/2/drop.o \
       gen249/2/flop.o \
       gen249/2/lent.o \
       gen249/2/levy.o \
       gen249/2/lien.o \
       gen249/2/need.o \
       gen249/2/reel.o \
       gen249/2/roll.o \
       gen249/2/skim.o \
       gen249/2/skip.o \
       gen249/2/slag.o \
       gen249/2/snag.o \
       gen249/2/sort.o \
       gen249/2/turn.o \
       gen249/2/weld.o

J249_3_OFILES=\
       gen249/3/can.o \
       gen249/3/cap.o \
       gen249/3/cat.o \
       gen249/3/con.o \
       gen249/3/cut.o \
       gen249/3/dor.o \
       gen249/3/dis.o \
       gen249/3/end.o \
       gen249/3/gor.o \
       gen249/3/hor.o \
       gen249/3/lsh.o \
       gen249/3/mas.o \
       gen249/3/met.o \
       gen249/3/mix.o \
       gen249/3/mug.o \
       gen249/3/peg.o \
       gen249/3/rap.o \
       gen249/3/rip.o \
       gen249/3/rsh.o \
       gen249/3/vor.o

J249_4_OFILES=\
       gen249/4/in.o \
       gen249/4/by.o \
       gen249/4/in_has.o \
       gen249/4/in_gas.o \
       gen249/4/in_put.o \
       gen249/4/in_tap.o \
       gen249/4/by_gas.o \
       gen249/4/by_get.o \
       gen249/4/by_has.o \
       gen249/4/by_put.o 

J249_5_OFILES=\
       gen249/5/cue.o \
       gen249/5/jam.o \
       gen249/5/mat.o \
       gen249/5/rub.o 

J249_6_OFILES=\
       gen249/6/ap.o \
       gen249/6/cell.o \
       gen249/6/comb.o \
       gen249/6/cons.o \
       gen249/6/core.o \
       gen249/6/cube.o \
       gen249/6/face.o \
       gen249/6/fine.o \
       gen249/6/flan.o \
       gen249/6/flip.o \
       gen249/6/flor.o \
       gen249/6/fork.o \
       gen249/6/hike.o \
       gen249/6/look.o \
       gen249/6/ream.o \
       gen249/6/ut.o

J249_6_OFILES_UT=\
       gen249/6/ut_bake.o \
       gen249/6/ut_burn.o \
       gen249/6/ut_cull.o \
       gen249/6/ut_emit.o \
       gen249/6/ut_find.o \
       gen249/6/ut_fire.o \
       gen249/6/ut_firm.o \
       gen249/6/ut_fish.o \
       gen249/6/ut_fret.o \
       gen249/6/ut_fuse.o \
       gen249/6/ut_gain.o \
       gen249/6/ut_heal.o \
       gen249/6/ut_mint.o \
       gen249/6/ut_orth.o \
       gen249/6/ut_nest.o \
       gen249/6/ut_park.o \
       gen249/6/ut_peek.o \
       gen249/6/ut_play.o \
       gen249/6/ut_repo.o \
       gen249/6/ut_rest.o \
       gen249/6/ut_seek.o \
       gen249/6/ut_snap.o \
       gen249/6/ut_tuck.o

J249_OFILES=\
       $(J249_1_OFILES) \
       $(J249_2_OFILES) \
       $(J249_3_OFILES) \
       $(J249_4_OFILES) \
       $(J249_5_OFILES) \
       $(J249_6_OFILES) \
       $(J249_6_OFILES_UT) \
       gen249/watt.o

EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J250_OFILES) \
       $(J249_OFILES)

all: $(BIN)/eyre

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
