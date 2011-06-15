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
       c/main.o \
       c/hill.o

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
       p/saur.o \
       p/watt.o

J269_1_OFILES=\
       gen269/1/add.o \
       gen269/1/bex.o \
       gen269/1/dec.o \
       gen269/1/div.o \
       gen269/1/gte.o \
       gen269/1/gth.o \
       gen269/1/lte.o \
       gen269/1/lth.o \
       gen269/1/mod.o \
       gen269/1/mul.o \
       gen269/1/sub.o

J269_2_OFILES=\
       gen269/2/bind.o \
       gen269/2/clap.o \
       gen269/2/drop.o \
       gen269/2/flop.o \
       gen269/2/lent.o \
       gen269/2/levy.o \
       gen269/2/lien.o \
       gen269/2/need.o \
       gen269/2/reel.o \
       gen269/2/roll.o \
       gen269/2/skim.o \
       gen269/2/skip.o \
       gen269/2/snag.o \
       gen269/2/sort.o \
       gen269/2/turn.o \
       gen269/2/weld.o

J269_3_OFILES=\
       gen269/3/cap.o \
       gen269/3/cat.o \
       gen269/3/con.o \
       gen269/3/cut.o \
       gen269/3/dor.o \
       gen269/3/dis.o \
       gen269/3/end.o \
       gen269/3/gor.o \
       gen269/3/hor.o \
       gen269/3/lsh.o \
       gen269/3/mas.o \
       gen269/3/met.o \
       gen269/3/mix.o \
       gen269/3/mug.o \
       gen269/3/peg.o \
       gen269/3/rap.o \
       gen269/3/rip.o \
       gen269/3/rsh.o \
       gen269/3/vor.o

J269_4_OFILES=\
       gen269/4/in.o \
       gen269/4/by.o \
       gen269/4/in_has.o \
       gen269/4/in_gas.o \
       gen269/4/in_put.o \
       gen269/4/in_tap.o \
       gen269/4/by_gas.o \
       gen269/4/by_get.o \
       gen269/4/by_has.o \
       gen269/4/by_put.o 

J269_5_OFILES=\
       gen269/5/to.o

J269_6_OFILES=\
       gen269/6/ap.o \
       gen269/6/cell.o \
       gen269/6/comb.o \
       gen269/6/cons.o \
       gen269/6/core.o \
       gen269/6/face.o \
       gen269/6/flan.o \
       gen269/6/flip.o \
       gen269/6/flor.o \
       gen269/6/fork.o \
       gen269/6/hack.o \
       gen269/6/hike.o \
       gen269/6/look.o \
       gen269/6/ream.o \
       gen269/6/ut.o

J269_6_OFILES_UT=\
       gen269/6/ut_bake.o \
       gen269/6/ut_burn.o \
       gen269/6/ut_cull.o \
       gen269/6/ut_edit.o \
       gen269/6/ut_emit.o \
       gen269/6/ut_find.o \
       gen269/6/ut_fire.o \
       gen269/6/ut_fish.o \
       gen269/6/ut_fret.o \
       gen269/6/ut_fuse.o \
       gen269/6/ut_gain.o \
       gen269/6/ut_heal.o \
       gen269/6/ut_mint.o \
       gen269/6/ut_orth.o \
       gen269/6/ut_nest.o \
       gen269/6/ut_park.o \
       gen269/6/ut_peek.o \
       gen269/6/ut_play.o \
       gen269/6/ut_repo.o \
       gen269/6/ut_rest.o \
       gen269/6/ut_seek.o \
       gen269/6/ut_snap.o \
       gen269/6/ut_tuck.o \
       gen269/6/ut_tusk.o

J269_OFILES=\
       $(J269_1_OFILES) \
       $(J269_2_OFILES) \
       $(J269_3_OFILES) \
       $(J269_4_OFILES) \
       $(J269_5_OFILES) \
       $(J269_6_OFILES) \
       $(J269_6_OFILES_UT) \
       gen269/watt.o

