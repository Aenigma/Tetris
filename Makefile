# This is a GNU Make file which describes how to build the application's
# DLL/SO for both x86 Windows and Linux systems.
#
# Some of the compiler flags here are essential such as '-masm=intel' which
# allows the inline assembly to be in Intel syntax instead of AT&T syntax.
# Additionally '-DASM' compiles the program so that the portions using inline
# assembly are actually used instead of their C equivalents.
#
#
# To do a full compile, invoke 'make all'
# To build just the shared objects and DLLs, invoke 'make so'
# To build just the test executable, invoke 'make bins'
#

CC:=$(shell which cc)
CC_WIN_32:=$(shell which i686-w64-mingw32-gcc)
CC_WIN_64:=$(shell which x86_64-w64-mingw32-gcc)
CFLAGS=-Wall -pedantic -O3 -std=c99 -masm=intel -DASM

SO_PREFIX=libtetris
LIBS=

SOURCES=./test.c ./lib/piece_logic.c ./lib/piece_logic.h ./lib/piece.c ./lib/piece.h
CFILES=./test.c ./lib/piece_logic.c ./lib/piece.c
OBJ=piece_logic.o piece.o

OUT_DIR=build

BIN_DIR=$(OUT_DIR)/bin
SO_DIR=$(OUT_DIR)/so

.PHONY: all bins so clean fresh not_do assembly

VPATH =lib

all: bins so

do: all

not_do:
	$(error 'make do because not do is not an option')

bins: piece_logic.o piece.o
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -o $(BIN_DIR)/tetris

$(OUT_DIR):
	@mkdir -p $(OUT_DIR)

so:
	@mkdir -p $(SO_DIR)/win/
	@mkdir -p $(SO_DIR)/posix/
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -m32 -fPIC -shared -o $(SO_DIR)/posix/$(SO_PREFIX)32.so
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -m64 -fPIC -shared -o $(SO_DIR)/posix/$(SO_PREFIX)64.so
	$(CC_WIN_32) $(CFLAGS) $(LIBS) $(CFILES) -shared -o $(SO_DIR)/win/$(SO_PREFIX)32.dll
	$(CC_WIN_64) $(CFLAGS) $(LIBS) $(CFILES) -shared -o $(SO_DIR)/win/$(SO_PREFIX)64.dll

assembly: piece_logic.s piece.s

clean:
	@rm -r $(OUT_DIR)
	@rm -f *.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.s: %.c
	$(CC) $(CFLAGS) $(LIBS) $(CFILES) -S $<

fresh: | clean all
