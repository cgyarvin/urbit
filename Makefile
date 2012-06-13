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
CLD=gcc -O3 -L/usr/local/lib
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU2_OS_$(OS) -DU2_OS_ENDIAN_$(ENDIAN)
CFLAGS=-O3 -I/usr/local/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
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
       f/hevn.o \
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

J214_1_OFILES=\
       gen214/1/add.o \
       gen214/1/dec.o \
       gen214/1/div.o \
       gen214/1/gte.o \
       gen214/1/gth.o \
       gen214/1/lte.o \
       gen214/1/lth.o \
       gen214/1/mod.o \
       gen214/1/mul.o \
       gen214/1/sub.o

J214_2_OFILES=\
       gen214/2/bind.o \
       gen214/2/clap.o \
       gen214/2/drop.o \
       gen214/2/flop.o \
       gen214/2/lent.o \
       gen214/2/levy.o \
       gen214/2/lien.o \
       gen214/2/need.o \
       gen214/2/reel.o \
       gen214/2/roll.o \
       gen214/2/skim.o \
       gen214/2/skip.o \
       gen214/2/slag.o \
       gen214/2/snag.o \
       gen214/2/sort.o \
       gen214/2/turn.o \
       gen214/2/weld.o

J214_3_OFILES=\
       gen214/3/bex.o \
       gen214/3/can.o \
       gen214/3/cap.o \
       gen214/3/cat.o \
       gen214/3/con.o \
       gen214/3/cut.o \
       gen214/3/dor.o \
       gen214/3/dis.o \
       gen214/3/end.o \
       gen214/3/gor.o \
       gen214/3/hor.o \
       gen214/3/lsh.o \
       gen214/3/mas.o \
       gen214/3/met.o \
       gen214/3/mix.o \
       gen214/3/mug.o \
       gen214/3/peg.o \
       gen214/3/rap.o \
       gen214/3/rip.o \
       gen214/3/rsh.o \
       gen214/3/vor.o

J214_4_OFILES=\
       gen214/4/in.o \
       gen214/4/by.o \
       gen214/4/in_has.o \
       gen214/4/in_gas.o \
       gen214/4/in_put.o \
       gen214/4/in_tap.o \
       gen214/4/by_gas.o \
       gen214/4/by_get.o \
       gen214/4/by_has.o \
       gen214/4/by_put.o 

J214_5_OFILES=\
       gen214/5/cue.o \
       gen214/5/jam.o \
       gen214/5/mat.o \
       gen214/5/mock.o \
       gen214/5/parse.o \
       gen214/5/rub.o \
       gen214/5/shax.o \
       gen214/5/trip.o

J214_6_OFILES=\
       gen214/6/ap.o \
       gen214/6/cell.o \
       gen214/6/comb.o \
       gen214/6/cons.o \
       gen214/6/core.o \
       gen214/6/cube.o \
       gen214/6/face.o \
       gen214/6/fine.o \
       gen214/6/flan.o \
       gen214/6/flip.o \
       gen214/6/flor.o \
       gen214/6/foam.o \
       gen214/6/fork.o \
       gen214/6/hike.o \
       gen214/6/look.o \
       gen214/6/ut.o

J214_6_OFILES_UT=\
       gen214/6/ut_burn.o \
       gen214/6/ut_bust.o \
       gen214/6/ut_crop.o \
       gen214/6/ut_cull.o \
       gen214/6/ut_find.o \
       gen214/6/ut_fink.o \
       gen214/6/ut_fire.o \
       gen214/6/ut_firm.o \
       gen214/6/ut_fish.o \
       gen214/6/ut_fuse.o \
       gen214/6/ut_gain.o \
       gen214/6/ut_heal.o \
       gen214/6/ut_lose.o \
       gen214/6/ut_mint.o \
       gen214/6/ut_moot.o \
       gen214/6/ut_mull.o \
       gen214/6/ut_nest.o \
       gen214/6/ut_park.o \
       gen214/6/ut_peek.o \
       gen214/6/ut_play.o \
       gen214/6/ut_repo.o \
       gen214/6/ut_rest.o \
       gen214/6/ut_seek.o \
       gen214/6/ut_snap.o \
       gen214/6/ut_swab.o \
       gen214/6/ut_tack.o \
       gen214/6/ut_tock.o \
       gen214/6/ut_wrap.o

J214_OFILES=\
       $(J214_1_OFILES) \
       $(J214_2_OFILES) \
       $(J214_3_OFILES) \
       $(J214_4_OFILES) \
       $(J214_5_OFILES) \
       $(J214_6_OFILES) \
       $(J214_6_OFILES_UT) \
       gen214/watt.o

J213_1_OFILES=\
       gen213/1/add.o \
       gen213/1/dec.o \
       gen213/1/div.o \
       gen213/1/gte.o \
       gen213/1/gth.o \
       gen213/1/lte.o \
       gen213/1/lth.o \
       gen213/1/mod.o \
       gen213/1/mul.o \
       gen213/1/sub.o

J213_2_OFILES=\
       gen213/2/bind.o \
       gen213/2/clap.o \
       gen213/2/drop.o \
       gen213/2/flop.o \
       gen213/2/lent.o \
       gen213/2/levy.o \
       gen213/2/lien.o \
       gen213/2/need.o \
       gen213/2/reel.o \
       gen213/2/roll.o \
       gen213/2/skim.o \
       gen213/2/skip.o \
       gen213/2/slag.o \
       gen213/2/snag.o \
       gen213/2/sort.o \
       gen213/2/turn.o \
       gen213/2/weld.o

J213_3_OFILES=\
       gen213/3/bex.o \
       gen213/3/can.o \
       gen213/3/cap.o \
       gen213/3/cat.o \
       gen213/3/con.o \
       gen213/3/cut.o \
       gen213/3/dor.o \
       gen213/3/dis.o \
       gen213/3/end.o \
       gen213/3/gor.o \
       gen213/3/hor.o \
       gen213/3/lsh.o \
       gen213/3/mas.o \
       gen213/3/met.o \
       gen213/3/mix.o \
       gen213/3/mug.o \
       gen213/3/peg.o \
       gen213/3/rap.o \
       gen213/3/rip.o \
       gen213/3/rsh.o \
       gen213/3/vor.o

J213_4_OFILES=\
       gen213/4/in.o \
       gen213/4/by.o \
       gen213/4/in_has.o \
       gen213/4/in_gas.o \
       gen213/4/in_put.o \
       gen213/4/in_tap.o \
       gen213/4/by_gas.o \
       gen213/4/by_get.o \
       gen213/4/by_has.o \
       gen213/4/by_put.o 

