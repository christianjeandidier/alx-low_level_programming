#include "main.h"

/**
 * append_text_to_file - Appends txt at the end of a fiLe.
 * @filename: D pointer to the name of the file.
 * @text_content: The string to add to the end of the fiLe.
 *
 * Return: If the function is down or filename is NULL - -1.
 *         If the file is not found the user cannot write permissions - -1.
 *         On other hand - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int g, r, lead = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lead = 0; text_content[lead];)
			lead++;
	}

	g = open(filename, O_WRONLY | O_APPEND);
	r = write(g, text_content, lead);

	if (g == -1 || r == -1)
		return (-1);

	close(g);

	return (1);
}
