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
CLD=gcc -g -L/sw/lib
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

J264_1_OFILES=\
       gen264/1/add.o \
       gen264/1/bex.o \
       gen264/1/dec.o \
       gen264/1/div.o \
       gen264/1/gte.o \
       gen264/1/gth.o \
       gen264/1/lte.o \
       gen264/1/lth.o \
       gen264/1/mod.o \
       gen264/1/mul.o \
       gen264/1/sub.o

J264_2_OFILES=\
       gen264/2/bind.o \
       gen264/2/clap.o \
       gen264/2/drop.o \
       gen264/2/flop.o \
       gen264/2/lent.o \
       gen264/2/levy.o \
       gen264/2/lien.o \
       gen264/2/need.o \
       gen264/2/reel.o \
       gen264/2/roll.o \
       gen264/2/skim.o \
       gen264/2/skip.o \
       gen264/2/snag.o \
       gen264/2/sort.o \
       gen264/2/turn.o \
       gen264/2/weld.o

J264_3_OFILES=\
       gen264/3/can.o \
       gen264/3/cap.o \
       gen264/3/cat.o \
       gen264/3/con.o \
       gen264/3/cue.o \
       gen264/3/cut.o \
       gen264/3/dor.o \
       gen264/3/dis.o \
       gen264/3/end.o \
       gen264/3/gor.o \
       gen264/3/hor.o \
       gen264/3/jam.o \
       gen264/3/lsh.o \
       gen264/3/mas.o \
       gen264/3/mat.o \
       gen264/3/met.o \
       gen264/3/mix.o \
       gen264/3/mug.o \
       gen264/3/peg.o \
       gen264/3/rap.o \
       gen264/3/rip.o \
       gen264/3/rub.o \
       gen264/3/rsh.o \
       gen264/3/vor.o

J264_4_OFILES=\
       gen264/4/in.o \
       gen264/4/by.o \
       gen264/4/in_has.o \
       gen264/4/in_gas.o \
       gen264/4/in_put.o \
       gen264/4/in_tap.o \
       gen264/4/by_gas.o \
       gen264/4/by_get.o \
       gen264/4/by_has.o \
       gen264/4/by_put.o 

J264_5_OFILES=\
       gen264/5/to.o

J264_6_OFILES=\
       gen264/6/ap.o \
       gen264/6/cell.o \
       gen264/6/comb.o \
       gen264/6/cons.o \
       gen264/6/core.o \
       gen264/6/face.o \
       gen264/6/flan.o \
       gen264/6/flip.o \
       gen264/6/flor.o \
       gen264/6/fork.o \
       gen264/6/hack.o \
       gen264/6/hike.o \
       gen264/6/look.o \
       gen264/6/ream.o \
       gen264/6/ut.o

J264_6_OFILES_UT=\
       gen264/6/ut_bake.o \
       gen264/6/ut_burn.o \
       gen264/6/ut_cull.o \
       gen264/6/ut_emit.o \
       gen264/6/ut_find.o \
       gen264/6/ut_fire.o \
       gen264/6/ut_fish.o \
       gen264/6/ut_fret.o \
       gen264/6/ut_fuse.o \
       gen264/6/ut_gain.o \
       gen264/6/ut_heal.o \
       gen264/6/ut_mint.o \
       gen264/6/ut_orth.o \
       gen264/6/ut_nest.o \
       gen264/6/ut_park.o \
       gen264/6/ut_peek.o \
       gen264/6/ut_play.o \
       gen264/6/ut_repo.o \
       gen264/6/ut_rest.o \
       gen264/6/ut_seek.o \
       gen264/6/ut_snap.o \
       gen264/6/ut_tuck.o

J264_OFILES=\
       $(J264_1_OFILES) \
       $(J264_2_OFILES) \
       $(J264_3_OFILES) \
       $(J264_4_OFILES) \
       $(J264_5_OFILES) \
       $(J264_6_OFILES) \
       $(J264_6_OFILES_UT) \
       gen264/watt.o


