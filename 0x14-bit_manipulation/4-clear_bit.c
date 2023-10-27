#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @m: pointer to the num to change
 * @index: index of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *m, unsigned int index)
{
	if (index > 63)
		return (-1);

	*m = (~(1UL << index) & *m);
	return (1);
}
