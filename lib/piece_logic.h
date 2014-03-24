#include <stdint.h>

/**
 * Rotates the piece clockwise by 90 degrees
 *
 * piece = pointer to a piece
 */
extern void piece_rotate_r(uint16_t *piece);

/**
 * Rotates the piece counter-clockwise by 90 degrees
 *  
 * piece = pointer to a piece
 */
extern void piece_rotate_l(uint16_t *piece);

/**
 * Sets a value of a bit in the piece.
 *
 * piece = pointer to a piece
 * pos = the position of the bit to set, which is between 0 and 15 inclusive
 * val = the value to set the bit. Should either be 0 or 1
 */
extern void piece_set_bit(uint16_t *piece, uint8_t pos, uint8_t val);

/**
 * Gets the value of a bit in the piece
 *
 * piece = pointer to a piece
 * Returns the value of the bit
 */
extern uint16_t piece_get_bit(uint16_t *piece, uint8_t pos);

/**
 * Sets the value of a piece by masking it. This effectively allows you to
 * modify segments of the data without worrying about side effects.
 *
 * piece = pointer to a piece
 * mask = the valid segments should be marked with ones
 * data = a new version of the piece that is masked, then masked again with
 * 	piece
 *
 */
extern void piece_set_with_mask(uint16_t *piece, uint16_t mask, uint16_t data);
