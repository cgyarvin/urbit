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
BIN=bin

RM=rm -f
CC=gcc
#CLD=gcc -g -L/sw/lib
CLD=gcc -g
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU2_OS_$(OS) -DU2_OS_ENDIAN_$(ENDIAN)
CFLAGS=-g -I/sw/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
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
       f/trac.o \
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

J228_1_OFILES=\
       gen228/1/add.o \
       gen228/1/bex.o \
       gen228/1/dec.o \
       gen228/1/div.o \
       gen228/1/gte.o \
       gen228/1/gth.o \
       gen228/1/lte.o \
       gen228/1/lth.o \
       gen228/1/mod.o \
       gen228/1/mul.o \
       gen228/1/sub.o

J228_2_OFILES=\
       gen228/2/bind.o \
       gen228/2/clap.o \
       gen228/2/drop.o \
       gen228/2/flop.o \
       gen228/2/lent.o \
       gen228/2/levy.o \
       gen228/2/lien.o \
       gen228/2/need.o \
       gen228/2/reel.o \
       gen228/2/roll.o \
       gen228/2/skim.o \
       gen228/2/skip.o \
       gen228/2/slag.o \
       gen228/2/snag.o \
       gen228/2/sort.o \
       gen228/2/turn.o \
       gen228/2/weld.o

J228_3_OFILES=\
       gen228/3/can.o \
       gen228/3/cap.o \
       gen228/3/cat.o \
       gen228/3/con.o \
       gen228/3/cut.o \
       gen228/3/dor.o \
       gen228/3/dis.o \
       gen228/3/end.o \
       gen228/3/gor.o \
       gen228/3/hor.o \
       gen228/3/lsh.o \
       gen228/3/mas.o \
       gen228/3/met.o \
       gen228/3/mix.o \
       gen228/3/mug.o \
       gen228/3/peg.o \
       gen228/3/rap.o \
       gen228/3/rip.o \
       gen228/3/rsh.o \
       gen228/3/vor.o

J228_4_OFILES=\
       gen228/4/in.o \
       gen228/4/by.o \
       gen228/4/in_has.o \
       gen228/4/in_gas.o \
       gen228/4/in_put.o \
       gen228/4/in_tap.o \
       gen228/4/by_gas.o \
       gen228/4/by_get.o \
       gen228/4/by_has.o \
       gen228/4/by_put.o 

J228_5_OFILES=\
       gen228/5/cue.o \
       gen228/5/jam.o \
       gen228/5/mat.o \
       gen228/5/rub.o \
       gen228/5/trip.o

J228_6_OFILES=\
       gen228/6/ap.o \
       gen228/6/cell.o \
       gen228/6/comb.o \
       gen228/6/cons.o \
       gen228/6/core.o \
       gen228/6/cube.o \
       gen228/6/face.o \
       gen228/6/fine.o \
       gen228/6/flan.o \
       gen228/6/flip.o \
       gen228/6/flor.o \
       gen228/6/foam.o \
       gen228/6/fork.o \
       gen228/6/hike.o \
       gen228/6/look.o \
       gen228/6/ream.o \
       gen228/6/ut.o

J228_6_OFILES_UT=\
       gen228/6/ut_burn.o \
       gen228/6/ut_bust.o \
       gen228/6/ut_crop.o \
       gen228/6/ut_cull.o \
       gen228/6/ut_find.o \
       gen228/6/ut_fink.o \
       gen228/6/ut_fire.o \
       gen228/6/ut_firm.o \
       gen228/6/ut_fish.o \
       gen228/6/ut_fuse.o \
       gen228/6/ut_gain.o \
       gen228/6/ut_heal.o \
       gen228/6/ut_lose.o \
       gen228/6/ut_mint.o \
       gen228/6/ut_mull.o \
       gen228/6/ut_nest.o \
       gen228/6/ut_orth.o \
       gen228/6/ut_park.o \
       gen228/6/ut_peek.o \
       gen228/6/ut_play.o \
       gen228/6/ut_repo.o \
       gen228/6/ut_rest.o \
       gen228/6/ut_seek.o \
       gen228/6/ut_snap.o \
       gen228/6/ut_swab.o \
       gen228/6/ut_tack.o \
       gen228/6/ut_tock.o