J263_1_OFILES=\
       gen263/1/add.o \
       gen263/1/bex.o \
       gen263/1/dec.o \
       gen263/1/div.o \
       gen263/1/gte.o \
       gen263/1/gth.o \
       gen263/1/lte.o \
       gen263/1/lth.o \
       gen263/1/mod.o \
       gen263/1/mul.o \
       gen263/1/sub.o

J263_2_OFILES=\
       gen263/2/bind.o \
       gen263/2/clap.o \
       gen263/2/drop.o \
       gen263/2/flop.o \
       gen263/2/lent.o \
       gen263/2/levy.o \
       gen263/2/lien.o \
       gen263/2/need.o \
       gen263/2/reel.o \
       gen263/2/roll.o \
       gen263/2/skim.o \
       gen263/2/skip.o \
       gen263/2/slag.o \
       gen263/2/snag.o \
       gen263/2/sort.o \
       gen263/2/turn.o \
       gen263/2/weld.o

J263_3_OFILES=\
       gen263/3/can.o \
       gen263/3/cap.o \
       gen263/3/cat.o \
       gen263/3/con.o \
       gen263/3/cue.o \
       gen263/3/cut.o \
       gen263/3/dor.o \
       gen263/3/dis.o \
       gen263/3/end.o \
       gen263/3/gor.o \
       gen263/3/hor.o \
       gen263/3/jam.o \
       gen263/3/lsh.o \
       gen263/3/mas.o \
       gen263/3/mat.o \
       gen263/3/met.o \
       gen263/3/mix.o \
       gen263/3/mug.o \
       gen263/3/peg.o \
       gen263/3/rap.o \
       gen263/3/rip.o \
       gen263/3/rub.o \
       gen263/3/rsh.o \
       gen263/3/vor.o

J263_4_OFILES=\
       gen263/4/in.o \
       gen263/4/by.o \
       gen263/4/in_has.o \
       gen263/4/in_gas.o \
       gen263/4/in_put.o \
       gen263/4/in_tap.o \
       gen263/4/by_gas.o \
       gen263/4/by_get.o \
       gen263/4/by_has.o \
       gen263/4/by_put.o 

J263_5_OFILES=\
       gen263/5/to.o

J263_6_OFILES=\
       gen263/6/ap.o \
       gen263/6/cell.o \
       gen263/6/comb.o \
       gen263/6/cons.o \
       gen263/6/core.o \
       gen263/6/face.o \
       gen263/6/flan.o \
       gen263/6/flip.o \
       gen263/6/flor.o \
       gen263/6/fork.o \
       gen263/6/hack.o \
       gen263/6/hike.o \
       gen263/6/look.o \
       gen263/6/ream.o \
       gen263/6/ut.o

J263_6_OFILES_UT=\
       gen263/6/ut_bake.o \
       gen263/6/ut_burn.o \
       gen263/6/ut_cull.o \
       gen263/6/ut_emit.o \
       gen263/6/ut_find.o \
       gen263/6/ut_fire.o \
       gen263/6/ut_fish.o \
       gen263/6/ut_fret.o \
       gen263/6/ut_fuse.o \
       gen263/6/ut_gain.o \
       gen263/6/ut_heal.o \
       gen263/6/ut_mint.o \
       gen263/6/ut_orth.o \
       gen263/6/ut_nest.o \
       gen263/6/ut_park.o \
       gen263/6/ut_peek.o \
       gen263/6/ut_play.o \
       gen263/6/ut_repo.o \
       gen263/6/ut_rest.o \
       gen263/6/ut_seek.o \
       gen263/6/ut_snap.o \
       gen263/6/ut_tuck.o

J263_OFILES=\
       $(J263_1_OFILES) \
       $(J263_2_OFILES) \
       $(J263_3_OFILES) \
       $(J263_4_OFILES) \
       $(J263_5_OFILES) \
       $(J263_6_OFILES) \
       $(J263_6_OFILES_UT) \
       gen263/watt.o

J262_1_OFILES=\
       gen262/1/add.o \
       gen262/1/bex.o \
       gen262/1/dec.o \
       gen262/1/div.o \
       gen262/1/gte.o \
       gen262/1/gth.o \
       gen262/1/lte.o \
       gen262/1/lth.o \
       gen262/1/mod.o \
       gen262/1/mul.o \
       gen262/1/sub.o

