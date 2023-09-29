#include "main.h"

/**
 * clear_bit - set the values of  given bits to 0
 * @in: pointer the number to change
 * @ind: index of the bits to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *in, unsigned int ind)
{
	if (ind > 63)
		return (-1);

	*in = (~(1UL << ind) & *in);
	return (1);
}
