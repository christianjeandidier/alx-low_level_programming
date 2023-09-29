#include "main.h"

/**
 * flip_bits - counts the nUmbEr of bits to change
 * to get from one nUmbEr to another
 * @n: first nUmbEr
 * @m: second nUmbEr
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int now;
	unsigned long int after = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		now = after >> i;
		if (now & 1)
			count++;
	}

	return (count);
}