J228_OFILES=\
       $(J228_1_OFILES) \
       $(J228_2_OFILES) \
       $(J228_3_OFILES) \
       $(J228_4_OFILES) \
       $(J228_5_OFILES) \
       $(J228_6_OFILES) \
       $(J228_6_OFILES_UT) \
       gen228/watt.o

J227_1_OFILES=\
       gen227/1/add.o \
       gen227/1/bex.o \
       gen227/1/dec.o \
       gen227/1/div.o \
       gen227/1/gte.o \
       gen227/1/gth.o \
       gen227/1/lte.o \
       gen227/1/lth.o \
       gen227/1/mod.o \
       gen227/1/mul.o \
       gen227/1/sub.o

J227_2_OFILES=\
       gen227/2/bind.o \
       gen227/2/clap.o \
       gen227/2/drop.o \
       gen227/2/flop.o \
       gen227/2/lent.o \
       gen227/2/levy.o \
       gen227/2/lien.o \
       gen227/2/need.o \
       gen227/2/reel.o \
       gen227/2/roll.o \
       gen227/2/skim.o \
       gen227/2/skip.o \
       gen227/2/slag.o \
       gen227/2/snag.o \
       gen227/2/sort.o \
       gen227/2/turn.o \
       gen227/2/weld.o

J227_3_OFILES=\
       gen227/3/can.o \
       gen227/3/cap.o \
       gen227/3/cat.o \
       gen227/3/con.o \
       gen227/3/cut.o \
       gen227/3/dor.o \
       gen227/3/dis.o \
       gen227/3/end.o \
       gen227/3/gor.o \
       gen227/3/hor.o \
       gen227/3/lsh.o \
       gen227/3/mas.o \
       gen227/3/met.o \
       gen227/3/mix.o \
       gen227/3/mug.o \
       gen227/3/peg.o \
       gen227/3/rap.o \
       gen227/3/rip.o \
       gen227/3/rsh.o \
       gen227/3/vor.o

J227_4_OFILES=\
       gen227/4/in.o \
       gen227/4/by.o \
       gen227/4/in_has.o \
       gen227/4/in_gas.o \
       gen227/4/in_put.o \
       gen227/4/in_tap.o \
       gen227/4/by_gas.o \
       gen227/4/by_get.o \
       gen227/4/by_has.o \
       gen227/4/by_put.o 

J227_5_OFILES=\
       gen227/5/cue.o \
       gen227/5/jam.o \
       gen227/5/mat.o \
       gen227/5/rub.o \
       gen227/5/trip.o

J227_6_OFILES=\
       gen227/6/ap.o \
       gen227/6/cell.o \
       gen227/6/comb.o \
       gen227/6/cons.o \
       gen227/6/core.o \
       gen227/6/cube.o \
       gen227/6/face.o \
       gen227/6/fine.o \
       gen227/6/flan.o \
       gen227/6/flip.o \
       gen227/6/flor.o \
       gen227/6/foam.o \
       gen227/6/fork.o \
       gen227/6/hike.o \
       gen227/6/look.o \
       gen227/6/ream.o \
       gen227/6/ut.o

J227_6_OFILES_UT=\
       gen227/6/ut_burn.o \
       gen227/6/ut_bust.o \
       gen227/6/ut_crop.o \
       gen227/6/ut_cull.o \
       gen227/6/ut_find.o \
       gen227/6/ut_fink.o \
       gen227/6/ut_fire.o \
       gen227/6/ut_firm.o \
       gen227/6/ut_fish.o \
       gen227/6/ut_fuse.o \
       gen227/6/ut_gain.o \
       gen227/6/ut_heal.o \
       gen227/6/ut_lose.o \
       gen227/6/ut_mint.o \
       gen227/6/ut_moot.o \
       gen227/6/ut_mull.o \
       gen227/6/ut_nest.o \
       gen227/6/ut_park.o \
       gen227/6/ut_peek.o \
       gen227/6/ut_play.o \
       gen227/6/ut_repo.o \
       gen227/6/ut_rest.o \
       gen227/6/ut_seek.o \
       gen227/6/ut_snap.o \
       gen227/6/ut_swab.o \
       gen227/6/ut_tack.o \
       gen227/6/ut_tock.o

J227_OFILES=\
       $(J227_1_OFILES) \
       $(J227_2_OFILES) \
       $(J227_3_OFILES) \
       $(J227_4_OFILES) \
       $(J227_5_OFILES) \
       $(J227_6_OFILES) \
       $(J227_6_OFILES_UT) \
       gen227/watt.o

