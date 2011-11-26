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
#CLD=gcc -O3 -L/sw/lib
CLD=gcc -O3
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

J230_1_OFILES=\
       gen230/1/add.o \
       gen230/1/bex.o \
       gen230/1/dec.o \
       gen230/1/div.o \
       gen230/1/gte.o \
       gen230/1/gth.o \
       gen230/1/lte.o \
       gen230/1/lth.o \
       gen230/1/mod.o \
       gen230/1/mul.o \
       gen230/1/sub.o

J230_2_OFILES=\
       gen230/2/bind.o \
       gen230/2/clap.o \
       gen230/2/drop.o \
       gen230/2/flop.o \
       gen230/2/lent.o \
       gen230/2/levy.o \
       gen230/2/lien.o \
       gen230/2/need.o \
       gen230/2/reel.o \
       gen230/2/roll.o \
       gen230/2/skim.o \
       gen230/2/skip.o \
       gen230/2/slag.o \
       gen230/2/snag.o \
       gen230/2/sort.o \
       gen230/2/turn.o \
       gen230/2/weld.o

J230_3_OFILES=\
       gen230/3/can.o \
       gen230/3/cap.o \
       gen230/3/cat.o \
       gen230/3/con.o \
       gen230/3/cut.o \
       gen230/3/dor.o \
       gen230/3/dis.o \
       gen230/3/end.o \
       gen230/3/gor.o \
       gen230/3/hor.o \
       gen230/3/lsh.o \
       gen230/3/mas.o \
       gen230/3/met.o \
       gen230/3/mix.o \
       gen230/3/mug.o \
       gen230/3/peg.o \
       gen230/3/rap.o \
       gen230/3/rip.o \
       gen230/3/rsh.o \
       gen230/3/vor.o

J230_4_OFILES=\
       gen230/4/in.o \
       gen230/4/by.o \
       gen230/4/in_has.o \
       gen230/4/in_gas.o \
       gen230/4/in_put.o \
       gen230/4/in_tap.o \
       gen230/4/by_gas.o \
       gen230/4/by_get.o \
       gen230/4/by_has.o \
       gen230/4/by_put.o 

J230_5_OFILES=\
       gen230/5/cue.o \
       gen230/5/jam.o \
       gen230/5/mat.o \
       gen230/5/rub.o \
       gen230/5/trip.o

J230_6_OFILES=\
       gen230/6/ap.o \
       gen230/6/cell.o \
       gen230/6/comb.o \
       gen230/6/cons.o \
       gen230/6/core.o \
       gen230/6/cube.o \
       gen230/6/face.o \
       gen230/6/fine.o \
       gen230/6/flan.o \
       gen230/6/flip.o \
       gen230/6/flor.o \
       gen230/6/foam.o \
       gen230/6/fork.o \
       gen230/6/hike.o \
       gen230/6/look.o \
       gen230/6/ream.o \
       gen230/6/ut.o

J230_6_OFILES_UT=\
       gen230/6/ut_burn.o \
       gen230/6/ut_bust.o \
       gen230/6/ut_crop.o \
       gen230/6/ut_cull.o \
       gen230/6/ut_find.o \
       gen230/6/ut_fink.o \
       gen230/6/ut_fire.o \
       gen230/6/ut_firm.o \
       gen230/6/ut_fish.o \
       gen230/6/ut_fuse.o \
       gen230/6/ut_gain.o \
       gen230/6/ut_heal.o \
       gen230/6/ut_lose.o \
       gen230/6/ut_mint.o \
       gen230/6/ut_mull.o \
       gen230/6/ut_nest.o \
       gen230/6/ut_orth.o \
       gen230/6/ut_park.o \
       gen230/6/ut_peek.o \
       gen230/6/ut_play.o \
       gen230/6/ut_repo.o \
       gen230/6/ut_rest.o \
       gen230/6/ut_seek.o \
       gen230/6/ut_snap.o \
       gen230/6/ut_swab.o \
       gen230/6/ut_tack.o \
       gen230/6/ut_tock.o

J230_OFILES=\
       $(J230_1_OFILES) \
       $(J230_2_OFILES) \
       $(J230_3_OFILES) \
       $(J230_4_OFILES) \
       $(J230_5_OFILES) \
       $(J230_6_OFILES) \
       $(J230_6_OFILES_UT) \
       gen230/watt.o

