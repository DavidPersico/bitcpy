#include "bitcpy.h"

void* bitcpy(void* dest, const void* source, size_t num_bits)
{
	if (num_bits == 0)
	{
		return dest;
	}

	/* Cast void ptr to char ptr as chars are a single byte. */
	char* char_dest = (char*)dest;
	const char* char_source = (const char*)source;

	size_t rem_bits;
	size_t byte_index;
	byte_index = 0;

	/* Avoid unnecessary byte copy when possible. */
	if (num_bits > 7)
	{
		size_t num_bytes;
		/* Use bit shifting to divide efficiently. */
		num_bytes = num_bits >> 3;

		for (; byte_index < num_bytes; byte_index++)
		{
			char_dest[byte_index] = char_source[byte_index];
		}

		/* Use bitwise & to modulo efficiently. */
		rem_bits = num_bits & 0x7;
	}
	else
	{
		rem_bits = num_bits;
	}
	
	if (rem_bits == 0)
	{
		return dest;
	}

	/* Create mask of size rem_bits and use it to copy appropriate source bits to destination. */
	unsigned char ones = 0xff >> (8 - rem_bits);
	char_dest[byte_index] = (ones | char_dest[byte_index]) ^ ((~char_source[byte_index]) & ones);

	return dest;
}
