CC:=$(shell which cc)
CC_WIN_32:=$(shell which i686-w64-mingw32-gcc)
CC_WIN_64:=$(shell which x86_64-w64-mingw32-gcc)
CFLAGS=-Wall -pedantic -O3 -std=c99 -masm=intel -DASM

SO_PREFIX=libtetris
LIBS=

SOURCES=./test.c ./lib/piece_logic.c ./lib/piece_logic.h ./lib/piece.c ./lib/piece.h
CFILES=./test.c ./lib/piece_logic.c ./lib/piece.c

OUT_DIR=./build/

BIN_DIR=$(OUT_DIR)/bin/
SO_DIR=$(OUT_DIR)/so/

.PHONY: all bins so clean fresh not_do

all: bins so

do: all

not_do:
	$(error 'make do because not do is not an option')

bins:
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -o $(BIN_DIR)/tetris

so:
	mkdir -p $(SO_DIR)/posix/
	mkdir -p $(SO_DIR)/win/
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -m32 -fPIC -shared -o $(SO_DIR)/posix/$(SO_PREFIX)32.so
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -m64 -fPIC -shared -o $(SO_DIR)/posix/$(SO_PREFIX)64.so
	$(CC_WIN_32) $(CFLAGS) $(LIBS) $(CFILES) -shared -o $(SO_DIR)/win/$(SO_PREFIX)32.dll
	$(CC_WIN_64) $(CFLAGS) $(LIBS) $(CFILES) -shared -o $(SO_DIR)/win/$(SO_PREFIX)64.dll

clean:
	rm -r $(OUT_DIR)

fresh: | clean all