J262_2_OFILES=\
       gen262/2/bind.o \
       gen262/2/clap.o \
       gen262/2/drop.o \
       gen262/2/flop.o \
       gen262/2/lent.o \
       gen262/2/levy.o \
       gen262/2/lien.o \
       gen262/2/need.o \
       gen262/2/reel.o \
       gen262/2/roll.o \
       gen262/2/skim.o \
       gen262/2/skip.o \
       gen262/2/slag.o \
       gen262/2/snag.o \
       gen262/2/sort.o \
       gen262/2/turn.o \
       gen262/2/weld.o

J262_3_OFILES=\
       gen262/3/can.o \
       gen262/3/cap.o \
       gen262/3/cat.o \
       gen262/3/con.o \
       gen262/3/cut.o \
       gen262/3/dor.o \
       gen262/3/dis.o \
       gen262/3/end.o \
       gen262/3/gor.o \
       gen262/3/hor.o \
       gen262/3/lsh.o \
       gen262/3/mas.o \
       gen262/3/met.o \
       gen262/3/mix.o \
       gen262/3/mug.o \
       gen262/3/peg.o \
       gen262/3/rap.o \
       gen262/3/rip.o \
       gen262/3/rsh.o \
       gen262/3/vor.o

J262_4_OFILES=\
       gen262/4/in.o \
       gen262/4/by.o \
       gen262/4/in_has.o \
       gen262/4/in_gas.o \
       gen262/4/in_put.o \
       gen262/4/in_tap.o \
       gen262/4/by_gas.o \
       gen262/4/by_get.o \
       gen262/4/by_has.o \
       gen262/4/by_put.o 

J262_5_OFILES=\
       gen262/5/cue.o \
       gen262/5/jam.o \
       gen262/5/mat.o \
       gen262/5/rub.o 

J262_6_OFILES=\
       gen262/6/ap.o \
       gen262/6/cell.o \
       gen262/6/comb.o \
       gen262/6/cons.o \
       gen262/6/core.o \
       gen262/6/face.o \
       gen262/6/flan.o \
       gen262/6/flip.o \
       gen262/6/flor.o \
       gen262/6/fork.o \
       gen262/6/hack.o \
       gen262/6/hike.o \
       gen262/6/look.o \
       gen262/6/ream.o \
       gen262/6/ut.o

J262_6_OFILES_UT=\
       gen262/6/ut_bake.o \
       gen262/6/ut_burn.o \
       gen262/6/ut_cull.o \
       gen262/6/ut_emit.o \
       gen262/6/ut_find.o \
       gen262/6/ut_fire.o \
       gen262/6/ut_fish.o \
       gen262/6/ut_fret.o \
       gen262/6/ut_fuse.o \
       gen262/6/ut_gain.o \
       gen262/6/ut_heal.o \
       gen262/6/ut_mint.o \
       gen262/6/ut_orth.o \
       gen262/6/ut_nest.o \
       gen262/6/ut_park.o \
       gen262/6/ut_peek.o \
       gen262/6/ut_play.o \
       gen262/6/ut_repo.o \
       gen262/6/ut_rest.o \
       gen262/6/ut_seek.o \
       gen262/6/ut_snap.o \
       gen262/6/ut_tuck.o

J262_OFILES=\
       $(J262_1_OFILES) \
       $(J262_2_OFILES) \
       $(J262_3_OFILES) \
       $(J262_4_OFILES) \
       $(J262_5_OFILES) \
       $(J262_6_OFILES) \
       $(J262_6_OFILES_UT) \
       gen262/watt.o

J261_1_OFILES=\
       gen261/1/add.o \
       gen261/1/bex.o \
       gen261/1/dec.o \
       gen261/1/div.o \
       gen261/1/gte.o \
       gen261/1/gth.o \
       gen261/1/lte.o \
       gen261/1/lth.o \
       gen261/1/mod.o \
       gen261/1/mul.o \
       gen261/1/sub.o

