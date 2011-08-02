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

J248_1_OFILES=\
       gen248/1/add.o \
       gen248/1/bex.o \
       gen248/1/dec.o \
       gen248/1/div.o \
       gen248/1/gte.o \
       gen248/1/gth.o \
       gen248/1/lte.o \
       gen248/1/lth.o \
       gen248/1/mod.o \
       gen248/1/mul.o \
       gen248/1/sub.o

J248_2_OFILES=\
       gen248/2/bind.o \
       gen248/2/clap.o \
       gen248/2/drop.o \
       gen248/2/flop.o \
       gen248/2/lent.o \
       gen248/2/levy.o \
       gen248/2/lien.o \
       gen248/2/need.o \
       gen248/2/reel.o \
       gen248/2/roll.o \
       gen248/2/skim.o \
       gen248/2/skip.o \
       gen248/2/slag.o \
       gen248/2/snag.o \
       gen248/2/sort.o \
       gen248/2/turn.o \
       gen248/2/weld.o

J248_3_OFILES=\
       gen248/3/can.o \
       gen248/3/cap.o \
       gen248/3/cat.o \
       gen248/3/con.o \
       gen248/3/cut.o \
       gen248/3/dor.o \
       gen248/3/dis.o \
       gen248/3/end.o \
       gen248/3/gor.o \
       gen248/3/hor.o \
       gen248/3/lsh.o \
       gen248/3/mas.o \
       gen248/3/met.o \
       gen248/3/mix.o \
       gen248/3/mug.o \
       gen248/3/peg.o \
       gen248/3/rap.o \
       gen248/3/rip.o \
       gen248/3/rsh.o \
       gen248/3/vor.o

J248_4_OFILES=\
       gen248/4/in.o \
       gen248/4/by.o \
       gen248/4/in_has.o \
       gen248/4/in_gas.o \
       gen248/4/in_put.o \
       gen248/4/in_tap.o \
       gen248/4/by_gas.o \
       gen248/4/by_get.o \
       gen248/4/by_has.o \
       gen248/4/by_put.o 

J248_5_OFILES=\
       gen248/5/cue.o \
       gen248/5/jam.o \
       gen248/5/mat.o \
       gen248/5/rub.o 

J248_6_OFILES=\
       gen248/6/ap.o \
       gen248/6/cell.o \
       gen248/6/comb.o \
       gen248/6/cons.o \
       gen248/6/core.o \
       gen248/6/cube.o \
       gen248/6/face.o \
       gen248/6/fine.o \
       gen248/6/flan.o \
       gen248/6/flip.o \
       gen248/6/flor.o \
       gen248/6/fork.o \
       gen248/6/hike.o \
       gen248/6/look.o \
       gen248/6/ream.o \
       gen248/6/ut.o

J248_6_OFILES_UT=\
       gen248/6/ut_bake.o \
       gen248/6/ut_burn.o \
       gen248/6/ut_cull.o \
       gen248/6/ut_emit.o \
       gen248/6/ut_find.o \
       gen248/6/ut_fire.o \
       gen248/6/ut_firm.o \
       gen248/6/ut_fish.o \
       gen248/6/ut_fret.o \
       gen248/6/ut_fuse.o \
       gen248/6/ut_gain.o \
       gen248/6/ut_heal.o \
       gen248/6/ut_mint.o \
       gen248/6/ut_orth.o \
       gen248/6/ut_nest.o \
       gen248/6/ut_park.o \
       gen248/6/ut_peek.o \
       gen248/6/ut_play.o \
       gen248/6/ut_repo.o \
       gen248/6/ut_rest.o \
       gen248/6/ut_seek.o \
       gen248/6/ut_snap.o \
       gen248/6/ut_tuck.o

J248_OFILES=\
       $(J248_1_OFILES) \
       $(J248_2_OFILES) \
       $(J248_3_OFILES) \
       $(J248_4_OFILES) \
       $(J248_5_OFILES) \
       $(J248_6_OFILES) \
       $(J248_6_OFILES_UT) \
       gen248/watt.o

