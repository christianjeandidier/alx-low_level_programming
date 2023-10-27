#include "main.h"

/**
 * set_bit - sets a bit at a given index to 1
 * @m: pointer to the num to change
 * @index: index of the bit to set to 1
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *m, unsigned int index)
{
	if (index > 63)
		return (-1);

	*m = ((1UL << index) | *m);
	return (1);
}