J213_5_OFILES=\
       gen213/5/cue.o \
       gen213/5/jam.o \
       gen213/5/mat.o \
       gen213/5/mock.o \
       gen213/5/parse.o \
       gen213/5/rub.o \
       gen213/5/shax.o \
       gen213/5/trip.o

J213_6_OFILES=\
       gen213/6/ap.o \
       gen213/6/cell.o \
       gen213/6/comb.o \
       gen213/6/cons.o \
       gen213/6/core.o \
       gen213/6/cube.o \
       gen213/6/face.o \
       gen213/6/fine.o \
       gen213/6/flan.o \
       gen213/6/flip.o \
       gen213/6/flor.o \
       gen213/6/foam.o \
       gen213/6/fork.o \
       gen213/6/hike.o \
       gen213/6/look.o \
       gen213/6/ut.o

J213_6_OFILES_UT=\
       gen213/6/ut_burn.o \
       gen213/6/ut_bust.o \
       gen213/6/ut_crop.o \
       gen213/6/ut_cull.o \
       gen213/6/ut_find.o \
       gen213/6/ut_fink.o \
       gen213/6/ut_fire.o \
       gen213/6/ut_firm.o \
       gen213/6/ut_fish.o \
       gen213/6/ut_fuse.o \
       gen213/6/ut_gain.o \
       gen213/6/ut_heal.o \
       gen213/6/ut_lose.o \
       gen213/6/ut_mint.o \
       gen213/6/ut_moot.o \
       gen213/6/ut_mull.o \
       gen213/6/ut_nest.o \
       gen213/6/ut_park.o \
       gen213/6/ut_peek.o \
       gen213/6/ut_play.o \
       gen213/6/ut_repo.o \
       gen213/6/ut_rest.o \
       gen213/6/ut_seek.o \
       gen213/6/ut_snap.o \
       gen213/6/ut_swab.o \
       gen213/6/ut_tack.o \
       gen213/6/ut_tock.o \
       gen213/6/ut_wrap.o

J213_OFILES=\
       $(J213_1_OFILES) \
       $(J213_2_OFILES) \
       $(J213_3_OFILES) \
       $(J213_4_OFILES) \
       $(J213_5_OFILES) \
       $(J213_6_OFILES) \
       $(J213_6_OFILES_UT) \
       gen213/watt.o

J212_1_OFILES=\
       gen212/1/add.o \
       gen212/1/dec.o \
       gen212/1/div.o \
       gen212/1/gte.o \
       gen212/1/gth.o \
       gen212/1/lte.o \
       gen212/1/lth.o \
       gen212/1/mod.o \
       gen212/1/mul.o \
       gen212/1/sub.o

J212_2_OFILES=\
       gen212/2/bind.o \
       gen212/2/clap.o \
       gen212/2/drop.o \
       gen212/2/flop.o \
       gen212/2/lent.o \
       gen212/2/levy.o \
       gen212/2/lien.o \
       gen212/2/need.o \
       gen212/2/reel.o \
       gen212/2/roll.o \
       gen212/2/skim.o \
       gen212/2/skip.o \
       gen212/2/slag.o \
       gen212/2/snag.o \
       gen212/2/sort.o \
       gen212/2/turn.o \
       gen212/2/weld.o

J212_3_OFILES=\
       gen212/3/bex.o \
       gen212/3/can.o \
       gen212/3/cap.o \
       gen212/3/cat.o \
       gen212/3/con.o \
       gen212/3/cut.o \
       gen212/3/dor.o \
       gen212/3/dis.o \
       gen212/3/end.o \
       gen212/3/gor.o \
       gen212/3/hor.o \
       gen212/3/lsh.o \
       gen212/3/mas.o \
       gen212/3/met.o \
       gen212/3/mix.o \
       gen212/3/mug.o \
       gen212/3/peg.o \
       gen212/3/rap.o \
       gen212/3/rip.o \
       gen212/3/rsh.o \
       gen212/3/vor.o

J212_4_OFILES=\
       gen212/4/in.o \
       gen212/4/by.o \
       gen212/4/in_has.o \
       gen212/4/in_gas.o \
       gen212/4/in_put.o \
       gen212/4/in_tap.o \
       gen212/4/by_gas.o \
       gen212/4/by_get.o \
       gen212/4/by_has.o \
       gen212/4/by_put.o 

J212_5_OFILES=\
       gen212/5/cue.o \
       gen212/5/jam.o \
       gen212/5/mat.o \
       gen212/5/mock.o \
       gen212/5/parse.o \
       gen212/5/rub.o \
       gen212/5/shax.o \
       gen212/5/trip.o

J212_6_OFILES=\
       gen212/6/ap.o \
       gen212/6/cell.o \
       gen212/6/comb.o \
       gen212/6/cons.o \
       gen212/6/core.o \
       gen212/6/cube.o \
       gen212/6/face.o \
       gen212/6/fine.o \
       gen212/6/flan.o \
       gen212/6/flip.o \
       gen212/6/flor.o \
       gen212/6/foam.o \
       gen212/6/fork.o \
       gen212/6/hike.o \
       gen212/6/look.o \
       gen212/6/ut.o

J212_6_OFILES_UT=\
       gen212/6/ut_burn.o \
       gen212/6/ut_bust.o \
       gen212/6/ut_crop.o \
       gen212/6/ut_cull.o \
       gen212/6/ut_find.o \
       gen212/6/ut_fink.o \
       gen212/6/ut_fire.o \
       gen212/6/ut_firm.o \
       gen212/6/ut_fish.o \
       gen212/6/ut_fuse.o \
       gen212/6/ut_gain.o \
       gen212/6/ut_heal.o \
       gen212/6/ut_lose.o \
       gen212/6/ut_mint.o \
       gen212/6/ut_moot.o \
       gen212/6/ut_mull.o \
       gen212/6/ut_nest.o \
       gen212/6/ut_park.o \
       gen212/6/ut_peek.o \
       gen212/6/ut_play.o \
       gen212/6/ut_repo.o \
       gen212/6/ut_rest.o \
       gen212/6/ut_seek.o \
       gen212/6/ut_snap.o \
       gen212/6/ut_swab.o \
       gen212/6/ut_tack.o \
       gen212/6/ut_tock.o \
       gen212/6/ut_wrap.o

J212_OFILES=\
       $(J212_1_OFILES) \
       $(J212_2_OFILES) \
       $(J212_3_OFILES) \
       $(J212_4_OFILES) \
       $(J212_5_OFILES) \
       $(J212_6_OFILES) \
       $(J212_6_OFILES_UT) \
       gen212/watt.o

