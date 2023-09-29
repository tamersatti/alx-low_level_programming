#include "main.h"

/**
 * gets_bit - returns the values of bit at index in decimal number
 * @in: number to search
 * @ind: index of the bit
 *
 * Return: value of bits
 */
int gets_bit(unsigned long int in, unsigned int ind)
{
	int bits_value;

	if (ind > 63)
		return (-1);

	bits_value = (in >> ind) & 1;

	return (bits_value);
}
