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

J246_1_OFILES=\
       gen246/1/add.o \
       gen246/1/bex.o \
       gen246/1/dec.o \
       gen246/1/div.o \
       gen246/1/gte.o \
       gen246/1/gth.o \
       gen246/1/lte.o \
       gen246/1/lth.o \
       gen246/1/mod.o \
       gen246/1/mul.o \
       gen246/1/sub.o

J246_2_OFILES=\
       gen246/2/bind.o \
       gen246/2/clap.o \
       gen246/2/drop.o \
       gen246/2/flop.o \
       gen246/2/lent.o \
       gen246/2/levy.o \
       gen246/2/lien.o \
       gen246/2/need.o \
       gen246/2/reel.o \
       gen246/2/roll.o \
       gen246/2/skim.o \
       gen246/2/skip.o \
       gen246/2/slag.o \
       gen246/2/snag.o \
       gen246/2/sort.o \
       gen246/2/turn.o \
       gen246/2/weld.o

J246_3_OFILES=\
       gen246/3/can.o \
       gen246/3/cap.o \
       gen246/3/cat.o \
       gen246/3/con.o \
       gen246/3/cut.o \
       gen246/3/dor.o \
       gen246/3/dis.o \
       gen246/3/end.o \
       gen246/3/gor.o \
       gen246/3/hor.o \
       gen246/3/lsh.o \
       gen246/3/mas.o \
       gen246/3/met.o \
       gen246/3/mix.o \
       gen246/3/mug.o \
       gen246/3/peg.o \
       gen246/3/rap.o \
       gen246/3/rip.o \
       gen246/3/rsh.o \
       gen246/3/vor.o

J246_4_OFILES=\
       gen246/4/in.o \
       gen246/4/by.o \
       gen246/4/in_has.o \
       gen246/4/in_gas.o \
       gen246/4/in_put.o \
       gen246/4/in_tap.o \
       gen246/4/by_gas.o \
       gen246/4/by_get.o \
       gen246/4/by_has.o \
       gen246/4/by_put.o 

J246_5_OFILES=\
       gen246/5/cue.o \
       gen246/5/jam.o \
       gen246/5/mat.o \
       gen246/5/rub.o 

J246_6_OFILES=\
       gen246/6/ap.o \
       gen246/6/cell.o \
       gen246/6/comb.o \
       gen246/6/cons.o \
       gen246/6/core.o \
       gen246/6/cube.o \
       gen246/6/face.o \
       gen246/6/fine.o \
       gen246/6/flan.o \
       gen246/6/flip.o \
       gen246/6/flor.o \
       gen246/6/fork.o \
       gen246/6/hike.o \
       gen246/6/look.o \
       gen246/6/ream.o \
       gen246/6/ut.o

J246_6_OFILES_UT=\
       gen246/6/ut_bake.o \
       gen246/6/ut_burn.o \
       gen246/6/ut_cull.o \
       gen246/6/ut_emit.o \
       gen246/6/ut_find.o \
       gen246/6/ut_fire.o \
       gen246/6/ut_firm.o \
       gen246/6/ut_fish.o \
       gen246/6/ut_fret.o \
       gen246/6/ut_fuse.o \
       gen246/6/ut_gain.o \
       gen246/6/ut_heal.o \
       gen246/6/ut_mint.o \
       gen246/6/ut_orth.o \
       gen246/6/ut_nest.o \
       gen246/6/ut_park.o \
       gen246/6/ut_peek.o \
       gen246/6/ut_play.o \
       gen246/6/ut_repo.o \
       gen246/6/ut_rest.o \
       gen246/6/ut_seek.o \
       gen246/6/ut_snap.o \
       gen246/6/ut_tuck.o

J246_OFILES=\
       $(J246_1_OFILES) \
       $(J246_2_OFILES) \
       $(J246_3_OFILES) \
       $(J246_4_OFILES) \
       $(J246_5_OFILES) \
       $(J246_6_OFILES) \
       $(J246_6_OFILES_UT) \
       gen246/watt.o