J211_1_OFILES=\
       gen211/1/add.o \
       gen211/1/dec.o \
       gen211/1/div.o \
       gen211/1/gte.o \
       gen211/1/gth.o \
       gen211/1/lte.o \
       gen211/1/lth.o \
       gen211/1/mod.o \
       gen211/1/mul.o \
       gen211/1/sub.o

J211_2_OFILES=\
       gen211/2/bind.o \
       gen211/2/clap.o \
       gen211/2/drop.o \
       gen211/2/flop.o \
       gen211/2/lent.o \
       gen211/2/levy.o \
       gen211/2/lien.o \
       gen211/2/need.o \
       gen211/2/reel.o \
       gen211/2/roll.o \
       gen211/2/skim.o \
       gen211/2/skip.o \
       gen211/2/slag.o \
       gen211/2/snag.o \
       gen211/2/sort.o \
       gen211/2/turn.o \
       gen211/2/weld.o

J211_3_OFILES=\
       gen211/3/bex.o \
       gen211/3/can.o \
       gen211/3/cap.o \
       gen211/3/cat.o \
       gen211/3/con.o \
       gen211/3/cut.o \
       gen211/3/dor.o \
       gen211/3/dis.o \
       gen211/3/end.o \
       gen211/3/gor.o \
       gen211/3/hor.o \
       gen211/3/lsh.o \
       gen211/3/mas.o \
       gen211/3/met.o \
       gen211/3/mix.o \
       gen211/3/mug.o \
       gen211/3/peg.o \
       gen211/3/rap.o \
       gen211/3/rip.o \
       gen211/3/rsh.o \
       gen211/3/vor.o

J211_4_OFILES=\
       gen211/4/in.o \
       gen211/4/by.o \
       gen211/4/in_has.o \
       gen211/4/in_gas.o \
       gen211/4/in_put.o \
       gen211/4/in_tap.o \
       gen211/4/by_gas.o \
       gen211/4/by_get.o \
       gen211/4/by_has.o \
       gen211/4/by_put.o 

J211_5_OFILES=\
       gen211/5/cue.o \
       gen211/5/jam.o \
       gen211/5/mat.o \
       gen211/5/mock.o \
       gen211/5/parse.o \
       gen211/5/rub.o \
       gen211/5/shax.o \
       gen211/5/trip.o

J211_6_OFILES=\
       gen211/6/ap.o \
       gen211/6/cell.o \
       gen211/6/comb.o \
       gen211/6/cons.o \
       gen211/6/core.o \
       gen211/6/cube.o \
       gen211/6/face.o \
       gen211/6/fine.o \
       gen211/6/flan.o \
       gen211/6/flip.o \
       gen211/6/flor.o \
       gen211/6/foam.o \
       gen211/6/fork.o \
       gen211/6/hike.o \
       gen211/6/look.o \
       gen211/6/ut.o

J211_6_OFILES_UT=\
       gen211/6/ut_burn.o \
       gen211/6/ut_bust.o \
       gen211/6/ut_crop.o \
       gen211/6/ut_cull.o \
       gen211/6/ut_find.o \
       gen211/6/ut_fink.o \
       gen211/6/ut_fire.o \
       gen211/6/ut_firm.o \
       gen211/6/ut_fish.o \
       gen211/6/ut_fuse.o \
       gen211/6/ut_gain.o \
       gen211/6/ut_heal.o \
       gen211/6/ut_lose.o \
       gen211/6/ut_mint.o \
       gen211/6/ut_moot.o \
       gen211/6/ut_mull.o \
       gen211/6/ut_nest.o \
       gen211/6/ut_park.o \
       gen211/6/ut_peek.o \
       gen211/6/ut_play.o \
       gen211/6/ut_repo.o \
       gen211/6/ut_rest.o \
       gen211/6/ut_seek.o \
       gen211/6/ut_snap.o \
       gen211/6/ut_swab.o \
       gen211/6/ut_tack.o \
       gen211/6/ut_tock.o \
       gen211/6/ut_wrap.o

J211_OFILES=\
       $(J211_1_OFILES) \
       $(J211_2_OFILES) \
       $(J211_3_OFILES) \
       $(J211_4_OFILES) \
       $(J211_5_OFILES) \
       $(J211_6_OFILES) \
       $(J211_6_OFILES_UT) \
       gen211/watt.o

J210_1_OFILES=\
       gen210/1/add.o \
       gen210/1/dec.o \
       gen210/1/div.o \
       gen210/1/gte.o \
       gen210/1/gth.o \
       gen210/1/lte.o \
       gen210/1/lth.o \
       gen210/1/mod.o \
       gen210/1/mul.o \
       gen210/1/sub.o

J210_2_OFILES=\
       gen210/2/bind.o \
       gen210/2/clap.o \
       gen210/2/drop.o \
       gen210/2/flop.o \
       gen210/2/lent.o \
       gen210/2/levy.o \
       gen210/2/lien.o \
       gen210/2/need.o \
       gen210/2/reel.o \
       gen210/2/roll.o \
       gen210/2/skim.o \
       gen210/2/skip.o \
       gen210/2/slag.o \
       gen210/2/snag.o \
       gen210/2/sort.o \
       gen210/2/turn.o \
       gen210/2/weld.o

J210_3_OFILES=\
       gen210/3/bex.o \
       gen210/3/can.o \
       gen210/3/cap.o \
       gen210/3/cat.o \
       gen210/3/con.o \
       gen210/3/cut.o \
       gen210/3/dor.o \
       gen210/3/dis.o \
       gen210/3/end.o \
       gen210/3/gor.o \
       gen210/3/hor.o \
       gen210/3/lsh.o \
       gen210/3/mas.o \
       gen210/3/met.o \
       gen210/3/mix.o \
       gen210/3/mug.o \
       gen210/3/peg.o \
       gen210/3/rap.o \
       gen210/3/rip.o \
       gen210/3/rsh.o \
       gen210/3/vor.o

J210_4_OFILES=\
       gen210/4/in.o \
       gen210/4/by.o \
       gen210/4/in_has.o \
       gen210/4/in_gas.o \
       gen210/4/in_put.o \
       gen210/4/in_tap.o \
       gen210/4/by_gas.o \
       gen210/4/by_get.o \
       gen210/4/by_has.o \
       gen210/4/by_put.o 

J210_5_OFILES=\
       gen210/5/cue.o \
       gen210/5/jam.o \
       gen210/5/mat.o \
       gen210/5/mock.o \
       gen210/5/parse.o \
       gen210/5/rub.o \
       gen210/5/shax.o \
       gen210/5/trip.o

