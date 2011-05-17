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

J270_1_OFILES=\
       gen270/1/add.o \
       gen270/1/bex.o \
       gen270/1/dec.o \
       gen270/1/div.o \
       gen270/1/gte.o \
       gen270/1/gth.o \
       gen270/1/lte.o \
       gen270/1/lth.o \
       gen270/1/mod.o \
       gen270/1/mul.o \
       gen270/1/sub.o

J270_2_OFILES=\
       gen270/2/bind.o \
       gen270/2/clap.o \
       gen270/2/drop.o \
       gen270/2/flop.o \
       gen270/2/lent.o \
       gen270/2/levy.o \
       gen270/2/lien.o \
       gen270/2/need.o \
       gen270/2/reel.o \
       gen270/2/roll.o \
       gen270/2/skim.o \
       gen270/2/skip.o \
       gen270/2/snag.o \
       gen270/2/sort.o \
       gen270/2/turn.o \
       gen270/2/weld.o

J270_3_OFILES=\
       gen270/3/cap.o \
       gen270/3/cat.o \
       gen270/3/con.o \
       gen270/3/cut.o \
       gen270/3/dor.o \
       gen270/3/dis.o \
       gen270/3/end.o \
       gen270/3/gor.o \
       gen270/3/hor.o \
       gen270/3/lsh.o \
       gen270/3/mas.o \
       gen270/3/met.o \
       gen270/3/mix.o \
       gen270/3/mug.o \
       gen270/3/peg.o \
       gen270/3/rap.o \
       gen270/3/rip.o \
       gen270/3/rsh.o \
       gen270/3/vor.o

J270_4_OFILES=\
       gen270/4/in.o \
       gen270/4/by.o \
       gen270/4/in_has.o \
       gen270/4/in_gas.o \
       gen270/4/in_put.o \
       gen270/4/in_tap.o \
       gen270/4/by_gas.o \
       gen270/4/by_get.o \
       gen270/4/by_has.o \
       gen270/4/by_put.o 

J270_5_OFILES=\
       gen270/5/to.o

J270_6_OFILES=\
       gen270/6/ap.o \
       gen270/6/cell.o \
       gen270/6/comb.o \
       gen270/6/cons.o \
       gen270/6/core.o \
       gen270/6/face.o \
       gen270/6/flan.o \
       gen270/6/flip.o \
       gen270/6/flor.o \
       gen270/6/fork.o \
       gen270/6/hack.o \
       gen270/6/hike.o \
       gen270/6/look.o \
       gen270/6/ream.o \
       gen270/6/ut.o

J270_6_OFILES_UT=\
       gen270/6/ut_bake.o \
       gen270/6/ut_burn.o \
       gen270/6/ut_cull.o \
       gen270/6/ut_edit.o \
       gen270/6/ut_emit.o \
       gen270/6/ut_find.o \
       gen270/6/ut_fire.o \
       gen270/6/ut_fish.o \
       gen270/6/ut_fret.o \
       gen270/6/ut_fuse.o \
       gen270/6/ut_gain.o \
       gen270/6/ut_heal.o \
       gen270/6/ut_mint.o \
       gen270/6/ut_orth.o \
       gen270/6/ut_nest.o \
       gen270/6/ut_park.o \
       gen270/6/ut_peek.o \
       gen270/6/ut_play.o \
       gen270/6/ut_repo.o \
       gen270/6/ut_rest.o \
       gen270/6/ut_seek.o \
       gen270/6/ut_snap.o \
       gen270/6/ut_tuck.o \
       gen270/6/ut_tusk.o

J270_OFILES=\
       $(J270_1_OFILES) \
       $(J270_2_OFILES) \
       $(J270_3_OFILES) \
       $(J270_4_OFILES) \
       $(J270_5_OFILES) \
       $(J270_6_OFILES) \
       $(J270_6_OFILES_UT) \
       gen270/watt.o

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
       gen268/6/ut_edit.o \
       gen268/6/ut_emit.o \
       gen268/6/ut_fern.o \
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
       gen268/6/ut_tuck.o \
       gen268/6/ut_tusk.o

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
       gen267/6/ut_edit.o \
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
       gen267/6/ut_tuck.o \
       gen267/6/ut_tusk.o

J267_OFILES=\
       $(J267_1_OFILES) \
       $(J267_2_OFILES) \
       $(J267_3_OFILES) \
       $(J267_4_OFILES) \
       $(J267_5_OFILES) \
       $(J267_6_OFILES) \
       $(J267_6_OFILES_UT) \
       gen267/watt.o

OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J270_OFILES) \
       $(J269_OFILES) \
       $(J268_OFILES) \
       $(J267_OFILES)

$(BIN)/hill: $(OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/hill $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/hill
