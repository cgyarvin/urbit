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

J220_1_OFILES=\
       gen220/1/add.o \
       gen220/1/dec.o \
       gen220/1/div.o \
       gen220/1/gte.o \
       gen220/1/gth.o \
       gen220/1/lte.o \
       gen220/1/lth.o \
       gen220/1/mod.o \
       gen220/1/mul.o \
       gen220/1/sub.o

J220_2_OFILES=\
       gen220/2/bind.o \
       gen220/2/clap.o \
       gen220/2/drop.o \
       gen220/2/flop.o \
       gen220/2/lent.o \
       gen220/2/levy.o \
       gen220/2/lien.o \
       gen220/2/need.o \
       gen220/2/reel.o \
       gen220/2/roll.o \
       gen220/2/skim.o \
       gen220/2/skip.o \
       gen220/2/slag.o \
       gen220/2/snag.o \
       gen220/2/sort.o \
       gen220/2/turn.o \
       gen220/2/weld.o

J220_3_OFILES=\
       gen220/3/bex.o \
       gen220/3/can.o \
       gen220/3/cap.o \
       gen220/3/cat.o \
       gen220/3/con.o \
       gen220/3/cut.o \
       gen220/3/dor.o \
       gen220/3/dis.o \
       gen220/3/end.o \
       gen220/3/gor.o \
       gen220/3/hor.o \
       gen220/3/lsh.o \
       gen220/3/mas.o \
       gen220/3/met.o \
       gen220/3/mix.o \
       gen220/3/mug.o \
       gen220/3/peg.o \
       gen220/3/rap.o \
       gen220/3/rip.o \
       gen220/3/rsh.o \
       gen220/3/vor.o

J220_4_OFILES=\
       gen220/4/in.o \
       gen220/4/by.o \
       gen220/4/in_has.o \
       gen220/4/in_gas.o \
       gen220/4/in_put.o \
       gen220/4/in_tap.o \
       gen220/4/by_gas.o \
       gen220/4/by_get.o \
       gen220/4/by_has.o \
       gen220/4/by_put.o 

J220_5_OFILES=\
       gen220/5/cue.o \
       gen220/5/jam.o \
       gen220/5/mat.o \
       gen220/5/parse.o \
       gen220/5/rub.o \
       gen220/5/shax.o \
       gen220/5/trip.o

J220_6_OFILES=\
       gen220/6/ap.o \
       gen220/6/cell.o \
       gen220/6/comb.o \
       gen220/6/cons.o \
       gen220/6/core.o \
       gen220/6/cube.o \
       gen220/6/face.o \
       gen220/6/fine.o \
       gen220/6/flan.o \
       gen220/6/flip.o \
       gen220/6/flor.o \
       gen220/6/foam.o \
       gen220/6/fork.o \
       gen220/6/hike.o \
       gen220/6/look.o \
       gen220/6/ut.o

J220_6_OFILES_UT=\
       gen220/6/ut_burn.o \
       gen220/6/ut_bust.o \
       gen220/6/ut_crop.o \
       gen220/6/ut_cull.o \
       gen220/6/ut_find.o \
       gen220/6/ut_fink.o \
       gen220/6/ut_fire.o \
       gen220/6/ut_firm.o \
       gen220/6/ut_fish.o \
       gen220/6/ut_fuse.o \
       gen220/6/ut_gain.o \
       gen220/6/ut_heal.o \
       gen220/6/ut_lose.o \
       gen220/6/ut_mint.o \
       gen220/6/ut_moot.o \
       gen220/6/ut_mull.o \
       gen220/6/ut_nest.o \
       gen220/6/ut_park.o \
       gen220/6/ut_peek.o \
       gen220/6/ut_play.o \
       gen220/6/ut_repo.o \
       gen220/6/ut_rest.o \
       gen220/6/ut_seek.o \
       gen220/6/ut_snap.o \
       gen220/6/ut_swab.o \
       gen220/6/ut_tack.o \
       gen220/6/ut_tock.o \
       gen220/6/ut_wrap.o

J220_OFILES=\
       $(J220_1_OFILES) \
       $(J220_2_OFILES) \
       $(J220_3_OFILES) \
       $(J220_4_OFILES) \
       $(J220_5_OFILES) \
       $(J220_6_OFILES) \
       $(J220_6_OFILES_UT) \
       gen220/watt.o