J210_6_OFILES=\
       gen210/6/ap.o \
       gen210/6/cell.o \
       gen210/6/comb.o \
       gen210/6/cons.o \
       gen210/6/core.o \
       gen210/6/cube.o \
       gen210/6/face.o \
       gen210/6/fine.o \
       gen210/6/fitz.o \
       gen210/6/flan.o \
       gen210/6/flip.o \
       gen210/6/flor.o \
       gen210/6/foam.o \
       gen210/6/fork.o \
       gen210/6/hike.o \
       gen210/6/look.o \
       gen210/6/ut.o

J210_6_OFILES_UT=\
       gen210/6/ut_burn.o \
       gen210/6/ut_bust.o \
       gen210/6/ut_crop.o \
       gen210/6/ut_cull.o \
       gen210/6/ut_find.o \
       gen210/6/ut_fink.o \
       gen210/6/ut_fire.o \
       gen210/6/ut_firm.o \
       gen210/6/ut_fish.o \
       gen210/6/ut_fuse.o \
       gen210/6/ut_gain.o \
       gen210/6/ut_heal.o \
       gen210/6/ut_lose.o \
       gen210/6/ut_mint.o \
       gen210/6/ut_moot.o \
       gen210/6/ut_mull.o \
       gen210/6/ut_nest.o \
       gen210/6/ut_park.o \
       gen210/6/ut_peek.o \
       gen210/6/ut_play.o \
       gen210/6/ut_repo.o \
       gen210/6/ut_rest.o \
       gen210/6/ut_seek.o \
       gen210/6/ut_snap.o \
       gen210/6/ut_swab.o \
       gen210/6/ut_tack.o \
       gen210/6/ut_tock.o \
       gen210/6/ut_wrap.o

J210_OFILES=\
       $(J210_1_OFILES) \
       $(J210_2_OFILES) \
       $(J210_3_OFILES) \
       $(J210_4_OFILES) \
       $(J210_5_OFILES) \
       $(J210_6_OFILES) \
       $(J210_6_OFILES_UT) \
       gen210/watt.o

J209_1_OFILES=\
       gen209/1/add.o \
       gen209/1/dec.o \
       gen209/1/div.o \
       gen209/1/gte.o \
       gen209/1/gth.o \
       gen209/1/lte.o \
       gen209/1/lth.o \
       gen209/1/mod.o \
       gen209/1/mul.o \
       gen209/1/sub.o

J209_2_OFILES=\
       gen209/2/bind.o \
       gen209/2/clap.o \
       gen209/2/drop.o \
       gen209/2/flop.o \
       gen209/2/lent.o \
       gen209/2/levy.o \
       gen209/2/lien.o \
       gen209/2/need.o \
       gen209/2/reel.o \
       gen209/2/roll.o \
       gen209/2/skim.o \
       gen209/2/skip.o \
       gen209/2/slag.o \
       gen209/2/snag.o \
       gen209/2/sort.o \
       gen209/2/turn.o \
       gen209/2/weld.o

J209_3_OFILES=\
       gen209/3/bex.o \
       gen209/3/can.o \
       gen209/3/cap.o \
       gen209/3/cat.o \
       gen209/3/con.o \
       gen209/3/cut.o \
       gen209/3/dor.o \
       gen209/3/dis.o \
       gen209/3/end.o \
       gen209/3/gor.o \
       gen209/3/hor.o \
       gen209/3/lsh.o \
       gen209/3/mas.o \
       gen209/3/met.o \
       gen209/3/mix.o \
       gen209/3/mug.o \
       gen209/3/peg.o \
       gen209/3/rap.o \
       gen209/3/rip.o \
       gen209/3/rsh.o \
       gen209/3/vor.o

J209_4_OFILES=\
       gen209/4/in.o \
       gen209/4/by.o \
       gen209/4/in_has.o \
       gen209/4/in_gas.o \
       gen209/4/in_put.o \
       gen209/4/in_tap.o \
       gen209/4/by_gas.o \
       gen209/4/by_get.o \
       gen209/4/by_has.o \
       gen209/4/by_put.o 

J209_5_OFILES=\
       gen209/5/cue.o \
       gen209/5/jam.o \
       gen209/5/mat.o \
       gen209/5/mock.o \
       gen209/5/parse.o \
       gen209/5/rub.o \
       gen209/5/shax.o \
       gen209/5/trip.o

J209_6_OFILES=\
       gen209/6/ap.o \
       gen209/6/cell.o \
       gen209/6/comb.o \
       gen209/6/cons.o \
       gen209/6/core.o \
       gen209/6/cube.o \
       gen209/6/face.o \
       gen209/6/fine.o \
       gen209/6/fitz.o \
       gen209/6/flan.o \
       gen209/6/flip.o \
       gen209/6/flor.o \
       gen209/6/foam.o \
       gen209/6/fork.o \
       gen209/6/hike.o \
       gen209/6/look.o \
       gen209/6/ut.o

J209_6_OFILES_UT=\
       gen209/6/ut_burn.o \
       gen209/6/ut_bust.o \
       gen209/6/ut_crop.o \
       gen209/6/ut_cull.o \
       gen209/6/ut_find.o \
       gen209/6/ut_fink.o \
       gen209/6/ut_fire.o \
       gen209/6/ut_firm.o \
       gen209/6/ut_fish.o \
       gen209/6/ut_fuse.o \
       gen209/6/ut_gain.o \
       gen209/6/ut_heal.o \
       gen209/6/ut_lose.o \
       gen209/6/ut_mint.o \
       gen209/6/ut_moot.o \
       gen209/6/ut_mull.o \
       gen209/6/ut_nest.o \
       gen209/6/ut_park.o \
       gen209/6/ut_peek.o \
       gen209/6/ut_play.o \
       gen209/6/ut_repo.o \
       gen209/6/ut_rest.o \
       gen209/6/ut_seek.o \
       gen209/6/ut_snap.o \
       gen209/6/ut_swab.o \
       gen209/6/ut_tack.o \
       gen209/6/ut_tock.o \
       gen209/6/ut_wrap.o

J209_OFILES=\
       $(J209_1_OFILES) \
       $(J209_2_OFILES) \
       $(J209_3_OFILES) \
       $(J209_4_OFILES) \
       $(J209_5_OFILES) \
       $(J209_6_OFILES) \
       $(J209_6_OFILES_UT) \
       gen209/watt.o

J208_1_OFILES=\
       gen208/1/add.o \
       gen208/1/dec.o \
       gen208/1/div.o \
       gen208/1/gte.o \
       gen208/1/gth.o \
       gen208/1/lte.o \
       gen208/1/lth.o \
       gen208/1/mod.o \
       gen208/1/mul.o \
       gen208/1/sub.o

