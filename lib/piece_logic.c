/**
 * This file implements the functionalities of piece_logic.h
 *
 * It primarily uses assembly for the logic and uses C to avoid things such as
 * function calling conventions.
 */
#include <stdint.h>
#include <stdio.h>
#include "piece_logic.h"

/* Defines the region in which the piece's type is defined */
#define PIECE_TYPE_MASK 0x18

void piece_set_with_mask(uint16_t *piece, uint16_t mask, uint16_t data)
{
#ifdef ASM
	__asm__ __volatile__(
		"and  %3, %2\n\t"   /* AND mask with data */
		"not  %2\n\t"       /* Invert the mask */
		"and  [%1], %2\n\t"	/* AND with the data at piece with the inverted mask to
													 clear the bits made valid with the mask */
		"or   [%1], %3\n\t" /* OR the masked data with the data at piece so that
													 data there is written verbatim from data */
		:"=a"(piece)
		:"a"(piece), "c"(mask), "d"(data)
		/* So, this causes problems for 32bit linux if you use ebx instead of ebx
		 * might be a bug, who nose? */
	);
#endif
#ifndef ASM
	*piece = (*piece & ~mask) | (data & mask);
#endif
}

uint16_t piece_get_bit(uint16_t *piece, uint8_t pos)
{
#ifdef ASM
	uint16_t piece_copy = *piece;
	__asm__ __volatile__(
		"shr	%1, %2\n\t"	/* Shift the digits to the right by pos */
		"and	%1, 1\n\t"	/* Mask it with 1 so only 0 or 1 is preserved */
		:"=a"(piece_copy)
		:"a"(piece_copy),"c"(pos)
	);
	return piece_copy;
#endif
#ifndef ASM
	return ((*piece) >> pos) & 1;
#endif
}

void piece_set_bit(uint16_t *piece, uint8_t pos, uint8_t val)
{
#ifdef ASM
	__asm__ __volatile__(
		"mov	ebx, 1\n\t"         /* Move 1 to ebx */
		"shl	ebx, %1\n\t"        /* Shift 1 by pos times, which is in cl */
		"movzx 	ecx, %2\n\t"      /* Move val into cx */
		"jecxz	PIECE_SET_VALUE_ZERO\n\t" /* Check if val is zero */
			"or [%0], ebx\n\t"			/* If value is non-zero, OR piece and ebx to
			                         * set it to 1 */
		"jmp	PIECE_SET_END\n\t"  /* Jump to the end */

		"PIECE_SET_VALUE_ZERO:"   /* Jumps to here if val is zero */
			"not	ebx\n\t"          /* Inverse ebx */
			"and	[%0], ebx\n\t"    /* If value is non-zero, AND it to set bit to 0 */
		"PIECE_SET_END:\n\t"      /* Label for end so that it can be jumped to */
		:
		:"a"(piece), "c"(pos), "g"(val)
	);
#endif
#ifndef ASM
	if(val)
		  *piece |= 1 << pos;
	else
		  *piece &= ~(1 << pos);
#endif
}

void piece_rotate_r(uint16_t *piece)
{
	uint16_t piece_copy = *piece;
#ifdef ASM
	__asm__ __volatile__(
		"add	%1, 8\n\t"  /* Add 8 to piece_copy */
		:"=a"(piece_copy)
		:"a"(piece_copy)
	);
#endif
#ifndef ASM
	piece_copy += 8;
#endif
	/* Use mask to set region so carries are not preserved */
	piece_set_with_mask(piece, PIECE_TYPE_MASK, piece_copy);
}

void piece_rotate_l(uint16_t *piece)
{
	uint16_t piece_copy = *piece;
#ifdef ASM
	__asm__ __volatile__(
		"sub	%1, 8\n\t"  /* Subtract 8 to piece_copy */
		:"=a"(piece_copy)
		:"a"(piece_copy)
	);
#endif
#ifndef ASM
	piece_copy -= 8;
#endif
	/* Use mask to set region so carries are not preserved */
	piece_set_with_mask(piece, PIECE_TYPE_MASK, piece_copy);
}

