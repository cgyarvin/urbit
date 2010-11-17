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
CLD=gcc -O2 -bind_at_load -L/sw/lib
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU2_OS_$(OS) -DU2_OS_ENDIAN_$(ENDIAN)
CFLAGS=-O2 -I/sw/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
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

J274_1_OFILES=\
       gen274/1/add.o \
       gen274/1/bex.o \
       gen274/1/dec.o \
       gen274/1/div.o \
       gen274/1/gte.o \
       gen274/1/gth.o \
       gen274/1/lte.o \
       gen274/1/lth.o \
       gen274/1/mod.o \
       gen274/1/mul.o \
       gen274/1/sub.o

J274_2_OFILES=\
       gen274/2/bind.o \
       gen274/2/clap.o 

J274_3_OFILES=\
       gen274/3/cat.o \
       gen274/3/met.o \
       gen274/3/mug.o \
       gen274/3/rip.o

J274_OFILES=\
       $(J274_1_OFILES) \
       $(J274_2_OFILES) \
       $(J274_3_OFILES) \
       gen274/watt.o

OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J274_OFILES)

$(BIN)/ford: $(OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/ford $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/ford