J208_2_OFILES=\
       gen208/2/bind.o \
       gen208/2/clap.o \
       gen208/2/drop.o \
       gen208/2/flop.o \
       gen208/2/lent.o \
       gen208/2/levy.o \
       gen208/2/lien.o \
       gen208/2/need.o \
       gen208/2/reel.o \
       gen208/2/roll.o \
       gen208/2/skim.o \
       gen208/2/skip.o \
       gen208/2/slag.o \
       gen208/2/snag.o \
       gen208/2/sort.o \
       gen208/2/turn.o \
       gen208/2/weld.o

J208_3_OFILES=\
       gen208/3/bex.o \
       gen208/3/can.o \
       gen208/3/cap.o \
       gen208/3/cat.o \
       gen208/3/con.o \
       gen208/3/cut.o \
       gen208/3/dor.o \
       gen208/3/dis.o \
       gen208/3/end.o \
       gen208/3/gor.o \
       gen208/3/hor.o \
       gen208/3/lsh.o \
       gen208/3/mas.o \
       gen208/3/met.o \
       gen208/3/mix.o \
       gen208/3/mug.o \
       gen208/3/peg.o \
       gen208/3/rap.o \
       gen208/3/rip.o \
       gen208/3/rsh.o \
       gen208/3/vor.o

J208_4_OFILES=\
       gen208/4/in.o \
       gen208/4/by.o \
       gen208/4/in_has.o \
       gen208/4/in_gas.o \
       gen208/4/in_put.o \
       gen208/4/in_tap.o \
       gen208/4/by_gas.o \
       gen208/4/by_get.o \
       gen208/4/by_has.o \
       gen208/4/by_put.o 

J208_5_OFILES=\
       gen208/5/cue.o \
       gen208/5/jam.o \
       gen208/5/mat.o \
       gen208/5/mock.o \
       gen208/5/parse.o \
       gen208/5/rub.o \
       gen208/5/shax.o \
       gen208/5/trip.o

J208_6_OFILES=\
       gen208/6/ap.o \
       gen208/6/cell.o \
       gen208/6/comb.o \
       gen208/6/cons.o \
       gen208/6/core.o \
       gen208/6/cube.o \
       gen208/6/face.o \
       gen208/6/fine.o \
       gen208/6/fitz.o \
       gen208/6/flan.o \
       gen208/6/flip.o \
       gen208/6/flor.o \
       gen208/6/foam.o \
       gen208/6/fork.o \
       gen208/6/hike.o \
       gen208/6/look.o \
       gen208/6/ut.o

J208_6_OFILES_UT=\
       gen208/6/ut_burn.o \
       gen208/6/ut_bust.o \
       gen208/6/ut_crop.o \
       gen208/6/ut_cull.o \
       gen208/6/ut_find.o \
       gen208/6/ut_fink.o \
       gen208/6/ut_fire.o \
       gen208/6/ut_firm.o \
       gen208/6/ut_fish.o \
       gen208/6/ut_fuse.o \
       gen208/6/ut_gain.o \
       gen208/6/ut_heal.o \
       gen208/6/ut_lose.o \
       gen208/6/ut_mint.o \
       gen208/6/ut_moot.o \
       gen208/6/ut_mull.o \
       gen208/6/ut_nest.o \
       gen208/6/ut_park.o \
       gen208/6/ut_peek.o \
       gen208/6/ut_play.o \
       gen208/6/ut_repo.o \
       gen208/6/ut_rest.o \
       gen208/6/ut_seek.o \
       gen208/6/ut_snap.o \
       gen208/6/ut_swab.o \
       gen208/6/ut_tack.o \
       gen208/6/ut_tock.o \
       gen208/6/ut_wrap.o

J208_OFILES=\
       $(J208_1_OFILES) \
       $(J208_2_OFILES) \
       $(J208_3_OFILES) \
       $(J208_4_OFILES) \
       $(J208_5_OFILES) \
       $(J208_6_OFILES) \
       $(J208_6_OFILES_UT) \
       gen208/watt.o

J207_1_OFILES=\
       gen207/1/add.o \
       gen207/1/dec.o \
       gen207/1/div.o \
       gen207/1/gte.o \
       gen207/1/gth.o \
       gen207/1/lte.o \
       gen207/1/lth.o \
       gen207/1/mod.o \
       gen207/1/mul.o \
       gen207/1/sub.o

J207_2_OFILES=\
       gen207/2/bind.o \
       gen207/2/clap.o \
       gen207/2/drop.o \
       gen207/2/flop.o \
       gen207/2/lent.o \
       gen207/2/levy.o \
       gen207/2/lien.o \
       gen207/2/need.o \
       gen207/2/reel.o \
       gen207/2/roll.o \
       gen207/2/skim.o \
       gen207/2/skip.o \
       gen207/2/slag.o \
       gen207/2/snag.o \
       gen207/2/sort.o \
       gen207/2/turn.o \
       gen207/2/weld.o

J207_3_OFILES=\
       gen207/3/bex.o \
       gen207/3/can.o \
       gen207/3/cap.o \
       gen207/3/cat.o \
       gen207/3/con.o \
       gen207/3/cut.o \
       gen207/3/dor.o \
       gen207/3/dis.o \
       gen207/3/end.o \
       gen207/3/gor.o \
       gen207/3/hor.o \
       gen207/3/lsh.o \
       gen207/3/mas.o \
       gen207/3/met.o \
       gen207/3/mix.o \
       gen207/3/mug.o \
       gen207/3/peg.o \
       gen207/3/rap.o \
       gen207/3/rip.o \
       gen207/3/rsh.o \
       gen207/3/vor.o

J207_4_OFILES=\
       gen207/4/in.o \
       gen207/4/by.o \
       gen207/4/in_has.o \
       gen207/4/in_gas.o \
       gen207/4/in_put.o \
       gen207/4/in_tap.o \
       gen207/4/by_gas.o \
       gen207/4/by_get.o \
       gen207/4/by_has.o \
       gen207/4/by_put.o 

J207_5_OFILES=\
       gen207/5/cue.o \
       gen207/5/jam.o \
       gen207/5/mat.o \
       gen207/5/mock.o \
       gen207/5/parse.o \
       gen207/5/rub.o \
       gen207/5/shax.o \
       gen207/5/trip.o

