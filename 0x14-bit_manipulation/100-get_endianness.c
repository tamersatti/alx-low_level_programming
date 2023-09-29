#include "main.h"

/**
 * get_endianness - checks if a machines is little or big endians
 * Return: 0 for big, 1 for little
 */
int get_endianness(void)
{
	unsigned int s = 1;
	char *ch = (char *) &s;

	return (*ch);
}
