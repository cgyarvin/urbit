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
       f/coal.o \
       f/host.o \
       f/benx.o \
       f/trac.o \
       f/bail.o \
       f/dash.o \
       f/unix.o \
       f/nock.o

P_OFILES=\
       p/book.o \
       p/list.o \
       p/pool.o \
       p/prep.o \
       p/saur.o

J225_1_OFILES=\
       gen225/1/add.o \
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
       gen225/3/bex.o \
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
       gen225/5/shax.o \
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

J224_1_OFILES=\
       gen224/1/add.o \
       gen224/1/dec.o \
       gen224/1/div.o \
       gen224/1/gte.o \
       gen224/1/gth.o \
       gen224/1/lte.o \
       gen224/1/lth.o \
       gen224/1/mod.o \
       gen224/1/mul.o \
       gen224/1/sub.o

J224_2_OFILES=\
       gen224/2/bind.o \
       gen224/2/clap.o \
       gen224/2/drop.o \
       gen224/2/flop.o \
       gen224/2/lent.o \
       gen224/2/levy.o \
       gen224/2/lien.o \
       gen224/2/need.o \
       gen224/2/reel.o \
       gen224/2/roll.o \
       gen224/2/skim.o \
       gen224/2/skip.o \
       gen224/2/slag.o \
       gen224/2/snag.o \
       gen224/2/sort.o \
       gen224/2/turn.o \
       gen224/2/weld.o

J224_3_OFILES=\
       gen224/3/bex.o \
       gen224/3/can.o \
       gen224/3/cap.o \
       gen224/3/cat.o \
       gen224/3/con.o \
       gen224/3/cut.o \
       gen224/3/dor.o \
       gen224/3/dis.o \
       gen224/3/end.o \
       gen224/3/gor.o \
       gen224/3/hor.o \
       gen224/3/lsh.o \
       gen224/3/mas.o \
       gen224/3/met.o \
       gen224/3/mix.o \
       gen224/3/mug.o \
       gen224/3/peg.o \
       gen224/3/rap.o \
       gen224/3/rip.o \
       gen224/3/rsh.o \
       gen224/3/vor.o

J224_4_OFILES=\
       gen224/4/in.o \
       gen224/4/by.o \
       gen224/4/in_has.o \
       gen224/4/in_gas.o \
       gen224/4/in_put.o \
       gen224/4/in_tap.o \
       gen224/4/by_gas.o \
       gen224/4/by_get.o \
       gen224/4/by_has.o \
       gen224/4/by_put.o 

J224_5_OFILES=\
       gen224/5/cue.o \
       gen224/5/jam.o \
       gen224/5/mat.o \
       gen224/5/parse.o \
       gen224/5/rub.o \
       gen224/5/shax.o \
       gen224/5/trip.o

J224_6_OFILES=\
       gen224/6/ap.o \
       gen224/6/cell.o \
       gen224/6/comb.o \
       gen224/6/cons.o \
       gen224/6/core.o \
       gen224/6/cube.o \
       gen224/6/face.o \
       gen224/6/fine.o \
       gen224/6/flan.o \
       gen224/6/flip.o \
       gen224/6/flor.o \
       gen224/6/foam.o \
       gen224/6/fork.o \
       gen224/6/hike.o \
       gen224/6/look.o \
       gen224/6/ut.o

J224_6_OFILES_UT=\
       gen224/6/ut_burn.o \
       gen224/6/ut_bust.o \
       gen224/6/ut_crop.o \
       gen224/6/ut_cull.o \
       gen224/6/ut_find.o \
       gen224/6/ut_fink.o \
       gen224/6/ut_fire.o \
       gen224/6/ut_firm.o \
       gen224/6/ut_fish.o \
       gen224/6/ut_fuse.o \
       gen224/6/ut_gain.o \
       gen224/6/ut_heal.o \
       gen224/6/ut_lose.o \
       gen224/6/ut_mint.o \
       gen224/6/ut_moot.o \
       gen224/6/ut_mull.o \
       gen224/6/ut_nest.o \
       gen224/6/ut_park.o \
       gen224/6/ut_peek.o \
       gen224/6/ut_play.o \
       gen224/6/ut_repo.o \
       gen224/6/ut_rest.o \
       gen224/6/ut_seek.o \
       gen224/6/ut_snap.o \
       gen224/6/ut_swab.o \
       gen224/6/ut_tack.o \
       gen224/6/ut_tock.o \
       gen224/6/ut_wrap.o

J224_OFILES=\
       $(J224_1_OFILES) \
       $(J224_2_OFILES) \
       $(J224_3_OFILES) \
       $(J224_4_OFILES) \
       $(J224_5_OFILES) \
       $(J224_6_OFILES) \
       $(J224_6_OFILES_UT) \
       gen224/watt.o

