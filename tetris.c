#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "./lib/piece.h"

static void test_display_bits(uint16_t *piece);
static void test_display_tbl();
static void test_display_piece_grid(uint16_t *piece);
static void test_demo_piece_rotate();
static void test_demo_piece_move();

int main()
{
	//uint16_t grid[24];
	test_demo_piece_rotate();
	test_demo_piece_move();
	return 0;
}
/* Displays a hex table */
static void test_display_tbl()
{
	int i = 0;
	for (i = 0; i < 16; ++i)
		printf("%x ",i);
	putchar('\n');
	for (i = 0; i < 32; ++i)
		putchar('-');
	putchar('\n');
}
static void test_display_bits(uint16_t *piece)
{
	int i = 0;
	for (i = 0; i < 16; ++i)
		printf("%d ", get_bit(piece,i));
	printf("= %d\n", *piece);
}

static void test_display_piece_grid(uint16_t *piece) {
	int i = 0;
	for (i = 0; i < 16; ++i) {
		printf("%d ", get_bit(piece,i));
		if (((i+1) % 4) == 0)
			putchar('\n');
	}
}

static void test_demo_piece_rotate() {
	uint16_t piece = 7;
	uint16_t piece2 = 0x0F0F;
	uint16_t *r_piece = &piece;
	uint16_t *r_piece2 = &piece2;

	test_display_tbl();
	test_display_bits(r_piece);

	set_bit(r_piece,1,0);
	test_display_bits(r_piece);
	piece = piece2;

	puts("doing clockwise rotations now");

	int i;
	for (i = 0; i < 5; i++) {
		rotate_r(r_piece2);
		test_display_piece_grid(r_piece2);
		putchar('\n');
	}

	puts("doing counter-clockwise rotations now");
	for (i = 0; i < 5; i++) {
		rotate_l(r_piece2);
		test_display_piece_grid(r_piece2);
		putchar('\n');
	}
}

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


