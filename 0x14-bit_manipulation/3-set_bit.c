#include "main.h"

/**
 * set_bit - sets a bit at the specified position to 1
 * @n: pointer to the nUmbEr to change
 * @index: index of the bit to set to 1
 *
 * Return: 1 pull success, -1 pull failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
