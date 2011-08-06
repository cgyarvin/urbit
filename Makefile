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

J244_1_OFILES=\
       gen244/1/add.o \
       gen244/1/bex.o \
       gen244/1/dec.o \
       gen244/1/div.o \
       gen244/1/gte.o \
       gen244/1/gth.o \
       gen244/1/lte.o \
       gen244/1/lth.o \
       gen244/1/mod.o \
       gen244/1/mul.o \
       gen244/1/sub.o

J244_2_OFILES=\
       gen244/2/bind.o \
       gen244/2/clap.o \
       gen244/2/drop.o \
       gen244/2/flop.o \
       gen244/2/lent.o \
       gen244/2/levy.o \
       gen244/2/lien.o \
       gen244/2/need.o \
       gen244/2/reel.o \
       gen244/2/roll.o \
       gen244/2/skim.o \
       gen244/2/skip.o \
       gen244/2/slag.o \
       gen244/2/snag.o \
       gen244/2/sort.o \
       gen244/2/turn.o \
       gen244/2/weld.o

J244_3_OFILES=\
       gen244/3/can.o \
       gen244/3/cap.o \
       gen244/3/cat.o \
       gen244/3/con.o \
       gen244/3/cut.o \
       gen244/3/dor.o \
       gen244/3/dis.o \
       gen244/3/end.o \
       gen244/3/gor.o \
       gen244/3/hor.o \
       gen244/3/lsh.o \
       gen244/3/mas.o \
       gen244/3/met.o \
       gen244/3/mix.o \
       gen244/3/mug.o \
       gen244/3/peg.o \
       gen244/3/rap.o \
       gen244/3/rip.o \
       gen244/3/rsh.o \
       gen244/3/vor.o

J244_4_OFILES=\
       gen244/4/in.o \
       gen244/4/by.o \
       gen244/4/in_has.o \
       gen244/4/in_gas.o \
       gen244/4/in_put.o \
       gen244/4/in_tap.o \
       gen244/4/by_gas.o \
       gen244/4/by_get.o \
       gen244/4/by_has.o \
       gen244/4/by_put.o 

J244_5_OFILES=\
       gen244/5/cue.o \
       gen244/5/jam.o \
       gen244/5/mat.o \
       gen244/5/rub.o 

J244_6_OFILES=\
       gen244/6/ap.o \
       gen244/6/cell.o \
       gen244/6/comb.o \
       gen244/6/cons.o \
       gen244/6/core.o \
       gen244/6/cube.o \
       gen244/6/face.o \
       gen244/6/fine.o \
       gen244/6/flan.o \
       gen244/6/flip.o \
       gen244/6/flor.o \
       gen244/6/fork.o \
       gen244/6/hike.o \
       gen244/6/look.o \
       gen244/6/ream.o \
       gen244/6/ut.o

J244_6_OFILES_UT=\
       gen244/6/ut_bake.o \
       gen244/6/ut_burn.o \
       gen244/6/ut_cull.o \
       gen244/6/ut_emit.o \
       gen244/6/ut_find.o \
       gen244/6/ut_fire.o \
       gen244/6/ut_firm.o \
       gen244/6/ut_fish.o \
       gen244/6/ut_fret.o \
       gen244/6/ut_fuse.o \
       gen244/6/ut_gain.o \
       gen244/6/ut_heal.o \
       gen244/6/ut_mint.o \
       gen244/6/ut_odor.o \
       gen244/6/ut_orth.o \
       gen244/6/ut_nest.o \
       gen244/6/ut_park.o \
       gen244/6/ut_peek.o \
       gen244/6/ut_play.o \
       gen244/6/ut_repo.o \
       gen244/6/ut_rest.o \
       gen244/6/ut_seek.o \
       gen244/6/ut_snap.o \
       gen244/6/ut_tuck.o

J244_OFILES=\
       $(J244_1_OFILES) \
       $(J244_2_OFILES) \
       $(J244_3_OFILES) \
       $(J244_4_OFILES) \
       $(J244_5_OFILES) \
       $(J244_6_OFILES) \
       $(J244_6_OFILES_UT) \
       gen244/watt.o


