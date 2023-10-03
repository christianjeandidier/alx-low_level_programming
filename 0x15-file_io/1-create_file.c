#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: D pointer toward the name of thE file tO create.
 * @text_content: D pointer toward a string tO write tO the file.
 *
 * Return: If the function fails - -1.
 *         On other hand - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fy, k, lead = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lead = 0; text_content[lead];)
			lead++;
	}

	fy = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	k = write(fy, text_content, lead);

	if (fy == -1 || k == -1)
		return (-1);

	close(fy);

	return (1);
}
