/**
 * Use this interface to set and get values from the tetris piece data structure
 *
 * Other mutators that may be of use can be found in piece_logic.h
 */

#include <stdint.h>

#define PIECE_ROTATION_MASK         0x18 
#define PIECE_ROTATION_BIT_POSITION	3

#define PIECE_TYPE_MASK             0x7
#define PIECE_TYPE_BIT_POSITION     0

#define PIECE_X_MASK                0x1E00
#define PIECE_X_BIT_POSITION        10

#define PIECE_Y_MASK                0x1F0
#define PIECE_Y_BIT_POSITION        5

#define PIECE_EXTRA_1_MASK          0x2000
#define PIECE_EXTRA_1_BIT_POSITION  14

#define PIECE_EXTRA_2_MASK          0x4000
#define PIECE_EXTRA_2_BIT_POSITION  15

/**
 * Returns a piece with Y at max value, X centered, with a random piece and
 * random rotation.
 */
extern uint16_t piece_auto_initialize();
/**
 * Returns the number associated with the piece type.
 * Only 7 types are supported but can support up to 8.
 *
 * returns value between 0 and 6 (inclusive)
 */
extern uint16_t piece_get_piece(uint16_t *piece);
/**
 * a piece type with a random piece with all other data untouched
 *
 * piece = original piece to change the piece of
 */
extern void piece_set_piece(uint16_t *piece, uint16_t type);

/**
 * Returns the number associated with the orientation.
 * Can return 4 different numbers
 *
 * returns value between 0 and 3 (inclusive)
 */
extern uint16_t piece_get_rotation(uint16_t *piece);
/**
 * Return a piece rotation with a random orientation with all other data untouched
 *
 * piece = original piece to change rotation of
 * orientation = 0 for no rotation, 1 for 90 degree, 2 for 180, and 3 for
 *               270 degrees
 */
extern void piece_set_rotation(uint16_t *piece, uint16_t orientation);

/**
 * Gets the value of the horizontal position.
 *
 * piece = pointer to the piece to get the horizontal position of
 * returns a value between 0 and 15.
 */
extern uint16_t piece_get_h(uint16_t *piece);

/**
 * Sets the value of the horizontal position.
 * The expected value is between 0 and 15
 *
 * piece = pointer to the piece to change horizontal position of
 * pos = must be between 0 and 15 (inclusive)
 */
extern void piece_set_h(uint16_t *piece, uint16_t pos);

/**
 * Gets the value of the vertical position.
 *
 * piece = pointer to the piece to get the horizontal position of
 * returns a value between 0 and 31 (inclusive).
 */
extern uint16_t piece_get_v(uint16_t *piece);

/**
 * Sets the value of the vertical position.
 * The expected value is between 0 and 31.
 *
 * piece = pointer to the piece to change rotation of
 * pos = must be between 0 and 31 (inclusive)
 */
extern void piece_set_v(uint16_t *piece, uint16_t pos);

/**
 * Gets the value of the extra bit in position 14 (or the 15th bit)
 *
 * piece = pointer to piece
 */
extern uint16_t piece_get_ex_1(uint16_t *piece);

/**
 * Sets the value of the extra bit in position 14 (or the 15th bit)
 *
 * piece = pointer to piece
 * value = if value is zero, sets bit on. Otherwise, sets bit off
 */
extern void piece_set_ex_1(uint16_t *piece, uint16_t value);

/**
 * Gets the value of the extra bit in position 14 (or the 15th bit)
 *
 * piece = pointer to piece
 */
extern uint16_t piece_get_ex_2(uint16_t *piece);

/**
 * Sets the value of the extra bit in position 15 (or the 16th bit)
 *
 * piece = pointer to piece
 * value = if value is zero, sets bit on. Otherwise, sets bit off
 */
extern void piece_set_ex_2(uint16_t *piece, uint16_t value);