J247_1_OFILES=\
       gen247/1/add.o \
       gen247/1/bex.o \
       gen247/1/dec.o \
       gen247/1/div.o \
       gen247/1/gte.o \
       gen247/1/gth.o \
       gen247/1/lte.o \
       gen247/1/lth.o \
       gen247/1/mod.o \
       gen247/1/mul.o \
       gen247/1/sub.o

J247_2_OFILES=\
       gen247/2/bind.o \
       gen247/2/clap.o \
       gen247/2/drop.o \
       gen247/2/flop.o \
       gen247/2/lent.o \
       gen247/2/levy.o \
       gen247/2/lien.o \
       gen247/2/need.o \
       gen247/2/reel.o \
       gen247/2/roll.o \
       gen247/2/skim.o \
       gen247/2/skip.o \
       gen247/2/slag.o \
       gen247/2/snag.o \
       gen247/2/sort.o \
       gen247/2/turn.o \
       gen247/2/weld.o

J247_3_OFILES=\
       gen247/3/can.o \
       gen247/3/cap.o \
       gen247/3/cat.o \
       gen247/3/con.o \
       gen247/3/cut.o \
       gen247/3/dor.o \
       gen247/3/dis.o \
       gen247/3/end.o \
       gen247/3/gor.o \
       gen247/3/hor.o \
       gen247/3/lsh.o \
       gen247/3/mas.o \
       gen247/3/met.o \
       gen247/3/mix.o \
       gen247/3/mug.o \
       gen247/3/peg.o \
       gen247/3/rap.o \
       gen247/3/rip.o \
       gen247/3/rsh.o \
       gen247/3/vor.o

J247_4_OFILES=\
       gen247/4/in.o \
       gen247/4/by.o \
       gen247/4/in_has.o \
       gen247/4/in_gas.o \
       gen247/4/in_put.o \
       gen247/4/in_tap.o \
       gen247/4/by_gas.o \
       gen247/4/by_get.o \
       gen247/4/by_has.o \
       gen247/4/by_put.o 

J247_5_OFILES=\
       gen247/5/cue.o \
       gen247/5/jam.o \
       gen247/5/mat.o \
       gen247/5/rub.o 

J247_6_OFILES=\
       gen247/6/ap.o \
       gen247/6/cell.o \
       gen247/6/comb.o \
       gen247/6/cons.o \
       gen247/6/core.o \
       gen247/6/cube.o \
       gen247/6/face.o \
       gen247/6/fine.o \
       gen247/6/flan.o \
       gen247/6/flip.o \
       gen247/6/flor.o \
       gen247/6/fork.o \
       gen247/6/hike.o \
       gen247/6/look.o \
       gen247/6/ream.o \
       gen247/6/ut.o

J247_6_OFILES_UT=\
       gen247/6/ut_bake.o \
       gen247/6/ut_burn.o \
       gen247/6/ut_cull.o \
       gen247/6/ut_emit.o \
       gen247/6/ut_find.o \
       gen247/6/ut_fire.o \
       gen247/6/ut_firm.o \
       gen247/6/ut_fish.o \
       gen247/6/ut_fret.o \
       gen247/6/ut_fuse.o \
       gen247/6/ut_gain.o \
       gen247/6/ut_heal.o \
       gen247/6/ut_mint.o \
       gen247/6/ut_orth.o \
       gen247/6/ut_nest.o \
       gen247/6/ut_park.o \
       gen247/6/ut_peek.o \
       gen247/6/ut_play.o \
       gen247/6/ut_repo.o \
       gen247/6/ut_rest.o \
       gen247/6/ut_seek.o \
       gen247/6/ut_snap.o \
       gen247/6/ut_tuck.o

J247_OFILES=\
       $(J247_1_OFILES) \
       $(J247_2_OFILES) \
       $(J247_3_OFILES) \
       $(J247_4_OFILES) \
       $(J247_5_OFILES) \
       $(J247_6_OFILES) \
       $(J247_6_OFILES_UT) \
       gen247/watt.o

EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J248_OFILES) \
       $(J247_OFILES)

all: $(BIN)/eyre

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