J226_1_OFILES=\
       gen226/1/add.o \
       gen226/1/bex.o \
       gen226/1/dec.o \
       gen226/1/div.o \
       gen226/1/gte.o \
       gen226/1/gth.o \
       gen226/1/lte.o \
       gen226/1/lth.o \
       gen226/1/mod.o \
       gen226/1/mul.o \
       gen226/1/sub.o

J226_2_OFILES=\
       gen226/2/bind.o \
       gen226/2/clap.o \
       gen226/2/drop.o \
       gen226/2/flop.o \
       gen226/2/lent.o \
       gen226/2/levy.o \
       gen226/2/lien.o \
       gen226/2/need.o \
       gen226/2/reel.o \
       gen226/2/roll.o \
       gen226/2/skim.o \
       gen226/2/skip.o \
       gen226/2/slag.o \
       gen226/2/snag.o \
       gen226/2/sort.o \
       gen226/2/turn.o \
       gen226/2/weld.o

J226_3_OFILES=\
       gen226/3/can.o \
       gen226/3/cap.o \
       gen226/3/cat.o \
       gen226/3/con.o \
       gen226/3/cut.o \
       gen226/3/dor.o \
       gen226/3/dis.o \
       gen226/3/end.o \
       gen226/3/gor.o \
       gen226/3/hor.o \
       gen226/3/lsh.o \
       gen226/3/mas.o \
       gen226/3/met.o \
       gen226/3/mix.o \
       gen226/3/mug.o \
       gen226/3/peg.o \
       gen226/3/rap.o \
       gen226/3/rip.o \
       gen226/3/rsh.o \
       gen226/3/vor.o

J226_4_OFILES=\
       gen226/4/in.o \
       gen226/4/by.o \
       gen226/4/in_has.o \
       gen226/4/in_gas.o \
       gen226/4/in_put.o \
       gen226/4/in_tap.o \
       gen226/4/by_gas.o \
       gen226/4/by_get.o \
       gen226/4/by_has.o \
       gen226/4/by_put.o 

J226_5_OFILES=\
       gen226/5/cue.o \
       gen226/5/jam.o \
       gen226/5/mat.o \
       gen226/5/parse.o \
       gen226/5/rub.o \
       gen226/5/trip.o

J226_6_OFILES=\
       gen226/6/ap.o \
       gen226/6/cell.o \
       gen226/6/comb.o \
       gen226/6/cons.o \
       gen226/6/core.o \
       gen226/6/cube.o \
       gen226/6/face.o \
       gen226/6/fine.o \
       gen226/6/flan.o \
       gen226/6/flip.o \
       gen226/6/flor.o \
       gen226/6/foam.o \
       gen226/6/fork.o \
       gen226/6/hike.o \
       gen226/6/look.o \
       gen226/6/ut.o

J226_6_OFILES_UT=\
       gen226/6/ut_burn.o \
       gen226/6/ut_bust.o \
       gen226/6/ut_crop.o \
       gen226/6/ut_cull.o \
       gen226/6/ut_find.o \
       gen226/6/ut_fink.o \
       gen226/6/ut_fire.o \
       gen226/6/ut_firm.o \
       gen226/6/ut_fish.o \
       gen226/6/ut_fuse.o \
       gen226/6/ut_gain.o \
       gen226/6/ut_heal.o \
       gen226/6/ut_lose.o \
       gen226/6/ut_mint.o \
       gen226/6/ut_moot.o \
       gen226/6/ut_mull.o \
       gen226/6/ut_nest.o \
       gen226/6/ut_park.o \
       gen226/6/ut_peek.o \
       gen226/6/ut_play.o \
       gen226/6/ut_repo.o \
       gen226/6/ut_rest.o \
       gen226/6/ut_seek.o \
       gen226/6/ut_snap.o \
       gen226/6/ut_swab.o \
       gen226/6/ut_tack.o \
       gen226/6/ut_tock.o

J226_OFILES=\
       $(J226_1_OFILES) \
       $(J226_2_OFILES) \
       $(J226_3_OFILES) \
       $(J226_4_OFILES) \
       $(J226_5_OFILES) \
       $(J226_6_OFILES) \
       $(J226_6_OFILES_UT) \
       gen226/watt.o

