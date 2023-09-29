#include "main.h"

/**
 * set_bit - set bit at  given indexs to 1
 * @in: pointer to numbers to change
 * @ind: index of the bits to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *in, unsigned int ind)
{
	if (ind > 63)
		return (-1);

	*in = ((1UL << ind) | *in);
	return (1);
}
