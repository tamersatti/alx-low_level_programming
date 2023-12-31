#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int filed);

/**
 * create_buffer - the function that Allocates 1024 bytes for a buffer.
 * @file:name of file buffer is  to storing chars for.
 * Return: A pointer to newly allocated buffers.
 */
char *create_buffer(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - Closes file descriptors.
 * @filed: The file descriptor to be closed.
 */
void close_file(int filed)
{
	int v;

	v = close(filed);

	if (v == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close filed %d\n", filed);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @ac: numbers of arguments supplied to program.
 * @av: array of pointers .
 *
 * Return: 0 on success.
 */
int main(int ac, char *av[])
{
	int fr, t, c, wr;
	char *buf;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buffer(av[2]);
	fr = open(av[1], O_RDONLY);
	c = read(fr, buf, 1024);
	t = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fr == -1 || c == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", av[1]);
			free(buf);
			exit(98);
		}

		wr = write(t, buf, c);
		if (t == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", av[2]);
			free(buf);
			exit(99);
		}

		c = read(fr, buf, 1024);
		t = open(av[2], O_WRONLY | O_APPEND);

	} while (c > 0);

	free(buf);
	close_file(fr);
	close_file(t);

	return (0);
}
