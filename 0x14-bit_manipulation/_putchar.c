#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: Up success 1.
 * Up error, -1 is returned, and errno is set aptly.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
