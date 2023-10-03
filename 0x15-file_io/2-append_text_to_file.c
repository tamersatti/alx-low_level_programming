#include "main.h"

/**
 * append_text_to_file - Appends text at EOF.
 * @filename: A pointer to name of  file.
 * @text_content: The string to add to EOF.
 *
 * Return: If the function fails or filename is NULL .
 *         If the file does not exist , user lack write permissions 1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	wr = write(a, text_content, length);

	if (a == -1 || wr == -1)
		return (-1);

	close(a);

	return (1);
}