J207_6_OFILES=\
       gen207/6/ap.o \
       gen207/6/cell.o \
       gen207/6/comb.o \
       gen207/6/cons.o \
       gen207/6/core.o \
       gen207/6/cube.o \
       gen207/6/face.o \
       gen207/6/fine.o \
       gen207/6/fitz.o \
       gen207/6/flan.o \
       gen207/6/flip.o \
       gen207/6/flor.o \
       gen207/6/foam.o \
       gen207/6/fork.o \
       gen207/6/hike.o \
       gen207/6/look.o \
       gen207/6/ut.o

J207_6_OFILES_UT=\
       gen207/6/ut_burn.o \
       gen207/6/ut_bust.o \
       gen207/6/ut_crop.o \
       gen207/6/ut_cull.o \
       gen207/6/ut_find.o \
       gen207/6/ut_fink.o \
       gen207/6/ut_fire.o \
       gen207/6/ut_firm.o \
       gen207/6/ut_fish.o \
       gen207/6/ut_fuse.o \
       gen207/6/ut_gain.o \
       gen207/6/ut_heal.o \
       gen207/6/ut_lose.o \
       gen207/6/ut_mint.o \
       gen207/6/ut_moot.o \
       gen207/6/ut_mull.o \
       gen207/6/ut_nest.o \
       gen207/6/ut_park.o \
       gen207/6/ut_peek.o \
       gen207/6/ut_play.o \
       gen207/6/ut_repo.o \
       gen207/6/ut_rest.o \
       gen207/6/ut_seek.o \
       gen207/6/ut_snap.o \
       gen207/6/ut_swab.o \
       gen207/6/ut_tack.o \
       gen207/6/ut_tock.o \
       gen207/6/ut_wrap.o

J207_OFILES=\
       $(J207_1_OFILES) \
       $(J207_2_OFILES) \
       $(J207_3_OFILES) \
       $(J207_4_OFILES) \
       $(J207_5_OFILES) \
       $(J207_6_OFILES) \
       $(J207_6_OFILES_UT) \
       gen207/watt.o

J206_1_OFILES=\
       gen206/1/add.o \
       gen206/1/dec.o \
       gen206/1/div.o \
       gen206/1/gte.o \
       gen206/1/gth.o \
       gen206/1/lte.o \
       gen206/1/lth.o \
       gen206/1/mod.o \
       gen206/1/mul.o \
       gen206/1/sub.o

J206_2_OFILES=\
       gen206/2/bind.o \
       gen206/2/clap.o \
       gen206/2/drop.o \
       gen206/2/flop.o \
       gen206/2/lent.o \
       gen206/2/levy.o \
       gen206/2/lien.o \
       gen206/2/need.o \
       gen206/2/reel.o \
       gen206/2/roll.o \
       gen206/2/skim.o \
       gen206/2/skip.o \
       gen206/2/slag.o \
       gen206/2/snag.o \
       gen206/2/sort.o \
       gen206/2/turn.o \
       gen206/2/weld.o

J206_3_OFILES=\
       gen206/3/bex.o \
       gen206/3/can.o \
       gen206/3/cap.o \
       gen206/3/cat.o \
       gen206/3/con.o \
       gen206/3/cut.o \
       gen206/3/dor.o \
       gen206/3/dis.o \
       gen206/3/end.o \
       gen206/3/gor.o \
       gen206/3/hor.o \
       gen206/3/lsh.o \
       gen206/3/mas.o \
       gen206/3/met.o \
       gen206/3/mix.o \
       gen206/3/mug.o \
       gen206/3/peg.o \
       gen206/3/rap.o \
       gen206/3/rip.o \
       gen206/3/rsh.o \
       gen206/3/vor.o

J206_4_OFILES=\
       gen206/4/in.o \
       gen206/4/by.o \
       gen206/4/in_has.o \
       gen206/4/in_gas.o \
       gen206/4/in_put.o \
       gen206/4/in_tap.o \
       gen206/4/by_gas.o \
       gen206/4/by_get.o \
       gen206/4/by_has.o \
       gen206/4/by_put.o 

J206_5_OFILES=\
       gen206/5/cue.o \
       gen206/5/jam.o \
       gen206/5/mat.o \
       gen206/5/mock.o \
       gen206/5/parse.o \
       gen206/5/rub.o \
       gen206/5/shax.o \
       gen206/5/trip.o

J206_6_OFILES=\
       gen206/6/ap.o \
       gen206/6/cell.o \
       gen206/6/comb.o \
       gen206/6/cons.o \
       gen206/6/core.o \
       gen206/6/cube.o \
       gen206/6/face.o \
       gen206/6/fine.o \
       gen206/6/fitz.o \
       gen206/6/flan.o \
       gen206/6/flip.o \
       gen206/6/flor.o \
       gen206/6/foam.o \
       gen206/6/fork.o \
       gen206/6/hike.o \
       gen206/6/look.o \
       gen206/6/ut.o

J206_6_OFILES_UT=\
       gen206/6/ut_burn.o \
       gen206/6/ut_bust.o \
       gen206/6/ut_crop.o \
       gen206/6/ut_cull.o \
       gen206/6/ut_find.o \
       gen206/6/ut_fink.o \
       gen206/6/ut_fire.o \
       gen206/6/ut_firm.o \
       gen206/6/ut_fish.o \
       gen206/6/ut_fuse.o \
       gen206/6/ut_gain.o \
       gen206/6/ut_heal.o \
       gen206/6/ut_lose.o \
       gen206/6/ut_mint.o \
       gen206/6/ut_moot.o \
       gen206/6/ut_mull.o \
       gen206/6/ut_nest.o \
       gen206/6/ut_park.o \
       gen206/6/ut_peek.o \
       gen206/6/ut_play.o \
       gen206/6/ut_repo.o \
       gen206/6/ut_rest.o \
       gen206/6/ut_seek.o \
       gen206/6/ut_snap.o \
       gen206/6/ut_swab.o \
       gen206/6/ut_tack.o \
       gen206/6/ut_tock.o \
       gen206/6/ut_wrap.o

J206_OFILES=\
       $(J206_1_OFILES) \
       $(J206_2_OFILES) \
       $(J206_3_OFILES) \
       $(J206_4_OFILES) \
       $(J206_5_OFILES) \
       $(J206_6_OFILES) \
       $(J206_6_OFILES_UT) \
       gen206/watt.o

J205_1_OFILES=\
       gen205/1/add.o \
       gen205/1/dec.o \
       gen205/1/div.o \
       gen205/1/gte.o \
       gen205/1/gth.o \
       gen205/1/lte.o \
       gen205/1/lth.o \
       gen205/1/mod.o \
       gen205/1/mul.o \
       gen205/1/sub.o