J219_1_OFILES=\
       gen219/1/add.o \
       gen219/1/dec.o \
       gen219/1/div.o \
       gen219/1/gte.o \
       gen219/1/gth.o \
       gen219/1/lte.o \
       gen219/1/lth.o \
       gen219/1/mod.o \
       gen219/1/mul.o \
       gen219/1/sub.o

J219_2_OFILES=\
       gen219/2/bind.o \
       gen219/2/clap.o \
       gen219/2/drop.o \
       gen219/2/flop.o \
       gen219/2/lent.o \
       gen219/2/levy.o \
       gen219/2/lien.o \
       gen219/2/need.o \
       gen219/2/reel.o \
       gen219/2/roll.o \
       gen219/2/skim.o \
       gen219/2/skip.o \
       gen219/2/slag.o \
       gen219/2/snag.o \
       gen219/2/sort.o \
       gen219/2/turn.o \
       gen219/2/weld.o

J219_3_OFILES=\
       gen219/3/bex.o \
       gen219/3/can.o \
       gen219/3/cap.o \
       gen219/3/cat.o \
       gen219/3/con.o \
       gen219/3/cut.o \
       gen219/3/dor.o \
       gen219/3/dis.o \
       gen219/3/end.o \
       gen219/3/gor.o \
       gen219/3/hor.o \
       gen219/3/lsh.o \
       gen219/3/mas.o \
       gen219/3/met.o \
       gen219/3/mix.o \
       gen219/3/mug.o \
       gen219/3/peg.o \
       gen219/3/rap.o \
       gen219/3/rip.o \
       gen219/3/rsh.o \
       gen219/3/vor.o

J219_4_OFILES=\
       gen219/4/in.o \
       gen219/4/by.o \
       gen219/4/in_has.o \
       gen219/4/in_gas.o \
       gen219/4/in_put.o \
       gen219/4/in_tap.o \
       gen219/4/by_gas.o \
       gen219/4/by_get.o \
       gen219/4/by_has.o \
       gen219/4/by_put.o 

J219_5_OFILES=\
       gen219/5/cue.o \
       gen219/5/jam.o \
       gen219/5/mat.o \
       gen219/5/mock.o \
       gen219/5/parse.o \
       gen219/5/rub.o \
       gen219/5/shax.o \
       gen219/5/trip.o

J219_6_OFILES=\
       gen219/6/ap.o \
       gen219/6/cell.o \
       gen219/6/comb.o \
       gen219/6/cons.o \
       gen219/6/core.o \
       gen219/6/cube.o \
       gen219/6/face.o \
       gen219/6/fine.o \
       gen219/6/flan.o \
       gen219/6/flip.o \
       gen219/6/flor.o \
       gen219/6/foam.o \
       gen219/6/fork.o \
       gen219/6/hike.o \
       gen219/6/look.o \
       gen219/6/ut.o

J219_6_OFILES_UT=\
       gen219/6/ut_burn.o \
       gen219/6/ut_bust.o \
       gen219/6/ut_crop.o \
       gen219/6/ut_cull.o \
       gen219/6/ut_find.o \
       gen219/6/ut_fink.o \
       gen219/6/ut_fire.o \
       gen219/6/ut_firm.o \
       gen219/6/ut_fish.o \
       gen219/6/ut_fuse.o \
       gen219/6/ut_gain.o \
       gen219/6/ut_heal.o \
       gen219/6/ut_lose.o \
       gen219/6/ut_mint.o \
       gen219/6/ut_moot.o \
       gen219/6/ut_mull.o \
       gen219/6/ut_nest.o \
       gen219/6/ut_park.o \
       gen219/6/ut_peek.o \
       gen219/6/ut_play.o \
       gen219/6/ut_repo.o \
       gen219/6/ut_rest.o \
       gen219/6/ut_seek.o \
       gen219/6/ut_snap.o \
       gen219/6/ut_swab.o \
       gen219/6/ut_tack.o \
       gen219/6/ut_tock.o \
       gen219/6/ut_wrap.o

J219_OFILES=\
       $(J219_1_OFILES) \
       $(J219_2_OFILES) \
       $(J219_3_OFILES) \
       $(J219_4_OFILES) \
       $(J219_5_OFILES) \
       $(J219_6_OFILES) \
       $(J219_6_OFILES_UT) \
       gen219/watt.o