J243_1_OFILES=\
       gen243/1/add.o \
       gen243/1/bex.o \
       gen243/1/dec.o \
       gen243/1/div.o \
       gen243/1/gte.o \
       gen243/1/gth.o \
       gen243/1/lte.o \
       gen243/1/lth.o \
       gen243/1/mod.o \
       gen243/1/mul.o \
       gen243/1/sub.o

J243_2_OFILES=\
       gen243/2/bind.o \
       gen243/2/clap.o \
       gen243/2/drop.o \
       gen243/2/flop.o \
       gen243/2/lent.o \
       gen243/2/levy.o \
       gen243/2/lien.o \
       gen243/2/need.o \
       gen243/2/reel.o \
       gen243/2/roll.o \
       gen243/2/skim.o \
       gen243/2/skip.o \
       gen243/2/slag.o \
       gen243/2/snag.o \
       gen243/2/sort.o \
       gen243/2/turn.o \
       gen243/2/weld.o

J243_3_OFILES=\
       gen243/3/can.o \
       gen243/3/cap.o \
       gen243/3/cat.o \
       gen243/3/con.o \
       gen243/3/cut.o \
       gen243/3/dor.o \
       gen243/3/dis.o \
       gen243/3/end.o \
       gen243/3/gor.o \
       gen243/3/hor.o \
       gen243/3/lsh.o \
       gen243/3/mas.o \
       gen243/3/met.o \
       gen243/3/mix.o \
       gen243/3/mug.o \
       gen243/3/peg.o \
       gen243/3/rap.o \
       gen243/3/rip.o \
       gen243/3/rsh.o \
       gen243/3/vor.o

J243_4_OFILES=\
       gen243/4/in.o \
       gen243/4/by.o \
       gen243/4/in_has.o \
       gen243/4/in_gas.o \
       gen243/4/in_put.o \
       gen243/4/in_tap.o \
       gen243/4/by_gas.o \
       gen243/4/by_get.o \
       gen243/4/by_has.o \
       gen243/4/by_put.o 

J243_5_OFILES=\
       gen243/5/cue.o \
       gen243/5/jam.o \
       gen243/5/mat.o \
       gen243/5/rub.o 

J243_6_OFILES=\
       gen243/6/ap.o \
       gen243/6/cell.o \
       gen243/6/comb.o \
       gen243/6/cons.o \
       gen243/6/core.o \
       gen243/6/cube.o \
       gen243/6/face.o \
       gen243/6/fine.o \
       gen243/6/flan.o \
       gen243/6/flip.o \
       gen243/6/flor.o \
       gen243/6/fork.o \
       gen243/6/hike.o \
       gen243/6/look.o \
       gen243/6/ream.o \
       gen243/6/ut.o

J243_6_OFILES_UT=\
       gen243/6/ut_bake.o \
       gen243/6/ut_burn.o \
       gen243/6/ut_cull.o \
       gen243/6/ut_emit.o \
       gen243/6/ut_find.o \
       gen243/6/ut_fire.o \
       gen243/6/ut_firm.o \
       gen243/6/ut_fish.o \
       gen243/6/ut_fret.o \
       gen243/6/ut_fuse.o \
       gen243/6/ut_gain.o \
       gen243/6/ut_heal.o \
       gen243/6/ut_mint.o \
       gen243/6/ut_odor.o \
       gen243/6/ut_orth.o \
       gen243/6/ut_nest.o \
       gen243/6/ut_park.o \
       gen243/6/ut_peek.o \
       gen243/6/ut_play.o \
       gen243/6/ut_repo.o \
       gen243/6/ut_rest.o \
       gen243/6/ut_seek.o \
       gen243/6/ut_snap.o \
       gen243/6/ut_tuck.o

J243_OFILES=\
       $(J243_1_OFILES) \
       $(J243_2_OFILES) \
       $(J243_3_OFILES) \
       $(J243_4_OFILES) \
       $(J243_5_OFILES) \
       $(J243_6_OFILES) \
       $(J243_6_OFILES_UT) \
       gen243/watt.o

