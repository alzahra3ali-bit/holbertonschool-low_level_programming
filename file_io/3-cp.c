#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd, wr, close_from, close_to;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO,
			"Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);

	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2],
			O_CREAT | O_WRONLY | O_TRUNC,
			0664);

	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	rd = read(fd_from, buffer, BUFFER_SIZE);

	while (rd > 0)
	{
		wr = write(fd_to, buffer, rd);

		if (wr == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			exit(99);
		}

		rd = read(fd_from, buffer, BUFFER_SIZE);
	}

	if (rd == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	close_from = close(fd_from);

	if (close_from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	close_to = close(fd_to);

	if (close_to == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
