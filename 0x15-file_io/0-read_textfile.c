#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of lettersters to be read
 * Return: wr- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bufer;
	ssize_t filed;
	ssize_t wr;
	ssize_t ta;

	filed = open(filename, O_RDONLY);
	if (filed == -1)
		return (0);
	bufer = malloc(sizeof(char) * letters);
	ta = read(filed, bufer, letters);
	wr = write(STDOUT_FILENO, bufer, ta);

	free(bufer);
	close(filed);
	return (wr);
}
