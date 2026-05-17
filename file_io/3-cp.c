#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void print_usage(void)
{
	dprintf(STDERR_FILENO,
		"Usage: cp file_from file_to\n");
	exit(97);
}

void read_error(char *file)
{
	dprintf(STDERR_FILENO,
		"Error: Can't read from file %s\n", file);
	exit(98);
}

void write_error(char *file)
{
	dprintf(STDERR_FILENO,
		"Error: Can't write to %s\n", file);
	exit(99);
}

void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[BUFFER_SIZE];
	int rd, wr;

	rd = read(fd_from, buffer, BUFFER_SIZE);

	while (rd > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1)
			write_error(file_to);

		rd = read(fd_from, buffer, BUFFER_SIZE);
	}

	if (rd == -1)
		read_error(file_from);
}

/**
 * main - copies file content
 */

int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
		print_usage();

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		read_error(argv[1]);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
		write_error(argv[2]);

	copy_file(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
