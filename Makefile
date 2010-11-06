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
DEFINES=-DU3_OS_$(OS) -DU3_OS_ENDIAN_$(ENDIAN)\
	-DU4_ENDIAN_$(ENDIAN) -DU4_OS_$(OS)
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
       f/hint.o \
       f/benx.o \
       f/bail.o \
       f/bask.o \
       f/lame.o \
       f/flee.o \
       f/toss.o \
       f/shed.o \
       f/unix.o \
       f/main.o

P_OFILES=\
       p/book.o \
       p/list.o \
       p/pool.o \
       p/prep.o \
       p/plow.o \
       p/saur.o \
       p/watt.o

J1_OFILES=\
       j/1/add.o \
       j/1/dec.o 

J_OFILES=\
       $(J1_OFILES) \
       j/watt.o

OFILES=\
       $(F_OFILES) \
       $(P_OFILES) \
       $(J_OFILES) \
       $(C_OFILES)

$(BIN)/ford: $(OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/ford $(OFILES) -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(OFILES) $(BIN)/ford

