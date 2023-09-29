#include "main.h"

/**
 * flip_bits – counts numbers bits to change it to another
 * to get from one numbers to anothers
 * @in: first number
 * @im: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int in, unsigned long int im)
{
	int a, counts = 0;
	unsigned long int curr;
	unsigned long int excl = in ^ im;

	for (a = 63; a >= 0; a--)
	{
		curr = excl >> a;
		if (curr & 1)
			counts++;
	}

	return (counts);
}