J223_1_OFILES=\
       gen223/1/add.o \
       gen223/1/dec.o \
       gen223/1/div.o \
       gen223/1/gte.o \
       gen223/1/gth.o \
       gen223/1/lte.o \
       gen223/1/lth.o \
       gen223/1/mod.o \
       gen223/1/mul.o \
       gen223/1/sub.o

J223_2_OFILES=\
       gen223/2/bind.o \
       gen223/2/clap.o \
       gen223/2/drop.o \
       gen223/2/flop.o \
       gen223/2/lent.o \
       gen223/2/levy.o \
       gen223/2/lien.o \
       gen223/2/need.o \
       gen223/2/reel.o \
       gen223/2/roll.o \
       gen223/2/skim.o \
       gen223/2/skip.o \
       gen223/2/slag.o \
       gen223/2/snag.o \
       gen223/2/sort.o \
       gen223/2/turn.o \
       gen223/2/weld.o

J223_3_OFILES=\
       gen223/3/bex.o \
       gen223/3/can.o \
       gen223/3/cap.o \
       gen223/3/cat.o \
       gen223/3/con.o \
       gen223/3/cut.o \
       gen223/3/dor.o \
       gen223/3/dis.o \
       gen223/3/end.o \
       gen223/3/gor.o \
       gen223/3/hor.o \
       gen223/3/lsh.o \
       gen223/3/mas.o \
       gen223/3/met.o \
       gen223/3/mix.o \
       gen223/3/mug.o \
       gen223/3/peg.o \
       gen223/3/rap.o \
       gen223/3/rip.o \
       gen223/3/rsh.o \
       gen223/3/vor.o

J223_4_OFILES=\
       gen223/4/in.o \
       gen223/4/by.o \
       gen223/4/in_has.o \
       gen223/4/in_gas.o \
       gen223/4/in_put.o \
       gen223/4/in_tap.o \
       gen223/4/by_gas.o \
       gen223/4/by_get.o \
       gen223/4/by_has.o \
       gen223/4/by_put.o 

J223_5_OFILES=\
       gen223/5/cue.o \
       gen223/5/jam.o \
       gen223/5/mat.o \
       gen223/5/parse.o \
       gen223/5/rub.o \
       gen223/5/shax.o \
       gen223/5/trip.o

J223_6_OFILES=\
       gen223/6/ap.o \
       gen223/6/cell.o \
       gen223/6/comb.o \
       gen223/6/cons.o \
       gen223/6/core.o \
       gen223/6/cube.o \
       gen223/6/face.o \
       gen223/6/fine.o \
       gen223/6/flan.o \
       gen223/6/flip.o \
       gen223/6/flor.o \
       gen223/6/foam.o \
       gen223/6/fork.o \
       gen223/6/hike.o \
       gen223/6/look.o \
       gen223/6/ut.o

J223_6_OFILES_UT=\
       gen223/6/ut_burn.o \
       gen223/6/ut_bust.o \
       gen223/6/ut_crop.o \
       gen223/6/ut_cull.o \
       gen223/6/ut_find.o \
       gen223/6/ut_fink.o \
       gen223/6/ut_fire.o \
       gen223/6/ut_firm.o \
       gen223/6/ut_fish.o \
       gen223/6/ut_fuse.o \
       gen223/6/ut_gain.o \
       gen223/6/ut_heal.o \
       gen223/6/ut_lose.o \
       gen223/6/ut_mint.o \
       gen223/6/ut_moot.o \
       gen223/6/ut_mull.o \
       gen223/6/ut_nest.o \
       gen223/6/ut_park.o \
       gen223/6/ut_peek.o \
       gen223/6/ut_play.o \
       gen223/6/ut_repo.o \
       gen223/6/ut_rest.o \
       gen223/6/ut_seek.o \
       gen223/6/ut_snap.o \
       gen223/6/ut_swab.o \
       gen223/6/ut_tack.o \
       gen223/6/ut_tock.o \
       gen223/6/ut_wrap.o

J223_OFILES=\
       $(J223_1_OFILES) \
       $(J223_2_OFILES) \
       $(J223_3_OFILES) \
       $(J223_4_OFILES) \
       $(J223_5_OFILES) \
       $(J223_6_OFILES) \
       $(J223_6_OFILES_UT) \
       gen223/watt.o

BASE_OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J225_OFILES) \
       $(J224_OFILES) \
       $(J223_OFILES)

EYRE_OFILES=\
       c/eyre.o \
       $(BASE_OFILES)

VERE_OFILES=\
       c/vere.o \
       $(BASE_OFILES)

all: $(BIN)/eyre $(BIN)/vere

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

$(BIN)/vere: $(VERE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/vere $(VERE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
