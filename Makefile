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
CLD=gcc -g -bind_at_load -L/sw/lib
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
       c/ford.o

F_OFILES=\
       f/rail.o \
       f/loom.o \
       f/wire.o \
       f/chad.o \
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

OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J273_OFILES)

$(BIN)/ford: $(OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/ford $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/ford

