CC:=$(shell which cc)
CC_WIN_32:=$(shell which i686-w64-mingw32-gcc)
CC_WIN_64:=$(shell which x86_64-w64-mingw32-gcc)
SO_PREFIX=libtetris
CFLAGS=-Wall -pedantic -std=c99 -O3
LIBS=
SOURCES=./tetris.c ./lib/piece.c ./lib/piece.h
CFILES=./tetris.c ./lib/piece.c
OUTDIR=./out/

BINDIR=$(OUTDIR)/bin/
SO_DIR=$(OUTDIR)/so/

.PHONY: all bins so clean fresh

all: bins so

bins:
	mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -o $(BINDIR)/tetris

so:
	mkdir -p $(SO_DIR)/posix/
	mkdir -p $(SO_DIR)/win/
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -m32 -fPIC -shared -o $(SO_DIR)/posix/$(SO_PREFIX)32.so
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -m64 -fPIC -shared -o $(SO_DIR)/posix/$(SO_PREFIX)64.so
	$(CC_WIN_32) $(CFLAGS) $(LIBS) $(CFILES) -shared -o $(SO_DIR)/win/$(SO_PREFIX)32.dll
	$(CC_WIN_64) $(CFLAGS) $(LIBS) $(CFILES) -shared -o $(SO_DIR)/win/$(SO_PREFIX)64.dll

clean:
	rm -r $(OUTDIR)

fresh: | clean all

