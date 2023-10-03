#include "main.h"

/**
 * create_file - Creates files.
 * filename: A pointer to name of  files to create.
 * text_content: A pointer to string to write files.
 *
 * Return: If function fail 1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int filed, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	filed = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	wr = write(filed, text_content, length);

	if (filed == -1 || wr == -1)
		return (-1);

	close(filed);

	return (1);
}
