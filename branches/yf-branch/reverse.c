#include <stdio.h>

int reverseint(int number)
{
	int result = 0;
	int number_in_progress = number;
	unsigned int overflow = false;
	while ( number_in_progress != 0 )
	{
		result = 10 * result + number_in_progress % 10;
		if ( (unsigned int)(result & 0x80000000) ) return -1;
		number_in_progress /= 10;
	}
	
	return result;
}

void reversebinary(int number, int bits_shift)
{
	if ( bits_shift == 1 )
	{
		if ( number == 1 ) return 2;
		if ( number == 2 ) return 1;
		return number;
	}
	
	int mask_right = ~(0xffffffff << bits_shift);
	int mask_left  = mask_right << bits_shift;
	
	int left  = reversebinary((number & mask_left) >> bits_shift, bits_shift / 2);
	int right = reversebinary(number & mask_right, bits_shift / 2);
	
	return right << bits_shift + left;
}