J218_1_OFILES=\
       gen218/1/add.o \
       gen218/1/dec.o \
       gen218/1/div.o \
       gen218/1/gte.o \
       gen218/1/gth.o \
       gen218/1/lte.o \
       gen218/1/lth.o \
       gen218/1/mod.o \
       gen218/1/mul.o \
       gen218/1/sub.o

J218_2_OFILES=\
       gen218/2/bind.o \
       gen218/2/clap.o \
       gen218/2/drop.o \
       gen218/2/flop.o \
       gen218/2/lent.o \
       gen218/2/levy.o \
       gen218/2/lien.o \
       gen218/2/need.o \
       gen218/2/reel.o \
       gen218/2/roll.o \
       gen218/2/skim.o \
       gen218/2/skip.o \
       gen218/2/slag.o \
       gen218/2/snag.o \
       gen218/2/sort.o \
       gen218/2/turn.o \
       gen218/2/weld.o

J218_3_OFILES=\
       gen218/3/bex.o \
       gen218/3/can.o \
       gen218/3/cap.o \
       gen218/3/cat.o \
       gen218/3/con.o \
       gen218/3/cut.o \
       gen218/3/dor.o \
       gen218/3/dis.o \
       gen218/3/end.o \
       gen218/3/gor.o \
       gen218/3/hor.o \
       gen218/3/lsh.o \
       gen218/3/mas.o \
       gen218/3/met.o \
       gen218/3/mix.o \
       gen218/3/mug.o \
       gen218/3/peg.o \
       gen218/3/rap.o \
       gen218/3/rip.o \
       gen218/3/rsh.o \
       gen218/3/vor.o

J218_4_OFILES=\
       gen218/4/in.o \
       gen218/4/by.o \
       gen218/4/in_has.o \
       gen218/4/in_gas.o \
       gen218/4/in_put.o \
       gen218/4/in_tap.o \
       gen218/4/by_gas.o \
       gen218/4/by_get.o \
       gen218/4/by_has.o \
       gen218/4/by_put.o 

J218_5_OFILES=\
       gen218/5/cue.o \
       gen218/5/jam.o \
       gen218/5/mat.o \
       gen218/5/mock.o \
       gen218/5/parse.o \
       gen218/5/rub.o \
       gen218/5/shax.o \
       gen218/5/trip.o

J218_6_OFILES=\
       gen218/6/ap.o \
       gen218/6/cell.o \
       gen218/6/comb.o \
       gen218/6/cons.o \
       gen218/6/core.o \
       gen218/6/cube.o \
       gen218/6/face.o \
       gen218/6/fine.o \
       gen218/6/flan.o \
       gen218/6/flip.o \
       gen218/6/flor.o \
       gen218/6/foam.o \
       gen218/6/fork.o \
       gen218/6/hike.o \
       gen218/6/look.o \
       gen218/6/ut.o

J218_6_OFILES_UT=\
       gen218/6/ut_burn.o \
       gen218/6/ut_bust.o \
       gen218/6/ut_crop.o \
       gen218/6/ut_cull.o \
       gen218/6/ut_find.o \
       gen218/6/ut_fink.o \
       gen218/6/ut_fire.o \
       gen218/6/ut_firm.o \
       gen218/6/ut_fish.o \
       gen218/6/ut_fuse.o \
       gen218/6/ut_gain.o \
       gen218/6/ut_heal.o \
       gen218/6/ut_lose.o \
       gen218/6/ut_mint.o \
       gen218/6/ut_moot.o \
       gen218/6/ut_mull.o \
       gen218/6/ut_nest.o \
       gen218/6/ut_park.o \
       gen218/6/ut_peek.o \
       gen218/6/ut_play.o \
       gen218/6/ut_repo.o \
       gen218/6/ut_rest.o \
       gen218/6/ut_seek.o \
       gen218/6/ut_snap.o \
       gen218/6/ut_swab.o \
       gen218/6/ut_tack.o \
       gen218/6/ut_tock.o \
       gen218/6/ut_wrap.o

J218_OFILES=\
       $(J218_1_OFILES) \
       $(J218_2_OFILES) \
       $(J218_3_OFILES) \
       $(J218_4_OFILES) \
       $(J218_5_OFILES) \
       $(J218_6_OFILES) \
       $(J218_6_OFILES_UT) \
       gen218/watt.o

