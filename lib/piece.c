#include <stdint.h>
#include <stdio.h>
#include "piece.h"
static void transpose(uint16_t *piece);
static void flip_v(uint16_t *piece);
static void flip_h(uint16_t *piece);
static void swap_bit(uint16_t *piece, uint8_t x, uint8_t y);


void rotate_l(uint16_t *piece)
{
	transpose(piece);
	flip_v(piece);
}

void rotate_r(uint16_t *piece)
{
	transpose(piece);
	flip_h(piece);
}

void move_up(uint16_t *piece)
{
	while(*piece && !(*piece & PIECE_FIRST_ROW_BITMASK))
		*piece = *piece >> PIECE_ROW_DIFF;
}

uint8_t get_bit(uint16_t *piece, uint8_t pos)
{
	return ((*piece) >> pos) & 1;
}

void set_bit(uint16_t *piece, uint8_t pos, uint8_t val)
{
	if(val)
		*piece |= 1 << pos;
	else
		*piece &= ~(1 << pos);
}

uint16_t piece_get_row(uint16_t piece, uint8_t row)
{
	uint16_t t_row = *piece;
	uint16_t row = t_row;
	row &= (PIECE_ROW_BITMASK << (row*PIECE_ROW_DIFF));

	if(!row)
		return 0;
	
	while(!(row & PIECE_ROW_BITMASK))
		row = row>> PIECE_ROW_DIFF;

	return row;
}

static void flip_v(uint16_t *piece)
{
	int i;
	for (i = 0; i < PIECE_ROW_DIFF; i += PIECE_COL_DIFF) {
		swap_bit(piece, i, i+(PIECE_ROW_DIFF*3));
		swap_bit(piece, i+PIECE_ROW_DIFF, i+(PIECE_ROW_DIFF*2));
	}
}

static void flip_h(uint16_t *piece)
{
	int i;
	for (i = 0; i < PIECE_SIZE; i+= PIECE_ROW_DIFF) {
		swap_bit(piece, i, i+(PIECE_COL_DIFF*3));
		swap_bit(piece, i+PIECE_COL_DIFF, i+(PIECE_COL_DIFF*2));
	}
}
static void swap_bit(uint16_t *piece, uint8_t x, uint8_t y)
{
	uint8_t x2 = get_bit(piece,x);
	uint8_t y2 = get_bit(piece,y);
	set_bit(piece, y, x2);
	set_bit(piece, x, y2);
}

/**
* Based off algorithm here:
* http://en.wikipedia.org/wiki/In-place_matrix_transposition#Square_matrices
* for n = 0 to N - 2
*   for m = n + 1 to N - 1
*     swap A(n,m) with A(m,n)
*/
static void transpose(uint16_t *piece)
{
	int i;
	int j;
	int n = 1;
	int m = 3;

	do { 
		for (i = n, j = 1; i < (n+m); ++i, ++j) {
			swap_bit(piece, i, i+(3*j));
		}
		n += 5;
		--m;
	} while(n < 16);
}

