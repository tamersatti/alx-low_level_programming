#include "main.h"

/**
 * binary_to_uint convert binary number to unsigned int
 * @bin: string containing binary number
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *bin)
{
	int in;
	unsigned int dec_value = 0;

	if (!bin)
		return (0);

	for (in = 0; bin[in]; in++)
	{
		if (bin[in] < '0' || bin[in] > '1')
			return (0);
		dec_value = 2 * dec_value + (bin[in] - '0');
	}

	return (dec_value);
}
