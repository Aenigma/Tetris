#include <stdint.h>

#define PIECE_SIZE 16
#define PIECE_EDGE_SIZE 4

#define PIECE_FIRST_ROW_INDEX 0
#define PIECE_SECOND_ROW_INDEX 1
#define PIECE_THIRD_ROW_INDEX 2
#define PIECE_FOURTH_ROW_INDEX 3

#define PIECE_ROW_DIFF 4
#define PIECE_COL_DIFF 1

#define PIECE_FIRST_ROW_BITMASK 0x000F
#define PIECE_LAST_ROW_BITMASK 0xF000

#define PIECE_ROW_BITMASK 0x000F

/**
 * Rotates the piece clockwise by 90 degrees
 *
 * piece = pointer to a piece
 **/
extern void rotate_r(uint16_t *piece);
/**
 * Rotates the piece counter-clockwise by 90 degrees
 *  
 * piece = pointer to a piece
 **/
extern void rotate_l(uint16_t *piece);
/**
 * Moves rows up until top row is no longer all 0s. Should ideally be called
 * after #rotate_r or #rotate_l so that pieces don't seem to "move down" after
 * rotation.
 *
 * piece = pointer to a piece
 */
extern void move_up(uint16_t *piece);
/**
 * Sets a value of a bit in the piece.
 *
 * piece = pointer to a piece
 * pos = the position of the bit to set, which is between 0 and 15 inclusive
 * val = the value to set the bit. Should either be 0 or 1
 */
extern void set_bit(uint16_t *piece, uint8_t pos, uint8_t val);
/**
 * Gets the value of a bit in the piece
 *
 * piece = pointer to a piece
 * Returns the value of the bit
 */
extern uint8_t get_bit(uint16_t *piece, uint8_t pos);
