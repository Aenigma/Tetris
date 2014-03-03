/** Size of the board in columns; if 16 bits is used, 6 bits are unused */
#define GRID_MAX_COL 10
/** Size of the board in rows. Is used for array based access. */
#define GRID_MAX_ROW 24
/** Set if piece overlaps existing blocks on board */
#define GRID_ERR_COLLIDING 1
/** Set if piece is going outside the boundaries of board */
#define GRID_ERR_BOUNDS 2
/** Set if piece is not about to collide with another block in the next tick */
#define GRID_ERR_FLOATING 4

/**
 * Because only GRID_MAX_COL bits are used per row, this represents the max
 * number possible per row. Can also be used as a bitmask for the valid items
 * per row.
 */
#define GRID_ROW_FULL 0x03FF

#ifndef GRID_POSITION_DEFINED
#define GRID_POSITION_DEFINED
struct Position {
	unsigned int x;
	unsigned int y;
}
#endif

/**
 * You can use this function to place pieces onto the grid. However, this
 * function does not check to see if the location is valid and thus pieces
 * can be placed where pieces already exist or where the pieces are "floating".
 *
 * Use grid_cannot_place(uint16_t, uint16_t, struct Position) to check if you can
 * place a piece safely.
 *
 * grid pointer to an array of 24 uint16_t
 * piece a tetris piece represented by ./lib/piece.h
 * pos a struct with and X and Y coordinates on the grid of the bottom left
 *	 corner of the piece. X represents the columns and Y being the rows.
 */
extern void grid_place(uint16_t *grid, uint16_t piece, struct Position pos);
/**
 * Returns true if a piece cannot be placed and false if it can.
 *
 * If the value is true, masks can be used to determine why the piece cannot be
 * placed. Simply negate the value to determine whether or not a piece can be
 * placed.
 */
extern unsigned int grid_cannot_place(uint16_t *grid, uint16_t piece,
		struct Position pos);
/**
 * Returns the value of GRID_ERR_COLLI
 */
extern unsigned int grid_will_collide(uint16_t *grid, uint16_t piece,
		struct Postition pos);
/**
 * Finds all rows that are full, zeros them, and moves all rows above it
 * downwards.
 */
extern void grid_remove_full(uint16_t *grid);