J229_1_OFILES=\
       gen229/1/add.o \
       gen229/1/bex.o \
       gen229/1/dec.o \
       gen229/1/div.o \
       gen229/1/gte.o \
       gen229/1/gth.o \
       gen229/1/lte.o \
       gen229/1/lth.o \
       gen229/1/mod.o \
       gen229/1/mul.o \
       gen229/1/sub.o

J229_2_OFILES=\
       gen229/2/bind.o \
       gen229/2/clap.o \
       gen229/2/drop.o \
       gen229/2/flop.o \
       gen229/2/lent.o \
       gen229/2/levy.o \
       gen229/2/lien.o \
       gen229/2/need.o \
       gen229/2/reel.o \
       gen229/2/roll.o \
       gen229/2/skim.o \
       gen229/2/skip.o \
       gen229/2/slag.o \
       gen229/2/snag.o \
       gen229/2/sort.o \
       gen229/2/turn.o \
       gen229/2/weld.o

J229_3_OFILES=\
       gen229/3/can.o \
       gen229/3/cap.o \
       gen229/3/cat.o \
       gen229/3/con.o \
       gen229/3/cut.o \
       gen229/3/dor.o \
       gen229/3/dis.o \
       gen229/3/end.o \
       gen229/3/gor.o \
       gen229/3/hor.o \
       gen229/3/lsh.o \
       gen229/3/mas.o \
       gen229/3/met.o \
       gen229/3/mix.o \
       gen229/3/mug.o \
       gen229/3/peg.o \
       gen229/3/rap.o \
       gen229/3/rip.o \
       gen229/3/rsh.o \
       gen229/3/vor.o

J229_4_OFILES=\
       gen229/4/in.o \
       gen229/4/by.o \
       gen229/4/in_has.o \
       gen229/4/in_gas.o \
       gen229/4/in_put.o \
       gen229/4/in_tap.o \
       gen229/4/by_gas.o \
       gen229/4/by_get.o \
       gen229/4/by_has.o \
       gen229/4/by_put.o 

J229_5_OFILES=\
       gen229/5/cue.o \
       gen229/5/jam.o \
       gen229/5/mat.o \
       gen229/5/rub.o \
       gen229/5/trip.o

J229_6_OFILES=\
       gen229/6/ap.o \
       gen229/6/cell.o \
       gen229/6/comb.o \
       gen229/6/cons.o \
       gen229/6/core.o \
       gen229/6/cube.o \
       gen229/6/face.o \
       gen229/6/fine.o \
       gen229/6/flan.o \
       gen229/6/flip.o \
       gen229/6/flor.o \
       gen229/6/foam.o \
       gen229/6/fork.o \
       gen229/6/hike.o \
       gen229/6/look.o \
       gen229/6/ream.o \
       gen229/6/ut.o

J229_6_OFILES_UT=\
       gen229/6/ut_burn.o \
       gen229/6/ut_bust.o \
       gen229/6/ut_crop.o \
       gen229/6/ut_cull.o \
       gen229/6/ut_find.o \
       gen229/6/ut_fink.o \
       gen229/6/ut_fire.o \
       gen229/6/ut_firm.o \
       gen229/6/ut_fish.o \
       gen229/6/ut_fuse.o \
       gen229/6/ut_gain.o \
       gen229/6/ut_heal.o \
       gen229/6/ut_lose.o \
       gen229/6/ut_mint.o \
       gen229/6/ut_mull.o \
       gen229/6/ut_nest.o \
       gen229/6/ut_orth.o \
       gen229/6/ut_park.o \
       gen229/6/ut_peek.o \
       gen229/6/ut_play.o \
       gen229/6/ut_repo.o \
       gen229/6/ut_rest.o \
       gen229/6/ut_seek.o \
       gen229/6/ut_snap.o \
       gen229/6/ut_swab.o \
       gen229/6/ut_tack.o \
       gen229/6/ut_tock.o

J229_OFILES=\
       $(J229_1_OFILES) \
       $(J229_2_OFILES) \
       $(J229_3_OFILES) \
       $(J229_4_OFILES) \
       $(J229_5_OFILES) \
       $(J229_6_OFILES) \
       $(J229_6_OFILES_UT) \
       gen229/watt.o

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



EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J230_OFILES) \
       $(J229_OFILES) \
       $(J228_OFILES)

all: $(BIN)/eyre

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