J217_1_OFILES=\
       gen217/1/add.o \
       gen217/1/dec.o \
       gen217/1/div.o \
       gen217/1/gte.o \
       gen217/1/gth.o \
       gen217/1/lte.o \
       gen217/1/lth.o \
       gen217/1/mod.o \
       gen217/1/mul.o \
       gen217/1/sub.o

J217_2_OFILES=\
       gen217/2/bind.o \
       gen217/2/clap.o \
       gen217/2/drop.o \
       gen217/2/flop.o \
       gen217/2/lent.o \
       gen217/2/levy.o \
       gen217/2/lien.o \
       gen217/2/need.o \
       gen217/2/reel.o \
       gen217/2/roll.o \
       gen217/2/skim.o \
       gen217/2/skip.o \
       gen217/2/slag.o \
       gen217/2/snag.o \
       gen217/2/sort.o \
       gen217/2/turn.o \
       gen217/2/weld.o

J217_3_OFILES=\
       gen217/3/bex.o \
       gen217/3/can.o \
       gen217/3/cap.o \
       gen217/3/cat.o \
       gen217/3/con.o \
       gen217/3/cut.o \
       gen217/3/dor.o \
       gen217/3/dis.o \
       gen217/3/end.o \
       gen217/3/gor.o \
       gen217/3/hor.o \
       gen217/3/lsh.o \
       gen217/3/mas.o \
       gen217/3/met.o \
       gen217/3/mix.o \
       gen217/3/mug.o \
       gen217/3/peg.o \
       gen217/3/rap.o \
       gen217/3/rip.o \
       gen217/3/rsh.o \
       gen217/3/vor.o

J217_4_OFILES=\
       gen217/4/in.o \
       gen217/4/by.o \
       gen217/4/in_has.o \
       gen217/4/in_gas.o \
       gen217/4/in_put.o \
       gen217/4/in_tap.o \
       gen217/4/by_gas.o \
       gen217/4/by_get.o \
       gen217/4/by_has.o \
       gen217/4/by_put.o 

J217_5_OFILES=\
       gen217/5/cue.o \
       gen217/5/jam.o \
       gen217/5/mat.o \
       gen217/5/mock.o \
       gen217/5/parse.o \
       gen217/5/rub.o \
       gen217/5/shax.o \
       gen217/5/trip.o

J217_6_OFILES=\
       gen217/6/ap.o \
       gen217/6/cell.o \
       gen217/6/comb.o \
       gen217/6/cons.o \
       gen217/6/core.o \
       gen217/6/cube.o \
       gen217/6/face.o \
       gen217/6/fine.o \
       gen217/6/flan.o \
       gen217/6/flip.o \
       gen217/6/flor.o \
       gen217/6/foam.o \
       gen217/6/fork.o \
       gen217/6/hike.o \
       gen217/6/look.o \
       gen217/6/ut.o

J217_6_OFILES_UT=\
       gen217/6/ut_burn.o \
       gen217/6/ut_bust.o \
       gen217/6/ut_crop.o \
       gen217/6/ut_cull.o \
       gen217/6/ut_find.o \
       gen217/6/ut_fink.o \
       gen217/6/ut_fire.o \
       gen217/6/ut_firm.o \
       gen217/6/ut_fish.o \
       gen217/6/ut_fuse.o \
       gen217/6/ut_gain.o \
       gen217/6/ut_heal.o \
       gen217/6/ut_lose.o \
       gen217/6/ut_mint.o \
       gen217/6/ut_moot.o \
       gen217/6/ut_mull.o \
       gen217/6/ut_nest.o \
       gen217/6/ut_park.o \
       gen217/6/ut_peek.o \
       gen217/6/ut_play.o \
       gen217/6/ut_repo.o \
       gen217/6/ut_rest.o \
       gen217/6/ut_seek.o \
       gen217/6/ut_snap.o \
       gen217/6/ut_swab.o \
       gen217/6/ut_tack.o \
       gen217/6/ut_tock.o \
       gen217/6/ut_wrap.o

J217_OFILES=\
       $(J217_1_OFILES) \
       $(J217_2_OFILES) \
       $(J217_3_OFILES) \
       $(J217_4_OFILES) \
       $(J217_5_OFILES) \
       $(J217_6_OFILES) \
       $(J217_6_OFILES_UT) \
       gen217/watt.o

