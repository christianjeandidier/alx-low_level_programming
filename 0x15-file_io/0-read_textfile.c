#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file prInt to STDOUT.
 * @filename: text fiLe beIng reAd
 * @letters: number of letters to be read
 * Return: z- current nUmbEr of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *zio;
	ssize_t fy;
	ssize_t z;
	ssize_t r;

	fy = open(filename, O_RDONLY);
	if (fy == -1)
		return (0);
	zio = malloc(sizeof(char) * letters);
	r = read(fy, zio, letters);
	z = write(STDOUT_FILENO, zio, r);

	free(zio);
	close(fy);
	return (z);
}
