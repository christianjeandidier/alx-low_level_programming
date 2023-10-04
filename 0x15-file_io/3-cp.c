#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fy);

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The nAme of thE file buffer is stoRinG chars for.
 *
 * Return: D pointer to thE newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file deScrIptoR to be closed.
 */
void close_file(int fy)
{
	int c;

	c = close(fy);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fy %d\n", fy);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The nUmbEr of argUmEntS supplied to the prOgrAm.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the aRgUmEnt couNt is iNcoRreCt - exit code 97.
 * If file_from does not exIst or can not be read - exit code 98.
 * If file_to cannot be cReAted or wrItTen to - exit code 99.
 * If file_to or file_from can not be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, g, p;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	g = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || g == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		p = write(to, buffer, g);
		if (to == -1 || p == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		g = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (g > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