J216_1_OFILES=\
       gen216/1/add.o \
       gen216/1/dec.o \
       gen216/1/div.o \
       gen216/1/gte.o \
       gen216/1/gth.o \
       gen216/1/lte.o \
       gen216/1/lth.o \
       gen216/1/mod.o \
       gen216/1/mul.o \
       gen216/1/sub.o

J216_2_OFILES=\
       gen216/2/bind.o \
       gen216/2/clap.o \
       gen216/2/drop.o \
       gen216/2/flop.o \
       gen216/2/lent.o \
       gen216/2/levy.o \
       gen216/2/lien.o \
       gen216/2/need.o \
       gen216/2/reel.o \
       gen216/2/roll.o \
       gen216/2/skim.o \
       gen216/2/skip.o \
       gen216/2/slag.o \
       gen216/2/snag.o \
       gen216/2/sort.o \
       gen216/2/turn.o \
       gen216/2/weld.o

J216_3_OFILES=\
       gen216/3/bex.o \
       gen216/3/can.o \
       gen216/3/cap.o \
       gen216/3/cat.o \
       gen216/3/con.o \
       gen216/3/cut.o \
       gen216/3/dor.o \
       gen216/3/dis.o \
       gen216/3/end.o \
       gen216/3/gor.o \
       gen216/3/hor.o \
       gen216/3/lsh.o \
       gen216/3/mas.o \
       gen216/3/met.o \
       gen216/3/mix.o \
       gen216/3/mug.o \
       gen216/3/peg.o \
       gen216/3/rap.o \
       gen216/3/rip.o \
       gen216/3/rsh.o \
       gen216/3/vor.o

J216_4_OFILES=\
       gen216/4/in.o \
       gen216/4/by.o \
       gen216/4/in_has.o \
       gen216/4/in_gas.o \
       gen216/4/in_put.o \
       gen216/4/in_tap.o \
       gen216/4/by_gas.o \
       gen216/4/by_get.o \
       gen216/4/by_has.o \
       gen216/4/by_put.o 

J216_5_OFILES=\
       gen216/5/cue.o \
       gen216/5/jam.o \
       gen216/5/mat.o \
       gen216/5/mock.o \
       gen216/5/parse.o \
       gen216/5/rub.o \
       gen216/5/shax.o \
       gen216/5/trip.o

J216_6_OFILES=\
       gen216/6/ap.o \
       gen216/6/cell.o \
       gen216/6/comb.o \
       gen216/6/cons.o \
       gen216/6/core.o \
       gen216/6/cube.o \
       gen216/6/face.o \
       gen216/6/fine.o \
       gen216/6/flan.o \
       gen216/6/flip.o \
       gen216/6/flor.o \
       gen216/6/foam.o \
       gen216/6/fork.o \
       gen216/6/hike.o \
       gen216/6/look.o \
       gen216/6/ut.o

J216_6_OFILES_UT=\
       gen216/6/ut_burn.o \
       gen216/6/ut_bust.o \
       gen216/6/ut_crop.o \
       gen216/6/ut_cull.o \
       gen216/6/ut_find.o \
       gen216/6/ut_fink.o \
       gen216/6/ut_fire.o \
       gen216/6/ut_firm.o \
       gen216/6/ut_fish.o \
       gen216/6/ut_fuse.o \
       gen216/6/ut_gain.o \
       gen216/6/ut_heal.o \
       gen216/6/ut_lose.o \
       gen216/6/ut_mint.o \
       gen216/6/ut_moot.o \
       gen216/6/ut_mull.o \
       gen216/6/ut_nest.o \
       gen216/6/ut_park.o \
       gen216/6/ut_peek.o \
       gen216/6/ut_play.o \
       gen216/6/ut_repo.o \
       gen216/6/ut_rest.o \
       gen216/6/ut_seek.o \
       gen216/6/ut_snap.o \
       gen216/6/ut_swab.o \
       gen216/6/ut_tack.o \
       gen216/6/ut_tock.o \
       gen216/6/ut_wrap.o

J216_OFILES=\
       $(J216_1_OFILES) \
       $(J216_2_OFILES) \
       $(J216_3_OFILES) \
       $(J216_4_OFILES) \
       $(J216_5_OFILES) \
       $(J216_6_OFILES) \
       $(J216_6_OFILES_UT) \
       gen216/watt.o