J205_2_OFILES=\
       gen205/2/bind.o \
       gen205/2/clap.o \
       gen205/2/drop.o \
       gen205/2/flop.o \
       gen205/2/lent.o \
       gen205/2/levy.o \
       gen205/2/lien.o \
       gen205/2/need.o \
       gen205/2/reel.o \
       gen205/2/roll.o \
       gen205/2/skim.o \
       gen205/2/skip.o \
       gen205/2/slag.o \
       gen205/2/snag.o \
       gen205/2/sort.o \
       gen205/2/turn.o \
       gen205/2/weld.o

J205_3_OFILES=\
       gen205/3/bex.o \
       gen205/3/can.o \
       gen205/3/cap.o \
       gen205/3/cat.o \
       gen205/3/con.o \
       gen205/3/cut.o \
       gen205/3/dor.o \
       gen205/3/dis.o \
       gen205/3/end.o \
       gen205/3/gor.o \
       gen205/3/hor.o \
       gen205/3/lsh.o \
       gen205/3/mas.o \
       gen205/3/met.o \
       gen205/3/mix.o \
       gen205/3/mug.o \
       gen205/3/peg.o \
       gen205/3/rap.o \
       gen205/3/rip.o \
       gen205/3/rsh.o \
       gen205/3/vor.o

J205_4_OFILES=\
       gen205/4/in.o \
       gen205/4/by.o \
       gen205/4/in_has.o \
       gen205/4/in_gas.o \
       gen205/4/in_put.o \
       gen205/4/in_tap.o \
       gen205/4/by_gas.o \
       gen205/4/by_get.o \
       gen205/4/by_has.o \
       gen205/4/by_put.o 

J205_5_OFILES=\
       gen205/5/cue.o \
       gen205/5/jam.o \
       gen205/5/mat.o \
       gen205/5/mock.o \
       gen205/5/parse.o \
       gen205/5/rub.o \
       gen205/5/shax.o \
       gen205/5/trip.o

J205_6_OFILES=\
       gen205/6/ap.o \
       gen205/6/cell.o \
       gen205/6/comb.o \
       gen205/6/cons.o \
       gen205/6/core.o \
       gen205/6/cube.o \
       gen205/6/face.o \
       gen205/6/fine.o \
       gen205/6/fitz.o \
       gen205/6/flan.o \
       gen205/6/flay.o \
       gen205/6/flip.o \
       gen205/6/flor.o \
       gen205/6/fork.o \
       gen205/6/hike.o \
       gen205/6/look.o \
       gen205/6/ut.o

J205_6_OFILES_UT=\
       gen205/6/ut_burn.o \
       gen205/6/ut_bust.o \
       gen205/6/ut_crop.o \
       gen205/6/ut_cull.o \
       gen205/6/ut_find.o \
       gen205/6/ut_fink.o \
       gen205/6/ut_fire.o \
       gen205/6/ut_firm.o \
       gen205/6/ut_fish.o \
       gen205/6/ut_fuse.o \
       gen205/6/ut_gain.o \
       gen205/6/ut_heal.o \
       gen205/6/ut_lose.o \
       gen205/6/ut_mint.o \
       gen205/6/ut_moot.o \
       gen205/6/ut_mull.o \
       gen205/6/ut_nest.o \
       gen205/6/ut_park.o \
       gen205/6/ut_peek.o \
       gen205/6/ut_play.o \
       gen205/6/ut_repo.o \
       gen205/6/ut_rest.o \
       gen205/6/ut_seek.o \
       gen205/6/ut_snap.o \
       gen205/6/ut_swab.o \
       gen205/6/ut_tack.o \
       gen205/6/ut_tock.o \
       gen205/6/ut_wrap.o

J205_OFILES=\
       $(J205_1_OFILES) \
       $(J205_2_OFILES) \
       $(J205_3_OFILES) \
       $(J205_4_OFILES) \
       $(J205_5_OFILES) \
       $(J205_6_OFILES) \
       $(J205_6_OFILES_UT) \
       gen205/watt.o

J204_1_OFILES=\
       gen204/1/add.o \
       gen204/1/dec.o \
       gen204/1/div.o \
       gen204/1/gte.o \
       gen204/1/gth.o \
       gen204/1/lte.o \
       gen204/1/lth.o \
       gen204/1/mod.o \
       gen204/1/mul.o \
       gen204/1/sub.o

J204_2_OFILES=\
       gen204/2/bind.o \
       gen204/2/clap.o \
       gen204/2/drop.o \
       gen204/2/flop.o \
       gen204/2/lent.o \
       gen204/2/levy.o \
       gen204/2/lien.o \
       gen204/2/need.o \
       gen204/2/reel.o \
       gen204/2/roll.o \
       gen204/2/skim.o \
       gen204/2/skip.o \
       gen204/2/slag.o \
       gen204/2/snag.o \
       gen204/2/sort.o \
       gen204/2/turn.o \
       gen204/2/weld.o

J204_3_OFILES=\
       gen204/3/bex.o \
       gen204/3/can.o \
       gen204/3/cap.o \
       gen204/3/cat.o \
       gen204/3/con.o \
       gen204/3/cut.o \
       gen204/3/dor.o \
       gen204/3/dis.o \
       gen204/3/end.o \
       gen204/3/gor.o \
       gen204/3/hor.o \
       gen204/3/lsh.o \
       gen204/3/mas.o \
       gen204/3/met.o \
       gen204/3/mix.o \
       gen204/3/mug.o \
       gen204/3/peg.o \
       gen204/3/rap.o \
       gen204/3/rip.o \
       gen204/3/rsh.o \
       gen204/3/vor.o

J204_4_OFILES=\
       gen204/4/in.o \
       gen204/4/by.o \
       gen204/4/in_has.o \
       gen204/4/in_gas.o \
       gen204/4/in_put.o \
       gen204/4/in_tap.o \
       gen204/4/by_gas.o \
       gen204/4/by_get.o \
       gen204/4/by_has.o \
       gen204/4/by_put.o 

J204_5_OFILES=\
       gen204/5/cue.o \
       gen204/5/jam.o \
       gen204/5/mat.o \
       gen204/5/mock.o \
       gen204/5/parse.o \
       gen204/5/rub.o \
       gen204/5/shax.o \
       gen204/5/trip.o

J204_6_OFILES=\
       gen204/6/ap.o \
       gen204/6/cell.o \
       gen204/6/comb.o \
       gen204/6/cons.o \
       gen204/6/core.o \
       gen204/6/cube.o \
       gen204/6/face.o \
       gen204/6/fine.o \
       gen204/6/fitz.o \
       gen204/6/flan.o \
       gen204/6/flay.o \
       gen204/6/flip.o \
       gen204/6/flor.o \
       gen204/6/fork.o \
       gen204/6/hike.o \
       gen204/6/look.o \
       gen204/6/ut.o

