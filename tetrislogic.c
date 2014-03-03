#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "./lib/piece.h"
#include "./lib/grid.h"
static void test_demo_piece_move()
{
	uint16_t piece = 0x1111;
	puts("original:");
	test_display_piece_grid(&piece);

	puts("left rotated:");
	rotate_l(&piece);
	test_display_piece_grid(&piece);

	puts("moved up:");
	move_up(&piece);
	test_display_piece_grid(&piece);
}

