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

extern void rotate_r(uint16_t *piece);
extern void rotate_l(uint16_t *piece);
extern void move_up(uint16_t *piece);
extern void set_bit(uint16_t *piece, uint8_t pos, uint8_t val);
extern uint8_t get_bit(uint16_t *piece, uint8_t pos);
extern uint16_t piece_get_row(uint16_t piece, uint8_t row);