J242_1_OFILES=\
       gen242/1/add.o \
       gen242/1/bex.o \
       gen242/1/dec.o \
       gen242/1/div.o \
       gen242/1/gte.o \
       gen242/1/gth.o \
       gen242/1/lte.o \
       gen242/1/lth.o \
       gen242/1/mod.o \
       gen242/1/mul.o \
       gen242/1/sub.o

J242_2_OFILES=\
       gen242/2/bind.o \
       gen242/2/clap.o \
       gen242/2/drop.o \
       gen242/2/flop.o \
       gen242/2/lent.o \
       gen242/2/levy.o \
       gen242/2/lien.o \
       gen242/2/need.o \
       gen242/2/reel.o \
       gen242/2/roll.o \
       gen242/2/skim.o \
       gen242/2/skip.o \
       gen242/2/slag.o \
       gen242/2/snag.o \
       gen242/2/sort.o \
       gen242/2/turn.o \
       gen242/2/weld.o

J242_3_OFILES=\
       gen242/3/can.o \
       gen242/3/cap.o \
       gen242/3/cat.o \
       gen242/3/con.o \
       gen242/3/cut.o \
       gen242/3/dor.o \
       gen242/3/dis.o \
       gen242/3/end.o \
       gen242/3/gor.o \
       gen242/3/hor.o \
       gen242/3/lsh.o \
       gen242/3/mas.o \
       gen242/3/met.o \
       gen242/3/mix.o \
       gen242/3/mug.o \
       gen242/3/peg.o \
       gen242/3/rap.o \
       gen242/3/rip.o \
       gen242/3/rsh.o \
       gen242/3/vor.o

J242_4_OFILES=\
       gen242/4/in.o \
       gen242/4/by.o \
       gen242/4/in_has.o \
       gen242/4/in_gas.o \
       gen242/4/in_put.o \
       gen242/4/in_tap.o \
       gen242/4/by_gas.o \
       gen242/4/by_get.o \
       gen242/4/by_has.o \
       gen242/4/by_put.o 

J242_5_OFILES=\
       gen242/5/cue.o \
       gen242/5/jam.o \
       gen242/5/mat.o \
       gen242/5/rub.o 

J242_6_OFILES=\
       gen242/6/ap.o \
       gen242/6/cell.o \
       gen242/6/comb.o \
       gen242/6/cons.o \
       gen242/6/core.o \
       gen242/6/cube.o \
       gen242/6/face.o \
       gen242/6/fine.o \
       gen242/6/flan.o \
       gen242/6/flip.o \
       gen242/6/flor.o \
       gen242/6/fork.o \
       gen242/6/hike.o \
       gen242/6/look.o \
       gen242/6/ream.o \
       gen242/6/ut.o

J242_6_OFILES_UT=\
       gen242/6/ut_bake.o \
       gen242/6/ut_burn.o \
       gen242/6/ut_cull.o \
       gen242/6/ut_emit.o \
       gen242/6/ut_find.o \
       gen242/6/ut_fire.o \
       gen242/6/ut_firm.o \
       gen242/6/ut_fish.o \
       gen242/6/ut_fret.o \
       gen242/6/ut_fuse.o \
       gen242/6/ut_gain.o \
       gen242/6/ut_heal.o \
       gen242/6/ut_mint.o \
       gen242/6/ut_odor.o \
       gen242/6/ut_orth.o \
       gen242/6/ut_nest.o \
       gen242/6/ut_park.o \
       gen242/6/ut_peek.o \
       gen242/6/ut_play.o \
       gen242/6/ut_repo.o \
       gen242/6/ut_rest.o \
       gen242/6/ut_seek.o \
       gen242/6/ut_snap.o \
       gen242/6/ut_tuck.o

J242_OFILES=\
       $(J242_1_OFILES) \
       $(J242_2_OFILES) \
       $(J242_3_OFILES) \
       $(J242_4_OFILES) \
       $(J242_5_OFILES) \
       $(J242_6_OFILES) \
       $(J242_6_OFILES_UT) \
       gen242/watt.o