J215_1_OFILES=\
       gen215/1/add.o \
       gen215/1/dec.o \
       gen215/1/div.o \
       gen215/1/gte.o \
       gen215/1/gth.o \
       gen215/1/lte.o \
       gen215/1/lth.o \
       gen215/1/mod.o \
       gen215/1/mul.o \
       gen215/1/sub.o

J215_2_OFILES=\
       gen215/2/bind.o \
       gen215/2/clap.o \
       gen215/2/drop.o \
       gen215/2/flop.o \
       gen215/2/lent.o \
       gen215/2/levy.o \
       gen215/2/lien.o \
       gen215/2/need.o \
       gen215/2/reel.o \
       gen215/2/roll.o \
       gen215/2/skim.o \
       gen215/2/skip.o \
       gen215/2/slag.o \
       gen215/2/snag.o \
       gen215/2/sort.o \
       gen215/2/turn.o \
       gen215/2/weld.o

J215_3_OFILES=\
       gen215/3/bex.o \
       gen215/3/can.o \
       gen215/3/cap.o \
       gen215/3/cat.o \
       gen215/3/con.o \
       gen215/3/cut.o \
       gen215/3/dor.o \
       gen215/3/dis.o \
       gen215/3/end.o \
       gen215/3/gor.o \
       gen215/3/hor.o \
       gen215/3/lsh.o \
       gen215/3/mas.o \
       gen215/3/met.o \
       gen215/3/mix.o \
       gen215/3/mug.o \
       gen215/3/peg.o \
       gen215/3/rap.o \
       gen215/3/rip.o \
       gen215/3/rsh.o \
       gen215/3/vor.o

J215_4_OFILES=\
       gen215/4/in.o \
       gen215/4/by.o \
       gen215/4/in_has.o \
       gen215/4/in_gas.o \
       gen215/4/in_put.o \
       gen215/4/in_tap.o \
       gen215/4/by_gas.o \
       gen215/4/by_get.o \
       gen215/4/by_has.o \
       gen215/4/by_put.o 

J215_5_OFILES=\
       gen215/5/cue.o \
       gen215/5/jam.o \
       gen215/5/mat.o \
       gen215/5/mock.o \
       gen215/5/parse.o \
       gen215/5/rub.o \
       gen215/5/shax.o \
       gen215/5/trip.o

J215_6_OFILES=\
       gen215/6/ap.o \
       gen215/6/cell.o \
       gen215/6/comb.o \
       gen215/6/cons.o \
       gen215/6/core.o \
       gen215/6/cube.o \
       gen215/6/face.o \
       gen215/6/fine.o \
       gen215/6/flan.o \
       gen215/6/flip.o \
       gen215/6/flor.o \
       gen215/6/foam.o \
       gen215/6/fork.o \
       gen215/6/hike.o \
       gen215/6/look.o \
       gen215/6/ut.o

J215_6_OFILES_UT=\
       gen215/6/ut_burn.o \
       gen215/6/ut_bust.o \
       gen215/6/ut_crop.o \
       gen215/6/ut_cull.o \
       gen215/6/ut_find.o \
       gen215/6/ut_fink.o \
       gen215/6/ut_fire.o \
       gen215/6/ut_firm.o \
       gen215/6/ut_fish.o \
       gen215/6/ut_fuse.o \
       gen215/6/ut_gain.o \
       gen215/6/ut_heal.o \
       gen215/6/ut_lose.o \
       gen215/6/ut_mint.o \
       gen215/6/ut_moot.o \
       gen215/6/ut_mull.o \
       gen215/6/ut_nest.o \
       gen215/6/ut_park.o \
       gen215/6/ut_peek.o \
       gen215/6/ut_play.o \
       gen215/6/ut_repo.o \
       gen215/6/ut_rest.o \
       gen215/6/ut_seek.o \
       gen215/6/ut_snap.o \
       gen215/6/ut_swab.o \
       gen215/6/ut_tack.o \
       gen215/6/ut_tock.o \
       gen215/6/ut_wrap.o

J215_OFILES=\
       $(J215_1_OFILES) \
       $(J215_2_OFILES) \
       $(J215_3_OFILES) \
       $(J215_4_OFILES) \
       $(J215_5_OFILES) \
       $(J215_6_OFILES) \
       $(J215_6_OFILES_UT) \
       gen215/watt.o

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


BASE_OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J217_OFILES) \
       $(J216_OFILES) \
       $(J215_OFILES)

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
