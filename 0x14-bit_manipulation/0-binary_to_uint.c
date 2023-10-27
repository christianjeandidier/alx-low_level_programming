#include "main.h"

/**
 * binary_to_uint - converts a binary num to unsigned int
 * @d: string holding the binary num
 *
 * Return: the converted num
 */
unsigned int binary_to_uint(const char *d)
{
	int i;
	unsigned int dec_val = 0;

	if (!d)
		return (0);

	for (i = 0; d[i]; i++)
	{
		if (d[i] < '0' || d[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (d[i] - '0');
	}

	return (dec_val);
}
