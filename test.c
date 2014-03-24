#include <stdio.h>
#include <stdint.h>
#include "lib/piece_logic.h"
void display_binary(uint16_t piece);
void test_rotation();
void test_set_with_mask();
void test_getset_bit();
int main()
{
	test_set_with_mask();
	test_rotation();
	test_getset_bit();
}

void test_getset_bit()
{
	puts("# Testing Setting and Getting a Single Bit");
	uint16_t test = 0x1;
	printf("    Initial:\t");
	display_binary(test);
	puts("## Setting a bit and getting it");
	printf("    Setting bit 4 to 1:\t");
	piece_set_bit(&test, 4, 1);
	display_binary(test);
	printf("    Setting bit 0 to 0:\t");
	piece_set_bit(&test, 0, 0);
	display_binary(test);
	printf("    Getting Value of bit 4: %d\n", piece_get_bit(&test,4));
	puts("## Doing Binary Display using Get Bit");
	int i = 16;
	while(i--)
		printf("%d", piece_get_bit(&test,i));
	putchar('\n');
}

void test_set_with_mask() 
{
	puts("# Testing Set with Mask");
	uint16_t test_piece = 0xFFFF;
	printf("    Test Piece:\t");
	display_binary(test_piece);
	printf("    Mask:\t");
	display_binary(0x0FF0);
	printf("    Data:\t");
	display_binary(0x00FF);
	piece_set_with_mask(&test_piece, 0x0FF0, 0x00FF);
	printf("    Result:\t");
	display_binary(test_piece);
}
void display_binary(uint16_t piece) 
{
	int i = 16;
	while(i--)
		printf("%d",piece >> i & 1);
	putchar('\n');
}

void test_rotation()
{
	puts("# Testing Rotation");
	uint16_t test = 0;
	int i = 0;
	printf("Initial:\t");
	display_binary(test);

	puts("## Rotating Right");
	for (i = 0; i < 5; i++) {
		piece_rotate_r(&test);
		printf("    Rotated right %d times:", i);
		display_binary(test);
	}
	test = 0;
	puts("## Rotating Left");

	
	for (i = 0; i < 5; i++) {
		piece_rotate_l(&test);
		printf("    Rotated left %d times:", i);
		display_binary(test);
	}
}
