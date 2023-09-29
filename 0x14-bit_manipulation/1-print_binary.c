#include "main.h"

/**
 * print_binary  prints the binary equivalents of  decimal numb
 * in: number print in binary
 */
void print_binary(unsigned long int in)
{
	int m, cou = 0;
	unsigned long int curr;

	for (m = 63; m >= 0; m--)
	{
		curr = in >> m;

		if (curr & 1)
		{
			_putchar('1');
			cou++;
		}
		else if (cou)
			_putchar('0');
	}
	if (!cou)
		_putchar('0');
}