J268_1_OFILES=\
       gen268/1/add.o \
       gen268/1/bex.o \
       gen268/1/dec.o \
       gen268/1/div.o \
       gen268/1/gte.o \
       gen268/1/gth.o \
       gen268/1/lte.o \
       gen268/1/lth.o \
       gen268/1/mod.o \
       gen268/1/mul.o \
       gen268/1/sub.o

J268_2_OFILES=\
       gen268/2/bind.o \
       gen268/2/clap.o \
       gen268/2/drop.o \
       gen268/2/flop.o \
       gen268/2/lent.o \
       gen268/2/levy.o \
       gen268/2/lien.o \
       gen268/2/need.o \
       gen268/2/reel.o \
       gen268/2/roll.o \
       gen268/2/skim.o \
       gen268/2/skip.o \
       gen268/2/snag.o \
       gen268/2/sort.o \
       gen268/2/turn.o \
       gen268/2/weld.o

J268_3_OFILES=\
       gen268/3/cap.o \
       gen268/3/cat.o \
       gen268/3/con.o \
       gen268/3/cut.o \
       gen268/3/dor.o \
       gen268/3/dis.o \
       gen268/3/end.o \
       gen268/3/gor.o \
       gen268/3/hor.o \
       gen268/3/lsh.o \
       gen268/3/mas.o \
       gen268/3/met.o \
       gen268/3/mix.o \
       gen268/3/mug.o \
       gen268/3/peg.o \
       gen268/3/rap.o \
       gen268/3/rip.o \
       gen268/3/rsh.o \
       gen268/3/vor.o

J268_4_OFILES=\
       gen268/4/in.o \
       gen268/4/by.o \
       gen268/4/in_has.o \
       gen268/4/in_gas.o \
       gen268/4/in_put.o \
       gen268/4/in_tap.o \
       gen268/4/by_gas.o \
       gen268/4/by_get.o \
       gen268/4/by_has.o \
       gen268/4/by_put.o 

J268_5_OFILES=\
       gen268/5/to.o

J268_6_OFILES=\
       gen268/6/ap.o \
       gen268/6/cell.o \
       gen268/6/comb.o \
       gen268/6/cons.o \
       gen268/6/core.o \
       gen268/6/face.o \
       gen268/6/flan.o \
       gen268/6/flip.o \
       gen268/6/flor.o \
       gen268/6/fork.o \
       gen268/6/hack.o \
       gen268/6/hike.o \
       gen268/6/look.o \
       gen268/6/ream.o \
       gen268/6/ut.o

J268_6_OFILES_UT=\
       gen268/6/ut_bake.o \
       gen268/6/ut_burn.o \
       gen268/6/ut_cull.o \
       gen268/6/ut_emit.o \
       gen268/6/ut_find.o \
       gen268/6/ut_fire.o \
       gen268/6/ut_fish.o \
       gen268/6/ut_fret.o \
       gen268/6/ut_fuse.o \
       gen268/6/ut_gain.o \
       gen268/6/ut_heal.o \
       gen268/6/ut_mint.o \
       gen268/6/ut_orth.o \
       gen268/6/ut_nest.o \
       gen268/6/ut_park.o \
       gen268/6/ut_peek.o \
       gen268/6/ut_play.o \
       gen268/6/ut_repo.o \
       gen268/6/ut_rest.o \
       gen268/6/ut_seek.o \
       gen268/6/ut_snap.o \
       gen268/6/ut_tuck.o

J268_OFILES=\
       $(J268_1_OFILES) \
       $(J268_2_OFILES) \
       $(J268_3_OFILES) \
       $(J268_4_OFILES) \
       $(J268_5_OFILES) \
       $(J268_6_OFILES) \
       $(J268_6_OFILES_UT) \
       gen268/watt.o