J241_1_OFILES=\
       gen241/1/add.o \
       gen241/1/bex.o \
       gen241/1/dec.o \
       gen241/1/div.o \
       gen241/1/gte.o \
       gen241/1/gth.o \
       gen241/1/lte.o \
       gen241/1/lth.o \
       gen241/1/mod.o \
       gen241/1/mul.o \
       gen241/1/sub.o

J241_2_OFILES=\
       gen241/2/bind.o \
       gen241/2/clap.o \
       gen241/2/drop.o \
       gen241/2/flop.o \
       gen241/2/lent.o \
       gen241/2/levy.o \
       gen241/2/lien.o \
       gen241/2/need.o \
       gen241/2/reel.o \
       gen241/2/roll.o \
       gen241/2/skim.o \
       gen241/2/skip.o \
       gen241/2/slag.o \
       gen241/2/snag.o \
       gen241/2/sort.o \
       gen241/2/turn.o \
       gen241/2/weld.o

J241_3_OFILES=\
       gen241/3/can.o \
       gen241/3/cap.o \
       gen241/3/cat.o \
       gen241/3/con.o \
       gen241/3/cut.o \
       gen241/3/dor.o \
       gen241/3/dis.o \
       gen241/3/end.o \
       gen241/3/gor.o \
       gen241/3/hor.o \
       gen241/3/lsh.o \
       gen241/3/mas.o \
       gen241/3/met.o \
       gen241/3/mix.o \
       gen241/3/mug.o \
       gen241/3/peg.o \
       gen241/3/rap.o \
       gen241/3/rip.o \
       gen241/3/rsh.o \
       gen241/3/vor.o

J241_4_OFILES=\
       gen241/4/in.o \
       gen241/4/by.o \
       gen241/4/in_has.o \
       gen241/4/in_gas.o \
       gen241/4/in_put.o \
       gen241/4/in_tap.o \
       gen241/4/by_gas.o \
       gen241/4/by_get.o \
       gen241/4/by_has.o \
       gen241/4/by_put.o 

J241_5_OFILES=\
       gen241/5/cue.o \
       gen241/5/jam.o \
       gen241/5/mat.o \
       gen241/5/rub.o 

J241_6_OFILES=\
       gen241/6/ap.o \
       gen241/6/cell.o \
       gen241/6/comb.o \
       gen241/6/cons.o \
       gen241/6/core.o \
       gen241/6/cube.o \
       gen241/6/face.o \
       gen241/6/fine.o \
       gen241/6/flan.o \
       gen241/6/flip.o \
       gen241/6/flor.o \
       gen241/6/fork.o \
       gen241/6/hike.o \
       gen241/6/look.o \
       gen241/6/ream.o \
       gen241/6/ut.o

J241_6_OFILES_UT=\
       gen241/6/ut_bake.o \
       gen241/6/ut_burn.o \
       gen241/6/ut_cull.o \
       gen241/6/ut_emit.o \
       gen241/6/ut_find.o \
       gen241/6/ut_fire.o \
       gen241/6/ut_firm.o \
       gen241/6/ut_fish.o \
       gen241/6/ut_fret.o \
       gen241/6/ut_fuse.o \
       gen241/6/ut_gain.o \
       gen241/6/ut_heal.o \
       gen241/6/ut_mint.o \
       gen241/6/ut_odor.o \
       gen241/6/ut_orth.o \
       gen241/6/ut_nest.o \
       gen241/6/ut_park.o \
       gen241/6/ut_peek.o \
       gen241/6/ut_play.o \
       gen241/6/ut_repo.o \
       gen241/6/ut_rest.o \
       gen241/6/ut_seek.o \
       gen241/6/ut_snap.o \
       gen241/6/ut_tuck.o

J241_OFILES=\
       $(J241_1_OFILES) \
       $(J241_2_OFILES) \
       $(J241_3_OFILES) \
       $(J241_4_OFILES) \
       $(J241_5_OFILES) \
       $(J241_6_OFILES) \
       $(J241_6_OFILES_UT) \
       gen241/watt.o


EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J242_OFILES) \
       $(J241_OFILES)

all: $(BIN)/eyre

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
