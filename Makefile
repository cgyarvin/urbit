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

J260_1_OFILES=\
       gen260/1/add.o \
       gen260/1/bex.o \
       gen260/1/dec.o \
       gen260/1/div.o \
       gen260/1/gte.o \
       gen260/1/gth.o \
       gen260/1/lte.o \
       gen260/1/lth.o \
       gen260/1/mod.o \
       gen260/1/mul.o \
       gen260/1/sub.o

J260_2_OFILES=\
       gen260/2/bind.o \
       gen260/2/clap.o \
       gen260/2/drop.o \
       gen260/2/flop.o \
       gen260/2/lent.o \
       gen260/2/levy.o \
       gen260/2/lien.o \
       gen260/2/need.o \
       gen260/2/reel.o \
       gen260/2/roll.o \
       gen260/2/skim.o \
       gen260/2/skip.o \
       gen260/2/slag.o \
       gen260/2/snag.o \
       gen260/2/sort.o \
       gen260/2/turn.o \
       gen260/2/weld.o

J260_3_OFILES=\
       gen260/3/can.o \
       gen260/3/cap.o \
       gen260/3/cat.o \
       gen260/3/con.o \
       gen260/3/cut.o \
       gen260/3/dor.o \
       gen260/3/dis.o \
       gen260/3/end.o \
       gen260/3/gor.o \
       gen260/3/hor.o \
       gen260/3/lsh.o \
       gen260/3/mas.o \
       gen260/3/met.o \
       gen260/3/mix.o \
       gen260/3/mug.o \
       gen260/3/peg.o \
       gen260/3/rap.o \
       gen260/3/rip.o \
       gen260/3/rsh.o \
       gen260/3/vor.o

J260_4_OFILES=\
       gen260/4/in.o \
       gen260/4/by.o \
       gen260/4/in_has.o \
       gen260/4/in_gas.o \
       gen260/4/in_put.o \
       gen260/4/in_tap.o \
       gen260/4/by_gas.o \
       gen260/4/by_get.o \
       gen260/4/by_has.o \
       gen260/4/by_put.o 

J260_5_OFILES=\
       gen260/5/cue.o \
       gen260/5/jam.o \
       gen260/5/mat.o \
       gen260/5/rub.o 

J260_6_OFILES=\
       gen260/6/ap.o \
       gen260/6/cell.o \
       gen260/6/comb.o \
       gen260/6/cons.o \
       gen260/6/core.o \
       gen260/6/face.o \
       gen260/6/flan.o \
       gen260/6/flip.o \
       gen260/6/flor.o \
       gen260/6/fork.o \
       gen260/6/hack.o \
       gen260/6/hike.o \
       gen260/6/look.o \
       gen260/6/ream.o \
       gen260/6/ut.o

J260_6_OFILES_UT=\
       gen260/6/ut_bake.o \
       gen260/6/ut_burn.o \
       gen260/6/ut_cull.o \
       gen260/6/ut_emit.o \
       gen260/6/ut_find.o \
       gen260/6/ut_fire.o \
       gen260/6/ut_fish.o \
       gen260/6/ut_fret.o \
       gen260/6/ut_fuse.o \
       gen260/6/ut_gain.o \
       gen260/6/ut_heal.o \
       gen260/6/ut_mint.o \
       gen260/6/ut_orth.o \
       gen260/6/ut_nest.o \
       gen260/6/ut_park.o \
       gen260/6/ut_peek.o \
       gen260/6/ut_play.o \
       gen260/6/ut_repo.o \
       gen260/6/ut_rest.o \
       gen260/6/ut_seek.o \
       gen260/6/ut_snap.o \
       gen260/6/ut_tuck.o

J260_OFILES=\
       $(J260_1_OFILES) \
       $(J260_2_OFILES) \
       $(J260_3_OFILES) \
       $(J260_4_OFILES) \
       $(J260_5_OFILES) \
       $(J260_6_OFILES) \
       $(J260_6_OFILES_UT) \
       gen260/watt.o