J267_1_OFILES=\
       gen267/1/add.o \
       gen267/1/bex.o \
       gen267/1/dec.o \
       gen267/1/div.o \
       gen267/1/gte.o \
       gen267/1/gth.o \
       gen267/1/lte.o \
       gen267/1/lth.o \
       gen267/1/mod.o \
       gen267/1/mul.o \
       gen267/1/sub.o

J267_2_OFILES=\
       gen267/2/bind.o \
       gen267/2/clap.o \
       gen267/2/drop.o \
       gen267/2/flop.o \
       gen267/2/lent.o \
       gen267/2/levy.o \
       gen267/2/lien.o \
       gen267/2/need.o \
       gen267/2/reel.o \
       gen267/2/roll.o \
       gen267/2/skim.o \
       gen267/2/skip.o \
       gen267/2/snag.o \
       gen267/2/sort.o \
       gen267/2/turn.o \
       gen267/2/weld.o

J267_3_OFILES=\
       gen267/3/cap.o \
       gen267/3/cat.o \
       gen267/3/con.o \
       gen267/3/cut.o \
       gen267/3/dor.o \
       gen267/3/dis.o \
       gen267/3/end.o \
       gen267/3/gor.o \
       gen267/3/hor.o \
       gen267/3/lsh.o \
       gen267/3/mas.o \
       gen267/3/met.o \
       gen267/3/mix.o \
       gen267/3/mug.o \
       gen267/3/peg.o \
       gen267/3/rap.o \
       gen267/3/rip.o \
       gen267/3/rsh.o \
       gen267/3/vor.o

J267_4_OFILES=\
       gen267/4/in.o \
       gen267/4/by.o \
       gen267/4/in_has.o \
       gen267/4/in_gas.o \
       gen267/4/in_put.o \
       gen267/4/in_tap.o \
       gen267/4/by_gas.o \
       gen267/4/by_get.o \
       gen267/4/by_has.o \
       gen267/4/by_put.o 

J267_5_OFILES=\
       gen267/5/to.o

J267_6_OFILES=\
       gen267/6/ap.o \
       gen267/6/cell.o \
       gen267/6/comb.o \
       gen267/6/cons.o \
       gen267/6/core.o \
       gen267/6/face.o \
       gen267/6/flan.o \
       gen267/6/flip.o \
       gen267/6/flor.o \
       gen267/6/fork.o \
       gen267/6/hack.o \
       gen267/6/hike.o \
       gen267/6/look.o \
       gen267/6/ream.o \
       gen267/6/ut.o

J267_6_OFILES_UT=\
       gen267/6/ut_bake.o \
       gen267/6/ut_burn.o \
       gen267/6/ut_cull.o \
       gen267/6/ut_emit.o \
       gen267/6/ut_find.o \
       gen267/6/ut_fire.o \
       gen267/6/ut_fish.o \
       gen267/6/ut_fret.o \
       gen267/6/ut_fuse.o \
       gen267/6/ut_gain.o \
       gen267/6/ut_heal.o \
       gen267/6/ut_mint.o \
       gen267/6/ut_orth.o \
       gen267/6/ut_nest.o \
       gen267/6/ut_park.o \
       gen267/6/ut_peek.o \
       gen267/6/ut_play.o \
       gen267/6/ut_repo.o \
       gen267/6/ut_rest.o \
       gen267/6/ut_seek.o \
       gen267/6/ut_snap.o \
       gen267/6/ut_tuck.o

J267_OFILES=\
       $(J267_1_OFILES) \
       $(J267_2_OFILES) \
       $(J267_3_OFILES) \
       $(J267_4_OFILES) \
       $(J267_5_OFILES) \
       $(J267_6_OFILES) \
       $(J267_6_OFILES_UT) \
       gen267/watt.o

J266_1_OFILES=\
       gen266/1/add.o \
       gen266/1/bex.o \
       gen266/1/dec.o \
       gen266/1/div.o \
       gen266/1/gte.o \
       gen266/1/gth.o \
       gen266/1/lte.o \
       gen266/1/lth.o \
       gen266/1/mod.o \
       gen266/1/mul.o \
       gen266/1/sub.o