J245_1_OFILES=\
       gen245/1/add.o \
       gen245/1/bex.o \
       gen245/1/dec.o \
       gen245/1/div.o \
       gen245/1/gte.o \
       gen245/1/gth.o \
       gen245/1/lte.o \
       gen245/1/lth.o \
       gen245/1/mod.o \
       gen245/1/mul.o \
       gen245/1/sub.o

J245_2_OFILES=\
       gen245/2/bind.o \
       gen245/2/clap.o \
       gen245/2/drop.o \
       gen245/2/flop.o \
       gen245/2/lent.o \
       gen245/2/levy.o \
       gen245/2/lien.o \
       gen245/2/need.o \
       gen245/2/reel.o \
       gen245/2/roll.o \
       gen245/2/skim.o \
       gen245/2/skip.o \
       gen245/2/slag.o \
       gen245/2/snag.o \
       gen245/2/sort.o \
       gen245/2/turn.o \
       gen245/2/weld.o

J245_3_OFILES=\
       gen245/3/can.o \
       gen245/3/cap.o \
       gen245/3/cat.o \
       gen245/3/con.o \
       gen245/3/cut.o \
       gen245/3/dor.o \
       gen245/3/dis.o \
       gen245/3/end.o \
       gen245/3/gor.o \
       gen245/3/hor.o \
       gen245/3/lsh.o \
       gen245/3/mas.o \
       gen245/3/met.o \
       gen245/3/mix.o \
       gen245/3/mug.o \
       gen245/3/peg.o \
       gen245/3/rap.o \
       gen245/3/rip.o \
       gen245/3/rsh.o \
       gen245/3/vor.o

J245_4_OFILES=\
       gen245/4/in.o \
       gen245/4/by.o \
       gen245/4/in_has.o \
       gen245/4/in_gas.o \
       gen245/4/in_put.o \
       gen245/4/in_tap.o \
       gen245/4/by_gas.o \
       gen245/4/by_get.o \
       gen245/4/by_has.o \
       gen245/4/by_put.o 

J245_5_OFILES=\
       gen245/5/cue.o \
       gen245/5/jam.o \
       gen245/5/mat.o \
       gen245/5/rub.o 

J245_6_OFILES=\
       gen245/6/ap.o \
       gen245/6/cell.o \
       gen245/6/comb.o \
       gen245/6/cons.o \
       gen245/6/core.o \
       gen245/6/cube.o \
       gen245/6/face.o \
       gen245/6/fine.o \
       gen245/6/flan.o \
       gen245/6/flip.o \
       gen245/6/flor.o \
       gen245/6/fork.o \
       gen245/6/hike.o \
       gen245/6/look.o \
       gen245/6/ream.o \
       gen245/6/ut.o

J245_6_OFILES_UT=\
       gen245/6/ut_bake.o \
       gen245/6/ut_burn.o \
       gen245/6/ut_cull.o \
       gen245/6/ut_emit.o \
       gen245/6/ut_find.o \
       gen245/6/ut_fire.o \
       gen245/6/ut_firm.o \
       gen245/6/ut_fish.o \
       gen245/6/ut_fret.o \
       gen245/6/ut_fuse.o \
       gen245/6/ut_gain.o \
       gen245/6/ut_heal.o \
       gen245/6/ut_mint.o \
       gen245/6/ut_odor.o \
       gen245/6/ut_orth.o \
       gen245/6/ut_nest.o \
       gen245/6/ut_park.o \
       gen245/6/ut_peek.o \
       gen245/6/ut_play.o \
       gen245/6/ut_repo.o \
       gen245/6/ut_rest.o \
       gen245/6/ut_seek.o \
       gen245/6/ut_snap.o \
       gen245/6/ut_tuck.o

J245_OFILES=\
       $(J245_1_OFILES) \
       $(J245_2_OFILES) \
       $(J245_3_OFILES) \
       $(J245_4_OFILES) \
       $(J245_5_OFILES) \
       $(J245_6_OFILES) \
       $(J245_6_OFILES_UT) \
       gen245/watt.o


EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J246_OFILES) \
       $(J245_OFILES)

all: $(BIN)/eyre

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
