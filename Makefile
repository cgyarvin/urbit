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
       c/zuse.o

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
       f/shed.o \
       f/unix.o \
       f/nock.o

P_OFILES=\
       p/book.o \
       p/list.o \
       p/pool.o \
       p/prep.o \
       p/plow.o \
       p/saur.o \
       p/watt.o

J273_1_OFILES=\
       gen273/1/add.o \
       gen273/1/bex.o \
       gen273/1/dec.o \
       gen273/1/div.o \
       gen273/1/gte.o \
       gen273/1/gth.o \
       gen273/1/lte.o \
       gen273/1/lth.o \
       gen273/1/mod.o \
       gen273/1/mul.o \
       gen273/1/sub.o

J273_2_OFILES=\
       gen273/2/bind.o \
       gen273/2/clap.o \
       gen273/2/drop.o \
       gen273/2/flop.o \
       gen273/2/lent.o \
       gen273/2/levy.o \
       gen273/2/lien.o \
       gen273/2/need.o \
       gen273/2/reel.o \
       gen273/2/roll.o \
       gen273/2/skim.o \
       gen273/2/skip.o \
       gen273/2/snag.o \
       gen273/2/sort.o \
       gen273/2/turn.o \
       gen273/2/weld.o

J273_3_OFILES=\
       gen273/3/cat.o \
       gen273/3/con.o \
       gen273/3/cut.o \
       gen273/3/dis.o \
       gen273/3/end.o \
       gen273/3/lsh.o \
       gen273/3/met.o \
       gen273/3/mix.o \
       gen273/3/mug.o \
       gen273/3/rap.o \
       gen273/3/rip.o \
       gen273/3/rsh.o 

J273_OFILES=\
       $(J273_1_OFILES) \
       $(J273_2_OFILES) \
       $(J273_3_OFILES) \
       gen273/watt.o

J271_1_OFILES=\
       gen271/1/add.o \
       gen271/1/bex.o \
       gen271/1/dec.o \
       gen271/1/div.o \
       gen271/1/gte.o \
       gen271/1/gth.o \
       gen271/1/lte.o \
       gen271/1/lth.o \
       gen271/1/mod.o \
       gen271/1/mul.o \
       gen271/1/sub.o

J271_2_OFILES=\
       gen271/2/bind.o \
       gen271/2/clap.o \
       gen271/2/drop.o \
       gen271/2/flop.o \
       gen271/2/lent.o \
       gen271/2/levy.o \
       gen271/2/lien.o \
       gen271/2/need.o \
       gen271/2/reel.o \
       gen271/2/roll.o \
       gen271/2/skim.o \
       gen271/2/skip.o \
       gen271/2/snag.o \
       gen271/2/sort.o \
       gen271/2/turn.o \
       gen271/2/weld.o

J271_3_OFILES=\
       gen271/3/cap.o \
       gen271/3/cat.o \
       gen271/3/con.o \
       gen271/3/cut.o \
       gen271/3/dor.o \
       gen271/3/dis.o \
       gen271/3/end.o \
       gen271/3/gor.o \
       gen271/3/hor.o \
       gen271/3/lsh.o \
       gen271/3/mas.o \
       gen271/3/met.o \
       gen271/3/mix.o \
       gen271/3/mug.o \
       gen271/3/peg.o \
       gen271/3/rap.o \
       gen271/3/rip.o \
       gen271/3/rsh.o \
       gen271/3/vor.o

J271_4_OFILES=\
       gen271/4/in.o \
       gen271/4/by.o \
       gen271/4/in_has.o \
       gen271/4/in_gas.o \
       gen271/4/in_put.o \
       gen271/4/in_tap.o \
       gen271/4/by_gas.o \
       gen271/4/by_get.o \
       gen271/4/by_has.o \
       gen271/4/by_put.o 

J271_6_OFILES=\
       gen271/6/ap.o \
       gen271/6/cell.o \
       gen271/6/comb.o \
       gen271/6/cons.o \
       gen271/6/core.o \
       gen271/6/face.o \
       gen271/6/flan.o \
       gen271/6/flip.o \
       gen271/6/flor.o \
       gen271/6/fork.o \
       gen271/6/hack.o \
       gen271/6/hike.o \
       gen271/6/look.o \
       gen271/6/ream.o \
       gen271/6/ut.o

J271_6_OFILES_UT=\
       gen271/6/ut_bake.o \
       gen271/6/ut_burn.o \
       gen271/6/ut_cull.o \
       gen271/6/ut_edit.o \
       gen271/6/ut_emit.o \
       gen271/6/ut_find.o \
       gen271/6/ut_fire.o \
       gen271/6/ut_fish.o \
       gen271/6/ut_fret.o \
       gen271/6/ut_fuse.o \
       gen271/6/ut_gain.o \
       gen271/6/ut_heal.o \
       gen271/6/ut_mint.o \
       gen271/6/ut_orth.o \
       gen271/6/ut_nest.o \
       gen271/6/ut_park.o \
       gen271/6/ut_peek.o \
       gen271/6/ut_play.o \
       gen271/6/ut_repo.o \
       gen271/6/ut_rest.o \
       gen271/6/ut_seek.o \
       gen271/6/ut_snap.o \
       gen271/6/ut_tuck.o \
       gen271/6/ut_tusk.o

J271_OFILES=\
       $(J271_1_OFILES) \
       $(J271_2_OFILES) \
       $(J271_3_OFILES) \
       $(J271_4_OFILES) \
       $(J271_6_OFILES) \
       $(J271_6_OFILES_UT) \
       gen271/watt.o

OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J271_OFILES)

$(BIN)/zuse: $(OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/zuse $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/zuse