J259_1_OFILES=\
       gen259/1/add.o \
       gen259/1/bex.o \
       gen259/1/dec.o \
       gen259/1/div.o \
       gen259/1/gte.o \
       gen259/1/gth.o \
       gen259/1/lte.o \
       gen259/1/lth.o \
       gen259/1/mod.o \
       gen259/1/mul.o \
       gen259/1/sub.o

J259_2_OFILES=\
       gen259/2/bind.o \
       gen259/2/clap.o \
       gen259/2/drop.o \
       gen259/2/flop.o \
       gen259/2/lent.o \
       gen259/2/levy.o \
       gen259/2/lien.o \
       gen259/2/need.o \
       gen259/2/reel.o \
       gen259/2/roll.o \
       gen259/2/skim.o \
       gen259/2/skip.o \
       gen259/2/slag.o \
       gen259/2/snag.o \
       gen259/2/sort.o \
       gen259/2/turn.o \
       gen259/2/weld.o

J259_3_OFILES=\
       gen259/3/can.o \
       gen259/3/cap.o \
       gen259/3/cat.o \
       gen259/3/con.o \
       gen259/3/cut.o \
       gen259/3/dor.o \
       gen259/3/dis.o \
       gen259/3/end.o \
       gen259/3/gor.o \
       gen259/3/hor.o \
       gen259/3/lsh.o \
       gen259/3/mas.o \
       gen259/3/met.o \
       gen259/3/mix.o \
       gen259/3/mug.o \
       gen259/3/peg.o \
       gen259/3/rap.o \
       gen259/3/rip.o \
       gen259/3/rsh.o \
       gen259/3/vor.o

J259_4_OFILES=\
       gen259/4/in.o \
       gen259/4/by.o \
       gen259/4/in_has.o \
       gen259/4/in_gas.o \
       gen259/4/in_put.o \
       gen259/4/in_tap.o \
       gen259/4/by_gas.o \
       gen259/4/by_get.o \
       gen259/4/by_has.o \
       gen259/4/by_put.o 

J259_5_OFILES=\
       gen259/5/cue.o \
       gen259/5/jam.o \
       gen259/5/mat.o \
       gen259/5/rub.o 

J259_6_OFILES=\
       gen259/6/ap.o \
       gen259/6/cell.o \
       gen259/6/comb.o \
       gen259/6/cons.o \
       gen259/6/core.o \
       gen259/6/face.o \
       gen259/6/flan.o \
       gen259/6/flip.o \
       gen259/6/flor.o \
       gen259/6/fork.o \
       gen259/6/hack.o \
       gen259/6/hike.o \
       gen259/6/look.o \
       gen259/6/ream.o \
       gen259/6/ut.o

J259_6_OFILES_UT=\
       gen259/6/ut_bake.o \
       gen259/6/ut_burn.o \
       gen259/6/ut_cull.o \
       gen259/6/ut_emit.o \
       gen259/6/ut_find.o \
       gen259/6/ut_fire.o \
       gen259/6/ut_fish.o \
       gen259/6/ut_fret.o \
       gen259/6/ut_fuse.o \
       gen259/6/ut_gain.o \
       gen259/6/ut_heal.o \
       gen259/6/ut_mint.o \
       gen259/6/ut_orth.o \
       gen259/6/ut_nest.o \
       gen259/6/ut_park.o \
       gen259/6/ut_peek.o \
       gen259/6/ut_play.o \
       gen259/6/ut_repo.o \
       gen259/6/ut_rest.o \
       gen259/6/ut_seek.o \
       gen259/6/ut_snap.o \
       gen259/6/ut_tuck.o

J259_OFILES=\
       $(J259_1_OFILES) \
       $(J259_2_OFILES) \
       $(J259_3_OFILES) \
       $(J259_4_OFILES) \
       $(J259_5_OFILES) \
       $(J259_6_OFILES) \
       $(J259_6_OFILES_UT) \
       gen259/watt.o

