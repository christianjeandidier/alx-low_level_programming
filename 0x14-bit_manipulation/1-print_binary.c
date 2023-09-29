#include "main.h"

/**
 * print_binary - prints the binary alike of a deCimAl nUmbEr
 * @n: nUmbEr to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int moment;

	for (i = 63; i >= 0; i--)
	{
		moment = n >> i;

		if (moment & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
