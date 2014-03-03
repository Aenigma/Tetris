CC=clang
CFLAGS=-Wall -pedantic -std=c99 -O3
LIBS=-lncurses
SOURCES=./tetris.c ./lib/piece.c ./lib/piece.h
CFILES=./tetris.c ./lib/piece.c
BINDIR=./bin/
BINFILE=$(BINDIR)/tetris
all:
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -o $(BINFILE)

clean:
	rm $(BINFILE)