J266_2_OFILES=\
       gen266/2/bind.o \
       gen266/2/clap.o \
       gen266/2/drop.o \
       gen266/2/flop.o \
       gen266/2/lent.o \
       gen266/2/levy.o \
       gen266/2/lien.o \
       gen266/2/need.o \
       gen266/2/reel.o \
       gen266/2/roll.o \
       gen266/2/skim.o \
       gen266/2/skip.o \
       gen266/2/snag.o \
       gen266/2/sort.o \
       gen266/2/turn.o \
       gen266/2/weld.o

J266_3_OFILES=\
       gen266/3/can.o \
       gen266/3/cap.o \
       gen266/3/cat.o \
       gen266/3/con.o \
       gen266/3/cue.o \
       gen266/3/cut.o \
       gen266/3/dor.o \
       gen266/3/dis.o \
       gen266/3/end.o \
       gen266/3/gor.o \
       gen266/3/hor.o \
       gen266/3/jam.o \
       gen266/3/lsh.o \
       gen266/3/mas.o \
       gen266/3/mat.o \
       gen266/3/met.o \
       gen266/3/mix.o \
       gen266/3/mug.o \
       gen266/3/peg.o \
       gen266/3/rap.o \
       gen266/3/rip.o \
       gen266/3/rub.o \
       gen266/3/rsh.o \
       gen266/3/vor.o

J266_4_OFILES=\
       gen266/4/in.o \
       gen266/4/by.o \
       gen266/4/in_has.o \
       gen266/4/in_gas.o \
       gen266/4/in_put.o \
       gen266/4/in_tap.o \
       gen266/4/by_gas.o \
       gen266/4/by_get.o \
       gen266/4/by_has.o \
       gen266/4/by_put.o 

J266_5_OFILES=\
       gen266/5/to.o

J266_6_OFILES=\
       gen266/6/ap.o \
       gen266/6/cell.o \
       gen266/6/comb.o \
       gen266/6/cons.o \
       gen266/6/core.o \
       gen266/6/face.o \
       gen266/6/flan.o \
       gen266/6/flip.o \
       gen266/6/flor.o \
       gen266/6/fork.o \
       gen266/6/hack.o \
       gen266/6/hike.o \
       gen266/6/look.o \
       gen266/6/ream.o \
       gen266/6/ut.o

J266_6_OFILES_UT=\
       gen266/6/ut_bake.o \
       gen266/6/ut_burn.o \
       gen266/6/ut_cull.o \
       gen266/6/ut_emit.o \
       gen266/6/ut_find.o \
       gen266/6/ut_fire.o \
       gen266/6/ut_fish.o \
       gen266/6/ut_fret.o \
       gen266/6/ut_fuse.o \
       gen266/6/ut_gain.o \
       gen266/6/ut_heal.o \
       gen266/6/ut_mint.o \
       gen266/6/ut_orth.o \
       gen266/6/ut_nest.o \
       gen266/6/ut_park.o \
       gen266/6/ut_peek.o \
       gen266/6/ut_play.o \
       gen266/6/ut_repo.o \
       gen266/6/ut_rest.o \
       gen266/6/ut_seek.o \
       gen266/6/ut_snap.o \
       gen266/6/ut_tuck.o

J266_OFILES=\
       $(J266_1_OFILES) \
       $(J266_2_OFILES) \
       $(J266_3_OFILES) \
       $(J266_4_OFILES) \
       $(J266_5_OFILES) \
       $(J266_6_OFILES) \
       $(J266_6_OFILES_UT) \
       gen266/watt.o

J265_1_OFILES=\
       gen265/1/add.o \
       gen265/1/bex.o \
       gen265/1/dec.o \
       gen265/1/div.o \
       gen265/1/gte.o \
       gen265/1/gth.o \
       gen265/1/lte.o \
       gen265/1/lth.o \
       gen265/1/mod.o \
       gen265/1/mul.o \
       gen265/1/sub.o