J225_1_OFILES=\
       gen225/1/add.o \
       gen225/1/bex.o \
       gen225/1/dec.o \
       gen225/1/div.o \
       gen225/1/gte.o \
       gen225/1/gth.o \
       gen225/1/lte.o \
       gen225/1/lth.o \
       gen225/1/mod.o \
       gen225/1/mul.o \
       gen225/1/sub.o

J225_2_OFILES=\
       gen225/2/bind.o \
       gen225/2/clap.o \
       gen225/2/drop.o \
       gen225/2/flop.o \
       gen225/2/lent.o \
       gen225/2/levy.o \
       gen225/2/lien.o \
       gen225/2/need.o \
       gen225/2/reel.o \
       gen225/2/roll.o \
       gen225/2/skim.o \
       gen225/2/skip.o \
       gen225/2/slag.o \
       gen225/2/snag.o \
       gen225/2/sort.o \
       gen225/2/turn.o \
       gen225/2/weld.o

J225_3_OFILES=\
       gen225/3/can.o \
       gen225/3/cap.o \
       gen225/3/cat.o \
       gen225/3/con.o \
       gen225/3/cut.o \
       gen225/3/dor.o \
       gen225/3/dis.o \
       gen225/3/end.o \
       gen225/3/gor.o \
       gen225/3/hor.o \
       gen225/3/lsh.o \
       gen225/3/mas.o \
       gen225/3/met.o \
       gen225/3/mix.o \
       gen225/3/mug.o \
       gen225/3/peg.o \
       gen225/3/rap.o \
       gen225/3/rip.o \
       gen225/3/rsh.o \
       gen225/3/vor.o

J225_4_OFILES=\
       gen225/4/in.o \
       gen225/4/by.o \
       gen225/4/in_has.o \
       gen225/4/in_gas.o \
       gen225/4/in_put.o \
       gen225/4/in_tap.o \
       gen225/4/by_gas.o \
       gen225/4/by_get.o \
       gen225/4/by_has.o \
       gen225/4/by_put.o 

J225_5_OFILES=\
       gen225/5/cue.o \
       gen225/5/jam.o \
       gen225/5/mat.o \
       gen225/5/parse.o \
       gen225/5/rub.o \
       gen225/5/trip.o

J225_6_OFILES=\
       gen225/6/ap.o \
       gen225/6/cell.o \
       gen225/6/comb.o \
       gen225/6/cons.o \
       gen225/6/core.o \
       gen225/6/cube.o \
       gen225/6/face.o \
       gen225/6/fine.o \
       gen225/6/flan.o \
       gen225/6/flip.o \
       gen225/6/flor.o \
       gen225/6/foam.o \
       gen225/6/fork.o \
       gen225/6/hike.o \
       gen225/6/look.o \
       gen225/6/ut.o

J225_6_OFILES_UT=\
       gen225/6/ut_burn.o \
       gen225/6/ut_bust.o \
       gen225/6/ut_crop.o \
       gen225/6/ut_cull.o \
       gen225/6/ut_find.o \
       gen225/6/ut_fink.o \
       gen225/6/ut_fire.o \
       gen225/6/ut_firm.o \
       gen225/6/ut_fish.o \
       gen225/6/ut_fuse.o \
       gen225/6/ut_gain.o \
       gen225/6/ut_heal.o \
       gen225/6/ut_lose.o \
       gen225/6/ut_mint.o \
       gen225/6/ut_moot.o \
       gen225/6/ut_mull.o \
       gen225/6/ut_nest.o \
       gen225/6/ut_park.o \
       gen225/6/ut_peek.o \
       gen225/6/ut_play.o \
       gen225/6/ut_repo.o \
       gen225/6/ut_rest.o \
       gen225/6/ut_seek.o \
       gen225/6/ut_snap.o \
       gen225/6/ut_swab.o \
       gen225/6/ut_tack.o \
       gen225/6/ut_tock.o

J225_OFILES=\
       $(J225_1_OFILES) \
       $(J225_2_OFILES) \
       $(J225_3_OFILES) \
       $(J225_4_OFILES) \
       $(J225_5_OFILES) \
       $(J225_6_OFILES) \
       $(J225_6_OFILES_UT) \
       gen225/watt.o

EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J228_OFILES) \
       $(J227_OFILES) \
       $(J226_OFILES) \
       $(J225_OFILES)

all: $(BIN)/eyre

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
