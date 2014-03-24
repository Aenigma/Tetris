/**
 * Implements functionalities of piece.h by using piece_logic.h
 *
 * Includes getter/setters for convenience and implemented in pure C.
 *
 * Other mutators that may be of use can be found in piece_logic.c
 */
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "piece.h"
#include "piece_logic.h"

/* Equivalent to 00_0101_10110_00_000 */
#define PIECE_CENTERED_X_MAX_Y 0x16c0 


uint16_t piece_auto_initialize()
{
	uint16_t piece = PIECE_CENTERED_X_MAX_Y;	
	piece |= rand() % (PIECE_TYPE_MASK | PIECE_ROTATION_MASK);
	return piece;
}
uint16_t piece_get_piece(uint16_t *piece)
{
	return (*piece & PIECE_TYPE_MASK) >> PIECE_TYPE_BIT_POSITION;
}
void piece_set_piece(uint16_t *piece, uint16_t type)
{
	piece_set_with_mask(piece, PIECE_TYPE_MASK, type << PIECE_TYPE_BIT_POSITION);
}
uint16_t piece_get_rotation(uint16_t *piece)
{
	return (*piece & PIECE_ROTATION_MASK) >> PIECE_ROTATION_BIT_POSITION;
}
void piece_set_rotation(uint16_t *piece, uint16_t orientation)
{
	piece_set_with_mask(piece, PIECE_ROTATION_MASK, orientation << PIECE_ROTATION_BIT_POSITION);
}
uint16_t piece_get_h(uint16_t *piece)
{
	return (*piece & PIECE_X_MASK) >> PIECE_X_BIT_POSITION;
}
void piece_set_h(uint16_t *piece, uint16_t pos)
{
	piece_set_with_mask(piece, PIECE_X_MASK, pos << PIECE_X_BIT_POSITION);
}
uint16_t piece_get_v(uint16_t *piece)
{
	return (*piece & PIECE_Y_MASK) >> PIECE_Y_BIT_POSITION;
}
void piece_set_v(uint16_t *piece, uint16_t pos)
{
	piece_set_with_mask(piece, PIECE_Y_MASK, pos << PIECE_Y_BIT_POSITION);
}
uint16_t piece_get_ex_1(uint16_t *piece)
{ 
	return (*piece & PIECE_EXTRA_1_MASK) >> PIECE_EXTRA_1_BIT_POSITION;
}
void piece_set_ex_1(uint16_t *piece, uint16_t value)
{
	piece_set_with_mask(piece, PIECE_EXTRA_1_MASK, value << PIECE_EXTRA_1_BIT_POSITION);
}
uint16_t piece_get_ex_2(uint16_t *piece)
{ 
	return (*piece & PIECE_EXTRA_2_MASK) >> PIECE_EXTRA_2_BIT_POSITION;
}
void piece_set_ex_2(uint16_t *piece, uint16_t value)
{
	piece_set_with_mask(piece, PIECE_EXTRA_2_MASK, value << PIECE_EXTRA_2_BIT_POSITION);
}
