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
BASE_OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J214_OFILES) \
       $(J213_OFILES) \
       $(J212_OFILES) \
       $(J211_OFILES) \
       $(J210_OFILES)

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