J258_1_OFILES=\
       gen258/1/add.o \
       gen258/1/bex.o \
       gen258/1/dec.o \
       gen258/1/div.o \
       gen258/1/gte.o \
       gen258/1/gth.o \
       gen258/1/lte.o \
       gen258/1/lth.o \
       gen258/1/mod.o \
       gen258/1/mul.o \
       gen258/1/sub.o

J258_2_OFILES=\
       gen258/2/bind.o \
       gen258/2/clap.o \
       gen258/2/drop.o \
       gen258/2/flop.o \
       gen258/2/lent.o \
       gen258/2/levy.o \
       gen258/2/lien.o \
       gen258/2/need.o \
       gen258/2/reel.o \
       gen258/2/roll.o \
       gen258/2/skim.o \
       gen258/2/skip.o \
       gen258/2/slag.o \
       gen258/2/snag.o \
       gen258/2/sort.o \
       gen258/2/turn.o \
       gen258/2/weld.o

J258_3_OFILES=\
       gen258/3/can.o \
       gen258/3/cap.o \
       gen258/3/cat.o \
       gen258/3/con.o \
       gen258/3/cut.o \
       gen258/3/dor.o \
       gen258/3/dis.o \
       gen258/3/end.o \
       gen258/3/gor.o \
       gen258/3/hor.o \
       gen258/3/lsh.o \
       gen258/3/mas.o \
       gen258/3/met.o \
       gen258/3/mix.o \
       gen258/3/mug.o \
       gen258/3/peg.o \
       gen258/3/rap.o \
       gen258/3/rip.o \
       gen258/3/rsh.o \
       gen258/3/vor.o

J258_4_OFILES=\
       gen258/4/in.o \
       gen258/4/by.o \
       gen258/4/in_has.o \
       gen258/4/in_gas.o \
       gen258/4/in_put.o \
       gen258/4/in_tap.o \
       gen258/4/by_gas.o \
       gen258/4/by_get.o \
       gen258/4/by_has.o \
       gen258/4/by_put.o 

J258_5_OFILES=\
       gen258/5/cue.o \
       gen258/5/jam.o \
       gen258/5/mat.o \
       gen258/5/rub.o 

J258_6_OFILES=\
       gen258/6/ap.o \
       gen258/6/cell.o \
       gen258/6/comb.o \
       gen258/6/cons.o \
       gen258/6/core.o \
       gen258/6/face.o \
       gen258/6/flan.o \
       gen258/6/flip.o \
       gen258/6/flor.o \
       gen258/6/fork.o \
       gen258/6/hack.o \
       gen258/6/hike.o \
       gen258/6/look.o \
       gen258/6/ream.o \
       gen258/6/ut.o

J258_6_OFILES_UT=\
       gen258/6/ut_bake.o \
       gen258/6/ut_burn.o \
       gen258/6/ut_cull.o \
       gen258/6/ut_emit.o \
       gen258/6/ut_find.o \
       gen258/6/ut_fire.o \
       gen258/6/ut_fish.o \
       gen258/6/ut_fret.o \
       gen258/6/ut_fuse.o \
       gen258/6/ut_gain.o \
       gen258/6/ut_heal.o \
       gen258/6/ut_mint.o \
       gen258/6/ut_orth.o \
       gen258/6/ut_nest.o \
       gen258/6/ut_park.o \
       gen258/6/ut_peek.o \
       gen258/6/ut_play.o \
       gen258/6/ut_repo.o \
       gen258/6/ut_rest.o \
       gen258/6/ut_seek.o \
       gen258/6/ut_snap.o \
       gen258/6/ut_tuck.o

J258_OFILES=\
       $(J258_1_OFILES) \
       $(J258_2_OFILES) \
       $(J258_3_OFILES) \
       $(J258_4_OFILES) \
       $(J258_5_OFILES) \
       $(J258_6_OFILES) \
       $(J258_6_OFILES_UT) \
       gen258/watt.o

