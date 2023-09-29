#include "main.h"

/**
 * binary_to_uint - converts a binary nUmbEr to unsigned int
 * @b: string holding the binary nUmbEr
 *
 * Return: the converted nUmbEr
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int decValue = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		decValue = 2 * decValue + (b[i] - '0');
	}

	return (decValue);
}