J261_2_OFILES=\
       gen261/2/bind.o \
       gen261/2/clap.o \
       gen261/2/drop.o \
       gen261/2/flop.o \
       gen261/2/lent.o \
       gen261/2/levy.o \
       gen261/2/lien.o \
       gen261/2/need.o \
       gen261/2/reel.o \
       gen261/2/roll.o \
       gen261/2/skim.o \
       gen261/2/skip.o \
       gen261/2/slag.o \
       gen261/2/snag.o \
       gen261/2/sort.o \
       gen261/2/turn.o \
       gen261/2/weld.o

J261_3_OFILES=\
       gen261/3/can.o \
       gen261/3/cap.o \
       gen261/3/cat.o \
       gen261/3/con.o \
       gen261/3/cut.o \
       gen261/3/dor.o \
       gen261/3/dis.o \
       gen261/3/end.o \
       gen261/3/gor.o \
       gen261/3/hor.o \
       gen261/3/lsh.o \
       gen261/3/mas.o \
       gen261/3/met.o \
       gen261/3/mix.o \
       gen261/3/mug.o \
       gen261/3/peg.o \
       gen261/3/rap.o \
       gen261/3/rip.o \
       gen261/3/rsh.o \
       gen261/3/vor.o

J261_4_OFILES=\
       gen261/4/in.o \
       gen261/4/by.o \
       gen261/4/in_has.o \
       gen261/4/in_gas.o \
       gen261/4/in_put.o \
       gen261/4/in_tap.o \
       gen261/4/by_gas.o \
       gen261/4/by_get.o \
       gen261/4/by_has.o \
       gen261/4/by_put.o 

J261_5_OFILES=\
       gen261/5/cue.o \
       gen261/5/jam.o \
       gen261/5/mat.o \
       gen261/5/rub.o 

J261_6_OFILES=\
       gen261/6/ap.o \
       gen261/6/cell.o \
       gen261/6/comb.o \
       gen261/6/cons.o \
       gen261/6/core.o \
       gen261/6/face.o \
       gen261/6/flan.o \
       gen261/6/flip.o \
       gen261/6/flor.o \
       gen261/6/fork.o \
       gen261/6/hack.o \
       gen261/6/hike.o \
       gen261/6/look.o \
       gen261/6/ream.o \
       gen261/6/ut.o

J261_6_OFILES_UT=\
       gen261/6/ut_bake.o \
       gen261/6/ut_burn.o \
       gen261/6/ut_cull.o \
       gen261/6/ut_emit.o \
       gen261/6/ut_find.o \
       gen261/6/ut_fire.o \
       gen261/6/ut_fish.o \
       gen261/6/ut_fret.o \
       gen261/6/ut_fuse.o \
       gen261/6/ut_gain.o \
       gen261/6/ut_heal.o \
       gen261/6/ut_mint.o \
       gen261/6/ut_orth.o \
       gen261/6/ut_nest.o \
       gen261/6/ut_park.o \
       gen261/6/ut_peek.o \
       gen261/6/ut_play.o \
       gen261/6/ut_repo.o \
       gen261/6/ut_rest.o \
       gen261/6/ut_seek.o \
       gen261/6/ut_snap.o \
       gen261/6/ut_tuck.o

J261_OFILES=\
       $(J261_1_OFILES) \
       $(J261_2_OFILES) \
       $(J261_3_OFILES) \
       $(J261_4_OFILES) \
       $(J261_5_OFILES) \
       $(J261_6_OFILES) \
       $(J261_6_OFILES_UT) \
       gen261/watt.o

HILL_OFILES=\
       c/hill.o \
       c/main.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J267_OFILES) \
       $(J266_OFILES) \
       $(J265_OFILES) \
       $(J264_OFILES)

EYRE_OFILES=\
       c/eyre.o \
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J264_OFILES) \
       $(J263_OFILES) \
       $(J262_OFILES) \
       $(J261_OFILES)

all: $(BIN)/eyre

$(BIN)/hill: $(HILL_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/hill $(HILL_OFILES) -lgmp -lreadline -ltermcap

$(BIN)/eyre: $(EYRE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/eyre $(EYRE_OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(HILL_OFILES) $(EYRE_OFILES) $(BIN)/hill $(BIN)/eyre