J257_1_OFILES=\
       gen257/1/add.o \
       gen257/1/bex.o \
       gen257/1/dec.o \
       gen257/1/div.o \
       gen257/1/gte.o \
       gen257/1/gth.o \
       gen257/1/lte.o \
       gen257/1/lth.o \
       gen257/1/mod.o \
       gen257/1/mul.o \
       gen257/1/sub.o

J257_2_OFILES=\
       gen257/2/bind.o \
       gen257/2/clap.o \
       gen257/2/drop.o \
       gen257/2/flop.o \
       gen257/2/lent.o \
       gen257/2/levy.o \
       gen257/2/lien.o \
       gen257/2/need.o \
       gen257/2/reel.o \
       gen257/2/roll.o \
       gen257/2/skim.o \
       gen257/2/skip.o \
       gen257/2/slag.o \
       gen257/2/snag.o \
       gen257/2/sort.o \
       gen257/2/turn.o \
       gen257/2/weld.o

J257_3_OFILES=\
       gen257/3/can.o \
       gen257/3/cap.o \
       gen257/3/cat.o \
       gen257/3/con.o \
       gen257/3/cut.o \
       gen257/3/dor.o \
       gen257/3/dis.o \
       gen257/3/end.o \
       gen257/3/gor.o \
       gen257/3/hor.o \
       gen257/3/lsh.o \
       gen257/3/mas.o \
       gen257/3/met.o \
       gen257/3/mix.o \
       gen257/3/mug.o \
       gen257/3/peg.o \
       gen257/3/rap.o \
       gen257/3/rip.o \
       gen257/3/rsh.o \
       gen257/3/vor.o

J257_4_OFILES=\
       gen257/4/in.o \
       gen257/4/by.o \
       gen257/4/in_has.o \
       gen257/4/in_gas.o \
       gen257/4/in_put.o \
       gen257/4/in_tap.o \
       gen257/4/by_gas.o \
       gen257/4/by_get.o \
       gen257/4/by_has.o \
       gen257/4/by_put.o 

J257_5_OFILES=\
       gen257/5/cue.o \
       gen257/5/jam.o \
       gen257/5/mat.o \
       gen257/5/rub.o 

J257_6_OFILES=\
       gen257/6/ap.o \
       gen257/6/cell.o \
       gen257/6/comb.o \
       gen257/6/cons.o \
       gen257/6/core.o \
       gen257/6/face.o \
       gen257/6/flan.o \
       gen257/6/flip.o \
       gen257/6/flor.o \
       gen257/6/fork.o \
       gen257/6/hike.o \
       gen257/6/look.o \
       gen257/6/ream.o \
       gen257/6/ut.o

J257_6_OFILES_UT=\
       gen257/6/ut_bake.o \
       gen257/6/ut_burn.o \
       gen257/6/ut_cull.o \
       gen257/6/ut_emit.o \
       gen257/6/ut_find.o \
       gen257/6/ut_fire.o \
       gen257/6/ut_fish.o \
       gen257/6/ut_fret.o \
       gen257/6/ut_fuse.o \
       gen257/6/ut_gain.o \
       gen257/6/ut_heal.o \
       gen257/6/ut_mint.o \
       gen257/6/ut_orth.o \
       gen257/6/ut_nest.o \
       gen257/6/ut_park.o \
       gen257/6/ut_peek.o \
       gen257/6/ut_play.o \
       gen257/6/ut_repo.o \
       gen257/6/ut_rest.o \
       gen257/6/ut_seek.o \
       gen257/6/ut_snap.o \
       gen257/6/ut_tuck.o

J257_OFILES=\
       $(J257_1_OFILES) \
       $(J257_2_OFILES) \
       $(J257_3_OFILES) \
       $(J257_4_OFILES) \
       $(J257_5_OFILES) \
       $(J257_6_OFILES) \
       $(J257_6_OFILES_UT) \
       gen257/watt.o

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
       $(J259_OFILES) \
       $(J258_OFILES) \
       $(J257_OFILES)

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