J265_2_OFILES=\
       gen265/2/bind.o \
       gen265/2/clap.o \
       gen265/2/drop.o \
       gen265/2/flop.o \
       gen265/2/lent.o \
       gen265/2/levy.o \
       gen265/2/lien.o \
       gen265/2/need.o \
       gen265/2/reel.o \
       gen265/2/roll.o \
       gen265/2/skim.o \
       gen265/2/skip.o \
       gen265/2/snag.o \
       gen265/2/sort.o \
       gen265/2/turn.o \
       gen265/2/weld.o

J265_3_OFILES=\
       gen265/3/can.o \
       gen265/3/cap.o \
       gen265/3/cat.o \
       gen265/3/con.o \
       gen265/3/cue.o \
       gen265/3/cut.o \
       gen265/3/dor.o \
       gen265/3/dis.o \
       gen265/3/end.o \
       gen265/3/gor.o \
       gen265/3/hor.o \
       gen265/3/jam.o \
       gen265/3/lsh.o \
       gen265/3/mas.o \
       gen265/3/mat.o \
       gen265/3/met.o \
       gen265/3/mix.o \
       gen265/3/mug.o \
       gen265/3/peg.o \
       gen265/3/rap.o \
       gen265/3/rip.o \
       gen265/3/rub.o \
       gen265/3/rsh.o \
       gen265/3/vor.o

J265_4_OFILES=\
       gen265/4/in.o \
       gen265/4/by.o \
       gen265/4/in_has.o \
       gen265/4/in_gas.o \
       gen265/4/in_put.o \
       gen265/4/in_tap.o \
       gen265/4/by_gas.o \
       gen265/4/by_get.o \
       gen265/4/by_has.o \
       gen265/4/by_put.o 

J265_5_OFILES=\
       gen265/5/to.o

J265_6_OFILES=\
       gen265/6/ap.o \
       gen265/6/cell.o \
       gen265/6/comb.o \
       gen265/6/cons.o \
       gen265/6/core.o \
       gen265/6/face.o \
       gen265/6/flan.o \
       gen265/6/flip.o \
       gen265/6/flor.o \
       gen265/6/fork.o \
       gen265/6/hack.o \
       gen265/6/hike.o \
       gen265/6/look.o \
       gen265/6/ream.o \
       gen265/6/ut.o

J265_6_OFILES_UT=\
       gen265/6/ut_bake.o \
       gen265/6/ut_burn.o \
       gen265/6/ut_cull.o \
       gen265/6/ut_emit.o \
       gen265/6/ut_find.o \
       gen265/6/ut_fire.o \
       gen265/6/ut_fish.o \
       gen265/6/ut_fret.o \
       gen265/6/ut_fuse.o \
       gen265/6/ut_gain.o \
       gen265/6/ut_heal.o \
       gen265/6/ut_mint.o \
       gen265/6/ut_orth.o \
       gen265/6/ut_nest.o \
       gen265/6/ut_park.o \
       gen265/6/ut_peek.o \
       gen265/6/ut_play.o \
       gen265/6/ut_repo.o \
       gen265/6/ut_rest.o \
       gen265/6/ut_seek.o \
       gen265/6/ut_snap.o \
       gen265/6/ut_tuck.o

J265_OFILES=\
       $(J265_1_OFILES) \
       $(J265_2_OFILES) \
       $(J265_3_OFILES) \
       $(J265_4_OFILES) \
       $(J265_5_OFILES) \
       $(J265_6_OFILES) \
       $(J265_6_OFILES_UT) \
       gen265/watt.o

HILL_OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J267_OFILES) \
       $(J266_OFILES) \
       $(J265_OFILES) 

$(BIN)/hill: $(HILL_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/hill $(HILL_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/hill