J204_6_OFILES_UT=\
       gen204/6/ut_burn.o \
       gen204/6/ut_bust.o \
       gen204/6/ut_crop.o \
       gen204/6/ut_cull.o \
       gen204/6/ut_find.o \
       gen204/6/ut_fink.o \
       gen204/6/ut_fire.o \
       gen204/6/ut_firm.o \
       gen204/6/ut_fish.o \
       gen204/6/ut_fuse.o \
       gen204/6/ut_gain.o \
       gen204/6/ut_heal.o \
       gen204/6/ut_lose.o \
       gen204/6/ut_mint.o \
       gen204/6/ut_moot.o \
       gen204/6/ut_mull.o \
       gen204/6/ut_nest.o \
       gen204/6/ut_park.o \
       gen204/6/ut_peek.o \
       gen204/6/ut_play.o \
       gen204/6/ut_repo.o \
       gen204/6/ut_rest.o \
       gen204/6/ut_seek.o \
       gen204/6/ut_snap.o \
       gen204/6/ut_swab.o \
       gen204/6/ut_tack.o \
       gen204/6/ut_tock.o \
       gen204/6/ut_wrap.o

J204_OFILES=\
       $(J204_1_OFILES) \
       $(J204_2_OFILES) \
       $(J204_3_OFILES) \
       $(J204_4_OFILES) \
       $(J204_5_OFILES) \
       $(J204_6_OFILES) \
       $(J204_6_OFILES_UT) \
       gen204/watt.o

J203_1_OFILES=\
       gen203/1/add.o \
       gen203/1/dec.o \
       gen203/1/div.o \
       gen203/1/gte.o \
       gen203/1/gth.o \
       gen203/1/lte.o \
       gen203/1/lth.o \
       gen203/1/mod.o \
       gen203/1/mul.o \
       gen203/1/sub.o

J203_2_OFILES=\
       gen203/2/bind.o \
       gen203/2/clap.o \
       gen203/2/drop.o \
       gen203/2/flop.o \
       gen203/2/lent.o \
       gen203/2/levy.o \
       gen203/2/lien.o \
       gen203/2/need.o \
       gen203/2/reel.o \
       gen203/2/roll.o \
       gen203/2/skim.o \
       gen203/2/skip.o \
       gen203/2/slag.o \
       gen203/2/snag.o \
       gen203/2/sort.o \
       gen203/2/turn.o \
       gen203/2/weld.o

J203_3_OFILES=\
       gen203/3/bex.o \
       gen203/3/can.o \
       gen203/3/cap.o \
       gen203/3/cat.o \
       gen203/3/con.o \
       gen203/3/cut.o \
       gen203/3/dor.o \
       gen203/3/dis.o \
       gen203/3/end.o \
       gen203/3/gor.o \
       gen203/3/hor.o \
       gen203/3/lsh.o \
       gen203/3/mas.o \
       gen203/3/met.o \
       gen203/3/mix.o \
       gen203/3/mug.o \
       gen203/3/peg.o \
       gen203/3/rap.o \
       gen203/3/rip.o \
       gen203/3/rsh.o \
       gen203/3/vor.o

J203_4_OFILES=\
       gen203/4/in.o \
       gen203/4/by.o \
       gen203/4/in_has.o \
       gen203/4/in_gas.o \
       gen203/4/in_put.o \
       gen203/4/in_tap.o \
       gen203/4/by_gas.o \
       gen203/4/by_get.o \
       gen203/4/by_has.o \
       gen203/4/by_put.o 

J203_5_OFILES=\
       gen203/5/cue.o \
       gen203/5/jam.o \
       gen203/5/mat.o \
       gen203/5/mock.o \
       gen203/5/parse.o \
       gen203/5/rub.o \
       gen203/5/shax.o \
       gen203/5/trip.o

J203_6_OFILES=\
       gen203/6/ap.o \
       gen203/6/cell.o \
       gen203/6/comb.o \
       gen203/6/cons.o \
       gen203/6/core.o \
       gen203/6/cube.o \
       gen203/6/face.o \
       gen203/6/fine.o \
       gen203/6/fitz.o \
       gen203/6/flan.o \
       gen203/6/flay.o \
       gen203/6/flip.o \
       gen203/6/flor.o \
       gen203/6/fork.o \
       gen203/6/hike.o \
       gen203/6/look.o \
       gen203/6/ut.o

J203_6_OFILES_UT=\
       gen203/6/ut_burn.o \
       gen203/6/ut_bust.o \
       gen203/6/ut_crop.o \
       gen203/6/ut_cull.o \
       gen203/6/ut_find.o \
       gen203/6/ut_fink.o \
       gen203/6/ut_fire.o \
       gen203/6/ut_firm.o \
       gen203/6/ut_fish.o \
       gen203/6/ut_fuse.o \
       gen203/6/ut_gain.o \
       gen203/6/ut_heal.o \
       gen203/6/ut_lose.o \
       gen203/6/ut_mint.o \
       gen203/6/ut_moot.o \
       gen203/6/ut_mull.o \
       gen203/6/ut_nest.o \
       gen203/6/ut_park.o \
       gen203/6/ut_peek.o \
       gen203/6/ut_play.o \
       gen203/6/ut_repo.o \
       gen203/6/ut_rest.o \
       gen203/6/ut_seek.o \
       gen203/6/ut_snap.o \
       gen203/6/ut_swab.o \
       gen203/6/ut_tack.o \
       gen203/6/ut_tock.o \
       gen203/6/ut_wrap.o

J203_OFILES=\
       $(J203_1_OFILES) \
       $(J203_2_OFILES) \
       $(J203_3_OFILES) \
       $(J203_4_OFILES) \
       $(J203_5_OFILES) \
       $(J203_6_OFILES) \
       $(J203_6_OFILES_UT) \
       gen203/watt.o

BASE_OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J205_OFILES) \
       $(J204_OFILES) \
       $(J203_OFILES)

OUT_OFILES=\
       outside/jhttp/http_parser.o

VERE_OFILES=\
       v/boot.o \
       v/fs.o \
       v/main.o \
       v/console.o \
       v/system.o \
       v/http.o \
       c/gunn.o \
       $(BASE_OFILES) \
       $(OUT_OFILES)

all: $(BIN)/vere

$(BIN)/vere: $(VERE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/vere $(VERE_OFILES) -lev -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(VERE_OFILES) $(BIN)/vere $(BIN)/eyre
